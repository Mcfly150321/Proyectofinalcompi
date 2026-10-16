/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "parser.y"

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

#line 110 "parser.tab.c"




# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_SUMA = 3,                    /* TK_SUMA  */
  YYSYMBOL_TK_RESTA = 4,                   /* TK_RESTA  */
  YYSYMBOL_TK_DIVISION = 5,                /* TK_DIVISION  */
  YYSYMBOL_TK_MULTIPLICACION = 6,          /* TK_MULTIPLICACION  */
  YYSYMBOL_TK_POTENCIACION = 7,            /* TK_POTENCIACION  */
  YYSYMBOL_TK_NUMERO = 8,                  /* TK_NUMERO  */
  YYSYMBOL_TK_ID = 9,                      /* TK_ID  */
  YYSYMBOL_TK_PAB = 10,                    /* TK_PAB  */
  YYSYMBOL_TK_PCE = 11,                    /* TK_PCE  */
  YYSYMBOL_TK_MAY = 12,                    /* TK_MAY  */
  YYSYMBOL_TK_MEN = 13,                    /* TK_MEN  */
  YYSYMBOL_TK_MAIG = 14,                   /* TK_MAIG  */
  YYSYMBOL_TK_MEIG = 15,                   /* TK_MEIG  */
  YYSYMBOL_TK_IG = 16,                     /* TK_IG  */
  YYSYMBOL_TK_NIG = 17,                    /* TK_NIG  */
  YYSYMBOL_TK_AND = 18,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 19,                     /* TK_OR  */
  YYSYMBOL_TK_ASIG = 20,                   /* TK_ASIG  */
  YYSYMBOL_TK_EOS = 21,                    /* TK_EOS  */
  YYSYMBOL_TK_DP = 22,                     /* TK_DP  */
  YYSYMBOL_TK_ALLOCATE = 23,               /* TK_ALLOCATE  */
  YYSYMBOL_TK_MAIN = 24,                   /* TK_MAIN  */
  YYSYMBOL_TK_INPUT = 25,                  /* TK_INPUT  */
  YYSYMBOL_TK_OUTPUT = 26,                 /* TK_OUTPUT  */
  YYSYMBOL_TK_THEN = 27,                   /* TK_THEN  */
  YYSYMBOL_TK_IF = 28,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 29,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 30,                    /* TK_FOR  */
  YYSYMBOL_TK_DO = 31,                     /* TK_DO  */
  YYSYMBOL_TK_BEGIN = 32,                  /* TK_BEGIN  */
  YYSYMBOL_TK_TO = 33,                     /* TK_TO  */
  YYSYMBOL_TK_END = 34,                    /* TK_END  */
  YYSYMBOL_TK_WHILE = 35,                  /* TK_WHILE  */
  YYSYMBOL_TK_COMENTARIO = 36,             /* TK_COMENTARIO  */
  YYSYMBOL_NEWLINE = 37,                   /* NEWLINE  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_inicio3 = 39,                   /* inicio3  */
  YYSYMBOL_inicio2 = 40,                   /* inicio2  */
  YYSYMBOL_opt_newline = 41,               /* opt_newline  */
  YYSYMBOL_inicio = 42,                    /* inicio  */
  YYSYMBOL_operacion = 43,                 /* operacion  */
  YYSYMBOL_comentario = 44,                /* comentario  */
  YYSYMBOL_lectura = 45,                   /* lectura  */
  YYSYMBOL_leer = 46,                      /* leer  */
  YYSYMBOL_impresion = 47,                 /* impresion  */
  YYSYMBOL_imprimir = 48,                  /* imprimir  */
  YYSYMBOL_output = 49,                    /* output  */
  YYSYMBOL_input = 50,                     /* input  */
  YYSYMBOL_expresion = 51,                 /* expresion  */
  YYSYMBOL_aritmetica = 52,                /* aritmetica  */
  YYSYMBOL_otraaritmetica = 53,            /* otraaritmetica  */
  YYSYMBOL_simarit = 54,                   /* simarit  */
  YYSYMBOL_logica = 55,                    /* logica  */
  YYSYMBOL_otralogica = 56,                /* otralogica  */
  YYSYMBOL_conectorlogico = 57,            /* conectorlogico  */
  YYSYMBOL_simlog = 58,                    /* simlog  */
  YYSYMBOL_definir2 = 59,                  /* definir2  */
  YYSYMBOL_definicion = 60,                /* definicion  */
  YYSYMBOL_condicionar = 61,               /* condicionar  */
  YYSYMBOL_condicion = 62,                 /* condicion  */
  YYSYMBOL_agrupa1 = 63,                   /* agrupa1  */
  YYSYMBOL_agrupa2 = 64,                   /* agrupa2  */
  YYSYMBOL_ciclofor = 65,                  /* ciclofor  */
  YYSYMBOL_encabezado_for = 66,            /* encabezado_for  */
  YYSYMBOL_variablefor = 67,               /* variablefor  */
  YYSYMBOL_dowhile = 68,                   /* dowhile  */
  YYSYMBOL_bloque1dw = 69,                 /* bloque1dw  */
  YYSYMBOL_bloque2dw = 70,                 /* bloque2dw  */
  YYSYMBOL_bloque3dw = 71,                 /* bloque3dw  */
  YYSYMBOL_cicloif = 72,                   /* cicloif  */
  YYSYMBOL_if_encabezado = 73,             /* if_encabezado  */
  YYSYMBOL_cuerpo_instrucciones = 74,      /* cuerpo_instrucciones  */
  YYSYMBOL_if_ramas = 75,                  /* if_ramas  */
  YYSYMBOL_instrucciones = 76,             /* instrucciones  */
  YYSYMBOL_masinstrucciones = 77,          /* masinstrucciones  */
  YYSYMBOL_bloque_begin_end = 78,          /* bloque_begin_end  */
  YYSYMBOL_declarar = 79,                  /* declarar  */
  YYSYMBOL_declaracion = 80,               /* declaracion  */
  YYSYMBOL_lista_ids = 81,                 /* lista_ids  */
  YYSYMBOL_then = 82,                      /* then  */
  YYSYMBOL_begin = 83,                     /* begin  */
  YYSYMBOL_if = 84,                        /* if  */
  YYSYMBOL_else = 85,                      /* else  */
  YYSYMBOL_dospuntos = 86,                 /* dospuntos  */
  YYSYMBOL_eos = 87,                       /* eos  */
  YYSYMBOL_for = 88,                       /* for  */
  YYSYMBOL_do = 89,                        /* do  */
  YYSYMBOL_to = 90,                        /* to  */
  YYSYMBOL_end = 91,                       /* end  */
  YYSYMBOL_variable = 92,                  /* variable  */
  YYSYMBOL_numero = 93,                    /* numero  */
  YYSYMBOL_sumar = 94,                     /* sumar  */
  YYSYMBOL_restar = 95,                    /* restar  */
  YYSYMBOL_multiplicar = 96,               /* multiplicar  */
  YYSYMBOL_dividir = 97,                   /* dividir  */
  YYSYMBOL_potenciar = 98,                 /* potenciar  */
  YYSYMBOL_definir = 99,                   /* definir  */
  YYSYMBOL_operador = 100,                 /* operador  */
  YYSYMBOL_allocate = 101,                 /* allocate  */
  YYSYMBOL_while = 102                     /* while  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    61,    64,    67,    68,    71,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      88,    91,    93,    96,    99,   102,   105,   110,   111,   116,
     119,   120,   123,   124,   125,   126,   127,   133,   136,   137,
     140,   141,   144,   145,   146,   147,   148,   149,   155,   158,
     161,   169,   172,   175,   178,   183,   189,   193,   200,   204,
     208,   212,   216,   223,   227,   231,   232,   233,   239,   240,
     241,   242,   246,   247,   248,   253,   259,   262,   266,   267,
     274,   277,   280,   283,   286,   289,   292,   295,   298,   301,
     304,   307,   311,   314,   317,   320,   323,   326,   329,   330,
     333,   336
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_SUMA", "TK_RESTA",
  "TK_DIVISION", "TK_MULTIPLICACION", "TK_POTENCIACION", "TK_NUMERO",
  "TK_ID", "TK_PAB", "TK_PCE", "TK_MAY", "TK_MEN", "TK_MAIG", "TK_MEIG",
  "TK_IG", "TK_NIG", "TK_AND", "TK_OR", "TK_ASIG", "TK_EOS", "TK_DP",
  "TK_ALLOCATE", "TK_MAIN", "TK_INPUT", "TK_OUTPUT", "TK_THEN", "TK_IF",
  "TK_ELSE", "TK_FOR", "TK_DO", "TK_BEGIN", "TK_TO", "TK_END", "TK_WHILE",
  "TK_COMENTARIO", "NEWLINE", "$accept", "inicio3", "inicio2",
  "opt_newline", "inicio", "operacion", "comentario", "lectura", "leer",
  "impresion", "imprimir", "output", "input", "expresion", "aritmetica",
  "otraaritmetica", "simarit", "logica", "otralogica", "conectorlogico",
  "simlog", "definir2", "definicion", "condicionar", "condicion",
  "agrupa1", "agrupa2", "ciclofor", "encabezado_for", "variablefor",
  "dowhile", "bloque1dw", "bloque2dw", "bloque3dw", "cicloif",
  "if_encabezado", "cuerpo_instrucciones", "if_ramas", "instrucciones",
  "masinstrucciones", "bloque_begin_end", "declarar", "declaracion",
  "lista_ids", "then", "begin", "if", "else", "dospuntos", "eos", "for",
  "do", "to", "end", "variable", "numero", "sumar", "restar",
  "multiplicar", "dividir", "potenciar", "definir", "operador", "allocate",
  "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -123,     8,     4,  -123,   -23,   -15,  -123,  -123,  -123,     2,
      21,  -123,    25,     1,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,    26,  -123,    27,
      53,    53,  -123,    28,    29,  -123,    30,  -123,    32,    11,
    -123,    49,  -123,    24,  -123,    49,  -123,    45,    75,    53,
      51,    -7,  -123,   127,    56,  -123,  -123,    65,    65,  -123,
    -123,  -123,  -123,    76,  -123,    63,  -123,  -123,    57,  -123,
    -123,  -123,    55,  -123,  -123,    78,    66,  -123,    69,    67,
      78,  -123,  -123,  -123,    79,    53,    11,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    11,    11,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
      24,  -123,  -123,    75,    14,  -123,  -123,   -16,  -123,    62,
    -123,    11,    11,  -123,    65,    81,  -123,    50,    40,     6,
      70,  -123,    68,  -123,  -123,    49,    75,  -123,    77,  -123,
    -123,  -123,  -123,    65,    11,  -123,  -123,  -123,    11,  -123,
      72,    14,  -123,  -123,    69,    74,  -123,    40,    63,  -123,
      80,  -123,  -123,    11,    49,     6,    66,  -123,  -123
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     6,     2,     4,     0,
       0,     8,     0,     7,     5,    91,    90,    53,    26,    25,
      82,    86,    87,    20,    15,    19,    17,     0,    18,     0,
       0,     0,     9,     0,     0,    10,     0,    12,     0,     0,
      11,     0,    14,     0,    16,     0,    13,     0,     0,     0,
       0,    98,    99,     0,     3,    21,    23,     0,     0,    28,
      27,    48,    51,     0,    98,     0,    81,    55,     0,    69,
      70,    68,     0,    71,    72,     0,    65,    76,     0,     0,
       0,    59,    97,    84,     0,     0,     0,    92,    93,    95,
      94,    96,    42,    43,    44,    45,    46,    47,     0,     0,
      32,    33,    34,    35,    36,    85,    24,    22,    54,    52,
       0,   101,    58,     0,    60,    83,    62,     0,    80,     0,
      88,     0,     0,   100,     0,    78,    50,     0,    30,    38,
       0,    72,     0,    74,    73,     0,     0,    63,     0,    57,
      77,    79,    49,     0,     0,    40,    41,    37,     0,    89,
       0,    64,    61,    67,     0,     0,    29,    30,     0,    75,
       0,    56,    31,     0,     0,    38,    65,    39,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,  -123,  -123,    93,  -123,  -123,  -123,    99,  -123,   100,
    -123,  -123,  -123,  -123,    33,   -42,  -122,    83,   -51,  -123,
     -40,  -123,   103,  -123,   -45,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,   107,  -123,  -123,   -39,   -36,    -8,
     -43,  -123,  -123,    -1,   -28,  -123,    12,  -123,  -123,   -54,
    -123,   -10,  -123,  -123,   -13,  -123,  -123,  -123,  -123,  -123,
    -123,    71,   -38,  -123,  -123
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     2,    12,    13,    25,    69,    27,    70,
      29,    30,    31,    32,    33,   143,    98,    34,   147,   148,
      99,    35,    71,    37,    38,    39,   109,    40,    41,    79,
      42,    43,    72,   112,    73,    45,   130,   116,   134,   114,
      67,    46,    47,    84,   119,    68,    48,   117,    85,   106,
      49,    50,   121,   150,    64,    52,   100,   101,   102,   103,
     104,    86,    53,   124,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    65,    76,    78,   107,     4,   144,    74,     3,    15,
      16,    17,    20,    82,     8,    83,   -78,    57,    58,    15,
      16,   135,     9,    16,   145,   146,    18,    19,     5,    20,
      75,    21,    22,    16,    10,   144,    80,    23,    24,    18,
      19,     6,    20,    87,    88,    89,    90,    91,   127,    18,
      19,   133,    20,    87,    88,    89,    90,    91,    11,    14,
     128,   129,    16,    55,    56,    59,    60,    61,   132,    62,
     140,   105,   125,   142,   131,    92,    93,    94,    95,    96,
      97,    66,    77,   138,   139,    17,   105,   108,    81,   156,
     111,   154,   153,     6,   110,   115,   118,    75,    82,   137,
     120,    75,   123,    83,   149,   152,   157,    54,    22,   159,
     158,   161,    26,    28,   167,   162,    36,   164,   163,   126,
      44,   166,    63,   151,   141,   165,   160,   168,   155,   136,
      87,    88,    89,    90,    91,     0,     0,     0,    75,    92,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,   122
};

static const yytype_int16 yycheck[] =
{
      13,    39,    45,    48,    58,     1,   128,    43,     0,     8,
       9,    10,    28,    20,    37,    22,    23,    30,    31,     8,
       9,    37,    37,     9,    18,    19,    25,    26,    24,    28,
      43,    30,    31,     9,    32,   157,    49,    36,    37,    25,
      26,    37,    28,     3,     4,     5,     6,     7,    86,    25,
      26,    37,    28,     3,     4,     5,     6,     7,    37,    34,
      98,    99,     9,    37,    37,    37,    37,    37,   113,    37,
     124,    21,    85,   127,   110,    12,    13,    14,    15,    16,
      17,    32,    37,   121,   122,    10,    21,    11,    37,   143,
      35,   136,   135,    37,    37,    29,    27,   110,    20,    37,
      33,   114,    23,    22,    34,    37,   144,    14,    31,    37,
     148,    37,    13,    13,   165,   157,    13,    37,   158,    86,
      13,   164,    39,   131,   125,   163,   154,   166,   138,   117,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   151,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    41,     0,     1,    24,    37,    40,    37,    37,
      32,    37,    42,    43,    34,     8,     9,    10,    25,    26,
      28,    30,    31,    36,    37,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    55,    59,    60,    61,    62,    63,
      65,    66,    68,    69,    72,    73,    79,    80,    84,    88,
      89,    92,    93,   100,    41,    37,    37,    92,    92,    37,
      37,    37,    37,    55,    92,   100,    32,    78,    83,    45,
      47,    60,    70,    72,    76,    92,    78,    37,    62,    67,
      92,    37,    20,    22,    81,    86,    99,     3,     4,     5,
       6,     7,    12,    13,    14,    15,    16,    17,    54,    58,
      94,    95,    96,    97,    98,    21,    87,    87,    11,    64,
      37,    35,    71,   102,    77,    29,    75,    85,    27,    82,
      33,    90,    99,    23,   101,    92,    52,   100,   100,   100,
      74,    76,    62,    37,    76,    37,    84,    37,   100,   100,
      87,    81,    87,    53,    54,    18,    19,    56,    57,    34,
      91,    77,    37,    78,    62,    89,    87,   100,   100,    37,
      82,    37,    53,    58,    37,   100,    78,    56,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    59,    60,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    75,    75,    76,    76,
      76,    76,    77,    77,    77,    78,    79,    80,    81,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   100,
     101,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     7,     2,     0,     2,     1,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     3,     2,     3,     1,     1,     2,     2,     5,
       0,     3,     1,     1,     1,     1,     1,     4,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     2,     3,     1,     1,     2,     6,     3,     3,     2,
       2,     3,     3,     4,     2,     0,     7,     3,     1,     1,
       1,     1,     0,     2,     2,     5,     2,     4,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* inicio2: TK_MAIN NEWLINE TK_BEGIN NEWLINE inicio TK_END opt_newline  */
