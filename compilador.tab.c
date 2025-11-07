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




/* First part of user prologue.  */
#line 4 "compilador.y"

#include "compilador.h"

#define DEBUG 0
#define COMMENTS 0
#define YYDEBUG 0
#define VAR(var) #var

int varCount, varTotal[STACK_SIZE], argCount, lastArgCount;
int labelCount = -1;
int lexLevel = -1;
int shift;

struct symbolTable symbolTable = {.top = -1};
struct symbolTableNode* lastSym[STACK_SIZE];
struct symbolTableNode* lastCall;
symbols symbol, relation;

char definedVars[MAX_VARS][TOKEN_SIZE+1];
char definedArgs[MAX_VARS][TOKEN_SIZE+1];
char lastSubroutine[TOKEN_SIZE+1];
char token[TOKEN_SIZE+1], lastIdent[TOKEN_SIZE+1];

char* catToStr[] = {"variable", "parameter", "procedure"};
char* typeToStr[] = {"integer", "real", "character", "boolean"};

int assignmentShift, varLexLevel;
enum category assignmentCategory;
bool assignmentRef;

enum type lElem;
struct typeStack ts1 = {.top = -1}, ts2 = {.top = -1}, ts3 = {.top = -1}, ts4 = {.top = -1};

struct labelStack ls = {.top = -1};
char nLabel[STACK_SIZE][LABEL_SIZE+1];
int lIndex = -1;

int mIndex = -1;
bool ref, minus[STACK_SIZE] = { [0 ... STACK_SIZE-1] = false};

enum type argsType[MAX_PARAM];
bool argsRef[MAX_PARAM];


