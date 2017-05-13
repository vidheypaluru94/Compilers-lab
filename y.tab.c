/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "stage10.y" /* yacc.c:339  */

	#include<stdio.h>
	#include<stdlib.h>
	#include "lex.yy.c"
	#include "sym_table.h"
	#include "exprtree.h"

	#define ID_ARRAY 1003
	int evaluate(struct tree_node *);
	void typecheck(struct tree_node *root,struct tree_node *,struct tree_node *,struct tree_node *);
	int vartype;
	int argtype;
	extern struct Argstruct *Arg_List;
	int line_count = 0;
	extern int sp;
	extern int Arg_bind;
	int getbind(char *name);

	int free_reg=-1;
	extern int start_addr;
	int evaluate(struct tree_node *);
	void freereg(int);
	int getreg();
	int codegen(struct tree_node *,FILE *);
	void Argcheck(int type, char *name, struct Argstruct *Arglist);
	FILE *outfile;

#line 94 "y.tab.c" /* yacc.c:339  */

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
    VARLIST = 258,
    FUNCT = 259,
    VALUE = 260,
    REFERENCE = 261,
    ID_REF = 262,
    ID_ARRAY_REF = 263,
    MAIN = 264,
    BODY = 265,
    BEG = 266,
    RETURN = 267,
    END = 268,
    NUM = 269,
    ID = 270,
    WRITE = 271,
    READ = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    BOOLEAN = 280,
    INTEGER = 281,
    VOID = 282,
    DECL = 283,
    ENDDECL = 284,
    TRUE = 285,
    FALSE = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    LT = 290,
    LE = 291,
    GT = 292,
    GE = 293,
    EQ = 294,
    NE = 295
  };
#endif
/* Tokens.  */
#define VARLIST 258
#define FUNCT 259
#define VALUE 260
#define REFERENCE 261
#define ID_REF 262
#define ID_ARRAY_REF 263
#define MAIN 264
#define BODY 265
#define BEG 266
#define RETURN 267
#define END 268
#define NUM 269
#define ID 270
#define WRITE 271
#define READ 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BOOLEAN 280
#define INTEGER 281
#define VOID 282
#define DECL 283
#define ENDDECL 284
#define TRUE 285
#define FALSE 286
#define AND 287
#define OR 288
#define NOT 289
#define LT 290
#define LE 291
#define GT 292
#define GE 293
#define EQ 294
#define NE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "stage10.y" /* yacc.c:355  */

	int val;
	char* identifier;
	struct tree_node *ptr;

#line 220 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,    52,     2,
      50,    51,    45,    43,    42,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   110,   113,   114,   117,   120,   121,   124,
     125,   128,   129,   130,   133,   134,   135,   138,   141,   142,
     145,   146,   149,   150,   155,   156,   159,   207,   209,   210,
     213,   216,   217,   220,   223,   248,   251,   252,   255,   256,
     257,   258,   261,   264,   265,   268,   269,   272,   275,   277,
     278,   279,   280,   281,   283,   285,   287,   288,   289,   290,
     291,   292,   294,   295,   296,   298,   299,   301,   302,   305,
     307,   313,   315,   322,   325,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VARLIST", "FUNCT", "VALUE", "REFERENCE",
  "ID_REF", "ID_ARRAY_REF", "MAIN", "BODY", "BEG", "RETURN", "END", "NUM",
  "ID", "WRITE", "READ", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BOOLEAN", "INTEGER", "VOID", "DECL", "ENDDECL", "TRUE",
  "FALSE", "AND", "OR", "NOT", "LT", "LE", "GT", "GE", "EQ", "NE", "'%'",
  "','", "'+'", "'-'", "'*'", "'/'", "';'", "'['", "']'", "'('", "')'",
  "'&'", "'{'", "'}'", "'='", "$accept", "prog", "GDefblock", "GDeflist",
  "Gdecl", "Type", "GIDlist", "GId", "ArgDeflist", "Argdecl", "ArgType",
  "ArgList", "ArgId", "FdefList", "Fdef", "LDefblock", "LDeflist", "Ldecl",
  "LIDlist", "LId", "Mainblock", "Body", "StmtList", "Stmt", "AsgStmt",
  "InOutStmt", "CondStmt", "IterStmt", "RetStmt", "E", "varlist", "var", YY_NULLPTR
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
     295,    37,    44,    43,    45,    42,    47,    59,    91,    93,
      40,    41,    38,   123,   125,    61
};
# endif

