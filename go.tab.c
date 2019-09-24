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
#define YYLAST   1940

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
      66,    67,    53,    49,    61,    50,    63,    54,     2,     2,
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
      45,    46,    47,    48,    64,    65,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   179,   184,   195,   199,   209,   216,   223,
     233,   240,   250,   257,   267,   274,   281,   291,   302,   306,
     319,   324,   331,   338,   346,   353,   360,   367,   374,   381,
     388,   395,   402,   409,   416,   426,   436,   443,   450,   460,
     467,   477,   484,   491,   501,   513,   523,   530,   537,   544,
     551,   558,   568,   575,   582,   590,   600,   612,   611,   645,
     649,   659,   670,   677,   687,   694,   701,   711,   721,   732,
     739,   750,   763,   774,   778,   788,   792,   803,   816,   830,
     837,   844,   851,   858,   865,   872,   879,   886,   893,   900,
     907,   914,   921,   928,   935,   942,   949,   956,   963,   971,
     981,   988,   995,  1002,  1009,  1016,  1023,  1031,  1038,  1052,
    1059,  1066,  1076,  1083,  1090,  1097,  1104,  1111,  1118,  1125,
    1132,  1139,  1146,  1153,  1160,  1169,  1179,  1188,  1198,  1205,
    1215,  1222,  1232,  1239,  1249,  1256,  1266,  1276,  1283,  1298,
    1308,  1318,  1322,  1332,  1339,  1346,  1356,  1363,  1373,  1383,
    1402,  1411,  1421,  1428,  1435,  1442,  1449,  1456,  1466,  1473,
    1480,  1487,  1497,  1504,  1511,  1518,  1525,  1535,  1542,  1551,
    1561,  1568,  1575,  1582,  1589,  1599,  1606,  1616,  1623,  1630,
    1637,  1644,  1651,  1658,  1668,  1678,  1688,  1695,  1705,  1712,
    1726,  1736,  1743,  1770,  1780,  1784,  1794,  1798,  1805,  1815,
    1825,  1832,  1847,  1851,  1861,  1868,  1878,  1885,  1895,  1902,
    1912,  1919,  1929,  1936,  1946,  1953,  1960,  1967,  1974,  1981,
    1991,  1998,  2008,  2018,  2025,  2032,  2042,  2055,  2062,  2069,
    2076,  2086,  2093,  2103,  2107,  2120,  2124,  2131,  2138,  2145,
    2155,  2162,  2169,  2176,  2183,  2190,  2198,  2205,  2212,  2219,
    2226,  2233,  2240,  2250,  2257,  2267,  2274,  2284,  2291,  2301,
    2308,  2318,  2325,  2338,  2345,  2352,  2359,  2369,  2373,  2386,
    2390,  2397,  2401,  2408,  2412,  2422,  2426,  2436,  2440,  2492,
    2496
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
  "','", "'`'", "'.'", "NotPackage", "NotParen", "'('", "')'",
  "PreferToRightParen", "'='", "':'", "'!'", "'~'", "'['", "']'", "'@'",
  "$accept", "file", "package", "imports", "import", "import_stmt",
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
      59,    44,    96,    46,   304,   305,    40,    41,   306,    61,
      58,    33,   126,    91,    93,    64
};
# endif

