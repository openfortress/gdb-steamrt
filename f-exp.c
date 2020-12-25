/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 43 "f-exp.y"


#include "defs.h"
#include "expression.h"
#include "value.h"
#include "parser-defs.h"
#include "language.h"
#include "f-lang.h"
#include "bfd.h" /* Required by objfiles.h.  */
#include "symfile.h" /* Required by objfiles.h.  */
#include "objfiles.h" /* For have_full_symbols and have_partial_symbols */
#include "block.h"
#include <ctype.h>
#include <algorithm>
#include "type-stack.h"

#define parse_type(ps) builtin_type (ps->gdbarch ())
#define parse_f_type(ps) builtin_f_type (ps->gdbarch ())

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror,
   etc).  */
#define GDB_YY_REMAP_PREFIX f_
#include "yy-remap.h"

/* The state of the parser, used internally when we are parsing the
   expression.  */

static struct parser_state *pstate = NULL;

/* Depth of parentheses.  */
static int paren_depth;

/* The current type stack.  */
static struct type_stack *type_stack;

int yyparse (void);

static int yylex (void);

static void yyerror (const char *);

static void growbuf_by_size (int);

static int match_string_literal (void);

static void push_kind_type (LONGEST val, struct type *type);

static struct type *convert_to_kind_type (struct type *basetype, int kind);


#line 121 "f-exp.c.tmp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTRPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTRPTR nullptr
#   else
#    define YY_NULLPTRPTR 0
#   endif
#  else
#   define YY_NULLPTRPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    STRING_LITERAL = 260,
    BOOLEAN_LITERAL = 261,
    NAME = 262,
    TYPENAME = 263,
    NAME_OR_INT = 264,
    SIZEOF = 265,
    KIND = 266,
    ERROR = 267,
    INT_KEYWORD = 268,
    INT_S2_KEYWORD = 269,
    LOGICAL_S1_KEYWORD = 270,
    LOGICAL_S2_KEYWORD = 271,
    LOGICAL_S8_KEYWORD = 272,
    LOGICAL_KEYWORD = 273,
    REAL_KEYWORD = 274,
    REAL_S8_KEYWORD = 275,
    REAL_S16_KEYWORD = 276,
    COMPLEX_KEYWORD = 277,
    COMPLEX_S8_KEYWORD = 278,
    COMPLEX_S16_KEYWORD = 279,
    COMPLEX_S32_KEYWORD = 280,
    BOOL_AND = 281,
    BOOL_OR = 282,
    BOOL_NOT = 283,
    SINGLE = 284,
    DOUBLE = 285,
    PRECISION = 286,
    CHARACTER = 287,
    DOLLAR_VARIABLE = 288,
    ASSIGN_MODIFY = 289,
    UNOP_INTRINSIC = 290,
    BINOP_INTRINSIC = 291,
    ABOVE_COMMA = 292,
    EQUAL = 293,
    NOTEQUAL = 294,
    LESSTHAN = 295,
    GREATERTHAN = 296,
    LEQ = 297,
    GEQ = 298,
    LSH = 299,
    RSH = 300,
    STARSTAR = 301,
    UNARY = 302
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING_LITERAL 260
#define BOOLEAN_LITERAL 261
#define NAME 262
#define TYPENAME 263
#define NAME_OR_INT 264
#define SIZEOF 265
#define KIND 266
#define ERROR 267
#define INT_KEYWORD 268
#define INT_S2_KEYWORD 269
#define LOGICAL_S1_KEYWORD 270
#define LOGICAL_S2_KEYWORD 271
#define LOGICAL_S8_KEYWORD 272
#define LOGICAL_KEYWORD 273
#define REAL_KEYWORD 274
#define REAL_S8_KEYWORD 275
#define REAL_S16_KEYWORD 276
#define COMPLEX_KEYWORD 277
#define COMPLEX_S8_KEYWORD 278
#define COMPLEX_S16_KEYWORD 279
#define COMPLEX_S32_KEYWORD 280
#define BOOL_AND 281
#define BOOL_OR 282
#define BOOL_NOT 283
#define SINGLE 284
#define DOUBLE 285
#define PRECISION 286
#define CHARACTER 287
#define DOLLAR_VARIABLE 288
#define ASSIGN_MODIFY 289
#define UNOP_INTRINSIC 290
#define BINOP_INTRINSIC 291
#define ABOVE_COMMA 292
#define EQUAL 293
#define NOTEQUAL 294
#define LESSTHAN 295
#define GREATERTHAN 296
#define LEQ 297
#define GEQ 298
#define LSH 299
#define RSH 300
#define STARSTAR 301
#define UNARY 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 99 "f-exp.y"

    LONGEST lval;
    struct {
      LONGEST val;
      struct type *type;
    } typed_val;
    struct {
      gdb_byte val[16];
      struct type *type;
    } typed_val_float;
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    struct ttype tsym;
    struct symtoken ssym;
    int voidval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  

#line 288 "f-exp.c.tmp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Second part of user prologue.  */
#line 122 "f-exp.y"

/* YYSTYPE gets defined by %union */
static int parse_number (struct parser_state *, const char *, int,
			 int, YYSTYPE *);

