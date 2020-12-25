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
#line 36 "c-exp.y"


#include "defs.h"
#include <ctype.h>
#include "expression.h"
#include "value.h"
#include "parser-defs.h"
#include "language.h"
#include "c-lang.h"
#include "c-support.h"
#include "bfd.h" /* Required by objfiles.h.  */
#include "symfile.h" /* Required by objfiles.h.  */
#include "objfiles.h" /* For have_full_symbols and have_partial_symbols */
#include "charset.h"
#include "block.h"
#include "cp-support.h"
#include "macroscope.h"
#include "objc-lang.h"
#include "typeprint.h"
#include "cp-abi.h"
#include "type-stack.h"
#include "target-float.h"

#define parse_type(ps) builtin_type (ps->gdbarch ())

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror,
   etc).  */
#define GDB_YY_REMAP_PREFIX c_
#include "yy-remap.h"

/* The state of the parser, used internally when we are parsing the
   expression.  */

static struct parser_state *pstate = NULL;

/* Data that must be held for the duration of a parse.  */

struct c_parse_state
{
  /* These are used to hold type lists and type stacks that are
     allocated during the parse.  */
  std::vector<std::unique_ptr<std::vector<struct type *>>> type_lists;
  std::vector<std::unique_ptr<struct type_stack>> type_stacks;

  /* Storage for some strings allocated during the parse.  */
  std::vector<gdb::unique_xmalloc_ptr<char>> strings;

  /* When we find that lexptr (the global var defined in parse.c) is
     pointing at a macro invocation, we expand the invocation, and call
     scan_macro_expansion to save the old lexptr here and point lexptr
     into the expanded text.  When we reach the end of that, we call
     end_macro_expansion to pop back to the value we saved here.  The
     macro expansion code promises to return only fully-expanded text,
     so we don't need to "push" more than one level.

     This is disgusting, of course.  It would be cleaner to do all macro
     expansion beforehand, and then hand that to lexptr.  But we don't
     really know where the expression ends.  Remember, in a command like

     (gdb) break *ADDRESS if CONDITION

     we evaluate ADDRESS in the scope of the current frame, but we
     evaluate CONDITION in the scope of the breakpoint's location.  So
     it's simply wrong to try to macro-expand the whole thing at once.  */
  const char *macro_original_text = nullptr;

  /* We save all intermediate macro expansions on this obstack for the
     duration of a single parse.  The expansion text may sometimes have
     to live past the end of the expansion, due to yacc lookahead.
     Rather than try to be clever about saving the data for a single
     token, we simply keep it all and delete it after parsing has
     completed.  */
  auto_obstack expansion_obstack;

  /* The type stack.  */
  struct type_stack type_stack;
};

/* This is set and cleared in c_parse.  */

static struct c_parse_state *cpstate;

int yyparse (void);

static int yylex (void);

static void yyerror (const char *);

static int type_aggregate_p (struct type *);


#line 162 "c-exp.c.tmp"

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
    COMPLEX_INT = 259,
    FLOAT = 260,
    COMPLEX_FLOAT = 261,
    STRING = 262,
    NSSTRING = 263,
    SELECTOR = 264,
    CHAR = 265,
    NAME = 266,
    UNKNOWN_CPP_NAME = 267,
    COMPLETE = 268,
    TYPENAME = 269,
    CLASSNAME = 270,
    OBJC_LBRAC = 271,
    NAME_OR_INT = 272,
    OPERATOR = 273,
    STRUCT = 274,
    CLASS = 275,
    UNION = 276,
    ENUM = 277,
    SIZEOF = 278,
    ALIGNOF = 279,
    UNSIGNED = 280,
    COLONCOLON = 281,
    TEMPLATE = 282,
    ERROR = 283,
    NEW = 284,
    DELETE = 285,
    REINTERPRET_CAST = 286,
    DYNAMIC_CAST = 287,
    STATIC_CAST = 288,
    CONST_CAST = 289,
    ENTRY = 290,
    TYPEOF = 291,
    DECLTYPE = 292,
    TYPEID = 293,
    SIGNED_KEYWORD = 294,
    LONG = 295,
    SHORT = 296,
    INT_KEYWORD = 297,
    CONST_KEYWORD = 298,
    VOLATILE_KEYWORD = 299,
    DOUBLE_KEYWORD = 300,
    RESTRICT = 301,
    ATOMIC = 302,
    FLOAT_KEYWORD = 303,
    COMPLEX = 304,
    DOLLAR_VARIABLE = 305,
    ASSIGN_MODIFY = 306,
    TRUEKEYWORD = 307,
    FALSEKEYWORD = 308,
    ABOVE_COMMA = 309,
    OROR = 310,
    ANDAND = 311,
    EQUAL = 312,
    NOTEQUAL = 313,
    LEQ = 314,
    GEQ = 315,
    LSH = 316,
    RSH = 317,
    UNARY = 318,
    INCREMENT = 319,
    DECREMENT = 320,
    ARROW = 321,
    ARROW_STAR = 322,
    DOT_STAR = 323,
    BLOCKNAME = 324,
    FILENAME = 325,
    DOTDOTDOT = 326
  };
#endif
/* Tokens.  */
#define INT 258
#define COMPLEX_INT 259
#define FLOAT 260
#define COMPLEX_FLOAT 261
#define STRING 262
#define NSSTRING 263
#define SELECTOR 264
#define CHAR 265
#define NAME 266
#define UNKNOWN_CPP_NAME 267
#define COMPLETE 268
#define TYPENAME 269
#define CLASSNAME 270
#define OBJC_LBRAC 271
#define NAME_OR_INT 272
#define OPERATOR 273
#define STRUCT 274
#define CLASS 275
#define UNION 276
#define ENUM 277
#define SIZEOF 278
#define ALIGNOF 279
#define UNSIGNED 280
#define COLONCOLON 281
#define TEMPLATE 282
#define ERROR 283
#define NEW 284
#define DELETE 285
#define REINTERPRET_CAST 286
#define DYNAMIC_CAST 287
#define STATIC_CAST 288
#define CONST_CAST 289
#define ENTRY 290
#define TYPEOF 291
#define DECLTYPE 292
#define TYPEID 293
#define SIGNED_KEYWORD 294
#define LONG 295
#define SHORT 296
#define INT_KEYWORD 297
#define CONST_KEYWORD 298
#define VOLATILE_KEYWORD 299
#define DOUBLE_KEYWORD 300
#define RESTRICT 301
#define ATOMIC 302
#define FLOAT_KEYWORD 303
#define COMPLEX 304
#define DOLLAR_VARIABLE 305
#define ASSIGN_MODIFY 306
#define TRUEKEYWORD 307
#define FALSEKEYWORD 308
#define ABOVE_COMMA 309
#define OROR 310
#define ANDAND 311
#define EQUAL 312
#define NOTEQUAL 313
#define LEQ 314
#define GEQ 315
#define LSH 316
#define RSH 317
#define UNARY 318
#define INCREMENT 319
#define DECREMENT 320
#define ARROW 321
#define ARROW_STAR 322
#define DOT_STAR 323
#define BLOCKNAME 324
#define FILENAME 325
#define DOTDOTDOT 326

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "c-exp.y"

    LONGEST lval;
    struct {
      LONGEST val;
      struct type *type;
    } typed_val_int;
    struct {
      gdb_byte val[16];
      struct type *type;
    } typed_val_float;
    struct type *tval;
    struct stoken sval;
    struct typed_stoken tsval;
    struct ttype tsym;
    struct symtoken ssym;
    int voidval;
    const struct block *bval;
    enum exp_opcode opcode;

    struct stoken_vector svec;
    std::vector<struct type *> *tvec;

    struct type_stack *type_stack;

    struct objc_class_str theclass;
  

#line 381 "c-exp.c.tmp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Second part of user prologue.  */
#line 160 "c-exp.y"

/* YYSTYPE gets defined by %union */
static int parse_number (struct parser_state *par_state,
			 const char *, int, int, YYSTYPE *);
static struct stoken operator_stoken (const char *);
static struct stoken typename_stoken (const char *);
static void check_parameter_typelist (std::vector<struct type *> *);
static void write_destructor_name (struct parser_state *par_state,
				   struct stoken);

#ifdef YYBISON
static void c_print_token (FILE *file, int type, YYSTYPE value);
#define YYPRINT(FILE, TYPE, VALUE) c_print_token (FILE, TYPE, VALUE)
#endif

#line 413 "c-exp.c.tmp"


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
#define YYFINAL  177
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1741

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  284
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  441

#define YYUNDEFTOK  2
#define YYMAXUTOK   326


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
       2,     2,     2,    90,     2,     2,     2,    76,    62,     2,
      85,    89,    74,    72,    54,    73,    82,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,     2,
      65,    56,    66,    57,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    84,     2,    92,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    60,    95,    91,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      58,    59,    63,    64,    67,    68,    69,    70,    77,    78,
      79,    80,    81,    83,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   280,   280,   281,   284,   288,   292,   298,   305,   306,
     311,   315,   319,   323,   327,   331,   335,   339,   343,   347,
     351,   355,   359,   363,   367,   373,   380,   390,   396,   403,
     411,   415,   421,   428,   438,   444,   451,   459,   463,   467,
     477,   476,   501,   500,   517,   516,   525,   527,   530,   531,
     534,   536,   538,   545,   542,   556,   566,   565,   591,   595,
     598,   602,   606,   627,   639,   646,   647,   650,   658,   661,
     668,   672,   676,   682,   686,   690,   694,   698,   702,   706,
     710,   714,   718,   722,   726,   730,   734,   738,   742,   746,
     750,   754,   758,   762,   766,   773,   780,   796,   805,   818,
     825,   846,   849,   855,   862,   881,   886,   890,   894,   901,
     918,   936,   969,   978,   986,   996,  1004,  1010,  1023,  1038,
    1057,  1070,  1094,  1103,  1104,  1134,  1212,  1213,  1217,  1219,
    1221,  1223,  1225,  1233,  1234,  1238,  1239,  1244,  1243,  1247,
    1246,  1249,  1251,  1253,  1255,  1259,  1266,  1268,  1269,  1272,
    1274,  1282,  1290,  1297,  1305,  1307,  1309,  1311,  1315,  1320,
    1332,  1339,  1342,  1345,  1348,  1351,  1354,  1357,  1360,  1363,
    1366,  1369,  1372,  1375,  1378,  1381,  1384,  1387,  1390,  1393,
    1396,  1399,  1402,  1405,  1408,  1411,  1414,  1417,  1422,  1427,
    1432,  1435,  1438,  1441,  1457,  1459,  1461,  1465,  1470,  1476,
    1482,  1487,  1493,  1499,  1504,  1510,  1516,  1520,  1525,  1534,
    1539,  1541,  1545,  1546,  1553,  1560,  1570,  1572,  1581,  1590,
    1597,  1598,  1605,  1609,  1610,  1613,  1614,  1617,  1621,  1623,
    1627,  1629,  1631,  1633,  1635,  1637,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1705,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,
    1725,  1727,  1729,  1731,  1733,  1735,  1737,  1759,  1760,  1761,
    1762,  1763,  1764,  1765,  1766,  1769,  1770,  1771,  1772,  1773,
    1774,  1777,  1778,  1786,  1799
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "COMPLEX_INT", "FLOAT",
  "COMPLEX_FLOAT", "STRING", "NSSTRING", "SELECTOR", "CHAR", "NAME",
  "UNKNOWN_CPP_NAME", "COMPLETE", "TYPENAME", "CLASSNAME", "OBJC_LBRAC",
  "NAME_OR_INT", "OPERATOR", "STRUCT", "CLASS", "UNION", "ENUM", "SIZEOF",
  "ALIGNOF", "UNSIGNED", "COLONCOLON", "TEMPLATE", "ERROR", "NEW",
  "DELETE", "REINTERPRET_CAST", "DYNAMIC_CAST", "STATIC_CAST",
  "CONST_CAST", "ENTRY", "TYPEOF", "DECLTYPE", "TYPEID", "SIGNED_KEYWORD",
  "LONG", "SHORT", "INT_KEYWORD", "CONST_KEYWORD", "VOLATILE_KEYWORD",
  "DOUBLE_KEYWORD", "RESTRICT", "ATOMIC", "FLOAT_KEYWORD", "COMPLEX",
  "DOLLAR_VARIABLE", "ASSIGN_MODIFY", "TRUEKEYWORD", "FALSEKEYWORD", "','",
  "ABOVE_COMMA", "'='", "'?'", "OROR", "ANDAND", "'|'", "'^'", "'&'",
  "EQUAL", "NOTEQUAL", "'<'", "'>'", "LEQ", "GEQ", "LSH", "RSH", "'@'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY", "INCREMENT", "DECREMENT",
  "ARROW", "ARROW_STAR", "'.'", "DOT_STAR", "'['", "'('", "BLOCKNAME",
  "FILENAME", "DOTDOTDOT", "')'", "'!'", "'~'", "']'", "':'", "'{'", "'}'",
  "$accept", "start", "type_exp", "exp1", "exp", "$@1", "$@2", "$@3",
  "msglist", "msgarglist", "msgarg", "$@4", "$@5", "lcurly", "arglist",
  "function_method", "function_method_void",
  "function_method_void_or_typelist", "rcurly", "string_exp", "block",
  "variable", "qualified_name", "const_or_volatile", "single_qualifier",
  "qualifier_seq_noopt", "qualifier_seq", "ptr_operator", "$@6", "$@7",
  "ptr_operator_ts", "abs_decl", "direct_abs_decl", "array_mod",
  "func_mod", "type", "scalar_type", "typebase", "type_name",
  "parameter_typelist", "nonempty_typelist", "ptype", "conversion_type_id",
  "conversion_declarator", "const_and_volatile", "const_or_volatile_noopt",
  "oper", "field_name", "name", "name_not_typename", YY_NULLPTRPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    44,   309,    61,    63,   310,   311,
     124,    94,    38,   312,   313,    60,    62,   314,   315,   316,
     317,    64,    43,    45,    42,    47,    37,   318,   319,   320,
     321,   322,    46,   323,    91,    40,   324,   325,   326,    41,
      33,   126,    93,    58,   123,   125
};
# endif

