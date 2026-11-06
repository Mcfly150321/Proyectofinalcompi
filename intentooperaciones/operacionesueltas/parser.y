%code top {
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
}

%token TK_SUMA TK_RESTA TK_DIVISION TK_MULTIPLICACION TK_POTENCIACION
%token TK_NUMERO TK_ID
%token TK_PAB TK_PCE
%token TK_MAY TK_MEN TK_MAIG TK_MEIG TK_IG TK_NIG
%token TK_AND TK_OR
%token TK_ASIG TK_EOS
%token TK_ALLOCATE TK_MAIN TK_INPUT TK_OUTPUT TK_IF TK_ELSE
%token NEWLINE


%%

operacion:
    %empty
  | operacion linea
  ;

linea:
    suma NEWLINE   { printf("CADENA VÁLIDA, SUMA\n"); }
  | resta NEWLINE {printf("CADENA VALIDA, RESTA\n");}
  | NEWLINE        { /* ignorar líneas vacías */ }
  | error NEWLINE  { printf(" -> CADENA INVÁLIDA\n"); yyerrok; }
  ;

suma:
    operador sumar operador
  ;

sumar:
    TK_SUMA
  ;

resta:
    operador restar operador
;

restar:
TK_RESTA
;

operador:
    TK_NUMERO
  | TK_ID
  ;

%%

void yyerror(const char *s) {
    /* Manejo discreto del error */
}

int main(void) {
    printf("=====================================================\n");
    printf("   ANALIZADOR SINTÁCTICO DE SUMAS EN EASYLANG    \n");
    printf("=====================================================\n");
    printf("Ingrese cadenas para evaluar:\n\n");
    yyparse();
    return 0;
}
