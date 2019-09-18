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
#include "token.h"
#include "tree.h"
#include "utils.h"

int yylex (void);
void yyerror (char const *);

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

// void yyerror(char *s)
// {
//    fprintf(stderr, "%s:%d: %s before '%s' token\n",
// 	   yyfilename, yylineno, s, yytext);
// }



#line 102 "go.tab.c" /* yacc.c:339  */

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
#line 58 "go.y" /* yacc.c:355  */

	struct tree* ast;
	struct token* t;

	char *sval;
	double dval;
	int ival;

#line 203 "go.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "go.tab.c" /* yacc.c:358  */

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
#define YYLAST   2213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  128
/* YYNRULES -- Number of rules.  */
#define YYNRULES  336
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  650

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
       2,     2,     2,    69,     2,     2,    64,    55,    56,     2,
      59,    60,    53,    49,    75,    50,    63,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    62,
       2,    65,     2,    73,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    72,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    51,    68,    70,     2,     2,     2,
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
      45,    46,    47,    48,    57,    58,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   153,   153,   156,   161,   164,   165,   168,   169,   170,
     174,   178,   179,   183,   184,   185,   189,   192,   193,   197,
     203,   207,   208,   209,   214,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   234,   238,   239,   240,   244,
     245,   249,   250,   251,   255,   263,   267,   268,   269,   270,
     271,   272,   276,   277,   278,   279,   283,   289,   288,   315,
     316,   320,   325,   326,   330,   331,   332,   336,   340,   345,
     346,   351,   358,   362,   363,   366,   367,   371,   377,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   406,
     410,   411,   412,   413,   414,   415,   416,   420,   421,   429,
     430,   431,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   451,   454,   461,   465,   466,
     470,   471,   475,   476,   480,   481,   484,   487,   488,   497,
     501,   504,   505,   509,   510,   511,   515,   516,   520,   524,
     537,   541,   545,   546,   547,   548,   549,   550,   554,   555,
     556,   557,   561,   562,   563,   564,   565,   569,   570,   573,
     577,   578,   579,   580,   581,   585,   586,   590,   591,   592,
     593,   594,   595,   596,   600,   604,   608,   609,   613,   614,
     622,   626,   627,   631,   632,   636,   639,   640,   644,   645,
     646,   650,   654,   655,   663,   664,   668,   669,   673,   674,
     678,   679,   683,   684,   688,   689,   693,   694,   695,   696,
     697,   698,   702,   703,   707,   711,   712,   713,   717,   724,
     725,   726,   727,   731,   732,   735,   736,   742,   743,   744,
     745,   746,   750,   751,   752,   753,   754,   755,   757,   758,
     759,   760,   761,   762,   763,   767,   768,   772,   773,   777,
     778,   782,   783,   787,   788,   795,   796,   797,   798,   801,
     802,   808,   809,   812,   813,   816,   817,   820,   821,   824,
     825,   828,   829,   832,   833,   836,   837,   840,   841,   848,
     849,   850,   851,   852,   853,   857,   861,   869,   870,   871,
     875,   876,   880,   881,   882,   883,   884,   885,   886,   887,
     888,   889,   890,   894,   898,   902,   903,   907,   911,   912,
     915,   916,   920,   921,   929,   930,   931,   935,   936,   939,
     940,   944,   945,   949,   950,   954,   955
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
  "'/'", "'%'", "'&'", "NotPackage", "NotParen", "'('", "')'",
  "PreferToRightParen", "';'", "'.'", "'$'", "'='", "':'", "'{'", "'}'",
  "'!'", "'~'", "'['", "']'", "'?'", "'@'", "','", "$accept", "file",
  "package", "imports", "import", "import_stmt", "import_stmt_list",
  "import_here", "import_package", "import_safety", "import_there", "xdcl",
  "common_dcl", "lconst", "vardcl", "constdcl", "constdcl1", "typedclname",
  "typedcl", "simple_stmt", "case", "compound_stmt", "caseblock", "$@1",
  "caseblock_list", "loop_body", "range_stmt", "for_header", "for_body",
  "for_stmt", "if_header", "if_stmt", "elseif", "elseif_list", "else",
  "switch_stmt", "select_stmt", "expr", "uexpr", "pseudocall",
  "pexpr_no_paren", "start_complit", "keyval", "bare_complitexpr",
  "complitexpr", "pexpr", "expr_or_type", "name_or_type", "lbrace",
  "new_name", "dcl_name", "onew_name", "sym", "hidden_importsym", "name",
  "labelname", "dotdotdot", "ntype", "non_expr_type", "non_recvchantype",
  "convtype", "comptype", "fnret_type", "dotname", "othertype", "ptrtype",
  "recvchantype", "structtype", "interfacetype", "xfndcl", "fndcl",
  "hidden_fndcl", "fntype", "fnbody", "fnres", "fnlitdcl", "fnliteral",
  "xdcl_list", "vardcl_list", "constdcl_list", "typedcl_list",
  "structdcl_list", "interfacedcl_list", "structdcl", "packname", "embed",
  "interfacedcl", "indcl", "arg_type", "arg_type_list",
  "oarg_type_list_ocomma", "stmt", "non_dcl_stmt", "stmt_list",
  "new_name_list", "dcl_name_list", "expr_list", "expr_or_type_list",
  "keyval_list", "braced_keyval_list", "osemi", "ocomma", "oexpr",
  "oexpr_list", "osimple_stmt", "ohidden_funarg_list",
  "ohidden_structdcl_list", "ohidden_interfacedcl_list", "oliteral",
  "hidden_import", "hidden_pkg_importsym", "hidden_pkgtype", "hidden_type",
  "hidden_type_non_recv_chan", "hidden_type_misc", "hidden_type_recv_chan",
  "hidden_type_func", "hidden_funarg", "hidden_structdcl",
  "hidden_interfacedcl", "ohidden_funres", "hidden_funres",
  "hidden_literal", "hidden_constant", "hidden_import_list",
  "hidden_funarg_list", "hidden_structdcl_list",
  "hidden_interfacedcl_list", YY_NULLPTR
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
      45,   124,    94,    42,    47,    37,    38,   304,   305,    40,
      41,   306,    59,    46,    36,    61,    58,   123,   125,    33,
     126,    91,    93,    63,    64,    44
};
# endif

#define YYPACT_NINF -528

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-528)))

