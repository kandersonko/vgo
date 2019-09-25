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
	fprintf(stderr, "ERROR: found '%s' token at line %d in file %s\n",
	   yytext,yylineno,yyfilename);
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

#line 212 "go.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "go.tab.c" /* yacc.c:358  */

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
#define YYLAST   961

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

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
      72,    73,    53,    49,    61,    50,    63,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
       2,    64,     2,    59,    69,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    70,    71,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   173,   179,   190,   194,   204,   211,   220,
     232,   238,   245,   249,   259,   266,   273,   284,   297,   301,
     314,   319,   323,   327,   332,   339,   346,   355,   364,   370,
     378,   387,   395,   402,   411,   423,   433,   439,   446,   456,
     463,   473,   477,   483,   490,   499,   508,   512,   519,   526,
     533,   540,   550,   562,   574,   582,   589,   598,   609,   613,
     624,   637,   649,   653,   662,   666,   679,   683,   690,   697,
     704,   711,   718,   725,   732,   739,   746,   753,   760,   767,
     774,   781,   788,   798,   802,   809,   816,   823,   830,   837,
     851,   859,   867,   879,   886,   890,   897,   906,   916,   924,
     928,   936,   945,   949,   960,   964,   973,   981,   988,  1003,
    1010,  1017,  1024,  1028,  1038,  1048,  1061,  1078,  1087,  1097,
    1101,  1105,  1109,  1113,  1124,  1128,  1132,  1142,  1146,  1154,
    1158,  1162,  1166,  1173,  1177,  1187,  1195,  1204,  1213,  1220,
    1230,  1238,  1253,  1263,  1271,  1285,  1297,  1301,  1312,  1316,
    1320,  1331,  1338,  1345,  1359,  1363,  1373,  1377,  1387,  1391,
    1401,  1405,  1415,  1419,  1429,  1435,  1441,  1449,  1456,  1465,
    1477,  1484,  1495,  1505,  1509,  1515,  1521,  1528,  1532,  1542,
    1546,  1558,  1562,  1566,  1570,  1574,  1581,  1586,  1591,  1595,
    1605,  1609,  1619,  1623,  1633,  1637,  1647,  1651,  1661,  1665,
    1683,  1687,  1697,  1701,  1711,  1715,  1722,  1726,  1733,  1737,
    1745,  1749
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LLITERAL", "LASOP", "LCOLAS", "LBREAK",
  "LCASE", "LCHAN", "LCONST", "LCONTINUE", "LDDD", "LDEFAULT", "LDEFER",
  "LELSE", "LFALL", "LFOR", "LFUNC", "LGO", "LGOTO", "LIF", "LIMPORT",
  "LINTERFACE", "LMAP", "LNAME", "LPACKAGE", "LRANGE", "LRETURN",
  "LSELECT", "LSTRUCT", "LSWITCH", "LTYPE", "LVAR", "LANDAND", "LANDNOT",
  "LBODY", "LCOMM", "LDEC", "LEQ", "LGE", "LGT", "LIGNORE", "LINC", "LLE",
  "LLSH", "LLT", "LNE", "LOROR", "LRSH", "'+'", "'-'", "'|'", "'^'", "'*'",
  "'/'", "'%'", "'&'", "'{'", "'}'", "'?'", "';'", "','", "'`'", "'.'",
  "'='", "'!'", "'~'", "'['", "']'", "'@'", "NotPackage", "NotParen",
  "'('", "')'", "PreferToRightParen", "$accept", "file", "package",
  "imports", "import", "import_stmt", "import_stmt_list", "import_here",
  "import_package", "import_safety", "xdcl", "common_dcl", "lconst",
  "vardcl", "constdcl", "constdcl1", "typedclname", "typedcl",
  "simple_stmt", "compound_stmt", "loop_body", "for_header", "for_body",
  "for_stmt", "if_header", "if_stmt", "elseif", "elseif_list", "else",
  "expr", "uexpr", "pseudocall", "pexpr_no_paren", "pexpr", "expr_or_type",
  "name_or_type", "lbrace", "new_name", "dcl_name", "sym",
  "hidden_importsym", "name", "dotdotdot", "ntype", "non_expr_type",
  "convtype", "fnret_type", "dotname", "othertype", "ptrtype",
  "structtype", "xfndcl", "fndcl", "fntype", "fnbody", "fnres", "fnlitdcl",
  "fnliteral", "xdcl_list", "vardcl_list", "constdcl_list", "typedcl_list",
  "structdcl_list", "structdcl", "packname", "embed", "arg_type",
  "arg_type_list", "oarg_type_list_ocomma", "stmt", "non_dcl_stmt",
  "stmt_list", "new_name_list", "dcl_name_list", "expr_list",
  "expr_or_type_list", "osemi", "ocomma", "oexpr", "oexpr_list",
  "osimple_stmt", "oliteral", YY_NULLPTR
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
     304,   305,    40,    41,   306
};
# endif

#define YYPACT_NINF -282

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-282)))

