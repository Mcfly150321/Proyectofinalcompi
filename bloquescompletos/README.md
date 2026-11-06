# 📚 Compilador de EasyLang (.bml) a Ensamblador x86 NASM

Este repositorio contiene la implementación completa de un compilador de extremo a extremo (*End-to-End*) para el lenguaje de programación imperativo **EasyLang** (archivos con extensión `.bml`). El compilador traduce código fuente de alto nivel a **Código de Tres Direcciones (TDC / TAC)** y, posteriormente, a código ensamblador **x86 de 32 bits** listo para ensamblarse con **NASM** y ejecutarse en Linux.

---

## 👥 Integrantes del Equipo (Universidad Mesoamericana)

* **Arturo Alejandro Maldonado Orozco** (Carné: 202308110)
* **Juan Luis Cojtin Herrera** (Carné: 202408007)
* **Sebastián Rodrigo Rodas Pineda** (Carné: 202408060)

---

## 🏗️ Arquitectura y Flujo de Compilación

El sistema se divide en dos fases principales (*Front-End* y *Back-End*):

```text
  [ Código Fuente .bml ]
            │
            ▼
    [ lexer.l (Flex) ]         ──> Tokenización y filtrado léxico
            │ (Tokens)
            ▼
    [ parser.y (Bison) ]       ──> Análisis sintáctico, semántica y emisión de TAC
            │
            ▼
    [ codigo_tdc.txt ]         ──> Código de Tres Direcciones (TAC)
            │
            ▼
   [ traductor.c (GCC) ]       ──> Mapeo a x86, registros y directivas
            │
            ▼
      [ salida.asm ]           ──> Código Ensamblador NASM (x86 32-bit)
            │
            ▼ (nasm -f elf32 & ld)
    [ Binario ELF32 ]          ──> Ejecutable nativo Linux
```

---

## 📁 Estructura del Proyecto

* **`lexer.l`**: Analizador léxico implementado en Flex.
* **`parser.y`** / **`parsersebastian.y`**: Analizador sintáctico y semántico implementado en Bison. Emite el código intermedio.
* **`traductor.c`**: Backend en C que procesa el Código de Tres Direcciones (`codigo_tdc.txt`) y genera código ensamblador Intel x86 de 32 bits (`salida.asm`).
* **`codigo_tdc.txt`**: Archivo intermedio generado automáticamente que contiene las cuádruplas/instrucciones de 3 direcciones.
* **`salida.asm`**: Archivo ensamblador final generado por `traductor`.
* **`reporte_compilador.tex`**: Documento formal en formato IEEE con la justificación técnica, gramáticas y resultados.
* **`codigosprueba/`**: Directorio con casos de prueba:
  * `test_b.bml`, `test_b2.bml`, `test_b3.bml`: Programas completos en EasyLang.
  * `ejemplo1.txt` - `ejemplo10.txt`: Pruebas de construcciones específicas.
  * `trampa1.txt` - `trampa7.txt`: Pruebas de estrés y casos límite (anidamientos, errores, sintaxis especial).

---

## 🔍 Explicación Detallada de los Componentes

### 1. Analizador Léxico (`lexer.l`)
Utiliza **Flex** para reconocer patrones mediante expresiones regulares:
* **Palabras reservadas**:
  * Estructura: `MAIN`, `BEGIN`, `END`.
  * Memoria e I/O: `ALLOCATE`, `INPUT`, `OUTPUT`.
  * Control condicional: `IF`, `THEN`, `ELSE`.
  * Ciclos: `FOR`, `TO`, `DO`, `WHILE`.
* **Operadores aritméticos y asignación**: `+`, `-`, `*`, `/`, `**` (potencia), `:=`.
* **Operadores relacionales y lógicos**: `<`, `>`, `<=`, `>=`, `==`, `<>`, `AND`, `OR`.
* **Comentarios**: Bloques delimitados por tres asteriscos:
  ```text
  *** Este es un comentario ***
  ```
* **Manejo de líneas y EOF**:
  * Cuenta líneas (`linea_actual`) para reportar la ubicación exacta de errores sintácticos.
  * En `<<EOF>>`, envía un `NEWLINE` final si el archivo no termina con salto de línea para evitar fallos de análisis.

---

### 2. Analizador Sintáctico y Semántico (`parser.y`)
Utiliza **Bison** con una gramática $LALR(1)$:
* **Semántica en la Unión (`%union`)**:
  * Maneja cadenas (`str`), enteros (`num`) y dos estructuras clave:
    * `IfInfo`: Guarda etiquetas de falso (`l_false`) y final (`l_end`).
    * `ForInfo`: Guarda la variable de iteración (`var`), el límite (`limit`) y etiquetas de control.
* **Declaración de Variables (`ALLOCATE`)**:
  * Sintaxis encadenada por dos puntos:
    ```pascal
    x:y:z:i:total ALLOCATE;
    ```
  * Por cada variable, emite en el TDC una directiva `DECL <nombre>`, que luego el backend reserva en memoria.
