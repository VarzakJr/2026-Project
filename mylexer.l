%{  
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "cgen.h"
  #include "myanalyzer.tab.h"
  
  int lineNum = 1;
%}


ID      [a-zA-Z_][0-9a-zA-Z_]*
DIGIT   [0-9]
NUMBER  [+-]?{DIGIT}{DIGIT}*
DECIMAL ([+-]?"."{NUMBER})|([+-]?{NUMBER}("."{NUMBER}?)?)
REAL    {DECIMAL}([eE][+-]?{NUMBER})?
STRING	\"[^'\n]*\"

%%

int		    return KW_INT;
real 		return KW_REAL;
text		return KW_TEXT;
bool		return KW_BOOL;
True		return KW_TRUE;
False		return KW_FALSE;
const		return KW_CONST;
if          return KW_IF;
else	    return KW_ELSE;
fi	        return KW_FI;	
for 		return KW_FOR;
in			return KW_IN;
rof		    return KW_ROF;
while		return KW_WHILE;
od	        return KW_OD;
break		return KW_BREAK;
continue	return KW_CONTINUE;
not			return KW_NOT;
and 		return KW_AND;
or 			return KW_OR;
fun			return KW_FUN;
nuf		    return KW_NUF;
main		return KW_MAIN;
return		return KW_RETURN;
record		return KW_RECORD;
drocer		return KW_DROCER;
of			return KW_OF;


{ID}        	{ yylval.str = strdup(yytext); /*printf("Identifier : ");*/ return TK_IDENT; }
{NUMBER}    	{ yylval.str = strdup(yytext); return TK_NUMBER; }
{REAL}      	{ yylval.str = strdup(yytext); return TK_REAL; }
{STRING}		{ yylval.str = strdup(yytext); return TK_STRING; }

"+="		/*printf("Increment operator : ");*/ return KW_INCR;
"-="		/*printf("Decrement operator : ");*/ return KW_DECR;
"*="		/*printf("Times Increment operator :");*/ return KW_TIMES_INCR;
"/="		/*printf("Divide Decrement operator : ");*/ return KW_DIV_DECR;
"%="		/*printf("Mod Decrement operator ");*/ return KW_MOD_DECR;

";"			/*printf("Semicolon : ");*/ return ';';
"("			/*printf("Left Parenthesis : ");*/ return '(';
")"			/*printf("Right Parenthesis :");*/ return ')';
","			/*printf("Comma :");*/ return ',';
"["			/*printf("Left Bracket : ");*/ return '[';
"]"			/*printf("Right Bracket : ");*/ return ']';
":"			/*printf("Colon :");*/ return ':';
"."			/*printf("Dot : ");*/ return '.';
"#"			/*printf("Hashtag : ");*/ return '#';

"+"         /*printf("Plus operator :");*/ return '+';
"-"         /*printf("Minus operator :");*/ return '-';
"*"         /*printf("Times operator :");*/ return '*';
"/"         /*printf("Divide operator : ");*/ return '/';
"%"			/*printf("Mod operator :");*/ return '%';
"**"		/*printf("Power operator :");*/ return KW_POW;

"=="		/*printf("Equality operator :");*/ return KW_EQ;
"!="		/*printf("Inequality operator :");*/ return KW_NOTEQ;
"<"			/*printf("Less operator :");*/ return '<';
"<="		/*printf("Less Equal operator :");*/ return KW_LESSEQ;
">"			/*printf("Greater operator :");*/ return '>';
">="		/*printf("Greater Equal operator :");*/ return KW_GREATEREQ;
"<-"		/*printf("Colon Equal operator :");*/ return KW_COLONEQ;
"="			/*printf("Assign operator :");*/ return '=';
"->"		/*printf("Function arrow :");*/ return KW_ARROW_FUNCTION;

"--"[^\n]*  printf("//Line %d: line comment: %s\n", lineNum, yytext);/* eat line comments */

[ \r\t]+		/* eat whitespace */
\n 					 ++lineNum;

<<EOF>> 	return EOF;
.           { printf("Line %d Lexical Error: Unrecognized literal %s\n", lineNum, yytext); }
%%