#line 310 "f-exp.c.tmp"


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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or xmalloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
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
       && ! ((defined YYMALLOC || defined xmalloc) \
             && (defined YYFREE || defined xfree)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC xmalloc
#   if ! defined xmalloc && ! defined EXIT_SUCCESS
void *xmalloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE xfree
#   if ! defined xfree && ! defined EXIT_SUCCESS
void xfree (void *); /* INFRINGES ON USER NAME SPACE */
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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    58,    43,     2,
      60,    61,    55,    53,    37,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
       2,    39,     2,    40,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    41,     2,    62,     2,     2,     2,
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
      35,    36,    38,    44,    45,    46,    47,    48,    49,    50,
      51,    57,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   205,   205,   206,   209,   215,   220,   224,   228,   232,
     236,   240,   244,   254,   253,   264,   268,   272,   275,   279,
     283,   289,   295,   301,   307,   313,   317,   325,   331,   339,
     343,   347,   351,   355,   359,   363,   367,   371,   375,   379,
     383,   387,   391,   395,   399,   403,   407,   412,   416,   420,
     426,   433,   444,   451,   454,   457,   468,   475,   483,   515,
     518,   519,   570,   572,   574,   576,   578,   581,   583,   585,
     587,   589,   593,   595,   600,   602,   604,   606,   608,   610,
     612,   614,   616,   618,   620,   622,   624,   626,   628,   630,
     632,   634,   636,   641,   646,   653,   657
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING_LITERAL",
  "BOOLEAN_LITERAL", "NAME", "TYPENAME", "NAME_OR_INT", "SIZEOF", "KIND",
  "ERROR", "INT_KEYWORD", "INT_S2_KEYWORD", "LOGICAL_S1_KEYWORD",
  "LOGICAL_S2_KEYWORD", "LOGICAL_S8_KEYWORD", "LOGICAL_KEYWORD",
  "REAL_KEYWORD", "REAL_S8_KEYWORD", "REAL_S16_KEYWORD", "COMPLEX_KEYWORD",
  "COMPLEX_S8_KEYWORD", "COMPLEX_S16_KEYWORD", "COMPLEX_S32_KEYWORD",
  "BOOL_AND", "BOOL_OR", "BOOL_NOT", "SINGLE", "DOUBLE", "PRECISION",
  "CHARACTER", "DOLLAR_VARIABLE", "ASSIGN_MODIFY", "UNOP_INTRINSIC",
  "BINOP_INTRINSIC", "','", "ABOVE_COMMA", "'='", "'?'", "'|'", "'^'",
  "'&'", "EQUAL", "NOTEQUAL", "LESSTHAN", "GREATERTHAN", "LEQ", "GEQ",
  "LSH", "RSH", "'@'", "'+'", "'-'", "'*'", "'/'", "STARSTAR", "'%'",
  "UNARY", "'('", "')'", "'~'", "':'", "$accept", "start", "type_exp",
  "exp", "$@1", "arglist", "subrange", "complexnum", "variable", "type",
  "ptype", "abs_decl", "direct_abs_decl", "func_mod", "typebase",
  "nonempty_typelist", "name", "name_not_typename", YY_NULLPTRPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    44,   292,    61,
      63,   124,    94,    38,   293,   294,   295,   296,   297,   298,
     299,   300,    64,    43,    45,    42,    47,   301,    37,   302,
      40,    41,   126,    58
};
# endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   182,   -58,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   217,    11,    16,   -59,   -59,   -54,   -53,
     217,   217,   217,   147,   217,    22,   -59,   515,   -59,   -59,
     -59,   -16,   -59,   147,   -25,   217,   -25,   -59,   -59,   -59,
     -59,   217,   217,   -25,   -25,   -25,   336,   -24,   -21,   -25,
     -59,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,    36,   -59,   -16,    -2,   278,   -59,   -11,   -59,
      -1,   372,   408,   480,   217,   -59,   -59,   217,   591,   548,
     515,   515,   610,   628,   645,   660,   660,    48,    48,    48,
      48,    71,    71,   262,   139,   139,    35,    35,    35,   -59,
     -59,    79,   -59,   -59,   -59,    20,   -59,   -59,    26,   -32,
      -4,   -59,   252,   -59,   -59,   217,   515,   -25,   217,   301,
     -13,   -59,    47,   -59,   599,   -59,   444,   515,   217,   217,
     -59,    30,   -59,   -59,   515,   515,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    50,    52,    57,    56,    96,    74,    51,     0,     0,
      75,    76,    81,    80,    78,    79,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    77,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     2,    53,     4,
      59,    60,    58,     0,    11,     0,     9,    91,    89,    92,
      90,     0,     0,     7,     8,     6,     0,     0,     0,    10,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    64,    62,     0,    61,    66,    71,
       0,     0,     0,     0,     0,     5,    26,     0,    46,    47,
      49,    48,    45,    44,    43,    37,    38,    41,    42,    39,
      40,    35,    36,    29,    33,    34,    31,    32,    30,    95,
      28,    17,    65,    69,    63,     0,    72,    93,     0,     0,
       0,    70,    55,    12,    15,     0,    25,    27,    24,    18,
       0,    19,     0,    67,     0,    73,     0,    23,    22,     0,
      14,     0,    94,    16,    21,    20,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,     3,
     -59,   -30,   -59,     8,   -59,   -59,   -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,    36,    56,   121,   140,   141,    57,    38,   127,
      40,    87,    88,    89,    41,   129,   120,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,   123,    45,    39,     6,   144,    51,    52,    44,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    60,    46,   149,    24,    25,    84,    26,   145,
      53,    54,    55,    47,    59,    83,    58,    96,    49,    85,
      97,    84,    48,   119,    86,    91,    90,    50,   150,   130,
     151,    92,    93,    85,   122,   124,   128,   126,    86,   142,
     132,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     1,     2,     3,     4,     5,   143,     7,     8,
       9,   156,    81,    82,   136,    83,   131,   137,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    23,    83,     0,
       0,     0,    27,     0,    28,    29,     0,     0,     0,     0,
       0,   139,    30,    76,    77,    78,    79,    80,    81,    82,
       0,    83,   137,    31,    32,   146,     0,     0,   147,    33,
       0,    34,   138,     0,     0,     0,     0,   152,   154,   155,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,    23,    24,    25,     0,    26,
      27,     0,    28,    29,     0,     1,     2,     3,     4,     5,
      30,     7,     8,     9,    79,    80,    81,    82,     0,    83,
       0,    31,    32,     0,     0,     0,     0,    33,     0,    34,
      23,     0,     0,     0,     0,    27,     0,    28,    29,     0,
       1,     2,     3,     4,     5,    30,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,     0,
       0,     0,    43,     0,    34,    23,     0,     0,     0,     0,
      27,     0,    28,    29,     0,     1,     2,     3,     4,     5,
      30,     7,     8,     9,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,    33,     0,    34,
      23,     0,     0,     0,     0,    27,     6,    28,    29,   125,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,    24,    25,     0,
      26,     0,    33,     0,    34,    77,    78,    79,    80,    81,
      82,    84,    83,     0,     0,     0,     0,    61,    62,     0,
       0,     0,     0,    85,     0,    63,     0,     0,    86,   126,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,    83,    61,    62,   148,     0,     0,     0,     0,     0,
      63,     0,     0,    94,     0,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,    83,    95,    61,    62,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,    83,   133,    61,    62,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    83,   134,
      61,    62,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,    83,   153,    61,    62,     0,     0,
       0,     0,     0,     0,    63,     0,     0,   135,     0,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
      83,    61,    62,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    61,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     6,    83,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,    24,    25,
       0,    26,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,    83,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
      83,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    83,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
      83
};

