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
  YYSYMBOL_oparit = 53,                    /* oparit  */
  YYSYMBOL_otraaritmetica = 54,            /* otraaritmetica  */
  YYSYMBOL_simarit = 55,                   /* simarit  */
  YYSYMBOL_logica = 56,                    /* logica  */
  YYSYMBOL_otralogica = 57,                /* otralogica  */
  YYSYMBOL_conectorlogico = 58,            /* conectorlogico  */
  YYSYMBOL_simlog = 59,                    /* simlog  */
  YYSYMBOL_definir2 = 60,                  /* definir2  */
  YYSYMBOL_definicion = 61,                /* definicion  */
  YYSYMBOL_condicionar = 62,               /* condicionar  */
  YYSYMBOL_condicion = 63,                 /* condicion  */
  YYSYMBOL_agrupa1 = 64,                   /* agrupa1  */
  YYSYMBOL_agrupa2 = 65,                   /* agrupa2  */
  YYSYMBOL_ciclofor = 66,                  /* ciclofor  */
  YYSYMBOL_encabezado_for = 67,            /* encabezado_for  */
  YYSYMBOL_variablefor = 68,               /* variablefor  */
  YYSYMBOL_dowhile = 69,                   /* dowhile  */
  YYSYMBOL_bloque1dw = 70,                 /* bloque1dw  */
  YYSYMBOL_bloque2dw = 71,                 /* bloque2dw  */
  YYSYMBOL_bloque3dw = 72,                 /* bloque3dw  */
  YYSYMBOL_cicloif = 73,                   /* cicloif  */
  YYSYMBOL_if_encabezado = 74,             /* if_encabezado  */
  YYSYMBOL_cuerpo_instrucciones = 75,      /* cuerpo_instrucciones  */
  YYSYMBOL_if_ramas = 76,                  /* if_ramas  */
  YYSYMBOL_instrucciones = 77,             /* instrucciones  */
  YYSYMBOL_masinstrucciones = 78,          /* masinstrucciones  */
  YYSYMBOL_bloque_begin_end = 79,          /* bloque_begin_end  */
  YYSYMBOL_declarar = 80,                  /* declarar  */
  YYSYMBOL_declaracion = 81,               /* declaracion  */
  YYSYMBOL_lista_ids = 82,                 /* lista_ids  */
  YYSYMBOL_then = 83,                      /* then  */
  YYSYMBOL_begin = 84,                     /* begin  */
  YYSYMBOL_if = 85,                        /* if  */
  YYSYMBOL_else = 86,                      /* else  */
  YYSYMBOL_dospuntos = 87,                 /* dospuntos  */
  YYSYMBOL_eos = 88,                       /* eos  */
  YYSYMBOL_for = 89,                       /* for  */
  YYSYMBOL_do = 90,                        /* do  */
  YYSYMBOL_to = 91,                        /* to  */
  YYSYMBOL_end = 92,                       /* end  */
  YYSYMBOL_variable = 93,                  /* variable  */
  YYSYMBOL_numero = 94,                    /* numero  */
  YYSYMBOL_sumar = 95,                     /* sumar  */
  YYSYMBOL_restar = 96,                    /* restar  */
  YYSYMBOL_multiplicar = 97,               /* multiplicar  */
  YYSYMBOL_dividir = 98,                   /* dividir  */
  YYSYMBOL_potenciar = 99,                 /* potenciar  */
  YYSYMBOL_definir = 100,                  /* definir  */
  YYSYMBOL_operador = 101,                 /* operador  */
  YYSYMBOL_factores = 102,                 /* factores  */
  YYSYMBOL_allocate = 103,                 /* allocate  */
  YYSYMBOL_while = 104                     /* while  */
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
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

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
     119,   122,   123,   126,   127,   128,   129,   130,   136,   139,
     140,   143,   144,   147,   148,   149,   150,   151,   152,   158,
     161,   164,   172,   175,   178,   181,   186,   192,   196,   203,
     207,   211,   215,   219,   226,   230,   234,   235,   236,   242,
     243,   244,   245,   249,   250,   251,   256,   262,   265,   269,
     270,   277,   280,   283,   286,   289,   292,   295,   298,   301,
     304,   307,   310,   314,   317,   320,   323,   326,   329,   332,
     333,   336,   337,   340,   343
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
  "oparit", "otraaritmetica", "simarit", "logica", "otralogica",
  "conectorlogico", "simlog", "definir2", "definicion", "condicionar",
  "condicion", "agrupa1", "agrupa2", "ciclofor", "encabezado_for",
  "variablefor", "dowhile", "bloque1dw", "bloque2dw", "bloque3dw",
  "cicloif", "if_encabezado", "cuerpo_instrucciones", "if_ramas",
  "instrucciones", "masinstrucciones", "bloque_begin_end", "declarar",
  "declaracion", "lista_ids", "then", "begin", "if", "else", "dospuntos",
  "eos", "for", "do", "to", "end", "variable", "numero", "sumar", "restar",
  "multiplicar", "dividir", "potenciar", "definir", "operador", "factores",
  "allocate", "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -131,    11,     6,  -131,   -21,   -16,  -131,  -131,  -131,    13,
     -10,  -131,     1,    16,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,    34,  -131,    38,
      29,    29,  -131,    40,    58,    41,  -131,    52,  -131,    53,
      60,  -131,    18,  -131,    23,  -131,    18,  -131,    54,    74,
      29,    62,    -5,  -131,   122,  -131,    65,  -131,  -131,    58,
      58,  -131,  -131,  -131,  -131,  -131,  -131,    77,    57,  -131,
      47,    91,  -131,  -131,    66,  -131,  -131,  -131,    69,  -131,
    -131,    85,    79,  -131,    83,    60,    73,    85,  -131,  -131,
    -131,    89,    29,    60,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,    60,    60,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,    91,    57,    23,  -131,
    -131,    74,     3,  -131,  -131,   -14,  -131,    76,  -131,    60,
      60,  -131,    58,    92,  -131,    51,    91,    55,    91,    81,
    -131,    82,  -131,  -131,    18,    74,  -131,    87,  -131,  -131,
    -131,  -131,  -131,    60,  -131,  -131,  -131,    60,    77,  -131,
      84,     3,  -131,  -131,    83,    86,    91,    47,  -131,  -131,
      93,  -131,  -131,    60,    18,    55,    79,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     6,     2,     4,     0,
       0,     8,     0,     7,     5,    92,    91,    54,    26,    25,
      83,    87,    88,    20,    15,    19,    17,     0,    18,     0,
       0,     0,     9,     0,     0,     0,    10,     0,    12,     0,
       0,    11,     0,    14,     0,    16,     0,    13,     0,     0,
       0,     0,   101,   102,     0,    99,     3,    21,    23,     0,
       0,    28,    86,    29,    27,    49,    52,     0,     0,   101,
       0,    99,    82,    56,     0,    70,    71,    69,     0,    72,
      73,     0,    66,    77,     0,     0,     0,     0,    60,    98,
      85,     0,     0,     0,    93,    94,    96,    95,    97,    43,
      44,    45,    46,    47,    48,     0,     0,    33,    34,    35,
      36,    37,    24,    22,    55,    53,     0,     0,     0,   104,
      59,     0,    61,    84,    63,     0,    81,     0,    89,     0,
       0,   103,     0,    79,    51,     0,    31,    39,    31,     0,
      73,     0,    75,    74,     0,     0,    64,     0,    58,    78,
      80,    50,    30,     0,    41,    42,    38,     0,     0,    90,
       0,    65,    62,    68,     0,     0,    31,     0,   100,    76,
       0,    57,    32,     0,     0,    39,    66,    40,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,   106,  -131,  -131,  -131,   109,  -131,   111,
    -131,  -131,  -131,  -131,    39,  -131,  -130,   -49,   128,   -33,
    -131,   -24,  -131,   132,  -131,   -45,   -12,    -9,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,   133,  -131,  -131,   -29,   -31,
       8,   -43,  -131,  -131,    19,    -8,  -131,    26,  -131,  -131,
     -50,  -131,     7,  -131,  -131,   -11,  -131,  -131,  -131,  -131,
    -131,  -131,    68,   -13,   -34,  -131,  -131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     2,    12,    13,    25,    75,    27,    76,
      29,    30,    31,    32,    33,    34,   152,   153,    67,   156,
     157,   106,    36,    77,    38,    39,    68,   115,    41,    42,
      86,    43,    44,    78,   120,    79,    46,   139,   124,   143,
     122,    73,    47,    48,    91,   127,    74,    49,   125,    92,
      63,    50,    51,   129,   160,    69,    53,   107,   108,   109,
     110,   111,    93,    70,    55,   132,   121
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    40,    52,    82,    84,   105,    71,     4,   158,   112,
     113,     3,    16,    80,    20,    89,     8,    90,   -79,    59,
      60,     9,   117,   144,    15,    16,    17,    11,    18,    19,
       5,    20,    16,    81,   116,    14,   172,    85,    16,    87,
     142,    18,    19,     6,    20,    10,    21,    22,    18,    19,
      72,    20,    23,    24,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    15,    16,   117,    15,    16,
      17,    57,    62,   154,   155,    58,   141,    61,    64,    62,
     135,   133,   149,   138,    17,   151,   105,   140,   114,    65,
      66,    83,   136,   137,    94,    95,    96,    97,    98,    88,
     164,   163,     6,   118,   119,    89,   128,    81,   123,    85,
     126,    81,   131,   146,    90,   159,   147,   148,    22,   162,
      56,   169,    26,   171,    28,    94,    95,    96,    97,    98,
     174,   176,   134,    85,    99,   100,   101,   102,   103,   104,
     166,    35,   177,   173,   167,    37,    45,   178,   161,   168,
      81,   145,   150,     0,   165,   130,   170,     0,     0,     0,
     175
};

