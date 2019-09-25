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
#line 21 "go.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "tree.h"
#include "utils.h"
#include "rules.h"

// #define YYDEBUG 1
// int yydebug=1;

// TODO: Remove all warnings (useless rule, etc)

struct tree* ast_root;

int yylex (void);
// void yyerror (char const *);

int yylast;
int yyprev;

// for location tracking
// typedef struct YYLTYPE
// {
// 	int first_line;
// 	int first_column;
// 	int last_line;
// 	int last_column;
// } YYLTYPE;

enum ErrorCode error_code;
char* yyfilename;
int yylineno;
char* yytext;

int ruleno = 0;

void yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
	fprintf(stderr, "syntax error: unexpected '%s' token in file %s, line %d\n",
	   yytext,yyfilename, yylineno);
	exit(2);
}



#line 115 "go.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "go.tab.h".  */
#ifndef YY_YY_GO_TAB_H_INCLUDED
# define YY_YY_GO_TAB_H_INCLUDED
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
    END = 0,
    LLITERAL = 258,
    LASOP = 259,
    LCOLAS = 260,
    LBREAK = 261,
    LCASE = 262,
    LCHAN = 263,
    LCONST = 264,
    LCONTINUE = 265,
    LDDD = 266,
    LDEFAULT = 267,
    LDEFER = 268,
    LELSE = 269,
    LFALL = 270,
    LFOR = 271,
    LFUNC = 272,
    LGO = 273,
    LGOTO = 274,
    LIF = 275,
    LIMPORT = 276,
    LINTERFACE = 277,
    LMAP = 278,
    LNAME = 279,
    LPACKAGE = 280,
    LRANGE = 281,
    LRETURN = 282,
    LSELECT = 283,
    LSTRUCT = 284,
    LSWITCH = 285,
    LTYPE = 286,
    LVAR = 287,
    LANDAND = 288,
    LANDNOT = 289,
    LBODY = 290,
    LCOMM = 291,
    LDEC = 292,
    LEQ = 293,
    LGE = 294,
    LGT = 295,
    LIGNORE = 296,
    LINC = 297,
    LLE = 298,
    LLSH = 299,
    LLT = 300,
    LNE = 301,
    LOROR = 302,
    LRSH = 303,
    NotPackage = 304,
    NotParen = 305,
    PreferToRightParen = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "go.y" /* yacc.c:355  */

	struct tree* ast;
	struct token* t;

#line 213 "go.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "go.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  426

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    55,    56,     2,
      67,    68,    53,    49,    61,    50,    63,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    60,
       2,    64,     2,    59,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    52,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    51,    58,    71,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    65,    66,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   176,   182,   194,   198,   208,   215,   222,
     232,   239,   246,   250,   260,   267,   274,   284,   295,   299,
     312,   317,   321,   325,   330,   337,   344,   351,   358,   365,
     372,   379,   386,   393,   400,   410,   420,   427,   434,   444,
     451,   461,   465,   472,   479,   488,   498,   502,   509,   516,
     523,   530,   540,   551,   562,   569,   576,   586,   597,   601,
     612,   625,   636,   640,   650,   654,   667,   671,   678,   685,
     692,   699,   706,   713,   720,   727,   734,   741,   748,   755,
     762,   769,   776,   783,   790,   797,   805,   815,   819,   826,
     833,   840,   847,   854,   862,   869,   883,   890,   897,   907,
     914,   918,   925,   932,   939,   946,   953,   960,   964,   971,
     978,   985,   994,  1001,  1010,  1020,  1024,  1034,  1038,  1048,
    1052,  1062,  1066,  1076,  1084,  1091,  1106,  1113,  1120,  1127,
    1131,  1141,  1148,  1158,  1168,  1184,  1193,  1203,  1207,  1211,
    1215,  1219,  1229,  1233,  1237,  1247,  1251,  1258,  1265,  1269,
    1273,  1277,  1284,  1288,  1298,  1305,  1312,  1319,  1326,  1333,
    1340,  1354,  1364,  1371,  1382,  1392,  1396,  1403,  1407,  1411,
    1418,  1425,  1432,  1447,  1451,  1461,  1465,  1475,  1479,  1489,
    1493,  1503,  1507,  1517,  1524,  1531,  1538,  1545,  1552,  1562,
    1569,  1579,  1589,  1593,  1600,  1607,  1614,  1618,  1628,  1632,
    1645,  1649,  1653,  1657,  1661,  1668,  1673,  1678,  1682,  1690,
    1697,  1707,  1711,  1721,  1725,  1735,  1739,  1749,  1753,  1763,
    1767,  1780,  1784,  1788,  1795,  1805,  1809,  1822,  1826,  1833,
    1837,  1844,  1848,  1855,  1859,  1866,  1870,  1878,  1882
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "LLITERAL", "LASOP", "LCOLAS",
  "LBREAK", "LCASE", "LCHAN", "LCONST", "LCONTINUE", "LDDD", "LDEFAULT",
  "LDEFER", "LELSE", "LFALL", "LFOR", "LFUNC", "LGO", "LGOTO", "LIF",
  "LIMPORT", "LINTERFACE", "LMAP", "LNAME", "LPACKAGE", "LRANGE",
  "LRETURN", "LSELECT", "LSTRUCT", "LSWITCH", "LTYPE", "LVAR", "LANDAND",
  "LANDNOT", "LBODY", "LCOMM", "LDEC", "LEQ", "LGE", "LGT", "LIGNORE",
  "LINC", "LLE", "LLSH", "LLT", "LNE", "LOROR", "LRSH", "'+'", "'-'",
  "'|'", "'^'", "'*'", "'/'", "'%'", "'&'", "'{'", "'}'", "'?'", "';'",
  "','", "'`'", "'.'", "'='", "NotPackage", "NotParen", "'('", "')'",
  "PreferToRightParen", "'!'", "'~'", "'['", "']'", "':'", "'@'",
  "$accept", "file", "package", "imports", "import", "import_stmt",
  "import_stmt_list", "import_here", "import_package", "import_safety",
  "xdcl", "common_dcl", "lconst", "vardcl", "constdcl", "constdcl1",
  "typedclname", "typedcl", "simple_stmt", "compound_stmt", "loop_body",
  "for_header", "for_body", "for_stmt", "if_header", "if_stmt", "elseif",
  "elseif_list", "else", "expr", "uexpr", "pseudocall", "pexpr_no_paren",
  "start_complit", "keyval", "bare_complitexpr", "complitexpr", "pexpr",
  "expr_or_type", "name_or_type", "lbrace", "new_name", "dcl_name", "sym",
  "hidden_importsym", "name", "labelname", "dotdotdot", "ntype",
  "non_expr_type", "convtype", "comptype", "fnret_type", "dotname",
  "othertype", "ptrtype", "structtype", "xfndcl", "fndcl", "fntype",
  "fnbody", "fnres", "fnlitdcl", "fnliteral", "xdcl_list", "vardcl_list",
  "constdcl_list", "typedcl_list", "structdcl_list", "structdcl",
  "packname", "embed", "arg_type", "arg_type_list",
  "oarg_type_list_ocomma", "stmt", "non_dcl_stmt", "stmt_list",
  "new_name_list", "dcl_name_list", "expr_list", "expr_or_type_list",
  "keyval_list", "braced_keyval_list", "osemi", "ocomma", "oexpr",
  "oexpr_list", "osimple_stmt", "oliteral", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    43,
      45,   124,    94,    42,    47,    37,    38,   123,   125,    63,
      59,    44,    96,    46,    61,   304,   305,    40,    41,   306,
      33,   126,    91,    93,    58,    64
};
# endif

