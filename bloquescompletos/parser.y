%code requires {
typedef struct {
    char *l_false;
    char *l_end;
    int linea_inicio;
} IfInfo;

typedef struct {
    char *var;
    char *limit;
    char *l_start;
    char *l_end;
    int linea_inicio;
} ForInfo;
}

%code top {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int yylex(void);
void yyerror(const char *s);

/* Salida del Código de Tres Direcciones */
FILE *archivo_tdc = NULL;

void emitir(const char *formato, ...) {
    if (archivo_tdc) {
        va_list args;
        va_start(args, formato);
        vfprintf(archivo_tdc, formato, args);
        va_end(args);
    }
}

int num_temp = 1;
char* nuevo_temp(void) {
    char buf[32];
    sprintf(buf, "t%d", num_temp++);
    return strdup(buf);
}

int num_label = 1;
char* nueva_label(void) {
    char buf[32];
    sprintf(buf, "l%d", num_label++);
    return strdup(buf);
}

extern int linea_actual;
int whileopen = 0;
int foropen = 0;
int thenopen = 0;
int ifopen = 0;
int iniciowhile = 0;

typedef struct {
    char nombre[64];
    int declarada;
    int usada;
    int linea_declaracion;
} Simbolo;

Simbolo tabla_simbolos[200];
int total_simbolos = 0;
int hay_error_semantico = 0;

void declarar_var(const char *nombre, int linea) {
    for (int i = 0; i < total_simbolos; i++) {
        if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) return;
    }
    strcpy(tabla_simbolos[total_simbolos].nombre, nombre);
    tabla_simbolos[total_simbolos].declarada = 1;
    tabla_simbolos[total_simbolos].usada = 0;
    tabla_simbolos[total_simbolos].linea_declaracion = linea;
    total_simbolos++;
}

void usar_var(const char *nombre, int linea) {
    for (int i = 0; i < total_simbolos; i++) {
        if (strcmp(tabla_simbolos[i].nombre, nombre) == 0) {
            tabla_simbolos[i].usada = 1;
            return;
        }
    }
    hay_error_semantico = 1;
    printf(" -> LINEA %d: ERROR SEMÁNTICO: Variable '%s' no ha sido declarada.\n", linea, nombre);
}

void revisar_variables_no_usadas(void) {
    for (int i = 0; i < total_simbolos; i++) {
        if (tabla_simbolos[i].declarada && !tabla_simbolos[i].usada) {
            printf(" -> LINEA %d: AVISO (WARNING): Variable '%s' declarada pero nunca fue usada.\n",
                   tabla_simbolos[i].linea_declaracion, tabla_simbolos[i].nombre);
        }
    }
}
}

%union {
    char *str;
    int num;
    IfInfo if_info;
    ForInfo for_info;
}

%token <str> TK_SUMA TK_RESTA TK_DIVISION TK_MULTIPLICACION TK_POTENCIACION
%token <str> TK_NUMERO TK_ID
%token <str> TK_MAY TK_MEN TK_MAIG TK_MEIG TK_IG TK_NIG
%token TK_PAB TK_PCE
%token TK_AND TK_OR
%token TK_ASIG TK_EOS TK_DP
%token TK_ALLOCATE 
%token TK_MAIN TK_INPUT TK_OUTPUT TK_THEN TK_IF TK_ELSE
%token TK_FOR TK_DO TK_BEGIN TK_TO TK_END TK_WHILE
%token TK_COMENTARIO
%token NEWLINE

%type <str> variable variable_decl numero oparit simarit operador factores
%type <str> condicion logica simlog
%type <if_info> if_encabezado
%type <for_info> encabezado_for
%type <str> bloque1dw
%type <num> if for do end bloque_begin_end if_ramas

%precedence REDUCE_NO_ELSE
%precedence NEWLINE

%start programa
%expect 1
%%
programa:
    opt_inicio bloque
    ;

bloque:
    TK_MAIN opt_inicio TK_BEGIN {
        emitir("main:\n");
    } cuerpo TK_END opt_inicio {
        if (!hay_error_semantico) {
            printf("\nBloque valido codigo completo\n");
        }
    }
    ;

opt_inicio:
    %empty
  | opt_inicio NEWLINE
  | opt_inicio comentario
  ;

opt_nl:
    %empty
  | opt_nl NEWLINE
  ;

cuerpo:
    operacion
    ;

operacion:
    %empty
  | operacion expresion
  | operacion definicion
  | operacion ciclofor
  | operacion condicionar
  | operacion declarar
  | operacion dowhile
  | operacion NEWLINE
  | operacion cicloif
  | operacion lectura
  | operacion impresion
  | operacion comentario
  ;

comentario:
    TK_COMENTARIO {
        printf(" -> LINEA %d: CADENA VÁLIDA: comentario\n", linea_actual);
    }
    ;

lectura:
    leer
    ;

