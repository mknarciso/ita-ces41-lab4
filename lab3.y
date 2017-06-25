%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define 	ADD		1
#define 	SUB		2

#define 	MULT	3
#define 	DIV		4
#define 	MOD		5

#define 	LT 		1
#define 	LE 		2
#define		GT		3
#define		GE		4
#define		EQ		5
#define		NE		6


int tab = 0;
%}
%union {
	char string[50];
	int valint, atr;
	float valfloat;
	char carac;
}
%token		DOLAR

%token CALL 		
%token CHAR 		
%token ELSE 		
%token FALSE 		
%token FLOAT 		
%token FOR 		
%token FUNCTION 	
%token IF 			
%token INT 		
%token LOGIC 		
%token PROCEDURE 	
%token PROGRAM 	
%token READ 		
%token REPEAT 		
%token RETURN 		
%token TRUE 		
%token VAR 	
%token WHILE 
%token WRITE 

%token	<string>	ID
%token	<string>	CHARCT
%token	<string>	STRING
%token	<valint>	INTCT
%token	<valfloat>	FLOATCT
%token				OR
%token				AND
%token				NOT
%token 				NEG
%token	<atr>		RELOP
%token	<atr>		ADOP
%token	<atr>		MULTOP
%token				OPPAR
%token				CLPAR
%token				OPBRAK
%token 				CLBRAK
%token				OPBRACE
%token				CLBRACE
%token				SCOLON
%token				COMMA
%token				ASSIGN
%token	<carac>		INVAL

%%

Prog 		: 	PROGRAM ID SCOLON {printf ("program %s; \n\n", $2);} 
				Decls 
				SubProgs 
				CompStat
			;

Decls 		:
			| 	VAR {tabular (); printf ("var\n"); tab++;} 
				DeclList
				{tab--; tabular (); printf ("\n");}
			;

DeclList 	:	Declaration
			| 	DeclList Declaration
			;

Declaration : 	{tabular ();} 
				Type ElemList SCOLON {printf(";\n");}
			;

Type 		: 	INT 	{printf("int ");}
			| 	FLOAT	{printf("float ");}
			| 	CHAR 	{printf("char ");}
			| 	LOGIC	{printf("logic ");}
			;

ElemList 	: 	Elem
			| 	ElemList COMMA  {printf(", ");}	Elem
			;

Elem 		: 	ID {printf ("%s", $1);} DimList
			;

DimList 	:
			| 	DimList Dim
			;

Dim 		: 	OPBRAK 	INTCT CLBRAK {printf ("[%d]", $2);}
			;

SubProgs 	:
			|	SubProgs SubProgDecl
			;

SubProgDecl :	Header Decls CompStat
			;

Header 		: 	{printf("function ");} FuncHeader
			| 	ProcHeader
			;

FuncHeader 	: 	FUNCTION Type ID OPPAR CLPAR SCOLON 
				{printf ("%s ();\n",$3);}
			|	FUNCTION Type ID OPPAR 
				{printf ("%s (",$3);}	
				ParamList CLPAR SCOLON
				{printf (");\n");}
			;

ProcHeader 	: 	PROCEDURE ID OPPAR CLPAR SCOLON
				{printf ("procedure %s ();\n",$2);}
			| 	PROCEDURE ID OPPAR 
				{printf ("procedure %s (",$2);}
				ParamList CLPAR SCOLON
				{printf (");\n");}
			;

ParamList 	: 	Parameter
			|	ParamList COMMA {printf(", ");} Parameter 
			;

Parameter 	:	Type ID {printf(" %s",$2);}


CompStat    :	OPBRACE {
					tab--;
					tabular (); 
					printf ("\{\n"); 
					tab++;	
					tab++;
				}
				StatList 
				CLBRACE {
					tab--;
					tab--; 
					tabular ();
					 printf ("}\n");
					 tab++;
				}
			;

StatList	:	
			|	StatList Statement
			;

Statement   :	CompStat
			|	{tabular ();} IfStat
			|	{tabular ();} WhileStat
			|	{tabular ();} RepeatStat
			|	{tabular ();} ForStat
			|	{tabular ();} ReadStat
			|	{tabular ();} WriteStat
			|	{tabular ();} AssignStat
			|	{tabular ();} CallStat
			|	{tabular ();} ReturnStat
			|	{tabular ();} SCOLON
			;