#define YYTABLE_NINF -197

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    51,    20,  -282,  -282,  -282,    40,   -22,  -282,  -282,
      25,    45,  -282,   106,    -2,   427,     0,  -282,    60,    88,
    -282,    63,   111,  -282,  -282,  -282,  -282,   591,   161,   591,
      55,   591,    47,   243,   260,   591,   591,   591,   591,   591,
     591,   563,   656,    69,  -282,   282,  -282,  -282,  -282,   693,
    -282,  -282,  -282,     4,  -282,  -282,    72,  -282,  -282,  -282,
      73,    35,  -282,  -282,    79,  -282,  -282,  -282,  -282,  -282,
     120,   140,  -282,  -282,    94,  -282,   163,  -282,   121,   487,
      99,   147,   163,   149,   619,   842,   174,  -282,  -282,  -282,
     202,   130,   619,  -282,  -282,   138,  -282,  -282,  -282,   732,
    -282,  -282,  -282,  -282,  -282,  -282,   172,   842,   177,   656,
     842,   183,  -282,   182,    29,  -282,   146,  -282,   736,   591,
     591,   591,   591,  -282,   591,   591,   591,  -282,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   290,   591,
     314,   591,  -282,   512,   591,   591,   591,   104,   189,   239,
     487,   512,  -282,   591,   619,   619,   619,  -282,   487,   203,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,   208,   204,   487,
     512,  -282,  -282,   591,   214,   150,    33,  -282,    53,  -282,
    -282,   216,  -282,  -282,   283,   753,  -282,  -282,   227,  -282,
    -282,  -282,   228,    51,   591,   234,   619,   619,  -282,  -282,
    -282,   231,   591,   235,   842,   906,  -282,   865,   193,   193,
     193,   193,   193,   193,   888,   321,   321,   321,  -282,  -282,
    -282,   602,  -282,   794,  -282,  -282,     8,   818,  -282,   512,
    -282,  -282,  -282,  -282,   135,   174,   842,   174,  -282,  -282,
    -282,   232,   230,   136,   240,  -282,  -282,   245,  -282,  -282,
      51,   487,  -282,   757,   250,   176,   291,  -282,   619,    51,
     241,   292,   283,   292,   252,   153,   268,  -282,  -282,    51,
     283,    51,   266,    51,   267,  -282,   174,   591,  -282,  -282,
      51,   271,   174,   591,   273,   274,  -282,   272,   656,   275,
    -282,   284,   181,  -282,   512,  -282,   757,  -282,   591,  -282,
    -282,  -282,   487,   281,  -282,  -282,  -282,  -282,  -282,  -282,
     757,  -282,    36,  -282,  -282,  -282,  -282,   285,  -282,   287,
     283,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   174,
    -282,  -282,   296,   736,  -282,   174,  -282,  -282,   288,  -282,
    -282,  -282,  -282,  -282,  -282,   293,   487,  -282,   591,  -282,
     283,   283,  -282,    51,   295,   235,  -282,  -282,   297,   163,
    -282,  -282,  -282,  -282,   757,  -282,  -282
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     5,   111,   113,     0,     0,   112,     1,
     154,     0,     4,     0,     0,     0,     0,    14,     0,     0,
       7,    11,     0,     6,    24,    93,    35,   208,     0,   208,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,    21,     0,   186,   187,   188,    46,
      66,    99,   102,    83,   116,    94,     0,   128,   138,    22,
     151,     0,   101,    23,     0,   114,   115,    16,     9,    12,
     200,     0,    10,    15,     0,   209,     0,    57,    55,   179,
       0,   146,     0,    58,     0,   196,   207,   189,   107,   108,
       0,     0,     0,    32,    44,     0,    25,   194,   110,     0,
      89,    85,    86,    84,    87,    88,     0,   205,     0,     0,
     104,     0,   105,   125,   124,   155,     0,    28,     0,     0,
       0,     0,     0,    51,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,     0,     0,   201,     0,    18,
     179,     0,    56,   208,   117,     0,     0,   173,   116,   133,
     176,   106,   122,   120,   121,   119,   177,   202,     0,   179,
       0,   142,    62,   208,     0,   111,     0,   141,     0,   192,
     109,   200,   162,   172,   210,     0,    34,   160,   200,    45,
      27,   156,   200,     0,     0,    36,     0,     0,   126,   103,
      31,   200,     0,     0,    47,    68,    81,    82,    69,    73,
      74,    72,    71,    70,    67,    75,    76,    77,    78,    79,
      80,     0,    95,     0,    90,   198,   202,   202,   185,     0,
     183,   182,   190,   184,     0,    49,   197,    48,    13,     8,
      19,     0,     0,     0,     0,   118,   139,     0,   174,   175,
       0,   203,   180,   148,     0,     0,    64,    59,     0,     0,
     170,     0,   210,     0,     0,   201,     0,   211,   165,     0,
     210,   201,     0,   201,     0,   195,    38,     0,   136,   135,
     201,     0,    40,     0,     0,     0,    98,   202,   203,     0,
     203,     0,     0,   152,     0,    17,   148,    53,   208,   123,
     134,   178,   179,   116,   149,   132,   130,   131,   129,   145,
     148,   147,     0,    63,    60,   137,   171,     0,   167,     0,
     210,   163,   140,   193,   164,   161,    33,   157,    26,    37,
      41,   158,   200,    43,    29,    39,    97,    96,     0,   199,
      91,   100,    52,   191,    54,     0,   179,   143,   208,    65,
     210,   210,   166,   201,     0,    42,    92,   150,     0,     0,
     169,   168,   159,    30,   148,    61,   144
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -282,  -282,  -282,  -282,  -282,    -5,  -282,  -282,  -282,  -282,
    -282,   354,  -282,   -82,   -29,    18,  -282,   -88,   -18,    65,
     -81,  -282,  -282,  -282,    24,  -282,  -282,  -282,  -282,   280,
      14,  -282,  -282,  -282,  -136,   224,   323,   116,   195,    -1,
    -282,   139,   233,   -58,   286,  -282,  -282,  -231,   -37,  -230,
    -282,  -282,  -282,    32,  -282,  -281,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,   124,  -282,  -161,   142,  -282,  -144,   100,
     383,  -130,  -282,   -43,    30,  -282,  -153,  -219,  -282,  -282,
     -17,  -225
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    70,    21,    72,   241,
      43,   230,    45,    96,   330,   331,    92,    93,    46,   231,
     152,    76,    77,    47,    82,    48,   313,   256,   314,    49,
      50,    51,    52,    53,   111,   157,    90,   179,    97,    54,
       8,    55,   160,   161,   112,    56,   304,   162,    57,   164,
      58,    59,    81,    60,   171,   309,    61,    62,    15,   192,
     332,   188,   181,   182,   183,   184,   166,   167,   168,   232,
     233,   234,   185,    99,    64,   226,   148,   252,   108,    87,
      83,   268
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,   172,   118,   187,   225,   113,   242,   289,   291,    75,
      78,    75,    22,   191,    69,   262,   117,   264,    22,   287,
       9,   243,   305,   307,    65,   254,   174,    80,   266,   347,
    -151,     1,    94,    98,   189,   272,   142,   318,    12,   274,
     255,   195,   163,    11,    98,   324,    13,   163,   281,   100,
     101,   102,   103,   104,   105,   163,   348,   260,    23,    66,
     203,    86,   163,    67,  -151,   305,   307,   138,   338,   288,
      88,   139,   113,   118,   114,     4,   140,   260,   158,   305,
     307,   163,    88,   366,   144,   285,  -151,   201,    71,   180,
      94,    17,    89,   229,    98,   352,   245,   246,   247,   292,
     317,  -127,   319,   113,    89,   261,   263,    17,    16,    17,
       5,   165,     4,   163,    73,    98,   165,   163,   163,   163,
       6,   163,    84,   103,   165,   360,   361,   270,     4,   115,
       4,   165,   163,   305,   307,    75,   244,   222,   278,   279,
     145,   114,   238,   146,   141,  -127,    22,     5,   163,   158,
     165,    18,   339,  -170,     4,    75,   257,     6,   345,   163,
     163,    68,     4,     5,   149,     5,   150,    18,   158,    18,
       4,   169,   114,     6,   235,     6,   237,   175,    19,   354,
     147,   153,   165,   325,   113,     4,   165,   165,   165,     5,
     165,   327,    98,   293,   297,   294,   294,     5,   151,     6,
     315,   165,   358,   186,   170,     5,   176,     6,  -170,   173,
    -170,   190,     5,   259,   163,     6,   306,   165,   159,   200,
       5,   163,     6,   159,   276,   178,   175,   121,   165,   165,
       6,   159,   282,    79,   311,   145,   294,   333,   159,   342,
     196,   294,   132,   133,   134,   197,   135,   136,   137,   300,
     158,   113,   303,   114,  -128,   176,   199,   159,   316,   306,
     177,     5,   239,   240,   180,   163,   250,     4,   180,   251,
      94,     6,    98,   306,   178,   355,   265,   253,   365,    98,
      75,   344,   258,   165,     4,   308,   267,   271,   273,   159,
     165,   280,   295,   159,   159,   159,   163,   159,   277,   283,
     298,   158,     5,   296,   259,   312,     4,   329,   159,   163,
     333,    85,     6,   335,     4,    91,   260,    25,   299,     5,
     114,   107,   110,   310,   159,   320,   322,   306,   308,     6,
      75,    74,    95,   290,   165,   159,   159,    30,     4,   326,
     328,     5,   308,    32,   334,   158,   336,   337,   340,     5,
      35,     6,    98,   346,   116,   121,   353,   341,   350,     6,
     351,   356,   221,    36,    37,   165,   357,   109,   363,    44,
     364,   362,   359,     5,   135,   136,   137,   349,   165,    39,
      40,    41,   248,     6,   143,   323,    42,   224,   275,   321,
     159,   249,   159,   301,   343,   198,   308,   159,    63,   204,
     205,   206,   207,     0,   208,   209,   210,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     0,   223,
     110,   227,     0,     0,    85,   236,    85,    -2,    24,     0,
      25,     0,     0,     0,     0,   159,    26,     0,     0,     0,
       0,   159,     0,    27,    28,     0,     0,    29,     0,   159,
      30,     4,     0,     0,    31,     0,    32,     0,    33,    34,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,    85,     0,    36,    37,     0,     0,
      38,     0,    85,     0,     0,   159,     5,   -20,     0,     0,
       0,     0,    39,    40,    41,     0,     6,     0,   154,    42,
       0,   110,     0,   159,    74,     0,     0,     0,     0,     0,
      30,     4,     0,   228,     0,    25,    32,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    27,    74,
       0,     0,    29,     0,     0,    30,     4,     0,     0,    31,
     155,    32,     0,    33,    34,     0,     5,     0,    35,     0,
       0,     0,     0,     0,    41,     0,     6,    85,     0,   156,
       0,    36,    37,    85,     0,    38,    25,     0,   110,   229,
    -181,     5,  -181,     0,   106,     0,     0,    39,    40,    41,
      74,     6,     0,     0,    42,     0,    30,     4,     0,     0,
       0,     0,    32,     0,    25,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,    25,     0,     0,    74,     0,
       0,     0,    36,    37,    30,     4,    38,     0,     0,    74,
      32,     0,     5,     0,     0,    30,     4,    35,    39,    40,
      41,    32,     6,   284,     0,    42,    74,     0,    35,     0,
      36,    37,    30,     4,    38,     0,     0,     0,    32,     0,
       5,    36,    37,     0,     0,   109,    39,    40,    41,    25,
       6,     5,     0,    42,     0,     0,     0,    39,    40,    41,
       0,     6,   155,    74,    42,     0,     0,     0,     5,    30,
       4,     0,     0,     0,     0,    32,    41,     0,     6,     0,
       0,   156,    35,     0,     0,     0,     0,   119,  -196,     0,
       0,     0,     0,     0,     0,    36,    37,     0,     0,   109,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,    39,    40,    41,     0,     6,   120,   121,    42,   122,
     123,   124,   125,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,   133,   134,     0,   135,   136,   137,    74,
       0,     0,     0,    74,  -196,    30,     4,  -196,     0,    30,
       4,    32,     0,     0,     0,    32,     0,     0,     0,     0,
      74,     0,     0,     0,    74,     0,    30,     4,     0,     0,
      30,     4,    32,     0,     0,   155,    32,     0,     0,   155,
       0,     5,     0,   193,     0,     5,   194,   193,     0,    41,
     202,     6,     0,    41,   156,     6,   155,     0,   156,     0,
     155,     0,     5,     0,   269,     0,     5,     0,     0,     0,
      41,     0,     6,     0,    41,   156,     6,   120,   121,   302,
     122,     0,   124,   125,   126,     0,     0,   128,     0,   129,
     130,   131,     0,   132,   133,   134,     0,   135,   136,   137,
       0,   120,   121,     0,   122,     0,   124,   125,   126,     0,
       0,   128,   286,   129,   130,   131,     0,   132,   133,   134,
       0,   135,   136,   137,     0,   120,   121,     0,   122,   290,
     124,   125,   126,     0,     0,   128,     0,   129,   130,   131,
       0,   132,   133,   134,     0,   135,   136,   137,   120,   121,
       0,     0,     0,   124,   125,   126,     0,     0,   128,     0,
     129,   130,   131,     0,   132,   133,   134,     0,   135,   136,
     137,   120,   121,     0,     0,     0,   124,   125,   126,     0,
       0,   128,     0,   129,   130,     0,     0,   132,   133,   134,
     121,   135,   136,   137,   124,   125,   126,     0,     0,   128,
       0,   129,   130,     0,     0,   132,   133,   134,     0,   135,
     136,   137
};

