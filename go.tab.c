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
	fprintf(stderr, "syntax error: unexpected '%s' token in file %s, line %d\n",
	   yytext,yyfilename, yylineno);
	exit(2);
}



#line 112 "go.tab.c" /* yacc.c:339  */

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
#line 68 "go.y" /* yacc.c:355  */

	struct tree* ast;
	struct token* t;

#line 210 "go.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "go.tab.c" /* yacc.c:358  */

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
#define YYLAST   1957

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  518

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
      67,    68,    53,    49,    61,    50,    63,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    60,
       2,    64,     2,    59,    75,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    65,    66,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   178,   184,   196,   200,   210,   217,   224,
     234,   241,   248,   252,   262,   269,   276,   286,   297,   301,
     314,   319,   323,   327,   332,   339,   346,   353,   360,   367,
     374,   381,   388,   395,   402,   412,   422,   429,   436,   446,
     453,   463,   467,   474,   481,   490,   500,   504,   511,   518,
     525,   532,   542,   549,   556,   564,   574,   586,   585,   619,
     623,   633,   644,   651,   661,   668,   672,   679,   689,   700,
     704,   715,   728,   739,   743,   753,   757,   767,   779,   793,
     797,   804,   811,   818,   825,   832,   839,   846,   853,   860,
     867,   874,   881,   888,   895,   902,   909,   916,   923,   931,
     941,   945,   952,   959,   966,   973,   980,   988,   995,  1009,
    1016,  1023,  1033,  1040,  1044,  1051,  1058,  1065,  1072,  1079,
    1086,  1090,  1097,  1104,  1111,  1120,  1127,  1136,  1146,  1150,
    1160,  1164,  1174,  1178,  1188,  1192,  1202,  1210,  1217,  1232,
    1239,  1246,  1250,  1257,  1264,  1268,  1278,  1285,  1295,  1305,
    1321,  1330,  1340,  1344,  1348,  1352,  1356,  1360,  1370,  1374,
    1378,  1382,  1392,  1396,  1400,  1404,  1408,  1415,  1419,  1426,
    1433,  1437,  1441,  1445,  1449,  1456,  1460,  1470,  1477,  1484,
    1491,  1498,  1505,  1509,  1516,  1524,  1540,  1547,  1557,  1564,
    1578,  1588,  1595,  1622,  1632,  1636,  1643,  1647,  1651,  1658,
    1665,  1672,  1687,  1691,  1701,  1705,  1715,  1719,  1729,  1733,
    1743,  1747,  1757,  1761,  1771,  1778,  1785,  1792,  1799,  1806,
    1816,  1823,  1833,  1840,  1847,  1851,  1858,  1871,  1875,  1882,
    1889,  1896,  1900,  1910,  1914,  1927,  1931,  1935,  1939,  1943,
    1950,  1955,  1960,  1964,  1968,  1972,  1980,  1987,  1994,  2001,
    2008,  2015,  2022,  2032,  2036,  2046,  2050,  2060,  2064,  2074,
    2078,  2088,  2092,  2105,  2109,  2113,  2120,  2130,  2134,  2147,
    2151,  2158,  2162,  2169,  2173,  2180,  2184,  2191,  2195,  2235,
    2239
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
  "PreferToRightParen", "':'", "'!'", "'~'", "'['", "']'", "'@'",
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
      59,    44,    96,    46,    61,   304,   305,    40,    41,   306,
      58,    33,   126,    91,    93,    64
};
# endif