#define YYPACT_NINF -449

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-449)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,     5,    46,  -449,  -449,  -449,    45,     1,  -449,  -449,
      70,     3,  -449,    72,    49,   970,    34,  -449,   120,    53,
    -449,   104,   146,  -449,  -449,  -449,     5,   760,  -449,     5,
     536,  -449,  1377,   248,   536,     5,  1377,   121,    94,  1377,
     135,   121,  1377,   313,   333,  1377,  1377,  1377,  1377,  1377,
    1377,  1415,  1377,  1377,   514,   133,  -449,   343,  -449,  -449,
    -449,  -449,  -449,  1641,  -449,  -449,   138,   123,  -449,   144,
    -449,   149,   137,   121,   158,  -449,  -449,  -449,   163,    80,
    -449,  -449,    36,  -449,  -449,  -449,  -449,  -449,   176,   215,
    -449,  -449,  -449,  -449,  -449,   190,  1524,  1524,  1524,  -449,
     179,  -449,  -449,  -449,  -449,  -449,  -449,   208,   123,  -449,
    -449,   224,  -449,    42,   198,   842,   195,   205,   238,  -449,
     224,   203,  -449,  -449,   124,  1524,  1813,   206,  -449,  -449,
     260,   236,    98,  1524,  -449,  -449,   250,  -449,  -449,  -449,
     619,  -449,  -449,  -449,  -449,  -449,  -449,  1453,  1415,  1813,
     213,  -449,   106,  -449,    38,  -449,  -449,   207,  1813,   212,
    -449,   318,  -449,   749,  1377,  1377,  1377,  1377,  -449,  1377,
    1377,  1377,  -449,  1377,  1377,  1377,  1377,  1377,  1377,  1377,
    1377,  1377,  1377,  1377,  1377,  1377,  1377,  -449,   344,   860,
    1377,  1055,  1377,  -449,  -449,  1128,  1377,  1377,  1377,   201,
     221,   270,   842,   287,  1524,  -449,  -449,  -449,  -449,  -449,
    -449,  -449,   230,     5,  1128,  -449,  1187,  1225,  1377,  1524,
    -449,   842,  -449,  -449,  -449,   244,   239,   842,  1128,  -449,
    -449,  1377,   111,  -449,   306,   265,   276,  -449,  -449,   269,
      50,     8,  -449,    41,  -449,   292,  -449,  -449,   350,  1491,
    -449,  -449,  -449,   294,  -449,  -449,  -449,   314,     5,  1377,
     309,  1532,  -449,   324,  1524,  1524,  -449,   326,  1377,   327,
    1813,  1884,  -449,  1837,   668,   668,   668,   668,  -449,   668,
     668,  1861,  -449,   413,   413,   413,   413,  -449,  -449,  -449,
    -449,  1263,  1301,  -449,  -449,  -449,    57,  1673,   293,  -449,
    1128,  -449,  -449,  -449,  -449,  1789,  1263,  -449,    -7,   206,
    1813,   206,  -449,  -449,  -449,   337,   320,  1524,   339,  -449,
    -449,    82,  1377,  1377,   352,  -449,  -449,  -449,   842,  -449,
    1550,   347,    92,   390,  -449,     5,   357,   348,   842,  -449,
     377,   366,  1524,  1415,   356,  -449,  -449,  -449,   306,   350,
     306,   360,   275,   371,  -449,  -449,     5,   350,   271,     5,
     367,     5,   372,  -449,   206,  1377,  1598,  1524,  -449,   216,
     234,   298,   303,  -449,  -449,  -449,     5,   373,   206,  1377,
    -449,  1705,  -449,  -449,   392,   375,   384,   389,   397,  1415,
     393,  -449,  1377,   100,  -449,   395,   380,  -449,  1055,  -449,
    1550,  -449,  -449,  1813,  1813,  1377,  -449,   842,   399,  -449,
    -449,  -449,  -449,  -449,  -449,  -449,  1550,  -449,    97,  -449,
    -449,  -449,  -449,   396,  -449,  -449,  -449,    31,  -449,  1055,
     404,  -449,   405,   350,  -449,  -449,  -449,  -449,  -449,  -449,
    -449,  -449,  -449,   206,   406,  1263,  -449,  -449,   414,   749,
    -449,   206,  1263,  1339,  1263,  -449,  -449,  -449,  -449,   408,
    -449,  -449,   132,  -449,  -449,  -449,  -449,  -449,   409,   842,
    -449,  1377,  -449,  1550,  1377,  1415,  1377,  -449,   418,   350,
     350,  -449,   445,   388,   421,     5,   419,   327,   422,  -449,
    1813,  -449,  -449,  -449,  -449,  1377,  -449,  -449,   425,   224,
     445,  -449,  1733,  1761,  -449,  -449,   461,   471,  -449,  -449,
    -449,  -449,  1263,   420,  1550,  -449,   471,  -449,  -449,   435,
    -449,  -449,  -449
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
     125,    23,     0,   146,   147,    16,     9,    12,   269,     0,
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
      95,   267,     0,   114,   109,   261,   271,   274,     0,   239,
       0,   237,   236,   245,   238,   271,   267,   253,     0,    49,
     260,    48,    13,     8,    19,     0,     0,     0,     0,   166,
     176,     0,     0,     0,     0,   151,   228,   229,   272,   234,
     196,     0,     0,    75,    70,     0,   220,     0,   233,   223,
     270,     0,     0,     0,     0,    78,    57,    60,     0,   279,
       0,     0,   270,     0,   280,   215,     0,   279,     0,   270,
       0,   270,     0,   258,    38,     0,     0,     0,   185,   156,
     154,   155,   153,   126,   178,   177,   270,     0,    40,     0,
     126,   128,   263,   264,   271,     0,     0,     0,   271,   272,
       0,   117,   273,     0,   272,     0,     0,   200,     0,    17,
     196,   157,    61,    63,    62,   277,   232,   233,   148,   197,
     174,   172,   173,   170,   171,   193,   196,   195,     0,    74,
      71,   221,   225,     0,   213,   188,   181,     0,    55,     0,
       0,   217,     0,   279,   211,   186,   256,   214,    73,   209,
      33,   205,    26,    37,     0,   267,    41,   206,   269,    43,
      29,    39,   267,     0,   272,   268,   123,   116,   115,     0,
     262,   110,     0,    56,   121,   122,   254,    64,     0,   233,
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
    -449,  -449,  -449,  -449,  -449,   -12,  -449,  -449,  -449,  -449,
    -449,   485,  -449,  -126,   -31,    21,  -449,  -118,   -30,  -449,
      89,  -449,  -449,   258,  -116,  -449,  -449,  -449,  -449,   -41,
    -449,  -448,  -396,  -449,  -449,  -449,   564,    37,   214,  -449,
    -162,    55,    56,  -449,   223,   -38,   290,   -19,     9,   256,
     486,   469,  -449,    83,  -449,   295,   450,   370,  -449,  -449,
    -449,  -449,   -18,   -27,    -9,    16,  -449,  -449,  -449,  -449,
      28,  -449,  -395,  -449,  -449,  -449,  -449,  -449,  -449,  -449,
    -449,   167,  -107,  -216,   180,  -449,   193,  -449,  -194,  -186,
     508,  -198,  -449,   -54,    11,   181,  -449,  -286,  -208,  -233,
    -171,  -449,   -21,  -334
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    88,    21,    90,   315,
      55,   301,    57,   137,   446,   447,   133,   134,    58,   346,
     302,   347,   429,   240,   215,   110,   111,   112,    59,   120,
      60,   419,   333,   420,    61,    62,    63,    64,    65,    66,
     291,   382,   383,   491,    67,   295,   220,   124,    68,   138,
      93,    99,     8,    70,    71,   222,   223,   151,   101,    72,
      73,   409,   206,    74,   208,   209,    75,    76,    77,   117,
      78,   229,   415,    79,    80,    15,   257,   448,   253,   245,
     236,   246,   247,   248,   238,   339,   224,   225,   226,   307,
     304,   308,   249,   140,    82,   296,   384,   385,   200,   329,
     159,   128,   121,   355
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   131,   109,   163,   230,   303,   109,    87,   316,   102,
     256,   114,   109,   150,   252,   431,   321,   237,   104,   298,
     396,   470,   130,   437,   152,   349,   162,   351,   341,     4,
     332,   306,   336,   331,   507,    92,   474,   353,    92,  -199,
       1,   196,   482,   113,   119,   360,     9,   216,    11,   362,
     127,   397,   516,   398,   193,   105,    17,   343,    83,   377,
     195,    12,   344,   390,     5,   336,    16,   153,   388,   207,
     207,   207,   395,  -199,   348,    17,   500,     4,   501,   154,
       6,   194,   141,   142,   143,   144,   145,   146,   207,   155,
     156,    13,   475,    84,   350,  -199,     4,   197,   207,   481,
     476,   477,   393,   197,  -167,   198,   207,   163,   345,    23,
     100,   217,     5,   207,  -220,   122,    18,   471,   389,   521,
      86,   152,     4,    85,   210,   210,   210,   337,     6,    89,
     267,     5,   430,   235,   432,    18,   207,   123,    19,   244,
     402,  -169,   398,   210,   423,   504,   505,     6,   232,    91,
     417,   455,   398,   210,   300,   459,   122,     5,   463,   484,
     398,   210,   152,  -169,   153,   251,   488,   125,   210,  -220,
     129,  -220,  -168,     6,   335,   207,   154,   207,   123,   100,
     100,   100,   233,     5,   141,   145,   188,   312,   109,   189,
     234,   210,   207,   160,   207,   187,   190,   324,   100,     6,
     207,   109,   495,   192,    17,   153,   496,   309,   100,   311,
     334,   445,   466,   468,  -139,  -250,   100,   154,   452,   191,
    -250,   462,   207,   100,  -168,     4,   519,   309,   311,  -167,
     210,   478,   210,   237,   370,   441,   199,   207,   207,   201,
     486,   439,   213,   369,   107,  -249,   100,   210,   118,   210,
    -249,  -165,   371,   108,   387,   210,   202,   108,   218,   214,
       5,   227,   228,   231,    18,   152,  -250,   197,  -250,  -163,
     364,   250,     4,  -165,     4,   498,     6,   210,   343,   378,
     263,   264,  -165,   344,   232,   100,   265,   100,   313,   372,
     207,  -163,   210,   210,   314,   317,  -249,   319,  -249,   232,
    -163,   207,   100,   411,   100,   328,   330,     5,   153,     5,
     100,   207,   410,   241,   115,   207,   152,   255,   242,     5,
     154,   412,   449,     6,   513,     6,   243,   512,   241,   438,
     336,   338,   100,  -164,     5,     6,   340,     4,  -162,   207,
     207,   243,     4,   342,   100,   210,   413,   100,   100,   235,
       6,   460,   352,   354,   359,  -164,   210,     4,   414,   153,
    -162,   244,   152,   392,  -164,   436,   210,     4,     4,  -162,
     210,   154,     5,   411,   361,   109,   443,     5,   365,   132,
     207,   373,   410,   515,   467,   266,   376,   400,     6,   411,
     451,   412,     5,     6,   210,   210,   379,   399,   410,   136,
     100,   232,     5,     5,   418,   153,   401,   412,     6,   161,
     292,   100,   405,   100,   416,   422,   413,   154,     6,     6,
     335,   100,   207,  -166,   425,   100,   428,   433,   414,   435,
     499,   449,   413,   456,   440,   210,     5,   460,   465,   442,
     450,   109,   207,   234,   414,  -166,   411,   166,   152,   100,
     100,   457,     6,   454,  -166,   410,   458,   174,   394,   506,
     461,   178,   464,   473,   412,   469,   183,   184,   185,   186,
       7,   479,   480,   483,   485,   494,   497,   210,   398,   508,
     511,   471,    22,   100,    69,   -74,   510,   411,    22,   413,
     100,   153,   514,   522,   520,    94,   410,   210,    94,   100,
      56,   414,   116,   154,    94,   412,   509,   472,   358,   492,
     493,   326,   135,   139,   363,   106,   327,    25,   262,   434,
     424,   406,    27,    81,   427,   157,   139,     0,     0,     0,
     413,    95,   100,     0,     0,     0,    37,    38,     4,    25,
       0,     0,   414,    41,    27,     0,   205,   211,   212,     0,
      45,     0,   100,    95,     0,     0,   100,     0,    37,    38,
       4,     0,     0,    46,    47,    41,    48,    49,     0,     0,
      50,     0,     0,     5,     0,   239,     0,     0,     0,     0,
      51,     0,     0,   254,   221,    52,    53,    54,     0,     6,
     260,     0,     0,    94,     0,     5,     0,   100,     0,    94,
       0,   135,    51,   126,     0,   139,     0,     0,     0,    54,
       0,     6,     0,   269,     0,   149,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
     139,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,    37,    38,     4,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,   318,   203,     0,   293,     0,     0,
      69,     0,     0,     0,    69,     0,     0,     0,    22,   325,
       0,   221,    97,     0,     0,     0,     0,     0,     5,     0,
     258,     0,   320,    69,     0,   204,     0,     0,   259,     0,
       0,     0,    54,     0,     6,     0,   221,    69,     0,   357,
       0,     0,   166,     0,     0,     0,     0,     0,     0,     0,
       0,   368,   174,     0,   374,   375,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,     0,   139,   270,   271,
     272,   273,     0,   274,   275,   276,     0,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,     0,     0,   149,   297,     0,   305,    27,     0,     0,
     126,   310,   126,     0,     0,     0,    95,   368,    27,    69,
       0,    37,    38,     4,     0,     0,     0,    95,    41,     0,
     126,   126,    37,    38,     4,   203,     0,     0,     0,    41,
       0,     0,   426,     0,     0,     0,    96,   221,     0,   408,
       0,     0,    97,     0,   421,     0,     0,   221,     5,    94,
     258,     0,     0,    97,     0,   204,   205,   444,   268,     5,
       0,    94,    54,   126,     6,    94,    98,     0,   135,     0,
     139,     0,   126,    54,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
      27,     0,     0,   219,     0,   381,   149,     0,     0,    95,
       0,     0,     0,    25,    37,    38,     4,    69,    27,     0,
     381,    41,     0,     0,     0,     0,   221,    95,   203,     0,
       0,     0,    37,    38,     4,     0,   403,   404,     0,    41,
       0,     0,     0,     0,     0,    97,   147,     0,    69,   487,
       0,     5,     0,     0,     0,     0,     0,   149,   204,    46,
      47,     0,    48,   148,     0,    54,    50,     6,     0,     5,
       0,     0,     0,     0,     0,     0,    51,   294,     0,   126,
       0,    52,    53,    54,     0,     6,     0,     0,   221,     0,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   149,   139,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -2,    24,     0,    25,     0,     0,    26,     0,    27,    28,
      29,     0,     0,    30,     0,    31,    32,    33,    34,    35,
      36,     0,    37,    38,     4,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,    45,     0,     0,   381,
       0,     0,     0,     0,     0,     0,   381,   490,   381,    46,
      47,     0,    48,    49,     0,     0,    50,     0,     0,     5,
     -20,     0,     0,     0,     0,     0,    51,     0,   502,   149,
     503,    52,    53,    54,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,    25,   158,
       0,    26,  -235,    27,    28,    29,     0,  -235,    30,     0,
      31,    32,    95,    34,    35,    36,   381,    37,    38,     4,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,     0,    48,    49,     0,
       0,    50,   300,  -235,     5,  -235,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,    52,    53,    54,   299,
       6,    25,     0,     0,    26,     0,    27,    28,    29,     0,
       0,    30,     0,    31,    32,    95,    34,    35,    36,     0,
      37,    38,     4,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     0,
      48,    49,     0,     0,    50,   300,  -235,     5,  -235,     0,
      25,     0,     0,     0,    51,    27,     0,     0,     0,    52,
      53,    54,     0,     6,    95,     0,     0,     0,     0,    37,
      38,     4,     0,   322,     0,     0,    41,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    27,     0,     0,    46,    47,     0,    48,
      49,     0,    95,    50,     0,     0,     5,    37,    38,     4,
       0,   323,     0,    51,    41,     0,     0,     0,    52,    53,
      54,    45,     6,     0,     0,     0,    25,     0,     0,     0,
       0,    27,     0,     0,    46,    47,     0,    48,    49,     0,
      95,    50,     0,     0,     5,    37,    38,     4,     0,     0,
       0,    51,    41,     0,     0,     0,    52,    53,    54,    45,
       6,     0,     0,     0,    25,     0,     0,     0,     0,    27,
       0,     0,    46,    47,     0,    48,    49,     0,    95,    50,
     380,     0,     5,    37,    38,     4,     0,     0,     0,    51,
      41,     0,   386,     0,    52,    53,    54,   147,     6,     0,
       0,     0,    25,     0,     0,     0,     0,    27,     0,     0,
      46,    47,     0,    48,   148,     0,    95,    50,     0,     0,
       5,    37,    38,     4,     0,     0,     0,    51,    41,     0,
       0,     0,    52,    53,    54,    45,     6,     0,     0,     0,
      25,     0,     0,     0,     0,    27,     0,     0,    46,    47,
       0,    48,    49,     0,    95,    50,   489,     0,     5,    37,
      38,     4,     0,     0,     0,    51,    41,     0,     0,     0,
      52,    53,    54,    45,     6,     0,     0,     0,    25,     0,
       0,     0,     0,    27,     0,     0,    46,    47,     0,    48,
      49,     0,    95,    50,     0,     0,     5,    37,    38,     4,
       0,     0,     0,    51,    41,     0,     0,     0,    52,    53,
      54,   147,     6,     0,     0,     0,    25,     0,     0,     0,
       0,   261,     0,     0,    46,    47,     0,    48,   148,     0,
      95,    50,     0,     0,     5,    37,    38,     4,     0,     0,
       0,    51,    41,     0,     0,     0,    52,    53,    54,    45,
       6,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    46,    47,     0,    48,    49,     0,    95,    50,
       0,     0,     5,    37,    38,     4,     0,     0,     0,    51,
      41,     0,     0,     0,    52,    53,    54,   203,     6,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      27,    95,     0,     0,    97,     0,    37,    38,     4,    95,
       5,     0,   356,    41,    37,    38,     4,   204,    27,     0,
     203,    41,     0,     0,    54,     0,     6,    95,   366,     0,
       0,     0,    37,    38,     4,     0,     0,    97,     0,    41,
       0,     0,     0,     5,     0,    97,   203,     0,     0,     0,
     204,     5,     0,     0,     0,     0,     0,    54,   367,     6,
       0,     0,     0,    97,     0,    54,   261,     6,     0,     5,
       0,     0,     0,     0,     0,    95,   407,     0,     0,     0,
      37,    38,     4,    54,     0,     6,     0,    41,     0,     0,
       0,     0,     0,     0,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,  -259,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,   204,     0,     0,     0,     0,     0,
       0,    54,     0,     6,   165,   166,     0,   167,   168,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,  -259,     0,     0,     0,   165,   166,     0,   167,
    -259,   169,   170,   171,     0,     0,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
       0,   167,     0,   169,   170,   171,     0,   391,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,     0,     0,     0,   165,   166,     0,   167,
       0,   169,   170,   171,     0,   453,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,     0,     0,     0,   165,   166,     0,   167,     0,   169,
     170,   171,     0,   517,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,   165,   166,     0,   167,     0,   169,   170,   171,
       0,   518,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   165,   166,     0,   167,
     394,   169,   170,   171,     0,     0,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     165,   166,     0,     0,     0,   169,   170,   171,     0,     0,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   165,   166,     0,     0,     0,   169,
     170,   171,     0,     0,   173,   174,   175,   176,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   166,     0,
       0,     0,   169,   170,   171,     0,     0,   173,   174,   175,
     176,     0,   178,   179,   180,   181,   182,   183,   184,   185,
     186
};

