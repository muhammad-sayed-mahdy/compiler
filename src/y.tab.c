/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "calc3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"

/* prototypes */

int noOfCases;

nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt);
nodeType *switchOpr(nodeType* exp, struct switchStatement * ss);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                    /* symbol table */

#line 89 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    VARIABLE = 259,
    WHILE = 260,
    IF = 261,
    PRINT = 262,
    FOR = 263,
    REPEAT = 264,
    UNTIL = 265,
    SWITCH = 266,
    CASE = 267,
    DEFAULT = 268,
    IFX = 269,
    ELSE = 270,
    PLUS_EQ = 271,
    MINUS_EQ = 272,
    MUL_EQ = 273,
    DIV_EQ = 274,
    MOD_EQ = 275,
    SH_LE_EQ = 276,
    SH_RI_EQ = 277,
    AND_EQ = 278,
    XOR_EQ = 279,
    OR_EQ = 280,
    OR = 281,
    AND = 282,
    GE = 283,
    LE = 284,
    EQ = 285,
    NE = 286,
    SHIFT_LEFT = 287,
    SHIFT_RIGHT = 288,
    UMINUS = 289
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define VARIABLE 259
#define WHILE 260
#define IF 261
#define PRINT 262
#define FOR 263
#define REPEAT 264
#define UNTIL 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define IFX 269
#define ELSE 270
#define PLUS_EQ 271
#define MINUS_EQ 272
#define MUL_EQ 273
#define DIV_EQ 274
#define MOD_EQ 275
#define SH_LE_EQ 276
#define SH_RI_EQ 277
#define AND_EQ 278
#define XOR_EQ 279
#define OR_EQ 280
#define OR 281
#define AND 282
#define GE 283
#define LE 284
#define EQ 285
#define NE 286
#define SHIFT_LEFT 287
#define SHIFT_RIGHT 288
#define UMINUS 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "calc3.y" /* yacc.c:355  */

    int iValue;                         /* integer value */
    char sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  

#line 204 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    44,    31,     2,
      49,    50,    42,    40,     2,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    48,
      37,    16,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    29,    52,    46,     2,     2,     2,
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
      15,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    32,    33,    34,    35,    38,    39,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    59,    60,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    77,    78,    79,    83,    84,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "VARIABLE", "WHILE", "IF",
  "PRINT", "FOR", "REPEAT", "UNTIL", "SWITCH", "CASE", "DEFAULT", "IFX",
  "ELSE", "'='", "PLUS_EQ", "MINUS_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ",
  "SH_LE_EQ", "SH_RI_EQ", "AND_EQ", "XOR_EQ", "OR_EQ", "OR", "AND", "'|'",
  "'^'", "'&'", "GE", "LE", "EQ", "NE", "'>'", "'<'", "SHIFT_LEFT",
  "SHIFT_RIGHT", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'~'", "'!'",
  "';'", "'('", "')'", "'{'", "'}'", "':'", "$accept", "program",
  "function", "stmt", "switch_stmt", "stmt_list", "const_expr", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
<<<<<<< HEAD
     265,   266,   267,   268,   269,   270,    61,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   124,
      94,    38,   283,   284,   285,   286,    62,    60,   287,   288,
      43,    45,    42,    47,    37,   289,   126,    33,    59,    40,
      41,   123,   125,    58
};
# endif

#define YYPACT_NINF -54
=======
     265,   266,   267,    61,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   124,    94,    38,   280,
     281,   282,   283,    62,    60,   284,   285,    43,    45,    42,
      47,    37,   286,   287,   126,    33,    59,    40,    41,   123,
     125
};
# endif

#define YYPACT_NINF (-42)
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
     -54,     6,    98,   -54,   -54,    -2,   -13,     3,     9,     5,
      98,     8,     9,     9,     9,   -54,     9,    98,   -54,   335,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,   357,     9,    49,     9,   -54,   -54,   -54,
     167,   -54,    75,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,   -54,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   191,   215,   -54,   379,    36,   239,   -54,
     -54,   -54,   440,   456,   487,   516,   543,    54,    54,    54,
      54,    54,    54,   -39,   -39,   -16,   -16,   -54,   -54,   -54,
      98,    98,     9,     9,    48,   -54,    93,   401,   263,    22,
      98,     9,    62,    84,    58,    60,   -54,   287,   -54,   -54,
      84,    84,    84,    84,   140,    98,   -54,    98,   -54,   -54,
     -54,   311,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    98,   -54,   -54,
     -54,   473,   503,   531,   557,   569,   -32,   -32,   -32,   -32,
     -32,   -32,    46,    46,   -54,   -54,    22,   -54