#define YYPACT_NINF -381

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-381)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,    75,    37,  -381,  -381,  -381,    64,    17,  -381,  -381,
      63,    57,  -381,    78,    98,   799,    30,  -381,   172,   211,
    -381,   158,   181,  -381,  -381,  -381,    75,  1495,  -381,    75,
     596,  -381,  1289,   263,   596,    75,  1289,    22,   115,  1289,
     156,    22,  1289,   287,   297,  1289,  1289,  1289,  1289,  1289,
    1289,  1329,  1289,  1289,  1015,   145,  -381,   337,  -381,  -381,
    -381,  -381,  -381,  1661,  -381,  -381,   185,   109,  -381,   130,
    -381,   179,   187,    22,   191,  -381,  -381,  -381,   195,    70,
    -381,  -381,    83,  -381,  -381,  -381,  -381,  -381,   206,   241,
    -381,  -381,  -381,  -381,  -381,   210,  1529,  1529,  1529,  -381,
     233,  -381,  -381,  -381,  -381,  -381,  -381,    68,   109,  -381,
    -381,   265,  -381,    91,   248,   606,   234,   258,    99,  -381,
     265,   257,  -381,  -381,   194,  1529,  1830,   262,  -381,  -381,
     197,   291,   208,  1529,  -381,  -381,   349,  -381,  -381,  -381,
    1409,  -381,  -381,  -381,  -381,  -381,  -381,  1369,  1329,  1830,
     260,  -381,     3,  -381,    51,  -381,  -381,   267,  1830,   271,
    -381,   394,  -381,  1435,  1289,  1289,  1289,  1289,  -381,  1289,
    1289,  1289,  -381,  1289,  1289,  1289,  1289,  1289,  1289,  1289,
    1289,  1289,  1289,  1289,  1289,  1289,  1289,  -381,   383,   688,
    1289,   876,  1289,  -381,  -381,   949,  1289,  1289,  1289,    73,
     276,   307,   606,   341,  1529,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,   282,    75,   949,  -381,  1055,  1095,  1289,  1529,
    -381,   606,  -381,  -381,  -381,   292,   284,   606,   949,  -381,
    -381,  1289,    27,  -381,   335,   302,   310,  -381,  -381,   300,
      88,    11,  -381,    59,  -381,   318,  -381,  -381,   378,  1469,
    -381,  -381,  -381,   327,  -381,  -381,  -381,   330,    75,  1289,
     329,  1555,  -381,   343,  1529,  1529,  -381,   345,  1289,   347,
    1830,  1901,  -381,  1854,   679,   679,   679,   679,  -381,   679,
     679,  1878,  -381,   450,   450,   450,   450,  -381,  -381,  -381,
    -381,  1135,  1192,  -381,  -381,  -381,    42,  1690,   350,  -381,
     949,  -381,  -381,  -381,  -381,  1806,  1135,  -381,   121,   262,
    1830,   262,  -381,  -381,  -381,   355,   351,  1529,   353,  -381,
    -381,   164,  1289,  1289,   362,  -381,  -381,  -381,   606,  -381,
    1589,   361,   231,   409,  -381,    75,   364,   367,   606,  -381,
     440,   381,  1529,  1329,   366,  -381,  -381,  -381,   335,   378,
     335,   372,   235,   398,  -381,  -381,    75,   378,   159,    75,
     395,    75,   399,  -381,   262,  1289,  1615,  1529,  -381,   228,
     246,   290,   359,  -381,  -381,  -381,    75,   405,   262,  1289,
    -381,  1722,  -381,  -381,   391,   403,   411,   417,   415,  1329,
     420,  -381,  1289,   247,  -381,   422,   419,  -381,   876,  -381,
    1589,  -381,  -381,  1830,  1830,  1289,  -381,   606,   426,  -381,
    -381,  -381,  -381,  -381,  -381,  -381,  1589,  -381,    62,  -381,
    -381,  -381,  -381,   427,  -381,  -381,  -381,    43,  -381,   876,
     432,  -381,   433,   378,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,   262,   434,  1135,  -381,  -381,   448,  1435,
    -381,   262,  1135,  1232,  1135,  -381,  -381,  -381,  -381,   442,
    -381,  -381,    47,  -381,  -381,  -381,  -381,  -381,   443,   606,
    -381,  1289,  -381,  1589,  1289,  1329,  1289,  -381,   452,   378,
     378,  -381,   408,   455,    75,   453,   347,   460,  -381,  1830,
    -381,  -381,  -381,  -381,  1289,  -381,  -381,   454,   265,  -381,
    1750,  1778,  -381,  -381,  -381,  -381,  -381,  -381,  1135,   449,
    1589,  -381,  -381,  -381,   467,  -381,  -381,  -381
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
       0,   217,     0,   279,   211,   186,   256,   214,    77,   209,
      33,   205,    26,    37,     0,   267,    41,   206,   269,    43,
      29,    39,   267,     0,   272,   268,   123,   116,   115,     0,
     262,   110,     0,    56,   121,   122,   254,    64,     0,   233,
     191,   277,    76,   196,     0,     0,     0,    52,    58,   279,
     279,   216,   157,     0,   270,     0,    42,     0,   126,   130,
     127,   265,   266,   111,   273,   118,   198,     0,     0,   226,
       0,     0,   219,   218,   124,   207,    30,   129,   267,     0,
     196,    72,    54,    53,     0,   119,   192,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -381,  -381,  -381,  -381,  -381,     0,  -381,  -381,  -381,  -381,
    -381,   511,  -381,  -116,   -51,    44,  -381,  -128,   -25,  -381,
     111,  -381,  -381,   277,  -119,  -381,  -381,  -381,  -381,   -40,
    -381,  -381,  -381,  -381,  -381,  -381,   393,    16,   140,  -381,
    -164,    76,    79,  -381,   143,   -41,   311,   205,   114,   278,
     508,    -1,  -381,   270,  -381,   317,   384,   397,  -381,  -381,
    -381,  -381,   -18,   -24,   -14,    41,  -381,  -381,  -381,  -381,
      71,  -381,  -380,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,   189,  -101,  -194,   199,  -381,   214,  -381,  -187,  -165,
     528,  -206,  -381,   -36,    12,   207,  -381,  -260,  -212,  -246,
    -185,  -381,   -16,  -318
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    88,    21,    90,   315,
      55,   301,    57,   137,   446,   447,   133,   134,    58,   346,
     302,   347,   429,   240,   215,   110,   111,   112,    59,   120,
      60,   419,   333,   420,    61,    62,    63,    64,    65,    66,
     291,   382,   383,   490,    67,   295,   220,   124,    68,   138,
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
       7,   230,   131,   103,   252,   298,   162,   109,   321,   102,
     150,   109,    22,   104,    69,   316,   114,   109,    22,    87,
     256,   163,   332,   237,   341,    94,   303,   152,    94,   306,
    -220,   431,   116,   353,    94,   336,   470,     9,  -169,   437,
     331,   360,   135,   139,   113,   362,   396,   349,   474,   351,
     390,   127,  -199,   388,    83,   377,   139,   122,     1,   395,
    -169,   141,   142,   143,   144,   145,   146,    11,   155,   156,
    -168,   194,   207,   207,   207,  -250,    17,    12,   348,   123,
    -250,    17,   471,   336,    13,  -220,  -199,  -220,   196,    84,
     335,   207,   153,   499,   393,   343,   216,     4,   105,     4,
     344,   207,     4,   389,   475,   122,  -249,   476,  -199,   207,
     267,  -249,   350,   477,   221,   481,   207,   494,  -167,   300,
      16,   495,   154,    94,   152,   163,  -250,   123,  -250,    94,
     516,   135,     5,   337,     5,   139,    18,     5,   455,   207,
      92,    18,   459,    92,   197,    19,   345,   198,     6,   119,
       6,   423,   197,     6,   430,   217,   432,  -249,    23,  -249,
     139,   502,   503,   141,   145,   152,   343,   210,   210,   210,
     107,   344,   188,   108,   118,    85,   189,   108,   207,   397,
     207,   398,   190,    89,    91,   483,   210,   293,   125,   153,
      69,   129,   487,   109,    69,   207,   210,   207,    22,   312,
    -139,   221,   324,   207,   210,   160,   109,   462,   309,   445,
     311,   210,   320,    69,    17,   334,   452,   438,   232,   154,
     468,   232,   402,   478,   398,   207,   221,    69,   309,   311,
     153,   439,     4,   466,   210,     4,   485,   370,   235,   237,
     207,   207,   187,   369,   244,   441,   130,   371,   514,   191,
     241,   387,   233,     5,   192,   242,     5,   139,  -168,   232,
     154,   234,  -167,  -165,   243,   201,   199,     5,   152,     6,
       5,   364,     6,   210,    18,   210,   251,   202,   193,    86,
     378,  -163,   497,     6,   195,  -165,     6,     4,   241,   417,
     210,   398,   210,   207,     5,  -165,   213,   100,   210,    69,
     214,   227,   243,  -163,   207,   463,   411,   398,   218,   509,
       6,     4,   410,  -163,   207,   228,   412,   231,   207,   152,
     210,     4,     5,   197,   508,  -164,   250,   221,   263,   408,
     115,   314,   372,   153,   421,   210,   210,   221,     6,    94,
     449,   264,   207,   207,   313,   265,     5,  -164,   460,   317,
     319,    94,   330,   328,   132,    94,     5,  -164,   135,   336,
     139,     4,     6,   154,   136,   152,   100,   100,   100,   338,
     340,   413,     6,     4,   342,   139,   411,   443,   352,   511,
     109,   354,   410,   207,   153,   100,   412,   359,   210,   467,
     361,   451,   411,   365,  -162,   100,     5,    69,   410,   210,
     373,   414,   412,   100,   161,   376,   221,     4,     5,   210,
     100,   379,     6,   210,   154,   399,  -162,   255,     4,   400,
     392,   401,   405,   418,     6,   207,  -162,   335,    69,   416,
     153,   498,   126,   100,   460,   422,   428,   210,   210,   425,
     433,   413,     5,  -166,   149,   207,   109,   158,   449,   411,
     292,   152,   454,     5,   235,   410,   435,   413,     6,   412,
     154,   456,   266,   440,   232,  -166,   244,   442,   221,     6,
     436,   414,   100,   450,   100,  -166,   394,   465,   210,   457,
     205,   211,   212,   139,   166,   458,   411,   414,   461,   100,
     464,   100,   410,   469,   174,   473,   412,   100,   178,     5,
     479,   480,   482,   183,   184,   185,   186,   234,   484,   239,
     493,   496,   398,   504,   413,     6,   153,   254,   507,   100,
     210,   506,   510,   515,   260,   517,    56,   358,   505,   472,
     491,   100,   326,   492,   100,   100,   363,   106,   327,   424,
     210,   434,   406,    81,   414,   262,   154,   269,     0,     0,
     427,   413,     0,     0,     0,     0,     0,   270,   271,   272,
     273,     0,   274,   275,   276,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
       0,   414,   149,   297,     0,   305,     0,   100,   318,   126,
     310,   126,     0,     0,     0,     0,     0,     0,   100,    25,
     100,     0,     0,   325,    27,     0,     0,     0,   100,   126,
     126,     0,   100,    95,    27,     0,     0,   219,    37,    38,
       4,     0,     0,    95,     0,    41,     0,     0,    37,    38,
       4,     0,     0,   357,     0,    41,   100,   100,     0,     0,
       0,     0,   203,     0,     0,   368,     0,     0,   374,   375,
       0,     0,   126,     0,     0,     5,     0,     0,     0,    97,
       0,   126,     0,    51,     0,     5,     0,     0,     0,    54,
     100,     6,     0,   204,     0,     0,     0,   100,     0,    54,
       0,     6,     0,     0,   381,   149,   100,     0,     0,     0,
       0,    25,     0,     0,     0,     0,    27,     0,     0,   381,
       0,   368,     0,     0,     0,    95,     0,     0,     0,     0,
      37,    38,     4,   166,     0,   403,   404,    41,     0,   100,
       0,     0,     0,   174,   147,     0,   426,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   149,    46,    47,   100,
      48,   148,     0,   100,    50,     0,     0,     5,     0,     0,
     205,   444,     0,     0,     0,    51,   294,     0,   126,    52,
      53,    54,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,     0,     0,     0,     0,     0,     0,
     100,     0,   149,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -2,
      24,     0,    25,     0,     0,    26,     0,    27,    28,    29,
       0,     0,    30,     0,    31,    32,    33,    34,    35,    36,
       0,    37,    38,     4,     0,     0,    39,    40,    41,    42,
      43,    44,     0,   486,     0,    45,     0,     0,   381,     0,
       0,     0,     0,     0,     0,   381,   489,   381,    46,    47,
       0,    48,    49,     0,     0,    50,     0,     0,     5,   -20,
       0,     0,     0,     0,     0,     0,    51,   500,   149,   501,
      52,    53,    54,     0,     6,     0,     0,   299,     0,    25,
       0,     0,    26,  -235,    27,    28,    29,   158,  -235,    30,
       0,    31,    32,    95,    34,    35,    36,     0,    37,    38,
       4,   381,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    47,     0,    48,    49,
       0,     0,    50,   300,  -235,     5,  -235,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,    52,    53,    54,
     299,     6,    25,     0,     0,    26,     0,    27,    28,    29,
       0,     0,    30,     0,    31,    32,    95,    34,    35,    36,
       0,    37,    38,     4,     0,     0,    39,    40,    41,    42,
      43,    44,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
       0,    48,    49,     0,     0,    50,   300,  -235,     5,  -235,
       0,     0,     0,     0,     0,     0,    51,     0,    25,     0,
      52,    53,    54,    27,     6,     0,   157,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,    37,    38,     4,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    27,    46,    47,     0,    48,    49,     0,
       0,    50,    95,     0,     5,     0,     0,    37,    38,     4,
       0,   322,    51,     0,    41,     0,    52,    53,    54,     0,
       6,    45,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    27,    46,    47,     0,    48,    49,     0,
       0,    50,    95,     0,     5,     0,     0,    37,    38,     4,
       0,   323,    51,     0,    41,     0,    52,    53,    54,     0,
       6,    45,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    27,    46,    47,     0,    48,    49,     0,
       0,    50,    95,     0,     5,     0,     0,    37,    38,     4,
       0,     0,    51,     0,    41,     0,    52,    53,    54,     0,
       6,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,     0,    48,    49,     0,
       0,    50,   380,     0,     5,    25,     0,     0,     0,     0,
      27,     0,    51,     0,     0,     0,    52,    53,    54,    95,
       6,     0,     0,     0,    37,    38,     4,     0,     0,     0,
       0,    41,     0,   386,     0,     0,     0,     0,   147,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
      27,    46,    47,     0,    48,   148,     0,     0,    50,    95,
       0,     5,     0,     0,    37,    38,     4,     0,     0,    51,
       0,    41,     0,    52,    53,    54,     0,     6,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,    48,    49,     0,     0,    50,   488,
       0,     5,    25,     0,     0,     0,     0,    27,     0,    51,
       0,     0,     0,    52,    53,    54,    95,     6,     0,     0,
       0,    37,    38,     4,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,    27,    46,    47,
       0,    48,    49,     0,     0,    50,    95,     0,     5,     0,
       0,    37,    38,     4,     0,     0,    51,     0,    41,     0,
      52,    53,    54,     0,     6,   147,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,   261,    46,    47,
       0,    48,   148,     0,     0,    50,    95,     0,     5,     0,
       0,    37,    38,     4,     0,     0,    51,     0,    41,     0,
      52,    53,    54,     0,     6,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    46,    47,
       0,    48,    49,     0,     0,    50,    95,     0,     5,     0,
       0,    37,    38,     4,     0,     0,    51,     0,    41,     0,
      52,    53,    54,    27,     6,   203,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,    37,    38,     4,
       0,     0,    97,     0,    41,     0,     0,     0,     5,     0,
     258,   203,     0,   259,     0,     0,   204,    27,     0,     0,
       0,     0,    54,     0,     6,     0,    95,     0,    97,     0,
       0,    37,    38,     4,     5,     0,   258,     0,    41,   268,
       0,     0,   204,    27,     0,   203,     0,     0,    54,     0,
       6,     0,    95,     0,     0,     0,     0,    37,    38,     4,
       0,     0,    97,     0,    41,     0,     0,     0,     5,     0,
     356,    96,     0,     0,     0,     0,   204,    27,     0,     0,
       0,     0,    54,     0,     6,     0,    95,     0,    97,     0,
       0,    37,    38,     4,     5,     0,     0,     0,    41,     0,
       0,     0,    98,    27,     0,   203,     0,     0,    54,     0,
       6,     0,    95,     0,     0,     0,     0,    37,    38,     4,
       0,     0,    97,     0,    41,     0,     0,     0,     5,     0,
       0,   366,     0,     0,     0,     0,   204,    27,     0,     0,
       0,     0,    54,     0,     6,     0,    95,     0,    97,     0,
       0,    37,    38,     4,     5,     0,     0,     0,    41,     0,
       0,     0,   367,   261,     0,   203,     0,     0,    54,     0,
       6,     0,    95,     0,     0,     0,     0,    37,    38,     4,
       0,     0,    97,     0,    41,     0,     0,     0,     5,     0,
       0,   203,     0,     0,     0,     0,   407,     0,     0,     0,
       0,     0,    54,     0,     6,   164,  -259,     0,    97,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,   204,     0,     0,     0,     0,     0,    54,     0,
       6,     0,     0,     0,   165,   166,     0,   167,   168,   169,
     170,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,  -259,   165,   166,  -259,   167,     0,   169,   170,
     171,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,     0,   167,     0,
     169,   170,   171,     0,   391,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
       0,     0,     0,   165,   166,     0,   167,     0,   169,   170,
     171,     0,   453,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,     0,     0,
       0,   165,   166,     0,   167,     0,   169,   170,   171,     0,
     512,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,     0,     0,     0,   165,
     166,     0,   167,     0,   169,   170,   171,     0,   513,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   165,   166,     0,   167,   394,   169,   170,
     171,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   165,   166,     0,
       0,     0,   169,   170,   171,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   165,   166,     0,     0,     0,   169,   170,   171,     0,
       0,   173,   174,   175,   176,     0,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   166,     0,     0,     0,   169,
     170,   171,     0,     0,   173,   174,   175,   176,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186
};

