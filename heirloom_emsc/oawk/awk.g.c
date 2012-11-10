/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 74 "awk.g.y"

#include <inttypes.h>
typedef	void	*YYSTYPE;
#define	YYSTYPE	YYSTYPE

/* Line 268 of yacc.c  */
#line 114 "awk.g.y"

/*	from 4.4BSD /usr/src/old/awk/awk.g.y	4.4 (Berkeley) 4/27/91	*/
/*	Sccsid @(#)awk.g.y	1.5 (gritter) 7/24/03>	*/

#include "awk.def"
#ifndef	DEBUG	
#	define	PUTS(x)
#endif


/* Line 268 of yacc.c  */
#line 89 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FIRSTTOKEN = 258,
     FINAL = 259,
     FATAL = 260,
     LT = 261,
     LE = 262,
     GT = 263,
     GE = 264,
     EQ = 265,
     NE = 266,
     MATCH = 267,
     NOTMATCH = 268,
     APPEND = 269,
     ADD = 270,
     MINUS = 271,
     MULT = 272,
     DIVIDE = 273,
     MOD = 274,
     UMINUS = 275,
     ASSIGN = 276,
     ADDEQ = 277,
     SUBEQ = 278,
     MULTEQ = 279,
     DIVEQ = 280,
     MODEQ = 281,
     JUMP = 282,
     XBEGIN = 283,
     XEND = 284,
     NL = 285,
     PRINT = 286,
     PRINTF = 287,
     SPRINTF = 288,
     SPLIT = 289,
     IF = 290,
     ELSE = 291,
     WHILE = 292,
     FOR = 293,
     IN = 294,
     NEXT = 295,
     EXIT = 296,
     BREAK = 297,
     CONTINUE = 298,
     PROGRAM = 299,
     PASTAT = 300,
     PASTAT2 = 301,
     REGEXPR = 302,
     ASGNOP = 303,
     BOR = 304,
     AND = 305,
     NOT = 306,
     INDEX = 307,
     LSUBSTR = 308,
     SUBSTR = 309,
     FNCN = 310,
     ARRAY = 311,
     VAR = 312,
     NUMBER = 313,
     GETLINE = 314,
     MATCHOP = 315,
     RELOP = 316,
     OR = 317,
     CHAR = 318,
     NCCL = 319,
     CCL = 320,
     DOT = 321,
     STRING = 322,
     CAT = 323,
     QUEST = 324,
     PLUS = 325,
     STAR = 326,
     DECR = 327,
     INCR = 328,
     PREDECR = 329,
     POSTDECR = 330,
     PREINCR = 331,
     POSTINCR = 332,
     INDIRECT = 333,
     FIELD = 334,
     LASTTOKEN = 335
   };
