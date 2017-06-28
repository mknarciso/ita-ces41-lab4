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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DOLAR = 258,
     CALL = 259,
     CHAR = 260,
     ELSE = 261,
     FALSE = 262,
     FLOAT = 263,
     FOR = 264,
     FUNCTION = 265,
     IF = 266,
     INT = 267,
     LOGIC = 268,
     PROCEDURE = 269,
     PROGRAM = 270,
     READ = 271,
     REPEAT = 272,
     RETURN = 273,
     TRUE = 274,
     VAR = 275,
     WHILE = 276,
     WRITE = 277,
     ID = 278,
     CHARCT = 279,
     STRING = 280,
     INTCT = 281,
     FLOATCT = 282,
     OR = 283,
     AND = 284,
     NOT = 285,
     NEG = 286,
     RELOP = 287,
     ADOP = 288,
     MULTOP = 289,
     OPPAR = 290,
     CLPAR = 291,
     OPBRAK = 292,
     CLBRAK = 293,
     OPBRACE = 294,
     CLBRACE = 295,
     SCOLON = 296,
     COMMA = 297,
     ASSIGN = 298,
     INVAL = 299
   };
#endif
/* Tokens.  */
#define DOLAR 258
#define CALL 259
#define CHAR 260
#define ELSE 261
#define FALSE 262
#define FLOAT 263
#define FOR 264
#define FUNCTION 265
#define IF 266
#define INT 267
#define LOGIC 268
#define PROCEDURE 269
#define PROGRAM 270
#define READ 271
#define REPEAT 272
#define RETURN 273
#define TRUE 274
#define VAR 275
#define WHILE 276
#define WRITE 277
#define ID 278
#define CHARCT 279
#define STRING 280
#define INTCT 281
#define FLOATCT 282
#define OR 283
#define AND 284
#define NOT 285
#define NEG 286
#define RELOP 287
#define ADOP 288
#define MULTOP 289
#define OPPAR 290
#define CLPAR 291
#define OPBRAK 292
#define CLBRAK 293
#define OPBRACE 294
#define CLBRACE 295
#define SCOLON 296
#define COMMA 297
#define ASSIGN 298
#define INVAL 299




/* Copy the first part of user declarations.  */
#line 1 "lab4.y"

/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */

#define 	LT 		1
#define 	LE 		2
#define		GT		3
#define		GE		4
#define		EQ		5
#define		NE		6
#define 	ADD		7
#define		SUB 	8
#define 	MULT	9
#define 	DIV		10
#define 	MOD		11

/*   Definicao dos tipos de identificadores   */

#define 	IDGLOB		1
#define 	IDVAR		2
#define		IDFUNC		3
#define		IDPROC		4
#define		IDPROG		5

/*	Definicao dos tipos de passagem de parametros */

#define		PARAMVAL	1
#define		PARAMREF	2

/*  Definicao dos tipos de variaveis   */

#define 	NAOVAR		0
#define 	INTEIRO		1
#define 	LOGICO		2
#define 	REAL		3
#define 	CARACTERE	4

/*   Definicao de outras constantes   */

