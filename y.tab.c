/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "lab4.y"
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
#line 130 "lab4.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char string[50];
	int valint, atr;
	float valfloat;
	char carac;
	simbolo simb;
	int tipoexpr;
	int nsubscr;
	infolistexpr infolexpr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 164 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define DOLAR 257
#define CALL 258
#define CHAR 259
#define ELSE 260
#define FALSE 261
#define FLOAT 262
#define FOR 263
#define FUNCTION 264
#define IF 265
#define INT 266
#define LOGIC 267
#define PROCEDURE 268
#define PROGRAM 269
#define READ 270
#define REPEAT 271
#define RETURN 272
#define TRUE 273
#define VAR 274
#define WHILE 275
#define WRITE 276
#define ID 277
#define CHARCT 278
#define STRING 279
#define INTCT 280
#define FLOATCT 281
#define OR 282
#define AND 283
#define NOT 284
#define NEG 285
#define RELOP 286
#define ADOP 287
#define MULTOP 288
#define OPPAR 289
#define CLPAR 290
#define OPBRAK 291
#define CLBRAK 292
#define OPBRACE 293
#define CLBRACE 294
#define SCOLON 295
#define COMMA 296
#define ASSIGN 297
#define INVAL 298
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   20,   22,    0,   21,   25,   21,   24,   24,   28,   26,
   27,   27,   27,   27,   29,   31,   29,   33,   30,   32,
   32,   34,   23,   23,   35,   36,    2,    2,   37,   38,
    3,   40,   41,    3,   42,   43,    4,   44,   45,    4,
   39,   47,   39,   46,   48,    8,    9,    9,   10,   50,
   10,   52,   10,   54,   10,   56,   10,   58,   10,   60,
   10,   62,   10,   64,   10,   65,   10,   66,   10,   67,
   68,   69,   70,   72,   49,   71,   73,   74,   71,   75,
   76,   77,   78,   51,   79,   80,   81,   53,   82,   83,
   84,   85,   86,   87,   88,   55,   90,   57,   89,   91,
   89,   93,   59,   92,   95,   92,   94,   94,   63,   96,
   63,   11,   97,   11,   98,   99,   61,   17,  100,   17,
    5,  101,    5,    6,  102,    6,    7,  103,    7,   12,
  104,   12,   13,  105,   13,   14,  106,   14,   15,   15,
   15,   15,   15,   15,  107,   15,  108,   15,   15,  109,
    1,   16,   16,  111,  110,  112,  113,   19,   18,   18,
};
static const YYINT yylen[] = {                            2,
    0,    0,    8,    0,    0,    3,    1,    2,    0,    4,
    1,    1,    1,    1,    1,    0,    4,    0,    3,    0,
    2,    3,    0,    2,    3,    0,    2,    1,    0,    0,
    8,    0,    0,    9,    0,    0,    7,    0,    0,    8,
    1,    0,    4,    2,    0,    4,    0,    2,    1,    0,
    2,    0,    2,    0,    2,    0,    2,    0,    2,    0,
    2,    0,    2,    0,    2,    0,    2,    0,    2,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    4,    0,
    0,    0,    0,    9,    0,    0,    0,   10,    0,    0,
    0,    0,    0,    0,    0,   20,    0,    6,    1,    0,
    4,    0,    6,    1,    0,    4,    1,    1,    5,    0,
    7,    2,    0,    4,    0,    0,    6,    1,    0,    4,
    1,    0,    4,    1,    0,    4,    1,    0,    3,    1,
    0,    4,    1,    0,    4,    1,    0,    4,    1,    1,
    1,    1,    1,    1,    0,    3,    0,    4,    1,    0,
    3,    0,    2,    0,    4,    0,    0,    6,    0,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    2,    0,    5,   23,    9,    0,
    0,    7,    0,    0,   45,    0,   28,    3,   24,    0,
    8,   13,   12,   11,   14,    0,    0,   47,    0,    0,
   27,   18,    0,   15,    0,    0,   25,    0,   20,   10,
   16,    0,    0,   46,   49,   48,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,   41,    0,   51,    0,   53,   85,   55,    0,
   57,    0,   59,    0,   61,  150,  115,   63,    0,   65,
    0,   67,   69,    0,    0,   21,   17,    0,   44,   39,
   42,   70,   80,    0,   89,   97,  102,  152,    0,    0,
  112,    0,    0,    0,    0,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  116,    0,  144,  143,    0,
  142,  140,  141,  128,  145,  147,  139,    0,    0,  124,
  127,    0,    0,  136,  149,   30,    0,   22,   40,   43,
    0,    0,    0,    0,   99,    0,  107,    0,    0,  104,
  154,  153,    0,    0,    0,    0,    0,    0,    0,  122,
  114,  125,  131,  134,  137,    0,   33,   71,   81,   86,
   90,    0,  100,    0,  105,    0,    0,  109,    0,    0,
    0,  157,  129,  146,    0,    0,    0,    0,    0,    0,
   31,    0,   72,   82,    0,    0,   98,    0,  103,    0,
    0,  117,  119,    0,    0,  148,    0,  126,    0,    0,
  138,   34,   73,   83,    0,    0,  101,  106,  155,    0,
  111,    0,    0,    0,    0,   91,    0,  158,   74,   84,
   87,    0,    0,   88,    0,   77,   75,   92,   78,    0,
    0,    0,   79,   93,    0,    0,   94,   95,    0,   96,
};
static const YYINT yydgoto[] = {                          1,
  127,   16,   31,   17,  148,  129,  130,   45,   36,   46,
   82,  131,  132,  133,  134,  115,  180,  181,  135,    2,
    8,    6,   10,   11,    9,   12,   61,   13,   33,   34,
   59,   58,   39,   86,   19,   20,  103,  166,   62,  104,
  192,   42,   88,   43,  107,   63,  108,   28,   65,   47,
   67,   48,   69,   49,   71,   50,   73,   51,   75,   52,
   78,   53,   80,   54,   55,   56,  109,  193,  213,  223,
  237,  233,  239,  241,  110,  194,  214,  224,   94,  195,
  234,  112,  196,  232,  240,  245,  248,  249,  146,  113,
  198,  149,  114,  150,  200,  155,  102,   99,  153,  220,
  186,  187,  157,  188,  189,  190,  158,  159,   98,  152,
  176,  156,  205,
};
static const YYINT yysindex[] = {                         0,
    0, -266, -264, -185,    0, -174,    0,    0,    0, -242,
    0,    0,  -22, -163,    0, -174,    0,    0,    0, -128,
    0,    0,    0,    0,    0, -156, -129,    0, -124,  -22,
    0,    0, -232,    0,    0, -221,    0, -112,    0,    0,
    0, -117,  -22,    0,    0,    0,  -83,  -90,  -94,  -77,
  -81,  -79,  -84,  -59,  -71,  -86,  -66,  -67, -156,    0,
  -51, -164,    0,  -55,    0,  -50,    0,    0,    0,  -43,
    0,  -42,    0,  -41,    0,    0,    0,    0,  -27,    0,
  -60,    0,    0,    0,  -29,    0,    0,  -40,    0,    0,
    0,    0,    0, -124,    0,    0,    0,    0,  -45,  -36,
    0, -169,  -34,  -22,  -38,    0,  -37,  -22, -169, -169,
  -18,  -84,  -84, -195,  -32,    0,  -30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -277,  -21,    0,
    0, -210,  -25,    0,    0,    0, -157,    0,    0,    0,
 -238, -203,  -28,  -33,    0, -144,    0,  -17, -137,    0,
    0,    0, -169,  -26, -169,  -23,  -97,  -97, -169,    0,
    0,    0,    0,    0,    0,  -24,    0,    0,    0,    0,
    0,  -20,    0,  -19,    0,  -97, -224,    0,  -17,  -16,
  -13,    0,    0,    0, -191, -169, -169,  -97,  -97,  -97,
    0,  -14,    0,    0, -169, -169,    0,  -84,    0, -195,
 -143,    0,    0,  -12, -169,    0,  -21,    0,  -15,  -25,
    0,    0,    0,    0, -187, -215,    0,    0,    0, -169,
    0,  -11, -124, -124,  -10,    0,  -17,    0,    0,    0,
    0, -169,    7,    0, -214,    0,    0,    0,    0,  -84,
 -124,   -9,    0,    0, -169, -165,    0,    0, -124,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -218,    0,    0,    0,    4,
 -219,    0,    0,    0,    0,   -6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -234, -241,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -172,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -123,    0,    0, -197,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -241,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -92,    0, -110,    0,    0,  -76,
    0,    0,    0,    0,    0,    0,    0,    0, -194,    0,
    0, -177,  -65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -118,    0,    0,
    0,    0,    0,    0,   -8,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -88,   -4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -8,    0, -153,    0, -155,  -54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -241, -241,    0,    0,  -47,    0,    0,    0,
    0,    0, -256,    0,    0,    0,    0,    0,    0,    0,
 -241,    0,    0,    0,    0,    0,    0,    0, -241,    0,
};
static const YYINT yygindex[] = {                         0,
  -53,    0,    0,    0,  -98,   84,   86,   -2,    0,  -93,
    0,  117, -135,   89, -148,    0,    0,   79,    0,    0,
  273,    0,    0,    0,    0,  279,   -7,    0,    0,  232,
    0,    0,    0,    0,    0,    0,    0,    0,  188,    0,
    0,    0,    0,    0,    0,  185,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 294
static const YYINT yytable[] = {                         77,
  111,   76,    3,  128,  160,   26,   76,   18,   76,  184,
  141,  142,    4,   76,   76,   76,   64,  161,   76,   76,
   76,   56,   38,   50,   38,   14,   37,   38,   58,   54,
   66,   38,   38,   52,   60,   62,   76,   76,   76,    9,
  201,  211,    9,  160,    6,    4,    9,    9,    6,    4,
   15,  168,  209,   68,  177,   35,  179,  160,  144,  145,
  185,   32,   40,   41,   32,  118,  160,  160,   32,   32,
  202,   15,   44,    6,    4,  163,  164,  119,  160,  226,
  238,  120,  121,  147,  122,  123,  169,  121,  124,  125,
  160,  118,   29,  126,  160,  121,  215,  216,  206,    7,
  121,  121,  225,  119,  130,  130,  179,  120,  121,    5,
  122,  123,  130,   27,  124,  125,  160,  130,  130,  126,
   32,  227,   19,   19,  247,   90,  132,  132,  123,  229,
  230,   91,  167,  235,  132,   30,  123,  113,   91,  132,
  132,  123,  123,  164,  217,  172,  246,  243,  219,  113,
  110,  173,  174,  113,  113,  250,  113,  113,  175,   35,
  113,  113,  110,  118,   57,  113,  110,  110,   15,  110,
  110,  108,   60,  110,  110,  119,   68,  108,  110,  120,
  121,   64,  122,  123,   66,   70,  242,  125,   72,  151,
  151,  126,   76,  151,  151,  151,   74,  151,   79,  151,
   81,  118,  151,  151,  151,  150,  150,  118,   83,  150,
  150,  150,  156,  150,  150,  150,  133,  133,  150,  150,
  133,  133,   84,   85,  133,   89,  133,  135,  135,  133,
  133,  135,  135,   92,  101,  135,   22,  135,   93,   23,
  135,  135,  120,   24,   25,   95,   96,   97,  120,  100,
  105,  116,  117,  138,  106,  136,  143,  139,  151,  154,
  170,  162,  165,  171,  160,  182,  236,   26,  178,  207,
  191,  164,  208,  183,  197,  199,  204,  210,  228,  203,
  212,  159,  221,  222,  231,  160,    4,  244,   29,   21,
   87,  137,  140,  218,
};
static const YYINT yycheck[] = {                         53,
   94,  258,  269,  102,  282,   13,  263,   10,  265,  158,
  109,  110,  277,  270,  271,  272,  258,  295,  275,  276,
  277,  263,   30,  265,  259,  268,   29,  262,  270,  271,
  272,  266,  267,  275,  276,  277,  293,  294,  295,  259,
  176,  190,  262,  282,  264,  264,  266,  267,  268,  268,
  293,  290,  188,  295,  153,  290,  155,  282,  112,  113,
  159,  259,  295,  296,  262,  261,  282,  282,  266,  267,
  295,  293,  294,  293,  293,  286,  287,  273,  282,  295,
  295,  277,  278,  279,  280,  281,  290,  282,  284,  285,
  282,  261,  290,  289,  282,  290,  195,  196,  290,  274,
  295,  296,  290,  273,  282,  283,  205,  277,  278,  295,
  280,  281,  290,  277,  284,  285,  282,  295,  296,  289,
  277,  220,  295,  296,  290,  290,  282,  283,  282,  223,
  224,  296,  290,  232,  290,  264,  290,  261,  296,  295,
  296,  295,  296,  287,  198,  290,  245,  241,  292,  273,
  261,  296,  290,  277,  278,  249,  280,  281,  296,  289,
  284,  285,  273,  261,  277,  289,  277,  278,  293,  280,
  281,  290,  290,  284,  285,  273,  271,  296,  289,  277,
  278,  265,  280,  281,  275,  263,  240,  285,  270,  282,
  283,  289,  277,  286,  287,  288,  276,  290,  258,  292,
  272,  290,  295,  296,  297,  282,  283,  296,  295,  286,
  287,  288,  289,  290,  291,  292,  282,  283,  295,  296,
  286,  287,  289,  291,  290,  277,  292,  282,  283,  295,
  296,  286,  287,  289,  295,  290,  259,  292,  289,  262,
  295,  296,  290,  266,  267,  289,  289,  289,  296,  277,
  280,  297,  289,  292,  295,  290,  275,  295,  291,  290,
  289,  283,  288,  297,  282,  289,  260,  264,  295,  186,
  295,  287,  187,  157,  295,  295,  290,  189,  290,  296,
  295,  290,  295,  205,  295,  290,  293,  297,   16,   11,
   59,  104,  108,  200,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#define YYUNDFTOKEN 414
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DOLAR","CALL","CHAR","ELSE",
"FALSE","FLOAT","FOR","FUNCTION","IF","INT","LOGIC","PROCEDURE","PROGRAM",
"READ","REPEAT","RETURN","TRUE","VAR","WHILE","WRITE","ID","CHARCT","STRING",
"INTCT","FLOATCT","OR","AND","NOT","NEG","RELOP","ADOP","MULTOP","OPPAR",
"CLPAR","OPBRAK","CLBRAK","OPBRACE","CLBRACE","SCOLON","COMMA","ASSIGN","INVAL",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Prog",
"$$1 :",
"$$2 :",
"Prog : $$1 PROGRAM ID SCOLON $$2 Decls SubProgs CompStat",
"Decls :",
"$$3 :",
"Decls : VAR $$3 DeclList",
"DeclList : Declaration",
"DeclList : DeclList Declaration",
"$$4 :",
"Declaration : $$4 Type ElemList SCOLON",
"Type : INT",
"Type : FLOAT",
"Type : CHAR",
"Type : LOGIC",
"ElemList : Elem",
"$$5 :",
"ElemList : ElemList COMMA $$5 Elem",
"$$6 :",
"Elem : ID $$6 DimList",
"DimList :",
"DimList : DimList Dim",
"Dim : OPBRAK INTCT CLBRAK",
"SubProgs :",
"SubProgs : SubProgs SubProgDecl",
"SubProgDecl : Header Decls CompStat",
"$$7 :",
"Header : $$7 FuncHeader",
"Header : ProcHeader",
"$$8 :",
"$$9 :",
"FuncHeader : FUNCTION Type ID OPPAR $$8 CLPAR $$9 SCOLON",
"$$10 :",
"$$11 :",
"FuncHeader : FUNCTION Type ID OPPAR $$10 ParamList CLPAR $$11 SCOLON",
"$$12 :",
"$$13 :",
"ProcHeader : PROCEDURE ID OPPAR $$12 CLPAR $$13 SCOLON",
"$$14 :",
"$$15 :",
"ProcHeader : PROCEDURE ID OPPAR $$14 ParamList CLPAR $$15 SCOLON",
"ParamList : Parameter",
"$$16 :",
"ParamList : ParamList COMMA $$16 Parameter",
"Parameter : Type ID",
"$$17 :",
"CompStat : OPBRACE $$17 StatList CLBRACE",
"StatList :",
"StatList : StatList Statement",
"Statement : CompStat",
"$$18 :",
"Statement : $$18 IfStat",
"$$19 :",
"Statement : $$19 WhileStat",
"$$20 :",
"Statement : $$20 RepeatStat",
"$$21 :",
"Statement : $$21 ForStat",
"$$22 :",
"Statement : $$22 ReadStat",
"$$23 :",
"Statement : $$23 WriteStat",
"$$24 :",
"Statement : $$24 AssignStat",
"$$25 :",
"Statement : $$25 CallStat",
"$$26 :",
"Statement : $$26 ReturnStat",
"$$27 :",
"Statement : $$27 SCOLON",
"$$28 :",
"$$29 :",
"$$30 :",
"$$31 :",
"$$32 :",
"IfStat : IF OPPAR $$28 Expression CLPAR $$29 $$30 $$31 Statement $$32 ElseStat",
"ElseStat :",
"$$33 :",
"$$34 :",
"ElseStat : ELSE $$33 $$34 Statement",
"$$35 :",
"$$36 :",
"$$37 :",
"$$38 :",
"WhileStat : WHILE OPPAR $$35 Expression CLPAR $$36 $$37 $$38 Statement",
"$$39 :",
"$$40 :",
"$$41 :",
"RepeatStat : REPEAT $$39 Statement WHILE OPPAR $$40 Expression CLPAR SCOLON $$41",
"$$42 :",
"$$43 :",
"$$44 :",
"$$45 :",
"$$46 :",
"$$47 :",
"$$48 :",
"ForStat : FOR OPPAR $$42 Variable ASSIGN $$43 Expression SCOLON $$44 Expression SCOLON $$45 Variable ASSIGN $$46 Expression CLPAR $$47 $$48 Statement",
"$$49 :",
"ReadStat : READ OPPAR $$49 ReadList CLPAR SCOLON",
"ReadList : Variable",
"$$50 :",
"ReadList : ReadList COMMA $$50 Variable",
"$$51 :",
"WriteStat : WRITE OPPAR $$51 WriteList CLPAR SCOLON",
"WriteList : WriteElem",
"$$52 :",
"WriteList : WriteList COMMA $$52 WriteElem",
"WriteElem : STRING",
"WriteElem : Expression",
"CallStat : CALL ID OPPAR CLPAR SCOLON",
"$$53 :",
"CallStat : CALL ID OPPAR $$53 Arguments CLPAR SCOLON",
"ReturnStat : RETURN SCOLON",
"$$54 :",
"ReturnStat : RETURN $$54 Expression SCOLON",
"$$55 :",
"$$56 :",
"AssignStat : Variable $$55 ASSIGN $$56 Expression SCOLON",
"ExprList : Expression",
"$$57 :",
"ExprList : ExprList COMMA $$57 Expression",
"Expression : AuxExpr1",
"$$58 :",
"Expression : Expression OR $$58 AuxExpr1",
"AuxExpr1 : AuxExpr2",
"$$59 :",
"AuxExpr1 : AuxExpr1 AND $$59 AuxExpr2",
"AuxExpr2 : AuxExpr3",
"$$60 :",
"AuxExpr2 : NOT $$60 AuxExpr3",
"AuxExpr3 : AuxExpr4",
"$$61 :",
"AuxExpr3 : AuxExpr4 RELOP $$61 AuxExpr4",
"AuxExpr4 : Term",
"$$62 :",
"AuxExpr4 : AuxExpr4 ADOP $$62 Term",
"Term : Factor",
"$$63 :",
"Term : Term MULTOP $$63 Factor",
"Factor : Variable",
"Factor : INTCT",
"Factor : FLOATCT",
"Factor : CHARCT",
"Factor : TRUE",
"Factor : FALSE",
"$$64 :",
"Factor : NEG $$64 Factor",
"$$65 :",
"Factor : OPPAR $$65 Expression CLPAR",
"Factor : FuncCall",
"$$66 :",
"Variable : ID $$66 SubscrList",
"SubscrList :",
"SubscrList : SubscrList Subscript",
"$$67 :",
"Subscript : OPBRAK $$67 AuxExpr4 CLBRAK",
"$$68 :",
"$$69 :",
"FuncCall : ID $$68 OPPAR $$69 Arguments CLPAR",
"Arguments :",
"Arguments : ExprList",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 681 "lab4.y"

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
		printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
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


#line 929 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 202 "lab4.y"
	{ InicTabSimb (); declparam = FALSO;
									escopo = simb = InsereSimb("global##", IDPROG, NAOVAR, NULL);
							  	pontvardecl = simb->listvardecl;
									pontfunc = simb->listfunc;
								}
break;
case 2:
#line 207 "lab4.y"
	{printf ("program %s ;\n", yystack.l_mark[-1].string);}
break;
case 3:
#line 208 "lab4.y"
	{ 
		                VerificaInicRef ();
		                ImprimeTabSimb ();
		            }
break;
case 5:
#line 215 "lab4.y"
	{tabular (); printf ("var\n"); tab++;}
break;
case 6:
#line 217 "lab4.y"
	{tab--; tabular (); printf ("\n");}
break;
case 9:
#line 224 "lab4.y"
	{tabular ();}
break;
case 10:
#line 225 "lab4.y"
	{printf(";\n");}
break;
case 11:
#line 228 "lab4.y"
	{printf ("int "); tipocorrente = INTEIRO;}
break;
case 12:
#line 229 "lab4.y"
	{printf ("float "); tipocorrente = REAL;}
break;
case 13:
#line 230 "lab4.y"
	{printf ("char "); tipocorrente = CARACTERE;}
break;
case 14:
#line 231 "lab4.y"
	{printf ("logic "); tipocorrente = LOGICO;}
break;
case 16:
#line 235 "lab4.y"
	{printf(", ");}
break;
case 18:
#line 238 "lab4.y"
	{
	              printf ("%s ", yystack.l_mark[0].string);
	              if  (ProcuraSimb (yystack.l_mark[0].string, escopo)  !=  NULL)
                  DeclaracaoRepetida (yystack.l_mark[0].string);
	              else {
                  simb = InsereSimb (yystack.l_mark[0].string,  IDVAR,  tipocorrente, escopo);
                  simb->array = FALSO; simb->ndims = 0;
	              }
		          }
break;
case 21:
#line 250 "lab4.y"
	{simb->array = VERDADE;}
break;
case 22:
#line 253 "lab4.y"
	{
						              printf ("[ %d ] ", yystack.l_mark[-1].valint);
						              if (yystack.l_mark[-1].valint <= 0) Esperado ("Valor inteiro positivo");
						              simb->ndims++; simb->dims[simb->ndims] = yystack.l_mark[-1].valint;}
break;
case 25:
#line 263 "lab4.y"
	{
								if (yystack.l_mark[0].tipoexpr == NAOVAR) {
									if (yystack.l_mark[-2].simb->tvar != NAOVAR)
										Incompatibilidade ("Função não void sem retorno");
								} else {
									if (yystack.l_mark[-2].simb->tvar == INTEIRO && yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr != CARACTERE)  
										Incompatibilidade ("Função do tipo inteiro não retorna inteiro ou caractere");
									if (yystack.l_mark[-2].simb->tvar == REAL && yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr != REAL && yystack.l_mark[0].tipoexpr != CARACTERE)
										Incompatibilidade ("Função do tipo real não retorna real, inteiro ou caractere");
									if (yystack.l_mark[-2].simb->tvar == CARACTERE && yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr != CARACTERE)
										Incompatibilidade ("Função do tipo caractere não retorna inteiro ou caractere");
									if (yystack.l_mark[-2].simb->tvar == LOGICO && yystack.l_mark[0].tipoexpr != LOGICO)
										Incompatibilidade ("Função do tipo lógico não retorna tipo lógico");
									if (yystack.l_mark[-2].simb->tvar == NAOVAR && yystack.l_mark[0].tipoexpr != NAOVAR)
										Incompatibilidade ("Função do tipo void retornando expressão");
									}	
								escopo = escopo->escopo;
							}
break;
case 26:
#line 283 "lab4.y"
	{printf("function ");}
break;
case 27:
#line 283 "lab4.y"
	{yyval.simb = yystack.l_mark[0].simb;}
break;
case 28:
#line 284 "lab4.y"
	{yyval.simb = yystack.l_mark[0].simb;}
break;
case 29:
#line 287 "lab4.y"
	{declparam = VERDADE;}
break;
case 30:
#line 287 "lab4.y"
	{declparam = FALSO;}
break;
case 31:
#line 287 "lab4.y"
	{
								printf ("%s ();\n",yystack.l_mark[-5].string); yyval.simb = simb;
								if  (ProcuraSimb (yystack.l_mark[-5].string, escopo)  !=  NULL)
                  DeclaracaoRepetida (yystack.l_mark[-5].string);
								escopo = simb = InsereSimb (yystack.l_mark[-5].string, IDFUNC, tipocorrente, escopo);
								pontvardecl = simb->listvardecl;
								pontparam = simb->listparam;
	              yyval.simb = simb;
							}
break;
case 32:
#line 296 "lab4.y"
	{
								declparam = VERDADE;
								printf ("%s (",yystack.l_mark[-1].string);
								if  (ProcuraSimb (yystack.l_mark[-1].string, escopo)  !=  NULL)
                  DeclaracaoRepetida (yystack.l_mark[-1].string);
									escopo = simb = InsereSimb (yystack.l_mark[-1].string, IDFUNC, tipocorrente, escopo);
									pontvardecl = simb->listvardecl;
									pontparam = simb->listparam;
									yyval.simb = simb;
							}
break;
case 33:
#line 306 "lab4.y"
	{declparam = FALSO;}
break;
case 34:
#line 307 "lab4.y"
	{printf (");\n");
								yyval.simb = simb;
							}
break;
case 35:
#line 312 "lab4.y"
	{declparam = VERDADE;}
break;
case 36:
#line 312 "lab4.y"
	{declparam = FALSO;}
break;
case 37:
#line 312 "lab4.y"
	{
								if  (ProcuraSimb (yystack.l_mark[-5].string, escopo)  !=  NULL)
	                DeclaracaoRepetida (yystack.l_mark[-5].string);
								escopo = simb = InsereSimb (yystack.l_mark[-5].string, IDPROC, NAOVAR, escopo);
								pontvardecl = simb->listvardecl;
								pontparam = simb->listparam;
								yyval.simb = simb;
								printf ("procedure %s ();\n",yystack.l_mark[-5].string);
								yyval.simb = simb;
							}
break;
case 38:
#line 323 "lab4.y"
	{
								printf ("procedure %s (",yystack.l_mark[-1].string); 
								declparam = VERDADE;
								if  (ProcuraSimb (yystack.l_mark[-1].string, escopo)  !=  NULL)
	                DeclaracaoRepetida (yystack.l_mark[-1].string);
								escopo = simb = InsereSimb (yystack.l_mark[-1].string, IDPROC, NAOVAR, escopo);
								pontvardecl = simb->listvardecl;
								pontparam = simb->listparam;
								yyval.simb = simb;
				
							}
break;
case 39:
#line 334 "lab4.y"
	{declparam = FALSO;}
break;
case 40:
#line 335 "lab4.y"
	{printf (");\n");
								yyval.simb = simb;
							}
break;
case 42:
#line 341 "lab4.y"
	{printf(", ");}
break;
case 44:
#line 344 "lab4.y"
	{printf(" %s",yystack.l_mark[0].string);}
break;
case 45:
#line 347 "lab4.y"
	{
								tab--;
								tabular (); 
								printf ("\{\n"); 
								tab++;	
								tab++;
							}
break;
case 46:
#line 355 "lab4.y"
	{
								tab--;
								tab--; 
								tabular ();
								 printf ("}\n");
								 tab++;
								 yyval.tipoexpr = yystack.l_mark[-1].tipoexpr;
							}
break;
case 48:
#line 366 "lab4.y"
	{
							yyval.tipoexpr = yystack.l_mark[0].tipoexpr;
						}
break;
case 49:
#line 371 "lab4.y"
	{yyval.tipoexpr = yystack.l_mark[0].tipoexpr;}
break;
case 50:
#line 372 "lab4.y"
	{tabular ();}
break;
case 51:
#line 372 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 52:
#line 373 "lab4.y"
	{tabular ();}
break;
case 53:
#line 373 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 54:
#line 374 "lab4.y"
	{tabular ();}
break;
case 55:
#line 374 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 56:
#line 375 "lab4.y"
	{tabular ();}
break;
case 57:
#line 375 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 58:
#line 376 "lab4.y"
	{tabular ();}
break;
case 59:
#line 376 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 60:
#line 377 "lab4.y"
	{tabular ();}
break;
case 61:
#line 377 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 62:
#line 378 "lab4.y"
	{tabular ();}
break;
case 63:
#line 378 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 64:
#line 379 "lab4.y"
	{tabular ();}
break;
case 65:
#line 379 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 66:
#line 380 "lab4.y"
	{tabular ();}
break;
case 67:
#line 380 "lab4.y"
	{
							yyval.tipoexpr = yystack.l_mark[0].tipoexpr;
						}
break;
case 68:
#line 383 "lab4.y"
	{tabular ();}
break;
case 69:
#line 383 "lab4.y"
	{yyval.tipoexpr = NAOVAR;}
break;
case 70:
#line 386 "lab4.y"
	{printf("if (");}
break;
case 71:
#line 387 "lab4.y"
	{printf(")\n");}
break;
case 72:
#line 387 "lab4.y"
	{
								if (yystack.l_mark[-2].tipoexpr != LOGICO)
                  Incompatibilidade ("Expressao nao logica/relacional dentro de if");
							}
break;
case 73:
#line 391 "lab4.y"
	{tab++;}
break;
case 74:
#line 391 "lab4.y"
	{tab--;}
break;
case 77:
#line 396 "lab4.y"
	{tabular (); printf("else\n");}
break;
case 78:
#line 397 "lab4.y"
	{tab++;}
break;
case 79:
#line 397 "lab4.y"
	{tab--;}
break;
case 80:
#line 401 "lab4.y"
	{printf("while ( ");}
break;
case 81:
#line 402 "lab4.y"
	{printf(" )\n");}
break;
case 82:
#line 402 "lab4.y"
	{
									if (yystack.l_mark[-2].tipoexpr != LOGICO)
		                Incompatibilidade ("Expressao nao logica/relacional dentro de while");
								}
break;
case 83:
#line 406 "lab4.y"
	{tab++;}
break;
case 84:
#line 406 "lab4.y"
	{tab--;}
break;
case 85:
#line 409 "lab4.y"
	{printf("repeat ");}
break;
case 86:
#line 410 "lab4.y"
	{printf(" while ( ");}
break;
case 87:
#line 411 "lab4.y"
	{printf(" );\n");}
break;
case 88:
#line 411 "lab4.y"
	{
								if (yystack.l_mark[-3].tipoexpr != LOGICO)
                	Incompatibilidade ("Expressao nao logica/relacional dentro de repeat");
							}
break;
case 89:
#line 417 "lab4.y"
	{printf("for ( ");}
break;
case 90:
#line 418 "lab4.y"
	{printf(" = "); 
							if (yystack.l_mark[-1].simb != NULL && (yystack.l_mark[-1].simb->ndims != 0 || (yystack.l_mark[-1].simb->tvar != INTEIRO && yystack.l_mark[-1].simb->tvar != CARACTERE))) {
								Incompatibilidade ("Variavel de inicializacao deve ser escalar do tipo inteiro ou caractere");
							}
						}
break;
case 91:
#line 423 "lab4.y"
	{printf("; ");}
break;
case 92:
#line 424 "lab4.y"
	{printf("; ");
							if (yystack.l_mark[-1].tipoexpr != LOGICO) {
								Incompatibilidade ("A segunda expressao de um comando for deve ser do tipo logico");
							}
						}
break;
case 93:
#line 429 "lab4.y"
	{ printf(" = ");
							if (yystack.l_mark[-10].simb != yystack.l_mark[-1].simb) {
								Incompatibilidade ("A variavel de atualizacao do comando for deve ser a mesma daquela de sua inicializacao");
							}
						}
break;
case 94:
#line 434 "lab4.y"
	{printf(" )\n");
							if ((yystack.l_mark[-10].tipoexpr != INTEIRO && yystack.l_mark[-10].tipoexpr != CARACTERE) || (yystack.l_mark[-1].tipoexpr != INTEIRO && yystack.l_mark[-1].tipoexpr != CARACTERE)) {
								Incompatibilidade ("A primeira e terceira expressao de um comando for deve ser do tipo inteiro ou caractere");
							}
						}
break;
case 95:
#line 439 "lab4.y"
	{tab++;}
break;
case 96:
#line 439 "lab4.y"
	{tab--;}
break;
case 97:
#line 442 "lab4.y"
	{printf("read (");}
break;
case 98:
#line 444 "lab4.y"
	{printf(");\n");}
break;
case 99:
#line 447 "lab4.y"
	{
		              if (yystack.l_mark[0].simb != NULL) {
		                yystack.l_mark[0].simb->inic = VERDADE;
		                yystack.l_mark[0].simb->ref = VERDADE;
		              }
		          }
break;
case 100:
#line 453 "lab4.y"
	{printf (", ");}
break;
case 101:
#line 454 "lab4.y"
	{
                if (yystack.l_mark[0].simb != NULL) {
                  yystack.l_mark[0].simb->inic = VERDADE;
                  yystack.l_mark[0].simb->ref = VERDADE;
                }
              }
break;
case 102:
#line 462 "lab4.y"
	{printf("write (");}
break;
case 103:
#line 464 "lab4.y"
	{printf(");\n");}
break;
case 105:
#line 468 "lab4.y"
	{printf(", ");}
break;
case 107:
#line 471 "lab4.y"
	{printf("%s",yystack.l_mark[0].string);}
break;
case 109:
#line 476 "lab4.y"
	{printf ("call %s ();\n",yystack.l_mark[-3].string);
								simb = ProcuraSimb (yystack.l_mark[-3].string, escopo);
								if (! simb) NaoDeclarado (yystack.l_mark[-3].string);
								else if (simb->tid != IDPROC)
									TipoInadequado (yystack.l_mark[-3].string);
								yyval.simb = simb;	
							}
break;
case 110:
#line 484 "lab4.y"
	{printf ("call %s (",yystack.l_mark[-1].string);
								simb = ProcuraSimb (yystack.l_mark[-1].string, escopo);
								if (! simb) NaoDeclarado (yystack.l_mark[-1].string);
								else if (simb->tid != IDPROC)
									TipoInadequado (yystack.l_mark[-1].string);
								yyval.simb = simb;	
							}
break;
case 111:
#line 492 "lab4.y"
	{printf (");\n");}
break;
case 112:
#line 495 "lab4.y"
	{printf ("return ;\n");
								yyval.tipoexpr = NAOVAR;
						}
break;
case 113:
#line 498 "lab4.y"
	{printf ("return ");}
break;
case 114:
#line 498 "lab4.y"
	{printf (";\n");
								yyval.tipoexpr = yystack.l_mark[-1].tipoexpr;
						}
break;
case 115:
#line 503 "lab4.y"
	{if  (yystack.l_mark[0].simb != NULL) yystack.l_mark[0].simb->inic = yystack.l_mark[0].simb->ref = VERDADE;}
break;
case 116:
#line 504 "lab4.y"
	{printf ("= ");}
break;
case 117:
#line 504 "lab4.y"
	{
                  printf (";\n");
                  if (yystack.l_mark[-5].simb != NULL)
                    if (((yystack.l_mark[-5].simb->tvar == INTEIRO || yystack.l_mark[-5].simb->tvar == CARACTERE) &&
                      (yystack.l_mark[-1].tipoexpr == REAL || yystack.l_mark[-1].tipoexpr == LOGICO)) ||
                      (yystack.l_mark[-5].simb->tvar == REAL && yystack.l_mark[-1].tipoexpr == LOGICO) ||
                      (yystack.l_mark[-5].simb->tvar == LOGICO && yystack.l_mark[-1].tipoexpr != LOGICO))
                      	Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                }
break;
case 118:
#line 515 "lab4.y"
	{yyval.infolexpr.nargs = 1;   yyval.infolexpr.listtipo = InicListTipo (yystack.l_mark[0].tipoexpr);}
break;
case 119:
#line 516 "lab4.y"
	{printf(", ");}
break;
case 120:
#line 516 "lab4.y"
	{
							yyval.infolexpr.nargs = yystack.l_mark[-3].infolexpr.nargs + 1;
							yyval.infolexpr.listtipo = 
								ConcatListTipo (yystack.l_mark[-3].infolexpr.listtipo, InicListTipo (yystack.l_mark[0].tipoexpr));

						}
break;
case 122:
#line 525 "lab4.y"
	{printf ("|| ");}
break;
case 123:
#line 525 "lab4.y"
	{
                  if (yystack.l_mark[-3].tipoexpr != LOGICO || yystack.l_mark[0].tipoexpr != LOGICO)
                    Incompatibilidade ("Operando improprio para operador or");
                  yyval.tipoexpr = LOGICO;
                }
break;
case 125:
#line 532 "lab4.y"
	{printf ("&& ");}
break;
case 126:
#line 532 "lab4.y"
	{
                  if (yystack.l_mark[-3].tipoexpr != LOGICO || yystack.l_mark[0].tipoexpr != LOGICO)
                    Incompatibilidade ("Operando improprio para operador and");
                  yyval.tipoexpr = LOGICO;
                }
break;
case 128:
#line 539 "lab4.y"
	{printf ("! ");}
break;
case 129:
#line 539 "lab4.y"
	{
                  if (yystack.l_mark[0].tipoexpr != LOGICO)
                    Incompatibilidade ("Operando improprio para operador not");
                  yyval.tipoexpr = LOGICO;
                }
break;
case 131:
#line 546 "lab4.y"
	{
                  switch (yystack.l_mark[0].atr) {
                    case LT: printf ("< "); break;
                    case LE: printf ("<= "); break;
                    case EQ: printf ("== "); break;
                    case NE: printf ("!= "); break;
                    case GT: printf ("> "); break;
                    case GE: printf (">= "); break;
                  }
                }
break;
case 132:
#line 555 "lab4.y"
	{
                  switch (yystack.l_mark[-2].atr) {
                    case LT: case LE: case GT: case GE:
                      if (yystack.l_mark[-3].tipoexpr != INTEIRO && yystack.l_mark[-3].tipoexpr != REAL && yystack.l_mark[-3].tipoexpr != CARACTERE || yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr != REAL && yystack.l_mark[0].tipoexpr != CARACTERE)
                        Incompatibilidade	("Operando improprio para operador relacional");
                      break;
                    case EQ: case NE:
                      if ((yystack.l_mark[-3].tipoexpr == LOGICO || yystack.l_mark[0].tipoexpr == LOGICO) && yystack.l_mark[-3].tipoexpr != yystack.l_mark[0].tipoexpr)
                        Incompatibilidade ("Operando improprio para operador relacional");
                      break;
                  }
                  yyval.tipoexpr = LOGICO;
                }
break;
case 134:
#line 570 "lab4.y"
	{
		              switch (yystack.l_mark[0].atr) {
                    case ADD: printf ("+ "); break;
                    case SUB: printf ("- "); break;
		              }
                }
break;
case 135:
#line 575 "lab4.y"
	{
                  if (yystack.l_mark[-3].tipoexpr != INTEIRO && yystack.l_mark[-3].tipoexpr != REAL && yystack.l_mark[-3].tipoexpr != CARACTERE || yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr!=REAL && yystack.l_mark[0].tipoexpr!=CARACTERE)
                      Incompatibilidade ("Operando improprio para operador aritmetico");
                  if (yystack.l_mark[-3].tipoexpr == REAL || yystack.l_mark[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                  else yyval.tipoexpr = INTEIRO;
                }
break;
case 137:
#line 584 "lab4.y"
	{
          		if (yystack.l_mark[0].atr == MULT) printf (" * ");
          		else if (yystack.l_mark[0].atr == DIV) printf (" / ");
						else printf (" %% ");
            	}
break;
case 138:
#line 589 "lab4.y"
	{
		            switch (yystack.l_mark[-2].atr) {
		              case MULT: case DIV:
		                if (yystack.l_mark[-3].tipoexpr != INTEIRO && yystack.l_mark[-3].tipoexpr != REAL && yystack.l_mark[-3].tipoexpr != CARACTERE
		                  || yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr!=REAL && yystack.l_mark[0].tipoexpr!=CARACTERE)
		                  Incompatibilidade ("Operando improprio para operador aritmetico");
		                if (yystack.l_mark[-3].tipoexpr == REAL || yystack.l_mark[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
		                else yyval.tipoexpr = INTEIRO;
		                break;
		              case MOD:
		                if (yystack.l_mark[-3].tipoexpr != INTEIRO && yystack.l_mark[-3].tipoexpr != CARACTERE
		                  ||  yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr != CARACTERE)
		                  Incompatibilidade ("Operando improprio para operador resto");
		                yyval.tipoexpr = INTEIRO;
		                break;
		            }
              }
break;
case 139:
#line 608 "lab4.y"
	{
                    if  (yystack.l_mark[0].simb != NULL)  {
                        yystack.l_mark[0].simb->ref  =  VERDADE;
                        yyval.tipoexpr = yystack.l_mark[0].simb->tvar;
                    }
                }
break;
case 140:
#line 614 "lab4.y"
	{printf ("%d ", yystack.l_mark[0].valint); yyval.tipoexpr = INTEIRO;}
break;
case 141:
#line 615 "lab4.y"
	{printf ("%g ", yystack.l_mark[0].valfloat); yyval.tipoexpr = REAL;}
break;
case 142:
#line 616 "lab4.y"
	{printf ("\'%c\' ", yystack.l_mark[0].string); yyval.tipoexpr = CARACTERE;}
break;
case 143:
#line 617 "lab4.y"
	{printf ("true "); yyval.tipoexpr = LOGICO;}
break;
case 144:
#line 618 "lab4.y"
	{printf ("false "); yyval.tipoexpr = LOGICO;}
break;
case 145:
#line 619 "lab4.y"
	{printf ("~ ");}
break;
case 146:
#line 619 "lab4.y"
	{
                    if (yystack.l_mark[0].tipoexpr != INTEIRO && yystack.l_mark[0].tipoexpr != REAL && yystack.l_mark[0].tipoexpr != CARACTERE)
                        Incompatibilidade  ("Operando improprio para menos unario");
                    if (yystack.l_mark[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                    else yyval.tipoexpr = INTEIRO;
                }
break;
case 147:
#line 625 "lab4.y"
	{printf ("( ");}
break;
case 148:
#line 625 "lab4.y"
	{
                    printf (") "); yyval.tipoexpr = yystack.l_mark[-1].tipoexpr;
                }
break;
case 150:
#line 630 "lab4.y"
	{
                    printf ("%s ", yystack.l_mark[0].string);
                    simb = ProcuraSimbDecl (yystack.l_mark[0].string, escopo);
                    if (simb == NULL)   NaoDeclarado (yystack.l_mark[0].string);
                    else if (simb->tid != IDVAR)   TipoInadequado (yystack.l_mark[0].string);
                    yyval.simb = simb;
                }
break;
case 151:
#line 636 "lab4.y"
	{
                    yyval.simb = yystack.l_mark[-1].simb;
                    if (yyval.simb != NULL) {
                        if (yyval.simb->array == FALSO && yystack.l_mark[0].nsubscr > 0)
                             NaoEsperado ("Subscrito\(s)");
                        else if (yyval.simb->array == VERDADE && yystack.l_mark[0].nsubscr == 0)
                                Esperado ("Subscrito\(s)");
                        else if (yyval.simb->ndims != yystack.l_mark[0].nsubscr)
                            Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                    }
                }
break;
case 152:
#line 649 "lab4.y"
	{yyval.nsubscr = 0;}
break;
case 153:
#line 650 "lab4.y"
	{yyval.nsubscr = yystack.l_mark[-1].nsubscr + 1;}
break;
case 154:
#line 653 "lab4.y"
	{printf ("[ ");}
break;
case 155:
#line 653 "lab4.y"
	{
                        printf ("] ");
                        if (yystack.l_mark[-1].tipoexpr != INTEIRO && yystack.l_mark[-1].tipoexpr != CARACTERE)
                            Incompatibilidade ("Tipo inadequado para subscrito");
                        }
break;
case 156:
#line 660 "lab4.y"
	{printf ("%s",yystack.l_mark[0].string);}
break;
case 157:
#line 660 "lab4.y"
	{printf ("(");
					simb = ProcuraSimb (yystack.l_mark[-2].string, escopo);
					if (! simb) NaoDeclarado (yystack.l_mark[-2].string);
					else if (simb->tid != IDFUNC)
						TipoInadequado (yystack.l_mark[-2].string);
					yyval.simb = simb;	
			}
break;
case 158:
#line 666 "lab4.y"
	{printf (")");
				yyval.simb = yystack.l_mark[-1].simb;
				if (yyval.simb && yyval.simb->tid == IDFUNC) {
					if (yyval.simb->nparam != yystack.l_mark[-1].infolexpr.nargs)
						Incompatibilidade 
				("Numero de argumentos diferente do  numero de parametros");
					ChecArgumentos  (yystack.l_mark[-1].infolexpr.listtipo, yyval.simb->listparam); 
				}
			}
break;
case 159:
#line 677 "lab4.y"
	{ yyval.infolexpr.nargs = 0; yyval.infolexpr.listtipo = NULL;}
break;
#line 1936 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
