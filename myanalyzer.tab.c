/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "myanalyzer.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>	
	#include "cgen.h"
	int step_value;
	extern int yylex(void);
	extern int atoi (const char *ptr);
	extern int line_num;
	char* deff = NULL;
	
	char *replaceSubstring(const char *str, const char *from, const char *to) {
		char *result;
		char *ins;
		char *tmp;
		size_t len_from;
		size_t len_to;
		size_t len_front;
		size_t count;

		if (!str || !from)
		    return NULL;

		len_from = strlen(from);
		if (len_from == 0)
		    return NULL; // replacing empty substring is undefined
		if (!to)
		    to = "";

		len_to = strlen(to);

		ins = (char *)str;
		for (count = 0; (tmp = strstr(ins, from)); ++count) {
		    ins = tmp + len_from;
		}

		tmp = result = (char *)malloc(strlen(str) + (len_to - len_from) * count + 1);

		if (!result)
		    return NULL;

		while (count--) {
		    ins = strstr(str, from);
		    len_front = ins - str;
		    tmp = strncpy(tmp, str, len_front) + len_front;
		    tmp = strcpy(tmp, to) + len_to;
		    str += len_front + len_from;
		}
		strcpy(tmp, str);
	    return result;
	}

#line 124 "myanalyzer.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "myanalyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_IDENT = 3,                   /* TK_IDENT  */
  YYSYMBOL_TK_NUMBER = 4,                  /* TK_NUMBER  */
  YYSYMBOL_TK_POS_INTEGER = 5,             /* TK_POS_INTEGER  */
  YYSYMBOL_TK_REAL = 6,                    /* TK_REAL  */
  YYSYMBOL_TK_STRING = 7,                  /* TK_STRING  */
  YYSYMBOL_KW_INT = 8,                     /* KW_INT  */
  YYSYMBOL_KW_REAL = 9,                    /* KW_REAL  */
  YYSYMBOL_KW_TEXT = 10,                   /* KW_TEXT  */
  YYSYMBOL_KW_BOOL = 11,                   /* KW_BOOL  */
  YYSYMBOL_KW_TRUE = 12,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 13,                  /* KW_FALSE  */
  YYSYMBOL_KW_CONST = 14,                  /* KW_CONST  */
  YYSYMBOL_KW_IF = 15,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 16,                   /* KW_ELSE  */
  YYSYMBOL_KW_FI = 17,                     /* KW_FI  */
  YYSYMBOL_KW_FOR = 18,                    /* KW_FOR  */
  YYSYMBOL_KW_IN = 19,                     /* KW_IN  */
  YYSYMBOL_KW_ROF = 20,                    /* KW_ROF  */
  YYSYMBOL_KW_WHILE = 21,                  /* KW_WHILE  */
  YYSYMBOL_KW_OD = 22,                     /* KW_OD  */
  YYSYMBOL_KW_BREAK = 23,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 24,               /* KW_CONTINUE  */
  YYSYMBOL_KW_NOT = 25,                    /* KW_NOT  */
  YYSYMBOL_KW_AND = 26,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 27,                     /* KW_OR  */
  YYSYMBOL_KW_FUN = 28,                    /* KW_FUN  */
  YYSYMBOL_KW_NUF = 29,                    /* KW_NUF  */
  YYSYMBOL_KW_ARROW_FUNCTION = 30,         /* KW_ARROW_FUNCTION  */
  YYSYMBOL_KW_MAIN = 31,                   /* KW_MAIN  */
  YYSYMBOL_KW_RETURN = 32,                 /* KW_RETURN  */
  YYSYMBOL_KW_RECORD = 33,                 /* KW_RECORD  */
  YYSYMBOL_KW_DROCER = 34,                 /* KW_DROCER  */
  YYSYMBOL_KW_OF = 35,                     /* KW_OF  */
  YYSYMBOL_KW_POW = 36,                    /* KW_POW  */
  YYSYMBOL_KW_EQ = 37,                     /* KW_EQ  */
  YYSYMBOL_KW_NOTEQ = 38,                  /* KW_NOTEQ  */
  YYSYMBOL_KW_LESSEQ = 39,                 /* KW_LESSEQ  */
  YYSYMBOL_KW_GREATEREQ = 40,              /* KW_GREATEREQ  */
  YYSYMBOL_KW_COLONEQ = 41,                /* KW_COLONEQ  */
  YYSYMBOL_KW_INCR = 42,                   /* KW_INCR  */
  YYSYMBOL_KW_DECR = 43,                   /* KW_DECR  */
  YYSYMBOL_KW_TIMES_INCR = 44,             /* KW_TIMES_INCR  */
  YYSYMBOL_KW_DIV_DECR = 45,               /* KW_DIV_DECR  */
  YYSYMBOL_KW_MOD_DECR = 46,               /* KW_MOD_DECR  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '%'  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* ';'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '.'  */
  YYSYMBOL_63_ = 63,                       /* '#'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_function_list = 66,             /* function_list  */
  YYSYMBOL_function = 67,                  /* function  */
  YYSYMBOL_function_argument_list = 68,    /* function_argument_list  */
  YYSYMBOL_single_argument_function = 69,  /* single_argument_function  */
  YYSYMBOL_multiple_argument_function = 70, /* multiple_argument_function  */
  YYSYMBOL_function_body = 71,             /* function_body  */
  YYSYMBOL_data = 72,                      /* data  */
  YYSYMBOL_data_type = 73,                 /* data_type  */
  YYSYMBOL_boolean_value = 74,             /* boolean_value  */
  YYSYMBOL_array_value = 75,               /* array_value  */
  YYSYMBOL_expr_data_type = 76,            /* expr_data_type  */
  YYSYMBOL_expr = 77,                      /* expr  */
  YYSYMBOL_declaration_list = 78,          /* declaration_list  */
  YYSYMBOL_declaration = 79,               /* declaration  */
  YYSYMBOL_variable_declaration = 80,      /* variable_declaration  */
  YYSYMBOL_variable_assign_declaration = 81, /* variable_assign_declaration  */
  YYSYMBOL_single_variable_declaration = 82, /* single_variable_declaration  */
  YYSYMBOL_multiple_variable_declaration = 83, /* multiple_variable_declaration  */
  YYSYMBOL_const_variable_declaration = 84, /* const_variable_declaration  */
  YYSYMBOL_const_variable_assign_declaration = 85, /* const_variable_assign_declaration  */
  YYSYMBOL_single_const_variable_declaration = 86, /* single_const_variable_declaration  */
  YYSYMBOL_multiple_const_variable_declaration = 87, /* multiple_const_variable_declaration  */
  YYSYMBOL_statement_list = 88,            /* statement_list  */
  YYSYMBOL_statement = 89,                 /* statement  */
  YYSYMBOL_assign_statement = 90,          /* assign_statement  */
  YYSYMBOL_assign_operator = 91,           /* assign_operator  */
  YYSYMBOL_break_statement = 92,           /* break_statement  */
  YYSYMBOL_continue_statement = 93,        /* continue_statement  */
  YYSYMBOL_return_statement = 94,          /* return_statement  */
  YYSYMBOL_if_statement = 95,              /* if_statement  */
  YYSYMBOL_if_for_while_body = 96,         /* if_for_while_body  */
  YYSYMBOL_while_statement = 97,           /* while_statement  */
  YYSYMBOL_for_statement = 98,             /* for_statement  */
  YYSYMBOL_function_statement = 99,        /* function_statement  */
  YYSYMBOL_expr_function = 100,            /* expr_function  */
  YYSYMBOL_function_parameter_list = 101,  /* function_parameter_list  */
  YYSYMBOL_comp_list = 102,                /* comp_list  */
  YYSYMBOL_comp = 103,                     /* comp  */
  YYSYMBOL_comp_body = 104,                /* comp_body  */
  YYSYMBOL_comp_variable_declaration_list = 105, /* comp_variable_declaration_list  */
  YYSYMBOL_comp_variable_declaration = 106, /* comp_variable_declaration  */
  YYSYMBOL_comp_variable_assign_declaration = 107, /* comp_variable_assign_declaration  */
  YYSYMBOL_single_comp_variable_declaration = 108, /* single_comp_variable_declaration  */
  YYSYMBOL_multiple_comp_variable_declaration = 109, /* multiple_comp_variable_declaration  */
  YYSYMBOL_comp_func_list = 110,           /* comp_func_list  */
  YYSYMBOL_comp_func = 111,                /* comp_func  */
  YYSYMBOL_comp_variable = 112,            /* comp_variable  */
  YYSYMBOL_comp_value = 113,               /* comp_value  */
  YYSYMBOL_comp_values = 114               /* comp_values  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    63,     2,    53,     2,     2,
      55,    56,    51,    50,    61,    49,    62,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    58,
      47,    54,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   152,   167,   181,   195,   208,   221,   234,
     250,   271,   272,   276,   278,   280,   287,   288,   292,   293,
     294,   298,   299,   303,   304,   305,   311,   312,   316,   317,
     318,   319,   320,   324,   325,   329,   330,   331,   332,   336,
     337,   338,   339,   340,   341,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   369,   370,   374,   375,
     381,   385,   386,   390,   391,   392,   393,   397,   398,   399,
     400,   401,   402,   403,   404,   410,   414,   415,   419,   423,
     424,   430,   431,   435,   436,   437,   438,   439,   440,   441,
     442,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     456,   460,   472,   473,   474,   475,   476,   480,   484,   488,
     489,   493,   495,   500,   501,   502,   506,   511,   513,   527,
     528,   529,   530,   534,   535,   539,   540,   541,   542,   543,
     544,   550,   551,   555,   561,   562,   563,   567,   568,   572,
     576,   577,   581,   582,   586,   587,   588,   592,   593,   597,
     623,   649,   653,   657,   658
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_IDENT",
  "TK_NUMBER", "TK_POS_INTEGER", "TK_REAL", "TK_STRING", "KW_INT",
  "KW_REAL", "KW_TEXT", "KW_BOOL", "KW_TRUE", "KW_FALSE", "KW_CONST",
  "KW_IF", "KW_ELSE", "KW_FI", "KW_FOR", "KW_IN", "KW_ROF", "KW_WHILE",
  "KW_OD", "KW_BREAK", "KW_CONTINUE", "KW_NOT", "KW_AND", "KW_OR",
  "KW_FUN", "KW_NUF", "KW_ARROW_FUNCTION", "KW_MAIN", "KW_RETURN",
  "KW_RECORD", "KW_DROCER", "KW_OF", "KW_POW", "KW_EQ", "KW_NOTEQ",
  "KW_LESSEQ", "KW_GREATEREQ", "KW_COLONEQ", "KW_INCR", "KW_DECR",
  "KW_TIMES_INCR", "KW_DIV_DECR", "KW_MOD_DECR", "'<'", "'>'", "'-'",
  "'+'", "'*'", "'/'", "'%'", "'='", "'('", "')'", "':'", "';'", "'['",
  "']'", "','", "'.'", "'#'", "$accept", "program", "function_list",
  "function", "function_argument_list", "single_argument_function",
  "multiple_argument_function", "function_body", "data", "data_type",
  "boolean_value", "array_value", "expr_data_type", "expr",
  "declaration_list", "declaration", "variable_declaration",
  "variable_assign_declaration", "single_variable_declaration",
  "multiple_variable_declaration", "const_variable_declaration",
  "const_variable_assign_declaration", "single_const_variable_declaration",
  "multiple_const_variable_declaration", "statement_list", "statement",
  "assign_statement", "assign_operator", "break_statement",
  "continue_statement", "return_statement", "if_statement",
  "if_for_while_body", "while_statement", "for_statement",
  "function_statement", "expr_function", "function_parameter_list",
  "comp_list", "comp", "comp_body", "comp_variable_declaration_list",
  "comp_variable_declaration", "comp_variable_assign_declaration",
  "single_comp_variable_declaration", "multiple_comp_variable_declaration",
  "comp_func_list", "comp_func", "comp_variable", "comp_value",
  "comp_values", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-278)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     366,  1214,    11,   -24,    30,    -9,   -13,    46,    18,   379,
      49,   104,    76,    37,  -278,   -27,   514,  -278,  -278,    71,
     141,  -278,   717,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,    78,  -278,   204,    69,  -278,  -278,  -278,  -278,
    -278,    50,   220,   402,     6,   549,    90,    77,   168,   549,
     142,   549,  -278,  -278,   111,   112,    84,  -278,  -278,  -278,
    -278,  -278,  -278,   549,   549,  -278,  -278,   129,  -278,   809,
    -278,   160,   158,  -278,   173,  -278,  -278,  -278,    34,   549,
     228,   212,  -278,   698,  -278,   279,     9,   181,  1220,   -26,
    -278,    66,   212,   198,    95,  -278,   160,   427,   443,   228,
     549,   549,  -278,   549,  -278,   837,    98,  -278,   549,  1201,
      89,  -278,   755,    -4,   201,   206,   865,   468,  -278,   279,
     259,   194,  1117,   209,  1145,   268,   216,   220,   228,  -278,
    1173,   210,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,  -278,   210,    40,     1,
     893,   219,    37,  -278,  -278,  -278,  -278,  -278,  -278,   105,
     224,   279,    16,   496,   549,   468,   549,   212,   549,   921,
    -278,   773,   222,   949,   707,   977,  -278,     6,  1201,   223,
     549,  -278,  -278,   501,  -278,  -278,  1201,  -278,   231,   279,
     271,   238,   549,   240,   125,   107,  -278,   241,   122,  -278,
    -278,  -278,  1247,  1247,   274,   360,   360,   360,   360,   360,
     360,    81,    81,   274,   274,   274,  -278,   258,   315,  -278,
     285,    40,  -278,   265,   200,   296,  -278,   160,  -278,  -278,
     292,   549,   549,  -278,   126,   272,   837,   893,  1201,  1005,
    -278,  -278,  -278,  -278,   326,  -278,  -278,  -278,  1201,   549,
    1033,   468,  -278,   276,  -278,  1089,  -278,   279,   273,   -19,
     329,  -278,  -278,  -278,   283,   281,  -278,   296,  -278,   279,
      39,   282,   290,  -278,  1201,  1201,   468,   549,  -278,   297,
    1061,  -278,  -278,   468,   172,   549,   313,  -278,   299,   279,
    -278,   144,   564,   268,  -278,  -278,    47,  -278,    58,   279,
    -278,  1201,   298,  -278,  -278,   304,   284,  -278,  -278,   726,
     291,   279,   305,   577,   279,   295,   308,  -278,  -278,   136,
     258,  -278,   364,  -278,   303,   352,  -278,  -278,   549,   316,
    -278,  -278,  -278,   321,  -278,   317,  -278,    70,  -278,   331,
     383,   596,   791,  -278,   615,  -278,   279,   279,  -278,   279,
     358,   337,   340,   628,   342,  -278,   350,   647,   359,   412,
    -278,  -278,   361,  -278,  -278,   362,  -278,   363,   666,  -278,
     679,  -278,   365,   370,   374,   279,  -278,  -278,   377,  -278
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    12,    75,     7,    67,    68,     0,
       0,    69,     4,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     8,   142,     0,     0,   112,   113,   114,   115,
     116,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   118,     0,     0,    39,    40,    41,    33,
      34,    62,    63,     0,     0,   119,    43,    42,    45,     0,
      64,    44,   164,    65,     0,   161,     1,    11,     0,     0,
       0,     5,    66,     0,    70,     0,     0,     0,     0,     0,
      91,    74,     3,    75,     0,   141,     0,     0,     0,     0,
       0,     0,    27,     0,    73,    26,    39,   139,     0,   136,
       0,    36,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,    20,     0,   140,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,     0,    10,
      76,     0,     0,    32,    28,    29,    30,    31,    72,    82,
      84,     0,     0,     0,     0,     0,     0,     9,     0,     0,
      37,     0,     0,     0,     0,     0,   101,     0,   137,     0,
       0,    35,   130,     0,   108,    88,    26,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,   134,
      46,   162,    59,    60,    52,    53,    54,    56,    58,    55,
      57,    48,    47,    49,    50,    51,   163,     0,     0,   153,
       0,   145,   148,     0,     0,   146,   158,   152,   105,   132,
       2,     0,     0,    71,    78,    80,     0,     0,    76,     0,
     106,    38,   131,   109,     0,   102,   138,   129,   135,     0,
       0,     0,    86,     0,   125,     0,   125,     0,     0,     0,
       0,    16,    25,   133,     0,     0,   147,   144,   149,     0,
       0,     0,     0,   157,    81,    83,     0,     0,   107,     0,
       0,   103,    90,     0,     0,     0,     0,    18,     0,     0,
      25,     0,     0,    20,   143,   151,     0,   155,     0,     0,
      77,    79,     0,   104,    89,     0,     0,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,     0,
     161,   156,     0,   150,     0,     0,   125,   121,     0,     0,
     126,    19,    25,     0,    21,     0,    13,     0,   154,     0,
       0,     0,     0,   125,     0,    15,     0,     0,    25,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
     122,   125,     0,    14,    25,     0,   110,     0,     0,   127,
       0,   160,     0,     0,     0,     0,   128,   159,     0,   111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,    -6,    27,   128,  -278,  -278,  -277,  -111,   -35,
    -278,     7,  -278,    73,   -12,     2,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,   214,   408,     8,  -278,   384,  -278,  -278,
    -278,  -278,  -231,  -278,  -278,  -278,   -39,   309,   -10,   -31,
    -278,  -278,   227,  -278,  -278,  -278,   232,  -208,     0,  -278,
    -278
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    12,    13,    14,   195,   196,   261,   292,   104,   158,
      66,    67,    68,   186,    16,   307,    18,    19,    20,    87,
      21,    47,    48,   121,    22,   308,    24,    45,    25,    26,
      27,    28,   284,    29,    30,    31,    70,   110,    32,    33,
     220,   221,   222,   223,   224,   272,   225,   226,    71,    72,
      73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    95,    17,    78,    91,   114,   185,    15,    23,   113,
      81,   289,   159,   313,    46,     2,    34,   273,    82,   234,
      94,    54,    34,    15,    23,   286,    92,    79,   164,    89,
      90,    49,    96,    50,    17,    80,    80,    91,   290,    93,
      77,   151,   188,   217,   115,    52,    51,    95,     2,    55,
     320,   127,    74,    56,    57,   344,    58,   102,   128,   273,
     172,   253,    59,    60,    11,     8,   149,    10,   218,    11,
      10,   357,    11,    61,    62,    63,    76,   152,    96,    11,
      17,    91,    69,    34,   187,    93,    96,   370,   167,   199,
      89,    90,     2,   160,    96,   341,    82,    11,    91,   103,
     347,    93,   296,    11,    53,    64,     8,    75,    77,     2,
      11,    10,   353,    11,   105,   109,   112,   134,   116,    77,
     165,   322,   122,     8,   124,    43,   233,   348,   101,    84,
     368,   201,   143,   144,   145,   118,   129,   130,   199,   127,
     282,    11,   230,    43,   117,   179,   128,   216,   227,    96,
     180,    82,   150,   127,   252,   219,    93,    43,    11,   231,
     177,   123,    96,   259,    43,   300,   125,   126,   260,   235,
     169,   171,   304,   173,   174,     1,   175,   246,   263,    77,
     276,   178,   257,   180,   258,    43,     2,     3,   305,   306,
       4,   131,   337,     5,    77,     6,     7,   260,    85,    95,
     109,   314,    86,   315,     9,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    98,
     147,   227,   287,   106,    57,   119,    58,   107,   219,   120,
     148,   113,    59,    60,   295,    11,   236,   237,   161,   238,
       8,   239,   162,    61,    62,    63,    36,    37,    38,    39,
      40,   189,   166,   248,   312,   190,   250,   269,    97,   182,
     183,   270,   188,    98,   323,   255,    99,   325,   192,   108,
     297,   194,   197,    11,   253,    64,   331,   229,   232,   334,
     242,   247,   153,    11,    34,   251,    34,   154,   155,   156,
     157,    15,    34,    15,   317,   254,    96,   256,   262,    15,
     318,   153,   324,   321,   274,   275,   154,   155,   156,   157,
     134,   355,   356,    34,   358,   317,     1,    43,   264,   265,
      15,   318,   280,   268,   218,    10,   277,     2,     3,   279,
     283,     4,   291,   288,     5,   310,     6,     7,   293,   294,
     378,    34,   327,   298,    34,     9,   317,   299,    15,   330,
     301,    15,   318,    34,   302,   335,   311,    34,   309,   317,
      15,   326,   332,   339,    15,   318,   336,   338,    34,     1,
      34,   340,   317,   343,   346,    15,    11,    15,   318,   345,
       2,     3,    56,    57,     4,    58,   350,     5,   349,     6,
       7,    59,    60,   359,     8,   360,   134,   361,     9,    10,
     363,   342,    61,    62,    63,    56,    57,   364,    58,   141,
     142,   143,   144,   145,    59,    60,   367,   366,   100,   369,
     371,   319,   375,   372,    83,    61,    62,    63,   376,    11,
      56,    57,   377,    58,    64,   379,   198,    65,   271,    59,
      60,     0,    11,     0,     0,     0,    56,    57,   266,    58,
      61,    62,    63,   267,     0,    59,    60,    64,     0,     0,
       0,     0,   111,     0,     0,    11,    61,    62,    63,     0,
       0,    56,    57,     0,    58,   102,   168,     0,     0,     0,
      59,    60,    64,     0,     0,     0,     0,     0,     0,     0,
      11,    61,    62,    63,     0,     0,     0,     0,    64,    56,
      57,     0,    58,   170,    56,    57,    11,    58,    59,    60,
       0,     0,     0,    59,    60,     0,     0,     1,     0,    61,
      62,    63,     0,    64,    61,    62,    63,     0,     2,     3,
       0,    11,     4,     0,     0,     5,     0,     6,     7,     0,
       0,     0,     8,     0,     0,   103,     9,     0,     0,     0,
     249,    64,    56,    57,     0,    58,    64,     0,     0,    11,
       0,    59,    60,     0,    11,     0,     0,     1,     0,     0,
       0,     0,    61,    62,    63,     0,     0,    11,     2,     3,
       1,     0,     4,     0,     0,     5,     0,     6,     7,     0,
       0,     2,     3,   316,     0,     4,     9,     0,     5,     1,
       6,     7,     0,     0,    64,     0,   333,     0,     0,     9,
       2,     3,    11,   351,     4,     0,     0,     5,     1,     6,
       7,     0,     0,     0,     0,     0,     0,    11,     9,     2,
       3,     1,     0,     4,     0,     0,     5,     0,     6,     7,
      11,     0,     2,     3,   354,     0,     4,     9,   362,     5,
       1,     6,     7,     0,     0,     0,     0,     0,     0,    11,
       9,     2,     3,     0,     0,     4,     0,     0,     5,     1,
       6,     7,     0,     0,     0,     0,   365,     0,    11,     9,
       2,     3,     1,     0,     4,     0,   373,     5,     0,     6,
       7,    11,     0,     2,     3,     0,     0,     4,     9,     0,
       5,    88,     6,     7,     0,     0,     0,     0,   374,     0,
      11,     9,     0,     3,     0,     0,     4,     0,     0,     5,
      88,     6,     7,     0,     0,   244,     8,     0,     0,    11,
       9,     0,     3,   132,   133,     4,     0,     0,     5,     0,
       6,     7,    11,   134,   135,   136,   137,   138,     0,     9,
       0,     0,   132,   133,   139,   140,   141,   142,   143,   144,
     145,    11,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   145,
      11,   132,   133,   328,     0,     0,   329,     0,     0,     0,
       0,   134,   135,   136,   137,   138,     0,     0,     0,   132,
     133,     0,   139,   140,   141,   142,   143,   144,   145,   134,
     135,   136,   137,   138,     0,   181,     0,   132,   133,     0,
     139,   140,   141,   142,   143,   144,   145,   134,   135,   136,
     137,   138,     0,   241,     0,   132,   133,     0,   139,   140,
     141,   142,   143,   144,   145,   134,   135,   136,   137,   138,
       0,   352,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   132,   133,     0,     0,   146,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   132,   133,     0,     0,   176,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   132,
     133,     0,     0,   184,     0,     0,     0,     0,     0,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   132,   133,     0,
       0,   228,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   132,   133,     0,     0,   240,
       0,     0,     0,     0,     0,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   132,   133,     0,     0,   243,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   132,   133,     0,     0,   245,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   132,
     133,     0,     0,   278,     0,     0,     0,     0,     0,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   132,   133,     0,
       0,   281,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   132,   133,     0,     0,   303,
       0,     0,     0,     0,     0,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   132,   133,     0,   285,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   132,   133,   191,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   132,
     133,   193,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   132,   133,   200,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,    35,    36,    37,    38,    39,
      40,    35,    36,    37,    38,    39,    40,     0,    41,    42,
       0,     0,     0,    43,   163,    42,    44,     0,     0,    43,
       0,     0,    44,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145
};

static const yytype_int16 yycheck[] =
{
       0,    32,     0,    13,     3,    44,   117,     0,     0,     3,
      16,    30,     3,   290,     3,    14,    16,   225,    16,     3,
      32,     3,    22,    16,    16,   256,    32,    54,    54,    22,
      22,    55,    32,     3,    32,    62,    62,     3,    57,    32,
      13,    80,     3,     3,    44,    58,    55,    78,    14,    31,
       3,    55,     3,     3,     4,   332,     6,     7,    62,   267,
      99,     3,    12,    13,    63,    28,    78,    33,    28,    63,
      33,   348,    63,    23,    24,    25,     0,    83,    78,    63,
      78,     3,     9,    83,   119,    78,    86,   364,    94,   128,
      83,    83,    14,    86,    94,   326,    94,    63,     3,    49,
      30,    94,    63,    63,    58,    55,    28,     3,    81,    14,
      63,    33,   343,    63,    41,    42,    43,    36,    45,    92,
      54,    63,    49,    28,    51,    59,   161,    57,    59,    58,
     361,   131,    51,    52,    53,    58,    63,    64,   177,    55,
     251,    63,   152,    59,    54,    56,    62,   147,   148,   149,
      61,   149,    79,    55,   189,   148,   149,    59,    63,    54,
      62,    19,   162,    56,    59,   276,    55,    55,    61,   162,
      97,    98,   283,   100,   101,     3,   103,   177,    56,   152,
      54,   108,    57,    61,    59,    59,    14,    15,    16,    17,
      18,    62,    56,    21,   167,    23,    24,    61,    57,   230,
     127,    57,    61,    59,    32,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    59,
      62,   221,   257,     3,     4,    57,     6,     7,   221,    61,
      57,     3,    12,    13,   269,    63,   163,   164,    57,   166,
      28,   168,    61,    23,    24,    25,    42,    43,    44,    45,
      46,    57,    54,   180,   289,    61,   183,    57,    54,    58,
      54,    61,     3,    59,   299,   192,    62,   302,    59,    49,
     270,     3,    56,    63,     3,    55,   311,    58,    54,   314,
      58,    58,     3,    63,   284,    54,   286,     8,     9,    10,
      11,   284,   292,   286,   292,    57,   296,    57,    57,   292,
     292,     3,     4,   296,   231,   232,     8,     9,    10,    11,
      36,   346,   347,   313,   349,   313,     3,    59,     3,    34,
     313,   313,   249,    58,    28,    33,    54,    14,    15,     3,
      54,    18,     3,    60,    21,    22,    23,    24,    55,    58,
     375,   341,    58,    61,   344,    32,   344,    57,   341,    58,
     277,   344,   344,   353,    57,    60,    57,   357,   285,   357,
     353,    57,    57,    60,   357,   357,    58,     3,   368,     3,
     370,    19,   370,    57,    57,   368,    63,   370,   370,    58,
      14,    15,     3,     4,    18,     6,     3,    21,    57,    23,
      24,    12,    13,    35,    28,    58,    36,    57,    32,    33,
      58,   328,    23,    24,    25,     3,     4,    57,     6,    49,
      50,    51,    52,    53,    12,    13,     4,    58,    34,    58,
      58,   293,    57,    60,    16,    23,    24,    25,    58,    63,
       3,     4,    58,     6,    55,    58,   127,    58,   224,    12,
      13,    -1,    63,    -1,    -1,    -1,     3,     4,   221,     6,
      23,    24,    25,   221,    -1,    12,    13,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    63,    23,    24,    25,    -1,
      -1,     3,     4,    -1,     6,     7,    49,    -1,    -1,    -1,
      12,    13,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    23,    24,    25,    -1,    -1,    -1,    -1,    55,     3,
       4,    -1,     6,    60,     3,     4,    63,     6,    12,    13,
      -1,    -1,    -1,    12,    13,    -1,    -1,     3,    -1,    23,
      24,    25,    -1,    55,    23,    24,    25,    -1,    14,    15,
      -1,    63,    18,    -1,    -1,    21,    -1,    23,    24,    -1,
      -1,    -1,    28,    -1,    -1,    49,    32,    -1,    -1,    -1,
      49,    55,     3,     4,    -1,     6,    55,    -1,    -1,    63,
      -1,    12,    13,    -1,    63,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    63,    14,    15,
       3,    -1,    18,    -1,    -1,    21,    -1,    23,    24,    -1,
      -1,    14,    15,    29,    -1,    18,    32,    -1,    21,     3,
      23,    24,    -1,    -1,    55,    -1,    29,    -1,    -1,    32,
      14,    15,    63,    17,    18,    -1,    -1,    21,     3,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    63,    32,    14,
      15,     3,    -1,    18,    -1,    -1,    21,    -1,    23,    24,
      63,    -1,    14,    15,    29,    -1,    18,    32,    20,    21,
       3,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      32,    14,    15,    -1,    -1,    18,    -1,    -1,    21,     3,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    63,    32,
      14,    15,     3,    -1,    18,    -1,    20,    21,    -1,    23,
      24,    63,    -1,    14,    15,    -1,    -1,    18,    32,    -1,
      21,     3,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,
      63,    32,    -1,    15,    -1,    -1,    18,    -1,    -1,    21,
       3,    23,    24,    -1,    -1,    18,    28,    -1,    -1,    63,
      32,    -1,    15,    26,    27,    18,    -1,    -1,    21,    -1,
      23,    24,    63,    36,    37,    38,    39,    40,    -1,    32,
      -1,    -1,    26,    27,    47,    48,    49,    50,    51,    52,
      53,    63,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      63,    26,    27,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    26,
      27,    -1,    47,    48,    49,    50,    51,    52,    53,    36,
      37,    38,    39,    40,    -1,    60,    -1,    26,    27,    -1,
      47,    48,    49,    50,    51,    52,    53,    36,    37,    38,
      39,    40,    -1,    60,    -1,    26,    27,    -1,    47,    48,
      49,    50,    51,    52,    53,    36,    37,    38,    39,    40,
      -1,    60,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    26,    27,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    26,    27,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    26,
      27,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    26,    27,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    26,    27,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    26,    27,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    26,    27,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    26,
      27,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    26,    27,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    26,    27,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    26,    27,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    26,    27,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    26,
      27,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    26,    27,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    41,    42,    43,    44,    45,
      46,    41,    42,    43,    44,    45,    46,    -1,    54,    55,
      -1,    -1,    -1,    59,    54,    55,    62,    -1,    -1,    59,
      -1,    -1,    62,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    14,    15,    18,    21,    23,    24,    28,    32,
      33,    63,    65,    66,    67,    75,    78,    79,    80,    81,
      82,    84,    88,    89,    90,    92,    93,    94,    95,    97,
      98,    99,   102,   103,   112,    41,    42,    43,    44,    45,
      46,    54,    55,    59,    62,    91,     3,    85,    86,    55,
       3,    55,    58,    58,     3,    31,     3,     4,     6,    12,
      13,    23,    24,    25,    55,    58,    74,    75,    76,    77,
     100,   112,   113,   114,     3,     3,     0,    67,   102,    54,
      62,    66,    79,    88,    58,    57,    61,    83,     3,    75,
      89,     3,    66,    75,    78,   103,   112,    54,    59,    62,
      91,    59,     7,    49,    72,    77,     3,     7,    49,    77,
     101,    60,    77,     3,   100,   112,    77,    54,    58,    57,
      61,    87,    77,    19,    77,    55,    55,    55,    62,    77,
      77,    62,    26,    27,    36,    37,    38,    39,    40,    47,
      48,    49,    50,    51,    52,    53,    58,    62,    57,    78,
      77,   100,    66,     3,     8,     9,    10,    11,    73,     3,
      75,    57,    61,    54,    54,    54,    54,    66,    49,    77,
      60,    77,   100,    77,    77,    77,    58,    62,    77,    56,
      61,    60,    58,    54,    58,    72,    77,    73,     3,    57,
      61,    56,    59,    56,     3,    68,    69,    56,   101,   100,
      56,   112,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,   112,     3,    28,    75,
     104,   105,   106,   107,   108,   110,   111,   112,    58,    58,
     102,    54,    54,    73,     3,    75,    77,    77,    77,    77,
      58,    60,    58,    58,    18,    58,   112,    58,    77,    49,
      77,    54,    73,     3,    57,    77,    57,    57,    59,    56,
      61,    70,    57,    56,     3,    34,   106,   110,    58,    57,
      61,    87,   109,   111,    77,    77,    54,    54,    58,     3,
      77,    58,    72,    54,    96,    57,    96,    73,    60,    30,
      57,     3,    71,    55,    58,    73,    63,   112,    61,    57,
      72,    77,    57,    58,    72,    16,    17,    79,    89,    77,
      22,    57,    73,    71,    57,    59,    29,    79,    89,    68,
       3,    75,    63,    73,     4,    73,    57,    58,    57,    60,
      58,    73,    57,    29,    73,    60,    58,    56,     3,    60,
      19,    96,    77,    57,    71,    58,    57,    30,    57,    57,
       3,    17,    60,    96,    29,    73,    73,    71,    73,    35,
      58,    57,    20,    58,    57,    29,    58,     4,    96,    58,
      71,    58,    60,    20,    29,    57,    58,    58,    73,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    92,    93,    94,
      94,    95,    95,    96,    96,    96,    97,    98,    98,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   101,   101,
     101,   102,   102,   103,   104,   104,   104,   105,   105,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   111,
     111,   112,   113,   114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     1,     1,     1,     3,
       3,     2,     1,     8,    11,     9,     2,     1,     3,     5,
       0,     4,     6,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     4,     3,     3,     1,     1,     3,     5,     3,     5,
       3,     4,     2,     4,     2,     3,     4,     3,     3,     5,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     6,     7,     4,     4,     5,     4,     4,
      12,    16,     1,     1,     1,     1,     1,     2,     2,     2,
       3,     8,    11,     2,     2,     0,     8,    12,    14,     5,
       4,     4,     4,     4,     3,     3,     1,     2,     3,     1,
       0,     2,     1,     6,     2,     1,     1,     2,     1,     2,
       4,     3,     1,     1,     4,     2,     3,     2,     1,    11,
       9,     2,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list statement_list function_list comp_list  */
