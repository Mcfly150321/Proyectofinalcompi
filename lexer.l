%{
#include <stdio.h>
#include "parser.tab.h"

int errores_lexicos = 0;
%}

%option noyywrap
%option yylineno

%x COMENTARIO

%%

"***"                   { BEGIN(COMENTARIO); }
<COMENTARIO>"***"       { BEGIN(INITIAL); }
<COMENTARIO>\n          { /* yylineno cuenta la línea automáticamente */ }
<COMENTARIO>.           { /* ignorar contenido del comentario */ }
<COMENTARIO><<EOF>>     {
                            fprintf(stderr, "Error léxico: comentario sin cerrar (falta ***)\n");
                            errores_lexicos++;
                            return 0;
                        }

"**"        { return TK_POTENCIACION; }
"+"         { return TK_SUMA; }
"-"         { return TK_RESTA; }
"/"         { return TK_DIVISION; }
"*"         { return TK_MULTIPLICACION; }

"AND"       { return TK_AND; }
"OR"        { return TK_OR; }
"ALLOCATE"  { return TK_ALLOCATE; }
"MAIN"      { return TK_MAIN; }
"INPUT"     { return TK_INPUT; }
"OUTPUT"    { return TK_OUTPUT; }
"IF"        { return TK_IF; }
"THEN"      { return TK_THEN; }
"ELSE"      { return TK_ELSE; }
"FOR"       { return TK_FOR; }
"BEGIN"     { return TK_BEGIN; }
"END"       { return TK_END; }
"TO"        { return TK_TO; }
"DO"        { return TK_DO; }
"WHILE"     { return TK_WHILE; }

0|([1-9][0-9]*)          { return TK_NUMERO; }
[a-zA-Z_][a-zA-Z0-9_]*   { return TK_ID; }

":="        { return TK_ASIG; }
":"         { return TK_DP; }
";"         { return TK_EOS; }
"("         { return TK_PAB; }
")"         { return TK_PCE; }
">="        { return TK_MAIG; }
"<="        { return TK_MEIG; }
"=="        { return TK_IG; }
"<>"        { return TK_NIG; }
">"         { return TK_MAY; }
"<"         { return TK_MEN; }

\n          { /* yylineno ya incrementa; no se envía al parser */ }
[ \t\r]+    { /* ignorar espacios */ }

.           {
                fprintf(stderr, "Error léxico en línea %d: caracter no reconocido '%s'\n",
                        yylineno, yytext);
                errores_lexicos++;
                return TK_ERROR;
            }

%%