#define YYPACT_NINF -132

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,  -132,    50,  -132,     3,  -132,    55,  -132,  -132,  -132,
    -132,    49,    56,    57,  -132,  -132,    47,   -33,  -132,    59,
      60,   108,    79,    49,  -132,    63,    79,    81,  -132,  -132,
      10,  -132,    -3,  -132,    75,    39,  -132,    79,  -132,  -132,
     119,   105,  -132,   114,    95,  -132,  -132,    -3,  -132,   148,
     114,  -132,    44,   262,   110,   148,  -132,   150,  -132,   128,
     131,   132,   143,   158,     5,  -132,  -132,  -132,  -132,  -132,
     161,  -132,   170,  -132,   -16,  -132,    37,    37,   217,    37,
      37,    37,  -132,   227,    37,  -132,   150,  -132,  -132,    53,
    -132,  -132,    37,    37,   151,  -132,    80,   196,   100,   117,
     166,  -132,   182,  -132,    32,   250,   134,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
    -132,   207,   208,   243,   258,  -132,  -132,   217,   198,   -38,
    -132,   250,   250,   256,   256,   256,   256,   256,   256,   213,
     228,   228,   250,   250,  -132,  -132,   262,   262,  -132,    77,
    -132,    38,    61,   217,   198,   262,   235,   236,  -132,   254,
    -132,  -132,   251,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,    25,     0,     1,     0,     8,     7,     3,
       4,     0,     7,     0,    24,     2,    11,     0,    10,     0,
       0,     0,    16,     0,     6,     0,    16,     0,    19,    18,
       0,    15,     0,     9,     0,     0,    12,     0,    13,    22,
       0,    17,    21,     0,     0,    14,    23,     0,    29,     0,
       0,    20,     0,     0,     0,     0,    27,     0,    28,    74,
       0,     0,     0,     0,     0,    37,    38,    41,    39,    40,
       0,    34,     0,    33,     0,    32,     0,     0,     0,     0,
       0,     0,    36,     0,     0,    26,     0,    30,    67,    74,
      65,    66,     0,     0,     0,    68,     0,     0,     0,     0,
       0,    35,     0,    31,    73,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,    48,    42,     0,    71,     0,
      54,    62,    63,    56,    57,    58,    59,    60,    61,    53,
      49,    50,    51,    52,    44,    43,     0,     0,    72,     0,
      55,     0,     0,     0,    69,     0,     0,     0,    70,     0,
      45,    47,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,  -132,    -4,  -132,   274,   273,   263,
    -132,  -132,   255,  -132,  -132,   253,  -132,  -132,  -132,   215,
    -132,   249,  -131,   -63,  -132,  -132,  -132,  -132,  -132,   -74,
    -132,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    11,    17,    18,    30,    31,
      32,    41,    42,     6,    14,    49,    52,    58,    74,    75,
      15,    54,    64,    65,    66,    67,    68,    69,    83,    94,
     129,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    82,    13,    96,   149,    98,    99,   100,     1,    23,
     102,    70,    39,   150,    24,   151,   152,    81,   105,   106,
      59,    60,    61,    62,   159,    97,    86,    63,     7,     8,
     128,    87,     9,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    88,    89,    57,    40,
       5,    88,    89,    59,    60,    61,    62,    37,   155,   156,
      63,    38,    90,    91,    16,    19,    92,    90,    91,     7,
       8,    92,    20,    56,   148,   154,    59,    60,    61,    62,
       7,    12,    93,    63,   127,   157,    37,    93,    82,    82,
      44,    88,    89,    70,    70,    21,    82,    22,    70,    70,
     158,    76,    70,   104,    28,    29,    70,    90,    91,    25,
      26,    92,   107,   108,    34,   109,   110,   111,   112,   113,
     114,   115,    27,   116,   117,   118,   119,    93,    43,   153,
      36,   121,   107,   108,    46,   109,   110,   111,   112,   113,
     114,   115,    48,   116,   117,   118,   119,    47,    50,   107,
     108,   123,   109,   110,   111,   112,   113,   114,   115,    53,
     116,   117,   118,   119,    71,    73,   107,   108,   124,   109,
     110,   111,   112,   113,   114,   115,    76,   116,   117,   118,
     119,    77,    78,   107,   108,   130,   109,   110,   111,   112,
     113,   114,   115,    79,   116,   117,   118,   119,   107,   108,
     120,   109,   110,   111,   112,   113,   114,   115,    80,   116,
     117,   118,   119,   125,   107,   108,    84,   109,   110,   111,
     112,   113,   114,   115,    85,   116,   117,   118,   119,   126,
     107,   108,    59,   109,   110,   111,   112,   113,   114,   115,
     101,   116,   117,   118,   119,   107,   108,   122,   109,   110,
     111,   112,   113,   114,   144,   145,   116,   117,   118,   119,
     107,   108,   146,   109,   110,   111,   112,   113,   114,    59,
      60,    61,    62,   118,   119,   162,    63,    59,    60,    61,
      62,   147,   160,   161,    63,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    33,   163,    35,
      45,   103,    51,    55,    72
};