#line 116 "compilador.tab.c"

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

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_PROCEDURE = 5,                  /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 6,                   /* FUNCTION  */
  YYSYMBOL_7_ = 7,                         /* '('  */
  YYSYMBOL_8_ = 8,                         /* ')'  */
  YYSYMBOL_9_ = 9,                         /* ','  */
  YYSYMBOL_10_ = 10,                       /* ':'  */
  YYSYMBOL_11_ = 11,                       /* ';'  */
  YYSYMBOL_12_ = 12,                       /* '.'  */
  YYSYMBOL_T_BEGIN = 13,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 14,                     /* T_END  */
  YYSYMBOL_READ = 15,                      /* READ  */
  YYSYMBOL_WRITE = 16,                     /* WRITE  */
  YYSYMBOL_IDENT = 17,                     /* IDENT  */
  YYSYMBOL_NUM = 18,                       /* NUM  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_ASSIGNMENT = 22,                /* ASSIGNMENT  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_DIFFERENT = 28,                 /* DIFFERENT  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_LESS_EQUAL = 31,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 32,             /* GREATER_EQUAL  */
  YYSYMBOL_33_ = 33,                       /* '&'  */
  YYSYMBOL_34_ = 34,                       /* '|'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_THEN = 39,                      /* THEN  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_main_args = 46,                 /* main_args  */
  YYSYMBOL_main_idents = 47,               /* main_idents  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_var = 49,                       /* var  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_declare_vars = 51,              /* declare_vars  */
  YYSYMBOL_declare_var = 52,               /* declare_var  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_list_id_var = 55,               /* list_id_var  */
  YYSYMBOL_sub_routines = 56,              /* sub_routines  */
  YYSYMBOL_sub_routine = 57,               /* sub_routine  */
  YYSYMBOL_procedure = 58,                 /* procedure  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_list_args = 66,                 /* list_args  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_list_idents = 68,               /* list_idents  */
  YYSYMBOL_ref = 69,                       /* ref  */
  YYSYMBOL_composite_command = 70,         /* composite_command  */
  YYSYMBOL_71_12 = 71,                     /* $@12  */
  YYSYMBOL_commands = 72,                  /* commands  */
  YYSYMBOL_who_cares = 73,                 /* who_cares  */
  YYSYMBOL_command = 74,                   /* command  */
  YYSYMBOL_assignment = 75,                /* assignment  */
  YYSYMBOL_76_13 = 76,                     /* $@13  */
  YYSYMBOL_read = 77,                      /* read  */
  YYSYMBOL_list_args_read = 78,            /* list_args_read  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_write = 80,                     /* write  */
  YYSYMBOL_list_args_write = 81,           /* list_args_write  */
  YYSYMBOL_while = 82,                     /* while  */
  YYSYMBOL_83_15 = 83,                     /* $@15  */
  YYSYMBOL_84_16 = 84,                     /* $@16  */
  YYSYMBOL_if = 85,                        /* if  */
  YYSYMBOL_if_then = 86,                   /* if_then  */
  YYSYMBOL_87_17 = 87,                     /* $@17  */
  YYSYMBOL_88_18 = 88,                     /* $@18  */
  YYSYMBOL_else = 89,                      /* else  */
  YYSYMBOL_90_19 = 90,                     /* $@19  */
  YYSYMBOL_nested_commands = 91,           /* nested_commands  */
  YYSYMBOL_procedure_call = 92,            /* procedure_call  */
  YYSYMBOL_93_20 = 93,                     /* $@20  */
  YYSYMBOL_exp_args = 94,                  /* exp_args  */
  YYSYMBOL_95_21 = 95,                     /* $@21  */
  YYSYMBOL_expression_list = 96,           /* expression_list  */
  YYSYMBOL_97_22 = 97,                     /* $@22  */
  YYSYMBOL_expression = 98,                /* expression  */
  YYSYMBOL_simple_expression = 99,         /* simple_expression  */
  YYSYMBOL_term = 100,                     /* term  */
  YYSYMBOL_factor = 101,                   /* factor  */
  YYSYMBOL_102_23 = 102,                   /* $@23  */
  YYSYMBOL_103_24 = 103,                   /* $@24  */
  YYSYMBOL_sign = 104                      /* sign  */
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
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
       2,     2,     2,    35,     2,     2,     2,     2,    33,     2,
       7,     8,    25,    23,     9,    24,    12,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    10,    11,
      29,    27,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    34,     2,     2,     2,     2,     2,
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
       5,     6,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    28,    31,    32,    36,    37,    38,    39,    40,
      41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    66,    64,    78,    79,    82,    83,    86,
      92,    92,    94,    97,    98,   101,   102,   101,   109,   110,
     113,   114,   117,   118,   121,   122,   121,   138,   139,   138,
     155,   155,   159,   162,   162,   168,   176,   177,   180,   181,
     184,   184,   190,   191,   194,   195,   198,   199,   200,   201,
     202,   203,   206,   206,   234,   237,   237,   248,   261,   264,
     265,   268,   272,   268,   282,   289,   293,   289,   297,   297,
     303,   306,   307,   310,   310,   319,   319,   320,   323,   323,
     328,   335,   336,   337,   338,   339,   340,   341,   344,   345,
     346,   347,   350,   351,   352,   353,   356,   357,   359,   391,
     392,   393,   394,   395,   400,   395,   406,   407
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "VAR",
  "PROCEDURE", "FUNCTION", "'('", "')'", "','", "':'", "';'", "'.'",
  "T_BEGIN", "T_END", "READ", "WRITE", "IDENT", "NUM", "DIV", "TRUE",
  "FALSE", "ASSIGNMENT", "'+'", "'-'", "'*'", "'/'", "'='", "DIFFERENT",
  "'<'", "'>'", "LESS_EQUAL", "GREATER_EQUAL", "'&'", "'|'", "'!'",
  "WHILE", "DO", "IF", "THEN", "ELSE", "LOWER_THAN_ELSE", "$accept",
  "program", "$@1", "$@2", "main_args", "main_idents", "block", "var",
  "$@3", "declare_vars", "declare_var", "$@4", "$@5", "list_id_var",
  "sub_routines", "sub_routine", "procedure", "$@6", "$@7", "function",
  "$@8", "$@9", "args", "$@10", "list_args", "$@11", "list_idents", "ref",
  "composite_command", "$@12", "commands", "who_cares", "command",
  "assignment", "$@13", "read", "list_args_read", "$@14", "write",
  "list_args_write", "while", "$@15", "$@16", "if", "if_then", "$@17",
  "$@18", "else", "$@19", "nested_commands", "procedure_call", "$@20",
  "exp_args", "$@21", "expression_list", "$@22", "expression",
  "simple_expression", "term", "factor", "$@23", "$@24", "sign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-104)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -155,     5,     6,  -155,    -4,    10,    12,    25,  -155,    37,
    -155,  -155,    21,    19,  -155,  -155,    44,  -155,  -155,  -155,
      42,    69,  -155,    70,    71,    74,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,    55,  -155,  -155,    15,    75,    76,    65,
      65,    82,    83,    77,  -155,  -155,    80,    84,  -155,  -155,
    -155,  -155,  -155,    56,  -155,  -155,  -155,  -155,    86,    88,
      85,     4,    78,    94,     4,     4,  -155,    15,  -155,  -155,
    -155,    92,   100,  -155,    89,    97,    99,     4,   101,  -155,
    -155,  -155,  -155,  -155,     4,    72,  -155,    39,     1,  -155,
       4,     4,  -155,  -155,  -155,  -155,  -155,    -1,  -155,  -155,
     102,    95,    19,    98,   104,  -155,   103,   107,  -155,  -155,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,  -155,  -155,     4,    79,    81,    15,  -155,
    -155,  -155,  -155,    73,   106,  -155,    85,  -155,  -155,  -155,
       1,     1,    20,    20,    20,    20,    20,    20,     1,  -155,
    -155,  -155,   110,   111,    -1,    -1,   108,   109,   112,  -155,
      19,  -155,     4,  -155,   114,  -155,  -155,  -155,  -155,   113,
     116,   117,     4,   119,  -155,  -155,  -155,   100,  -155
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     6,     0,     0,     8,     0,
       3,     5,     0,    12,     7,    10,     0,    21,    15,     4,
       0,    11,    14,     0,     0,     0,    40,    20,    22,    23,
       9,    13,    19,     0,    24,    27,     0,     0,     0,    32,
      32,     0,     0,    73,    61,    65,     0,    45,    46,    47,
      48,    49,    50,    70,    51,    18,    16,    30,     0,     0,
       0,     0,     0,    77,     0,     0,    41,    44,    43,    68,
      64,     0,    39,    25,     0,    55,     0,     0,    98,    99,
     100,   101,   106,   107,     0,     0,    60,    87,    91,    95,
       0,     0,    75,    74,    62,    66,    42,     0,    17,    38,
       0,     0,    12,     0,     0,    54,     0,     0,    96,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    53,     0,     0,     0,     0,    72,
      69,    31,    37,     0,     0,    28,     0,   102,   104,    59,
      88,    89,    81,    82,    83,    84,    85,    86,    90,    93,
      92,    94,     0,    78,     0,     0,     0,     0,     0,    26,
      12,    56,     0,    76,     0,    63,    67,    71,    36,    33,
       0,     0,     0,     0,    29,   105,    79,    39,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,  -155,  -155,  -155,  -100,  -155,  -155,  -155,
     115,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,    91,  -155,   -53,  -155,  -155,  -155,  -155,  -155,
     -67,  -155,   -96,  -155,  -155,  -155,   -21,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,   -70,
    -155,  -155,  -155,  -155,  -154,  -155,   -58,   -39,   -62,   -80,
    -155,  -155,  -155
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    13,     7,     9,    16,    17,    18,    21,
      22,    23,    71,    33,    20,    27,    28,    39,   102,    29,
      40,   160,    58,    72,   100,   173,   133,   101,    30,    36,
      46,    68,    47,    48,    62,    49,    76,   104,    50,    85,
      51,    64,   126,    52,    53,    65,   127,    70,    97,   130,
      54,    63,    93,   125,   152,   164,   153,    87,    88,    89,
     107,   162,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,   129,   134,    86,   108,     3,    94,    95,   171,     4,
     123,    77,   128,     5,    41,    42,    43,     6,   176,   106,
     120,    78,    79,    15,    80,    81,   121,    82,    83,     8,
      41,    42,    43,   124,   122,    44,    10,    45,    14,    84,
     149,   150,   151,   111,   112,    11,    12,    24,    25,   140,
     141,    44,   139,    45,   119,    26,    19,   148,   129,   129,
     170,   156,   111,   112,    37,    38,   113,   114,   115,   116,
     117,   118,    57,   119,   142,   143,   144,   145,   146,   147,
     109,   110,   157,   158,   165,   166,   -15,    32,    34,    60,
      61,    35,    55,    56,    66,    67,    69,    73,    74,   -52,
      91,    92,    75,    98,    99,   -57,   103,   105,  -103,   135,
     131,   137,   132,   136,   138,   161,   154,   159,   163,   -80,
     155,   -35,   167,   172,   178,   175,   168,   174,     0,   169,
     177,    59,     0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      67,    97,   102,    61,    84,     0,    64,    65,   162,     3,
      90,     7,    13,    17,    15,    16,    17,     7,   172,    77,
      19,    17,    18,     4,    20,    21,    25,    23,    24,    17,
      15,    16,    17,    91,    33,    36,    11,    38,    17,    35,
     120,   121,   122,    23,    24,     8,     9,     5,     6,   111,
     112,    36,   110,    38,    34,    13,    12,   119,   154,   155,
     160,   128,    23,    24,     9,    10,    27,    28,    29,    30,
      31,    32,     7,    34,   113,   114,   115,   116,   117,   118,
       8,     9,     9,    10,   154,   155,    17,    17,    17,     7,
       7,    17,    17,    17,    14,    11,    40,    11,    10,    22,
      22,     7,    17,    11,     4,     8,    17,     8,     7,    11,
       8,     8,    17,     9,     7,   136,    37,    11,     8,     8,
      39,     8,    14,     9,   177,     8,    17,    11,    -1,    17,
      11,    40,    -1,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,     3,    17,     7,    46,    17,    47,
      11,     8,     9,    45,    17,     4,    48,    49,    50,    12,
      56,    51,    52,    53,     5,     6,    13,    57,    58,    61,
      70,    52,    17,    55,    17,    17,    71,     9,    10,    59,
      62,    15,    16,    17,    36,    38,    72,    74,    75,    77,
      80,    82,    85,    86,    92,    17,    17,     7,    64,    64,
       7,     7,    76,    93,    83,    87,    14,    11,    73,    40,
      89,    54,    65,    11,    10,    17,    78,     7,    17,    18,
      20,    21,    23,    24,    35,    81,    98,    99,   100,   101,
     104,    22,     7,    94,    98,    98,    72,    90,    11,     4,
      66,    69,    60,    17,    79,     8,    98,   102,   101,     8,
       9,    23,    24,    27,    28,    29,    30,    31,    32,    34,
      19,    25,    33,   101,    98,    95,    84,    88,    13,    74,
      91,     8,    17,    68,    48,    11,     9,     8,     7,    98,
     100,   100,    99,    99,    99,    99,    99,    99,   100,   101,
     101,   101,    96,    98,    37,    39,    72,     9,    10,    11,
      63,    78,   103,     8,    97,    91,    91,    14,    17,    17,
      48,    96,     9,    67,    11,     8,    96,    11,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    45,    43,    46,    46,    47,    47,    48,
      50,    49,    49,    51,    51,    53,    54,    52,    55,    55,
      56,    56,    57,    57,    59,    60,    58,    62,    63,    61,
      65,    64,    64,    67,    66,    66,    68,    68,    69,    69,
      71,    70,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    76,    75,    77,    79,    78,    78,    80,    81,
      81,    83,    84,    82,    85,    87,    88,    86,    90,    89,
      89,    91,    91,    93,    92,    95,    94,    94,    97,    96,
      96,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   102,   103,   101,   104,   104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     3,     0,     3,     1,     3,
       0,     3,     0,     2,     1,     0,     0,     6,     3,     1,
       2,     0,     1,     1,     0,     0,     8,     0,     0,    10,
       0,     4,     0,     0,     7,     4,     3,     1,     1,     0,
       0,     4,     3,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     0,     4,     4,     0,     4,     1,     4,     3,
       1,     0,     0,     6,     2,     0,     0,     6,     0,     3,
       0,     3,     1,     0,     3,     0,     4,     0,     0,     4,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     1,     1,
       1,     1,     3,     0,     0,     6,     1,     1
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
  case 2: /* $@1: %empty  */