=======
     -42,     4,    78,   -42,   -42,   425,   -41,   -35,    57,   -33,
      78,    57,    57,    57,    57,   -42,    57,    78,   -42,   229,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,   252,    57,     5,   -42,   -42,   -42,   -42,
     104,   -42,    30,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,   -42,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   129,   154,   -42,   275,   -31,   -42,   -42,
     -42,   338,   354,   369,   383,   396,    71,    71,    71,    71,
      71,    71,    25,    25,   -38,   -38,   -42,   -42,   -42,    78,
      78,    57,    57,   -42,    18,   298,   179,    78,    57,    12,
     -42,   204,   -42,    78,   -42
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
       4,     0,     2,     1,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    54,    53,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    52,    51,     0,     0,     7,     0,     0,     0,    74,
      14,    19,    56,    57,    58,    59,    60,    68,    69,    71,
      70,    67,    66,    72,    73,    61,    62,    63,    64,    65,
       0,     0,     0,     0,     0,     8,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     9,    20,
       0,     0,     0,     0,     0,     0,    11,     0,    23,    22,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    10,
      39,    24,    25,    26,    27,    28,    35,    36,    38,    37,
      34,    33,    29,    30,    31,    32,    15,    16
=======
       4,     0,     2,     1,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    30,    29,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    28,    27,     0,     0,     7,     0,     0,    51,    13,
      15,    33,    34,    35,    36,    37,    45,    46,    48,    47,
      44,    43,    49,    50,    38,    39,    40,    41,    42,     0,
       0,     0,     0,     8,    11,     0,     0,     0,     0,     0,
      12,     0,     9,     0,    10
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -54,   -54,   -54,   -10,   -53,   -54,    20,    17
=======
     -42,   -42,   -42,   -10,   -42,    -3
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
<<<<<<< HEAD
      -1,     1,     2,    18,   115,    42,   124,    19
=======
      -1,     1,     2,    18,    42,    19
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      35,    56,    57,    58,    59,    60,     3,    41,   143,   144,
     145,   146,     4,     5,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    33,    58,    59,    60,    37,
      38,    39,    81,    40,   113,   114,    31,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      12,    76,    32,    78,    34,    13,    14,    36,    16,    77,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     4,     5,
       6,     7,     8,     9,    10,   103,    11,   119,   145,   146,
     105,   106,    54,    55,    56,    57,    58,    59,    60,   109,
     116,     4,     5,     6,     7,     8,     9,    10,   110,    11,
     118,   125,   126,   167,     0,   148,    12,   149,     0,   107,
     108,    13,    14,    15,    16,   120,    17,    80,   117,     0,
     121,   122,     0,   123,     0,     0,     0,   166,     0,    12,
     128,   129,   130,   131,    13,    14,    15,    16,     0,    17,
       0,     0,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,    79,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,   100,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,   101,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,   104,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,   112,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,   127,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,   146,     0,     0,     0,     0,     0,
       0,   150,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,    61,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,    75,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,   102,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,   111,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,   146,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,   146,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,   146,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
     146,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,   145,   146