#line 61 "parser.y"
                                                               {
        printf("\nBloque valido codigo completo\n");
    }
#line 1331 "parser.tab.c"
    break;

  case 4: /* inicio2: error NEWLINE  */
#line 64 "parser.y"
                  { parisopen = 0; contador = 0; contador2 = 0; whileopen=0; ifopen=0; foropen=0; thenopen=0; printf(" CADENA INVÁLIDA\n"); yyerrok; }
#line 1337 "parser.tab.c"
    break;

  case 20: /* comentario: TK_COMENTARIO  */
#line 88 "parser.y"
              {printf(" -> LINEA %d: CADENA VÁLIDA: comentario\n", linea_actual - 1);}
#line 1343 "parser.tab.c"
    break;

  case 21: /* lectura: leer NEWLINE  */
#line 91 "parser.y"
             {imprimir_in();}
#line 1349 "parser.tab.c"
    break;

  case 23: /* impresion: imprimir NEWLINE  */
#line 96 "parser.y"
                {imprimir_out();}
#line 1355 "parser.tab.c"
    break;

  case 27: /* expresion: logica NEWLINE  */
#line 110 "parser.y"
                       { imprimir_logica(); }
#line 1361 "parser.tab.c"
    break;

  case 28: /* expresion: aritmetica NEWLINE  */
