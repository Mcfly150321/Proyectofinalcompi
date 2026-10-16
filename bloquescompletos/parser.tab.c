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
  YYSYMBOL_REDUCE_NO_ELSE = 38,            /* REDUCE_NO_ELSE  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_bloque = 41,                    /* bloque  */
  YYSYMBOL_opt_inicio = 42,                /* opt_inicio  */
  YYSYMBOL_opt_nl = 43,                    /* opt_nl  */
  YYSYMBOL_cuerpo = 44,                    /* cuerpo  */
  YYSYMBOL_operacion = 45,                 /* operacion  */
  YYSYMBOL_comentario = 46,                /* comentario  */
  YYSYMBOL_lectura = 47,                   /* lectura  */
  YYSYMBOL_leer = 48,                      /* leer  */
  YYSYMBOL_impresion = 49,                 /* impresion  */
  YYSYMBOL_imprimir = 50,                  /* imprimir  */
  YYSYMBOL_output = 51,                    /* output  */
  YYSYMBOL_input = 52,                     /* input  */
  YYSYMBOL_expresion = 53,                 /* expresion  */
  YYSYMBOL_aritmetica = 54,                /* aritmetica  */
  YYSYMBOL_oparit = 55,                    /* oparit  */
  YYSYMBOL_otraaritmetica = 56,            /* otraaritmetica  */
  YYSYMBOL_simarit = 57,                   /* simarit  */
  YYSYMBOL_logica = 58,                    /* logica  */
  YYSYMBOL_otralogica = 59,                /* otralogica  */
  YYSYMBOL_conectorlogico = 60,            /* conectorlogico  */
  YYSYMBOL_simlog = 61,                    /* simlog  */
  YYSYMBOL_definicion = 62,                /* definicion  */
  YYSYMBOL_condicionar = 63,               /* condicionar  */
  YYSYMBOL_condicion = 64,                 /* condicion  */
  YYSYMBOL_agrupa1 = 65,                   /* agrupa1  */
  YYSYMBOL_agrupa2 = 66,                   /* agrupa2  */
  YYSYMBOL_ciclofor = 67,                  /* ciclofor  */
  YYSYMBOL_encabezado_for = 68,            /* encabezado_for  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_variablefor = 70,               /* variablefor  */
  YYSYMBOL_dowhile = 71,                   /* dowhile  */
  YYSYMBOL_bloque1dw = 72,                 /* bloque1dw  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_bloque2dw = 74,                 /* bloque2dw  */
  YYSYMBOL_bloque3dw = 75,                 /* bloque3dw  */
  YYSYMBOL_cicloif = 76,                   /* cicloif  */
  YYSYMBOL_if_encabezado = 77,             /* if_encabezado  */
  YYSYMBOL_cuerpo_instrucciones = 78,      /* cuerpo_instrucciones  */
  YYSYMBOL_if_ramas = 79,                  /* if_ramas  */
  YYSYMBOL_instrucciones = 80,             /* instrucciones  */
  YYSYMBOL_masinstrucciones = 81,          /* masinstrucciones  */
  YYSYMBOL_bloque_begin_end = 82,          /* bloque_begin_end  */
  YYSYMBOL_declarar = 83,                  /* declarar  */
  YYSYMBOL_declaracion = 84,               /* declaracion  */
  YYSYMBOL_lista_ids = 85,                 /* lista_ids  */
  YYSYMBOL_then = 86,                      /* then  */
  YYSYMBOL_begin = 87,                     /* begin  */
  YYSYMBOL_if = 88,                        /* if  */
  YYSYMBOL_else = 89,                      /* else  */
  YYSYMBOL_dospuntos = 90,                 /* dospuntos  */
  YYSYMBOL_eos = 91,                       /* eos  */
  YYSYMBOL_for = 92,                       /* for  */
  YYSYMBOL_do = 93,                        /* do  */
  YYSYMBOL_to = 94,                        /* to  */
  YYSYMBOL_end = 95,                       /* end  */
  YYSYMBOL_variable = 96,                  /* variable  */
  YYSYMBOL_numero = 97,                    /* numero  */
  YYSYMBOL_sumar = 98,                     /* sumar  */
  YYSYMBOL_restar = 99,                    /* restar  */
  YYSYMBOL_multiplicar = 100,              /* multiplicar  */
  YYSYMBOL_dividir = 101,                  /* dividir  */
  YYSYMBOL_potenciar = 102,                /* potenciar  */
  YYSYMBOL_definir = 103,                  /* definir  */
  YYSYMBOL_operador = 104,                 /* operador  */
  YYSYMBOL_factores = 105,                 /* factores  */
  YYSYMBOL_allocate = 106,                 /* allocate  */
  YYSYMBOL_while = 107                     /* while  */
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
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    64,    68,    69,    70,    74,    75,    78,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    95,    98,   100,   103,   106,   109,   112,   117,
     118,   123,   126,   129,   130,   133,   134,   135,   136,   137,
     143,   146,   147,   150,   151,   154,   155,   156,   157,   158,
     159,   168,   171,   179,   182,   185,   188,   193,   199,   199,
     203,   210,   214,   214,   218,   222,   226,   233,   237,   241,
     242,   243,   249,   250,   251,   252,   253,   254,   255,   259,
     260,   261,   266,   272,   275,   279,   280,   287,   290,   293,
     296,   299,   302,   305,   308,   311,   314,   317,   320,   324,
     327,   330,   333,   336,   339,   342,   343,   346,   347,   348,
     351,   354
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
  "TK_COMENTARIO", "NEWLINE", "REDUCE_NO_ELSE", "$accept", "programa",
  "bloque", "opt_inicio", "opt_nl", "cuerpo", "operacion", "comentario",
  "lectura", "leer", "impresion", "imprimir", "output", "input",
  "expresion", "aritmetica", "oparit", "otraaritmetica", "simarit",
  "logica", "otralogica", "conectorlogico", "simlog", "definicion",
  "condicionar", "condicion", "agrupa1", "agrupa2", "ciclofor",
  "encabezado_for", "$@1", "variablefor", "dowhile", "bloque1dw", "$@2",
  "bloque2dw", "bloque3dw", "cicloif", "if_encabezado",
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

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -132,     7,   -13,  -132,  -132,  -132,  -132,  -132,  -132,   -22,
    -132,   -21,   114,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    18,
      18,  -132,    -4,    41,     4,  -132,  -132,     6,    47,  -132,
      13,  -132,   143,  -132,    13,  -132,  -132,    58,    18,  -132,
      15,  -132,    61,   177,  -132,    24,    41,    41,  -132,  -132,
    -132,  -132,  -132,    59,    47,  -132,   177,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,    38,  -132,  -132,    51,
      45,    49,    47,    48,    51,  -132,  -132,  -132,    60,    18,
      47,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,    47,    47,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,   128,    47,    22,  -132,  -132,    58,   129,
    -132,  -132,    67,  -132,  -132,   183,  -132,    47,    47,    62,
    -132,    41,    64,  -132,   122,   128,    46,   128,  -132,    54,
    -132,  -132,  -132,  -132,   -11,    58,    62,    65,  -132,  -132,
    -132,  -132,  -132,    47,  -132,  -132,  -132,    47,    59,  -132,
    -132,   129,  -132,    49,  -132,   128,   183,  -132,    62,  -132,
    -132,  -132,    47,   -11,    62,    46,    45,  -132,  -132
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     4,    22,     5,     2,     6,     0,
      10,     0,     9,     4,   100,    98,    97,    55,    28,    27,
      89,    93,    94,    17,    21,    19,    23,    20,    25,     0,
       0,    11,     0,     0,     0,    12,    14,     0,     0,    13,
       0,    16,     0,    18,     0,    15,    83,     0,     0,    62,
     107,   108,     0,     0,   105,     3,     0,     0,    30,    92,
      31,    29,    53,     0,     0,   107,     0,    88,    57,     7,
      78,    73,    74,    72,    76,    77,     0,    75,    79,     0,
      69,     0,     0,     0,     0,     7,   104,    91,     0,     0,
       0,   109,    99,   102,   101,   103,    45,    46,    47,    48,
      49,    50,     0,     0,    35,    36,    37,    38,    39,    26,
      24,    56,    54,     0,     0,     0,   111,    61,     0,    64,
      90,    66,     7,    87,     7,     0,    95,     0,     0,    63,
     110,     0,    85,    52,     0,    33,    41,    33,     8,     0,
      79,    65,    81,    80,     0,     0,    67,     0,    60,    84,
      86,    51,    32,     0,    43,    44,    40,     0,     0,    96,
       7,    68,    71,     0,    58,    33,     0,   106,    82,     7,
       7,    34,     0,     0,    59,    41,    69,    42,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,    36,   -80,  -132,  -132,    20,    86,  -132,
      88,  -132,  -132,  -132,  -132,    12,  -132,  -131,   -41,    92,
     -70,  -132,   -58,    97,  -132,   -39,    -8,   -47,   100,  -132,
    -132,  -132,   101,  -132,  -132,  -132,  -132,   102,  -132,  -132,
     -60,   -33,   -20,   -43,  -132,  -132,     9,   -44,  -132,    25,
    -132,  -132,   -37,  -132,    -1,  -132,  -132,   -12,    96,  -132,
     -50,  -132,  -132,  -132,    69,   -36,  -132,  -132,  -132
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     2,   115,    11,    12,    70,    71,    26,
      72,    28,    29,    30,    31,    32,    33,   152,   153,    63,
     156,   157,   103,    73,    36,    37,    64,   112,    74,    40,
     170,    83,    75,    42,    85,    76,   117,    77,    44,   139,
     121,   143,   119,    68,    45,    46,    88,   124,    69,    47,
     122,    89,    60,    48,    49,   127,   160,    65,    51,   104,
      52,   106,   107,   108,    90,    53,    54,   131,   118
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    80,    66,   105,    38,   129,   158,     3,    81,    78,
      10,     4,   102,    13,     5,     6,   105,    56,    57,   109,
     110,    67,     8,     5,     6,   114,   138,    16,   113,     8,
      79,    16,    24,    58,   171,    86,    84,    87,   -85,    82,
       9,    61,   144,    62,   146,    67,   125,    18,    19,    55,
      20,    14,    21,    22,   134,    15,    16,    17,     5,   138,
       5,     6,    59,   105,   154,   155,   135,   136,    17,    15,
     111,    86,   114,   116,   120,     8,   123,   132,   137,   141,
     168,   126,   140,   130,   105,   105,    87,   105,   159,   173,
     174,   147,   148,   102,   149,    20,    22,   151,    25,   138,
      27,   162,   133,    79,    34,   177,   163,    79,   172,    35,
      82,   167,    39,    41,    43,   105,   178,   165,    14,   169,
     161,   166,    15,    16,    17,    92,    14,    93,    94,    95,
     176,    92,    14,    93,    94,    95,   175,    82,    16,    18,
      19,   150,    20,    59,    21,    22,   164,   145,    91,    79,
       5,    23,    16,   128,    18,    19,     0,    20,     0,    21,
      22,     0,     0,     0,     0,     5,   142,     0,    18,    19,
       0,    20,     0,    21,    22,     0,     0,     0,     0,     5,
      92,    14,    93,    94,    95,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,    96,    97,    98,    99,   100,
     101
};

