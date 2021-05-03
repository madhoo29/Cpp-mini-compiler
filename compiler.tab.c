/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_MAIN = 258,
     T_WHILE = 259,
     T_IF = 260,
     T_ELSE = 261,
     T_INCLUDE = 262,
     T_HEADER = 263,
     T_SWITCH = 264,
     T_CASE = 265,
     T_PRINT = 266,
     T_INT = 267,
     T_DOUBLE = 268,
     T_BOOL = 269,
     T_CHAR = 270,
     T_STRING = 271,
     T_VOID = 272,
     STRING_TERMINATE = 273,
     T_COUT = 274,
     T_CIN = 275,
     T_EXT = 276,
     T_INS = 277,
     T_BREAK = 278,
     T_DEFAULT = 279,
     T_GE = 280,
     T_LE = 281,
     T_EQ = 282,
     T_NE = 283,
     T_OR = 284,
     T_AND = 285,
     T_NEWLINE = 286,
     T_CHAR_VAL = 287,
     T_FLOAT_VAL = 288,
     T_INTEGER_VAL = 289,
     T_STRING_VAL = 290,
     IDENTIFIER = 291,
     NOT_STRING = 292,
     T_LOGICAL_OR = 293,
     T_LOGICAL_AND = 294,
     T_NOT_EQ = 295,
     T_GR_EQ = 296,
     T_LS_EQ = 297,
     T_INC = 298,
     T_DEC = 299,
     T_TRUE = 300,
     T_FALSE = 301,
     T_RETURN = 302,
     T_CONST = 303,
     T_AUTO = 304,
     T_CLASS = 305,
     T_PRIVATE = 306,
     T_PUBLIC = 307,
     T_PROTECTED = 308
   };
