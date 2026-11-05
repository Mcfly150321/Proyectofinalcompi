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
int ramas=0;
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

#line 111 "parser.tab.c"




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
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_bloque = 40,                    /* bloque  */
  YYSYMBOL_opt_inicio = 41,                /* opt_inicio  */
  YYSYMBOL_opt_nl = 42,                    /* opt_nl  */
  YYSYMBOL_cuerpo = 43,                    /* cuerpo  */
  YYSYMBOL_operacion = 44,                 /* operacion  */
  YYSYMBOL_comentario = 45,                /* comentario  */
  YYSYMBOL_lectura = 46,                   /* lectura  */
  YYSYMBOL_leer = 47,                      /* leer  */
  YYSYMBOL_impresion = 48,                 /* impresion  */
  YYSYMBOL_imprimir = 49,                  /* imprimir  */
  YYSYMBOL_output = 50,                    /* output  */
  YYSYMBOL_input = 51,                     /* input  */
  YYSYMBOL_aritmetica = 52,                /* aritmetica  */
  YYSYMBOL_oparit = 53,                    /* oparit  */
  YYSYMBOL_otraaritmetica = 54,            /* otraaritmetica  */
  YYSYMBOL_simarit = 55,                   /* simarit  */
  YYSYMBOL_logica = 56,                    /* logica  */
  YYSYMBOL_otralogica = 57,                /* otralogica  */
  YYSYMBOL_conectorlogico = 58,            /* conectorlogico  */
  YYSYMBOL_simlog = 59,                    /* simlog  */
  YYSYMBOL_definicion = 60,                /* definicion  */
  YYSYMBOL_condicion = 61,                 /* condicion  */
  YYSYMBOL_agrupa1 = 62,                   /* agrupa1  */
  YYSYMBOL_agrupa2 = 63,                   /* agrupa2  */
  YYSYMBOL_ciclofor = 64,                  /* ciclofor  */
  YYSYMBOL_encabezado_for = 65,            /* encabezado_for  */
  YYSYMBOL_66_1 = 66,                      /* @1  */
  YYSYMBOL_variablefor = 67,               /* variablefor  */
  YYSYMBOL_dowhile = 68,                   /* dowhile  */
  YYSYMBOL_bloque1dw = 69,                 /* bloque1dw  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
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
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       0,    62,    62,    65,    69,    70,    71,    75,    76,    79,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      94,    97,    99,   102,   105,   108,   111,   119,   122,   125,
     126,   129,   130,   131,   132,   133,   139,   142,   143,   146,
     147,   150,   151,   152,   153,   154,   155,   164,   167,   176,
     179,   182,   187,   195,   195,   199,   206,   210,   210,   214,
     218,   222,   234,   238,   242,   243,   244,   250,   251,   252,
     253,   254,   255,   256,   260,   261,   262,   267,   273,   276,
     280,   281,   288,   291,   294,   297,   300,   303,   306,   309,
     312,   315,   318,   321,   325,   328,   331,   334,   337,   340,
     343,   344,   347,   348,   349,   352,   355
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
  "TK_COMENTARIO", "NEWLINE", "$accept", "programa", "bloque",
  "opt_inicio", "opt_nl", "cuerpo", "operacion", "comentario", "lectura",
  "leer", "impresion", "imprimir", "output", "input", "aritmetica",
  "oparit", "otraaritmetica", "simarit", "logica", "otralogica",
  "conectorlogico", "simlog", "definicion", "condicion", "agrupa1",
  "agrupa2", "ciclofor", "encabezado_for", "@1", "variablefor", "dowhile",
  "bloque1dw", "$@2", "bloque2dw", "bloque3dw", "cicloif", "if_encabezado",
  "cuerpo_instrucciones", "if_ramas", "instrucciones", "masinstrucciones",
  "bloque_begin_end", "declarar", "declaracion", "lista_ids", "then",
  "begin", "if", "else", "dospuntos", "eos", "for", "do", "to", "end",
  "variable", "numero", "sumar", "restar", "multiplicar", "dividir",
  "potenciar", "definir", "operador", "factores", "allocate", "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -117,    18,     1,  -117,  -117,  -117,  -117,  -117,  -117,    -1,
    -117,     5,    75,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,    36,    36,  -117,  -117,
      16,  -117,   119,  -117,    16,  -117,  -117,    42,    36,  -117,
      29,    22,    33,    33,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,    26,  -117,  -117,    37,    48,  -117,    53,
      59,    46,    37,  -117,  -117,  -117,    60,    36,    59,  -117,
    -117,  -117,    88,  -117,  -117,    42,   106,  -117,  -117,    54,
    -117,  -117,  -117,  -117,    74,    59,  -117,  -117,    78,   144,
    -117,  -117,    59,    59,    50,  -117,    33,    67,  -117,    33,
       6,  -117,    58,  -117,  -117,  -117,  -117,    10,    42,    50,
    -117,  -117,   159,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
      59,    62,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
      59,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,   106,
    -117,    53,    59,    52,  -117,   159,    50,  -117,   159,  -117,
    -117,  -117,    59,  -117,  -117,    59,    10,    74,   144,    50,
     159,    48,  -117,    59,  -117,  -117,    52,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     4,    20,     5,     2,     6,     0,
      10,     0,     9,     4,    92,    26,    25,    84,    88,    89,
      15,    19,    17,    21,    18,    23,     0,     0,    13,    11,
       0,    14,     0,    16,     0,    12,    78,     0,     0,    57,
      80,     3,     0,     0,    83,    52,     7,    73,    68,    69,
      67,    71,    72,     0,    70,    74,     0,    64,    50,     0,
       0,     0,     0,     7,    99,    86,     0,     0,     0,    87,
      24,    22,     0,   106,    56,     0,    59,    85,    61,     7,
      82,     7,    95,    93,     0,     0,   102,   103,     0,     0,
     100,    90,     0,     0,    58,   105,     0,    80,    48,     0,
       0,     8,     0,    74,    60,    76,    75,     0,     0,    62,
      51,    49,     0,   104,    41,    42,    43,    44,    45,    46,
       0,     0,    55,    79,    81,    27,    94,    97,    96,    98,
       0,    47,    31,    32,    33,    34,    35,    91,     7,    63,
      66,     0,     0,    37,    53,    29,    77,     7,    29,    39,
      40,    36,     0,     7,    28,     0,     0,     0,     0,    54,
      29,    64,   101,     0,    30,    65,    37,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,  -117,     3,   -57,  -117,  -117,    21,    82,  -117,
      83,  -117,  -117,  -117,  -117,  -117,  -116,   -66,  -117,   -68,
    -117,   -56,    92,   -67,   -35,   -50,    96,  -117,  -117,  -117,
      97,  -117,  -117,  -117,  -117,    98,  -117,  -117,   -44,   -29,
      17,   -33,  -117,  -117,    24,   -19,  -117,    47,  -117,  -117,
     -24,  -117,     8,  -117,  -117,   -12,    45,  -117,   -95,  -117,
    -117,  -117,    68,   -64,  -117,  -117,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     2,    72,    11,    12,    47,    48,    23,
      49,    25,    26,    27,    98,    99,   154,   155,    84,   151,
     152,   120,    50,    59,    85,   111,    51,    30,   153,    61,
      52,    32,    63,    53,    74,    54,    34,   102,    78,   106,
      76,    45,    35,    36,    66,    81,    46,    37,    79,    67,
      70,    38,    39,    92,   138,    86,    87,   132,    88,   134,
     135,   136,    68,    89,    90,    96,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    57,    60,    55,   100,   133,    94,     9,   104,   126,
      82,   127,   128,   129,    42,    43,    41,   133,     3,    71,
      56,   112,   107,     8,   109,     4,    62,    69,   121,   122,
       8,    10,   157,    21,   130,     5,     6,     5,     6,    13,
      60,   141,    44,   103,   164,    14,   142,   101,    44,    64,
     133,    65,    58,   133,    69,    97,   143,    64,     5,     6,
      56,    73,     8,    82,    56,   133,   145,    83,    14,    58,
     149,   150,   123,    60,   140,   125,   131,    77,   148,    91,
      80,   146,    17,    95,    14,   110,    83,   101,   158,    65,
     156,   160,   137,    19,    22,    24,   159,    14,   167,   166,
      15,    16,   163,    17,    28,    18,    19,   162,    29,    31,
      33,     5,    20,    15,    16,    14,    17,   165,    18,    19,
     139,   124,   147,   161,     5,   101,   108,    56,    14,   144,
      93,    15,    16,   113,    17,     0,    18,    19,     0,     0,
       0,     0,     5,   105,    15,    16,     0,    17,     0,    18,
      19,     0,     0,     0,     0,     5,   114,   115,   116,   117,
     118,   119,   126,    82,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
      12,    34,    37,    32,    68,   100,    63,     4,    75,     3,
       4,     5,     6,     7,    26,    27,    13,   112,     0,    43,
      32,    85,    79,     2,    81,    24,    38,    21,    92,    93,
       9,    32,   148,    12,   100,    36,    37,    36,    37,    34,
      75,   108,    32,    72,   160,     9,   112,    37,    32,    20,
     145,    22,    10,   148,    21,    67,   120,    20,    36,    37,
      72,    35,    41,     4,    76,   160,   130,     8,     9,    10,
      18,    19,    96,   108,   107,    99,   100,    29,   142,    33,
      27,   138,    28,    23,     9,    11,     8,    37,   152,    22,
     147,   155,    34,    31,    12,    12,   153,     9,   166,   163,
      25,    26,   158,    28,    12,    30,    31,   157,    12,    12,
      12,    36,    37,    25,    26,     9,    28,   161,    30,    31,
     103,    97,   141,   156,    36,    37,    79,   139,     9,   121,
      62,    25,    26,    88,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    25,    26,    -1,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    12,    13,    14,    15,
      16,    17,     3,     4,     5,     6,     7
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    41,     0,    24,    36,    37,    40,    45,    41,
      32,    43,    44,    34,     9,    25,    26,    28,    30,    31,
      37,    45,    46,    47,    48,    49,    50,    51,    60,    64,
      65,    68,    69,    73,    74,    80,    81,    85,    89,    90,
      93,    41,    93,    93,    32,    79,    84,    45,    46,    48,
      60,    64,    68,    71,    73,    77,    93,    79,    10,    61,
      62,    67,    93,    70,    20,    22,    82,    87,   100,    21,
      88,    88,    42,    35,    72,   104,    78,    29,    76,    86,
      27,    83,     4,     8,    56,    62,    93,    94,    96,   101,
     102,    33,    91,   100,    42,    23,   103,    93,    52,    53,
     101,    37,    75,    77,    61,    37,    77,    42,    85,    42,
      11,    63,   101,    94,    12,    13,    14,    15,    16,    17,
      59,   101,   101,    88,    82,    88,     3,     5,     6,     7,
      55,    88,    95,    96,    97,    98,    99,    34,    92,    78,
      79,    61,    55,   101,    90,   101,    42,    83,   101,    18,
      19,    57,    58,    66,    54,    55,    42,    54,   101,    42,
     101,    79,    63,    59,    54,    76,   101,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    41,    41,    41,    42,    42,    43,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      54,    55,    55,    55,    55,    55,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      62,    63,    64,    66,    65,    67,    68,    70,    69,    71,
      72,    73,    74,    75,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    80,    81,
      82,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   101,   102,   102,   102,   103,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     6,     0,     2,     2,     0,     2,     1,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     3,     1,     3,     1,     1,     2,     4,     0,
       3,     1,     1,     1,     1,     1,     4,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       1,     1,     2,     0,     7,     3,     3,     0,     3,     2,
       2,     3,     4,     2,     0,     7,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     2,     5,     1,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     1,     1,     2,     1,     1
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
  case 3: /* bloque: TK_MAIN opt_inicio TK_BEGIN cuerpo TK_END opt_inicio  */