#define YYPACT_NINF (-324)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     407,  -324,  -324,  -324,  -324,  -324,  -324,   -56,  -324,  -324,
     -43,    42,   591,  -324,   854,    78,   236,   259,   267,   683,
     -20,    95,    29,    13,    28,    53,    86,    96,   -14,    -9,
     105,   321,   588,    20,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,   326,  -324,  -324,  -324,   775,   180,   775,   775,   775,
     775,   775,   407,   166,  -324,   775,   775,  -324,   198,  -324,
     147,  1379,   407,   178,  -324,   185,   205,   188,  -324,  -324,
    -324,  1670,    85,  -324,  -324,    85,   141,  -324,   184,    13,
    -324,    52,    42,  -324,  1379,  -324,   128,    16,    18,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,  -324,  -324,  -324,   136,   153,  -324,  -324,   985,  -324,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,   223,  -324,   232,
    -324,   238,  -324,   239,    42,   407,   208,  1634,  -324,    79,
     213,  -324,  -324,  -324,  -324,  -324,   191,  1634,  1634,  1634,
    1634,   499,   775,   407,   125,  -324,  -324,   215,   216,   171,
    -324,  -324,   217,   225,  -324,  -324,   208,  -324,   208,   208,
     208,   208,   208,   186,    -1,   208,   208,  -324,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,  -324,  -324,   221,   775,   284,   775,   775,  1021,
     187,  1379,     2,    13,  -324,    13,    85,  -324,   197,    14,
      11,   209,  -324,    19,   965,   220,    32,  -324,    39,  -324,
    -324,  -324,   210,   775,    13,   274,    40,    40,    40,  -324,
     211,   214,   226,   227,  -324,  -324,   143,  -324,  -324,  -324,
    -324,  -324,   219,   224,   263,  -324,  -324,  1670,   249,   255,
     261,   262,  1127,   244,  1163,   247,  1199,   295,  -324,  -324,
    -324,   296,   297,  -324,  -324,  -324,   775,  -324,  1379,    -5,
    1379,  1379,   890,  1440,  1474,  1501,   314,  1535,  1562,  1562,
     484,   484,   484,   484,   576,   576,   668,   760,   760,   208,
     208,   208,  -324,    42,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,    13,  -324,   329,  -324,    65,  -324,    13,  -324,   330,
      65,     6,    35,   775,  -324,   257,   293,  -324,   775,   775,
    -324,  -324,   323,   258,  -324,   220,   220,    85,   260,  -324,
    -324,   266,   268,  -324,    39,  1057,  -324,  -324,  -324,    21,
    -324,    13,   775,   775,   264,    40,  -324,   271,   277,   281,
    -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,  -324,   325,
     315,   316,   318,   319,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,  -324,   208,  -324,   775,   346,  -324,   392,  -324,  -324,
     376,   379,  -324,  -324,  -324,    23,    64,  1093,   208,  1379,
    -324,  -324,   116,  -324,  -324,  -324,    85,  -324,  -324,  1379,
    1379,  -324,  -324,   271,   775,  -324,  -324,  -324,   775,   775,
     775,   775,  1413,  -324,  -324,  -324,  -324,  -324,  -324,  -324,
    -324,   116,  1379,  1235,  1271,  1307,  1343,  -324,  -324,  -324,
    -324
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    95,    96,    99,   100,   109,   112,     0,    97,   281,
     284,   194,     0,    98,     0,     0,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   162,   163,   161,   128,   129,   187,   131,   130,
     188,     0,   102,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,   282,   116,     0,     0,    58,     0,     3,
       2,     8,    59,    64,    66,     0,   111,     0,   101,   123,
     133,     0,     0,     4,   195,   220,   160,   283,   125,     0,
      56,     0,    40,    42,    44,   194,     0,   230,   231,   249,
     260,   246,   257,   256,   243,   241,   242,   252,   253,   247,
     248,   254,   255,   250,   251,   236,   237,   238,   239,   240,
     258,   259,   262,   261,     0,     0,   245,   244,   223,   266,
     275,   279,   198,   277,   278,   276,   280,   197,   201,   200,
     204,   203,   207,   206,     0,     0,    22,     0,   212,   214,
     215,   213,   190,   284,   282,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   215,   192,   170,   166,   171,
     164,   189,   185,   183,   181,   196,    11,   132,    13,    12,
      10,    16,    17,     0,     0,    14,    15,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,     0,    53,
       0,    60,     0,     0,   110,     0,   210,   134,   211,     0,
     143,   141,   139,     0,     0,   145,   147,   221,   148,   151,
     153,   118,     0,    59,     0,   120,     0,     0,     0,   265,
       0,     0,     0,     0,   264,   263,   223,   222,   199,   202,
     205,   208,     0,     0,   177,   168,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   167,   169,
     165,   179,   174,   172,   186,   182,     0,    72,     9,     0,
      94,    93,     0,    91,    90,    89,    88,    87,    81,    82,
      85,    86,    83,    84,    79,    80,    73,    77,    78,    74,
      75,    76,    26,   277,   274,   273,   271,   272,   270,   268,
     269,     0,    29,    24,   267,    30,    33,     0,    36,    31,
      37,     0,    55,    59,   218,     0,   216,    68,     0,     0,
      69,    67,   119,     0,   155,   144,   142,   136,     0,   154,
     158,     0,     0,   137,   146,     0,   150,   152,   103,     0,
     121,     0,     0,     0,     0,    47,    48,    46,     0,     0,
     234,   232,   235,   233,   137,   224,   104,    23,   178,     0,
       0,     0,     0,     0,     5,     6,     7,    21,    20,   176,
     180,   173,    71,    39,     0,    27,    25,    34,    32,    38,
     228,   229,    63,   227,   126,     0,   127,     0,    70,    61,
     157,   135,   140,   156,   149,   159,   136,    57,   122,    52,
      51,    41,    49,     0,     0,    43,    45,   209,     0,     0,
       0,     0,    92,    28,    35,   225,   226,    54,    62,   217,
     219,   138,    50,     0,     0,     0,     0,   105,   107,   106,
     108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -324,  -324,     5,    15,   -12,  -324,  -324,  -324,  -124,  -324,
      80,  -324,  -324,  -324,  -220,  -324,  -324,  -324,   230,  -324,
    -324,  -324,   -79,    41,   -71,   -72,  -323,  -116,  -324,  -324,
    -324,   212,   235,  -224,  -222,  -123,   417,     9,   431,   254,
    -324,  -324,  -324,   218,  -324,  -324,    -7,   265,     3,   443
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    58,   173,   174,    61,   236,   237,   238,   354,   355,
     356,   323,   233,    62,   212,    63,    64,    65,   328,    66,
      67,    68,    69,   392,    70,    71,    72,   225,   406,   337,
     226,   227,   228,   229,   230,    73,    74,    75,   142,   342,
     326,    76,   119,   247,   393,   394,    77,   313,   357,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,   217,   246,   218,   346,    59,   347,   136,   126,   126,
     126,   126,   252,   349,   402,    60,   126,   333,   127,   129,
     131,   133,   338,   118,   120,   121,   146,   123,   263,    79,
     124,    14,   240,   166,   242,   168,   169,   170,   171,   172,
       9,   143,    80,   175,   176,   162,   218,    14,   219,   178,
     211,   120,   121,   178,   123,   219,   329,   124,    14,   163,
     178,  -127,   164,   120,   121,   137,   123,   210,    81,   124,
      14,   151,   126,   221,   126,   329,   152,   329,   390,   391,
     216,   179,   232,   431,   235,   222,   324,   383,   277,   120,
     121,   122,   123,   147,   352,   124,    14,   327,   389,   125,
     241,   324,   243,   395,   335,   336,   334,   390,   391,   138,
     407,   339,   427,   358,   359,   144,   223,   224,   148,   254,
     346,   255,   347,   223,   345,   312,   125,   318,    35,    36,
     246,    38,    39,   353,   369,   139,   140,   141,   125,   262,
     264,   266,   253,   234,   218,   204,   205,   206,   207,   208,
     209,   149,   258,   259,   260,   261,    46,   219,   265,    35,
      36,   150,    38,    39,   125,   267,   278,   268,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     153,   167,  -115,   315,   279,   320,   271,   126,   177,   126,
     220,   178,   220,   221,   -65,   221,   126,   314,   126,   314,
     272,   213,   214,   273,   215,   222,   331,   364,   332,   231,
     239,   211,   324,   321,   179,   223,   224,   126,   244,   126,
     126,   126,   120,   121,   302,   303,   248,   350,   124,    14,
    -135,  -135,   245,  -135,  -135,   249,   304,   120,   121,   128,
     123,   250,   251,   124,    14,   256,   257,   269,   270,   274,
     305,   306,   307,   308,   382,   401,   309,   275,  -135,   310,
     120,   121,   130,   123,   430,   276,   124,    14,   120,   121,
     132,   123,   327,   222,   124,    14,   202,   203,   204,   205,
     206,   207,   208,   209,   343,   120,   121,   316,   303,   348,
     351,   124,    14,   360,   126,   368,   361,   125,   366,   304,
     126,   211,   311,   367,   385,   370,   398,   399,   362,   363,
     387,   371,   125,   305,   306,   307,   308,   372,   373,   309,
     179,   217,   310,   375,   401,   138,   377,   379,   380,   381,
     409,   410,   386,   388,   126,   125,   396,   397,   126,  -117,
     400,    21,   403,   125,   408,   404,   411,   405,   413,   423,
     217,   154,   155,   141,   414,    31,    32,    33,    34,   415,
     125,    37,   422,   416,    40,   317,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   417,   202,   203,   204,   205,   206,   207,   208,   209,
     418,   419,   432,   420,   421,   424,   433,   434,   435,   436,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
     425,    11,   426,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   412,   341,   428,    24,    25,
      26,    27,   330,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   165,    43,
      44,   344,   156,   325,   365,   145,     0,     0,     0,    45,
       0,   319,     0,     0,     0,     0,     0,     0,    46,    47,
      48,    49,     0,     0,     0,    50,    51,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,    55,    56,     0,
     179,    57,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     0,     0,
      24,    25,    26,    27,     0,     0,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,   194,   195,   196,   197,   198,   199,   200,
     201,    45,   202,   203,   204,   205,   206,   207,   208,   209,
      46,    47,    48,    49,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,    52,    53,    54,     0,     0,    55,
      56,     0,   179,    57,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    82,    83,    12,    13,    14,
       0,     0,     0,   157,    19,    20,     0,    22,     0,     0,
       0,     0,    24,    25,    26,    27,     0,   158,   159,    30,
     160,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    43,    44,     0,     0,   196,   197,   198,
     199,   200,   201,    45,   202,   203,   204,   205,   206,   207,
     208,   209,     0,    47,    48,    49,     0,     0,     0,    50,
      51,     0,     0,     0,     0,     0,    52,    53,    54,     0,
       0,    55,    56,     0,   179,    57,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,   134,     0,    12,
      13,    14,     0,     0,     0,     0,    19,    20,     0,    22,
       0,     0,     0,     0,    24,    25,    26,    27,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    43,    44,     0,     0,     0,
     197,   198,   199,   200,   201,    45,   202,   203,   204,   205,
     206,   207,   208,   209,     0,    47,    48,    49,     0,     0,
       0,    50,    51,     0,     0,     0,     0,     0,   135,    53,
      54,     0,     0,    55,    56,     0,   179,    57,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,   134,
       0,    12,    13,    14,     0,     0,     0,     0,    19,    20,
       0,    22,     0,     0,     0,     0,    24,    25,    26,    27,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,    43,    44,     0,
       0,     0,     0,     0,   199,   200,   201,    45,   202,   203,
     204,   205,   206,   207,   208,   209,     0,    47,    48,    49,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
      52,    53,    54,     0,     0,    55,    56,     0,    85,    57,
      86,     0,     0,    15,    16,    17,    18,     0,     0,    21,
       0,    23,     0,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    89,   179,     0,    90,     0,
      91,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    46,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,     0,     0,   114,   115,
       0,   180,     0,     0,   116,   117,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,    85,
       0,   219,     0,   384,    15,    16,    17,    18,     0,     0,
      21,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,   221,    35,    36,
       0,    38,    39,     0,     0,    85,    46,     0,     0,   222,
      15,    16,    17,    18,   220,     0,    21,   221,    23,   223,
     224,     0,     0,     0,   340,     0,    46,     0,     0,   222,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    85,     0,     0,     0,     0,    15,    16,    17,    18,
       0,     0,    21,     0,    23,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    85,     0,     0,
     322,     0,    15,    16,    17,    18,     0,     0,    21,     0,
      23,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   179,     0,     0,   340,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   179,
       0,   429,     0,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   180,   179,   374,     0,     0,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     180,   179,   376,     0,     0,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   180,   179,   378,     0,
       0,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   180,   179,   437,     0,     0,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   180,   179,
     438,     0,     0,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   180,   179,   439,     0,     0,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   179,
     180,     0,   440,     0,     0,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   179,   202,   203,   204,
     205,   206,   207,   208,   209,     0,     0,     0,     0,     0,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     179,   202,   203,   204,   205,   206,   207,   208,   209,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   179,   202,   203,
     204,   205,   206,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   179,   202,   203,   204,   205,   206,   207,   208,   209,
       0,     0,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   179,   202,
     203,   204,   205,   206,   207,   208,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,     0,     0,     0,     0,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,    85,     0,
       0,     0,     0,    15,    16,    17,    18,     0,     0,    21,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    85,     0,     0,     0,     0,    15,
      16,    17,    18,     0,     0,    21,     0,    23,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46
};

static const yytype_int16 yycheck[] =
{
      12,    72,   118,    75,   228,     0,   228,    19,    15,    16,
      17,    18,   135,   233,   337,     0,    23,     3,    15,    16,
      17,    18,     3,    14,    11,    12,    23,    14,   151,    85,
      17,    18,    16,    45,    16,    47,    48,    49,    50,    51,
      11,    12,    85,    55,    56,    25,   118,    18,    16,    54,
      62,    11,    12,    54,    14,    16,    54,    17,    18,    39,
      54,    26,    42,    11,    12,    85,    14,    62,    26,    17,
      18,    85,    79,    62,    81,    54,    85,    54,    43,    44,
      71,    16,    79,   406,    81,    74,   209,    92,    89,    11,
      12,    13,    14,    65,    54,    17,    18,    95,    92,    86,
      84,   224,    84,   323,   220,   221,    92,    43,    44,    14,
      89,    92,    89,   237,   238,    86,    84,    85,    65,    40,
     344,    42,   344,    84,    85,   204,    86,   206,    43,    44,
     246,    46,    47,    93,   257,    40,    41,    42,    86,   151,
     152,   153,   137,    91,   216,    80,    81,    82,    83,    84,
      85,    65,   147,   148,   149,   150,    71,    16,   153,    43,
      44,    65,    46,    47,    86,    40,   178,    42,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      85,    11,    26,   205,   179,   207,    25,   204,     0,   206,
      59,    54,    59,    62,    26,    62,   213,   204,   215,   206,
      39,    26,     7,    42,    26,    74,   213,    74,   215,    35,
      92,   233,   345,   208,    16,    84,    85,   234,    92,   236,
     237,   238,    11,    12,    13,    14,    13,   234,    17,    18,
      43,    44,    89,    46,    47,    13,    25,    11,    12,    13,
      14,    13,    13,    17,    18,    42,    65,    42,    42,    42,
      39,    40,    41,    42,   276,   337,    45,    42,    71,    48,
      11,    12,    13,    14,   397,    89,    17,    18,    11,    12,
      13,    14,    95,    74,    17,    18,    78,    79,    80,    81,
      82,    83,    84,    85,    74,    11,    12,    13,    14,    89,
      26,    17,    18,    92,   311,    42,    92,    86,    89,    25,
     317,   323,    91,    89,   311,    66,   328,   329,    92,    92,
     317,    66,    86,    39,    40,    41,    42,    66,    66,    45,
      16,   402,    48,    89,   406,    14,    89,    42,    42,    42,
     352,   353,    13,    13,   351,    86,    89,    54,   355,    26,
      92,    25,    92,    86,   351,    89,    92,    89,   355,    13,
     431,    40,    41,    42,    93,    39,    40,    41,    42,    92,
      86,    45,   384,    92,    48,    91,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    66,    78,    79,    80,    81,    82,    83,    84,    85,
      85,    85,   414,    85,    85,    13,   418,   419,   420,   421,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      44,    14,    43,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   355,   224,   396,    31,    32,
      33,    34,   212,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    41,    52,
      53,   226,    31,   209,   246,    22,    -1,    -1,    -1,    62,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    -1,    -1,    90,    91,    -1,
      16,    94,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    69,    70,    71,    72,    73,    74,    75,
      76,    62,    78,    79,    80,    81,    82,    83,    84,    85,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,    90,
      91,    -1,    16,    94,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    25,    23,    24,    -1,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    39,    40,    38,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    -1,    -1,    71,    72,    73,
      74,    75,    76,    62,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    91,    -1,    16,    94,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    52,    53,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    62,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    72,    73,    74,    -1,    -1,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    -1,    -1,    90,    91,    -1,    16,    94,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    62,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,    -1,    90,    91,    -1,    14,    94,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    16,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    -1,    -1,    84,    85,
      -1,    51,    -1,    -1,    90,    91,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    -1,    -1,    14,
      -1,    16,    -1,    93,    19,    20,    21,    22,    -1,    -1,
      25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    43,    44,
      -1,    46,    47,    -1,    -1,    14,    71,    -1,    -1,    74,
      19,    20,    21,    22,    59,    -1,    25,    62,    27,    84,
      85,    -1,    -1,    -1,    89,    -1,    71,    -1,    -1,    74,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    14,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    14,    -1,    -1,
      89,    -1,    19,    20,    21,    22,    -1,    -1,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    16,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    16,
      -1,    88,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    51,    16,    89,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      51,    16,    89,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    51,    16,    89,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    51,    16,    89,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    51,    16,
      89,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    51,    16,    89,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    16,
      51,    -1,    89,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    16,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      16,    78,    79,    80,    81,    82,    83,    84,    85,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    16,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    16,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    16,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    14,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    14,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    31,    32,    33,    34,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    52,    53,    62,    71,    72,    73,    74,
      78,    79,    85,    86,    87,    90,    91,    94,    97,    98,
      99,   100,   109,   111,   112,   113,   115,   116,   117,   118,
     120,   121,   122,   131,   132,   133,   137,   142,   145,    85,
      85,    26,    14,    15,   100,    14,    16,    29,    30,    51,
      54,    56,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    84,    85,    90,    91,   133,   138,
      11,    12,    13,    14,    17,    86,   142,   144,    13,   144,
      13,   144,    13,   144,    14,    85,   100,    85,    14,    40,
      41,    42,   134,    12,    86,   145,   144,    65,    65,    65,
      65,    85,    85,    85,    40,    41,   134,    25,    39,    40,
      42,    45,    25,    39,    42,   132,   100,    11,   100,   100,
     100,   100,   100,    98,    99,   100,   100,     0,    54,    16,
      51,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    78,    79,    80,    81,    82,    83,    84,    85,
      98,   100,   110,    26,     7,    26,   133,   120,   121,    16,
      59,    62,    74,    84,    85,   123,   126,   127,   128,   129,
     130,    35,   144,   108,    91,   144,   101,   102,   103,    92,
      16,    84,    16,    84,    92,    89,   123,   139,    13,    13,
      13,    13,   131,    98,    40,    42,    42,    65,    98,    98,
      98,    98,   100,   131,   100,    98,   100,    40,    42,    42,
      42,    25,    39,    42,    42,    42,    89,    89,   100,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,    13,    14,    25,    39,    40,    41,    42,    45,
      48,    91,   118,   143,   144,   100,    13,    91,   118,   143,
     100,    99,    89,   107,   131,   135,   136,    95,   114,    54,
     114,   144,   144,     3,    92,   123,   123,   125,     3,    92,
      89,   127,   135,    74,   128,    85,   129,   130,    89,   110,
     144,    26,    54,    93,   104,   105,   106,   144,   104,   104,
      92,    92,    92,    92,    74,   139,    89,    89,    42,   131,
      66,    66,    66,    66,    89,    89,    89,    89,    89,    42,
      42,    42,   100,    92,    93,   144,    13,   144,    13,    92,
      43,    44,   119,   140,   141,   110,    89,    54,   100,   100,
      92,   121,   122,    92,    89,    89,   124,    89,   144,   100,
     100,    92,   106,   144,    93,    92,    92,    66,    85,    85,
      85,    85,   100,    13,    13,    44,    43,    89,   119,    88,
     131,   122,   100,   100,   100,   100,   100,    89,    89,    89,
      89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    97,    98,    98,    98,    98,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   100,   102,   100,   103,   100,   104,   104,   105,   105,
     106,   106,   106,   107,   100,   100,   108,   100,   109,   110,
     110,   110,   111,   112,   100,   113,   113,   100,   114,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   115,
     115,   100,   100,   100,   100,   116,   116,   116,   117,   117,
     118,   118,   118,   117,   117,   117,   119,   119,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   124,   123,   125,
     123,   123,   123,   123,   123,   126,   127,   127,   127,   128,
     128,   128,   128,   128,   129,   129,   129,   129,   130,   130,
     131,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   139,   139,   140,   140,   141,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     143,   143,   143,   143,   143,   144,   144,   144,   144,   144,
     144,   145,   145,   145,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     4,     4,     4,     1,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     4,     2,     4,     3,     4,     3,     4,     5,     3,
       3,     3,     4,     3,     4,     5,     3,     3,     4,     4,
       0,     5,     0,     5,     0,     5,     1,     1,     1,     2,
       3,     2,     2,     0,     5,     3,     0,     5,     1,     0,
       1,     3,     5,     4,     1,     1,     1,     3,     1,     3,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     7,     7,     7,     7,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     4,     5,     1,     2,     1,     1,     0,     1,     1,
       1,     1,     2,     1,     2,     1,     0,     0,     4,     0,
       3,     1,     2,     1,     2,     1,     2,     1,     1,     3,
       2,     1,     2,     1,     2,     2,     3,     3,     2,     3,
       1,     1,     1,     1,     2,     3,     2,     3,     3,     3,
       2,     2,     3,     4,     3,     3,     4,     3,     4,     3,
       4,     2,     3,     2,     3,     2,     3,     1,     1,     2,
       2,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       2,     2,     3,     2,     2,     3,     2,     2,     3,     5,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     2,     0,     2,     2,     2,     1,     1,     1,
       2,     2,     4,     4,     4,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 285 "c-exp.y"
                        { write_exp_elt_opcode(pstate, OP_TYPE);
			  write_exp_elt_type(pstate, (yyvsp[0].tval));
			  write_exp_elt_opcode(pstate, OP_TYPE);}
#line 2175 "c-exp.c.tmp"
    break;

  case 5:
#line 289 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_TYPEOF);
			}
