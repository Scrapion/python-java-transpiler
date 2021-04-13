
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 3 "parser.y"


#define YYSTYPE char *
#define BUFFER_SIZE 200000

#define S "String"
#define I "int"

#include <stdio.h>
#include <string.h>
#include "symboltable.h"
#include "linkList.h"
#include "string_buffer.h"
#include "list_op.h"

extern FILE* yyin;
extern int yylineno;


int yyerror(char *s);
int yylex();

/*tab counter*/
int tab = 0;
/*tab value of precedent line*/
int otab = 0;
/*Flag for empty line*/
int end=0; 
/* type of current function */
char* currentFType;
/* current scope used for decleration disambiguation in distinct functions */
int currentScope=0;
/*inline flag*/
int in_line = 0;
/*return flag*/
int returnFlag = 0;
/*loose code flag */
int loseCodeFlag =0;
/* main existance flag */
int mainExistanceFlag = 0;
/*emptyStart flag*/
int emptyStart =1;
/*Used Lists flag*/
int listFlag = 0;


/* Cheks existance of variable in symble table else adds entry with respective type and constructs java string in return */
char* decl(char* ,char*, char*,int ); 

/* Builds if string in java having in input string condition*/
char* build_if(char*);

/*Builds java for string given iterable variable and condition variable condition  is alwais LESS THAN*/
char* build_for(char*,char*);

/*Builds strings of matematical expressions*/
char* build_mExp(char*,char*,char*);

/*Builds strings for combined Input\Output operations*/
char* build_IOop(char*,char*);

/*Builds strings for output operations*/
char* build_out(char*);

/* costume string concatenation */
char* myStrCat (char* ,char*);

/*Builds a string contaning function call with rispective decorators*/
char*  buildFCall(char* , char* );

/*gets the function name from a function call*/
char* getFName(char* );

/* builds if condition with % element*/
char*  build_odd_cond(char* , char* ,char* );

/*Adds or modifies element  to symble table*/
void addTipo( char* ,char*,int );

/*This methods are used respectevly to get the number of parenthesis needed and building a string with the parenthesis*/
int pClosure( int,int);
char* buildClosures ( int,int);

/*This function is used to build the decoration of a function*/
char* buildDecoration();
/*This Function builds the string of the java function declaration input: type,name,decoration*/
char* buildFDecleration(char*,char*,char*);

/*this function prints on file opens and closes buffer. on input requires file name*/
void printOnF (char* );

/*This function loads into the buffer a java method to emulate the python pop function */
void loadPopToBuffer();
/*This function loads into the buffer a java method to emulate the python copy function */
void loadCopyToBuffer ();