static const yytype_int16 yycheck[] =
{
       0,     3,    60,     0,     8,    37,    60,    60,     8,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    23,    37,    29,    30,    43,    32,    61,
      30,    31,    32,    22,    34,    60,    33,    61,    22,    55,
      61,    43,    31,     7,    60,    45,    43,    31,    61,    60,
       3,    51,    52,    55,    84,    85,    86,    61,    60,    39,
      61,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     3,     4,     5,     6,     7,    61,     9,    10,
      11,    61,    57,    58,    94,    60,    88,    97,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    28,    60,    -1,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,   121,    43,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,   132,    54,    55,   135,    -1,    -1,   138,    60,
      -1,    62,    63,    -1,    -1,    -1,    -1,   144,   148,   149,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    -1,     3,     4,     5,     6,     7,
      43,     9,    10,    11,    55,    56,    57,    58,    -1,    60,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    -1,    62,
      28,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,    -1,
       3,     4,     5,     6,     7,    43,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    60,    -1,    62,    28,    -1,    -1,    -1,    -1,
      33,    -1,    35,    36,    -1,     3,     4,     5,     6,     7,
      43,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    60,    -1,    62,
      28,    -1,    -1,    -1,    -1,    33,     8,    35,    36,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,
      32,    -1,    60,    -1,    62,    53,    54,    55,    56,    57,
      58,    43,    60,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    55,    -1,    34,    -1,    -1,    60,    61,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    26,    27,    63,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    26,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     8,    60,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      -1,    32,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    28,    29,    30,    32,    33,    35,    36,
      43,    54,    55,    60,    62,    65,    66,    67,    72,    73,
      74,    78,    81,    60,    67,    60,    67,    22,    31,    22,
      31,    60,    60,    67,    67,    67,    67,    71,    73,    67,
       0,    26,    27,    34,    39,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    60,    43,    55,    60,    75,    76,    77,
      73,    67,    67,    67,    37,    61,    61,    61,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,     7,
      80,    68,    75,     3,    75,    11,    61,    73,    75,    79,
      60,    77,    61,    61,    61,    37,    67,    67,    63,    67,
      69,    70,    39,    61,    37,    61,    67,    67,    63,    37,
      61,     3,    73,    61,    67,    67,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    67,    67,    67,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     2,     2,     2,     2,
       2,     2,     4,     0,     5,     4,     6,     0,     1,     1,
       3,     3,     2,     2,     1,     3,     3,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     2,     1,     3,     5,     2,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTRPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTRPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTRPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to xreallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to xreallocate the stack.  Use copies of
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 4:
#line 210 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_TYPE);
			  write_exp_elt_type (pstate, (yyvsp[0].tval));
			  write_exp_elt_opcode (pstate, OP_TYPE); }
#line 1702 "f-exp.c.tmp"
    break;

  case 5:
#line 216 "f-exp.y"
                        { }
#line 1708 "f-exp.c.tmp"
    break;

  case 6:
#line 221 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_IND); }
#line 1714 "f-exp.c.tmp"
    break;

  case 7:
#line 225 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_ADDR); }
#line 1720 "f-exp.c.tmp"
    break;

  case 8:
#line 229 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_NEG); }
#line 1726 "f-exp.c.tmp"
    break;

  case 9:
#line 233 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_LOGICAL_NOT); }
#line 1732 "f-exp.c.tmp"
    break;

  case 10:
#line 237 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_COMPLEMENT); }
#line 1738 "f-exp.c.tmp"
    break;

  case 11:
#line 241 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_SIZEOF); }
#line 1744 "f-exp.c.tmp"
    break;

  case 12:
#line 245 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_FORTRAN_KIND); }
#line 1750 "f-exp.c.tmp"
    break;

  case 13:
#line 254 "f-exp.y"
                        { pstate->start_arglist (); }
#line 1756 "f-exp.c.tmp"
    break;

  case 14:
#line 256 "f-exp.y"
                        { write_exp_elt_opcode (pstate,
						OP_F77_UNDETERMINED_ARGLIST);
			  write_exp_elt_longcst (pstate,
						 pstate->end_arglist ());
			  write_exp_elt_opcode (pstate,
					      OP_F77_UNDETERMINED_ARGLIST); }
#line 1767 "f-exp.c.tmp"
    break;

  case 15:
#line 265 "f-exp.y"
                        { write_exp_elt_opcode (pstate, (yyvsp[-3].opcode)); }
#line 1773 "f-exp.c.tmp"
    break;

  case 16:
#line 269 "f-exp.y"
                        { write_exp_elt_opcode (pstate, (yyvsp[-5].opcode)); }
#line 1779 "f-exp.c.tmp"
    break;

  case 18:
#line 276 "f-exp.y"
                        { pstate->arglist_len = 1; }
#line 1785 "f-exp.c.tmp"
    break;

  case 19:
#line 280 "f-exp.y"
                        { pstate->arglist_len = 1; }
#line 1791 "f-exp.c.tmp"
    break;

  case 20:
#line 284 "f-exp.y"
                        { pstate->arglist_len++; }
#line 1797 "f-exp.c.tmp"
    break;

  case 21:
#line 290 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_RANGE); 
			  write_exp_elt_longcst (pstate, NONE_BOUND_DEFAULT);
			  write_exp_elt_opcode (pstate, OP_RANGE); }
#line 1805 "f-exp.c.tmp"
    break;

  case 22:
#line 296 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_RANGE);
			  write_exp_elt_longcst (pstate, HIGH_BOUND_DEFAULT);
			  write_exp_elt_opcode (pstate, OP_RANGE); }
#line 1813 "f-exp.c.tmp"
    break;

  case 23:
#line 302 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_RANGE);
			  write_exp_elt_longcst (pstate, LOW_BOUND_DEFAULT);
			  write_exp_elt_opcode (pstate, OP_RANGE); }
#line 1821 "f-exp.c.tmp"
    break;

  case 24:
#line 308 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_RANGE);
			  write_exp_elt_longcst (pstate, BOTH_BOUND_DEFAULT);
			  write_exp_elt_opcode (pstate, OP_RANGE); }
#line 1829 "f-exp.c.tmp"
    break;

  case 25:
#line 314 "f-exp.y"
                        { }
#line 1835 "f-exp.c.tmp"
    break;

  case 26:
#line 318 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_COMPLEX);
			  write_exp_elt_type (pstate,
					      parse_f_type (pstate)
					      ->builtin_complex_s16);
			  write_exp_elt_opcode (pstate, OP_COMPLEX); }
#line 1845 "f-exp.c.tmp"
    break;

  case 27:
#line 326 "f-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_CAST);
			  write_exp_elt_type (pstate, (yyvsp[-2].tval));
			  write_exp_elt_opcode (pstate, UNOP_CAST); }
#line 1853 "f-exp.c.tmp"
    break;

  case 28:
#line 332 "f-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
                          write_exp_string (pstate, (yyvsp[0].sval));
                          write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 1861 "f-exp.c.tmp"
    break;

  case 29:
#line 340 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_REPEAT); }
#line 1867 "f-exp.c.tmp"
    break;

  case 30:
#line 344 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_EXP); }
#line 1873 "f-exp.c.tmp"
    break;

  case 31:
#line 348 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_MUL); }
#line 1879 "f-exp.c.tmp"
    break;

  case 32:
#line 352 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_DIV); }
#line 1885 "f-exp.c.tmp"
    break;

  case 33:
#line 356 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ADD); }
#line 1891 "f-exp.c.tmp"
    break;

  case 34:
#line 360 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_SUB); }
#line 1897 "f-exp.c.tmp"
    break;

  case 35:
#line 364 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LSH); }
#line 1903 "f-exp.c.tmp"
    break;

  case 36:
#line 368 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_RSH); }
#line 1909 "f-exp.c.tmp"
    break;

  case 37:
#line 372 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_EQUAL); }
#line 1915 "f-exp.c.tmp"
    break;

  case 38:
#line 376 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_NOTEQUAL); }
#line 1921 "f-exp.c.tmp"
    break;

  case 39:
#line 380 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LEQ); }
#line 1927 "f-exp.c.tmp"
    break;

  case 40:
#line 384 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_GEQ); }
#line 1933 "f-exp.c.tmp"
    break;

  case 41:
#line 388 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LESS); }
#line 1939 "f-exp.c.tmp"
    break;

  case 42:
#line 392 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_GTR); }
#line 1945 "f-exp.c.tmp"
    break;

  case 43:
#line 396 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_BITWISE_AND); }
#line 1951 "f-exp.c.tmp"
    break;

  case 44:
#line 400 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_BITWISE_XOR); }
#line 1957 "f-exp.c.tmp"
    break;

  case 45:
#line 404 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_BITWISE_IOR); }
#line 1963 "f-exp.c.tmp"
    break;

  case 46:
#line 408 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LOGICAL_AND); }
#line 1969 "f-exp.c.tmp"
    break;

  case 47:
#line 413 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LOGICAL_OR); }
#line 1975 "f-exp.c.tmp"
    break;

  case 48:
#line 417 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN); }
#line 1981 "f-exp.c.tmp"
    break;

  case 49:
#line 421 "f-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN_MODIFY);
			  write_exp_elt_opcode (pstate, (yyvsp[-1].opcode));
			  write_exp_elt_opcode (pstate, BINOP_ASSIGN_MODIFY); }
#line 1989 "f-exp.c.tmp"
    break;

  case 50:
#line 427 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, (yyvsp[0].typed_val).type);
			  write_exp_elt_longcst (pstate, (LONGEST) ((yyvsp[0].typed_val).val));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 1998 "f-exp.c.tmp"
    break;

  case 51:
#line 434 "f-exp.y"
                        { YYSTYPE val;
			  parse_number (pstate, (yyvsp[0].ssym).stoken.ptr,
					(yyvsp[0].ssym).stoken.length, 0, &val);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, val.typed_val.type);
			  write_exp_elt_longcst (pstate,
						 (LONGEST)val.typed_val.val);
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2011 "f-exp.c.tmp"
    break;

  case 52:
#line 445 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_type (pstate, (yyvsp[0].typed_val_float).type);
			  write_exp_elt_floatcst (pstate, (yyvsp[0].typed_val_float).val);
			  write_exp_elt_opcode (pstate, OP_FLOAT); }
#line 2020 "f-exp.c.tmp"
    break;

  case 55:
#line 458 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					      parse_f_type (pstate)
					      ->builtin_integer);
			  (yyvsp[-1].tval) = check_typedef ((yyvsp[-1].tval));
			  write_exp_elt_longcst (pstate,
						 (LONGEST) TYPE_LENGTH ((yyvsp[-1].tval)));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2033 "f-exp.c.tmp"
    break;

  case 56:
#line 469 "f-exp.y"
                        { write_exp_elt_opcode (pstate, OP_BOOL);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].lval));
			  write_exp_elt_opcode (pstate, OP_BOOL);
			}
#line 2042 "f-exp.c.tmp"
    break;

  case 57:
#line 476 "f-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_STRING);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, OP_STRING);
			}
#line 2052 "f-exp.c.tmp"
    break;

  case 58:
#line 484 "f-exp.y"
                        { struct block_symbol sym = (yyvsp[0].ssym).sym;

			  if (sym.symbol)
			    {
			      if (symbol_read_needs_frame (sym.symbol))
				pstate->block_tracker->update (sym);
			      write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			      write_exp_elt_block (pstate, sym.block);
			      write_exp_elt_sym (pstate, sym.symbol);
			      write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			      break;
			    }
			  else
			    {
			      struct bound_minimal_symbol msymbol;
			      std::string arg = copy_name ((yyvsp[0].ssym).stoken);

			      msymbol =
				lookup_bound_minimal_symbol (arg.c_str ());
			      if (msymbol.minsym != NULL)
				write_exp_msymbol (pstate, msymbol);
			      else if (!have_full_symbols () && !have_partial_symbols ())
				error (_("No symbol table is loaded.  Use the \"file\" command."));
			      else
				error (_("No symbol \"%s\" in current context."),
				       arg.c_str ());
			    }
			}
#line 2085 "f-exp.c.tmp"
    break;

  case 61:
#line 520 "f-exp.y"
                {
		  /* This is where the interesting stuff happens.  */
		  int done = 0;
		  int array_size;
		  struct type *follow_type = (yyvsp[-1].tval);
		  struct type *range_type;
		  
		  while (!done)
		    switch (type_stack->pop ())
		      {
		      case tp_end:
			done = 1;
			break;
		      case tp_pointer:
			follow_type = lookup_pointer_type (follow_type);
			break;
		      case tp_reference:
			follow_type = lookup_lvalue_reference_type (follow_type);
			break;
		      case tp_array:
			array_size = type_stack->pop_int ();
			if (array_size != -1)
			  {
			    range_type =
			      create_static_range_type ((struct type *) NULL,
							parse_f_type (pstate)
							->builtin_integer,
							0, array_size - 1);
			    follow_type =
			      create_array_type ((struct type *) NULL,
						 follow_type, range_type);
			  }
			else
			  follow_type = lookup_pointer_type (follow_type);
			break;
		      case tp_function:
			follow_type = lookup_function_type (follow_type);
			break;
		      case tp_kind:
			{
			  int kind_val = type_stack->pop_int ();
			  follow_type
			    = convert_to_kind_type (follow_type, kind_val);
			}
			break;
		      }
		  (yyval.tval) = follow_type;
		}
#line 2138 "f-exp.c.tmp"
    break;

  case 62:
#line 571 "f-exp.y"
                        { type_stack->push (tp_pointer); (yyval.voidval) = 0; }
#line 2144 "f-exp.c.tmp"
    break;

  case 63:
#line 573 "f-exp.y"
                        { type_stack->push (tp_pointer); (yyval.voidval) = (yyvsp[0].voidval); }
#line 2150 "f-exp.c.tmp"
    break;

  case 64:
#line 575 "f-exp.y"
                        { type_stack->push (tp_reference); (yyval.voidval) = 0; }
