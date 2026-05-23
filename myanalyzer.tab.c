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
  YYSYMBOL_UMINUS = 62,                    /* UMINUS  */
  YYSYMBOL_63_ = 63,                       /* '.'  */
  YYSYMBOL_64_ = 64,                       /* '#'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_function_list = 67,             /* function_list  */
  YYSYMBOL_function = 68,                  /* function  */
  YYSYMBOL_function_argument_list = 69,    /* function_argument_list  */
  YYSYMBOL_single_argument_function = 70,  /* single_argument_function  */
  YYSYMBOL_multiple_argument_function = 71, /* multiple_argument_function  */
  YYSYMBOL_function_body = 72,             /* function_body  */
  YYSYMBOL_data = 73,                      /* data  */
  YYSYMBOL_data_type = 74,                 /* data_type  */
  YYSYMBOL_boolean_value = 75,             /* boolean_value  */
  YYSYMBOL_array_value = 76,               /* array_value  */
  YYSYMBOL_expr_data_type = 77,            /* expr_data_type  */
  YYSYMBOL_expr = 78,                      /* expr  */
  YYSYMBOL_declaration_list = 79,          /* declaration_list  */
  YYSYMBOL_declaration = 80,               /* declaration  */
  YYSYMBOL_variable_declaration = 81,      /* variable_declaration  */
  YYSYMBOL_variable_assign_declaration = 82, /* variable_assign_declaration  */
  YYSYMBOL_single_variable_declaration = 83, /* single_variable_declaration  */
  YYSYMBOL_multiple_variable_declaration = 84, /* multiple_variable_declaration  */
  YYSYMBOL_const_variable_declaration = 85, /* const_variable_declaration  */
  YYSYMBOL_const_variable_assign_declaration = 86, /* const_variable_assign_declaration  */
  YYSYMBOL_single_const_variable_declaration = 87, /* single_const_variable_declaration  */
  YYSYMBOL_multiple_const_variable_declaration = 88, /* multiple_const_variable_declaration  */
  YYSYMBOL_statement_list = 89,            /* statement_list  */
  YYSYMBOL_statement = 90,                 /* statement  */
  YYSYMBOL_assign_statement = 91,          /* assign_statement  */
  YYSYMBOL_assign_operator = 92,           /* assign_operator  */
  YYSYMBOL_break_statement = 93,           /* break_statement  */
  YYSYMBOL_continue_statement = 94,        /* continue_statement  */
  YYSYMBOL_return_statement = 95,          /* return_statement  */
  YYSYMBOL_if_statement = 96,              /* if_statement  */
  YYSYMBOL_if_for_while_body = 97,         /* if_for_while_body  */
  YYSYMBOL_while_statement = 98,           /* while_statement  */
  YYSYMBOL_for_statement = 99,             /* for_statement  */
  YYSYMBOL_function_statement = 100,       /* function_statement  */
  YYSYMBOL_expr_function = 101,            /* expr_function  */
  YYSYMBOL_function_parameter_list = 102,  /* function_parameter_list  */
  YYSYMBOL_comp_list = 103,                /* comp_list  */
  YYSYMBOL_comp = 104,                     /* comp  */
  YYSYMBOL_comp_body = 105,                /* comp_body  */
  YYSYMBOL_comp_variable_declaration_list = 106, /* comp_variable_declaration_list  */
  YYSYMBOL_comp_variable_declaration = 107, /* comp_variable_declaration  */
  YYSYMBOL_comp_variable_assign_declaration = 108, /* comp_variable_assign_declaration  */
  YYSYMBOL_single_comp_variable_declaration = 109, /* single_comp_variable_declaration  */
  YYSYMBOL_multiple_comp_variable_declaration = 110, /* multiple_comp_variable_declaration  */
  YYSYMBOL_comp_func_list = 111,           /* comp_func_list  */
  YYSYMBOL_comp_func = 112,                /* comp_func  */
  YYSYMBOL_comp_variable = 113,            /* comp_variable  */
  YYSYMBOL_comp_value = 114,               /* comp_value  */
  YYSYMBOL_comp_values = 115               /* comp_values  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  384

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
       2,     2,     2,     2,     2,    64,     2,    53,     2,     2,
      55,    56,    51,    50,    61,    49,    63,    52,     2,     2,
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
      45,    46,    62
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
     360,   361,   362,   363,   364,   365,   366,   367,   371,   372,
     376,   377,   383,   387,   388,   392,   393,   394,   395,   399,
     400,   401,   402,   403,   404,   405,   406,   412,   416,   417,
     421,   425,   426,   432,   433,   437,   438,   439,   440,   441,
     442,   443,   444,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   458,   462,   474,   475,   476,   477,   478,   482,
     486,   490,   491,   495,   497,   502,   503,   504,   508,   513,
     515,   529,   530,   531,   532,   536,   537,   541,   542,   543,
     544,   545,   546,   552,   553,   557,   563,   564,   565,   569,
     570,   574,   578,   579,   583,   584,   588,   589,   590,   594,
     595,   599,   625,   651,   655,   659,   660
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
  "']'", "','", "UMINUS", "'.'", "'#'", "$accept", "program",
  "function_list", "function", "function_argument_list",
  "single_argument_function", "multiple_argument_function",
  "function_body", "data", "data_type", "boolean_value", "array_value",
  "expr_data_type", "expr", "declaration_list", "declaration",
  "variable_declaration", "variable_assign_declaration",
  "single_variable_declaration", "multiple_variable_declaration",
  "const_variable_declaration", "const_variable_assign_declaration",
  "single_const_variable_declaration",
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

#define YYPACT_NINF (-286)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     593,   288,    32,   -44,    33,    -9,    36,    47,     9,    52,
      69,   120,   129,    14,  -286,   -26,   637,  -286,  -286,    68,
     -36,  -286,   803,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,    17,  -286,   358,    77,  -286,  -286,  -286,  -286,
    -286,   384,   407,   440,    51,   214,    89,   106,   100,   214,
     166,   214,  -286,  -286,   140,   141,    82,  -286,  -286,  -286,
    -286,  -286,  -286,   214,   214,   214,   214,  -286,  -286,   138,
    -286,   905,  -286,   160,   159,  -286,   143,  -286,  -286,  -286,
      45,   214,   230,   207,  -286,   290,  -286,   220,    57,   136,
     438,    65,  -286,    25,   207,   182,   110,  -286,   160,   529,
     463,   230,   214,   214,  -286,   214,  -286,   933,   121,  -286,
     214,  1297,    50,  -286,   851,    49,   197,   186,   961,   513,
    -286,   220,   255,   137,  1213,   203,  1241,   267,   215,   407,
     230,  -286,  1297,  1297,  1269,   212,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
    -286,   212,    10,    54,   989,   221,    14,  -286,  -286,  -286,
    -286,  -286,  -286,    85,   226,   220,    58,   563,   214,   513,
     214,   207,   214,  1017,  -286,   869,   223,  1045,   805,  1073,
    -286,    51,  1297,   224,   214,  -286,  -286,   579,  -286,  -286,
    1297,  -286,   229,   220,   281,   234,   214,   237,   154,    64,
    -286,   242,   102,  -286,  -286,  -286,  1315,  1315,   250,   139,
     139,   139,   139,   139,   139,    81,    81,   250,   250,   250,
    -286,   228,   299,  -286,   272,    10,  -286,   251,   145,   282,
    -286,   160,  -286,  -286,   279,   214,   214,  -286,   124,   261,
     933,   989,  1297,  1101,  -286,  -286,  -286,  -286,   313,  -286,
    -286,  -286,  1297,   214,  1129,   513,  -286,   266,  -286,  1185,
    -286,   220,   263,   -16,   318,  -286,  -286,  -286,   271,   269,
    -286,   282,  -286,   220,    63,   274,   280,  -286,  1297,  1297,
     513,   214,  -286,   287,  1157,  -286,  -286,   513,   621,   214,
     525,  -286,   289,   220,  -286,   157,   659,   267,  -286,  -286,
      66,  -286,    67,   220,  -286,  1297,   257,  -286,  -286,   292,
     270,  -286,  -286,   823,   278,   220,   296,   675,   220,   300,
     301,  -286,  -286,   126,   228,  -286,   335,  -286,   302,   320,
    -286,  -286,   214,   308,  -286,  -286,  -286,   309,  -286,   314,
    -286,    -4,  -286,   316,   363,   694,   887,  -286,   713,  -286,
     220,   220,  -286,   220,   340,   312,   321,   729,   319,  -286,
     323,   751,   325,   380,  -286,  -286,   327,  -286,  -286,   331,
    -286,   332,   764,  -286,   787,  -286,   336,   337,   341,   220,
    -286,  -286,   347,  -286
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    12,    77,     7,    69,    70,     0,
       0,    71,     4,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     8,   144,     0,     0,   114,   115,   116,   117,
     118,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,     0,     0,    39,    40,    41,    33,
      34,    64,    65,     0,     0,     0,     0,   121,    43,    42,
      45,     0,    66,    44,   166,    67,     0,   163,     1,    11,
       0,     0,     0,     5,    68,     0,    72,     0,     0,     0,
       0,     0,    93,    76,     3,    77,     0,   143,     0,     0,
       0,     0,     0,     0,    27,     0,    75,    26,    39,   141,
       0,   138,     0,    36,     0,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,    20,     0,   142,
       0,    63,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,    10,    78,     0,     0,    32,    28,    29,
      30,    31,    74,    84,    86,     0,     0,     0,     0,     0,
       0,     9,     0,     0,    37,     0,     0,     0,     0,    49,
     103,     0,    49,     0,     0,    35,   132,     0,   110,    90,
      26,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,   136,    46,   164,    61,    62,    54,    55,
      56,    58,    60,    57,    59,    48,    47,    51,    52,    53,
     165,     0,     0,   155,     0,   147,   150,     0,     0,   148,
     160,   154,   107,   134,     2,     0,     0,    73,    80,    82,
       0,     0,    78,     0,   108,    38,   133,   111,     0,   104,
     140,   131,   137,     0,     0,     0,    88,     0,   127,     0,
     127,     0,     0,     0,     0,    16,    25,   135,     0,     0,
     149,   146,   151,     0,     0,     0,     0,   159,    83,    85,
       0,     0,   109,     0,     0,   105,    92,     0,     0,     0,
       0,    18,     0,     0,    25,     0,     0,    20,   145,   153,
       0,   157,     0,     0,    79,    81,     0,   106,    91,     0,
       0,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,     0,   163,   158,     0,   152,     0,     0,
     127,   123,     0,     0,   128,    19,    25,     0,    21,     0,
      13,     0,   156,     0,     0,     0,     0,   127,     0,    15,
       0,     0,    25,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,   124,   127,     0,    14,    25,     0,
     112,     0,     0,   129,     0,   162,     0,     0,     0,     0,
     130,   161,     0,   113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -286,  -286,     1,     6,   101,  -286,  -286,  -285,  -115,   -94,
    -286,     7,  -286,   105,   -17,     2,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,   178,   399,     8,  -286,   382,  -286,  -286,
    -286,  -286,  -257,  -286,  -286,  -286,   -39,   293,    -7,   -31,
    -286,  -286,   193,  -286,  -286,  -286,   198,  -219,     0,  -286,
    -286
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    12,    13,    14,   199,   200,   265,   296,   106,   162,
      68,    69,    70,   190,    16,   311,    18,    19,    20,    89,
      21,    47,    48,   123,    22,   312,    24,    45,    25,    26,
      27,    28,   288,    29,    30,    31,    72,   112,    32,    33,
     224,   225,   226,   227,   228,   276,   229,   230,    73,    74,
      75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    97,    17,   290,   189,   116,    80,    15,    23,   317,
     277,    49,    54,   221,   293,    96,    34,    83,    84,    79,
      93,    87,    34,    15,    23,    88,   351,   191,    81,    91,
      92,     2,    98,    94,    17,    46,    50,    82,   222,    95,
      55,   294,     8,   155,   117,     8,    51,    10,    93,    97,
      10,   348,   277,   352,   115,    56,    57,    93,    58,     2,
     163,   238,   176,   153,    59,    60,   192,   361,     2,   324,
     257,   237,    76,   345,    11,    61,    62,    63,    10,   169,
      98,    11,    17,   374,    43,    34,   156,    95,    98,    79,
     357,   203,    91,    92,    52,   164,    98,   171,    84,   256,
      79,    64,    65,    95,   129,    53,   183,    66,   372,    11,
      67,   184,   130,    93,    71,    11,    11,   138,    11,   168,
     263,    11,    11,    77,     2,   264,    86,   300,    82,    78,
      11,   326,   147,   148,   149,   205,   103,   129,     8,   235,
     286,    43,   203,   119,    43,   130,   107,   111,   114,   234,
     118,   220,   231,    98,   124,    84,   126,   121,   267,   223,
      95,   122,    79,   184,   120,   304,    98,   291,   131,   132,
     133,   134,   308,   239,    11,   138,   129,    79,   280,   299,
      43,   250,   341,    43,   181,   125,   154,   264,   145,   146,
     147,   148,   149,   165,   193,   127,   128,   166,   194,   316,
     152,   135,   273,    97,   173,   175,   274,   177,   178,   327,
     179,   261,   329,   262,   318,   182,   319,    56,    57,   100,
      58,   335,   151,   157,   338,   231,    59,    60,   158,   159,
     160,   161,   223,   115,   111,     8,   170,    61,    62,    63,
     187,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   186,   359,   360,   192,   362,
     157,   328,   196,    64,    65,   158,   159,   160,   161,    66,
     198,   201,   240,   241,   301,   242,    11,   243,    11,   233,
     236,   246,   251,   255,   257,   382,   138,    43,    34,   252,
      34,   258,   254,    90,   260,    15,    34,    15,   321,   266,
      98,   259,   268,    15,   322,     3,   269,   325,     4,   272,
     222,     5,    10,     6,     7,   281,   283,    34,     8,   321,
     287,   295,     9,   292,    15,   322,   297,   298,   331,    35,
      36,    37,    38,    39,    40,   302,   334,   303,   342,   344,
     278,   279,    41,    42,   306,    34,   315,    43,    34,   330,
     321,    44,    15,   336,    11,    15,   322,    34,   284,   340,
     339,    34,   343,   321,    15,   347,   354,   349,    15,   322,
     364,   350,    34,   353,    34,   363,   321,   367,   365,    15,
     368,    15,   322,   370,   371,   373,   305,    56,    57,   375,
      58,   104,   376,   379,   313,   380,    59,    60,   323,   381,
      36,    37,    38,    39,    40,   383,   275,    61,    62,    63,
     108,    57,    99,    58,   109,    85,   102,   100,   270,    59,
      60,   101,   202,   271,     0,     0,     0,     0,     0,     0,
      61,    62,    63,   105,    65,     0,     0,   346,     0,    66,
       0,     0,     0,    56,    57,     0,    58,     0,    11,     0,
       0,     0,    59,    60,     0,     0,   110,    65,     0,     0,
       0,     0,    66,    61,    62,    63,    56,    57,     0,    58,
       0,    11,     0,     0,     0,    59,    60,     0,     0,    35,
      36,    37,    38,    39,    40,     0,    61,    62,    63,    64,
      65,     0,   167,    42,     0,    66,     0,    43,     0,     0,
     113,    44,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     0,     0,    56,    57,    66,    58,
     104,     0,     0,   174,     0,    59,    60,    11,     1,     0,
       0,     0,    56,    57,     0,    58,    61,    62,    63,     2,
       3,    59,    60,     4,     0,     0,     5,   314,     6,     7,
       0,     0,    61,    62,    63,     0,     0,     9,     0,     0,
       0,     0,    64,    65,     0,     0,    56,    57,    66,    58,
       0,     0,     0,     0,     0,    59,    60,    11,   172,    65,
       0,     0,    56,    57,    66,    58,    61,    62,    63,    11,
       0,    59,    60,    11,     0,     0,     1,     0,     0,     0,
       0,     0,    61,    62,    63,     0,     0,     2,     3,     0,
       0,     4,   105,    65,     5,     0,     6,     7,    66,     0,
       0,     8,     0,     0,     1,     9,    10,    11,   253,    65,
       0,     0,     0,     0,    66,     2,     3,   309,   310,     4,
       1,     0,     5,    11,     6,     7,     0,     0,     0,     0,
       0,     2,     3,     9,     0,     4,     0,    11,     5,     0,
       6,     7,     1,     0,     0,     8,     0,     0,     0,     9,
       0,     0,     0,     2,     3,     0,     0,     4,     1,     0,
       5,     0,     6,     7,     0,    11,     0,     0,   320,     2,
       3,     9,     0,     4,     0,     0,     5,     1,     6,     7,
       0,    11,     0,     0,   337,     0,     0,     9,     2,     3,
       0,   355,     4,     0,     0,     5,     1,     6,     7,     0,
       0,     0,     0,    11,     0,     0,     9,     2,     3,     0,
       0,     4,     1,     0,     5,     0,     6,     7,     0,    11,
       0,     0,   358,     2,     3,     9,     0,     4,     0,   366,
       5,     0,     6,     7,     1,     0,     0,     0,    11,     0,
       0,     9,     0,     0,     0,     2,     3,     1,     0,     4,
       0,     0,     5,     0,     6,     7,     0,    11,     2,     3,
     369,     0,     4,     9,   377,     5,     0,     6,     7,     0,
       1,     0,     0,    11,     0,     0,     9,     0,     0,     0,
       0,     2,     3,     0,     0,     4,    90,     0,     5,     0,
       6,     7,     0,     0,     0,    11,   378,     0,     3,     9,
       0,     4,     0,   248,     5,     0,     6,     7,    11,     0,
       0,   136,   137,     0,     0,     9,     0,     0,     0,     0,
       0,   138,   139,   140,   141,   142,     0,     0,     0,   136,
     137,    11,   143,   144,   145,   146,   147,   148,   149,   138,
     139,   140,   141,   142,     0,     0,     0,    11,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   136,   137,     0,
     332,     0,     0,   333,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,     0,   136,   137,     0,   143,   144,
     145,   146,   147,   148,   149,   138,   139,   140,   141,   142,
       0,   185,     0,   136,   137,     0,   143,   144,   145,   146,
     147,   148,   149,   138,   139,   140,   141,   142,     0,   245,
       0,   136,   137,     0,   143,   144,   145,   146,   147,   148,
     149,   138,   139,   140,   141,   142,     0,   356,     0,     0,
       0,     0,   143,   144,   145,   146,   147,   148,   149,   136,
     137,     0,     0,   150,     0,     0,     0,     0,     0,   138,
     139,   140,   141,   142,     0,     0,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   136,   137,     0,
       0,   180,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,   147,   148,   149,   136,   137,     0,     0,   188,
       0,     0,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,   143,   144,   145,   146,
     147,   148,   149,   136,   137,     0,     0,   232,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,     0,     0,
       0,     0,     0,     0,   143,   144,   145,   146,   147,   148,
     149,   136,   137,     0,     0,   244,     0,     0,     0,     0,
       0,   138,   139,   140,   141,   142,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,   147,   148,   149,   136,
     137,     0,     0,   247,     0,     0,     0,     0,     0,   138,
     139,   140,   141,   142,     0,     0,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   136,   137,     0,
       0,   249,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,   147,   148,   149,   136,   137,     0,     0,   282,
       0,     0,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,   143,   144,   145,   146,
     147,   148,   149,   136,   137,     0,     0,   285,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,     0,     0,
       0,     0,     0,     0,   143,   144,   145,   146,   147,   148,
     149,   136,   137,     0,     0,   307,     0,     0,     0,     0,
       0,   138,   139,   140,   141,   142,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,   147,   148,   149,   136,
     137,     0,   289,     0,     0,     0,     0,     0,     0,   138,
     139,   140,   141,   142,     0,     0,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   148,   149,   136,   137,   195,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,   142,     0,     0,     0,     0,     0,     0,   143,   144,
     145,   146,   147,   148,   149,   136,   137,   197,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,   143,   144,   145,   146,
     147,   148,   149,   136,   137,   204,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,     0,     0,
       0,     0,     0,     0,   143,   144,   145,   146,   147,   148,
     149,   138,   139,   140,   141,   142,     0,     0,     0,     0,
       0,     0,   143,   144,   145,   146,   147,   148,   149
};

static const yytype_int16 yycheck[] =
{
       0,    32,     0,   260,   119,    44,    13,     0,     0,   294,
     229,    55,     3,     3,    30,    32,    16,    16,    16,    13,
       3,    57,    22,    16,    16,    61,    30,   121,    54,    22,
      22,    14,    32,    32,    32,     3,     3,    63,    28,    32,
      31,    57,    28,    82,    44,    28,    55,    33,     3,    80,
      33,   336,   271,    57,     3,     3,     4,     3,     6,    14,
       3,     3,   101,    80,    12,    13,     3,   352,    14,     3,
       3,   165,     3,   330,    64,    23,    24,    25,    33,    54,
      80,    64,    80,   368,    59,    85,    85,    80,    88,    83,
     347,   130,    85,    85,    58,    88,    96,    96,    96,   193,
      94,    49,    50,    96,    55,    58,    56,    55,   365,    64,
      58,    61,    63,     3,     9,    64,    64,    36,    64,    54,
      56,    64,    64,     3,    14,    61,    58,    64,    63,     0,
      64,    64,    51,    52,    53,   135,    59,    55,    28,    54,
     255,    59,   181,    54,    59,    63,    41,    42,    43,   156,
      45,   151,   152,   153,    49,   153,    51,    57,    56,   152,
     153,    61,   156,    61,    58,   280,   166,   261,    63,    64,
      65,    66,   287,   166,    64,    36,    55,   171,    54,   273,
      59,   181,    56,    59,    63,    19,    81,    61,    49,    50,
      51,    52,    53,    57,    57,    55,    55,    61,    61,   293,
      57,    63,    57,   234,    99,   100,    61,   102,   103,   303,
     105,    57,   306,    59,    57,   110,    59,     3,     4,    59,
       6,   315,    63,     3,   318,   225,    12,    13,     8,     9,
      10,    11,   225,     3,   129,    28,    54,    23,    24,    25,
      54,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    58,   350,   351,     3,   353,
       3,     4,    59,    49,    50,     8,     9,    10,    11,    55,
       3,    56,   167,   168,   274,   170,    64,   172,    64,    58,
      54,    58,    58,    54,     3,   379,    36,    59,   288,   184,
     290,    57,   187,     3,    57,   288,   296,   290,   296,    57,
     300,   196,     3,   296,   296,    15,    34,   300,    18,    58,
      28,    21,    33,    23,    24,    54,     3,   317,    28,   317,
      54,     3,    32,    60,   317,   317,    55,    58,    58,    41,
      42,    43,    44,    45,    46,    61,    58,    57,     3,    19,
     235,   236,    54,    55,    57,   345,    57,    59,   348,    57,
     348,    63,   345,    57,    64,   348,   348,   357,   253,    58,
      60,   361,    60,   361,   357,    57,     3,    58,   361,   361,
      58,    57,   372,    57,   374,    35,   374,    58,    57,   372,
      57,   374,   374,    58,     4,    58,   281,     3,     4,    58,
       6,     7,    60,    57,   289,    58,    12,    13,   297,    58,
      42,    43,    44,    45,    46,    58,   228,    23,    24,    25,
       3,     4,    54,     6,     7,    16,    34,    59,   225,    12,
      13,    63,   129,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    49,    50,    -1,    -1,   332,    -1,    55,
      -1,    -1,    -1,     3,     4,    -1,     6,    -1,    64,    -1,
      -1,    -1,    12,    13,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    55,    23,    24,    25,     3,     4,    -1,     6,
      -1,    64,    -1,    -1,    -1,    12,    13,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    23,    24,    25,    49,
      50,    -1,    54,    55,    -1,    55,    -1,    59,    -1,    -1,
      60,    63,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,     3,     4,    55,     6,
       7,    -1,    -1,    60,    -1,    12,    13,    64,     3,    -1,
      -1,    -1,     3,     4,    -1,     6,    23,    24,    25,    14,
      15,    12,    13,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    -1,    23,    24,    25,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,     3,     4,    55,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    64,    49,    50,
      -1,    -1,     3,     4,    55,     6,    23,    24,    25,    64,
      -1,    12,    13,    64,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    14,    15,    -1,
      -1,    18,    49,    50,    21,    -1,    23,    24,    55,    -1,
      -1,    28,    -1,    -1,     3,    32,    33,    64,    49,    50,
      -1,    -1,    -1,    -1,    55,    14,    15,    16,    17,    18,
       3,    -1,    21,    64,    23,    24,    -1,    -1,    -1,    -1,
      -1,    14,    15,    32,    -1,    18,    -1,    64,    21,    -1,
      23,    24,     3,    -1,    -1,    28,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    14,    15,    -1,    -1,    18,     3,    -1,
      21,    -1,    23,    24,    -1,    64,    -1,    -1,    29,    14,
      15,    32,    -1,    18,    -1,    -1,    21,     3,    23,    24,
      -1,    64,    -1,    -1,    29,    -1,    -1,    32,    14,    15,
      -1,    17,    18,    -1,    -1,    21,     3,    23,    24,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    32,    14,    15,    -1,
      -1,    18,     3,    -1,    21,    -1,    23,    24,    -1,    64,
      -1,    -1,    29,    14,    15,    32,    -1,    18,    -1,    20,
      21,    -1,    23,    24,     3,    -1,    -1,    -1,    64,    -1,
      -1,    32,    -1,    -1,    -1,    14,    15,     3,    -1,    18,
      -1,    -1,    21,    -1,    23,    24,    -1,    64,    14,    15,
      29,    -1,    18,    32,    20,    21,    -1,    23,    24,    -1,
       3,    -1,    -1,    64,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    14,    15,    -1,    -1,    18,     3,    -1,    21,    -1,
      23,    24,    -1,    -1,    -1,    64,    29,    -1,    15,    32,
      -1,    18,    -1,    18,    21,    -1,    23,    24,    64,    -1,
      -1,    26,    27,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    26,
      27,    64,    47,    48,    49,    50,    51,    52,    53,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    64,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    26,    27,    -1,
      57,    -1,    -1,    60,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    26,    27,    -1,    47,    48,
      49,    50,    51,    52,    53,    36,    37,    38,    39,    40,
      -1,    60,    -1,    26,    27,    -1,    47,    48,    49,    50,
      51,    52,    53,    36,    37,    38,    39,    40,    -1,    60,
      -1,    26,    27,    -1,    47,    48,    49,    50,    51,    52,
      53,    36,    37,    38,    39,    40,    -1,    60,    -1,    -1,
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
      51,    52,    53,    26,    27,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    26,    27,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    26,
      27,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    26,    27,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    26,    27,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    26,    27,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    14,    15,    18,    21,    23,    24,    28,    32,
      33,    64,    66,    67,    68,    76,    79,    80,    81,    82,
      83,    85,    89,    90,    91,    93,    94,    95,    96,    98,
      99,   100,   103,   104,   113,    41,    42,    43,    44,    45,
      46,    54,    55,    59,    63,    92,     3,    86,    87,    55,
       3,    55,    58,    58,     3,    31,     3,     4,     6,    12,
      13,    23,    24,    25,    49,    50,    55,    58,    75,    76,
      77,    78,   101,   113,   114,   115,     3,     3,     0,    68,
     103,    54,    63,    67,    80,    89,    58,    57,    61,    84,
       3,    76,    90,     3,    67,    76,    79,   104,   113,    54,
      59,    63,    92,    59,     7,    49,    73,    78,     3,     7,
      49,    78,   102,    60,    78,     3,   101,   113,    78,    54,
      58,    57,    61,    88,    78,    19,    78,    55,    55,    55,
      63,    78,    78,    78,    78,    63,    26,    27,    36,    37,
      38,    39,    40,    47,    48,    49,    50,    51,    52,    53,
      58,    63,    57,    79,    78,   101,    67,     3,     8,     9,
      10,    11,    74,     3,    76,    57,    61,    54,    54,    54,
      54,    67,    49,    78,    60,    78,   101,    78,    78,    78,
      58,    63,    78,    56,    61,    60,    58,    54,    58,    73,
      78,    74,     3,    57,    61,    56,    59,    56,     3,    69,
      70,    56,   102,   101,    56,   113,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
     113,     3,    28,    76,   105,   106,   107,   108,   109,   111,
     112,   113,    58,    58,   103,    54,    54,    74,     3,    76,
      78,    78,    78,    78,    58,    60,    58,    58,    18,    58,
     113,    58,    78,    49,    78,    54,    74,     3,    57,    78,
      57,    57,    59,    56,    61,    71,    57,    56,     3,    34,
     107,   111,    58,    57,    61,    88,   110,   112,    78,    78,
      54,    54,    58,     3,    78,    58,    73,    54,    97,    57,
      97,    74,    60,    30,    57,     3,    72,    55,    58,    74,
      64,   113,    61,    57,    73,    78,    57,    58,    73,    16,
      17,    80,    90,    78,    22,    57,    74,    72,    57,    59,
      29,    80,    90,    69,     3,    76,    64,    74,     4,    74,
      57,    58,    57,    60,    58,    74,    57,    29,    74,    60,
      58,    56,     3,    60,    19,    97,    78,    57,    72,    58,
      57,    30,    57,    57,     3,    17,    60,    97,    29,    74,
      74,    72,    74,    35,    58,    57,    20,    58,    57,    29,
      58,     4,    97,    58,    72,    58,    60,    20,    29,    57,
      58,    58,    74,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    86,    86,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    93,
      94,    95,    95,    96,    96,    97,    97,    97,    98,    99,
      99,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   105,   105,   105,   106,
     106,   107,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   114,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     1,     1,     1,     3,
       3,     2,     1,     8,    11,     9,     2,     1,     3,     5,
       0,     4,     6,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     4,     3,     3,     1,     1,     3,     5,
       3,     5,     3,     4,     2,     4,     2,     3,     4,     3,
       3,     5,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     6,     7,     4,     4,     5,
       4,     4,    12,    16,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     8,    11,     2,     2,     0,     8,    12,
      14,     5,     4,     4,     4,     4,     3,     3,     1,     2,
       3,     1,     0,     2,     1,     6,     2,     1,     1,     2,
       1,     2,     4,     3,     1,     1,     4,     2,     3,     2,
       1,    11,     9,     2,     3,     3,     1
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
#line 1704 "myanalyzer.tab.c"
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
#line 1724 "myanalyzer.tab.c"
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
#line 1742 "myanalyzer.tab.c"
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
#line 1761 "myanalyzer.tab.c"
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
#line 1779 "myanalyzer.tab.c"
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
#line 1797 "myanalyzer.tab.c"
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
#line 1815 "myanalyzer.tab.c"
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
#line 1835 "myanalyzer.tab.c"
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
#line 1855 "myanalyzer.tab.c"
    break;

  case 11: /* function_list: function_list function  */