static const yytype_uint8 yycheck[] =
{
      53,    64,     6,    77,    42,    79,    80,    81,    28,    42,
      84,    64,    15,    51,    47,   146,   147,    12,    92,    93,
      15,    16,    17,    18,   155,    78,    42,    22,    25,    26,
     104,    47,    29,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    14,    15,    52,    52,
       0,    14,    15,    15,    16,    17,    18,    47,    20,    21,
      22,    51,    30,    31,    15,     9,    34,    30,    31,    25,
      26,    34,    15,    29,   127,   149,    15,    16,    17,    18,
      25,    26,    50,    22,    52,    24,    47,    50,   151,   152,
      51,    14,    15,   146,   147,    48,   159,    50,   151,   152,
     153,    48,   155,    50,    25,    26,   159,    30,    31,    50,
      50,    34,    32,    33,    51,    35,    36,    37,    38,    39,
      40,    41,    14,    43,    44,    45,    46,    50,    53,    52,
      49,    51,    32,    33,    15,    35,    36,    37,    38,    39,
      40,    41,    28,    43,    44,    45,    46,    42,    53,    32,
      33,    51,    35,    36,    37,    38,    39,    40,    41,    11,
      43,    44,    45,    46,    54,    15,    32,    33,    51,    35,
      36,    37,    38,    39,    40,    41,    48,    43,    44,    45,
      46,    50,    50,    32,    33,    51,    35,    36,    37,    38,
      39,    40,    41,    50,    43,    44,    45,    46,    32,    33,
      49,    35,    36,    37,    38,    39,    40,    41,    50,    43,
      44,    45,    46,    47,    32,    33,    55,    35,    36,    37,
      38,    39,    40,    41,    54,    43,    44,    45,    46,    47,
      32,    33,    15,    35,    36,    37,    38,    39,    40,    41,
      13,    43,    44,    45,    46,    32,    33,    51,    35,    36,
      37,    38,    39,    40,    47,    47,    43,    44,    45,    46,
      32,    33,    19,    35,    36,    37,    38,    39,    40,    15,
      16,    17,    18,    45,    46,    21,    22,    15,    16,    17,
      18,    23,    47,    47,    22,    35,    36,    37,    38,    39,
      40,    35,    36,    37,    38,    39,    40,    23,    47,    26,
      37,    86,    47,    50,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    57,    58,    59,     0,    69,    25,    26,    29,
      60,    61,    26,    61,    70,    76,    15,    62,    63,     9,
      15,    48,    50,    42,    47,    50,    50,    14,    25,    26,
      64,    65,    66,    63,    51,    64,    49,    47,    51,    15,
      52,    67,    68,    53,    51,    65,    15,    42,    28,    71,
      53,    68,    72,    11,    77,    71,    29,    61,    73,    15,
      16,    17,    18,    22,    78,    79,    80,    81,    82,    83,
      87,    54,    77,    15,    74,    75,    48,    50,    50,    50,
      50,    12,    79,    84,    55,    54,    42,    47,    14,    15,
      30,    31,    34,    50,    85,    87,    85,    87,    85,    85,
      85,    13,    85,    75,    50,    85,    85,    32,    33,    35,
      36,    37,    38,    39,    40,    41,    43,    44,    45,    46,
      49,    51,    51,    51,    51,    47,    47,    52,    85,    86,
      51,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    47,    47,    19,    23,    87,    42,
      51,    78,    78,    52,    85,    20,    21,    24,    87,    78,
      47,    47,    21,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    71,    72,    72,
      73,    74,    74,    75,    76,    77,    78,    78,    79,    79,
      79,    79,    80,    81,    81,    82,    82,    83,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     0,     3,     1,     1,     3,
       1,     1,     4,     4,     3,     1,     0,     2,     1,     1,
       3,     1,     1,     2,     2,     0,     9,     3,     2,     0,
       3,     3,     1,     1,     8,     4,     2,     1,     1,     1,
       1,     1,     4,     5,     5,     8,    10,     8,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     3,
       4,     1,     2,     0,     1,     4
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
        case 7:
#line 120 "stage10.y" /* yacc.c:1646  */
    {vartype = INTEGER;(yyval.val)=INTEGER;}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "stage10.y" /* yacc.c:1646  */
    {vartype = BOOLEAN;(yyval.val)=BOOLEAN;}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "stage10.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[0].identifier),vartype,1,ID,NULL);}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "stage10.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-3].identifier),vartype,(yyvsp[-1].val),ID_ARRAY,NULL);}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "stage10.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-3].identifier),vartype,0,FUNCT,Arg_List); Arg_List = NULL; Arg_bind = 0;}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 141 "stage10.y" /* yacc.c:1646  */
    {argtype = INTEGER;}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 142 "stage10.y" /* yacc.c:1646  */
    {argtype = BOOLEAN;}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "stage10.y" /* yacc.c:1646  */
    { Arginstall(argtype,VALUE,(yyvsp[0].identifier)); }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "stage10.y" /* yacc.c:1646  */
    { Arginstall(argtype,REFERENCE,(yyvsp[0].identifier)); }
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 159 "stage10.y" /* yacc.c:1646  */
    {	int r,r1;
														Argcheck((yyvsp[-8].val),(yyvsp[-7].identifier),Arg_List);
														free_reg = -1;
														fprintf(outfile,"\n%s: \n", (yyvsp[-7].identifier));
														fprintf(outfile,"PUSH BP\n");
														fprintf(outfile,"MOV BP, SP\n");

														r = getreg();
														r1 = getreg();
														fprintf(outfile,"MOV R%d, %d\n",r,sp);
														fprintf(outfile,"MOV R%d, SP\n",r1);
														fprintf(outfile,"ADD R%d, R%d\n",r,r1);
														fprintf(outfile,"MOV SP, R%d\n",r);
														freereg(r);
														freereg(r1);

														struct tree_node *node = (yyvsp[-1].ptr);

														if((yyvsp[-1].ptr)->r->type != (yyvsp[-8].val)) {
															printf("return type mismatch");
															yyerror();
														}

														codegen((yyvsp[-1].ptr)->l,outfile);
														r1 = codegen((yyvsp[-1].ptr)->r,outfile);
														r = getreg();
														fprintf(outfile,"MOV R%d, BP\n",r);
														fprintf(outfile,"DCR R%d\n",r);
														fprintf(outfile,"DCR R%d\n",r);
														fprintf(outfile,"MOV [R%d], R%d\n",r,r1);
														freereg(r1);
														freereg(r);

														r = getreg();
														fprintf(outfile,"MOV SP, BP\n");
														fprintf(outfile,"POP R%d\n",r);
														fprintf(outfile,"MOV BP, R%d\n",r);
														freereg(r);

														fprintf(outfile,"RET\n\n");

														Arg_List = NULL;		// actually delete operation is to be done //
														Lsymbol_Table = NULL;	// actually delete operation is to be done //
														sp=0;
														Arg_bind = 0;
													  }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 220 "stage10.y" /* yacc.c:1646  */
    {Linstall((yyvsp[0].identifier),vartype);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 223 "stage10.y" /* yacc.c:1646  */
    {	int t,r1,r;
															fprintf(outfile,"\nSTART\n");
															fprintf(outfile,"MOV BP, 0\n");
															fprintf(outfile,"MOV SP, %d\n",start_addr-1);
															fprintf(outfile,"PUSH BP\n");
															fprintf(outfile,"MOV BP, SP\n");
															free_reg = -1;
															
															r = getreg();
															r1 = getreg();
															fprintf(outfile,"MOV R%d, %d\n",r,sp);
															fprintf(outfile,"MOV R%d, SP\n",r1);
															fprintf(outfile,"ADD R%d, R%d\n",r,r1);
															fprintf(outfile,"MOV SP, R%d\n",r);
															freereg(r);
															freereg(r1);
				// done //											
															codegen((yyvsp[-1].ptr)->l,outfile);

															fprintf(outfile,"HALT");
															printf("complete %d",free_reg);
															fclose(outfile);}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID,BODY,NULL,-1,(yyvsp[-2].ptr),NULL,(yyvsp[-1].ptr));}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 251 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr)=makenode(VOID,3,NULL,-1,(yyvsp[-1].ptr),NULL,(yyvsp[0].ptr));}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 255 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 256 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 257 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 258 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, '=', NULL, -1, (yyvsp[-3].ptr),NULL,(yyvsp[-1].ptr));			typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 264 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, READ, NULL, -1, (yyvsp[-2].ptr),NULL,NULL);			typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 265 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, WRITE,NULL, -1, (yyvsp[-2].ptr),NULL,NULL);			typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, IF,NULL, -1, (yyvsp[-5].ptr),(yyvsp[-2].ptr),NULL);		typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, ELSE,NULL,-1,(yyvsp[-7].ptr),(yyvsp[-4].ptr),(yyvsp[-2].ptr));}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, WHILE,NULL,-1,(yyvsp[-5].ptr),(yyvsp[-2].ptr),NULL);	typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 275 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 277 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, '+', NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 278 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, '-', NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 279 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, '*', NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, '/', NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, '%', NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 283 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[-1].ptr);}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER,FUNCT, (yyvsp[-3].identifier), -1, (yyvsp[-1].ptr), NULL, NULL);typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 287 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, LT, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 288 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, LE, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 289 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, GT, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 290 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, GE, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 291 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, EQ, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 292 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, NE, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 294 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, AND, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 295 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, OR, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 296 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, NOT, NULL, -1, (yyvsp[0].ptr), NULL, NULL);typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 298 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, TRUE, NULL, -1, NULL, NULL, NULL);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 299 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(BOOLEAN, FALSE, NULL, -1, NULL, NULL, NULL);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 301 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, NUM, NULL, (yyvsp[0].val), NULL, NULL, NULL);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 302 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = (yyvsp[0].ptr);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 305 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, VARLIST, NULL, -1, (yyvsp[-2].ptr), NULL, (yyvsp[0].ptr));}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 307 "stage10.y" /* yacc.c:1646  */
    {	if((yyvsp[0].ptr)->nodetype == ID)
										(yyvsp[0].ptr)->nodetype = ID_REF;
									else if((yyvsp[0].ptr)->nodetype == ID_ARRAY)
										(yyvsp[0].ptr)->nodetype = ID_ARRAY_REF;
									(yyval.ptr) = makenode(VOID, VARLIST, NULL, -1, (yyvsp[-3].ptr), NULL, (yyvsp[0].ptr));}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 313 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, VARLIST, NULL, -1, NULL, NULL, (yyvsp[0].ptr));}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 315 "stage10.y" /* yacc.c:1646  */
    {	if((yyvsp[0].ptr)->nodetype == ID)
										(yyvsp[0].ptr)->nodetype = ID_REF;
									else if((yyvsp[0].ptr)->nodetype == ID_ARRAY)
										(yyvsp[0].ptr)->nodetype = ID_ARRAY_REF;
									(yyval.ptr) = makenode(VOID, VARLIST, NULL, -1, NULL, NULL, (yyvsp[0].ptr));
								}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 322 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(VOID, VARLIST, NULL, -1, NULL, NULL, NULL);}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 325 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, ID, (yyvsp[0].identifier), -1, NULL,NULL,NULL);typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 326 "stage10.y" /* yacc.c:1646  */
    {(yyval.ptr) = makenode(INTEGER, ID_ARRAY,(yyvsp[-3].identifier),-1,(yyvsp[-1].ptr),NULL,NULL);
/*							struct Gsymbol *temp;
							temp = Glookup($1);
							if(temp->size == -1)
							{
								printf("error ");
								yyerror();
							}*/
						typecheck((yyval.ptr),(yyval.ptr)->l,(yyval.ptr)->m,(yyval.ptr)->r);}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1852 "y.tab.c" /* yacc.c:1646  */
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
#line 337 "stage10.y" /* yacc.c:1906  */


