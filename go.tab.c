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

// #define YYDEBUG 1
// int yydebug=1;

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
	
   fprintf(stderr, "syntax error: unespected '%s' token in file %s, line %d\n",
	   yytext,yyfilename, yylineno);
}




#line 113 "go.tab.c" /* yacc.c:339  */

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
#line 69 "go.y" /* yacc.c:355  */

	struct tree* ast;
	struct token* t;

#line 211 "go.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "go.tab.c" /* yacc.c:358  */

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
#define YYLAST   1971

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  523

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
       2,     2,     2,    71,     2,     2,     2,    55,    56,     2,
      65,    66,    53,    49,    61,    50,    68,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    60,
       2,    69,     2,    59,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    52,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    51,    58,    72,     2,     2,     2,
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
      45,    46,    47,    48,    63,    64,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   177,   182,   193,   197,   207,   214,   221,
     231,   238,   248,   255,   265,   272,   279,   289,   300,   304,
     317,   322,   329,   336,   344,   351,   358,   365,   372,   379,
     386,   393,   400,   407,   414,   424,   434,   441,   448,   458,
     465,   475,   482,   489,   499,   511,   521,   528,   535,   542,
     549,   556,   566,   573,   580,   588,   598,   610,   609,   643,
     647,   657,   668,   675,   685,   692,   699,   709,   719,   730,
     737,   748,   761,   772,   776,   786,   790,   801,   814,   828,
     835,   842,   849,   856,   863,   870,   877,   884,   891,   898,
     905,   912,   919,   926,   933,   940,   947,   954,   961,   969,
     979,   986,   993,  1000,  1007,  1014,  1021,  1029,  1036,  1050,
    1057,  1064,  1074,  1081,  1088,  1095,  1102,  1109,  1116,  1123,
    1130,  1137,  1144,  1151,  1158,  1167,  1177,  1186,  1196,  1203,
    1213,  1220,  1230,  1237,  1247,  1254,  1264,  1274,  1281,  1296,
    1306,  1316,  1320,  1330,  1337,  1344,  1354,  1361,  1371,  1381,
    1400,  1409,  1419,  1426,  1433,  1440,  1447,  1454,  1464,  1471,
    1478,  1485,  1495,  1502,  1509,  1516,  1523,  1533,  1540,  1549,
    1559,  1566,  1573,  1580,  1587,  1597,  1604,  1614,  1621,  1628,
    1635,  1642,  1649,  1656,  1666,  1676,  1686,  1693,  1703,  1710,
    1724,  1734,  1741,  1768,  1778,  1782,  1792,  1796,  1803,  1813,
    1823,  1830,  1845,  1849,  1859,  1866,  1876,  1883,  1893,  1900,
    1910,  1917,  1927,  1934,  1944,  1951,  1958,  1965,  1972,  1979,
    1989,  1996,  2006,  2016,  2023,  2030,  2040,  2053,  2060,  2067,
    2074,  2084,  2091,  2101,  2105,  2118,  2122,  2129,  2136,  2143,
    2153,  2160,  2167,  2174,  2181,  2188,  2196,  2203,  2210,  2217,
    2224,  2231,  2238,  2248,  2255,  2265,  2272,  2282,  2289,  2299,
    2306,  2316,  2323,  2336,  2343,  2350,  2357,  2367,  2371,  2384,
    2388,  2395,  2399,  2406,  2410,  2420,  2424,  2434,  2438,  2490,
    2494
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
  "','", "'`'", "NotPackage", "NotParen", "'('", "')'",
  "PreferToRightParen", "'.'", "'='", "':'", "'!'", "'~'", "'['", "']'",
  "'@'", "$accept", "file", "package", "imports", "import", "import_stmt",
  "import_stmt_list", "import_here", "import_package", "import_safety",
  "xdcl", "common_dcl", "lconst", "vardcl", "constdcl", "constdcl1",
  "typedclname", "typedcl", "simple_stmt", "case", "compound_stmt",
  "caseblock", "$@1", "caseblock_list", "loop_body", "range_stmt",
  "for_header", "for_body", "for_stmt", "if_header", "if_stmt", "elseif",
  "elseif_list", "else", "switch_stmt", "select_stmt", "expr", "uexpr",
  "pseudocall", "pexpr_no_paren", "start_complit", "keyval",
  "bare_complitexpr", "complitexpr", "pexpr", "expr_or_type",
  "name_or_type", "lbrace", "new_name", "dcl_name", "onew_name", "sym",
  "hidden_importsym", "name", "labelname", "dotdotdot", "ntype",
  "non_expr_type", "non_recvchantype", "convtype", "comptype",
  "fnret_type", "dotname", "othertype", "ptrtype", "recvchantype",
  "structtype", "interfacetype", "xfndcl", "fndcl", "fntype", "fnbody",
  "fnres", "fnlitdcl", "fnliteral", "xdcl_list", "vardcl_list",
  "constdcl_list", "typedcl_list", "structdcl_list", "interfacedcl_list",
  "structdcl", "packname", "embed", "interfacedcl", "indcl", "arg_type",
  "arg_type_list", "oarg_type_list_ocomma", "stmt", "non_dcl_stmt",
  "stmt_list", "new_name_list", "dcl_name_list", "expr_list",
  "expr_or_type_list", "keyval_list", "braced_keyval_list", "osemi",
  "ocomma", "oexpr", "oexpr_list", "osimple_stmt", "oliteral", YY_NULLPTR
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
      59,    44,    96,   304,   305,    40,    41,   306,    46,    61,
      58,    33,   126,    91,    93,    64
};
# endif