#define YYPACT_NINF -320

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-320)))

#define YYTABLE_NINF -218

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      51,    32,    71,  -320,  -320,  -320,    77,    33,  -320,  -320,
     116,    45,  -320,    46,    88,   586,    65,  -320,   144,    87,
    -320,   129,   156,  -320,  -320,  -320,  -320,   928,   133,   346,
     928,    94,   928,    27,   137,   177,   928,   928,   928,   928,
     928,   928,   965,   928,   928,   743,   121,  -320,   233,  -320,
    -320,  -320,   515,  -320,  -320,   113,   110,  -320,   102,  -320,
     114,   126,    27,   127,  -320,  -320,   135,    37,  -320,  -320,
      31,  -320,  -320,  -320,  -320,  -320,   143,   229,  -320,  -320,
     187,  -320,   220,  -320,  -320,   199,   436,   195,   206,     6,
     110,   220,   204,   647,  1149,   207,  -320,  -320,  -320,   246,
     181,   647,  -320,  -320,   242,  -320,  -320,  -320,   996,  -320,
    -320,  -320,  -320,  -320,  -320,   965,  1149,   201,  -320,   117,
      43,  -320,  -320,   194,  1149,   200,  -320,   278,  -320,  1005,
     928,   928,   928,   928,  -320,   928,   928,   928,  -320,   928,
     928,   928,   928,   928,   928,   928,   928,   928,   928,   928,
     928,   928,   928,  -320,   257,   780,   928,   681,   928,  -320,
    -320,   681,   928,   928,   928,   120,   211,   250,   436,   681,
    -320,   928,   647,   647,   647,  -320,   436,   219,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,   227,   221,   436,   681,  -320,
    -320,   928,   224,    56,     0,  -320,    22,  -320,  -320,   231,
    -320,  -320,   311,  1022,  -320,  -320,   249,  -320,  -320,  -320,
     255,    32,   928,   254,  -320,   262,   647,   647,  -320,   260,
     928,   258,  1149,  1220,  -320,  1173,   480,   480,   480,   480,
    -320,   480,   480,  1197,  -320,   323,   323,   323,   323,  -320,
    -320,  -320,  -320,   817,   854,  -320,  -320,  -320,    12,  1094,
     261,  -320,   681,  -320,  -320,  -320,  -320,  1125,   817,  -320,
      19,   207,  1149,   207,  -320,  -320,  -320,   274,   271,    62,
     280,  -320,  -320,   275,  -320,  -320,    32,   436,  -320,   752,
     277,    80,   328,  -320,   647,    32,   284,   324,   311,   324,
     282,   218,   294,  -320,  -320,    32,   311,    32,   286,    32,
     287,  -320,   207,   928,  -320,  -320,  -320,    32,   288,   207,
     928,  -320,  1062,  -320,  -320,   297,   301,   293,   298,   303,
     965,   300,  -320,   928,   151,  -320,   304,   322,  -320,   681,
    -320,   752,  -320,   928,  -320,  -320,  -320,   436,   295,  -320,
    -320,  -320,  -320,  -320,  -320,   752,  -320,    49,  -320,  -320,
    -320,  -320,   313,  -320,   315,   311,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,   207,   817,  -320,  -320,   325,  1005,
    -320,   207,   817,   891,   817,  -320,  -320,  -320,  -320,   316,
    -320,  -320,   -13,  -320,  -320,  -320,  -320,  -320,   319,   436,
    -320,   928,  -320,   311,   311,  -320,   332,    32,   326,   258,
     333,  -320,  1149,  -320,  -320,  -320,  -320,  -320,   928,  -320,
     327,   220,  -320,  -320,  -320,  -320,  -320,  -320,   817,   329,
     752,  -320,   340,  -320,  -320,  -320
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     5,   128,   130,     0,     0,   129,     1,
     173,     0,     4,     0,     0,     0,     0,    14,     0,     0,
       7,    11,     0,     6,    24,    99,    35,   235,     0,     0,
     235,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,     0,    21,     0,   205,
     206,   207,    46,    66,   107,   119,    87,   134,   133,   100,
       0,     0,     0,   147,   157,    22,   170,     0,   112,    23,
       0,   131,   132,    16,     9,    12,   227,     0,    10,    15,
       0,   236,     0,    57,   133,    55,   198,     0,   165,   107,
       0,     0,    58,     0,   217,   234,   210,   124,   125,     0,
       0,     0,    32,    44,     0,    25,   215,   127,     0,    95,
      90,    91,    94,    88,    89,     0,   121,     0,   122,   143,
     142,    92,    93,     0,   232,     0,   174,     0,    28,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,   231,     0,     0,   113,
     172,     0,     0,     0,     0,   228,     0,    18,   198,     0,
      56,   235,   135,     0,     0,   192,   133,   152,   195,   123,
     140,   138,   139,   137,   196,   229,     0,   198,     0,   161,
      62,   235,     0,   128,     0,   160,     0,   213,   126,   227,
     181,   191,   237,     0,    34,   179,   227,    45,    27,   175,
     227,     0,     0,    36,   144,   120,     0,     0,    31,   227,
       0,     0,    47,    68,    83,    86,    69,    73,    74,    72,
      84,    71,    70,    67,    85,    75,    76,    77,    78,    79,
      80,    81,    82,   225,     0,   101,    96,   219,   229,   232,
       0,   204,     0,   202,   201,   208,   203,   229,   225,   211,
       0,    49,   218,    48,    13,     8,    19,     0,     0,     0,
       0,   136,   158,     0,   193,   194,     0,   230,   199,   167,
       0,     0,    64,    59,     0,     0,   189,     0,   237,     0,
       0,   228,     0,   238,   184,     0,   237,   228,     0,   228,
       0,   216,    38,     0,   113,   155,   154,   228,     0,    40,
       0,   113,   115,   221,   222,   229,     0,     0,     0,   229,
     230,     0,   104,   231,     0,   230,     0,     0,   171,     0,
      17,   167,    53,   235,   141,   153,   197,   198,   133,   168,
     151,   149,   150,   148,   164,   167,   166,     0,    63,    60,
     156,   190,     0,   186,     0,   237,   182,   159,   214,   183,
     180,    33,   176,    26,    37,   225,    41,   177,   227,    43,
      29,    39,   225,     0,   230,   226,   110,   103,   102,     0,
     220,    97,     0,    52,   108,   109,   212,    54,     0,   198,
     162,   235,    65,   237,   237,   185,     0,   228,     0,    42,
       0,   113,   117,   114,   223,   224,    98,   105,   231,   169,
       0,     0,   188,   187,   111,   178,    30,   116,   225,     0,
     167,    61,     0,   106,   163,   118
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -320,  -320,  -320,  -320,  -320,    -2,  -320,  -320,  -320,  -320,
    -320,   385,  -320,   -93,    -9,    11,  -320,   -90,   -26,    63,
     -88,  -320,  -320,  -320,    18,  -320,  -320,  -320,  -320,    83,
      14,   383,  -320,  -153,    41,    42,  -320,   388,  -142,   243,
       1,   -74,   209,    -1,  -320,   306,  -320,   247,   -86,   307,
    -320,  -320,  -320,  -249,   157,  -248,  -320,  -320,  -320,   296,
    -320,  -319,  -320,  -320,  -320,  -320,  -320,  -320,  -320,   136,
    -320,  -154,   147,  -320,  -152,  -138,   411,  -140,  -320,   -46,
     -23,  -320,  -320,  -238,  -178,  -183,  -148,  -320,   -22,  -251
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    76,    21,    78,   267,
      46,   253,    48,   105,   366,   367,   101,   102,    49,   254,
     170,    82,    83,    50,    91,    51,   348,   282,   349,    52,
      53,    54,    55,   243,   313,   314,   403,    56,   117,   175,
      99,    57,   106,    84,     8,    59,    60,   178,   179,   118,
      61,    62,   339,   180,    63,   182,    64,    65,    88,    66,
     189,   344,    67,    68,    15,   210,   368,   206,   199,   200,
     201,   202,   184,   185,   186,   259,   256,   260,   203,   108,
      70,   248,   315,   316,   166,   278,   125,    96,    92,   294
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    81,   129,   190,    81,    85,   258,   192,   250,    95,
     205,   209,    22,   247,    58,   207,   268,    75,    22,   255,
     327,   292,   213,   319,   286,   197,   390,    87,   298,   269,
     340,   342,   300,   103,   107,   280,   162,   353,   160,   128,
     288,   308,   290,   221,  -170,   359,   286,   107,   281,    17,
     109,   110,   111,   112,   113,   114,     4,   121,   122,  -189,
     407,   408,    97,   159,  -209,   321,  -209,   287,   161,   391,
       4,     9,    97,   320,   326,   289,     1,   328,  -170,   329,
      11,   129,   340,   342,    98,   176,   271,   272,   273,    71,
      17,     5,   163,    12,    98,   164,   340,   342,   198,   103,
    -170,   424,   318,   107,   395,     5,   252,     6,    16,    18,
    -145,     4,   324,    19,  -189,    94,  -189,   296,   219,   285,
     332,     6,   329,    17,    72,   116,   107,   396,   124,   113,
     305,   306,   375,   352,   400,   354,   379,    13,   346,   261,
     329,   263,   412,   413,     4,    81,     5,    73,    23,   270,
      18,   365,  -147,   245,    77,    74,    58,     4,   372,    79,
      58,     4,     6,   264,    22,    81,    93,   176,    58,   283,
     153,   340,   342,   154,  -147,   382,  -126,   155,   380,     5,
     422,   126,   156,    18,  -146,   388,   176,    58,   157,   302,
     398,   386,     5,   158,  -146,     6,     5,   309,   350,   119,
      86,     4,  -145,   165,   100,     4,   362,   360,     6,   383,
     107,   329,     6,   222,   223,   224,   225,   197,   226,   227,
     228,   358,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     5,   410,   116,   249,
       5,   257,   193,   181,   104,    94,   262,    94,   418,   204,
     181,    58,     6,   167,   168,   169,     6,     4,   181,   171,
     419,   369,   187,   188,   191,   181,     4,   216,   163,   215,
     193,   194,   119,   217,   266,   335,   176,     5,   338,   265,
     364,     4,   276,   399,   351,   196,   181,   371,   277,   279,
     198,   291,     5,     6,   198,    94,   103,   284,   107,   194,
     127,     5,     4,    94,   195,     5,   107,    81,     6,   297,
     208,   387,   119,   196,   293,   299,     5,     6,   303,   304,
     307,     6,   310,   421,   244,   181,   312,   116,    58,   181,
     181,   181,     6,   181,   330,   323,   176,     5,   120,   331,
     333,   312,   347,   334,   181,   345,   218,   285,   286,    25,
     355,   369,   357,     6,   361,   363,   370,   132,   374,   376,
     181,   377,   389,    80,   325,    81,   378,   140,   381,    31,
       4,   144,   384,   181,   181,    33,   149,   150,   151,   152,
     385,   393,   183,   394,   406,   397,    94,   409,   176,   183,
     414,   417,   177,    94,   416,   420,   107,   183,   425,   177,
      47,   119,   423,   116,   183,     5,   124,   177,   415,   411,
     392,   120,    89,    42,   177,   404,   405,    90,    45,   274,
     301,     6,   214,   275,   336,   183,    69,   356,     0,     0,
       0,     0,     0,     0,   181,   177,   341,     0,     0,     0,
       0,   181,     0,     0,     0,     0,     0,   172,   312,     0,
       0,   120,     0,    80,     0,   312,   402,   312,     0,    31,
       4,     0,     0,     0,   183,    33,     0,     0,   183,   183,
     183,     0,   183,     0,   177,     0,     0,   119,   177,   177,
     177,     0,   177,   183,     0,     0,     0,     0,   341,   173,
       0,   124,     0,   177,   181,     5,     0,     0,     0,   183,
       0,   312,   341,   174,     0,     0,     0,     0,    45,   177,
       0,     6,   183,   183,   132,     0,     0,     0,     0,   130,
    -217,     0,   177,   177,   140,     0,   181,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     120,     0,     0,     0,     0,     0,   181,     0,   131,   132,
       0,   133,   134,   135,   136,   137,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   183,     0,   343,  -217,   341,     0,  -217,
     183,     0,     0,   177,     0,   177,    -2,    24,     0,    25,
     177,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,    27,    28,    29,     0,    30,     0,     0,    31,
       4,     0,     0,    32,     0,    33,   120,    34,    35,     0,
       0,     0,    36,     0,     0,     0,     0,   343,     0,     0,
       0,     0,     0,   183,     0,    37,    38,   177,    39,    40,
       0,   343,    41,   177,     0,     5,   -20,     0,     0,     0,
       0,   177,     0,    42,     0,     0,    43,    44,    45,     0,
       0,     6,     0,     0,    80,   183,     0,     0,     0,     0,
      31,     4,     0,     0,     0,   177,    33,     0,     0,     0,
       0,     0,   251,     0,    25,   183,     0,     0,     0,     0,
      26,     0,     0,     0,     0,   177,     0,    27,    80,    29,
     173,    30,     0,     0,    31,     4,     5,     0,    32,     0,
      33,     0,    34,    35,   174,     0,   343,    36,     0,    45,
       0,     0,     6,     0,     0,     0,   177,     0,     0,     0,
      37,    38,     0,    39,    40,     0,     0,    41,   252,  -200,
       5,  -200,     0,     0,     0,     0,    25,     0,    42,     0,
       0,    43,    44,    45,   123,     0,     6,     0,     0,     0,
      80,     0,     0,     0,     0,     0,    31,     4,     0,    80,
       0,     0,    33,     0,     0,    31,     4,     0,     0,    36,
       0,    33,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    38,     0,    39,    40,    80,     0,    41,
       0,     0,     5,    31,     4,   173,     0,     0,     0,    33,
      42,     5,     0,    43,    44,    45,    36,     0,     6,   337,
      25,     0,     0,     0,    45,     0,     0,     6,     0,    37,
      38,     0,    39,   115,    80,     0,    41,     0,     0,     5,
      31,     4,     0,     0,     0,     0,    33,    42,   246,     0,
      43,    44,    45,    36,     0,     6,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,     0,    39,
      40,    80,     0,    41,   311,     0,     5,    31,     4,     0,
       0,     0,     0,    33,    42,   317,     0,    43,    44,    45,
      36,     0,     6,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    38,     0,    39,   115,    80,     0,
      41,     0,     0,     5,    31,     4,     0,     0,     0,     0,
      33,    42,     0,     0,    43,    44,    45,    36,     0,     6,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    38,     0,    39,    40,    80,     0,    41,   401,     0,
       5,    31,     4,     0,     0,     0,     0,    33,    42,     0,
       0,    43,    44,    45,    36,     0,     6,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    38,     0,
      39,    40,    80,     0,    41,     0,     0,     5,    31,     4,
       0,     0,     0,     0,    33,    42,     0,     0,    43,    44,
      45,    36,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    37,    38,     0,    39,   115,    31,
       4,    41,    80,     0,     5,    33,     0,     0,    31,     4,
       0,     0,    42,     0,    33,    43,    44,    45,     0,    80,
       6,     0,     0,     0,     0,    31,     4,     0,     0,   173,
       0,    33,     0,     0,     0,     5,     0,   211,   173,     0,
     212,     0,     0,   174,     5,     0,   211,     0,    45,   220,
       0,     6,   174,     0,     0,   173,     0,    45,     0,     0,
       6,     5,     0,   295,     0,     0,     0,     0,     0,   174,
       0,     0,     0,     0,    45,   131,   132,     6,   133,     0,
     135,   136,   137,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,     0,
     133,     0,   135,   136,   137,     0,   373,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,   131,   132,
       0,   133,     0,   135,   136,   137,     0,   322,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   131,   132,     0,   133,   325,   135,   136,   137,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   131,   132,     0,     0,
       0,   135,   136,   137,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     131,   132,     0,     0,     0,   135,   136,   137,     0,     0,
     139,   140,   141,   142,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   132,     0,     0,     0,   135,   136,
     137,     0,     0,   139,   140,   141,   142,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152
};