#line 2156 "f-exp.c.tmp"
    break;

  case 65:
#line 577 "f-exp.y"
                        { type_stack->push (tp_reference); (yyval.voidval) = (yyvsp[0].voidval); }
#line 2162 "f-exp.c.tmp"
    break;

  case 67:
#line 582 "f-exp.y"
                        { (yyval.voidval) = (yyvsp[-1].voidval); }
#line 2168 "f-exp.c.tmp"
    break;

  case 68:
#line 584 "f-exp.y"
                        { push_kind_type ((yyvsp[-1].typed_val).val, (yyvsp[-1].typed_val).type); }
#line 2174 "f-exp.c.tmp"
    break;

  case 69:
#line 586 "f-exp.y"
                        { push_kind_type ((yyvsp[0].typed_val).val, (yyvsp[0].typed_val).type); }
#line 2180 "f-exp.c.tmp"
    break;

  case 70:
#line 588 "f-exp.y"
                        { type_stack->push (tp_function); }
#line 2186 "f-exp.c.tmp"
    break;

  case 71:
#line 590 "f-exp.y"
                        { type_stack->push (tp_function); }
#line 2192 "f-exp.c.tmp"
    break;

  case 72:
#line 594 "f-exp.y"
                        { (yyval.voidval) = 0; }
#line 2198 "f-exp.c.tmp"
    break;

  case 73:
#line 596 "f-exp.y"
                        { xfree ((yyvsp[-1].tvec)); (yyval.voidval) = 0; }
#line 2204 "f-exp.c.tmp"
    break;

  case 74:
#line 601 "f-exp.y"
                        { (yyval.tval) = (yyvsp[0].tsym).type; }
#line 2210 "f-exp.c.tmp"
    break;

  case 75:
#line 603 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_integer; }
#line 2216 "f-exp.c.tmp"
    break;

  case 76:
#line 605 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_integer_s2; }
#line 2222 "f-exp.c.tmp"
    break;

  case 77:
#line 607 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_character; }
#line 2228 "f-exp.c.tmp"
    break;

  case 78:
#line 609 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_logical_s8; }
#line 2234 "f-exp.c.tmp"
    break;

  case 79:
#line 611 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_logical; }
#line 2240 "f-exp.c.tmp"
    break;

  case 80:
#line 613 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_logical_s2; }
#line 2246 "f-exp.c.tmp"
    break;

  case 81:
#line 615 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_logical_s1; }
#line 2252 "f-exp.c.tmp"
    break;

  case 82:
#line 617 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_real; }
#line 2258 "f-exp.c.tmp"
    break;

  case 83:
#line 619 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_real_s8; }
#line 2264 "f-exp.c.tmp"
    break;

  case 84:
#line 621 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_real_s16; }
#line 2270 "f-exp.c.tmp"
    break;

  case 85:
#line 623 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_complex_s8; }
#line 2276 "f-exp.c.tmp"
    break;

  case 86:
#line 625 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_complex_s8; }
#line 2282 "f-exp.c.tmp"
    break;

  case 87:
#line 627 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_complex_s16; }
#line 2288 "f-exp.c.tmp"
    break;

  case 88:
#line 629 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_complex_s32; }
#line 2294 "f-exp.c.tmp"
    break;

  case 89:
#line 631 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_real;}
#line 2300 "f-exp.c.tmp"
    break;

  case 90:
#line 633 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_real_s8;}
#line 2306 "f-exp.c.tmp"
    break;

  case 91:
#line 635 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_complex_s8;}
#line 2312 "f-exp.c.tmp"
    break;

  case 92:
#line 637 "f-exp.y"
                        { (yyval.tval) = parse_f_type (pstate)->builtin_complex_s16;}
#line 2318 "f-exp.c.tmp"
    break;

  case 93:
#line 642 "f-exp.y"
                { (yyval.tvec) = (struct type **) xmalloc (sizeof (struct type *) * 2);
		  (yyval.ivec)[0] = 1;	/* Number of types in vector */
		  (yyval.tvec)[1] = (yyvsp[0].tval);
		}
#line 2327 "f-exp.c.tmp"
    break;

  case 94:
#line 647 "f-exp.y"
                { int len = sizeof (struct type *) * (++((yyvsp[-2].ivec)[0]) + 1);
		  (yyval.tvec) = (struct type **) xrealloc ((char *) (yyvsp[-2].tvec), len);
		  (yyval.tvec)[(yyval.ivec)[0]] = (yyvsp[0].tval);
		}
#line 2336 "f-exp.c.tmp"
    break;

  case 95:
#line 654 "f-exp.y"
                {  (yyval.sval) = (yyvsp[0].ssym).stoken; }
#line 2342 "f-exp.c.tmp"
    break;


#line 2346 "f-exp.c.tmp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 667 "f-exp.y"


/* Take care of parsing a number (anything that starts with a digit).
   Set yylval and return the token type; update lexptr.
   LEN is the number of characters in it.  */

/*** Needs some error checking for the float case ***/