/* Line 189 of yacc.c  */
#line 171 "parser.tab.c"

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
     END = 258,
     TAB = 259,
     ID = 260,
     ASSIGN = 261,
     STRING = 262,
     NUM = 263,
     LESS = 264,
     MORE = 265,
     EQUALS = 266,
     DIFFER = 267,
     AND = 268,
     PLUS = 269,
     MINUS = 270,
     MULT = 271,
     DIV = 272,
     IF = 273,
     ELSE = 274,
     INR = 275,
     FOR = 276,
     RP = 277,
     LP = 278,
     LS = 279,
     RS = 280,
     COLON = 281,
     INPUT = 282,
     PRINT = 283,
     APPEND = 284,
     CLEAR = 285,
     COUNT = 286,
     EXTEND = 287,
     INSERT = 288,
     INDEX = 289,
     POP = 290,
     REMOVE = 291,
     COPY = 292,
     REVERSE = 293,
     SORT = 294,
     DEF = 295,
     RETURN = 296,
     PERCENT = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 255 "parser.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    14,    16,    17,    20,    21,    24,
      26,    28,    31,    34,    37,    40,    44,    47,    50,    54,
      55,    58,    62,    66,    70,    74,    78,    84,    88,    96,
     102,   109,   114,   119,   125,   130,   135,   141,   147,   154,
     159,   165,   171,   176,   181,   186,   190,   195,   197,   200,
     202,   205,   207,   211,   217,   220,   222,   224,   226,   228,
     230,   234,   238,   240,   242,   244,   246,   248,   250,   252,
     254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    44,    40,     5,    23,    45,    22,
      26,     3,    46,    -1,    46,    -1,    -1,     5,    45,    -1,
      -1,    46,    47,    -1,     3,    -1,    48,    -1,    48,    52,
      -1,    48,    49,    -1,    48,    53,    -1,    48,    50,    -1,
      48,    19,    26,    -1,    48,    51,    -1,    48,    54,    -1,
      48,    41,    58,    -1,    -1,     4,    48,    -1,     5,     6,
       7,    -1,     5,     6,     8,    -1,     5,     6,    59,    -1,
       5,     6,    54,    -1,     5,     6,     5,    -1,    18,    23,
      57,    22,    26,    -1,    18,    57,    26,    -1,    21,    58,
      20,    23,    58,    22,    26,    -1,     5,     6,    27,    23,
      22,    -1,     5,     6,    27,    23,    58,    22,    -1,    28,
      23,    56,    22,    -1,     5,     6,    24,    25,    -1,     5,
      29,    23,    58,    22,    -1,     5,    30,    23,    22,    -1,
       5,    31,    23,    22,    -1,     5,    32,    23,    58,    22,
      -1,     5,    34,    23,    58,    22,    -1,     5,    33,    23,
      58,    58,    22,    -1,     5,    35,    23,    22,    -1,     5,
      35,    23,    58,    22,    -1,     5,    36,    23,    58,    22,
      -1,     5,    37,    23,    22,    -1,     5,    38,    23,    22,
      -1,     5,    39,    23,    22,    -1,     5,    23,    22,    -1,
       5,    23,    55,    22,    -1,    58,    -1,    58,    55,    -1,
      58,    -1,    58,    56,    -1,    58,    -1,    58,    60,    58,
      -1,    58,    42,    58,    11,    58,    -1,    57,    57,    -1,
       5,    -1,     8,    -1,     7,    -1,    53,    -1,    54,    -1,
      58,    61,    58,    -1,    23,    59,    22,    -1,    11,    -1,
      12,    -1,     9,    -1,    10,    -1,    13,    -1,    14,    -1,
      15,    -1,    16,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   123,   158,   168,   169,   172,   173,   198,
     200,   202,   204,   206,   208,   210,   212,   214,   216,   222,
     223,   226,   228,   230,   232,   234,   237,   239,   244,   247,
     249,   251,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   269,   270,   273,   274,   278,
     280,   283,   285,   287,   291,   294,   296,   298,   300,   302,
     305,   307,   310,   312,   314,   316,   318,   321,   322,   323,
     324
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END", "TAB", "ID", "ASSIGN", "STRING",
  "NUM", "LESS", "MORE", "EQUALS", "DIFFER", "AND", "PLUS", "MINUS",
  "MULT", "DIV", "IF", "ELSE", "INR", "FOR", "RP", "LP", "LS", "RS",
  "COLON", "INPUT", "PRINT", "APPEND", "CLEAR", "COUNT", "EXTEND",
  "INSERT", "INDEX", "POP", "REMOVE", "COPY", "REVERSE", "SORT", "DEF",
  "RETURN", "PERCENT", "$accept", "definition", "decoration", "input",
  "line", "tab", "declaration", "selection", "iteration", "IOoperation",
  "list", "function_call", "passing_vallues", "txt", "condition", "type",
  "math_exp", "logic_op", "math_op", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    50,    50,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    61,    61,    61,
      61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     1,     0,     2,     0,     2,     1,
       1,     2,     2,     2,     2,     3,     2,     2,     3,     0,
       2,     3,     3,     3,     3,     3,     5,     3,     7,     5,
       6,     4,     4,     5,     4,     4,     5,     5,     6,     4,
       5,     5,     4,     4,     4,     3,     4,     1,     2,     1,
       2,     1,     3,     5,     2,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,    19,     1,     0,     9,    19,     8,    10,     0,
      20,     0,     0,     0,     0,     0,     0,    12,    14,    16,
      11,    13,    17,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    57,    56,
       0,    58,    59,     0,    51,    15,     0,     0,    18,     5,
       0,    25,    21,    22,     0,     0,     0,    24,     0,    23,
      45,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    54,    64,    65,
      62,    63,    66,     0,     0,     0,     0,    49,     6,     0,
       0,    32,     0,    67,    68,    69,    70,     0,    46,    48,
       0,    34,    35,     0,     0,     0,    39,     0,     0,    42,
      43,    44,     0,     0,    52,     0,    31,    50,     0,    61,
      29,     0,    60,    33,    36,     0,    37,    40,    41,    26,
       0,     0,     7,    30,    38,    53,     0,    19,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    50,     2,     7,     8,    17,    18,    19,    20,
      41,    42,    61,    86,    77,    44,    59,    84,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -15