#line 65 "parser.y"
                                                        {
        printf("\nBloque valido codigo completo\n");
    }
#line 1335 "parser.tab.c"
    break;

  case 20: /* comentario: TK_COMENTARIO  */
#line 94 "parser.y"
              {printf(" -> LINEA %d: CADENA VÁLIDA: comentario\n", linea_actual);}
#line 1341 "parser.tab.c"
    break;

  case 21: /* lectura: leer  */
#line 97 "parser.y"
     {imprimir_in();}
#line 1347 "parser.tab.c"
    break;

  case 23: /* impresion: imprimir  */
#line 102 "parser.y"
        {imprimir_out();}
#line 1353 "parser.tab.c"
    break;

  case 30: /* otraaritmetica: simarit operador otraaritmetica  */
#line 126 "parser.y"
                                  {contador++; /*esto apra incrementar el contador de simbolos en la operacion */}
#line 1359 "parser.tab.c"
    break;

  case 31: /* simarit: sumar  */
#line 129 "parser.y"
      {strcpy(tipoaritmetica, "SUMA");}
#line 1365 "parser.tab.c"
    break;

  case 32: /* simarit: restar  */
#line 130 "parser.y"
        {strcpy(tipoaritmetica, "RESTA");}
#line 1371 "parser.tab.c"
    break;

  case 33: /* simarit: multiplicar  */