#define YYPACT_NINF -401

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-401)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   146,    38,  -401,  -401,  -401,    44,    -8,  -401,  -401,
      45,    28,  -401,    69,    67,   930,    27,  -401,    84,   130,
    -401,   117,   151,  -401,  -401,  -401,   146,  1504,  -401,   146,
     385,  -401,  1390,    99,   385,   146,  1390,   105,    82,  1390,
     134,   105,  1390,   199,   267,  1390,  1390,  1390,  1390,  1390,
    1390,  1428,  1390,  1390,   989,   127,  -401,   331,  -401,  -401,
    -401,  -401,  -401,  1672,  -401,  -401,   138,   398,  -401,   136,
    -401,   140,   162,   105,   165,  -401,  -401,  -401,   166,    48,
    -401,  -401,    31,  -401,  -401,  -401,  -401,   156,  -401,   205,
    -401,  -401,  -401,  -401,  -401,   177,  1536,  1536,  1536,  -401,
     150,  -401,  -401,  -401,  -401,  -401,  -401,   153,   398,  -401,
    -401,   218,  -401,    43,   195,   831,   191,   202,   192,  -401,
     218,   203,  -401,  -401,   248,  1536,  1844,   210,  -401,  -401,
     227,   240,   295,  1536,  -401,  -401,   328,  -401,  -401,  -401,
     632,  -401,  -401,  -401,  -401,  -401,  -401,  1466,  1428,  1844,
     221,  -401,    10,  -401,    54,  -401,  -401,   219,  1844,   222,
    -401,   345,  -401,   762,  1390,  1390,  1390,  1390,  -401,  1390,
    1390,  1390,  -401,  1390,  1390,  1390,  1390,  1390,  1390,  1390,
    1390,  1390,  1390,  1390,  1390,  1390,  1390,  -401,   520,   376,
    1390,  1068,  1390,  -401,  -401,  1141,  1390,  1390,  1390,    73,
     229,   260,   831,   291,  1536,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,   239,   146,  1141,  -401,  1200,  1238,  1390,  1536,
    -401,   831,  -401,  -401,  -401,   247,   244,   831,  1141,  -401,
    -401,  1390,    57,  -401,   294,   256,   265,  -401,  -401,   254,
     207,     9,  -401,    98,  -401,   270,  -401,  -401,   334,   842,
    -401,  -401,  -401,   281,  -401,  -401,  -401,   293,   146,  1390,
     262,  1563,  -401,   299,  1536,  1536,  -401,   297,  1390,   289,
    1844,  1915,  -401,  1868,   681,   681,   681,   681,  -401,   681,
     681,  1892,  -401,   567,   567,   567,   567,  -401,  -401,  -401,
    -401,  1276,  -401,  -401,    30,  1314,  -401,  1704,   292,  -401,
    1141,  -401,  -401,  -401,  -401,  1820,  1276,  -401,     4,   210,
    1844,   210,  -401,  -401,  -401,   303,   298,  1536,   308,  -401,
    -401,   123,  1390,  1390,   305,  -401,  -401,  -401,   831,  -401,
    1574,   309,   124,   364,  -401,   146,   313,   318,   831,  -401,
     394,   341,  1536,  1428,   346,  -401,  -401,  -401,   294,   334,
     294,   349,   223,   359,  -401,  -401,   146,   334,   271,   146,
     368,   146,   370,  -401,   210,  1390,  1629,  1536,  -401,   163,
     279,   362,   366,  -401,  -401,  -401,   146,   372,   210,  1390,
    -401,  1736,  -401,  -401,   378,   387,   386,  1428,   383,   390,
     391,  -401,  1390,   128,  -401,   395,   404,  -401,  1068,  -401,
    1574,  -401,  -401,  1844,  1844,  1390,  -401,   831,   399,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  1574,  -401,     8,  -401,
    -401,  -401,  -401,   401,  -401,  -401,  -401,   102,  -401,  1068,
     402,  -401,   406,   334,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,   210,   407,  1276,  -401,  -401,   410,   762,
    -401,   210,  1276,  1352,  1276,  -401,  -401,   409,  -401,  -401,
    -401,  -401,   -17,  -401,  -401,  -401,  -401,  -401,   411,   831,
    -401,  1390,  -401,  1574,  1390,  1428,  1390,  -401,   416,   334,
     334,  -401,   465,   375,   424,   146,   418,   289,   427,  -401,
    1844,  -401,  -401,  -401,  -401,  1390,  -401,  -401,   420,   218,
     465,  -401,  1764,  1792,  -401,  -401,   468,   475,  -401,  -401,
    -401,  -401,  1276,   417,  1574,  -401,   475,  -401,  -401,   432,
    -401,  -401,  -401
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     5,   143,   145,     0,     0,   144,     1,
     202,     0,     4,     0,     0,     0,     0,    14,     0,     0,
       7,    11,     0,     6,    24,   112,   141,     0,    35,   141,
       0,   246,   277,     0,     0,     0,   277,     0,     0,   275,
       0,     0,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,    21,     0,   240,   241,
     244,   242,   243,    46,    79,   120,   132,   100,   149,   148,
     113,     0,     0,     0,   169,   182,   183,    22,   199,     0,
     125,    23,     0,   146,   147,     9,    12,   269,    16,     0,
      10,    15,   142,   247,   139,     0,     0,     0,     0,   148,
     175,   179,   165,   163,   164,   162,   248,   120,     0,   278,
      66,     0,    68,     0,    65,   233,     0,   194,   120,   251,
       0,    69,   137,   138,     0,     0,   259,   276,   252,    59,
       0,     0,     0,     0,    32,    44,     0,    25,   257,   140,
       0,   108,   103,   104,   107,   101,   102,     0,     0,   134,
       0,   135,   160,   158,   159,   105,   106,     0,   274,     0,
     203,     0,    28,     0,     0,     0,     0,     0,    51,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,     0,
     273,     0,     0,   126,   201,     0,     0,     0,     0,   270,
       0,    18,   233,     0,     0,   180,   156,   154,   155,   152,
     153,   184,     0,     0,     0,    67,     0,     0,   277,   150,
     227,   148,   230,   136,   231,   271,     0,   233,     0,   190,
      73,   277,   143,   189,     0,     0,   269,   224,   212,     0,
       0,     0,   187,     0,   255,   269,   210,   222,   279,     0,
      59,    34,   208,   269,    45,    27,   204,   269,     0,     0,
      36,     0,   161,   133,     0,     0,    31,   269,     0,     0,
      47,    81,    96,    99,    82,    86,    87,    85,    97,    84,
      83,    80,    98,    88,    89,    90,    91,    92,    93,    94,
      95,   267,   109,   261,   271,     0,   114,   274,     0,   239,
       0,   237,   236,   245,   238,   271,   267,   253,     0,    49,
     260,    48,    13,     8,    19,     0,     0,     0,     0,   166,
     176,     0,     0,     0,     0,   151,   228,   229,   272,   234,
     196,     0,     0,    75,    70,     0,   220,     0,   233,   223,
     270,     0,     0,     0,     0,    78,    57,    60,     0,   279,
       0,     0,   270,     0,   280,   215,     0,   279,     0,   270,
       0,   270,     0,   258,    38,     0,     0,     0,   185,   156,
     154,   155,   153,   126,   178,   177,   270,     0,    40,     0,
     126,   128,   263,   264,   271,     0,   271,   272,     0,     0,
       0,   117,   273,     0,   272,     0,     0,   200,     0,    17,
     196,   157,    61,    63,    62,   277,   232,   233,   148,   197,
     174,   172,   173,   170,   171,   193,   196,   195,     0,    74,
      71,   221,   225,     0,   213,   188,   181,     0,    55,     0,
       0,   217,     0,   279,   211,   186,   256,   214,    73,   209,
      33,   205,    26,    37,     0,   267,    41,   206,   269,    43,
      29,    39,   267,     0,   272,   268,   123,     0,   262,   110,
     116,   115,     0,    56,   121,   122,   254,    64,     0,   233,
     191,   277,    73,   196,     0,     0,     0,    52,    58,   279,
     279,   216,     0,   157,     0,   270,     0,    42,     0,   126,
     130,   127,   265,   266,   111,   273,   118,   198,     0,     0,
       0,   226,     0,     0,   219,   218,     0,    77,   124,   207,
      30,   129,   267,     0,   196,    72,    76,    54,    53,     0,
     119,   192,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -401,  -401,  -401,  -401,  -401,    13,  -401,  -401,  -401,  -401,
    -401,   483,  -401,  -125,   -35,    14,  -401,  -115,   -28,  -401,
      83,  -401,  -401,   253,  -113,  -401,  -401,  -401,  -401,   -41,
    -401,  -315,  -377,  -401,  -401,  -401,   577,    32,    29,  -401,
    -172,    50,    51,  -401,    60,   -38,   286,   194,    -6,   251,
     481,   482,  -401,   164,  -401,   300,   463,   365,  -401,  -401,
    -401,  -401,   -21,   -27,   -18,   -49,  -401,  -401,  -401,  -401,
       5,  -401,  -400,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,   160,   -99,  -201,   174,  -401,   188,  -401,  -192,  -173,
     503,  -184,  -401,   -52,   -20,   179,  -401,  -279,  -199,  -255,
    -175,  -401,   -29,  -323
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    87,    21,    90,   315,
      55,   301,    57,   137,   446,   447,   133,   134,    58,   346,
     302,   347,   429,   240,   215,   110,   111,   112,    59,   120,
      60,   419,   333,   420,    61,    62,    63,    64,    65,    66,
     291,   382,   383,   491,    67,   293,   220,   124,    68,   138,
      93,    99,     8,    70,    71,   222,   223,   151,   101,    72,
      73,   409,   206,    74,   208,   209,    75,    76,    77,   117,
      78,   229,   415,    79,    80,    15,   257,   448,   253,   245,
     236,   246,   247,   248,   238,   339,   224,   225,   226,   307,
     304,   308,   249,   140,    82,   294,   384,   385,   200,   329,
     159,   128,   121,   355
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   131,   153,   114,   109,   163,   102,   230,   109,   104,
     316,   256,   113,   150,   109,   298,   470,   252,   303,   127,
      92,   306,   162,    92,   152,   237,   431,   396,   471,   119,
     321,    86,   105,   336,   437,   331,   196,   341,     9,   388,
     349,   386,   351,     1,   332,  -169,   353,    11,   216,   194,
     395,    83,    12,   495,   360,  -199,   154,   496,   362,   107,
    -220,   482,   397,   118,   398,   300,    13,  -169,   377,   207,
     207,   207,    17,   501,   348,  -168,    17,   141,   142,   143,
     144,   145,   146,   122,   155,   156,    84,    17,   207,  -199,
     108,   387,   197,     4,   108,   500,    16,     4,   207,   153,
     198,   210,   210,   210,   197,   123,   207,   474,     4,   163,
     481,  -199,   217,   207,   521,  -220,   393,  -220,   235,  -167,
     210,   152,   336,     4,   244,   335,   267,    23,     5,   455,
     210,   457,     5,    88,    18,   337,   207,    19,   210,   153,
     122,    19,    89,     5,     6,   210,   423,   430,     6,   432,
      85,   350,    19,   154,    91,   125,   504,   505,     5,     6,
    -250,   152,   123,   475,   115,  -250,   484,   507,   210,   129,
       4,   476,   477,   488,     6,   207,   309,   207,   311,   141,
     145,   402,   417,   398,   398,   516,   463,   160,   398,   324,
     109,   100,   207,   154,   207,   187,   309,   311,  -165,  -249,
     207,   445,   334,   109,  -249,     5,  -139,   210,   452,   210,
     191,  -250,   312,  -250,   343,   468,   199,   462,   213,   344,
    -165,     6,   207,     4,   210,   466,   210,   192,  -165,   201,
    -168,  -167,   210,   519,   370,   130,   441,   207,   207,   364,
     369,   237,   202,   371,   439,   478,   153,   232,   378,   486,
    -249,   232,  -249,   214,   210,   218,   227,   390,     5,   228,
     100,   100,   100,   231,   132,   345,   372,   193,   152,   210,
     210,   197,   232,   195,     6,   250,   241,   498,   343,   100,
     241,   413,     5,   344,   314,   242,     5,   263,   243,   100,
     207,     4,   243,   264,   153,   313,   265,   100,     6,   317,
     154,   207,     6,   411,   100,   319,   233,     5,   328,   410,
     330,   207,   412,   234,  -163,   207,   152,   512,   336,     4,
     513,   338,   210,     6,   449,   340,     5,   100,   342,   438,
     352,   365,   136,   210,   235,   414,  -163,   354,   153,   207,
     207,   359,     6,   210,  -163,   443,   244,   210,   154,   458,
     436,   413,     4,   361,     5,     4,   373,   376,   379,   451,
     152,   251,   392,   399,   400,   405,   100,   413,   100,     4,
       6,   210,   210,   411,   401,   416,   467,   109,   418,   410,
     207,   335,   412,   100,   422,   100,   515,     5,    25,   411,
       5,   100,   154,    27,   255,   410,   161,  -164,   412,   425,
       4,  -162,    95,     6,     5,   414,     6,    37,    38,     4,
    -166,   266,   210,   100,    41,   433,   428,   435,   232,  -164,
       6,   414,   207,  -162,   413,   100,   153,  -164,   100,   100,
     499,  -162,  -166,   449,   440,     5,   442,   458,   450,   454,
    -166,   295,   207,   109,     5,   456,   411,   394,   152,   459,
      51,     6,   410,     5,   210,   412,   460,   461,    54,   234,
       6,   464,   465,   188,   469,   413,   189,   473,   479,     6,
     485,   190,   480,   483,   210,   494,   398,   497,   414,   506,
     154,   100,   508,     7,   510,   511,   514,   411,   471,   -74,
     522,   520,   100,   410,   100,    22,   412,    69,    56,   509,
      22,   472,   100,   358,   492,   493,   100,   326,    94,   363,
     106,    94,   434,   262,   424,   116,   406,    94,    81,   414,
       0,   327,   427,    25,     0,   135,   139,     0,    27,     0,
     100,   100,     0,     0,     0,     0,     0,    95,     0,   139,
       0,     0,    37,    38,     4,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,   147,     0,     0,   205,
     211,   212,     0,     0,   100,     0,     0,     0,     0,    46,
      47,   100,    48,   148,     0,     0,    50,     0,     0,     5,
     100,     0,     0,     0,     0,    51,   292,     0,   239,     0,
       0,    52,    53,    54,     0,     6,   254,   221,     0,     0,
       0,   166,     0,   260,     0,     0,    94,     0,     0,     0,
       0,   174,    94,   100,   135,   178,   126,     0,   139,     0,
     183,   184,   185,   186,     0,     0,   269,     0,   149,     0,
       0,   158,     0,   100,     0,     0,     0,   100,     0,     0,
      27,     0,     0,   139,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,    37,    38,     4,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,   318,   203,     0,
       0,   296,     0,    69,     0,     0,     0,    69,   100,     0,
       0,    22,   325,     0,   221,    97,     0,     0,     0,     0,
       0,     5,     0,   258,     0,   320,    69,   204,     0,     0,
       0,   259,     0,     0,     0,    54,     0,     6,     0,   221,
      69,     0,   357,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,   368,   174,     0,   374,   375,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
     139,   270,   271,   272,   273,     0,   274,   275,   276,     0,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,     0,   149,     0,   297,     0,   305,
      27,     0,     0,   126,   310,   126,     0,     0,     0,    95,
     368,     0,    69,     0,    37,    38,     4,     0,     0,     0,
       0,    41,     0,   126,   126,     0,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   426,     0,     0,     0,     0,
     221,     0,   408,     0,     0,    97,     0,   421,     0,     0,
     221,     5,    94,   258,     0,     0,     0,   204,     0,   205,
     444,   268,     0,     0,    94,    54,   126,     6,    94,    27,
       0,   135,   219,   139,     0,   126,     0,     0,    95,     0,
      27,     0,     0,    37,    38,     4,     0,     0,   139,    95,
      41,     0,     0,     0,    37,    38,     4,   203,   381,     0,
       0,    41,   149,     0,     0,     0,     0,     0,   203,     0,
      69,     0,     0,   381,    97,     0,     0,     0,     0,   221,
       5,     0,     0,     0,     0,    97,   204,     0,     0,   403,
     404,     5,     0,   356,    54,     0,     6,   204,     0,     0,
       0,    69,   487,     0,     0,    54,     0,     6,     0,     0,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -2,    24,     0,    25,     0,     0,    26,     0,    27,    28,
      29,     0,   126,    30,     0,    31,    32,    33,    34,    35,
      36,   221,    37,    38,     4,     0,   126,    39,    40,    41,
      42,    43,    44,     0,   149,     0,    45,   139,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,     0,    48,    49,     0,     0,    50,     0,     0,     5,
     -20,     0,    25,     0,     0,    51,     0,    27,     0,     0,
     157,    52,    53,    54,     0,     6,    95,     0,     0,     0,
       0,    37,    38,     4,     0,     0,     0,     0,    41,     0,
       0,     0,   381,     0,     0,    45,     0,     0,     0,   381,
     490,   381,     0,     0,     0,     0,     0,     0,    46,    47,
       0,    48,    49,     0,     0,    50,     0,     0,     5,     0,
       0,   502,   149,   503,    51,     0,     0,     0,     0,     0,
      52,    53,    54,     0,     6,     0,     0,     0,     0,   299,
       0,    25,   158,     0,    26,  -235,    27,    28,    29,     0,
    -235,    30,     0,    31,    32,    95,    34,    35,    36,   381,
      37,    38,     4,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     0,
      48,    49,     0,     0,    50,   300,  -235,     5,  -235,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,    52,
      53,    54,   299,     6,    25,     0,     0,    26,     0,    27,
      28,    29,     0,     0,    30,     0,    31,    32,    95,    34,
      35,    36,     0,    37,    38,     4,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,    48,    49,     0,     0,    50,   300,  -235,
       5,  -235,     0,    25,     0,     0,    51,     0,    27,     0,
       0,     0,    52,    53,    54,     0,     6,    95,     0,     0,
       0,     0,    37,    38,     4,     0,   322,     0,     0,    41,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,    25,     0,     0,     0,     0,    27,     0,     0,    46,
      47,     0,    48,    49,     0,    95,    50,     0,     0,     5,
      37,    38,     4,     0,   323,    51,     0,    41,     0,     0,
       0,    52,    53,    54,    45,     6,     0,     0,     0,    25,
       0,     0,     0,     0,    27,     0,     0,    46,    47,     0,
      48,    49,     0,    95,    50,     0,     0,     5,    37,    38,
       4,     0,     0,    51,     0,    41,     0,     0,     0,    52,
      53,    54,    45,     6,     0,     0,     0,    25,     0,     0,
       0,     0,    27,     0,     0,    46,    47,     0,    48,    49,
       0,    95,    50,   380,     0,     5,    37,    38,     4,     0,
       0,    51,     0,    41,     0,   389,     0,    52,    53,    54,
     147,     6,     0,     0,     0,    25,     0,     0,     0,     0,
      27,     0,     0,    46,    47,     0,    48,   148,     0,    95,
      50,     0,     0,     5,    37,    38,     4,     0,     0,    51,
       0,    41,     0,     0,     0,    52,    53,    54,    45,     6,
       0,     0,     0,    25,     0,     0,     0,     0,    27,     0,
       0,    46,    47,     0,    48,    49,     0,    95,    50,   489,
       0,     5,    37,    38,     4,     0,     0,    51,     0,    41,
       0,     0,     0,    52,    53,    54,    45,     6,     0,     0,
       0,    25,     0,     0,     0,     0,    27,     0,     0,    46,
      47,     0,    48,    49,     0,    95,    50,     0,     0,     5,
      37,    38,     4,     0,     0,    51,     0,    41,     0,     0,
       0,    52,    53,    54,   147,     6,     0,     0,     0,    25,
       0,     0,     0,     0,   261,     0,     0,    46,    47,     0,
      48,   148,     0,    95,    50,     0,     0,     5,    37,    38,
       4,     0,     0,    51,     0,    41,     0,     0,     0,    52,
      53,    54,    45,     6,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    46,    47,     0,    48,    49,
       0,    95,    50,     0,     0,     5,    37,    38,     4,     0,
       0,    51,     0,    41,     0,     0,     0,    52,    53,    54,
      96,     6,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,    97,    37,    38,
       4,     0,     0,     5,     0,    41,     0,     0,     0,    98,
       0,    27,   203,     0,     0,     0,     0,    54,     0,     6,
      95,     0,    27,     0,     0,    37,    38,     4,     0,    97,
       0,    95,    41,     0,     0,     5,    37,    38,     4,   366,
       0,   204,     0,    41,     0,     0,     0,     0,     0,    54,
     203,     6,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,    97,   367,     0,
       0,     0,     0,     5,     0,     0,    54,   261,     6,   407,
       0,     0,     0,     0,     0,     0,    95,    54,     0,     6,
       0,    37,    38,     4,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,  -259,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,   204,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     6,   165,   166,     0,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
       0,     0,     0,  -259,     0,     0,     0,   165,   166,     0,
     167,  -259,   169,   170,   171,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,     0,   167,     0,   169,   170,   171,     0,   391,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,   165,   166,     0,
     167,     0,   169,   170,   171,     0,   453,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,     0,     0,     0,   165,   166,     0,   167,     0,
     169,   170,   171,     0,   517,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
       0,     0,     0,   165,   166,     0,   167,     0,   169,   170,
     171,     0,   518,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   165,   166,     0,
     167,   394,   169,   170,   171,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   165,   166,     0,     0,     0,   169,   170,   171,     0,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   165,   166,     0,     0,     0,
     169,   170,   171,     0,     0,   173,   174,   175,   176,     0,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   166,
       0,     0,     0,   169,   170,   171,     0,     0,   173,   174,
     175,   176,     0,   178,   179,   180,   181,   182,   183,   184,
     185,   186
};

