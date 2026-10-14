%code top {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);
void imprimir_aritmetica(void);
void imprimir_logica(void);

int contador = 0;
int contador2=0;

/*
int c_suma = 0;
int c_resta = 0;
int c_multi = 0;  
int c_divi = 0;
int c_expo = 0;
int c_definicion = 0;
 */

char tipoaritmetica[20] = ""; 
char tipologica[20]="";
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
%token TK_ASIG TK_EOS TK_DP
%token TK_ALLOCATE TK_MAIN TK_INPUT TK_OUTPUT TK_IF TK_ELSE
%token TK_FOR TK_DO TK_BEGIN TK_TO TK_END
%token NEWLINE

%start inicio

%%

inicio:
    operacion
  ;
operacion:
    %empty
  | operacion expresion
  | operacion definir2
  | operacion ciclofor
  | operacion condicion
  |operacion declarar
  |NEWLINE
  | error NEWLINE { parisopen = 0; contador = 0; contador2 = 0; printf(" CADENA INVÁLIDA\n"); yyerrok; }
  ;




  /*aca viene la logica con la que se esctructuran las expresiones logicas y aritmeticas */
expresion:
    logica NEWLINE     { imprimir_logica(); }
  | aritmetica NEWLINE { imprimir_aritmetica(); }
  ;


aritmetica:
operador simarit operador otraaritmetica
;
otraaritmetica:
%empty 
| simarit operador otraaritmetica {contador++; /*esto apra incrementar el contador de simbolos en la operacion */}
;
simarit:
sumar {strcpy(tipoaritmetica, "SUMA");}
|restar {strcpy(tipoaritmetica, "RESTA");}
|multiplicar {strcpy(tipoaritmetica, "MULTIPLICACION");}
|dividir {strcpy(tipoaritmetica, "DIVISION");}
|potenciar {strcpy(tipoaritmetica, "POTENCIACION");}
;



logica:
operador simlog operador otralogica;
otralogica:
 %empty
 |conectorlogico operador simlog operador otralogica {contador2++;}
;
conectorlogico:
TK_AND
| TK_OR
;
simlog:
    TK_MAY {strcpy(tipologica, "MAYOR QUE");}
  | TK_MEN {strcpy(tipologica, "MENOR QUE");}
  | TK_MAIG {strcpy(tipologica, "MAYOR O IGUAL");}
  | TK_MEIG {strcpy(tipologica, "MENOR O IGUAL");;}
  | TK_IG {strcpy(tipologica, "IGUAL");}
  | TK_NIG {strcpy(tipologica, "DISTINTO");}
  ;


/*aca viene toda la logica de la definicion de una variable */
definir2:
definicion NEWLINE
;
definicion:
    variable definir numero{
     printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE\n", linea_actual); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
    ;


/*aca viene la logica de las condicones entre parentesis */
condicion:
  agrupa1 logica agrupa2 NEWLINE { contador2=0; printf(" -> LINEA %d: CADENA VÁLIDA: AGRUPACIÓN DE CONDICION\n", linea_actual - 1); }
  ;
agrupa1:
    TK_PAB {parisopen++;}
  ;
agrupa2:
    TK_PCE {parisopen--;}
  ;

/*aca viene la logica del clco for */
ciclofor:
bloque1 bloque2 bloque3 fin {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);}
;

bloque1:
for variablefor to operador do NEWLINE {iniciofor=linea_actual-1;}
;
bloque2:
begin NEWLINE 
;

bloque3:
instrucciones masinstrucciones /*observa que aca la logica de extension es distinta porque arranca en un nivel 
arriba, con la logica con la que extendemops las operaciones las instruccuiones deberian extenderse en el bloque instrucciones
eso no afecta nada perio para lleavr una logica prolija no estaria de mas estandarizar todo*/
;

instrucciones:
variable definir nuevovalor eos NEWLINE { contador = 0; }
;
nuevovalor:
numero
|aritmetica
;
masinstrucciones:
    %empty
  | masinstrucciones instrucciones
  ;

fin:
end {finfor=linea_actual;}
|end NEWLINE {finfor=linea_actual-1;}
;

variablefor:
variable definir operador
;

/*aca integrqamos la logica de declaradciones con allocate */

declarar:
declaracion {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual);}
|declaracion NEWLINE   {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual - 1);}
;
declaracion:
    TK_ID lista_ids TK_ALLOCATE TK_EOS
  ;

lista_ids:
    %empty
  | TK_DP TK_ID lista_ids
  ;


/*aca vienen tokens necesarios para operar con el programa */

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
variable:
    TK_ID
  ;
numero:
    TK_NUMERO
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
    variable
  | numero
  ;


/* se comentan porque no se van a usar todavia 
allocate:
TK_ALLOCATE 
;
main:
TK_MAIN
;
input: 
TK_INPUT
;
output: 
TK_OUTPUT
;
if:
TK_IF
;
else:
TK_ELSE
;


*/






/* 
expresion:
linea2
|linea2 NEWLINE
;
linea2:
    variable seguirvariable
    | numero seguirnumero
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

definicion:
    definir numero{
        c_definicion++;
    }
    ;
originalmente el newline esta definido hasta el bloque comparar, quuizas convendria, para usar comparacion en  otras partes, mover el newline
al bloque de segurvariable por temas de que la comparacuon consuma la sentencia de comparaciion sin precisar saltos de linea 
comparacion:
 simlog operador extender
 ;

 extender:
    %empty
  | extensor operador simlog operador extender {strcpy(tipo, "CONDICION COMPUESTA");}
  ;
  */




/*

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
resta:
    restar operador
;
multuplicacion:
    multiplicar operador
  ;
division:
    dividir operador
  ;
potenciacion:
    potenciar operador
  ;

*/

%%

void yyerror(const char *s) {
    extern int yylineno;
    extern char *yytext;

    int linea = yylineno;
    const char *texto = yytext;

    /*si el error fue causado por el salto de línea pertenece a
     la liuneaque acaba de terminar*/
    if (yytext[0] == '\n') {
        linea = yylineno - 1;
        texto = "\\n";
    }

    fprintf(stderr, " -> LINEA %i: Error en %s, ", linea, texto);
}


/*se declaran estas funcones para sacar toda la logica que
estaba metida en el bloque de opreaciones, para ser mas limpios */
void imprimir_aritmetica(void) {
    printf(" -> LINEA %d: CADENA VÁLIDA: operacion aritmetica", linea_actual - 1);
    if (contador == 0) {
        printf(" %s\n", tipoaritmetica);
    } else {
        printf(" compuesta\n");
    }
    contador = 0; 
}

void imprimir_logica(void) {
    if (parisopen == 0) {
        printf(" -> LINEA %d: CADENA VÁLIDA: operacion logica", linea_actual - 1);
        if (contador2 == 0) {
            printf(" %s\n", tipologica);
        } else {
            printf(" compuesta\n");
        }
    }
    contador2 = 0; 
}

int main(void) {
    printf("=====================================================\n");
    printf("   ANALIZADOR SINTÁCTICO DE SUMAS EN EASYLANG    \n");
    printf("=====================================================\n");
    printf("Ingrese cadenas para evaluar:\n\n");
    yyparse();
    return 0;
}