#line 131 "parser.y"
             {strcpy(tipoaritmetica, "MULTIPLICACION");}
#line 1377 "parser.tab.c"
    break;

  case 34: /* simarit: dividir  */
#line 132 "parser.y"
         {strcpy(tipoaritmetica, "DIVISION");}
#line 1383 "parser.tab.c"
    break;

  case 35: /* simarit: potenciar  */
#line 133 "parser.y"
           {strcpy(tipoaritmetica, "POTENCIACION");}
#line 1389 "parser.tab.c"
    break;

  case 38: /* otralogica: conectorlogico operador simlog operador otralogica  */
#line 143 "parser.y"
                                                     {contador2++;}
#line 1395 "parser.tab.c"
    break;

  case 41: /* simlog: TK_MAY  */
#line 150 "parser.y"
           {strcpy(tipologica, "MAYOR QUE");}
#line 1401 "parser.tab.c"
    break;

  case 42: /* simlog: TK_MEN  */
#line 151 "parser.y"
           {strcpy(tipologica, "MENOR QUE");}
#line 1407 "parser.tab.c"
    break;

  case 43: /* simlog: TK_MAIG  */
#line 152 "parser.y"
            {strcpy(tipologica, "MAYOR O IGUAL");}
#line 1413 "parser.tab.c"
    break;

  case 44: /* simlog: TK_MEIG  */
