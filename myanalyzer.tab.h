/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MYANALYZER_TAB_H_INCLUDED
# define YY_YY_MYANALYZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_IDENT = 258,                /* TK_IDENT  */
    TK_NUMBER = 259,               /* TK_NUMBER  */
    TK_POS_INTEGER = 260,          /* TK_POS_INTEGER  */
    TK_REAL = 261,                 /* TK_REAL  */
    TK_STRING = 262,               /* TK_STRING  */
    KW_INT = 263,                  /* KW_INT  */
    KW_REAL = 264,                 /* KW_REAL  */
    KW_TEXT = 265,                 /* KW_TEXT  */
    KW_BOOL = 266,                 /* KW_BOOL  */
    KW_TRUE = 267,                 /* KW_TRUE  */
    KW_FALSE = 268,                /* KW_FALSE  */
    KW_CONST = 269,                /* KW_CONST  */
    KW_IF = 270,                   /* KW_IF  */
    KW_ELSE = 271,                 /* KW_ELSE  */
    KW_FI = 272,                   /* KW_FI  */
    KW_FOR = 273,                  /* KW_FOR  */
    KW_IN = 274,                   /* KW_IN  */
    KW_ROF = 275,                  /* KW_ROF  */
    KW_WHILE = 276,                /* KW_WHILE  */
    KW_OD = 277,                   /* KW_OD  */
    KW_BREAK = 278,                /* KW_BREAK  */
    KW_CONTINUE = 279,             /* KW_CONTINUE  */
    KW_NOT = 280,                  /* KW_NOT  */
    KW_AND = 281,                  /* KW_AND  */
    KW_OR = 282,                   /* KW_OR  */
    KW_FUN = 283,                  /* KW_FUN  */
    KW_NUF = 284,                  /* KW_NUF  */
    KW_ARROW_FUNCTION = 285,       /* KW_ARROW_FUNCTION  */
    KW_MAIN = 286,                 /* KW_MAIN  */
    KW_RETURN = 287,               /* KW_RETURN  */
    KW_RECORD = 288,               /* KW_RECORD  */
    KW_DROCER = 289,               /* KW_DROCER  */
    KW_OF = 290,                   /* KW_OF  */
    KW_POW = 291,                  /* KW_POW  */
    KW_EQ = 292,                   /* KW_EQ  */
    KW_NOTEQ = 293,                /* KW_NOTEQ  */
    KW_LESSEQ = 294,               /* KW_LESSEQ  */
    KW_GREATEREQ = 295,            /* KW_GREATEREQ  */
    KW_COLONEQ = 296,              /* KW_COLONEQ  */
    KW_INCR = 297,                 /* KW_INCR  */
    KW_DECR = 298,                 /* KW_DECR  */
    KW_TIMES_INCR = 299,           /* KW_TIMES_INCR  */
    KW_DIV_DECR = 300,             /* KW_DIV_DECR  */
    KW_MOD_DECR = 301              /* KW_MOD_DECR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "myanalyzer.y"

	char* str;

#line 114 "myanalyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MYANALYZER_TAB_H_INCLUDED  */