#endif
/* Tokens.  */
#define T_MAIN 258
#define T_WHILE 259
#define T_IF 260
#define T_ELSE 261
#define T_INCLUDE 262
#define T_HEADER 263
#define T_SWITCH 264
#define T_CASE 265
#define T_PRINT 266
#define T_INT 267
#define T_DOUBLE 268
#define T_BOOL 269
#define T_CHAR 270
#define T_STRING 271
#define T_VOID 272
#define STRING_TERMINATE 273
#define T_COUT 274
#define T_CIN 275
#define T_EXT 276
#define T_INS 277
#define T_BREAK 278
#define T_DEFAULT 279
#define T_GE 280
#define T_LE 281
#define T_EQ 282
#define T_NE 283
#define T_OR 284
#define T_AND 285
#define T_NEWLINE 286
#define T_CHAR_VAL 287
#define T_FLOAT_VAL 288
#define T_INTEGER_VAL 289
#define T_STRING_VAL 290
#define IDENTIFIER 291
#define NOT_STRING 292
#define T_LOGICAL_OR 293
#define T_LOGICAL_AND 294
#define T_NOT_EQ 295
#define T_GR_EQ 296
#define T_LS_EQ 297
#define T_INC 298
#define T_DEC 299
#define T_TRUE 300
#define T_FALSE 301
#define T_RETURN 302
#define T_CONST 303
#define T_AUTO 304
#define T_CLASS 305
#define T_PRIVATE 306
#define T_PUBLIC 307
#define T_PROTECTED 308




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "symboltable.c"

    int yylex();
    extern int yylineno;
    extern char* yytext;
    int scope = 0;
    int err;
    int type;
    int idx = 0;
    FILE * fp;
    FILE * qptr;
    FILE* tptr;
    char* id;
    int top=-1;
    int top2 = -1;
    int ch;
    void while1();
    void while2();
    void while3();
    void switch1();
    void test();
    void next();
    void casestart();
    void caseend();
    void push_t();
    void push_op(char*);
    void codegen();
    void codegen_assign();
    void codegen_assigna();
    void arg1();
    void funcall();
    void fun1();
    void fun2();
    void postinc();
    void preinc();
    void postdec();
    void predec();
    void array_assign();
    void array_val();
    int num_cases = 0;
    char cases[20];
    int arg_count = 0;

    typedef struct quadruples
    {
        char* op;
        sym* arg1;
        sym* arg2;
        sym* res;
    } quad;

    int quadlen = 0;
    quad q[100];
    sym* case_var;
 
    void yyerror(const char *str)
    {
        fprintf(tptr,"Error at line: %d %s %s\n",yylineno,str,yytext);
    }




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 96 "compiler.y"
{  
  struct {
     char* strval;
     int  intval;
  } structure;
}
/* Line 193 of yacc.c.  */
#line 276 "compiler.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 301 "compiler.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,     2,     2,
      67,    68,    48,    46,    69,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    65,
      42,    38,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
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
      35,    36,    37,    39,    40,    41,    44,    45,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    16,    19,    22,    25,
      26,    30,    34,    35,    38,    39,    41,    43,    44,    45,
      51,    53,    55,    57,    59,    61,    63,    65,    67,    70,
      73,    76,    78,    80,    82,    85,    88,    91,    92,   102,
     103,   111,   115,   118,   119,   120,   121,   129,   133,   135,
     136,   142,   143,   150,   154,   156,   163,   164,   176,   180,
     182,   183,   185,   187,   191,   193,   194,   200,   201,   210,
     215,   220,   221,   222,   228,   229,   230,   236,   238,   239,
     240,   246,   247,   248,   254,   256,   258,   260,   262,   264,
     266,   271,   273,   275,   277,   279,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   300,   303,   306,   309,   313,
     317,   320,   321,   322,   330,   332,   334,   338,   340,   342,
     344,   346,   348,   350,   352,   354,   356,   358,   359,   360,
     370,   372,   375,   377,   380,   381,   389
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      73,     0,    -1,    74,    -1,     7,     8,    74,    -1,     7,
       8,    75,    -1,    76,    77,    -1,    76,    87,    -1,    76,
      85,    -1,    76,    95,    -1,    -1,    12,     3,    80,    -1,
      17,     3,    80,    -1,    -1,    78,    79,    -1,    -1,    80,
      -1,    83,    -1,    -1,    -1,    63,    81,    78,    64,    82,
      -1,   125,    -1,    95,    -1,   131,    -1,   102,    -1,    94,
      -1,   124,    -1,   105,    -1,   106,    -1,   122,    65,    -1,
     123,    65,    -1,    23,    65,    -1,    85,    -1,    90,    -1,
      65,    -1,    61,    66,    -1,    60,    66,    -1,    62,    66,
      -1,    -1,    59,    36,    63,    86,    84,    75,    84,    75,
      64,    -1,    -1,   121,    36,    88,    67,    89,    68,    80,
      -1,   121,    36,    89,    -1,    69,    89,    -1,    -1,    -1,
      -1,    36,    91,    67,    93,    92,    68,    65,    -1,    93,
      69,   107,    -1,   107,    -1,    -1,    11,    67,    35,    68,
      65,    -1,    -1,   121,    36,    38,    96,   107,    65,    -1,
     121,   101,    65,    -1,    97,    -1,   121,    36,    70,   107,
      71,    65,    -1,    -1,   121,    36,    70,   107,    71,    98,
      38,    63,    99,    64,    65,    -1,    99,    69,   100,    -1,
     100,    -1,    -1,    34,    -1,    32,    -1,   101,    69,    36,
      -1,    36,    -1,    -1,    36,    38,   103,   107,    65,    -1,
      -1,    36,    70,   119,    71,    38,   120,   104,    65,    -1,
      20,    22,    36,    65,    -1,    19,    21,    35,    65,    -1,
      -1,    -1,   107,   108,    46,   109,   112,    -1,    -1,    -1,
     107,   110,    47,   111,   112,    -1,   112,    -1,    -1,    -1,
     112,   113,    48,   114,   117,    -1,    -1,    -1,   112,   115,
      49,   116,   117,    -1,   117,    -1,   118,    -1,    36,    -1,
     120,    -1,   122,    -1,   123,    -1,    36,    70,   119,    71,
      -1,    36,    -1,   120,    -1,   122,    -1,   123,    -1,    34,
      -1,    33,    -1,    32,    -1,    35,    -1,    12,    -1,    13,
      -1,    17,    -1,    15,    -1,    16,    -1,    36,    52,    -1,
      52,    36,    -1,    36,    53,    -1,    53,    36,    -1,    56,
      36,    65,    -1,    56,   120,    65,    -1,    56,    65,    -1,
      -1,    -1,     4,   126,    67,   128,    68,   127,    80,    -1,
     120,    -1,    36,    -1,   107,   129,   107,    -1,    54,    -1,
      55,    -1,    42,    -1,    43,    -1,    28,    -1,    27,    -1,
      26,    -1,    25,    -1,    34,    -1,    32,    -1,    -1,    -1,
       9,   132,    67,   107,   133,    68,    63,   134,    64,    -1,
     135,    -1,   135,   138,    -1,   136,    -1,   135,   136,    -1,
      -1,    10,   130,   137,    66,    78,    23,    65,    -1,    24,
      66,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   109,   110,   113,   115,   116,   117,   118,
     123,   124,   125,   128,   129,   132,   133,   137,   137,   137,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   159,   160,   161,   164,   164,   167,
     167,   182,   183,   184,   187,   193,   187,   195,   196,   197,
     200,   202,   202,   217,   218,   221,   226,   226,   238,   240,
     242,   245,   246,   250,   256,   264,   264,   272,   272,   293,
     296,   299,   299,   299,   304,   304,   304,   305,   308,   308,
     308,   309,   309,   309,   310,   312,   314,   319,   321,   322,
     323,   330,   334,   336,   337,   340,   341,   342,   343,   347,
     348,   349,   350,   351,   354,   357,   361,   364,   369,   370,
     371,   374,   374,   374,   377,   378,   379,   380,   381,   384,
     385,   386,   387,   388,   389,   391,   392,   394,   394,   394,
     397,   398,   401,   402,   405,   405,   409
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_MAIN", "T_WHILE", "T_IF", "T_ELSE",
  "T_INCLUDE", "T_HEADER", "T_SWITCH", "T_CASE", "T_PRINT", "T_INT",
  "T_DOUBLE", "T_BOOL", "T_CHAR", "T_STRING", "T_VOID", "STRING_TERMINATE",
  "T_COUT", "T_CIN", "T_EXT", "T_INS", "T_BREAK", "T_DEFAULT", "T_GE",
  "T_LE", "T_EQ", "T_NE", "T_OR", "T_AND", "T_NEWLINE", "T_CHAR_VAL",
  "T_FLOAT_VAL", "T_INTEGER_VAL", "T_STRING_VAL", "IDENTIFIER",
  "NOT_STRING", "'='", "T_LOGICAL_OR", "T_LOGICAL_AND", "T_NOT_EQ", "'<'",
  "'>'", "T_GR_EQ", "T_LS_EQ", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "T_INC", "T_DEC", "T_TRUE", "T_FALSE", "T_RETURN", "T_CONST", "T_AUTO",
  "T_CLASS", "T_PRIVATE", "T_PUBLIC", "T_PROTECTED", "'{'", "'}'", "';'",
  "':'", "'('", "')'", "','", "'['", "']'", "$accept", "BEGIN", "preproc",
  "Functions", "cf", "main", "statements", "stmt", "compound_stmt", "@1",
  "@2", "single_stmt", "access", "Class", "@3", "Function_Dec", "@4",
  "Parameters", "Function_call", "@5", "@6", "Arguments", "Print",
  "Decleration", "@7", "ArrayDec", "@8", "ArrayObj", "Arraytype",
  "Listvariables", "Assignment", "@9", "@10", "Input", "Output", "exp",
  "@11", "@12", "@13", "@14", "Term", "@15", "@16", "@17", "@18", "Factor",
  "Literal", "Index", "consttype", "Type", "increment", "decrement",
  "Return", "While", "@19", "@20", "global_check", "relop", "constcases",
  "Switch", "@21", "@22", "Cases", "Case", "C", "@23", "Default", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,    61,   293,
     294,   295,    60,    62,   296,   297,    43,    45,    42,    47,
      37,    33,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   123,   125,    59,    58,    40,    41,    44,
      91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    75,    76,    76,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    81,    82,    80,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    86,    85,    88,
      87,    89,    89,    89,    91,    92,    90,    93,    93,    93,
      94,    96,    95,    95,    95,    97,    98,    97,    99,    99,
      99,   100,   100,   101,   101,   103,   102,   104,   102,   105,
     106,   108,   109,   107,   110,   111,   107,   107,   113,   114,
     112,   115,   116,   112,   112,   117,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   126,   127,   125,   128,   128,   128,   128,   128,   129,
     129,   129,   129,   129,   129,   130,   130,   132,   133,   131,
     134,   134,   135,   135,   137,   136,   138
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     2,     2,     0,
       3,     3,     0,     2,     0,     1,     1,     0,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     2,     2,     2,     0,     9,     0,
       7,     3,     2,     0,     0,     0,     7,     3,     1,     0,
       5,     0,     6,     3,     1,     6,     0,    11,     3,     1,
       0,     1,     1,     3,     1,     0,     5,     0,     8,     4,
       4,     0,     0,     5,     0,     0,     5,     1,     0,     0,
       5,     0,     0,     5,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     3,
       2,     0,     0,     7,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     9,
       1,     2,     1,     2,     0,     7,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     9,     1,     3,     4,    12,    99,
     100,   102,   103,   101,     0,     5,     7,     6,     8,    54,
       0,     0,     0,     0,    64,     0,    17,    10,    11,    37,
      51,     0,     0,    53,     0,    14,     0,     0,    97,    96,
      95,    98,    86,     0,     0,    71,    77,    84,    85,    87,
      88,    89,    43,    63,     0,     0,     0,     0,     9,    71,
     104,   106,     0,   105,   107,    56,     0,     0,     0,     0,
      99,   101,    43,     0,     0,   111,   127,     0,     0,     0,
       0,    44,     0,    18,    33,    13,    15,    16,    31,    32,
      24,    21,    23,    26,    27,     0,     0,     0,    25,    20,
      22,    35,    34,    36,     0,    52,    91,     0,    92,    93,
      94,    55,     0,    72,    75,    79,    82,    42,     0,    43,
       0,     0,     0,     0,     0,    30,    65,     0,     0,     0,
     110,     0,    19,    64,    28,    29,     9,    90,     0,     0,
       0,     0,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,    49,   108,   109,     0,    60,    73,    76,    80,
      83,    86,   117,   118,    71,    87,     0,    71,     0,    70,
      69,    71,     0,    45,    48,    38,    62,    61,     0,    59,
     124,   123,   122,   121,   119,   120,     0,   112,     0,    50,
      66,     0,     0,     0,     0,     0,    71,     0,     0,    67,
      47,     0,    57,    58,   113,     0,     0,    46,     0,     0,
     130,   132,    68,   126,   125,   134,   129,     0,   133,   131,
       0,    14,    14,   136,     0,     0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    15,    54,    85,    86,    35,
     132,    87,    58,    88,    36,    17,    32,    73,    89,   128,
     193,   173,    90,    91,    37,    19,   112,   178,   179,    25,
      92,   150,   206,    93,    94,    45,    66,   139,    67,   140,
      46,    68,   141,    69,   142,    47,    48,   107,    49,    74,
      50,    51,    98,    99,   120,   197,   166,   186,   215,   100,
     121,   188,   209,   210,   211,   220,   219
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
       8,    11,    32,   -73,     8,   -73,   -73,   -73,    35,    59,
     -73,   -73,   -73,    70,    46,   -73,   -73,   -73,   -73,   -73,
      79,    63,    63,    67,   -11,    30,   -73,   -73,   -73,   -73,
     -73,   170,    55,   -73,    98,   -73,   100,   170,   -73,   -73,
     -73,   -73,    44,   106,   110,   -16,    54,   -73,   -73,   -73,
     -73,   -73,    21,   -73,     5,    86,    92,    97,   -73,   -35,
     -73,   -73,   175,   -73,   -73,    71,   121,   129,   134,   139,
     -73,   -73,    21,   115,   153,   -73,   -73,   125,   173,   174,
     130,    22,    73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   176,   148,   149,   -73,   -73,
     -73,   -73,   -73,   -73,   100,   -73,    58,   150,   -73,   -73,
     -73,   -73,   186,   -73,   -73,   -73,   -73,   -73,    63,    21,
     158,   159,   194,   195,   196,   -73,   -73,   175,   164,   168,
     -73,   169,   -73,   -28,   -73,   -73,   -73,   -73,   172,   170,
     170,   170,   170,   -73,   -73,   165,   170,   171,   177,   178,
     170,   166,   170,   -73,   -73,   180,    31,    54,    54,   -73,
     -73,    48,   -73,   -73,   143,   179,   181,   -24,   183,   -73,
     -73,     2,   198,   182,    82,   -73,   -73,   -73,   -29,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   170,   -73,   184,   -73,
     -73,   122,   170,   185,   189,    31,    -2,    63,   187,   -73,
      82,   190,   -73,   -73,   -73,   228,   191,   -73,    91,   193,
      19,   -73,   -73,   -73,   -73,   -73,   -73,   192,   -73,   -73,
     197,   -73,   -73,    68,   128,   199,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   236,   -50,   -73,   -73,   -72,   -73,   -20,   -73,
     -73,   -73,   137,   237,   -73,   -73,   -73,   -65,   -73,   -73,
     -73,   -73,   -73,   238,   -73,   -73,   -73,   -73,    64,   -73,
     -73,   -73,   -73,   -73,   -73,   -33,   -73,   -73,   -73,   -73,
      26,   -73,   -73,   -73,   -73,    37,   -73,   133,   -56,    -8,
     -51,   -49,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    51,   -73,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -136