#line 2183 "c-exp.c.tmp"
    break;

  case 6:
#line 293 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_TYPE);
			  write_exp_elt_type (pstate, (yyvsp[-1].tval));
			  write_exp_elt_opcode (pstate, OP_TYPE);
			}
#line 2193 "c-exp.c.tmp"
    break;

  case 7:
#line 299 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_DECLTYPE);
			}
#line 2201 "c-exp.c.tmp"
    break;

  case 9:
#line 307 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_COMMA); }
#line 2207 "c-exp.c.tmp"
    break;

  case 10:
#line 312 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_IND); }
#line 2213 "c-exp.c.tmp"
    break;

  case 11:
#line 316 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_ADDR); }
#line 2219 "c-exp.c.tmp"
    break;

  case 12:
#line 320 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_NEG); }
#line 2225 "c-exp.c.tmp"
    break;

  case 13:
#line 324 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_PLUS); }
#line 2231 "c-exp.c.tmp"
    break;

  case 14:
#line 328 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_LOGICAL_NOT); }
#line 2237 "c-exp.c.tmp"
    break;

  case 15:
#line 332 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_COMPLEMENT); }
#line 2243 "c-exp.c.tmp"
    break;

  case 16:
#line 336 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_PREINCREMENT); }
#line 2249 "c-exp.c.tmp"
    break;

  case 17:
#line 340 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_PREDECREMENT); }
#line 2255 "c-exp.c.tmp"
    break;

  case 18:
#line 344 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_POSTINCREMENT); }
#line 2261 "c-exp.c.tmp"
    break;

  case 19:
#line 348 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_POSTDECREMENT); }
#line 2267 "c-exp.c.tmp"
    break;

  case 20:
#line 352 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_TYPEID); }
#line 2273 "c-exp.c.tmp"
    break;

  case 21:
#line 356 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_TYPEID); }
#line 2279 "c-exp.c.tmp"
    break;

  case 22:
#line 360 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_SIZEOF); }
#line 2285 "c-exp.c.tmp"
    break;

  case 23:
#line 364 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_ALIGNOF); }
#line 2291 "c-exp.c.tmp"
    break;

  case 24:
#line 368 "c-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR); }
#line 2299 "c-exp.c.tmp"
    break;

  case 25:
#line 374 "c-exp.y"
                        { pstate->mark_struct_expression ();
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			  write_exp_string (pstate, (yyvsp[-1].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR); }
#line 2308 "c-exp.c.tmp"
    break;

  case 26:
#line 381 "c-exp.y"
                        { struct stoken s;
			  pstate->mark_struct_expression ();
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			  s.ptr = "";
			  s.length = 0;
			  write_exp_string (pstate, s);
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR); }
#line 2320 "c-exp.c.tmp"
    break;

  case 27:
#line 391 "c-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			  write_destructor_name (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR); }
#line 2328 "c-exp.c.tmp"
    break;

  case 28:
#line 397 "c-exp.y"
                        { pstate->mark_struct_expression ();
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			  write_destructor_name (pstate, (yyvsp[-1].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_PTR); }
#line 2337 "c-exp.c.tmp"
    break;

  case 29:
#line 404 "c-exp.y"
                        { /* exp->type::name becomes exp->*(&type::name) */
			  /* Note: this doesn't work if name is a
			     static member!  FIXME */
			  write_exp_elt_opcode (pstate, UNOP_ADDR);
			  write_exp_elt_opcode (pstate, STRUCTOP_MPTR); }
#line 2347 "c-exp.c.tmp"
    break;

  case 30:
#line 412 "c-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_MPTR); }
#line 2353 "c-exp.c.tmp"
    break;

  case 31:
#line 416 "c-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 2361 "c-exp.c.tmp"
    break;

  case 32:
#line 422 "c-exp.y"
                        { pstate->mark_struct_expression ();
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
			  write_exp_string (pstate, (yyvsp[-1].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 2370 "c-exp.c.tmp"
    break;

  case 33:
#line 429 "c-exp.y"
                        { struct stoken s;
			  pstate->mark_struct_expression ();
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
			  s.ptr = "";
			  s.length = 0;
			  write_exp_string (pstate, s);
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 2382 "c-exp.c.tmp"
    break;

  case 34:
#line 439 "c-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
			  write_destructor_name (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 2390 "c-exp.c.tmp"
    break;

  case 35:
#line 445 "c-exp.y"
                        { pstate->mark_struct_expression ();
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT);
			  write_destructor_name (pstate, (yyvsp[-1].sval));
			  write_exp_elt_opcode (pstate, STRUCTOP_STRUCT); }
#line 2399 "c-exp.c.tmp"
    break;

  case 36:
#line 452 "c-exp.y"
                        { /* exp.type::name becomes exp.*(&type::name) */
			  /* Note: this doesn't work if name is a
			     static member!  FIXME */
			  write_exp_elt_opcode (pstate, UNOP_ADDR);
			  write_exp_elt_opcode (pstate, STRUCTOP_MEMBER); }
#line 2409 "c-exp.c.tmp"
    break;

  case 37:
#line 460 "c-exp.y"
                        { write_exp_elt_opcode (pstate, STRUCTOP_MEMBER); }
#line 2415 "c-exp.c.tmp"
    break;

  case 38:
#line 464 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_SUBSCRIPT); }
#line 2421 "c-exp.c.tmp"
    break;

  case 39:
#line 468 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_SUBSCRIPT); }
#line 2427 "c-exp.c.tmp"
    break;

  case 40:
#line 477 "c-exp.y"
                        {
			  CORE_ADDR theclass;

			  std::string copy = copy_name ((yyvsp[0].tsym).stoken);
			  theclass = lookup_objc_class (pstate->gdbarch (),
							copy.c_str ());
			  if (theclass == 0)
			    error (_("%s is not an ObjC Class"),
				   copy.c_str ());
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					      parse_type (pstate)->builtin_int);
			  write_exp_elt_longcst (pstate, (LONGEST) theclass);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  start_msglist();
			}
#line 2448 "c-exp.c.tmp"
    break;

  case 41:
#line 494 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_OBJC_MSGCALL);
			  end_msglist (pstate);
			  write_exp_elt_opcode (pstate, OP_OBJC_MSGCALL);
			}
#line 2457 "c-exp.c.tmp"
    break;

  case 42:
#line 501 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate,
					    parse_type (pstate)->builtin_int);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].theclass).theclass);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  start_msglist();
			}
#line 2470 "c-exp.c.tmp"
    break;

  case 43:
#line 510 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_OBJC_MSGCALL);
			  end_msglist (pstate);
			  write_exp_elt_opcode (pstate, OP_OBJC_MSGCALL);
			}
#line 2479 "c-exp.c.tmp"
    break;

  case 44:
#line 517 "c-exp.y"
                        { start_msglist(); }
#line 2485 "c-exp.c.tmp"
    break;

  case 45:
#line 519 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_OBJC_MSGCALL);
			  end_msglist (pstate);
			  write_exp_elt_opcode (pstate, OP_OBJC_MSGCALL);
			}
#line 2494 "c-exp.c.tmp"
    break;

  case 46:
#line 526 "c-exp.y"
                        { add_msglist(&(yyvsp[0].sval), 0); }
#line 2500 "c-exp.c.tmp"
    break;

  case 50:
#line 535 "c-exp.y"
                        { add_msglist(&(yyvsp[-2].sval), 1); }
#line 2506 "c-exp.c.tmp"
    break;

  case 51:
#line 537 "c-exp.y"
                        { add_msglist(0, 1);   }
#line 2512 "c-exp.c.tmp"
    break;

  case 52:
#line 539 "c-exp.y"
                        { add_msglist(0, 0);   }
#line 2518 "c-exp.c.tmp"
    break;

  case 53:
#line 545 "c-exp.y"
                        { pstate->start_arglist (); }
#line 2524 "c-exp.c.tmp"
    break;

  case 54:
#line 547 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_FUNCALL);
			  write_exp_elt_longcst (pstate,
						 pstate->end_arglist ());
			  write_exp_elt_opcode (pstate, OP_FUNCALL); }
#line 2533 "c-exp.c.tmp"
    break;

  case 55:
#line 557 "c-exp.y"
                        { pstate->start_arglist ();
			  write_exp_elt_opcode (pstate, OP_FUNCALL);
			  write_exp_elt_longcst (pstate,
						 pstate->end_arglist ());
			  write_exp_elt_opcode (pstate, OP_FUNCALL); }
#line 2543 "c-exp.c.tmp"
    break;

  case 56:
#line 566 "c-exp.y"
                        {
			  /* This could potentially be a an argument defined
			     lookup function (Koenig).  */
			  write_exp_elt_opcode (pstate, OP_ADL_FUNC);
			  write_exp_elt_block
			    (pstate, pstate->expression_context_block);
			  write_exp_elt_sym (pstate,
					     NULL); /* Placeholder.  */
			  write_exp_string (pstate, (yyvsp[-1].ssym).stoken);
			  write_exp_elt_opcode (pstate, OP_ADL_FUNC);

			/* This is to save the value of arglist_len
			   being accumulated by an outer function call.  */

			  pstate->start_arglist ();
			}
#line 2564 "c-exp.c.tmp"
    break;

  case 57:
#line 583 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_FUNCALL);
			  write_exp_elt_longcst (pstate,
						 pstate->end_arglist ());
			  write_exp_elt_opcode (pstate, OP_FUNCALL);
			}
#line 2575 "c-exp.c.tmp"
    break;

  case 58:
#line 592 "c-exp.y"
                        { pstate->start_arglist (); }
#line 2581 "c-exp.c.tmp"
    break;

  case 60:
#line 599 "c-exp.y"
                        { pstate->arglist_len = 1; }
#line 2587 "c-exp.c.tmp"
    break;

  case 61:
#line 603 "c-exp.y"
                        { pstate->arglist_len++; }
#line 2593 "c-exp.c.tmp"
    break;

  case 62:
#line 607 "c-exp.y"
                        {
			  std::vector<struct type *> *type_list = (yyvsp[-2].tvec);
			  LONGEST len = type_list->size ();

			  write_exp_elt_opcode (pstate, TYPE_INSTANCE);
			  /* Save the const/volatile qualifiers as
			     recorded by the const_or_volatile
			     production's actions.  */
			  write_exp_elt_longcst
			    (pstate,
			     (cpstate->type_stack
			      .follow_type_instance_flags ()));
			  write_exp_elt_longcst (pstate, len);
			  for (type *type_elt : *type_list)
			    write_exp_elt_type (pstate, type_elt);
			  write_exp_elt_longcst(pstate, len);
			  write_exp_elt_opcode (pstate, TYPE_INSTANCE);
			}
#line 2616 "c-exp.c.tmp"
    break;

  case 63:
#line 628 "c-exp.y"
                       { write_exp_elt_opcode (pstate, TYPE_INSTANCE);
			 /* See above.  */
			 write_exp_elt_longcst
			   (pstate,
			    cpstate->type_stack.follow_type_instance_flags ());
			 write_exp_elt_longcst (pstate, 0);
			 write_exp_elt_longcst (pstate, 0);
			 write_exp_elt_opcode (pstate, TYPE_INSTANCE);
		       }
#line 2630 "c-exp.c.tmp"
    break;

  case 67:
#line 651 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_FUNC_STATIC_VAR);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, OP_FUNC_STATIC_VAR);
			}
#line 2640 "c-exp.c.tmp"
    break;

  case 68:
#line 659 "c-exp.y"
                        { (yyval.lval) = pstate->end_arglist () - 1; }
#line 2646 "c-exp.c.tmp"
    break;

  case 69:
#line 662 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_ARRAY);
			  write_exp_elt_longcst (pstate, (LONGEST) 0);
			  write_exp_elt_longcst (pstate, (LONGEST) (yyvsp[0].lval));
			  write_exp_elt_opcode (pstate, OP_ARRAY); }
#line 2655 "c-exp.c.tmp"
    break;

  case 70:
#line 669 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_MEMVAL_TYPE); }
#line 2661 "c-exp.c.tmp"
    break;

  case 71:
#line 673 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_CAST_TYPE); }
#line 2667 "c-exp.c.tmp"
    break;

  case 72:
#line 677 "c-exp.y"
                        { }
#line 2673 "c-exp.c.tmp"
    break;

  case 73:
#line 683 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_REPEAT); }
#line 2679 "c-exp.c.tmp"
    break;

  case 74:
#line 687 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_MUL); }
#line 2685 "c-exp.c.tmp"
    break;

  case 75:
#line 691 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_DIV); }
#line 2691 "c-exp.c.tmp"
    break;

  case 76:
#line 695 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_REM); }
#line 2697 "c-exp.c.tmp"
    break;

  case 77:
#line 699 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ADD); }
#line 2703 "c-exp.c.tmp"
    break;

  case 78:
#line 703 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_SUB); }
#line 2709 "c-exp.c.tmp"
    break;

  case 79:
#line 707 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LSH); }
#line 2715 "c-exp.c.tmp"
    break;

  case 80:
#line 711 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_RSH); }
#line 2721 "c-exp.c.tmp"
    break;

  case 81:
#line 715 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_EQUAL); }
#line 2727 "c-exp.c.tmp"
    break;

  case 82:
#line 719 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_NOTEQUAL); }
#line 2733 "c-exp.c.tmp"
    break;

  case 83:
#line 723 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LEQ); }
#line 2739 "c-exp.c.tmp"
    break;

  case 84:
#line 727 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_GEQ); }
#line 2745 "c-exp.c.tmp"
    break;

  case 85:
#line 731 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LESS); }
#line 2751 "c-exp.c.tmp"
    break;

  case 86:
#line 735 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_GTR); }
#line 2757 "c-exp.c.tmp"
    break;

  case 87:
#line 739 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_BITWISE_AND); }
#line 2763 "c-exp.c.tmp"
    break;

  case 88:
#line 743 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_BITWISE_XOR); }
#line 2769 "c-exp.c.tmp"
    break;

  case 89:
#line 747 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_BITWISE_IOR); }
#line 2775 "c-exp.c.tmp"
    break;

  case 90:
#line 751 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LOGICAL_AND); }
#line 2781 "c-exp.c.tmp"
    break;

  case 91:
#line 755 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_LOGICAL_OR); }
#line 2787 "c-exp.c.tmp"
    break;

  case 92:
#line 759 "c-exp.y"
                        { write_exp_elt_opcode (pstate, TERNOP_COND); }
#line 2793 "c-exp.c.tmp"
    break;

  case 93:
#line 763 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN); }
#line 2799 "c-exp.c.tmp"
    break;

  case 94:
#line 767 "c-exp.y"
                        { write_exp_elt_opcode (pstate, BINOP_ASSIGN_MODIFY);
			  write_exp_elt_opcode (pstate, (yyvsp[-1].opcode));
			  write_exp_elt_opcode (pstate,
						BINOP_ASSIGN_MODIFY); }
#line 2808 "c-exp.c.tmp"
    break;

  case 95:
#line 774 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, (yyvsp[0].typed_val_int).type);
			  write_exp_elt_longcst (pstate, (LONGEST) ((yyvsp[0].typed_val_int).val));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2817 "c-exp.c.tmp"
    break;

  case 96:
#line 781 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, TYPE_TARGET_TYPE ((yyvsp[0].typed_val_int).type));
			  write_exp_elt_longcst (pstate, 0);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, TYPE_TARGET_TYPE ((yyvsp[0].typed_val_int).type));
			  write_exp_elt_longcst (pstate, (LONGEST) ((yyvsp[0].typed_val_int).val));
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_opcode (pstate, OP_COMPLEX);
			  write_exp_elt_type (pstate, (yyvsp[0].typed_val_int).type);
			  write_exp_elt_opcode (pstate, OP_COMPLEX);
			}
#line 2835 "c-exp.c.tmp"
    break;

  case 97:
#line 797 "c-exp.y"
                        {
			  struct stoken_vector vec;
			  vec.len = 1;
			  vec.tokens = &(yyvsp[0].tsval);
			  write_exp_string_vector (pstate, (yyvsp[0].tsval).type, &vec);
			}
#line 2846 "c-exp.c.tmp"
    break;

  case 98:
#line 806 "c-exp.y"
                        { YYSTYPE val;
			  parse_number (pstate, (yyvsp[0].ssym).stoken.ptr,
					(yyvsp[0].ssym).stoken.length, 0, &val);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, val.typed_val_int.type);
			  write_exp_elt_longcst (pstate,
					    (LONGEST) val.typed_val_int.val);
			  write_exp_elt_opcode (pstate, OP_LONG);
			}
#line 2860 "c-exp.c.tmp"
    break;

  case 99:
#line 819 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_type (pstate, (yyvsp[0].typed_val_float).type);
			  write_exp_elt_floatcst (pstate, (yyvsp[0].typed_val_float).val);
			  write_exp_elt_opcode (pstate, OP_FLOAT); }
#line 2869 "c-exp.c.tmp"
    break;

  case 100:
#line 826 "c-exp.y"
                        {
			  struct type *underlying
			    = TYPE_TARGET_TYPE ((yyvsp[0].typed_val_float).type);

			  write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_type (pstate, underlying);
			  gdb_byte val[16];
			  target_float_from_host_double (val, underlying, 0);
			  write_exp_elt_floatcst (pstate, val);
			  write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_type (pstate, underlying);
			  write_exp_elt_floatcst (pstate, (yyvsp[0].typed_val_float).val);
			  write_exp_elt_opcode (pstate, OP_FLOAT);
			  write_exp_elt_opcode (pstate, OP_COMPLEX);
			  write_exp_elt_type (pstate, (yyvsp[0].typed_val_float).type);
			  write_exp_elt_opcode (pstate, OP_COMPLEX);
			}
#line 2892 "c-exp.c.tmp"
    break;

  case 102:
#line 850 "c-exp.y"
                        {
			  write_dollar_variable (pstate, (yyvsp[0].sval));
			}
#line 2900 "c-exp.c.tmp"
    break;

  case 103:
#line 856 "c-exp.y"
                        {
			  write_exp_elt_opcode (pstate, OP_OBJC_SELECTOR);
			  write_exp_string (pstate, (yyvsp[-1].sval));
			  write_exp_elt_opcode (pstate, OP_OBJC_SELECTOR); }
#line 2909 "c-exp.c.tmp"
    break;

  case 104:
#line 863 "c-exp.y"
                        { struct type *type = (yyvsp[-1].tval);
			  write_exp_elt_opcode (pstate, OP_LONG);
			  write_exp_elt_type (pstate, lookup_signed_typename
					      (pstate->language (),
					       "int"));
			  type = check_typedef (type);

			    /* $5.3.3/2 of the C++ Standard (n3290 draft)
			       says of sizeof:  "When applied to a reference
			       or a reference type, the result is the size of
			       the referenced type."  */
			  if (TYPE_IS_REFERENCE (type))
			    type = check_typedef (TYPE_TARGET_TYPE (type));
			  write_exp_elt_longcst (pstate,
						 (LONGEST) TYPE_LENGTH (type));
			  write_exp_elt_opcode (pstate, OP_LONG); }
#line 2930 "c-exp.c.tmp"
    break;

  case 105:
#line 882 "c-exp.y"
                        { write_exp_elt_opcode (pstate,
						UNOP_REINTERPRET_CAST); }
#line 2937 "c-exp.c.tmp"
    break;

  case 106:
#line 887 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_CAST_TYPE); }
#line 2943 "c-exp.c.tmp"
    break;

  case 107:
#line 891 "c-exp.y"
                        { write_exp_elt_opcode (pstate, UNOP_DYNAMIC_CAST); }
#line 2949 "c-exp.c.tmp"
    break;

  case 108:
#line 895 "c-exp.y"
                        { /* We could do more error checking here, but
			     it doesn't seem worthwhile.  */
			  write_exp_elt_opcode (pstate, UNOP_CAST_TYPE); }
#line 2957 "c-exp.c.tmp"
    break;

  case 109:
#line 902 "c-exp.y"
                        {
			  /* We copy the string here, and not in the
			     lexer, to guarantee that we do not leak a
			     string.  Note that we follow the
			     NUL-termination convention of the
			     lexer.  */
			  struct typed_stoken *vec = XNEW (struct typed_stoken);
			  (yyval.svec).len = 1;
			  (yyval.svec).tokens = vec;

			  vec->type = (yyvsp[0].tsval).type;
			  vec->length = (yyvsp[0].tsval).length;
			  vec->ptr = (char *) xmalloc ((yyvsp[0].tsval).length + 1);
			  memcpy (vec->ptr, (yyvsp[0].tsval).ptr, (yyvsp[0].tsval).length + 1);
			}
#line 2977 "c-exp.c.tmp"
    break;

  case 110:
#line 919 "c-exp.y"
                        {
			  /* Note that we NUL-terminate here, but just
			     for convenience.  */
			  char *p;
			  ++(yyval.svec).len;
			  (yyval.svec).tokens = XRESIZEVEC (struct typed_stoken,
						  (yyval.svec).tokens, (yyval.svec).len);

			  p = (char *) xmalloc ((yyvsp[0].tsval).length + 1);
			  memcpy (p, (yyvsp[0].tsval).ptr, (yyvsp[0].tsval).length + 1);

			  (yyval.svec).tokens[(yyval.svec).len - 1].type = (yyvsp[0].tsval).type;
			  (yyval.svec).tokens[(yyval.svec).len - 1].length = (yyvsp[0].tsval).length;
			  (yyval.svec).tokens[(yyval.svec).len - 1].ptr = p;
			}
#line 2997 "c-exp.c.tmp"
    break;

  case 111:
#line 937 "c-exp.y"
                        {
			  int i;
			  c_string_type type = C_STRING;

			  for (i = 0; i < (yyvsp[0].svec).len; ++i)
			    {
			      switch ((yyvsp[0].svec).tokens[i].type)
				{
				case C_STRING:
				  break;
				case C_WIDE_STRING:
				case C_STRING_16:
				case C_STRING_32:
				  if (type != C_STRING
				      && type != (yyvsp[0].svec).tokens[i].type)
				    error (_("Undefined string concatenation."));
				  type = (enum c_string_type_values) (yyvsp[0].svec).tokens[i].type;
				  break;
				default:
				  /* internal error */
				  internal_error (__FILE__, __LINE__,
						  "unrecognized type in string concatenation");
				}
			    }

			  write_exp_string_vector (pstate, type, &(yyvsp[0].svec));
			  for (i = 0; i < (yyvsp[0].svec).len; ++i)
			    xfree ((yyvsp[0].svec).tokens[i].ptr);
			  xfree ((yyvsp[0].svec).tokens);
			}
#line 3032 "c-exp.c.tmp"
    break;

  case 112:
#line 972 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_OBJC_NSSTRING);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, OP_OBJC_NSSTRING); }
#line 3040 "c-exp.c.tmp"
    break;

  case 113:
#line 979 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
                          write_exp_elt_type (pstate,
					  parse_type (pstate)->builtin_bool);
                          write_exp_elt_longcst (pstate, (LONGEST) 1);
                          write_exp_elt_opcode (pstate, OP_LONG); }
#line 3050 "c-exp.c.tmp"
    break;

  case 114:
#line 987 "c-exp.y"
                        { write_exp_elt_opcode (pstate, OP_LONG);
                          write_exp_elt_type (pstate,
					  parse_type (pstate)->builtin_bool);
                          write_exp_elt_longcst (pstate, (LONGEST) 0);
                          write_exp_elt_opcode (pstate, OP_LONG); }
#line 3060 "c-exp.c.tmp"
    break;

  case 115:
#line 997 "c-exp.y"
                        {
			  if ((yyvsp[0].ssym).sym.symbol)
			    (yyval.bval) = SYMBOL_BLOCK_VALUE ((yyvsp[0].ssym).sym.symbol);
			  else
			    error (_("No file or function \"%s\"."),
				   copy_name ((yyvsp[0].ssym).stoken).c_str ());
			}
#line 3072 "c-exp.c.tmp"
    break;

  case 116:
#line 1005 "c-exp.y"
                        {
			  (yyval.bval) = (yyvsp[0].bval);
			}
#line 3080 "c-exp.c.tmp"
    break;

  case 117:
#line 1011 "c-exp.y"
                        {
			  std::string copy = copy_name ((yyvsp[0].sval));
			  struct symbol *tem
			    = lookup_symbol (copy.c_str (), (yyvsp[-2].bval),
					     VAR_DOMAIN, NULL).symbol;

			  if (!tem || SYMBOL_CLASS (tem) != LOC_BLOCK)
			    error (_("No function \"%s\" in specified context."),
				   copy.c_str ());
			  (yyval.bval) = SYMBOL_BLOCK_VALUE (tem); }
#line 3095 "c-exp.c.tmp"
    break;

  case 118:
#line 1024 "c-exp.y"
                        { struct symbol *sym = (yyvsp[-1].ssym).sym.symbol;

			  if (sym == NULL || !SYMBOL_IS_ARGUMENT (sym)
			      || !symbol_read_needs_frame (sym))
			    error (_("@entry can be used only for function "
				     "parameters, not for \"%s\""),
				   copy_name ((yyvsp[-1].ssym).stoken).c_str ());

			  write_exp_elt_opcode (pstate, OP_VAR_ENTRY_VALUE);
			  write_exp_elt_sym (pstate, sym);
			  write_exp_elt_opcode (pstate, OP_VAR_ENTRY_VALUE);
			}
#line 3112 "c-exp.c.tmp"
    break;

  case 119:
#line 1039 "c-exp.y"
                        {
			  std::string copy = copy_name ((yyvsp[0].sval));
			  struct block_symbol sym
			    = lookup_symbol (copy.c_str (), (yyvsp[-2].bval),
					     VAR_DOMAIN, NULL);

			  if (sym.symbol == 0)
			    error (_("No symbol \"%s\" in specified context."),
				   copy.c_str ());
			  if (symbol_read_needs_frame (sym.symbol))
			    pstate->block_tracker->update (sym);

			  write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			  write_exp_elt_block (pstate, sym.block);
			  write_exp_elt_sym (pstate, sym.symbol);
			  write_exp_elt_opcode (pstate, OP_VAR_VALUE); }
#line 3133 "c-exp.c.tmp"
    break;

  case 120:
#line 1058 "c-exp.y"
                        {
			  struct type *type = (yyvsp[-2].tsym).type;
			  type = check_typedef (type);
			  if (!type_aggregate_p (type))
			    error (_("`%s' is not defined as an aggregate type."),
				   TYPE_SAFE_NAME (type));

			  write_exp_elt_opcode (pstate, OP_SCOPE);
			  write_exp_elt_type (pstate, type);
			  write_exp_string (pstate, (yyvsp[0].sval));
			  write_exp_elt_opcode (pstate, OP_SCOPE);
			}
#line 3150 "c-exp.c.tmp"
    break;

  case 121:
#line 1071 "c-exp.y"
                        {
			  struct type *type = (yyvsp[-3].tsym).type;
			  struct stoken tmp_token;
			  char *buf;

			  type = check_typedef (type);
			  if (!type_aggregate_p (type))
			    error (_("`%s' is not defined as an aggregate type."),
				   TYPE_SAFE_NAME (type));
			  buf = (char *) alloca ((yyvsp[0].sval).length + 2);
			  tmp_token.ptr = buf;
			  tmp_token.length = (yyvsp[0].sval).length + 1;
			  buf[0] = '~';
			  memcpy (buf+1, (yyvsp[0].sval).ptr, (yyvsp[0].sval).length);
			  buf[tmp_token.length] = 0;

			  /* Check for valid destructor name.  */
			  destructor_name_p (tmp_token.ptr, (yyvsp[-3].tsym).type);
			  write_exp_elt_opcode (pstate, OP_SCOPE);
			  write_exp_elt_type (pstate, type);
			  write_exp_string (pstate, tmp_token);
			  write_exp_elt_opcode (pstate, OP_SCOPE);
			}
#line 3178 "c-exp.c.tmp"
    break;

  case 122:
#line 1095 "c-exp.y"
                        {
			  std::string copy = copy_name ((yyvsp[-2].sval));
			  error (_("No type \"%s\" within class "
				   "or namespace \"%s\"."),
				 copy.c_str (), TYPE_SAFE_NAME ((yyvsp[-4].tsym).type));
			}
#line 3189 "c-exp.c.tmp"
    break;

  case 124:
#line 1105 "c-exp.y"
                        {
			  std::string name = copy_name ((yyvsp[0].ssym).stoken);
			  struct symbol *sym;
			  struct bound_minimal_symbol msymbol;

			  sym
			    = lookup_symbol (name.c_str (),
					     (const struct block *) NULL,
					     VAR_DOMAIN, NULL).symbol;
			  if (sym)
			    {
			      write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			      write_exp_elt_block (pstate, NULL);
			      write_exp_elt_sym (pstate, sym);
			      write_exp_elt_opcode (pstate, OP_VAR_VALUE);
			      break;
			    }

			  msymbol = lookup_bound_minimal_symbol (name.c_str ());
			  if (msymbol.minsym != NULL)
			    write_exp_msymbol (pstate, msymbol);
			  else if (!have_full_symbols () && !have_partial_symbols ())
			    error (_("No symbol table is loaded.  Use the \"file\" command."));
			  else
			    error (_("No symbol \"%s\" in current context."),
				   name.c_str ());
			}
#line 3221 "c-exp.c.tmp"
    break;

  case 125:
#line 1135 "c-exp.y"
                        { struct block_symbol sym = (yyvsp[0].ssym).sym;

			  if (sym.symbol)
			    {
			      if (symbol_read_needs_frame (sym.symbol))
				pstate->block_tracker->update (sym);

			      /* If we found a function, see if it's
				 an ifunc resolver that has the same
				 address as the ifunc symbol itself.
				 If so, prefer the ifunc symbol.  */

			      bound_minimal_symbol resolver
				= find_gnu_ifunc (sym.symbol);
			      if (resolver.minsym != NULL)
				write_exp_msymbol (pstate, resolver);
			      else
				{
				  write_exp_elt_opcode (pstate, OP_VAR_VALUE);
				  write_exp_elt_block (pstate, sym.block);
				  write_exp_elt_sym (pstate, sym.symbol);
				  write_exp_elt_opcode (pstate, OP_VAR_VALUE);
				}
			    }
			  else if ((yyvsp[0].ssym).is_a_field_of_this)
			    {
			      /* C++: it hangs off of `this'.  Must
			         not inadvertently convert from a method call
				 to data ref.  */
			      pstate->block_tracker->update (sym);
			      write_exp_elt_opcode (pstate, OP_THIS);
			      write_exp_elt_opcode (pstate, OP_THIS);
			      write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			      write_exp_string (pstate, (yyvsp[0].ssym).stoken);
			      write_exp_elt_opcode (pstate, STRUCTOP_PTR);
			    }
			  else
			    {
			      std::string arg = copy_name ((yyvsp[0].ssym).stoken);

			      bound_minimal_symbol msymbol
				= lookup_bound_minimal_symbol (arg.c_str ());
			      if (msymbol.minsym == NULL)
				{
				  if (!have_full_symbols () && !have_partial_symbols ())
				    error (_("No symbol table is loaded.  Use the \"file\" command."));
				  else
				    error (_("No symbol \"%s\" in current context."),
					   arg.c_str ());
				}

			      /* This minsym might be an alias for
				 another function.  See if we can find
				 the debug symbol for the target, and
				 if so, use it instead, since it has
				 return type / prototype info.  This
				 is important for example for "p
				 *__errno_location()".  */
			      symbol *alias_target
				= ((msymbol.minsym->type != mst_text_gnu_ifunc
				    && msymbol.minsym->type != mst_data_gnu_ifunc)
				   ? find_function_alias_target (msymbol)
				   : NULL);
			      if (alias_target != NULL)
				{
				  write_exp_elt_opcode (pstate, OP_VAR_VALUE);
				  write_exp_elt_block
				    (pstate, SYMBOL_BLOCK_VALUE (alias_target));
				  write_exp_elt_sym (pstate, alias_target);
				  write_exp_elt_opcode (pstate, OP_VAR_VALUE);
				}
			      else
				write_exp_msymbol (pstate, msymbol);
			    }
			}
#line 3301 "c-exp.c.tmp"
    break;

  case 128:
#line 1218 "c-exp.y"
                        { cpstate->type_stack.insert (tp_const); }
#line 3307 "c-exp.c.tmp"
    break;

  case 129:
#line 1220 "c-exp.y"
                        { cpstate->type_stack.insert (tp_volatile); }
#line 3313 "c-exp.c.tmp"
    break;

  case 130:
#line 1222 "c-exp.y"
                        { cpstate->type_stack.insert (tp_atomic); }
#line 3319 "c-exp.c.tmp"
    break;

  case 131:
#line 1224 "c-exp.y"
                        { cpstate->type_stack.insert (tp_restrict); }
#line 3325 "c-exp.c.tmp"
    break;

  case 132:
#line 1226 "c-exp.y"
                {
		  cpstate->type_stack.insert (pstate,
					      copy_name ((yyvsp[0].ssym).stoken).c_str ());
		}
#line 3334 "c-exp.c.tmp"
    break;

  case 137:
#line 1244 "c-exp.y"
                        { cpstate->type_stack.insert (tp_pointer); }
#line 3340 "c-exp.c.tmp"
    break;

  case 139:
#line 1247 "c-exp.y"
                        { cpstate->type_stack.insert (tp_pointer); }
#line 3346 "c-exp.c.tmp"
    break;

  case 141:
#line 1250 "c-exp.y"
                        { cpstate->type_stack.insert (tp_reference); }
#line 3352 "c-exp.c.tmp"
    break;

  case 142:
#line 1252 "c-exp.y"
                        { cpstate->type_stack.insert (tp_reference); }
#line 3358 "c-exp.c.tmp"
    break;

  case 143:
#line 1254 "c-exp.y"
                        { cpstate->type_stack.insert (tp_rvalue_reference); }
#line 3364 "c-exp.c.tmp"
    break;

  case 144:
#line 1256 "c-exp.y"
                        { cpstate->type_stack.insert (tp_rvalue_reference); }
#line 3370 "c-exp.c.tmp"
    break;

  case 145:
#line 1260 "c-exp.y"
                        {
			  (yyval.type_stack) = cpstate->type_stack.create ();
			  cpstate->type_stacks.emplace_back ((yyval.type_stack));
			}
#line 3379 "c-exp.c.tmp"
    break;

  case 146:
#line 1267 "c-exp.y"
                        { (yyval.type_stack) = (yyvsp[0].type_stack)->append ((yyvsp[-1].type_stack)); }
#line 3385 "c-exp.c.tmp"
    break;

  case 149:
#line 1273 "c-exp.y"
                        { (yyval.type_stack) = (yyvsp[-1].type_stack); }
#line 3391 "c-exp.c.tmp"
    break;

  case 150:
#line 1275 "c-exp.y"
                        {
			  cpstate->type_stack.push ((yyvsp[-1].type_stack));
			  cpstate->type_stack.push ((yyvsp[0].lval));
			  cpstate->type_stack.push (tp_array);
			  (yyval.type_stack) = cpstate->type_stack.create ();
			  cpstate->type_stacks.emplace_back ((yyval.type_stack));
			}
#line 3403 "c-exp.c.tmp"
    break;

  case 151:
#line 1283 "c-exp.y"
                        {
			  cpstate->type_stack.push ((yyvsp[0].lval));
			  cpstate->type_stack.push (tp_array);
			  (yyval.type_stack) = cpstate->type_stack.create ();
			  cpstate->type_stacks.emplace_back ((yyval.type_stack));
			}
#line 3414 "c-exp.c.tmp"
    break;

  case 152:
#line 1291 "c-exp.y"
                        {
			  cpstate->type_stack.push ((yyvsp[-1].type_stack));
			  cpstate->type_stack.push ((yyvsp[0].tvec));
			  (yyval.type_stack) = cpstate->type_stack.create ();
			  cpstate->type_stacks.emplace_back ((yyval.type_stack));
			}
#line 3425 "c-exp.c.tmp"
    break;

  case 153:
#line 1298 "c-exp.y"
                        {
			  cpstate->type_stack.push ((yyvsp[0].tvec));
			  (yyval.type_stack) = cpstate->type_stack.create ();
			  cpstate->type_stacks.emplace_back ((yyval.type_stack));
			}
#line 3435 "c-exp.c.tmp"
    break;

  case 154:
#line 1306 "c-exp.y"
                        { (yyval.lval) = -1; }
#line 3441 "c-exp.c.tmp"
    break;

  case 155:
#line 1308 "c-exp.y"
                        { (yyval.lval) = -1; }
#line 3447 "c-exp.c.tmp"
    break;

  case 156:
#line 1310 "c-exp.y"
                        { (yyval.lval) = (yyvsp[-1].typed_val_int).val; }
#line 3453 "c-exp.c.tmp"
    break;

  case 157:
#line 1312 "c-exp.y"
                        { (yyval.lval) = (yyvsp[-1].typed_val_int).val; }
#line 3459 "c-exp.c.tmp"
    break;

  case 158:
#line 1316 "c-exp.y"
                        {
			  (yyval.tvec) = new std::vector<struct type *>;
			  cpstate->type_lists.emplace_back ((yyval.tvec));
			}
#line 3468 "c-exp.c.tmp"
    break;

  case 159:
#line 1321 "c-exp.y"
                        { (yyval.tvec) = (yyvsp[-1].tvec); }
#line 3474 "c-exp.c.tmp"
    break;

  case 161:
#line 1340 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "int"); }
#line 3481 "c-exp.c.tmp"
    break;

  case 162:
#line 1343 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long"); }
#line 3488 "c-exp.c.tmp"
    break;

  case 163:
#line 1346 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "short"); }
#line 3495 "c-exp.c.tmp"
    break;

  case 164:
#line 1349 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long"); }
#line 3502 "c-exp.c.tmp"
    break;

  case 165:
#line 1352 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long"); }
#line 3509 "c-exp.c.tmp"
    break;

  case 166:
#line 1355 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long"); }
#line 3516 "c-exp.c.tmp"
    break;

  case 167:
#line 1358 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long"); }
#line 3523 "c-exp.c.tmp"
    break;

  case 168:
#line 1361 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long"); }
#line 3530 "c-exp.c.tmp"
    break;

  case 169:
#line 1364 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long"); }
#line 3537 "c-exp.c.tmp"
    break;

  case 170:
#line 1367 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long"); }
#line 3544 "c-exp.c.tmp"
    break;

  case 171:
#line 1370 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long long"); }
#line 3551 "c-exp.c.tmp"
    break;

  case 172:
#line 1373 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long long"); }
#line 3558 "c-exp.c.tmp"
    break;

  case 173:
#line 1376 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long long"); }
#line 3565 "c-exp.c.tmp"
    break;

  case 174:
#line 1379 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long long"); }
#line 3572 "c-exp.c.tmp"
    break;

  case 175:
#line 1382 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long long"); }
#line 3579 "c-exp.c.tmp"
    break;

  case 176:
#line 1385 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "long long"); }
#line 3586 "c-exp.c.tmp"
    break;

  case 177:
#line 1388 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long long"); }
#line 3593 "c-exp.c.tmp"
    break;

  case 178:
#line 1391 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long long"); }
#line 3600 "c-exp.c.tmp"
    break;

  case 179:
#line 1394 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long long"); }
#line 3607 "c-exp.c.tmp"
    break;

  case 180:
#line 1397 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "long long"); }
#line 3614 "c-exp.c.tmp"
    break;

  case 181:
#line 1400 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "short"); }
#line 3621 "c-exp.c.tmp"
    break;

  case 182:
#line 1403 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "short"); }
#line 3628 "c-exp.c.tmp"
    break;

  case 183:
#line 1406 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "short"); }
#line 3635 "c-exp.c.tmp"
    break;

  case 184:
#line 1409 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "short"); }
#line 3642 "c-exp.c.tmp"
    break;

  case 185:
#line 1412 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "short"); }
#line 3649 "c-exp.c.tmp"
    break;

  case 186:
#line 1415 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "short"); }
#line 3656 "c-exp.c.tmp"
    break;

  case 187:
#line 1418 "c-exp.y"
                        { (yyval.tval) = lookup_typename (pstate->language (),
						"double",
						NULL,
						0); }
#line 3665 "c-exp.c.tmp"
    break;

  case 188:
#line 1423 "c-exp.y"
                        { (yyval.tval) = lookup_typename (pstate->language (),
						"float",
						NULL,
						0); }
#line 3674 "c-exp.c.tmp"
    break;

  case 189:
#line 1428 "c-exp.y"
                        { (yyval.tval) = lookup_typename (pstate->language (),
						"long double",
						NULL,
						0); }
#line 3683 "c-exp.c.tmp"
    break;

  case 190:
#line 1433 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 (yyvsp[0].tsym).type->name ()); }
#line 3690 "c-exp.c.tmp"
    break;

  case 191:
#line 1436 "c-exp.y"
                        { (yyval.tval) = lookup_unsigned_typename (pstate->language (),
							 "int"); }
#line 3697 "c-exp.c.tmp"
    break;

  case 192:
#line 1439 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       (yyvsp[0].tsym).type->name ()); }
#line 3704 "c-exp.c.tmp"
    break;

  case 193:
#line 1442 "c-exp.y"
                        { (yyval.tval) = lookup_signed_typename (pstate->language (),
						       "int"); }
#line 3711 "c-exp.c.tmp"
    break;

  case 194:
#line 1458 "c-exp.y"
                        { (yyval.tval) = (yyvsp[0].tsym).type; }
#line 3717 "c-exp.c.tmp"
    break;

  case 195:
#line 1460 "c-exp.y"
                        { (yyval.tval) = (yyvsp[0].tval); }
#line 3723 "c-exp.c.tmp"
    break;

  case 196:
#line 1462 "c-exp.y"
                        {
			  (yyval.tval) = init_complex_type (nullptr, (yyvsp[0].tval));
			}
#line 3731 "c-exp.c.tmp"
    break;

  case 197:
#line 1466 "c-exp.y"
                        { (yyval.tval)
			    = lookup_struct (copy_name ((yyvsp[0].sval)).c_str (),
					     pstate->expression_context_block);
			}
#line 3740 "c-exp.c.tmp"
    break;

  case 198:
#line 1471 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_STRUCT,
						       "", 0);
			  (yyval.tval) = NULL;
			}
#line 3750 "c-exp.c.tmp"
    break;

  case 199:
#line 1477 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_STRUCT,
						       (yyvsp[-1].sval).ptr, (yyvsp[-1].sval).length);
			  (yyval.tval) = NULL;
			}
#line 3760 "c-exp.c.tmp"
    break;

  case 200:
#line 1483 "c-exp.y"
                        { (yyval.tval) = lookup_struct
			    (copy_name ((yyvsp[0].sval)).c_str (),
			     pstate->expression_context_block);
			}
#line 3769 "c-exp.c.tmp"
    break;

  case 201:
#line 1488 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_STRUCT,
						       "", 0);
			  (yyval.tval) = NULL;
			}
#line 3779 "c-exp.c.tmp"
    break;

  case 202:
#line 1494 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_STRUCT,
						       (yyvsp[-1].sval).ptr, (yyvsp[-1].sval).length);
			  (yyval.tval) = NULL;
			}
#line 3789 "c-exp.c.tmp"
    break;

  case 203:
#line 1500 "c-exp.y"
                        { (yyval.tval)
			    = lookup_union (copy_name ((yyvsp[0].sval)).c_str (),
					    pstate->expression_context_block);
			}
#line 3798 "c-exp.c.tmp"
    break;

  case 204:
#line 1505 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_UNION,
						       "", 0);
			  (yyval.tval) = NULL;
			}
#line 3808 "c-exp.c.tmp"
    break;

  case 205:
#line 1511 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_UNION,
						       (yyvsp[-1].sval).ptr, (yyvsp[-1].sval).length);
			  (yyval.tval) = NULL;
			}
#line 3818 "c-exp.c.tmp"
    break;

  case 206:
#line 1517 "c-exp.y"
                        { (yyval.tval) = lookup_enum (copy_name ((yyvsp[0].sval)).c_str (),
					    pstate->expression_context_block);
			}
#line 3826 "c-exp.c.tmp"
    break;

  case 207:
#line 1521 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_ENUM, "", 0);
			  (yyval.tval) = NULL;
			}
#line 3835 "c-exp.c.tmp"
    break;

  case 208:
#line 1526 "c-exp.y"
                        {
			  pstate->mark_completion_tag (TYPE_CODE_ENUM, (yyvsp[-1].sval).ptr,
						       (yyvsp[-1].sval).length);
			  (yyval.tval) = NULL;
			}
#line 3845 "c-exp.c.tmp"
    break;

  case 209:
#line 1535 "c-exp.y"
                        { (yyval.tval) = lookup_template_type
			    (copy_name((yyvsp[-3].sval)).c_str (), (yyvsp[-1].tval),
			     pstate->expression_context_block);
			}
#line 3854 "c-exp.c.tmp"
    break;

  case 210:
#line 1540 "c-exp.y"
                        { (yyval.tval) = cpstate->type_stack.follow_types ((yyvsp[0].tval)); }
#line 3860 "c-exp.c.tmp"
    break;

  case 211:
#line 1542 "c-exp.y"
                        { (yyval.tval) = cpstate->type_stack.follow_types ((yyvsp[-1].tval)); }
#line 3866 "c-exp.c.tmp"
    break;

  case 213:
#line 1547 "c-exp.y"
                {
		  (yyval.tsym).stoken.ptr = "int";
		  (yyval.tsym).stoken.length = 3;
		  (yyval.tsym).type = lookup_signed_typename (pstate->language (),
						    "int");
		}
#line 3877 "c-exp.c.tmp"
    break;

  case 214:
#line 1554 "c-exp.y"
                {
		  (yyval.tsym).stoken.ptr = "long";
		  (yyval.tsym).stoken.length = 4;
		  (yyval.tsym).type = lookup_signed_typename (pstate->language (),
						    "long");
		}
#line 3888 "c-exp.c.tmp"
    break;

  case 215:
#line 1561 "c-exp.y"
                {
		  (yyval.tsym).stoken.ptr = "short";
		  (yyval.tsym).stoken.length = 5;
		  (yyval.tsym).type = lookup_signed_typename (pstate->language (),
						    "short");
		}
#line 3899 "c-exp.c.tmp"
    break;

  case 216:
#line 1571 "c-exp.y"
                        { check_parameter_typelist ((yyvsp[0].tvec)); }
#line 3905 "c-exp.c.tmp"
    break;

  case 217:
#line 1573 "c-exp.y"
                        {
			  (yyvsp[-2].tvec)->push_back (NULL);
			  check_parameter_typelist ((yyvsp[-2].tvec));
			  (yyval.tvec) = (yyvsp[-2].tvec);
			}
#line 3915 "c-exp.c.tmp"
    break;

  case 218:
#line 1582 "c-exp.y"
                {
		  std::vector<struct type *> *typelist
		    = new std::vector<struct type *>;
		  cpstate->type_lists.emplace_back (typelist);

		  typelist->push_back ((yyvsp[0].tval));
		  (yyval.tvec) = typelist;
		}
#line 3928 "c-exp.c.tmp"
    break;

  case 219:
#line 1591 "c-exp.y"
                {
		  (yyvsp[-2].tvec)->push_back ((yyvsp[0].tval));
		  (yyval.tvec) = (yyvsp[-2].tvec);
		}
#line 3937 "c-exp.c.tmp"
    break;

  case 221:
#line 1599 "c-exp.y"
                {
		  cpstate->type_stack.push ((yyvsp[0].type_stack));
		  (yyval.tval) = cpstate->type_stack.follow_types ((yyvsp[-1].tval));
		}
#line 3946 "c-exp.c.tmp"
    break;

  case 222:
#line 1606 "c-exp.y"
                { (yyval.tval) = cpstate->type_stack.follow_types ((yyvsp[-1].tval)); }
#line 3952 "c-exp.c.tmp"
    break;

  case 227:
#line 1618 "c-exp.y"
                        { cpstate->type_stack.insert (tp_const);
			  cpstate->type_stack.insert (tp_volatile);
			}
#line 3960 "c-exp.c.tmp"
    break;

  case 228:
#line 1622 "c-exp.y"
                        { cpstate->type_stack.insert (tp_const); }
#line 3966 "c-exp.c.tmp"
    break;

  case 229:
#line 1624 "c-exp.y"
                        { cpstate->type_stack.insert (tp_volatile); }
#line 3972 "c-exp.c.tmp"
    break;

  case 230:
#line 1628 "c-exp.y"
                        { (yyval.sval) = operator_stoken (" new"); }
#line 3978 "c-exp.c.tmp"
    break;

  case 231:
#line 1630 "c-exp.y"
                        { (yyval.sval) = operator_stoken (" delete"); }
#line 3984 "c-exp.c.tmp"
    break;

  case 232:
#line 1632 "c-exp.y"
                        { (yyval.sval) = operator_stoken (" new[]"); }
#line 3990 "c-exp.c.tmp"
    break;

  case 233:
#line 1634 "c-exp.y"
                        { (yyval.sval) = operator_stoken (" delete[]"); }
#line 3996 "c-exp.c.tmp"
    break;

  case 234:
#line 1636 "c-exp.y"
                        { (yyval.sval) = operator_stoken (" new[]"); }
#line 4002 "c-exp.c.tmp"
    break;

  case 235:
#line 1638 "c-exp.y"
                        { (yyval.sval) = operator_stoken (" delete[]"); }
#line 4008 "c-exp.c.tmp"
    break;

  case 236:
#line 1640 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("+"); }
#line 4014 "c-exp.c.tmp"
    break;

  case 237:
#line 1642 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("-"); }
#line 4020 "c-exp.c.tmp"
    break;

  case 238:
#line 1644 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("*"); }
#line 4026 "c-exp.c.tmp"
    break;

  case 239:
#line 1646 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("/"); }
#line 4032 "c-exp.c.tmp"
    break;

  case 240:
#line 1648 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("%"); }
#line 4038 "c-exp.c.tmp"
    break;

  case 241:
#line 1650 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("^"); }
#line 4044 "c-exp.c.tmp"
    break;

  case 242:
#line 1652 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("&"); }
#line 4050 "c-exp.c.tmp"
    break;

  case 243:
#line 1654 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("|"); }
#line 4056 "c-exp.c.tmp"
    break;

  case 244:
#line 1656 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("~"); }
#line 4062 "c-exp.c.tmp"
    break;

  case 245:
#line 1658 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("!"); }
#line 4068 "c-exp.c.tmp"
    break;

  case 246:
#line 1660 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("="); }
#line 4074 "c-exp.c.tmp"
    break;

  case 247:
#line 1662 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("<"); }
#line 4080 "c-exp.c.tmp"
    break;

  case 248:
#line 1664 "c-exp.y"
                        { (yyval.sval) = operator_stoken (">"); }
#line 4086 "c-exp.c.tmp"
    break;

  case 249:
#line 1666 "c-exp.y"
                        { const char *op = " unknown";
			  switch ((yyvsp[0].opcode))
			    {
			    case BINOP_RSH:
			      op = ">>=";
			      break;
			    case BINOP_LSH:
			      op = "<<=";
			      break;
			    case BINOP_ADD:
			      op = "+=";
			      break;
			    case BINOP_SUB:
			      op = "-=";
			      break;
			    case BINOP_MUL:
			      op = "*=";
			      break;
			    case BINOP_DIV:
			      op = "/=";
			      break;
			    case BINOP_REM:
			      op = "%=";
			      break;
			    case BINOP_BITWISE_IOR:
			      op = "|=";
			      break;
			    case BINOP_BITWISE_AND:
			      op = "&=";
			      break;
			    case BINOP_BITWISE_XOR:
			      op = "^=";
			      break;
			    default:
			      break;
			    }

			  (yyval.sval) = operator_stoken (op);
			}
#line 4130 "c-exp.c.tmp"
    break;

  case 250:
#line 1706 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("<<"); }
#line 4136 "c-exp.c.tmp"
    break;

  case 251:
#line 1708 "c-exp.y"
                        { (yyval.sval) = operator_stoken (">>"); }
#line 4142 "c-exp.c.tmp"
    break;

  case 252:
#line 1710 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("=="); }
#line 4148 "c-exp.c.tmp"
    break;

  case 253:
#line 1712 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("!="); }
#line 4154 "c-exp.c.tmp"
    break;

  case 254:
#line 1714 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("<="); }
#line 4160 "c-exp.c.tmp"
    break;

  case 255:
#line 1716 "c-exp.y"
                        { (yyval.sval) = operator_stoken (">="); }
#line 4166 "c-exp.c.tmp"
    break;

  case 256:
#line 1718 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("&&"); }
#line 4172 "c-exp.c.tmp"
    break;

  case 257:
#line 1720 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("||"); }
#line 4178 "c-exp.c.tmp"
    break;

  case 258:
#line 1722 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("++"); }
#line 4184 "c-exp.c.tmp"
    break;

  case 259:
#line 1724 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("--"); }
#line 4190 "c-exp.c.tmp"
    break;

  case 260:
#line 1726 "c-exp.y"
                        { (yyval.sval) = operator_stoken (","); }
#line 4196 "c-exp.c.tmp"
    break;

  case 261:
#line 1728 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("->*"); }
#line 4202 "c-exp.c.tmp"
    break;

  case 262:
#line 1730 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("->"); }
#line 4208 "c-exp.c.tmp"
    break;

  case 263:
#line 1732 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("()"); }
#line 4214 "c-exp.c.tmp"
    break;

  case 264:
#line 1734 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("[]"); }
#line 4220 "c-exp.c.tmp"
    break;

  case 265:
#line 1736 "c-exp.y"
                        { (yyval.sval) = operator_stoken ("[]"); }
#line 4226 "c-exp.c.tmp"
    break;

  case 266:
#line 1738 "c-exp.y"
                        { string_file buf;

			  c_print_type ((yyvsp[0].tval), NULL, &buf, -1, 0,
					&type_print_raw_options);
			  std::string name = std::move (buf.string ());

			  /* This also needs canonicalization.  */
			  gdb::unique_xmalloc_ptr<char> canon
			    = cp_canonicalize_string (name.c_str ());
			  if (canon != nullptr)
			    name = canon.get ();
			  (yyval.sval) = operator_stoken ((" " + name).c_str ());
			}
#line 4244 "c-exp.c.tmp"
    break;

  case 268:
#line 1760 "c-exp.y"
                               { (yyval.sval) = typename_stoken ("double"); }
#line 4250 "c-exp.c.tmp"
    break;

  case 269:
#line 1761 "c-exp.y"
                              { (yyval.sval) = typename_stoken ("float"); }
#line 4256 "c-exp.c.tmp"
    break;

  case 270:
#line 1762 "c-exp.y"
                            { (yyval.sval) = typename_stoken ("int"); }
#line 4262 "c-exp.c.tmp"
    break;

  case 271:
#line 1763 "c-exp.y"
                     { (yyval.sval) = typename_stoken ("long"); }
#line 4268 "c-exp.c.tmp"
    break;

  case 272:
#line 1764 "c-exp.y"
                      { (yyval.sval) = typename_stoken ("short"); }
#line 4274 "c-exp.c.tmp"
    break;

  case 273:
#line 1765 "c-exp.y"
                               { (yyval.sval) = typename_stoken ("signed"); }
#line 4280 "c-exp.c.tmp"
    break;

  case 274:
#line 1766 "c-exp.y"
                         { (yyval.sval) = typename_stoken ("unsigned"); }
#line 4286 "c-exp.c.tmp"
    break;

  case 275:
#line 1769 "c-exp.y"
                     { (yyval.sval) = (yyvsp[0].ssym).stoken; }
#line 4292 "c-exp.c.tmp"
    break;

  case 276:
#line 1770 "c-exp.y"
                          { (yyval.sval) = (yyvsp[0].ssym).stoken; }
#line 4298 "c-exp.c.tmp"
    break;

  case 277:
#line 1771 "c-exp.y"
                         { (yyval.sval) = (yyvsp[0].tsym).stoken; }
#line 4304 "c-exp.c.tmp"
    break;

  case 278:
#line 1772 "c-exp.y"
                             { (yyval.sval) = (yyvsp[0].ssym).stoken; }
#line 4310 "c-exp.c.tmp"
    break;

  case 279:
#line 1773 "c-exp.y"
                                  { (yyval.sval) = (yyvsp[0].ssym).stoken; }
#line 4316 "c-exp.c.tmp"
    break;

  case 280:
#line 1774 "c-exp.y"
                     { (yyval.sval) = (yyvsp[0].sval); }
#line 4322 "c-exp.c.tmp"
    break;

  case 283:
#line 1787 "c-exp.y"
                        {
			  struct field_of_this_result is_a_field_of_this;

			  (yyval.ssym).stoken = (yyvsp[0].sval);
			  (yyval.ssym).sym
			    = lookup_symbol ((yyvsp[0].sval).ptr,
					     pstate->expression_context_block,
					     VAR_DOMAIN,
					     &is_a_field_of_this);
			  (yyval.ssym).is_a_field_of_this
			    = is_a_field_of_this.type != NULL;
			}
#line 4339 "c-exp.c.tmp"
    break;


#line 4343 "c-exp.c.tmp"

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
#line 1802 "c-exp.y"


/* Like write_exp_string, but prepends a '~'.  */

static void
write_destructor_name (struct parser_state *par_state, struct stoken token)
{
  char *copy = (char *) alloca (token.length + 1);

  copy[0] = '~';
  memcpy (&copy[1], token.ptr, token.length);

  token.ptr = copy;
  ++token.length;

  write_exp_string (par_state, token);
}

/* Returns a stoken of the operator name given by OP (which does not
   include the string "operator").  */

static struct stoken
operator_stoken (const char *op)
{
  struct stoken st = { NULL, 0 };
  char *buf;

  st.length = CP_OPERATOR_LEN + strlen (op);
  buf = (char *) xmalloc (st.length + 1);
  strcpy (buf, CP_OPERATOR_STR);
  strcat (buf, op);
  st.ptr = buf;

  /* The toplevel (c_parse) will free the memory allocated here.  */
  cpstate->strings.emplace_back (buf);
  return st;
};

/* Returns a stoken of the type named TYPE.  */

static struct stoken
typename_stoken (const char *type)
{
  struct stoken st = { type, 0 };
  st.length = strlen (type);
  return st;
};

/* Return true if the type is aggregate-like.  */

static int
type_aggregate_p (struct type *type)
{
  return (type->code () == TYPE_CODE_STRUCT
	  || type->code () == TYPE_CODE_UNION
	  || type->code () == TYPE_CODE_NAMESPACE
	  || (type->code () == TYPE_CODE_ENUM
	      && TYPE_DECLARED_CLASS (type)));
}

/* Validate a parameter typelist.  */

static void
check_parameter_typelist (std::vector<struct type *> *params)
{
  struct type *type;
  int ix;

  for (ix = 0; ix < params->size (); ++ix)
    {
      type = (*params)[ix];
      if (type != NULL && check_typedef (type)->code () == TYPE_CODE_VOID)
	{
	  if (ix == 0)
	    {
	      if (params->size () == 1)
		{
		  /* Ok.  */
		  break;
		}
	      error (_("parameter types following 'void'"));
	    }
	  else
	    error (_("'void' invalid as parameter type"));
	}
    }
}

/* Take care of parsing a number (anything that starts with a digit).
   Set yylval and return the token type; update lexptr.
   LEN is the number of characters in it.  */

/*** Needs some error checking for the float case ***/

static int
parse_number (struct parser_state *par_state,
	      const char *buf, int len, int parsed_float, YYSTYPE *putithere)
{
  ULONGEST n = 0;
  ULONGEST prevn = 0;
  ULONGEST un;

  int i = 0;
  int c;
  int base = input_radix;
  int unsigned_p = 0;

  /* Number of "L" suffixes encountered.  */
  int long_p = 0;

  /* Imaginary number.  */
  bool imaginary_p = false;

  /* We have found a "L" or "U" (or "i") suffix.  */
  int found_suffix = 0;

  ULONGEST high_bit;
  struct type *signed_type;
  struct type *unsigned_type;
  char *p;

  p = (char *) alloca (len);
  memcpy (p, buf, len);

  if (parsed_float)
    {
      if (len >= 1 && p[len - 1] == 'i')
	{
	  imaginary_p = true;
	  --len;
	}

      /* Handle suffixes for decimal floating-point: "df", "dd" or "dl".  */
      if (len >= 2 && p[len - 2] == 'd' && p[len - 1] == 'f')
	{
	  putithere->typed_val_float.type
	    = parse_type (par_state)->builtin_decfloat;
	  len -= 2;
	}
      else if (len >= 2 && p[len - 2] == 'd' && p[len - 1] == 'd')
	{
	  putithere->typed_val_float.type
	    = parse_type (par_state)->builtin_decdouble;
	  len -= 2;
	}
      else if (len >= 2 && p[len - 2] == 'd' && p[len - 1] == 'l')
	{
	  putithere->typed_val_float.type
	    = parse_type (par_state)->builtin_declong;
	  len -= 2;
	}
      /* Handle suffixes: 'f' for float, 'l' for long double.  */
      else if (len >= 1 && TOLOWER (p[len - 1]) == 'f')
	{
	  putithere->typed_val_float.type
	    = parse_type (par_state)->builtin_float;
	  len -= 1;
	}
      else if (len >= 1 && TOLOWER (p[len - 1]) == 'l')
	{
	  putithere->typed_val_float.type
	    = parse_type (par_state)->builtin_long_double;
	  len -= 1;
	}
      /* Default type for floating-point literals is double.  */
      else
	{
	  putithere->typed_val_float.type
	    = parse_type (par_state)->builtin_double;
	}

      if (!parse_float (p, len,
			putithere->typed_val_float.type,
			putithere->typed_val_float.val))
        return ERROR;

      if (imaginary_p)
	putithere->typed_val_float.type
	  = init_complex_type (nullptr, putithere->typed_val_float.type);

      return imaginary_p ? COMPLEX_FLOAT : FLOAT;
    }

  /* Handle base-switching prefixes 0x, 0t, 0d, 0 */
  if (p[0] == '0' && len > 1)
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

      case 'b':
      case 'B':
	if (len >= 3)
	  {
	    p += 2;
	    base = 2;
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
      if (c >= 'A' && c <= 'Z')
	c += 'a' - 'A';
      if (c != 'l' && c != 'u' && c != 'i')
	n *= base;
      if (c >= '0' && c <= '9')
	{
	  if (found_suffix)
	    return ERROR;
	  n += i = c - '0';
	}
      else
	{
	  if (base > 10 && c >= 'a' && c <= 'f')
	    {
	      if (found_suffix)
		return ERROR;
	      n += i = c - 'a' + 10;
	    }
	  else if (c == 'l')
	    {
	      ++long_p;
	      found_suffix = 1;
	    }
	  else if (c == 'u')
	    {
	      unsigned_p = 1;
	      found_suffix = 1;
	    }
	  else if (c == 'i')
	    {
	      imaginary_p = true;
	      found_suffix = 1;
	    }
	  else
	    return ERROR;	/* Char not a digit */
	}
      if (i >= base)
	return ERROR;		/* Invalid digit in this base */

      /* Portably test for overflow (only works for nonzero values, so make
	 a second check for zero).  FIXME: Can't we just make n and prevn
	 unsigned and avoid this?  */
      if (c != 'l' && c != 'u' && c != 'i' && (prevn >= n) && n != 0)
	unsigned_p = 1;		/* Try something unsigned */

      /* Portably test for unsigned overflow.
	 FIXME: This check is wrong; for example it doesn't find overflow
	 on 0x123456789 when LONGEST is 32 bits.  */
      if (c != 'l' && c != 'u' && c != 'i' && n != 0)
	{	
	  if (unsigned_p && prevn >= n)
	    error (_("Numeric constant too large."));
	}
      prevn = n;
    }

  /* An integer constant is an int, a long, or a long long.  An L
     suffix forces it to be long; an LL suffix forces it to be long
     long.  If not forced to a larger size, it gets the first type of
     the above that it fits in.  To figure out whether it fits, we
     shift it right and see whether anything remains.  Note that we
     can't shift sizeof (LONGEST) * HOST_CHAR_BIT bits or more in one
     operation, because many compilers will warn about such a shift
     (which always produces a zero result).  Sometimes gdbarch_int_bit
     or gdbarch_long_bit will be that big, sometimes not.  To deal with
     the case where it is we just always shift the value more than
     once, with fewer bits each time.  */

  un = n >> 2;
  if (long_p == 0
      && (un >> (gdbarch_int_bit (par_state->gdbarch ()) - 2)) == 0)
    {
      high_bit
	= ((ULONGEST)1) << (gdbarch_int_bit (par_state->gdbarch ()) - 1);

      /* A large decimal (not hex or octal) constant (between INT_MAX
	 and UINT_MAX) is a long or unsigned long, according to ANSI,
	 never an unsigned int, but this code treats it as unsigned
	 int.  This probably should be fixed.  GCC gives a warning on
	 such constants.  */

      unsigned_type = parse_type (par_state)->builtin_unsigned_int;
      signed_type = parse_type (par_state)->builtin_int;
    }
  else if (long_p <= 1
	   && (un >> (gdbarch_long_bit (par_state->gdbarch ()) - 2)) == 0)
    {
      high_bit
	= ((ULONGEST)1) << (gdbarch_long_bit (par_state->gdbarch ()) - 1);
      unsigned_type = parse_type (par_state)->builtin_unsigned_long;
      signed_type = parse_type (par_state)->builtin_long;
    }
  else
    {
      int shift;
      if (sizeof (ULONGEST) * HOST_CHAR_BIT
	  < gdbarch_long_long_bit (par_state->gdbarch ()))
	/* A long long does not fit in a LONGEST.  */
	shift = (sizeof (ULONGEST) * HOST_CHAR_BIT - 1);
      else
	shift = (gdbarch_long_long_bit (par_state->gdbarch ()) - 1);
      high_bit = (ULONGEST) 1 << shift;
      unsigned_type = parse_type (par_state)->builtin_unsigned_long_long;
      signed_type = parse_type (par_state)->builtin_long_long;
    }

   putithere->typed_val_int.val = n;

   /* If the high bit of the worked out type is set then this number
      has to be unsigned. */

   if (unsigned_p || (n & high_bit))
     {
       putithere->typed_val_int.type = unsigned_type;
     }
   else
     {
       putithere->typed_val_int.type = signed_type;
     }

   if (imaginary_p)
     putithere->typed_val_int.type
       = init_complex_type (nullptr, putithere->typed_val_int.type);

   return imaginary_p ? COMPLEX_INT : INT;
}

/* Temporary obstack used for holding strings.  */
static struct obstack tempbuf;
static int tempbuf_init;

/* Parse a C escape sequence.  The initial backslash of the sequence
   is at (*PTR)[-1].  *PTR will be updated to point to just after the
   last character of the sequence.  If OUTPUT is not NULL, the
   translated form of the escape sequence will be written there.  If
   OUTPUT is NULL, no output is written and the call will only affect
   *PTR.  If an escape sequence is expressed in target bytes, then the
   entire sequence will simply be copied to OUTPUT.  Return 1 if any
   character was emitted, 0 otherwise.  */

int
c_parse_escape (const char **ptr, struct obstack *output)
{
  const char *tokptr = *ptr;
  int result = 1;

  /* Some escape sequences undergo character set conversion.  Those we
     translate here.  */
  switch (*tokptr)
    {
      /* Hex escapes do not undergo character set conversion, so keep
	 the escape sequence for later.  */
    case 'x':
      if (output)
	obstack_grow_str (output, "\\x");
      ++tokptr;
      if (!ISXDIGIT (*tokptr))
	error (_("\\x escape without a following hex digit"));
      while (ISXDIGIT (*tokptr))
	{
	  if (output)
	    obstack_1grow (output, *tokptr);
	  ++tokptr;
	}
      break;

      /* Octal escapes do not undergo character set conversion, so
	 keep the escape sequence for later.  */
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      {
	int i;
	if (output)
	  obstack_grow_str (output, "\\");
	for (i = 0;
	     i < 3 && ISDIGIT (*tokptr) && *tokptr != '8' && *tokptr != '9';
	     ++i)
	  {
	    if (output)
	      obstack_1grow (output, *tokptr);
	    ++tokptr;
	  }
      }
      break;

      /* We handle UCNs later.  We could handle them here, but that
	 would mean a spurious error in the case where the UCN could
	 be converted to the target charset but not the host
	 charset.  */
    case 'u':
    case 'U':
      {
	char c = *tokptr;
	int i, len = c == 'U' ? 8 : 4;
	if (output)
	  {
	    obstack_1grow (output, '\\');
	    obstack_1grow (output, *tokptr);
	  }
	++tokptr;
	if (!ISXDIGIT (*tokptr))
	  error (_("\\%c escape without a following hex digit"), c);
	for (i = 0; i < len && ISXDIGIT (*tokptr); ++i)
	  {
	    if (output)
	      obstack_1grow (output, *tokptr);
	    ++tokptr;
	  }
      }
      break;

      /* We must pass backslash through so that it does not
	 cause quoting during the second expansion.  */
    case '\\':
      if (output)
	obstack_grow_str (output, "\\\\");
      ++tokptr;
      break;

      /* Escapes which undergo conversion.  */
    case 'a':
      if (output)
	obstack_1grow (output, '\a');
      ++tokptr;
      break;
    case 'b':
      if (output)
	obstack_1grow (output, '\b');
      ++tokptr;
      break;
    case 'f':
      if (output)
	obstack_1grow (output, '\f');
      ++tokptr;
      break;
    case 'n':
      if (output)
	obstack_1grow (output, '\n');
      ++tokptr;
      break;
    case 'r':
      if (output)
	obstack_1grow (output, '\r');
      ++tokptr;
      break;
    case 't':
      if (output)
	obstack_1grow (output, '\t');
      ++tokptr;
      break;
    case 'v':
      if (output)
	obstack_1grow (output, '\v');
      ++tokptr;
      break;

      /* GCC extension.  */
    case 'e':
      if (output)
	obstack_1grow (output, HOST_ESCAPE_CHAR);
      ++tokptr;
      break;

      /* Backslash-newline expands to nothing at all.  */
    case '\n':
      ++tokptr;
      result = 0;
      break;

      /* A few escapes just expand to the character itself.  */
    case '\'':
    case '\"':
    case '?':
      /* GCC extensions.  */
    case '(':
    case '{':
    case '[':
    case '%':
      /* Unrecognized escapes turn into the character itself.  */
    default:
      if (output)
	obstack_1grow (output, *tokptr);
      ++tokptr;
      break;
    }
  *ptr = tokptr;
  return result;
}