static const yytype_int16 yycheck[] =
{
       1,    82,    45,    91,   140,    42,   150,   226,   227,    27,
      27,    29,    13,    95,    19,   176,    45,   178,    19,    11,
       0,   151,   253,   253,    24,   169,    84,    28,   181,   310,
       1,    25,    33,    34,    92,   188,     1,   262,    60,   192,
     170,    99,    79,     3,    45,   270,    21,    84,   201,    35,
      36,    37,    38,    39,    40,    92,    20,    24,    60,    59,
     118,    31,    99,     3,    35,   296,   296,    63,   287,    61,
      35,    67,   109,   116,    42,    24,    72,    24,    79,   310,
     310,   118,    35,   364,     5,   221,    57,   116,    25,    90,
      91,     3,    57,    57,    95,   320,   154,   155,   156,   229,
     261,    72,   263,   140,    57,    72,    53,     3,    63,     3,
      59,    79,    24,   150,     3,   116,    84,   154,   155,   156,
      69,   158,    67,   109,    92,   350,   351,   185,    24,    60,
      24,    99,   169,   364,   364,   153,   153,   138,   196,   197,
      61,   109,   147,    64,    72,    72,   147,    59,   185,   150,
     118,    63,   288,     3,    24,   173,   173,    69,   302,   196,
     197,    73,    24,    59,    24,    59,    72,    63,   169,    63,
      24,    72,   140,    69,   144,    69,   146,    24,    72,   332,
      60,    60,   150,   271,   221,    24,   154,   155,   156,    59,
     158,   273,   193,    58,    58,    60,    60,    59,    35,    69,
     258,   169,   346,    73,    57,    59,    53,    69,    58,    60,
      60,    73,    59,    63,   251,    69,   253,   185,    79,    73,
      59,   258,    69,    84,   194,    72,    24,    34,   196,   197,
      69,    92,   202,    72,    58,    61,    60,   280,    99,    58,
      68,    60,    49,    50,    51,    68,    53,    54,    55,   250,
     251,   288,   253,   221,    72,    53,    73,   118,   259,   296,
      58,    59,    73,    24,   265,   302,    63,    24,   269,    61,
     271,    69,   273,   310,    72,   333,    60,    73,   359,   280,
     298,   298,    68,   251,    24,   253,     3,    60,    60,   150,
     258,    60,    60,   154,   155,   156,   333,   158,    64,    64,
      60,   302,    59,    73,    63,    14,    24,   277,   169,   346,
     353,    31,    69,   283,    24,    72,    24,     3,    73,    59,
     288,    41,    42,    73,   185,    73,    58,   364,   296,    69,
     348,    17,    72,    61,   302,   196,   197,    23,    24,    73,
      73,    59,   310,    29,    73,   346,    73,    73,    73,    59,
      36,    69,   353,    72,    72,    34,    60,    73,    73,    69,
      73,    73,    72,    49,    50,   333,    73,    53,    73,    15,
      73,   353,   348,    59,    53,    54,    55,   312,   346,    65,
      66,    67,   158,    69,    61,   269,    72,    73,   193,   265,
     251,   158,   253,   251,   294,   109,   364,   258,    15,   119,
     120,   121,   122,    -1,   124,   125,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    -1,   139,
     140,   141,    -1,    -1,   144,   145,   146,     0,     1,    -1,
       3,    -1,    -1,    -1,    -1,   296,     9,    -1,    -1,    -1,
      -1,   302,    -1,    16,    17,    -1,    -1,    20,    -1,   310,
      23,    24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   333,    -1,   194,    -1,    49,    50,    -1,    -1,
      53,    -1,   202,    -1,    -1,   346,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    69,    -1,    11,    72,
      -1,   221,    -1,   364,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,     1,    -1,     3,    29,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    -1,    -1,    23,    24,    -1,    -1,    27,
      53,    29,    -1,    31,    32,    -1,    59,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,   277,    -1,    72,
      -1,    49,    50,   283,    -1,    53,     3,    -1,   288,    57,
      58,    59,    60,    -1,    11,    -1,    -1,    65,    66,    67,
      17,    69,    -1,    -1,    72,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    -1,     3,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    17,    -1,
      -1,    -1,    49,    50,    23,    24,    53,    -1,    -1,    17,
      29,    -1,    59,    -1,    -1,    23,    24,    36,    65,    66,
      67,    29,    69,    31,    -1,    72,    17,    -1,    36,    -1,
      49,    50,    23,    24,    53,    -1,    -1,    -1,    29,    -1,
      59,    49,    50,    -1,    -1,    53,    65,    66,    67,     3,
      69,    59,    -1,    72,    -1,    -1,    -1,    65,    66,    67,
      -1,    69,    53,    17,    72,    -1,    -1,    -1,    59,    23,
      24,    -1,    -1,    -1,    -1,    29,    67,    -1,    69,    -1,
      -1,    72,    36,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    69,    33,    34,    72,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    45,    46,
      47,    -1,    49,    50,    51,    -1,    53,    54,    55,    17,
      -1,    -1,    -1,    17,    61,    23,    24,    64,    -1,    23,
      24,    29,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    17,    -1,    23,    24,    -1,    -1,
      23,    24,    29,    -1,    -1,    53,    29,    -1,    -1,    53,
      -1,    59,    -1,    61,    -1,    59,    64,    61,    -1,    67,
      64,    69,    -1,    67,    72,    69,    53,    -1,    72,    -1,
      53,    -1,    59,    -1,    61,    -1,    59,    -1,    -1,    -1,
      67,    -1,    69,    -1,    67,    72,    69,    33,    34,    72,
      36,    -1,    38,    39,    40,    -1,    -1,    43,    -1,    45,
      46,    47,    -1,    49,    50,    51,    -1,    53,    54,    55,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    -1,
      -1,    43,    68,    45,    46,    47,    -1,    49,    50,    51,
      -1,    53,    54,    55,    -1,    33,    34,    -1,    36,    61,
      38,    39,    40,    -1,    -1,    43,    -1,    45,    46,    47,
      -1,    49,    50,    51,    -1,    53,    54,    55,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    -1,
      45,    46,    47,    -1,    49,    50,    51,    -1,    53,    54,
      55,    33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    43,    -1,    45,    46,    -1,    -1,    49,    50,    51,
      34,    53,    54,    55,    38,    39,    40,    -1,    -1,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    51,    -1,    53,
      54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    76,    77,    24,    59,    69,   114,   115,     0,
      78,     3,    60,    21,    79,   133,    63,     3,    63,    72,
      80,    82,   114,    60,     1,     3,     9,    16,    17,    20,
      23,    27,    29,    31,    32,    36,    49,    50,    53,    65,
      66,    67,    72,    85,    86,    87,    93,    98,   100,   104,
     105,   106,   107,   108,   114,   116,   120,   123,   125,   126,
     128,   131,   132,   145,   149,    24,    59,     3,    73,    80,
      81,    25,    83,     3,    17,    93,    96,    97,   155,    72,
     114,   127,    99,   155,    67,   104,   149,   154,    35,    57,
     111,    72,    91,    92,   114,    72,    88,   113,   114,   148,
     105,   105,   105,   105,   105,   105,    11,   104,   153,    53,
     104,   109,   119,   123,   128,    60,    72,    89,   148,     4,
      33,    34,    36,    37,    38,    39,    40,    42,    43,    45,
      46,    47,    49,    50,    51,    53,    54,    55,    63,    67,
      72,    72,     1,   111,     5,    61,    64,    60,   151,    24,
      72,    35,    95,    60,    11,    53,    72,   110,   114,   116,
     117,   118,   122,   123,   124,   128,   141,   142,   143,    72,
      57,   129,    95,    60,   118,    24,    53,    58,    72,   112,
     114,   137,   138,   139,   140,   147,    73,    92,   136,   118,
      73,    88,   134,    61,    64,   118,    68,    68,   119,    73,
      73,    89,    64,   118,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,    72,   114,   104,    73,   109,   150,   104,     1,    57,
      86,    94,   144,   145,   146,   149,   104,   149,    80,    73,
      24,    84,   143,   146,   155,   118,   118,   118,   110,   117,
      63,    61,   152,    73,   143,   146,   102,   155,    68,    63,
      24,    72,   140,    53,   140,    60,   151,     3,   156,    61,
     118,    60,   151,    60,   151,   113,   149,    64,   118,   118,
      60,   151,   149,    64,    31,   109,    68,    11,    61,   152,
      61,   152,   146,    58,    60,    60,    73,    58,    60,    73,
     114,   141,    72,   114,   121,   122,   123,   124,   128,   130,
      73,    58,    14,   101,   103,   118,   114,   140,   156,   140,
      73,   138,    58,   112,   156,    92,    73,    88,    73,   149,
      89,    90,   135,   148,    73,   149,    73,    73,   152,   109,
      73,    73,    58,   144,   155,   143,    72,   130,    20,    94,
      73,    73,   156,    60,   151,   118,    73,    73,   143,    99,
     156,   156,    90,    73,    73,    95,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    83,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    88,    88,    88,    89,
      89,    90,    90,    90,    91,    92,    93,    93,    93,    93,
      93,    93,    94,    95,    96,    96,    97,    98,    99,    99,
     100,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   109,   109,   110,   111,   111,   112,
     113,   114,   114,   114,   115,   115,   116,   117,   117,   118,
     118,   118,   118,   118,   119,   119,   119,   120,   120,   121,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     125,   125,   126,   127,   127,   128,   129,   129,   130,   130,
     130,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   141,   141,   141,   141,   142,   142,   143,
     143,   144,   144,   144,   144,   144,   145,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156
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
       3,     3,     3,     1,     2,     2,     2,     2,     2,     2,
       3,     5,     6,     1,     1,     3,     5,     5,     4,     1,
       5,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     1,     1,     2,     1,
       1,     1,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     5,     1,     2,
       5,     3,     3,     5,     8,     5,     0,     3,     0,     1,
       3,     1,     4,     2,     0,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     2,     4,     3,     5,     5,
       1,     3,     1,     1,     2,     2,     1,     1,     3,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1
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
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FILE, "file", nkids, kids, NULL);
		ast_root = (yyval.ast);
	}