#line 111 "parser.y"
                       { imprimir_aritmetica(); }
#line 1367 "parser.tab.c"
    break;

  case 31: /* otraaritmetica: simarit operador otraaritmetica  */
#line 120 "parser.y"
                                  {contador++; /*esto apra incrementar el contador de simbolos en la operacion */}
#line 1373 "parser.tab.c"
    break;

  case 32: /* simarit: sumar  */
#line 123 "parser.y"
      {strcpy(tipoaritmetica, "SUMA");}
#line 1379 "parser.tab.c"
    break;

  case 33: /* simarit: restar  */
#line 124 "parser.y"
        {strcpy(tipoaritmetica, "RESTA");}
#line 1385 "parser.tab.c"
    break;

  case 34: /* simarit: multiplicar  */
#line 125 "parser.y"
             {strcpy(tipoaritmetica, "MULTIPLICACION");}
#line 1391 "parser.tab.c"
    break;

  case 35: /* simarit: dividir  */
#line 126 "parser.y"
         {strcpy(tipoaritmetica, "DIVISION");}
#line 1397 "parser.tab.c"
    break;

  case 36: /* simarit: potenciar  */
#line 127 "parser.y"
           {strcpy(tipoaritmetica, "POTENCIACION");}
#line 1403 "parser.tab.c"
    break;

  case 39: /* otralogica: conectorlogico operador simlog operador otralogica  */