/* Parse a string or character literal from TOKPTR.  The string or
   character may be wide or unicode.  *OUTPTR is set to just after the
   end of the literal in the input string.  The resulting token is
   stored in VALUE.  This returns a token value, either STRING or
   CHAR, depending on what was parsed.  *HOST_CHARS is set to the
   number of host characters in the literal.  */

static int
parse_string_or_char (const char *tokptr, const char **outptr,
		      struct typed_stoken *value, int *host_chars)
{
  int quote;
  c_string_type type;
  int is_objc = 0;

  /* Build the gdb internal form of the input string in tempbuf.  Note
     that the buffer is null byte terminated *only* for the
     convenience of debugging gdb itself and printing the buffer
     contents when the buffer contains no embedded nulls.  Gdb does
     not depend upon the buffer being null byte terminated, it uses
     the length string instead.  This allows gdb to handle C strings
     (as well as strings in other languages) with embedded null
     bytes */

  if (!tempbuf_init)
    tempbuf_init = 1;
  else
    obstack_free (&tempbuf, NULL);
  obstack_init (&tempbuf);

  /* Record the string type.  */
  if (*tokptr == 'L')
    {
      type = C_WIDE_STRING;
      ++tokptr;
    }
  else if (*tokptr == 'u')
    {
      type = C_STRING_16;
      ++tokptr;
    }
  else if (*tokptr == 'U')
    {
      type = C_STRING_32;
      ++tokptr;
    }
  else if (*tokptr == '@')
    {
      /* An Objective C string.  */
      is_objc = 1;
      type = C_STRING;
      ++tokptr;
    }
  else
    type = C_STRING;

  /* Skip the quote.  */
  quote = *tokptr;
  if (quote == '\'')
    type |= C_CHAR;
  ++tokptr;

  *host_chars = 0;

  while (*tokptr)
    {
      char c = *tokptr;
      if (c == '\\')
	{
	  ++tokptr;
	  *host_chars += c_parse_escape (&tokptr, &tempbuf);
	}
      else if (c == quote)
	break;
      else
	{
	  obstack_1grow (&tempbuf, c);
	  ++tokptr;
	  /* FIXME: this does the wrong thing with multi-byte host
	     characters.  We could use mbrlen here, but that would
	     make "set host-charset" a bit less useful.  */
	  ++*host_chars;
	}
    }

  if (*tokptr != quote)
    {
      if (quote == '"')
	error (_("Unterminated string in expression."));
      else
	error (_("Unmatched single quote."));
    }
  ++tokptr;

  value->type = type;
  value->ptr = (char *) obstack_base (&tempbuf);
  value->length = obstack_object_size (&tempbuf);

  *outptr = tokptr;

  return quote == '"' ? (is_objc ? NSSTRING : STRING) : CHAR;
}

/* This is used to associate some attributes with a token.  */

enum token_flag
{
  /* If this bit is set, the token is C++-only.  */

  FLAG_CXX = 1,

  /* If this bit is set, the token is C-only.  */

  FLAG_C = 2,

  /* If this bit is set, the token is conditional: if there is a
     symbol of the same name, then the token is a symbol; otherwise,
     the token is a keyword.  */

  FLAG_SHADOW = 4
};
DEF_ENUM_FLAGS_TYPE (enum token_flag, token_flags);

struct token
{
  const char *oper;
  int token;
  enum exp_opcode opcode;
  token_flags flags;
};

static const struct token tokentab3[] =
  {
    {">>=", ASSIGN_MODIFY, BINOP_RSH, 0},
    {"<<=", ASSIGN_MODIFY, BINOP_LSH, 0},
    {"->*", ARROW_STAR, BINOP_END, FLAG_CXX},
    {"...", DOTDOTDOT, BINOP_END, 0}
  };

static const struct token tokentab2[] =
  {
    {"+=", ASSIGN_MODIFY, BINOP_ADD, 0},
    {"-=", ASSIGN_MODIFY, BINOP_SUB, 0},
    {"*=", ASSIGN_MODIFY, BINOP_MUL, 0},
    {"/=", ASSIGN_MODIFY, BINOP_DIV, 0},
    {"%=", ASSIGN_MODIFY, BINOP_REM, 0},
    {"|=", ASSIGN_MODIFY, BINOP_BITWISE_IOR, 0},
    {"&=", ASSIGN_MODIFY, BINOP_BITWISE_AND, 0},
    {"^=", ASSIGN_MODIFY, BINOP_BITWISE_XOR, 0},
    {"++", INCREMENT, BINOP_END, 0},
    {"--", DECREMENT, BINOP_END, 0},
    {"->", ARROW, BINOP_END, 0},
    {"&&", ANDAND, BINOP_END, 0},
    {"||", OROR, BINOP_END, 0},
    /* "::" is *not* only C++: gdb overrides its meaning in several
       different ways, e.g., 'filename'::func, function::variable.  */
    {"::", COLONCOLON, BINOP_END, 0},
    {"<<", LSH, BINOP_END, 0},
    {">>", RSH, BINOP_END, 0},
    {"==", EQUAL, BINOP_END, 0},
    {"!=", NOTEQUAL, BINOP_END, 0},
    {"<=", LEQ, BINOP_END, 0},
    {">=", GEQ, BINOP_END, 0},
    {".*", DOT_STAR, BINOP_END, FLAG_CXX}
  };

/* Identifier-like tokens.  Only type-specifiers than can appear in
   multi-word type names (for example 'double' can appear in 'long
   double') need to be listed here.  type-specifiers that are only ever
   single word (like 'char') are handled by the classify_name function.  */
static const struct token ident_tokens[] =
  {
    {"unsigned", UNSIGNED, OP_NULL, 0},
    {"template", TEMPLATE, OP_NULL, FLAG_CXX},
    {"volatile", VOLATILE_KEYWORD, OP_NULL, 0},
    {"struct", STRUCT, OP_NULL, 0},
    {"signed", SIGNED_KEYWORD, OP_NULL, 0},
    {"sizeof", SIZEOF, OP_NULL, 0},
    {"_Alignof", ALIGNOF, OP_NULL, 0},
    {"alignof", ALIGNOF, OP_NULL, FLAG_CXX},
    {"double", DOUBLE_KEYWORD, OP_NULL, 0},
    {"float", FLOAT_KEYWORD, OP_NULL, 0},
    {"false", FALSEKEYWORD, OP_NULL, FLAG_CXX},
    {"class", CLASS, OP_NULL, FLAG_CXX},
    {"union", UNION, OP_NULL, 0},
    {"short", SHORT, OP_NULL, 0},
    {"const", CONST_KEYWORD, OP_NULL, 0},
    {"restrict", RESTRICT, OP_NULL, FLAG_C | FLAG_SHADOW},
    {"__restrict__", RESTRICT, OP_NULL, 0},
    {"__restrict", RESTRICT, OP_NULL, 0},
    {"_Atomic", ATOMIC, OP_NULL, 0},
    {"enum", ENUM, OP_NULL, 0},
    {"long", LONG, OP_NULL, 0},
    {"_Complex", COMPLEX, OP_NULL, 0},
    {"__complex__", COMPLEX, OP_NULL, 0},

    {"true", TRUEKEYWORD, OP_NULL, FLAG_CXX},
    {"int", INT_KEYWORD, OP_NULL, 0},
    {"new", NEW, OP_NULL, FLAG_CXX},
    {"delete", DELETE, OP_NULL, FLAG_CXX},
    {"operator", OPERATOR, OP_NULL, FLAG_CXX},

    {"and", ANDAND, BINOP_END, FLAG_CXX},
    {"and_eq", ASSIGN_MODIFY, BINOP_BITWISE_AND, FLAG_CXX},
    {"bitand", '&', OP_NULL, FLAG_CXX},
    {"bitor", '|', OP_NULL, FLAG_CXX},
    {"compl", '~', OP_NULL, FLAG_CXX},
    {"not", '!', OP_NULL, FLAG_CXX},
    {"not_eq", NOTEQUAL, BINOP_END, FLAG_CXX},
    {"or", OROR, BINOP_END, FLAG_CXX},
    {"or_eq", ASSIGN_MODIFY, BINOP_BITWISE_IOR, FLAG_CXX},
    {"xor", '^', OP_NULL, FLAG_CXX},
    {"xor_eq", ASSIGN_MODIFY, BINOP_BITWISE_XOR, FLAG_CXX},

    {"const_cast", CONST_CAST, OP_NULL, FLAG_CXX },
    {"dynamic_cast", DYNAMIC_CAST, OP_NULL, FLAG_CXX },
    {"static_cast", STATIC_CAST, OP_NULL, FLAG_CXX },
    {"reinterpret_cast", REINTERPRET_CAST, OP_NULL, FLAG_CXX },

    {"__typeof__", TYPEOF, OP_TYPEOF, 0 },
    {"__typeof", TYPEOF, OP_TYPEOF, 0 },
    {"typeof", TYPEOF, OP_TYPEOF, FLAG_SHADOW },
    {"__decltype", DECLTYPE, OP_DECLTYPE, FLAG_CXX },
    {"decltype", DECLTYPE, OP_DECLTYPE, FLAG_CXX | FLAG_SHADOW },

    {"typeid", TYPEID, OP_TYPEID, FLAG_CXX}
  };


static void
scan_macro_expansion (const char *expansion)
{
  /* We'd better not be trying to push the stack twice.  */
  gdb_assert (! cpstate->macro_original_text);

  /* Copy to the obstack.  */
  const char *copy = obstack_strdup (&cpstate->expansion_obstack, expansion);

  /* Save the old lexptr value, so we can return to it when we're done
     parsing the expanded text.  */
  cpstate->macro_original_text = pstate->lexptr;
  pstate->lexptr = copy;
}

static int
scanning_macro_expansion (void)
{
  return cpstate->macro_original_text != 0;
}

static void
finished_macro_expansion (void)
{
  /* There'd better be something to pop back to.  */
  gdb_assert (cpstate->macro_original_text);

  /* Pop back to the original text.  */
  pstate->lexptr = cpstate->macro_original_text;
  cpstate->macro_original_text = 0;
}

/* Return true iff the token represents a C++ cast operator.  */

static int
is_cast_operator (const char *token, int len)
{
  return (! strncmp (token, "dynamic_cast", len)
	  || ! strncmp (token, "static_cast", len)
	  || ! strncmp (token, "reinterpret_cast", len)
	  || ! strncmp (token, "const_cast", len));
}

/* The scope used for macro expansion.  */
static struct macro_scope *expression_macro_scope;

/* This is set if a NAME token appeared at the very end of the input
   string, with no whitespace separating the name from the EOF.  This
   is used only when parsing to do field name completion.  */
static int saw_name_at_eof;

/* This is set if the previously-returned token was a structure
   operator -- either '.' or ARROW.  */
static bool last_was_structop;

/* Depth of parentheses.  */
static int paren_depth;

/* Read one token, getting characters through lexptr.  */

