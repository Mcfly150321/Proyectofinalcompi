%code top {
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);

int contador = 0;
int c_suma = 0;
int c_resta = 0;
int c_multi = 0;  
int c_divi = 0;
int c_expo = 0;
extern int linea_actual; /* <--- Traemos la variable desde Flex */
}

%token TK_SUMA TK_RESTA TK_DIVISION TK_MULTIPLICACION TK_POTENCIACION
%token TK_NUMERO TK_ID
%token TK_PAB TK_PCE
%token TK_MAY TK_MEN TK_MAIG TK_MEIG TK_IG TK_NIG
%token TK_AND TK_OR
%token TK_ASIG TK_EOS TK_COMA
%token TK_ALLOCATE TK_MAIN TK_INPUT TK_OUTPUT TK_IF TK_ELSE TK_DEC
%token NEWLINE DOLLAR VACIO

%%
inicio:
    %empty
  | inicio linea
  ;

linea:
    { contador = 0; c_suma=0; c_resta=0; c_multi=0; c_divi=0; c_expo=0;} 
    operador extension NEWLINE {
        int l = linea_actual - 1; 
        
        if (contador == 1 && c_suma == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: SUMA SIMPLE\n", l);
        } 
        else if (contador == 1 && c_resta == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: RESTA SIMPLE\n", l);
        } 
        else if (contador == 1 && c_multi == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: MULTIPLICACIÓN SIMPLE\n", l);
        } 
        else if (contador == 1 && c_divi == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: DIVISIÓN SIMPLE\n", l);
        } 
        else if (contador == 1 && c_expo == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: POTENCIACIÓN SIMPLE\n", l);
        }
        else if (contador > 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: OPERACIÓN COMPUESTA (Contador: %d)\n", l, contador);
        } else {
            printf(" -> LINEA %d: CADENA VÁLIDA: SOLO UN OPERANDO SUELTO\n", l);
        }
    }
  | declaracion NEWLINE {
        printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual - 1);
    }
  | NEWLINE        { /* ignorar líneas vacías */ }
  | error NEWLINE  { printf(" -> LINEA %d: CADENA INVÁLIDA\n", linea_actual - 1); yyerrok; }
  ;

extension:
    %empty
  | extension suma  { contador++; c_suma++; }
  | extension resta { contador++; c_resta++; }
  | extension multuplicacion { contador++; c_multi++; }
  | extension division { contador++; c_divi++; }
  | extension potenciacion { contador++; c_expo++; }
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
    ;
operador:
    TK_NUMERO
  | TK_ID
  | variable
  ;

declaracion:
    TK_DEC variable otra_variable opc_eos
  ;
opc_eos:
    TK_EOS
  | %empty
  ;
otra_variable: TK_COMA variable otra_variable
    | %empty
    ;
variable:  DOLLAR TK_ID
    ;

%%

void yyerror(const char *s) {
    /* Manejo discreto del error */
}

int main(void) {
    printf("=====================================================\n");
    printf("   ANALIZADOR SINTÁCTICO DE SUMAS EN EASYLANG    \n");
    printf("=====================================================\n");
    yyparse();
    return 0;
}
