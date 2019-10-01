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
	fprintf(stderr, "ERROR: found '%s' token at line %d in file %s\n",
	   yytext,yylineno,yyfilename);
	exit(2);
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
#define YYLAST   1095

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  396

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
       2,     2,     2,    65,     2,     2,     2,    55,    56,     2,
      74,    75,    53,    49,    61,    50,    63,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    60,
      70,    64,     2,    59,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    52,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    51,    58,    66,     2,     2,     2,
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
      45,    46,    47,    48,    72,    73,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   169,   175,   186,   190,   200,   207,   216,
     228,   234,   241,   245,   255,   262,   269,   280,   292,   296,
     309,   314,   318,   322,   327,   334,   341,   350,   359,   365,
     373,   382,   390,   397,   406,   418,   428,   434,   441,   451,
     458,   468,   472,   478,   485,   494,   503,   507,   514,   521,
     528,   535,   545,   557,   569,   577,   584,   593,   604,   608,
     619,   632,   644,   648,   657,   661,   674,   678,   685,   692,
     699,   706,   713,   720,   727,   734,   741,   748,   755,   762,
     769,   776,   783,   790,   798,   805,   815,   819,   826,   833,
     840,   847,   855,   869,   877,   885,   897,   904,   908,   915,
     924,   934,   942,   946,   954,   961,   970,   974,   985,   989,
     996,  1004,  1019,  1026,  1033,  1040,  1044,  1054,  1064,  1077,
    1094,  1103,  1113,  1117,  1121,  1125,  1129,  1140,  1144,  1148,
    1158,  1162,  1169,  1176,  1180,  1184,  1188,  1195,  1199,  1209,
    1217,  1226,  1235,  1242,  1252,  1260,  1275,  1285,  1293,  1307,
    1319,  1323,  1334,  1338,  1342,  1353,  1360,  1367,  1381,  1385,
    1395,  1399,  1409,  1413,  1423,  1427,  1437,  1441,  1451,  1457,
    1463,  1471,  1478,  1487,  1499,  1506,  1517,  1527,  1531,  1537,
    1543,  1550,  1554,  1564,  1568,  1580,  1584,  1588,  1592,  1596,
    1603,  1607,  1611,  1615,  1625,  1629,  1639,  1643,  1653,  1657,
    1667,  1671,  1681,  1685,  1698,  1702,  1706,  1713,  1723,  1727,
    1740,  1744,  1754,  1758,  1768,  1772,  1779,  1783,  1790,  1794,
    1802,  1806,  1816,  1824,  1834,  1838,  1849,  1853
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
  "','", "'`'", "'.'", "'='", "'!'", "'~'", "'['", "']'", "'@'", "'<'",
  "':'", "NotPackage", "NotParen", "'('", "')'", "PreferToRightParen",
  "$accept", "file", "package", "imports", "import", "import_stmt",
  "import_stmt_list", "import_here", "import_package", "import_safety",
  "xdcl", "common_dcl", "lconst", "vardcl", "constdcl", "constdcl1",
  "typedclname", "typedcl", "simple_stmt", "compound_stmt", "loop_body",
  "for_header", "for_body", "for_stmt", "if_header", "if_stmt", "elseif",
  "elseif_list", "else", "expr", "uexpr", "pseudocall", "pexpr_no_paren",
  "pexpr", "expr_or_type", "name_or_type", "lbrace", "new_name",
  "dcl_name", "sym", "hidden_importsym", "name", "dotdotdot", "ntype",
  "non_expr_type", "convtype", "comptype", "fnret_type", "dotname",
  "othertype", "ptrtype", "structtype", "xfndcl", "fndcl", "fntype",
  "fnbody", "fnres", "fnlitdcl", "fnliteral", "xdcl_list", "vardcl_list",
  "constdcl_list", "typedcl_list", "structdcl_list", "structdcl",
  "packname", "embed", "arg_type", "arg_type_list",
  "oarg_type_list_ocomma", "stmt", "non_dcl_stmt", "stmt_list",
  "new_name_list", "dcl_name_list", "expr_list", "expr_or_type_list",
  "keyval_list", "braced_keyval_list", "osemi", "ocomma", "oexpr",
  "oexpr_list", "osimple_stmt", "oliteral", "start_complit", "keyval",
  "bare_complitexpr", "complitexpr", YY_NULLPTR
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
      59,    44,    96,    46,    61,    33,   126,    91,    93,    64,
      60,    58,   304,   305,    40,    41,   306
};
# endif

#define YYPACT_NINF -309

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-309)))

