/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "compiler.h"
#include <string>

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

void yyerror(const std::string& s);
int sym[26];                    /* symbol table */

#line 94 "parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    FLOAT = 259,
    CHAR = 260,
    BOOL = 261,
    VARIABLE = 262,
    WHILE = 263,
    IF = 264,
    PRINT = 265,
    FOR = 266,
    REPEAT = 267,
    UNTIL = 268,
    SWITCH = 269,
    CASE = 270,
    DEFAULT = 271,
    VOID = 272,
    BOOL_TYPE = 273,
    CHAR_TYPE = 274,
    INT_TYPE = 275,
    FLOAT_TYPE = 276,
    CONST = 277,
    RETURN = 278,
    CONTINUE = 279,
    BREAK = 280,
    IFX = 281,
    ELSE = 282,
    PLUS_EQ = 283,
    MINUS_EQ = 284,
    MUL_EQ = 285,
    DIV_EQ = 286,
    MOD_EQ = 287,
    SH_LE_EQ = 288,
    SH_RI_EQ = 289,
    AND_EQ = 290,
    XOR_EQ = 291,
    OR_EQ = 292,
    OR = 293,
    AND = 294,
    GE = 295,
    LE = 296,
    EQ = 297,
    NE = 298,
    SHIFT_LEFT = 299,
    SHIFT_RIGHT = 300,
    UMINUS = 301,
    UPLUS = 302
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT 259
#define CHAR 260
#define BOOL 261
#define VARIABLE 262
#define WHILE 263
#define IF 264
#define PRINT 265
#define FOR 266
#define REPEAT 267
#define UNTIL 268
#define SWITCH 269
#define CASE 270
#define DEFAULT 271
#define VOID 272
#define BOOL_TYPE 273
#define CHAR_TYPE 274
#define INT_TYPE 275
#define FLOAT_TYPE 276
#define CONST 277
#define RETURN 278
#define CONTINUE 279
#define BREAK 280
#define IFX 281
#define ELSE 282
#define PLUS_EQ 283
#define MINUS_EQ 284
#define MUL_EQ 285
#define DIV_EQ 286
#define MOD_EQ 287
#define SH_LE_EQ 288
#define SH_RI_EQ 289
#define AND_EQ 290
#define XOR_EQ 291
#define OR_EQ 292
#define OR 293
#define AND 294
#define GE 295
#define LE 296
#define EQ 297
#define NE 298
#define SHIFT_LEFT 299
#define SHIFT_RIGHT 300
#define UMINUS 301
#define UPLUS 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    int iValue;                         /* integer value */
    double dValue;                      /* double value */
    char cValue;                        /* char value */
    bool bValue;                        /* boolean value */
    char sIndex;                        /* symbol table index */
    nodeType *nPtr;                     /* node pointer */
    switchstatement *swtch;  