#define YYTABLE_NINF -262

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   128,    41,  -528,  -528,  -528,    58,     0,  -528,  -528,
      94,    47,  -528,    44,    76,  1023,    13,  -528,    84,   146,
    -528,   150,   204,  -528,  -528,  -528,   128,   677,  -528,   128,
     266,  -528,  1638,   208,   266,   128,  1638,    17,   151,  1638,
     186,    17,  1638,   382,   425,  1638,  1638,  1638,  1638,  1638,
    1638,  1681,  1638,  1638,  1289,   162,  -528,   446,  -528,  -528,
    -528,  -528,  -528,  1234,  -528,  -528,   170,   209,  -528,   179,
    -528,   196,   193,    17,   211,  -528,  -528,  -528,   235,    98,
    -528,  -528,   121,  -528,  -528,  -528,  -528,   201,  -528,   272,
    -528,  -528,  -528,  -528,  -528,   241,  1293,  1293,  1293,  -528,
     256,  -528,  -528,  -528,  -528,  -528,  -528,   252,   209,  -528,
    -528,   268,  -528,   165,   259,   429,   265,   264,   254,  -528,
     268,   273,  -528,  -528,   358,  1293,  2086,   251,  -528,  -528,
     362,   309,   224,  1293,  -528,  -528,   231,  -528,  -528,  -528,
     667,  -528,  -528,  -528,  -528,  -528,  -528,  1724,  1681,  2086,
     285,  -528,   240,  -528,   218,  -528,  -528,   289,  2086,   291,
    -528,   305,  -528,   744,  1638,  1638,  1638,  1638,  -528,  1638,
    1638,  1638,  -528,  1638,  1638,  1638,  1638,  1638,  1638,  1638,
    1638,  1638,  1638,  1638,  1638,  1638,  1638,  -528,  1332,   455,
    1638,  1097,  1638,  -528,  -528,  1192,  1638,  1638,  1638,   110,
     287,   344,  -528,   345,   429,   363,  1293,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,   310,   128,  1192,  -528,  1387,  1442,
    1638,  1293,  -528,   429,  -528,  -528,  -528,   299,   321,   429,
    1192,  -528,  -528,  1638,   163,   359,  -528,   328,   326,  -528,
    -528,   319,    82,    29,    39,  -528,  -528,   332,  -528,  -528,
     395,  1767,  -528,  -528,  -528,   335,  -528,  -528,  -528,   339,
    1638,   128,   338,  1792,  -528,   340,  1293,  1293,  -528,   352,
    1638,   351,  2086,  2157,  -528,  2110,  1128,  1128,  1128,  1128,
    -528,  1128,  1128,  2134,  -528,   539,   539,   539,   539,  -528,
    -528,  -528,  -528,  1485,  -528,  -528,    53,  1540,  -528,  1984,
     353,  -528,  1192,  -528,  -528,  -528,  -528,  1951,  1485,  -528,
      36,   251,   251,  2086,  -528,  -528,  -528,   360,   346,    89,
     400,   346,   346,   369,  -528,   374,  1293,   378,  -528,  -528,
     117,  1638,  1638,   377,  -528,  -528,  -528,   429,  -528,  1800,
     385,   182,   445,  -528,   128,   397,   401,   429,  -528,   506,
     406,  1293,  1681,   396,  -528,  -528,  -528,   359,   395,   359,
     403,   433,   409,  -528,  -528,   128,   395,    83,   128,   420,
     128,   430,   251,  -528,  1638,  1826,  1293,  -528,   275,   282,
     383,   408,  -528,  -528,  -528,   128,   434,   251,  1638,  -528,
    2014,  -528,  -528,   393,   417,   421,  1681,   437,   441,   453,
    -528,  1638,   203,  -528,   457,   447,  1097,  -528,  -528,  -528,
    1853,   128,   264,   459,   518,  -528,  1912,  1912,  -528,  1800,
    -528,  -528,  2086,  2086,  1638,  -528,   429,   463,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  1800,  -528,    18,  -528,  -528,
    -528,  -528,   464,  -528,  -528,  -528,   106,  -528,  1097,   471,
    -528,   472,   395,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,   251,   473,  1485,  -528,  -528,   475,   744,  -528,
     251,  1485,  1583,  1485,  -528,  -528,   474,  -528,  -528,  -528,
    -528,   102,  -528,  -528,  -528,  -528,   874,   476,   479,   467,
    -528,   484,   531,  1912,    46,    28,  -528,   490,  -528,  -528,
    -528,  1879,  -528,    81,   478,   128,   496,   499,   500,  -528,
     481,   429,  -528,  1638,  -528,  1800,  1638,  1638,  -528,  1681,
     502,   395,   395,  -528,   477,   501,   128,   507,   351,   503,
    -528,  2086,  -528,  -528,  -528,  -528,  1638,  -528,  1912,   532,
    -528,  -528,  -528,   128,   936,  1912,   128,  1912,  -528,  -528,
     567,   143,  -528,  -528,   510,   505,  1912,    46,  1912,   395,
     128,   128,  -528,   514,   513,  -528,  -528,  -528,  -528,   515,
     268,  -528,  2038,  2062,  -528,  -528,  -528,  -528,  -528,  -528,
    1485,   526,  -528,   522,   530,   519,   541,   542,   536,  -528,
    -528,   543,   534,  1912,   540,  -528,   547,  -528,  -528,   561,
    -528,  1912,  -528,   551,   395,  -528,   556,  -528,  1887,  1800,
    -528,  -528,  -528,   549,  -528,  -528,  1887,   128,  -528,   936,
    1912,   395,  -528,   128,   143,  -528,  -528,  -528,   128,   128,
    -528,  -528,  -528,  -528,  -528,  -528,   560,  -528,  -528,  -528,
    -528,   564,   565,   566,  1887,  -528,  1887,  -528,  -528,  -528
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     5,   143,   145,     0,     0,   144,     1,
     204,     0,     4,     0,     0,     0,     0,    13,     0,     0,
       7,     0,     0,     6,    24,   112,   141,     0,    35,   141,
       0,   248,   279,     0,     0,     0,   279,     0,     0,   277,
       0,     0,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,    21,     0,   242,   243,
     246,   244,   245,    46,    79,   120,   132,   100,   149,   148,
     113,     0,     0,     0,   169,   182,   183,    22,   201,     0,
     125,    23,     0,   146,   147,     9,    11,   271,    15,     0,
     329,    14,   142,   249,   139,     0,     0,     0,     0,   148,
     175,   179,   165,   163,   164,   162,   250,   120,     0,   280,
      66,     0,    68,     0,    65,   235,     0,   196,   120,   253,
       0,    69,   137,   138,     0,     0,   261,   278,   254,    59,
       0,     0,     0,     0,    32,    44,     0,    25,   259,   140,
       0,   108,   103,   104,   107,   101,   102,     0,     0,   134,
       0,   135,   160,   158,   159,   105,   106,     0,   276,     0,
     205,     0,    28,     0,     0,     0,     0,     0,    51,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,     0,
     275,     0,     0,   126,   203,     0,     0,     0,     0,   272,
       0,    17,    10,     0,   235,     0,     0,   180,   156,   154,
     155,   152,   153,   184,     0,     0,     0,    67,     0,     0,
     279,   150,   229,   148,   232,   136,   233,   273,     0,   235,
       0,   190,    73,   279,   143,     0,   189,     0,   271,   226,
     214,     0,     0,     0,     0,   187,   257,   271,   212,   224,
     287,     0,    59,    34,   210,   271,    45,    27,   206,   271,
       0,     0,    36,     0,   161,   133,     0,     0,    31,   271,
       0,     0,    47,    81,    96,    99,    82,    86,    87,    85,
      97,    84,    83,    80,    98,    88,    89,    90,    91,    92,
      93,    94,    95,   269,   109,   263,   273,     0,   114,   276,
       0,   241,     0,   239,   238,   247,   240,   273,   269,   255,
       0,    49,    48,   262,    12,     8,    18,     0,     0,     0,
       0,     0,     0,     0,   330,     0,     0,     0,   166,   176,
       0,     0,     0,     0,   151,   230,   231,   274,   236,   198,
       0,     0,    75,    70,     0,   222,     0,   235,   225,   272,
       0,     0,     0,     0,    78,    57,    60,     0,   287,     0,
       0,   272,     0,   288,   217,     0,   287,     0,   272,     0,
     272,     0,    38,   260,     0,     0,     0,   185,   156,   154,
     155,   153,   126,   178,   177,   272,     0,    40,     0,   126,
     128,   265,   266,   273,     0,   273,   274,     0,     0,     0,
     117,   275,     0,   274,     0,     0,     0,   202,    16,   295,
       0,     0,   196,     0,     0,   296,     0,     0,    19,   198,
     157,    61,    63,    62,   279,   234,   235,   148,   199,   174,
     172,   173,   170,   171,   195,   198,   197,     0,    74,    71,
     223,   227,     0,   215,   188,   181,     0,    55,     0,     0,
     219,     0,   287,   213,   186,   258,   216,    77,   211,    33,
     207,    26,    37,     0,   269,    41,   208,   271,    43,    29,
      39,   269,     0,   274,   270,   123,     0,   264,   110,   116,
     115,     0,    56,   121,   122,   256,     0,     0,     0,     0,
     303,     0,     0,     0,     0,     0,   302,     0,   297,   298,
     299,     0,   331,     0,     0,   281,     0,     0,     0,    64,
       0,   235,   191,   279,    76,   198,     0,     0,    52,     0,
      58,   287,   287,   218,   157,     0,   272,     0,    42,     0,
     126,   130,   127,   267,   268,   111,   275,   118,     0,     0,
     310,   300,   301,   281,   285,     0,   283,     0,   309,   324,
       0,     0,   326,   327,     0,     0,     0,     0,     0,   287,
       0,     0,   294,     0,   282,   289,   293,   290,   200,     0,
       0,   228,     0,     0,   221,   220,   124,   209,    30,   129,
     269,     0,   312,     0,     0,   303,     0,   302,     0,   319,
     335,   286,     0,     0,     0,   333,   284,   313,   325,     0,
     291,     0,   304,     0,   287,   315,     0,   332,   320,   198,
      72,    54,    53,     0,   119,   311,   320,   281,   308,     0,
       0,   287,   307,     0,     0,   305,   292,   316,   281,   281,
     323,   193,   321,   192,   131,   314,     0,   336,   306,   317,
     334,     0,     0,     0,   320,   328,   320,   322,   318,   194
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -528,  -528,  -528,  -528,  -528,     1,  -528,  -528,  -528,  -528,
    -528,  -528,   606,  -528,  -121,   -39,   103,  -528,  -122,     3,
    -528,   194,  -528,  -528,   380,  -116,  -528,  -528,  -528,  -528,
     -41,  -528,  -528,  -528,  -528,  -528,  -528,   670,    30,    35,
    -528,  -171,   157,   160,  -528,   278,   -43,   411,    80,    31,
     376,   609,    -1,   327,   451,  -528,   416,   456,   492,  -528,
    -528,  -528,  -528,    -7,   -24,    -6,   -46,  -528,  -528,  -528,
    -528,  -528,   260,   229,  -422,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,   281,  -108,  -214,   294,  -528,   307,  -528,
    -193,  -168,   632,  -190,  -528,   -55,    16,   298,  -528,  -302,
    -188,  -263,  -181,  -528,   -25,  -492,  -528,  -528,  -312,  -528,
    -130,  -528,   394,  -528,   166,   112,   167,    93,    37,    40,
    -440,  -528,  -527,   101,  -528,   250,  -528,  -528
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    20,    87,    21,    90,   317,
     202,    55,   303,    57,   137,   465,   466,   133,   134,    58,
     355,   304,   356,   448,   242,   217,   110,   111,   112,    59,
     120,    60,   438,   342,   439,    61,    62,    63,    64,    65,
      66,   293,   391,   392,   532,    67,   295,   222,   124,    68,
     138,    93,    99,     8,    70,    71,   224,   225,   151,   101,
      72,    73,   428,   208,    74,   210,   211,    75,    76,    77,
     117,   412,    78,   231,   434,    79,    80,    15,   259,   467,
     255,   247,   238,   248,   249,   250,   240,   348,   226,   227,
     228,   309,   306,   310,   251,   140,    82,   296,   393,   394,
     200,   338,   159,   128,   121,   563,   594,   588,   364,   324,
     410,   416,   630,   540,   498,   499,   500,   502,   595,   590,
     631,   632,   553,   554,   203,   564,   596,   591
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,   131,   163,   103,   232,   153,   405,   114,   150,   300,
     254,   325,    22,   512,    69,   258,   239,    22,   162,    86,
     102,   104,   308,   305,   599,    94,   330,   152,    94,   358,
     360,   555,   116,   397,    94,   109,   340,    83,   513,   109,
     341,     9,   135,   139,   404,   109,   450,    17,   113,   549,
     350,   584,   122,   345,   456,   127,   139,    92,     1,   362,
      92,    11,    12,   345,   395,   107,   119,   369,     4,   118,
       4,   371,   209,   209,   209,   141,   142,   143,   144,   145,
     146,   386,   155,   156,   123,   302,    84,    17,   357,   352,
     352,   209,   359,   571,   353,   353,   550,   641,   406,   194,
     556,   209,   153,    18,   407,   551,   163,    19,     4,   209,
      16,   516,   402,    17,   223,    13,   209,     5,     6,     5,
       6,   130,   269,    94,   152,   636,   196,   346,   396,    94,
     474,   135,   476,   122,     4,   139,   642,   643,    23,   209,
     523,   560,   153,   449,    85,   451,   549,    19,   411,    88,
     354,   457,     4,   193,   442,   237,   561,     5,     6,   195,
     139,   246,   525,     6,   152,   123,  -222,     4,   536,   529,
     218,   517,   518,    19,   537,    89,   635,   141,   145,   406,
     209,   519,   209,     5,     6,   421,   197,   633,   298,   413,
      69,   415,   417,   550,    69,   333,   198,   209,    22,   209,
     314,     5,     6,   223,   648,   209,   649,    91,   343,   574,
     575,   464,   311,   312,   329,    69,     5,     6,   471,  -201,
     481,   129,   125,   109,   160,  -222,   344,   209,   223,    69,
     219,  -222,     4,   510,   311,   312,   109,   187,   485,   379,
     198,   239,   209,   209,   406,  -139,   458,   605,     4,   460,
     436,   153,   192,  -201,   399,     4,   378,   380,   520,  -252,
     139,  -251,   191,   199,  -252,   406,  -251,   115,   188,    25,
    -168,   482,   189,   152,    27,  -169,   372,  -167,   613,   527,
     190,     5,     6,    95,   253,  -201,   387,   105,    37,    38,
       4,   257,   627,   432,  -167,    41,   201,     5,     6,  -168,
     204,    69,   209,   216,     5,     6,   153,  -169,   108,   639,
    -165,   154,   108,   209,  -252,   430,  -251,  -163,   569,   215,
    -252,   220,  -251,   209,   229,    51,   198,   209,   152,     4,
     468,   230,   429,   431,  -165,   233,   223,    54,   427,     5,
       6,  -163,  -165,   440,   252,   265,   223,   315,    94,  -163,
     153,   209,   209,   477,   318,   581,   212,   212,   212,   580,
      94,   266,   319,   267,    94,   268,   320,   135,   316,   139,
     328,   326,   152,   432,   337,   212,   321,   322,     5,     6,
     237,   339,   234,   345,   139,   212,   234,   347,   349,   432,
     462,   351,   246,   212,   361,   430,   455,   368,   363,   509,
     212,   370,   209,   374,   470,    69,     4,   382,   154,   323,
     501,   430,   429,   431,   385,   243,   388,   235,  -164,   401,
       6,   244,   408,   212,   414,   223,   236,   109,   429,   431,
     245,     5,     6,   418,   419,     5,     6,    27,   420,   424,
     221,   132,  -164,  -162,   209,   435,    95,    69,   154,     4,
    -164,    37,    38,     4,   610,     5,     6,   234,    41,   437,
     344,   441,   447,   452,   212,   205,   212,  -162,   473,   432,
       4,   468,   570,   153,   444,  -162,   477,   454,   100,     4,
     459,   212,    97,   212,   136,   475,   243,   209,   206,   212,
     461,   430,   244,   552,   469,   152,   403,   478,     5,     6,
      54,   479,     5,     6,   501,   161,     5,     6,   429,   431,
     223,   212,  -166,   480,   297,   484,   109,   483,   505,     5,
       6,   506,   511,   381,   515,   139,   212,   212,     5,     6,
     234,   521,   522,   524,   535,   543,  -166,   526,   545,   547,
     562,   568,   501,   586,  -166,   593,   544,   100,   100,   100,
     552,   546,   207,   213,   214,   557,   552,   154,   565,   606,
     501,   566,   567,   432,   406,   235,   100,   578,   492,   576,
     598,   579,   600,   166,   608,   609,   100,   601,  -143,     5,
       6,   241,   615,   174,   100,   430,   212,   178,   561,   256,
     616,   100,   183,   184,   185,   186,   262,   212,   614,   433,
     617,  -144,   429,   431,   618,   619,   620,   212,   622,   623,
     624,   212,   154,   626,   100,   628,   501,   634,   586,   271,
     644,    56,   593,   552,   645,   646,   647,   501,   501,   577,
     533,   514,   367,   534,   335,   212,   212,   373,   106,   336,
     264,   504,   453,   443,   425,   409,   409,    81,   409,   409,
     446,   583,   541,   542,   607,   100,   154,   100,   603,   637,
     640,   503,   327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   100,    27,     0,   334,     0,   433,
     100,     0,     0,     0,    95,    27,   212,     0,     0,    37,
      38,     4,     0,     0,    95,   433,    41,     0,     0,    37,
      38,     4,   100,   205,     0,     0,    41,   366,     0,   126,
       0,     0,     0,    96,   100,     0,     0,   100,   100,   377,
      97,   149,   383,   384,   158,     0,   206,     0,   212,     0,
      97,     0,   260,     0,     0,     0,    98,   496,    54,     0,
       5,     6,   261,   496,   496,     0,     0,     0,    54,     0,
       5,     6,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    37,    38,     4,     0,
       0,   212,     0,    41,     0,   433,     0,   100,     0,   154,
     205,     0,   377,     0,     0,     0,     0,     0,   100,     0,
     100,     0,     0,     0,     0,     0,     0,    97,   100,     0,
       0,     0,   100,   206,   497,     0,     0,   445,     0,   270,
     507,   508,     0,   496,     0,    54,     0,     5,     6,   261,
     496,     0,     0,     0,     0,     0,   100,   100,   496,     0,
       0,   207,   463,     0,   272,   273,   274,   275,     0,   276,
     277,   278,     0,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,     0,   149,     0,
     299,     0,   307,     0,     0,   496,   126,   126,   313,   433,
     100,   587,   496,     0,   496,     0,     0,   100,     0,     0,
       0,     0,   486,   496,     0,   496,   100,   548,   126,   126,
       0,   487,     0,     0,     0,   559,   488,   489,   490,     0,
       0,     0,     0,   491,     0,     0,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     496,     0,     0,     0,   528,     0,     0,   493,   496,     0,
     126,     0,   582,   539,     0,   496,     0,     0,   589,   592,
     126,   597,     0,   496,   486,   495,   587,   496,     6,     0,
     602,     0,   604,   487,     0,     0,     0,     0,   488,   489,
     585,     0,   100,   390,     0,   491,   100,   149,     0,     0,
       0,   496,   492,   496,     0,     0,     0,     0,   390,     0,
       0,     0,     0,     0,     0,     0,     0,   621,     0,   493,
       0,     0,     0,     0,     0,   625,     0,     0,     0,     0,
       0,   422,   423,     0,     0,     0,     0,   495,     0,     5,
       6,     0,     0,   589,   638,     0,     0,     0,     0,     0,
       0,     0,   149,    -2,    24,     0,    25,     0,     0,    26,
       0,    27,    28,    29,     0,     0,    30,     0,    31,    32,
      33,    34,    35,    36,   126,    37,    38,     4,     0,     0,
      39,    40,    41,    42,    43,    44,     0,     0,   126,    45,
     100,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,   158,    46,    47,     0,    48,    49,     0,     0,    50,
       0,     0,    51,     0,     0,   -20,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     5,     6,   301,     0,
      25,     0,     0,    26,  -237,    27,    28,    29,     0,  -237,
      30,     0,    31,    32,    95,    34,    35,    36,     0,    37,
      38,     4,     0,     0,    39,    40,    41,    42,    43,    44,
       0,     0,     0,    45,   390,     0,     0,     0,     0,     0,
       0,   390,   531,   390,     0,     0,    46,    47,     0,    48,
      49,     0,     0,    50,     0,     0,    51,     0,     0,  -237,
       0,     0,   166,     0,   302,  -237,    52,    53,    54,     0,
       5,     6,   174,     0,     0,     0,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   572,   573,     0,   149,
       0,     0,     0,   301,     0,    25,     0,     0,    26,     0,
      27,    28,    29,     0,     0,    30,   158,    31,    32,    95,
      34,    35,    36,     0,    37,    38,     4,     0,     0,    39,
      40,    41,    42,    43,    44,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,  -261,
       0,    46,    47,     0,    48,    49,     0,     0,    50,     0,
     390,    51,     0,     0,  -237,     0,     0,     0,     0,   302,
    -237,    52,    53,    54,     0,     5,     6,   165,   166,     0,
     167,   168,   169,   170,   171,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,    25,     0,     0,     0,     0,    27,     0,  -261,
     157,    27,     0,     0,     0,     0,    95,     0,     0,  -261,
      95,    37,    38,     4,     0,    37,    38,     4,    41,     0,
       0,     0,    41,     0,     0,    45,     0,     0,     0,   205,
       0,     0,     0,     0,     0,    25,     0,     0,    46,    47,
      27,    48,    49,     0,     0,    50,    97,     0,    51,    95,
       0,     0,   206,     0,    37,    38,     4,     0,    52,    53,
      54,    41,     5,     6,    54,     0,     5,     6,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,    48,   148,     0,     0,    50,     0,
      25,    51,   294,     0,     0,    27,     0,     0,     0,     0,
       0,    52,    53,    54,    95,     5,     6,     0,     0,    37,
      38,     4,     0,   331,     0,     0,    41,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,    48,
      49,     0,     0,    50,     0,    25,    51,     0,     0,     0,
      27,     0,     0,     0,     0,     0,    52,    53,    54,    95,
       5,     6,     0,     0,    37,    38,     4,     0,   332,     0,
       0,    41,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,    46,    47,    27,    48,    49,     0,     0,    50,     0,
       0,    51,    95,     0,     0,     0,     0,    37,    38,     4,
       0,    52,    53,    54,    41,     5,     6,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,     0,    48,    49,     0,
       0,    50,     0,    25,    51,     0,     0,     0,    27,     0,
       0,     0,   389,     0,    52,    53,    54,    95,     5,     6,
       0,     0,    37,    38,     4,     0,     0,     0,     0,    41,
       0,   398,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,    46,
      47,    27,    48,   148,     0,     0,    50,     0,     0,    51,
      95,     0,     0,     0,     0,    37,    38,     4,     0,    52,
      53,    54,    41,     5,     6,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,     0,    48,    49,     0,     0,    50,
       0,    25,    51,     0,     0,     0,    27,     0,     0,     0,
     530,     0,    52,    53,    54,    95,     5,     6,     0,     0,
      37,    38,     4,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    46,    47,    27,
      48,    49,     0,     0,    50,     0,     0,    51,    95,     0,
       0,     0,     0,    37,    38,     4,     0,    52,    53,    54,
      41,     5,     6,     0,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
      46,    47,   263,    48,   148,     0,     0,    50,     0,     0,
      51,    95,     0,     0,     0,     0,    37,    38,     4,     0,
      52,    53,    54,    41,     5,     6,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,    27,    48,    49,     0,     0,
      50,     0,     0,    51,    95,     0,     0,     0,     0,    37,
      38,     4,     0,    52,    53,    54,    41,     5,     6,     0,
      27,     0,     0,   205,     0,     0,     0,     0,    27,    95,
       0,     0,     0,     0,    37,    38,     4,    95,     0,     0,
      97,    41,    37,    38,     4,     0,   206,     0,   375,    41,
       0,     0,     0,     0,   263,     0,   205,     0,    54,     0,
       5,     6,   365,    95,     0,    97,     0,     0,    37,    38,
       4,   376,     0,    97,     0,    41,     0,     0,     0,   426,
       0,   486,   205,    54,     0,     5,     6,     0,     0,     0,
     487,    54,     0,     5,     6,   488,   489,   490,     0,    97,
       0,     0,   491,     0,     0,   206,     0,   486,     0,   492,
     558,     0,     0,     0,     0,   486,   487,    54,     0,     5,
       6,   488,   489,   490,   487,     0,   493,     0,   491,   488,
     489,   490,     0,     0,     0,   492,   491,     0,   494,     0,
     486,     0,     0,   492,   495,     0,     0,     6,     0,   487,
       0,     0,   493,     0,   488,   489,   490,     0,     0,     0,
     493,   491,     0,     0,     0,     0,   629,     0,   492,     0,
     495,     0,     0,     6,     0,     0,     0,     0,   495,     0,
       0,     6,     0,     0,     0,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   165,   166,     6,   167,     0,   169,
     170,   171,     0,     0,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,     0,
     167,     0,   169,   170,   171,     0,   403,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,     0,     0,     0,     0,     0,   165,   166,     0,
     167,     0,   169,   170,   171,     0,   400,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   165,   166,     0,   167,     0,   169,   170,   171,     0,
     472,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   165,   166,     0,   167,     0,
     169,   170,   171,     0,   611,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   165,
     166,     0,   167,     0,   169,   170,   171,     0,   612,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   165,   166,     0,     0,     0,   169,   170,
     171,     0,     0,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   165,   166,     0,
       0,     0,   169,   170,   171,     0,     0,   173,   174,   175,
     176,     0,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   166,     0,     0,     0,   169,   170,   171,     0,     0,
     173,   174,   175,   176,     0,   178,   179,   180,   181,   182,
     183,   184,   185,   186
};