#line 153 "parser.y"
            {strcpy(tipologica, "MENOR O IGUAL");;}
#line 1419 "parser.tab.c"
    break;

  case 45: /* simlog: TK_IG  */
#line 154 "parser.y"
          {strcpy(tipologica, "IGUAL");}
#line 1425 "parser.tab.c"
    break;

  case 46: /* simlog: TK_NIG  */
#line 155 "parser.y"
           {strcpy(tipologica, "DISTINTO");}
#line 1431 "parser.tab.c"
    break;

  case 47: /* definicion: variable definir operador eos  */
#line 164 "parser.y"
                                 {
      imprimir_defnum();/*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1439 "parser.tab.c"
    break;

  case 48: /* definicion: variable definir aritmetica  */
#line 167 "parser.y"
                                 {
     imprimir_defop(); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1447 "parser.tab.c"
    break;

  case 49: /* condicion: agrupa1 logica agrupa2  */
#line 176 "parser.y"
                         {    contador2=0; }
#line 1453 "parser.tab.c"
    break;

  case 50: /* agrupa1: TK_PAB  */
#line 179 "parser.y"
           {parisopen++;}
#line 1459 "parser.tab.c"
    break;

  case 51: /* agrupa2: TK_PCE  */
#line 182 "parser.y"
           {parisopen--;}
#line 1465 "parser.tab.c"
    break;

  case 52: /* ciclofor: encabezado_for bloque_begin_end  */
#line 187 "parser.y"
                                    {
      foropen--;
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", yyvsp[-1], yyvsp[0]);
        
    }
#line 1475 "parser.tab.c"
    break;

  case 53: /* @1: %empty  */
#line 195 "parser.y"
                                   { iniciofor = linea_actual; foropen++; yyval=yyvsp[-4];}
#line 1481 "parser.tab.c"
    break;

  case 56: /* dowhile: bloque1dw bloque2dw bloque3dw  */
#line 206 "parser.y"
                              { {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, finwhile);}}
#line 1487 "parser.tab.c"
    break;

  case 57: /* $@2: %empty  */
#line 210 "parser.y"
   {whileopen++; iniciowhile=linea_actual;}
#line 1493 "parser.tab.c"
    break;

  case 60: /* bloque3dw: while condicion  */
#line 218 "parser.y"
                 {finwhile=linea_actual; whileopen--;}
#line 1499 "parser.tab.c"
    break;

  case 61: /* cicloif: if_encabezado bloque_begin_end if_ramas  */
#line 222 "parser.y"
                                            {
        ifopen--;
        if (yyvsp[0]>0){
            printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF-ELSE\n", yyvsp[-2], yyvsp[0]);
        }else{
        printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", yyvsp[-2], yyvsp[-1]);
        }
      }
#line 1512 "parser.tab.c"
    break;

  case 62: /* if_encabezado: if condicion then opt_nl  */
#line 234 "parser.y"
                             { yyval = yyvsp[-3]; ifopen++; }
#line 1518 "parser.tab.c"
    break;

  case 64: /* if_ramas: %empty  */
#line 242 "parser.y"
           { yyval = 0; }
#line 1524 "parser.tab.c"
    break;

  case 65: /* if_ramas: else if condicion then opt_nl bloque_begin_end if_ramas  */
#line 243 "parser.y"
                                                            { yyval = (yyvsp[0] != 0) ? yyvsp[0] : yyvsp[-1]; }
#line 1530 "parser.tab.c"
    break;

  case 66: /* if_ramas: else opt_nl bloque_begin_end  */
#line 244 "parser.y"
                                 { yyval = yyvsp[0]; }
#line 1536 "parser.tab.c"
    break;

  case 67: /* instrucciones: definicion  */
#line 250 "parser.y"
           { contador = 0; }
#line 1542 "parser.tab.c"
    break;

  case 68: /* instrucciones: lectura  */
#line 251 "parser.y"
          {contador=0;}
#line 1548 "parser.tab.c"
    break;

  case 69: /* instrucciones: impresion  */
#line 252 "parser.y"
           {contador=0;}
#line 1554 "parser.tab.c"
    break;

  case 77: /* bloque_begin_end: begin opt_nl cuerpo_instrucciones end opt_nl  */
#line 267 "parser.y"
                                                { yyval = yyvsp[-1]; }
#line 1560 "parser.tab.c"
    break;

  case 78: /* declarar: declaracion  */
#line 273 "parser.y"
            {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual);}
#line 1566 "parser.tab.c"
    break;

  case 82: /* then: TK_THEN  */
#line 288 "parser.y"
        {thenopen=1;}
#line 1572 "parser.tab.c"
    break;

  case 84: /* if: TK_IF  */
#line 294 "parser.y"
      { yyval = linea_actual; }
#line 1578 "parser.tab.c"
    break;

  case 85: /* else: TK_ELSE  */
#line 297 "parser.y"
            {thenopen=1;}
#line 1584 "parser.tab.c"
    break;

  case 88: /* for: TK_FOR  */
#line 306 "parser.y"
       {yyval = linea_actual;}
#line 1590 "parser.tab.c"
    break;

  case 91: /* end: TK_END  */
#line 315 "parser.y"
           { thenopen = 0; yyval = linea_actual; }
#line 1596 "parser.tab.c"
    break;


#line 1600 "parser.tab.c"

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

#line 484 "parser.y"


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