static const yytype_int16 yypact[] =
{
      17,    18,     1,   -15,     7,   -15,    15,   -15,     4,    -3,
     -15,   106,    58,    -5,     8,     6,     8,   -15,   -15,   -15,
     -15,   -15,   -15,    21,    23,    77,    16,    28,    37,    41,
      45,    48,    49,    52,    56,    68,    70,   124,   -15,   -15,
       8,   -15,   -15,    54,    25,   -15,    24,     8,   -15,    21,
       5,    88,    72,    81,    69,    75,    87,    92,   155,   -15,
     -15,    91,     8,     8,    93,   110,     8,     8,     8,   126,
       8,   128,   142,   151,    90,   144,   -15,     8,   -15,   -15,
     -15,   -15,   -15,     8,     8,   105,   152,     8,   -15,   120,
     153,   -15,   160,   -15,   -15,   -15,   -15,     8,   -15,   -15,
     154,   -15,   -15,   156,     8,   157,   -15,   158,   159,   -15,
     -15,   -15,   161,   166,   -15,     8,   -15,   -15,   180,   -15,
     -15,   162,   -15,   -15,   -15,   163,   -15,   -15,   -15,   -15,
       8,   164,   -15,   -15,   -15,   -15,   165,     3,   -15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -15,   -15,   139,    57,   -15,   184,   -15,   -15,   -15,   -15,
     185,     0,   130,   107,     2,   -14,   141,   -15,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      46,    -4,    48,    -3,     5,     6,     5,     6,    22,    11,
      58,    62,     9,    37,    43,    38,    39,    -2,     3,     6,
      23,    45,    12,    13,    57,    14,    49,    89,    51,    47,
      52,    53,    15,    87,    78,    79,    80,    81,    82,    63,
      58,    -4,    75,    -3,    85,    16,    54,    55,    62,   100,
      56,    64,   103,   104,   105,   107,   108,    -2,     4,    37,
      65,    38,    39,    37,    66,    38,    39,    83,    67,   113,
     114,    68,    69,    87,    37,    70,    38,    39,   121,    71,
      76,    40,    37,   122,    38,    39,   -57,   -57,   -57,   -57,
     125,    72,    54,    73,    74,   -56,   -56,   -56,   -56,    60,
      91,   131,   -55,   -55,   -55,   -55,   -59,   -59,   -59,   -59,
      92,    25,    24,    98,    55,   101,   135,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   115,    25,
      74,    37,   102,    38,    39,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,   118,    25,   106,    37,
     109,    38,    39,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,   110,    37,   112,    38,    39,    93,
      94,    95,    96,   111,   116,   119,   123,   130,   124,   126,
     127,   128,   120,   132,   133,   134,   136,   129,    88,   137,
      10,   138,    99,    21,   117,    90
};