static const yytype_int16 yycheck[] =
{
       1,   120,    42,    27,   132,   190,    57,    32,   214,    27,
      51,    36,    13,    27,    15,   202,    32,    42,    19,    19,
     136,    57,   228,   124,   236,    26,   191,    51,    29,   193,
       3,   349,    33,   245,    35,    24,   416,     0,    35,   357,
     227,   253,    43,    44,    32,   257,   306,   241,     5,   243,
     296,    39,     1,    11,    24,   267,    57,    35,    25,   305,
      57,    45,    46,    47,    48,    49,    50,     3,    52,    53,
      67,     1,    96,    97,    98,     7,     3,    60,    67,    57,
      12,     3,    20,    24,    21,    58,    35,    60,     5,    59,
      63,   115,    51,   473,   300,     7,     5,    24,    27,    24,
      12,   125,    24,    61,    61,    35,     7,    64,    57,   133,
     161,    12,    53,    70,   115,   433,   140,    70,    67,    57,
      63,    74,    51,   124,   148,   161,    58,    57,    60,   130,
     510,   132,    59,   234,    59,   136,    63,    59,   384,   163,
      26,    63,   388,    29,    61,    67,    58,    64,    75,    35,
      75,   338,    61,    75,   348,    64,   350,    58,    60,    60,
     161,   479,   480,   147,   148,   189,     7,    96,    97,    98,
      30,    12,    63,    30,    34,     3,    67,    34,   202,    58,
     204,    60,    73,    25,     3,   445,   115,   188,    73,   148,
     191,    35,   452,   218,   195,   219,   125,   221,   199,   199,
      70,   202,   218,   227,   133,    60,   231,   392,   196,   373,
     198,   140,   213,   214,     3,   231,   380,    58,    24,   148,
     407,    24,    58,   429,    60,   249,   227,   228,   216,   217,
     189,   359,    24,   398,   163,    24,   448,   261,   124,   340,
     264,   265,    57,   261,   130,   361,    41,   261,   508,    70,
      53,   292,    58,    59,    67,    58,    59,   258,    67,    24,
     189,    67,    67,    35,    67,    24,    60,    59,   292,    75,
      59,   259,    75,   202,    63,   204,    68,    67,    73,    68,
     268,    35,   469,    75,    79,    57,    75,    24,    53,    58,
     219,    60,   221,   317,    59,    67,    63,    27,   227,   300,
      35,    67,    67,    57,   328,    58,   330,    60,    60,   494,
      75,    24,   330,    67,   338,    57,   330,    60,   342,   343,
     249,    24,    59,    61,   488,    35,    35,   328,    68,   330,
      67,    24,   261,   292,   335,   264,   265,   338,    75,   340,
     376,    74,   366,   367,    68,    74,    59,    57,   389,     8,
      68,   352,    68,    61,    67,   356,    59,    67,   359,    24,
     361,    24,    75,   292,    67,   389,    96,    97,    98,    67,
      60,   330,    75,    24,    74,   376,   400,   365,    60,   498,
     405,     3,   400,   407,   343,   115,   400,    60,   317,   405,
      60,   379,   416,    64,    35,   125,    59,   398,   416,   328,
      57,   330,   416,   133,    67,    60,   407,    24,    59,   338,
     140,    64,    75,   342,   343,    60,    57,    68,    24,    68,
      70,    68,    60,    14,    75,   449,    67,    63,   429,    68,
     389,   471,    39,   163,   475,    68,    70,   366,   367,    58,
      68,   400,    59,    35,    51,   469,   471,    54,   484,   473,
      67,   475,    61,    59,   340,   473,    58,   416,    75,   473,
     389,    58,    68,    68,    24,    57,   352,    68,   469,    75,
     356,   400,   202,    68,   204,    67,    61,    58,   407,    68,
      96,    97,    98,   484,    34,    68,   510,   416,    68,   219,
      68,   221,   510,    67,    44,    68,   510,   227,    48,    59,
      68,    68,    68,    53,    54,    55,    56,    67,    60,   125,
      68,    68,    60,    58,   473,    75,   475,   133,    58,   249,
     449,    68,    68,    74,   140,    58,    15,   250,   484,   418,
     454,   261,   221,   454,   264,   265,   258,    29,   221,   340,
     469,   352,   328,    15,   473,   148,   475,   163,    -1,    -1,
     343,   510,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,    -1,   169,   170,   171,    -1,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,   510,   189,   190,    -1,   192,    -1,   317,   204,   196,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,   328,     3,
     330,    -1,    -1,   219,     8,    -1,    -1,    -1,   338,   216,
     217,    -1,   342,    17,     8,    -1,    -1,    11,    22,    23,
      24,    -1,    -1,    17,    -1,    29,    -1,    -1,    22,    23,
      24,    -1,    -1,   249,    -1,    29,   366,   367,    -1,    -1,
      -1,    -1,    36,    -1,    -1,   261,    -1,    -1,   264,   265,
      -1,    -1,   259,    -1,    -1,    59,    -1,    -1,    -1,    53,
      -1,   268,    -1,    67,    -1,    59,    -1,    -1,    -1,    73,
     400,    75,    -1,    67,    -1,    -1,    -1,   407,    -1,    73,
      -1,    75,    -1,    -1,   291,   292,   416,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,   306,
      -1,   317,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    34,    -1,   322,   323,    29,    -1,   449,
      -1,    -1,    -1,    44,    36,    -1,   342,    48,    49,    50,
      51,    52,    53,    54,    55,    56,   343,    49,    50,   469,
      52,    53,    -1,   473,    56,    -1,    -1,    59,    -1,    -1,
     366,   367,    -1,    -1,    -1,    67,    68,    -1,   365,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     510,    -1,   389,    -1,    -1,   392,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,    -1,    -1,     6,    -1,     8,     9,    10,
      -1,    -1,    13,    -1,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,   449,    -1,    36,    -1,    -1,   445,    -1,
      -1,    -1,    -1,    -1,    -1,   452,   453,   454,    49,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,   474,   475,   476,
      71,    72,    73,    -1,    75,    -1,    -1,     1,    -1,     3,
      -1,    -1,     6,     7,     8,     9,    10,   494,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,   508,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,    53,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,    73,
       1,    75,     3,    -1,    -1,     6,    -1,     8,     9,    10,
      -1,    -1,    13,    -1,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    52,    53,    -1,    -1,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,     3,    -1,
      71,    72,    73,     8,    75,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,     8,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    17,    -1,    59,    -1,    -1,    22,    23,    24,
      -1,    26,    67,    -1,    29,    -1,    71,    72,    73,    -1,
      75,    36,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,     8,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    17,    -1,    59,    -1,    -1,    22,    23,    24,
      -1,    26,    67,    -1,    29,    -1,    71,    72,    73,    -1,
      75,    36,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,     8,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    17,    -1,    59,    -1,    -1,    22,    23,    24,
      -1,    -1,    67,    -1,    29,    -1,    71,    72,    73,    -1,
      75,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    57,    -1,    59,     3,    -1,    -1,    -1,    -1,
       8,    -1,    67,    -1,    -1,    -1,    71,    72,    73,    17,
      75,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
       8,    49,    50,    -1,    52,    53,    -1,    -1,    56,    17,
      -1,    59,    -1,    -1,    22,    23,    24,    -1,    -1,    67,
      -1,    29,    -1,    71,    72,    73,    -1,    75,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    -1,    56,    57,
      -1,    59,     3,    -1,    -1,    -1,    -1,     8,    -1,    67,
      -1,    -1,    -1,    71,    72,    73,    17,    75,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    49,    50,
      -1,    52,    53,    -1,    -1,    56,    17,    -1,    59,    -1,
      -1,    22,    23,    24,    -1,    -1,    67,    -1,    29,    -1,
      71,    72,    73,    -1,    75,    36,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    49,    50,
      -1,    52,    53,    -1,    -1,    56,    17,    -1,    59,    -1,
      -1,    22,    23,    24,    -1,    -1,    67,    -1,    29,    -1,
      71,    72,    73,    -1,    75,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    49,    50,
      -1,    52,    53,    -1,    -1,    56,    17,    -1,    59,    -1,
      -1,    22,    23,    24,    -1,    -1,    67,    -1,    29,    -1,
      71,    72,    73,     8,    75,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    53,    -1,    29,    -1,    -1,    -1,    59,    -1,
      61,    36,    -1,    64,    -1,    -1,    67,     8,    -1,    -1,
      -1,    -1,    73,    -1,    75,    -1,    17,    -1,    53,    -1,
      -1,    22,    23,    24,    59,    -1,    61,    -1,    29,    64,
      -1,    -1,    67,     8,    -1,    36,    -1,    -1,    73,    -1,
      75,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    53,    -1,    29,    -1,    -1,    -1,    59,    -1,
      61,    36,    -1,    -1,    -1,    -1,    67,     8,    -1,    -1,
      -1,    -1,    73,    -1,    75,    -1,    17,    -1,    53,    -1,
      -1,    22,    23,    24,    59,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    67,     8,    -1,    36,    -1,    -1,    73,    -1,
      75,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    53,    -1,    29,    -1,    -1,    -1,    59,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    67,     8,    -1,    -1,
      -1,    -1,    73,    -1,    75,    -1,    17,    -1,    53,    -1,
      -1,    22,    23,    24,    59,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    67,     8,    -1,    36,    -1,    -1,    73,    -1,
      75,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    53,    -1,    29,    -1,    -1,    -1,    59,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,     4,     5,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    33,    34,    64,    36,    -1,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    -1,    74,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    70,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    -1,
      70,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    -1,    70,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    33,    34,    -1,    36,    61,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    77,    78,    24,    59,    75,   127,   128,     0,
      79,     3,    60,    21,    80,   151,    63,     3,    63,    67,
      81,    83,   127,    60,     1,     3,     6,     8,     9,    10,
      13,    15,    16,    17,    18,    19,    20,    22,    23,    27,
      28,    29,    30,    31,    32,    36,    49,    50,    52,    53,
      56,    67,    71,    72,    73,    86,    87,    88,    94,   104,
     106,   110,   111,   112,   113,   114,   115,   120,   124,   127,
     129,   130,   135,   136,   139,   142,   143,   144,   146,   149,
     150,   166,   170,    24,    59,     3,    68,    81,    82,    25,
      84,     3,   124,   126,   127,    17,    36,    53,    67,   127,
     129,   134,   138,   139,   140,   146,   126,   114,   120,    94,
     101,   102,   103,   170,   178,    67,   127,   145,   114,   124,
     105,   178,    35,    57,   123,    73,   112,   170,   177,    35,
     123,   105,    67,    92,    93,   127,    67,    89,   125,   127,
     169,   113,   113,   113,   113,   113,   113,    36,    53,   112,
     121,   133,   139,   141,   146,   113,   113,    11,   112,   176,
      60,    67,    90,   169,     4,    33,    34,    36,    37,    38,
      39,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    63,    67,
      73,    70,    67,   123,     1,   123,     5,    61,    64,    60,
     174,    24,    67,    36,    67,   132,   138,   139,   140,   141,
     146,   132,   132,    63,    35,   100,     5,    64,    60,    11,
     122,   127,   131,   132,   162,   163,   164,    67,    57,   147,
     100,    60,    24,    58,    67,   124,   156,   158,   160,   132,
      99,    53,    58,    67,   124,   155,   157,   158,   159,   168,
      35,    68,    93,   154,   132,    68,    89,   152,    61,    64,
     132,     8,   133,    68,    74,    74,    68,    90,    64,   132,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   116,    67,   127,    68,   121,   171,   112,   176,     1,
      57,    87,    96,   165,   166,   112,   116,   165,   167,   170,
     112,   170,    81,    68,    24,    85,   164,     8,   132,    68,
     127,   167,    26,    26,   178,   132,   122,   131,    61,   175,
      68,   164,   167,   108,   178,    63,    24,   158,    67,   161,
      60,   174,    74,     7,    12,    58,    95,    97,    67,   159,
      53,   159,    60,   174,     3,   179,    61,   132,    99,    60,
     174,    60,   174,   125,   170,    64,    36,    67,   132,   138,
     139,   140,   146,    57,   132,   132,    60,   174,   170,    64,
      57,   112,   117,   118,   172,   173,    31,   121,    11,    61,
     175,    74,    70,   167,    61,   175,   173,    58,    60,    60,
      68,    68,    58,   112,   112,    60,   162,    67,   127,   137,
     138,   139,   140,   141,   146,   148,    68,    58,    14,   107,
     109,   127,    68,   164,   160,    58,   132,   171,    70,    98,
     159,   179,   159,    68,   157,    58,   124,   179,    58,    93,
      68,    89,    68,   170,   132,   116,    90,    91,   153,   169,
      68,   170,   116,    70,    61,   175,    58,    68,    68,   175,
     121,    68,   176,    58,    68,    58,   165,   178,   164,    67,
     148,    20,    96,    68,     5,    61,    64,    70,   167,    68,
      68,   179,    68,   173,    60,   174,   132,   173,    57,   112,
     119,   117,   118,    68,    70,    74,    68,   164,   105,   148,
     112,   112,   179,   179,    58,    91,    68,    58,   116,   176,
      68,   100,    70,    70,   173,    74,   148,    58
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
       3,     5,     4,     0,     2,     0,     2,     5,     4,     1,
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
#line 166 "go.y" /* yacc.c:1646  */
    {
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "file", nkids, kids, leaf);
		ast_root = (yyval.ast);
	}