#line 137 "parser.y"
                                                     {contador2++;}
#line 1409 "parser.tab.c"
    break;

  case 42: /* simlog: TK_MAY  */
#line 144 "parser.y"
           {strcpy(tipologica, "MAYOR QUE");}
#line 1415 "parser.tab.c"
    break;

  case 43: /* simlog: TK_MEN  */
#line 145 "parser.y"
           {strcpy(tipologica, "MENOR QUE");}
#line 1421 "parser.tab.c"
    break;

  case 44: /* simlog: TK_MAIG  */
#line 146 "parser.y"
            {strcpy(tipologica, "MAYOR O IGUAL");}
#line 1427 "parser.tab.c"
    break;

  case 45: /* simlog: TK_MEIG  */
#line 147 "parser.y"
            {strcpy(tipologica, "MENOR O IGUAL");;}
#line 1433 "parser.tab.c"
    break;

  case 46: /* simlog: TK_IG  */
#line 148 "parser.y"
          {strcpy(tipologica, "IGUAL");}
#line 1439 "parser.tab.c"
    break;

  case 47: /* simlog: TK_NIG  */
#line 149 "parser.y"
           {strcpy(tipologica, "DISTINTO");}
#line 1445 "parser.tab.c"
    break;

  case 49: /* definicion: variable definir operador eos  */