leer:
    input variable eos {
        emitir("        call input;\n");
        emitir("        pop %s;\n", $2);
        if (whileopen == 0 && foropen == 0 && thenopen == 0) {
            printf(" -> LINEA %d: CADENA VÁLIDA: LECTURA DE VARIABLE\n", linea_actual);
        }
    }
    ;

impresion:
    imprimir
    ;

imprimir:
    output variable eos {
        emitir("        push %s;\n", $2);
        emitir("        call output;\n");
        if (whileopen == 0 && foropen == 0 && thenopen == 0) {
            printf(" -> LINEA %d: CADENA VÁLIDA: IMPRESION DE VARIABLE\n", linea_actual);
        }
    }
    ;

output:
    TK_OUTPUT
    ;

input:
    TK_INPUT
    ;

expresion:
    logica NEWLINE
  | oparit NEWLINE
  | aritmetica NEWLINE
  ;

aritmetica:
    oparit eos
    ;

oparit:
    oparit simarit operador {
        char *t = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t, $1, $2, $3);
        $$ = t;
    }
  | operador {
        $$ = $1;
    }
  ;

simarit:
    sumar         { $$ = "+"; }
  | restar        { $$ = "-"; }
  | multiplicar   { $$ = "*"; }
  | dividir       { $$ = "/"; }
  | potenciar     { $$ = "**"; }
  ;

logica:
    operador simlog operador {
        char *t = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t, $1, $2, $3);
        $$ = t;
    }
  | logica TK_AND operador simlog operador {
        char *t_rel = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t_rel, $3, $4, $5);
        char *t_and = nuevo_temp();
        emitir("        %s=%s&&%s;\n", t_and, $1, t_rel);
        $$ = t_and;
    }
  | logica TK_OR operador simlog operador {
        char *t_rel = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t_rel, $3, $4, $5);
        char *t_or = nuevo_temp();
        emitir("        %s=%s||%s;\n", t_or, $1, t_rel);
        $$ = t_or;
    }
  ;

simlog:
    TK_MAY   { $$ = ">"; }
  | TK_MEN   { $$ = "<"; }
  | TK_MAIG  { $$ = ">="; }
  | TK_MEIG  { $$ = "<="; }
  | TK_IG    { $$ = "=="; }
  | TK_NIG   { $$ = "<>"; }
  ;

definicion:
    variable definir oparit eos {
        emitir("        %s=%s;\n", $1, $3);
        if (whileopen == 0 && foropen == 0 && thenopen == 0) {
            printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE A OPERACION\n", linea_actual);
        }
    }
    ;

condicionar:
    condicion NEWLINE
    ;

condicion:
    agrupa1 logica agrupa2 {
        $$ = $2;
    }
    ;

agrupa1:
    TK_PAB
    ;

agrupa2:
    TK_PCE
    ;

/* --- CICLO FOR --- */
for:
    TK_FOR { $$ = linea_actual; }
    ;

encabezado_for:
    for variable definir operador to operador do opt_nl {
        emitir("        %s=%s;\n", $2, $4);
        char *l_start = nueva_label();
        char *l_end = nueva_label();
        emitir("%s:\n", l_start);
        char *t_cond = nuevo_temp();
        emitir("        %s=%s<=%s;\n", t_cond, $2, $6);
        emitir("        ifz %s goto %s:\n", t_cond, l_end);

        $$.var = $2;
        $$.limit = $6;
        $$.l_start = l_start;
        $$.l_end = l_end;
        $$.linea_inicio = $1;
        foropen++;
    }
    ;

ciclofor:
    encabezado_for bloque_begin_end {
        char *t_inc = nuevo_temp();
        emitir("        %s=%s+1;\n", t_inc, $1.var);
        emitir("        %s=%s;\n", $1.var, t_inc);
        emitir("        jmp %s\n", $1.l_start);
        emitir("%s:\n", $1.l_end);
        foropen--;
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", $1.linea_inicio, $2);
    }
    ;

/* --- CICLO DO-WHILE --- */
do:
    TK_DO { $$ = linea_actual; }
    ;

bloque1dw:
    do opt_nl {
        char *l_start = nueva_label();
        emitir("%s:\n", l_start);
        $$ = l_start;
        iniciowhile = $1;
        whileopen++;
    }
    ;

bloque2dw:
    instrucciones masinstrucciones
    ;

dowhile:
    bloque1dw bloque2dw while condicion {
        emitir("        ifnz %s goto %s:\n", $4, $1);
        whileopen--;
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, linea_actual);
    }
    ;

/* --- CICLO IF / ELSE --- */
if:
    TK_IF { $$ = linea_actual; }
    ;

if_encabezado:
    if condicion then opt_nl {
        char *l_false = nueva_label();
        char *l_end = nueva_label();
        emitir("        ifz %s goto %s:\n", $2, l_false);
        $$.l_false = l_false;
        $$.l_end = l_end;
        $$.linea_inicio = $1;
        ifopen++;
    }
    ;