#line 135 "myanalyzer.y"
                                                                {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    puts(c_prologue); // puts the kappalib library
    printf("//HERE1\n");
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[-3].str));
    printf("%s\n", (yyvsp[-2].str));
    printf("%s\n", (yyvsp[-1].str));
    printf("%s\n", (yyvsp[0].str));
	printf("\n\n");
  }
  
}
#line 1687 "myanalyzer.tab.c"
    break;

  case 3: /* program: comp_list function_list  */
#line 152 "myanalyzer.y"
                           {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    puts(c_prologue); // puts the kappalib library
    printf("//HERE1test\n");
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[-1].str));
    printf("%s\n", (yyvsp[0].str));
	printf("\n\n");
  }
  
}
#line 1707 "myanalyzer.tab.c"
    break;

  case 4: /* program: statement_list  */
#line 167 "myanalyzer.y"
                 {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    printf("HERE2");
    puts(c_prologue); // puts the kappalib library
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[0].str));
    printf("\n\n");
  }
}
#line 1725 "myanalyzer.tab.c"
    break;

  case 5: /* program: declaration_list function_list  */
#line 181 "myanalyzer.y"
                                {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    printf("//HERE3\n");
    puts(c_prologue); // puts the kappalib library
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[-1].str));
    printf("%s\n", (yyvsp[0].str));
    printf("\n\n");
  }
}
#line 1744 "myanalyzer.tab.c"
    break;

  case 6: /* program: function_list  */