#line 64 "compilador.y"
                  { generateCode(-1, "INPP"); }
#line 1329 "compilador.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 66 "compilador.y"
                          { ++lexLevel; }
#line 1335 "compilador.tab.c"
    break;

  case 4: /* program: $@1 PROGRAM IDENT main_args ';' $@2 block '.'  */
#line 67 "compilador.y"
                          { --lexLevel;
			    generateCode(-1, "PARA");
				#if DEBUG == 2
				printStack(&ts1);
				printStack(&ts2);
				printStack(&ts3);
				printStack(&ts4);
				#endif
			  }
#line 1349 "compilador.tab.c"
    break;

  case 9: /* block: var sub_routines composite_command  */
#line 88 "compilador.y"
                                            { if(varTotal[lexLevel] > 0)
									  generateCode(-1, "DMEM", varTotal[lexLevel]); }
#line 1356 "compilador.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 92 "compilador.y"
                              { varTotal[lexLevel] = 0; shift = 0; }
#line 1362 "compilador.tab.c"
    break;

  case 11: /* var: VAR $@3 declare_vars  */
#line 93 "compilador.y"
                                             { generateCode(-1, "AMEM", varTotal[lexLevel]); }
#line 1368 "compilador.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 101 "compilador.y"
                  { varCount = 0; }