#define YYTABLE_NINF -201

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   149,    52,  -309,  -309,  -309,    50,    -4,  -309,  -309,
      38,     8,  -309,   173,     5,   469,    19,  -309,    59,   146,
    -309,    45,    73,  -309,  -309,  -309,  -309,   728,    27,   728,
      16,   728,    72,   257,   298,   728,   728,   728,   728,   728,
     728,   624,   739,    24,  -309,   326,  -309,  -309,  -309,   795,
    -309,  -309,  -309,   139,  -309,  -309,    69,    72,   100,  -309,
    -309,    78,    30,  -309,  -309,    95,  -309,  -309,  -309,  -309,
    -309,    98,   143,  -309,  -309,    89,  -309,   125,  -309,   131,
     245,   126,   150,   125,   151,   840,   968,   159,  -309,  -309,
     300,   109,   840,  -309,  -309,   180,  -309,  -309,  -309,   756,
    -309,  -309,  -309,  -309,  -309,  -309,   142,   968,   154,   739,
     968,   152,  -309,   -11,     7,  -309,   224,  -309,   837,   728,
     728,   728,   728,  -309,   728,   728,   728,  -309,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   330,   728,   491,   728,  -309,  -309,   571,   728,   728,
     728,   174,   163,   202,   245,   571,  -309,   728,   840,   840,
     840,  -309,   245,   171,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,   183,   176,   245,   571,  -309,  -309,   728,   178,    88,
      31,  -309,    21,  -309,  -309,   192,  -309,  -309,   250,   407,
    -309,  -309,   194,  -309,  -309,  -309,   201,   149,   728,   199,
     840,   840,  -309,  -309,  -309,   204,   728,   203,   968,  1039,
    -309,   992,   608,   608,   608,   608,  -309,   608,   608,  1016,
    -309,    13,    13,    13,  -309,  -309,  -309,  -309,   663,  -309,
     918,  -309,  -309,   124,   944,   652,  -309,   571,  -309,  -309,
    -309,  -309,    17,   159,   968,   159,  -309,  -309,  -309,   205,
     220,   123,   217,  -309,  -309,   222,  -309,  -309,   149,   245,
    -309,   857,   225,   129,   289,  -309,   840,   149,   244,   284,
     250,   284,   234,   166,   252,  -309,  -309,   149,   250,   149,
     236,   149,   242,  -309,   159,   728,  -309,  -309,   149,   255,
     159,   728,   259,   262,  -309,   264,   739,   263,  -309,   265,
    -309,   889,   266,   260,  -309,  -309,   141,  -309,   571,  -309,
     857,  -309,   728,  -309,  -309,  -309,   245,   267,  -309,  -309,
    -309,  -309,  -309,  -309,   857,  -309,     3,  -309,  -309,  -309,
    -309,   268,  -309,   272,   250,  -309,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,   159,  -309,  -309,   288,   837,  -309,   159,
    -309,  -309,   274,  -309,  -309,  -309,   652,   717,   652,  -309,
    -309,  -309,  -309,  -309,   280,   245,  -309,   728,  -309,   250,
     250,  -309,   149,   281,   203,  -309,   304,  -309,   968,  -309,
    -309,  -309,  -309,   290,   125,  -309,  -309,  -309,  -309,  -309,
     652,   857,  -309,   305,  -309,  -309
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     5,   114,   116,     0,     0,   115,     1,
     158,     0,     4,     0,     0,     0,     0,    14,     0,     0,
       7,    11,     0,     6,    24,    96,    35,   218,     0,   218,
       0,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,    21,     0,   190,   191,   192,    46,
      66,   102,   106,    86,   119,    97,     0,     0,   131,   142,
      22,   155,     0,   105,    23,     0,   117,   118,    16,     9,
      12,   210,     0,    10,    15,     0,   219,     0,    57,    55,
     183,     0,   150,     0,    58,     0,   200,   217,   193,   111,
       0,     0,     0,    32,    44,     0,    25,   198,   113,     0,
      92,    88,    89,    87,    90,    91,     0,   215,     0,     0,
     108,     0,   109,   128,   127,   159,     0,    28,     0,     0,
       0,     0,     0,    51,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   157,     0,     0,     0,
       0,   211,     0,    18,   183,     0,    56,   218,   120,     0,
       0,   177,   119,   137,   180,   110,   125,   123,   124,   122,
     181,   212,     0,   183,     0,   146,    62,   218,     0,   114,
       0,   145,     0,   196,   112,   210,   166,   176,   220,     0,
      34,   164,   210,    45,    27,   160,   210,     0,     0,    36,
       0,     0,   129,   107,    31,   210,     0,     0,    47,    68,
      82,    85,    69,    73,    74,    72,    83,    71,    70,    67,
      84,    75,    76,    77,    78,    79,    80,    81,     0,    98,
       0,    93,   202,   212,   212,   208,   189,     0,   187,   186,
     194,   188,     0,    49,   201,    48,    13,     8,    19,     0,
       0,     0,     0,   121,   143,     0,   178,   179,     0,   213,
     184,   152,     0,     0,    64,    59,     0,     0,   174,     0,
     220,     0,     0,   211,     0,   221,   169,     0,   220,   211,
       0,   211,     0,   199,    38,     0,   140,   139,   211,     0,
      40,     0,     0,     0,   101,   212,   213,     0,   213,     0,
     222,   224,   212,     0,   204,   205,     0,   156,     0,    17,
     152,    53,   218,   126,   138,   182,   183,   119,   153,   136,
     134,   135,   133,   149,   152,   151,     0,    63,    60,   141,
     175,     0,   171,     0,   220,   167,   144,   197,   168,   165,
      33,   161,    26,    37,    41,   162,   210,    43,    29,    39,
     100,    99,     0,   203,    94,   103,   208,     0,   213,   209,
     104,    52,   195,    54,     0,   183,   147,   218,    65,   220,
     220,   170,   211,     0,    42,    95,     0,   222,   226,   223,
     206,   207,   154,     0,     0,   173,   172,   163,    30,   225,
     208,   152,    61,     0,   148,   227
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,  -309,  -309,  -309,    -9,  -309,  -309,  -309,  -309,
    -309,   351,  -309,   -89,   -21,    -2,  -309,   -86,   -16,    42,
     -82,  -309,  -309,  -309,     6,  -309,  -309,  -309,  -309,   -12,
       2,  -309,  -309,  -309,  -136,   214,    -8,   105,   187,    -1,
    -309,   221,   215,    70,   278,  -309,  -309,  -309,  -252,   132,
    -225,  -309,  -309,  -309,   243,  -309,  -298,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,   115,  -309,  -165,   133,  -309,  -151,
      82,   381,  -139,  -309,   -43,    -3,  -309,  -309,  -308,  -171,
    -131,  -309,  -309,   -23,  -190,  -280,    48,    49,  -309
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    71,    21,    73,   249,
      43,   238,    45,    96,   344,   345,    92,    93,    46,   239,
     156,    77,    78,    47,    83,    48,   327,   264,   328,    49,
      50,    51,    52,    53,   111,   161,    90,   183,    97,    54,
       8,    55,   164,   165,   112,    56,    57,   318,   166,    58,
     168,    59,    60,    82,    61,   175,   323,    62,    63,    15,
     196,   346,   192,   185,   186,   187,   188,   170,   171,   172,
     240,   241,   242,   189,    99,    65,   233,   302,   303,   152,
     260,   108,    88,    84,   276,   235,   304,   305,   379
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,   176,   118,   250,    79,   191,   195,   232,  -155,   319,
      70,    76,    22,    76,   274,   270,   251,   272,    22,    86,
     356,   280,   262,   367,   117,   282,   366,    81,    87,   107,
     110,   146,    94,    98,   289,   263,   321,   100,   101,   102,
     103,   104,   105,    66,    98,   268,  -132,   121,   376,   145,
       1,     4,     9,    11,   147,   268,    12,   129,   319,    13,
     237,   133,    68,  -131,  -155,    23,   137,   138,   139,   140,
      72,    16,   319,   118,   271,   307,    74,   308,    67,   162,
     332,  -130,   393,    85,   115,   321,     5,    89,   338,   184,
      94,  -174,   293,   394,    98,   205,     6,   390,   306,   321,
     148,    80,   297,   299,   331,   269,   333,   208,   209,   210,
     211,   103,   212,   213,   214,    98,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    89,
     230,   110,   234,     4,   252,   295,    86,   244,    86,   319,
     229,    76,   246,   144,   371,   243,  -174,   245,  -174,    17,
      22,   267,  -130,   162,   265,   178,   149,  -132,   151,   150,
     353,    76,   193,   154,   352,   364,   321,   153,     5,   199,
       4,   359,   162,     4,   113,   373,    17,    17,     6,   385,
     386,   311,   155,   308,   190,   296,    86,   325,   207,   308,
     179,   157,   341,   339,    86,   284,    98,     4,     4,   361,
     173,   308,   141,   290,     4,     5,   142,   174,     5,    18,
     200,   177,   167,   143,   383,     6,   110,   167,     6,   180,
     149,    69,   201,   301,   167,     5,   248,   203,   253,   254,
     255,   167,     5,     5,   258,     6,    18,    18,   247,     5,
     182,   113,     6,     6,   259,   347,   266,    19,     4,     6,
     167,   261,   273,   275,   279,   194,   158,   314,   162,   278,
     317,   281,    75,   285,   288,   309,   330,   291,    30,     4,
     286,   287,   184,    86,    32,   113,   184,   312,    94,    86,
      98,     4,   343,     5,   110,   114,   167,    98,   349,   363,
     167,   167,   167,     6,   167,   310,    76,   313,   159,   204,
     324,   163,   392,   326,     5,   167,   163,   267,   268,   334,
     336,   340,    41,   163,     6,   162,     5,   342,   360,   160,
     163,   167,     4,   169,   179,   298,     6,   358,   169,   347,
     348,    91,   167,   167,   350,   169,   329,   351,   354,   163,
     355,   365,   169,   369,   301,   378,   301,   370,   372,   375,
       4,    76,   114,   180,     4,   382,   388,     5,   181,     5,
     113,   169,   389,   395,   162,   391,    44,     6,   368,     6,
     387,    98,    95,   384,   182,   163,   256,   257,   301,   163,
     163,   163,   337,   163,   283,     5,   114,   202,   335,     5,
     362,   167,   315,   320,   163,     6,    64,   169,   167,     6,
     116,   169,   169,   169,   228,   169,   380,   381,     0,     0,
     163,     0,     0,     0,     0,     0,   169,   374,     0,     0,
       0,   163,   163,     0,    75,     0,     0,     0,   113,     0,
      30,     4,   169,     0,     0,     0,    32,     0,     0,     0,
       0,     0,   320,   169,   169,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,   320,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     5,     0,   277,    -2,
      24,   114,    25,     0,    41,     0,     6,     0,    26,   167,
     163,   160,   163,     0,     0,    27,    28,   163,     0,    29,
       0,     0,    30,     4,    25,     0,    31,   167,    32,     0,
      33,    34,   169,     0,   322,    35,     0,     0,    75,   169,
       0,     0,     0,     0,    30,     4,     0,     0,    36,    37,
      32,     0,    38,   320,     0,     0,     0,    35,     5,   -20,
       0,   163,     0,     0,    39,    40,    41,   163,     6,   114,
      36,    37,     0,    42,   109,   163,     0,     0,     0,     0,
       5,     0,     0,   322,     0,     0,    39,    40,    41,   169,
       6,     0,     0,     0,     0,    42,   231,   322,   163,     0,
       0,     0,   236,     0,    25,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,   163,    27,    75,     0,
     169,    29,     0,     0,    30,     4,     0,     0,    31,     0,
      32,     0,    33,    34,     0,     0,     0,    35,   169,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
      36,    37,     0,     0,    38,     0,     0,    25,   237,  -185,
       5,  -185,     0,     0,   322,   106,    39,    40,    41,     0,
       6,    75,   121,     0,     0,    42,     0,    30,     4,     0,
       0,     0,   129,    32,     0,    25,   133,   134,   135,   136,
      35,   137,   138,   139,   140,     0,    25,     0,     0,    75,
       0,     0,     0,    36,    37,    30,     4,    38,     0,     0,
      75,    32,     0,     5,     0,     0,    30,     4,    35,    39,
      40,    41,    32,     6,   292,     0,     0,     0,    42,    35,
       0,    36,    37,     0,     0,    38,     0,     0,     0,   300,
       0,     5,    36,    37,     0,     0,   109,    39,    40,    41,
      25,     6,     5,     0,     0,     0,    42,     0,    39,    40,
      41,    25,     6,     0,    75,     0,     0,    42,     0,     0,
      30,     4,    25,     0,     0,    75,    32,     0,     0,     0,
       0,    30,     4,    35,     0,     0,    75,    32,     0,     0,
       0,     0,    30,     4,    35,     0,    36,    37,    32,     0,
      38,     0,     0,    75,   377,    35,     5,    36,    37,    30,
       4,    38,    39,    40,    41,    32,     6,     5,    36,    37,
       0,    42,   109,    39,    40,    41,     0,     6,     5,   119,
    -200,     0,    42,     0,    39,    40,    41,     0,     6,   159,
       0,     0,     0,    42,     0,     5,     0,   197,     0,     0,
     198,     0,     0,    41,     0,     6,     0,     0,   120,   121,
     160,   122,   123,   124,   125,   126,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,   137,   138,
     139,   140,     0,     0,    75,     0,  -200,    75,     0,  -200,
      30,     4,     0,    30,     4,     0,    32,     0,     0,    32,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
      30,     4,     0,     0,     0,     0,    32,     0,     0,     0,
     159,     0,     0,   159,     0,     0,     5,     0,   197,     5,
       0,   206,     0,     0,    41,     0,     6,    41,     0,     6,
     159,   160,     0,     0,   160,     0,     5,     0,     0,     0,
       0,     0,   120,   121,    41,   122,     6,   124,   125,   126,
       0,   316,   128,   129,   130,   131,   132,   133,   134,   135,
     136,     0,   137,   138,   139,   140,     0,     0,     0,     0,
       0,   120,   121,     0,   122,     0,   124,   125,   126,     0,
     357,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   139,   140,     0,     0,   120,   121,     0,
     122,     0,   124,   125,   126,     0,   294,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,   137,   138,   139,
     140,   120,   121,     0,   122,   298,   124,   125,   126,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   139,   140,   120,   121,     0,     0,     0,
     124,   125,   126,     0,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,   137,   138,   139,   140,   120,
     121,     0,     0,     0,   124,   125,   126,     0,     0,   128,
     129,   130,   131,     0,   133,   134,   135,   136,     0,   137,
     138,   139,   140,   121,     0,     0,     0,   124,   125,   126,
       0,     0,   128,   129,   130,   131,     0,   133,   134,   135,
     136,     0,   137,   138,   139,   140
};