static const yytype_int16 yytable[] =
{
      20,    27,    28,    96,    59,    97,   108,   117,   104,    75,
      30,   109,   -74,   110,    76,     1,    77,    70,    10,     4,
      11,    12,    71,   -74,    78,    79,   131,    30,    80,   208,
     105,   -74,     5,    70,    10,   194,    11,    12,    71,  -135,
     195,    81,    31,   217,  -128,   -74,    95,     9,    10,   -74,
      11,    12,    13,  -135,   144,    65,   -39,    43,    44,    31,
     126,    82,    21,   176,    14,   177,  -116,   190,    26,    83,
      84,   108,    75,    22,    60,    61,   109,    76,   110,    77,
      70,    10,    23,    11,    12,    71,   155,    78,    79,   165,
      72,    80,   127,  -135,    14,    33,    60,    61,   143,    34,
      60,    61,   -78,   -81,    81,    38,    39,    40,    41,   129,
      60,    61,   164,   167,    62,    24,  -115,   171,    62,   174,
      43,    44,    52,   213,    82,   214,    26,    14,   -71,   -74,
      29,    26,    75,    84,    53,   199,   111,    76,   130,    77,
      70,    10,    63,    11,    12,    71,    64,    78,    79,   223,
     224,   225,   101,   196,    38,    39,    40,    41,   102,   200,
      55,    56,    57,   103,    81,   157,   158,   113,   180,   181,
     182,   183,    96,    96,    97,    97,   114,   204,   159,   160,
      43,    44,   115,   118,    82,   184,   185,    14,   116,   119,
     -74,    26,   122,    84,   123,   125,   124,    38,    39,    40,
      41,   161,    38,    39,    40,    41,    42,    38,    39,    40,
      41,   106,   133,   134,   135,    95,    95,    43,    44,   162,
     163,   137,    43,    44,   138,   145,   146,    43,    44,   147,
     148,   152,   149,   153,   154,   156,   191,   172,   208,   168,
       6,   136,   169,   170,   175,    16,    18,  -114,   189,   187,
     205,   192,   198,   201,   202,   207,   212,   216,   221,   203,
     151,   218,     0,   222,   226
};