#line 1714 "go.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 174 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		(yyval.ast) = new_epsilon_tree(R_PACKAGE, "package");
		exit(2);
	}
#line 1724 "go.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 180 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(R_PACKAGE, "package", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "package", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_PACKAGE, "package", nkids, kids, NULL);
	}
#line 1736 "go.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 191 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_IMPORTS, "imports");
	}
#line 1744 "go.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 195 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "imports", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_IMPORTS, "imports", nkids, kids, NULL);
	}
#line 1755 "go.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 205 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "import", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
#line 1766 "go.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LIMPORT, "import", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "import", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "import", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
#line 1779 "go.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 221 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LIMPORT, "import", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "import", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "import", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		(yyval.ast) = new_tree_node(R_IMPORT, "import", nkids, kids, NULL);
	}
#line 1792 "go.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 233 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IMPORT_STMT, "import_stmt", nkids, kids, NULL);
	}
#line 1802 "go.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 239 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1810 "go.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 246 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1818 "go.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 250 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "import_stmt_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IMPORT_STMT_LIST, "import_stmt_list", nkids, kids, NULL);
	}
#line 1829 "go.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 260 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "import_here", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
#line 1840 "go.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 267 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LLITERAL, "import_here", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), t2);
		(yyval.ast) = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
#line 1851 "go.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 274 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "import_here", (yyvsp[-1].t));
		struct tree* t2 = new_leaf_node(LLITERAL, "import_here", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2);
		(yyval.ast) = new_tree_node(R_IMPORT_HERE, "import_here", nkids, kids, NULL);
	}
