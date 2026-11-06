%code requires {
typedef struct {
    char *l_false;
    char *l_end;
} IfInfo;

typedef struct {
    char *var;
    char *limit;
    char *l_start;
    char *l_end;
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
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);

    if (archivo_tdc) {
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
}

%union {
    char *str;
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

%type <str> variable numero oparit simarit operador factores
%type <str> condicion logica simlog
%type <if_info> if_encabezado
%type <for_info> encabezado_for
%type <str> bloque1dw

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
    } cuerpo TK_END opt_inicio
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
    TK_COMENTARIO
    ;

lectura:
    leer
    ;

leer:
    input variable eos {
        emitir("        call input;\n");
        emitir("        pop %s;\n", $2);
    }
    ;

impresion:
    imprimir
    ;

imprimir:
    output variable eos {
        emitir("        push %s;\n", $2);
        emitir("        call output;\n");
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
ciclofor:
    encabezado_for bloque_begin_end {
        char *t_inc = nuevo_temp();
        emitir("        %s=%s+1;\n", t_inc, $1.var);
        emitir("        %s=%s;\n", $1.var, t_inc);
        emitir("        jmp %s\n", $1.l_start);
        emitir("%s:\n", $1.l_end);
    }
    ;

encabezado_for:
    for variable definir operador to operador do opt_nl {
        /* $2 es var, $4 es valor inicial, $6 es límite */
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
    }
    ;

/* --- CICLO DO-WHILE --- */
dowhile:
    bloque1dw bloque2dw while condicion {
        emitir("        ifnz %s goto %s:\n", $4, $1);
    }
    ;

bloque1dw:
    do opt_nl {
        char *l_start = nueva_label();
        emitir("%s:\n", l_start);
        $$ = l_start;
    }
    ;

bloque2dw:
    instrucciones masinstrucciones
    ;

/* --- CICLO IF / ELSE --- */
cicloif:
    if_encabezado bloque_begin_end {
        emitir("        jmp %s\n", $1.l_end);
        emitir("%s:\n", $1.l_false);
    } if_ramas {
        emitir("%s:\n", $1.l_end);
    }
    ;

if_encabezado:
    if condicion then opt_nl {
        char *l_false = nueva_label();
        char *l_end = nueva_label();
        emitir("        ifz %s goto %s:\n", $2, l_false);
        $$.l_false = l_false;
        $$.l_end = l_end;
    }
    ;

cuerpo_instrucciones:
    instrucciones masinstrucciones
    ;

if_ramas:
    %empty %prec REDUCE_NO_ELSE
  | else opt_nl bloque_begin_end
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
    begin opt_nl cuerpo_instrucciones end opt_nl
    ;

declarar:
    declaracion
    ;

declaracion:
    variable lista_ids allocate eos
    ;

lista_ids:
    %empty
  | dospuntos variable lista_ids
  ;

then:
    TK_THEN
    ;

begin:
    TK_BEGIN
    ;

if:
    TK_IF
    ;

else:
    TK_ELSE
    ;

dospuntos:
    TK_DP
    ;

eos:
    TK_EOS
    ;

for:
    TK_FOR
    ;

do:
    TK_DO
    ;

to:
    TK_TO
    ;

end:
    TK_END
    ;

variable:
    TK_ID { $$ = $1; }
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

    archivo_tdc = fopen(nombre_salida, "w");
    if (!archivo_tdc) {
        fprintf(stderr, "Aviso: No se pudo abrir %s para escribir TDC.\n", nombre_salida);
    }

    yyparse();

    if (archivo_tdc) {
        fclose(archivo_tdc);
        printf("\n[TDC guardado exitosamente en: %s]\n", nombre_salida);
    }

    return 0;
}