static const yytype_int16 yycheck[] =
{
      27,    42,    51,    32,    32,    57,    27,   120,    36,    27,
     202,   136,    32,    51,    42,   190,   416,   132,   191,    39,
      26,   193,    57,    29,    51,   124,   349,   306,    20,    35,
     214,    18,    27,    24,   357,   227,     5,   236,     0,   294,
     241,    11,   243,    25,   228,    35,   245,     3,     5,     1,
     305,    24,    60,    70,   253,     1,    51,    74,   257,    30,
       3,   438,    58,    34,    60,    57,    21,    57,   267,    96,
      97,    98,     3,   473,    65,    65,     3,    45,    46,    47,
      48,    49,    50,    35,    52,    53,    59,     3,   115,    35,
      30,    61,    61,    24,    34,   472,    68,    24,   125,   148,
      69,    96,    97,    98,    61,    57,   133,     5,    24,   161,
     433,    57,    69,   140,   514,    58,   300,    60,   124,    65,
     115,   148,    24,    24,   130,    68,   161,    60,    59,   384,
     125,   386,    59,     3,    65,   234,   163,    68,   133,   188,
      35,    68,    25,    59,    75,   140,   338,   348,    75,   350,
      66,    53,    68,   148,     3,    73,   479,   480,    59,    75,
       7,   188,    57,    61,    65,    12,   445,   482,   163,    35,
      24,    69,    70,   452,    75,   202,   196,   204,   198,   147,
     148,    58,    58,    60,    60,   500,    58,    60,    60,   218,
     218,    27,   219,   188,   221,    57,   216,   217,    35,     7,
     227,   373,   231,   231,    12,    59,    70,   202,   380,   204,
      70,    58,   199,    60,     7,   407,    60,   392,    68,    12,
      57,    75,   249,    24,   219,   398,   221,    65,    65,    24,
      65,    65,   227,   512,   261,    41,   361,   264,   265,   259,
     261,   340,    65,   261,   359,   429,   295,    24,   268,   448,
      58,    24,    60,    35,   249,    60,    65,   295,    59,    57,
      96,    97,    98,    60,    65,    58,   261,    73,   295,   264,
     265,    61,    24,    79,    75,    35,    53,   469,     7,   115,
      53,   330,    59,    12,    24,    58,    59,    66,    65,   125,
     317,    24,    65,    74,   343,    66,    74,   133,    75,     8,
     295,   328,    75,   330,   140,    66,    58,    59,    61,   330,
      66,   338,   330,    65,    35,   342,   343,   489,    24,    24,
     495,    65,   317,    75,   376,    60,    59,   163,    74,    58,
      60,    69,    65,   328,   340,   330,    57,     3,   387,   366,
     367,    60,    75,   338,    65,   365,   352,   342,   343,   387,
     356,   400,    24,    60,    59,    24,    57,    60,    69,   379,
     387,    66,    70,    60,    66,    60,   202,   416,   204,    24,
      75,   366,   367,   400,    66,    66,   405,   405,    14,   400,
     407,    68,   400,   219,    66,   221,   499,    59,     3,   416,
      59,   227,   387,     8,    66,   416,    65,    35,   416,    58,
      24,    35,    17,    75,    59,   400,    75,    22,    23,    24,
      35,    66,   407,   249,    29,    66,    70,    58,    24,    57,
      75,   416,   449,    57,   473,   261,   475,    65,   264,   265,
     471,    65,    57,   485,    66,    59,    66,   475,    66,    61,
      65,    65,   469,   471,    59,    58,   473,    61,   475,    66,
      65,    75,   473,    59,   449,   473,    66,    66,    73,    65,
      75,    66,    58,    65,    65,   514,    68,    66,    66,    75,
      60,    73,    66,    66,   469,    66,    60,    66,   473,    14,
     475,   317,    58,     1,    66,    58,    66,   514,    20,    14,
      58,    74,   328,   514,   330,    13,   514,    15,    15,   485,
      18,   418,   338,   250,   454,   454,   342,   221,    26,   258,
      29,    29,   352,   148,   340,    33,   328,    35,    15,   514,
      -1,   221,   343,     3,    -1,    43,    44,    -1,     8,    -1,
     366,   367,    -1,    -1,    -1,    -1,    -1,    17,    -1,    57,
      -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    96,
      97,    98,    -1,    -1,   400,    -1,    -1,    -1,    -1,    49,
      50,   407,    52,    53,    -1,    -1,    56,    -1,    -1,    59,
     416,    -1,    -1,    -1,    -1,    65,    66,    -1,   125,    -1,
      -1,    71,    72,    73,    -1,    75,   133,   115,    -1,    -1,
      -1,    34,    -1,   140,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    44,   130,   449,   132,    48,    39,    -1,   136,    -1,
      53,    54,    55,    56,    -1,    -1,   163,    -1,    51,    -1,
      -1,    54,    -1,   469,    -1,    -1,    -1,   473,    -1,    -1,
       8,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,   204,    36,    -1,
      -1,   189,    -1,   191,    -1,    -1,    -1,   195,   514,    -1,
      -1,   199,   219,    -1,   202,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    -1,   213,   214,    65,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    73,    -1,    75,    -1,   227,
     228,    -1,   249,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,    44,    -1,   264,   265,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
     258,   164,   165,   166,   167,    -1,   169,   170,   171,    -1,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,   188,    -1,   190,    -1,   192,
       8,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,    17,
     317,    -1,   300,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,   216,   217,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,   342,    -1,    -1,    -1,    -1,
     328,    -1,   330,    -1,    -1,    53,    -1,   335,    -1,    -1,
     338,    59,   340,    61,    -1,    -1,    -1,    65,    -1,   366,
     367,    69,    -1,    -1,   352,    73,   259,    75,   356,     8,
      -1,   359,    11,   361,    -1,   268,    -1,    -1,    17,    -1,
       8,    -1,    -1,    22,    23,    24,    -1,    -1,   376,    17,
      29,    -1,    -1,    -1,    22,    23,    24,    36,   291,    -1,
      -1,    29,   295,    -1,    -1,    -1,    -1,    -1,    36,    -1,
     398,    -1,    -1,   306,    53,    -1,    -1,    -1,    -1,   407,
      59,    -1,    -1,    -1,    -1,    53,    65,    -1,    -1,   322,
     323,    59,    -1,    61,    73,    -1,    75,    65,    -1,    -1,
      -1,   429,   449,    -1,    -1,    73,    -1,    75,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,    -1,    -1,     6,    -1,     8,     9,
      10,    -1,   365,    13,    -1,    15,    16,    17,    18,    19,
      20,   469,    22,    23,    24,    -1,   379,    27,    28,    29,
      30,    31,    32,    -1,   387,    -1,    36,   485,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,     3,    -1,    -1,    65,    -1,     8,    -1,    -1,
      11,    71,    72,    73,    -1,    75,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,   445,    -1,    -1,    36,    -1,    -1,    -1,   452,
     453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,   474,   475,   476,    65,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,     1,
      -1,     3,   495,    -1,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,   512,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    -1,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,     1,    75,     3,    -1,    -1,     6,    -1,     8,
       9,    10,    -1,    -1,    13,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    -1,    56,    57,    58,
      59,    60,    -1,     3,    -1,    -1,    65,    -1,     8,    -1,
      -1,    -1,    71,    72,    73,    -1,    75,    17,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    49,
      50,    -1,    52,    53,    -1,    17,    56,    -1,    -1,    59,
      22,    23,    24,    -1,    26,    65,    -1,    29,    -1,    -1,
      -1,    71,    72,    73,    36,    75,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    17,    56,    -1,    -1,    59,    22,    23,
      24,    -1,    -1,    65,    -1,    29,    -1,    -1,    -1,    71,
      72,    73,    36,    75,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    49,    50,    -1,    52,    53,
      -1,    17,    56,    57,    -1,    59,    22,    23,    24,    -1,
      -1,    65,    -1,    29,    -1,    31,    -1,    71,    72,    73,
      36,    75,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    49,    50,    -1,    52,    53,    -1,    17,
      56,    -1,    -1,    59,    22,    23,    24,    -1,    -1,    65,
      -1,    29,    -1,    -1,    -1,    71,    72,    73,    36,    75,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    17,    56,    57,
      -1,    59,    22,    23,    24,    -1,    -1,    65,    -1,    29,
      -1,    -1,    -1,    71,    72,    73,    36,    75,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    49,
      50,    -1,    52,    53,    -1,    17,    56,    -1,    -1,    59,
      22,    23,    24,    -1,    -1,    65,    -1,    29,    -1,    -1,
      -1,    71,    72,    73,    36,    75,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    17,    56,    -1,    -1,    59,    22,    23,
      24,    -1,    -1,    65,    -1,    29,    -1,    -1,    -1,    71,
      72,    73,    36,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    49,    50,    -1,    52,    53,
      -1,    17,    56,    -1,    -1,    59,    22,    23,    24,    -1,
      -1,    65,    -1,    29,    -1,    -1,    -1,    71,    72,    73,
      36,    75,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    53,    22,    23,
      24,    -1,    -1,    59,    -1,    29,    -1,    -1,    -1,    65,
      -1,     8,    36,    -1,    -1,    -1,    -1,    73,    -1,    75,
      17,    -1,     8,    -1,    -1,    22,    23,    24,    -1,    53,
      -1,    17,    29,    -1,    -1,    59,    22,    23,    24,    36,
      -1,    65,    -1,    29,    -1,    -1,    -1,    -1,    -1,    73,
      36,    75,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    53,    65,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    73,     8,    75,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    73,    -1,    75,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    33,    34,    -1,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    33,    34,    -1,
      36,    69,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    -1,    74,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    -1,    70,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    -1,    70,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    70,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    33,    34,    -1,
      36,    61,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    77,    78,    24,    59,    75,   127,   128,     0,
      79,     3,    60,    21,    80,   151,    68,     3,    65,    68,
      81,    83,   127,    60,     1,     3,     6,     8,     9,    10,
      13,    15,    16,    17,    18,    19,    20,    22,    23,    27,
      28,    29,    30,    31,    32,    36,    49,    50,    52,    53,
      56,    65,    71,    72,    73,    86,    87,    88,    94,   104,
     106,   110,   111,   112,   113,   114,   115,   120,   124,   127,
     129,   130,   135,   136,   139,   142,   143,   144,   146,   149,
     150,   166,   170,    24,    59,    66,    81,    82,     3,    25,
      84,     3,   124,   126,   127,    17,    36,    53,    65,   127,
     129,   134,   138,   139,   140,   146,   126,   114,   120,    94,
     101,   102,   103,   170,   178,    65,   127,   145,   114,   124,
     105,   178,    35,    57,   123,    73,   112,   170,   177,    35,
     123,   105,    65,    92,    93,   127,    65,    89,   125,   127,
     169,   113,   113,   113,   113,   113,   113,    36,    53,   112,
     121,   133,   139,   141,   146,   113,   113,    11,   112,   176,
      60,    65,    90,   169,     4,    33,    34,    36,    37,    38,
      39,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    65,    68,
      73,    70,    65,   123,     1,   123,     5,    61,    69,    60,
     174,    24,    65,    36,    65,   132,   138,   139,   140,   141,
     146,   132,   132,    68,    35,   100,     5,    69,    60,    11,
     122,   127,   131,   132,   162,   163,   164,    65,    57,   147,
     100,    60,    24,    58,    65,   124,   156,   158,   160,   132,
      99,    53,    58,    65,   124,   155,   157,   158,   159,   168,
      35,    66,    93,   154,   132,    66,    89,   152,    61,    69,
     132,     8,   133,    66,    74,    74,    66,    90,    69,   132,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   116,    66,   121,   171,    65,   127,   112,   176,     1,
      57,    87,    96,   165,   166,   112,   116,   165,   167,   170,
     112,   170,    81,    66,    24,    85,   164,     8,   132,    66,
     127,   167,    26,    26,   178,   132,   122,   131,    61,   175,
      66,   164,   167,   108,   178,    68,    24,   158,    65,   161,
      60,   174,    74,     7,    12,    58,    95,    97,    65,   159,
      53,   159,    60,   174,     3,   179,    61,   132,    99,    60,
     174,    60,   174,   125,   170,    69,    36,    65,   132,   138,
     139,   140,   146,    57,   132,   132,    60,   174,   170,    69,
      57,   112,   117,   118,   172,   173,    11,    61,   175,    31,
     121,    74,    70,   167,    61,   175,   173,    58,    60,    60,
      66,    66,    58,   112,   112,    60,   162,    65,   127,   137,
     138,   139,   140,   141,   146,   148,    66,    58,    14,   107,
     109,   127,    66,   164,   160,    58,   132,   171,    70,    98,
     159,   179,   159,    66,   157,    58,   124,   179,    58,    93,
      66,    89,    66,   170,   132,   116,    90,    91,   153,   169,
      66,   170,   116,    70,    61,   175,    58,   175,   121,    66,
      66,    66,   176,    58,    66,    58,   165,   178,   164,    65,
     148,    20,    96,    66,     5,    61,    69,    70,   167,    66,
      66,   179,   108,    66,   173,    60,   174,   132,   173,    57,
     112,   119,   117,   118,    66,    70,    74,    66,   164,   105,
     108,   148,   112,   112,   179,   179,    14,   107,    58,    91,
      66,    58,   116,   176,    66,   100,   107,    70,    70,   173,
      74,   148,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    84,    85,    85,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    89,    89,    89,    90,
      90,    91,    91,    91,    92,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    95,    96,    98,    97,    99,
      99,   100,   101,   101,   102,   102,   102,   103,   104,   105,
     105,   106,   107,   108,   108,   109,   109,   110,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   123,   123,   124,
     125,   126,   126,   127,   127,   127,   128,   128,   129,   130,
     131,   131,   132,   132,   132,   132,   132,   132,   133,   133,
     133,   133,   134,   134,   134,   134,   134,   135,   135,   136,
     137,   137,   137,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   140,   141,   142,   142,   143,   143,
     144,   145,   145,   146,   147,   147,   148,   148,   148,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   156,   156,   157,   157,   157,   157,   157,   157,
     158,   158,   159,   160,   160,   160,   161,   162,   162,   162,
     162,   163,   163,   164,   164,   165,   165,   165,   165,   165,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   176,   177,   177,   178,   178,   179,
     179
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     3,     0,     3,     2,     5,     3,
       2,     1,     1,     3,     1,     2,     2,     4,     0,     1,
       0,     1,     1,     1,     1,     2,     5,     3,     2,     5,
       7,     3,     2,     5,     3,     1,     2,     4,     3,     4,
       3,     1,     2,     1,     1,     2,     1,     3,     3,     3,
       2,     2,     3,     5,     5,     2,     3,     0,     3,     0,
       2,     3,     4,     4,     5,     1,     1,     2,     2,     1,
       3,     5,     4,     0,     2,     0,     4,     7,     4,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       5,     6,     1,     1,     3,     5,     5,     4,     6,     8,
       1,     5,     5,     5,     7,     1,     0,     3,     1,     4,
       1,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     4,     4,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     2,
       3,     5,     1,     1,     2,     3,     5,     3,     5,     3,
       3,     5,     8,     5,     0,     3,     0,     1,     3,     1,
       4,     2,     0,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     2,     4,     3,     5,     5,
       1,     3,     1,     2,     1,     3,     4,     1,     2,     2,
       1,     1,     3,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     3,     3,     0,     2,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1
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
#line 165 "go.y" /* yacc.c:1646  */
    {
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "file", nkids, kids, leaf);
		ast_root = (yyval.ast);
	}