#line 1374 "compilador.tab.c"
    break;

  case 16: /* $@5: %empty  */
#line 102 "compilador.y"
                                  { varTotal[lexLevel] += varCount;
					enum type type = strToType(lastIdent);
					for(int i = 0; i < varCount; ++i, ++shift)
						insert(definedVars[i], variable, type, shift); }
#line 1383 "compilador.tab.c"
    break;

  case 18: /* list_id_var: list_id_var ',' IDENT  */
#line 109 "compilador.y"
                                                { strncpy(definedVars[varCount], lastIdent, TOKEN_SIZE); ++varCount; }
#line 1389 "compilador.tab.c"
    break;

  case 19: /* list_id_var: IDENT  */
#line 110 "compilador.y"
                                        { strncpy(definedVars[varCount], lastIdent, TOKEN_SIZE); ++varCount; }
#line 1395 "compilador.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 121 "compilador.y"
                                          { strncpy(lastSubroutine, lastIdent, TOKEN_SIZE); argCount = 0; }
#line 1401 "compilador.tab.c"
    break;

  case 25: /* $@7: %empty  */
#line 122 "compilador.y"
                                                                  { generateCode(-1, "DSVS", newLabel());
									#if COMMENTS == 1
									generateCode(-1, "//", lastSubroutine);
									#endif
									generateCode(newLabel(), "ENPR", lexLevel+1);
									lastSym[lexLevel] = insert(lastSubroutine, procedure, popLabel());
									++lexLevel; }
#line 1413 "compilador.tab.c"
    break;

  case 26: /* procedure: PROCEDURE IDENT $@6 args ';' $@7 block ';'  */
#line 130 "compilador.y"
                                                                  { --lexLevel;
									generateCode(-1, "RTPR", lexLevel+1, ((struct procedure*)lastSym[lexLevel]->data)->argNum);
									#if COMMENTS == 1
									generateCode(-1, "//end", lastSym[lexLevel]->ident);
									#endif
									generateCode(popLabel(), "NADA"); }
#line 1424 "compilador.tab.c"
    break;

  case 27: /* $@8: %empty  */
#line 138 "compilador.y"
                                         { strncpy(lastSubroutine, lastIdent, TOKEN_SIZE); argCount = 0; }
#line 1430 "compilador.tab.c"
    break;

  case 28: /* $@9: %empty  */
#line 139 "compilador.y"
                                                                 { generateCode(-1, "DSVS", newLabel());
								   #if COMMENTS == 1
								   generateCode(-1, "//", lastSubroutine);
								   #endif
								   generateCode(newLabel(), "ENPR", lexLevel+1);
								   lastSym[lexLevel] = insert(lastSubroutine, function, popLabel(), strToType(lastIdent), -argCount-4);
								   ++lexLevel; }
#line 1442 "compilador.tab.c"
    break;

  case 29: /* function: FUNCTION IDENT $@8 args ':' IDENT ';' $@9 block ';'  */
#line 147 "compilador.y"
                                                                 { --lexLevel;
								   generateCode(-1, "RTPR", lexLevel+1, ((struct function*)lastSym[lexLevel]->data)->argNum);
								   #if COMMENTS == 1
								   generateCode(-1, "//end", lastSym[lexLevel]->ident);
								   #endif
								   generateCode(popLabel(), "NADA"); }
#line 1453 "compilador.tab.c"
    break;

  case 30: /* $@10: %empty  */
#line 155 "compilador.y"
                              { argCount = 0; lastArgCount = 0; }
#line 1459 "compilador.tab.c"
    break;

  case 31: /* args: '(' $@10 list_args ')'  */
#line 156 "compilador.y"
                                          { for(int i = 0, shift = 0; i < argCount; ++i, ++shift)
							//printf("\t%s %s %d %s\n", definedArgs[i], typeToStr[argsType[argCount]], shift-argCount-3, argsRef[argCount]?"reference":"value"),
							insert(definedArgs[i], parameter, argsType[i], shift-argCount-3, argsRef[i]); }
#line 1467 "compilador.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 162 "compilador.y"
                                                    { enum type type = strToType(lastIdent);
											  for(int i = lastArgCount; i < argCount; ++i) {
												  argsType[i] = type;
												  argsRef[i] = ref;
											  }
											  lastArgCount = argCount; }
#line 1478 "compilador.tab.c"
    break;

  case 35: /* list_args: ref list_idents ':' IDENT  */
#line 168 "compilador.y"
                                                            { enum type type = strToType(lastIdent);
											  for(int i = lastArgCount; i < argCount; ++i) {
												  argsType[i] = type;
												  argsRef[i] = ref;
											  }
											  lastArgCount = argCount; }
#line 1489 "compilador.tab.c"
    break;

  case 36: /* list_idents: list_idents ',' IDENT  */
#line 176 "compilador.y"
                                                { strncpy(definedArgs[argCount], lastIdent, TOKEN_SIZE); ++argCount; }
#line 1495 "compilador.tab.c"
    break;

  case 37: /* list_idents: IDENT  */
#line 177 "compilador.y"
                                        { strncpy(definedArgs[argCount], lastIdent, TOKEN_SIZE); ++argCount; }
#line 1501 "compilador.tab.c"
    break;

  case 38: /* ref: VAR  */
#line 180 "compilador.y"
                                      { ref = true; /*printf("\treference\n");*/ }
#line 1507 "compilador.tab.c"
    break;

  case 39: /* ref: %empty  */