static const yytype_int16 yycheck[] =
{
       1,    42,    57,    27,   120,    51,   308,    32,    51,   190,
     132,   204,    13,   435,    15,   136,   124,    18,    57,    18,
      27,    27,   193,   191,   551,    26,   216,    51,    29,   243,
     244,     3,    33,   296,    35,    32,   229,    24,    20,    36,
     230,     0,    43,    44,   307,    42,   358,     3,    32,     3,
     238,   543,    35,    24,   366,    39,    57,    26,    25,   247,
      29,     3,    62,    24,    11,    30,    35,   255,    24,    34,
      24,   259,    96,    97,    98,    45,    46,    47,    48,    49,
      50,   269,    52,    53,    67,    67,    73,     3,    59,     7,
       7,   115,    53,   515,    12,    12,    50,   624,    62,     1,
      72,   125,   148,    59,    68,    59,   161,    63,    24,   133,
      63,     5,   302,     3,   115,    21,   140,    73,    74,    73,
      74,    41,   161,   124,   148,   617,     5,   235,    75,   130,
     393,   132,   395,    35,    24,   136,   628,   629,    62,   163,
     452,    60,   188,   357,    60,   359,     3,    63,    59,     3,
      68,    68,    24,    73,   347,   124,    75,    73,    74,    79,
     161,   130,   464,    74,   188,    67,     3,    24,    66,   471,
       5,    65,    66,    63,    72,    25,   616,   147,   148,    62,
     204,    75,   206,    73,    74,    68,    65,   609,   189,   319,
     191,   321,   322,    50,   195,   220,    75,   221,   199,   223,
     199,    73,    74,   204,   644,   229,   646,     3,   233,   521,
     522,   382,   196,   197,   215,   216,    73,    74,   389,     1,
     401,    35,    71,   220,    62,    62,    63,   251,   229,   230,
      65,    68,    24,   426,   218,   219,   233,    67,   406,   263,
      75,   349,   266,   267,    62,    66,   368,   559,    24,   370,
      68,   297,    59,    35,   297,    24,   263,   263,   448,     7,
     261,     7,    66,    62,    12,    62,    12,    59,    59,     3,
      59,    68,    63,   297,     8,    35,   260,    59,   580,   467,
      71,    73,    74,    17,    60,    67,   270,    27,    22,    23,
      24,    60,   604,   339,    59,    29,    24,    73,    74,    59,
      59,   302,   326,    35,    73,    74,   352,    67,    30,   621,
      35,    51,    34,   337,    62,   339,    62,    35,   511,    63,
      68,    62,    68,   347,    59,    59,    75,   351,   352,    24,
     385,    67,   339,   339,    59,    62,   337,    71,   339,    73,
      74,    59,    67,   344,    35,    60,   347,    60,   349,    67,
     396,   375,   376,   396,     9,   536,    96,    97,    98,   530,
     361,    72,    17,    72,   365,    60,    21,   368,    24,   370,
      60,     8,   396,   419,    75,   115,    31,    32,    73,    74,
     349,    60,    24,    24,   385,   125,    24,    59,    62,   435,
     374,    72,   361,   133,    62,   419,   365,    62,     3,   424,
     140,    62,   426,    65,   388,   406,    24,    67,   148,    64,
     411,   435,   419,   419,    62,    53,    65,    59,    35,    66,
      74,    59,    62,   163,    24,   426,    68,   424,   435,   435,
      68,    73,    74,    64,    60,    73,    74,     8,    60,    62,
      11,    59,    59,    35,   468,    60,    17,   448,   188,    24,
      67,    22,    23,    24,   570,    73,    74,    24,    29,    14,
      63,    60,    66,    60,   204,    36,   206,    59,    75,   515,
      24,   526,   513,   519,    68,    67,   519,    68,    27,    24,
      60,   221,    53,   223,    59,    68,    53,   511,    59,   229,
      60,   515,    59,   494,    60,   519,    75,    60,    73,    74,
      71,    60,    73,    74,   505,    59,    73,    74,   515,   515,
     511,   251,    35,    60,    59,    68,   513,    60,    59,    73,
      74,     3,    59,   263,    60,   526,   266,   267,    73,    74,
      24,    60,    60,    60,    60,    59,    59,    62,    71,     8,
      62,    60,   543,   544,    67,   546,    67,    96,    97,    98,
     551,    67,    96,    97,    98,    65,   557,   297,    62,   560,
     561,    62,    62,   609,    62,    59,   115,    60,    36,    68,
       3,    68,    62,    34,    60,    60,   125,    72,    59,    73,
      74,   125,    60,    44,   133,   609,   326,    48,    75,   133,
      60,   140,    53,    54,    55,    56,   140,   337,    72,   339,
      59,    59,   609,   609,    68,    62,    72,   347,    68,    62,
      49,   351,   352,    62,   163,    59,   617,    68,   619,   163,
      60,    15,   623,   624,    60,    60,    60,   628,   629,   526,
     473,   437,   252,   473,   223,   375,   376,   261,    29,   223,
     148,   412,   361,   349,   337,   318,   319,    15,   321,   322,
     352,   539,   486,   486,   561,   204,   396,   206,   557,   619,
     623,   411,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,    -1,   223,     8,    -1,   221,    -1,   419,
     229,    -1,    -1,    -1,    17,     8,   426,    -1,    -1,    22,
      23,    24,    -1,    -1,    17,   435,    29,    -1,    -1,    22,
      23,    24,   251,    36,    -1,    -1,    29,   251,    -1,    39,
      -1,    -1,    -1,    36,   263,    -1,    -1,   266,   267,   263,
      53,    51,   266,   267,    54,    -1,    59,    -1,   468,    -1,
      53,    -1,    65,    -1,    -1,    -1,    59,   410,    71,    -1,
      73,    74,    75,   416,   417,    -1,    -1,    -1,    71,    -1,
      73,    74,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,   511,    -1,    29,    -1,   515,    -1,   326,    -1,   519,
      36,    -1,   326,    -1,    -1,    -1,    -1,    -1,   337,    -1,
     339,    -1,    -1,    -1,    -1,    -1,    -1,    53,   347,    -1,
      -1,    -1,   351,    59,   410,    -1,    -1,   351,    -1,    65,
     416,   417,    -1,   486,    -1,    71,    -1,    73,    74,    75,
     493,    -1,    -1,    -1,    -1,    -1,   375,   376,   501,    -1,
      -1,   375,   376,    -1,   164,   165,   166,   167,    -1,   169,
     170,   171,    -1,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,    -1,
     190,    -1,   192,    -1,    -1,   538,   196,   197,   198,   609,
     419,   544,   545,    -1,   547,    -1,    -1,   426,    -1,    -1,
      -1,    -1,     8,   556,    -1,   558,   435,   493,   218,   219,
      -1,    17,    -1,    -1,    -1,   501,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
     593,    -1,    -1,    -1,   468,    -1,    -1,    53,   601,    -1,
     260,    -1,   538,    59,    -1,   608,    -1,    -1,   544,   545,
     270,   547,    -1,   616,     8,    71,   619,   620,    74,    -1,
     556,    -1,   558,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,   511,   293,    -1,    29,   515,   297,    -1,    -1,
      -1,   644,    36,   646,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,    53,
      -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,    -1,    -1,
      -1,   331,   332,    -1,    -1,    -1,    -1,    71,    -1,    73,
      74,    -1,    -1,   619,   620,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   352,     0,     1,    -1,     3,    -1,    -1,     6,
      -1,     8,     9,    10,    -1,    -1,    13,    -1,    15,    16,
      17,    18,    19,    20,   374,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,   388,    36,
     609,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,   401,    49,    50,    -1,    52,    53,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    -1,    73,    74,     1,    -1,
       3,    -1,    -1,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,   464,    -1,    -1,    -1,    -1,    -1,
      -1,   471,   472,   473,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,
      -1,    -1,    34,    -1,    67,    68,    69,    70,    71,    -1,
      73,    74,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,   516,   517,    -1,   519,
      -1,    -1,    -1,     1,    -1,     3,    -1,    -1,     6,    -1,
       8,     9,    10,    -1,    -1,    13,   536,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    49,    50,    -1,    52,    53,    -1,    -1,    56,    -1,
     580,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    -1,    73,    74,    33,    34,    -1,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    65,
      11,     8,    -1,    -1,    -1,    -1,    17,    -1,    -1,    75,
      17,    22,    23,    24,    -1,    22,    23,    24,    29,    -1,
      -1,    -1,    29,    -1,    -1,    36,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    49,    50,
       8,    52,    53,    -1,    -1,    56,    53,    -1,    59,    17,
      -1,    -1,    59,    -1,    22,    23,    24,    -1,    69,    70,
      71,    29,    73,    74,    71,    -1,    73,    74,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    52,    53,    -1,    -1,    56,    -1,
       3,    59,    60,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    17,    73,    74,    -1,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    52,
      53,    -1,    -1,    56,    -1,     3,    59,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    17,
      73,    74,    -1,    -1,    22,    23,    24,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    49,    50,     8,    52,    53,    -1,    -1,    56,    -1,
      -1,    59,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    69,    70,    71,    29,    73,    74,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    52,    53,    -1,
      -1,    56,    -1,     3,    59,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    17,    73,    74,
      -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      -1,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    49,
      50,     8,    52,    53,    -1,    -1,    56,    -1,    -1,    59,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    69,
      70,    71,    29,    73,    74,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    52,    53,    -1,    -1,    56,
      -1,     3,    59,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    17,    73,    74,    -1,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    49,    50,     8,
      52,    53,    -1,    -1,    56,    -1,    -1,    59,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    69,    70,    71,
      29,    73,    74,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      49,    50,     8,    52,    53,    -1,    -1,    56,    -1,    -1,
      59,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      69,    70,    71,    29,    73,    74,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,     8,    52,    53,    -1,    -1,
      56,    -1,    -1,    59,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    69,    70,    71,    29,    73,    74,    -1,
       8,    -1,    -1,    36,    -1,    -1,    -1,    -1,     8,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    17,    -1,    -1,
      53,    29,    22,    23,    24,    -1,    59,    -1,    36,    29,
      -1,    -1,    -1,    -1,     8,    -1,    36,    -1,    71,    -1,
      73,    74,    75,    17,    -1,    53,    -1,    -1,    22,    23,
      24,    59,    -1,    53,    -1,    29,    -1,    -1,    -1,    59,
      -1,     8,    36,    71,    -1,    73,    74,    -1,    -1,    -1,
      17,    71,    -1,    73,    74,    22,    23,    24,    -1,    53,
      -1,    -1,    29,    -1,    -1,    59,    -1,     8,    -1,    36,
      11,    -1,    -1,    -1,    -1,     8,    17,    71,    -1,    73,
      74,    22,    23,    24,    17,    -1,    53,    -1,    29,    22,
      23,    24,    -1,    -1,    -1,    36,    29,    -1,    65,    -1,
       8,    -1,    -1,    36,    71,    -1,    -1,    74,    -1,    17,
      -1,    -1,    53,    -1,    22,    23,    24,    -1,    -1,    -1,
      53,    29,    -1,    -1,    -1,    -1,    59,    -1,    36,    -1,
      71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    33,    34,    74,    36,    -1,    38,
      39,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    -1,    75,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    -1,    72,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    33,    34,    -1,    36,    -1,    38,    39,    40,    -1,
      66,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    33,    34,    -1,    36,    -1,
      38,    39,    40,    -1,    66,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    33,
      34,    -1,    36,    -1,    38,    39,    40,    -1,    66,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    77,    78,    24,    73,    74,   128,   129,     0,
      79,     3,    62,    21,    80,   153,    63,     3,    59,    63,
      81,    83,   128,    62,     1,     3,     6,     8,     9,    10,
      13,    15,    16,    17,    18,    19,    20,    22,    23,    27,
      28,    29,    30,    31,    32,    36,    49,    50,    52,    53,
      56,    59,    69,    70,    71,    87,    88,    89,    95,   105,
     107,   111,   112,   113,   114,   115,   116,   121,   125,   128,
     130,   131,   136,   137,   140,   143,   144,   145,   148,   151,
     152,   168,   172,    24,    73,    60,    81,    82,     3,    25,
      84,     3,   125,   127,   128,    17,    36,    53,    59,   128,
     130,   135,   139,   140,   141,   148,   127,   115,   121,    95,
     102,   103,   104,   172,   180,    59,   128,   146,   115,   125,
     106,   180,    35,    67,   124,    71,   113,   172,   179,    35,
     124,   106,    59,    93,    94,   128,    59,    90,   126,   128,
     171,   114,   114,   114,   114,   114,   114,    36,    53,   113,
     122,   134,   140,   142,   148,   114,   114,    11,   113,   178,
      62,    59,    91,   171,     4,    33,    34,    36,    37,    38,
      39,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    67,    59,    63,
      71,    66,    59,   124,     1,   124,     5,    65,    75,    62,
     176,    24,    86,   200,    59,    36,    59,   133,   139,   140,
     141,   142,   148,   133,   133,    63,    35,   101,     5,    65,
      62,    11,   123,   128,   132,   133,   164,   165,   166,    59,
      67,   149,   101,    62,    24,    59,    68,   125,   158,   160,
     162,   133,   100,    53,    59,    68,   125,   157,   159,   160,
     161,   170,    35,    60,    94,   156,   133,    60,    90,   154,
      65,    75,   133,     8,   134,    60,    72,    72,    60,    91,
      65,   133,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   117,    60,   122,   173,    59,   128,   113,
     178,     1,    67,    88,    97,   167,   168,   113,   117,   167,
     169,   172,   172,   113,    81,    60,    24,    85,     9,    17,
      21,    31,    32,    64,   185,   166,     8,   133,    60,   128,
     169,    26,    26,   180,   133,   123,   132,    75,   177,    60,
     166,   169,   109,   180,    63,    24,   160,    59,   163,    62,
     176,    72,     7,    12,    68,    96,    98,    59,   161,    53,
     161,    62,   176,     3,   184,    75,   133,   100,    62,   176,
      62,   176,   172,   126,    65,    36,    59,   133,   139,   140,
     141,   148,    67,   133,   133,    62,   176,   172,    65,    67,
     113,   118,   119,   174,   175,    11,    75,   177,    31,   122,
      72,    66,   169,    75,   177,   175,    62,    68,    62,   129,
     186,    59,   147,   186,    24,   186,   187,   186,    64,    60,
      60,    68,   113,   113,    62,   164,    59,   128,   138,   139,
     140,   141,   142,   148,   150,    60,    68,    14,   108,   110,
     128,    60,   166,   162,    68,   133,   173,    66,    99,   161,
     184,   161,    60,   159,    68,   125,   184,    68,    94,    60,
      90,    60,   172,   133,   117,    91,    92,   155,   171,    60,
     172,   117,    66,    75,   177,    68,   177,   122,    60,    60,
      60,   178,    68,    60,    68,   167,     8,    17,    22,    23,
      24,    29,    36,    53,    65,    71,   129,   188,   190,   191,
     192,   128,   193,   201,   149,    59,     3,   188,   188,   180,
     166,    59,   150,    20,    97,    60,     5,    65,    66,    75,
     169,    60,    60,   184,    60,   175,    62,   176,   133,   175,
      67,   113,   120,   118,   119,    60,    66,    72,    36,    59,
     189,   190,   192,    59,    67,    71,    67,     8,   188,     3,
      50,    59,   128,   198,   199,     3,    72,    65,    11,   188,
      60,    75,    62,   181,   201,    62,    62,    62,    60,   166,
     106,   150,   113,   113,   184,   184,    68,    92,    60,    68,
     117,   178,   188,   191,   181,    24,   128,   129,   183,   188,
     195,   203,   188,   128,   182,   194,   202,   188,     3,   198,
      62,    72,   188,   199,   188,   184,   128,   193,    60,    60,
     101,    66,    66,   175,    72,    60,    60,    59,    68,    62,
      72,   188,    68,    62,    49,   188,    62,   184,    59,    59,
     188,   196,   197,   150,    68,   196,   181,   195,   188,   184,
     194,   198,   181,   181,    60,    60,    60,    60,   196,   196
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    82,    82,    83,    83,    83,    84,    85,    85,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    90,    91,
      91,    92,    92,    92,    93,    94,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    97,    99,    98,   100,
     100,   101,   102,   102,   103,   103,   103,   104,   105,   106,
     106,   107,   108,   109,   109,   110,   110,   111,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   115,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   124,   124,   125,
     126,   127,   127,   128,   128,   128,   129,   129,   130,   131,
     132,   132,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   134,   135,   135,   135,   135,   135,   136,   136,   137,
     138,   138,   138,   138,   138,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   141,   142,   143,   143,   144,   144,
     145,   146,   146,   147,   147,   148,   149,   149,   150,   150,
     150,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     159,   159,   160,   160,   161,   162,   162,   162,   163,   164,
     164,   164,   164,   165,   165,   166,   166,   167,   167,   167,
     167,   167,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   185,   185,   185,   185,   186,   187,   188,   188,   188,
     189,   189,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   191,   192,   193,   193,   194,   195,   195,
     196,   196,   197,   197,   198,   198,   198,   199,   199,   200,
     200,   201,   201,   202,   202,   203,   203
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     3,     0,     3,     2,     5,     3,
       3,     1,     3,     1,     2,     2,     4,     0,     1,     3,
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
       3,     5,     8,     5,     8,     5,     0,     3,     0,     1,
       3,     1,     4,     2,     0,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     2,     4,     3,
       5,     5,     1,     3,     1,     2,     1,     3,     4,     1,
       2,     2,     1,     1,     3,     0,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     3,     0,
       2,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     4,
       4,     5,     6,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     5,     4,     4,     2,
       2,     4,     3,     3,     5,     3,     4,     3,     5,     1,
       0,     1,     3,     1,     1,     2,     1,     1,     5,     0,
       2,     1,     3,     1,     3,     1,     3
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
        case 3:
#line 157 "go.y" /* yacc.c:1646  */
    {
		yyerror("package statement must be first");
		exit(1);
	}
#line 2094 "go.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 203 "go.y" /* yacc.c:1646  */
    {
		yyerror("empty top-level declaration");
		// $$ = nil;
	}
#line 2103 "go.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 210 "go.y" /* yacc.c:1646  */
    {
		yyerror("non-declaration statement outside function body");
		// $$ = nil;
	}
#line 2112 "go.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 215 "go.y" /* yacc.c:1646  */
    {
		// $$ = nil;
	}
#line 2120 "go.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 256 "go.y" /* yacc.c:1646  */
    {
		// the name becomes visible right here, not at the end
		// of the declaration.
	}
#line 2129 "go.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 289 "go.y" /* yacc.c:1646  */
    {
		// If the last token read by the lexer was consumed
		// as part of the case, clear it (parser has cleared yychar).
		// If the last token read by the lexer was the lookahead
		// leave it alone (parser has it cached in yychar).
		// This is so that the stmt_list action doesn't look at
		// the case tokens if the stmt_list is empty.
		yylast = yychar;
	}
#line 2143 "go.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 299 "go.y" /* yacc.c:1646  */
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
	}
#line 2163 "go.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 417 "go.y" /* yacc.c:1646  */
    {
		yyerror("the bitwise complement operator is ^");
	}
#line 2171 "go.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 448 "go.y" /* yacc.c:1646  */
    {
		yyerror("cannot parenthesize type in composite literal");
	}
#line 2179 "go.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 454 "go.y" /* yacc.c:1646  */
    {
		// composite expression.
		// make node early so we get the right line number.
	}
#line 2188 "go.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 538 "go.y" /* yacc.c:1646  */
    {
		yyerror("final argument in variadic function missing type");
	}
#line 2196 "go.tab.c" /* yacc.c:1646  */
    break;


#line 2200 "go.tab.c" /* yacc.c:1646  */
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
#line 958 "go.y" /* yacc.c:1906  */