#define	NCLASSHASH	23
#define	VERDADE		1
#define	FALSO		0
#define MAXDIMS     10

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[6] = {" ", "IDGLOB", "IDVAR", "IDFUNC", "IDPROC", "IDPROG"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[5] = {"NAOVAR",
	"INTEIRO", "LOGICO", "REAL", "CARACTERE"
};



/*    Declaracoes para a tabela de simbolos     */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;

/* Listas de simbolos */
typedef struct elemlistsimb elemlistsimb;
typedef elemlistsimb *pontelemlistsimb;
typedef elemlistsimb *listsimb;

struct elemlistsimb {
	simbolo simb; 
	pontelemlistsimb prox;
};


struct celsimb {
	char *cadeia;
	int tid, tvar, tparam, ndims, dims[MAXDIMS + 1], nparam;
	char inic, ref, array, param;
	listsimb listparam, listfunc, listvardecl;
	simbolo escopo, prox;
};

/* Declaração para lista de expressões */

typedef struct infolistexpr infolistexpr;
typedef struct pontexprtipo pontexprtipo;
struct pontexprtipo {
	pontexprtipo* prox;
	int tipo;
};

struct infolistexpr { 
	pontexprtipo* listtipo;  
	int nargs; 
};

/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb, escopo;
int tipocorrente;
int tab = 0;
int declparam;
listsimb pontvardecl, pontfunc, pontparam;
/* Prototipos das funcoes para a tabela de simbolos e analise semantica */

void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int, simbolo);
int hash (char *);
simbolo ProcuraSimb (char *, simbolo);
simbolo ProcuraSimbDecl (char *, simbolo);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);
void VerificaInicRef (void);
void Incompatibilidade (char *);
void Esperado (char *);
void NaoEsperado (char *);
void ChecArgumentos (pontexprtipo*, listsimb);
pontexprtipo* InicListTipo (int);
void InsereListSimb (simbolo, listsimb*);


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 130 "lab4.y"
{
	char string[50];
	int valint, atr;
	float valfloat;
	char carac;
	simbolo simb;
	int tipoexpr;
	int nsubscr;
	infolistexpr infolexpr;
}
/* Line 193 of yacc.c.  */
#line 322 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 335 "y.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNRULES -- Number of states.  */
#define YYNSTATES  252

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    15,    16,    20,    22,
      25,    26,    31,    33,    35,    37,    39,    41,    42,    47,
      48,    52,    53,    56,    60,    61,    64,    68,    69,    72,
      74,    75,    76,    85,    86,    87,    97,    98,    99,   107,
     108,   109,   118,   120,   121,   126,   129,   130,   135,   136,
     139,   141,   142,   145,   146,   149,   150,   153,   154,   157,
     158,   161,   162,   165,   166,   169,   170,   173,   174,   177,
     178,   181,   182,   183,   184,   185,   186,   198,   199,   200,
     201,   206,   207,   208,   209,   210,   220,   221,   222,   223,
     234,   235,   236,   237,   238,   239,   240,   241,   262,   263,
     270,   272,   273,   278,   279,   286,   288,   289,   294,   296,
     298,   304,   305,   313,   316,   317,   322,   323,   324,   331,
     333,   334,   339,   341,   342,   347,   349,   350,   355,   357,
     358,   362,   364,   365,   370,   372,   373,   378,   380,   381,
     386,   388,   390,   392,   394,   396,   398,   399,   403,   404,
     409,   411,   412,   416,   417,   420,   421,   426,   427,   428,
     435,   436
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      46,     0,    -1,    -1,    -1,    47,    15,    23,    41,    48,
      49,    61,    78,    -1,    -1,    -1,    20,    50,    51,    -1,
      52,    -1,    51,    52,    -1,    -1,    53,    54,    55,    41,
      -1,    12,    -1,     8,    -1,     5,    -1,    13,    -1,    57,
      -1,    -1,    55,    42,    56,    57,    -1,    -1,    23,    58,
      59,    -1,    -1,    59,    60,    -1,    37,    26,    38,    -1,
      -1,    61,    62,    -1,    63,    49,    78,    -1,    -1,    64,
      65,    -1,    70,    -1,    -1,    -1,    10,    54,    23,    35,
      66,    36,    67,    41,    -1,    -1,    -1,    10,    54,    23,
      35,    68,    75,    36,    69,    41,    -1,    -1,    -1,    14,
      23,    35,    71,    36,    72,    41,    -1,    -1,    -1,    14,
      23,    35,    73,    75,    36,    74,    41,    -1,    77,    -1,
      -1,    75,    42,    76,    77,    -1,    54,    23,    -1,    -1,
      39,    79,    80,    40,    -1,    -1,    80,    81,    -1,    78,
      -1,    -1,    82,    92,    -1,    -1,    83,   101,    -1,    -1,
      84,   106,    -1,    -1,    85,   110,    -1,    -1,    86,   118,
      -1,    -1,    87,   122,    -1,    -1,    88,   131,    -1,    -1,
      89,   127,    -1,    -1,    90,   129,    -1,    -1,    91,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    35,    93,   136,
      36,    94,    95,    96,    81,    97,    98,    -1,    -1,    -1,
      -1,     6,    99,   100,    81,    -1,    -1,    -1,    -1,    -1,
      21,    35,   102,   136,    36,   103,   104,   105,    81,    -1,
      -1,    -1,    -1,    17,   107,    81,    21,    35,   108,   136,
      36,    41,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    35,   111,   151,    43,   112,   136,    41,   113,
     136,    41,   114,   151,    43,   115,   136,    36,   116,   117,
      81,    -1,    -1,    16,    35,   119,   120,    36,    41,    -1,
     151,    -1,    -1,   120,    42,   121,   151,    -1,    -1,    22,
      35,   123,   124,    36,    41,    -1,   126,    -1,    -1,   124,
      42,   125,   126,    -1,    25,    -1,   136,    -1,     4,    23,
      35,    36,    41,    -1,    -1,     4,    23,    35,   128,   134,
      36,    41,    -1,    18,    41,    -1,    -1,    18,   130,   136,
      41,    -1,    -1,    -1,   151,   132,    43,   133,   136,    41,
      -1,   136,    -1,    -1,   134,    42,   135,   136,    -1,   138,
      -1,    -1,   136,    28,   137,   138,    -1,   140,    -1,    -1,
     138,    29,   139,   140,    -1,   142,    -1,    -1,    30,   141,
     142,    -1,   144,    -1,    -1,   144,    32,   143,   144,    -1,
     146,    -1,    -1,   144,    33,   145,   146,    -1,   148,    -1,
      -1,   146,    34,   147,   148,    -1,   151,    -1,    26,    -1,
      27,    -1,    24,    -1,    19,    -1,     7,    -1,    -1,    31,
     149,   148,    -1,    -1,    35,   150,   136,    36,    -1,   156,
      -1,    -1,    23,   152,   153,    -1,    -1,   153,   154,    -1,
      -1,    37,   155,   144,    38,    -1,    -1,    -1,    23,   157,
      35,   158,   159,    36,    -1,    -1,   134,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   203,   203,   208,   203,   215,   216,   216,   221,   222,
     225,   225,   229,   230,   231,   232,   235,   236,   236,   239,
     239,   251,   252,   255,   261,   262,   265,   285,   285,   286,
     289,   289,   289,   298,   308,   298,   314,   314,   314,   325,
     336,   325,   342,   343,   343,   346,   349,   349,   367,   368,
     373,   374,   374,   375,   375,   376,   376,   377,   377,   378,
     378,   379,   379,   380,   380,   381,   381,   382,   382,   385,
     385,   388,   389,   389,   393,   393,   388,   397,   398,   399,
     398,   403,   404,   404,   408,   403,   411,   412,   413,   411,
     419,   420,   425,   426,   431,   436,   441,   419,   444,   444,
     449,   454,   454,   462,   462,   467,   468,   468,   471,   472,
     475,   478,   477,   483,   486,   486,   491,   492,   491,   503,
     504,   504,   512,   513,   513,   519,   520,   520,   526,   527,
     527,   533,   534,   534,   557,   558,   558,   571,   572,   572,
     596,   602,   603,   604,   605,   606,   607,   607,   613,   613,
     616,   618,   618,   637,   638,   641,   641,   648,   648,   648,
     665,   666
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOLAR", "CALL", "CHAR", "ELSE", "FALSE",
  "FLOAT", "FOR", "FUNCTION", "IF", "INT", "LOGIC", "PROCEDURE", "PROGRAM",
  "READ", "REPEAT", "RETURN", "TRUE", "VAR", "WHILE", "WRITE", "ID",
  "CHARCT", "STRING", "INTCT", "FLOATCT", "OR", "AND", "NOT", "NEG",
  "RELOP", "ADOP", "MULTOP", "OPPAR", "CLPAR", "OPBRAK", "CLBRAK",
  "OPBRACE", "CLBRACE", "SCOLON", "COMMA", "ASSIGN", "INVAL", "$accept",
  "Prog", "@1", "@2", "Decls", "@3", "DeclList", "Declaration", "@4",
  "Type", "ElemList", "@5", "Elem", "@6", "DimList", "Dim", "SubProgs",
  "SubProgDecl", "Header", "@7", "FuncHeader", "@8", "@9", "@10", "@11",
  "ProcHeader", "@12", "@13", "@14", "@15", "ParamList", "@16",
  "Parameter", "CompStat", "@17", "StatList", "Statement", "@18", "@19",
  "@20", "@21", "@22", "@23", "@24", "@25", "@26", "@27", "IfStat", "@28",
  "@29", "@30", "@31", "@32", "ElseStat", "@33", "@34", "WhileStat", "@35",
  "@36", "@37", "@38", "RepeatStat", "@39", "@40", "@41", "ForStat", "@42",
  "@43", "@44", "@45", "@46", "@47", "@48", "ReadStat", "@49", "ReadList",
  "@50", "WriteStat", "@51", "WriteList", "@52", "WriteElem", "CallStat",
  "@53", "ReturnStat", "@54", "AssignStat", "@55", "@56", "ExprList",
  "@57", "Expression", "@58", "AuxExpr1", "@59", "AuxExpr2", "@60",
  "AuxExpr3", "@61", "AuxExpr4", "@62", "Term", "@63", "Factor", "@64",
  "@65", "Variable", "@66", "SubscrList", "Subscript", "@67", "FuncCall",
  "@68", "@69", "Arguments", 0
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    48,    46,    49,    50,    49,    51,    51,
      53,    52,    54,    54,    54,    54,    55,    56,    55,    58,
      57,    59,    59,    60,    61,    61,    62,    64,    63,    63,
      66,    67,    65,    68,    69,    65,    71,    72,    70,    73,
      74,    70,    75,    76,    75,    77,    79,    78,    80,    80,
      81,    82,    81,    83,    81,    84,    81,    85,    81,    86,
      81,    87,    81,    88,    81,    89,    81,    90,    81,    91,
      81,    93,    94,    95,    96,    97,    92,    98,    99,   100,
      98,   102,   103,   104,   105,   101,   107,   108,   109,   106,
     111,   112,   113,   114,   115,   116,   117,   110,   119,   118,
     120,   121,   120,   123,   122,   124,   125,   124,   126,   126,
     127,   128,   127,   129,   130,   129,   132,   133,   131,   134,
     135,   134,   136,   137,   136,   138,   139,   138,   140,   141,
     140,   142,   143,   142,   144,   145,   144,   146,   147,   146,
     148,   148,   148,   148,   148,   148,   149,   148,   150,   148,
     148,   152,   151,   153,   153,   155,   154,   157,   158,   156,
     159,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     0,     3,     1,     2,
       0,     4,     1,     1,     1,     1,     1,     0,     4,     0,
       3,     0,     2,     3,     0,     2,     3,     0,     2,     1,
       0,     0,     8,     0,     0,     9,     0,     0,     7,     0,
       0,     8,     1,     0,     4,     2,     0,     4,     0,     2,
       1,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       4,     0,     0,     0,     0,     9,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     6,
       1,     0,     4,     0,     6,     1,     0,     4,     1,     1,
       5,     0,     7,     2,     0,     4,     0,     0,     6,     1,
       0,     4,     1,     0,     4,     1,     0,     4,     1,     0,
       3,     1,     0,     4,     1,     0,     4,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     4,
       1,     0,     3,     0,     2,     0,     4,     0,     0,     6,
       0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     5,     6,    24,
      10,    27,    10,     8,     0,     0,    46,    25,     5,     0,
      29,     4,     9,    14,    13,    12,    15,     0,     0,    48,
       0,     0,    28,    19,     0,    16,    39,    51,    26,     0,
      21,    11,    17,     0,     0,    47,    50,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,    37,     0,     0,    42,     0,    52,     0,    54,    86,
      56,     0,    58,     0,    60,     0,    62,   151,    64,   116,
       0,    66,   114,    68,    70,    33,     0,    22,    18,     0,
      45,    40,    43,    71,    81,    51,    90,    98,   103,   153,
       0,     0,   113,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   117,   111,   145,
     144,   151,   143,   141,   142,   129,   146,   148,     0,   122,
     125,   128,   131,   134,   137,   140,   150,    31,     0,    23,
      41,    44,     0,     0,     0,     0,     0,   100,   108,     0,
     105,   109,   155,   154,     0,     0,     0,     0,     0,     0,
       0,   123,   115,   126,   132,   135,   138,     0,    34,    72,
      82,    87,    91,     0,   101,     0,   106,     0,     0,   110,
       0,   119,   158,   130,   147,     0,     0,     0,     0,     0,
       0,    32,     0,    73,    83,     0,     0,    99,     0,   104,
       0,     0,   118,     0,   120,   160,   149,   124,   127,   133,
     136,   139,    35,    74,    84,     0,     0,   102,   107,   156,
     112,     0,   161,     0,    51,    51,     0,    92,   121,   159,
      75,    85,    88,     0,    77,    89,     0,    78,    76,    93,
      79,     0,    51,     0,    80,    94,     0,     0,    95,    96,
      51,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     9,    10,    12,    13,    14,    62,
      34,    60,    35,    40,    59,    87,    11,    17,    18,    19,
      32,   104,   167,   105,   192,    20,    43,    89,    44,   108,
      63,   109,    64,    46,    29,    37,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    66,   110,   193,
     213,   224,   234,   238,   240,   242,    68,   111,   194,   214,
     225,    70,    95,   195,   235,    72,   113,   196,   233,   241,
     246,   249,   250,    74,   114,   146,   198,    76,   115,   149,
     200,   150,    81,   156,    83,   103,    78,   100,   154,   180,
     221,   151,   186,   129,   187,   130,   158,   131,   188,   132,
     189,   133,   190,   134,   159,   160,   135,    99,   116,   153,
     177,   136,   157,   205,   223
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -157
static const yytype_int16 yypact[] =
{
    -157,    45,    32,  -157,   -14,     8,  -157,    58,  -157,  -157,
    -157,    -6,    -4,  -157,    81,    80,  -157,  -157,    58,    75,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,    94,    84,  -157,
      82,    81,  -157,  -157,   -18,  -157,    87,    -2,  -157,   101,
    -157,  -157,  -157,    89,    81,  -157,  -157,  -157,   115,   106,
     111,   120,   116,   113,   110,   132,   119,    97,   104,   103,
      94,  -157,   118,    62,  -157,   107,  -157,   108,  -157,  -157,
    -157,   114,  -157,   117,  -157,   122,  -157,  -157,  -157,  -157,
     123,  -157,   109,  -157,  -157,   124,   125,  -157,  -157,   112,
    -157,  -157,  -157,  -157,  -157,     9,  -157,  -157,  -157,  -157,
     102,   126,  -157,    49,   127,    81,   121,  -157,   128,    81,
      49,    49,   133,   110,   110,    39,   129,  -157,   131,  -157,
    -157,   130,  -157,  -157,  -157,  -157,  -157,  -157,     0,   135,
    -157,  -157,    83,   134,  -157,  -157,  -157,  -157,    69,  -157,
    -157,  -157,    15,    16,   136,   137,    71,  -157,  -157,    76,
    -157,   142,  -157,  -157,    49,   138,    49,   139,    64,    64,
      49,  -157,  -157,  -157,  -157,  -157,  -157,   140,  -157,  -157,
    -157,  -157,  -157,   141,  -157,   143,  -157,    64,     1,  -157,
      78,   142,  -157,  -157,  -157,    72,    49,    49,    64,    64,
      64,  -157,   144,  -157,  -157,    49,    49,  -157,   110,  -157,
      39,    44,  -157,   145,  -157,    49,  -157,   135,  -157,   150,
     134,  -157,  -157,  -157,  -157,    73,    12,  -157,  -157,  -157,
    -157,    49,   146,   153,     9,     9,   149,  -157,   142,  -157,
    -157,  -157,  -157,    49,   152,  -157,    26,  -157,  -157,  -157,
    -157,   110,     9,   148,  -157,  -157,    49,    74,  -157,  -157,
       9,  -157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,   154,  -157,  -157,   161,  -157,    -9,
    -157,  -157,    95,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
      57,  -157,    66,     6,  -157,  -157,   -94,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,   -24,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   -28,
    -157,   -99,  -157,    -8,  -157,     5,  -157,    35,  -157,   -96,
    -157,     7,  -157,  -156,  -157,  -157,   -54,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -158
static const yytype_int16 yytable[] =
{
      79,   112,   -65,   184,   128,    27,    -7,   -57,    15,     5,
      -7,   142,   143,   -65,   -59,   -55,   -67,    21,   -57,   -53,
     -61,   -63,    39,    41,    42,   -59,   -55,   -67,   161,   161,
     -53,   -61,   -63,    16,   211,    -7,    38,    16,    45,   -69,
     161,   162,   202,   161,   161,     3,   119,     4,    16,     6,
     -69,   169,   170,   227,   161,   178,   119,   181,   120,   145,
     147,   185,   121,   122,   148,   123,   124,   239,   120,   125,
     126,   119,   121,   122,   127,   123,   124,   165,     8,   125,
     126,   201,   219,   120,   127,    31,    23,   121,   122,    24,
     123,   124,   209,    25,    26,   126,   215,   216,    91,   127,
     161,   161,   161,    28,    92,   168,   181,   173,   206,   226,
     248,    92,   175,   174,   203,   164,   165,    33,   176,    36,
     204,    16,   228,   -36,    58,    61,    65,    67,    69,    71,
     230,   231,    73,    77,   236,    75,    80,    82,    84,    85,
      86,    90,    93,    94,   217,   117,   101,   247,   244,    96,
     102,   106,    97,   107,   144,    88,   251,    98,   237,   139,
     -30,   118,   138,   137,   163,  -157,   152,   155,   166,   140,
     161,   171,    30,    22,   182,   141,   218,   222,   207,   179,
     172,   191,   197,   165,   199,   212,   220,   243,   204,   229,
     232,   245,   208,   183,     0,     0,   210
};

static const yytype_int16 yycheck[] =
{
      54,    95,     4,   159,   103,    14,    10,     9,    14,    23,
      14,   110,   111,     4,    16,    17,    18,    11,     9,    21,
      22,    23,    31,    41,    42,    16,    17,    18,    28,    28,
      21,    22,    23,    39,   190,    39,    30,    39,    40,    41,
      28,    41,    41,    28,    28,     0,     7,    15,    39,    41,
      41,    36,    36,    41,    28,   154,     7,   156,    19,   113,
     114,   160,    23,    24,    25,    26,    27,    41,    19,    30,
      31,     7,    23,    24,    35,    26,    27,    33,    20,    30,
      31,   177,    38,    19,    35,    10,     5,    23,    24,     8,
      26,    27,   188,    12,    13,    31,   195,   196,    36,    35,
      28,    28,    28,    23,    42,    36,   205,    36,    36,    36,
      36,    42,    36,    42,    36,    32,    33,    23,    42,    35,
      42,    39,   221,    36,    23,    36,    11,    21,    17,     9,
     224,   225,    16,    23,   233,    22,     4,    18,    41,    35,
      37,    23,    35,    35,   198,    43,    23,   246,   242,    35,
      41,    26,    35,    41,    21,    60,   250,    35,     6,    38,
      36,    35,   105,    36,    29,    35,    37,    36,    34,    41,
      28,    35,    18,    12,    35,   109,   200,   205,   186,    41,
      43,    41,    41,    33,    41,    41,    41,   241,    42,    36,
      41,    43,   187,   158,    -1,    -1,   189
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,    15,    23,    41,    48,    20,    49,
      50,    61,    51,    52,    53,    14,    39,    62,    63,    64,
      70,    78,    52,     5,     8,    12,    13,    54,    23,    79,
      49,    10,    65,    23,    55,    57,    35,    80,    78,    54,
      58,    41,    42,    71,    73,    40,    78,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    23,    59,
      56,    36,    54,    75,    77,    11,    92,    21,   101,    17,
     106,     9,   110,    16,   118,    22,   122,    23,   131,   151,
       4,   127,    18,   129,    41,    35,    37,    60,    57,    72,
      23,    36,    42,    35,    35,   107,    35,    35,    35,   152,
     132,    23,    41,   130,    66,    68,    26,    41,    74,    76,
      93,   102,    81,   111,   119,   123,   153,    43,    35,     7,
      19,    23,    24,    26,    27,    30,    31,    35,   136,   138,
     140,   142,   144,   146,   148,   151,   156,    36,    75,    38,
      41,    77,   136,   136,    21,   151,   120,   151,    25,   124,
     126,   136,    37,   154,   133,    36,   128,   157,   141,   149,
     150,    28,    41,    29,    32,    33,    34,    67,    36,    36,
      36,    35,    43,    36,    42,    36,    42,   155,   136,    41,
     134,   136,    35,   142,   148,   136,   137,   139,   143,   145,
     147,    41,    69,    94,   103,   108,   112,    41,   121,    41,
     125,   144,    41,    36,    42,   158,    36,   138,   140,   144,
     146,   148,    41,    95,   104,   136,   136,   151,   126,    38,
      41,   135,   134,   159,    96,   105,    36,    41,   136,    36,
      81,    81,    41,   113,    97,   109,   136,     6,    98,    41,
      99,   114,   100,   151,    81,    43,   115,   136,    36,   116,
     117,    81
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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
#line 203 "lab4.y"
    {InicTabSimb (); declparam = FALSO;
						escopo = simb = InsereSimb("global##", IDPROG, NAOVAR, NULL);
						pontvardecl = simb->listvardecl;
						pontfunc = simb->listfunc;
					}
    break;

  case 3:
#line 208 "lab4.y"
    {printf ("program %s ;\n", (yyvsp[(3) - (4)].string));}
    break;

  case 4:
#line 209 "lab4.y"
    {
                        VerificaInicRef ();
                        ImprimeTabSimb ();
                    }
    break;

  case 6:
#line 216 "lab4.y"
    {tabular (); printf ("var\n"); tab++;}
    break;

  case 7:
#line 218 "lab4.y"
    {tab--; tabular (); printf ("\n");}
    break;

  case 10:
#line 225 "lab4.y"
    {tabular ();}
    break;

  case 11:
#line 226 "lab4.y"
    {printf(";\n");}
    break;

  case 12:
#line 229 "lab4.y"
    {printf ("int "); tipocorrente = INTEIRO;}
    break;

  case 13:
#line 230 "lab4.y"
    {printf ("float "); tipocorrente = REAL;}
    break;

  case 14:
#line 231 "lab4.y"
    {printf ("char "); tipocorrente = CARACTERE;}
    break;

  case 15:
#line 232 "lab4.y"
    {printf ("logic "); tipocorrente = LOGICO;}
    break;

  case 17:
#line 236 "lab4.y"
    {printf(", ");}
    break;

  case 19:
#line 239 "lab4.y"
    {
                    printf ("%s ", (yyvsp[(1) - (1)].string));
                    if  (ProcuraSimb ((yyvsp[(1) - (1)].string), escopo)  !=  NULL)
                        DeclaracaoRepetida ((yyvsp[(1) - (1)].string));
                    else {
                        simb = InsereSimb ((yyvsp[(1) - (1)].string),  IDVAR,  tipocorrente, escopo);
                        simb->array = FALSO; simb->ndims = 0;
                    }

                }
    break;

  case 22:
#line 252 "lab4.y"
    {simb->array = VERDADE;}
    break;

  case 23:
#line 255 "lab4.y"
    {
                    printf ("[ %d ] ", (yyvsp[(2) - (3)].valint));
                    if ((yyvsp[(2) - (3)].valint) <= 0) Esperado ("Valor inteiro positivo");
                    simb->ndims++; simb->dims[simb->ndims] = (yyvsp[(2) - (3)].valint);}
    break;

  case 26:
#line 265 "lab4.y"
    {
					if ((yyvsp[(3) - (3)].tipoexpr) == NAOVAR) {
						if ((yyvsp[(1) - (3)].simb)->tvar != NAOVAR)
							Incompatibilidade ("Função não void sem retorno");
					} else {
						if ((yyvsp[(1) - (3)].simb)->tvar == INTEIRO && (yyvsp[(3) - (3)].tipoexpr) != INTEIRO && (yyvsp[(3) - (3)].tipoexpr) != CARACTERE)  
							Incompatibilidade ("Função do tipo inteiro não retorna inteiro ou caractere");
						if ((yyvsp[(1) - (3)].simb)->tvar == REAL && (yyvsp[(3) - (3)].tipoexpr) != INTEIRO && (yyvsp[(3) - (3)].tipoexpr) != REAL && (yyvsp[(3) - (3)].tipoexpr) != CARACTERE)
							Incompatibilidade ("Função do tipo real não retorna real, inteiro ou caractere");
						if ((yyvsp[(1) - (3)].simb)->tvar == CARACTERE && (yyvsp[(3) - (3)].tipoexpr) != INTEIRO && (yyvsp[(3) - (3)].tipoexpr) != CARACTERE)
							Incompatibilidade ("Função do tipo caractere não retorna inteiro ou caractere");
						if ((yyvsp[(1) - (3)].simb)->tvar == LOGICO && (yyvsp[(3) - (3)].tipoexpr) != LOGICO)
							Incompatibilidade ("Função do tipo lógico não retorna tipo lógico");
						if ((yyvsp[(1) - (3)].simb)->tvar == NAOVAR && (yyvsp[(3) - (3)].tipoexpr) != NAOVAR)
							Incompatibilidade ("Função do tipo void retornando expressão");
						}	
					escopo = escopo->escopo;
				}
    break;

  case 27:
#line 285 "lab4.y"
    {printf("function ");}
    break;

  case 28:
#line 285 "lab4.y"
    {(yyval.simb) = (yyvsp[(2) - (2)].simb);}
    break;

  case 29:
#line 286 "lab4.y"
    {(yyval.simb) = (yyvsp[(1) - (1)].simb);}
    break;

  case 30:
#line 289 "lab4.y"
    {declparam = VERDADE;}
    break;

  case 31:
#line 289 "lab4.y"
    {declparam = FALSO;}
    break;

  case 32:
#line 289 "lab4.y"
    {
					printf ("%s ();\n",(yyvsp[(3) - (8)].string)); (yyval.simb) = simb;
					if  (ProcuraSimb ((yyvsp[(3) - (8)].string), escopo)  !=  NULL)
                        DeclaracaoRepetida ((yyvsp[(3) - (8)].string));
					escopo = simb = InsereSimb ((yyvsp[(3) - (8)].string), IDFUNC, tipocorrente, escopo);
					pontvardecl = simb->listvardecl;
					pontparam = simb->listparam;
                    (yyval.simb) = simb;
				}
    break;

  case 33:
#line 298 "lab4.y"
    {
					declparam = VERDADE;
					printf ("%s (",(yyvsp[(3) - (4)].string));
					if  (ProcuraSimb ((yyvsp[(3) - (4)].string), escopo)  !=  NULL)
                        DeclaracaoRepetida ((yyvsp[(3) - (4)].string));
						escopo = simb = InsereSimb ((yyvsp[(3) - (4)].string), IDFUNC, tipocorrente, escopo);
						pontvardecl = simb->listvardecl;
						pontparam = simb->listparam;
						(yyval.simb) = simb;
				}
    break;

  case 34:
#line 308 "lab4.y"
    {declparam = FALSO;}
    break;

  case 35:
#line 309 "lab4.y"
    {printf (");\n");
					(yyval.simb) = simb;
				}
    break;

  case 36:
#line 314 "lab4.y"
    {declparam = VERDADE;}
    break;

  case 37:
#line 314 "lab4.y"
    {declparam = FALSO;}
    break;

  case 38:
#line 314 "lab4.y"
    {
					if  (ProcuraSimb ((yyvsp[(2) - (7)].string), escopo)  !=  NULL)
                        DeclaracaoRepetida ((yyvsp[(2) - (7)].string));
					escopo = simb = InsereSimb ((yyvsp[(2) - (7)].string), IDPROC, NAOVAR, escopo);
					pontvardecl = simb->listvardecl;
					pontparam = simb->listparam;
					(yyval.simb) = simb;
					printf ("procedure %s ();\n",(yyvsp[(2) - (7)].string));
					(yyval.simb) = simb;
				}
    break;

  case 39:
#line 325 "lab4.y"
    {
					printf ("procedure %s (",(yyvsp[(2) - (3)].string)); 
					declparam = VERDADE;
					if  (ProcuraSimb ((yyvsp[(2) - (3)].string), escopo)  !=  NULL)
                        DeclaracaoRepetida ((yyvsp[(2) - (3)].string));
					escopo = simb = InsereSimb ((yyvsp[(2) - (3)].string), IDPROC, NAOVAR, escopo);
					pontvardecl = simb->listvardecl;
					pontparam = simb->listparam;
					(yyval.simb) = simb;
					
				}
    break;

  case 40:
#line 336 "lab4.y"
    {declparam = FALSO;}
    break;

  case 41:
#line 337 "lab4.y"
    {printf (");\n");
					(yyval.simb) = simb;
				}
    break;

  case 43:
#line 343 "lab4.y"
    {printf(", ");}
    break;

  case 45:
#line 346 "lab4.y"
    {printf(" %s",(yyvsp[(2) - (2)].string));}
    break;

  case 46:
#line 349 "lab4.y"
    {
					tab--;
					tabular (); 
					printf ("\{\n"); 
					tab++;	
					tab++;
				}
    break;

  case 47:
#line 357 "lab4.y"
    {
					tab--;
					tab--; 
					tabular ();
					 printf ("}\n");
					 tab++;
					 (yyval.tipoexpr) = (yyvsp[(3) - (4)].tipoexpr);
				}
    break;

  case 49:
#line 368 "lab4.y"
    {
				(yyval.tipoexpr) = (yyvsp[(2) - (2)].tipoexpr);
			}
    break;

  case 50:
#line 373 "lab4.y"
    {(yyval.tipoexpr) = (yyvsp[(1) - (1)].tipoexpr);}
    break;

  case 51:
#line 374 "lab4.y"
    {tabular ();}
    break;

  case 52:
#line 374 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 53:
#line 375 "lab4.y"
    {tabular ();}
    break;

  case 54:
#line 375 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 55:
#line 376 "lab4.y"
    {tabular ();}
    break;

  case 56:
#line 376 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 57:
#line 377 "lab4.y"
    {tabular ();}
    break;

  case 58:
#line 377 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 59:
#line 378 "lab4.y"
    {tabular ();}
    break;

  case 60:
#line 378 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 61:
#line 379 "lab4.y"
    {tabular ();}
    break;

  case 62:
#line 379 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 63:
#line 380 "lab4.y"
    {tabular ();}
    break;

  case 64:
#line 380 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 65:
#line 381 "lab4.y"
    {tabular ();}
    break;

  case 66:
#line 381 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 67:
#line 382 "lab4.y"
    {tabular ();}
    break;

  case 68:
#line 382 "lab4.y"
    {
				(yyval.tipoexpr) = (yyvsp[(2) - (2)].tipoexpr);
			}
    break;

  case 69:
#line 385 "lab4.y"
    {tabular ();}
    break;

  case 70:
#line 385 "lab4.y"
    {(yyval.tipoexpr) = NAOVAR;}
    break;

  case 71:
#line 388 "lab4.y"
    {printf("if (");}
    break;

  case 72:
#line 389 "lab4.y"
    {printf(")\n");}
    break;

  case 73:
#line 389 "lab4.y"
    {
					if ((yyvsp[(4) - (6)].tipoexpr) != LOGICO)
                            Incompatibilidade ("Expressao nao logica/relacional dentro de if");
				}
    break;

  case 74:
#line 393 "lab4.y"
    {tab++;}
    break;

  case 75:
#line 393 "lab4.y"
    {tab--;}
    break;

  case 78:
#line 398 "lab4.y"
    {tabular (); printf("else\n");}
    break;

  case 79:
#line 399 "lab4.y"
    {tab++;}
    break;

  case 80:
#line 399 "lab4.y"
    {tab--;}
    break;

  case 81:
#line 403 "lab4.y"
    {printf("while ( ");}
    break;

  case 82:
#line 404 "lab4.y"
    {printf(" )\n");}
    break;

  case 83:
#line 404 "lab4.y"
    {
					if ((yyvsp[(4) - (6)].tipoexpr) != LOGICO)
                            Incompatibilidade ("Expressao nao logica/relacional dentro de while");
				}
    break;

  case 84:
#line 408 "lab4.y"
    {tab++;}
    break;

  case 85:
#line 408 "lab4.y"
    {tab--;}
    break;

  case 86:
#line 411 "lab4.y"
    {printf("repeat ");}
    break;

  case 87:
#line 412 "lab4.y"
    {printf(" while ( ");}
    break;

  case 88:
#line 413 "lab4.y"
    {printf(" );\n");}
    break;

  case 89:
#line 413 "lab4.y"
    {
					if ((yyvsp[(7) - (10)].tipoexpr) != LOGICO)
                            Incompatibilidade ("Expressao nao logica/relacional dentro de repeat");
				}
    break;

  case 90:
#line 419 "lab4.y"
    {printf("for ( ");}
    break;

  case 91:
#line 420 "lab4.y"
    {printf(" = "); 
						if ((yyvsp[(4) - (5)].simb)->ndims != 0 || ((yyvsp[(4) - (5)].simb)->tvar != INTEIRO && (yyvsp[(4) - (5)].simb)->tvar != CARACTERE)) {
							Incompatibilidade ("Variavel de inicializacao deve ser escalar do tipo inteiro ou caractere");
						}
				}
    break;

  case 92:
#line 425 "lab4.y"
    {printf("; ");}
    break;

  case 93:
#line 426 "lab4.y"
    {printf("; ");
					if ((yyvsp[(10) - (11)].tipoexpr) != LOGICO) {
						Incompatibilidade ("A segunda expressao de um comando for deve ser do tipo logico");
					}
				}
    break;

  case 94:
#line 431 "lab4.y"
    { printf(" = ");
					if ((yyvsp[(4) - (14)].simb) != (yyvsp[(13) - (14)].simb)) {
						Incompatibilidade ("A variavel de atualizacao do comando for deve ser a mesma daquela de sua inicializacao");
					}
				}
    break;

  case 95:
#line 436 "lab4.y"
    {printf(" )\n");
					if (((yyvsp[(7) - (17)].tipoexpr) != INTEIRO && (yyvsp[(7) - (17)].tipoexpr) != CARACTERE) || ((yyvsp[(16) - (17)].tipoexpr) != INTEIRO && (yyvsp[(16) - (17)].tipoexpr) != CARACTERE)) {
						Incompatibilidade ("A primeira e terceira expressao de um comando for deve ser do tipo inteiro ou caractere");
					}
				}
    break;

  case 96:
#line 441 "lab4.y"
    {tab++;}
    break;

  case 97:
#line 441 "lab4.y"
    {tab--;}
    break;

  case 98:
#line 444 "lab4.y"
    {printf("read (");}
    break;

  case 99:
#line 446 "lab4.y"
    {printf(");\n");}
    break;

  case 100:
#line 449 "lab4.y"
    {
                        if ((yyvsp[(1) - (1)].simb) != NULL) {
                            (yyvsp[(1) - (1)].simb)->inic = VERDADE;
                            (yyvsp[(1) - (1)].simb)->ref = VERDADE;
                        }
                    }
    break;

  case 101:
#line 454 "lab4.y"
    {printf (", ");}
    break;

  case 102:
#line 454 "lab4.y"
    {
                        if ((yyvsp[(4) - (4)].simb) != NULL) {
                            (yyvsp[(4) - (4)].simb)->inic = VERDADE;
                            (yyvsp[(4) - (4)].simb)->ref = VERDADE;
                        }
                    }
    break;

  case 103:
#line 462 "lab4.y"
    {printf("write (");}
    break;

  case 104:
#line 464 "lab4.y"
    {printf(");\n");}
    break;

  case 106:
#line 468 "lab4.y"
    {printf(", ");}
    break;

  case 108:
#line 471 "lab4.y"
    {printf("%s",(yyvsp[(1) - (1)].string));}
    break;

  case 110:
#line 476 "lab4.y"
    {printf ("call %s ();\n",(yyvsp[(2) - (5)].string));}
    break;

  case 111:
#line 478 "lab4.y"
    {printf ("call %s (",(yyvsp[(2) - (3)].string));}
    break;

  case 112:
#line 480 "lab4.y"
    {printf (");\n");}
    break;

  case 113:
#line 483 "lab4.y"
    {printf ("return ;\n");
					(yyval.tipoexpr) = NAOVAR;
			}
    break;

  case 114:
#line 486 "lab4.y"
    {printf ("return ");}
    break;

  case 115:
#line 486 "lab4.y"
    {printf (";\n");
					(yyval.tipoexpr) = (yyvsp[(3) - (4)].tipoexpr);
			}
    break;

  case 116:
#line 491 "lab4.y"
    {if  ((yyvsp[(1) - (1)].simb) != NULL) (yyvsp[(1) - (1)].simb)->inic = (yyvsp[(1) - (1)].simb)->ref = VERDADE;}
    break;

  case 117:
#line 492 "lab4.y"
    {printf ("= ");}
    break;

  case 118:
#line 492 "lab4.y"
    {
                    printf (";\n");
                    if ((yyvsp[(1) - (6)].simb) != NULL)
                        if ((((yyvsp[(1) - (6)].simb)->tvar == INTEIRO || (yyvsp[(1) - (6)].simb)->tvar == CARACTERE) &&
                            ((yyvsp[(5) - (6)].tipoexpr) == REAL || (yyvsp[(5) - (6)].tipoexpr) == LOGICO)) ||
                            ((yyvsp[(1) - (6)].simb)->tvar == REAL && (yyvsp[(5) - (6)].tipoexpr) == LOGICO) ||
                            ((yyvsp[(1) - (6)].simb)->tvar == LOGICO && (yyvsp[(5) - (6)].tipoexpr) != LOGICO))
                            Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                }
    break;

  case 119:
#line 503 "lab4.y"
    {(yyval.infolexpr).nargs = 1;   (yyval.infolexpr).listtipo = InicListTipo ((yyvsp[(1) - (1)].tipoexpr));}
    break;

  case 120:
#line 504 "lab4.y"
    {printf(", ");}
    break;

  case 121:
#line 504 "lab4.y"
    {
				(yyval.infolexpr).nargs = (yyvsp[(1) - (4)].infolexpr).nargs + 1;
				(yyval.infolexpr).listtipo = 
					ConcatListTipo ((yyvsp[(1) - (4)].infolexpr).listtipo, InicListTipo ((yyvsp[(4) - (4)].tipoexpr)));

			}
    break;

  case 123:
#line 513 "lab4.y"
    {printf ("|| ");}
    break;

  case 124:
#line 513 "lab4.y"
    {
                    if ((yyvsp[(1) - (4)].tipoexpr) != LOGICO || (yyvsp[(4) - (4)].tipoexpr) != LOGICO)
                        Incompatibilidade ("Operando improprio para operador or");
                    (yyval.tipoexpr) = LOGICO;
                }
    break;

  case 126:
#line 520 "lab4.y"
    {printf ("&& ");}
    break;

  case 127:
#line 520 "lab4.y"
    {
                    if ((yyvsp[(1) - (4)].tipoexpr) != LOGICO || (yyvsp[(4) - (4)].tipoexpr) != LOGICO)
                        Incompatibilidade ("Operando improprio para operador and");
                    (yyval.tipoexpr) = LOGICO;
                }
    break;

  case 129:
#line 527 "lab4.y"
    {printf ("! ");}
    break;

  case 130:
#line 527 "lab4.y"
    {
                    if ((yyvsp[(3) - (3)].tipoexpr) != LOGICO)
                        Incompatibilidade ("Operando improprio para operador not");
                    (yyval.tipoexpr) = LOGICO;
                }
    break;

  case 132:
#line 534 "lab4.y"
    {
                    switch ((yyvsp[(2) - (2)].atr)) {
                        case LT: printf ("< "); break;
                        case LE: printf ("<= "); break;
                        case EQ: printf ("== "); break;
                        case NE: printf ("!= "); break;
                        case GT: printf ("> "); break;
                        case GE: printf (">= "); break;
                    }
                }
    break;

  case 133:
#line 543 "lab4.y"
    {
                    switch ((yyvsp[(2) - (4)].atr)) {
                        case LT: case LE: case GT: case GE:
                            if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != REAL && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE || (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr) != REAL && (yyvsp[(4) - (4)].tipoexpr) != CARACTERE)
                                Incompatibilidade	("Operando improprio para operador relacional");
                            break;
                        case EQ: case NE:
                            if (((yyvsp[(1) - (4)].tipoexpr) == LOGICO || (yyvsp[(4) - (4)].tipoexpr) == LOGICO) && (yyvsp[(1) - (4)].tipoexpr) != (yyvsp[(4) - (4)].tipoexpr))
                                Incompatibilidade ("Operando improprio para operador relacional");
                            break;
                    }
                    (yyval.tipoexpr) = LOGICO;
                }
    break;

  case 135:
#line 558 "lab4.y"
    {
                    switch ((yyvsp[(2) - (2)].atr)) {
                        case ADD: printf ("+ "); break;
                        case SUB: printf ("- "); break;
                    }
                }
    break;

  case 136:
#line 563 "lab4.y"
    {
                    if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != REAL && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE || (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr)!=REAL && (yyvsp[(4) - (4)].tipoexpr)!=CARACTERE)
                        Incompatibilidade ("Operando improprio para operador aritmetico");
                    if ((yyvsp[(1) - (4)].tipoexpr) == REAL || (yyvsp[(4) - (4)].tipoexpr) == REAL) (yyval.tipoexpr) = REAL;
                    else (yyval.tipoexpr) = INTEIRO;
                }
    break;

  case 138:
#line 572 "lab4.y"
    {
            		if ((yyvsp[(2) - (2)].atr) == MULT) printf (" * ");
            		else if ((yyvsp[(2) - (2)].atr) == DIV) printf (" / ");
					else printf (" %% ");
            	}
    break;

  case 139:
#line 577 "lab4.y"
    {
                    switch ((yyvsp[(2) - (4)].atr)) {
                        case MULT: case DIV:
                            if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != REAL && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE
                                || (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr)!=REAL && (yyvsp[(4) - (4)].tipoexpr)!=CARACTERE)
                                Incompatibilidade ("Operando improprio para operador aritmetico");
                            if ((yyvsp[(1) - (4)].tipoexpr) == REAL || (yyvsp[(4) - (4)].tipoexpr) == REAL) (yyval.tipoexpr) = REAL;
                            else (yyval.tipoexpr) = INTEIRO;
                            break;
                        case MOD:
                            if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE
                                ||  (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr) != CARACTERE)
                                Incompatibilidade ("Operando improprio para operador resto");
                            (yyval.tipoexpr) = INTEIRO;
                            break;
                    }
                }
    break;

  case 140:
#line 596 "lab4.y"
    {
                    if  ((yyvsp[(1) - (1)].simb) != NULL)  {
                        (yyvsp[(1) - (1)].simb)->ref  =  VERDADE;
                        (yyval.tipoexpr) = (yyvsp[(1) - (1)].simb)->tvar;
                    }
                }
    break;

  case 141:
#line 602 "lab4.y"
    {printf ("%d ", (yyvsp[(1) - (1)].valint)); (yyval.tipoexpr) = INTEIRO;}
    break;

  case 142:
#line 603 "lab4.y"
    {printf ("%g ", (yyvsp[(1) - (1)].valfloat)); (yyval.tipoexpr) = REAL;}
    break;

  case 143:
#line 604 "lab4.y"
    {printf ("\'%c\' ", (yyvsp[(1) - (1)].string)); (yyval.tipoexpr) = CARACTERE;}
    break;

  case 144:
#line 605 "lab4.y"
    {printf ("true "); (yyval.tipoexpr) = LOGICO;}
    break;

  case 145:
#line 606 "lab4.y"
    {printf ("false "); (yyval.tipoexpr) = LOGICO;}
    break;

  case 146:
#line 607 "lab4.y"
    {printf ("~ ");}
    break;

  case 147:
#line 607 "lab4.y"
    {
                    if ((yyvsp[(3) - (3)].tipoexpr) != INTEIRO && (yyvsp[(3) - (3)].tipoexpr) != REAL && (yyvsp[(3) - (3)].tipoexpr) != CARACTERE)
                        Incompatibilidade  ("Operando improprio para menos unario");
                    if ((yyvsp[(3) - (3)].tipoexpr) == REAL) (yyval.tipoexpr) = REAL;
                    else (yyval.tipoexpr) = INTEIRO;
                }
    break;

  case 148:
#line 613 "lab4.y"
    {printf ("( ");}
    break;

  case 149:
#line 613 "lab4.y"
    {
                    printf (") "); (yyval.tipoexpr) = (yyvsp[(3) - (4)].tipoexpr);
                }
    break;

  case 151:
#line 618 "lab4.y"
    {
                    printf ("%s ", (yyvsp[(1) - (1)].string));
                    simb = ProcuraSimbDecl ((yyvsp[(1) - (1)].string), escopo);
                    if (simb == NULL)   NaoDeclarado ((yyvsp[(1) - (1)].string));
                    else if (simb->tid != IDVAR)   TipoInadequado ((yyvsp[(1) - (1)].string));
                    (yyval.simb) = simb;
                }
    break;

  case 152:
#line 624 "lab4.y"
    {
                    (yyval.simb) = (yyvsp[(2) - (3)].simb);
                    if ((yyval.simb) != NULL) {
                        if ((yyval.simb)->array == FALSO && (yyvsp[(3) - (3)].nsubscr) > 0)
                             NaoEsperado ("Subscrito\(s)");
                        else if ((yyval.simb)->array == VERDADE && (yyvsp[(3) - (3)].nsubscr) == 0)
                                Esperado ("Subscrito\(s)");
                        else if ((yyval.simb)->ndims != (yyvsp[(3) - (3)].nsubscr))
                            Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                    }
                }
    break;

  case 153:
#line 637 "lab4.y"
    {(yyval.nsubscr) = 0;}
    break;

  case 154:
#line 638 "lab4.y"
    {(yyval.nsubscr) = (yyvsp[(1) - (2)].nsubscr) + 1;}
    break;

  case 155:
#line 641 "lab4.y"
    {printf ("[ ");}
    break;

  case 156:
#line 641 "lab4.y"
    {
                        printf ("] ");
                        if ((yyvsp[(3) - (4)].tipoexpr) != INTEIRO && (yyvsp[(3) - (4)].tipoexpr) != CARACTERE)
                            Incompatibilidade ("Tipo inadequado para subscrito");
                        }
    break;

  case 157:
#line 648 "lab4.y"
    {printf ("%s",(yyvsp[(1) - (1)].string));}
    break;

  case 158:
#line 648 "lab4.y"
    {printf ("(");
					simb = ProcuraSimb ((yyvsp[(1) - (3)].string), escopo->escopo);
					if (! simb) NaoDeclarado ((yyvsp[(1) - (3)].string));
					else if (simb->tid != IDFUNC)
						TipoInadequado ((yyvsp[(1) - (3)].string));
					(yyval.simb) = simb;	
			}
    break;

  case 159:
#line 654 "lab4.y"
    {printf (")");
				(yyval.simb) = (yyvsp[(4) - (6)].simb);
				if ((yyval.simb) && (yyval.simb)->tid == IDFUNC) {
					if ((yyval.simb)->nparam != (yyvsp[(5) - (6)].infolexpr).nargs)
						Incompatibilidade 
				("Numero de argumentos diferente do  numero de parametros");
					ChecArgumentos  ((yyvsp[(5) - (6)].infolexpr).listtipo, (yyval.simb)->listparam); 
				}
			}
    break;

  case 160:
#line 665 "lab4.y"
    { (yyval.infolexpr).nargs = 0; (yyval.infolexpr).listtipo = NULL;}
    break;


/* Line 1267 of yacc.c.  */
#line 2712 "y.tab.c"
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
		      yytoken, &yylval);
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

  if (yyn == YYFINAL)
    YYACCEPT;

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


#line 668 "lab4.y"


/* Inclusao do analisador lexico  */

#include "lex.yy.c" 

tabular () {
	int i;
	for (i = 1; i <= tab; i++)
   	/* printf ("\t");*/
   	printf("  ");
}

comentario () {

	char c;  int estado;
	estado = 1;
	while (estado != 3) {
		switch (estado) {
			case 1:
				c = input ();
				if (c == EOF) estado = 3;
				else if (c == '*') estado = 2;
				break;
			case 2:
				c = input ();
				if (c=='*') estado = 2;
				else if (c == EOF || c=='/') estado = 3;
				else estado = 1;
				break;
		}
	}
}

/*  InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
	int i;
	for (i = 0; i < NCLASSHASH; i++)
		tabsimb[i] = NULL;
}

/*
	ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia, simbolo escopo) {
	simbolo s; int i;
	i = hash (cadeia);

	for (s = tabsimb[i]; (s!=NULL); s = s->prox) {
		if (strcmp(cadeia, s->cadeia) == 0 && (s->escopo == escopo)) break;
	}
	return s;
}

/*
	ProcuraSimbDecl (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL. Esta função procura no escopo local e global.
 */
 simbolo ProcuraSimbDecl (char *cadeia, simbolo escopo) {
	simbolo s = ProcuraSimb (cadeia, escopo);
	if (s != NULL) return s;
	s = ProcuraSimb (cadeia, escopo->escopo);
	return s;
}