#line 181 "compilador.y"
                                  { ref = false; /*printf("\tvalue\n");*/ }
#line 1513 "compilador.tab.c"
    break;

  case 40: /* $@12: %empty  */
#line 184 "compilador.y"
                           {
						#if DEBUG == 1
						print();
						#endif
					}
#line 1523 "compilador.tab.c"
    break;

  case 52: /* $@13: %empty  */
#line 206 "compilador.y"
                                { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("symbol not found", __LINE__);
						  varLexLevel = sym->lexLevel;
						  assignmentShift = ((struct variable*)sym->data)->shift;
						  lElem = ((struct variable*)sym->data)->type;
						  assignmentCategory = sym->category;
						  if(sym->category == parameter && ((struct parameter*)sym->data)->ref) {
							  assignmentRef = ((struct parameter*)sym->data)->ref;
						  } else {
							  assignmentRef = false;
						  } }
#line 1540 "compilador.tab.c"
    break;

  case 53: /* assignment: IDENT $@13 ASSIGNMENT expression  */
#line 218 "compilador.y"
                                                { enum type t = popType(&ts1);
						  #if DEBUG == 2
						  printf("\t%d %d ", lElem, t);
						  printf("%s %s\n", typeToStr[lElem], typeToStr[t]);
						  #endif
						  if(lElem == t) {
							  if(assignmentCategory == function)
								  generateCode(-1, "ARMZ", varLexLevel+1, assignmentShift);
							  else if(assignmentCategory == parameter && assignmentRef)
								  generateCode(-1, "ARMI", varLexLevel, assignmentShift);
							  else
								  generateCode(-1, "ARMZ", varLexLevel, assignmentShift);
						  } else
							  printError("wrong type", __LINE__); }
#line 1559 "compilador.tab.c"
    break;

  case 55: /* $@14: %empty  */
#line 237 "compilador.y"
                        { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("variable not found", __LINE__);
						  struct variable* var = sym->data;
						  generateCode(-1, "LEIT");
						  if(sym->category == function)
							  generateCode(-1, "ARMZ", sym->lexLevel+1, var->shift);
						  else if(sym->category == parameter && ((struct parameter*)sym->data)->ref)
							  generateCode(-1, "ARMI", sym->lexLevel, var->shift);
						  else
							  generateCode(-1, "ARMZ", sym->lexLevel, var->shift); }
#line 1575 "compilador.tab.c"
    break;

  case 57: /* list_args_read: IDENT  */
#line 248 "compilador.y"
                                        { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("variable not found", __LINE__);
						  struct variable* var = sym->data;
						  generateCode(-1, "LEIT");
						  if(sym->category == function)
							  generateCode(-1, "ARMZ", sym->lexLevel+1, var->shift);
						  else if(sym->category == parameter && ((struct parameter*)sym->data)->ref)
							  generateCode(-1, "ARMI", sym->lexLevel, var->shift);
						  else
							  generateCode(-1, "ARMZ", sym->lexLevel, var->shift); }
#line 1591 "compilador.tab.c"
    break;

  case 59: /* list_args_write: list_args_write ',' expression  */
#line 264 "compilador.y"
                                                 { popType(&ts1); generateCode(-1, "IMPR"); }
#line 1597 "compilador.tab.c"
    break;

  case 60: /* list_args_write: expression  */
#line 265 "compilador.y"
                                             { popType(&ts1); generateCode(-1, "IMPR"); }
#line 1603 "compilador.tab.c"
    break;

  case 61: /* $@15: %empty  */
#line 268 "compilador.y"
                                { 
						  #if COMMENTS == 1
						  generateCode(-1, "//", "while");
						  #endif
						  generateCode(newLabel(), "NADA"); }
#line 1613 "compilador.tab.c"
    break;

  case 62: /* $@16: %empty  */
#line 272 "compilador.y"
                                                                                                 { if(popType(&ts1) != boolean) printError("wrong type", __LINE__); generateCode(-1, "DSVF", newLabel()); }
#line 1619 "compilador.tab.c"
    break;

  case 63: /* while: WHILE $@15 expression $@16 DO nested_commands  */
#line 274 "compilador.y"
                                { int label = popLabel();
				  #if COMMENTS == 1
				  generateCode(-1, "//", "end while");
				  #endif
				  generateCode(-1, "DSVS", popLabel());
				  generateCode(label, "NADA"); }
#line 1630 "compilador.tab.c"
    break;

  case 64: /* if: if_then else  */
#line 282 "compilador.y"
                                               { --lIndex;
								 #if COMMENTS == 1
								 generateCode(-1, "//", "end if");
								 #endif
							   }
#line 1640 "compilador.tab.c"
    break;

  case 65: /* $@17: %empty  */
#line 289 "compilador.y"
                             {
					   #if COMMENTS == 1
					   generateCode(-1, "//", "if");
					   #endif
					 }
#line 1650 "compilador.tab.c"
    break;

  case 66: /* $@18: %empty  */
#line 293 "compilador.y"
                                                      { if(popType(&ts1) != boolean) printError("wrong type", __LINE__); generateCode(-1, "DSVF", newLabel()); }
#line 1656 "compilador.tab.c"
    break;

  case 67: /* if_then: IF $@17 expression $@18 THEN nested_commands  */
#line 294 "compilador.y"
                                                          { generateCode(-1, "DSVS", newLabel()); strncpy(nLabel[++lIndex], ls.ls[popLabel()], LABEL_SIZE); generateCode(popLabel(), "NADA"); }
#line 1662 "compilador.tab.c"
    break;

  case 68: /* $@19: %empty  */
#line 297 "compilador.y"
                               {
						 #if COMMENTS == 1
	   					 generateCode(-1, "//", "else");
						 #endif
					   }
#line 1672 "compilador.tab.c"
    break;

  case 69: /* else: ELSE $@19 nested_commands  */
