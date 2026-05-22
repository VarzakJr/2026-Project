%{  
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "cgen.h"
  #include "myanalyzer.tab.h"
  
  int line_num = 1;
%}

  /* NEW CODE FOR HANDLING @def (until line 42)*/

  typedef struct {
    char *name;
    char *value;
  } DefEntry;

  #define MAX_DEFS 1024

  static DefEntry defs[MAX_DEFS];
  static int def_count = 0;

  static void add_def(const char *name, const char *value) {
    if (def_count >= MAX_DEFS) return;
    defs[def_count].name  = strdup(name);
    defs[def_count].value = strdup(value);
    def_count++;
  }

  /* look up most recent definition */
  static const char *find_def(const char *name) {
    for (int i = def_count - 1; i >= 0; --i) {
      if (strcmp(defs[i].name, name) == 0)
        return defs[i].value;
    }
    return NULL;
  }

  /* single-level macro expansion buffer */
  static YY_BUFFER_STATE macro_buf = NULL;
  static YY_BUFFER_STATE file_buf  = NULL;
  static int in_macro = 0;


ID      [a-zA-Z_][0-9a-zA-Z_]*
DIGIT   [0-9]
NUMBER  [+-]?{DIGIT}{DIGIT}*
DECIMAL ([+-]?"."{NUMBER})|([+-]?{NUMBER}("."{NUMBER}?)?)
REAL    {DECIMAL}([eE][+-]?{NUMBER})?
STRING  \"([^\"\n\\]|\\.)*\"


%%

"@def"[ \t]+{ID}[ \t]+[^\n]* {
    /* yytext = "@def <name> <replacement...>" */
    char *text = strdup(yytext);
    char *p = text;

    /* skip "@def" */
    p += 4;
    while (*p == ' ' || *p == '\t') p++;

    /* parse identifier */
    char *name_start = p;
    while (isalnum((unsigned char)*p) || *p == '_') p++;
    char saved = *p;
    *p = '\0';
    char *name = strdup(name_start);
    *p = saved;

    /* skip spaces before replacement */
    while (*p == ' ' || *p == '\t') p++;

    char *value = strdup(p);

    add_def(name, value);

    free(name);
    free(value);
    free(text);

    /* do NOT return a token */
}

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



{ID} {
    const char *rep = find_def(yytext);
    if (rep && !in_macro) {
        /* First time expanding this macro: switch to buffer with replacement */
        file_buf = YY_CURRENT_BUFFER;
        if (macro_buf) yy_delete_buffer(macro_buf);
        macro_buf = yy_scan_string(rep);
        yy_switch_to_buffer(macro_buf);
        in_macro = 1;
        return yylex();   /* get token(s) from replacement */
    } else {
        yylval.str = strdup(yytext);
        return TK_IDENT;
    }
}
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

"--"[^\n]*  /* eat line comments */

[ \r\t]+		/* eat whitespace */
\n 					 ++line_num;



<<EOF>> {
    if (in_macro && YY_CURRENT_BUFFER == macro_buf) {
        /* finished macro replacement: go back to the original file */
        yy_delete_buffer(macro_buf);
        macro_buf = NULL;
        yy_switch_to_buffer(file_buf);
        in_macro = 0;
        return yylex();   /* continue lexing original input */
    } else {
        return 0;         /* real EOF for the parser */
    }
}
.           { printf("Line %d Lexical Error: Unrecognized literal %s\n", line_num, yytext); }
%%