/*
	InsereSimb (cadeia, tid, tvar, simbolo escopo): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador, com tvar como
	tipo de variavel, e com o escopo; Retorna um ponteiro para a celula inserida
 */
simbolo InsereSimb (char *cadeia, int tid, int tvar, simbolo escopo) {
	int i; simbolo aux, s;
	i = hash (cadeia);  aux = tabsimb[i];
	s = tabsimb[i] = malloc (sizeof (celsimb));
	s->cadeia = malloc ((strlen(cadeia)+1)* sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->prox = aux; s->tid = tid;  s->tvar = tvar;
	s->escopo = escopo; s->listvardecl = NULL;

/*	Codigo para parametros e variáveis globais e locais  */

	if (declparam) {
		s->inic = s->ref = s->param = VERDADE;
		if (s->tid == IDVAR)
			InsereListSimb (s, &pontparam);
		s->escopo->nparam++;
	}
	else {
		s->inic = s->ref = s->param = FALSO;
		if (s->tid == IDVAR)
			InsereListSimb (s, &pontvardecl);
	}

/*	Codigo para identificador global ou nome de função  */

	if (tid == IDGLOB || tid == IDFUNC || tid == IDPROC) {
		s->listvardecl = (elemlistsimb *) 
			malloc  (sizeof (elemlistsimb));
		s->listvardecl->prox = NULL;
	}
	if (tid == IDGLOB) {
		s->listfunc = (elemlistsimb *) 
			malloc  (sizeof (elemlistsimb));
		s->listfunc->prox = NULL;
	}

/*	Codigo para nome de função e retorno de Inserir */
	if (tid == IDFUNC || tid == IDPROC) {
		s->listparam = (elemlistsimb *) 
			malloc  (sizeof (elemlistsimb));
		s->listparam->prox = NULL;
		s->nparam = 0;
   		InsereListSimb (s, &pontfunc);
	}
	return s;
}

/*
	hash (cadeia): funcao que determina e retorna a classe
	de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
	int i, h;
	for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}

/* ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
	int i; simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			printf ("Classe %d:\n", i);
			for (s = tabsimb[i]; s!=NULL; s = s->prox){
				printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
				if (s->tid == IDVAR) {
					printf (", %s, %d, %d",
						nometipvar[s->tvar], s->inic, s->ref);
                    if (s->array == VERDADE) { int j;
                            printf (", EH ARRAY\n\tndims = %d, dimensoes:", s->ndims);
                            for (j = 1; j <= s->ndims; j++)
                                        printf ("  %d", s->dims[j]);
                    }
                }
                

				printf(")\n");
			}
		}
}

/*  Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
printf
("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

void Incompatibilidade (char *s) {
printf ("\n\n***** Incompatibilidade: %s *****\n\n", s);
}

void Esperado (char *s) {
    printf ("\n\n***** Esperado: %s *****\n\n", s);
}

void NaoEsperado (char *s) {
    printf ("\n\n***** Nao Esperado: %s *****\n\n", s);
}

void VerificaInicRef () {
	int i; simbolo s;

	printf ("\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i])
			for (s = tabsimb[i]; s!=NULL; s = s->prox)
				if (s->tid == IDVAR) {
					if (s->inic == FALSO)
						printf ("%s: Nao Inicializada\n", s->cadeia);
					if (s->ref == FALSO)
						printf ("%s: Nao Referenciada\n", s->cadeia);
				}
}

void ChecArgumentos (pontexprtipo* Ltiparg,   listsimb Lparam) {
	pontexprtipo* p;  pontelemlistsimb q;
	p = Ltiparg->prox; q = Lparam->prox;
	while (p != NULL && q != NULL) {
		switch (q->simb->tvar) {
			case INTEIRO: case CARACTERE:
				if (p->tipo != INTEIRO && p->tipo != CARACTERE)
					Incompatibilidade("Tipo de argumento diferente do tipo de parametro");
				break;
			case REAL:
				if (p->tipo != INTEIRO &&  p->tipo != CARACTERE && 
								p->tipo != REAL)
					Incompatibilidade("Tipo de argumento diferente do tipo de parametro");			
				break;
			case LOGICO:
				if (p->tipo != LOGICO)
					Incompatibilidade("Tipo de argumento diferente do tipo de parametro");
				break;
			default:
				if (q->simb->tvar != p->tipo)
					Incompatibilidade("Tipo de argumento diferente do tipo de parametro");
				break;
		}
		p = p->prox; q = q->prox;
	}


}

pontexprtipo* InicListTipo (int tipoexpr) {
	pontexprtipo* s;
	s = (pontexprtipo*) malloc (sizeof (pontexprtipo));
	s->prox = NULL;
	s->tipo = tipoexpr; 
	return s;
} 

pontexprtipo* ConcatListTipo (pontexprtipo* first, pontexprtipo* second) {
	pontexprtipo* p = first;
	while (p->prox != NULL) p = p->prox;
	p->prox = second;
	return first;
}

void InsereListSimb (simbolo s, listsimb* p) {
	listsimb aux = s->listvardecl;

	if (aux == NULL) s->listvardecl = *p;
	else {
		while (aux->prox != NULL){ 
			aux = aux->prox;
		}
		
		aux->prox = *p;

	}
}