static const yytype_int16 yycheck[] =
{
       1,    83,    45,   154,    27,    91,    95,   143,     1,   261,
      19,    27,    13,    29,   185,   180,   155,   182,    19,    31,
     300,   192,   173,    20,    45,   196,   324,    28,    31,    41,
      42,     1,    33,    34,   205,   174,   261,    35,    36,    37,
      38,    39,    40,    24,    45,    24,    57,    34,   356,    57,
      25,    24,     0,     3,    62,    24,    60,    44,   310,    21,
      57,    48,     3,    74,    57,    60,    53,    54,    55,    56,
      25,    63,   324,   116,    53,    58,     3,    60,    59,    80,
     270,    74,   390,    67,    60,   310,    59,    57,   278,    90,
      91,     3,   228,   391,    95,   116,    69,   377,   237,   324,
       5,    74,   233,   234,   269,    74,   271,   119,   120,   121,
     122,   109,   124,   125,   126,   116,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    57,
     142,   143,   144,    24,   157,    11,   148,   149,   150,   391,
     141,   157,   151,    74,   334,   148,    58,   150,    60,     3,
     151,    63,    74,   154,   177,    85,    61,    57,    60,    64,
     296,   177,    92,    74,   295,   316,   391,    24,    59,    99,
      24,   302,   173,    24,    42,   346,     3,     3,    69,   369,
     370,    58,    57,    60,    75,    61,   198,    58,   118,    60,
      24,    60,   281,   279,   206,   198,   197,    24,    24,    58,
      74,    60,    63,   206,    24,    59,    67,    57,    59,    63,
      68,    60,    80,    74,   365,    69,   228,    85,    69,    53,
      61,    75,    68,   235,    92,    59,    24,    75,   158,   159,
     160,    99,    59,    59,    63,    69,    63,    63,    75,    59,
      74,   109,    69,    69,    61,   288,    68,    74,    24,    69,
     118,    75,    60,     3,    60,    75,    11,   258,   259,   189,
     261,    60,    17,    64,    60,    60,   267,    64,    23,    24,
     200,   201,   273,   285,    29,   143,   277,    60,   279,   291,
     281,    24,   285,    59,   296,    42,   154,   288,   291,   312,
     158,   159,   160,    69,   162,    75,   312,    75,    53,    75,
      75,    80,   384,    14,    59,   173,    85,    63,    24,    75,
      58,    75,    67,    92,    69,   316,    59,    75,    58,    74,
      99,   189,    24,    80,    24,    61,    69,    61,    85,   372,
      75,    74,   200,   201,    75,    92,   266,    75,    75,   118,
      75,    74,    99,    75,   356,   357,   358,    75,    60,    75,
      24,   367,   109,    53,    24,    75,    75,    59,    58,    59,
     228,   118,    58,    58,   365,    75,    15,    69,   326,    69,
     372,   372,    74,   367,    74,   154,   162,   162,   390,   158,
     159,   160,   277,   162,   197,    59,   143,   109,   273,    59,
     308,   259,   259,   261,   173,    69,    15,   154,   266,    69,
      74,   158,   159,   160,    74,   162,   358,   358,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,   173,   347,    -1,    -1,
      -1,   200,   201,    -1,    17,    -1,    -1,    -1,   296,    -1,
      23,    24,   189,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,   310,   200,   201,    -1,    -1,    -1,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,     0,
       1,   228,     3,    -1,    67,    -1,    69,    -1,     9,   347,
     259,    74,   261,    -1,    -1,    16,    17,   266,    -1,    20,
      -1,    -1,    23,    24,     3,    -1,    27,   365,    29,    -1,
      31,    32,   259,    -1,   261,    36,    -1,    -1,    17,   266,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    49,    50,
      29,    -1,    53,   391,    -1,    -1,    -1,    36,    59,    60,
      -1,   310,    -1,    -1,    65,    66,    67,   316,    69,   296,
      49,    50,    -1,    74,    53,   324,    -1,    -1,    -1,    -1,
      59,    -1,    -1,   310,    -1,    -1,    65,    66,    67,   316,
      69,    -1,    -1,    -1,    -1,    74,    75,   324,   347,    -1,
      -1,    -1,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,   365,    16,    17,    -1,
     347,    20,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,
      29,    -1,    31,    32,    -1,    -1,    -1,    36,   365,    -1,
      -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    53,    -1,    -1,     3,    57,    58,
      59,    60,    -1,    -1,   391,    11,    65,    66,    67,    -1,
      69,    17,    34,    -1,    -1,    74,    -1,    23,    24,    -1,
      -1,    -1,    44,    29,    -1,     3,    48,    49,    50,    51,
      36,    53,    54,    55,    56,    -1,     3,    -1,    -1,    17,
      -1,    -1,    -1,    49,    50,    23,    24,    53,    -1,    -1,
      17,    29,    -1,    59,    -1,    -1,    23,    24,    36,    65,
      66,    67,    29,    69,    31,    -1,    -1,    -1,    74,    36,
      -1,    49,    50,    -1,    -1,    53,    -1,    -1,    -1,    57,
      -1,    59,    49,    50,    -1,    -1,    53,    65,    66,    67,
       3,    69,    59,    -1,    -1,    -1,    74,    -1,    65,    66,
      67,     3,    69,    -1,    17,    -1,    -1,    74,    -1,    -1,
      23,    24,     3,    -1,    -1,    17,    29,    -1,    -1,    -1,
      -1,    23,    24,    36,    -1,    -1,    17,    29,    -1,    -1,
      -1,    -1,    23,    24,    36,    -1,    49,    50,    29,    -1,
      53,    -1,    -1,    17,    57,    36,    59,    49,    50,    23,
      24,    53,    65,    66,    67,    29,    69,    59,    49,    50,
      -1,    74,    53,    65,    66,    67,    -1,    69,    59,     4,
       5,    -1,    74,    -1,    65,    66,    67,    -1,    69,    53,
      -1,    -1,    -1,    74,    -1,    59,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    -1,    69,    -1,    -1,    33,    34,
      74,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    -1,    -1,    17,    -1,    61,    17,    -1,    64,
      23,    24,    -1,    23,    24,    -1,    29,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      53,    -1,    -1,    53,    -1,    -1,    59,    -1,    61,    59,
      -1,    64,    -1,    -1,    67,    -1,    69,    67,    -1,    69,
      53,    74,    -1,    -1,    74,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    33,    34,    67,    36,    69,    38,    39,    40,
      -1,    74,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    -1,
      71,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    -1,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    -1,    68,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    33,    34,    -1,    36,    61,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    -1,    53,
      54,    55,    56,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    -1,    53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    78,    79,    24,    59,    69,   116,   117,     0,
      80,     3,    60,    21,    81,   136,    63,     3,    63,    74,
      82,    84,   116,    60,     1,     3,     9,    16,    17,    20,
      23,    27,    29,    31,    32,    36,    49,    50,    53,    65,
      66,    67,    74,    87,    88,    89,    95,   100,   102,   106,
     107,   108,   109,   110,   116,   118,   122,   123,   126,   128,
     129,   131,   134,   135,   148,   152,    24,    59,     3,    75,
      82,    83,    25,    85,     3,    17,    95,    98,    99,   160,
      74,   116,   130,   101,   160,    67,   106,   152,   159,    57,
     113,    74,    93,    94,   116,    74,    90,   115,   116,   151,
     107,   107,   107,   107,   107,   107,    11,   106,   158,    53,
     106,   111,   121,   126,   131,    60,    74,    91,   151,     4,
      33,    34,    36,    37,    38,    39,    40,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    53,    54,    55,
      56,    63,    67,    74,    74,   113,     1,   113,     5,    61,
      64,    60,   156,    24,    74,    57,    97,    60,    11,    53,
      74,   112,   116,   118,   119,   120,   125,   126,   127,   131,
     144,   145,   146,    74,    57,   132,    97,    60,   120,    24,
      53,    58,    74,   114,   116,   140,   141,   142,   143,   150,
      75,    94,   139,   120,    75,    90,   137,    61,    64,   120,
      68,    68,   121,    75,    75,    91,    64,   120,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,    74,   116,
     106,    75,   111,   153,   106,   162,     1,    57,    88,    96,
     147,   148,   149,   152,   106,   152,    82,    75,    24,    86,
     146,   149,   160,   120,   120,   120,   112,   119,    63,    61,
     157,    75,   146,   149,   104,   160,    68,    63,    24,    74,
     143,    53,   143,    60,   156,     3,   161,    61,   120,    60,
     156,    60,   156,   115,   152,    64,   120,   120,    60,   156,
     152,    64,    31,   111,    68,    11,    61,   157,    61,   157,
      57,   106,   154,   155,   163,   164,   149,    58,    60,    60,
      75,    58,    60,    75,   116,   144,    74,   116,   124,   125,
     126,   127,   131,   133,    75,    58,    14,   103,   105,   120,
     116,   143,   161,   143,    75,   141,    58,   114,   161,    94,
      75,    90,    75,   152,    91,    92,   138,   151,    75,   152,
      75,    75,   157,   111,    75,    75,   162,    71,    61,   157,
      58,    58,   147,   160,   146,    74,   133,    20,    96,    75,
      75,   161,    60,   156,   120,    75,   155,    57,   106,   165,
     163,   164,    75,   146,   101,   161,   161,    92,    75,    58,
     162,    75,    97,   155,   133,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    90,    91,
      91,    92,    92,    92,    93,    94,    95,    95,    95,    95,
      95,    95,    96,    97,    98,    98,    99,   100,   101,   101,
     102,   103,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   111,
     112,   113,   114,   115,   116,   116,   116,   117,   117,   118,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   121,
     122,   122,   123,   124,   124,   124,   124,   125,   125,   126,
     126,   126,   126,   127,   128,   128,   129,   130,   130,   131,
     132,   132,   133,   133,   133,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   139,   140,   140,   141,   141,
     141,   141,   141,   141,   142,   142,   143,   144,   144,   144,
     144,   145,   145,   146,   146,   147,   147,   147,   147,   147,
     148,   148,   148,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   162,   163,   164,   164,   165,   165
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
       3,     3,     3,     3,     3,     3,     1,     2,     2,     2,
       2,     2,     2,     3,     5,     6,     1,     1,     3,     5,
       5,     4,     1,     5,     5,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       1,     2,     1,     1,     1,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     5,     1,     2,     5,     3,     3,     5,     8,     5,
       0,     3,     0,     1,     3,     1,     4,     2,     0,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       4,     3,     5,     5,     1,     3,     1,     1,     2,     2,
       1,     1,     3,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     3,     0,     2,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     3,     1,     4,     1,     4
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
#line 160 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FILE, "file", nkids, kids, NULL);
		ast_root = (yyval.ast);
	}
