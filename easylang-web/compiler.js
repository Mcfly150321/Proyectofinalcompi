/* ---------- Léxico ---------- */
const KW=new Set("AND OR ALLOCATE MAIN INPUT OUTPUT IF ELSE FOR BEGIN END THEN WHILE TO DO".split(" "));
const NUM=/^-?\d+$/;
function lex(s){
  const T=[],re=/([ \t\r\n]+)|(\*\*\*(?:[^*]|\*[^*]|\*\*[^*])*\*\*\*)|(0|[1-9]\d*)|([A-Za-z_]\w*)|(\*\*|:=|>=|<=|==|<>|[-+*\/():;<>])|(.)/gy;
  let m,l=1;
  while(re.lastIndex<s.length&&(m=re.exec(s))){
    if(m[1]||m[2]){l+=(m[0].match(/\n/g)||[]).length;continue}
    if(m[3])T.push({t:"num",v:m[3],l});
    else if(m[4]){const v=m[4],u=(v=="to"||v=="do")?v.toUpperCase():v;T.push(KW.has(u)?{t:u,v:u,l}:{t:"id",v,l})}
    else if(m[5])T.push({t:m[5],v:m[5],l});
    else throw{l,msg:`Carácter no reconocido «${m[6]}»`};
  }
  T.push({t:"EOF",v:"fin del archivo",l});return T;
}

/* ---------- Sintaxis + generación de TDC (traducción dirigida por la sintaxis) ---------- */
function compile(src){
  const T=lex(src),code=[],vars=new Set(),warns=new Set();
  let p=0,nt=0,nl=0;
  const pk=()=>T[p].t,tk=()=>T[p++];
  const err=w=>{throw{l:T[p].l,msg:`Se esperaba ${w} y se encontró «${T[p].v}»`}};
  const ex=(t,w)=>pk()==t?tk():err(w||`«${t}»`);
  const tmp=()=>"t"+(++nt),lab=()=>"L"+(++nl);
  const emit=(o,a,b,r)=>code.push({o,a,b,r});
  const lbl=r=>emit("label",null,null,r);
  const use=v=>{if(!vars.has(v))warns.add(`«${v}» se usa sin declarar con ALLOCATE`)};
  const bin=(o,a,b)=>{const r=tmp();emit(o,a,b,r);return r};

  function atom(){
    const t=pk();
    if(t=="num")return tk().v;
    if(t=="id"){const v=tk().v;use(v);return v}
    if(t=="-"){tk();if(pk()=="num")return"-"+tk().v;const r=tmp();emit("neg",atom(),null,r);return r}
    if(t=="("){tk();const r=expr();ex(")");return r}
    err("un número, una variable o «(»");
  }
  function pow(){const a=atom();if(pk()=="**"){tk();return bin("**",a,pow())}return a}
  function term(){let a=pow();while(pk()=="*"||pk()=="/"){const o=tk().t;a=bin(o,a,pow())}return a}
  function expr(){let a=term();while(pk()=="+"||pk()=="-"){const o=tk().t;a=bin(o,a,term())}return a}
  function rel(){
    const a=expr(),o=pk();
    if(!["<",">","<=",">=","==","<>"].includes(o))err("un operador relacional");
    tk();return bin(o,a,expr());
  }
  function andx(){let a=rel();while(pk()=="AND"){tk();a=bin("AND",a,rel())}return a}
  function orx(){let a=andx();while(pk()=="OR"){tk();a=bin("OR",a,andx())}return a}
  function cond(){ex("(");const r=orx();ex(")");return r}

  function stmts(stop){while(!stop.includes(pk())){if(pk()=="EOF")err(`«${stop[0]}»`);stmt()}}
  function block(){ex("BEGIN");stmts(["END"]);ex("END")}

  function stmt(){
    const t=pk();
    if(t=="id"){
      const first=tk().v;
      if(pk()==":="){
        tk();use(first);
        const n=code.length,r=expr(),last=code[code.length-1];
        if(code.length>n&&last.r===r&&/^t\d+$/.test(r))last.r=first;else emit("=",r,null,first);
        ex(";");return;
      }
      const ids=[first];
      while(pk()==":"){tk();ids.push(ex("id","un identificador").v)}
      ex("ALLOCATE");ex(";");ids.forEach(v=>vars.add(v));return;
    }
    if(t=="INPUT"){tk();const v=ex("id","un identificador").v;use(v);ex(";");emit("in",null,null,v);return}
    if(t=="OUTPUT"){tk();const v=ex("id","un identificador").v;use(v);ex(";");emit("out",v,null,null);return}
    if(t=="IF"){
      tk();let c=cond(),end=null;ex("THEN");
      for(;;){
        const nx=lab();emit("iff",c,null,nx);block();
        if(pk()=="ELSE"){
          tk();end=end||lab();emit("goto",null,null,end);lbl(nx);
          if(pk()=="IF"){tk();c=cond();ex("THEN");continue}
          block();lbl(end);return;
        }
        lbl(nx);if(end)lbl(end);return;
      }
    }
    if(t=="FOR"){
      tk();const v=ex("id","un identificador").v;use(v);ex(":=");
      emit("=",expr(),null,v);ex("TO");
      let lim=expr();ex("DO");
      if(!NUM.test(lim)){const x=tmp();emit("=",lim,null,x);lim=x}
      const top=lab(),end=lab();lbl(top);
      emit("iff",bin("<=",v,lim),null,end);block();
      emit("+",v,"1",v);emit("goto",null,null,top);lbl(end);return;
    }
    if(t=="DO"){
      tk();const top=lab();lbl(top);stmts(["WHILE"]);ex("WHILE");
      emit("if",cond(),null,top);return;
    }
    err("una sentencia (declaración, asignación, INPUT, OUTPUT, IF, FOR o DO)");
  }

  ex("MAIN");ex("BEGIN");stmts(["END"]);ex("END");ex("EOF","el fin del programa");
  return{code,vars:[...vars],warns:[...warns]};
}