#line 250 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   846

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    56,    43,     2,
      62,    63,    54,    52,    66,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    61,
      49,    28,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    41,    65,    59,     2,     2,     2,
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
      25,    26,    27,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    44,    45,    46,    47,    50,
      51,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    66,    67,    71,    72,    73,    74,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    99,   100,   101,
     105,   106,   107,   111,   112,   113,   117,   118,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   194,   195,   196,   197
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT", "CHAR", "BOOL",
  "VARIABLE", "WHILE", "IF", "PRINT", "FOR", "REPEAT", "UNTIL", "SWITCH",
  "CASE", "DEFAULT", "VOID", "BOOL_TYPE", "CHAR_TYPE", "INT_TYPE",
  "FLOAT_TYPE", "CONST", "RETURN", "CONTINUE", "BREAK", "IFX", "ELSE",
  "'='", "PLUS_EQ", "MINUS_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ", "SH_LE_EQ",
  "SH_RI_EQ", "AND_EQ", "XOR_EQ", "OR_EQ", "OR", "AND", "'|'", "'^'",
  "'&'", "GE", "LE", "EQ", "NE", "'>'", "'<'", "SHIFT_LEFT", "SHIFT_RIGHT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "UPLUS", "'~'", "'!'",
  "';'", "'('", "')'", "'{'", "'}'", "','", "':'", "$accept", "program",
  "function", "decl", "stmt", "param_list", "arg_list", "switch_stmt",
  "stmt_list", "const_expr", "expr", "typ", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    61,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   124,    94,    38,   295,   296,   297,   298,    62,    60,
     299,   300,    43,    45,    42,    47,    37,   301,   302,   126,
      33,    59,    40,    41,   123,   125,    44,    58
};
# endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -89,     2,   202,   -89,   -89,   -89,   -89,   -89,    58,   -54,
     -46,   242,   -40,   202,   -17,    48,   -89,   -89,   -89,   -89,
       7,   230,    -1,    24,   242,   242,   242,   242,   -89,   242,
     202,    44,   -89,   517,    99,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   540,
      97,   100,   242,    52,   114,   -89,   563,   -89,   -89,   -89,
     -89,   -89,   -89,   317,   -89,   179,   -89,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   -89,   -19,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   -60,   655,
     342,   367,   -89,    61,   586,   118,    65,   392,    -8,   102,
     -89,   -89,   -89,   -89,   672,   705,   225,   750,   777,   123,
     123,   123,   123,   123,   123,    -5,    -5,    43,    43,   -89,
     -89,   -89,   242,    -8,   -89,   242,   202,   202,   242,   242,
     103,   242,    64,   -89,   -59,   242,   655,   -10,   655,   -89,
     109,   609,   632,   417,    42,   202,    -8,   655,   202,   202,
     242,   242,    73,   105,    71,    75,   -89,   -89,   -89,   -89,
     442,   467,   -89,   -89,   -89,   -89,   -89,   105,   105,   105,
     105,   288,   202,   -89,   202,   202,   -89,   -89,   -89,   492,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   202,   -89,
     -89,   -89,   -89,   689,   721,   736,   764,   790,   295,   295,
     295,   295,   295,   295,    27,    27,   107,   107,   -89,   -89,
     -89,    42,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,     0,     0,   106,   105,   104,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    10,    11,    83,
      84,    82,    81,     0,    36,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     5,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    79,     0,    30,
       0,     0,    13,     0,     0,     0,     0,     0,    29,     7,
      18,   103,    26,    37,    85,    86,    87,    88,    89,    97,
      98,   100,    99,    96,    95,   101,   102,    90,    91,    92,
      93,    94,     0,    29,    69,     0,     0,     0,     0,     0,
       5,     0,     0,    27,     0,     0,     6,     0,    31,    14,
      24,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    28,    16,    25,
       0,     0,    20,    38,    39,    40,    41,     0,     0,     0,
       0,     0,     0,    23,     0,     0,    44,    43,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      22,    21,    63,    45,    46,    47,    48,    49,    57,    58,
      60,    59,    56,    55,    61,    62,    50,    51,    52,    53,
      54,    33,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   -49,   -13,     8,   -89,   -88,   -89,   119,
      -6,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    31,    32,   144,    98,   165,    65,   181,
      33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,   103,     3,   134,   155,    49,   135,   156,    47,   132,
      16,    17,    18,    19,    20,    56,    48,    64,    59,    60,
      61,    62,    50,    63,    54,    16,    17,    18,    19,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      99,   100,   101,   133,   104,    52,   107,    80,    81,    82,
      83,    84,   113,   158,   105,    53,   156,   163,   164,   143,
      57,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   203,
     204,   205,   206,   207,   143,    58,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    82,    83,    84,
       4,     5,     6,     7,     8,    66,    86,   167,   173,   174,
     175,   176,   105,   106,   108,    16,    17,    18,    19,    20,
      46,   109,   138,   149,   150,   140,   146,   141,   154,   148,
     145,   132,   151,   152,   172,   153,   159,   105,   182,   157,
     183,   147,   166,   232,     0,   168,   169,     0,     0,    24,
      25,     0,     0,     0,   170,   171,    26,    27,   177,    29,
     105,   205,   206,   207,   178,   179,     0,   180,     0,   209,
       0,   210,   211,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,     0,   231,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
       0,    24,    25,     4,     5,     6,     7,     8,    26,    27,
      28,    29,     0,    30,   112,     4,     5,     6,     7,     8,
       0,     0,     0,     0,    24,    25,     0,     0,     0,     0,
       0,    26,    27,    28,    29,     0,    30,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    24,    25,     0,     0,     0,     0,     0,    26,
      27,    55,    29,     0,    24,    25,   186,   187,   188,   189,
       0,    26,    27,     0,    29,     0,     0,     0,     0,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   201,   202,   203,   204,   205,
     206,   207,     0,     0,     0,   208,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
     111,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,   136,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
     137,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,   142,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
     162,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,   184,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
     185,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,     0,
       0,     0,     0,     0,     0,   212,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    85,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,   102,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,   110,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,   139,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
     160,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,   161,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207
};