void Argcheck(int type, char *name, struct Argstruct *Arglist){
	struct Gsymbol *temp = Glookup(name);
	struct Argstruct *temp1 = temp->arglist;
	if(temp->binding == 0)
		temp->binding = 1;
	else
	{
		printf("error - two definition of same function %s\n",name);
		yyerror();
	}
	if(temp->type == type){
		while(temp1 != NULL) {
			if((strcmp(temp1->name,Arglist->name) == 0) && temp1->type == Arglist->type && temp1->passby == Arglist->passby)
				;
			else {
				printf("error in arglist of function %s",name);
				yyerror();
			}
			temp1 = temp1->next;
			Arglist = Arglist->next;
		}
		if(temp1 != NULL || Arglist != NULL) {
			printf("error arguments mismatch in %s", name);
			yyerror();
		}
	}
	else {
		printf("error in type of the function\n");
		yyerror();
	}
}

void typecheck(struct tree_node *root,struct tree_node *l,struct tree_node *m,struct tree_node *r)
{
	struct Gsymbol *temp = NULL;
	struct Argstruct *temp1 = NULL;

	if(root->nodetype == FUNCT) {
		temp = Glookup(root->name);
		temp1 = temp->arglist;
		if(temp != NULL) {
			while(l != NULL && l->r != NULL && temp1 != NULL) {
				if(temp1->type != l->r->type) {
					printf("error in types of function");
					yyerror();
				}
				temp1=temp1->next;
				l = l->l;
			}
			if(temp1 != NULL || l != NULL){
				printf("error in no of args in funct in typecheck");
				yyerror();
			}
		}
		else {
			printf("error in typecheck of funct");
			yyerror();
		}
	}

	else if(root->nodetype == ID) {
		struct Gsymbol *temp = root->Gentry;
		struct Lsymbol *temp1 = root->Lentry;
		struct Argstruct *temp2 = Arglookup(root->name);
		if(temp==NULL && temp1 == NULL && temp2 == NULL) {
			printf("error - identifier not declared");
			yyerror();
		}
		if(temp1==NULL && temp2==NULL && temp!=NULL && temp->nodetype != ID) {
			 printf("error - variable declared as array");
			 yyerror();
		}
	}

	else if(root->nodetype == ID_ARRAY)
	{
		struct Gsymbol *temp = root->Gentry;
		struct Lsymbol *temp1 = root->Lentry;
		struct Argstruct *temp2 = Arglookup(root->name);
		if(temp == NULL) {
			printf("error array declaration not found");
			yyerror();
		}
		if(root->l->type != INTEGER) {
			printf("error expr in array is not integer");
		}
	}

	else if(root->nodetype == '+' || root->nodetype == '-' || root->nodetype == '*' || root->nodetype == '/' || root->nodetype == '%')
	{
		if(l->type == INTEGER && r->type == INTEGER)
			;
		else
		{
		printf("error in operator");
		yyerror();
		}
	}
	else if(root->nodetype == LT || root->nodetype == LE || root->nodetype == GT || root->nodetype == GE || root->nodetype == EQ || root->nodetype == NE )
	{
		if(l->type == INTEGER && r->type == INTEGER)
			;
		else
		{
		printf("error in relop");
		yyerror();
		}
	}
	else if(root->nodetype == AND || root->nodetype == OR)
	{
		if(l->type == BOOLEAN && r->type == BOOLEAN)
			;
		else
		{
		printf("error in AND | OR");
		yyerror();
		}
	}
	else if(root->nodetype == NOT)
	{
		if(l->type == BOOLEAN)
			;
		else
		{
		printf("error in NOT");
		yyerror();
		}
	}
	else if(root->nodetype == IF)
	{
		if(l->type == BOOLEAN && m->type == VOID)
			;
		else
		{
		printf("error in IF");
		yyerror();
		}
	}
	else if(root->nodetype == WHILE)
	{
		if(l->type == BOOLEAN && m->type == VOID)
			;
		else
		{
		printf("error in WHILE");
		yyerror();
		}

	}
	else if(root->nodetype == READ)
	{
		if(l->type == INTEGER)
			;
		else
		{
		printf("error in READ ");
		yyerror();
		}
	}
	else if(root->nodetype == WRITE)
	{
		if(l->type == INTEGER)
			;
		else
		{
		printf("error in WRITE ");
		yyerror();
		}
	}
	else if(root->nodetype == '=')
	{
		if(l->type == INTEGER && r->type == INTEGER)
			;
		else if(l->type == BOOLEAN && r->type == BOOLEAN)
			;
		else
		{
		printf("error in = ");
		yyerror();
		}
	}
}

