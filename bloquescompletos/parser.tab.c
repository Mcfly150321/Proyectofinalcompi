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
#line 15 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int yylex(void);
void yyerror(const char *s);

/* Salida del Código de Tres Direcciones */
FILE *archivo_tdc = NULL;

void emitir(const char *formato, ...) {
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);

    if (archivo_tdc) {
        va_start(args, formato);
        vfprintf(archivo_tdc, formato, args);
        va_end(args);
    }
}

int num_temp = 1;
char* nuevo_temp(void) {
    char buf[32];
    sprintf(buf, "t%d", num_temp++);
    return strdup(buf);
}

int num_label = 1;
char* nueva_label(void) {
    char buf[32];
    sprintf(buf, "l%d", num_label++);
    return strdup(buf);
}

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
  YYSYMBOL_TK_MAY = 10,                    /* TK_MAY  */
  YYSYMBOL_TK_MEN = 11,                    /* TK_MEN  */
  YYSYMBOL_TK_MAIG = 12,                   /* TK_MAIG  */
  YYSYMBOL_TK_MEIG = 13,                   /* TK_MEIG  */
  YYSYMBOL_TK_IG = 14,                     /* TK_IG  */
  YYSYMBOL_TK_NIG = 15,                    /* TK_NIG  */
  YYSYMBOL_TK_PAB = 16,                    /* TK_PAB  */
  YYSYMBOL_TK_PCE = 17,                    /* TK_PCE  */
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
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_opt_inicio = 43,                /* opt_inicio  */
  YYSYMBOL_opt_nl = 44,                    /* opt_nl  */
  YYSYMBOL_cuerpo = 45,                    /* cuerpo  */
  YYSYMBOL_operacion = 46,                 /* operacion  */
  YYSYMBOL_comentario = 47,                /* comentario  */
  YYSYMBOL_lectura = 48,                   /* lectura  */
  YYSYMBOL_leer = 49,                      /* leer  */
  YYSYMBOL_impresion = 50,                 /* impresion  */
  YYSYMBOL_imprimir = 51,                  /* imprimir  */
  YYSYMBOL_output = 52,                    /* output  */
  YYSYMBOL_input = 53,                     /* input  */
  YYSYMBOL_expresion = 54,                 /* expresion  */
  YYSYMBOL_aritmetica = 55,                /* aritmetica  */
  YYSYMBOL_oparit = 56,                    /* oparit  */
  YYSYMBOL_simarit = 57,                   /* simarit  */
  YYSYMBOL_logica = 58,                    /* logica  */
  YYSYMBOL_simlog = 59,                    /* simlog  */
  YYSYMBOL_definicion = 60,                /* definicion  */
  YYSYMBOL_condicionar = 61,               /* condicionar  */
  YYSYMBOL_condicion = 62,                 /* condicion  */
  YYSYMBOL_agrupa1 = 63,                   /* agrupa1  */
  YYSYMBOL_agrupa2 = 64,                   /* agrupa2  */
  YYSYMBOL_ciclofor = 65,                  /* ciclofor  */
  YYSYMBOL_encabezado_for = 66,            /* encabezado_for  */
  YYSYMBOL_dowhile = 67,                   /* dowhile  */
  YYSYMBOL_bloque1dw = 68,                 /* bloque1dw  */
  YYSYMBOL_bloque2dw = 69,                 /* bloque2dw  */
  YYSYMBOL_cicloif = 70,                   /* cicloif  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_if_encabezado = 72,             /* if_encabezado  */
  YYSYMBOL_cuerpo_instrucciones = 73,      /* cuerpo_instrucciones  */
  YYSYMBOL_if_ramas = 74,                  /* if_ramas  */
  YYSYMBOL_instrucciones = 75,             /* instrucciones  */
  YYSYMBOL_masinstrucciones = 76,          /* masinstrucciones  */
  YYSYMBOL_bloque_begin_end = 77,          /* bloque_begin_end  */
  YYSYMBOL_declarar = 78,                  /* declarar  */
  YYSYMBOL_declaracion = 79,               /* declaracion  */
  YYSYMBOL_lista_ids = 80,                 /* lista_ids  */
  YYSYMBOL_then = 81,                      /* then  */
  YYSYMBOL_begin = 82,                     /* begin  */
  YYSYMBOL_if = 83,                        /* if  */
  YYSYMBOL_else = 84,                      /* else  */
  YYSYMBOL_dospuntos = 85,                 /* dospuntos  */
  YYSYMBOL_eos = 86,                       /* eos  */
  YYSYMBOL_for = 87,                       /* for  */
  YYSYMBOL_do = 88,                        /* do  */
  YYSYMBOL_to = 89,                        /* to  */
  YYSYMBOL_end = 90,                       /* end  */
  YYSYMBOL_variable = 91,                  /* variable  */
  YYSYMBOL_numero = 92,                    /* numero  */
  YYSYMBOL_sumar = 93,                     /* sumar  */
  YYSYMBOL_restar = 94,                    /* restar  */
  YYSYMBOL_multiplicar = 95,               /* multiplicar  */
  YYSYMBOL_dividir = 96,                   /* dividir  */
  YYSYMBOL_potenciar = 97,                 /* potenciar  */
  YYSYMBOL_definir = 98,                   /* definir  */
  YYSYMBOL_operador = 99,                  /* operador  */
  YYSYMBOL_factores = 100,                 /* factores  */
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
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

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
       0,    88,    88,    92,    92,    98,    99,   100,   104,   105,
     109,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   128,   132,   136,   143,   147,   154,   158,
     162,   163,   167,   171,   176,   182,   183,   184,   185,   186,
     190,   195,   202,   212,   213,   214,   215,   216,   217,   221,
     227,   231,   237,   241,   246,   256,   275,   281,   289,   294,
     294,   303,   313,   317,   318,   322,   323,   324,   325,   326,
     327,   328,   332,   333,   334,   338,   342,   346,   350,   351,
     355,   359,   363,   367,   371,   375,   379,   383,   387,   391,
     395,   399,   403,   407,   411,   415,   419,   423,   427,   428,
     432,   433,   434,   442,   446
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
  "TK_ID", "TK_MAY", "TK_MEN", "TK_MAIG", "TK_MEIG", "TK_IG", "TK_NIG",
  "TK_PAB", "TK_PCE", "TK_AND", "TK_OR", "TK_ASIG", "TK_EOS", "TK_DP",
  "TK_ALLOCATE", "TK_MAIN", "TK_INPUT", "TK_OUTPUT", "TK_THEN", "TK_IF",
  "TK_ELSE", "TK_FOR", "TK_DO", "TK_BEGIN", "TK_TO", "TK_END", "TK_WHILE",
  "TK_COMENTARIO", "NEWLINE", "REDUCE_NO_ELSE", "$accept", "programa",
  "bloque", "$@1", "opt_inicio", "opt_nl", "cuerpo", "operacion",
  "comentario", "lectura", "leer", "impresion", "imprimir", "output",
  "input", "expresion", "aritmetica", "oparit", "simarit", "logica",
  "simlog", "definicion", "condicionar", "condicion", "agrupa1", "agrupa2",
  "ciclofor", "encabezado_for", "dowhile", "bloque1dw", "bloque2dw",
  "cicloif", "$@2", "if_encabezado", "cuerpo_instrucciones", "if_ramas",
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

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -88,    10,    11,   -88,   -88,   -88,   -88,   -88,   -88,    60,
     -88,   -88,   -11,    90,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
      25,    25,   -88,     2,    66,    -5,   -88,   -88,    18,    58,
     -88,    29,   -88,   104,   -88,    29,   -88,   -88,    44,    25,
     -88,    80,   -88,    55,   137,   -88,   -28,    57,    57,   -88,
     -88,   -88,   -88,   -88,   -88,    58,   -88,   -88,   -88,   -88,
     -88,   -88,    58,    58,   -88,   -88,   139,   105,    58,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    45,
     -88,   -88,    61,   -88,    59,    58,    61,    53,   -88,   -88,
      72,    25,    58,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
      58,   -88,   -88,   -88,   137,   137,   -88,   -88,   -88,   -88,
      15,   -88,    44,    28,    76,   -88,   -88,   137,    58,   -88,
     -88,    57,    86,    66,   -88,    58,    58,    75,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    53,    81,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,    28,    -6,   -88,    58,    53,   -88,
      88,   -88,    53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     5,    23,     6,     2,     7,     0,
       3,    11,     0,    10,     5,    93,    91,    90,    52,    29,
      28,    82,    86,    87,    18,    22,    20,    24,    21,    26,
       0,     0,    12,     0,     0,     0,    13,    15,     0,     0,
      14,     0,    17,     0,    19,     0,    16,    76,     0,     0,
       8,   100,   101,     0,    34,    98,     4,     0,     0,    31,
      92,    95,    94,    96,    85,     0,    32,    35,    36,    37,
      38,    39,     0,     0,    30,    50,     0,     0,     0,   100,
      81,    54,     8,    71,    66,    67,    65,    69,    70,     0,
      68,    72,     0,    59,     0,     0,     0,    57,    97,    84,
       0,     0,     0,   102,    43,    44,    45,    46,    47,    48,
       0,    27,    25,    33,     0,     0,    53,    99,    51,    34,
       0,   104,     0,    58,    63,    80,     8,     0,     0,     9,
     103,     0,    78,     0,    40,     0,     0,     0,    72,    56,
      74,    73,    83,    60,     8,    61,     0,    77,    79,    49,
      41,    42,    89,     8,    62,     0,    88,     0,    75,    64,
       0,     8,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,   -88,     7,   -76,   -88,   -88,    20,   112,
     -88,   115,   -88,   -88,   -88,   -88,   -88,    -9,   -88,   118,
     -87,   120,   -88,   -43,   -10,    40,   123,   -88,   124,   -88,
     -88,   125,   -88,   -88,   -88,   -88,   -36,     1,   -44,   -88,
     -88,    21,   -88,   -88,   -88,   -88,   -88,   -42,   -88,    -3,
     -88,   -88,   -13,   101,   -88,   -32,   -88,   -88,   -88,    62,
     -53,   -88,   -88,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,    11,     2,    97,    12,    13,    83,    84,
      27,    85,    29,    30,    31,    32,    33,    76,    65,    77,
     110,    86,    37,    38,    78,   117,    87,    41,    88,    43,
      89,    90,   124,    45,   137,   143,   141,   123,    81,    46,
      47,   100,   126,    82,    48,   144,   101,    66,    49,    50,
     157,   153,    79,    52,    67,    53,    69,    70,    71,   102,
      54,    55,   131,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    93,    68,    39,    34,    94,   120,    91,     5,     6,
       3,     9,   113,    72,    73,   111,   112,    57,    58,   114,
     115,    56,     8,    14,    17,   119,    80,   135,   136,     8,
      92,   129,    74,    25,    17,     4,    96,    17,    95,    59,
      19,    20,   127,    21,    68,    22,    23,     5,     6,   119,
     145,     5,   129,    19,    20,    75,    21,   134,    22,    23,
      18,    80,    15,    16,     5,   140,    16,    17,   155,    60,
      15,    61,    62,    63,    18,   146,     8,   158,    64,   139,
     121,    98,   150,   151,   138,   162,   125,    64,   132,   147,
     129,   149,    10,   133,    15,   130,     5,     6,    16,    17,
      98,    68,    99,   -78,   160,   142,    18,    92,    99,   152,
      92,   159,    95,    17,   156,    19,    20,   118,    21,    23,
      22,    23,   116,    72,    73,    26,     5,    24,    28,    19,
      20,    35,    21,    36,    22,    23,    40,    42,    44,   154,
       5,    92,    60,    15,    61,    62,    63,   104,   105,   106,
     107,   108,   109,   148,   103,     0,   116,   161,   128
};