#line 158 "parser.y"
                                 {
      imprimir_defnum();/*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1453 "parser.tab.c"
    break;

  case 50: /* definicion: variable definir aritmetica  */
#line 161 "parser.y"
                                 {
     imprimir_defop(); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1461 "parser.tab.c"
    break;

  case 51: /* condicionar: condicion NEWLINE  */
#line 169 "parser.y"
                   {imprimir_condicion();}
#line 1467 "parser.tab.c"
    break;

  case 52: /* condicion: agrupa1 logica agrupa2  */
#line 172 "parser.y"
                         {    contador2=0; }
#line 1473 "parser.tab.c"
    break;

  case 53: /* agrupa1: TK_PAB  */
#line 175 "parser.y"
           {parisopen++;}
#line 1479 "parser.tab.c"
    break;

  case 54: /* agrupa2: TK_PCE  */
#line 178 "parser.y"
           {parisopen--;}
#line 1485 "parser.tab.c"
    break;

  case 55: /* ciclofor: encabezado_for bloque_begin_end  */
#line 183 "parser.y"
                                    {
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);
    }
#line 1493 "parser.tab.c"
    break;

  case 56: /* encabezado_for: for variablefor to operador do NEWLINE  */
#line 189 "parser.y"
                                           { iniciofor = linea_actual - 1; foropen++;}
#line 1499 "parser.tab.c"
    break;

  case 58: /* dowhile: bloque1dw bloque2dw bloque3dw  */
#line 200 "parser.y"
                              { {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, finwhile);}}