#line 195 "myanalyzer.y"
               {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    printf("//HERE4\n");
    puts(c_prologue); // puts the kappalib library
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[0].str));
    printf("\n\n");
  }
}
#line 1762 "myanalyzer.tab.c"
    break;

  case 7: /* program: declaration_list  */
#line 208 "myanalyzer.y"
                  {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    printf("//HERE5\n");
    puts(c_prologue); // puts the kappalib library
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[0].str));
    printf("\n\n");
  }
}
#line 1780 "myanalyzer.tab.c"
    break;

  case 8: /* program: comp_list  */
#line 221 "myanalyzer.y"
            {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    printf("//HERE6\n");
    puts(c_prologue); // puts the kappalib library
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[0].str));
    printf("\n\n");
  }
}
#line 1798 "myanalyzer.tab.c"
    break;

  case 9: /* program: comp_list declaration_list function_list  */
#line 234 "myanalyzer.y"
                                          {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    puts(c_prologue); // puts the kappalib library
    printf("//HERE7\n");
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[-2].str));
    printf("%s\n", (yyvsp[-1].str));
    printf("%s\n", (yyvsp[0].str));
	printf("\n\n");
  }
}
#line 1818 "myanalyzer.tab.c"
    break;

  case 10: /* program: function_list comp_list declaration_list  */
