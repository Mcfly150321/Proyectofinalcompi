/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_SUMA = 258,                 /* TK_SUMA  */
    TK_RESTA = 259,                /* TK_RESTA  */
    TK_DIVISION = 260,             /* TK_DIVISION  */
    TK_MULTIPLICACION = 261,       /* TK_MULTIPLICACION  */
    TK_POTENCIACION = 262,         /* TK_POTENCIACION  */
    TK_NUMERO = 263,               /* TK_NUMERO  */
    TK_ID = 264,                   /* TK_ID  */
    TK_PAB = 265,                  /* TK_PAB  */
    TK_PCE = 266,                  /* TK_PCE  */
    TK_MAY = 267,                  /* TK_MAY  */
    TK_MEN = 268,                  /* TK_MEN  */
    TK_MAIG = 269,                 /* TK_MAIG  */
    TK_MEIG = 270,                 /* TK_MEIG  */
    TK_IG = 271,                   /* TK_IG  */
    TK_NIG = 272,                  /* TK_NIG  */
    TK_AND = 273,                  /* TK_AND  */
    TK_OR = 274,                   /* TK_OR  */
    TK_ASIG = 275,                 /* TK_ASIG  */
    TK_EOS = 276,                  /* TK_EOS  */
    TK_DP = 277,                   /* TK_DP  */
    TK_ALLOCATE = 278,             /* TK_ALLOCATE  */
    TK_MAIN = 279,                 /* TK_MAIN  */
    TK_INPUT = 280,                /* TK_INPUT  */
    TK_OUTPUT = 281,               /* TK_OUTPUT  */
    TK_THEN = 282,                 /* TK_THEN  */
    TK_IF = 283,                   /* TK_IF  */
    TK_ELSE = 284,                 /* TK_ELSE  */
    TK_FOR = 285,                  /* TK_FOR  */
    TK_DO = 286,                   /* TK_DO  */
    TK_BEGIN = 287,                /* TK_BEGIN  */
    TK_TO = 288,                   /* TK_TO  */
    TK_END = 289,                  /* TK_END  */
    TK_WHILE = 290,                /* TK_WHILE  */
    NEWLINE = 291                  /* NEWLINE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