#line 1863 "go.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 285 "go.y" /* yacc.c:1646  */
    {
		// TODO: concat package and name
		int nkids = 4;
		struct tree* t1 = new_leaf_node(LPACKAGE, "import_package", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LNAME, "import_package", (yyvsp[-2].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "import_package", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_IMPORT_PACKAGE, "import_package", nkids, kids, NULL);
	}
#line 1877 "go.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 298 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_IMPORT_SAFETY, "import_safety");
	}
#line 1885 "go.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 302 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LNAME, "import_safety", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_IMPORT_SAFETY, "import_safety", nkids, kids, NULL);
	}
#line 1896 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 315 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		(yyval.ast) = new_epsilon_tree(R_XDCL, "xdcl");
	}
#line 1905 "go.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 320 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1913 "go.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 324 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1921 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 328 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1930 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 333 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 1938 "go.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 340 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LVAR, "common_dcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 1949 "go.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 347 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LVAR, "common_dcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 1962 "go.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 356 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LVAR, "common_dcl", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "common_dcl", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 1975 "go.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 365 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 1985 "go.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 371 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 1997 "go.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 379 "go.y" /* yacc.c:1646  */
    {
		int nkids = 7;
		struct tree* t2 = new_leaf_node((yyvsp[-5].t)->category, "common_dcl", (yyvsp[-5].t));
		struct tree* t4 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t7 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-6].ast), t2, (yyvsp[-4].ast), t4, (yyvsp[-2].ast), (yyvsp[-1].ast), t7);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2010 "go.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 388 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "common_dcl", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, t3);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2022 "go.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 396 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LTYPE, "common_dcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2033 "go.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 403 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LTYPE, "common_dcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "common_dcl", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2046 "go.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 412 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LTYPE, "common_dcl", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "common_dcl", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "common_dcl", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3);
		(yyval.ast) = new_tree_node(R_COMMON_DCL, "common_dcl", nkids, kids, NULL);
	}