cicloif:
    if_encabezado bloque_begin_end {
        emitir("        jmp %s\n", $1.l_end);
        emitir("%s:\n", $1.l_false);
    } if_ramas {
        emitir("%s:\n", $1.l_end);
        ifopen--;
        if ($4 > 0) {
            printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF-ELSE\n", $1.linea_inicio, $4);
        } else {
            printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", $1.linea_inicio, $2);
        }
    }
    ;

cuerpo_instrucciones:
    instrucciones masinstrucciones
    ;

if_ramas:
    %empty %prec REDUCE_NO_ELSE {
        $$ = 0;
    }
  | else opt_nl bloque_begin_end {
        $$ = $3;
    }
  | else opt_nl if_encabezado bloque_begin_end {
        emitir("        jmp %s\n", $3.l_end);
        emitir("%s:\n", $3.l_false);
    } if_ramas {
        emitir("%s:\n", $3.l_end);
        ifopen--;
        $$ = ($6 > 0) ? $6 : $4;
    }
  ;

instrucciones:
    definicion
  | lectura
  | impresion
  | cicloif
  | ciclofor
  | dowhile
  | comentario
  ;

masinstrucciones:
    %empty
  | masinstrucciones instrucciones
  | masinstrucciones NEWLINE
  ;

bloque_begin_end:
    begin opt_nl cuerpo_instrucciones end opt_nl {
        $$ = $4;
    }
    ;

declarar:
    declaracion {
        printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual);
    }
    ;

declaracion:
    variable_decl lista_ids allocate eos
    ;

lista_ids:
    %empty
  | dospuntos variable_decl lista_ids
  ;

then:
    TK_THEN { thenopen = 1; }
    ;

begin:
    TK_BEGIN
    ;

else:
    TK_ELSE { thenopen = 1; }
    ;

dospuntos:
    TK_DP
    ;

eos:
    TK_EOS
    ;

to:
    TK_TO
    ;

end:
    TK_END { thenopen = 0; $$ = linea_actual; }
    ;

variable:
    TK_ID {
        usar_var($1, linea_actual);
        $$ = $1;
    }
    ;

variable_decl:
    TK_ID {
        declarar_var($1, linea_actual);
        emitir("        DECL %s\n", $1);
        $$ = $1;
    }
    ;

numero:
    TK_NUMERO { $$ = $1; }
    ;

sumar:
    TK_SUMA
    ;

restar:
    TK_RESTA
    ;

multiplicar:
    TK_MULTIPLICACION
    ;

dividir:
    TK_DIVISION
    ;

potenciar:
    TK_POTENCIACION
    ;

definir:
    TK_ASIG
    ;

operador:
    factores { $$ = $1; }
  | agrupa1 oparit agrupa2 { $$ = $2; }
  ;

factores:
    variable { $$ = $1; }
  | numero   { $$ = $1; }
  | restar numero {
        char buf[64];
        sprintf(buf, "-%s", $2);
        $$ = strdup(buf);
    }
  ;

allocate:
    TK_ALLOCATE 
    ;

while:
    TK_WHILE
    ;

%%

void yyerror(const char *s) {
    extern int yylineno;
    extern char *yytext;

    int linea = yylineno;
    const char *texto = yytext;

    if (yytext && yytext[0] == '\n') {
        linea = yylineno - 1;
        texto = "\\n";
    }

    fprintf(stderr, " -> LINEA %i: Error en %s (%s)\n", linea, texto ? texto : "", s);
}

int main(int argc, char **argv) {
    const char *nombre_salida = "codigo_tdc.txt";
    if (argc > 1) {
        nombre_salida = argv[1];
    }

    archivo_tdc = fopen(nombre_salida, "w+");
    if (!archivo_tdc) {
        fprintf(stderr, "Aviso: No se pudo abrir %s para escribir TDC.\n", nombre_salida);
    }

    printf("=====================================================\n");
    printf("   ANALIZADOR SINTÁCTICO DE SUMAS EN EASYLANG    \n");
    printf("=====================================================\n");
    printf("Ingrese cadenas para evaluar:\n\n");

    yyparse();
    revisar_variables_no_usadas();

    if (archivo_tdc) {
        fflush(archivo_tdc);
        rewind(archivo_tdc);
        if (!hay_error_semantico) {
            printf("\n=====================================================\n");
            printf("       CÓDIGO DE TRES DIRECCIONES (TDC) GENERADO     \n");
            printf("=====================================================\n\n");
            char linea_buf[256];
            while (fgets(linea_buf, sizeof(linea_buf), archivo_tdc)) {
                printf("%s", linea_buf);
            }
            printf("\n[TDC guardado exitosamente en: %s]\n", nombre_salida);
        } else {
            printf("\n[TDC no generado debido a errores semanticos]\n");
        }
        fclose(archivo_tdc);
    }

    return 0;
}