#line 302 "compilador.y"
                                                          { generateCode(-2, "NADA"); }
#line 1678 "compilador.tab.c"
    break;

  case 73: /* $@20: %empty  */
#line 310 "compilador.y"
                        { lastCall = search(lastIdent);
						  if(lastCall == NULL)
							  printError("symbol not found", __LINE__); }
#line 1686 "compilador.tab.c"
    break;

  case 74: /* procedure_call: IDENT $@20 exp_args  */
#line 314 "compilador.y"
                                                { if(argCount != ((struct procedure*)lastCall->data)->argNum)
							  printError("wrong number of arguments", __LINE__);
						  generateCode(-1, "CHPR", ((struct procedure*)lastCall->data)->label, lexLevel); }
#line 1694 "compilador.tab.c"
    break;

  case 75: /* $@21: %empty  */
#line 319 "compilador.y"
                      { argCount = 0; }
#line 1700 "compilador.tab.c"
    break;

  case 78: /* $@22: %empty  */
#line 323 "compilador.y"
                             { if(lastCall->category == procedure) {
								   if(((struct procedure*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } else {
								   if(((struct function*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } }
#line 1710 "compilador.tab.c"
    break;

  case 80: /* expression_list: expression  */
#line 328 "compilador.y"
                                             { if(lastCall->category == procedure) {
								   if(((struct procedure*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } else {
								   if(((struct function*)lastCall->data)->argsType[argCount] != popType(&ts1)) printError("wrong type", __LINE__); ++argCount;
							   } }
#line 1720 "compilador.tab.c"
    break;

  case 81: /* expression: simple_expression '=' simple_expression  */
#line 335 "compilador.y"
                                                                                        { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMIG"); }
#line 1726 "compilador.tab.c"
    break;

  case 82: /* expression: simple_expression DIFFERENT simple_expression  */
#line 336 "compilador.y"
                                                                                        { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMDG"); }
#line 1732 "compilador.tab.c"
    break;

  case 83: /* expression: simple_expression '<' simple_expression  */
#line 337 "compilador.y"
                                                                                                { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMME"); }
#line 1738 "compilador.tab.c"
    break;

  case 84: /* expression: simple_expression '>' simple_expression  */
#line 338 "compilador.y"
                                                                                                { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMMA"); }
#line 1744 "compilador.tab.c"
    break;

  case 85: /* expression: simple_expression LESS_EQUAL simple_expression  */
#line 339 "compilador.y"
                                                                                        { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMEG"); }
#line 1750 "compilador.tab.c"
    break;

  case 86: /* expression: simple_expression GREATER_EQUAL simple_expression  */
#line 340 "compilador.y"
                                                                                    { if(popType(&ts2) != popType(&ts2)) printError("wrong type", __LINE__); pushType(&ts1, boolean); generateCode(-1, "CMAG"); }
#line 1756 "compilador.tab.c"
    break;

  case 87: /* expression: simple_expression  */
#line 341 "compilador.y"
                                                                                                                        { pushType(&ts1, popType(&ts2)); }
#line 1762 "compilador.tab.c"
    break;

  case 88: /* simple_expression: simple_expression '+' term  */
#line 344 "compilador.y"
                                                     { if(popType(&ts2) != popType(&ts3)) printError("wrong type", __LINE__); pushType(&ts2, integer); generateCode(-1, "SOMA"); }
#line 1768 "compilador.tab.c"
    break;

  case 89: /* simple_expression: simple_expression '-' term  */
#line 345 "compilador.y"
                                                                     { if(popType(&ts2) != popType(&ts3)) printError("wrong type", __LINE__); pushType(&ts2, integer); generateCode(-1, "SUBT"); }
#line 1774 "compilador.tab.c"
    break;

  case 90: /* simple_expression: simple_expression '|' term  */
#line 346 "compilador.y"
                                                                     { if(popType(&ts2) != popType(&ts3)) printError("wrong type", __LINE__); pushType(&ts2, boolean); generateCode(-1, "DISJ"); }
#line 1780 "compilador.tab.c"
    break;

  case 91: /* simple_expression: term  */
#line 347 "compilador.y"
                                                                                         { pushType(&ts2, popType(&ts3)); }
#line 1786 "compilador.tab.c"
    break;

  case 92: /* term: term '*' factor  */
#line 350 "compilador.y"
                                                { if(popType(&ts3) != popType(&ts4)) printError("wrong type", __LINE__); pushType(&ts3, integer); generateCode(-1, "MULT"); }
#line 1792 "compilador.tab.c"
    break;

  case 93: /* term: term DIV factor  */
#line 351 "compilador.y"
                                                        { if(popType(&ts3) != popType(&ts4)) printError("wrong type", __LINE__); pushType(&ts3, integer); generateCode(-1, "DIVI"); }
#line 1798 "compilador.tab.c"
    break;

  case 94: /* term: term '&' factor  */
#line 352 "compilador.y"
                                                        { if(popType(&ts3) != popType(&ts4)) printError("wrong type", __LINE__); pushType(&ts3, boolean); generateCode(-1, "CONJ"); }
#line 1804 "compilador.tab.c"
    break;

  case 95: /* term: factor  */
#line 353 "compilador.y"
                                                                { pushType(&ts3, popType(&ts4)); }
#line 1810 "compilador.tab.c"
    break;

  case 96: /* factor: '!' factor  */
#line 356 "compilador.y"
                                     { if(popType(&ts4) != boolean) printError("wrong type", __LINE__); pushType(&ts4, boolean); generateCode(-1, "NEGA"); }
#line 1816 "compilador.tab.c"
    break;

  case 97: /* factor: sign factor  */
#line 357 "compilador.y"
                                              { if(popType(&ts4) != integer) printError("wrong type", __LINE__); pushType(&ts4, integer);
								if(minus[mIndex]) { generateCode(-1, "INVR"); minus[mIndex] = false; } --mIndex; }
#line 1823 "compilador.tab.c"
    break;

  case 98: /* factor: IDENT  */
#line 359 "compilador.y"
                                        { struct symbolTableNode* sym = search(lastIdent);
						  if(sym == NULL)
							  printError("symbol not found", __LINE__);
						  if(sym->category == function) {
							  generateCode(-1, "AMEM", 1);
			 				  lastCall = search(lastIdent);
							  if(lastCall == NULL)
								  printError("symbol not found", __LINE__);
							  pushType(&ts4, ((struct function*)lastCall->data)->type);
							  generateCode(-1, "CHPR", ((struct function*)lastCall->data)->label, lexLevel);
						  }
						  else if(sym->category == parameter && ((struct parameter*)sym->data)->ref) {
							  if(lastCall && lastCall->category == procedure && ((struct procedure*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CRVL", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else if(lastCall && lastCall->category == function && ((struct function*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CRVL", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else
								  generateCode(-1, "CRVI", sym->lexLevel, ((struct variable*)sym->data)->shift);
						  } else {
							  if(lastCall && lastCall->category == procedure && ((struct procedure*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CREN", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else if(lastCall && lastCall->category == function && ((struct function*)lastCall->data)->argsRef[argCount])
								  generateCode(-1, "CREN", sym->lexLevel, ((struct variable*)sym->data)->shift);
							  else
								  generateCode(-1, "CRVL", sym->lexLevel, ((struct variable*)sym->data)->shift);
						  }
						  if(sym->category == variable)
							  pushType(&ts4, ((struct variable*)sym->data)->type);
						  else if(sym->category == parameter)
							  pushType(&ts4, ((struct parameter*)sym->data)->type);
						  else if(sym->category == function)
							  pushType(&ts4, ((struct function*)sym->data)->type); }
#line 1860 "compilador.tab.c"
    break;

  case 99: /* factor: NUM  */
#line 391 "compilador.y"
                                      { generateCode(-1, "CRCT", token); pushType(&ts4, integer); }
#line 1866 "compilador.tab.c"
    break;

  case 100: /* factor: TRUE  */
#line 392 "compilador.y"
                                        { generateCode(-1, "CRCT", "1"); pushType(&ts4, boolean); }
#line 1872 "compilador.tab.c"
    break;

  case 101: /* factor: FALSE  */
#line 393 "compilador.y"
                                        { generateCode(-1, "CRCT", "0"); pushType(&ts4, boolean); }
#line 1878 "compilador.tab.c"
    break;

  case 102: /* factor: '(' expression ')'  */
#line 394 "compilador.y"
                                                     { pushType(&ts4, popType(&ts1)); }
#line 1884 "compilador.tab.c"
    break;

  case 103: /* $@23: %empty  */
#line 395 "compilador.y"
                                        { generateCode(-1, "AMEM", 1);
			 				   lastCall = search(lastIdent);
							   if(lastCall == NULL)
								   printError("symbol not found", __LINE__);
							   pushType(&ts4, ((struct function*)lastCall->data)->type); }
#line 1894 "compilador.tab.c"
    break;

  case 104: /* $@24: %empty  */
#line 400 "compilador.y"
                                                    { argCount = 0; }
#line 1900 "compilador.tab.c"
    break;

  case 105: /* factor: IDENT $@23 '(' $@24 expression_list ')'  */
#line 401 "compilador.y"
                                                         { if(argCount != ((struct function*)lastCall->data)->argNum)
								   printError("wrong number of arguments", __LINE__);
							   generateCode(-1, "CHPR", ((struct function*)lastCall->data)->label, lexLevel); }
#line 1908 "compilador.tab.c"
    break;

  case 107: /* sign: '-'  */
#line 407 "compilador.y"
                                      { minus[++mIndex] = true; }
#line 1914 "compilador.tab.c"
    break;


#line 1918 "compilador.tab.c"

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

#line 410 "compilador.y"


FILE* fp = NULL;
void generateCode(int label, char* command, ...) {
	va_list ap;

	va_start(ap, command);

	if(fp == NULL)
		fp = fopen ("MEPA", "w");

	if(label >= 0)
		fprintf(fp, "%s:", ls.ls[label]);
	else if(label == -2)
		fprintf(fp, "%s:", nLabel[lIndex]);
	else
		fprintf(fp, "    ");

	if(strcasecmp(command, "CRCT") == 0) {
		fprintf(fp, "%s %s\n", command, va_arg(ap, char*));
	} else if(strcasecmp(command, "DSVS") == 0 || strcasecmp(command, "DSVF") == 0) {
		fprintf(fp, "%s %s\n", command, ls.ls[va_arg(ap, int)]);
	} else if(strcasecmp(command, "AMEM") == 0 || strcasecmp(command, "DMEM") == 0 || strcasecmp(command, "ENPR") == 0) {
		fprintf(fp, "%s %d\n", command, va_arg(ap, int));
	} else if(strcasecmp(command, "ARMZ") == 0 || strcasecmp(command, "ARMI") == 0 || strcasecmp(command, "CRVL") == 0 ||
			  strcasecmp(command, "CRVI") == 0 || strcasecmp(command, "CREN") == 0 || strcasecmp(command, "RTPR") == 0) {
		int lex = va_arg(ap, int);
		fprintf(fp, "%s %d, %d\n", command, lex, va_arg(ap, int));
	} else if(strcasecmp(command, "CHPR") == 0) {
		char* label = va_arg(ap, char*);
		fprintf(fp, "%s %s, %d\n", command, label, va_arg(ap, int));
	} else if(strncmp(command, "//", 2) == 0) {
		fprintf(fp, "%s %s\n", command, va_arg(ap, char*));
	} else {
		fprintf(fp, "%s\n", command);
	}
	fflush(fp);
	va_end(ap);
}

int printError(char* error, int line) {
	printf("compilador.y line %d \u2551 Error in line %d - %s\n", line, nl, error);
	exit(-1);
}

struct symbolTableNode* insert(char* ident, enum category category, ...) {
	++symbolTable.top;
	struct symbolTableNode* node = &symbolTable.st[symbolTable.top];
	strncpy(node->ident,ident,TOKEN_SIZE);
	node->category = category;
	node->lexLevel = lexLevel;

	#if DEBUG == 1
	printf("inserting: %s\n", ident);
	#endif

	va_list ap;
	va_start(ap, category);

	switch(category) {
		case variable:
			node->data = malloc(sizeof(struct variable));
			struct variable* var = node->data;
			var->type = va_arg(ap, enum type);
			var->shift = va_arg(ap, int);
			break;

		case parameter:
			++node->lexLevel;
			node->data = malloc(sizeof(struct parameter));
			struct parameter* par = node->data;
			par->type = va_arg(ap, enum type);
			par->shift = va_arg(ap, int);
			par->ref = va_arg(ap, int);
			break;

		case procedure:
			node->data = malloc(sizeof(struct procedure));
			struct procedure* proc = node->data;
			strncpy(proc->label, ls.ls[va_arg(ap, int)], LABEL_SIZE);
			proc->argNum = argCount;
			for(int i = 0; i < proc->argNum; ++i) {
				proc->argsType[i] = argsType[i];
				proc->argsRef[i] = argsRef[i];
			}
			break;

		case function:
			node->data = malloc(sizeof(struct function));
			struct function* func = node->data;
			strncpy(func->label, ls.ls[va_arg(ap, int)], LABEL_SIZE);
			func->argNum = argCount;
			for(int i = 0; i < func->argNum; ++i) {
				func->argsType[i] = argsType[i];
				func->argsRef[i] = argsRef[i];
			}
			func->type = va_arg(ap, enum type);
			func->shift = va_arg(ap, int);
			break;
	}
	va_end(ap);
	return node;
}

struct symbolTableNode* search(char* ident) {
	for(int i = symbolTable.top; i >= 0; --i) {
		#if DEBUG == 1
		printf("comparing: %s with %s\n",symbolTable.st[i].ident,ident);
		#endif
		if(strncasecmp(symbolTable.st[i].ident,ident,TOKEN_SIZE) == 0 && symbolTable.st[i].lexLevel <= lexLevel) {
			#if DEBUG == 1
			printf("\tsearch success\n");
			#endif
			return &symbolTable.st[i];
		}
	}
	#if DEBUG == 1
	printf("\tsearch failed\n");
	#endif
	return NULL;
}

void remov(int n) {
	for(int i = 0; i < n; ++i, --symbolTable.top)
		free(symbolTable.st[symbolTable.top].data);
}

void print() {
	printf("print: top == %d\n", symbolTable.top);
	for(int i = symbolTable.top; i >= 0; --i) {
		printf("print: %s %s %d, ", symbolTable.st[i].ident, catToStr[symbolTable.st[i].category], symbolTable.st[i].lexLevel);
		if(symbolTable.st[i].category == variable) {
			struct variable* data = symbolTable.st[i].data;
			printf("%d\n", data->shift);
		} else if(symbolTable.st[i].category == parameter) {
			struct parameter* data = symbolTable.st[i].data;
			printf("%d %s\n", data->shift, data->ref?"reference":"value");
		} else if(symbolTable.st[i].category == procedure) {
			struct procedure* data = symbolTable.st[i].data;
			printf("%s %d\n", data->label, data->argNum);
		}
	}
}

void pushType(struct typeStack* ts, enum type type) {
	++ts->top;
	ts->ts[ts->top] = type;
	#if DEBUG == 2
	printf("%p: pushing %s to postion %d\n", ts, typeToStr[type], ts->top);
	#endif
}

enum type popType(struct typeStack* ts) {
	#if DEBUG == 2
	printf("%p: popping %s on postion %d\n", ts, typeToStr[ts->ts[ts->top]], ts->top);
	#endif
	--ts->top;
	return ts->ts[ts->top+1];
}

void printStack(struct typeStack* ts) {
	printf("print: top == %d\n", ts->top);
	for(int i = ts->top; i >= 0; --i) {
		printf("print: %s\n", typeToStr[ts->ts[i]]);
	}
}

enum type strToType(char* str) {
	if(strncasecmp(str, "integer", TOKEN_SIZE) == 0)
		return integer;
	else if(strncasecmp(str, "real", TOKEN_SIZE) == 0)
		return real;
	else if(strncasecmp(str, "character", TOKEN_SIZE) == 0)
		return character;
	else if(strncasecmp(str, "boolean", TOKEN_SIZE) == 0)
		return boolean;

	printError("strToType: invalid argument\n", __LINE__);
	return integer;
}

int newLabel() {
	++ls.top;
	snprintf(ls.ls[ls.top], LABEL_SIZE, "R%02d", ++labelCount);
	#if DEBUG == 3
	printf("new label: %s\n", ls.ls[ls.top]);
	printf("pushing %s to postion %d\n", ls.ls[ls.top], ls.top);
	#endif
	return ls.top;
}

int popLabel() {
	#if DEBUG == 3
	printf("poping %s on postion %d\n", ls.ls[ls.top], ls.top);
	#endif
	--ls.top;
	return ls.top+1;
}


int main(int argc, char** argv) {
	FILE* fp;
	extern FILE* yyin;

	#if YYDEBUG == 1
	yydebug = 1;
	#endif

	if (argc != 2) {
		 printf("usage: ./compilador <arq.pas>\n");
		 return -1;
	}

	fp = fopen (argv[1], "r");
	if (fp == NULL) {
		printf("usage ./compilador <arq.pas>\n");
		return -1;
	}

	yyin = fp;
	yyparse();

	return 0;
}