static const yytype_int16 yycheck[] =
{
      27,    42,    32,    57,   120,   191,    36,    19,   202,    27,
     136,    32,    42,    51,   132,   349,   214,   124,    27,   190,
     306,   416,    41,   357,    51,   241,    57,   243,   236,    24,
     228,   193,    24,   227,   482,    26,     5,   245,    29,     1,
      25,     5,   438,    32,    35,   253,     0,     5,     3,   257,
      39,    58,   500,    60,    73,    27,     3,     7,    24,   267,
      79,    60,    12,   296,    59,    24,    63,    51,    11,    96,
      97,    98,   305,    35,    66,     3,   472,    24,   473,    51,
      75,     1,    45,    46,    47,    48,    49,    50,   115,    52,
      53,    21,    61,    59,    53,    57,    24,    61,   125,   433,
      69,    70,   300,    61,    66,    69,   133,   161,    58,    60,
      27,    69,    59,   140,     3,    35,    63,    20,    61,   514,
      67,   148,    24,     3,    96,    97,    98,   234,    75,    25,
     161,    59,   348,   124,   350,    63,   163,    57,    66,   130,
      58,    35,    60,   115,   338,   479,   480,    75,    24,     3,
      58,   384,    60,   125,    57,   388,    35,    59,    58,   445,
      60,   133,   189,    57,   148,    67,   452,    73,   140,    58,
      35,    60,    66,    75,    63,   202,   148,   204,    57,    96,
      97,    98,    58,    59,   147,   148,    63,   199,   218,    66,
      66,   163,   219,    60,   221,    57,    73,   218,   115,    75,
     227,   231,    70,    66,     3,   189,    74,   196,   125,   198,
     231,   373,   398,   407,    70,     7,   133,   189,   380,    70,
      12,   392,   249,   140,    66,    24,   512,   216,   217,    66,
     202,   429,   204,   340,   261,   361,    60,   264,   265,    24,
     448,   359,    63,   261,    30,     7,   163,   219,    34,   221,
      12,    35,   261,    30,   292,   227,    66,    34,    60,    35,
      59,    66,    57,    60,    63,   292,    58,    61,    60,    35,
     259,    35,    24,    57,    24,   469,    75,   249,     7,   268,
      67,    74,    66,    12,    24,   202,    74,   204,    67,   261,
     317,    57,   264,   265,    24,     8,    58,    67,    60,    24,
      66,   328,   219,   330,   221,    61,    67,    59,   292,    59,
     227,   338,   330,    53,    66,   342,   343,    67,    58,    59,
     292,   330,   376,    75,   495,    75,    66,   489,    53,    58,
      24,    66,   249,    35,    59,    75,    60,    24,    35,   366,
     367,    66,    24,    74,   261,   317,   330,   264,   265,   340,
      75,   389,    60,     3,    60,    57,   328,    24,   330,   343,
      57,   352,   389,    70,    66,   356,   338,    24,    24,    66,
     342,   343,    59,   400,    60,   405,   365,    59,    69,    66,
     407,    57,   400,   499,   405,    67,    60,    67,    75,   416,
     379,   400,    59,    75,   366,   367,    69,    60,   416,    66,
     317,    24,    59,    59,    14,   389,    67,   416,    75,    66,
      66,   328,    60,   330,    67,    67,   400,   389,    75,    75,
      63,   338,   449,    35,    58,   342,    70,    67,   400,    58,
     471,   485,   416,    58,    67,   407,    59,   475,    58,    67,
      67,   471,   469,    66,   416,    57,   473,    34,   475,   366,
     367,    67,    75,    61,    66,   473,    67,    44,    61,    14,
      67,    48,    67,    67,   473,    66,    53,    54,    55,    56,
       1,    67,    67,    67,    60,    67,    67,   449,    60,    58,
      58,    20,    13,   400,    15,    14,    67,   514,    19,   473,
     407,   475,    67,    58,    74,    26,   514,   469,    29,   416,
      15,   473,    33,   475,    35,   514,   485,   418,   250,   454,
     454,   221,    43,    44,   258,    29,   221,     3,   148,   352,
     340,   328,     8,    15,   343,    11,    57,    -1,    -1,    -1,
     514,    17,   449,    -1,    -1,    -1,    22,    23,    24,     3,
      -1,    -1,   514,    29,     8,    -1,    96,    97,    98,    -1,
      36,    -1,   469,    17,    -1,    -1,   473,    -1,    22,    23,
      24,    -1,    -1,    49,    50,    29,    52,    53,    -1,    -1,
      56,    -1,    -1,    59,    -1,   125,    -1,    -1,    -1,    -1,
      66,    -1,    -1,   133,   115,    71,    72,    73,    -1,    75,
     140,    -1,    -1,   124,    -1,    59,    -1,   514,    -1,   130,
      -1,   132,    66,    39,    -1,   136,    -1,    -1,    -1,    73,
      -1,    75,    -1,   163,    -1,    51,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,   204,    36,    -1,   188,    -1,    -1,
     191,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   219,
      -1,   202,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      61,    -1,   213,   214,    -1,    66,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    -1,   227,   228,    -1,   249,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   261,    44,    -1,   264,   265,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,   258,   164,   165,
     166,   167,    -1,   169,   170,   171,    -1,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,   189,   190,    -1,   192,     8,    -1,    -1,
     196,   197,   198,    -1,    -1,    -1,    17,   317,     8,   300,
      -1,    22,    23,    24,    -1,    -1,    -1,    17,    29,    -1,
     216,   217,    22,    23,    24,    36,    -1,    -1,    -1,    29,
      -1,    -1,   342,    -1,    -1,    -1,    36,   328,    -1,   330,
      -1,    -1,    53,    -1,   335,    -1,    -1,   338,    59,   340,
      61,    -1,    -1,    53,    -1,    66,   366,   367,    69,    59,
      -1,   352,    73,   259,    75,   356,    66,    -1,   359,    -1,
     361,    -1,   268,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    -1,   291,   292,    -1,    -1,    17,
      -1,    -1,    -1,     3,    22,    23,    24,   398,     8,    -1,
     306,    29,    -1,    -1,    -1,    -1,   407,    17,    36,    -1,
      -1,    -1,    22,    23,    24,    -1,   322,   323,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    53,    36,    -1,   429,   449,
      -1,    59,    -1,    -1,    -1,    -1,    -1,   343,    66,    49,
      50,    -1,    52,    53,    -1,    73,    56,    75,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,   365,
      -1,    71,    72,    73,    -1,    75,    -1,    -1,   469,    -1,
      -1,    -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   389,   485,    -1,   392,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,    -1,    -1,     6,    -1,     8,     9,
      10,    -1,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    36,    -1,    -1,   445,
      -1,    -1,    -1,    -1,    -1,    -1,   452,   453,   454,    49,
      50,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,   474,   475,
     476,    71,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,   495,
      -1,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,   512,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    71,    72,    73,     1,
      75,     3,    -1,    -1,     6,    -1,     8,     9,    10,    -1,
      -1,    13,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    -1,    -1,    56,    57,    58,    59,    60,    -1,
       3,    -1,    -1,    -1,    66,     8,    -1,    -1,    -1,    71,
      72,    73,    -1,    75,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    17,    56,    -1,    -1,    59,    22,    23,    24,
      -1,    26,    -1,    66,    29,    -1,    -1,    -1,    71,    72,
      73,    36,    75,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      17,    56,    -1,    -1,    59,    22,    23,    24,    -1,    -1,
      -1,    66,    29,    -1,    -1,    -1,    71,    72,    73,    36,
      75,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    17,    56,
      57,    -1,    59,    22,    23,    24,    -1,    -1,    -1,    66,
      29,    -1,    31,    -1,    71,    72,    73,    36,    75,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      49,    50,    -1,    52,    53,    -1,    17,    56,    -1,    -1,
      59,    22,    23,    24,    -1,    -1,    -1,    66,    29,    -1,
      -1,    -1,    71,    72,    73,    36,    75,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    17,    56,    57,    -1,    59,    22,
      23,    24,    -1,    -1,    -1,    66,    29,    -1,    -1,    -1,
      71,    72,    73,    36,    75,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    17,    56,    -1,    -1,    59,    22,    23,    24,
      -1,    -1,    -1,    66,    29,    -1,    -1,    -1,    71,    72,
      73,    36,    75,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      17,    56,    -1,    -1,    59,    22,    23,    24,    -1,    -1,
      -1,    66,    29,    -1,    -1,    -1,    71,    72,    73,    36,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    17,    56,
      -1,    -1,    59,    22,    23,    24,    -1,    -1,    -1,    66,
      29,    -1,    -1,    -1,    71,    72,    73,    36,    75,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    17,    -1,    -1,    53,    -1,    22,    23,    24,    17,
      59,    -1,    61,    29,    22,    23,    24,    66,     8,    -1,
      36,    29,    -1,    -1,    73,    -1,    75,    17,    36,    -1,
      -1,    -1,    22,    23,    24,    -1,    -1,    53,    -1,    29,
      -1,    -1,    -1,    59,    -1,    53,    36,    -1,    -1,    -1,
      66,    59,    -1,    -1,    -1,    -1,    -1,    73,    66,    75,
      -1,    -1,    -1,    53,    -1,    73,     8,    75,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    17,    66,    -1,    -1,    -1,
      22,    23,    24,    73,    -1,    75,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    75,    33,    34,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    33,    34,    -1,    36,
      69,    38,    39,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    74,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      -1,    38,    39,    40,    -1,    70,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    -1,    38,
      39,    40,    -1,    70,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    -1,    38,    39,    40,
      -1,    70,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    33,    34,    -1,    36,
      61,    38,    39,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    77,    78,    24,    59,    75,   127,   128,     0,
      79,     3,    60,    21,    80,   151,    63,     3,    63,    66,
      81,    83,   127,    60,     1,     3,     6,     8,     9,    10,
      13,    15,    16,    17,    18,    19,    20,    22,    23,    27,
      28,    29,    30,    31,    32,    36,    49,    50,    52,    53,
      56,    66,    71,    72,    73,    86,    87,    88,    94,   104,
     106,   110,   111,   112,   113,   114,   115,   120,   124,   127,
     129,   130,   135,   136,   139,   142,   143,   144,   146,   149,
     150,   166,   170,    24,    59,     3,    67,    81,    82,    25,
      84,     3,   124,   126,   127,    17,    36,    53,    66,   127,
     129,   134,   138,   139,   140,   146,   126,   114,   120,    94,
     101,   102,   103,   170,   178,    66,   127,   145,   114,   124,
     105,   178,    35,    57,   123,    73,   112,   170,   177,    35,
     123,   105,    66,    92,    93,   127,    66,    89,   125,   127,
     169,   113,   113,   113,   113,   113,   113,    36,    53,   112,
     121,   133,   139,   141,   146,   113,   113,    11,   112,   176,
      60,    66,    90,   169,     4,    33,    34,    36,    37,    38,
      39,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    63,    66,
      73,    70,    66,   123,     1,   123,     5,    61,    69,    60,
     174,    24,    66,    36,    66,   132,   138,   139,   140,   141,
     146,   132,   132,    63,    35,   100,     5,    69,    60,    11,
     122,   127,   131,   132,   162,   163,   164,    66,    57,   147,
     100,    60,    24,    58,    66,   124,   156,   158,   160,   132,
      99,    53,    58,    66,   124,   155,   157,   158,   159,   168,
      35,    67,    93,   154,   132,    67,    89,   152,    61,    69,
     132,     8,   133,    67,    74,    74,    67,    90,    69,   132,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   116,    66,   127,    67,   121,   171,   112,   176,     1,
      57,    87,    96,   165,   166,   112,   116,   165,   167,   170,
     112,   170,    81,    67,    24,    85,   164,     8,   132,    67,
     127,   167,    26,    26,   178,   132,   122,   131,    61,   175,
      67,   164,   167,   108,   178,    63,    24,   158,    66,   161,
      60,   174,    74,     7,    12,    58,    95,    97,    66,   159,
      53,   159,    60,   174,     3,   179,    61,   132,    99,    60,
     174,    60,   174,   125,   170,    69,    36,    66,   132,   138,
     139,   140,   146,    57,   132,   132,    60,   174,   170,    69,
      57,   112,   117,   118,   172,   173,    31,   121,    11,    61,
     175,    74,    70,   167,    61,   175,   173,    58,    60,    60,
      67,    67,    58,   112,   112,    60,   162,    66,   127,   137,
     138,   139,   140,   141,   146,   148,    67,    58,    14,   107,
     109,   127,    67,   164,   160,    58,   132,   171,    70,    98,
     159,   179,   159,    67,   157,    58,   124,   179,    58,    93,
      67,    89,    67,   170,   132,   116,    90,    91,   153,   169,
      67,   170,   116,    70,    61,   175,    58,    67,    67,   175,
     121,    67,   176,    58,    67,    58,   165,   178,   164,    66,
     148,    20,    96,    67,     5,    61,    69,    70,   167,    67,
      67,   179,   108,    67,   173,    60,   174,   132,   173,    57,
     112,   119,   117,   118,    67,    70,    74,    67,   164,   105,
     108,   148,   112,   112,   179,   179,    14,   107,    58,    91,
      67,    58,   116,   176,    67,   100,   107,    70,    70,   173,
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
#line 167 "go.y" /* yacc.c:1646  */
    {
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "file", nkids, kids, leaf);
		ast_root = (yyval.ast);
	}