#line 1753 "go.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 170 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		(yyval.ast) = new_epsilon_tree(R_PACKAGE, "package");
		exit(2);
	}
#line 1763 "go.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 176 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(R_PACKAGE, "package", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "package", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_PACKAGE, "package", nkids, kids, NULL);
	}
#line 1775 "go.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 187 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_IMPORTS, "imports");
	}
#line 1783 "go.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 191 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "imports", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_IMPORTS, "imports", nkids, kids, NULL);
	}
#line 1794 "go.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 201 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "import", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
#line 1805 "go.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 208 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LIMPORT, "import", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "import", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "import", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
#line 1818 "go.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 217 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LIMPORT, "import", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "import", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "import", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		(yyval.ast) = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
#line 1831 "go.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 229 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IMPORT_STMT, "import_stmt", nkids, kids, NULL);
	}
#line 1841 "go.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 235 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1849 "go.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 242 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1857 "go.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 246 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "import_stmt_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IMPORT_STMT_LIST, "import_stmt_list", nkids, kids, NULL);
	}
#line 1868 "go.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 256 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "import_here", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
#line 1879 "go.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 263 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LLITERAL, "import_here", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), t2);
		(yyval.ast) = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
#line 1890 "go.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 270 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "import_here", (yyvsp[-1].t));
		struct tree* t2 = new_leaf_node(LLITERAL, "import_here", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2);
		(yyval.ast) = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