#line 1988 "go.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 179 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		(yyval.ast) = NULL;
		exit(2);
	}
#line 1998 "go.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 185 "go.y" /* yacc.c:1646  */
    { 
		// tree_ptr new_tree_node(int prodrule, char *prodname, int nkids, struct tree **kids, struct token *leaf)
		// struct tree **create_tree_kids(int nkids, ...)
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "package", nkids, kids, leaf);
	}
#line 2011 "go.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 197 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2019 "go.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 201 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "imports", nkids, kids, leaf);
	}
#line 2030 "go.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2041 "go.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 218 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2052 "go.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 225 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import", nkids, kids, leaf);
	}
#line 2063 "go.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 235 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt", nkids, kids, leaf);
	}
#line 2074 "go.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 242 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2082 "go.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 249 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2090 "go.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 253 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_stmt_list", nkids, kids, leaf);
	}
#line 2101 "go.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 263 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2112 "go.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 270 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2123 "go.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 277 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_here", nkids, kids, leaf);
	}
#line 2134 "go.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 287 "go.y" /* yacc.c:1646  */
    {
		// TODO: concat package and name
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "import_package", nkids, kids, leaf);
	}
#line 2146 "go.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 298 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2154 "go.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 302 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "import_safety", nkids, kids, leaf);
	}