#line 2059 "go.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 424 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LCONST, "lconst", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_LCONST, "lconst", nkids, kids, NULL);
	}
#line 2070 "go.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 434 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
#line 2080 "go.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 440 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "vardcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
#line 2091 "go.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 447 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "vardcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL, "vardcl", nkids, kids, NULL);
	}
#line 2102 "go.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 457 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "constdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL, "constdcl", nkids, kids, NULL);
	}
#line 2113 "go.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 464 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "constdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL, "constdcl", nkids, kids, NULL);
	}
#line 2124 "go.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 474 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2132 "go.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 478 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL1, "constdcl1", nkids, kids, NULL);
	}
#line 2142 "go.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 484 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2150 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 491 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2160 "go.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 500 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_TYPEDCL, "typedcl", nkids, kids, NULL);
	}
#line 2170 "go.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 509 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2178 "go.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 513 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LASOP, "simple_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2189 "go.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 520 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "simple_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2200 "go.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 527 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LCOLAS, "simple_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2211 "go.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 534 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LINC, "simple_stmt", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), t2);
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2222 "go.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 541 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t2 = new_leaf_node(LDEC, "simple_stmt", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), t2);
		(yyval.ast) = new_tree_node(R_SIMPLE_STMT, "simple_stmt", nkids, kids, NULL);
	}
#line 2233 "go.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 552 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "compound_stmt", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "compound_stmt", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_COMPOUND_STMT, "compound_stmt", nkids, kids, NULL);
	}
#line 2245 "go.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 564 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LBODY, "loop_body", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "loop_body", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_LOOP_BODY, "loop_body", nkids, kids, NULL);
	}
#line 2257 "go.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 575 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "for_header", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "for_header", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FOR_HEADER, "for_header", nkids, kids, NULL);
	}
#line 2269 "go.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 583 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2277 "go.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 590 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FOR_BODY, "for_body", nkids, kids, NULL);
	}
#line 2287 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 600 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LFOR, "for_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FOR_STMT, "for_stmt", nkids, kids, NULL);
	}
#line 2298 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 610 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2306 "go.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 614 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "if_header", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IF_HEADER, "if_header", nkids, kids, NULL);
	}
#line 2317 "go.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 628 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LIF, "if_stmt", (yyvsp[-4].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_IF_STMT, "if_stmt", nkids, kids, NULL);
	}
#line 2328 "go.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 639 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node(LELSE, "elseif", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LIF, "elseif", (yyvsp[-2].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ELSEIF, "elseif", nkids, kids, NULL);
	}
#line 2340 "go.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 650 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_ELSEIF_LIST, "elseif_list");
	}
#line 2348 "go.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 654 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ELSEIF_LIST, "elseif_list", nkids, kids, NULL);
	}
#line 2358 "go.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 663 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_ELSE, "else");
	}
#line 2366 "go.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 667 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LELSE, "else", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ELSE, "else", nkids, kids, NULL);
	}
#line 2377 "go.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 680 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2385 "go.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 684 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LOROR, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2396 "go.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 691 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LANDAND, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2407 "go.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 698 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LEQ, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2418 "go.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 705 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LNE, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2429 "go.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 712 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LLT, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2440 "go.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 719 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LLE, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2451 "go.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 726 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LGE, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2462 "go.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 733 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LGT, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2473 "go.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 740 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2484 "go.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 747 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2495 "go.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 754 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2506 "go.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 761 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2517 "go.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 768 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2528 "go.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 775 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2539 "go.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 782 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LANDNOT, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2550 "go.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 789 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node(LCOMM, "expr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR, "expr", nkids, kids, NULL);
	}
#line 2561 "go.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 799 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2569 "go.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 803 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2580 "go.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 810 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2591 "go.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 817 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2602 "go.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 824 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2613 "go.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 831 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2624 "go.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 838 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LCOMM, "uexpr", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_UEXPR, "uexpr", nkids, kids, NULL);
	}
#line 2635 "go.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 852 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "pseudocall", (yyvsp[-1].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "pseudocall", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, t3);
		(yyval.ast) = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
#line 2647 "go.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 860 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pseudocall", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pseudocall", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
#line 2659 "go.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 868 "go.y" /* yacc.c:1646  */
    {
		int nkids = 6;
		struct tree* t2 = new_leaf_node((yyvsp[-4].t)->category, "pseudocall", (yyvsp[-4].t));
		struct tree* t4 = new_leaf_node(LDDD, "pseudocall", (yyvsp[-2].t));
		struct tree* t6 = new_leaf_node((yyvsp[0].t)->category, "pseudocall", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-5].ast), t2, (yyvsp[-3].ast), t4, (yyvsp[-1].ast), t6);
		(yyval.ast) = new_tree_node(R_PSEUDOCALL, "pseudocall", nkids, kids, NULL);
	}
#line 2672 "go.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 880 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2683 "go.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 887 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2691 "go.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 891 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "pexpr_no_paren", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2702 "go.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 898 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pexpr_no_paren", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-2].t)->category, "pexpr_no_paren", (yyvsp[-2].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, t3, (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2715 "go.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 907 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pexpr_no_paren", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-2].t)->category, "pexpr_no_paren", (yyvsp[-2].t));
		struct tree* t4 = new_leaf_node(LTYPE, "pexpr_no_paren", (yyvsp[-1].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, t3, t4, t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2729 "go.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 917 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t2 = new_leaf_node((yyvsp[-2].t)->category, "pexpr_no_paren", (yyvsp[-2].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), t2, (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2741 "go.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 925 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2749 "go.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 929 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "pexpr_no_paren", (yyvsp[-3].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "pexpr_no_paren", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_PEXPR_NO_PAREN, "pexpr_no_paren", nkids, kids, NULL);
	}
#line 2761 "go.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 937 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2769 "go.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 946 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2777 "go.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 950 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "pexpr", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "pexpr", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_PEXPR, "pexpr", nkids, kids, NULL);
	}