#line 1996 "go.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		exit(1);
	}
#line 2005 "go.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 183 "go.y" /* yacc.c:1646  */
    { 
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "package", nkids, kids, (yyvsp[-2].t));
	}
#line 2017 "go.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 194 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "imports", 0, NULL, NULL);
	}
#line 2025 "go.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 198 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "imports", nkids, kids, leaf);
	}
#line 2036 "go.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 208 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2047 "go.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 215 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2058 "go.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 222 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2069 "go.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 232 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
#line 2080 "go.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 239 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
#line 2091 "go.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 249 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
#line 2102 "go.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 256 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
#line 2113 "go.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 266 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2124 "go.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 273 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2135 "go.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 280 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2146 "go.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 290 "go.y" /* yacc.c:1646  */
    {
		// TODO: concat package and name
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_package", nkids, kids, leaf);
	}
#line 2158 "go.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 301 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "import_safety", 0, NULL, NULL);
	}
#line 2166 "go.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 305 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_safety", nkids, kids, leaf);
	}
#line 2177 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 318 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", 0, NULL, NULL);
	}
#line 2186 "go.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 323 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
#line 2197 "go.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 330 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
#line 2208 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 337 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
#line 2220 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 345 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", 0, NULL, NULL);
	}
#line 2228 "go.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 352 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2239 "go.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 359 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2250 "go.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 366 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2261 "go.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 373 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2272 "go.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 380 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2283 "go.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 387 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2294 "go.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 394 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2305 "go.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 401 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2316 "go.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 408 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2327 "go.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2338 "go.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 425 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lconst", nkids, kids, leaf);
	}