#line 250 "myanalyzer.y"
                                           {

 	// Successful parse! Check for syntax errors and generate output. 
  
  if (yyerror_count == 0) {
    puts(c_prologue); // puts the kappalib library
    printf("//HERE7\n");
    puts("#include <math.h>\n#include <stdio.h>"); 
    printf("/* program */ \n\n");
    printf("%s\n", (yyvsp[-2].str));
    printf("%s\n", (yyvsp[-1].str));
    printf("%s\n", (yyvsp[0].str));
	printf("\n\n");
  }
}
#line 1838 "myanalyzer.tab.c"
    break;

  case 11: /* function_list: function_list function  */
#line 271 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1844 "myanalyzer.tab.c"
    break;

  case 13: /* function: KW_FUN KW_MAIN '(' ')' ':' function_body KW_NUF ';'  */
#line 277 "myanalyzer.y"
                { (yyval.str) = template("int main () {\n%s\n}", (yyvsp[-2].str)); }
#line 1850 "myanalyzer.tab.c"
    break;

  case 14: /* function: KW_FUN TK_IDENT '(' function_argument_list ')' KW_ARROW_FUNCTION data_type ':' function_body KW_NUF ';'  */
#line 279 "myanalyzer.y"
                { (yyval.str) = template("%s %s(%s) {\n%s\n}", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str)); }