static int
parse_number (struct parser_state *par_state,
	      const char *p, int len, int parsed_float, YYSTYPE *putithere)
{
  LONGEST n = 0;
  LONGEST prevn = 0;
  int c;
  int base = input_radix;
  int unsigned_p = 0;
  int long_p = 0;
  ULONGEST high_bit;
  struct type *signed_type;
  struct type *unsigned_type;

  if (parsed_float)
    {
      /* It's a float since it contains a point or an exponent.  */
      /* [dD] is not understood as an exponent by parse_float,
	 change it to 'e'.  */
      char *tmp, *tmp2;

      tmp = xstrdup (p);
      for (tmp2 = tmp; *tmp2; ++tmp2)
	if (*tmp2 == 'd' || *tmp2 == 'D')
	  *tmp2 = 'e';

      /* FIXME: Should this use different types?  */
      putithere->typed_val_float.type = parse_f_type (pstate)->builtin_real_s8;
      bool parsed = parse_float (tmp, len,
				 putithere->typed_val_float.type,
				 putithere->typed_val_float.val);
      xfree (tmp);
      return parsed? FLOAT : ERROR;
    }

  /* Handle base-switching prefixes 0x, 0t, 0d, 0 */
  if (p[0] == '0')
    switch (p[1])
      {
      case 'x':
      case 'X':
	if (len >= 3)
	  {
	    p += 2;
	    base = 16;
	    len -= 2;
	  }
	break;
	
      case 't':
      case 'T':
      case 'd':
      case 'D':
	if (len >= 3)
	  {
	    p += 2;
	    base = 10;
	    len -= 2;
	  }
	break;
	
      default:
	base = 8;
	break;
      }
  
  while (len-- > 0)
    {
      c = *p++;
      if (isupper (c))
	c = tolower (c);
      if (len == 0 && c == 'l')
	long_p = 1;
      else if (len == 0 && c == 'u')
	unsigned_p = 1;
      else
	{
	  int i;
	  if (c >= '0' && c <= '9')
	    i = c - '0';
	  else if (c >= 'a' && c <= 'f')
	    i = c - 'a' + 10;
	  else
	    return ERROR;	/* Char not a digit */
	  if (i >= base)
	    return ERROR;		/* Invalid digit in this base */
	  n *= base;
	  n += i;
	}
      /* Portably test for overflow (only works for nonzero values, so make
	 a second check for zero).  */
      if ((prevn >= n) && n != 0)
	unsigned_p=1;		/* Try something unsigned */
      /* If range checking enabled, portably test for unsigned overflow.  */
      if (RANGE_CHECK && n != 0)
	{
	  if ((unsigned_p && (unsigned)prevn >= (unsigned)n))
	    range_error (_("Overflow on numeric constant."));
	}
      prevn = n;
    }
  
  /* If the number is too big to be an int, or it's got an l suffix
     then it's a long.  Work out if this has to be a long by
     shifting right and seeing if anything remains, and the
     target int size is different to the target long size.
     
     In the expression below, we could have tested
     (n >> gdbarch_int_bit (parse_gdbarch))
     to see if it was zero,
     but too many compilers warn about that, when ints and longs
     are the same size.  So we shift it twice, with fewer bits
     each time, for the same result.  */
  
  if ((gdbarch_int_bit (par_state->gdbarch ())
       != gdbarch_long_bit (par_state->gdbarch ())
       && ((n >> 2)
	   >> (gdbarch_int_bit (par_state->gdbarch ())-2))) /* Avoid
							    shift warning */
      || long_p)
    {
      high_bit = ((ULONGEST)1)
      << (gdbarch_long_bit (par_state->gdbarch ())-1);
      unsigned_type = parse_type (par_state)->builtin_unsigned_long;
      signed_type = parse_type (par_state)->builtin_long;
    }
  else 
    {
      high_bit =
	((ULONGEST)1) << (gdbarch_int_bit (par_state->gdbarch ()) - 1);
      unsigned_type = parse_type (par_state)->builtin_unsigned_int;
      signed_type = parse_type (par_state)->builtin_int;
    }    
  
  putithere->typed_val.val = n;
  
  /* If the high bit of the worked out type is set then this number
     has to be unsigned.  */
  
  if (unsigned_p || (n & high_bit)) 
    putithere->typed_val.type = unsigned_type;
  else 
    putithere->typed_val.type = signed_type;
  
  return INT;
}

/* Called to setup the type stack when we encounter a '(kind=N)' type
   modifier, performs some bounds checking on 'N' and then pushes this to
   the type stack followed by the 'tp_kind' marker.  */
static void
push_kind_type (LONGEST val, struct type *type)
{
  int ival;

  if (TYPE_UNSIGNED (type))
    {
      ULONGEST uval = static_cast <ULONGEST> (val);
      if (uval > INT_MAX)
	error (_("kind value out of range"));
      ival = static_cast <int> (uval);
    }
  else
    {
      if (val > INT_MAX || val < 0)
	error (_("kind value out of range"));
      ival = static_cast <int> (val);
    }

  type_stack->push (ival);
  type_stack->push (tp_kind);
}

/* Called when a type has a '(kind=N)' modifier after it, for example
   'character(kind=1)'.  The BASETYPE is the type described by 'character'
   in our example, and KIND is the integer '1'.  This function returns a
   new type that represents the basetype of a specific kind.  */
static struct type *
convert_to_kind_type (struct type *basetype, int kind)
{
  if (basetype == parse_f_type (pstate)->builtin_character)
    {
      /* Character of kind 1 is a special case, this is the same as the
	 base character type.  */
      if (kind == 1)
	return parse_f_type (pstate)->builtin_character;
    }
  else if (basetype == parse_f_type (pstate)->builtin_complex_s8)
    {
      if (kind == 4)
	return parse_f_type (pstate)->builtin_complex_s8;
      else if (kind == 8)
	return parse_f_type (pstate)->builtin_complex_s16;
      else if (kind == 16)
	return parse_f_type (pstate)->builtin_complex_s32;
    }
  else if (basetype == parse_f_type (pstate)->builtin_real)
    {
      if (kind == 4)
	return parse_f_type (pstate)->builtin_real;
      else if (kind == 8)
	return parse_f_type (pstate)->builtin_real_s8;
      else if (kind == 16)
	return parse_f_type (pstate)->builtin_real_s16;
    }
  else if (basetype == parse_f_type (pstate)->builtin_logical)
    {
      if (kind == 1)
	return parse_f_type (pstate)->builtin_logical_s1;
      else if (kind == 2)
	return parse_f_type (pstate)->builtin_logical_s2;
      else if (kind == 4)
	return parse_f_type (pstate)->builtin_logical;
      else if (kind == 8)
	return parse_f_type (pstate)->builtin_logical_s8;
    }
  else if (basetype == parse_f_type (pstate)->builtin_integer)
    {
      if (kind == 2)
	return parse_f_type (pstate)->builtin_integer_s2;
      else if (kind == 4)
	return parse_f_type (pstate)->builtin_integer;
      else if (kind == 8)
	return parse_f_type (pstate)->builtin_integer_s8;
    }

  error (_("unsupported kind %d for type %s"),
	 kind, TYPE_SAFE_NAME (basetype));

  /* Should never get here.  */
  return nullptr;
}

struct token
{
  /* The string to match against.  */
  const char *oper;

  /* The lexer token to return.  */
  int token;

  /* The expression opcode to embed within the token.  */
  enum exp_opcode opcode;

  /* When this is true the string in OPER is matched exactly including
     case, when this is false OPER is matched case insensitively.  */
  bool case_sensitive;
};

static const struct token dot_ops[] =
{
  { ".and.", BOOL_AND, BINOP_END, false },
  { ".or.", BOOL_OR, BINOP_END, false },
  { ".not.", BOOL_NOT, BINOP_END, false },
  { ".eq.", EQUAL, BINOP_END, false },
  { ".eqv.", EQUAL, BINOP_END, false },
  { ".neqv.", NOTEQUAL, BINOP_END, false },
  { ".ne.", NOTEQUAL, BINOP_END, false },
  { ".le.", LEQ, BINOP_END, false },
  { ".ge.", GEQ, BINOP_END, false },
  { ".gt.", GREATERTHAN, BINOP_END, false },
  { ".lt.", LESSTHAN, BINOP_END, false },
};

/* Holds the Fortran representation of a boolean, and the integer value we
   substitute in when one of the matching strings is parsed.  */