#line 2349 "go.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 435 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2360 "go.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 442 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2371 "go.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 449 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2382 "go.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 459 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2393 "go.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 466 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2404 "go.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 476 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2415 "go.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 483 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2426 "go.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 490 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2437 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 500 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedclname", nkids, kids, leaf);
	}
#line 2450 "go.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 512 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl", nkids, kids, leaf);
	}
#line 2461 "go.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 522 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2472 "go.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 529 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2483 "go.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 536 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2494 "go.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 543 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2505 "go.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 550 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2516 "go.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 557 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2527 "go.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 567 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2538 "go.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 574 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2549 "go.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 581 "go.y" /* yacc.c:1646  */
    {
		// TODO: maybe concat tokens?
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2561 "go.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 589 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2572 "go.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 600 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "compound_stmt", nkids, kids, leaf);
	}
#line 2583 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 610 "go.y" /* yacc.c:1646  */
    {
		// If the last token read by the lexer was consumed
		// as part of the case, clear it (parser has cleared yychar).
		// If the last token read by the lexer was the lookahead
		// leave it alone (parser has it cached in yychar).
		// This is so that the stmt_list action doesn't look at
		// the case tokens if the stmt_list is empty.
		yylast = yychar;
	}
#line 2597 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 620 "go.y" /* yacc.c:1646  */
    {
		int last;

		// This is the only place in the language where a statement
		// list is not allowed to drop the final semicolon, because
		// it's the only place where a statement list is not followed 
		// by a closing brace.  Handle the error for pedantry.

		// Find the final token of the statement list.
		// yylast is lookahead; yyprev is last of stmt_list
		last = yyprev;

		if(last > 0 && last != ';' && yychar != '}')
			yyerror("missing statement after label");

		struct token *leaf = NULL; // TODO: not sure ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "caseblock", nkids, kids, leaf);
	}