static const yytype_int16 yycheck[] =
{
       1,    27,    48,    91,    30,    27,   159,    93,   156,    32,
     100,   104,    13,   155,    15,   101,   168,    19,    19,   157,
     258,   199,   108,    11,    24,    99,   345,    28,   206,   169,
     279,   279,   210,    34,    35,   187,     5,   288,     1,    48,
     194,   219,   196,   129,     1,   296,    24,    48,   188,     3,
      36,    37,    38,    39,    40,    41,    24,    43,    44,     3,
      73,    74,    35,    62,    58,   248,    60,    67,    67,    20,
      24,     0,    35,    61,   257,    53,    25,    58,    35,    60,
       3,   127,   331,   331,    57,    86,   172,   173,   174,    24,
       3,    59,    61,    60,    57,    64,   345,   345,    99,   100,
      57,   420,   244,   104,   355,    59,    57,    75,    63,    63,
      67,    24,   252,    67,    58,    32,    60,   203,   127,    63,
      58,    75,    60,     3,    59,    42,   127,   365,    45,   115,
     216,   217,   315,   287,   372,   289,   319,    21,    58,   162,
      60,   164,   393,   394,    24,   171,    59,     3,    60,   171,
      63,   304,    35,   154,    25,    68,   157,    24,   311,     3,
     161,    24,    75,   165,   165,   191,    72,   168,   169,   191,
      57,   420,   420,    63,    57,   323,    74,    67,   320,    59,
     418,    60,    72,    63,    67,   337,   187,   188,    74,   212,
     368,   329,    59,    67,    67,    75,    59,   220,   284,    42,
      67,    24,    67,    60,    67,    24,   299,   297,    75,    58,
     211,    60,    75,   130,   131,   132,   133,   291,   135,   136,
     137,   295,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    59,   389,   155,   156,
      59,   158,    24,    86,    67,   162,   163,   164,   401,    68,
      93,   252,    75,    24,    67,    35,    75,    24,   101,    60,
     408,   307,    67,    57,    60,   108,    24,    73,    61,    68,
      24,    53,   115,    73,    24,   276,   277,    59,   279,    68,
     303,    24,    63,   369,   285,    67,   129,   310,    61,    68,
     291,    60,    59,    75,   295,   212,   297,    73,   299,    53,
      67,    59,    24,   220,    58,    59,   307,   333,    75,    60,
      68,   333,   155,    67,     3,    60,    59,    75,    64,    57,
      60,    75,    64,   411,    67,   168,   243,   244,   329,   172,
     173,   174,    75,   176,    60,    74,   337,    59,    42,    68,
      60,   258,    14,    68,   187,    68,    68,    63,    24,     3,
      68,   397,    58,    75,    68,    68,    68,    34,    61,    58,
     203,    68,    67,    17,    61,   391,    68,    44,    68,    23,
      24,    48,    68,   216,   217,    29,    53,    54,    55,    56,
      58,    68,    86,    68,    68,    60,   303,    68,   389,    93,
      58,    58,    86,   310,    68,    68,   397,   101,    58,    93,
      15,   244,    73,   320,   108,    59,   323,   101,   397,   391,
     347,   115,    29,    67,   108,   374,   374,    29,    72,   176,
     211,    75,   115,   176,   277,   129,    15,   291,    -1,    -1,
      -1,    -1,    -1,    -1,   277,   129,   279,    -1,    -1,    -1,
      -1,   284,    -1,    -1,    -1,    -1,    -1,    11,   365,    -1,
      -1,   155,    -1,    17,    -1,   372,   373,   374,    -1,    23,
      24,    -1,    -1,    -1,   168,    29,    -1,    -1,   172,   173,
     174,    -1,   176,    -1,   168,    -1,    -1,   320,   172,   173,
     174,    -1,   176,   187,    -1,    -1,    -1,    -1,   331,    53,
      -1,   408,    -1,   187,   337,    59,    -1,    -1,    -1,   203,
      -1,   418,   345,    67,    -1,    -1,    -1,    -1,    72,   203,
      -1,    75,   216,   217,    34,    -1,    -1,    -1,    -1,     4,
       5,    -1,   216,   217,    44,    -1,   369,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,   389,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,   277,    -1,   279,    61,   420,    -1,    64,
     284,    -1,    -1,   277,    -1,   279,     0,     1,    -1,     3,
     284,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    -1,    20,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    29,   320,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,   331,    -1,    -1,
      -1,    -1,    -1,   337,    -1,    49,    50,   331,    52,    53,
      -1,   345,    56,   337,    -1,    59,    60,    -1,    -1,    -1,
      -1,   345,    -1,    67,    -1,    -1,    70,    71,    72,    -1,
      -1,    75,    -1,    -1,    17,   369,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,   369,    29,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,   389,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,   389,    -1,    16,    17,    18,
      53,    20,    -1,    -1,    23,    24,    59,    -1,    27,    -1,
      29,    -1,    31,    32,    67,    -1,   420,    36,    -1,    72,
      -1,    -1,    75,    -1,    -1,    -1,   420,    -1,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    -1,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,     3,    -1,    67,    -1,
      -1,    70,    71,    72,    11,    -1,    75,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    17,
      -1,    -1,    29,    -1,    -1,    23,    24,    -1,    -1,    36,
      -1,    29,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    53,    17,    -1,    56,
      -1,    -1,    59,    23,    24,    53,    -1,    -1,    -1,    29,
      67,    59,    -1,    70,    71,    72,    36,    -1,    75,    67,
       3,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    49,
      50,    -1,    52,    53,    17,    -1,    56,    -1,    -1,    59,
      23,    24,    -1,    -1,    -1,    -1,    29,    67,    68,    -1,
      70,    71,    72,    36,    -1,    75,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    17,    -1,    56,    57,    -1,    59,    23,    24,    -1,
      -1,    -1,    -1,    29,    67,    31,    -1,    70,    71,    72,
      36,    -1,    75,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    52,    53,    17,    -1,
      56,    -1,    -1,    59,    23,    24,    -1,    -1,    -1,    -1,
      29,    67,    -1,    -1,    70,    71,    72,    36,    -1,    75,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    52,    53,    17,    -1,    56,    57,    -1,
      59,    23,    24,    -1,    -1,    -1,    -1,    29,    67,    -1,
      -1,    70,    71,    72,    36,    -1,    75,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    17,    -1,    56,    -1,    -1,    59,    23,    24,
      -1,    -1,    -1,    -1,    29,    67,    -1,    -1,    70,    71,
      72,    36,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    49,    50,    -1,    52,    53,    23,
      24,    56,    17,    -1,    59,    29,    -1,    -1,    23,    24,
      -1,    -1,    67,    -1,    29,    70,    71,    72,    -1,    17,
      75,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    53,
      -1,    29,    -1,    -1,    -1,    59,    -1,    61,    53,    -1,
      64,    -1,    -1,    67,    59,    -1,    61,    -1,    72,    64,
      -1,    75,    67,    -1,    -1,    53,    -1,    72,    -1,    -1,
      75,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    72,    33,    34,    75,    36,    -1,
      38,    39,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    -1,    74,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    73,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    33,    34,    -1,    36,    61,    38,    39,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    77,    78,    24,    59,    75,   119,   120,     0,
      79,     3,    60,    21,    80,   140,    63,     3,    63,    67,
      81,    83,   119,    60,     1,     3,     9,    16,    17,    18,
      20,    23,    27,    29,    31,    32,    36,    49,    50,    52,
      53,    56,    67,    70,    71,    72,    86,    87,    88,    94,
      99,   101,   105,   106,   107,   108,   113,   117,   119,   121,
     122,   126,   127,   130,   132,   133,   135,   138,   139,   152,
     156,    24,    59,     3,    68,    81,    82,    25,    84,     3,
      17,    94,    97,    98,   119,   164,    67,   119,   134,   107,
     113,   100,   164,    72,   105,   156,   163,    35,    57,   116,
      67,    92,    93,   119,    67,    89,   118,   119,   155,   106,
     106,   106,   106,   106,   106,    53,   105,   114,   125,   130,
     135,   106,   106,    11,   105,   162,    60,    67,    90,   155,
       4,    33,    34,    36,    37,    38,    39,    40,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    63,    67,    72,    74,    67,   116,
       1,   116,     5,    61,    64,    60,   160,    24,    67,    35,
      96,    60,    11,    53,    67,   115,   119,   121,   123,   124,
     129,   130,   131,   135,   148,   149,   150,    67,    57,   136,
      96,    60,   124,    24,    53,    58,    67,   117,   119,   144,
     145,   146,   147,   154,    68,    93,   143,   124,    68,    89,
     141,    61,    64,   124,   125,    68,    73,    73,    68,    90,
      64,   124,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   109,    67,   119,    68,   114,   157,   105,
     162,     1,    57,    87,    95,   151,   152,   105,   109,   151,
     153,   156,   105,   156,    81,    68,    24,    85,   150,   153,
     164,   124,   124,   124,   115,   123,    63,    61,   161,    68,
     150,   153,   103,   164,    73,    63,    24,    67,   147,    53,
     147,    60,   160,     3,   165,    61,   124,    60,   160,    60,
     160,   118,   156,    64,    57,   124,   124,    60,   160,   156,
      64,    57,   105,   110,   111,   158,   159,    31,   114,    11,
      61,   161,    73,    74,   153,    61,   161,   159,    58,    60,
      60,    68,    58,    60,    68,   119,   148,    67,   119,   128,
     129,   130,   131,   135,   137,    68,    58,    14,   102,   104,
     124,   119,   147,   165,   147,    68,   145,    58,   117,   165,
      93,    68,    89,    68,   156,   109,    90,    91,   142,   155,
      68,   156,   109,    74,    61,   161,    58,    68,    68,   161,
     114,    68,   162,    58,    68,    58,   151,   164,   150,    67,
     137,    20,    95,    68,    68,   165,   159,    60,   160,   124,
     159,    57,   105,   112,   110,   111,    68,    73,    74,    68,
     150,   100,   165,   165,    58,    91,    68,    58,   109,   162,
      68,    96,   159,    73,   137,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    84,    85,    85,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    89,    89,    89,    90,
      90,    91,    91,    91,    92,    93,    94,    94,    94,    94,
      94,    94,    95,    96,    97,    97,    98,    99,   100,   100,
     101,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   109,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   116,   116,   117,   118,   119,   119,
     119,   120,   120,   121,   122,   123,   123,   124,   124,   124,
     124,   124,   125,   125,   125,   126,   126,   127,   128,   128,
     128,   128,   129,   129,   130,   130,   130,   130,   131,   132,
     132,   133,   134,   134,   135,   136,   136,   137,   137,   137,
     138,   139,   139,   140,   140,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   145,   145,   145,   145,   146,
     146,   147,   148,   148,   148,   148,   149,   149,   150,   150,
     151,   151,   151,   151,   151,   152,   152,   152,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   157,
     157,   158,   158,   158,   158,   159,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   164,   164,   165,   165
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     3,     0,     3,     2,     5,     3,
       2,     1,     1,     3,     1,     2,     2,     4,     0,     1,
       0,     1,     1,     1,     1,     2,     5,     3,     2,     5,
       7,     3,     2,     5,     3,     1,     2,     4,     3,     4,
       3,     1,     2,     1,     1,     2,     1,     3,     3,     3,
       2,     2,     3,     3,     5,     1,     2,     2,     1,     3,
       5,     4,     0,     2,     0,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     5,     6,     1,
       1,     3,     5,     5,     4,     6,     8,     1,     5,     5,
       5,     7,     1,     0,     3,     1,     4,     1,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     5,     1,     2,     5,
       3,     3,     5,     8,     5,     0,     3,     0,     1,     3,
       1,     4,     2,     0,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     2,     4,     3,     5,     5,     1,
       3,     1,     1,     2,     2,     1,     1,     3,     0,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     3,     3,     0,     2,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1
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
        case 2:
#line 164 "go.y" /* yacc.c:1646  */
    {
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FILE, "file", nkids, kids, leaf);
		ast_root = (yyval.ast);
	}