#line 1856 "myanalyzer.tab.c"
    break;

  case 15: /* function: KW_FUN TK_IDENT '(' function_argument_list ')' ':' function_body KW_NUF ';'  */
#line 281 "myanalyzer.y"
                { (yyval.str) = template("void %s(%s) {\n%s\n}", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 1862 "myanalyzer.tab.c"
    break;

  case 16: /* function_argument_list: function_argument_list multiple_argument_function  */
#line 287 "myanalyzer.y"
                                                                { (yyval.str) = template("%s %s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1868 "myanalyzer.tab.c"
    break;

  case 17: /* function_argument_list: single_argument_function  */
#line 288 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 1874 "myanalyzer.tab.c"
    break;

  case 18: /* single_argument_function: TK_IDENT ':' data_type  */
#line 292 "myanalyzer.y"
                                                        { (yyval.str) = template("%s %s", (yyvsp[0].str),(yyvsp[-2].str)); }
#line 1880 "myanalyzer.tab.c"
    break;

  case 19: /* single_argument_function: TK_IDENT '[' ']' ':' data_type  */
#line 293 "myanalyzer.y"
                                                { (yyval.str) = template("%s *%s", (yyvsp[0].str),(yyvsp[-4].str));}
#line 1886 "myanalyzer.tab.c"
    break;

  case 20: /* single_argument_function: %empty  */
#line 294 "myanalyzer.y"
                                                                        { (yyval.str) = ""; }
#line 1892 "myanalyzer.tab.c"
    break;

  case 21: /* multiple_argument_function: ',' TK_IDENT ':' data_type  */
#line 298 "myanalyzer.y"
                                                        { (yyval.str) = template(",%s %s", (yyvsp[0].str),(yyvsp[-2].str)); }
#line 1898 "myanalyzer.tab.c"
    break;

  case 22: /* multiple_argument_function: ',' TK_IDENT '[' ']' ':' data_type  */
#line 299 "myanalyzer.y"
                                                { (yyval.str) = template(",%s *%s", (yyvsp[0].str),(yyvsp[-4].str)); }
#line 1904 "myanalyzer.tab.c"
    break;

  case 23: /* function_body: function_body declaration  */
#line 303 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1910 "myanalyzer.tab.c"
    break;

  case 24: /* function_body: function_body statement  */
#line 304 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1916 "myanalyzer.tab.c"
    break;

  case 25: /* function_body: %empty  */
#line 305 "myanalyzer.y"
                                                        { (yyval.str) = ""; }
#line 1922 "myanalyzer.tab.c"
    break;

  case 26: /* data: expr  */
#line 311 "myanalyzer.y"
                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1928 "myanalyzer.tab.c"
    break;

  case 27: /* data: TK_STRING  */
#line 312 "myanalyzer.y"
                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1934 "myanalyzer.tab.c"
    break;

  case 28: /* data_type: KW_INT  */
#line 316 "myanalyzer.y"
                                { (yyval.str) = "int"; }
#line 1940 "myanalyzer.tab.c"
    break;

  case 29: /* data_type: KW_REAL  */
#line 317 "myanalyzer.y"
                                { (yyval.str) = "double"; }
#line 1946 "myanalyzer.tab.c"
    break;

  case 30: /* data_type: KW_TEXT  */
#line 318 "myanalyzer.y"
                                { (yyval.str) = "char*"; }
#line 1952 "myanalyzer.tab.c"
    break;

  case 31: /* data_type: KW_BOOL  */
#line 319 "myanalyzer.y"
                                { (yyval.str) = "int"; }
#line 1958 "myanalyzer.tab.c"
    break;

  case 32: /* data_type: TK_IDENT  */
#line 320 "myanalyzer.y"
                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1964 "myanalyzer.tab.c"
    break;

  case 33: /* boolean_value: KW_TRUE  */
#line 324 "myanalyzer.y"
                                { (yyval.str) = "1"; }
#line 1970 "myanalyzer.tab.c"
    break;

  case 34: /* boolean_value: KW_FALSE  */
#line 325 "myanalyzer.y"
                                { (yyval.str) = "0"; }
#line 1976 "myanalyzer.tab.c"
    break;

  case 35: /* array_value: TK_IDENT '[' expr ']'  */
#line 329 "myanalyzer.y"
                                                        { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1982 "myanalyzer.tab.c"
    break;

  case 36: /* array_value: TK_IDENT '[' ']'  */
#line 330 "myanalyzer.y"
                                                                { (yyval.str) = template("%s*", (yyvsp[-2].str)); }
#line 1988 "myanalyzer.tab.c"
    break;

  case 37: /* array_value: comp_variable '[' ']'  */
#line 331 "myanalyzer.y"
                                                        { (yyval.str) = template("self->%s[]", (yyvsp[-2].str)); }
#line 1994 "myanalyzer.tab.c"
    break;

  case 38: /* array_value: comp_variable '[' expr ']'  */
#line 332 "myanalyzer.y"
                                                { (yyval.str) = template("self->%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2000 "myanalyzer.tab.c"
    break;

  case 39: /* expr_data_type: TK_IDENT  */
#line 336 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2006 "myanalyzer.tab.c"
    break;

  case 40: /* expr_data_type: TK_NUMBER  */
#line 337 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2012 "myanalyzer.tab.c"
    break;

  case 41: /* expr_data_type: TK_REAL  */
#line 338 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2018 "myanalyzer.tab.c"
    break;

  case 42: /* expr_data_type: array_value  */
#line 339 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2024 "myanalyzer.tab.c"
    break;

  case 43: /* expr_data_type: boolean_value  */
#line 340 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2030 "myanalyzer.tab.c"
    break;

  case 44: /* expr_data_type: comp_variable  */
#line 341 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2036 "myanalyzer.tab.c"
    break;

  case 46: /* expr: '(' expr ')'  */
#line 346 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[-1].str)); }
#line 2042 "myanalyzer.tab.c"
    break;

  case 47: /* expr: expr '+' expr  */
#line 347 "myanalyzer.y"
                                        { (yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2048 "myanalyzer.tab.c"
    break;

  case 48: /* expr: expr '-' expr  */
#line 348 "myanalyzer.y"
                                        { (yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2054 "myanalyzer.tab.c"
    break;

  case 49: /* expr: expr '*' expr  */
#line 349 "myanalyzer.y"
                                        { (yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2060 "myanalyzer.tab.c"
    break;

  case 50: /* expr: expr '/' expr  */
#line 350 "myanalyzer.y"
                                        { (yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2066 "myanalyzer.tab.c"
    break;

  case 51: /* expr: expr '%' expr  */
#line 351 "myanalyzer.y"
                                        { (yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2072 "myanalyzer.tab.c"
    break;

  case 52: /* expr: expr KW_POW expr  */
#line 352 "myanalyzer.y"
                                        { (yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2078 "myanalyzer.tab.c"
    break;

  case 53: /* expr: expr KW_EQ expr  */
#line 353 "myanalyzer.y"
                                        { (yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2084 "myanalyzer.tab.c"
    break;

  case 54: /* expr: expr KW_NOTEQ expr  */
#line 354 "myanalyzer.y"
                                { (yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2090 "myanalyzer.tab.c"
    break;

  case 55: /* expr: expr '<' expr  */
#line 355 "myanalyzer.y"
                                        { (yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2096 "myanalyzer.tab.c"
    break;

  case 56: /* expr: expr KW_LESSEQ expr  */
#line 356 "myanalyzer.y"
                                { (yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2102 "myanalyzer.tab.c"
    break;

  case 57: /* expr: expr '>' expr  */
#line 357 "myanalyzer.y"
                                        { (yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2108 "myanalyzer.tab.c"
    break;

  case 58: /* expr: expr KW_GREATEREQ expr  */
#line 358 "myanalyzer.y"
                                { (yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2114 "myanalyzer.tab.c"
    break;

  case 59: /* expr: expr KW_AND expr  */
#line 359 "myanalyzer.y"
                                        { (yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2120 "myanalyzer.tab.c"
    break;

  case 60: /* expr: expr KW_OR expr  */
#line 360 "myanalyzer.y"
                                        { (yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2126 "myanalyzer.tab.c"
    break;

  case 61: /* expr: KW_NOT expr  */
#line 361 "myanalyzer.y"
                                { (yyval.str) = template("!%s", (yyvsp[0].str)); }
#line 2132 "myanalyzer.tab.c"
    break;

  case 62: /* expr: KW_BREAK  */
#line 362 "myanalyzer.y"
                                                { (yyval.str) = template("break"); }
#line 2138 "myanalyzer.tab.c"
    break;

  case 63: /* expr: KW_CONTINUE  */
#line 363 "myanalyzer.y"
                                        { (yyval.str) = template("continue"); }
#line 2144 "myanalyzer.tab.c"
    break;

  case 64: /* expr: expr_function  */
#line 364 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2150 "myanalyzer.tab.c"
    break;

  case 65: /* expr: comp_values  */
#line 365 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2156 "myanalyzer.tab.c"
    break;

  case 66: /* declaration_list: declaration_list declaration  */
#line 369 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2162 "myanalyzer.tab.c"
    break;

  case 67: /* declaration_list: declaration  */
#line 370 "myanalyzer.y"
                                                        { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 2168 "myanalyzer.tab.c"
    break;

  case 68: /* declaration: variable_declaration  */
#line 374 "myanalyzer.y"
                                                { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2174 "myanalyzer.tab.c"
    break;

  case 69: /* declaration: const_variable_declaration  */
#line 375 "myanalyzer.y"
                                        { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2180 "myanalyzer.tab.c"
    break;

  case 70: /* variable_declaration: variable_assign_declaration ';'  */
#line 381 "myanalyzer.y"
                                        { (yyval.str) = template("%s;",(yyvsp[-1].str)); }
#line 2186 "myanalyzer.tab.c"
    break;

  case 71: /* variable_assign_declaration: single_variable_declaration multiple_variable_declaration ':' data_type  */
#line 385 "myanalyzer.y"
                                                                               { {(yyval.str) = template("%s %s %s",(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-2].str));} }
#line 2192 "myanalyzer.tab.c"
    break;

  case 72: /* variable_assign_declaration: single_variable_declaration ':' data_type  */
#line 386 "myanalyzer.y"
                                                    { (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2198 "myanalyzer.tab.c"
    break;

  case 73: /* single_variable_declaration: TK_IDENT '=' data  */
#line 390 "myanalyzer.y"
                                                { (yyval.str) = template("%s = %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2204 "myanalyzer.tab.c"
    break;

  case 74: /* single_variable_declaration: TK_IDENT  */
#line 391 "myanalyzer.y"
                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2210 "myanalyzer.tab.c"
    break;

  case 75: /* single_variable_declaration: array_value  */
#line 392 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2216 "myanalyzer.tab.c"
    break;

  case 76: /* single_variable_declaration: array_value '=' expr  */
#line 393 "myanalyzer.y"
                                        { (yyval.str) = template("%s = %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2222 "myanalyzer.tab.c"
    break;

  case 77: /* multiple_variable_declaration: multiple_variable_declaration ',' TK_IDENT '=' data  */
#line 397 "myanalyzer.y"
                                                            { (yyval.str) = template("%s, %s = %s",(yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));}
#line 2228 "myanalyzer.tab.c"
    break;

  case 78: /* multiple_variable_declaration: multiple_variable_declaration ',' TK_IDENT  */
#line 398 "myanalyzer.y"
                                                     { (yyval.str) = template("%s, %s ",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2234 "myanalyzer.tab.c"
    break;

  case 79: /* multiple_variable_declaration: multiple_variable_declaration ',' array_value '=' expr  */
#line 399 "myanalyzer.y"
                                                                 {{(yyval.str) = template("%s, %s = %s",(yyvsp[-4].str),(yyvsp[-2].str), (yyvsp[0].str));}}
#line 2240 "myanalyzer.tab.c"
    break;

  case 80: /* multiple_variable_declaration: multiple_variable_declaration ',' array_value  */
#line 400 "myanalyzer.y"
                                                        { (yyval.str) = template("%s, %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2246 "myanalyzer.tab.c"
    break;

  case 81: /* multiple_variable_declaration: ',' TK_IDENT '=' expr  */
#line 401 "myanalyzer.y"
                                                                                { (yyval.str) = template(", %s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2252 "myanalyzer.tab.c"
    break;

  case 82: /* multiple_variable_declaration: ',' TK_IDENT  */
#line 402 "myanalyzer.y"
                                                                                        { (yyval.str) = template(", %s ",(yyvsp[0].str));}
#line 2258 "myanalyzer.tab.c"
    break;

  case 83: /* multiple_variable_declaration: ',' array_value '=' expr  */
#line 403 "myanalyzer.y"
                                                                                { (yyval.str) = template(", %s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2264 "myanalyzer.tab.c"
    break;

  case 84: /* multiple_variable_declaration: ',' array_value  */
#line 404 "myanalyzer.y"
                                                                                        { (yyval.str) = template(", %s ",(yyvsp[0].str));}
#line 2270 "myanalyzer.tab.c"
    break;

  case 85: /* const_variable_declaration: KW_CONST const_variable_assign_declaration ';'  */
#line 410 "myanalyzer.y"
                                                       { (yyval.str) = template("const %s;",(yyvsp[-1].str)); }
#line 2276 "myanalyzer.tab.c"
    break;

  case 86: /* const_variable_assign_declaration: single_const_variable_declaration multiple_const_variable_declaration ':' data_type  */
#line 414 "myanalyzer.y"
                                                                                            { {(yyval.str) = template("%s %s %s",(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-2].str));} }
#line 2282 "myanalyzer.tab.c"
    break;

  case 87: /* const_variable_assign_declaration: single_const_variable_declaration ':' data_type  */
#line 415 "myanalyzer.y"
                                                          { (yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2288 "myanalyzer.tab.c"
    break;

  case 88: /* single_const_variable_declaration: TK_IDENT '=' data  */
#line 419 "myanalyzer.y"
                          { (yyval.str) = template("%s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2294 "myanalyzer.tab.c"
    break;

  case 89: /* multiple_const_variable_declaration: multiple_const_variable_declaration ',' TK_IDENT '=' data  */
#line 423 "myanalyzer.y"
                                                                  { (yyval.str) = template("%s, %s = %s",(yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));}
#line 2300 "myanalyzer.tab.c"
    break;

  case 90: /* multiple_const_variable_declaration: ',' TK_IDENT '=' data  */
#line 424 "myanalyzer.y"
                                { (yyval.str) = template(", %s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2306 "myanalyzer.tab.c"
    break;

  case 91: /* statement_list: statement_list statement  */
#line 430 "myanalyzer.y"
                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2312 "myanalyzer.tab.c"
    break;

  case 92: /* statement_list: statement  */
#line 431 "myanalyzer.y"
                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2318 "myanalyzer.tab.c"
    break;

  case 93: /* statement: assign_statement  */
#line 435 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2324 "myanalyzer.tab.c"
    break;

  case 94: /* statement: break_statement  */
#line 436 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2330 "myanalyzer.tab.c"
    break;

  case 95: /* statement: continue_statement  */
#line 437 "myanalyzer.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 2336 "myanalyzer.tab.c"
    break;

  case 96: /* statement: return_statement  */
#line 438 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2342 "myanalyzer.tab.c"
    break;

  case 97: /* statement: if_statement  */
#line 439 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2348 "myanalyzer.tab.c"
    break;

  case 98: /* statement: while_statement  */
#line 440 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2354 "myanalyzer.tab.c"
    break;

  case 99: /* statement: for_statement  */
#line 441 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2360 "myanalyzer.tab.c"
    break;

  case 100: /* statement: function_statement  */
#line 442 "myanalyzer.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 2366 "myanalyzer.tab.c"
    break;

  case 101: /* assign_statement: TK_IDENT '=' expr ';'  */
#line 446 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2372 "myanalyzer.tab.c"
    break;

  case 102: /* assign_statement: TK_IDENT '=' '-' expr ';'  */
#line 447 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s = -%s;", (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2378 "myanalyzer.tab.c"
    break;

  case 103: /* assign_statement: TK_IDENT '.' comp_variable '=' expr ';'  */
#line 448 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s.%s = %s;", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2384 "myanalyzer.tab.c"
    break;

  case 104: /* assign_statement: TK_IDENT '.' comp_variable '=' '-' expr ';'  */
#line 449 "myanalyzer.y"
                                                                { (yyval.str) = template("%s.%s = -%s;", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2390 "myanalyzer.tab.c"
    break;

  case 105: /* assign_statement: array_value '=' expr ';'  */
#line 450 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2396 "myanalyzer.tab.c"
    break;

  case 106: /* assign_statement: comp_variable '=' expr ';'  */
#line 451 "myanalyzer.y"
                                                                                { (yyval.str) = template("self->%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2402 "myanalyzer.tab.c"
    break;

  case 107: /* assign_statement: comp_variable '=' '-' expr ';'  */
#line 452 "myanalyzer.y"
                                                                                { (yyval.str) = template("self->%s = -self->%s;", (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2408 "myanalyzer.tab.c"
    break;

  case 108: /* assign_statement: TK_IDENT assign_operator expr ';'  */
#line 453 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s %s %s;", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2414 "myanalyzer.tab.c"
    break;

  case 109: /* assign_statement: comp_variable assign_operator expr ';'  */
#line 454 "myanalyzer.y"
                                                                        { (yyval.str) = template("self->%s %s %s;", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2420 "myanalyzer.tab.c"
    break;

  case 110: /* assign_statement: TK_IDENT KW_COLONEQ '[' expr KW_FOR TK_IDENT ':' TK_NUMBER ']' ':' data_type ';'  */
#line 457 "myanalyzer.y"
                { (yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s=0; %s < %s; ++%s){\n%s[%s] = %s;\n}",
		                (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str)); }
#line 2427 "myanalyzer.tab.c"
    break;

  case 111: /* assign_statement: TK_IDENT KW_COLONEQ '[' expr KW_FOR TK_IDENT ':' data_type KW_IN TK_IDENT KW_OF TK_NUMBER ']' ':' data_type ';'  */
#line 461 "myanalyzer.y"
                {
			char* res = (char *)malloc(strlen((yyvsp[-6].str)) + 16);
			sprintf(res, "%s[%s_i]", (yyvsp[-6].str), (yyvsp[-6].str));
			char* final_char = replaceSubstring((yyvsp[-12].str), (yyvsp[-10].str), res);
			free(res);
			(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s_i=0; %s_i < %s; ++%s_i){\n%s[%s_i] = %s;\n}",
			             (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-15].str), (yyvsp[-6].str), final_char);
		}
#line 2440 "myanalyzer.tab.c"
    break;

  case 112: /* assign_operator: KW_INCR  */
#line 472 "myanalyzer.y"
                                                { (yyval.str) = template("+="); }
#line 2446 "myanalyzer.tab.c"
    break;

  case 113: /* assign_operator: KW_DECR  */
#line 473 "myanalyzer.y"
                                                { (yyval.str) = template("-="); }
#line 2452 "myanalyzer.tab.c"
    break;

  case 114: /* assign_operator: KW_TIMES_INCR  */
#line 474 "myanalyzer.y"
                                        { (yyval.str) = template("*="); }
#line 2458 "myanalyzer.tab.c"
    break;

  case 115: /* assign_operator: KW_DIV_DECR  */
#line 475 "myanalyzer.y"
                                        { (yyval.str) = template("/="); }
#line 2464 "myanalyzer.tab.c"
    break;

  case 116: /* assign_operator: KW_MOD_DECR  */
#line 476 "myanalyzer.y"
                                        { (yyval.str) = template("%="); }
#line 2470 "myanalyzer.tab.c"
    break;

  case 117: /* break_statement: KW_BREAK ';'  */
#line 480 "myanalyzer.y"
                                                { (yyval.str) = "break; "; }
#line 2476 "myanalyzer.tab.c"
    break;

  case 118: /* continue_statement: KW_CONTINUE ';'  */
#line 484 "myanalyzer.y"
                                                { (yyval.str) = "continue; "; }
#line 2482 "myanalyzer.tab.c"
    break;

  case 119: /* return_statement: KW_RETURN ';'  */
#line 488 "myanalyzer.y"
                                                { (yyval.str) = "return;"; }
#line 2488 "myanalyzer.tab.c"
    break;

  case 120: /* return_statement: KW_RETURN expr ';'  */
#line 489 "myanalyzer.y"
                                        { (yyval.str) = template("return %s;", (yyvsp[-1].str)); }
#line 2494 "myanalyzer.tab.c"
    break;

  case 121: /* if_statement: KW_IF '(' expr ')' ':' if_for_while_body KW_FI ';'  */
#line 494 "myanalyzer.y"
                { (yyval.str) = template("if (%s) {\n%s\n}",(yyvsp[-5].str),(yyvsp[-2].str)); }
#line 2500 "myanalyzer.tab.c"
    break;

  case 122: /* if_statement: KW_IF '(' expr ')' ':' if_for_while_body KW_ELSE ':' if_for_while_body KW_FI ';'  */
#line 496 "myanalyzer.y"
                { (yyval.str) = template("if (%s) {\n%s\n} else {\n%s\n}",(yyvsp[-8].str),(yyvsp[-5].str),(yyvsp[-2].str)); }
#line 2506 "myanalyzer.tab.c"
    break;

  case 123: /* if_for_while_body: if_for_while_body declaration  */
#line 500 "myanalyzer.y"
                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2512 "myanalyzer.tab.c"
    break;

  case 124: /* if_for_while_body: if_for_while_body statement  */
#line 501 "myanalyzer.y"
                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2518 "myanalyzer.tab.c"
    break;

  case 125: /* if_for_while_body: %empty  */
#line 502 "myanalyzer.y"
                                                                        { (yyval.str) = ""; }
#line 2524 "myanalyzer.tab.c"
    break;

  case 126: /* while_statement: KW_WHILE '(' expr ')' ':' if_for_while_body KW_OD ';'  */
#line 507 "myanalyzer.y"
                { (yyval.str) = template("while(%s) {\n%s\n} ",(yyvsp[-5].str),(yyvsp[-2].str)); }
#line 2530 "myanalyzer.tab.c"
    break;

  case 127: /* for_statement: KW_FOR TK_IDENT KW_IN '[' expr ':' expr ']' ':' if_for_while_body KW_ROF ';'  */
#line 512 "myanalyzer.y"
                { (yyval.str) = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str)); }
#line 2536 "myanalyzer.tab.c"
    break;

  case 128: /* for_statement: KW_FOR TK_IDENT KW_IN '[' expr ':' expr ':' expr ']' ':' if_for_while_body KW_ROF ';'  */
#line 514 "myanalyzer.y"
                {
			step_value = atoi((yyvsp[-5].str));
			if (step_value > 0) {
				(yyval.str) = template("for (int %s = %s; %s < %s; %s+=%s) {\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str)); 
			} else if (step_value == -1) { 
				(yyval.str) = template("for (int %s = %s; %s < %s; %s--) {\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-2].str)); 
			} else {
				(yyval.str) = template("for (int %s = %s; %s < %s; %s-=%s) {\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str)+1, (yyvsp[-2].str));
			}
		}
#line 2551 "myanalyzer.tab.c"
    break;

  case 129: /* function_statement: TK_IDENT '(' function_parameter_list ')' ';'  */
#line 527 "myanalyzer.y"
                                                     { (yyval.str) = template("%s(%s);", (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2557 "myanalyzer.tab.c"
    break;

  case 130: /* function_statement: TK_IDENT '.' expr_function ';'  */
#line 528 "myanalyzer.y"
                                                                 { (yyval.str) = template("%s.%s;?", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2563 "myanalyzer.tab.c"
    break;

  case 131: /* function_statement: comp_variable '.' expr_function ';'  */
#line 529 "myanalyzer.y"
                                                         { (yyval.str) = template("%s.%s;?", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2569 "myanalyzer.tab.c"
    break;

  case 132: /* function_statement: array_value '.' expr_function ';'  */
#line 530 "myanalyzer.y"
                                                         { (yyval.str) = template("%s.%s;?", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2575 "myanalyzer.tab.c"
    break;

  case 133: /* expr_function: TK_IDENT '(' function_parameter_list ')'  */
#line 534 "myanalyzer.y"
                                                        { (yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2581 "myanalyzer.tab.c"
    break;

  case 134: /* expr_function: TK_IDENT '.' expr_function  */
#line 535 "myanalyzer.y"
                                                                { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2587 "myanalyzer.tab.c"
    break;

  case 135: /* function_parameter_list: function_parameter_list ',' expr  */
#line 539 "myanalyzer.y"
                                                        { (yyval.str) = template("%s,%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2593 "myanalyzer.tab.c"
    break;

  case 136: /* function_parameter_list: expr  */
#line 540 "myanalyzer.y"
                                                                                { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 2599 "myanalyzer.tab.c"
    break;

  case 137: /* function_parameter_list: '-' expr  */
#line 541 "myanalyzer.y"
                                                                                { (yyval.str) = template("-%s", (yyvsp[0].str));  }
#line 2605 "myanalyzer.tab.c"
    break;

  case 138: /* function_parameter_list: TK_IDENT '.' comp_variable  */
#line 542 "myanalyzer.y"
                                                        { (yyval.str) = template("%s.%s", (yyvsp[-2].str),(yyvsp[0].str)); }
#line 2611 "myanalyzer.tab.c"
    break;

  case 139: /* function_parameter_list: TK_STRING  */
#line 543 "myanalyzer.y"
                                                                                { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 2617 "myanalyzer.tab.c"
    break;

  case 140: /* function_parameter_list: %empty  */
#line 544 "myanalyzer.y"
                                                                                { (yyval.str) = ""; }
#line 2623 "myanalyzer.tab.c"
    break;

  case 141: /* comp_list: comp_list comp  */
#line 550 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2629 "myanalyzer.tab.c"
    break;

  case 143: /* comp: KW_RECORD TK_IDENT ':' comp_body KW_DROCER ';'  */
#line 556 "myanalyzer.y"
                {  (yyval.str) = template("#define SELF struct %s *self \ntypedef struct %s {\n%s\n} %s ;\n\n%s\n#undef SELF\n",
		                 (yyvsp[-4].str), (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str), deff); }
#line 2636 "myanalyzer.tab.c"
    break;

  case 144: /* comp_body: comp_variable_declaration_list comp_func_list  */
#line 561 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str)); }
#line 2642 "myanalyzer.tab.c"
    break;

  case 145: /* comp_body: comp_variable_declaration_list  */
#line 562 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2648 "myanalyzer.tab.c"
    break;

  case 146: /* comp_body: comp_func_list  */
#line 563 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2654 "myanalyzer.tab.c"
    break;

  case 147: /* comp_variable_declaration_list: comp_variable_declaration_list comp_variable_declaration  */
#line 567 "myanalyzer.y"
                                                                 { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2660 "myanalyzer.tab.c"
    break;

  case 149: /* comp_variable_declaration: comp_variable_assign_declaration ';'  */
#line 572 "myanalyzer.y"
                                                { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 2666 "myanalyzer.tab.c"
    break;

  case 150: /* comp_variable_assign_declaration: single_comp_variable_declaration multiple_comp_variable_declaration ':' data_type  */
#line 576 "myanalyzer.y"
                                                                                          { {(yyval.str) = template("%s %s %s",(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-2].str));} }
#line 2672 "myanalyzer.tab.c"
    break;

  case 151: /* comp_variable_assign_declaration: single_comp_variable_declaration ':' data_type  */
#line 577 "myanalyzer.y"
                                                         { (yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2678 "myanalyzer.tab.c"
    break;

  case 152: /* single_comp_variable_declaration: comp_variable  */
#line 581 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2684 "myanalyzer.tab.c"
    break;

  case 153: /* single_comp_variable_declaration: array_value  */
#line 582 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2690 "myanalyzer.tab.c"
    break;

  case 154: /* multiple_comp_variable_declaration: multiple_const_variable_declaration ',' '#' TK_IDENT  */
#line 586 "myanalyzer.y"
                                                                { (yyval.str) = template("%s, %s",(yyvsp[-3].str),(yyvsp[0].str)); }
#line 2696 "myanalyzer.tab.c"
    break;

  case 155: /* multiple_comp_variable_declaration: ',' comp_variable  */
#line 587 "myanalyzer.y"
                                                                                                { (yyval.str) = template(", %s",(yyvsp[0].str)); }
#line 2702 "myanalyzer.tab.c"
    break;

  case 156: /* multiple_comp_variable_declaration: ',' '#' array_value  */
#line 588 "myanalyzer.y"
                                                                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2708 "myanalyzer.tab.c"
    break;

  case 157: /* comp_func_list: comp_func_list comp_func  */
#line 592 "myanalyzer.y"
                                                                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2714 "myanalyzer.tab.c"
    break;

  case 159: /* comp_func: KW_FUN TK_IDENT '(' function_argument_list ')' KW_ARROW_FUNCTION data_type ':' function_body KW_NUF ';'  */
#line 597 "myanalyzer.y"
                                                                                                                 {
		int alloc_size = strlen((yyvsp[-9].str))+strlen((yyvsp[-7].str))+strlen((yyvsp[-4].str))+strlen((yyvsp[-2].str))+20;
		size_t newLength = (deff ? strlen(deff) : 0) + alloc_size + 1;
    	char *newDest = (char *)realloc(deff, newLength);
		char* src = (char *)malloc(alloc_size * sizeof(char));
		if (strlen((yyvsp[-7].str)) == 0) {
			sprintf(src, "%s %s(SELF){%s\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-2].str));
			(yyval.str) = template("%s (*%s) (SELF);", (yyvsp[-4].str), (yyvsp[-9].str)); 
		} else {
			sprintf(src, "%s %s(SELF,%s){%s\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));
			(yyval.str) = template("%s (*%s) (SELF, %s);", (yyvsp[-4].str), (yyvsp[-9].str),(yyvsp[-7].str)); 
		}
    	
		if (deff == NULL)
		{
		    strcpy(newDest, src);
		}
		else
		{
		    strcat(newDest, src);
		}
		deff = newDest;

		}
#line 2743 "myanalyzer.tab.c"
    break;

  case 160: /* comp_func: KW_FUN TK_IDENT '(' function_argument_list ')' ':' function_body KW_NUF ';'  */
#line 623 "myanalyzer.y"
                                                                                        { 
		int alloc_size = strlen((yyvsp[-7].str))+strlen((yyvsp[-5].str))+strlen((yyvsp[-2].str))+20;
		size_t newLength = (deff ? strlen(deff) : 0) + alloc_size + 1;
    	char *newDest = (char *)realloc(deff, newLength);
		char* src = (char *)malloc(alloc_size * sizeof(char));
		if (strlen((yyvsp[-5].str)) == 0)  { 
			sprintf(src, "void %s(SELF){%s\n}\n",(yyvsp[-7].str),(yyvsp[-2].str));
			(yyval.str) = template("void (*%s) (SELF);", (yyvsp[-7].str)); 
		} else {
			sprintf(src, "void %s(SELF, %s){%s\n}\n",(yyvsp[-7].str),(yyvsp[-5].str),(yyvsp[-2].str));
			(yyval.str) = template("void (*%s) (SELF, %s);", (yyvsp[-7].str),(yyvsp[-5].str));
		} 

		if (deff == NULL)
		{
		    strcpy(newDest, src);
		}
		else
		{
		    strcat(newDest, src);
		}
		deff = newDest;
		}
#line 2771 "myanalyzer.tab.c"
    break;

  case 161: /* comp_variable: '#' TK_IDENT  */
#line 649 "myanalyzer.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 2777 "myanalyzer.tab.c"
    break;

  case 162: /* comp_value: array_value '.' comp_variable  */
#line 653 "myanalyzer.y"
                                       { (yyval.str) = template("self->%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2783 "myanalyzer.tab.c"
    break;

  case 163: /* comp_values: comp_value '.' comp_variable  */
#line 657 "myanalyzer.y"
                                       { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2789 "myanalyzer.tab.c"
    break;


#line 2793 "myanalyzer.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 662 "myanalyzer.y"


int main () {
  if ( yyparse() == 0 )
    printf("// Your program is syntactically correct!\n");
  else
  	printf("// Your program is not syntactically correct!\n");
}