/* ---------- Formato TDC ---------- */
function fmt(i){
  const o=i.o;
  if(o=="label")return i.r+":";
  const s=o=="="?`${i.r} = ${i.a}`:o=="neg"?`${i.r} = -${i.a}`:o=="in"?`read ${i.r}`:o=="out"?`print ${i.a}`:
    o=="goto"?`goto ${i.r}`:o=="iff"?`ifFalse ${i.a} goto ${i.r}`:o=="if"?`if ${i.a} goto ${i.r}`:`${i.r} = ${i.a} ${o} ${i.b}`;
  return"    "+s;
}

/* ---------- Generación de ASM (x86-64 NASM, Linux) ---------- */
function genAsm(code,declared){
  const N=new Set(declared),A=x=>NUM.test(x)?x:`[v_${x}]`,J=["label","goto","iff","if"];
  code.forEach(c=>[c.a,c.b,J.includes(c.o)?null:c.r].forEach(x=>x&&!NUM.test(x)&&N.add(x)));
  const S={"<":"l",">":"g","<=":"le",">=":"ge","==":"e","<>":"ne"};
  let s=`; Generado por el compilador EasyLang - x86-64 NASM (Linux)
; Ensamblar y enlazar:
;   nasm -f elf64 programa.asm -o programa.o && ld programa.o -o programa

section .bss
    buf resb 32
`+[...N].map(n=>`    v_${n} resq 1`).join("\n")+`

section .text
global _start
_start:
`;
  for(const c of code){
    const{o,a,b,r}=c,R=`[v_${r}]`;let L;
    if(o=="label"){s+=r+":\n";continue}
    if(o=="=")L=[`mov rax, ${A(a)}`,`mov ${R}, rax`];
    else if(o=="neg")L=[`mov rax, ${A(a)}`,"neg rax",`mov ${R}, rax`];
    else if(o=="in")L=["call read_int",`mov ${R}, rax`];
    else if(o=="out")L=[`mov rax, ${A(a)}`,"call print_int"];
    else if(o=="goto")L=["jmp "+r];
    else if(o=="iff"||o=="if")L=[`mov rax, ${A(a)}`,"cmp rax, 0",(o=="iff"?"je ":"jne ")+r];
    else{
      L=[`mov rax, ${A(a)}`,`mov rbx, ${A(b)}`];
      if(o=="/")L.push("cqo","idiv rbx");
      else if(o=="**")L=[`mov rdi, ${A(a)}`,`mov rsi, ${A(b)}`,"call pow"];
      else if(S[o])L.push("cmp rax, rbx","set"+S[o]+" al","movzx rax, al");
      else L.push({"+":"add rax, rbx","-":"sub rax, rbx","*":"imul rax, rbx",AND:"and rax, rbx",OR:"or rax, rbx"}[o]);
      L.push(`mov ${R}, rax`);
    }
    s+=`    ; ${fmt(c).trim()}\n    ${L.join("\n    ")}\n`;
  }
  return s+`
    mov rax, 60
    xor rdi, rdi
    syscall

; ---- rutinas de apoyo ----
pow:                    ; rax = rdi ** rsi
    mov rax, 1
.l: test rsi, rsi
    jle .e
    imul rax, rdi
    dec rsi
    jmp .l
.e: ret

print_int:              ; imprime rax y salto de línea
    lea rdi, [buf+31]
    mov byte [rdi], 10
    mov rcx, 10
    xor r8, r8
    test rax, rax
    jns .d
    neg rax
    mov r8, 1
.d: xor rdx, rdx
    div rcx
    add dl, '0'
    dec rdi
    mov [rdi], dl
    test rax, rax
    jnz .d
    test r8, r8
    jz .w
    dec rdi
    mov byte [rdi], '-'
.w: mov rsi, rdi
    lea rdx, [buf+32]
    sub rdx, rsi
    mov rax, 1
    mov rdi, 1
    syscall
    ret

read_int:               ; lee un entero de stdin (byte a byte) -> rax
    xor r8, r8
    xor r9, r9
.s: call getc
    cmp rax, -1
    je .f
    cmp al, '-'
    jne .t
    mov r8, 1
    jmp .s
.t: sub rax, '0'
    cmp rax, 9
    ja .s
.n: imul r9, r9, 10
    add r9, rax
    call getc
    cmp rax, -1
    je .f
    sub rax, '0'
    cmp rax, 9
    jbe .n
.f: mov rax, r9
    test r8, r8
    jz .z
    neg rax
.z: ret

getc:                   ; rax = siguiente byte de stdin, o -1 si no hay mas
    xor rax, rax
    xor rdi, rdi
    lea rsi, [buf]
    mov rdx, 1
    syscall
    cmp rax, 1
    jne .e
    movzx rax, byte [buf]
    ret
.e: mov rax, -1
    ret
`;
}