#line 1990 "go.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 180 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		exit(1);
	}
#line 1999 "go.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 185 "go.y" /* yacc.c:1646  */
    { 
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "package", nkids, kids, (yyvsp[-2].t));
	}
#line 2011 "go.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 196 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "imports", 0, NULL, NULL);
	}
#line 2019 "go.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 200 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "imports", nkids, kids, leaf);
	}
#line 2030 "go.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 210 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2041 "go.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 217 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2052 "go.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 224 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2063 "go.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 234 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
#line 2074 "go.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 241 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
#line 2085 "go.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 251 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
#line 2096 "go.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 258 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
#line 2107 "go.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 268 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2118 "go.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 275 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2129 "go.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 282 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2140 "go.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 292 "go.y" /* yacc.c:1646  */
    {
		// TODO: concat package and name
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_package", nkids, kids, leaf);
	}
#line 2152 "go.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 303 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "import_safety", 0, NULL, NULL);
	}
#line 2160 "go.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 307 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_safety", nkids, kids, leaf);
	}
#line 2171 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 320 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", 0, NULL, NULL);
	}
#line 2180 "go.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 325 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
#line 2191 "go.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 332 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
#line 2202 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 339 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", nkids, kids, leaf);
	}
#line 2214 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 347 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "xdcl", 0, NULL, NULL);
	}