static const yytype_int16 yycheck[] =
{
       8,    21,    22,    54,    37,    54,    62,    72,    58,     4,
      38,    62,    47,    62,     9,     7,    11,    12,    13,     8,
      15,    16,    17,    47,    19,    20,    82,    38,    23,    10,
      65,    47,     0,    12,    13,    64,    15,    16,    17,    10,
      69,    36,    70,    24,    68,    47,    54,    12,    13,    47,
      15,    16,    17,    24,   119,    71,    67,    52,    53,    70,
      38,    56,     3,    32,    59,    34,    68,    65,    63,    64,
      65,   127,     4,     3,    52,    53,   127,     9,   127,    11,
      12,    13,    36,    15,    16,    17,   136,    19,    20,   145,
      69,    23,    70,    64,    59,    65,    52,    53,   118,    69,
      52,    53,    48,    49,    36,    32,    33,    34,    35,    36,
      52,    53,   145,   146,    70,    36,    68,   150,    70,   152,
      52,    53,    67,    32,    56,    34,    63,    59,    46,    47,
      63,    63,     4,    65,    36,   191,    65,     9,    65,    11,
      12,    13,    36,    15,    16,    17,    36,    19,    20,   221,
     222,    23,    66,   186,    32,    33,    34,    35,    66,   192,
      60,    61,    62,    66,    36,   139,   140,    46,    25,    26,
      27,    28,   223,   224,   223,   224,    47,   197,   141,   142,
      52,    53,    48,    68,    56,    42,    43,    59,    49,    36,
      47,    63,    67,    65,    21,    65,    22,    32,    33,    34,
      35,    36,    32,    33,    34,    35,    36,    32,    33,    34,
      35,    36,    36,    65,    65,   223,   224,    52,    53,    54,
      55,    71,    52,    53,    38,    67,    67,    52,    53,    35,
      35,    67,    36,    65,    65,    63,    38,    71,    10,    68,
       4,   104,    65,    65,    64,     8,     8,    68,    65,    68,
      63,    69,    68,    68,    65,    65,    65,    64,    66,   195,
     127,   210,    -1,    66,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    73,    74,     8,     0,    74,    75,    76,    12,
      13,    15,    16,    17,    59,    77,    85,    87,    95,    97,
     121,     3,     3,    36,    36,   101,    63,    80,    80,    63,
      38,    70,    88,    65,    69,    81,    86,    96,    32,    33,
      34,    35,    36,    52,    53,   107,   112,   117,   118,   120,
     122,   123,    67,    36,    78,    60,    61,    62,    84,   107,
      52,    53,    70,    36,    36,    71,   108,   110,   113,   115,
      12,    17,    69,    89,   121,     4,     9,    11,    19,    20,
      23,    36,    56,    64,    65,    79,    80,    83,    85,    90,
      94,    95,   102,   105,   106,   121,   122,   123,   124,   125,
     131,    66,    66,    66,    75,    65,    36,   119,   120,   122,
     123,    65,    98,    46,    47,    48,    49,    89,    68,    36,
     126,   132,    67,    21,    22,    65,    38,    70,    91,    36,
      65,   120,    82,    36,    65,    65,    84,    71,    38,   109,
     111,   114,   116,    80,    89,    67,    67,    35,    35,    36,
     103,   119,    67,    65,    65,    75,    63,   112,   112,   117,
     117,    36,    54,    55,   107,   120,   128,   107,    68,    65,
      65,   107,    71,    93,   107,    64,    32,    34,    99,   100,
      25,    26,    27,    28,    42,    43,   129,    68,   133,    65,
      65,    38,    69,    92,    64,    69,   107,   127,    68,   120,
     107,    68,    65,   100,    80,    63,   104,    65,    10,   134,
     135,   136,    65,    32,    34,   130,    64,    24,   136,   138,
     137,    66,    66,    78,    78,    23,    65
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 13:
#line 128 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(2) - (2)].structure.intval);;}
    break;

  case 15:
#line 132 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(1) - (1)].structure.intval);;}
    break;

  case 16:
#line 133 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(1) - (1)].structure.intval); ;}
    break;

  case 17:
#line 137 "compiler.y"
    {scope++;enter_scope(scope); ;}
    break;

  case 18:
#line 137 "compiler.y"
    {exit_scope(scope + 1); scope--;;}
    break;

  case 19:
#line 137 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(3) - (5)].structure.intval);;}
    break;

  case 25:
#line 148 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(1) - (1)].structure.intval); printf("return type %d\n",(yyval.structure.intval)) ;;}
    break;

  case 37:
#line 164 "compiler.y"
    {scope++;enter_scope(scope); ;}
    break;

  case 38:
#line 164 "compiler.y"
    {exit_scope(scope + 1); scope--;;}
    break;

  case 39:
#line 167 "compiler.y"
    {
                err = lookup((yyvsp[(2) - (2)].structure.strval), scope, (yyvsp[(1) - (2)].structure.intval), (yylsp[(2) - (2)]).first_line, 1); 
                if(!err) fprintf(tptr,"Redeclaration error : %s has already been declared in this scope.\n",(yyvsp[(2) - (2)].structure.strval));
                push_t();
                fun1();
                ;}
    break;

  case 40:
#line 174 "compiler.y"
    {int t1 = (yyvsp[(1) - (7)].structure.intval);
                                                                  int t2 = (yyvsp[(6) - (7)].structure.intval);
                                                                  if (t1!=t2)
                                                                 printf("return type does not match function");
                                                                 fun2();
                                                                 ;}
    break;

  case 44:
#line 187 "compiler.y"
    { err = check((yyvsp[(1) - (1)].structure.strval),scope,(yylsp[(1) - (1)]).first_line,"0"); 
                        if(!err){
                            fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yyvsp[(1) - (1)].structure.strval),(yylsp[(1) - (1)]).first_line); 
                        }
                        else
                            push_t();;}
    break;

  case 45:
#line 193 "compiler.y"
    {if(arg_count == 1) arg1();;}
    break;

  case 46:
#line 193 "compiler.y"
    {if(err) funcall();;}
    break;

  case 47:
#line 195 "compiler.y"
    {arg_count++; arg1();;}
    break;

  case 48:
#line 196 "compiler.y"
    {arg_count++;;}
    break;

  case 51:
#line 202 "compiler.y"
    {push_op("=");;}
    break;

  case 52:
#line 202 "compiler.y"
    { 
                                            if((yyvsp[(1) - (6)].structure.intval) != (yyvsp[(5) - (6)].structure.intval))
                                                printf("Error at line: %d WARNING : Type mismatch\n",(yylsp[(1) - (6)]).first_line);
                                            err = lookup((yyvsp[(2) - (6)].structure.strval),scope, (yyvsp[(1) - (6)].structure.intval), (yylsp[(2) - (6)]).first_line,1); 
                                            if(!err) fprintf(tptr,"Redeclaration error : %s has already been declared in this scope.\n",(yyvsp[(2) - (6)].structure.strval));
                                            else{
                                            
                                            err = check((yyvsp[(2) - (6)].structure.strval),scope,(yylsp[(2) - (6)]).first_line,(yyvsp[(5) - (6)].structure.strval));  
                                            if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(2) - (6)]).first_line,(yyvsp[(2) - (6)].structure.strval));
                                            }
                                            if(err){
                                            push_t();
                                            codegen_assign();} 
                                            ;}
    break;

  case 55:
#line 221 "compiler.y"
    { 

                                            err = lookup_arr((yyvsp[(2) - (6)].structure.strval),scope, (yyvsp[(1) - (6)].structure.intval), (yylsp[(2) - (6)]).first_line, (yyvsp[(4) - (6)].structure.strval)); 
                                            if(!err) fprintf(tptr,"Redeclaration error : %s has already been declared in this scope.\n",(yyvsp[(2) - (6)].structure.strval));
                                           ;}
    break;

  case 56:
#line 226 "compiler.y"
    { err = lookup_arr((yyvsp[(2) - (5)].structure.strval),scope, (yyvsp[(1) - (5)].structure.intval), (yylsp[(2) - (5)]).first_line, (yyvsp[(4) - (5)].structure.strval)); 
            
                                            if(!err) fprintf(tptr,"Redeclaration error : %s has already been declared in this scope.\n",(yyvsp[(2) - (5)].structure.strval));
                                            id = (yyvsp[(2) - (5)].structure.strval);
                                            idx = 0;
                                            

                                           ;}
    break;

  case 57:
#line 233 "compiler.y"
    {
                                                if((yyvsp[(1) - (11)].structure.intval) != (yyvsp[(9) - (11)].structure.intval))
                                                printf("Error at line: %d WARNING : Type mismatch\n",(yylsp[(1) - (11)]).first_line); ;}
    break;

  case 58:
#line 238 "compiler.y"
    {err = check_arr(id,scope,(yylsp[(3) - (3)]).first_line,(yyvsp[(3) - (3)].structure.strval),idx++);  
                        if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(1) - (3)]).first_line,(yyvsp[(1) - (3)].structure.strval)); ;}
    break;

  case 59:
#line 240 "compiler.y"
    {err = check_arr(id,scope,(yylsp[(1) - (1)]).first_line,(yyvsp[(1) - (1)].structure.strval),idx++);  
                        if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(1) - (1)]).first_line,(yyvsp[(1) - (1)].structure.strval));;}
    break;

  case 63:
#line 250 "compiler.y"
    {  err = lookup((yyvsp[(3) - (3)].structure.strval),scope, type, (yylsp[(3) - (3)]).first_line,1);
                                                if(!err) fprintf(tptr,"Redeclaration error : %s has already been declared in this scope.\n",(yyvsp[(3) - (3)].structure.strval),1);
                                                else{
                                                err = check((yyvsp[(3) - (3)].structure.strval),scope,(yylsp[(3) - (3)]).first_line,"0");
                                                if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(1) - (3)]).first_line,(yyvsp[(3) - (3)].structure.strval)); }
                                            ;}
    break;

  case 64:
#line 256 "compiler.y"
    {
                        err = lookup((yyvsp[(1) - (1)].structure.strval),scope, type, (yylsp[(1) - (1)]).first_line,1);
                        if(!err) fprintf(tptr,"Redeclaration error : %s has already been declared in this scope.\n",(yyvsp[(1) - (1)].structure.strval));
                        else{
                        err = check((yyvsp[(1) - (1)].structure.strval),scope,(yylsp[(1) - (1)]).first_line,"0");
                        if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(1) - (1)]).first_line,(yyvsp[(1) - (1)].structure.strval)); }
;}
    break;

  case 65:
#line 264 "compiler.y"
    {push_op("=");;}
    break;

  case 66:
#line 264 "compiler.y"
    { 
                                    if((yyvsp[(1) - (5)].structure.intval) != (yyvsp[(4) - (5)].structure.intval))
                                        printf("Error at line: %d WARNING : Type mismatch\n",(yylsp[(1) - (5)]).first_line);
                                    err = check((yyvsp[(1) - (5)].structure.strval),scope, (yylsp[(1) - (5)]).first_line, "0"); 
                                    if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(1) - (5)]).first_line,(yyvsp[(1) - (5)].structure.strval));
                                    else {push_t();
                                    codegen_assign(); }
;}
    break;

  case 67:
#line 272 "compiler.y"
    {          ch = ((yyvsp[(3) - (6)].structure.intval) != 1);
                                                          if(ch)
                                                            yyerror("Index must be an integer");
                                                          else{
                                                            ch = (type != (yyvsp[(6) - (6)].structure.intval));
                                                          if(ch)
                                                            yyerror("Type mismatch");
                                                        else{
                                                          err = lookup((yyvsp[(6) - (6)].structure.strval),scope,type,(yylsp[(5) - (6)]).first_line,1);
                                                          push_t();
                                                          err = lookup((yyvsp[(3) - (6)].structure.strval),scope,type,(yylsp[(3) - (6)]).first_line,1);
                                                          push_t();
                                                          }}
                                                        ;}
    break;

  case 68:
#line 286 "compiler.y"
    {if(!ch){if((yyvsp[(3) - (8)].structure.intval) == 1){err = check_arr((yyvsp[(1) - (8)].structure.strval),scope, (yylsp[(1) - (8)]).first_line, (yyvsp[(6) - (8)].structure.strval), atoi((yyvsp[(3) - (8)].structure.strval))); 
                                                            type = link->type;
                                                if(!err) fprintf(tptr,"Error at line: %d %s has not been declared in this scope.\n",(yylsp[(1) - (8)]).first_line,(yyvsp[(1) - (8)].structure.strval));
                                                else {push_t(); array_assign();}}}
;}
    break;

  case 71:
#line 299 "compiler.y"
    {if(link->arr != NULL) yyerror("Invalid operation on given data type\n"); ;}
    break;

  case 72:
#line 299 "compiler.y"
    {push_op("+");;}
    break;

  case 73:
#line 299 "compiler.y"
    { 
                    codegen(); 
                    int t1 = (yyvsp[(1) - (5)].structure.intval);
                    int t2 = (yyvsp[(5) - (5)].structure.intval);  
                    ;}
    break;

  case 74:
#line 304 "compiler.y"
    {if(link->arr != NULL) yyerror("Invalid operation on given data type\n"); ;}
    break;

  case 75:
#line 304 "compiler.y"
    {push_op("-");;}
    break;

  case 76:
#line 304 "compiler.y"
    { codegen();  ;}
    break;

  case 78:
#line 308 "compiler.y"
    { ch = (link->arr != NULL);if(ch) yyerror("Invalid operation on given data type\n");;}
    break;

  case 79:
#line 308 "compiler.y"
    { if(!ch) push_op("*");;}
    break;

  case 80:
#line 308 "compiler.y"
    { if(!ch)codegen();  (yyval.structure.intval) = (yyvsp[(1) - (5)].structure.intval);;}
    break;

  case 81:
#line 309 "compiler.y"
    {ch = (link->arr != NULL);if(ch) yyerror("Invalid operation on given data type\n");;}
    break;

  case 82:
#line 309 "compiler.y"
    {if(!ch) push_op("/");;}
    break;

  case 83:
#line 309 "compiler.y"
    { if(!ch) codegen();  (yyval.structure.intval) = (yyvsp[(1) - (5)].structure.intval);;}
    break;

  case 84:
#line 310 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(1) - (1)].structure.intval);;}
    break;

  case 85:
#line 312 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(1) - (1)].structure.intval);;}
    break;

  case 86:
#line 314 "compiler.y"
    {
                        err = check((yyvsp[(1) - (1)].structure.strval),scope,(yylsp[(1) - (1)]).first_line,"0"); if(!err) fprintf(tptr,"Undefined error : %s has not been declared in this scope.\n",(yyvsp[(1) - (1)].structure.strval)); (yyval.structure.strval) = (yyvsp[(1) - (1)].structure.strval);
                        push_t(); 
                        (yyval.structure.intval) = link->type;
                        ;}
    break;

  case 87:
#line 319 "compiler.y"
    { link = create_var((yyvsp[(1) - (1)].structure.strval),-1,(yyvsp[(1) - (1)].structure.intval),-1);
         push_t(); (yyval.structure.intval) = (yyvsp[(1) - (1)].structure.intval);;}
    break;

  case 90:
#line 323 "compiler.y"
    {err = check_arr((yyvsp[(1) - (4)].structure.strval),scope, (yylsp[(1) - (4)]).first_line, "0", atoi((yyvsp[(3) - (4)].structure.strval))); 
                                                type = link->type;
                                                if(!err) fprintf(tptr,"Undefined error : %s has not been declared in this scope.\n",(yyvsp[(1) - (4)].structure.strval));
                                                else {push_t();
                                                array_val();};}
    break;

  case 91:
#line 330 "compiler.y"
    {
                        err = check((yyvsp[(1) - (1)].structure.strval),scope,(yylsp[(1) - (1)]).first_line,"0"); if(!err) fprintf(tptr,"Undefined error : %s has not been declared in this scope.\n",(yyvsp[(1) - (1)].structure.strval)); (yyval.structure.strval) = (yyvsp[(1) - (1)].structure.strval);
                        push_t(); 
                        ;}
    break;

  case 92:
#line 334 "compiler.y"
    { link = create_var((yyvsp[(1) - (1)].structure.strval),-1,(yyvsp[(1) - (1)].structure.intval),-1);
         push_t();;}
    break;

  case 99:
#line 347 "compiler.y"
    {type = 1; ;}
    break;

  case 100:
#line 348 "compiler.y"
    {type = 2;;}
    break;

  case 101:
#line 349 "compiler.y"
    {type = 3;;}
    break;

  case 102:
#line 350 "compiler.y"
    {type = 4;;}
    break;

  case 103:
#line 351 "compiler.y"
    {type = 5;;}
    break;

  case 104:
#line 354 "compiler.y"
    {err = check((yyvsp[(1) - (2)].structure.strval),scope, (yylsp[(1) - (2)]).first_line,0); 
                                if(!err) fprintf(tptr,"Error at line %d : %s has not been declared in this scope.\n",(yylsp[(1) - (2)]).first_line,(yyvsp[(1) - (2)].structure.strval));
                                if(err) {push_t(); postinc();};}
    break;

  case 105:
#line 357 "compiler.y"
    {check((yyvsp[(2) - (2)].structure.strval),scope, (yylsp[(2) - (2)]).first_line,0); 
                        if(!err) fprintf(tptr,"Error at line %d : %s has not been declared in this scope.\n",(yylsp[(2) - (2)]).first_line,(yyvsp[(2) - (2)].structure.strval));
                        if(err){push_t(); preinc();};}
    break;

  case 106:
#line 361 "compiler.y"
    {check((yyvsp[(1) - (2)].structure.strval),scope, (yylsp[(1) - (2)]).first_line,0); 
                                if(!err) fprintf(tptr,"Error at line %d : %s has not been declared in this scope.\n",(yylsp[(1) - (2)]).first_line,(yyvsp[(1) - (2)].structure.strval));
                                if(err) {push_t(); postdec();};}
    break;

  case 107:
#line 364 "compiler.y"
    {check((yyvsp[(2) - (2)].structure.strval),scope, (yylsp[(2) - (2)]).first_line,0); 
                        if(!err) fprintf(tptr,"Error at line %d : %s has not been declared in this scope.\n",(yylsp[(2) - (2)]).first_line,(yyvsp[(2) - (2)].structure.strval));
                        if(err){push_t(); predec();};}
    break;

  case 108:
#line 369 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(2) - (3)].structure.intval);;}
    break;

  case 109:
#line 370 "compiler.y"
    {(yyval.structure.intval) = (yyvsp[(2) - (3)].structure.intval);;}
    break;

  case 111:
#line 374 "compiler.y"
    {while1();;}
    break;

  case 112:
#line 374 "compiler.y"
    {while2();;}
    break;

  case 113:
#line 374 "compiler.y"
    {while3();;}
    break;

  case 116:
#line 379 "compiler.y"
    {codegen_assigna();;}
    break;

  case 119:
#line 384 "compiler.y"
    {push_op("<");push_op(" ");;}
    break;

  case 120:
#line 385 "compiler.y"
    {push_op(">");push_op(" ");;}
    break;

  case 121:
#line 386 "compiler.y"
    {push_op("!");push_op("=");;}
    break;

  case 122:
#line 387 "compiler.y"
    {push_op("=");push_op("=");;}
    break;

  case 123:
#line 388 "compiler.y"
    {push_op("<"); push_op("=");;}
    break;

  case 124:
#line 389 "compiler.y"
    {push_op(">"); push_op("=");;}
    break;

  case 127:
#line 394 "compiler.y"
    {switch1();;}
    break;

  case 128:
#line 394 "compiler.y"
    {case_var = link;;}
    break;

  case 129:
#line 394 "compiler.y"
    {test(); next();;}
    break;

  case 134:
#line 405 "compiler.y"
    {cases[num_cases] = (yyvsp[(2) - (2)].structure.strval)[0]; num_cases++; casestart();;}
    break;

  case 135:
#line 405 "compiler.y"
    {caseend();;}
    break;


/* Line 1267 of yacc.c.  */
#line 2228 "compiler.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 413 "compiler.y"

#include<ctype.h>
char st1[100][7];
sym* st2[100];

char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[5]="t";

int lnum=0;
int ltop=0;
int abcd=0;
int l_while=0;
int l_switch=0;
int label = 0;
int l_for=0;
int flag_set = 1;
int snum = 0;
int nnum = 0;
int change_rec[10];
int change = 0;
int gotos[10];
int goto_i = 0;


