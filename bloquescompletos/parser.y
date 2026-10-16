%code top {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(const char *s);
void imprimir_aritmetica(void);
void imprimir_defnum(void);
void imprimir_defop(void);
void imprimir_logica(void);
void imprimir_condicion(void);
void imprimir_in(void);
void imprimir_out(void);

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
int foropen =0;
int parisopen=0;
int whileopen=0;
int iniciowhile=0;
int finwhile=0;
int inicioif=0;
int finif=0;
int ifopen=0;
int thenopen=0;
extern int linea_actual;
}

%token TK_SUMA TK_RESTA TK_DIVISION TK_MULTIPLICACION TK_POTENCIACION
%token TK_NUMERO TK_ID
%token TK_PAB TK_PCE
%token TK_MAY TK_MEN TK_MAIG TK_MEIG TK_IG TK_NIG
%token TK_AND TK_OR
%token TK_ASIG TK_EOS TK_DP
%token TK_ALLOCATE TK_MAIN TK_INPUT TK_OUTPUT TK_THEN TK_IF TK_ELSE
%token TK_FOR TK_DO TK_BEGIN TK_TO TK_END TK_WHILE
%token TK_COMENTARIO
%token NEWLINE

%precedence REDUCE_NO_ELSE
%precedence NEWLINE

%start inicio3

%%
inicio3:
opt_inicio inicio2
;
inicio2:
    TK_MAIN opt_inicio TK_BEGIN inicio TK_END opt_inicio{
        printf("\nBloque valido codigo completo\n");
    }
opt_inicio:
    %empty
  | opt_inicio NEWLINE
  | opt_inicio comentario
  ;

opt_nl:
    %empty
  | opt_nl NEWLINE
  ;
inicio:
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
TK_COMENTARIO {printf(" -> LINEA %d: CADENA VÁLIDA: comentario\n", linea_actual);}
;
lectura:
leer {imprimir_in();}
leer:
input variable eos
;
impresion:
imprimir{imprimir_out();}
;
imprimir:
output variable eos
;
output:
TK_OUTPUT
;
input:
TK_INPUT
;

  /*aca viene la logica con la que se esctructuran las expresiones logicas y aritmeticas */
expresion:
    logica NEWLINE     { imprimir_logica(); }
  | aritmetica NEWLINE { imprimir_aritmetica(); }
  ;


aritmetica:
 oparit eos
;
oparit:
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
operador simlog operador otralogica
;
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
/*definir2:
definicion NEWLINE
;*/
definicion:
    variable definir operador eos{
      imprimir_defnum();/*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
    |variable definir aritmetica {
     imprimir_defop(); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
    ;


/*aca viene la logica de las condicones entre parentesis */
condicionar:
 condicion NEWLINE {imprimir_condicion();}
 ;
condicion:
  agrupa1 logica agrupa2 {    contador2=0; }
  ;
agrupa1:
    TK_PAB {parisopen++;}
  ;
agrupa2:
    TK_PCE {parisopen--;}
  ;

/*aca viene la logica del clco for */
ciclofor:
    encabezado_for bloque_begin_end {
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);
    }
    ;

encabezado_for:
    for variablefor to operador do { iniciofor = linea_actual; foropen++;} opt_nl
    ;

variablefor:
    variable definir operador
    ;

/*ahora la logica del dowhile */


dowhile:
bloque1dw bloque2dw bloque3dw { {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, finwhile);}}
;

bloque1dw:
do {whileopen++; iniciowhile=linea_actual;} opt_nl
;

bloque2dw:
instrucciones masinstrucciones
;

bloque3dw:
 while condicion {finwhile=linea_actual; whileopen--;}
;

cicloif:
    if_encabezado bloque_begin_end if_ramas {
        ifopen--;
        printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", $1, finif);
    }
    ;

if_encabezado:
    if condicion then opt_nl { $$ = $1; ifopen++; }
    ;

cuerpo_instrucciones:
    instrucciones masinstrucciones
    ;

if_ramas:
    %empty %prec REDUCE_NO_ELSE
  | else if condicion then opt_nl bloque_begin_end if_ramas
  | else opt_nl bloque_begin_end
  ;

/*bloque utilm tanto para for como para while */

instrucciones:
definicion { contador = 0; }
| lectura {contador=0;}
|impresion {contador=0;}
|cicloif
|ciclofor
|dowhile
|comentario
;

masinstrucciones:
    %empty
  | masinstrucciones instrucciones
  | masinstrucciones NEWLINE
  ;
/*bloque para for y para if */

bloque_begin_end:
    begin opt_nl cuerpo_instrucciones end{ finif = linea_actual; finfor=linea_actual; foropen=0; whileopen=0; ifopen=0;}
    ;

/*aca integrqamos la logica de declaradciones con allocate */

declarar:
declaracion {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual);}
;
declaracion:
    variable lista_ids allocate eos
  ;

lista_ids:
    %empty
  | dospuntos variable lista_ids
  ;



/*aca vienen tokens necesarios para operar con el programa */
then:
TK_THEN {thenopen=1;}
;
begin:
TK_BEGIN
;
if:
TK_IF { $$ = linea_actual; }
;
else:
    TK_ELSE {thenopen=1;}
  | NEWLINE else
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
TK_END  {thenopen=0;}
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
factores
| agrupa1 operador simarit operador otraaritmetica agrupa2
;
factores:
    variable
  | numero
  | restar numero
  ;
allocate:
TK_ALLOCATE 
;
while:
TK_WHILE
;

/* se comentan porque no se van a usar todavia 

main:
TK_MAIN
;
input: 
TK_INPUT
;
output: 
TK_OUTPUT
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

void imprimir_condicion(void){
if(whileopen==0 && foropen==0  && thenopen==0){
printf(" -> LINEA %d: CADENA VÁLIDA: AGRUPACIÓN DE CONDICION\n", linea_actual - 1);
}
}

void imprimir_in(void){
  if (whileopen==0 && foropen==0 && thenopen==0)
  {
   printf(" -> LINEA %d: CADENA VÁLIDA: LECTURA DE VARIABLE\n", linea_actual);
  }
}
void imprimir_out(void){
  if (whileopen==0 && foropen==0 && thenopen==0)
  {
   printf(" -> LINEA %d: CADENA VÁLIDA: IMPRESION DE VARIABLE\n", linea_actual);
  }
}
void imprimir_defnum(){
  if (whileopen==0 && foropen==0 && thenopen==0)
  {
   printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE A NUMERO/VARIABLE\n", linea_actual);
  }
}
void imprimir_defop(){
  if (whileopen==0 && foropen==0 && thenopen==0)
  {
   printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE A OPERACION\n", linea_actual);
  }

}
int main(void) {
    printf("=====================================================\n");
    printf("   ANALIZADOR SINTÁCTICO DE SUMAS EN EASYLANG    \n");
    printf("=====================================================\n");
    printf("Ingrese cadenas para evaluar:\n\n");
    yyparse();
    return 0;
}