#line 2622 "go.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 644 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "caseblock_list", 0, NULL, NULL);
	}
#line 2630 "go.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 648 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "caseblock_list", nkids, kids, leaf);
	}
#line 2641 "go.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 659 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "loop_body", nkids, kids, leaf);
	}
#line 2652 "go.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 669 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
#line 2663 "go.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 676 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t); // TODO: concat tokens
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
#line 2674 "go.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 686 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2685 "go.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 693 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2696 "go.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 700 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2707 "go.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 710 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_body", nkids, kids, leaf);
	}
#line 2718 "go.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 721 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_stmt", nkids, kids, leaf);
	}
#line 2729 "go.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 731 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
#line 2740 "go.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 738 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
#line 2751 "go.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 752 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_stmt", nkids, kids, leaf);
	}
#line 2762 "go.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 763 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens "elseif"
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif", nkids, kids, leaf);
	}
#line 2773 "go.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 773 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "elseif_list", 0, NULL, NULL);
	}
#line 2781 "go.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 777 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif_list", nkids, kids, leaf);
	}
#line 2792 "go.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 787 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "else", 0, NULL, NULL);
	}
#line 2800 "go.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 792 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "else", nkids, kids, leaf);
	}
#line 2811 "go.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 805 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-6].t); // TODO: maybe concat tokens
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "switch_stmt", nkids, kids, leaf);
	}