#line 1806 "go.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 177 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		(yyval.ast) = NULL;
		exit(2);
	}
#line 1816 "go.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 183 "go.y" /* yacc.c:1646  */
    { 
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "package", nkids, kids, leaf);
	}
#line 1829 "go.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 195 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 1837 "go.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 199 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "imports", nkids, kids, leaf);
	}
#line 1848 "go.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 209 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 1859 "go.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 216 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 1870 "go.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 223 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 1881 "go.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 233 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
#line 1892 "go.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 240 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1900 "go.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 247 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1908 "go.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 251 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
#line 1919 "go.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 261 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 1930 "go.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 268 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 1941 "go.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 275 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 1952 "go.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 285 "go.y" /* yacc.c:1646  */
    {
		// TODO: concat package and name
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_package", nkids, kids, leaf);
	}
#line 1964 "go.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 296 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 1972 "go.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 300 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_safety", nkids, kids, leaf);
	}
#line 1983 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 313 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		(yyval.ast) = NULL;
	}
#line 1992 "go.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 318 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2000 "go.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 322 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2008 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 326 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2017 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 331 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2025 "go.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 338 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2036 "go.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 345 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2047 "go.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 352 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2058 "go.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 359 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2069 "go.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 366 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2080 "go.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 373 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2091 "go.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 380 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2102 "go.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 387 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2113 "go.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 394 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2124 "go.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 401 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2135 "go.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 411 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lconst", nkids, kids, leaf);
	}