#line 2222 "go.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 354 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2233 "go.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 361 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2244 "go.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 368 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2255 "go.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 375 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2266 "go.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 382 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2277 "go.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 389 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2288 "go.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 396 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2299 "go.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 403 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2310 "go.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 410 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2321 "go.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2332 "go.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 427 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lconst", nkids, kids, leaf);
	}
#line 2343 "go.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 437 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2354 "go.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 444 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2365 "go.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 451 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2376 "go.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 461 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2387 "go.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 468 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2398 "go.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 478 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2409 "go.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 485 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2420 "go.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 492 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2431 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 502 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedclname", nkids, kids, leaf);
	}
#line 2444 "go.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 514 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl", nkids, kids, leaf);
	}
#line 2455 "go.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 524 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2466 "go.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 531 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2477 "go.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 538 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2488 "go.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 545 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2499 "go.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 552 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2510 "go.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 559 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2521 "go.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 569 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2532 "go.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 576 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2543 "go.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 583 "go.y" /* yacc.c:1646  */
    {
		// TODO: maybe concat tokens?
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2555 "go.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 591 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2566 "go.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 602 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "compound_stmt", nkids, kids, leaf);
	}
#line 2577 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 612 "go.y" /* yacc.c:1646  */
    {
		// If the last token read by the lexer was consumed
		// as part of the case, clear it (parser has cleared yychar).
		// If the last token read by the lexer was the lookahead
		// leave it alone (parser has it cached in yychar).
		// This is so that the stmt_list action doesn't look at
		// the case tokens if the stmt_list is empty.
		yylast = yychar;
	}
