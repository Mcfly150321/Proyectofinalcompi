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
  YYSYMBOL_NEWLINE = 36,                   /* NEWLINE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_inicio3 = 38,                   /* inicio3  */
  YYSYMBOL_inicio2 = 39,                   /* inicio2  */
  YYSYMBOL_opt_newline = 40,               /* opt_newline  */
  YYSYMBOL_inicio = 41,                    /* inicio  */
  YYSYMBOL_operacion = 42,                 /* operacion  */
  YYSYMBOL_lectura = 43,                   /* lectura  */
  YYSYMBOL_leer = 44,                      /* leer  */
  YYSYMBOL_impresion = 45,                 /* impresion  */
  YYSYMBOL_imprimir = 46,                  /* imprimir  */
  YYSYMBOL_output = 47,                    /* output  */
  YYSYMBOL_input = 48,                     /* input  */
  YYSYMBOL_expresion = 49,                 /* expresion  */
  YYSYMBOL_aritmetica = 50,                /* aritmetica  */
  YYSYMBOL_otraaritmetica = 51,            /* otraaritmetica  */
  YYSYMBOL_simarit = 52,                   /* simarit  */
  YYSYMBOL_logica = 53,                    /* logica  */
  YYSYMBOL_otralogica = 54,                /* otralogica  */
  YYSYMBOL_conectorlogico = 55,            /* conectorlogico  */
  YYSYMBOL_simlog = 56,                    /* simlog  */
  YYSYMBOL_definir2 = 57,                  /* definir2  */
  YYSYMBOL_definicion = 58,                /* definicion  */
  YYSYMBOL_condicionar = 59,               /* condicionar  */
  YYSYMBOL_condicion = 60,                 /* condicion  */
  YYSYMBOL_agrupa1 = 61,                   /* agrupa1  */
  YYSYMBOL_agrupa2 = 62,                   /* agrupa2  */
  YYSYMBOL_ciclofor = 63,                  /* ciclofor  */
  YYSYMBOL_encabezado_for = 64,            /* encabezado_for  */
  YYSYMBOL_variablefor = 65,               /* variablefor  */
  YYSYMBOL_dowhile = 66,                   /* dowhile  */
  YYSYMBOL_bloque1dw = 67,                 /* bloque1dw  */
  YYSYMBOL_bloque2dw = 68,                 /* bloque2dw  */
  YYSYMBOL_bloque3dw = 69,                 /* bloque3dw  */
  YYSYMBOL_cicloif = 70,                   /* cicloif  */
  YYSYMBOL_if_encabezado = 71,             /* if_encabezado  */
  YYSYMBOL_cuerpo_instrucciones = 72,      /* cuerpo_instrucciones  */
  YYSYMBOL_if_ramas = 73,                  /* if_ramas  */
  YYSYMBOL_instrucciones = 74,             /* instrucciones  */
  YYSYMBOL_masinstrucciones = 75,          /* masinstrucciones  */
  YYSYMBOL_bloque_begin_end = 76,          /* bloque_begin_end  */
  YYSYMBOL_declarar = 77,                  /* declarar  */
  YYSYMBOL_declaracion = 78,               /* declaracion  */
  YYSYMBOL_lista_ids = 79,                 /* lista_ids  */
  YYSYMBOL_then = 80,                      /* then  */
  YYSYMBOL_begin = 81,                     /* begin  */
  YYSYMBOL_if = 82,                        /* if  */
  YYSYMBOL_else = 83,                      /* else  */
  YYSYMBOL_dospuntos = 84,                 /* dospuntos  */
  YYSYMBOL_eos = 85,                       /* eos  */
  YYSYMBOL_for = 86,                       /* for  */
  YYSYMBOL_do = 87,                        /* do  */
  YYSYMBOL_to = 88,                        /* to  */
  YYSYMBOL_end = 89,                       /* end  */
  YYSYMBOL_variable = 90,                  /* variable  */
  YYSYMBOL_numero = 91,                    /* numero  */
  YYSYMBOL_sumar = 92,                     /* sumar  */
  YYSYMBOL_restar = 93,                    /* restar  */
  YYSYMBOL_multiplicar = 94,               /* multiplicar  */
  YYSYMBOL_dividir = 95,                   /* dividir  */
  YYSYMBOL_potenciar = 96,                 /* potenciar  */
  YYSYMBOL_definir = 97,                   /* definir  */
  YYSYMBOL_operador = 98,                  /* operador  */
  YYSYMBOL_allocate = 99,                  /* allocate  */
  YYSYMBOL_while = 100                     /* while  */
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
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    60,    63,    66,    67,    70,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    88,
      90,    93,    96,    99,   102,   107,   108,   113,   116,   117,
     120,   121,   122,   123,   124,   130,   133,   134,   137,   138,
     141,   142,   143,   144,   145,   146,   152,   155,   158,   166,
     169,   172,   175,   180,   186,   190,   197,   201,   205,   209,
     213,   220,   224,   228,   229,   230,   236,   237,   238,   242,
     243,   244,   249,   255,   258,   262,   263,   270,   273,   276,
     279,   282,   285,   288,   291,   294,   297,   300,   303,   307,
     310,   313,   316,   319,   322,   325,   326,   329,   332
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
  "NEWLINE", "$accept", "inicio3", "inicio2", "opt_newline", "inicio",
  "operacion", "lectura", "leer", "impresion", "imprimir", "output",
  "input", "expresion", "aritmetica", "otraaritmetica", "simarit",
  "logica", "otralogica", "conectorlogico", "simlog", "definir2",
  "definicion", "condicionar", "condicion", "agrupa1", "agrupa2",
  "ciclofor", "encabezado_for", "variablefor", "dowhile", "bloque1dw",
  "bloque2dw", "bloque3dw", "cicloif", "if_encabezado",
  "cuerpo_instrucciones", "if_ramas", "instrucciones", "masinstrucciones",
  "bloque_begin_end", "declarar", "declaracion", "lista_ids", "then",
  "begin", "if", "else", "dospuntos", "eos", "for", "do", "to", "end",
  "variable", "numero", "sumar", "restar", "multiplicar", "dividir",
  "potenciar", "definir", "operador", "allocate", "while", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -120,    14,     3,  -120,   -24,   -10,  -120,  -120,  -120,    -9,
      -5,  -120,    -2,    12,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,    -3,  -120,     5,    35,    35,
    -120,     9,    10,  -120,    13,  -120,    15,     2,  -120,    18,
    -120,     4,  -120,    18,  -120,    21,    48,    35,    32,    73,
    -120,    49,    44,  -120,  -120,    50,    50,  -120,  -120,  -120,
    -120,    70,  -120,    62,  -120,  -120,    53,  -120,  -120,  -120,
      64,  -120,    77,    71,  -120,    74,    69,    77,  -120,  -120,
    -120,    80,    35,     2,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,     2,     2,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,     4,  -120,  -120,
      48,    -1,  -120,  -120,   -19,  -120,    68,  -120,     2,     2,
    -120,    50,    83,  -120,    50,    81,    81,     0,    75,  -120,
      72,  -120,  -120,    18,    48,  -120,    76,  -120,  -120,  -120,
    -120,    50,     2,  -120,  -120,  -120,     2,  -120,    78,    -1,
    -120,  -120,    74,    79,  -120,    81,    62,  -120,    82,  -120,
    -120,     2,    18,     0,    71,  -120,  -120
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     6,     2,     4,     0,
       0,     8,     0,     7,     5,    88,    87,    51,    24,    23,
      79,    83,    84,    15,    17,     0,    18,     0,     0,     0,
       9,     0,     0,    10,     0,    12,     0,     0,    11,     0,
      14,     0,    16,     0,    13,     0,     0,     0,     0,    95,
      96,     0,     3,    19,    21,     0,     0,    26,    25,    46,
      49,     0,    95,     0,    78,    53,     0,    67,    68,    66,
       0,    69,     0,    63,    73,     0,     0,     0,    57,    94,
      81,     0,     0,     0,    89,    90,    92,    91,    93,    40,
      41,    42,    43,    44,    45,     0,     0,    30,    31,    32,
      33,    34,    82,    22,    20,    52,    50,     0,    98,    56,
       0,    58,    80,    60,     0,    77,     0,    85,     0,     0,
      97,     0,    75,    48,    96,     0,    28,    36,     0,    69,
       0,    71,    70,     0,     0,    61,     0,    55,    74,    76,
      47,     0,     0,    38,    39,    35,     0,    86,     0,    62,
      59,    65,     0,     0,    27,    28,     0,    72,     0,    54,
      29,     0,     0,    36,    63,    37,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -120,  -120,  -120,    97,  -120,  -120,    99,  -120,   100,  -120,
    -120,  -120,  -120,    33,   -38,  -119,    85,   -44,  -120,   -33,
    -120,   107,  -120,   -43,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,   -40,   -35,     1,   -41,
    -120,  -120,     6,   -26,  -120,    17,  -120,  -120,   -51,  -120,
      -7,  -120,  -120,   -13,    51,  -120,  -120,  -120,  -120,  -120,
      55,   -36,  -120,  -120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     2,    12,    13,    67,    25,    68,    27,
      28,    29,    30,    31,   141,    95,    32,   145,   146,    96,
      33,    69,    35,    36,    37,   106,    38,    39,    76,    40,
      41,    70,   109,    42,    43,   128,   113,   132,   111,    65,
      44,    45,    81,   116,    66,    46,   114,    82,   103,    47,
      48,   118,   148,    62,    50,    97,    98,    99,   100,   101,
      83,    51,   121,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    63,    73,    75,     4,   104,    71,   142,    16,    20,
      15,    16,     8,    16,     3,    55,    56,   133,   143,   144,
      15,    16,    17,    10,    18,    19,     9,     5,    72,    18,
      19,    11,    14,    53,    77,   131,   142,    18,    19,     6,
      20,    54,    21,    22,    16,    57,    58,   125,    23,    59,
      64,    60,    84,    85,    86,    87,    88,    74,    17,   126,
     127,    89,    90,    91,    92,    93,    94,   130,    78,   122,
     138,   102,   129,   140,    89,    90,    91,    92,    93,    94,
       6,   105,   136,   137,    84,    85,    86,    87,    88,   107,
     154,   152,   151,    79,    72,    80,   -75,    79,    72,   108,
     112,   115,   117,   120,   135,    80,   155,    22,   150,   147,
     156,    52,    24,    26,   157,   159,   123,   160,   162,   165,
      34,   164,    61,   161,   166,   163,   158,     0,   139,   153,
     149,   134,   119,     0,   124,     0,    72
};