#line 1902 "go.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 281 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node(LPACKAGE, "import_package", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LNAME, "import_package", (yyvsp[-2].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "import_package", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_IMPORT_PACKAGE, "import_package", nkids, kids, NULL);
	}
#line 1915 "go.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 293 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_IMPORT_SAFETY, "import_safety");
	}
#line 1923 "go.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 297 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LNAME, "import_safety", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_IMPORT_SAFETY, "import_safety", nkids, kids, NULL);
	}
#line 1934 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 310 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		(yyval.ast) = new_epsilon_tree(R_XDCL, "xdcl");
	}
#line 1943 "go.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 315 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1951 "go.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 319 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1959 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 323 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1968 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 328 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1976 "go.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 335 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LVAR, "common_dcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 1987 "go.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 342 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LVAR, "common_dcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2000 "go.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 351 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LVAR, "common_dcl", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "common_dcl", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2013 "go.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 360 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2023 "go.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 366 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2035 "go.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 374 "go.y" /* yacc.c:1646  */
    {
		int nkids = 7;
		struct tree* t2 = new_leaf_node((yyvsp[-5].t)->category, "common_dcl", (yyvsp[-5].t));
		struct tree* t4 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t7 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), t2, (yyvsp[-4].ast), t4, (yyvsp[-2].ast), (yyvsp[-1].ast), t7);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2048 "go.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 383 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "common_dcl", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, t3);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2060 "go.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 391 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LTYPE, "common_dcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2071 "go.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 398 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LTYPE, "common_dcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2084 "go.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 407 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LTYPE, "common_dcl", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "common_dcl", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2097 "go.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LCONST, "lconst", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_LCONST, "lconst", nkids, kids, NULL);
	}
