delim		[ \t\n\r]
ws			{delim}+
digito		[0-9]
letra		[A-Za-z]
intct		{digito}+
id			{letra}({letra}|{digito})*
floatct		{digito}+\.{digito}*([Ee][+-]?{digito}+)?
carac1		\\.|[^\\']
carac2		\\.|[^\\\"]
charct		'{carac1}'
string		\"{carac2}*\"

%%

{ws}		{ ;}
"/*"		{comentario ();}

call 		{return CALL;}
char		{return CHAR;}
else		{return ELSE;}
false		{return FALSE;}
float		{return FLOAT;}
for			{return FOR;}
function	{return FUNCTION;}
if			{return IF;}
int			{return INT;}
logic		{return LOGIC;}
procedure	{return PROCEDURE;}
program		{return PROGRAM;}
read		{return READ;}
repeat		{return REPEAT;}
return		{return RETURN;}
true		{return TRUE;}
var			{return VAR;}
while		{return WHILE;}
write		{return WRITE;}

{id}		{strcpy (yylval.string, yytext); 	return ID;}
{intct}		{yylval.valint = atoi(yytext); 		return INTCT;}
{charct}	{strcpy (yylval.string, yytext); 	return CHARCT;}
{string}	{strcpy (yylval.string, yytext); 	return STRING;}
{floatct}	{yylval.valfloat = atof(yytext); 	return FLOATCT;}

"||" 		{return OR;}
"&&" 		{return AND;}
"!"			{return NOT;}
"<"			{yylval.atr = LT; 					return RELOP;}
"<="		{yylval.atr = LE; 					return RELOP;}
">"			{yylval.atr = GT; 					return RELOP;}
">="		{yylval.atr = GE; 					return RELOP;}
"=="		{yylval.atr = EQ; 					return RELOP;}
"!="		{yylval.atr = NE; 					return RELOP;}
"+"			{yylval.atr = ADD; 					return ADOP;}
"-"			{yylval.atr = SUB; 					return ADOP;}
"*"			{yylval.atr = MULT; 				return MULTOP;}
"/"			{yylval.atr = DIV; 					return MULTOP;}
"%"			{yylval.atr = MOD; 					return MULTOP;}
"~"			{return NEG;}

"("			{return OPPAR;}
")"			{return CLPAR;}
"["			{return OPBRAK;}
"]"			{return CLBRAK;}
"{"			{return OPBRACE;}
"}"			{return CLBRACE;}
";"			{return SCOLON;}
","			{return COMMA;}
"="			{return ASSIGN;}

"$"			{return DOLAR;}
.			{yylval.carac = yytext[0]; return INVAL;}

%%

