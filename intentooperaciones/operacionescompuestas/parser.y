%code top {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);

int contador = 0;
int c_suma = 0;
int c_resta = 0;
int c_multi = 0;  
int c_divi = 0;
int c_expo = 0;
int c_definicion = 0;
char tipo[20] = ""; 
extern int linea_actual;
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
  | operacion linea2
  ;
linea2:
    variable seguirvariable
    | numero seguirnumero
    | error NEWLINE { printf(" -> LINEA %d: CADENA INVÁLIDA\n", linea_actual - 1); yyerrok;}
    ;

seguirvariable:
   definicion {printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE\n", linea_actual - 1);}
  | operando 
  | comparacion
  ;

seguirnumero:
    operando 
  ;

operando:
 { contador = 0; c_suma=0; c_resta=0; c_multi=0; c_divi=0; c_expo=0;} extension NEWLINE {
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
        } 
        else {
            printf(" -> LINEA %d: CADENA VÁLIDA: SOLO UN OPERANDO SUELTO\n", l);
        }

    } 
        ;

extension:
    %empty
  | extension suma  { contador++; c_suma++; }
  | extension resta { contador++; c_resta++; }
  | extension multuplicacion { contador++; c_multi++; }
  | extension division { contador++; c_divi++; }
  | extension potenciacion { contador++; c_expo++; }
  ;
  

definicion:
    definir numero NEWLINE{
        c_definicion++;
    }
    ;

comparacion:
 comparar numero NEWLINE {printf(" -> LINEA %d: CADENA VÁLIDA: COMPARACIÓN DEL TIPO %s\n", linea_actual-1, tipo);}
 | comparar variable NEWLINE {printf(" -> LINEA %d: CADENA VÁLIDA: COMPARACIÓN DEL TIPO %s\n", linea_actual-1, tipo);}
 ;

comparar:
    TK_MAY {strcpy(tipo, "MAYOR QUE");}
  | TK_MEN {strcpy(tipo, "MENOR QUE");}
  | TK_MAIG {strcpy(tipo, "MAYOR O IGUAL");}
  | TK_MEIG {strcpy(tipo, "MENOR O IGUAL");;}
  | TK_IG {strcpy(tipo, "IGUAL");}
  | TK_NIG {strcpy(tipo, "DISTINTO");}
  ;
/* optamos por una mejor opcion, conservamos el linea_actual-1 y el consumo de newline, y ahora en el bloque comparar se identifica el tipo*/
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
    variable
  | numero
  ;

variable:
    TK_ID
  ;
numero:
    TK_NUMERO
  ;
definir:
    TK_ASIG
  ;

/*



linea:
    
    variable definicion {printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE\n", linea_actual - 1);}
    |
  | NEWLINE        { }
  | error NEWLINE  { printf(" -> LINEA %d: CADENA INVÁLIDA\n", linea_actual - 1); yyerrok; }
  ;
*/
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