#line 2789 "go.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 961 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2797 "go.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 965 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR_OR_TYPE, "expr_or_type", nkids, kids, NULL);
	}
#line 2807 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 974 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);

	}
#line 2816 "go.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 982 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LBODY, "lbrace", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_LBRACE, "lbrace", nkids, kids, NULL);
	}
#line 2827 "go.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 989 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "lbrace", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_LBRACE, "lbrace", nkids, kids, NULL);
	}
#line 2838 "go.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1004 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2846 "go.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1011 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2854 "go.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1018 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LNAME, "sym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_SYM, "sym", nkids, kids, NULL);
	}
#line 2865 "go.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1025 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2873 "go.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1029 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "sym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_SYM, "sym", nkids, kids, NULL);
	}
#line 2884 "go.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1039 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "hidden_importsym", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LLITERAL, "hidden_importsym", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "hidden_importsym", (yyvsp[-1].t));
		struct tree* t4 = new_leaf_node(LNAME, "hidden_importsym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, t4);
		(yyval.ast) = new_tree_node(R_HIDDEN_IMPORTSYM, "hidden_importsym", nkids, kids, NULL);
	}
#line 2898 "go.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1049 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "hidden_importsym", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LLITERAL, "hidden_importsym", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "hidden_importsym", (yyvsp[-1].t));
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "hidden_importsym", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, t4);
		(yyval.ast) = new_tree_node(R_HIDDEN_IMPORTSYM, "hidden_importsym", nkids, kids, NULL);
	}
#line 2912 "go.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1062 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2920 "go.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1079 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");

		int nkids = 1;
		struct tree* t1 = new_leaf_node(LDDD, "dotdotdot", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_DOTDOTDOT, "dotdotdot", nkids, kids, NULL);
	}
#line 2933 "go.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1088 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LDDD, "dotdotdot", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_DOTDOTDOT, "dotdotdot", nkids, kids, NULL);
	}
#line 2944 "go.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1098 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2952 "go.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1102 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2960 "go.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1106 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2968 "go.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1110 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2976 "go.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1114 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "ntype", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "ntype", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_NTYPE, "ntype", nkids, kids, NULL);
	}
#line 2988 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1125 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 2996 "go.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1129 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3004 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1133 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "non_expr_type", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_NON_EXPR_TYPE, "non_expr_type", nkids, kids, NULL);
	}
#line 3015 "go.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1143 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3023 "go.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1147 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3031 "go.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1155 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3039 "go.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1159 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3047 "go.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1163 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3055 "go.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1167 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3063 "go.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1174 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3071 "go.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1178 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "dotname", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_DOTNAME, "dotname", nkids, kids, NULL);
	}
#line 3082 "go.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1188 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "othertype", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "othertype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}
#line 3094 "go.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1196 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "othertype", (yyvsp[-3].t));
		struct tree* t2 = new_leaf_node(LDDD, "othertype", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "othertype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}
#line 3107 "go.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1205 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LMAP, "othertype", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node(LDDD, "othertype", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "othertype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OTHERTYPE, "othertype", nkids, kids, NULL);
	}
#line 3120 "go.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1214 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3128 "go.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1221 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node((yyvsp[-1].t)->category, "ptrtype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_PTRTYPE, "ptrtype", nkids, kids, NULL);
	}
#line 3139 "go.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1231 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LSTRUCT, "structtype", (yyvsp[-4].t));
		struct tree* t5 = new_leaf_node((yyvsp[0].t)->category, "structtype", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), t5);
		(yyval.ast) = new_tree_node(R_STRUCTTYPE, "structtype", nkids, kids, NULL);
	}
#line 3151 "go.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1239 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LSTRUCT, "structtype", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "structtype", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_STRUCTTYPE, "structtype", nkids, kids, NULL);
	}
#line 3163 "go.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1254 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LFUNC, "xfndcl", (yyvsp[-2].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_XFNDCL, "xfndcl", nkids, kids, NULL);
	}
#line 3174 "go.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1264 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "fndcl", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "fndcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-4].ast), t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNDCL, "fndcl", nkids, kids, NULL);
	}
#line 3186 "go.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1272 "go.y" /* yacc.c:1646  */
    {
		int nkids = 8;
		struct tree* t1 = new_leaf_node((yyvsp[-7].t)->category, "fndcl", (yyvsp[-7].t));
		struct tree* t3 = new_leaf_node((yyvsp[-5].t)->category, "fndcl", (yyvsp[-5].t));
		struct tree* t5 = new_leaf_node((yyvsp[-3].t)->category, "fndcl", (yyvsp[-3].t));
		struct tree* t7 = new_leaf_node((yyvsp[-1].t)->category, "fndcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-6].ast), t3, (yyvsp[-4].ast), t5, (yyvsp[-2].ast), t7, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNDCL, "fndcl", nkids, kids, NULL);
	}
#line 3200 "go.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1286 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node(LFUNC, "fntype", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "fntype", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "fntype", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNTYPE, "fntype", nkids, kids, NULL);
	}
#line 3213 "go.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1298 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_FNBODY, "fnbody");
	}
#line 3221 "go.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1302 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "fnbody", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "fnbody", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_FNBODY, "fnbody", nkids, kids, NULL);
	}
#line 3233 "go.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1313 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_FNRES, "fnres");
	}
#line 3241 "go.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1317 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3249 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1321 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "fnres", (yyvsp[-2].t));
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "fnres", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_FNRES, "fnres", nkids, kids, NULL);
	}
#line 3261 "go.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1332 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3269 "go.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1339 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t4 = new_leaf_node((yyvsp[0].t)->category, "fnliteral", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), t4);
		(yyval.ast) = new_tree_node(R_FNLITERAL, "fnliteral", nkids, kids, NULL);
	}
#line 3280 "go.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1346 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_FNLITERAL, "fnliteral", nkids, kids, NULL);
	}
#line 3290 "go.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1360 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_XDCL_LIST, "xdcl_list");
	}
#line 3298 "go.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1364 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t3 = new_leaf_node((yyvsp[0].t)->category, "xdcl_list", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), t3);
		(yyval.ast) = new_tree_node(R_XDCL_LIST, "xdcl_list", nkids, kids, NULL);
	}