#line 2146 "go.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 421 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2157 "go.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 428 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2168 "go.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 435 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2179 "go.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 445 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2190 "go.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 452 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2201 "go.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 462 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2209 "go.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 466 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2220 "go.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 473 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2228 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 480 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2238 "go.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 489 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl", nkids, kids, leaf);
	}
#line 2249 "go.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 499 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2257 "go.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 503 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2268 "go.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 510 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2279 "go.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 517 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2290 "go.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 524 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2301 "go.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 531 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2312 "go.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 542 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "compound_stmt", nkids, kids, leaf);
	}
#line 2323 "go.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 553 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "loop_body", nkids, kids, leaf);
	}
#line 2334 "go.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 563 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2345 "go.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 570 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2353 "go.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 577 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_body", nkids, kids, leaf);
	}
#line 2364 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 588 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_stmt", nkids, kids, leaf);
	}
#line 2375 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 598 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2383 "go.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 602 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
#line 2394 "go.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 616 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_stmt", nkids, kids, leaf);
	}
#line 2405 "go.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 627 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens "elseif"
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif", nkids, kids, leaf);
	}
#line 2416 "go.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 637 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2424 "go.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 641 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif_list", nkids, kids, leaf);
	}
#line 2435 "go.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 651 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2443 "go.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 655 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "else", nkids, kids, leaf);
	}
