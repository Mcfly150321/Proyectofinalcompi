%{
#include <stdio.h>
#include <stdlib.h>

extern int   yylex(void);
extern int   yylineno;
extern char *yytext;
extern FILE *yyin;
extern int   errores_lexicos;

int errores_sintacticos = 0;
void yyerror(const char *s);
%}

%define parse.error verbose

%token TK_POTENCIACION TK_SUMA TK_RESTA TK_DIVISION TK_MULTIPLICACION
%token TK_NUMERO TK_ID
%token TK_AND TK_OR
%token TK_ALLOCATE TK_MAIN TK_INPUT TK_OUTPUT
%token TK_IF TK_THEN TK_ELSE
%token TK_FOR TK_TO TK_DO TK_WHILE
%token TK_BEGIN TK_END
%token TK_ASIG TK_DP TK_EOS TK_PAB TK_PCE
%token TK_MAY TK_MEN TK_MAIG TK_MEIG TK_IG TK_NIG
%token TK_ERROR

%start programa

%%

/* ---------- Programa ---------- */
programa
    : TK_MAIN TK_BEGIN lista_sentencias TK_END
    ;

lista_sentencias
    : lista_sentencias sentencia
    | sentencia
    ;

/* ---------- Sentencias ---------- */
sentencia
    : declaracion TK_EOS
    | asignacion  TK_EOS
    | lectura     TK_EOS
    | escritura   TK_EOS
    | sentencia_if
    | sentencia_for
    | sentencia_dowhile
    ;

/* a:b:c ALLOCATE */
declaracion
    : lista_ids TK_ALLOCATE
    ;

lista_ids
    : TK_ID
    | lista_ids TK_DP TK_ID
    ;

asignacion
    : TK_ID TK_ASIG expresion
    ;

lectura
    : TK_INPUT TK_ID
    ;

escritura
    : TK_OUTPUT TK_ID
    ;

/* ---------- IF - ELSE ---------- */
sentencia_if
    : TK_IF TK_PAB condicion TK_PCE TK_THEN bloque parte_else
    ;

parte_else
    : TK_ELSE bloque
    | %empty
    ;

bloque
    : TK_BEGIN lista_sentencias TK_END
    ;

/* ---------- FOR ---------- */
sentencia_for
    : TK_FOR TK_ID TK_ASIG expresion TK_TO expresion TK_DO bloque
    ;

/* ---------- DO - WHILE ---------- */
sentencia_dowhile
    : TK_DO lista_sentencias TK_WHILE TK_PAB condicion TK_PCE
    | TK_DO lista_sentencias TK_WHILE TK_PAB condicion TK_PCE TK_EOS
    ;

/* ---------- Condiciones (AND con mayor precedencia que OR) ---------- */
condicion
    : condicion TK_OR cond_and
    | cond_and
    ;

cond_and
    : cond_and TK_AND cond_simple
    | cond_simple
    ;

cond_simple
    : expresion op_relacional expresion
    ;

op_relacional
    : TK_MAY | TK_MEN | TK_MAIG | TK_MEIG | TK_IG | TK_NIG
    ;

/* ---------- Expresiones ---------- */
expresion
    : expresion TK_SUMA  termino
    | expresion TK_RESTA termino
    | termino
    ;

termino
    : termino TK_MULTIPLICACION unario
    | termino TK_DIVISION       unario
    | unario
    ;

unario
    : TK_RESTA unario
    | potencia
    ;

/* exponente ** base  (ej: 2**x  = x elevado a la 2). Asociativa a la derecha */
potencia
    : factor TK_POTENCIACION potencia
    | factor
    ;

factor
    : TK_PAB expresion TK_PCE
    | TK_ID
    | TK_NUMERO
    ;

%%

void yyerror(const char *s) {
    errores_sintacticos++;
    fprintf(stderr, "Error sintáctico en línea %d: %s (cerca de '%s')\n",
            yylineno, s, yytext);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) { perror("No se pudo abrir el archivo"); return 1; }
    }
    int r = yyparse();
    if (r == 0 && errores_lexicos == 0 && errores_sintacticos == 0) {
        printf("Sintaxis correcta\n");
        return 0;
    }
    printf("Sintaxis incorrecta\n");
    return 1;
}