static const yytype_uint8 yycheck[] =
{
      14,     0,    16,     0,     3,     4,     3,     4,     8,     5,
      24,    25,     5,     5,    12,     7,     8,     0,     0,     4,
      23,    26,    18,    19,    24,    21,     5,    22,     5,    23,
       7,     8,    28,    47,     9,    10,    11,    12,    13,    23,
      54,    40,    40,    40,    20,    41,    23,    24,    62,    63,
      27,    23,    66,    67,    68,    69,    70,    40,    40,     5,
      23,     7,     8,     5,    23,     7,     8,    42,    23,    83,
      84,    23,    23,    87,     5,    23,     7,     8,    92,    23,
      26,    23,     5,    97,     7,     8,    14,    15,    16,    17,
     104,    23,    23,    23,     6,    14,    15,    16,    17,    22,
      25,   115,    14,    15,    16,    17,    14,    15,    16,    17,
      23,    23,     6,    22,    24,    22,   130,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    23,    23,
       6,     5,    22,     7,     8,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    26,    23,    22,     5,
      22,     7,     8,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    22,     5,    22,     7,     8,    14,
      15,    16,    17,    22,    22,    22,    22,    11,    22,    22,
      22,    22,    22,     3,    22,    22,    22,    26,    49,   132,
       6,    26,    62,     8,    87,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    46,     0,    40,     3,     4,    47,    48,     5,
      48,     5,    18,    19,    21,    28,    41,    49,    50,    51,
      52,    53,    54,    23,     6,    23,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     5,     7,     8,
      23,    53,    54,    57,    58,    26,    58,    23,    58,     5,
      45,     5,     7,     8,    23,    24,    27,    54,    58,    59,
      22,    55,    58,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,     6,    57,    26,    57,     9,    10,
      11,    12,    13,    42,    60,    20,    56,    58,    45,    22,
      59,    25,    23,    14,    15,    16,    17,    61,    22,    55,
      58,    22,    22,    58,    58,    58,    22,    58,    58,    22,
      22,    22,    22,    58,    58,    23,    22,    56,    26,    22,
      22,    58,    58,    22,    22,    58,    22,    22,    22,    26,
      11,    58,     3,    22,    22,    58,    22,    46,    26
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 3:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {    char* dec;
                                                                if(strcmp(strdup((yyvsp[(3) - (9)])),"main")==0){
                                                                    dec = "String []args";
                                                                    currentFType="void";

                                                                    mainExistanceFlag = 1;
                                                                    if(loseCodeFlag){insetrOnTop("loose_code();\n");loseCodeFlag=0;}

                                                                }else{ 
                                                                    dec = buildDecoration();
                                                                }
                                                                
                                                                if(returnFlag == 0){currentFType="void";}
                                                                returnFlag =0;
                                                                

                                                                char* top = buildFDecleration(currentFType,(yyvsp[(3) - (9)]),dec);
                                                                insetrOnTop(top);
                                                                
                                                                char* closures = buildClosures(otab,tab );
                                                                insertBuffer(closures);
                                                                
                                                                printBuffer() ;

                                                                printOnF ("newprogram.java") ;

                                                                clearBuffer();
                                                                clearList();


                                                                otab=0;
                                                                tab=0;
                                                                 
                                                                currentScope++;
                                                            ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {  if(!emptyStart){  char* top = buildFDecleration("void","loose_code"," ");
                                                                insetrOnTop(top);
                                                                insertBuffer("}");
                                                                printBuffer() ;printOnF ("newprogram.java");clearBuffer();
                                                                loseCodeFlag=1;};}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {currentFType = "void";;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { addList((yyvsp[(1) - (2)])); currentFType = "void"; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {   
                                                if(!end){     

                                                    emptyStart=0;
                                                    in_line = 0;
                                                    char* closures = buildClosures(otab,tab );
                                                    insertBuffer(closures);
                                                    insertBuffer(strdup((yyvsp[(2) - (2)])));
                                                    insertBuffer("\n");
                                                    otab=tab; 
                                                    tab=0;                                                    
                                                
                                                }else{
                                                    in_line = 0;
                                                    end=0;
                                                    insertBuffer(strdup((yyvsp[(2) - (2)])));
                                                    tab=0;                                                    
                                                }
                                            ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {(yyval)="\n";end=1;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);  ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {  (yyval) = strdup((yyvsp[(2) - (2)])); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {  (yyval) = strdup((yyvsp[(2) - (2)])); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {   if(in_line==0){(yyval) = myStrCat(strdup((yyvsp[(2) - (2)])),";");}else{(yyval) = strdup((yyvsp[(2) - (2)]));} listFlag = 1; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {  (yyval) =strdup((yyvsp[(2) - (2)]));    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { (yyval)="else{";      ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {  (yyval) = strdup((yyvsp[(2) - (2)]));   ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval) = myStrCat( strdup((yyvsp[(2) - (2)])),";"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {if( strcmp(  getType((yyvsp[(3) - (3)])),"ERROR")!=0){currentFType=getType((yyvsp[(3) - (3)]));}      char* ret=myStrCat("return ",strdup((yyvsp[(3) - (3)])));(yyval)=myStrCat(ret,";"); returnFlag=1;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {tab++; (yyval)="\t";;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {(yyval) = decl(strdup((yyvsp[(1) - (3)])), S ,strdup((yyvsp[(3) - (3)])),currentScope ); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {(yyval) = decl(strdup((yyvsp[(1) - (3)])), I ,strdup((yyvsp[(3) - (3)])),currentScope ); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {(yyval) = decl(strdup((yyvsp[(1) - (3)])), I ,strdup((yyvsp[(3) - (3)])),currentScope ); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {(yyval) = decl(strdup((yyvsp[(1) - (3)])),getType(getFName((yyvsp[(3) - (3)]))),strdup((yyvsp[(3) - (3)])),currentScope);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {(yyval) = decl(strdup((yyvsp[(1) - (3)])),getType(getFName((yyvsp[(3) - (3)]))),strdup((yyvsp[(3) - (3)])),currentScope);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { (yyval) = build_if(strdup((yyvsp[(3) - (5)])));  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval) = build_if(strdup((yyvsp[(2) - (3)])));  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {(yyval)=build_for(strdup((yyvsp[(2) - (7)])),strdup((yyvsp[(5) - (7)])));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {(yyval) = decl(strdup((yyvsp[(1) - (5)])), S ,"tastiera.nextLine()",currentScope );;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {(yyval) = build_IOop(strdup((yyvsp[(1) - (6)])),strdup((yyvsp[(5) - (6)])));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {(yyval) = build_out(strdup((yyvsp[(3) - (4)])));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    {(yyval)= newList(strdup((yyvsp[(1) - (4)]))); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {(yyval)= appendList (strdup((yyvsp[(1) - (5)])),strdup((yyvsp[(4) - (5)]))  );  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {(yyval)=clList ( strdup((yyvsp[(1) - (4)]))   );  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {(yyval)= countList ( strdup((yyvsp[(1) - (4)]))  );  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {(yyval)= extendList ( strdup((yyvsp[(1) - (5)])),strdup((yyvsp[(4) - (5)])) ); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {(yyval)= indexList ( strdup((yyvsp[(1) - (5)])),strdup((yyvsp[(4) - (5)]))  );  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {(yyval)=  insertList( strdup((yyvsp[(1) - (6)])),strdup((yyvsp[(4) - (6)])),strdup((yyvsp[(5) - (6)])) ); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {(yyval)=  popList (strdup((yyvsp[(1) - (4)]))    );  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {(yyval)= popElList ( strdup((yyvsp[(1) - (5)])),strdup((yyvsp[(4) - (5)]))  );  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {(yyval)=removeList( strdup((yyvsp[(1) - (5)])),strdup((yyvsp[(4) - (5)]))   ); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {(yyval)= copyList( strdup((yyvsp[(1) - (4)]))  ); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {(yyval)= reverseList( strdup((yyvsp[(1) - (4)]))  ); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {(yyval)= sortList( strdup((yyvsp[(1) - (4)]))  ); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {(yyval) = buildFCall(strdup((yyvsp[(1) - (3)]))," ");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    {(yyval) = buildFCall(strdup((yyvsp[(1) - (4)])),strdup((yyvsp[(3) - (4)])));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    {(yyval) = myStrCat(strdup((yyvsp[(1) - (2)])),strdup(",")); (yyval) = myStrCat(strdup((yyval)),strdup((yyvsp[(2) - (2)])));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {(yyval)=(yyvsp[(1) - (2)]);strcat((yyval),"+");strcat((yyval),(yyvsp[(2) - (2)]));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);addTipo(strdup((yyvsp[(1) - (1)])),"int",currentScope);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]); strcat((yyval),(yyvsp[(2) - (3)])); strcat((yyval),(yyvsp[(3) - (3)]));addTipo(strdup((yyvsp[(1) - (3)])),"int",currentScope);addTipo(strdup((yyvsp[(3) - (3)])),"int",currentScope); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {(yyval) = build_odd_cond(strdup((yyvsp[(1) - (5)])),strdup((yyvsp[(3) - (5)])),strdup((yyvsp[(5) - (5)])));
                                                            addTipo(strdup((yyvsp[(1) - (5)])),"int",currentScope);
                                                            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]); strcat((yyval)," ");strcat((yyval),(yyvsp[(2) - (2)])); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    {(yyval) = strdup((yyvsp[(1) - (1)]));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {(yyval) = strdup((yyvsp[(1) - (1)]));currentFType = "Int";;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {(yyval) = strdup((yyvsp[(1) - (1)])); currentFType = "String";;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {(yyval) = strdup((yyvsp[(1) - (1)])); in_line=1;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {(yyval) = strdup((yyvsp[(1) - (1)]));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {(yyval)= build_mExp((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {(yyval)= build_mExp("(",strdup((yyvsp[(2) - (3)])),")");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    { (yyval) = "==";;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    {(yyval) = "!="; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {(yyval) = "<"; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {(yyval) = ">"; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    {(yyval) = "&&";;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    {(yyval)="+";;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    {(yyval)="-";;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {(yyval)="*";;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {(yyval)="/";;}
    break;



/* Line 1455 of yacc.c  */
#line 2099 "parser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 329 "parser.y"



char* buildDecoration(){

    if(!isEmpty()){
        
        char buffer[BUFFER_SIZE];
        *buffer=NULL;
        while(!isEmpty())
        {
            struct node* element = pop();
            char* nome = element->nome;
            char* tipo = getType(element->nome);
            
            if(Listlength()!=0){ 
                char* tmp= buffer;
                snprintf(buffer, sizeof(buffer), "%s %s %s , ",tmp , tipo,nome);
            }else{
                char* tmp= buffer;
                snprintf(buffer, sizeof(buffer), "%s %s %s ",tmp , tipo,nome);
            }
            
        }
        char* str = buffer;
        return str;
    }
    return " ";
}


char* decl( char* name, char* type, char* val,int currentScope){  

    char buffer[2048];
    
    if(exist(name) == 1 && getScope(name)==currentScope){
        
        snprintf(buffer, sizeof(buffer), "%s = %s ;" , name,val);
        char* ass = buffer;
        return ass;

    }
    else if(exist(name) == 1 && getScope(name)!=currentScope){
        
        snprintf(buffer, sizeof(buffer), "%s %s = %s ;" , type, name,val);   
        setScope(name,currentScope);
        char* ass = buffer;
        return ass;

    }
    else{        
        
        addref(yylineno,  name, type,currentScope);        
        
        snprintf(buffer, sizeof(buffer), "%s %s = %s ;" , type, name,val);        
        char* dec = buffer;
        
        return dec;

    }


}


char* build_if(char* cond){
   
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "if ( %s ){ " , cond);
    char* sel = buffer;
    return sel;

}


int pClosure(int otab,int tab ){
    int closures=0;
    
    //while ( otab > tab ){ closures++;otab--;}
    
    if(otab>tab){closures = otab-tab;}
    

    return closures;     

}


char* build_for(char* iter,char* cond){
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "for(;%s<%s;%s++){" ,iter, cond,iter);
    char* str = buffer;
    return str;
}


char* build_mExp(char* l,char* c,char* r){
    char buffer[1024];
    
    snprintf(buffer, sizeof(buffer), "%s %s %s",l,c,r);
    char* str = buffer;
    return str;
}


char* build_IOop(char* id,char* strout){
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s\n%s " ,build_out (strout), decl(id, S ,"tastiera.nextLine()" ,currentScope) );
    char* str = buffer;
    return str;
}

char* build_out (char* outs){
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "System.out.println( %s );" ,outs );
    char* str = buffer;
    return str;
}

char* myStrCat (char* l ,char* r){
    

    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s%s" ,l,r );
  
    char* str = buffer;
    
    return str;
}



void addTipo( char* var,char* tipo,int currentScope)
{
    if (exist(var))
    {
        modtype(var,tipo,currentScope);
    }else{
        addref(yylineno,  var, tipo,currentScope); 
    }

}


char*  buildFCall(char* name, char* values)
{   
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s(%s)" , name,values);
    char* fun = buffer;
    
    return fun;

}

char*  build_odd_cond(char* element, char* divisor,char* equals)
{   
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s %% %s == %s" , element,divisor,equals);
    char* cnd = buffer;
    
    return cnd;

}
char* getFName(char* fun){char *sym = strtok(fun, "("); return sym;}

char* buildClosures ( int otab,int tab )
{   
    int cl = pClosure(otab,tab );
    if(cl!=0){
    
    char* cnd =malloc(sizeof(char));
    
    while (cl>0){ 
        strcat(cnd,"}");
        cl--;
    }   
    return cnd;    
    }
    else
    {
        return " ";
    } 
    
}

char* buildFDecleration(char* tipo,char* nome,char* dec)
{
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "public static %s %s ( %s ) { \n",tipo,nome,dec );
  
    
    char* str = buffer;
    
    return str;
}


int yyerror(char* s) {
    
    printf("%s in linea : %d \n", s , yylineno);
    
}


void printOnF (char* name )
{
    FILE *fptr;

    fptr = fopen(name,"a");

    printBufferOnFile(fptr);

    fclose(fptr);

}

void loadPopToBuffer (){

    insertBuffer("public static Object popList (ArrayList lst, int j) \n" );    
    insertBuffer("{\n Object temp = new Object();\n");
    insertBuffer(" temp = lst.get(j);\n lst.remove(j);\n");   
    insertBuffer(" return temp;\n}\n");
    
    
}

void loadCopyToBuffer (){

  insertBuffer( "public static ArrayList copyList ( ArrayList toCopy){\n" );
  insertBuffer(" ArrayList copy = new ArrayList();\n");
  insertBuffer( "copy.addAll(toCopy); \n return copy;}   ");
    
    
}

int main(int argc, char const *argv[]) {
    
    
    insertBuffer("import java.util.ArrayList;\n");
    insertBuffer("import java.util.Collections;\n");
    insertBuffer("public class CLASSNAME{ \n");
    printBuffer() ;
    //printOnF ("newprogram.java") ;
    clearBuffer();

    

    yyin = fopen(argv[1], "r");

    int result_code = yyparse();

    fclose(yyin);

    if (!mainExistanceFlag && loseCodeFlag)
    {
        insertBuffer("public void main ( ){\n");
        insertBuffer("loose_code();\n");
        insertBuffer("}\n");


    }    


    if(listFlag)
    {
        printBuffer() ;
        clearBuffer();
        loadPopToBuffer ();
        loadCopyToBuffer ();
    }

    insertBuffer("}\n");

    

    printBuffer() ;
    printOnF ("newprogram.java") ;
    
    
    return result_code;
}