#line 2454 "go.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 668 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2462 "go.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 672 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2473 "go.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 679 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2484 "go.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 686 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2495 "go.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 693 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2506 "go.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 700 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2517 "go.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 707 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2528 "go.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 714 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2539 "go.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 721 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2550 "go.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 728 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2561 "go.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 735 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2572 "go.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 742 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2583 "go.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 749 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2594 "go.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 756 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2605 "go.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 763 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2616 "go.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 770 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2627 "go.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 777 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2638 "go.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 784 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2649 "go.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 791 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2660 "go.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 799 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2671 "go.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 806 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2682 "go.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 816 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2690 "go.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 820 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2701 "go.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 827 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2712 "go.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 834 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2723 "go.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 841 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2734 "go.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 848 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2745 "go.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 855 "go.y" /* yacc.c:1646  */
    {
		yyerror("the bitwise complement operator is ^");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2757 "go.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 863 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2768 "go.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 870 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 2779 "go.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 884 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 2790 "go.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 891 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 2801 "go.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 898 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 2812 "go.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 908 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2823 "go.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 915 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2831 "go.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 919 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2842 "go.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 926 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2853 "go.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 933 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2864 "go.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 940 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2875 "go.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 947 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2886 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 954 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2897 "go.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 961 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2905 "go.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 965 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2916 "go.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 972 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2927 "go.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 979 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2938 "go.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 986 "go.y" /* yacc.c:1646  */
    {
		yyerror("cannot parenthesize type in composite literal");

		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 2951 "go.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 995 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2959 "go.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1002 "go.y" /* yacc.c:1646  */
    {
		// composite expression.
		// make node early so we get the right line number.
		(yyval.ast) = NULL;
	}
#line 2969 "go.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1011 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval", nkids, kids, leaf);
	}
#line 2980 "go.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1021 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2988 "go.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1025 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
#line 2999 "go.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1035 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3007 "go.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1039 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
#line 3018 "go.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1049 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3026 "go.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1053 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
#line 3037 "go.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1063 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3045 "go.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1067 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
#line 3056 "go.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1077 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);

	}