=======
      35,    58,    59,    60,     3,    33,    31,    41,    36,    37,
      38,    39,    32,    40,    34,    77,   102,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     107,    76,    80,     4,     5,     6,     7,     8,     9,    10,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   112,     0,
       4,     5,    56,    57,    58,    59,    60,    11,    12,     0,
       0,     0,     0,     0,    13,    14,    15,    16,     0,    17,
      79,     4,     5,     6,     7,     8,     9,    10,     0,   103,
     104,     0,     0,     0,    11,    12,     0,   110,   105,   106,
       0,    13,    14,   114,    16,   111,    54,    55,    56,    57,
      58,    59,    60,     0,     0,    11,    12,     0,     0,     0,
       0,     0,    13,    14,    15,    16,     0,    17,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,    78,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,    99,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,   100,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,   109,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,   113,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,    61,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,    75,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,   101,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,   108,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
      10,    40,    41,    42,    43,    44,     0,    17,    40,    41,
      42,    43,     3,     4,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     8,    42,    43,    44,    12,
      13,    14,    42,    16,    12,    13,    49,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      41,    34,    49,    36,    49,    46,    47,    49,    49,    10,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     3,     4,
       5,     6,     7,     8,     9,    49,    11,     3,    42,    43,
     100,   101,    38,    39,    40,    41,    42,    43,    44,    51,
     110,     3,     4,     5,     6,     7,     8,     9,    15,    11,
      48,    53,    52,   166,    -1,   125,    41,   127,    -1,   102,
     103,    46,    47,    48,    49,    41,    51,    52,   111,    -1,
      46,    47,    -1,    49,    -1,    -1,    -1,   147,    -1,    41,
     120,   121,   122,   123,    46,    47,    48,    49,    -1,    51,
      -1,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    50,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43
=======
      10,    39,    40,    41,     0,     8,    47,    17,    11,    12,
      13,    14,    47,    16,    47,    10,    47,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      12,    34,    42,     3,     4,     5,     6,     7,     8,     9,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    46,    -1,
       3,     4,    37,    38,    39,    40,    41,    37,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,
      50,     3,     4,     5,     6,     7,     8,     9,    -1,    99,
     100,    -1,    -1,    -1,    37,    38,    -1,   107,   101,   102,
      -1,    44,    45,   113,    47,   108,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    49,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,    55,    56,     0,     3,     4,     5,     6,     7,     8,
       9,    11,    41,    46,    47,    48,    49,    51,    57,    61,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    49,    49,    61,    49,    57,    49,    61,    61,    61,
      61,    57,    59,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    48,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    48,    61,    10,    61,    50,
      52,    57,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      50,    50,    48,    49,    50,    57,    57,    61,    61,    51,
      15,    48,    50,    12,    13,    58,    57,    61,    48,     3,
      41,    46,    47,    49,    60,    53,    52,    50,    60,    60,
      60,    60,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    40,    41,    42,    43,    53,    57,    57,
      50,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    57,    58
=======
       0,    52,    53,     0,     3,     4,     5,     6,     7,     8,
       9,    37,    38,    44,    45,    46,    47,    49,    54,    56,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    47,    47,    56,    47,    54,    56,    56,    56,    56,
      56,    54,    55,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    46,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    46,    56,    10,    48,    50,
      54,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    48,
      48,    46,    47,    54,    54,    56,    56,    12,    46,    48,
      54,    56,    46,    48,    54
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61
=======
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     3,     5,     7,
<<<<<<< HEAD
       9,     7,     5,     7,     3,     4,     5,     3,     1,     2,
       1,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
=======
       9,     5,     7,     3,     1,     2,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
<<<<<<< HEAD
        case 2:
#line 55 "calc3.y" /* yacc.c:1646  */
    { exit(0); }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "calc3.y" /* yacc.c:1646  */
    { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 68 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(REPEAT, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr)); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 69 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = switchOpr( (yyvsp[-4].nPtr), (yyvsp[-1].swtch)); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "calc3.y" /* yacc.c:1646  */
    { (yyval.swtch) = conc(CASE, (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 78 "calc3.y" /* yacc.c:1646  */
    { (yyval.swtch) = conc(CASE, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr), (yyvsp[0].swtch));}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "calc3.y" /* yacc.c:1646  */
    { (yyval.swtch) = conc(DEFAULT, NULL, (yyvsp[0].nPtr), NULL);}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 88 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 89 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('!', 1, (yyvsp[0].nPtr)); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 90 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('~', 1, (yyvsp[0].nPtr)); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 91 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 92 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 93 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 94 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('|', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('&', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 98 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 103 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 105 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 107 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 112 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 113 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 114 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 115 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(MINUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 116 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(MUL_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 117 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(DIV_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 118 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 119 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(SH_LE_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 120 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 121 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(AND_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
=======
  case 2:
#line 48 "calc3.y"
                                { exit(0); }
#line 1522 "y.tab.c"
    break;

  case 3:
#line 52 "calc3.y"
                                { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1528 "y.tab.c"
    break;

  case 5:
#line 57 "calc3.y"
                                                                 { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1534 "y.tab.c"
    break;

  case 6:
#line 58 "calc3.y"
                                                                 { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1540 "y.tab.c"
    break;

  case 7:
#line 59 "calc3.y"
                                                                 { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1546 "y.tab.c"
    break;

  case 8:
#line 60 "calc3.y"
                                                                 { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1552 "y.tab.c"
    break;

  case 9:
#line 61 "calc3.y"
                                                                 { (yyval.nPtr) = opr(REPEAT, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr)); }
#line 1558 "y.tab.c"
    break;

  case 10:
#line 62 "calc3.y"
                                                                 { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1564 "y.tab.c"
    break;

  case 11:
#line 64 "calc3.y"
                                                                 { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1570 "y.tab.c"
    break;

  case 12:
#line 65 "calc3.y"
                                                                 { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1576 "y.tab.c"
    break;

  case 13:
#line 66 "calc3.y"
                                                                 { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1582 "y.tab.c"
    break;

  case 14:
#line 76 "calc3.y"
                                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1588 "y.tab.c"
    break;

  case 15:
#line 77 "calc3.y"
                                { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1594 "y.tab.c"
    break;

  case 16:
#line 104 "calc3.y"
                                    { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1600 "y.tab.c"
    break;

  case 17:
#line 105 "calc3.y"
                                    { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1606 "y.tab.c"
    break;

  case 18:
#line 106 "calc3.y"
                                    { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1612 "y.tab.c"
    break;

  case 19:
#line 107 "calc3.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1618 "y.tab.c"
    break;

  case 20:
#line 108 "calc3.y"
                                    { (yyval.nPtr) = opr(MINUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1624 "y.tab.c"
    break;

  case 21:
#line 109 "calc3.y"
                                    { (yyval.nPtr) = opr(MUL_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1630 "y.tab.c"
    break;

  case 22:
#line 110 "calc3.y"
                                    { (yyval.nPtr) = opr(DIV_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1636 "y.tab.c"
    break;

  case 23:
#line 111 "calc3.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1642 "y.tab.c"
    break;

  case 24:
#line 112 "calc3.y"
                                    { (yyval.nPtr) = opr(SH_LE_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1648 "y.tab.c"
    break;

  case 25:
#line 113 "calc3.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1654 "y.tab.c"
    break;

  case 26:
#line 114 "calc3.y"
                                    { (yyval.nPtr) = opr(AND_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1660 "y.tab.c"
    break;

  case 27:
#line 115 "calc3.y"
                                    { (yyval.nPtr) = opr(OR_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1666 "y.tab.c"
    break;

  case 28:
#line 116 "calc3.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1672 "y.tab.c"
    break;

  case 29:
#line 117 "calc3.y"
                                    { (yyval.nPtr) = opr('!', 1, (yyvsp[0].nPtr)); }
#line 1678 "y.tab.c"
    break;

  case 30:
#line 118 "calc3.y"
                                    { (yyval.nPtr) = opr('~', 1, (yyvsp[0].nPtr)); }
#line 1684 "y.tab.c"
    break;

  case 31:
#line 119 "calc3.y"
                                    { (yyval.nPtr) = opr(UPLUS, 1, (yyvsp[0].nPtr)); }
#line 1690 "y.tab.c"
    break;

  case 32:
#line 120 "calc3.y"
                                    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1696 "y.tab.c"
    break;

  case 33:
#line 121 "calc3.y"
                                    { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1702 "y.tab.c"
    break;

  case 34:
#line 122 "calc3.y"
                                    { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1708 "y.tab.c"
    break;

  case 35:
#line 123 "calc3.y"
                                    { (yyval.nPtr) = opr('|', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1714 "y.tab.c"
    break;

  case 36:
#line 124 "calc3.y"
                                    { (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1720 "y.tab.c"
    break;

  case 37:
#line 125 "calc3.y"
                                    { (yyval.nPtr) = opr('&', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1726 "y.tab.c"
    break;

  case 38:
#line 126 "calc3.y"
                                    { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1732 "y.tab.c"
    break;

  case 39:
#line 127 "calc3.y"
                                    { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1738 "y.tab.c"
    break;

  case 40:
#line 128 "calc3.y"
                                    { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1744 "y.tab.c"
    break;

  case 41:
#line 129 "calc3.y"
                                    { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1750 "y.tab.c"
    break;

  case 42:
#line 130 "calc3.y"
                                    { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1756 "y.tab.c"
    break;

  case 43:
#line 131 "calc3.y"
                                    { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1762 "y.tab.c"
    break;

  case 44:
#line 132 "calc3.y"
                                    { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1768 "y.tab.c"
    break;

  case 45:
#line 133 "calc3.y"
                                    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1774 "y.tab.c"
    break;

  case 46:
#line 134 "calc3.y"
                                    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1780 "y.tab.c"
    break;

  case 47:
#line 135 "calc3.y"
                                    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1786 "y.tab.c"
    break;

  case 48:
#line 136 "calc3.y"
                                    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1792 "y.tab.c"
    break;

  case 49:
#line 137 "calc3.y"
                                    { (yyval.nPtr) = opr(SHIFT_LEFT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1798 "y.tab.c"
    break;

  case 50:
#line 138 "calc3.y"
                                    { (yyval.nPtr) = opr(SHIFT_RIGHT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1804 "y.tab.c"
    break;

  case 51:
#line 139 "calc3.y"
                                    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1810 "y.tab.c"
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3
    break;

  case 51:
#line 122 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(OR_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

<<<<<<< HEAD
  case 52:
#line 123 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 124 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('!', 1, (yyvsp[0].nPtr)); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 125 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('~', 1, (yyvsp[0].nPtr)); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 126 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 127 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 128 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 129 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('|', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 130 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 131 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('&', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 132 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 133 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 134 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 135 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 136 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 137 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 138 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 139 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 140 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 141 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 142 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;
=======
#line 1814 "y.tab.c"
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3

  case 72:
#line 143 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(SHIFT_LEFT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 144 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(SHIFT_RIGHT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 145 "calc3.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1921 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
<<<<<<< HEAD
#line 148 "calc3.y" /* yacc.c:1906  */
=======
#line 142 "calc3.y"
>>>>>>> c8b6279a429549031ffecac63583fc48166d26e3


nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

nodeType *switchOpr(nodeType* exp, struct switchStatement * ss) {
    nodeType *p;
    int i = 2, casesNo = 0, nops = 2;
    struct switchStatement *tmp = ss;
    // No of operands =         1            +        1        +        3*No of Cases       -       1
    //                  (switch expression)     (No of Cases)           (each Case)             (if default exists)

    while(tmp){
        if(tmp->oper == DEFAULT) nops--;
        tmp = tmp->nxt;
        casesNo++;
        nops += 3;
    }

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = SWITCH;
    p->opr.nops = nops;
    p->opr.op[0] = exp;
    p->opr.op[1] = malloc(sizeof(nodeType));
    p->opr.op[1]->con.value = casesNo;
    while(ss){
        tmp = ss;
        if(ss->oper == DEFAULT){
            p->opr.op[i] = malloc(sizeof(nodeType));
            p->opr.op[i++]->con.value = DEFAULT;
            p->opr.op[i++] = ss->stmnt;
        }
        else{
            p->opr.op[i] = malloc(sizeof(nodeType));
            p->opr.op[i++]->con.value = CASE;
            p->opr.op[i++] = ss->exp;
            p->opr.op[i++] = ss->stmnt;
        }
        ss = ss->nxt;
        free(tmp);
    }
    return p;
}



void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}

struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt){
    struct switchStatement * ret = malloc(sizeof(switchstatement));
    ret->oper = oper;
    ret->stmnt = stmnt;
    ret->nxt = nxt;
    if(oper == CASE){
        ret->exp = exp;
    }
    return ret;
}
/*
x = 1;
switch(x){
    case 0: print 0;
    case 1: print 1;
    case 2: print 2;
    default: print 3;
}

*/