int main(){
    init();
    fp = fopen("ICG.txt","w");
    qptr = fopen("Quadruples.txt","w");
    tptr = fopen("Errors.txt","w");
       
    if(!yyparse()) 
    {
        //printf("Parsing Complete\n");
        //printf("---------------------Quadruples-------------------------\n\n");
        //fprintf(qptr,"Quadruples\n\n");
        //printf("Operator \t Arg1 \t\t Arg2 \t\t Result \n");
        //fprintf(qptr,"Operator \t Arg1 \t\t Arg2 \t\t Result \n");
        int i;
        for(i=0;i<quadlen;i++)
        {
            char *a1, *a2, *r;
            if(q[i].arg1 != NULL) 
                a1 = q[i].arg1->name;
            else
                a1 = (char*)q[i].arg1;
            if(q[i].arg2 != NULL) 
                a2 = q[i].arg2->name;
            else
                a2 = (char*)q[i].arg2;
            if(q[i].res != NULL) 
                r = q[i].res->name;
            else
                r = (char*)q[i].res;

            //printf("%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,a1,a2,r);
            fprintf(qptr,"%-8s \t %-8s \t %-8s \t %-6s \n",q[i].op,a1,a2,r);
        }
    }
    display();
    fclose(qptr);
    fclose(fp);
}


int yywrap()
{
  return(1);
}

void test()
{
    fprintf(fp,"test%d:\n",snum-1);

    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;   
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",snum-1);
    char l1[11]="test";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;

    int i;
    sym* t = case_var;
    for(i=0;i<num_cases;i++)
    {
        strcpy(temp,"T");
        sprintf(tmp_i, "%d", temp_i);
        strcat(temp,tmp_i);
        fprintf(fp, "%s = %s == %c\n",temp,t->name,cases[i]);        
        q[quadlen].op = (char*)malloc(sizeof(char)*3);
        strcpy(q[quadlen].op,"==");
        q[quadlen].arg1 = t;
        char x[10];
        sprintf(x,"%c",cases[i]);
        err = lookup(x,scope,type,quadlen,0);
        q[quadlen].arg2 = link;
        err = lookup(temp,scope,type,quadlen,1);
        q[quadlen].res = link;        
        quadlen++;

        fprintf(fp,"if %s goto L%d\n",temp,lnum - num_cases + i);
        q[quadlen].op = (char*)malloc(sizeof(char)*3);
        q[quadlen].arg1 = link;
        q[quadlen].arg2 = NULL;        
        strcpy(q[quadlen].op,"if");
        sprintf(x,"%d",lnum - num_cases + i);
        char l[11]="L";
        strcat(l,x);
        err = lookup(l,scope,type,quadlen,0);
        q[quadlen].res = link;
        st2[top2] = link;
        quadlen++;
        temp_i++;
    }   
}

void next()
{
    fprintf(fp,"next%d:\n",nnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",nnum-1);
    char l1[11]="next";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;
    num_cases = 0;
}

void casestart()
{
    l_switch = lnum;
    fprintf(fp, "L%d :\n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;   
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[11]="L";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;   
}

void caseend()
{
    fprintf(fp,"goto next%d\n",nnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",nnum);
    char l[11]="next";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;
}

void switch1()
{
    fprintf(fp,"goto test%d\n",snum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",snum-1);
    char l[11]="test";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;
}

void while1()
{
    l_while = lnum;
    gotos[goto_i] = lnum;
    goto_i++;
    fprintf(fp, "L%d :\n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[11]="L";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;
}

void while2()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = not %s\n",temp,st2[top2]->name);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"not");
    q[quadlen].arg1 = st2[top2];
    err = lookup(temp,scope,type,quadlen,1);
    q[quadlen].res = link;
    quadlen++;
    fprintf(fp, "if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = link;
    q[quadlen].arg2 = NULL; 
    strcpy(q[quadlen].op,"if");
    char x[10];
    sprintf(x,"%d",lnum);char l[11]="L";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen,0);
    q[quadlen].res = link;
    st2[top2] = link;
    change_rec[change] = quadlen;
    change++;
    quadlen++;
    temp_i++;
}

void while3()
{
    fprintf(fp,"goto L%d\n",gotos[--goto_i]);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"goto");
    char x[10];
    sprintf(x,"%d",gotos[goto_i]);
    char l[11]="L";
    strcat(l,x);
    err = lookup(l,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;
    fprintf(fp,"L%d: \n",lnum++); 
    sprintf(x,"%d",lnum-1);
    char l2[11] = "L";
    strcat(l2,x);
    err = lookup(l2,scope,type,quadlen,0);
    q[change_rec[--change]].res = link;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;    
    strcpy(q[quadlen].op,"Label");
    char x1[10];
    sprintf(x1,"%d",lnum-1);
    char l1[11]="L";
    strcat(l1,x1);
    err = lookup(l1,scope,type,quadlen,0);
    q[quadlen].res = link;
    quadlen++;
}

void codegen()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = %s %s %s\n",temp,st2[top2-1]->name,st1[top],st2[top2]->name);
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st1[top]));
    strcpy(q[quadlen].op,st1[top]);
    q[quadlen].arg1 = st2[top2-1];
    q[quadlen].arg2 = st2[top2];
    err = lookup(temp,scope,type,quadlen,1);
    q[quadlen].res = link;
    quadlen++;
    top2-=1;
    top-=1;
    st2[top2] = link;
    temp_i++;
}

void push_t()
{
    st2[++top2] = link; 
}

void push_op(char* text)
{
    strcpy(st1[++top],text);  
}

void codegen_assigna()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = %s %s %s %s\n",temp,st2[top2-1]->name,st1[top-1],st1[top],st2[top2]->name);
    if(strlen(st1[top])==1)
    {        
        char t[120];
        strcpy(t,st1[top-1]);
        strcat(t,st1[top]);
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(t));
        strcpy(q[quadlen].op,t);
        q[quadlen].arg1 = st2[top2-1];
        q[quadlen].arg2 = st2[top2];
        err = lookup(temp,scope,type,quadlen,1);
        q[quadlen].res = link;
        quadlen++;  
    }
    else
    {
        q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st1[top]));
        strcpy(q[quadlen].op,st1[top]);
        q[quadlen].arg1 = st2[top2-1];
        q[quadlen].arg2 = st2[top2];
        err = lookup(temp,scope,type,quadlen,1);
        q[quadlen].res = link;
        quadlen++;
    }
    top2-=2;
    top-=2;
    temp_i++;
    st2[++top2] = link;
}

void codegen_assign()
{
    fprintf(fp,"%s = %s\n",st2[top2]->name,st2[top2-1]->name);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg2 = NULL;
    strcpy(q[quadlen].op,"=");
    q[quadlen].arg1 = st2[top2-1];
    q[quadlen].res = st2[top2];
    quadlen++;
    top2-=2;
    top-=1;
}