#line 3309 "go.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1374 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3317 "go.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1378 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "vardcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_VARDCL_LIST, "vardcl_list", nkids, kids, NULL);
	}
#line 3328 "go.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1388 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3336 "go.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1392 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "constdcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_CONSTDCL_LIST, "constdcl_list", nkids, kids, NULL);
	}
#line 3347 "go.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1402 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3355 "go.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1406 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "typedcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_TYPEDCL_LIST, "typedcl_list", nkids, kids, NULL);
	}
#line 3366 "go.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1416 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3374 "go.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1420 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "structdcl_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL_LIST, "structdcl_list", nkids, kids, NULL);
	}
#line 3385 "go.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1430 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3395 "go.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1436 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3405 "go.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1442 "go.y" /* yacc.c:1646  */
    {
		int nkids = 4;
		struct tree* t1 = new_leaf_node((yyvsp[-3].t)->category, "structdcl", (yyvsp[-3].t));
		struct tree* t3 = new_leaf_node((yyvsp[-1].t)->category, "structdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-2].ast), t3, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3417 "go.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1450 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node((yyvsp[-2].t)->category, "structdcl", (yyvsp[-2].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3428 "go.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1457 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node((yyvsp[-4].t)->category, "structdcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "structdcl", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "structdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3441 "go.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1466 "go.y" /* yacc.c:1646  */
    {
		int nkids = 5;
		struct tree* t1 = new_leaf_node((yyvsp[-4].t)->category, "structdcl", (yyvsp[-4].t));
		struct tree* t2 = new_leaf_node((yyvsp[-3].t)->category, "structdcl", (yyvsp[-3].t));
		struct tree* t4 = new_leaf_node((yyvsp[-1].t)->category, "structdcl", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[-2].ast), t4, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STRUCTDCL, "structdcl", nkids, kids, NULL);
	}
#line 3454 "go.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1478 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LNAME, "packname", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_PACKNAME, "packname", nkids, kids, NULL);
	}
#line 3465 "go.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1485 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t1 = new_leaf_node(LNAME, "packname", (yyvsp[-2].t));
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "packname", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_PACKNAME, "packname", nkids, kids, NULL);
	}
#line 3477 "go.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1496 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3485 "go.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1506 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3493 "go.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1510 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ARG_TYPE, "arg_type", nkids, kids, NULL);
	}
#line 3503 "go.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1516 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ARG_TYPE, "arg_type", nkids, kids, NULL);
	}
#line 3513 "go.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1522 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3521 "go.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1529 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3529 "go.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1533 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "arg_type_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_ARG_TYPE_LIST, "arg_type_list", nkids, kids, NULL);
	}
#line 3540 "go.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1543 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OARG_TYPE_LIST_OCOMMA, "oarg_type_list_ocomma");
	}
#line 3548 "go.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1547 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-1].ast), (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_OARG_TYPE_LIST_OCOMMA, "oarg_type_list_ocomma", nkids, kids, NULL);
	}
#line 3558 "go.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1559 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_STMT, "stmt");
	}
#line 3566 "go.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1563 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3574 "go.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1567 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3582 "go.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1571 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3590 "go.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1575 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3598 "go.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1582 "go.y" /* yacc.c:1646  */
    {
		
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3607 "go.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1587 "go.y" /* yacc.c:1646  */
    {
		
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3616 "go.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1592 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3624 "go.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1596 "go.y" /* yacc.c:1646  */
    {
		int nkids = 2;
		struct tree* t1 = new_leaf_node(LRETURN, "non_dcl_stmt", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, t1, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_NON_DCL_STMT, "non_dcl_stmt", nkids, kids, NULL);
	}
#line 3635 "go.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1606 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3643 "go.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1610 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "stmt_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_STMT_LIST, "stmt_list", nkids, kids, NULL);
	}
#line 3654 "go.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1620 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3662 "go.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1624 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "new_name_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_NEW_NAME_LIST, "new_name_list", nkids, kids, NULL);
	}
#line 3673 "go.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1634 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3681 "go.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1638 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "dcl_name_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_DCL_NAME_LIST, "dcl_name_list", nkids, kids, NULL);
	}
#line 3692 "go.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1648 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3700 "go.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1652 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR_LIST, "expr_list", nkids, kids, NULL);
	}
#line 3711 "go.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1662 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3719 "go.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1666 "go.y" /* yacc.c:1646  */
    {
		int nkids = 3;
		struct tree* t2 = new_leaf_node((yyvsp[-1].t)->category, "expr_or_type_list", (yyvsp[-1].t));
		struct tree** kids = create_tree_kids(nkids, (yyvsp[-2].ast), t2, (yyvsp[0].ast));
		(yyval.ast) = new_tree_node(R_EXPR_OR_TYPE_LIST, "expr_or_type_list", nkids, kids, NULL);
	}
#line 3730 "go.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1684 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OSEMI, "osemi");
	}
#line 3738 "go.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1688 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "osemi", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_OSEMI, "osemi", nkids, kids, NULL);
	}
#line 3749 "go.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1698 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OCOMMA, "ocomma");
	}
#line 3757 "go.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1702 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node((yyvsp[0].t)->category, "ocomma", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_OCOMMA, "ocomma", nkids, kids, NULL);
	}
#line 3768 "go.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1712 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OEXPR, "oexpr");
	}
#line 3776 "go.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1716 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3784 "go.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1723 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OEXPR_LIST, "oexpr_list");
	}
#line 3792 "go.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1727 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3800 "go.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1734 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OSIMPLE_STMT, "osimple_stmt");		
	}
#line 3808 "go.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1738 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = (yyvsp[0].ast);
	}
#line 3816 "go.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1746 "go.y" /* yacc.c:1646  */
    {
		(yyval.ast) = new_epsilon_tree(R_OLITERAL, "oliteral");		
	}
#line 3824 "go.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1750 "go.y" /* yacc.c:1646  */
    {
		int nkids = 1;
		struct tree* t1 = new_leaf_node(LLITERAL, "oliteral", (yyvsp[0].t));
		struct tree** kids = create_tree_kids(nkids, t1);
		(yyval.ast) = new_tree_node(R_OLITERAL, "oliteral", nkids, kids, NULL);
	}
#line 3835 "go.tab.c" /* yacc.c:1646  */
    break;


#line 3839 "go.tab.c" /* yacc.c:1646  */
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
#line 1773 "go.y" /* yacc.c:1906  */