static const yytype_int16 yycheck[] =
{
      13,    13,    13,    46,    49,    54,    40,     1,   138,    59,
      60,     0,     9,    44,    28,    20,    37,    22,    23,    30,
      31,    37,    71,    37,     8,     9,    10,    37,    25,    26,
      24,    28,     9,    44,    68,    34,   166,    49,     9,    50,
      37,    25,    26,    37,    28,    32,    30,    31,    25,    26,
      32,    28,    36,    37,     3,     4,     5,     6,     7,    12,
      13,    14,    15,    16,    17,     8,     9,   116,     8,     9,
      10,    37,    21,    18,    19,    37,   121,    37,    37,    21,
      93,    92,   132,   117,    10,   135,   135,   118,    11,    37,
      37,    37,   105,   106,     3,     4,     5,     6,     7,    37,
     145,   144,    37,    37,    35,    20,    33,   118,    29,   121,
      27,   122,    23,    37,    22,    34,   129,   130,    31,    37,
      14,    37,    13,    37,    13,     3,     4,     5,     6,     7,
      37,   174,    93,   145,    12,    13,    14,    15,    16,    17,
     153,    13,   175,   167,   157,    13,    13,   176,   140,   158,
     161,   125,   133,    -1,   147,    87,   164,    -1,    -1,    -1,
     173
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    41,     0,     1,    24,    37,    40,    37,    37,
      32,    37,    42,    43,    34,     8,     9,    10,    25,    26,
      28,    30,    31,    36,    37,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    56,    60,    61,    62,    63,
      64,    66,    67,    69,    70,    73,    74,    80,    81,    85,
      89,    90,    93,    94,   101,   102,    41,    37,    37,    93,
      93,    37,    21,    88,    37,    37,    37,    56,    64,    93,
     101,   102,    32,    79,    84,    45,    47,    61,    71,    73,
      77,    93,    79,    37,    63,    64,    68,    93,    37,    20,
      22,    82,    87,   100,     3,     4,     5,     6,     7,    12,
      13,    14,    15,    16,    17,    55,    59,    95,    96,    97,
      98,    99,    88,    88,    11,    65,   102,    55,    37,    35,
      72,   104,    78,    29,    76,    86,    27,    83,    33,    91,
     100,    23,   103,    93,    52,   101,   101,   101,   102,    75,
      77,    63,    37,    77,    37,    85,    37,   101,   101,    88,
      82,    88,    54,    55,    18,    19,    57,    58,    54,    34,
      92,    78,    37,    79,    63,    90,   101,   101,    65,    37,
      83,    37,    54,    59,    37,   101,    79,    57,    76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    51,    52,
      53,    54,    54,    55,    55,    55,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    60,
      61,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    76,    76,    77,
      77,    77,    77,    78,    78,    78,    79,    80,    81,    82,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     101,   102,   102,   103,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     7,     2,     0,     2,     1,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     3,     2,     3,     1,     1,     2,     2,     2,
       4,     0,     3,     1,     1,     1,     1,     1,     4,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     2,     3,     1,     1,     2,     6,     3,     3,
       2,     2,     3,     3,     4,     2,     0,     7,     3,     1,
       1,     1,     1,     0,     2,     2,     5,     2,     4,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     1,     1,     1
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
#line 1338 "parser.tab.c"
    break;

  case 4: /* inicio2: error NEWLINE  */
#line 64 "parser.y"
                  { parisopen = 0; contador = 0; contador2 = 0; whileopen=0; ifopen=0; foropen=0; thenopen=0; printf(" CADENA INVÁLIDA\n"); yyerrok; }
#line 1344 "parser.tab.c"
    break;

  case 20: /* comentario: TK_COMENTARIO  */
#line 88 "parser.y"
              {printf(" -> LINEA %d: CADENA VÁLIDA: comentario\n", linea_actual - 1);}
#line 1350 "parser.tab.c"
    break;

  case 21: /* lectura: leer NEWLINE  */
#line 91 "parser.y"
             {imprimir_in();}
#line 1356 "parser.tab.c"
    break;

  case 23: /* impresion: imprimir NEWLINE  */
#line 96 "parser.y"
                {imprimir_out();}
#line 1362 "parser.tab.c"
    break;

  case 27: /* expresion: logica NEWLINE  */
#line 110 "parser.y"
                       { imprimir_logica(); }
#line 1368 "parser.tab.c"
    break;

  case 28: /* expresion: aritmetica NEWLINE  */
#line 111 "parser.y"
                       { imprimir_aritmetica(); }
#line 1374 "parser.tab.c"
    break;

  case 32: /* otraaritmetica: simarit operador otraaritmetica  */
#line 123 "parser.y"
                                  {contador++; /*esto apra incrementar el contador de simbolos en la operacion */}
#line 1380 "parser.tab.c"
    break;

  case 33: /* simarit: sumar  */
#line 126 "parser.y"
      {strcpy(tipoaritmetica, "SUMA");}
#line 1386 "parser.tab.c"
    break;

  case 34: /* simarit: restar  */
#line 127 "parser.y"
        {strcpy(tipoaritmetica, "RESTA");}
#line 1392 "parser.tab.c"
    break;

  case 35: /* simarit: multiplicar  */
#line 128 "parser.y"
             {strcpy(tipoaritmetica, "MULTIPLICACION");}
#line 1398 "parser.tab.c"
    break;

  case 36: /* simarit: dividir  */
#line 129 "parser.y"
         {strcpy(tipoaritmetica, "DIVISION");}
#line 1404 "parser.tab.c"
    break;

  case 37: /* simarit: potenciar  */
#line 130 "parser.y"
           {strcpy(tipoaritmetica, "POTENCIACION");}
#line 1410 "parser.tab.c"
    break;

  case 40: /* otralogica: conectorlogico operador simlog operador otralogica  */
#line 140 "parser.y"
                                                     {contador2++;}
#line 1416 "parser.tab.c"
    break;

  case 43: /* simlog: TK_MAY  */
#line 147 "parser.y"
           {strcpy(tipologica, "MAYOR QUE");}
#line 1422 "parser.tab.c"
    break;

  case 44: /* simlog: TK_MEN  */
#line 148 "parser.y"
           {strcpy(tipologica, "MENOR QUE");}
#line 1428 "parser.tab.c"
    break;

  case 45: /* simlog: TK_MAIG  */
#line 149 "parser.y"
            {strcpy(tipologica, "MAYOR O IGUAL");}
#line 1434 "parser.tab.c"
    break;

  case 46: /* simlog: TK_MEIG  */
#line 150 "parser.y"
            {strcpy(tipologica, "MENOR O IGUAL");;}
#line 1440 "parser.tab.c"
    break;

  case 47: /* simlog: TK_IG  */
#line 151 "parser.y"
          {strcpy(tipologica, "IGUAL");}
#line 1446 "parser.tab.c"
    break;

  case 48: /* simlog: TK_NIG  */
#line 152 "parser.y"
           {strcpy(tipologica, "DISTINTO");}
#line 1452 "parser.tab.c"
    break;

  case 50: /* definicion: variable definir operador eos  */
#line 161 "parser.y"
                                 {
      imprimir_defnum();/*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1460 "parser.tab.c"
    break;

  case 51: /* definicion: variable definir aritmetica  */
#line 164 "parser.y"
                                 {
     imprimir_defop(); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1468 "parser.tab.c"
    break;

  case 52: /* condicionar: condicion NEWLINE  */
#line 172 "parser.y"
                   {imprimir_condicion();}
#line 1474 "parser.tab.c"
    break;

  case 53: /* condicion: agrupa1 logica agrupa2  */
#line 175 "parser.y"
                         {    contador2=0; }
#line 1480 "parser.tab.c"
    break;

  case 54: /* agrupa1: TK_PAB  */
#line 178 "parser.y"
           {parisopen++;}
#line 1486 "parser.tab.c"
    break;

  case 55: /* agrupa2: TK_PCE  */
#line 181 "parser.y"
           {parisopen--;}
#line 1492 "parser.tab.c"
    break;

  case 56: /* ciclofor: encabezado_for bloque_begin_end  */
#line 186 "parser.y"
                                    {
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);
    }
#line 1500 "parser.tab.c"
    break;

  case 57: /* encabezado_for: for variablefor to operador do NEWLINE  */
#line 192 "parser.y"
                                           { iniciofor = linea_actual - 1; foropen++;}
#line 1506 "parser.tab.c"
    break;

  case 59: /* dowhile: bloque1dw bloque2dw bloque3dw  */
#line 203 "parser.y"
                              { {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, finwhile);}}
#line 1512 "parser.tab.c"
    break;

  case 60: /* bloque1dw: do NEWLINE  */
#line 207 "parser.y"
           {whileopen++; iniciowhile=linea_actual-1;}
#line 1518 "parser.tab.c"
    break;

  case 62: /* bloque3dw: while condicion NEWLINE  */
#line 215 "parser.y"
                         {finwhile=linea_actual-1; whileopen--;}
#line 1524 "parser.tab.c"
    break;

  case 63: /* cicloif: if_encabezado bloque_begin_end if_ramas  */
#line 219 "parser.y"
                                            {
        ifopen--;
        printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", yyvsp[-2], finif);
    }
#line 1533 "parser.tab.c"
    break;

  case 64: /* if_encabezado: if condicion then NEWLINE  */
#line 226 "parser.y"
                              { yyval = linea_actual - 1; ifopen++; }
#line 1539 "parser.tab.c"
    break;

  case 69: /* instrucciones: definicion  */
#line 242 "parser.y"
           { contador = 0; }
#line 1545 "parser.tab.c"
    break;

  case 70: /* instrucciones: lectura  */
#line 243 "parser.y"
          {contador=0;}
#line 1551 "parser.tab.c"
    break;

  case 71: /* instrucciones: impresion  */
#line 244 "parser.y"
           {contador=0;}
#line 1557 "parser.tab.c"
    break;

  case 76: /* bloque_begin_end: begin NEWLINE cuerpo_instrucciones end NEWLINE  */
#line 256 "parser.y"
                                                   { finif = linea_actual - 1; finfor=linea_actual-1; foropen=0; whileopen=0; ifopen=0;}
#line 1563 "parser.tab.c"
    break;

  case 77: /* declarar: declaracion NEWLINE  */
#line 262 "parser.y"
                      {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual - 1);}
#line 1569 "parser.tab.c"
    break;

  case 81: /* then: TK_THEN  */
#line 277 "parser.y"
        {thenopen=1;}
#line 1575 "parser.tab.c"
    break;

  case 84: /* else: TK_ELSE  */
#line 286 "parser.y"
        {thenopen=1;}
#line 1581 "parser.tab.c"
    break;

  case 90: /* end: TK_END  */
#line 304 "parser.y"
        {thenopen=0;}
#line 1587 "parser.tab.c"
    break;


#line 1591 "parser.tab.c"

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

#line 472 "parser.y"


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