static int
lex_one_token (struct parser_state *par_state, bool *is_quoted_name)
{
  int c;
  int namelen;
  unsigned int i;
  const char *tokstart;
  bool saw_structop = last_was_structop;

  last_was_structop = false;
  *is_quoted_name = false;

 retry:

  /* Check if this is a macro invocation that we need to expand.  */
  if (! scanning_macro_expansion ())
    {
      gdb::unique_xmalloc_ptr<char> expanded
	= macro_expand_next (&pstate->lexptr, *expression_macro_scope);

      if (expanded != nullptr)
        scan_macro_expansion (expanded.get ());
    }

  pstate->prev_lexptr = pstate->lexptr;

  tokstart = pstate->lexptr;
  /* See if it is a special token of length 3.  */
  for (i = 0; i < sizeof tokentab3 / sizeof tokentab3[0]; i++)
    if (strncmp (tokstart, tokentab3[i].oper, 3) == 0)
      {
	if ((tokentab3[i].flags & FLAG_CXX) != 0
	    && par_state->language ()->la_language != language_cplus)
	  break;
	gdb_assert ((tokentab3[i].flags & FLAG_C) == 0);

	pstate->lexptr += 3;
	yylval.opcode = tokentab3[i].opcode;
	return tokentab3[i].token;
      }

  /* See if it is a special token of length 2.  */
  for (i = 0; i < sizeof tokentab2 / sizeof tokentab2[0]; i++)
    if (strncmp (tokstart, tokentab2[i].oper, 2) == 0)
      {
	if ((tokentab2[i].flags & FLAG_CXX) != 0
	    && par_state->language ()->la_language != language_cplus)
	  break;
	gdb_assert ((tokentab2[i].flags & FLAG_C) == 0);

	pstate->lexptr += 2;
	yylval.opcode = tokentab2[i].opcode;
	if (tokentab2[i].token == ARROW)
	  last_was_structop = 1;
	return tokentab2[i].token;
      }

  switch (c = *tokstart)
    {
    case 0:
      /* If we were just scanning the result of a macro expansion,
         then we need to resume scanning the original text.
	 If we're parsing for field name completion, and the previous
	 token allows such completion, return a COMPLETE token.
         Otherwise, we were already scanning the original text, and
         we're really done.  */
      if (scanning_macro_expansion ())
        {
          finished_macro_expansion ();
          goto retry;
        }
      else if (saw_name_at_eof)
	{
	  saw_name_at_eof = 0;
	  return COMPLETE;
	}
      else if (par_state->parse_completion && saw_structop)
	return COMPLETE;
      else
        return 0;

    case ' ':
    case '\t':
    case '\n':
      pstate->lexptr++;
      goto retry;

    case '[':
    case '(':
      paren_depth++;
      pstate->lexptr++;
      if (par_state->language ()->la_language == language_objc
	  && c == '[')
	return OBJC_LBRAC;
      return c;

    case ']':
    case ')':
      if (paren_depth == 0)
	return 0;
      paren_depth--;
      pstate->lexptr++;
      return c;

    case ',':
      if (pstate->comma_terminates
          && paren_depth == 0
          && ! scanning_macro_expansion ())
	return 0;
      pstate->lexptr++;
      return c;

    case '.':
      /* Might be a floating point number.  */
      if (pstate->lexptr[1] < '0' || pstate->lexptr[1] > '9')
	{
	  last_was_structop = true;
	  goto symbol;		/* Nope, must be a symbol. */
	}
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
	int got_dot = 0, got_e = 0, got_p = 0, toktype;
	const char *p = tokstart;
	int hex = input_radix > 10;

	if (c == '0' && (p[1] == 'x' || p[1] == 'X'))
	  {
	    p += 2;
	    hex = 1;
	  }
	else if (c == '0' && (p[1]=='t' || p[1]=='T' || p[1]=='d' || p[1]=='D'))
	  {
	    p += 2;
	    hex = 0;
	  }

	for (;; ++p)
	  {
	    /* This test includes !hex because 'e' is a valid hex digit
	       and thus does not indicate a floating point number when
	       the radix is hex.  */
	    if (!hex && !got_e && !got_p && (*p == 'e' || *p == 'E'))
	      got_dot = got_e = 1;
	    else if (!got_e && !got_p && (*p == 'p' || *p == 'P'))
	      got_dot = got_p = 1;
	    /* This test does not include !hex, because a '.' always indicates
	       a decimal floating point number regardless of the radix.  */
	    else if (!got_dot && *p == '.')
	      got_dot = 1;
	    else if (((got_e && (p[-1] == 'e' || p[-1] == 'E'))
		      || (got_p && (p[-1] == 'p' || p[-1] == 'P')))
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
	toktype = parse_number (par_state, tokstart, p - tokstart,
				got_dot | got_e | got_p, &yylval);
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

    case '@':
      {
	const char *p = &tokstart[1];

	if (par_state->language ()->la_language == language_objc)
	  {
	    size_t len = strlen ("selector");

	    if (strncmp (p, "selector", len) == 0
		&& (p[len] == '\0' || ISSPACE (p[len])))
	      {
		pstate->lexptr = p + len;
		return SELECTOR;
	      }
	    else if (*p == '"')
	      goto parse_string;
	  }

	while (ISSPACE (*p))
	  p++;
	size_t len = strlen ("entry");
	if (strncmp (p, "entry", len) == 0 && !c_ident_is_alnum (p[len])
	    && p[len] != '_')
	  {
	    pstate->lexptr = &p[len];
	    return ENTRY;
	  }
      }
      /* FALLTHRU */
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
    case '<':
    case '>':
    case '?':
    case ':':
    case '=':
    case '{':
    case '}':
    symbol:
      pstate->lexptr++;
      return c;

    case 'L':
    case 'u':
    case 'U':
      if (tokstart[1] != '"' && tokstart[1] != '\'')
	break;
      /* Fall through.  */
    case '\'':
    case '"':

    parse_string:
      {
	int host_len;
	int result = parse_string_or_char (tokstart, &pstate->lexptr,
					   &yylval.tsval, &host_len);
	if (result == CHAR)
	  {
	    if (host_len == 0)
	      error (_("Empty character constant."));
	    else if (host_len > 2 && c == '\'')
	      {
		++tokstart;
		namelen = pstate->lexptr - tokstart - 1;
		*is_quoted_name = true;

		goto tryname;
	      }
	    else if (host_len > 1)
	      error (_("Invalid character constant."));
	  }
	return result;
      }
    }

  if (!(c == '_' || c == '$' || c_ident_is_alpha (c)))
    /* We must have come across a bad character (e.g. ';').  */
    error (_("Invalid character '%c' in expression."), c);

  /* It's a name.  See how long it is.  */
  namelen = 0;
  for (c = tokstart[namelen];
       (c == '_' || c == '$' || c_ident_is_alnum (c) || c == '<');)
    {
      /* Template parameter lists are part of the name.
	 FIXME: This mishandles `print $a<4&&$a>3'.  */

      if (c == '<')
	{
	  if (! is_cast_operator (tokstart, namelen))
	    {
	      /* Scan ahead to get rest of the template specification.  Note
		 that we look ahead only when the '<' adjoins non-whitespace
		 characters; for comparison expressions, e.g. "a < b > c",
		 there must be spaces before the '<', etc. */
	      const char *p = find_template_name_end (tokstart + namelen);

	      if (p)
		namelen = p - tokstart;
	    }
	  break;
	}
      c = tokstart[++namelen];
    }

  /* The token "if" terminates the expression and is NOT removed from
     the input stream.  It doesn't count if it appears in the
     expansion of a macro.  */
  if (namelen == 2
      && tokstart[0] == 'i'
      && tokstart[1] == 'f'
      && ! scanning_macro_expansion ())
    {
      return 0;
    }

  /* For the same reason (breakpoint conditions), "thread N"
     terminates the expression.  "thread" could be an identifier, but
     an identifier is never followed by a number without intervening
     punctuation.  "task" is similar.  Handle abbreviations of these,
     similarly to breakpoint.c:find_condition_and_thread.  */
  if (namelen >= 1
      && (strncmp (tokstart, "thread", namelen) == 0
	  || strncmp (tokstart, "task", namelen) == 0)
      && (tokstart[namelen] == ' ' || tokstart[namelen] == '\t')
      && ! scanning_macro_expansion ())
    {
      const char *p = tokstart + namelen + 1;

      while (*p == ' ' || *p == '\t')
	p++;
      if (*p >= '0' && *p <= '9')
	return 0;
    }

  pstate->lexptr += namelen;

  tryname:

  yylval.sval.ptr = tokstart;
  yylval.sval.length = namelen;

  /* Catch specific keywords.  */
  std::string copy = copy_name (yylval.sval);
  for (i = 0; i < sizeof ident_tokens / sizeof ident_tokens[0]; i++)
    if (copy == ident_tokens[i].oper)
      {
	if ((ident_tokens[i].flags & FLAG_CXX) != 0
	    && par_state->language ()->la_language != language_cplus)
	  break;
	if ((ident_tokens[i].flags & FLAG_C) != 0
	    && par_state->language ()->la_language != language_c
	    && par_state->language ()->la_language != language_objc)
	  break;

	if ((ident_tokens[i].flags & FLAG_SHADOW) != 0)
	  {
	    struct field_of_this_result is_a_field_of_this;

	    if (lookup_symbol (copy.c_str (),
			       pstate->expression_context_block,
			       VAR_DOMAIN,
			       (par_state->language ()->la_language
			        == language_cplus ? &is_a_field_of_this
				: NULL)).symbol
		!= NULL)
	      {
		/* The keyword is shadowed.  */
		break;
	      }
	  }

	/* It is ok to always set this, even though we don't always
	   strictly need to.  */
	yylval.opcode = ident_tokens[i].opcode;
	return ident_tokens[i].token;
      }

  if (*tokstart == '$')
    return DOLLAR_VARIABLE;

  if (pstate->parse_completion && *pstate->lexptr == '\0')
    saw_name_at_eof = 1;

  yylval.ssym.stoken = yylval.sval;
  yylval.ssym.sym.symbol = NULL;
  yylval.ssym.sym.block = NULL;
  yylval.ssym.is_a_field_of_this = 0;
  return NAME;
}

/* An object of this type is pushed on a FIFO by the "outer" lexer.  */
struct token_and_value
{
  int token;
  YYSTYPE value;
};

/* A FIFO of tokens that have been read but not yet returned to the
   parser.  */
static std::vector<token_and_value> token_fifo;

/* Non-zero if the lexer should return tokens from the FIFO.  */
static int popping;

/* Temporary storage for c_lex; this holds symbol names as they are
   built up.  */
auto_obstack name_obstack;

/* Classify a NAME token.  The contents of the token are in `yylval'.
   Updates yylval and returns the new token type.  BLOCK is the block
   in which lookups start; this can be NULL to mean the global scope.
   IS_QUOTED_NAME is non-zero if the name token was originally quoted
   in single quotes.  IS_AFTER_STRUCTOP is true if this name follows
   a structure operator -- either '.' or ARROW  */

static int
classify_name (struct parser_state *par_state, const struct block *block,
	       bool is_quoted_name, bool is_after_structop)
{
  struct block_symbol bsym;
  struct field_of_this_result is_a_field_of_this;

  std::string copy = copy_name (yylval.sval);

  /* Initialize this in case we *don't* use it in this call; that way
     we can refer to it unconditionally below.  */
  memset (&is_a_field_of_this, 0, sizeof (is_a_field_of_this));

  bsym = lookup_symbol (copy.c_str (), block, VAR_DOMAIN,
			par_state->language ()->la_name_of_this
			? &is_a_field_of_this : NULL);

  if (bsym.symbol && SYMBOL_CLASS (bsym.symbol) == LOC_BLOCK)
    {
      yylval.ssym.sym = bsym;
      yylval.ssym.is_a_field_of_this = is_a_field_of_this.type != NULL;
      return BLOCKNAME;
    }
  else if (!bsym.symbol)
    {
      /* If we found a field of 'this', we might have erroneously
	 found a constructor where we wanted a type name.  Handle this
	 case by noticing that we found a constructor and then look up
	 the type tag instead.  */
      if (is_a_field_of_this.type != NULL
	  && is_a_field_of_this.fn_field != NULL
	  && TYPE_FN_FIELD_CONSTRUCTOR (is_a_field_of_this.fn_field->fn_fields,
					0))
	{
	  struct field_of_this_result inner_is_a_field_of_this;

	  bsym = lookup_symbol (copy.c_str (), block, STRUCT_DOMAIN,
				&inner_is_a_field_of_this);
	  if (bsym.symbol != NULL)
	    {
	      yylval.tsym.type = SYMBOL_TYPE (bsym.symbol);
	      return TYPENAME;
	    }
	}

      /* If we found a field on the "this" object, or we are looking
	 up a field on a struct, then we want to prefer it over a
	 filename.  However, if the name was quoted, then it is better
	 to check for a filename or a block, since this is the only
	 way the user has of requiring the extension to be used.  */
      if ((is_a_field_of_this.type == NULL && !is_after_structop) 
	  || is_quoted_name)
	{
	  /* See if it's a file name. */
	  struct symtab *symtab;

	  symtab = lookup_symtab (copy.c_str ());
	  if (symtab)
	    {
	      yylval.bval = BLOCKVECTOR_BLOCK (SYMTAB_BLOCKVECTOR (symtab),
					       STATIC_BLOCK);
	      return FILENAME;
	    }
	}
    }

  if (bsym.symbol && SYMBOL_CLASS (bsym.symbol) == LOC_TYPEDEF)
    {
      yylval.tsym.type = SYMBOL_TYPE (bsym.symbol);
      return TYPENAME;
    }

  /* See if it's an ObjC classname.  */
  if (par_state->language ()->la_language == language_objc && !bsym.symbol)
    {
      CORE_ADDR Class = lookup_objc_class (par_state->gdbarch (),
					   copy.c_str ());
      if (Class)
	{
	  struct symbol *sym;

	  yylval.theclass.theclass = Class;
	  sym = lookup_struct_typedef (copy.c_str (),
				       par_state->expression_context_block, 1);
	  if (sym)
	    yylval.theclass.type = SYMBOL_TYPE (sym);
	  return CLASSNAME;
	}
    }

  /* Input names that aren't symbols but ARE valid hex numbers, when
     the input radix permits them, can be names or numbers depending
     on the parse.  Note we support radixes > 16 here.  */
  if (!bsym.symbol
      && ((copy[0] >= 'a' && copy[0] < 'a' + input_radix - 10)
	  || (copy[0] >= 'A' && copy[0] < 'A' + input_radix - 10)))
    {
      YYSTYPE newlval;	/* Its value is ignored.  */
      int hextype = parse_number (par_state, copy.c_str (), yylval.sval.length,
				  0, &newlval);

      if (hextype == INT)
	{
	  yylval.ssym.sym = bsym;
	  yylval.ssym.is_a_field_of_this = is_a_field_of_this.type != NULL;
	  return NAME_OR_INT;
	}
    }

  /* Any other kind of symbol */
  yylval.ssym.sym = bsym;
  yylval.ssym.is_a_field_of_this = is_a_field_of_this.type != NULL;

  if (bsym.symbol == NULL
      && par_state->language ()->la_language == language_cplus
      && is_a_field_of_this.type == NULL
      && lookup_minimal_symbol (copy.c_str (), NULL, NULL).minsym == NULL)
    return UNKNOWN_CPP_NAME;

  return NAME;
}

/* Like classify_name, but used by the inner loop of the lexer, when a
   name might have already been seen.  CONTEXT is the context type, or
   NULL if this is the first component of a name.  */

static int
classify_inner_name (struct parser_state *par_state,
		     const struct block *block, struct type *context)
{
  struct type *type;

  if (context == NULL)
    return classify_name (par_state, block, false, false);

  type = check_typedef (context);
  if (!type_aggregate_p (type))
    return ERROR;

  std::string copy = copy_name (yylval.ssym.stoken);
  /* N.B. We assume the symbol can only be in VAR_DOMAIN.  */
  yylval.ssym.sym = cp_lookup_nested_symbol (type, copy.c_str (), block,
					     VAR_DOMAIN);

  /* If no symbol was found, search for a matching base class named
     COPY.  This will allow users to enter qualified names of class members
     relative to the `this' pointer.  */
  if (yylval.ssym.sym.symbol == NULL)
    {
      struct type *base_type = cp_find_type_baseclass_by_name (type,
							       copy.c_str ());

      if (base_type != NULL)
	{
	  yylval.tsym.type = base_type;
	  return TYPENAME;
	}

      return ERROR;
    }

  switch (SYMBOL_CLASS (yylval.ssym.sym.symbol))
    {
    case LOC_BLOCK:
    case LOC_LABEL:
      /* cp_lookup_nested_symbol might have accidentally found a constructor
	 named COPY when we really wanted a base class of the same name.
	 Double-check this case by looking for a base class.  */
      {
	struct type *base_type
	  = cp_find_type_baseclass_by_name (type, copy.c_str ());

	if (base_type != NULL)
	  {
	    yylval.tsym.type = base_type;
	    return TYPENAME;
	  }
      }
      return ERROR;

    case LOC_TYPEDEF:
      yylval.tsym.type = SYMBOL_TYPE (yylval.ssym.sym.symbol);
      return TYPENAME;

    default:
      return NAME;
    }
  internal_error (__FILE__, __LINE__, _("not reached"));
}

/* The outer level of a two-level lexer.  This calls the inner lexer
   to return tokens.  It then either returns these tokens, or
   aggregates them into a larger token.  This lets us work around a
   problem in our parsing approach, where the parser could not
   distinguish between qualified names and qualified types at the
   right point.

   This approach is still not ideal, because it mishandles template
   types.  See the comment in lex_one_token for an example.  However,
   this is still an improvement over the earlier approach, and will
   suffice until we move to better parsing technology.  */

static int
yylex (void)
{
  token_and_value current;
  int first_was_coloncolon, last_was_coloncolon;
  struct type *context_type = NULL;
  int last_to_examine, next_to_examine, checkpoint;
  const struct block *search_block;
  bool is_quoted_name, last_lex_was_structop;

  if (popping && !token_fifo.empty ())
    goto do_pop;
  popping = 0;

  last_lex_was_structop = last_was_structop;

  /* Read the first token and decide what to do.  Most of the
     subsequent code is C++-only; but also depends on seeing a "::" or
     name-like token.  */
  current.token = lex_one_token (pstate, &is_quoted_name);
  if (current.token == NAME)
    current.token = classify_name (pstate, pstate->expression_context_block,
				   is_quoted_name, last_lex_was_structop);
  if (pstate->language ()->la_language != language_cplus
      || (current.token != TYPENAME && current.token != COLONCOLON
	  && current.token != FILENAME))
    return current.token;

  /* Read any sequence of alternating "::" and name-like tokens into
     the token FIFO.  */
  current.value = yylval;
  token_fifo.push_back (current);
  last_was_coloncolon = current.token == COLONCOLON;
  while (1)
    {
      bool ignore;

      /* We ignore quoted names other than the very first one.
	 Subsequent ones do not have any special meaning.  */
      current.token = lex_one_token (pstate, &ignore);
      current.value = yylval;
      token_fifo.push_back (current);

      if ((last_was_coloncolon && current.token != NAME)
	  || (!last_was_coloncolon && current.token != COLONCOLON))
	break;
      last_was_coloncolon = !last_was_coloncolon;
    }
  popping = 1;

  /* We always read one extra token, so compute the number of tokens
     to examine accordingly.  */
  last_to_examine = token_fifo.size () - 2;
  next_to_examine = 0;

  current = token_fifo[next_to_examine];
  ++next_to_examine;

  name_obstack.clear ();
  checkpoint = 0;
  if (current.token == FILENAME)
    search_block = current.value.bval;
  else if (current.token == COLONCOLON)
    search_block = NULL;
  else
    {
      gdb_assert (current.token == TYPENAME);
      search_block = pstate->expression_context_block;
      obstack_grow (&name_obstack, current.value.sval.ptr,
		    current.value.sval.length);
      context_type = current.value.tsym.type;
      checkpoint = 1;
    }

  first_was_coloncolon = current.token == COLONCOLON;
  last_was_coloncolon = first_was_coloncolon;

  while (next_to_examine <= last_to_examine)
    {
      token_and_value next;

      next = token_fifo[next_to_examine];
      ++next_to_examine;

      if (next.token == NAME && last_was_coloncolon)
	{
	  int classification;

	  yylval = next.value;
	  classification = classify_inner_name (pstate, search_block,
						context_type);
	  /* We keep going until we either run out of names, or until
	     we have a qualified name which is not a type.  */
	  if (classification != TYPENAME && classification != NAME)
	    break;

	  /* Accept up to this token.  */
	  checkpoint = next_to_examine;

	  /* Update the partial name we are constructing.  */
	  if (context_type != NULL)
	    {
	      /* We don't want to put a leading "::" into the name.  */
	      obstack_grow_str (&name_obstack, "::");
	    }
	  obstack_grow (&name_obstack, next.value.sval.ptr,
			next.value.sval.length);

	  yylval.sval.ptr = (const char *) obstack_base (&name_obstack);
	  yylval.sval.length = obstack_object_size (&name_obstack);
	  current.value = yylval;
	  current.token = classification;

	  last_was_coloncolon = 0;

	  if (classification == NAME)
	    break;

	  context_type = yylval.tsym.type;
	}
      else if (next.token == COLONCOLON && !last_was_coloncolon)
	last_was_coloncolon = 1;
      else
	{
	  /* We've reached the end of the name.  */
	  break;
	}
    }

  /* If we have a replacement token, install it as the first token in
     the FIFO, and delete the other constituent tokens.  */
  if (checkpoint > 0)
    {
      current.value.sval.ptr
	= obstack_strndup (&cpstate->expansion_obstack,
			   current.value.sval.ptr,
			   current.value.sval.length);

      token_fifo[0] = current;
      if (checkpoint > 1)
	token_fifo.erase (token_fifo.begin () + 1,
			  token_fifo.begin () + checkpoint);
    }

 do_pop:
  current = token_fifo[0];
  token_fifo.erase (token_fifo.begin ());
  yylval = current.value;
  return current.token;
}

int
c_parse (struct parser_state *par_state)
{
  /* Setting up the parser state.  */
  scoped_restore pstate_restore = make_scoped_restore (&pstate);
  gdb_assert (par_state != NULL);
  pstate = par_state;

  c_parse_state cstate;
  scoped_restore cstate_restore = make_scoped_restore (&cpstate, &cstate);

  gdb::unique_xmalloc_ptr<struct macro_scope> macro_scope;

  if (par_state->expression_context_block)
    macro_scope
      = sal_macro_scope (find_pc_line (par_state->expression_context_pc, 0));
  else
    macro_scope = default_macro_scope ();
  if (! macro_scope)
    macro_scope = user_macro_scope ();

  scoped_restore restore_macro_scope
    = make_scoped_restore (&expression_macro_scope, macro_scope.get ());

  scoped_restore restore_yydebug = make_scoped_restore (&yydebug,
							parser_debug);

  /* Initialize some state used by the lexer.  */
  last_was_structop = false;
  saw_name_at_eof = 0;
  paren_depth = 0;

  token_fifo.clear ();
  popping = 0;
  name_obstack.clear ();

  return yyparse ();
}

#ifdef YYBISON

/* This is called via the YYPRINT macro when parser debugging is
   enabled.  It prints a token's value.  */

static void
c_print_token (FILE *file, int type, YYSTYPE value)
{
  switch (type)
    {
    case INT:
      parser_fprintf (file, "typed_val_int<%s, %s>",
		      TYPE_SAFE_NAME (value.typed_val_int.type),
		      pulongest (value.typed_val_int.val));
      break;

    case CHAR:
    case STRING:
      {
	char *copy = (char *) alloca (value.tsval.length + 1);

	memcpy (copy, value.tsval.ptr, value.tsval.length);
	copy[value.tsval.length] = '\0';

	parser_fprintf (file, "tsval<type=%d, %s>", value.tsval.type, copy);
      }
      break;

    case NSSTRING:
    case DOLLAR_VARIABLE:
      parser_fprintf (file, "sval<%s>", copy_name (value.sval).c_str ());
      break;

    case TYPENAME:
      parser_fprintf (file, "tsym<type=%s, name=%s>",
		      TYPE_SAFE_NAME (value.tsym.type),
		      copy_name (value.tsym.stoken).c_str ());
      break;

    case NAME:
    case UNKNOWN_CPP_NAME:
    case NAME_OR_INT:
    case BLOCKNAME:
      parser_fprintf (file, "ssym<name=%s, sym=%s, field_of_this=%d>",
		       copy_name (value.ssym.stoken).c_str (),
		       (value.ssym.sym.symbol == NULL
			? "(null)" : value.ssym.sym.symbol->print_name ()),
		       value.ssym.is_a_field_of_this);
      break;

    case FILENAME:
      parser_fprintf (file, "bval<%s>", host_address_to_string (value.bval));
      break;
    }
}

#endif

static void
yyerror (const char *msg)
{
  if (pstate->prev_lexptr)
    pstate->lexptr = pstate->prev_lexptr;

  error (_("A %s in expression, near `%s'."), msg, pstate->lexptr);
}