struct f77_boolean_val
{
  /* The string representing a Fortran boolean.  */
  const char *name;

  /* The integer value to replace it with.  */
  int value;
};

/* The set of Fortran booleans.  These are matched case insensitively.  */
static const struct f77_boolean_val boolean_values[]  =
{
  { ".true.", 1 },
  { ".false.", 0 }
};

static const struct token f77_keywords[] =
{
  /* Historically these have always been lowercase only in GDB.  */
  { "complex_16", COMPLEX_S16_KEYWORD, BINOP_END, true },
  { "complex_32", COMPLEX_S32_KEYWORD, BINOP_END, true },
  { "character", CHARACTER, BINOP_END, true },
  { "integer_2", INT_S2_KEYWORD, BINOP_END, true },
  { "logical_1", LOGICAL_S1_KEYWORD, BINOP_END, true },
  { "logical_2", LOGICAL_S2_KEYWORD, BINOP_END, true },
  { "logical_8", LOGICAL_S8_KEYWORD, BINOP_END, true },
  { "complex_8", COMPLEX_S8_KEYWORD, BINOP_END, true },
  { "integer", INT_KEYWORD, BINOP_END, true },
  { "logical", LOGICAL_KEYWORD, BINOP_END, true },
  { "real_16", REAL_S16_KEYWORD, BINOP_END, true },
  { "complex", COMPLEX_KEYWORD, BINOP_END, true },
  { "sizeof", SIZEOF, BINOP_END, true },
  { "real_8", REAL_S8_KEYWORD, BINOP_END, true },
  { "real", REAL_KEYWORD, BINOP_END, true },
  { "single", SINGLE, BINOP_END, true },
  { "double", DOUBLE, BINOP_END, true },
  { "precision", PRECISION, BINOP_END, true },
  /* The following correspond to actual functions in Fortran and are case
     insensitive.  */
  { "kind", KIND, BINOP_END, false },
  { "abs", UNOP_INTRINSIC, UNOP_ABS, false },
  { "mod", BINOP_INTRINSIC, BINOP_MOD, false },
  { "floor", UNOP_INTRINSIC, UNOP_FORTRAN_FLOOR, false },
  { "ceiling", UNOP_INTRINSIC, UNOP_FORTRAN_CEILING, false },
  { "modulo", BINOP_INTRINSIC, BINOP_FORTRAN_MODULO, false },
  { "cmplx", BINOP_INTRINSIC, BINOP_FORTRAN_CMPLX, false },
};

/* Implementation of a dynamically expandable buffer for processing input
   characters acquired through lexptr and building a value to return in
   yylval.  Ripped off from ch-exp.y */ 

static char *tempbuf;		/* Current buffer contents */
static int tempbufsize;		/* Size of allocated buffer */
static int tempbufindex;	/* Current index into buffer */

#define GROWBY_MIN_SIZE 64	/* Minimum amount to grow buffer by */

#define CHECKBUF(size) \
  do { \
    if (tempbufindex + (size) >= tempbufsize) \
      { \
	growbuf_by_size (size); \
      } \
  } while (0);


/* Grow the static temp buffer if necessary, including allocating the
   first one on demand.  */

static void
growbuf_by_size (int count)
{
  int growby;

  growby = std::max (count, GROWBY_MIN_SIZE);
  tempbufsize += growby;
  if (tempbuf == NULL)
    tempbuf = (char *) xmalloc (tempbufsize);
  else
    tempbuf = (char *) xrealloc (tempbuf, tempbufsize);
}

/* Blatantly ripped off from ch-exp.y. This routine recognizes F77 
   string-literals.
   
   Recognize a string literal.  A string literal is a nonzero sequence
   of characters enclosed in matching single quotes, except that
   a single character inside single quotes is a character literal, which
   we reject as a string literal.  To embed the terminator character inside
   a string, it is simply doubled (I.E. 'this''is''one''string') */

static int
match_string_literal (void)
{
  const char *tokptr = pstate->lexptr;

  for (tempbufindex = 0, tokptr++; *tokptr != '\0'; tokptr++)
    {
      CHECKBUF (1);
      if (*tokptr == *pstate->lexptr)
	{
	  if (*(tokptr + 1) == *pstate->lexptr)
	    tokptr++;
	  else
	    break;
	}
      tempbuf[tempbufindex++] = *tokptr;
    }
  if (*tokptr == '\0'					/* no terminator */
      || tempbufindex == 0)				/* no string */
    return 0;
  else
    {
      tempbuf[tempbufindex] = '\0';
      yylval.sval.ptr = tempbuf;
      yylval.sval.length = tempbufindex;
      pstate->lexptr = ++tokptr;
      return STRING_LITERAL;
    }
}

/* Read one token, getting characters through lexptr.  */