#line 2165 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 315 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		(yyval.ast) = NULL;
	}
#line 2174 "go.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 320 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2182 "go.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 324 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2190 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 328 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2199 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 333 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2207 "go.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 340 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2218 "go.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 347 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2229 "go.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 354 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2240 "go.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 361 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2251 "go.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 368 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2262 "go.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 375 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2273 "go.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 382 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2284 "go.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 389 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2295 "go.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 396 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2306 "go.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "common_dcl", nkids, kids, leaf);
	}
#line 2317 "go.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 413 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lconst", nkids, kids, leaf);
	}
#line 2328 "go.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 423 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2339 "go.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 430 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2350 "go.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 437 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl", nkids, kids, leaf);
	}
#line 2361 "go.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 447 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2372 "go.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 454 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl", nkids, kids, leaf);
	}
#line 2383 "go.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 464 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2391 "go.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 468 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl1", nkids, kids, leaf);
	}
#line 2402 "go.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 475 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2410 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 482 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2420 "go.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 491 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl", nkids, kids, leaf);
	}
#line 2431 "go.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 501 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2439 "go.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 505 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2450 "go.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 512 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2461 "go.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 519 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2472 "go.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 526 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2483 "go.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 533 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "simple_stmt", nkids, kids, leaf);
	}
#line 2494 "go.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 543 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2505 "go.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 550 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2516 "go.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 557 "go.y" /* yacc.c:1646  */
    {
		// TODO: maybe concat tokens?
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2528 "go.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 565 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "case", nkids, kids, leaf);
	}