#line 2108 "go.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 429 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
#line 2118 "go.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 435 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "vardcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
#line 2129 "go.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 442 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "vardcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
#line 2140 "go.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 452 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "constdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL, "constdcl", nkids, kids, NULL);
	}
#line 2151 "go.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 459 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "constdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL, "constdcl", nkids, kids, NULL);
	}
#line 2162 "go.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 469 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2170 "go.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 473 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL1, "constdcl1", nkids, kids, NULL);
	}
#line 2180 "go.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 479 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2188 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 486 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2198 "go.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 495 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_TYPEDCL, "typedcl", nkids, kids, NULL);
	}
#line 2208 "go.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 504 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2216 "go.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 508 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LASOP, "simple_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2227 "go.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 515 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "simple_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2238 "go.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 522 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LCOLAS, "simple_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2249 "go.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 529 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LINC, "simple_stmt", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), t2);
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2260 "go.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 536 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LDEC, "simple_stmt", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), t2);
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2271 "go.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 547 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "compound_stmt", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "compound_stmt", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_COMPOUND_STMT, "compound_stmt", nkids, kids, NULL);
	}
#line 2283 "go.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 559 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "loop_body", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "loop_body", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_LOOP_BODY, "loop_body", nkids, kids, NULL);
	}
#line 2295 "go.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 570 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "for_header", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "for_header", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FOR_HEADER, "for_header", nkids, kids, NULL);
	}
#line 2307 "go.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 578 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2315 "go.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 585 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FOR_BODY, "for_body", nkids, kids, NULL);
	}
#line 2325 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 595 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LFOR, "for_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FOR_STMT, "for_stmt", nkids, kids, NULL);
	}
#line 2336 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 605 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2344 "go.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 609 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "if_header", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IF_HEADER, "if_header", nkids, kids, NULL);
	}
#line 2355 "go.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 623 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LIF, "if_stmt", (yyvsp[-4].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IF_STMT, "if_stmt", nkids, kids, NULL);
	}
#line 2366 "go.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 634 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node(LELSE, "elseif", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LIF, "elseif", (yyvsp[-2].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ELSEIF, "elseif", nkids, kids, NULL);
	}
#line 2378 "go.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 645 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_ELSEIF_LIST, "elseif_list");
	}
#line 2386 "go.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 649 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ELSEIF_LIST, "elseif_list", nkids, kids, NULL);
	}
#line 2396 "go.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 658 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_ELSE, "else");
	}
#line 2404 "go.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 662 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LELSE, "else", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ELSE, "else", nkids, kids, NULL);
	}
#line 2415 "go.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 675 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2423 "go.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 679 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LOROR, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2434 "go.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 686 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LANDAND, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2445 "go.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 693 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LEQ, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2456 "go.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 700 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LNE, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2467 "go.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 707 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LLT, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2478 "go.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 714 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LLE, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2489 "go.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 721 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LGE, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2500 "go.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 728 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LGT, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2511 "go.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 735 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2522 "go.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 742 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2533 "go.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 749 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2544 "go.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 756 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2555 "go.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 763 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2566 "go.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 770 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2577 "go.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 777 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2588 "go.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 784 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LANDNOT, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2599 "go.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 791 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LCOMM, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2610 "go.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 799 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LCOMM, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2621 "go.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 806 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LCOMM, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2632 "go.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 816 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2640 "go.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 820 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2651 "go.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 827 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2662 "go.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 834 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2673 "go.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 841 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2684 "go.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 848 "go.y" /* yacc.c:1646  */
    {
		yyerror("the bitwise complement operator is ^");
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2696 "go.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 856 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LCOMM, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2707 "go.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 870 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "pseudocall", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "pseudocall", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, t3);
		(yyval.ast) = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
