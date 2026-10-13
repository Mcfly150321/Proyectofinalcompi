%code top {
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);

int contador = 0;
extern int linea_actual; /* <--- Traemos la variable desde Flex */
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
    { contador = 0; } operador extension NEWLINE {
        /* Restamos 1 porque el NEWLINE ya fue procesado por Flex e incrementó la línea */
        int l = linea_actual - 1; 
        
        if (contador == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: SUMA/RESTA SIMPLE\n", l);
        } else if (contador > 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: OPERACIÓN COMPUESTA (Contador: %d)\n", l, contador);
        } else {
            printf(" -> LINEA %d: CADENA VÁLIDA: SOLO UN OPERANDO SUELTO\n", l);
        }
    }
  | NEWLINE        { /* ignorar líneas vacías */ }
  | error NEWLINE  { printf(" -> LINEA %d: CADENA INVÁLIDA\n", linea_actual - 1); yyerrok; }
  ;
extension:
    %empty
  | extension suma  { contador++; }
  | extension resta { contador++; }
  | extension multuplicacion { contador++; }
  | extension division { contador++; }
  | extension potenciacion { contador++; }
  ;
  
suma:
     sumar operador
  ;

sumar:
    TK_SUMA
  ;

resta:
    restar operador
;
restar:
TK_RESTA
;
multuplicacion:
    multiplicar operador
  ;
multiplicar:
    TK_MULTIPLICACION
  ;
division:
    dividir operador
  ;
dividir:
    TK_DIVISION
  ;
potenciacion:
    potenciar operador
  ;
potenciar:
    TK_POTENCIACION
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