#line 2539 "go.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 576 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "compound_stmt", nkids, kids, leaf);
	}
#line 2550 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 586 "go.y" /* yacc.c:1646  */
    {
		// If the last token read by the lexer was consumed
		// as part of the case, clear it (parser has cleared yychar).
		// If the last token read by the lexer was the lookahead
		// leave it alone (parser has it cached in yychar).
		// This is so that the stmt_list action doesn't look at
		// the case tokens if the stmt_list is empty.
		yylast = yychar;
	}
#line 2564 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 596 "go.y" /* yacc.c:1646  */
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
#line 2589 "go.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 620 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2597 "go.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 624 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "caseblock_list", nkids, kids, leaf);
	}
#line 2608 "go.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 635 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "loop_body", nkids, kids, leaf);
	}
#line 2619 "go.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 645 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
#line 2630 "go.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 652 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t); // TODO: concat tokens
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "range_stmt", nkids, kids, leaf);
	}
#line 2641 "go.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 662 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_header", nkids, kids, leaf);
	}
#line 2652 "go.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 669 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2660 "go.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 673 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2668 "go.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 680 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_body", nkids, kids, leaf);
	}
#line 2679 "go.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 691 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "for_stmt", nkids, kids, leaf);
	}
#line 2690 "go.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 701 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2698 "go.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 705 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_header", nkids, kids, leaf);
	}