/* ---------- Intérprete del TDC ---------- */
function exec(code,queue){
  const M={},out=[],L={};
  code.forEach((c,i)=>{if(c.o=="label")L[c.r]=i});
  const v=a=>NUM.test(a)?+a:(M[a]??0),b2=x=>+x;
  const O={"+":(a,b)=>a+b,"-":(a,b)=>a-b,"*":(a,b)=>a*b,
    "/":(a,b)=>{if(!b)throw Error("División entre cero");return Math.trunc(a/b)},
    "**":(a,b)=>b<0?0:Math.trunc(a**b),
    "<":(a,b)=>b2(a<b),">":(a,b)=>b2(a>b),"<=":(a,b)=>b2(a<=b),">=":(a,b)=>b2(a>=b),
    "==":(a,b)=>b2(a==b),"<>":(a,b)=>b2(a!=b),AND:(a,b)=>b2(a&&b),OR:(a,b)=>b2(a||b)};
  let pc=0,n=0;
  while(pc<code.length){
    if(++n>2e6)throw Error("Posible ciclo infinito (más de 2 000 000 de instrucciones)");
    const c=code[pc++],o=c.o;
    if(o=="=")M[c.r]=v(c.a);
    else if(o=="neg")M[c.r]=-v(c.a);
    else if(o=="in"){
      let x=queue.length?queue.shift():null;
      if(x===null)throw Error(`Faltan entradas: no hay dato para INPUT ${c.r}. Escríbelos en el cuadro de entradas`);
      x=parseInt(x,10);if(isNaN(x))throw Error(`El valor de entrada para «${c.r}» no es un entero`);
      M[c.r]=x;
    }
    else if(o=="out")out.push(v(c.a));
    else if(o=="goto")pc=L[c.r];
    else if(o=="iff"){if(!v(c.a))pc=L[c.r]}
    else if(o=="if"){if(v(c.a))pc=L[c.r]}
    else if(o!="label")M[c.r]=O[o](v(c.a),v(c.b));
  }
  return{out,M};
}


module.exports={compile,fmt,genAsm,exec};