static int
yylex (void)
{
  int c;
  int namelen;
  unsigned int token;
  const char *tokstart;
  
 retry:
 
  pstate->prev_lexptr = pstate->lexptr;
 
  tokstart = pstate->lexptr;

  /* First of all, let us make sure we are not dealing with the
     special tokens .true. and .false. which evaluate to 1 and 0.  */

  if (*pstate->lexptr == '.')
    {
      for (int i = 0; i < ARRAY_SIZE (boolean_values); i++)
	{
	  if (strncasecmp (tokstart, boolean_values[i].name,
			   strlen (boolean_values[i].name)) == 0)
	    {
	      pstate->lexptr += strlen (boolean_values[i].name);
	      yylval.lval = boolean_values[i].value;
	      return BOOLEAN_LITERAL;
	    }
	}
    }

  /* See if it is a special .foo. operator.  */
  for (int i = 0; i < ARRAY_SIZE (dot_ops); i++)
    if (strncasecmp (tokstart, dot_ops[i].oper,
		     strlen (dot_ops[i].oper)) == 0)
      {
	gdb_assert (!dot_ops[i].case_sensitive);
	pstate->lexptr += strlen (dot_ops[i].oper);
	yylval.opcode = dot_ops[i].opcode;
	return dot_ops[i].token;
      }

  /* See if it is an exponentiation operator.  */

  if (strncmp (tokstart, "**", 2) == 0)
    {
      pstate->lexptr += 2;
      yylval.opcode = BINOP_EXP;
      return STARSTAR;
    }

  switch (c = *tokstart)
    {
    case 0:
      return 0;
      
    case ' ':
    case '\t':
    case '\n':
      pstate->lexptr++;
      goto retry;
      
    case '\'':
      token = match_string_literal ();
      if (token != 0)
	return (token);
      break;
      
    case '(':
      paren_depth++;
      pstate->lexptr++;
      return c;
      
    case ')':
      if (paren_depth == 0)
	return 0;
      paren_depth--;
      pstate->lexptr++;
      return c;
      
    case ',':
      if (pstate->comma_terminates && paren_depth == 0)
	return 0;
      pstate->lexptr++;
      return c;
      
    case '.':
      /* Might be a floating point number.  */
      if (pstate->lexptr[1] < '0' || pstate->lexptr[1] > '9')
	goto symbol;		/* Nope, must be a symbol.  */
      /* FALL THRU.  */
      
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      {
        /* It's a number.  */
	int got_dot = 0, got_e = 0, got_d = 0, toktype;
	const char *p = tokstart;
	int hex = input_radix > 10;
	
	if (c == '0' && (p[1] == 'x' || p[1] == 'X'))
	  {
	    p += 2;
	    hex = 1;
	  }
	else if (c == '0' && (p[1]=='t' || p[1]=='T'
			      || p[1]=='d' || p[1]=='D'))
	  {
	    p += 2;
	    hex = 0;
	  }
	
	for (;; ++p)
	  {
	    if (!hex && !got_e && (*p == 'e' || *p == 'E'))
	      got_dot = got_e = 1;
	    else if (!hex && !got_d && (*p == 'd' || *p == 'D'))
	      got_dot = got_d = 1;
	    else if (!hex && !got_dot && *p == '.')
	      got_dot = 1;
	    else if (((got_e && (p[-1] == 'e' || p[-1] == 'E'))
		     || (got_d && (p[-1] == 'd' || p[-1] == 'D')))
		     && (*p == '-' || *p == '+'))
	      /* This is the sign of the exponent, not the end of the
		 number.  */
	      continue;
	    /* We will take any letters or digits.  parse_number will
	       complain if past the radix, or if L or U are not final.  */
	    else if ((*p < '0' || *p > '9')
		     && ((*p < 'a' || *p > 'z')
			 && (*p < 'A' || *p > 'Z')))
	      break;
	  }
	toktype = parse_number (pstate, tokstart, p - tokstart,
				got_dot|got_e|got_d,
				&yylval);
        if (toktype == ERROR)
          {
	    char *err_copy = (char *) alloca (p - tokstart + 1);
	    
	    memcpy (err_copy, tokstart, p - tokstart);
	    err_copy[p - tokstart] = 0;
	    error (_("Invalid number \"%s\"."), err_copy);
	  }
	pstate->lexptr = p;
	return toktype;
      }
      
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '|':
    case '&':
    case '^':
    case '~':
    case '!':
    case '@':
    case '<':
    case '>':
    case '[':
    case ']':
    case '?':
    case ':':
    case '=':
    case '{':
    case '}':
    symbol:
      pstate->lexptr++;
      return c;
    }
  
  if (!(c == '_' || c == '$' || c ==':'
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    /* We must have come across a bad character (e.g. ';').  */
    error (_("Invalid character '%c' in expression."), c);
  
  namelen = 0;
  for (c = tokstart[namelen];
       (c == '_' || c == '$' || c == ':' || (c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')); 
       c = tokstart[++namelen]);
  
  /* The token "if" terminates the expression and is NOT 
     removed from the input stream.  */
  
  if (namelen == 2 && tokstart[0] == 'i' && tokstart[1] == 'f')
    return 0;
  
  pstate->lexptr += namelen;
  
  /* Catch specific keywords.  */

  for (int i = 0; i < ARRAY_SIZE (f77_keywords); i++)
    if (strlen (f77_keywords[i].oper) == namelen
	&& ((!f77_keywords[i].case_sensitive
	     && strncasecmp (tokstart, f77_keywords[i].oper, namelen) == 0)
	    || (f77_keywords[i].case_sensitive
		&& strncmp (tokstart, f77_keywords[i].oper, namelen) == 0)))
      {
	yylval.opcode = f77_keywords[i].opcode;
	return f77_keywords[i].token;
      }

  yylval.sval.ptr = tokstart;
  yylval.sval.length = namelen;
  
  if (*tokstart == '$')
    {
      write_dollar_variable (pstate, yylval.sval);
      return DOLLAR_VARIABLE;
    }
  
  /* Use token-type TYPENAME for symbols that happen to be defined
     currently as names of types; NAME for other symbols.
     The caller is not constrained to care about the distinction.  */
  {
    std::string tmp = copy_name (yylval.sval);
    struct block_symbol result;
    enum domain_enum_tag lookup_domains[] =
    {
      STRUCT_DOMAIN,
      VAR_DOMAIN,
      MODULE_DOMAIN
    };
    int hextype;

    for (int i = 0; i < ARRAY_SIZE (lookup_domains); ++i)
      {
	result = lookup_symbol (tmp.c_str (), pstate->expression_context_block,
				lookup_domains[i], NULL);
	if (result.symbol && SYMBOL_CLASS (result.symbol) == LOC_TYPEDEF)
	  {
	    yylval.tsym.type = SYMBOL_TYPE (result.symbol);
	    return TYPENAME;
	  }

	if (result.symbol)
	  break;
      }

    yylval.tsym.type
      = language_lookup_primitive_type (pstate->language (),
					pstate->gdbarch (), tmp.c_str ());
    if (yylval.tsym.type != NULL)
      return TYPENAME;
    
    /* Input names that aren't symbols but ARE valid hex numbers,
       when the input radix permits them, can be names or numbers
       depending on the parse.  Note we support radixes > 16 here.  */
    if (!result.symbol
	&& ((tokstart[0] >= 'a' && tokstart[0] < 'a' + input_radix - 10)
	    || (tokstart[0] >= 'A' && tokstart[0] < 'A' + input_radix - 10)))
      {
 	YYSTYPE newlval;	/* Its value is ignored.  */
	hextype = parse_number (pstate, tokstart, namelen, 0, &newlval);
	if (hextype == INT)
	  {
	    yylval.ssym.sym = result;
	    yylval.ssym.is_a_field_of_this = false;
	    return NAME_OR_INT;
	  }
      }
    
    /* Any other kind of symbol */
    yylval.ssym.sym = result;
    yylval.ssym.is_a_field_of_this = false;
    return NAME;
  }
}

int
f_parse (struct parser_state *par_state)
{
  /* Setting up the parser state.  */
  scoped_restore pstate_restore = make_scoped_restore (&pstate);
  scoped_restore restore_yydebug = make_scoped_restore (&yydebug,
							parser_debug);
  gdb_assert (par_state != NULL);
  pstate = par_state;
  paren_depth = 0;

  struct type_stack stack;
  scoped_restore restore_type_stack = make_scoped_restore (&type_stack,
							   &stack);

  return yyparse ();
}

static void
yyerror (const char *msg)
{
  if (pstate->prev_lexptr)
    pstate->lexptr = pstate->prev_lexptr;

  error (_("A %s in expression, near `%s'."), msg, pstate->lexptr);
}