#line 2822 "go.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 816 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "select_stmt", nkids, kids, leaf);
	}
#line 2833 "go.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 829 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2844 "go.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 836 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2855 "go.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 843 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2866 "go.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 850 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2877 "go.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 857 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2888 "go.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 864 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2899 "go.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 871 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2910 "go.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 878 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2921 "go.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 885 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2932 "go.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 892 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2943 "go.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 899 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2954 "go.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 906 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2965 "go.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 913 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2976 "go.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 920 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2987 "go.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 927 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2998 "go.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 934 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3009 "go.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 941 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3020 "go.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 948 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3031 "go.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 955 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3042 "go.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 963 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3053 "go.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 970 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3064 "go.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 980 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3075 "go.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 987 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3086 "go.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 994 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3097 "go.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1001 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3108 "go.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1008 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3119 "go.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1015 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3130 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1022 "go.y" /* yacc.c:1646  */
    {
		yyerror("the bitwise complement operator is ^");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3142 "go.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1030 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3153 "go.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1037 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3164 "go.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1051 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3175 "go.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1058 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3186 "go.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1065 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3197 "go.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1075 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3208 "go.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1082 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3219 "go.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1089 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3230 "go.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1096 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3241 "go.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1103 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3252 "go.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1110 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3263 "go.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1117 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3274 "go.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1124 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3285 "go.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1131 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3296 "go.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1138 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3307 "go.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1145 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3318 "go.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1152 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3329 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1159 "go.y" /* yacc.c:1646  */
    {
		yyerror("cannot parenthesize type in composite literal");

		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3342 "go.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1168 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3353 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1178 "go.y" /* yacc.c:1646  */
    {
		// composite expression.
		// make node early so we get the right line number.
		(yyval.ast) = new_tree_node(++ruleno, "start_complit", 0, NULL, NULL);
	}
#line 3363 "go.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1187 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval", nkids, kids, leaf);
	}
#line 3374 "go.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1197 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
#line 3385 "go.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1204 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
#line 3396 "go.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1214 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
#line 3407 "go.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1221 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
#line 3418 "go.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1231 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
#line 3429 "go.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1238 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
#line 3440 "go.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1248 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
#line 3451 "go.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1255 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
#line 3462 "go.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1265 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "name_or_type", nkids, kids, leaf);
	}