#line 271 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1861 "myanalyzer.tab.c"
    break;

  case 13: /* function: KW_FUN KW_MAIN '(' ')' ':' function_body KW_NUF ';'  */
#line 277 "myanalyzer.y"
                { (yyval.str) = template("int main () {\n%s\n}", (yyvsp[-2].str)); }
#line 1867 "myanalyzer.tab.c"
    break;

  case 14: /* function: KW_FUN TK_IDENT '(' function_argument_list ')' KW_ARROW_FUNCTION data_type ':' function_body KW_NUF ';'  */
#line 279 "myanalyzer.y"
                { (yyval.str) = template("%s %s(%s) {\n%s\n}", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str)); }
#line 1873 "myanalyzer.tab.c"
    break;

  case 15: /* function: KW_FUN TK_IDENT '(' function_argument_list ')' ':' function_body KW_NUF ';'  */
#line 281 "myanalyzer.y"
                { (yyval.str) = template("void %s(%s) {\n%s\n}", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 1879 "myanalyzer.tab.c"
    break;

  case 16: /* function_argument_list: function_argument_list multiple_argument_function  */
#line 287 "myanalyzer.y"
                                                                { (yyval.str) = template("%s %s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1885 "myanalyzer.tab.c"
    break;

  case 17: /* function_argument_list: single_argument_function  */
#line 288 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 1891 "myanalyzer.tab.c"
    break;

  case 18: /* single_argument_function: TK_IDENT ':' data_type  */
#line 292 "myanalyzer.y"
                                                        { (yyval.str) = template("%s %s", (yyvsp[0].str),(yyvsp[-2].str)); }
#line 1897 "myanalyzer.tab.c"
    break;

  case 19: /* single_argument_function: TK_IDENT '[' ']' ':' data_type  */
#line 293 "myanalyzer.y"
                                                { (yyval.str) = template("%s *%s", (yyvsp[0].str),(yyvsp[-4].str));}
#line 1903 "myanalyzer.tab.c"
    break;

  case 20: /* single_argument_function: %empty  */
#line 294 "myanalyzer.y"
                                                                        { (yyval.str) = ""; }
#line 1909 "myanalyzer.tab.c"
    break;

  case 21: /* multiple_argument_function: ',' TK_IDENT ':' data_type  */
#line 298 "myanalyzer.y"
                                                        { (yyval.str) = template(",%s %s", (yyvsp[0].str),(yyvsp[-2].str)); }
#line 1915 "myanalyzer.tab.c"
    break;

  case 22: /* multiple_argument_function: ',' TK_IDENT '[' ']' ':' data_type  */
#line 299 "myanalyzer.y"
                                                { (yyval.str) = template(",%s *%s", (yyvsp[0].str),(yyvsp[-4].str)); }
#line 1921 "myanalyzer.tab.c"
    break;

  case 23: /* function_body: function_body declaration  */
#line 303 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1927 "myanalyzer.tab.c"
    break;

  case 24: /* function_body: function_body statement  */
#line 304 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1933 "myanalyzer.tab.c"
    break;

  case 25: /* function_body: %empty  */
#line 305 "myanalyzer.y"
                                                        { (yyval.str) = ""; }
#line 1939 "myanalyzer.tab.c"
    break;

  case 26: /* data: expr  */
#line 311 "myanalyzer.y"
                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1945 "myanalyzer.tab.c"
    break;

  case 27: /* data: TK_STRING  */
#line 312 "myanalyzer.y"
                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1951 "myanalyzer.tab.c"
    break;

  case 28: /* data_type: KW_INT  */
#line 316 "myanalyzer.y"
                                { (yyval.str) = "int"; }
#line 1957 "myanalyzer.tab.c"
    break;

  case 29: /* data_type: KW_REAL  */
#line 317 "myanalyzer.y"
                                { (yyval.str) = "double"; }
#line 1963 "myanalyzer.tab.c"
    break;

  case 30: /* data_type: KW_TEXT  */
#line 318 "myanalyzer.y"
                                { (yyval.str) = "char*"; }
#line 1969 "myanalyzer.tab.c"
    break;

  case 31: /* data_type: KW_BOOL  */
#line 319 "myanalyzer.y"
                                { (yyval.str) = "int"; }
#line 1975 "myanalyzer.tab.c"
    break;

  case 32: /* data_type: TK_IDENT  */
#line 320 "myanalyzer.y"
                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1981 "myanalyzer.tab.c"
    break;

  case 33: /* boolean_value: KW_TRUE  */
#line 324 "myanalyzer.y"
                                { (yyval.str) = "1"; }
#line 1987 "myanalyzer.tab.c"
    break;

  case 34: /* boolean_value: KW_FALSE  */
#line 325 "myanalyzer.y"
                                { (yyval.str) = "0"; }
#line 1993 "myanalyzer.tab.c"
    break;

  case 35: /* array_value: TK_IDENT '[' expr ']'  */
#line 329 "myanalyzer.y"
                                                        { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1999 "myanalyzer.tab.c"
    break;

  case 36: /* array_value: TK_IDENT '[' ']'  */
#line 330 "myanalyzer.y"
                                                                { (yyval.str) = template("%s*", (yyvsp[-2].str)); }
#line 2005 "myanalyzer.tab.c"
    break;

  case 37: /* array_value: comp_variable '[' ']'  */
#line 331 "myanalyzer.y"
                                                        { (yyval.str) = template("self->%s[]", (yyvsp[-2].str)); }
#line 2011 "myanalyzer.tab.c"
    break;

  case 38: /* array_value: comp_variable '[' expr ']'  */
#line 332 "myanalyzer.y"
                                                { (yyval.str) = template("self->%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2017 "myanalyzer.tab.c"
    break;

  case 39: /* expr_data_type: TK_IDENT  */
#line 336 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2023 "myanalyzer.tab.c"
    break;

  case 40: /* expr_data_type: TK_NUMBER  */
#line 337 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2029 "myanalyzer.tab.c"
    break;

  case 41: /* expr_data_type: TK_REAL  */
#line 338 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2035 "myanalyzer.tab.c"
    break;

  case 42: /* expr_data_type: array_value  */
#line 339 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2041 "myanalyzer.tab.c"
    break;

  case 43: /* expr_data_type: boolean_value  */
#line 340 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2047 "myanalyzer.tab.c"
    break;

  case 44: /* expr_data_type: comp_variable  */
#line 341 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2053 "myanalyzer.tab.c"
    break;

  case 46: /* expr: '(' expr ')'  */
#line 346 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[-1].str)); }
#line 2059 "myanalyzer.tab.c"
    break;

  case 47: /* expr: expr '+' expr  */
#line 347 "myanalyzer.y"
                                        { (yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2065 "myanalyzer.tab.c"
    break;

  case 48: /* expr: expr '-' expr  */
#line 348 "myanalyzer.y"
                                        { (yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2071 "myanalyzer.tab.c"
    break;

  case 49: /* expr: '-' expr  */
#line 349 "myanalyzer.y"
                                { (yyval.str) = template("(-%s)", (yyvsp[0].str)); }
#line 2077 "myanalyzer.tab.c"
    break;

  case 50: /* expr: '+' expr  */
#line 350 "myanalyzer.y"
                            { (yyval.str) = (yyvsp[0].str); }
#line 2083 "myanalyzer.tab.c"
    break;

  case 51: /* expr: expr '*' expr  */
#line 351 "myanalyzer.y"
                                        { (yyval.str) = template("%s * %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2089 "myanalyzer.tab.c"
    break;

  case 52: /* expr: expr '/' expr  */
#line 352 "myanalyzer.y"
                                        { (yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2095 "myanalyzer.tab.c"
    break;

  case 53: /* expr: expr '%' expr  */
#line 353 "myanalyzer.y"
                                        { (yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2101 "myanalyzer.tab.c"
    break;

  case 54: /* expr: expr KW_POW expr  */
#line 354 "myanalyzer.y"
                                        { (yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2107 "myanalyzer.tab.c"
    break;

  case 55: /* expr: expr KW_EQ expr  */
#line 355 "myanalyzer.y"
                                        { (yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2113 "myanalyzer.tab.c"
    break;

  case 56: /* expr: expr KW_NOTEQ expr  */
#line 356 "myanalyzer.y"
                                { (yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2119 "myanalyzer.tab.c"
    break;

  case 57: /* expr: expr '<' expr  */
#line 357 "myanalyzer.y"
                                        { (yyval.str) = template("%s < %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2125 "myanalyzer.tab.c"
    break;

  case 58: /* expr: expr KW_LESSEQ expr  */
#line 358 "myanalyzer.y"
                                { (yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2131 "myanalyzer.tab.c"
    break;

  case 59: /* expr: expr '>' expr  */
#line 359 "myanalyzer.y"
                                        { (yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2137 "myanalyzer.tab.c"
    break;

  case 60: /* expr: expr KW_GREATEREQ expr  */
#line 360 "myanalyzer.y"
                                { (yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2143 "myanalyzer.tab.c"
    break;

  case 61: /* expr: expr KW_AND expr  */
#line 361 "myanalyzer.y"
                                        { (yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2149 "myanalyzer.tab.c"
    break;

  case 62: /* expr: expr KW_OR expr  */
#line 362 "myanalyzer.y"
                                        { (yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2155 "myanalyzer.tab.c"
    break;

  case 63: /* expr: KW_NOT expr  */
#line 363 "myanalyzer.y"
                                { (yyval.str) = template("!%s", (yyvsp[0].str)); }
#line 2161 "myanalyzer.tab.c"
    break;

  case 64: /* expr: KW_BREAK  */
#line 364 "myanalyzer.y"
                                                { (yyval.str) = template("break"); }
#line 2167 "myanalyzer.tab.c"
    break;

  case 65: /* expr: KW_CONTINUE  */
#line 365 "myanalyzer.y"
                                        { (yyval.str) = template("continue"); }
#line 2173 "myanalyzer.tab.c"
    break;

  case 66: /* expr: expr_function  */
#line 366 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2179 "myanalyzer.tab.c"
    break;

  case 67: /* expr: comp_values  */
#line 367 "myanalyzer.y"
                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2185 "myanalyzer.tab.c"
    break;

  case 68: /* declaration_list: declaration_list declaration  */
#line 371 "myanalyzer.y"
                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2191 "myanalyzer.tab.c"
    break;

  case 69: /* declaration_list: declaration  */
#line 372 "myanalyzer.y"
                                                        { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 2197 "myanalyzer.tab.c"
    break;

  case 70: /* declaration: variable_declaration  */
#line 376 "myanalyzer.y"
                                                { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2203 "myanalyzer.tab.c"
    break;

  case 71: /* declaration: const_variable_declaration  */
#line 377 "myanalyzer.y"
                                        { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2209 "myanalyzer.tab.c"
    break;

  case 72: /* variable_declaration: variable_assign_declaration ';'  */
#line 383 "myanalyzer.y"
                                        { (yyval.str) = template("%s;",(yyvsp[-1].str)); }
#line 2215 "myanalyzer.tab.c"
    break;

  case 73: /* variable_assign_declaration: single_variable_declaration multiple_variable_declaration ':' data_type  */
#line 387 "myanalyzer.y"
                                                                               { {(yyval.str) = template("%s %s %s",(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-2].str));} }
#line 2221 "myanalyzer.tab.c"
    break;

  case 74: /* variable_assign_declaration: single_variable_declaration ':' data_type  */
#line 388 "myanalyzer.y"
                                                    { (yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str)); }
#line 2227 "myanalyzer.tab.c"
    break;

  case 75: /* single_variable_declaration: TK_IDENT '=' data  */
#line 392 "myanalyzer.y"
                                                { (yyval.str) = template("%s = %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2233 "myanalyzer.tab.c"
    break;

  case 76: /* single_variable_declaration: TK_IDENT  */
#line 393 "myanalyzer.y"
                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2239 "myanalyzer.tab.c"
    break;

  case 77: /* single_variable_declaration: array_value  */
#line 394 "myanalyzer.y"
                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2245 "myanalyzer.tab.c"
    break;

  case 78: /* single_variable_declaration: array_value '=' expr  */
#line 395 "myanalyzer.y"
                                        { (yyval.str) = template("%s = %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2251 "myanalyzer.tab.c"
    break;

  case 79: /* multiple_variable_declaration: multiple_variable_declaration ',' TK_IDENT '=' data  */
#line 399 "myanalyzer.y"
                                                            { (yyval.str) = template("%s, %s = %s",(yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));}
#line 2257 "myanalyzer.tab.c"
    break;

  case 80: /* multiple_variable_declaration: multiple_variable_declaration ',' TK_IDENT  */
#line 400 "myanalyzer.y"
                                                     { (yyval.str) = template("%s, %s ",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2263 "myanalyzer.tab.c"
    break;

  case 81: /* multiple_variable_declaration: multiple_variable_declaration ',' array_value '=' expr  */
#line 401 "myanalyzer.y"
                                                                 {{(yyval.str) = template("%s, %s = %s",(yyvsp[-4].str),(yyvsp[-2].str), (yyvsp[0].str));}}
#line 2269 "myanalyzer.tab.c"
    break;

  case 82: /* multiple_variable_declaration: multiple_variable_declaration ',' array_value  */
#line 402 "myanalyzer.y"
                                                        { (yyval.str) = template("%s, %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2275 "myanalyzer.tab.c"
    break;

  case 83: /* multiple_variable_declaration: ',' TK_IDENT '=' expr  */
#line 403 "myanalyzer.y"
                                                                                { (yyval.str) = template(", %s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2281 "myanalyzer.tab.c"
    break;

  case 84: /* multiple_variable_declaration: ',' TK_IDENT  */
#line 404 "myanalyzer.y"
                                                                                        { (yyval.str) = template(", %s ",(yyvsp[0].str));}
#line 2287 "myanalyzer.tab.c"
    break;

  case 85: /* multiple_variable_declaration: ',' array_value '=' expr  */
#line 405 "myanalyzer.y"
                                                                                { (yyval.str) = template(", %s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2293 "myanalyzer.tab.c"
    break;

  case 86: /* multiple_variable_declaration: ',' array_value  */
#line 406 "myanalyzer.y"
                                                                                        { (yyval.str) = template(", %s ",(yyvsp[0].str));}
#line 2299 "myanalyzer.tab.c"
    break;

  case 87: /* const_variable_declaration: KW_CONST const_variable_assign_declaration ';'  */
#line 412 "myanalyzer.y"
                                                       { (yyval.str) = template("const %s;",(yyvsp[-1].str)); }
#line 2305 "myanalyzer.tab.c"
    break;

  case 88: /* const_variable_assign_declaration: single_const_variable_declaration multiple_const_variable_declaration ':' data_type  */
#line 416 "myanalyzer.y"
                                                                                            { {(yyval.str) = template("%s %s %s",(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-2].str));} }
#line 2311 "myanalyzer.tab.c"
    break;

  case 89: /* const_variable_assign_declaration: single_const_variable_declaration ':' data_type  */
#line 417 "myanalyzer.y"
                                                          { (yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2317 "myanalyzer.tab.c"
    break;

  case 90: /* single_const_variable_declaration: TK_IDENT '=' data  */
#line 421 "myanalyzer.y"
                          { (yyval.str) = template("%s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2323 "myanalyzer.tab.c"
    break;

  case 91: /* multiple_const_variable_declaration: multiple_const_variable_declaration ',' TK_IDENT '=' data  */
#line 425 "myanalyzer.y"
                                                                  { (yyval.str) = template("%s, %s = %s",(yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));}
#line 2329 "myanalyzer.tab.c"
    break;

  case 92: /* multiple_const_variable_declaration: ',' TK_IDENT '=' data  */
#line 426 "myanalyzer.y"
                                { (yyval.str) = template(", %s = %s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2335 "myanalyzer.tab.c"
    break;

  case 93: /* statement_list: statement_list statement  */
#line 432 "myanalyzer.y"
                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2341 "myanalyzer.tab.c"
    break;

  case 94: /* statement_list: statement  */
#line 433 "myanalyzer.y"
                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2347 "myanalyzer.tab.c"
    break;

  case 95: /* statement: assign_statement  */
#line 437 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2353 "myanalyzer.tab.c"
    break;

  case 96: /* statement: break_statement  */
#line 438 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2359 "myanalyzer.tab.c"
    break;

  case 97: /* statement: continue_statement  */
#line 439 "myanalyzer.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 2365 "myanalyzer.tab.c"
    break;

  case 98: /* statement: return_statement  */
#line 440 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2371 "myanalyzer.tab.c"
    break;

  case 99: /* statement: if_statement  */
#line 441 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2377 "myanalyzer.tab.c"
    break;

  case 100: /* statement: while_statement  */
#line 442 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2383 "myanalyzer.tab.c"
    break;

  case 101: /* statement: for_statement  */
#line 443 "myanalyzer.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 2389 "myanalyzer.tab.c"
    break;

  case 102: /* statement: function_statement  */
#line 444 "myanalyzer.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 2395 "myanalyzer.tab.c"
    break;

  case 103: /* assign_statement: TK_IDENT '=' expr ';'  */
#line 448 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2401 "myanalyzer.tab.c"
    break;

  case 104: /* assign_statement: TK_IDENT '=' '-' expr ';'  */
#line 449 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s = -%s;", (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2407 "myanalyzer.tab.c"
    break;

  case 105: /* assign_statement: TK_IDENT '.' comp_variable '=' expr ';'  */
#line 450 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s.%s = %s;", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2413 "myanalyzer.tab.c"
    break;

  case 106: /* assign_statement: TK_IDENT '.' comp_variable '=' '-' expr ';'  */
#line 451 "myanalyzer.y"
                                                                { (yyval.str) = template("%s.%s = -%s;", (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2419 "myanalyzer.tab.c"
    break;

  case 107: /* assign_statement: array_value '=' expr ';'  */
#line 452 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2425 "myanalyzer.tab.c"
    break;

  case 108: /* assign_statement: comp_variable '=' expr ';'  */
#line 453 "myanalyzer.y"
                                                                                { (yyval.str) = template("self->%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2431 "myanalyzer.tab.c"
    break;

  case 109: /* assign_statement: comp_variable '=' '-' expr ';'  */
#line 454 "myanalyzer.y"
                                                                                { (yyval.str) = template("self->%s = -self->%s;", (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 2437 "myanalyzer.tab.c"
    break;

  case 110: /* assign_statement: TK_IDENT assign_operator expr ';'  */
#line 455 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s %s %s;", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2443 "myanalyzer.tab.c"
    break;

  case 111: /* assign_statement: comp_variable assign_operator expr ';'  */
#line 456 "myanalyzer.y"
                                                                        { (yyval.str) = template("self->%s %s %s;", (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str)); }
#line 2449 "myanalyzer.tab.c"
    break;

  case 112: /* assign_statement: TK_IDENT KW_COLONEQ '[' expr KW_FOR TK_IDENT ':' TK_NUMBER ']' ':' data_type ';'  */
#line 459 "myanalyzer.y"
                { (yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s=0; %s < %s; ++%s){\n%s[%s] = %s;\n}",
		                (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str)); }
#line 2456 "myanalyzer.tab.c"
    break;

  case 113: /* assign_statement: TK_IDENT KW_COLONEQ '[' expr KW_FOR TK_IDENT ':' data_type KW_IN TK_IDENT KW_OF TK_NUMBER ']' ':' data_type ';'  */
#line 463 "myanalyzer.y"
                {
			char* res = (char *)malloc(strlen((yyvsp[-6].str)) + 16);
			sprintf(res, "%s[%s_i]", (yyvsp[-6].str), (yyvsp[-6].str));
			char* final_char = replaceSubstring((yyvsp[-12].str), (yyvsp[-10].str), res);
			free(res);
			(yyval.str) = template("%s* %s = (%s*)malloc(%s * sizeof(%s));\nfor (int %s_i=0; %s_i < %s; ++%s_i){\n%s[%s_i] = %s;\n}",
			             (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-15].str), (yyvsp[-6].str), final_char);
		}
#line 2469 "myanalyzer.tab.c"
    break;

  case 114: /* assign_operator: KW_INCR  */
#line 474 "myanalyzer.y"
                                                { (yyval.str) = template("+="); }
#line 2475 "myanalyzer.tab.c"
    break;

  case 115: /* assign_operator: KW_DECR  */
#line 475 "myanalyzer.y"
                                                { (yyval.str) = template("-="); }
#line 2481 "myanalyzer.tab.c"
    break;

  case 116: /* assign_operator: KW_TIMES_INCR  */
#line 476 "myanalyzer.y"
                                        { (yyval.str) = template("*="); }
#line 2487 "myanalyzer.tab.c"
    break;

  case 117: /* assign_operator: KW_DIV_DECR  */
#line 477 "myanalyzer.y"
                                        { (yyval.str) = template("/="); }
#line 2493 "myanalyzer.tab.c"
    break;

  case 118: /* assign_operator: KW_MOD_DECR  */
#line 478 "myanalyzer.y"
                                        { (yyval.str) = template("%="); }
#line 2499 "myanalyzer.tab.c"
    break;

  case 119: /* break_statement: KW_BREAK ';'  */
#line 482 "myanalyzer.y"
                                                { (yyval.str) = "break; "; }
#line 2505 "myanalyzer.tab.c"
    break;

  case 120: /* continue_statement: KW_CONTINUE ';'  */
#line 486 "myanalyzer.y"
                                                { (yyval.str) = "continue; "; }
#line 2511 "myanalyzer.tab.c"
    break;

  case 121: /* return_statement: KW_RETURN ';'  */
#line 490 "myanalyzer.y"
                                                { (yyval.str) = "return;"; }
#line 2517 "myanalyzer.tab.c"
    break;

  case 122: /* return_statement: KW_RETURN expr ';'  */
#line 491 "myanalyzer.y"
                                        { (yyval.str) = template("return %s;", (yyvsp[-1].str)); }
#line 2523 "myanalyzer.tab.c"
    break;

  case 123: /* if_statement: KW_IF '(' expr ')' ':' if_for_while_body KW_FI ';'  */
#line 496 "myanalyzer.y"
                { (yyval.str) = template("if (%s) {\n%s\n}",(yyvsp[-5].str),(yyvsp[-2].str)); }
#line 2529 "myanalyzer.tab.c"
    break;

  case 124: /* if_statement: KW_IF '(' expr ')' ':' if_for_while_body KW_ELSE ':' if_for_while_body KW_FI ';'  */
#line 498 "myanalyzer.y"
                { (yyval.str) = template("if (%s) {\n%s\n} else {\n%s\n}",(yyvsp[-8].str),(yyvsp[-5].str),(yyvsp[-2].str)); }
#line 2535 "myanalyzer.tab.c"
    break;

  case 125: /* if_for_while_body: if_for_while_body declaration  */
#line 502 "myanalyzer.y"
                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2541 "myanalyzer.tab.c"
    break;

  case 126: /* if_for_while_body: if_for_while_body statement  */
#line 503 "myanalyzer.y"
                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2547 "myanalyzer.tab.c"
    break;

  case 127: /* if_for_while_body: %empty  */
#line 504 "myanalyzer.y"
                                                                        { (yyval.str) = ""; }
#line 2553 "myanalyzer.tab.c"
    break;

  case 128: /* while_statement: KW_WHILE '(' expr ')' ':' if_for_while_body KW_OD ';'  */
#line 509 "myanalyzer.y"
                { (yyval.str) = template("while(%s) {\n%s\n} ",(yyvsp[-5].str),(yyvsp[-2].str)); }
#line 2559 "myanalyzer.tab.c"
    break;

  case 129: /* for_statement: KW_FOR TK_IDENT KW_IN '[' expr ':' expr ']' ':' if_for_while_body KW_ROF ';'  */
#line 514 "myanalyzer.y"
                { (yyval.str) = template("for (int %s = %s; %s <= %s; %s++) {\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str)); }
#line 2565 "myanalyzer.tab.c"
    break;

  case 130: /* for_statement: KW_FOR TK_IDENT KW_IN '[' expr ':' expr ':' expr ']' ':' if_for_while_body KW_ROF ';'  */
#line 516 "myanalyzer.y"
                {
			step_value = atoi((yyvsp[-5].str));
			if (step_value > 0) {
				(yyval.str) = template("for (int %s = %s; %s <= %s; %s+=%s) {\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str)); 
			} else if (step_value == -1) { 
				(yyval.str) = template("for (int %s = %s; %s >= %s; --%s) {\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-2].str)); 
			} else {
				(yyval.str) = template("for (int %s = %s; %s < %s; %s-=%s) {\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-5].str)+1, (yyvsp[-2].str));
			}
		}
#line 2580 "myanalyzer.tab.c"
    break;

  case 131: /* function_statement: TK_IDENT '(' function_parameter_list ')' ';'  */
#line 529 "myanalyzer.y"
                                                     { (yyval.str) = template("%s(%s);", (yyvsp[-4].str), (yyvsp[-2].str)); }
#line 2586 "myanalyzer.tab.c"
    break;

  case 132: /* function_statement: TK_IDENT '.' expr_function ';'  */
#line 530 "myanalyzer.y"
                                                                 { (yyval.str) = template("%s.%s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2592 "myanalyzer.tab.c"
    break;

  case 133: /* function_statement: comp_variable '.' expr_function ';'  */
#line 531 "myanalyzer.y"
                                                         { (yyval.str) = template("%s.%s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2598 "myanalyzer.tab.c"
    break;

  case 134: /* function_statement: array_value '.' expr_function ';'  */
#line 532 "myanalyzer.y"
                                                         { (yyval.str) = template("%s.%s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2604 "myanalyzer.tab.c"
    break;

  case 135: /* expr_function: TK_IDENT '(' function_parameter_list ')'  */
#line 536 "myanalyzer.y"
                                                        { (yyval.str) = template("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2610 "myanalyzer.tab.c"
    break;

  case 136: /* expr_function: TK_IDENT '.' expr_function  */
#line 537 "myanalyzer.y"
                                                                { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2616 "myanalyzer.tab.c"
    break;

  case 137: /* function_parameter_list: function_parameter_list ',' expr  */
#line 541 "myanalyzer.y"
                                                        { (yyval.str) = template("%s,%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2622 "myanalyzer.tab.c"
    break;

  case 138: /* function_parameter_list: expr  */
#line 542 "myanalyzer.y"
                                                                                { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 2628 "myanalyzer.tab.c"
    break;

  case 139: /* function_parameter_list: '-' expr  */
#line 543 "myanalyzer.y"
                                                                                { (yyval.str) = template("-%s", (yyvsp[0].str));  }
#line 2634 "myanalyzer.tab.c"
    break;

  case 140: /* function_parameter_list: TK_IDENT '.' comp_variable  */
#line 544 "myanalyzer.y"
                                                        { (yyval.str) = template("%s.%s", (yyvsp[-2].str),(yyvsp[0].str)); }
#line 2640 "myanalyzer.tab.c"
    break;

  case 141: /* function_parameter_list: TK_STRING  */
#line 545 "myanalyzer.y"
                                                                                { (yyval.str) = template("%s", (yyvsp[0].str));  }
#line 2646 "myanalyzer.tab.c"
    break;

  case 142: /* function_parameter_list: %empty  */
#line 546 "myanalyzer.y"
                                                                                { (yyval.str) = ""; }
#line 2652 "myanalyzer.tab.c"
    break;

  case 143: /* comp_list: comp_list comp  */
#line 552 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2658 "myanalyzer.tab.c"
    break;

  case 145: /* comp: KW_RECORD TK_IDENT ':' comp_body KW_DROCER ';'  */
#line 558 "myanalyzer.y"
                {  (yyval.str) = template("#define SELF struct %s *self \ntypedef struct %s {\n%s\n} %s ;\n\n%s\n#undef SELF\n",
		                 (yyvsp[-4].str), (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str), deff); }
#line 2665 "myanalyzer.tab.c"
    break;

  case 146: /* comp_body: comp_variable_declaration_list comp_func_list  */
#line 563 "myanalyzer.y"
                                                        { (yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str)); }
#line 2671 "myanalyzer.tab.c"
    break;

  case 147: /* comp_body: comp_variable_declaration_list  */
#line 564 "myanalyzer.y"
                                                                        { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2677 "myanalyzer.tab.c"
    break;

  case 148: /* comp_body: comp_func_list  */
#line 565 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s",(yyvsp[0].str)); }
#line 2683 "myanalyzer.tab.c"
    break;

  case 149: /* comp_variable_declaration_list: comp_variable_declaration_list comp_variable_declaration  */
#line 569 "myanalyzer.y"
                                                                 { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2689 "myanalyzer.tab.c"
    break;

  case 151: /* comp_variable_declaration: comp_variable_assign_declaration ';'  */
#line 574 "myanalyzer.y"
                                                { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 2695 "myanalyzer.tab.c"
    break;

  case 152: /* comp_variable_assign_declaration: single_comp_variable_declaration multiple_comp_variable_declaration ':' data_type  */
#line 578 "myanalyzer.y"
                                                                                          { {(yyval.str) = template("%s %s %s",(yyvsp[0].str),(yyvsp[-3].str),(yyvsp[-2].str));} }
#line 2701 "myanalyzer.tab.c"
    break;

  case 153: /* comp_variable_assign_declaration: single_comp_variable_declaration ':' data_type  */
#line 579 "myanalyzer.y"
                                                         { (yyval.str) = template("%s %s",(yyvsp[0].str),(yyvsp[-2].str));}
#line 2707 "myanalyzer.tab.c"
    break;

  case 154: /* single_comp_variable_declaration: comp_variable  */
#line 583 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2713 "myanalyzer.tab.c"
    break;

  case 155: /* single_comp_variable_declaration: array_value  */
#line 584 "myanalyzer.y"
                                                                                        { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2719 "myanalyzer.tab.c"
    break;

  case 156: /* multiple_comp_variable_declaration: multiple_const_variable_declaration ',' '#' TK_IDENT  */
#line 588 "myanalyzer.y"
                                                                { (yyval.str) = template("%s, %s",(yyvsp[-3].str),(yyvsp[0].str)); }
#line 2725 "myanalyzer.tab.c"
    break;

  case 157: /* multiple_comp_variable_declaration: ',' comp_variable  */
#line 589 "myanalyzer.y"
                                                                                                { (yyval.str) = template(", %s",(yyvsp[0].str)); }
#line 2731 "myanalyzer.tab.c"
    break;

  case 158: /* multiple_comp_variable_declaration: ',' '#' array_value  */
#line 590 "myanalyzer.y"
                                                                                                { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 2737 "myanalyzer.tab.c"
    break;

  case 159: /* comp_func_list: comp_func_list comp_func  */
#line 594 "myanalyzer.y"
                                                                                                { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2743 "myanalyzer.tab.c"
    break;

  case 161: /* comp_func: KW_FUN TK_IDENT '(' function_argument_list ')' KW_ARROW_FUNCTION data_type ':' function_body KW_NUF ';'  */
#line 599 "myanalyzer.y"
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
#line 2772 "myanalyzer.tab.c"
    break;

  case 162: /* comp_func: KW_FUN TK_IDENT '(' function_argument_list ')' ':' function_body KW_NUF ';'  */
#line 625 "myanalyzer.y"
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
#line 2800 "myanalyzer.tab.c"
    break;

  case 163: /* comp_variable: '#' TK_IDENT  */
#line 651 "myanalyzer.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 2806 "myanalyzer.tab.c"
    break;

  case 164: /* comp_value: array_value '.' comp_variable  */
#line 655 "myanalyzer.y"
                                       { (yyval.str) = template("self->%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2812 "myanalyzer.tab.c"
    break;

  case 165: /* comp_values: comp_value '.' comp_variable  */
#line 659 "myanalyzer.y"
                                       { (yyval.str) = template("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2818 "myanalyzer.tab.c"
    break;


#line 2822 "myanalyzer.tab.c"

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

#line 664 "myanalyzer.y"


int main () {
  if ( yyparse() == 0 )
    printf("// Your program is syntactically correct!\n");
  else
  	printf("// Your program is not syntactically correct!\n");
}