#line 2719 "go.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 878 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pseudocall", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pseudocall", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
#line 2731 "go.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 886 "go.y" /* yacc.c:1646  */
    {
		int nkids = 6;
		struct tree* t2 = new_leaf_node((yyvsp[-4].t)->category, "pseudocall", (yyvsp[-4].t));
		struct tree* t4 = new_leaf_node(LDDD, "pseudocall", (yyvsp[-2].t));
		struct tree* t6 = new_leaf_node((yyvsp[0].t)->category, "pseudocall", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), t2, (yyvsp[-3].ast), t4, (yyvsp[-1].ast), t6);
		(yyval.ast) = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
#line 2744 "go.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 898 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2755 "go.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 905 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2763 "go.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 909 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "pexpr_no_paren", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2774 "go.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 916 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pexpr_no_paren", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-2].t)->category, "pexpr_no_paren", (yyvsp[-2].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, t3, (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2787 "go.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 925 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pexpr_no_paren", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-2].t)->category, "pexpr_no_paren", (yyvsp[-2].t));
		struct tree* t4 = new_leaf_node(LTYPE, "pexpr_no_paren", (yyvsp[-1].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, t3, t4, t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2801 "go.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 935 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t2 = new_leaf_node((yyvsp[-2].t)->category, "pexpr_no_paren", (yyvsp[-2].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), t2, (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2813 "go.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 943 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2821 "go.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 947 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pexpr_no_paren", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2833 "go.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 955 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2844 "go.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 962 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2852 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 971 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2860 "go.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 975 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "pexpr", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "pexpr", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_PEXPR, "pexpr", nkids, kids, NULL);
	}
#line 2872 "go.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 986 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2880 "go.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 990 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2888 "go.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 997 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);

	}
#line 2897 "go.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1005 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "lbrace", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_LBRACE, "lbrace", nkids, kids, NULL);
	}
#line 2908 "go.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1020 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2916 "go.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1027 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2924 "go.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1034 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LNAME, "sym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_SYM, "sym", nkids, kids, NULL);
	}
#line 2935 "go.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1041 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2943 "go.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1045 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "sym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_SYM, "sym", nkids, kids, NULL);
	}
#line 2954 "go.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1055 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "hidden_importsym", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LLITERAL, "hidden_importsym", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "hidden_importsym", (yyvsp[-1].t));
		struct tree* t4 = new_leaf_node(LNAME, "hidden_importsym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, t4);
		(yyval.ast) = new_tree_node(R_HIDDEN_IMPORTSYM, "hidden_importsym", nkids, kids, NULL);
	}
#line 2968 "go.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1065 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "hidden_importsym", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LLITERAL, "hidden_importsym", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "hidden_importsym", (yyvsp[-1].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "hidden_importsym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, t4);
		(yyval.ast) = new_tree_node(R_HIDDEN_IMPORTSYM, "hidden_importsym", nkids, kids, NULL);
	}
#line 2982 "go.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1078 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2990 "go.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1095 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");

		int nkids = 1;
		struct tree* t1 = new_leaf_node(LDDD, "dotdotdot", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_DOTDOTDOT, "dotdotdot", nkids, kids, NULL);
	}
#line 3003 "go.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1104 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LDDD, "dotdotdot", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_DOTDOTDOT, "dotdotdot", nkids, kids, NULL);
	}
#line 3014 "go.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1114 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3022 "go.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1118 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3030 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1122 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3038 "go.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1126 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3046 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1130 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "ntype", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "ntype", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_NTYPE, "ntype", nkids, kids, NULL);
	}
#line 3058 "go.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1141 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3066 "go.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1145 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3074 "go.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1149 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "non_expr_type", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_NON_EXPR_TYPE, "non_expr_type", nkids, kids, NULL);
	}
#line 3085 "go.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1159 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3093 "go.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1163 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3101 "go.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1170 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3109 "go.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1177 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3117 "go.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1181 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3125 "go.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1185 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3133 "go.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1189 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3141 "go.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1196 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3149 "go.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1200 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "dotname", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_DOTNAME, "dotname", nkids, kids, NULL);
	}
#line 3160 "go.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1210 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "othertype", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "othertype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}
#line 3172 "go.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1218 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "othertype", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LDDD, "othertype", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "othertype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}
#line 3185 "go.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1227 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LMAP, "othertype", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node(LDDD, "othertype", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "othertype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}
#line 3198 "go.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1236 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3206 "go.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1243 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "ptrtype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_PTRTYPE, "ptrtype", nkids, kids, NULL);
	}
#line 3217 "go.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1253 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LSTRUCT, "structtype", (yyvsp[-4].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "structtype", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_STRUCTTYPE, "structtype", nkids, kids, NULL);
	}
#line 3229 "go.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1261 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LSTRUCT, "structtype", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "structtype", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_STRUCTTYPE, "structtype", nkids, kids, NULL);
	}
#line 3241 "go.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1276 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LFUNC, "xfndcl", (yyvsp[-2].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_XFNDCL, "xfndcl", nkids, kids, NULL);
	}
#line 3252 "go.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1286 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "fndcl", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "fndcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNDCL, "fndcl", nkids, kids, NULL);
	}
#line 3264 "go.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1294 "go.y" /* yacc.c:1646  */
    {
		int nkids = 8;
		struct tree* t1 = new_leaf_node((yyvsp[-7].t)->category, "fndcl", (yyvsp[-7].t));
		struct tree* t3 = new_leaf_node((yyvsp[-5].t)->category, "fndcl", (yyvsp[-5].t));
		struct tree* t5 = new_leaf_node((yyvsp[-3].t)->category, "fndcl", (yyvsp[-3].t));
		struct tree* t7 = new_leaf_node((yyvsp[-1].t)->category, "fndcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-6].ast), t3, (yyvsp[-4].ast), t5, (yyvsp[-2].ast), t7, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNDCL, "fndcl", nkids, kids, NULL);
	}
#line 3278 "go.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1308 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LFUNC, "fntype", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "fntype", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "fntype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNTYPE, "fntype", nkids, kids, NULL);
	}
#line 3291 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1320 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_FNBODY, "fnbody");
	}
#line 3299 "go.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1324 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "fnbody", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "fnbody", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_FNBODY, "fnbody", nkids, kids, NULL);
	}
#line 3311 "go.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1335 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_FNRES, "fnres");
	}