#line 1505 "parser.tab.c"
    break;

  case 59: /* bloque1dw: do NEWLINE  */
#line 204 "parser.y"
           {whileopen++; iniciowhile=linea_actual-1;}
#line 1511 "parser.tab.c"
    break;

  case 61: /* bloque3dw: while condicion NEWLINE  */
#line 212 "parser.y"
                         {finwhile=linea_actual-1; whileopen--;}
#line 1517 "parser.tab.c"
    break;

  case 62: /* cicloif: if_encabezado bloque_begin_end if_ramas  */
#line 216 "parser.y"
                                            {
        ifopen--;
        printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", yyvsp[-2], finif);
    }
#line 1526 "parser.tab.c"
    break;

  case 63: /* if_encabezado: if condicion then NEWLINE  */
#line 223 "parser.y"
                              { yyval = linea_actual - 1; ifopen++; }
#line 1532 "parser.tab.c"
    break;

  case 68: /* instrucciones: definicion  */
#line 239 "parser.y"
           { contador = 0; }
#line 1538 "parser.tab.c"
    break;

  case 69: /* instrucciones: lectura  */
#line 240 "parser.y"
          {contador=0;}
#line 1544 "parser.tab.c"
    break;

  case 70: /* instrucciones: impresion  */
#line 241 "parser.y"
           {contador=0;}
#line 1550 "parser.tab.c"
    break;

  case 75: /* bloque_begin_end: begin NEWLINE cuerpo_instrucciones end NEWLINE  */
#line 253 "parser.y"
                                                   { finif = linea_actual - 1; finfor=linea_actual-1; foropen=0; whileopen=0; ifopen=0;}
#line 1556 "parser.tab.c"
    break;

  case 76: /* declarar: declaracion NEWLINE  */
#line 259 "parser.y"
                      {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual - 1);}
#line 1562 "parser.tab.c"
    break;

  case 80: /* then: TK_THEN  */
#line 274 "parser.y"
        {thenopen=1;}
#line 1568 "parser.tab.c"
    break;

  case 83: /* else: TK_ELSE  */
#line 283 "parser.y"
        {thenopen=1;}
#line 1574 "parser.tab.c"
    break;

  case 89: /* end: TK_END  */
#line 301 "parser.y"
        {thenopen=0;}
#line 1580 "parser.tab.c"
    break;


#line 1584 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 465 "parser.y"


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
   printf(" -> LINEA %d: CADENA VÁLIDA: LECTURA DE VARIABLE\n", linea_actual-1);
  }
}
void imprimir_out(void){
  if (whileopen==0 && foropen==0 && thenopen==0)
  {
   printf(" -> LINEA %d: CADENA VÁLIDA: IMPRESION DE VARIABLE\n", linea_actual-1);
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
