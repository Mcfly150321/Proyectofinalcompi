// Backend del IDE EasyLang.
// Flujo: analizador en C (Flex/Bison) -> código intermedio (TDC) -> ASM NASM
//        -> nasm + ld (ejecutable) -> ejecución del binario.
const http=require("http"),fs=require("fs"),os=require("os"),path=require("path");
const {spawn}=require("child_process"),crypto=require("crypto");
const {compile,fmt,genAsm}=require("./compiler");
const BIN=process.env.ANALIZADOR||path.join(__dirname,"analizador","analizador");
const PORT=process.env.PORT||3000,PUB=path.join(__dirname,"public");
const MIME={".html":"text/html; charset=utf-8",".png":"image/png"};
const builds=new Map();

const send=(res,code,obj)=>{res.writeHead(code,{"Content-Type":"application/json; charset=utf-8"});res.end(JSON.stringify(obj))};

// Ejecuta un programa externo, con stdin opcional y tiempo límite.
function sh(cmd,args,{cwd,input="",timeout=5000}={}){
  return new Promise(resolve=>{
    let o="",e="";
    const p=spawn(cmd,args,{cwd,timeout});
    p.stdout.on("data",d=>o+=d);p.stderr.on("data",d=>e+=d);
    p.on("error",x=>resolve({code:-1,out:o,err:x.code==="ENOENT"?`No se encontró «${cmd}». Instálalo (en Ubuntu/WSL: sudo apt install nasm binutils gcc)`:x.message}));
    p.on("close",(code,sig)=>resolve({code,out:o,err:e,timeout:sig==="SIGTERM"}));
    p.stdin.on("error",()=>{});p.stdin.end(input);
  });
}

async function analizar(src){
  if(!fs.existsSync(BIN))return{error:"No se encontró el analizador. Ejecuta primero: npm run build"};
  const r=await sh(BIN,[],{input:src});
  if(r.code===-1)return{error:r.err};
  const output=r.out.split("\n").filter(l=>!/^=+$|ANALIZADOR SINT|Ingrese cadenas/.test(l)).join("\n").trim();
  return{output,errors:r.err.trim(),ok:output.includes("Bloque valido")&&!r.err.trim()};
}

async function generarExe(asm){
  const dir=fs.mkdtempSync(path.join(os.tmpdir(),"el-"));
  fs.writeFileSync(path.join(dir,"programa.asm"),asm);
  const cmds=[["nasm",["-f","elf64","programa.asm","-o","programa.o"]],["ld",["programa.o","-o","programa"]]];
  let log="";
  for(const [c,a] of cmds){
    log+=`$ ${c} ${a.join(" ")}\n`;
    const r=await sh(c,a,{cwd:dir});
    const t=(r.out+r.err).trim();log+=t?t+"\n":"";
    if(r.code!==0){fs.rmSync(dir,{recursive:true,force:true});return{error:`falló «${c}»`,log}}
  }
  const id=crypto.randomUUID();builds.set(id,dir);
  setTimeout(()=>{builds.delete(id);fs.rmSync(dir,{recursive:true,force:true})},10*60*1000).unref();
  return{id,log:log+"Ejecutable generado."};
}

async function handle(j){
  const src=String(j.source||""),step=j.step||"run",r={analyzer:await analizar(src)};
  if(r.analyzer.error)return[500,r];
  if(!r.analyzer.ok){
    const m=/LINEA (\d+)/.exec(r.analyzer.errors);if(m)r.errorLine=+m[1];
    return[200,r];
  }
  let c;
  try{c=compile(src)}catch(e){r.compileError={l:e.l,msg:e.msg||e.message};return[200,r]}
  r.tdc=c.code.map(fmt).join("\n");r.warns=c.warns;
  if(step==="tdc")return[200,r];
  r.asm=genAsm(c.code,c.vars);
  if(step==="asm")return[200,r];
  let dir=builds.get(j.id);
  if(!dir){r.build=await generarExe(r.asm);if(r.build.error)return[200,r];dir=builds.get(r.build.id)}
  else r.build={id:j.id,log:"Se reutiliza el ejecutable ya generado."};
  if(step==="exe")return[200,r];
  const x=await sh(path.join(dir,"programa"),[],{cwd:dir,input:String(j.inputs||"").split(/\s+/).filter(Boolean).join("\n")+"\n"});
  r.run={out:x.out.trimEnd(),code:x.code,timeout:x.timeout};
  return[200,r];
}

http.createServer(async(req,res)=>{
  const url=req.url.split("?")[0];
  if(req.method==="GET"){
    const f=path.join(PUB,url==="/"?"index.html":path.basename(url));
    if(!fs.existsSync(f)){res.writeHead(404);return res.end("No encontrado")}
    res.writeHead(200,{"Content-Type":MIME[path.extname(f)]||"application/octet-stream"});
    return fs.createReadStream(f).pipe(res);
  }
  if(req.method==="POST"&&url==="/api/compile"){
    let b="";for await(const c of req){b+=c;if(b.length>1e6)return send(res,413,{error:"Código demasiado grande"})}
    let j;try{j=JSON.parse(b)}catch{return send(res,400,{error:"JSON inválido"})}
    try{const [code,r]=await handle(j);return send(res,code,r)}
    catch(e){return send(res,500,{error:"Error interno: "+e.message})}
  }
  res.writeHead(404);res.end("No encontrado");
}).listen(PORT,()=>console.log(`IDE EasyLang en http://localhost:${PORT}`));