* **Estructuras de Control**:
  * **`IF-THEN-ELSE`**: Resuelve la ambigüedad del *dangling else* usando `%precedence REDUCE_NO_ELSE`. Emite saltos condicionales `ifz` (salto si es cero / falso) y saltos incondicionales `jmp`.
  * **`FOR`**: Inicializa la variable de control, crea la etiqueta de inicio de bucle, evalúa si sobrepasa el límite y al final del bloque incrementa la variable y salta al inicio.
  * **`DO ... WHILE(cond)`**: Ejecuta el bloque primero y al final evalúa la condición emitiendo un `ifnz` (salto si es distinto de cero / verdadero) hacia el inicio.
* **Generación de TAC / TDC**:
  * `nuevo_temp()` genera temporales únicos (`t1`, `t2`, ...).
  * `nueva_label()` genera etiquetas de salto únicas (`l1`, `l2`, ...).
  * Todo se escribe en el archivo `codigo_tdc.txt`.

---

### 3. Código de Tres Direcciones (TDC / TAC)
El TDC linealiza las instrucciones complejas. Ejemplo de lo que se genera internamente:
```text
DECL x
DECL total
t1 = total + 1
total = t1
t2 = x < 25
ifz t2 goto l1
...
```

---

### 4. Generador de Código Objeto (`traductor.c`)
Es el motor backend del compilador. Lee línea por línea `codigo_tdc.txt` y lo transforma en ensamblador x86:
* **Sección de Datos No Inicializados (`section .bss`)**:
  * Detecta cada `DECL <var>` y la traduce a:
    ```nasm
    <var> resd 1    ; Reserva 1 double-word (4 bytes, entero de 32 bits)
    ```
* **Mapeo y Reutilización de Registros (`eax` y `ecx`)**:
  * Implementa un seguimiento básico para evitar instrucciones `mov` redundantes cuando el valor ya se encuentra en `eax` o `ecx` (optimización *peephole*).
* **Traducción de Comparaciones**:
  * Transforma comparaciones en la secuencia canónica x86:
    ```nasm
    mov eax, [op1]
    cmp eax, [op2]
    set<cond> al      ; ej. setl, setg, setle, sete, setne
    movzx eax, al     ; Limpia la parte alta y deja 0 o 1 en eax
    ```
* **Salida del Programa**:
  * Añade al final de `_start` la interrupción de salida estándar de Linux:
    ```nasm
    mov eax, 1        ; sys_exit
    xor ebx, ebx      ; return 0
    int 0x80
    ```

---

## 🚀 Guía de Compilación y Ejecución

### Prerrequisitos en Linux
Tener instalados los paquetes de desarrollo:
```bash
sudo apt update
sudo apt install build-essential flex bison nasm
```

### Paso 1: Generar el Compilador (Front-End)
Compilar el lexer y el parser:
```bash
# 1. Generar analizador sintáctico en C
bison -d parser.y -o parser.tab.c

# 2. Generar analizador léxico en C
flex -o lex.yy.c lexer.l

# 3. Compilar el ejecutable del compilador
gcc -o compilador parser.tab.c lex.yy.c -lfl
```

### Paso 2: Compilar el Traductor (Back-End)
```bash
gcc -o traductor traductor.c
```

### Paso 3: Probar un Programa en EasyLang
Tomando como ejemplo `codigosprueba/test_b.bml`:

```bash
# 1. Ejecutar el compilador sobre el archivo fuente
./compilador < codigosprueba/test_b.bml

# Esto generará el archivo intermedio: codigo_tdc.txt

# 2. Ejecutar el traductor a ensamblador
./traductor

# Esto generará el archivo ensamblador: salida.asm

# 3. Ensamblar y enlazar el código x86 resultante
nasm -f elf32 salida.asm -o salida.o
ld -m elf_i386 salida.o -o programa_final

# 4. Ejecutar el programa nativo generado
./programa_final
```

---

## 🧠 Puntos Clave para Estudiar con el Grupo

1. **¿Cómo fluyen los datos semánticos en Bison?**
   * En las reglas, `$$` es el valor devuelto por la regla actual, y `$1`, `$2`, `$3` son los valores semánticos de los símbolos a la derecha.
   * Noten cómo en las expresiones aritméticas se llama a `nuevo_temp()` y se escribe en `codigo_tdc.txt` la cuádrupla generada.

2. **¿Cómo se resuelven los bucles y condicionales?**
   * Miren las estructuras `IfInfo` y `ForInfo`. Las etiquetas deben guardarse al abrir la estructura (`IF`, `FOR`, `DO`) para poder saber a qué etiqueta saltar cuando se cierra el bloque (`END`, `WHILE`).

3. **¿Cómo maneja el backend x86 las variables?**
   * Como no hay paso de parámetros por pila todavía (es un código lineal monolítico dentro de `MAIN`), todas las variables declaradas se ubican como memoria estática de 4 bytes en `.bss` con `resd 1`.

4. **El rol del Código de Tres Direcciones:**
   * Pregunta típica de examen/defensa: *¿Por qué no generar Ensamblador directamente desde Bison?*
   * **Respuesta:** Desacopla la lógica del lenguaje de la máquina. Si mañana queremos compilar para ARM o RISC-V, solo cambiamos `traductor.c`, sin tocar `parser.y` ni `lexer.l`.