#line 2591 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 622 "go.y" /* yacc.c:1646  */
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
#line 2616 "go.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 646 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "caseblock_list", 0, NULL, NULL);
	}
#line 2624 "go.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 650 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "caseblock_list", nkids, kids, leaf);
	}
#line 2635 "go.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 661 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "loop_body", nkids, kids, leaf);
	}
#line 2646 "go.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 671 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
#line 2657 "go.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 678 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t); // TODO: concat tokens
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
#line 2668 "go.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 688 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2679 "go.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 695 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2690 "go.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 702 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2701 "go.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 712 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_body", nkids, kids, leaf);
	}
#line 2712 "go.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 723 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_stmt", nkids, kids, leaf);
	}
#line 2723 "go.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 733 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
#line 2734 "go.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 740 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
#line 2745 "go.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 754 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_stmt", nkids, kids, leaf);
	}
#line 2756 "go.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 765 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens "elseif"
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif", nkids, kids, leaf);
	}
#line 2767 "go.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 775 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "elseif_list", 0, NULL, NULL);
	}
#line 2775 "go.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 779 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif_list", nkids, kids, leaf);
	}
#line 2786 "go.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 789 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "else", 0, NULL, NULL);
	}
#line 2794 "go.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 794 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "else", nkids, kids, leaf);
	}