void arg1()
{
    int rem = arg_count % 3;
    int m = arg_count / 3;

    for(int i = 0; i < m; ++i){
        fprintf(fp,"param %s, %s, %s\n",st2[top2]->name,st2[top2-1]->name,st2[top2-2]->name);
        q[quadlen].op = (char*)malloc(sizeof(char) * 6);
        strcpy(q[quadlen].op,"param");
        q[quadlen].arg1 = st2[top2];
        q[quadlen].arg2 = st2[top2-1];
        q[quadlen].res = st2[top2-2];
        quadlen++;
        top2-=3;
    }
    
    if(rem == 1){
        fprintf(fp,"param %s\n",st2[top2]->name);
        q[quadlen].op = (char*)malloc(sizeof(char) * 6);
        strcpy(q[quadlen].op,"param");
        q[quadlen].arg1 = st2[top2];
        q[quadlen].arg2 = NULL;
        q[quadlen].res = NULL;
        quadlen++;
        top2-=1;        
    }
    if(rem == 2){
        fprintf(fp,"param %s, %s\n",st2[top2]->name,st2[top2-1]->name);
        q[quadlen].op = (char*)malloc(sizeof(char) * 6);
        strcpy(q[quadlen].op,"param");
        q[quadlen].arg1 = st2[top2];
        q[quadlen].arg2 = st2[top2-1];
        q[quadlen].res = NULL;
        quadlen++;
        top2-=2;
    }
}

void funcall()
{
    fprintf(fp,"call %s, %d\n",st2[top2]->name,arg_count);
    q[quadlen].op = (char*)malloc(sizeof(char) * 5);
    strcpy(q[quadlen].op,"call");
    q[quadlen].arg1 = st2[top2];
    char x[2];
    sprintf(x,"%d",arg_count);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg2 = link;
    q[quadlen].res = NULL;
    quadlen++;
    top2-=1;    
}

void fun1()
{
    fprintf(fp,"func begin %s\n",st2[top2]->name);
    q[quadlen].op = (char*)malloc(sizeof(char) * 5);
    strcpy(q[quadlen].op,"func");
    q[quadlen].arg2 = link;
    err = lookup("begin",scope,type,quadlen,0);
    q[quadlen].arg1 = link;
    q[quadlen].res = NULL;
    quadlen++;
    top2-=1;      
}

void fun2()
{
    fprintf(fp,"func end\n");
    q[quadlen].op = (char*)malloc(sizeof(char) * 5);
    strcpy(q[quadlen].op,"func");
    q[quadlen].arg2 = NULL;
    err = lookup("end",scope,type,quadlen,0);
    q[quadlen].arg1 = link;
    q[quadlen].res = NULL;
    quadlen++;     
}

void postinc()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = %s\n",temp,st2[top2]->name);   
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"=");
    q[quadlen].arg2 = NULL;
    q[quadlen].arg1 = st2[top2];
    sym* var = st2[top2];
    err = lookup(temp,scope,type,quadlen,1);    
    q[quadlen].res = link;
    st2[top2] = link;
    quadlen++;  
    fprintf(fp,"%s = %s + 1\n",var->name,var->name);   
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"+");
    char x[10];
    sprintf(x,"%d",1);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg2 = link;
    q[quadlen].arg1 = var;
    q[quadlen].res = var;
    quadlen++; 
    temp_i++; 
}

void preinc()
{
    fprintf(fp,"%s = %s + 1\n",st2[top2]->name,st2[top2]->name);   
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"+");
    q[quadlen].arg1 = st2[top2];
    q[quadlen].res = st2[top2];
    char x[10];
    sprintf(x,"%d",1);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg2 = link;
    quadlen++;  
}

void postdec()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fprintf(fp,"%s = %s\n",temp,st2[top2]->name);   
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"=");
    q[quadlen].arg2 = NULL;
    q[quadlen].arg1 = st2[top2];
    sym* var = st2[top2];
    err = lookup(temp,scope,type,quadlen,1);    
    q[quadlen].res = link;
    st2[top2] = link;
    quadlen++;  
    fprintf(fp,"%s = %s - 1\n",var->name,var->name);   
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"-");
    char x[10];
    sprintf(x,"%d",1);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg2 = link;
    q[quadlen].arg1 = var;
    q[quadlen].res = var;
    quadlen++; 
    temp_i++; 
}

void predec()
{
    fprintf(fp,"%s = %s - 1\n",st2[top2]->name,st2[top2]->name);   
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"+");
    q[quadlen].arg1 = st2[top2];
    q[quadlen].res = st2[top2];
    char x[10];
    sprintf(x,"%d",1);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg2 = link;
    quadlen++;  
}

void array_assign()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    int size;
    if(type == 1)
        size = 4;
    else if(type == 2)
        size = 8;
    else if(type == 4)
        size = 1;
    fprintf(fp,"%s = %d * %s\n",temp,size,st2[top2-1]->name); 
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"*");
    char x[10];
    sprintf(x,"%d",size);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg1 = link;
    q[quadlen].arg2 = st2[top2-1];
    err = lookup(temp,scope,type,quadlen,1);
    q[quadlen].res = link;
    quadlen++;  

    temp_i++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);    
    fprintf(fp,"%s = %s[%s]\n",temp,st2[top2]->name,link->name);  
    q[quadlen].op = (char*)malloc(sizeof(char) * 3);
    q[quadlen].arg2 = link;
    strcpy(q[quadlen].op,"[]=");
    sprintf(x,"%d",size);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg1 = st2[top2];
    err = lookup(temp,scope,type,quadlen,1);
    q[quadlen].res = link;
    quadlen++; 
    temp_i++;

    sym* b = st2[top2-2];
    top2-=2;
    st2[top2] = link;
    codegen_assign();
}

void array_val()
{
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    int size;
    if(type == 1)
        size = 4;
    else if(type == 2)
        size = 8;
    else if(type == 4)
        size = 1;
    fprintf(fp,"%s = %d * %s\n",temp,size,st2[top2-1]->name); 
    q[quadlen].op = (char*)malloc(sizeof(char) * 2);
    strcpy(q[quadlen].op,"*");
    char x[10];
    sprintf(x,"%d",size);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg1 = link;
    q[quadlen].arg2 = st2[top2-1];
    err = lookup(temp,scope,type,quadlen,1);
    q[quadlen].res = link;
    quadlen++;  

    temp_i++;
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);    
    fprintf(fp,"%s = %s[%s]\n",temp,st2[top2]->name,link->name);  
    q[quadlen].op = (char*)malloc(sizeof(char) * 3);
    q[quadlen].arg2 = link;
    strcpy(q[quadlen].op,"=[]");
    sprintf(x,"%d",size);
    err = lookup(x,scope,type,quadlen,0);
    q[quadlen].arg1 = st2[top2];
    err = lookup(temp,scope,type,quadlen,1);
    q[quadlen].res = link;
    quadlen++; 
    temp_i++;

    top2-=1;
    st2[top2] = link;  
}