static const yytype_int16 yycheck[] =
{
      13,    50,     0,    63,    63,    11,    66,    66,    62,    28,
      18,    19,    20,    21,    22,    21,    62,    30,    24,    25,
      26,    27,    62,    29,    20,    18,    19,    20,    21,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    62,    50,    62,    52,    52,    53,    54,
      55,    56,    65,    63,    50,     7,    66,    15,    16,   108,
      61,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    52,
      53,    54,    55,    56,   133,    61,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    54,    55,    56,
       3,     4,     5,     6,     7,    61,     7,   156,     3,     4,
       5,     6,   108,    13,    62,    18,    19,    20,    21,    22,
      62,     7,    61,   136,   137,     7,   132,    62,    64,   135,
      28,    28,   138,   139,    61,   141,    27,   133,    67,   145,
      65,   133,   155,   231,    -1,   158,   159,    -1,    -1,    52,
      53,    -1,    -1,    -1,   160,   161,    59,    60,    53,    62,
     156,    54,    55,    56,    59,    60,    -1,    62,    -1,   182,
      -1,   184,   185,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,   208,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    52,    53,     3,     4,     5,     6,     7,    59,    60,
      61,    62,    -1,    64,    65,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    52,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    52,    53,   177,   178,   179,   180,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    67,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,    70,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    14,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    52,    53,    59,    60,    61,    62,
      64,    71,    72,    78,    79,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    62,    62,    62,    78,
      62,    72,    62,     7,    79,    61,    78,    61,    61,    78,
      78,    78,    78,    78,    72,    76,    61,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    61,     7,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    74,    78,
      78,    78,    61,    71,    78,    79,    13,    78,    62,     7,
      61,    63,    65,    72,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    28,    62,    63,    66,    63,    63,    61,    61,
       7,    62,    63,    71,    73,    28,    78,    73,    78,    72,
      72,    78,    78,    78,    64,    63,    66,    78,    63,    27,
      61,    61,    63,    15,    16,    75,    72,    71,    72,    72,
      78,    78,    61,     3,     4,     5,     6,    53,    59,    60,
      62,    77,    67,    65,    63,    63,    77,    77,    77,    77,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    67,    72,
      72,    72,    63,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    72,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     4,     3,     5,     1,
       2,     2,     2,     3,     5,     2,     6,     6,     3,     2,
       7,     9,     9,     7,     5,     7,     3,     1,     3,     0,
       1,     3,     0,     4,     5,     3,     1,     2,     1,     1,
       1,     1,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 62 "parser.y"
                                { exit(0); }
#line 1701 "parser.cpp"
    break;

  case 3:
#line 66 "parser.y"
                                { ex((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr)); }
#line 1707 "parser.cpp"
    break;

  case 5:
#line 71 "parser.y"
                                                          { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1713 "parser.cpp"
    break;

  case 6:
#line 72 "parser.y"
                                                          { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1719 "parser.cpp"
    break;

  case 7:
#line 73 "parser.y"
                                                          { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 1725 "parser.cpp"
    break;

  case 8:
#line 74 "parser.y"
                                                          { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 1731 "parser.cpp"
    break;

  case 9:
#line 78 "parser.y"
                                                                 { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
#line 1737 "parser.cpp"
    break;

  case 10:
#line 79 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1743 "parser.cpp"
    break;

  case 11:
#line 80 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1749 "parser.cpp"
    break;

  case 12:
#line 81 "parser.y"
                                                                 { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1755 "parser.cpp"
    break;

  case 13:
#line 82 "parser.y"
                                                                 { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1761 "parser.cpp"
    break;

  case 14:
#line 83 "parser.y"
                                                                 { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1767 "parser.cpp"
    break;

  case 15:
#line 84 "parser.y"
                                                                 { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1773 "parser.cpp"
    break;

  case 16:
#line 85 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1779 "parser.cpp"
    break;

  case 17:
#line 86 "parser.y"
                                                                  { (yyval.nPtr) = NULL; }
#line 1785 "parser.cpp"
    break;

  case 18:
#line 87 "parser.y"
                                                                 { (yyval.nPtr) = opr(RETURN, 1, (yyvsp[-1].nPtr)); }
#line 1791 "parser.cpp"
    break;

  case 19:
#line 88 "parser.y"
                                                                 { (yyval.nPtr) = opr(RETURN, 0); }
#line 1797 "parser.cpp"
    break;

  case 20:
#line 89 "parser.y"
                                                                 { (yyval.nPtr) = opr(REPEAT, 2, (yyvsp[-5].nPtr), (yyvsp[-2].nPtr)); }
#line 1803 "parser.cpp"
    break;

  case 21:
#line 90 "parser.y"
                                                                 { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1809 "parser.cpp"
    break;

  case 22:
#line 91 "parser.y"
                                                                 { (yyval.nPtr) = opr(FOR, 4, (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1815 "parser.cpp"
    break;

  case 23:
#line 92 "parser.y"
                                                                 { (yyval.nPtr) = switchOpr( (yyvsp[-4].nPtr), (yyvsp[-1].swtch)); }
#line 1821 "parser.cpp"
    break;

  case 24:
#line 93 "parser.y"
                                                                 { (yyval.nPtr) = opr(IF, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1827 "parser.cpp"
    break;

  case 25:
#line 94 "parser.y"
                                                                 { (yyval.nPtr) = opr(IF, 3, (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1833 "parser.cpp"
    break;

  case 26:
#line 95 "parser.y"
                                                                 { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1839 "parser.cpp"
    break;

  case 27:
#line 99 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1845 "parser.cpp"
    break;

  case 28:
#line 100 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1851 "parser.cpp"
    break;

  case 29:
#line 101 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1857 "parser.cpp"
    break;

  case 30:
#line 105 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1863 "parser.cpp"
    break;

  case 31:
#line 106 "parser.y"
                                                           { (yyval.nPtr) = NULL; }
#line 1869 "parser.cpp"
    break;

  case 32:
#line 107 "parser.y"
                                                                 { (yyval.nPtr) = NULL; }
#line 1875 "parser.cpp"
    break;

  case 33:
#line 111 "parser.y"
                                                                       { (yyval.swtch) = conc(CASE, (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1881 "parser.cpp"
    break;

  case 34:
#line 112 "parser.y"
                                                                       { (yyval.swtch) = conc(CASE, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr), (yyvsp[0].swtch));}
#line 1887 "parser.cpp"
    break;

  case 35:
#line 113 "parser.y"
                                                                 { (yyval.swtch) = conc(DEFAULT, NULL, (yyvsp[0].nPtr), NULL);}
#line 1893 "parser.cpp"
    break;

  case 36:
#line 117 "parser.y"
                                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1899 "parser.cpp"
    break;

  case 37:
#line 118 "parser.y"
                                { (yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1905 "parser.cpp"
    break;

  case 38:
#line 122 "parser.y"
                                            { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 1911 "parser.cpp"
    break;

  case 39:
#line 123 "parser.y"
                                            { (yyval.nPtr) = con((yyvsp[0].dValue)); }
#line 1917 "parser.cpp"
    break;

  case 40:
#line 124 "parser.y"
                                            { (yyval.nPtr) = con((yyvsp[0].cValue)); }
#line 1923 "parser.cpp"
    break;

  case 41:
#line 125 "parser.y"
                                            { (yyval.nPtr) = con((yyvsp[0].bValue)); }
#line 1929 "parser.cpp"
    break;

  case 42:
#line 126 "parser.y"
                                            { (yyval.nPtr) = opr('!', 1, (yyvsp[0].nPtr)); }
#line 1935 "parser.cpp"
    break;

  case 43:
#line 127 "parser.y"
                                            { (yyval.nPtr) = opr('~', 1, (yyvsp[0].nPtr)); }
#line 1941 "parser.cpp"
    break;

  case 44:
#line 128 "parser.y"
                                            { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 1947 "parser.cpp"
    break;

  case 45:
#line 129 "parser.y"
                                            { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1953 "parser.cpp"
    break;

  case 46:
#line 130 "parser.y"
                                            { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1959 "parser.cpp"
    break;

  case 47:
#line 131 "parser.y"
                                            { (yyval.nPtr) = opr('|', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1965 "parser.cpp"
    break;

  case 48:
#line 132 "parser.y"
                                            { (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1971 "parser.cpp"
    break;

  case 49:
#line 133 "parser.y"
                                            { (yyval.nPtr) = opr('&', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1977 "parser.cpp"
    break;

  case 50:
#line 134 "parser.y"
                                            { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1983 "parser.cpp"
    break;

  case 51:
#line 135 "parser.y"
                                            { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1989 "parser.cpp"
    break;

  case 52:
#line 136 "parser.y"
                                            { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1995 "parser.cpp"
    break;

  case 53:
#line 137 "parser.y"
                                            { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2001 "parser.cpp"
    break;

  case 54:
#line 138 "parser.y"
                                            { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2007 "parser.cpp"
    break;

  case 55:
#line 139 "parser.y"
                                            { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2013 "parser.cpp"
    break;

  case 56:
#line 140 "parser.y"
                                            { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2019 "parser.cpp"
    break;

  case 57:
#line 141 "parser.y"
                                            { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2025 "parser.cpp"
    break;

  case 58:
#line 142 "parser.y"
                                            { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2031 "parser.cpp"
    break;

  case 59:
#line 143 "parser.y"
                                            { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2037 "parser.cpp"
    break;

  case 60:
#line 144 "parser.y"
                                            { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2043 "parser.cpp"
    break;

  case 61:
#line 145 "parser.y"
                                                { (yyval.nPtr) = opr(SHIFT_LEFT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2049 "parser.cpp"
    break;

  case 62:
#line 146 "parser.y"
                                                { (yyval.nPtr) = opr(SHIFT_RIGHT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2055 "parser.cpp"
    break;

  case 63:
#line 147 "parser.y"
                                          { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 2061 "parser.cpp"
    break;

  case 64:
#line 151 "parser.y"
                                    { (yyval.nPtr) = con((yyvsp[0].iValue)); }
#line 2067 "parser.cpp"
    break;

  case 65:
#line 152 "parser.y"
                                    { (yyval.nPtr) = con((yyvsp[0].dValue)); }
#line 2073 "parser.cpp"
    break;

  case 66:
#line 153 "parser.y"
                                    { (yyval.nPtr) = con((yyvsp[0].cValue)); }
#line 2079 "parser.cpp"
    break;

  case 67:
#line 154 "parser.y"
                                    { (yyval.nPtr) = con((yyvsp[0].bValue)); }
#line 2085 "parser.cpp"
    break;

  case 68:
#line 155 "parser.y"
                                    { (yyval.nPtr) = id((yyvsp[0].sIndex)); }
#line 2091 "parser.cpp"
    break;

  case 69:
#line 156 "parser.y"
                                    { (yyval.nPtr) = NULL; }
#line 2097 "parser.cpp"
    break;

  case 70:
#line 157 "parser.y"
                                    { (yyval.nPtr) = opr('=', 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2103 "parser.cpp"
    break;

  case 71:
#line 158 "parser.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2109 "parser.cpp"
    break;

  case 72:
#line 159 "parser.y"
                                    { (yyval.nPtr) = opr(MINUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2115 "parser.cpp"
    break;

  case 73:
#line 160 "parser.y"
                                    { (yyval.nPtr) = opr(MUL_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2121 "parser.cpp"
    break;

  case 74:
#line 161 "parser.y"
                                    { (yyval.nPtr) = opr(DIV_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2127 "parser.cpp"
    break;

  case 75:
#line 162 "parser.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2133 "parser.cpp"
    break;

  case 76:
#line 163 "parser.y"
                                    { (yyval.nPtr) = opr(SH_LE_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2139 "parser.cpp"
    break;

  case 77:
#line 164 "parser.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2145 "parser.cpp"
    break;

  case 78:
#line 165 "parser.y"
                                    { (yyval.nPtr) = opr(AND_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2151 "parser.cpp"
    break;

  case 79:
#line 166 "parser.y"
                                    { (yyval.nPtr) = opr(OR_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2157 "parser.cpp"
    break;

  case 80:
#line 167 "parser.y"
                                    { (yyval.nPtr) = opr(PLUS_EQ, 2, id((yyvsp[-2].sIndex)), (yyvsp[0].nPtr)); }
#line 2163 "parser.cpp"
    break;

  case 81:
#line 168 "parser.y"
                                    { (yyval.nPtr) = opr('!', 1, (yyvsp[0].nPtr)); }
#line 2169 "parser.cpp"
    break;

  case 82:
#line 169 "parser.y"
                                    { (yyval.nPtr) = opr('~', 1, (yyvsp[0].nPtr)); }
#line 2175 "parser.cpp"
    break;

  case 83:
#line 170 "parser.y"
                                    { (yyval.nPtr) = opr(UPLUS, 1, (yyvsp[0].nPtr)); }
#line 2181 "parser.cpp"
    break;

  case 84:
#line 171 "parser.y"
                                    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[0].nPtr)); }
#line 2187 "parser.cpp"
    break;

  case 85:
#line 172 "parser.y"
                                    { (yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2193 "parser.cpp"
    break;

  case 86:
#line 173 "parser.y"
                                    { (yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2199 "parser.cpp"
    break;

  case 87:
#line 174 "parser.y"
                                    { (yyval.nPtr) = opr('|', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2205 "parser.cpp"
    break;

  case 88:
#line 175 "parser.y"
                                    { (yyval.nPtr) = opr('^', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2211 "parser.cpp"
    break;

  case 89:
#line 176 "parser.y"
                                    { (yyval.nPtr) = opr('&', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2217 "parser.cpp"
    break;

  case 90:
#line 177 "parser.y"
                                    { (yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2223 "parser.cpp"
    break;

  case 91:
#line 178 "parser.y"
                                    { (yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2229 "parser.cpp"
    break;

  case 92:
#line 179 "parser.y"
                                    { (yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2235 "parser.cpp"
    break;

  case 93:
#line 180 "parser.y"
                                    { (yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2241 "parser.cpp"
    break;

  case 94:
#line 181 "parser.y"
                                    { (yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2247 "parser.cpp"
    break;

  case 95:
#line 182 "parser.y"
                                    { (yyval.nPtr) = opr('<', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2253 "parser.cpp"
    break;

  case 96:
#line 183 "parser.y"
                                    { (yyval.nPtr) = opr('>', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2259 "parser.cpp"
    break;

  case 97:
#line 184 "parser.y"
                                    { (yyval.nPtr) = opr(GE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2265 "parser.cpp"
    break;

  case 98:
#line 185 "parser.y"
                                    { (yyval.nPtr) = opr(LE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2271 "parser.cpp"
    break;

  case 99:
#line 186 "parser.y"
                                    { (yyval.nPtr) = opr(NE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2277 "parser.cpp"
    break;

  case 100:
#line 187 "parser.y"
                                    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2283 "parser.cpp"
    break;

  case 101:
#line 188 "parser.y"
                                    { (yyval.nPtr) = opr(SHIFT_LEFT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2289 "parser.cpp"
    break;

  case 102:
#line 189 "parser.y"
                                    { (yyval.nPtr) = opr(SHIFT_RIGHT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 2295 "parser.cpp"
    break;

  case 103:
#line 190 "parser.y"
                                    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 2301 "parser.cpp"
    break;


#line 2305 "parser.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 198 "parser.y"


nodeType *con(int value) {
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p = new nodeType();


    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p = new nodeType();
    int i;


    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    p->opr.op = new nodeType* [nops];
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

nodeType *switchOpr(nodeType* exp, struct switchStatement * ss) {
    nodeType *p = new nodeType();
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

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = SWITCH;
    p->opr.nops = nops;
    p->opr.op = new nodeType* [nops];
    p->opr.op[0] = exp;
    p->opr.op[1] = new nodeType();
    p->opr.op[1]->con.value = casesNo;
    while(ss){
        tmp = ss;
        if(ss->oper == DEFAULT){
            p->opr.op[i] = new nodeType();
            p->opr.op[i++]->con.value = DEFAULT;
            p->opr.op[i++] = ss->stmnt;
        }
        else{
            p->opr.op[i] = new nodeType();
            p->opr.op[i++]->con.value = CASE;
            p->opr.op[i++] = ss->exp;
            p->opr.op[i++] = ss->stmnt;
        }
        ss = ss->nxt;
        delete tmp;
    }
    return p;
}



void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
        delete[] p->opr.op;
    }
    delete p;
}

void yyerror(const std::string& s) {
    fprintf(stdout, "%s\n", s.c_str());
}

int main(void) {
    yyparse();
    return 0;
}

struct switchStatement * conc(int oper, nodeType * exp, nodeType * stmnt, struct switchStatement * nxt){
    struct switchStatement * ret = new switchstatement();
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