#line 3473 "go.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1275 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3484 "go.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1282 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3495 "go.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1297 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name", nkids, kids, leaf);
	}
#line 3506 "go.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1307 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name", nkids, kids, leaf);
	}
#line 3517 "go.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1317 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "onew_name", 0, NULL, NULL);
	}
#line 3525 "go.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1321 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "onew_name", nkids, kids, leaf);
	}
#line 3536 "go.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1331 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3547 "go.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1338 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3558 "go.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1345 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3569 "go.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1355 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3580 "go.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1362 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3591 "go.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1372 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "name", nkids, kids, leaf);
	}
#line 3602 "go.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1382 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "labelname", nkids, kids, leaf);
	}
#line 3613 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1401 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");

		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3626 "go.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1410 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3637 "go.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1420 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3648 "go.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1427 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3659 "go.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1434 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3670 "go.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1441 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3681 "go.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1448 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3692 "go.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1455 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3703 "go.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1465 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3714 "go.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1472 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3725 "go.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1479 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3736 "go.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1486 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3747 "go.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1496 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3758 "go.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1503 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3769 "go.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1510 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3780 "go.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1517 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3791 "go.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1524 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3802 "go.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1534 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "convtype", nkids, kids, leaf);
	}
#line 3813 "go.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1541 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "convtype", nkids, kids, leaf);
	}
#line 3824 "go.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1550 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "comptype", nkids, kids, leaf);
	}
#line 3835 "go.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1560 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3846 "go.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1567 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3857 "go.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1574 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3868 "go.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1581 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3879 "go.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1588 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3890 "go.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1598 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
#line 3901 "go.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1605 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
#line 3912 "go.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1615 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3923 "go.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1622 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3934 "go.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1629 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3945 "go.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1636 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3956 "go.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1643 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].t), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3967 "go.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1650 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3978 "go.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1657 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3989 "go.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1667 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ptrtype", nkids, kids, leaf);
	}
#line 4000 "go.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1677 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	// TODO: concat tokens ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "recvchantype", nkids, kids, leaf);
	}
#line 4011 "go.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1687 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 4022 "go.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1694 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 4033 "go.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1704 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
#line 4044 "go.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1711 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
#line 4055 "go.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1725 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xfndcl", nkids, kids, leaf);
	}
#line 4066 "go.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1735 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 4077 "go.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1742 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 4088 "go.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1769 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fntype", nkids, kids, leaf);
	}
#line 4099 "go.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1779 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "fnbody", 0, NULL, NULL);
	}
#line 4107 "go.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1783 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnbody", nkids, kids, leaf);
	}
#line 4118 "go.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1793 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "fnres", 0, NULL, NULL);
	}
#line 4126 "go.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1797 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnres", nkids, kids, leaf);
	}
#line 4137 "go.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1804 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnres", nkids, kids, leaf);
	}
#line 4148 "go.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1814 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnlitdcl", nkids, kids, leaf);
	}
#line 4159 "go.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1824 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 4170 "go.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1831 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 4181 "go.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1846 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "xdcl_list", 0, NULL, NULL);
	}
#line 4189 "go.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1850 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl_list", nkids, kids, leaf);
	}
#line 4200 "go.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1860 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
#line 4211 "go.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1867 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
#line 4222 "go.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1877 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
#line 4233 "go.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1884 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
#line 4244 "go.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1894 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
#line 4255 "go.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1901 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
#line 4266 "go.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1911 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
#line 4277 "go.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1918 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
#line 4288 "go.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1928 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
	}
#line 4299 "go.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1935 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
	}
#line 4310 "go.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1945 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4321 "go.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1952 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4332 "go.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1959 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4343 "go.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1966 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4354 "go.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1973 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4365 "go.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1980 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4376 "go.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1990 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 4387 "go.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1997 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 4398 "go.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 2007 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "embed", nkids, kids, leaf);
	}
#line 4409 "go.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 2017 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4420 "go.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 2024 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4431 "go.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 2031 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4442 "go.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 2041 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "indcl", nkids, kids, leaf);
	}
#line 4453 "go.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 2054 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4464 "go.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 2061 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4475 "go.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 2068 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4486 "go.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 2075 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4497 "go.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 2085 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
#line 4508 "go.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 2092 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
#line 4519 "go.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 2102 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oarg_type_list_ocomma", 0, NULL, NULL);
	}
#line 4527 "go.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 2106 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oarg_type_list_ocomma", nkids, kids, leaf);
	}
#line 4538 "go.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 2119 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "stmt", 0, NULL, NULL);
	}
#line 4546 "go.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 2123 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4557 "go.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 2130 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4568 "go.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 2137 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4579 "go.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 2144 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4590 "go.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 2154 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4601 "go.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 2161 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4612 "go.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 2168 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4623 "go.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 2175 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4634 "go.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 2182 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4645 "go.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 2190 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 22;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4656 "go.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 2197 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4667 "go.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 2204 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4678 "go.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 2211 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4689 "go.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 2218 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4700 "go.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 2225 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4711 "go.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 2232 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4722 "go.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2239 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4733 "go.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2249 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
#line 4744 "go.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2256 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
#line 4755 "go.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 2266 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
#line 4766 "go.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 2273 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
#line 4777 "go.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 2283 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
#line 4788 "go.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 2290 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
#line 4799 "go.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 2300 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
#line 4810 "go.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 2307 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
#line 4821 "go.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 2317 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
#line 4832 "go.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 2324 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
#line 4843 "go.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 2337 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4854 "go.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 2344 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4865 "go.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 2351 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4876 "go.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 2358 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4887 "go.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 2368 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "braced_keyval_list", 0, NULL, NULL);
	}
#line 4895 "go.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 2372 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "braced_keyval_list", nkids, kids, leaf);
	}
#line 4906 "go.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 2385 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osemi", 0, NULL, NULL);
	}
#line 4914 "go.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 2389 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osemi", 0, NULL, (yyvsp[0].t));
	}
#line 4922 "go.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 2396 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "ocomma", 0, NULL, NULL);
	}
#line 4930 "go.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2400 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "ocomma", 0, NULL, (yyvsp[0].t));
	}
#line 4938 "go.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2407 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oexpr", 0, NULL, NULL);
	}
#line 4946 "go.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2411 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oexpr", nkids, kids, leaf);
	}
#line 4957 "go.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2421 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oexpr_list", 0, NULL, NULL);
	}
#line 4965 "go.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2425 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oexpr_list", nkids, kids, leaf);
	}
#line 4976 "go.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2435 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osimple_stmt", 0, NULL, NULL);
	}
#line 4984 "go.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 2439 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "osimple_stmt", nkids, kids, leaf);
	}
#line 4995 "go.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 2491 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oliteral", 0, NULL, NULL);
	}
#line 5003 "go.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 2495 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "oliteral", nkids, kids, leaf);
	}
#line 5014 "go.tab.c" /* yacc.c:1646  */
    break;


#line 5018 "go.tab.c" /* yacc.c:1646  */
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
#line 2892 "go.y" /* yacc.c:1906  */