IfStat		: 	IF OPPAR {printf("if (");} 
				Expression CLPAR {printf(")\n");}
				{tab++;} Statement {tab--;}
				ElseStat
			;

ElseStat 	: 	
			| 	ELSE {tabular (); printf("else\n");} 
				{tab++;} Statement {tab--;}

			;

WhileStat 	: 	WHILE OPPAR {printf("while ( ");}
				Expression CLPAR {printf(" )\n");}
				{tab++;} Statement {tab--;}
			;

RepeatStat 	: 	REPEAT {printf("repeat ");}
				Statement WHILE OPPAR {printf(" while ( ");}
				Expression CLPAR SCOLON {printf(" );\n");}
			;

ForStat 	: 	FOR OPPAR {printf("for ( ");}
				Variable ASSIGN {printf(" = ");}
				Expression SCOLON {printf("; ");}
				Expression SCOLON {printf("; ");}
				Variable ASSIGN {printf(" = ");}
				Expression CLPAR {printf(" )\n");}
				{tab++;} Statement {tab--;}
			;

ReadStat 	:	READ OPPAR {printf("read (");} 
				ReadList CLPAR SCOLON
				{printf(");\n");}
			;

ReadList 	: 	Variable
			| 	ReadList COMMA {printf(", ");} Variable
			;

WriteStat 	: 	WRITE OPPAR {printf("write (");} 
				WriteList 
				CLPAR SCOLON {printf(");\n");}
			;

WriteList 	: 	WriteElem
			| 	WriteList COMMA {printf(", ");} WriteElem
			;

WriteElem 	: 	STRING {printf("%s",$1);}
			| 	Expression 
			;

CallStat 	: 	CALL ID OPPAR CLPAR SCOLON 
				{printf ("call %s ();\n",$2);}
			|	CALL ID OPPAR 
				{printf ("call %s (",$2);}
				ExprList CLPAR SCOLON
				{printf (");\n");}
			;

ReturnStat 	: 	RETURN SCOLON {printf ("return ;\n");}
			| 	RETURN {printf ("return ");}Expression SCOLON {printf (";\\n");}
			;

AssignStat 	:	Variable
				ASSIGN {printf (" = ");}
				Expression SCOLON {printf(";\n");}
			;

ExprList 	: 	Expression
			| 	ExprList COMMA {printf(", ");} Expression
			;

Expression 	: 	InitExpr AuxExpr2
			;

InitExpr	:   
			|	Expression OR {printf(" || ");}
			| 	Expression AND {printf(" && ");}
			;

AuxExpr2 	: 	AuxExpr3
			| 	NOT {printf("~");} AuxExpr3
			;

AuxExpr3 	: 	AuxExpr4
			| 	AuxExpr4 RELOP {
            		if ($2 == LT) printf (" < ");
            		else if ($2 == LE) printf (" <= ");
            		else if ($2 == GT) printf (" > ");
            		else if ($2 == GE) printf (" >= ");
            		else if ($2 == EQ) printf (" == ");
            		else printf (" != ");
            	}
            	AuxExpr4
			;

AuxExpr4 	: 	Term
			| 	AuxExpr4 ADOP {
            		if ($2 == ADD) printf (" + ");
					else printf (" - ");
            	} 
            	Term
			;

Term 		: 	Factor
			| 	Term MULTOP {
            		if ($2 == MULT) printf (" * ");
            		else if ($2 == DIV) printf (" / ");
					else printf (" %% ");
            	}
            	Factor
			;

Factor 		: 	Variable
			| 	INTCT			{printf ("%d", $1);}
			| 	FLOATCT			{printf ("%g", $1);}
			|	CHARCT			{printf ("%s", $1);}
			| 	TRUE			{printf ("true");}
			| 	FALSE			{printf ("false");}
			| 	NEG 			{printf ("~");} Factor 		
			| 	OPPAR {printf ("(");} Expression CLPAR {printf (") ");}
			| 	FuncCall
			;

Variable 	: 	ID {printf ("%s",$1);} SubscrList
			;

SubscrList 	: 	
			| 	SubscrList Subscript
			;

Subscript 	: 	OPBRAK {printf ("[");} AuxExpr4 CLBRAK {printf ("]");}
			;

FuncCall 	: 	ID {printf ("%s",$1);}  FuncCallAux
			;

FuncCallAux	: 	OPPAR {printf ("(");} CLPAR {printf (")");}
			|	OPPAR {printf ("(");} ExprList CLPAR {printf (")");}
			;

%%
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

