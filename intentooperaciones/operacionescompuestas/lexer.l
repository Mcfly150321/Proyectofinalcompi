%{
#include "parser.tab.h"
int linea_actual = 1; 
%}

%option noyywrap

%%
"**"        { return TK_POTENCIACION; }
"+"         { return TK_SUMA; }
"-"         { return TK_RESTA; }
"/"         { return TK_DIVISION; }
"*"         { return TK_MULTIPLICACION; }
0|([1-9][0-9]*)      { return TK_NUMERO; }
"AND"       { return TK_AND; }
"OR"        { return TK_OR; }
"ALLOCATE"  { return TK_ALLOCATE; }
"MAIN"      { return TK_MAIN; }
"INPUT"     { return TK_INPUT; }
"OUTPUT"    { return TK_OUTPUT; }
"IF"        { return TK_IF; }
"ELSE"      { return TK_ELSE; }
[a-zA-Z][a-zA-Z0-9_]*  { return TK_ID; }
":="        { return TK_ASIG; }
";"         { return TK_EOS; }
":"         { return TK_DP; }
"("         { return TK_PAB; }
")"         { return TK_PCE; }
">"         { return TK_MAY; }
"<"         { return TK_MEN; }
">="        { return TK_MAIG; }
"<="        { return TK_MEIG; }
"=="        { return TK_IG; }
"<>"        { return TK_NIG; }
"\n"        { linea_actual++; return NEWLINE; }
[ \t\r]+    { /* ignorar espacios */ }
.           { return yytext[0]; }

%%