#line 2709 "go.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 719 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "if_stmt", nkids, kids, leaf);
	}
#line 2720 "go.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 730 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens "elseif"
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif", nkids, kids, leaf);
	}
#line 2731 "go.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 740 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2739 "go.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 744 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL; 
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "elseif_list", nkids, kids, leaf);
	}
#line 2750 "go.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 754 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 2758 "go.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 758 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "else", nkids, kids, leaf);
	}
#line 2769 "go.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 770 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t); // TODO: maybe concat tokens
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "switch_stmt", nkids, kids, leaf);
	}
#line 2780 "go.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 781 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-3].t); // TODO: maybe concat tokens
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "select_stmt", nkids, kids, leaf);
	}
#line 2791 "go.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 794 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2799 "go.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 798 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2810 "go.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 805 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2821 "go.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 812 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2832 "go.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 819 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2843 "go.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 826 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2854 "go.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 833 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2865 "go.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 840 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2876 "go.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 847 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2887 "go.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 854 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2898 "go.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 861 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2909 "go.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 868 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2920 "go.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 875 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2931 "go.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 882 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2942 "go.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 889 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2953 "go.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 896 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2964 "go.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 903 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2975 "go.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 910 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2986 "go.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 917 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 2997 "go.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 925 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3008 "go.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 932 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr", nkids, kids, leaf);
	}
#line 3019 "go.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 942 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3027 "go.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 946 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3038 "go.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 953 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3049 "go.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 960 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3060 "go.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 967 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3071 "go.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 974 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3082 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 981 "go.y" /* yacc.c:1646  */
    {
		yyerror("the bitwise complement operator is ^");
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3094 "go.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 989 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3105 "go.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 996 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "uexpr", nkids, kids, leaf);
	}
#line 3116 "go.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1010 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3127 "go.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1017 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3138 "go.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1024 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pseudocall", nkids, kids, leaf);
	}
#line 3149 "go.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1034 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3160 "go.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1041 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3168 "go.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1045 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3179 "go.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1052 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3190 "go.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1059 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3201 "go.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1066 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3212 "go.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1073 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3223 "go.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1080 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-7].ast), (yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3234 "go.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1087 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3242 "go.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1091 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3253 "go.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1098 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3264 "go.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1105 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3275 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1112 "go.y" /* yacc.c:1646  */
    {
		yyerror("cannot parenthesize type in composite literal");

		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr_no_paren", nkids, kids, leaf);
	}
#line 3288 "go.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1121 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3296 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1128 "go.y" /* yacc.c:1646  */
    {
		// composite expression.
		// make node early so we get the right line number.
		(yyval.ast) = NULL;
	}
#line 3306 "go.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1137 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval", nkids, kids, leaf);
	}
#line 3317 "go.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1147 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3325 "go.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1151 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "bare_complitexpr", nkids, kids, leaf);
	}
#line 3336 "go.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1161 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3344 "go.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1165 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "complitexpr", nkids, kids, leaf);
	}
#line 3355 "go.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1175 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3363 "go.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1179 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "pexpr", nkids, kids, leaf);
	}
#line 3374 "go.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1189 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3382 "go.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1193 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type", nkids, kids, leaf);
	}
#line 3393 "go.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1203 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);

	}
#line 3402 "go.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1211 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3413 "go.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1218 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "lbrace", nkids, kids, leaf);
	}
#line 3424 "go.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1233 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3432 "go.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1240 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3440 "go.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1247 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3448 "go.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1251 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3456 "go.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1258 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3467 "go.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1265 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3475 "go.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1269 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3486 "go.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1279 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3497 "go.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1286 "go.y" /* yacc.c:1646  */
    {
		struct token* leaf = (yyvsp[-2].t); // TODO: concat tokens ?
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "sym", nkids, kids, leaf);
	}
#line 3508 "go.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1296 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "name", nkids, kids, leaf);
	}
#line 3519 "go.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1306 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3527 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1322 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");

		struct token *leaf = (yyvsp[0].t);
		int nkids = 0;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3540 "go.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1331 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotdotdot", nkids, kids, leaf);
	}
#line 3551 "go.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1341 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3559 "go.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1345 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3567 "go.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1349 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3575 "go.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1353 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3583 "go.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1357 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3591 "go.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1361 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "ntype", nkids, kids, leaf);
	}
#line 3602 "go.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1371 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3610 "go.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1375 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3618 "go.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1379 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3626 "go.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1383 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_expr_type", nkids, kids, leaf);
	}
#line 3637 "go.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1393 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3645 "go.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1397 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);;
	}
#line 3653 "go.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1401 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3661 "go.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1405 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3669 "go.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1409 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 3677 "go.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1416 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3685 "go.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1420 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3693 "go.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1427 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3701 "go.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1434 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3709 "go.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1438 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3717 "go.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1442 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3725 "go.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1446 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3733 "go.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1450 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3741 "go.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1457 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3749 "go.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1461 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dotname", nkids, kids, leaf);
	}