#line 3319 "go.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1339 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3327 "go.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1343 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "fnres", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "fnres", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_FNRES, "fnres", nkids, kids, NULL);
	}
#line 3339 "go.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1354 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3347 "go.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1361 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "fnliteral", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_FNLITERAL, "fnliteral", nkids, kids, NULL);
	}
#line 3358 "go.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1368 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNLITERAL, "fnliteral", nkids, kids, NULL);
	}
#line 3368 "go.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1382 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_XDCL_LIST, "xdcl_list");
	}
#line 3376 "go.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1386 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "xdcl_list", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_XDCL_LIST, "xdcl_list", nkids, kids, NULL);
	}
#line 3387 "go.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1396 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3395 "go.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1400 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "vardcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL_LIST, "vardcl_list", nkids, kids, NULL);
	}
#line 3406 "go.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1410 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3414 "go.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1414 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "constdcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL_LIST, "constdcl_list", nkids, kids, NULL);
	}
#line 3425 "go.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1424 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3433 "go.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1428 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "typedcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_TYPEDCL_LIST, "typedcl_list", nkids, kids, NULL);
	}
#line 3444 "go.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1438 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3452 "go.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1442 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "structdcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL_LIST, "structdcl_list", nkids, kids, NULL);
	}
#line 3463 "go.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1452 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3473 "go.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1458 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3483 "go.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1464 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "structdcl", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "structdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3495 "go.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1472 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "structdcl", (yyvsp[-2].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3506 "go.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1479 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node((yyvsp[-4].t)->category, "structdcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "structdcl", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "structdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3519 "go.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1488 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node((yyvsp[-4].t)->category, "structdcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "structdcl", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "structdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3532 "go.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1500 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LNAME, "packname", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_PACKNAME, "packname", nkids, kids, NULL);
	}
#line 3543 "go.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1507 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LNAME, "packname", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "packname", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_PACKNAME, "packname", nkids, kids, NULL);
	}
#line 3555 "go.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1518 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3563 "go.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1528 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3571 "go.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1532 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ARG_TYPE, "arg_type", nkids, kids, NULL);
	}
#line 3581 "go.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1538 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ARG_TYPE, "arg_type", nkids, kids, NULL);
	}
#line 3591 "go.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1544 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3599 "go.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1551 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3607 "go.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1555 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "arg_type_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ARG_TYPE_LIST, "arg_type_list", nkids, kids, NULL);
	}
#line 3618 "go.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1565 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OARG_TYPE_LIST_OCOMMA, "oarg_type_list_ocomma");
	}
#line 3626 "go.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1569 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OARG_TYPE_LIST_OCOMMA, "oarg_type_list_ocomma", nkids, kids, NULL);
	}
#line 3636 "go.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1581 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_STMT, "stmt");
	}
#line 3644 "go.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1585 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3652 "go.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1589 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3660 "go.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1593 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3668 "go.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1597 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3676 "go.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1604 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3684 "go.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1608 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3692 "go.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1612 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3700 "go.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1616 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LRETURN, "non_dcl_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_NON_DCL_STMT, "non_dcl_stmt", nkids, kids, NULL);
	}
#line 3711 "go.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1626 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3719 "go.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1630 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "stmt_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STMT_LIST, "stmt_list", nkids, kids, NULL);
	}
#line 3730 "go.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1640 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3738 "go.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1644 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "new_name_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_NEW_NAME_LIST, "new_name_list", nkids, kids, NULL);
	}
#line 3749 "go.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1654 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3757 "go.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1658 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "dcl_name_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_DCL_NAME_LIST, "dcl_name_list", nkids, kids, NULL);
	}
#line 3768 "go.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1668 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3776 "go.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1672 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR_LIST, "expr_list", nkids, kids, NULL);
	}
#line 3787 "go.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1682 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3795 "go.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1686 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr_or_type_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR_OR_TYPE_LIST, "expr_or_type_list", nkids, kids, NULL);
	}
#line 3806 "go.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1699 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3814 "go.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1703 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3822 "go.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1707 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "keyval_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_KEYVAL_LIST, "keyval_list", nkids, kids, NULL);
	}
#line 3833 "go.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1714 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "keyval_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_KEYVAL_LIST, "keyval_list", nkids, kids, NULL);
	}
#line 3844 "go.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1724 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_BRACED_KEYVAL_LIST, "braced_keyval_list");
	}
#line 3852 "go.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1728 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_BRACED_KEYVAL_LIST, "braced_keyval_list", nkids, kids, NULL);
	}
#line 3862 "go.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1741 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OSEMI, "osemi");
	}
#line 3870 "go.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1745 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "osemi", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_OSEMI, "osemi", nkids, kids, NULL);
	}
#line 3881 "go.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1755 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OCOMMA, "ocomma");
	}
#line 3889 "go.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1759 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "ocomma", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_OCOMMA, "ocomma", nkids, kids, NULL);
	}
#line 3900 "go.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1769 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OEXPR, "oexpr");
	}
#line 3908 "go.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1773 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3916 "go.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1780 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OEXPR_LIST, "oexpr_list");
	}
#line 3924 "go.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1784 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3932 "go.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1791 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OSIMPLE_STMT, "osimple_stmt");		
	}
#line 3940 "go.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1795 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3948 "go.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1803 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OLITERAL, "oliteral");		
	}
#line 3956 "go.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1807 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "oliteral", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_OLITERAL, "oliteral", nkids, kids, NULL);
	}
#line 3967 "go.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1817 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_START_COMPLIT, "start_complit");		
	}
#line 3975 "go.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1825 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "keyval", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_KEYVAL, "keyval", nkids, kids, NULL);
	}
#line 3986 "go.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1835 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3994 "go.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1839 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "bare_complitexpr", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "bare_complitexpr", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-2].ast), (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_BARE_COMPLITEXPR, "bare_complitexpr", nkids, kids, NULL);
	}
#line 4006 "go.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1850 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 4014 "go.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1854 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "bare_complitexpr", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "bare_complitexpr", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-2].ast), (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_COMPLITEXPR, "complitexpr", nkids, kids, NULL);
	}
#line 4026 "go.tab.c" /* yacc.c:1646  */
    break;


#line 4030 "go.tab.c" /* yacc.c:1646  */
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
#line 1878 "go.y" /* yacc.c:1906  */