static const yytype_int16 yycheck[] =
{
      12,    44,    38,    53,    12,    85,   137,     0,    47,    42,
      32,    24,    53,    34,    36,    37,    66,    29,    30,    56,
      57,    32,     2,    36,    37,    66,    37,     9,    64,     9,
      42,     9,    12,    37,   165,    20,    48,    22,    23,    47,
       4,    37,   122,    37,   124,    32,    82,    25,    26,    13,
      28,     4,    30,    31,    90,     8,     9,    10,    36,    37,
      36,    37,    21,   113,    18,    19,   102,   103,    10,     8,
      11,    20,   113,    35,    29,    55,    27,    89,   114,   118,
     160,    33,   115,    23,   134,   135,    22,   137,    34,   169,
     170,   127,   128,   134,   131,    28,    31,   134,    12,    37,
      12,   144,    90,   115,    12,   175,   145,   119,   166,    12,
     118,   158,    12,    12,    12,   165,   176,   153,     4,   163,
     140,   157,     8,     9,    10,     3,     4,     5,     6,     7,
     173,     3,     4,     5,     6,     7,   172,   145,     9,    25,
      26,   132,    28,    21,    30,    31,   147,   122,    52,   161,
      36,    37,     9,    84,    25,    26,    -1,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    37,    -1,    25,    26,
      -1,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    12,    13,    14,    15,    16,
      17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    42,     0,    24,    36,    37,    41,    46,    42,
      32,    44,    45,    34,     4,     8,     9,    10,    25,    26,
      28,    30,    31,    37,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    58,    62,    63,    64,    65,    67,
      68,    71,    72,    76,    77,    83,    84,    88,    92,    93,
      96,    97,    99,   104,   105,    42,    96,    96,    37,    21,
      91,    37,    37,    58,    65,    96,   104,    32,    82,    87,
      46,    47,    49,    62,    67,    71,    74,    76,    80,    96,
      82,    64,    65,    70,    96,    73,    20,    22,    85,    90,
     103,    97,     3,     5,     6,     7,    12,    13,    14,    15,
      16,    17,    57,    61,    98,    99,   100,   101,   102,    91,
      91,    11,    66,   104,    57,    43,    35,    75,   107,    81,
      29,    79,    89,    27,    86,   104,    33,    94,   103,    43,
      23,   106,    96,    54,   104,   104,   104,   104,    37,    78,
      80,    64,    37,    80,    43,    88,    43,   104,   104,    91,
      85,    91,    56,    57,    18,    19,    59,    60,    56,    34,
      95,    81,    82,    64,    93,   104,   104,    66,    43,    86,
      69,    56,    61,    43,    43,   104,    82,    59,    79
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    42,    43,    43,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      53,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    64,    65,    66,    67,    69,    68,
      70,    71,    73,    72,    74,    75,    76,    77,    78,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    82,    83,    84,    85,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   104,   105,   105,   105,
     106,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     6,     0,     2,     2,     0,     2,     1,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     3,     1,     3,     1,     1,     2,
       2,     2,     4,     0,     3,     1,     1,     1,     1,     1,
       4,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     2,     3,     1,     1,     2,     0,     7,
       3,     3,     0,     3,     2,     2,     3,     4,     2,     0,
       7,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     5,     1,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     1,     1,     2,
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
  case 3: /* bloque: TK_MAIN opt_inicio TK_BEGIN cuerpo TK_END opt_inicio  */
#line 64 "parser.y"
                                                        {
        printf("\nBloque valido codigo completo\n");
    }
#line 1352 "parser.tab.c"
    break;

  case 22: /* comentario: TK_COMENTARIO  */
#line 95 "parser.y"
              {printf(" -> LINEA %d: CADENA VÁLIDA: comentario\n", linea_actual);}
#line 1358 "parser.tab.c"
    break;

  case 23: /* lectura: leer  */
#line 98 "parser.y"
     {imprimir_in();}
#line 1364 "parser.tab.c"
    break;

  case 25: /* impresion: imprimir  */
#line 103 "parser.y"
        {imprimir_out();}
#line 1370 "parser.tab.c"
    break;

  case 29: /* expresion: logica NEWLINE  */
#line 117 "parser.y"
                       { imprimir_logica(); }
#line 1376 "parser.tab.c"
    break;

  case 30: /* expresion: aritmetica NEWLINE  */
#line 118 "parser.y"
                       { imprimir_aritmetica(); }
#line 1382 "parser.tab.c"
    break;

  case 34: /* otraaritmetica: simarit operador otraaritmetica  */
#line 130 "parser.y"
                                  {contador++; /*esto apra incrementar el contador de simbolos en la operacion */}
#line 1388 "parser.tab.c"
    break;

  case 35: /* simarit: sumar  */
#line 133 "parser.y"
      {strcpy(tipoaritmetica, "SUMA");}
#line 1394 "parser.tab.c"
    break;

  case 36: /* simarit: restar  */
#line 134 "parser.y"
        {strcpy(tipoaritmetica, "RESTA");}
#line 1400 "parser.tab.c"
    break;

  case 37: /* simarit: multiplicar  */
#line 135 "parser.y"
             {strcpy(tipoaritmetica, "MULTIPLICACION");}
#line 1406 "parser.tab.c"
    break;

  case 38: /* simarit: dividir  */
#line 136 "parser.y"
         {strcpy(tipoaritmetica, "DIVISION");}
#line 1412 "parser.tab.c"
    break;

  case 39: /* simarit: potenciar  */
#line 137 "parser.y"
           {strcpy(tipoaritmetica, "POTENCIACION");}
#line 1418 "parser.tab.c"
    break;

  case 42: /* otralogica: conectorlogico operador simlog operador otralogica  */
#line 147 "parser.y"
                                                     {contador2++;}
#line 1424 "parser.tab.c"
    break;

  case 45: /* simlog: TK_MAY  */
#line 154 "parser.y"
           {strcpy(tipologica, "MAYOR QUE");}
#line 1430 "parser.tab.c"
    break;

  case 46: /* simlog: TK_MEN  */
#line 155 "parser.y"
           {strcpy(tipologica, "MENOR QUE");}
#line 1436 "parser.tab.c"
    break;

  case 47: /* simlog: TK_MAIG  */
#line 156 "parser.y"
            {strcpy(tipologica, "MAYOR O IGUAL");}
#line 1442 "parser.tab.c"
    break;

  case 48: /* simlog: TK_MEIG  */
#line 157 "parser.y"
            {strcpy(tipologica, "MENOR O IGUAL");;}
#line 1448 "parser.tab.c"
    break;

  case 49: /* simlog: TK_IG  */
#line 158 "parser.y"
          {strcpy(tipologica, "IGUAL");}
#line 1454 "parser.tab.c"
    break;

  case 50: /* simlog: TK_NIG  */
#line 159 "parser.y"
           {strcpy(tipologica, "DISTINTO");}
#line 1460 "parser.tab.c"
    break;

  case 51: /* definicion: variable definir operador eos  */
#line 168 "parser.y"
                                 {
      imprimir_defnum();/*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1468 "parser.tab.c"
    break;

  case 52: /* definicion: variable definir aritmetica  */
#line 171 "parser.y"
                                 {
     imprimir_defop(); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1476 "parser.tab.c"
    break;

  case 53: /* condicionar: condicion NEWLINE  */
#line 179 "parser.y"
                   {imprimir_condicion();}
#line 1482 "parser.tab.c"
    break;

  case 54: /* condicion: agrupa1 logica agrupa2  */
#line 182 "parser.y"
                         {    contador2=0; }
#line 1488 "parser.tab.c"
    break;

  case 55: /* agrupa1: TK_PAB  */
#line 185 "parser.y"
           {parisopen++;}
#line 1494 "parser.tab.c"
    break;

  case 56: /* agrupa2: TK_PCE  */
#line 188 "parser.y"
           {parisopen--;}
#line 1500 "parser.tab.c"
    break;

  case 57: /* ciclofor: encabezado_for bloque_begin_end  */
#line 193 "parser.y"
                                    {
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);
    }
#line 1508 "parser.tab.c"
    break;

  case 58: /* $@1: %empty  */
#line 199 "parser.y"
                                   { iniciofor = linea_actual; foropen++;}
#line 1514 "parser.tab.c"
    break;

  case 61: /* dowhile: bloque1dw bloque2dw bloque3dw  */
#line 210 "parser.y"
                              { {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, finwhile);}}
#line 1520 "parser.tab.c"
    break;

  case 62: /* $@2: %empty  */
#line 214 "parser.y"
   {whileopen++; iniciowhile=linea_actual;}
#line 1526 "parser.tab.c"
    break;

  case 65: /* bloque3dw: while condicion  */
#line 222 "parser.y"
                 {finwhile=linea_actual; whileopen--;}
#line 1532 "parser.tab.c"
    break;

  case 66: /* cicloif: if_encabezado bloque_begin_end if_ramas  */
#line 226 "parser.y"
                                            {
        ifopen--;
        printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", yyvsp[-2], finif);
    }
#line 1541 "parser.tab.c"
    break;

  case 67: /* if_encabezado: if condicion then opt_nl  */
#line 233 "parser.y"
                             { yyval = yyvsp[-3]; ifopen++; }
#line 1547 "parser.tab.c"
    break;

  case 72: /* instrucciones: definicion  */
#line 249 "parser.y"
           { contador = 0; }
#line 1553 "parser.tab.c"
    break;

  case 73: /* instrucciones: lectura  */
#line 250 "parser.y"
          {contador=0;}
#line 1559 "parser.tab.c"
    break;

  case 74: /* instrucciones: impresion  */
#line 251 "parser.y"
           {contador=0;}
#line 1565 "parser.tab.c"
    break;

  case 82: /* bloque_begin_end: begin opt_nl cuerpo_instrucciones end opt_nl  */
#line 266 "parser.y"
                                                 { finif = linea_actual; finfor=linea_actual; foropen=0; whileopen=0; ifopen=0;}
#line 1571 "parser.tab.c"
    break;

  case 83: /* declarar: declaracion  */
#line 272 "parser.y"
            {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual);}
#line 1577 "parser.tab.c"
    break;

  case 87: /* then: TK_THEN  */
#line 287 "parser.y"
        {thenopen=1;}
#line 1583 "parser.tab.c"
    break;

  case 89: /* if: TK_IF  */
#line 293 "parser.y"
      { yyval = linea_actual; }
#line 1589 "parser.tab.c"
    break;

  case 90: /* else: TK_ELSE  */
#line 296 "parser.y"
            {thenopen=1;}
#line 1595 "parser.tab.c"
    break;

  case 96: /* end: TK_END  */
#line 314 "parser.y"
        {thenopen=0;}
#line 1601 "parser.tab.c"
    break;


#line 1605 "parser.tab.c"

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

#line 483 "parser.y"


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