#line 3760 "go.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1471 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3771 "go.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1478 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3782 "go.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1485 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3793 "go.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1492 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3804 "go.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1499 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].t), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "othertype", nkids, kids, leaf);
	}
#line 3815 "go.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1506 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3823 "go.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1510 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3831 "go.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1517 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3839 "go.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1525 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	// TODO: concat tokens ?
		int nkids = 1;
		struct tree * t1 = new_tree_node(LCOMM, "recvchantype", 0, NULL, (yyvsp[-2].t));
		struct tree * t2 =  new_tree_node(++ruleno, "recvchantype", 0, NULL, (yyvsp[-1].t));
		struct tree ** kids = safe_malloc(3*sizeof(*kids));
		kids[0] = t1;
		kids[1] = t2;
		kids[2] = (yyvsp[0].ast);
		// struct tree** kids = create_tree_kids(nkids, $3);
		(yyval.ast) = new_tree_node(++ruleno, "recvchantype", nkids, kids, leaf);
	}
#line 3856 "go.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1541 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 3867 "go.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1548 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);	
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structtype", nkids, kids, leaf);
	}
#line 3878 "go.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1558 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
#line 3889 "go.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1565 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacetype", nkids, kids, leaf);
	}
#line 3900 "go.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1579 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xfndcl", nkids, kids, leaf);
	}
#line 3911 "go.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1589 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 3922 "go.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1596 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 4;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fndcl", nkids, kids, leaf);
	}
#line 3933 "go.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1623 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-4].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fntype", nkids, kids, leaf);
	}
#line 3944 "go.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1633 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3952 "go.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1637 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 3960 "go.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1644 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 3968 "go.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1648 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3976 "go.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1652 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 3984 "go.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1659 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3992 "go.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1666 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 4003 "go.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1673 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "fnliteral", nkids, kids, leaf);
	}
#line 4014 "go.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1688 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4022 "go.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1692 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast));
		(yyval.ast) = new_tree_node(++ruleno, "xdcl_list", nkids, kids, leaf);
	}
#line 4033 "go.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1702 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4041 "go.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1706 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "vardcl_list", nkids, kids, leaf);
	}
#line 4052 "go.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1716 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4060 "go.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1720 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "constdcl_list", nkids, kids, leaf);
	}
#line 4071 "go.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1730 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4079 "go.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1734 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "typedcl_list", nkids, kids, leaf);
	}
#line 4090 "go.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1744 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4098 "go.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1748 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl_list", nkids, kids, leaf);
	}
#line 4109 "go.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1758 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4117 "go.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1762 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl_list", nkids, kids, leaf);
	}
#line 4128 "go.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1772 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4139 "go.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1779 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4150 "go.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1786 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4161 "go.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1793 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4172 "go.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1800 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4183 "go.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1807 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "structdcl", nkids, kids, leaf);
	}
#line 4194 "go.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1817 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[0].t);
		int nkids = 1;
		struct tree** kids = NULL;
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 4205 "go.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1824 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-2].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "packname", nkids, kids, leaf);
	}
#line 4216 "go.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1834 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4224 "go.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1841 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "interfacedcl", nkids, kids, leaf);
	}
#line 4235 "go.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1848 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4243 "go.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1852 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[-1].ast);
	}
#line 4251 "go.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1859 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "indcl", nkids, kids, leaf);
	}
#line 4262 "go.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1872 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4270 "go.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1876 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4281 "go.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1883 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type", nkids, kids, leaf);
	}
#line 4292 "go.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1890 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4300 "go.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1897 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4308 "go.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1901 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "arg_type_list", nkids, kids, leaf);
	}
#line 4319 "go.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1911 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4327 "go.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1915 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "oarg_type_list_ocomma", nkids, kids, leaf);
	}
#line 4338 "go.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1928 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4346 "go.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1932 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4354 "go.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1936 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4362 "go.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1940 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4370 "go.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1944 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4378 "go.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1951 "go.y" /* yacc.c:1646  */
    {
		
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4387 "go.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1956 "go.y" /* yacc.c:1646  */
    {
		
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4396 "go.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1961 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4404 "go.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1965 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4412 "go.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1969 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4420 "go.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1974 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 22;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4431 "go.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1981 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4442 "go.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1988 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4453 "go.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1995 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4464 "go.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 2002 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4475 "go.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 2009 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4486 "go.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 2016 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4497 "go.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 2023 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = (yyvsp[-1].t);
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "non_dcl_stmt", nkids, kids, leaf);
	}
#line 4508 "go.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 2033 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4516 "go.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 2037 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "stmt_list", nkids, kids, leaf);
	}
#line 4527 "go.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 2047 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4535 "go.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 2051 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "new_name_list", nkids, kids, leaf);
	}
#line 4546 "go.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 2061 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4554 "go.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 2065 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "dcl_name_list", nkids, kids, leaf);
	}
#line 4565 "go.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 2075 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4573 "go.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 2079 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_list", nkids, kids, leaf);
	}
#line 4584 "go.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 2089 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4592 "go.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 2093 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "expr_or_type_list", nkids, kids, leaf);
	}
#line 4603 "go.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 2106 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4611 "go.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 2110 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4619 "go.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 2114 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4630 "go.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 2121 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "keyval_list", nkids, kids, leaf);
	}
#line 4641 "go.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 2131 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4649 "go.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 2135 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(++ruleno, "braced_keyval_list", nkids, kids, leaf);
	}
#line 4660 "go.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 2148 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4668 "go.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 2152 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "osemi", 0, NULL, (yyvsp[0].t));
	}
#line 4676 "go.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 2159 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4684 "go.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2163 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_tree_node(++ruleno, "ocomma", 0, NULL, (yyvsp[0].t));
	}
#line 4692 "go.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2170 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4700 "go.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2174 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4708 "go.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2181 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4716 "go.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2185 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4724 "go.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2192 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4732 "go.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 2196 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4740 "go.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 2236 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = NULL;
	}
#line 4748 "go.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 2240 "go.y" /* yacc.c:1646  */
    {
		struct token *leaf = NULL;
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].t));
		(yyval.ast) = new_tree_node(++ruleno, "oliteral", nkids, kids, leaf);
	}
#line 4759 "go.tab.c" /* yacc.c:1646  */
    break;


#line 4763 "go.tab.c" /* yacc.c:1646  */
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
#line 2583 "go.y" /* yacc.c:1906  */