static const yytype_int16 yycheck[] =
{
      13,    37,    43,    46,     1,    56,    41,   126,     9,    28,
       8,     9,    36,     9,     0,    28,    29,    36,    18,    19,
       8,     9,    10,    32,    25,    26,    36,    24,    41,    25,
      26,    36,    34,    36,    47,    36,   155,    25,    26,    36,
      28,    36,    30,    31,     9,    36,    36,    83,    36,    36,
      32,    36,     3,     4,     5,     6,     7,    36,    10,    95,
      96,    12,    13,    14,    15,    16,    17,   110,    36,    82,
     121,    21,   107,   124,    12,    13,    14,    15,    16,    17,
      36,    11,   118,   119,     3,     4,     5,     6,     7,    36,
     141,   134,   133,    20,   107,    22,    23,    20,   111,    35,
      29,    27,    33,    23,    36,    22,   142,    31,    36,    34,
     146,    14,    13,    13,    36,    36,    83,   155,    36,   163,
      13,   162,    37,   156,   164,   161,   152,    -1,   122,   136,
     129,   114,    77,    -1,    83,    -1,   149
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    40,     0,     1,    24,    36,    39,    36,    36,
      32,    36,    41,    42,    34,     8,     9,    10,    25,    26,
      28,    30,    31,    36,    43,    44,    45,    46,    47,    48,
      49,    50,    53,    57,    58,    59,    60,    61,    63,    64,
      66,    67,    70,    71,    77,    78,    82,    86,    87,    90,
      91,    98,    40,    36,    36,    90,    90,    36,    36,    36,
      36,    53,    90,    98,    32,    76,    81,    43,    45,    58,
      68,    74,    90,    76,    36,    60,    65,    90,    36,    20,
      22,    79,    84,    97,     3,     4,     5,     6,     7,    12,
      13,    14,    15,    16,    17,    52,    56,    92,    93,    94,
      95,    96,    21,    85,    85,    11,    62,    36,    35,    69,
     100,    75,    29,    73,    83,    27,    80,    33,    88,    97,
      23,    99,    90,    50,    91,    98,    98,    98,    72,    74,
      60,    36,    74,    36,    82,    36,    98,    98,    85,    79,
      85,    51,    52,    18,    19,    54,    55,    34,    89,    75,
      36,    76,    60,    87,    85,    98,    98,    36,    80,    36,
      51,    56,    36,    98,    76,    54,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    43,
      44,    45,    46,    47,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    58,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    76,    77,    78,    79,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    98,    99,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     7,     2,     0,     2,     1,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     2,     3,     1,     1,     2,     2,     5,     0,     3,
       1,     1,     1,     1,     1,     4,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     3,     2,
       3,     1,     1,     2,     6,     3,     3,     2,     2,     3,
       3,     4,     2,     0,     7,     3,     1,     1,     1,     0,
       2,     2,     5,     2,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 60 "parser.y"
                                                               {
        printf("\nBloque valido codigo completo\n");
    }
#line 1321 "parser.tab.c"
    break;

  case 4: /* inicio2: error NEWLINE  */
#line 63 "parser.y"
                  { parisopen = 0; contador = 0; contador2 = 0; whileopen=0; ifopen=0; foropen=0; thenopen=0; printf(" CADENA INVÁLIDA\n"); yyerrok; }
#line 1327 "parser.tab.c"
    break;

  case 19: /* lectura: leer NEWLINE  */
#line 88 "parser.y"
             {imprimir_in();}
#line 1333 "parser.tab.c"
    break;

  case 21: /* impresion: imprimir NEWLINE  */
#line 93 "parser.y"
                {imprimir_out();}
#line 1339 "parser.tab.c"
    break;

  case 25: /* expresion: logica NEWLINE  */
#line 107 "parser.y"
                       { imprimir_logica(); }
#line 1345 "parser.tab.c"
    break;

  case 26: /* expresion: aritmetica NEWLINE  */
#line 108 "parser.y"
                       { imprimir_aritmetica(); }
#line 1351 "parser.tab.c"
    break;

  case 29: /* otraaritmetica: simarit operador otraaritmetica  */
#line 117 "parser.y"
                                  {contador++; /*esto apra incrementar el contador de simbolos en la operacion */}
#line 1357 "parser.tab.c"
    break;

  case 30: /* simarit: sumar  */
#line 120 "parser.y"
      {strcpy(tipoaritmetica, "SUMA");}
#line 1363 "parser.tab.c"
    break;

  case 31: /* simarit: restar  */
#line 121 "parser.y"
        {strcpy(tipoaritmetica, "RESTA");}
#line 1369 "parser.tab.c"
    break;

  case 32: /* simarit: multiplicar  */
#line 122 "parser.y"
             {strcpy(tipoaritmetica, "MULTIPLICACION");}
#line 1375 "parser.tab.c"
    break;

  case 33: /* simarit: dividir  */
#line 123 "parser.y"
         {strcpy(tipoaritmetica, "DIVISION");}
#line 1381 "parser.tab.c"
    break;

  case 34: /* simarit: potenciar  */
#line 124 "parser.y"
           {strcpy(tipoaritmetica, "POTENCIACION");}
#line 1387 "parser.tab.c"
    break;

  case 37: /* otralogica: conectorlogico operador simlog operador otralogica  */
#line 134 "parser.y"
                                                     {contador2++;}
#line 1393 "parser.tab.c"
    break;

  case 40: /* simlog: TK_MAY  */
#line 141 "parser.y"
           {strcpy(tipologica, "MAYOR QUE");}
#line 1399 "parser.tab.c"
    break;

  case 41: /* simlog: TK_MEN  */
#line 142 "parser.y"
           {strcpy(tipologica, "MENOR QUE");}
#line 1405 "parser.tab.c"
    break;

  case 42: /* simlog: TK_MAIG  */
#line 143 "parser.y"
            {strcpy(tipologica, "MAYOR O IGUAL");}
#line 1411 "parser.tab.c"
    break;

  case 43: /* simlog: TK_MEIG  */
#line 144 "parser.y"
            {strcpy(tipologica, "MENOR O IGUAL");;}
#line 1417 "parser.tab.c"
    break;

  case 44: /* simlog: TK_IG  */
#line 145 "parser.y"
          {strcpy(tipologica, "IGUAL");}
#line 1423 "parser.tab.c"
    break;

  case 45: /* simlog: TK_NIG  */
#line 146 "parser.y"
           {strcpy(tipologica, "DISTINTO");}
#line 1429 "parser.tab.c"
    break;

  case 47: /* definicion: variable definir numero eos  */
#line 155 "parser.y"
                               {
      imprimir_defnum();/*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1437 "parser.tab.c"
    break;

  case 48: /* definicion: variable definir aritmetica  */
#line 158 "parser.y"
                                 {
     imprimir_defop(); /*voy a quytar el contador de definciones porqe no me esta sirviendo */
    }
#line 1445 "parser.tab.c"
    break;

  case 49: /* condicionar: condicion NEWLINE  */
#line 166 "parser.y"
                   {imprimir_condicion();}
#line 1451 "parser.tab.c"
    break;

  case 50: /* condicion: agrupa1 logica agrupa2  */
#line 169 "parser.y"
                         {    contador2=0; }
#line 1457 "parser.tab.c"
    break;

  case 51: /* agrupa1: TK_PAB  */
#line 172 "parser.y"
           {parisopen++;}
#line 1463 "parser.tab.c"
    break;

  case 52: /* agrupa2: TK_PCE  */
#line 175 "parser.y"
           {parisopen--;}
#line 1469 "parser.tab.c"
    break;

  case 53: /* ciclofor: encabezado_for bloque_begin_end  */
#line 180 "parser.y"
                                    {
        printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO FOR\n", iniciofor, finfor);
    }
#line 1477 "parser.tab.c"
    break;

  case 54: /* encabezado_for: for variablefor to operador do NEWLINE  */
#line 186 "parser.y"
                                           { iniciofor = linea_actual - 1; foropen++;}
#line 1483 "parser.tab.c"
    break;

  case 56: /* dowhile: bloque1dw bloque2dw bloque3dw  */
#line 197 "parser.y"
                              { {printf(" -> LINEAS %d-%d : CADENA VÁLIDA: CICLO DOWHILE\n", iniciowhile, finwhile);}}
#line 1489 "parser.tab.c"
    break;

  case 57: /* bloque1dw: do NEWLINE  */
#line 201 "parser.y"
           {whileopen++; iniciowhile=linea_actual-1;}
#line 1495 "parser.tab.c"
    break;

  case 59: /* bloque3dw: while condicion NEWLINE  */
#line 209 "parser.y"
                         {finwhile=linea_actual-1; whileopen--;}
#line 1501 "parser.tab.c"
    break;

  case 60: /* cicloif: if_encabezado bloque_begin_end if_ramas  */
#line 213 "parser.y"
                                            {
        ifopen--;
        printf("-> LINEAS %d-%d: CADENA VALIDA: CICLO IF\n", inicioif, finif);
    }
#line 1510 "parser.tab.c"
    break;

  case 61: /* if_encabezado: if condicion then NEWLINE  */
#line 220 "parser.y"
                              { inicioif = linea_actual - 1; ifopen++; }
#line 1516 "parser.tab.c"
    break;

  case 66: /* instrucciones: definicion  */
#line 236 "parser.y"
           { contador = 0; }
#line 1522 "parser.tab.c"
    break;

  case 67: /* instrucciones: lectura  */
#line 237 "parser.y"
          {contador=0;}
#line 1528 "parser.tab.c"
    break;

  case 68: /* instrucciones: impresion  */
#line 238 "parser.y"
           {contador=0;}
#line 1534 "parser.tab.c"
    break;

  case 72: /* bloque_begin_end: begin NEWLINE cuerpo_instrucciones end NEWLINE  */
#line 249 "parser.y"
                                                   { finif = linea_actual - 1; finfor=linea_actual-1; foropen=0; whileopen=0; ifopen=0;}
#line 1540 "parser.tab.c"
    break;

  case 73: /* declarar: declaracion NEWLINE  */
#line 255 "parser.y"
                      {printf(" -> LINEA %d: CADENA VÁLIDA: DECLARACIÓN\n", linea_actual - 1);}
#line 1546 "parser.tab.c"
    break;

  case 77: /* then: TK_THEN  */
#line 270 "parser.y"
        {thenopen=1;}
#line 1552 "parser.tab.c"
    break;

  case 80: /* else: TK_ELSE  */
#line 279 "parser.y"
        {thenopen=1;}
#line 1558 "parser.tab.c"
    break;

  case 86: /* end: TK_END  */
#line 297 "parser.y"
        {thenopen=0;}
#line 1564 "parser.tab.c"
    break;


#line 1568 "parser.tab.c"

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

#line 461 "parser.y"


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
   printf(" -> LINEA %d: CADENA VÁLIDA: DEFINICIÓN DE VARIABLE A NUMERO\n", linea_actual);
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
