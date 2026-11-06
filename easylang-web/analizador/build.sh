#!/bin/sh
# Compila el analizador Flex/Bison. Si no hay bison/flex, usa los .c ya generados.
cd "$(dirname "$0")" || exit 1
if command -v bison >/dev/null && command -v flex >/dev/null; then
  bison -d -o parser.tab.c parser.y && flex lexer.l
else
  echo "bison/flex no encontrados: se usan lex.yy.c y parser.tab.c incluidos"
fi
gcc lex.yy.c parser.tab.c -o analizador && echo "Analizador compilado"
