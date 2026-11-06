# IDE EasyLang — Universidad Mesoamericana

IDE web para el lenguaje EasyLang (archivos `.el`): abrir/editar/guardar, código intermedio (TDC),
ensamblador NASM x86-64, generación de ejecutable (nasm + ld) y ejecución.

**Integrantes**
- Juan Luis Cojtin Herrera — 202408007
- Sebastian Rodrigo Rodas Pineda — 202408060
- Arturo Alejandro Maldonado Orozco — 202308110

## Requisitos (Linux o WSL)
`node` (v18+), `gcc`, `nasm`, `binutils` (ld). Opcional: `bison` y `flex`.
```
sudo apt install nodejs gcc nasm binutils bison flex
```

## Uso
```
npm run build    # compila el analizador en C (analizador/)
npm start        # abre http://localhost:3000
```

## Arquitectura
- `analizador/` — lexer.l y parser.y (Flex/Bison). Valida la sintaxis; el backend le envía el código por stdin.
- `server.js` — backend HTTP (`POST /api/compile`, campo `step`: tdc | asm | exe | run).
- `compiler.js` — genera el TDC y el ASM NASM a partir del código fuente.
- `public/` — frontend (index.html y logo).