static const yytype_int16 yycheck[] =
{
      13,    45,    34,    13,    13,    48,    82,    43,    36,    37,
       0,     4,    65,    18,    19,    57,    58,    30,    31,    72,
      73,    14,     2,    34,     9,    78,    32,   114,   115,     9,
      43,    37,    37,    13,     9,    24,    49,     9,    48,    37,
      25,    26,    95,    28,    76,    30,    31,    36,    37,   102,
     126,    36,    37,    25,    26,    37,    28,   110,    30,    31,
      16,    32,     4,     8,    36,    37,     8,     9,   144,     3,
       4,     5,     6,     7,    16,   128,    56,   153,    21,   122,
      35,    20,   135,   136,   120,   161,    27,    21,   101,   131,
      37,   133,    32,   102,     4,    23,    36,    37,     8,     9,
      20,   133,    22,    23,   157,    29,    16,   120,    22,    34,
     123,   155,   122,     9,    33,    25,    26,    77,    28,    31,
      30,    31,    17,    18,    19,    13,    36,    37,    13,    25,
      26,    13,    28,    13,    30,    31,    13,    13,    13,   138,
      36,   154,     3,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,   132,    53,    -1,    17,   160,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    43,     0,    24,    36,    37,    41,    47,    43,
      32,    42,    45,    46,    34,     4,     8,     9,    16,    25,
      26,    28,    30,    31,    37,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    58,    60,    61,    62,    63,
      65,    66,    67,    68,    70,    72,    78,    79,    83,    87,
      88,    91,    92,    94,    99,   100,    43,    91,    91,    37,
       3,     5,     6,     7,    21,    57,    86,    93,    94,    95,
      96,    97,    18,    19,    37,    37,    56,    58,    63,    91,
      32,    77,    82,    47,    48,    50,    60,    65,    67,    69,
      70,    75,    91,    77,    62,    63,    91,    44,    20,    22,
      80,    85,    98,    92,    10,    11,    12,    13,    14,    15,
      59,    86,    86,    99,    99,    99,    17,    64,    64,    99,
      44,    35,   102,    76,    71,    27,    81,    99,    98,    37,
      23,   101,    91,    56,    99,    59,    59,    73,    75,    62,
      37,    75,    29,    74,    84,    44,    99,    86,    80,    86,
      99,    99,    34,    90,    76,    44,    33,    89,    44,    77,
      99,    88,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    42,    41,    43,    43,    43,    44,    44,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    71,
      70,    72,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    77,    78,    79,    80,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    99,
     100,   100,   100,   101,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     7,     0,     2,     2,     0,     2,
       1,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     3,     1,     3,     1,     1,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     5,     5,     1,     1,     1,     1,     1,     1,     4,
       2,     3,     1,     1,     2,     8,     4,     2,     2,     0,
       4,     4,     2,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     2,     5,     1,     4,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     2,     1,     1
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
  case 3: /* $@1: %empty  */
#line 92 "parser.y"
                                {
        emitir("main:\n");
    }
#line 1330 "parser.tab.c"
    break;

  case 25: /* leer: input variable eos  */
#line 136 "parser.y"
                       {
        emitir("        call input;\n");
        emitir("        pop %s;\n", (yyvsp[-1].str));
    }
#line 1339 "parser.tab.c"
    break;

  case 27: /* imprimir: output variable eos  */
#line 147 "parser.y"
                        {
        emitir("        push %s;\n", (yyvsp[-1].str));
        emitir("        call output;\n");
    }
#line 1348 "parser.tab.c"
    break;

  case 33: /* oparit: oparit simarit operador  */
#line 171 "parser.y"
                            {
        char *t = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t, (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
        (yyval.str) = t;
    }
#line 1358 "parser.tab.c"
    break;

  case 34: /* oparit: operador  */
#line 176 "parser.y"
             {
        (yyval.str) = (yyvsp[0].str);
    }
#line 1366 "parser.tab.c"
    break;

  case 35: /* simarit: sumar  */
#line 182 "parser.y"
                  { (yyval.str) = "+"; }
#line 1372 "parser.tab.c"
    break;

  case 36: /* simarit: restar  */
#line 183 "parser.y"
                  { (yyval.str) = "-"; }
#line 1378 "parser.tab.c"
    break;

  case 37: /* simarit: multiplicar  */
#line 184 "parser.y"
                  { (yyval.str) = "*"; }
#line 1384 "parser.tab.c"
    break;

  case 38: /* simarit: dividir  */
#line 185 "parser.y"
                  { (yyval.str) = "/"; }
#line 1390 "parser.tab.c"
    break;

  case 39: /* simarit: potenciar  */
#line 186 "parser.y"
                  { (yyval.str) = "**"; }
#line 1396 "parser.tab.c"
    break;

  case 40: /* logica: operador simlog operador  */
#line 190 "parser.y"
                             {
        char *t = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t, (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
        (yyval.str) = t;
    }
#line 1406 "parser.tab.c"
    break;

  case 41: /* logica: logica TK_AND operador simlog operador  */
#line 195 "parser.y"
                                           {
        char *t_rel = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t_rel, (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
        char *t_and = nuevo_temp();
        emitir("        %s=%s&&%s;\n", t_and, (yyvsp[-4].str), t_rel);
        (yyval.str) = t_and;
    }
#line 1418 "parser.tab.c"
    break;

  case 42: /* logica: logica TK_OR operador simlog operador  */
#line 202 "parser.y"
                                          {
        char *t_rel = nuevo_temp();
        emitir("        %s=%s%s%s;\n", t_rel, (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
        char *t_or = nuevo_temp();
        emitir("        %s=%s||%s;\n", t_or, (yyvsp[-4].str), t_rel);
        (yyval.str) = t_or;
    }
#line 1430 "parser.tab.c"
    break;

  case 43: /* simlog: TK_MAY  */
#line 212 "parser.y"
             { (yyval.str) = ">"; }
#line 1436 "parser.tab.c"
    break;

  case 44: /* simlog: TK_MEN  */
#line 213 "parser.y"
             { (yyval.str) = "<"; }
#line 1442 "parser.tab.c"
    break;

  case 45: /* simlog: TK_MAIG  */
#line 214 "parser.y"
             { (yyval.str) = ">="; }
#line 1448 "parser.tab.c"
    break;

  case 46: /* simlog: TK_MEIG  */
#line 215 "parser.y"
             { (yyval.str) = "<="; }
#line 1454 "parser.tab.c"
    break;

  case 47: /* simlog: TK_IG  */
#line 216 "parser.y"
             { (yyval.str) = "=="; }
#line 1460 "parser.tab.c"
    break;

  case 48: /* simlog: TK_NIG  */
#line 217 "parser.y"
             { (yyval.str) = "<>"; }
#line 1466 "parser.tab.c"
    break;

  case 49: /* definicion: variable definir oparit eos  */
#line 221 "parser.y"
                                {
        emitir("        %s=%s;\n", (yyvsp[-3].str), (yyvsp[-1].str));
    }
#line 1474 "parser.tab.c"
    break;

  case 51: /* condicion: agrupa1 logica agrupa2  */
#line 231 "parser.y"
                           {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 1482 "parser.tab.c"
    break;

  case 54: /* ciclofor: encabezado_for bloque_begin_end  */
#line 246 "parser.y"
                                    {
        char *t_inc = nuevo_temp();
        emitir("        %s=%s+1;\n", t_inc, (yyvsp[-1].for_info).var);
        emitir("        %s=%s;\n", (yyvsp[-1].for_info).var, t_inc);
        emitir("        jmp %s\n", (yyvsp[-1].for_info).l_start);
        emitir("%s:\n", (yyvsp[-1].for_info).l_end);
    }
#line 1494 "parser.tab.c"
    break;

  case 55: /* encabezado_for: for variable definir operador to operador do opt_nl  */
#line 256 "parser.y"
                                                        {
        /* $2 es var, $4 es valor inicial, $6 es límite */
        emitir("        %s=%s;\n", (yyvsp[-6].str), (yyvsp[-4].str));
        char *l_start = nueva_label();
        char *l_end = nueva_label();
        emitir("%s:\n", l_start);
        char *t_cond = nuevo_temp();
        emitir("        %s=%s<=%s;\n", t_cond, (yyvsp[-6].str), (yyvsp[-2].str));
        emitir("        ifz %s goto %s:\n", t_cond, l_end);

        (yyval.for_info).var = (yyvsp[-6].str);
        (yyval.for_info).limit = (yyvsp[-2].str);
        (yyval.for_info).l_start = l_start;
        (yyval.for_info).l_end = l_end;
    }
#line 1514 "parser.tab.c"
    break;

  case 56: /* dowhile: bloque1dw bloque2dw while condicion  */
#line 275 "parser.y"
                                        {
        emitir("        ifnz %s goto %s:\n", (yyvsp[0].str), (yyvsp[-3].str));
    }
#line 1522 "parser.tab.c"
    break;

  case 57: /* bloque1dw: do opt_nl  */
#line 281 "parser.y"
              {
        char *l_start = nueva_label();
        emitir("%s:\n", l_start);
        (yyval.str) = l_start;
    }
#line 1532 "parser.tab.c"
    break;

  case 59: /* $@2: %empty  */
#line 294 "parser.y"
                                   {
        emitir("        jmp %s\n", (yyvsp[-1].if_info).l_end);
        emitir("%s:\n", (yyvsp[-1].if_info).l_false);
    }
#line 1541 "parser.tab.c"
    break;

  case 60: /* cicloif: if_encabezado bloque_begin_end $@2 if_ramas  */
#line 297 "parser.y"
               {
        emitir("%s:\n", (yyvsp[-3].if_info).l_end);
    }
#line 1549 "parser.tab.c"
    break;

  case 61: /* if_encabezado: if condicion then opt_nl  */
#line 303 "parser.y"
                             {
        char *l_false = nueva_label();
        char *l_end = nueva_label();
        emitir("        ifz %s goto %s:\n", (yyvsp[-2].str), l_false);
        (yyval.if_info).l_false = l_false;
        (yyval.if_info).l_end = l_end;
    }
#line 1561 "parser.tab.c"
    break;

  case 90: /* variable: TK_ID  */
#line 395 "parser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1567 "parser.tab.c"
    break;

  case 91: /* numero: TK_NUMERO  */
#line 399 "parser.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1573 "parser.tab.c"
    break;

  case 98: /* operador: factores  */
#line 427 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1579 "parser.tab.c"
    break;

  case 99: /* operador: agrupa1 oparit agrupa2  */
#line 428 "parser.y"
                           { (yyval.str) = (yyvsp[-1].str); }
#line 1585 "parser.tab.c"
    break;

  case 100: /* factores: variable  */
#line 432 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1591 "parser.tab.c"
    break;

  case 101: /* factores: numero  */
#line 433 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1597 "parser.tab.c"
    break;

  case 102: /* factores: restar numero  */
#line 434 "parser.y"
                  {
        char buf[64];
        sprintf(buf, "-%s", (yyvsp[0].str));
        (yyval.str) = strdup(buf);
    }
#line 1607 "parser.tab.c"
    break;


#line 1611 "parser.tab.c"

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

#line 449 "parser.y"


void yyerror(const char *s) {
    extern int yylineno;
    extern char *yytext;

    int linea = yylineno;
    const char *texto = yytext;

    if (yytext && yytext[0] == '\n') {
        linea = yylineno - 1;
        texto = "\\n";
    }

    fprintf(stderr, " -> LINEA %i: Error en %s (%s)\n", linea, texto ? texto : "", s);
}

int main(int argc, char **argv) {
    const char *nombre_salida = "codigo_tdc.txt";
    if (argc > 1) {
        nombre_salida = argv[1];
    }

    archivo_tdc = fopen(nombre_salida, "w");
    if (!archivo_tdc) {
        fprintf(stderr, "Aviso: No se pudo abrir %s para escribir TDC.\n", nombre_salida);
    }

    yyparse();

    if (archivo_tdc) {
        fclose(archivo_tdc);
        printf("\n[TDC guardado exitosamente en: %s]\n", nombre_salida);
    }

    return 0;
}
