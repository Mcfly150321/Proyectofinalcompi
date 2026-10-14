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
int iniciofor = 0;
int finfor = 0;
int parisopen=0;
extern int linea_actual;
}

%token TK_SUMA TK_RESTA TK_DIVISION TK_MULTIPLICACION TK_POTENCIACION
%token TK_NUMERO TK_ID
%token TK_PAB TK_PCE
%token TK_MAY TK_MEN TK_MAIG TK_MEIG TK_IG TK_NIG
%token TK_AND TK_OR
%token TK_ASIG TK_EOS
%token TK_ALLOCATE TK_MAIN TK_INPUT TK_OUTPUT TK_IF TK_ELSE
%token TK_FOR TK_DO TK_BEGIN TK_TO TK_END
%token NEWLINE

%start arranque

%%

arranque:
    operacion
  ;
operacion:
    %empty
  | operacion expresion
  | operacion ciclofor
  | operacion condicion
    | error NEWLINE{ printf(" CADENA INVÁLIDA\n"); yyerrok; }
  ;

expresion:
linea2
|linea2 NEWLINE
;
linea2:
    variable seguirvariable
    | numero seguirnumero
    ;
condicion:
  agrupa1 expresion agrupa2 NEWLINE { printf(" -> LINEA %d: CADENA VÁLIDA: AGRUPACIÓN DE CONDICION\n", linea_actual - 1); }
  ;
agrupa1:
    TK_PAB {parisopen++;}
  ;
agrupa2:
    TK_PCE {parisopen--;}
  ;
seguirvariable:
   definicion {printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE\n", linea_actual);}
  | operando
  | comparacion {if (parisopen== 0 ){
    {printf(" -> LINEA %d: CADENA VÁLIDA: COMPARACIÓN DEL TIPO %s\n", linea_actual-1, tipo);}
    }
  }
   ;

seguirnumero:
    operando
    | comparacion  {if (parisopen== 0 ){
    {printf(" -> LINEA %d: CADENA VÁLIDA: COMPARACIÓN DEL TIPO %s\n", linea_actual-1, tipo);}
    }
  }
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
begin:
TK_BEGIN
;
to:
TK_TO
;
end:
TK_END
;

ciclofor:
bloque1 bloque2 bloque3 fin {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);}
;

bloque1:
for iniciar to operador do NEWLINE {iniciofor=linea_actual-1;}
;
bloque2:
begin NEWLINE 
;

bloque3:
instrucciones masinstrucciones
;

masinstrucciones:
    %empty
  | masinstrucciones instrucciones
  ;

fin:
end {finfor=linea_actual;}
|end NEWLINE {finfor=linea_actual-1;}
;

iniciar:
variable definir operador
;

instrucciones:
variable definir nuevovalor eos NEWLINE
;

nuevovalor:
numero
|larga extension
;

operando:
 { contador = 0; c_suma=0; c_resta=0; c_multi=0; c_divi=0; c_expo=0;} extension {
        int l = linea_actual - 1; 
        if (parisopen== 0 ){
        if (contador == 1 && c_suma == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: SUMA SIMPLE\n", linea_actual-1);
        } 
        else if (contador == 1 && c_resta == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: RESTA SIMPLE\n", linea_actual-1);
        } 
        else if (contador == 1 && c_multi == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: MULTIPLICACIÓN SIMPLE\n", linea_actual-1);
        } 
        else if (contador == 1 && c_divi == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: DIVISIÓN SIMPLE\n", linea_actual-1);
        } 
        else if (contador == 1 && c_expo == 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: POTENCIACIÓN SIMPLE\n", linea_actual-1);
        }
        else if (contador > 1) {
            printf(" -> LINEA %d: CADENA VÁLIDA: OPERACIÓN COMPUESTA (Contador: %d)\n", linea_actual-1, contador);
        } 
        else {
            printf(" -> LINEA %d: CADENA VÁLIDA: SOLO UN OPERANDO SUELTO\n", linea_actual-1);
        }
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
    definir numero{
        c_definicion++;
    }
    ;
/*originalmente el newline esta definido hasta el bloque comparar, quuizas convendria, para usar comparacion en  otras partes, mover el newline
al bloque de segurvariable por temas de que la comparacuon consuma la sentencia de comparaciion sin precisar saltos de linea */
comparacion:
 comparar operador extender
 ;


extender:
    %empty
  | extensor operador comparar operador extender {strcpy(tipo, "CONDICION COMPUESTA");}
  ;

extensor:
TK_AND
| TK_OR
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
  ;
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
larga:
operador sumar operador
| operador restar operador
|operador multiplicar operador
|operador dividir operador
|operador potenciar operador
;
%%

void yyerror(const char *s) {
   extern int yylineno;
    extern char *yytext;
   fprintf(stderr, " -> LINEA %i: Error cerca de %s, ", yylineno, yytext);
}

int main(void) {
    printf("=====================================================\n");
    printf("   ANALIZADOR SINTÁCTICO DE SUMAS EN EASYLANG    \n");
    printf("=====================================================\n");
    printf("Ingrese cadenas para evaluar:\n\n");
    yyparse();
    return 0;
}