#line 3065 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1085 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3076 "go.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1092 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3087 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1107 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3095 "go.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1114 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3103 "go.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1121 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3114 "go.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1128 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3122 "go.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1132 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3133 "go.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1142 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3144 "go.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1149 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3155 "go.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1159 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "name", nkids, kids, leaf);
	}
#line 3166 "go.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1169 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3174 "go.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1185 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");

		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3187 "go.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1194 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3198 "go.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1204 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3206 "go.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1208 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3214 "go.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1212 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3222 "go.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1216 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3230 "go.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1220 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3241 "go.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1230 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3249 "go.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1234 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3257 "go.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1238 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3268 "go.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1248 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3276 "go.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1252 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3284 "go.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1259 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3292 "go.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1266 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3300 "go.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1270 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3308 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1274 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3316 "go.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1278 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3324 "go.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1285 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3332 "go.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1289 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
#line 3343 "go.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1299 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3354 "go.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1306 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3365 "go.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1313 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].t), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3376 "go.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1320 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3384 "go.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1327 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3392 "go.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1334 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 3403 "go.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1341 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 3414 "go.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1355 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xfndcl", nkids, kids, leaf);
	}
#line 3425 "go.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1365 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 3436 "go.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1372 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 3447 "go.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1383 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fntype", nkids, kids, leaf);
	}