#endif
/* Tokens.  */
#define FIRSTTOKEN 258
#define FINAL 259
#define FATAL 260
#define LT 261
#define LE 262
#define GT 263
#define GE 264
#define EQ 265
#define NE 266
#define MATCH 267
#define NOTMATCH 268
#define APPEND 269
#define ADD 270
#define MINUS 271
#define MULT 272
#define DIVIDE 273
#define MOD 274
#define UMINUS 275
#define ASSIGN 276
#define ADDEQ 277
#define SUBEQ 278
#define MULTEQ 279
#define DIVEQ 280
#define MODEQ 281
#define JUMP 282
#define XBEGIN 283
#define XEND 284
#define NL 285
#define PRINT 286
#define PRINTF 287
#define SPRINTF 288
#define SPLIT 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define IN 294
#define NEXT 295
#define EXIT 296
#define BREAK 297
#define CONTINUE 298
#define PROGRAM 299
#define PASTAT 300
#define PASTAT2 301
#define REGEXPR 302
#define ASGNOP 303
#define BOR 304
#define AND 305
#define NOT 306
#define INDEX 307
#define LSUBSTR 308
#define SUBSTR 309
#define FNCN 310
#define ARRAY 311
#define VAR 312
#define NUMBER 313
#define GETLINE 314
#define MATCHOP 315
#define RELOP 316
#define OR 317
#define CHAR 318
#define NCCL 319
#define CCL 320
#define DOT 321
#define STRING 322
#define CAT 323
#define QUEST 324
#define PLUS 325
#define STAR 326
#define DECR 327
#define INCR 328
#define PREDECR 329
#define POSTDECR 330
#define PREINCR 331
#define POSTINCR 332
#define INDIRECT 333
#define FIELD 334
#define LASTTOKEN 335




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 291 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1725

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   335

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    70,    76,     2,     2,
      68,    91,    74,    72,    94,    73,     2,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    96,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,     2,    93,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,    95,    90,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    71,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    14,    17,    18,    23,    26,
      27,    31,    35,    38,    42,    46,    50,    53,    57,    59,
      61,    63,    65,    68,    70,    73,    79,    83,    87,    89,
      91,    93,    98,   100,   102,   104,   106,   110,   115,   118,
     127,   134,   143,   150,   157,   161,   165,   169,   173,   177,
     181,   184,   187,   190,   193,   196,   199,   201,   204,   208,
     210,   211,   213,   218,   222,   229,   233,   237,   238,   241,
     243,   245,   247,   249,   251,   253,   254,   258,   262,   266,
     268,   270,   271,   276,   280,   284,   286,   288,   293,   296,
     301,   304,   306,   307,   309,   312,   315,   320,   323,   325,
     328,   331,   335,   338,   341,   345,   348,   349,   355,   366,
     376
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      98,     0,    -1,    99,   113,   100,    -1,     1,    -1,    28,
      89,   124,    90,    -1,    99,    30,    -1,    -1,    29,    89,
     124,    90,    -1,   100,    30,    -1,    -1,   103,    49,   103,
      -1,   103,    50,   103,    -1,    51,   103,    -1,    68,   101,
      91,    -1,   114,    49,   114,    -1,   114,    50,   114,    -1,
      51,   114,    -1,    68,   102,    91,    -1,   110,    -1,   120,
      -1,   107,    -1,   101,    -1,    36,   111,    -1,    87,    -1,
      86,   109,    -1,    35,    68,   103,    91,   111,    -1,   110,
      60,   118,    -1,    68,   107,    91,    -1,    58,    -1,    67,
      -1,    57,    -1,    57,    92,   110,    93,    -1,   105,    -1,
     108,    -1,    59,    -1,    55,    -1,    55,    68,    91,    -1,
      55,    68,   110,    91,    -1,    33,   115,    -1,    54,    68,
     110,    94,   110,    94,   110,    91,    -1,    54,    68,   110,
      94,   110,    91,    -1,    34,    68,   110,    94,    57,    94,
     110,    91,    -1,    34,    68,   110,    94,    57,    91,    -1,
      52,    68,   110,    94,   110,    91,    -1,    68,   110,    91,
      -1,   109,    72,   109,    -1,   109,    73,   109,    -1,   109,
      74,   109,    -1,   109,    75,   109,    -1,   109,    76,   109,
      -1,    73,   109,    -1,    72,   109,    -1,    81,   108,    -1,
      80,   108,    -1,   108,    81,    -1,   108,    80,    -1,   109,
      -1,   110,   109,    -1,   108,    48,   110,    -1,    30,    -1,
      -1,   114,    -1,   114,    89,   124,    90,    -1,   114,    94,
     114,    -1,   114,    94,   114,    89,   124,    90,    -1,    89,
     124,    90,    -1,   113,   112,   121,    -1,    -1,   113,   112,
      -1,   118,    -1,   120,    -1,   107,    -1,   102,    -1,   110,
      -1,   116,    -1,    -1,   110,    94,   110,    -1,   116,    94,
     110,    -1,    68,   116,    91,    -1,    61,    -1,    95,    -1,
      -1,    75,   119,    47,    75,    -1,   110,    61,   110,    -1,
      68,   120,    91,    -1,    30,    -1,    96,    -1,    31,   115,
     117,   110,    -1,    31,   115,    -1,    32,   115,   117,   110,
      -1,    32,   115,    -1,   110,    -1,    -1,     1,    -1,   122,
     121,    -1,   106,   123,    -1,   106,   123,   104,   123,    -1,
     125,   123,    -1,   126,    -1,    40,   121,    -1,    41,   121,
      -1,    41,   110,   121,    -1,    42,   121,    -1,    43,   121,
      -1,    89,   124,    90,    -1,   124,   123,    -1,    -1,    37,
      68,   103,    91,   111,    -1,    38,    68,   122,    96,   103,
      96,   122,    91,   111,   123,    -1,    38,    68,   122,    96,
      96,   122,    91,   111,   123,    -1,    38,    68,    57,    39,
      57,    91,   111,   123,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   131,   132,   133,   137,   138,   139,
     143,   144,   145,   146,   150,   151,   152,   153,   157,   158,
     159,   160,   164,   168,   169,   173,   177,   178,   182,   183,
     184,   185,   186,   189,   190,   191,   194,   197,   198,   199,
     201,   203,   205,   207,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   224,   225,   226,   230,
     231,   235,   236,   237,   238,   240,   244,   245,   246,   250,
     253,   254,   255,   259,   260,   261,   265,   266,   267,   271,
     272,   276,   276,   282,   284,   289,   290,   294,   296,   298,
     300,   302,   303,   304,   308,   309,   310,   312,   313,   314,
     315,   316,   317,   318,   319,   323,   324,   328,   332,   334,
     336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FIRSTTOKEN", "FINAL", "FATAL", "LT",
  "LE", "GT", "GE", "EQ", "NE", "MATCH", "NOTMATCH", "APPEND", "ADD",
  "MINUS", "MULT", "DIVIDE", "MOD", "UMINUS", "ASSIGN", "ADDEQ", "SUBEQ",
  "MULTEQ", "DIVEQ", "MODEQ", "JUMP", "XBEGIN", "XEND", "NL", "PRINT",
  "PRINTF", "SPRINTF", "SPLIT", "IF", "ELSE", "WHILE", "FOR", "IN", "NEXT",
  "EXIT", "BREAK", "CONTINUE", "PROGRAM", "PASTAT", "PASTAT2", "REGEXPR",
  "ASGNOP", "BOR", "AND", "NOT", "INDEX", "LSUBSTR", "SUBSTR", "FNCN",
  "ARRAY", "VAR", "NUMBER", "GETLINE", "MATCHOP", "RELOP", "OR", "CHAR",
  "NCCL", "CCL", "DOT", "STRING", "'('", "'^'", "'$'", "CAT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "QUEST", "PLUS", "STAR", "DECR", "INCR", "PREDECR",
  "POSTDECR", "PREINCR", "POSTINCR", "INDIRECT", "FIELD", "LASTTOKEN",
  "'{'", "'}'", "')'", "'['", "']'", "','", "'|'", "';'", "$accept",
  "program", "begin", "end", "compound_conditional", "compound_pattern",
  "conditional", "else", "field", "if", "lex_expr", "var", "term", "expr",
  "optNL", "pa_stat", "pa_stats", "pattern", "print_list", "pe_list",
  "redir", "regular_expr", "$@1", "rel_expr", "st", "simple_stat",
  "statement", "stat_list", "while", "for", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    40,    94,
      36,   323,    43,    45,    42,    47,    37,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   123,
     125,    41,    91,    93,    44,   124,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    98,    99,    99,    99,   100,   100,   100,
     101,   101,   101,   101,   102,   102,   102,   102,   103,   103,
     103,   103,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   113,   113,   113,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   116,   117,
     117,   119,   118,   120,   120,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   126,   126,
     126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     4,     2,     0,     4,     2,     0,
       3,     3,     2,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     2,     1,     2,     5,     3,     3,     1,     1,
       1,     4,     1,     1,     1,     1,     3,     4,     2,     8,
       6,     8,     6,     6,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     1,
       0,     1,     4,     3,     6,     3,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     0,     3,     3,     3,     1,
       1,     0,     4,     3,     3,     1,     1,     4,     2,     4,
       2,     1,     0,     1,     2,     2,     4,     2,     1,     2,
       2,     3,     2,     2,     3,     2,     0,     5,    10,     9,
       8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,    67,   106,     1,     5,     9,     0,
       0,    75,     0,     0,     0,     0,    35,    30,    28,    34,
      29,     0,     0,     0,    81,     0,     0,     0,    23,   106,
       2,    72,    32,    71,    33,    56,     0,    68,    61,    69,
      70,    93,    75,    75,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     4,     0,    91,     0,   105,     0,    98,
     106,     0,    73,    38,    74,     0,    16,     0,     0,     0,
       0,    72,    71,     0,     0,    70,    33,    51,    50,     0,
      53,    52,    24,     0,     8,     0,    55,    54,     0,     0,
       0,     0,     0,     0,     0,    57,    85,    86,    66,     0,
       0,   106,     0,    88,    90,     0,     0,     0,    99,     0,
     100,   102,   103,     0,     0,    95,    94,    97,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,    17,
      27,    44,    84,     0,    65,    58,    45,    46,    47,    48,
      49,    26,    83,    14,    15,     0,    63,    79,    80,     0,
       0,     0,     0,    21,     0,    20,    18,    19,     0,    30,
       0,   101,   104,    60,     0,     7,    78,    76,    77,     0,
       0,     0,    37,    31,    82,    62,   106,    87,    89,    12,
      21,     0,    20,    18,    19,     0,     0,    60,    60,     0,
       0,    59,    22,    96,     0,     0,     0,     0,    13,    10,
      11,    25,   107,     0,     0,     0,    42,     0,    43,    40,
       0,    64,    60,     0,     0,     0,     0,     0,    60,     0,
      41,    39,   110,     0,    60,   109,     0,   108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    30,   153,    31,   154,   164,    32,    54,
     155,    34,    35,    55,   192,    37,     8,    38,    63,    64,
     149,    39,    79,   157,    98,    56,    57,     9,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const yytype_int16 yypact[] =
{
     772,  -106,   -85,    10,    -9,  -106,  -106,  -106,  1133,   219,
     -77,  1602,   -38,  1493,   -14,   -12,   -10,   -47,  -106,  -106,
    -106,  1493,  1638,  1638,  -106,   181,   181,  1638,  -106,  -106,
      17,  -106,  -106,  -106,   -31,   111,  1529,   -29,   -43,  -106,
    -106,  -106,  1602,  1602,    -5,    -3,     3,   -29,   808,   -29,
     -29,  1638,  -106,  -106,   629,  1638,   -29,  -106,   629,  -106,
    -106,  1602,   969,  -106,   -25,  1638,  -106,  1638,  1638,  1247,
    1638,     2,    24,  1206,    55,    28,    15,  -106,  -106,    75,
    -106,  -106,  -106,   289,  -106,  1638,  -106,  -106,  1638,  1638,
    1638,  1638,  1638,    48,  1638,   111,  -106,  -106,  -106,  1493,
    1493,  -106,  1493,   -20,   -20,  1566,  1566,   672,  -106,   808,
    -106,  -106,  -106,  1288,   357,    90,  -106,  -106,   425,   887,
     -66,  1638,  1638,  1010,  1051,  1092,  -106,  1329,  1169,  -106,
    -106,  -106,  -106,    52,  -106,  1638,    14,    14,  -106,  -106,
    -106,  -106,   674,    82,  -106,   493,   -17,  -106,  -106,  1638,
    1638,  1566,  1566,  -106,   -23,  -106,  1529,  -106,   -13,   -28,
      38,  -106,  -106,   106,   629,  -106,  -106,  1638,  1638,    80,
    1638,  1638,  -106,  -106,  -106,  -106,  -106,  1638,  1638,  -106,
      49,    58,    24,  1206,    28,  1566,  1566,   106,   106,    88,
     851,  -106,  -106,  -106,   -18,  1370,   928,   561,  -106,    89,
    -106,  -106,  -106,    56,   731,   -26,  -106,  1638,  -106,  -106,
    1638,  -106,   106,    59,   731,  1411,  1452,   629,   106,    60,
    -106,  -106,  -106,   629,   106,  -106,   629,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,  -106,    -6,   133,    46,  -106,  -106,  -106,
       1,    -7,   102,    -8,   116,  -106,  -106,    31,    68,    95,
      54,    74,  -106,    66,   156,  -105,   -16,   -21,  -106,  -106
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      36,    96,   160,    62,     5,    36,    99,   100,    83,    33,
       6,   189,    60,    73,    33,    76,    76,    85,    80,    81,
      76,     7,    72,   185,   186,   166,   185,   186,   122,    76,
      65,   114,    99,   100,    62,    62,   185,   186,   115,   118,
     109,   147,   117,   113,    66,    70,   101,    84,    76,    86,
      87,   102,    74,   119,    67,    76,    68,   123,    69,   124,
     125,   127,   128,   105,    70,   106,    76,    97,   187,   122,
     214,   107,   176,   206,    40,   148,   207,   135,   188,    40,
     145,    76,    76,    76,    76,    76,   142,    75,    90,    91,
      92,    36,    36,   129,    36,    86,    87,   156,   156,   213,
      33,    33,    76,    33,    99,   100,    76,   185,   186,   219,
     103,   104,    76,   167,   168,   130,    76,    76,    76,   132,
      76,    76,   133,    24,    77,    78,   163,   174,    76,    82,
     143,   144,   100,   146,   190,    76,   191,   194,    95,   186,
     198,   177,   178,   156,   183,   203,   180,   212,   193,    76,
     218,   224,   158,   182,    71,   197,   120,    95,   150,     0,
      76,    76,   195,   196,    95,    40,    40,   141,    40,     0,
      76,    76,     0,     0,     0,    95,    76,   156,   156,     0,
       0,     0,   156,    88,    89,    90,    91,    92,    76,    76,
     136,   137,   138,   139,   140,     0,     0,   179,   181,   215,
       0,   222,   216,   108,   110,   111,   112,   225,    76,    76,
     227,    95,   116,     0,     0,    95,     0,     0,   184,     0,
      41,    95,     0,     0,     0,    95,    95,    95,     0,    95,
      95,   199,   200,     0,     0,     0,   205,    95,    17,    18,
       0,     0,     0,     0,    95,     0,     0,     0,    20,   -92,
      42,    43,    11,    12,    44,     0,    45,    46,    95,    47,
      48,    49,    50,     0,     0,   161,     0,    27,    28,    95,
      95,    14,     0,    15,    16,     0,    17,    18,    19,    95,
      95,     0,     0,     0,     0,    95,    20,    51,     0,     0,
      41,    22,    23,     0,     0,     0,     0,    95,    95,    25,
      26,     0,     0,   201,   202,    27,    28,     0,    52,    53,
       0,     0,     0,     0,     0,   -92,     0,    95,    95,   -92,
      42,    43,    11,    12,    44,     0,    45,    46,   217,    47,
      48,    49,    50,     0,   223,     0,     0,     0,     0,     0,
     226,    14,     0,    15,    16,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,    20,    51,    41,     0,
       0,    22,    23,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,    52,   134,
       0,     0,     0,     0,     0,   -92,     0,   -92,    42,    43,
      11,    12,    44,     0,    45,    46,     0,    47,    48,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    15,    16,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,    20,    51,    41,     0,     0,    22,
      23,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,    52,   162,     0,     0,
       0,     0,     0,   -92,     0,   -92,    42,    43,    11,    12,
      44,     0,    45,    46,     0,    47,    48,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,     0,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,    20,    51,    41,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,    28,     0,    52,   165,     0,     0,     0,     0,
       0,   -92,     0,   -92,    42,    43,    11,    12,    44,     0,
      45,    46,     0,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,    15,    16,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      20,    51,    41,     0,     0,    22,    23,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
      28,     0,    52,   175,     0,     0,     0,     0,     0,   -92,
       0,   -92,    42,    43,    11,    12,    44,     0,    45,    46,
       0,    47,    48,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    16,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    20,    51,
      41,     0,     0,    22,    23,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,    28,     0,
      52,   211,     0,     0,     0,     0,     0,   -92,     0,   -92,
      42,    43,    11,    12,    44,     0,    45,    46,     0,    47,
      48,    49,    50,    41,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,    20,    51,     0,     0,
       0,    22,    23,    42,    43,    11,    12,    11,    12,    25,
      26,     0,     0,     0,     0,    27,    28,     0,    52,     0,
       0,     0,     0,     0,    14,   -92,    15,    16,     0,   159,
      18,    19,    41,     0,     0,     0,     0,     0,     0,    20,
      51,    20,    51,     0,    22,    23,    22,    23,     0,     0,
       0,     0,    25,    26,    25,    26,     0,     0,    27,    28,
      27,    28,    42,    43,    11,    12,     0,     0,   -92,     0,
       0,     0,    -6,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    16,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    20,    51,
       2,    -6,    -6,    22,    23,    -6,    -6,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,   -92,    -6,    -6,     0,    -6,    -6,     0,    -6,
      -6,    -6,     0,     0,     0,     0,     0,     0,    96,    -6,
      -6,    11,    12,     0,    -6,    -6,     0,    -6,     0,     0,
       0,     0,    -6,    -6,     0,     0,     0,     0,    -6,    -6,
      14,    -6,    15,    16,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,    20,    51,     0,     0,     0,
      22,    23,     0,     0,    11,    12,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,     0,
       0,     0,   151,    14,    97,    15,    16,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    20,   152,
      11,    12,     0,    22,    23,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,    28,    14,
       0,    15,    16,     0,    17,    18,    19,   204,     0,     0,
       0,     0,     0,     0,    20,    51,     0,     0,     0,    22,
      23,    11,    12,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,     0,   131,     0,
      14,   121,    15,    16,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,    20,    51,     0,     0,     0,
      22,    23,    11,    12,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,   209,
       0,    14,   210,    15,    16,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,    20,    51,     0,     0,
       0,    22,    23,    11,    12,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,     0,    14,   121,    15,    16,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,    20,    51,     0,
       0,     0,    22,    23,    11,    12,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,    28,     0,     0,
       0,     0,     0,    14,   169,    15,    16,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    20,    51,
       0,     0,     0,    22,    23,    11,    12,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,     0,    14,   170,    15,    16,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,    20,
      51,     0,    10,     0,    22,    23,    11,    12,     0,     0,
       0,     0,    25,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,     0,    13,    14,   171,    15,    16,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      20,    21,    11,    12,     0,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    14,    29,    15,    16,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,    20,    51,     0,    11,
      12,    22,    23,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,    14,     0,
      15,    16,   173,    17,    18,    19,    93,    94,     0,     0,
       0,     0,     0,    20,    51,     0,     0,     0,    22,    23,
      11,    12,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     0,     0,     0,   131,     0,    14,
       0,    15,    16,     0,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,    20,    51,     0,     0,     0,    22,
      23,    11,    12,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,     0,     0,   126,     0,
      14,     0,    15,    16,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,    20,    51,     0,     0,     0,
      22,    23,    11,    12,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28,     0,     0,     0,   131,
       0,    14,     0,    15,    16,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,    20,    51,     0,     0,
       0,    22,    23,    11,    12,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,     0,     0,     0,
     172,     0,    14,     0,    15,    16,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,    20,    51,     0,
       0,     0,    22,    23,    11,    12,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,    27,    28,     0,     0,
       0,   208,     0,    14,     0,    15,    16,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,    20,    51,
       0,     0,     0,    22,    23,    11,    12,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,    27,    28,     0,
       0,     0,   220,     0,    14,     0,    15,    16,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,    20,
      51,     0,     0,     0,    22,    23,    11,    12,     0,     0,
       0,     0,    25,    26,     0,     0,     0,     0,    27,    28,
       0,     0,     0,   221,    13,    14,     0,    15,    16,     0,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      20,    21,    11,    12,     0,    22,    23,     0,    24,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,    27,
      28,    14,     0,    15,    16,     0,    17,    18,    19,    93,
      94,     0,     0,     0,     0,     0,    20,    51,     0,    11,
      12,    22,    23,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,   151,    14,     0,
      15,    16,     0,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,    20,   152,    11,    12,     0,    22,    23,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,    28,    14,     0,    15,    16,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,    20,
      61,    11,    12,     0,    22,    23,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,     0,    27,    28,
      14,     0,    15,    16,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,    20,    51,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,    27,    28
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-106))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       8,    30,   107,    11,    89,    13,    49,    50,    29,     8,
       0,    39,    89,    21,    13,    22,    23,    48,    25,    26,
      27,    30,    21,    49,    50,    91,    49,    50,    94,    36,
      68,    52,    49,    50,    42,    43,    49,    50,    54,    60,
      48,    61,    58,    51,    13,    92,    89,    30,    55,    80,
      81,    94,    21,    61,    68,    62,    68,    65,    68,    67,
      68,    69,    70,    68,    92,    68,    73,    96,    91,    94,
      96,    68,    89,    91,     8,    95,    94,    85,    91,    13,
     101,    88,    89,    90,    91,    92,    94,    21,    74,    75,
      76,    99,   100,    91,   102,    80,    81,   105,   106,   204,
      99,   100,   109,   102,    49,    50,   113,    49,    50,   214,
      42,    43,   119,   121,   122,    91,   123,   124,   125,    91,
     127,   128,    47,    75,    22,    23,    36,    75,   135,    27,
      99,   100,    50,   102,    96,   142,    30,    57,    36,    50,
      91,   149,   150,   151,   152,    57,   152,    91,   164,   156,
      91,    91,   106,   152,    21,   176,    61,    55,   104,    -1,
     167,   168,   170,   171,    62,    99,   100,    93,   102,    -1,
     177,   178,    -1,    -1,    -1,    73,   183,   185,   186,    -1,
      -1,    -1,   190,    72,    73,    74,    75,    76,   195,   196,
      88,    89,    90,    91,    92,    -1,    -1,   151,   152,   207,
      -1,   217,   210,    47,    48,    49,    50,   223,   215,   216,
     226,   109,    56,    -1,    -1,   113,    -1,    -1,   152,    -1,
       1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   185,   186,    -1,    -1,    -1,   190,   135,    57,    58,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    67,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,   156,    40,
      41,    42,    43,    -1,    -1,   109,    -1,    86,    87,   167,
     168,    52,    -1,    54,    55,    -1,    57,    58,    59,   177,
     178,    -1,    -1,    -1,    -1,   183,    67,    68,    -1,    -1,
       1,    72,    73,    -1,    -1,    -1,    -1,   195,   196,    80,
      81,    -1,    -1,   187,   188,    86,    87,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,   215,   216,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,   212,    40,
      41,    42,    43,    -1,   218,    -1,    -1,    -1,    -1,    -1,
     224,    52,    -1,    54,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,     1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,     1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    86,    87,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,     1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      -1,    86,    87,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    -1,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,     1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,
      87,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      -1,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
       1,    -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    -1,    40,
      41,    42,    43,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    72,    73,    31,    32,    33,    34,    33,    34,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    52,    96,    54,    55,    -1,    57,
      58,    59,     1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    67,    68,    -1,    72,    73,    72,    73,    -1,    -1,
      -1,    -1,    80,    81,    80,    81,    -1,    -1,    86,    87,
      86,    87,    31,    32,    33,    34,    -1,    -1,    96,    -1,
      -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      28,    29,    30,    72,    73,    33,    34,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    51,    52,    -1,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    30,    67,
      68,    33,    34,    -1,    72,    73,    -1,    75,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      52,    89,    54,    55,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      72,    73,    -1,    -1,    33,    34,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    96,    54,    55,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      33,    34,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    52,
      -1,    54,    55,    -1,    57,    58,    59,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    72,
      73,    33,    34,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,    -1,
      52,    94,    54,    55,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      72,    73,    33,    34,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,
      -1,    52,    94,    54,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    72,    73,    33,    34,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    52,    94,    54,    55,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    72,    73,    33,    34,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    52,    94,    54,    55,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    72,    73,    33,    34,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    52,    94,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    29,    -1,    72,    73,    33,    34,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    51,    52,    94,    54,    55,    -1,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    33,    34,    -1,    72,    73,    -1,    75,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,
      87,    52,    89,    54,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    33,
      34,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    52,    -1,
      54,    55,    93,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    72,    73,
      33,    34,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    91,    -1,    52,
      -1,    54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    72,
      73,    33,    34,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,    -1,
      52,    -1,    54,    55,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      72,    73,    33,    34,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,
      -1,    52,    -1,    54,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    72,    73,    33,    34,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      91,    -1,    52,    -1,    54,    55,    -1,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    72,    73,    33,    34,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    91,    -1,    52,    -1,    54,    55,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    72,    73,    33,    34,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    -1,    52,    -1,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    72,    73,    33,    34,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    91,    51,    52,    -1,    54,    55,    -1,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    33,    34,    -1,    72,    73,    -1,    75,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,
      87,    52,    -1,    54,    55,    -1,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    33,
      34,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    51,    52,    -1,
      54,    55,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    33,    34,    -1,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    87,    52,    -1,    54,    55,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    33,    34,    -1,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    86,    87,
      52,    -1,    54,    55,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    28,    98,    99,    89,     0,    30,   113,   124,
      29,    33,    34,    51,    52,    54,    55,    57,    58,    59,
      67,    68,    72,    73,    75,    80,    81,    86,    87,    89,
     100,   102,   105,   107,   108,   109,   110,   112,   114,   118,
     120,     1,    31,    32,    35,    37,    38,    40,    41,    42,
      43,    68,    89,    90,   106,   110,   122,   123,   125,   126,
      89,    68,   110,   115,   116,    68,   114,    68,    68,    68,
      92,   102,   107,   110,   114,   120,   108,   109,   109,   119,
     108,   108,   109,   124,    30,    48,    80,    81,    72,    73,
      74,    75,    76,    60,    61,   109,    30,    96,   121,    49,
      50,    89,    94,   115,   115,    68,    68,    68,   121,   110,
     121,   121,   121,   110,   124,   123,   121,   123,   124,   110,
     116,    94,    94,   110,   110,   110,    91,   110,   110,    91,
      91,    91,    91,    47,    90,   110,   109,   109,   109,   109,
     109,   118,   110,   114,   114,   124,   114,    61,    95,   117,
     117,    51,    68,   101,   103,   107,   110,   120,   103,    57,
     122,   121,    90,    36,   104,    90,    91,   110,   110,    94,
      94,    94,    91,    93,    75,    90,    89,   110,   110,   103,
     101,   103,   107,   110,   120,    49,    50,    91,    91,    39,
      96,    30,   111,   123,    57,   110,   110,   124,    91,   103,
     103,   111,   111,    57,    96,   103,    91,    94,    91,    91,
      94,    90,    91,   122,    96,   110,   110,   111,    91,   122,
      91,    91,   123,   111,    91,   123,   111,   123
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 126 "awk.g.y"
    { if (errorflag==0) winner = (node *)stat3(PROGRAM, (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 127 "awk.g.y"
    { yyclearin; yyerror("bailing out"); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 131 "awk.g.y"
    { PUTS("XBEGIN list"); (yyval) = (yyvsp[(3) - (4)]); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 133 "awk.g.y"
    { PUTS("empty XBEGIN"); (yyval) = nullstat; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 137 "awk.g.y"
    { PUTS("XEND list"); (yyval) = (yyvsp[(3) - (4)]); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 139 "awk.g.y"
    { PUTS("empty END"); (yyval) = nullstat; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 143 "awk.g.y"
    { PUTS("cond||cond"); (yyval) = op2(BOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 144 "awk.g.y"
    { PUTS("cond&&cond"); (yyval) = op2(AND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 145 "awk.g.y"
    { PUTS("!cond"); (yyval) = op1(NOT, (yyvsp[(2) - (2)])); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 146 "awk.g.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 150 "awk.g.y"
    { PUTS("pat||pat"); (yyval) = op2(BOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 151 "awk.g.y"
    { PUTS("pat&&pat"); (yyval) = op2(AND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 152 "awk.g.y"
    { PUTS("!pat"); (yyval) = op1(NOT, (yyvsp[(2) - (2)])); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 153 "awk.g.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 157 "awk.g.y"
    { PUTS("expr"); (yyval) = op2(NE, (yyvsp[(1) - (1)]), valtonode(lookup("$zero&null", symtab, 0), CCON)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 158 "awk.g.y"
    { PUTS("relexpr"); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 159 "awk.g.y"
    { PUTS("lexexpr"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 160 "awk.g.y"
    { PUTS("compcond"); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 164 "awk.g.y"
    { PUTS("else"); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 168 "awk.g.y"
    { PUTS("field"); (yyval) = valtonode((yyvsp[(1) - (1)]), CFLD); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 169 "awk.g.y"
    { PUTS("ind field"); (yyval) = op1(INDIRECT, (yyvsp[(2) - (2)])); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 173 "awk.g.y"
    { PUTS("if(cond)"); (yyval) = (yyvsp[(3) - (5)]); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 177 "awk.g.y"
    { PUTS("expr~re"); (yyval) = op2((intptr_t)(yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (void *)makedfa((yyvsp[(3) - (3)]))); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 178 "awk.g.y"
    { PUTS("(lex_expr)"); (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 182 "awk.g.y"
    {PUTS("number"); (yyval) = valtonode((yyvsp[(1) - (1)]), CCON); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 183 "awk.g.y"
    { PUTS("string"); (yyval) = valtonode((yyvsp[(1) - (1)]), CCON); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 184 "awk.g.y"
    { PUTS("var"); (yyval) = valtonode((yyvsp[(1) - (1)]), CVAR); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 185 "awk.g.y"
    { PUTS("array[]"); (yyval) = op2(ARRAY, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 190 "awk.g.y"
    { PUTS("getline"); (yyval) = op1(GETLINE, 0); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 191 "awk.g.y"
    { PUTS("func");
			(yyval) = op2(FNCN, (yyvsp[(1) - (1)]), valtonode(lookup("$record", symtab, 0), CFLD));
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 194 "awk.g.y"
    { PUTS("func()"); 
			(yyval) = op2(FNCN, (yyvsp[(1) - (3)]), valtonode(lookup("$record", symtab, 0), CFLD));
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 197 "awk.g.y"
    { PUTS("func(expr)"); (yyval) = op2(FNCN, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 198 "awk.g.y"
    { PUTS("sprintf"); (yyval) = op1((intptr_t)(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 200 "awk.g.y"
    { PUTS("substr(e,e,e)"); (yyval) = op3(SUBSTR, (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)])); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 202 "awk.g.y"
    { PUTS("substr(e,e,e)"); (yyval) = op3(SUBSTR, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), nullstat); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 204 "awk.g.y"
    { PUTS("split(e,e,e)"); (yyval) = op3(SPLIT, (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)])); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 206 "awk.g.y"
    { PUTS("split(e,e,e)"); (yyval) = op3(SPLIT, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]), nullstat); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 208 "awk.g.y"
    { PUTS("index(e,e)"); (yyval) = op2(INDEX, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)])); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 209 "awk.g.y"
    {PUTS("(expr)");  (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 210 "awk.g.y"
    { PUTS("t+t"); (yyval) = op2(ADD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 211 "awk.g.y"
    { PUTS("t-t"); (yyval) = op2(MINUS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 212 "awk.g.y"
    { PUTS("t*t"); (yyval) = op2(MULT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 213 "awk.g.y"
    { PUTS("t/t"); (yyval) = op2(DIVIDE, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 214 "awk.g.y"
    { PUTS("t%t"); (yyval) = op2(MOD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 215 "awk.g.y"
    { PUTS("-term"); (yyval) = op1(UMINUS, (yyvsp[(2) - (2)])); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 216 "awk.g.y"
    { PUTS("+term"); (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 217 "awk.g.y"
    { PUTS("++var"); (yyval) = op1(PREINCR, (yyvsp[(2) - (2)])); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 218 "awk.g.y"
    { PUTS("--var"); (yyval) = op1(PREDECR, (yyvsp[(2) - (2)])); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 219 "awk.g.y"
    { PUTS("var++"); (yyval)= op1(POSTINCR, (yyvsp[(1) - (2)])); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 220 "awk.g.y"
    { PUTS("var--"); (yyval)= op1(POSTDECR, (yyvsp[(1) - (2)])); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 224 "awk.g.y"
    { PUTS("term"); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 225 "awk.g.y"
    { PUTS("expr term"); (yyval) = op2(CAT, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 226 "awk.g.y"
    { PUTS("var=expr"); (yyval) = stat2((intptr_t)(yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 235 "awk.g.y"
    { PUTS("pattern"); (yyval) = stat2(PASTAT, (yyvsp[(1) - (1)]), genprint()); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 236 "awk.g.y"
    { PUTS("pattern {...}"); (yyval) = stat2(PASTAT, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 237 "awk.g.y"
    { PUTS("srch,srch"); (yyval) = pa2stat((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), genprint()); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 239 "awk.g.y"
    { PUTS("srch, srch {...}"); (yyval) = pa2stat((yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)])); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 240 "awk.g.y"
    { PUTS("null pattern {...}"); (yyval) = stat2(PASTAT, nullstat, (yyvsp[(2) - (3)])); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 244 "awk.g.y"
    { PUTS("pa_stats pa_stat"); (yyval) = linkum((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 245 "awk.g.y"
    { PUTS("null pa_stat"); (yyval) = nullstat; }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 246 "awk.g.y"
    {PUTS("pa_stats pa_stat"); (yyval) = linkum((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 250 "awk.g.y"
    { PUTS("regex");
		(yyval) = op2(MATCH, valtonode(lookup("$record", symtab, 0), CFLD), (void *)makedfa((yyvsp[(1) - (1)])));
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 253 "awk.g.y"
    { PUTS("relexpr"); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 254 "awk.g.y"
    { PUTS("lexexpr"); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 255 "awk.g.y"
    { PUTS("comp pat"); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 259 "awk.g.y"
    { PUTS("expr"); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 260 "awk.g.y"
    { PUTS("pe_list"); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 261 "awk.g.y"
    { PUTS("null print_list"); (yyval) = valtonode(lookup("$record", symtab, 0), CFLD); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 265 "awk.g.y"
    {(yyval) = linkum((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 266 "awk.g.y"
    {(yyval) = linkum((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 267 "awk.g.y"
    {(yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 276 "awk.g.y"
    { startreg(); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 278 "awk.g.y"
    { PUTS("/r/"); (yyval) = (yyvsp[(3) - (4)]); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 283 "awk.g.y"
    { PUTS("expr relop expr"); (yyval) = op2((intptr_t)(yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 285 "awk.g.y"
    { PUTS("(relexpr)"); (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 295 "awk.g.y"
    { PUTS("print>stat"); (yyval) = stat3((intptr_t)(yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 297 "awk.g.y"
    { PUTS("print list"); (yyval) = stat3((intptr_t)(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), nullstat, nullstat); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 299 "awk.g.y"
    { PUTS("printf>stat"); (yyval) = stat3((intptr_t)(yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 301 "awk.g.y"
    { PUTS("printf list"); (yyval) = stat3((intptr_t)(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), nullstat, nullstat); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 302 "awk.g.y"
    { PUTS("expr"); (yyval) = exptostat((yyvsp[(1) - (1)])); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 303 "awk.g.y"
    { PUTS("null simple statement"); (yyval) = nullstat; }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 304 "awk.g.y"
    { yyclearin; yyerror("illegal statement"); (yyval) = nullstat; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 308 "awk.g.y"
    { PUTS("simple stat"); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 309 "awk.g.y"
    { PUTS("if stat"); (yyval) = stat3(IF, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), nullstat); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 311 "awk.g.y"
    { PUTS("if-else stat"); (yyval) = stat3(IF, (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 312 "awk.g.y"
    { PUTS("while stat"); (yyval) = stat2(WHILE, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 313 "awk.g.y"
    { PUTS("for stat"); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 314 "awk.g.y"
    { PUTS("next"); (yyval) = stat1(NEXT, 0); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 315 "awk.g.y"
    { PUTS("exit"); (yyval) = stat1(EXIT, 0); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 316 "awk.g.y"
    { PUTS("exit"); (yyval) = stat1(EXIT, (yyvsp[(2) - (3)])); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 317 "awk.g.y"
    { PUTS("break"); (yyval) = stat1(BREAK, 0); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 318 "awk.g.y"
    { PUTS("continue"); (yyval) = stat1(CONTINUE, 0); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 319 "awk.g.y"
    { PUTS("{statlist}"); (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 323 "awk.g.y"
    { PUTS("stat_list stat"); (yyval) = linkum((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 324 "awk.g.y"
    { PUTS("null stat list"); (yyval) = nullstat; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 328 "awk.g.y"
    { PUTS("while(cond)"); (yyval) = (yyvsp[(3) - (5)]); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 333 "awk.g.y"
    { PUTS("for(e;e;e)"); (yyval) = stat4(FOR, (yyvsp[(3) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(10) - (10)])); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 335 "awk.g.y"
    { PUTS("for(e;e;e)"); (yyval) = stat4(FOR, (yyvsp[(3) - (9)]), nullstat, (yyvsp[(6) - (9)]), (yyvsp[(9) - (9)])); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 337 "awk.g.y"
    { PUTS("for(v in v)"); (yyval) = stat3(IN, (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(8) - (8)])); }
    break;



/* Line 1806 of yacc.c  */
#line 2727 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 340 "awk.g.y"