#line 2805 "go.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 807 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-6].t); // TODO: maybe concat tokens
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "switch_stmt", nkids, kids, leaf);
	}
#line 2816 "go.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 818 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "select_stmt", nkids, kids, leaf);
	}
#line 2827 "go.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 831 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2838 "go.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 838 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2849 "go.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 845 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2860 "go.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 852 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2871 "go.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 859 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2882 "go.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 866 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2893 "go.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 873 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2904 "go.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 880 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2915 "go.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 887 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2926 "go.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 894 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2937 "go.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 901 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2948 "go.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 908 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2959 "go.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 915 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2970 "go.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 922 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2981 "go.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 929 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2992 "go.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 936 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3003 "go.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 943 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3014 "go.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 950 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3025 "go.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 957 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3036 "go.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 965 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3047 "go.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 972 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3058 "go.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 982 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3069 "go.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 989 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3080 "go.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 996 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3091 "go.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1003 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3102 "go.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1010 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3113 "go.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1017 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3124 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1024 "go.y" /* yacc.c:1646  */
    {
		yyerror("the bitwise complement operator is ^");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3136 "go.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1032 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3147 "go.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1039 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3158 "go.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1053 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3169 "go.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1060 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3180 "go.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1067 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3191 "go.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1077 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3202 "go.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1084 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3213 "go.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1091 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3224 "go.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1098 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3235 "go.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1105 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3246 "go.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1112 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3257 "go.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1119 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3268 "go.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1126 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3279 "go.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1133 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3290 "go.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1140 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3301 "go.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1147 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3312 "go.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1154 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3323 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1161 "go.y" /* yacc.c:1646  */
    {
		yyerror("cannot parenthesize type in composite literal");

		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3336 "go.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1170 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3347 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1180 "go.y" /* yacc.c:1646  */
    {
		// composite expression.
		// make node early so we get the right line number.
		(yyval.ast) = new_tree_node(++ruleno, "start_complit", 0, NULL, NULL);
	}
#line 3357 "go.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1189 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval", nkids, kids, leaf);
	}
#line 3368 "go.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1199 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
#line 3379 "go.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1206 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
#line 3390 "go.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1216 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
#line 3401 "go.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1223 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
#line 3412 "go.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1233 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
#line 3423 "go.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1240 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
#line 3434 "go.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1250 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
#line 3445 "go.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1257 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
#line 3456 "go.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1267 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "name_or_type", nkids, kids, leaf);
	}
#line 3467 "go.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1277 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3478 "go.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1284 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3489 "go.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1299 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name", nkids, kids, leaf);
	}
#line 3500 "go.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1309 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name", nkids, kids, leaf);
	}
#line 3511 "go.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1319 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "onew_name", 0, NULL, NULL);
	}
#line 3519 "go.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1323 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "onew_name", nkids, kids, leaf);
	}
#line 3530 "go.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1333 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3541 "go.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1340 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3552 "go.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1347 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3563 "go.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1357 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3574 "go.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1364 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3585 "go.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1374 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "name", nkids, kids, leaf);
	}
#line 3596 "go.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1384 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "labelname", nkids, kids, leaf);
	}