#line 3458 "go.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1393 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3466 "go.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1397 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 3474 "go.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1404 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3482 "go.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1408 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3490 "go.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1412 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 3498 "go.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1419 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3506 "go.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1426 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 3517 "go.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1433 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 3528 "go.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1448 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3536 "go.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1452 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl_list", nkids, kids, leaf);
	}
#line 3547 "go.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1462 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3555 "go.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1466 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
#line 3566 "go.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1476 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3574 "go.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1480 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
#line 3585 "go.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1490 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3593 "go.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1494 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
#line 3604 "go.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1504 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3612 "go.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1508 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
#line 3623 "go.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1518 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 3634 "go.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1525 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 3645 "go.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1532 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 3656 "go.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1539 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 3667 "go.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1546 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 3678 "go.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1553 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 3689 "go.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1563 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 3700 "go.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1570 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 3711 "go.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1580 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3719 "go.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1590 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3727 "go.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1594 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 3738 "go.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1601 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 3749 "go.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1608 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3757 "go.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1615 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3765 "go.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1619 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
#line 3776 "go.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1629 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3784 "go.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1633 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oarg_type_list_ocomma", nkids, kids, leaf);
	}
#line 3795 "go.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1646 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3803 "go.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1650 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3811 "go.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1654 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3819 "go.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1658 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3827 "go.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1662 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3835 "go.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1669 "go.y" /* yacc.c:1646  */
    {
		
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3844 "go.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1674 "go.y" /* yacc.c:1646  */
    {
		
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3853 "go.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1679 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3861 "go.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1684 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 22;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 3872 "go.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1691 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 3883 "go.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1698 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 3894 "go.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1708 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3902 "go.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1712 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
#line 3913 "go.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1722 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3921 "go.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1726 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
#line 3932 "go.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1736 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3940 "go.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1740 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
#line 3951 "go.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1750 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3959 "go.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1754 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
#line 3970 "go.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1764 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3978 "go.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1768 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
#line 3989 "go.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1781 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3997 "go.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1785 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4005 "go.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1789 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4016 "go.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1796 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4027 "go.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1806 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4035 "go.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1810 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "braced_keyval_list", nkids, kids, leaf);
	}
#line 4046 "go.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1823 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4054 "go.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1827 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osemi", 0, NULL, (yyvsp[0].t));
	}
#line 4062 "go.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1834 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4070 "go.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1838 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "ocomma", 0, NULL, (yyvsp[0].t));
	}
#line 4078 "go.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1845 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4086 "go.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1849 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4094 "go.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1856 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4102 "go.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1860 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4110 "go.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1867 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4118 "go.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1871 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4126 "go.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1879 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4134 "go.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1883 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "oliteral", nkids, kids, leaf);
	}
#line 4145 "go.tab.c" /* yacc.c:1646  */
    break;


#line 4149 "go.tab.c" /* yacc.c:1646  */
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
#line 1906 "go.y" /* yacc.c:1906  */