int getreg(){
	free_reg++;
	return free_reg;
}

void freereg(int r){
		free_reg--;
}

int getlabel()
{
	static int l=0;
	return ++l;
}

int getbind(char *name){
	int r1,r2,loc,r3;
	r1=getreg();
	r2=getreg();
	struct Gsymbol *temp1 = NULL;
	struct Lsymbol *temp2 = NULL;
	struct Argstruct *temp3 = NULL;
	temp3 = Arglookup(name);
	temp2 = Llookup(name);
	temp1 = Glookup(name);
	if(temp3 != NULL) {
		loc = temp3->argbind + 2;
		fprintf(outfile,"MOV R%d, BP\n",r1);
		fprintf(outfile,"MOV R%d, %d\n",r2,loc);
		fprintf(outfile,"SUB R%d, R%d\n",r1,r2);
		if(temp3->passby == REFERENCE) {
			fprintf(outfile,"MOV R%d, [R%d]\n",r2,r1);
			fprintf(outfile,"MOV R%d, R%d\n",r1,r2);
//			fprintf(outfile,"MOV R%d, [BP]\n",r1);
//			fprintf(outfile,"ADD R%d, R%d\n",r1,r2);
		}
		freereg(r2);
		return r1;
	}
	else if(temp2 != NULL) {
		loc = temp2->binding;
		fprintf(outfile,"MOV R%d, BP\n",r1);
		fprintf(outfile,"MOV R%d, %d\n",r2,loc);
		fprintf(outfile,"ADD R%d, R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(temp1 != NULL) {
		loc = temp1->binding;
		fprintf(outfile,"MOV R%d, %d\n",r1,loc);
		freereg(r2);
		return r1;
	}
}

int codegen(struct tree_node *head,FILE * outfile)
{
	struct tree_node *temp=NULL;
	int r,r1,r2,loc,l1,l2,i,j,argcount1=0;
	if(head == NULL) {
		printf("error in codegen");
		yyerror();
	}
	else if(head->nodetype == NUM){
		r = getreg();
		fprintf(outfile,"MOV R%d, %d\n",r,head->value);
		return r;
	}
	else if(head->nodetype == ID){
		r=getreg();
		r1=getbind(head->name);
		fprintf(outfile,"MOV R%d [R%d]\n",r,r1);
		freereg(r1);
		return r;
	}
	else if(head->nodetype == ID_REF) {
		r = getbind(head->name);
//		r1 =getreg();
//		fprintf(outfile,"MOV R%d, BP\n",r1);
//		fprintf(outfile,"SUB R%d, R%d\n",r,r1);
//		freereg(r1);
		return r;
	}
	else if(head->nodetype == ID_ARRAY_REF) {
		r1=getreg();
		r2=codegen(head->l,outfile);
		r=getreg();
		loc = head->Gentry->binding;
		fprintf(outfile,"MOV R%d %d\n",r,loc);
		fprintf(outfile,"ADD R%d R%d\n",r2,r);
		fprintf(outfile,"MOV R%d R%d\n",r1,r2);
		freereg(r2);
		freereg(r);
		return r1;
	}
	else if(head->nodetype == ID_ARRAY){
		r1=getreg();
		r2=codegen(head->l,outfile);
		r=getreg();
		loc = head->Gentry->binding;
		fprintf(outfile,"MOV R%d %d\n",r,loc);
		fprintf(outfile,"ADD R%d R%d\n",r2,r);
		fprintf(outfile,"MOV R%d [R%d]\n",r1,r2);
		freereg(r2);
		freereg(r);
		return r1;
	}
	else if(head->nodetype == TRUE){
		r = getreg();
		fprintf(outfile,"MOV R%d 1\n",r);
		return r;
	}
	else if(head->nodetype == FALSE){
		r = getreg();
		fprintf(outfile,"MOV R%d 0\n",r);
		return r;
	}
	else if(head->nodetype == '+'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"ADD R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == '-'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"SUB R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}	
	else if(head->nodetype == '*'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"MUL R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == '/'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"DIV R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == '%'){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"MOD R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == LT){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"LT R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == LE){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"LE R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == GT){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"GT R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == GE){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"GE R%d R%d\n",r1,r2);
		freereg(r2);
		return r1;
	}
	else if(head->nodetype == EQ){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"EQ R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == NE){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"NE R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == AND){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"MUL R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == OR){
		r1 = codegen(head->l,outfile);
		r2 = codegen(head->r,outfile);
		fprintf(outfile,"ADD R%d R%d\n",r1,r2);
		fprintf(outfile,"MOV R%d 0\n",r2);
		fprintf(outfile,"GT R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == NOT){
		r1 = codegen(head->l,outfile);					
		r2 = getreg();
		fprintf(outfile,"MOV R%d 0",r2);
		fprintf(outfile,"EQ R%d R%d\n",r1,r2);
		freereg(r2);
		return (r1);
	}
	else if(head->nodetype == 3){
		codegen(head->l,outfile);
		codegen(head->r,outfile);
		return free_reg;
	}
	else if(head->nodetype == '='){

		r = codegen(head->r,outfile);
		if(head->l->nodetype == ID){
			r1=getbind(head->l->name);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);
			freereg(r1);
		}
		else{
			loc = head->l->Gentry->binding;
			r1 = codegen(head->l->l,outfile);
			r2 = getreg();
			fprintf(outfile,"MOV R%d %d\n",r2,loc);
			fprintf(outfile,"ADD R%d R%d\n",r1,r2);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);		
			freereg(r2);
			freereg(r1);
		}
		freereg(r);
		return free_reg;
	}
	else if(head->nodetype == READ)
	{
		r = getreg();
		fprintf(outfile,"IN R%d\n",r);
		if(head->l->nodetype == ID){
			r1=getbind(head->l->name);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);
			freereg(r1);
		}
		if(head->l->nodetype == ID_ARRAY){
			loc = head->l->Gentry->binding;
			r1 = codegen(head->l->l,outfile);
			r2 = getreg();
			fprintf(outfile,"MOV R%d %d\n",r2,loc);
			fprintf(outfile,"ADD R%d R%d\n",r1,r2);
			fprintf(outfile,"MOV [R%d] R%d\n",r1,r);		
			freereg(r2);
			freereg(r1);
		}

		freereg(r);
		return free_reg;
	}
	else if(head->nodetype == WRITE)
	{
		r = codegen(head->l,outfile);
		fprintf(outfile,"OUT R%d\n",r);
		freereg(r);
		return free_reg;
	}
	else if(head->nodetype == IF)
	{
		l1 = getlabel();
		r1 = codegen(head->l,outfile);
		freereg(r1);
		fprintf(outfile,"JZ R%d l%d\n",r1,l1);
		r1 = codegen(head->m,outfile);
		if(r1 == -1)
			r1 = getreg();
		fprintf(outfile,"l%d: \n",l1);
		freereg(r1);
		return free_reg;
	}
	else if(head->nodetype == ELSE)
	{
		l1 = getlabel();
		l2 = getlabel();
		r1 = codegen(head->l,outfile);
		freereg(r1);
		fprintf(outfile,"JZ R%d, l%d\n",r1,l1);
		r1 = codegen(head->m,outfile);
		fprintf(outfile,"JMP l%d\n",l2);
/*		if(r1 != -1){
			printf("error in else\n");
			yyerror();						check later
		}*/
		fprintf(outfile,"l%d: \n",l1);
		r1 = codegen(head->r, outfile);
		fprintf(outfile,"l%d: \n",l2);
		return free_reg;
	}
	else if(head->nodetype == WHILE)
	{
		l1=getlabel();
		l2 = getlabel();
		fprintf(outfile,"l%d: \n",l1);
		r1 = codegen(head->l,outfile);
		freereg(r1);
		fprintf(outfile,"JZ R%d l%d\n",r1,l2);
		r1 = codegen(head->m,outfile);
		if(r1 == -1)
			r1 = getreg();
		fprintf(outfile,"JMP l%d\n",l1);
		fprintf(outfile,"l%d: \n",l2);
		freereg(r1);
		return free_reg;
	}
	else if(head->nodetype == FUNCT) {
		temp = head;
		for(i=0;i<=free_reg;i++) {
			fprintf(outfile,"PUSH R%d\n",i);
		}
		temp = temp->l;
		while(temp != NULL && temp->r != NULL) {
			r1 = codegen(temp->r,outfile);
			fprintf(outfile,"PUSH R%d\n",r1);
			freereg(r1);
			temp = temp->l;
			argcount1++;
		}
		fprintf(outfile,"PUSH R0\n");
		fprintf(outfile,"CALL %s \n",head->name);

		r=getreg();
		fprintf(outfile,"POP R%d\n",r);
		r2=getreg();

		for(j=0;j<argcount1;j++)
			fprintf(outfile,"POP R%d\n",r2);
		freereg(r2);

		for(j=i-1;j>-1;j--)
			fprintf(outfile,"POP R%d\n",j);
		return r;
	}
}

yyerror()
{
	printf("\nerror in line no %d\n",line_count+1);
	exit(1);
}

int main(int argc, char* argv[])
{
	outfile = fopen("output","w");
	yyin = fopen(argv[1],"r");
	yyparse();
	fclose(yyin);
	return 1;
}