#line 3607 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1403 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");

		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3620 "go.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1412 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3631 "go.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1422 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3642 "go.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1429 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3653 "go.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1436 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3664 "go.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1443 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3675 "go.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1450 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3686 "go.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1457 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3697 "go.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1467 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3708 "go.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1474 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3719 "go.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1481 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3730 "go.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1488 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3741 "go.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1498 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3752 "go.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1505 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3763 "go.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1512 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3774 "go.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1519 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3785 "go.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1526 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_recvchantype", nkids, kids, leaf);
	}
#line 3796 "go.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1536 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "convtype", nkids, kids, leaf);
	}
#line 3807 "go.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1543 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "convtype", nkids, kids, leaf);
	}
#line 3818 "go.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1552 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "comptype", nkids, kids, leaf);
	}
#line 3829 "go.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1562 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3840 "go.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1569 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3851 "go.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1576 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3862 "go.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1583 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3873 "go.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1590 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnret_type", nkids, kids, leaf);
	}
#line 3884 "go.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1600 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
#line 3895 "go.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1607 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
#line 3906 "go.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1617 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3917 "go.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1624 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3928 "go.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1631 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3939 "go.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1638 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3950 "go.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1645 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].t), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3961 "go.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1652 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3972 "go.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1659 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3983 "go.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1669 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ptrtype", nkids, kids, leaf);
	}
#line 3994 "go.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1679 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	// TODO: concat tokens ?
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "recvchantype", nkids, kids, leaf);
	}
#line 4005 "go.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1689 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 4016 "go.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1696 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 4027 "go.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1706 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
#line 4038 "go.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1713 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
#line 4049 "go.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1727 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xfndcl", nkids, kids, leaf);
	}
#line 4060 "go.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1737 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 4071 "go.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1744 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 4082 "go.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1771 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fntype", nkids, kids, leaf);
	}
#line 4093 "go.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1781 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "fnbody", 0, NULL, NULL);
	}
#line 4101 "go.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1785 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnbody", nkids, kids, leaf);
	}
#line 4112 "go.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1795 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "fnres", 0, NULL, NULL);
	}
#line 4120 "go.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1799 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnres", nkids, kids, leaf);
	}
#line 4131 "go.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1806 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnres", nkids, kids, leaf);
	}
#line 4142 "go.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1816 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnlitdcl", nkids, kids, leaf);
	}
#line 4153 "go.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1826 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 4164 "go.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1833 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 4175 "go.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1848 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "xdcl_list", 0, NULL, NULL);
	}
#line 4183 "go.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1852 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl_list", nkids, kids, leaf);
	}
#line 4194 "go.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1862 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
#line 4205 "go.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1869 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
#line 4216 "go.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1879 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
#line 4227 "go.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1886 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
#line 4238 "go.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1896 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
#line 4249 "go.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1903 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
#line 4260 "go.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1913 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
#line 4271 "go.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1920 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
#line 4282 "go.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1930 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
	}
#line 4293 "go.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1937 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
	}
#line 4304 "go.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1947 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4315 "go.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1954 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4326 "go.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1961 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4337 "go.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1968 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4348 "go.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1975 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4359 "go.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1982 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4370 "go.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1992 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 4381 "go.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1999 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 4392 "go.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 2009 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "embed", nkids, kids, leaf);
	}
#line 4403 "go.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 2019 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4414 "go.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 2026 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4425 "go.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 2033 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4436 "go.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 2043 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "indcl", nkids, kids, leaf);
	}
#line 4447 "go.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 2056 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4458 "go.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 2063 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4469 "go.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 2070 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4480 "go.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 2077 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4491 "go.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 2087 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
#line 4502 "go.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 2094 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
#line 4513 "go.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 2104 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oarg_type_list_ocomma", 0, NULL, NULL);
	}
#line 4521 "go.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 2108 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oarg_type_list_ocomma", nkids, kids, leaf);
	}
#line 4532 "go.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 2121 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "stmt", 0, NULL, NULL);
	}
#line 4540 "go.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 2125 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4551 "go.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 2132 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4562 "go.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 2139 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4573 "go.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 2146 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt", nkids, kids, leaf);
	}
#line 4584 "go.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 2156 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4595 "go.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 2163 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4606 "go.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 2170 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4617 "go.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 2177 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4628 "go.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 2184 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4639 "go.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 2192 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 22;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4650 "go.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 2199 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4661 "go.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 2206 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4672 "go.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 2213 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4683 "go.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 2220 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4694 "go.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 2227 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4705 "go.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 2234 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4716 "go.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2241 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4727 "go.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2251 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
#line 4738 "go.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2258 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
#line 4749 "go.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 2268 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
#line 4760 "go.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 2275 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
#line 4771 "go.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 2285 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
#line 4782 "go.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 2292 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
#line 4793 "go.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 2302 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
#line 4804 "go.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 2309 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
#line 4815 "go.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 2319 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
#line 4826 "go.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 2326 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
#line 4837 "go.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 2339 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4848 "go.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 2346 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4859 "go.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 2353 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4870 "go.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 2360 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4881 "go.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 2370 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "braced_keyval_list", 0, NULL, NULL);
	}
#line 4889 "go.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 2374 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "braced_keyval_list", nkids, kids, leaf);
	}
#line 4900 "go.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 2387 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osemi", 0, NULL, NULL);
	}
#line 4908 "go.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 2391 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osemi", 0, NULL, (yyvsp[0].t));
	}
#line 4916 "go.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 2398 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "ocomma", 0, NULL, NULL);
	}
#line 4924 "go.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2402 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "ocomma", 0, NULL, (yyvsp[0].t));
	}
#line 4932 "go.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2409 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oexpr", 0, NULL, NULL);
	}
#line 4940 "go.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2413 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oexpr", nkids, kids, leaf);
	}
#line 4951 "go.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2423 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oexpr_list", 0, NULL, NULL);
	}
#line 4959 "go.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2427 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oexpr_list", nkids, kids, leaf);
	}
#line 4970 "go.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2437 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osimple_stmt", 0, NULL, NULL);
	}
#line 4978 "go.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 2441 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "osimple_stmt", nkids, kids, leaf);
	}
#line 4989 "go.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 2493 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "oliteral", 0, NULL, NULL);
	}
#line 4997 "go.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 2497 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "oliteral", nkids, kids, leaf);
	}
#line 5008 "go.tab.c" /* yacc.c:1646  */
    break;


#line 5012 "go.tab.c" /* yacc.c:1646  */
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
#line 2894 "go.y" /* yacc.c:1906  */

