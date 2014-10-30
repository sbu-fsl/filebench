/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 29 "parser_gram.y" /* yacc.c:339  */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <locale.h>
#include <sys/utsname.h>
#include <sys/statvfs.h>
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#ifdef HAVE_LIBTECLA
#include <libtecla.h>
#endif
#include "parsertypes.h"
#include "filebench.h"
#include "utils.h"
#include "stats.h"
#include "vars.h"
#include "eventgen.h"
#include "aslr.h"
#ifdef HAVE_LIBTECLA
#include "auto_comp.h"
#endif
#include "multi_client_sync.h"

/* yacc and lex externals */
extern FILE *yyin;
extern int yydebug;
extern void yyerror(char *s);
extern int yylex(void);

/* GetLine resource object */
#ifdef HAVE_LIBTECLA
static GetLine *gl;
#endif

/* executable name to execute worker processes later */
char *execname;

static int dofile = DOFILE_FALSE;

static char *fbbasepath = FILEBENCHDIR;
static char cwd[MAXPATHLEN];
static pidlist_t *pidlist;
static int filecreate_done;

/* utilities */
static cmd_t *alloc_cmd(void);
static attr_t *alloc_attr(void);
static attr_t *alloc_lvar_attr(var_t *var);
static attr_t *get_attr(cmd_t *cmd, int64_t name);
static attr_t *get_attr_fileset(cmd_t *cmd, int64_t name);
static attr_t *get_attr_integer(cmd_t *cmd, int64_t name);
static attr_t *get_attr_bool(cmd_t *cmd, int64_t name);
static void get_attr_lvars(cmd_t *cmd, flowop_t *flowop);
static list_t *alloc_list();
static probtabent_t *alloc_probtabent(void);
static void add_lvar_to_list(var_t *newlvar, var_t **lvar_list);

/* Info Commands */
static void parser_list(cmd_t *);
static void parser_flowop_list(cmd_t *);
static void parser_list_cvar_types(void);
static void parser_list_cvar_type_parameters(char *);

/* Define Commands */
static void parser_proc_define(cmd_t *);
static void parser_thread_define(cmd_t *, procflow_t *, int instances);
static void parser_flowop_define(cmd_t *, threadflow_t *, flowop_t **, int);
static void parser_file_define(cmd_t *);
static void parser_fileset_define(cmd_t *);
static void parser_var_assign_random(char *, cmd_t *);
static void parser_composite_flowop_define(cmd_t *);
static void parser_var_assign_custom(char *, cmd_t *);

/* Create Commands */
static void parser_proc_create(cmd_t *);
static void parser_fileset_create(cmd_t *);

/* Shutdown Commands */
static void parser_proc_shutdown(cmd_t *);
static void parser_filebench_shutdown(cmd_t *cmd);
static void parser_fileset_shutdown(cmd_t *cmd);

/* Other Commands */
static void parser_echo(cmd_t *cmd);
static void parser_fscheck(cmd_t *cmd);
static void parser_fsflush(cmd_t *cmd);
static void parser_log(cmd_t *cmd);
static void parser_statscmd(cmd_t *cmd);
static void parser_statsdump(cmd_t *cmd);
static void parser_statsxmldump(cmd_t *cmd);
static void parser_statsmultidump(cmd_t *cmd);
static void parser_usage(cmd_t *cmd);
static void parser_system(cmd_t *cmd);
static void parser_statssnap(cmd_t *cmd);
static void parser_directory(cmd_t *cmd);
static void parser_eventgen(cmd_t *cmd);
static void parser_enable_mc(cmd_t *cmd);
static void parser_domultisync(cmd_t *cmd);
static void parser_run(cmd_t *cmd);
static void parser_run_variable(cmd_t *cmd);
static void parser_psrun(cmd_t *cmd);
static void parser_sleep(cmd_t *cmd);
static void parser_sleep_variable(cmd_t *cmd);
static void parser_warmup(cmd_t *cmd);
static void parser_warmup_variable(cmd_t *cmd);
static void parser_help(cmd_t *cmd);
static void arg_parse(const char *command);
static void parser_abort(int arg);
static void parser_version(cmd_t *cmd);
static void parser_osprof_enable(cmd_t *cmd);
static void parser_osprof_disable(cmd_t *cmd);


#line 191 "parser_gram.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    FSC_LIST = 258,
    FSC_DEFINE = 259,
    FSC_QUIT = 260,
    FSC_DEBUG = 261,
    FSC_CREATE = 262,
    FSC_SLEEP = 263,
    FSC_STATS = 264,
    FSC_FOREACH = 265,
    FSC_SET = 266,
    FSC_SHUTDOWN = 267,
    FSC_LOG = 268,
    FSC_SYSTEM = 269,
    FSC_FLOWOP = 270,
    FSC_EVENTGEN = 271,
    FSC_ECHO = 272,
    FSC_RUN = 273,
    FSC_PSRUN = 274,
    FSC_WARMUP = 275,
    FSC_NOUSESTATS = 276,
    FSC_FSCHECK = 277,
    FSC_FSFLUSH = 278,
    FSC_USAGE = 279,
    FSC_HELP = 280,
    FSC_VERSION = 281,
    FSC_ENABLE = 282,
    FSC_DOMULTISYNC = 283,
    FSV_STRING = 284,
    FSV_VAL_INT = 285,
    FSV_VAL_NEGINT = 286,
    FSV_VAL_BOOLEAN = 287,
    FSV_VARIABLE = 288,
    FSV_WHITESTRING = 289,
    FSV_RANDUNI = 290,
    FSV_RANDTAB = 291,
    FSV_URAND = 292,
    FSV_RAND48 = 293,
    FSE_FILE = 294,
    FSE_PROC = 295,
    FSE_THREAD = 296,
    FSE_CLEAR = 297,
    FSE_SNAP = 298,
    FSE_DUMP = 299,
    FSE_DIRECTORY = 300,
    FSE_COMMAND = 301,
    FSE_FILESET = 302,
    FSE_XMLDUMP = 303,
    FSE_RAND = 304,
    FSE_MODE = 305,
    FSE_MULTI = 306,
    FSE_MULTIDUMP = 307,
    FSK_SEPLST = 308,
    FSK_OPENLST = 309,
    FSK_CLOSELST = 310,
    FSK_OPENPAR = 311,
    FSK_CLOSEPAR = 312,
    FSK_ASSIGN = 313,
    FSK_IN = 314,
    FSK_QUOTE = 315,
    FSA_SIZE = 316,
    FSA_PREALLOC = 317,
    FSA_PARALLOC = 318,
    FSA_PATH = 319,
    FSA_REUSE = 320,
    FSA_PROCESS = 321,
    FSA_MEMSIZE = 322,
    FSA_RATE = 323,
    FSA_CACHED = 324,
    FSA_READONLY = 325,
    FSA_TRUSTTREE = 326,
    FSA_IOSIZE = 327,
    FSA_FILE = 328,
    FSA_WSS = 329,
    FSA_NAME = 330,
    FSA_RANDOM = 331,
    FSA_INSTANCES = 332,
    FSA_DSYNC = 333,
    FSA_TARGET = 334,
    FSA_ITERS = 335,
    FSA_NICE = 336,
    FSA_VALUE = 337,
    FSA_BLOCKING = 338,
    FSA_HIGHWATER = 339,
    FSA_DIRECTIO = 340,
    FSA_DIRWIDTH = 341,
    FSA_FD = 342,
    FSA_SRCFD = 343,
    FSA_ROTATEFD = 344,
    FSA_ENTRIES = 345,
    FSA_DIRDEPTHRV = 346,
    FSA_DIRGAMMA = 347,
    FSA_USEISM = 348,
    FSA_TYPE = 349,
    FSA_RANDTABLE = 350,
    FSA_RANDSRC = 351,
    FSA_ROUND = 352,
    FSA_LEAFDIRS = 353,
    FSA_INDEXED = 354,
    FSA_FSTYPE = 355,
    FSA_RANDSEED = 356,
    FSA_RANDGAMMA = 357,
    FSA_RANDMEAN = 358,
    FSA_MIN = 359,
    FSA_MAX = 360,
    FSA_MASTER = 361,
    FSA_CLIENT = 362,
    FSS_TYPE = 363,
    FSS_SEED = 364,
    FSS_GAMMA = 365,
    FSS_MEAN = 366,
    FSS_MIN = 367,
    FSS_SRC = 368,
    FSS_ROUND = 369,
    FSA_LVAR_ASSIGN = 370,
    FSA_ALLDONE = 371,
    FSA_FIRSTDONE = 372,
    FSA_TIMEOUT = 373,
    FSC_OSPROF_ENABLE = 374,
    FSC_OSPROF_DISABLE = 375,
    FSA_NOREADAHEAD = 376,
    FSA_IOPRIO = 377,
    FSA_WRITEONLY = 378,
    FSA_OFFSET = 379,
    FSA_LENGTH = 380,
    FSA_LOCKTYPE = 381,
    FSE_CVAR = 382,
    FSA_PARAMETERS = 383
  };
#endif
/* Tokens.  */
#define FSC_LIST 258
#define FSC_DEFINE 259
#define FSC_QUIT 260
#define FSC_DEBUG 261
#define FSC_CREATE 262
#define FSC_SLEEP 263
#define FSC_STATS 264
#define FSC_FOREACH 265
#define FSC_SET 266
#define FSC_SHUTDOWN 267
#define FSC_LOG 268
#define FSC_SYSTEM 269
#define FSC_FLOWOP 270
#define FSC_EVENTGEN 271
#define FSC_ECHO 272
#define FSC_RUN 273
#define FSC_PSRUN 274
#define FSC_WARMUP 275
#define FSC_NOUSESTATS 276
#define FSC_FSCHECK 277
#define FSC_FSFLUSH 278
#define FSC_USAGE 279
#define FSC_HELP 280
#define FSC_VERSION 281
#define FSC_ENABLE 282
#define FSC_DOMULTISYNC 283
#define FSV_STRING 284
#define FSV_VAL_INT 285
#define FSV_VAL_NEGINT 286
#define FSV_VAL_BOOLEAN 287
#define FSV_VARIABLE 288
#define FSV_WHITESTRING 289
#define FSV_RANDUNI 290
#define FSV_RANDTAB 291
#define FSV_URAND 292
#define FSV_RAND48 293
#define FSE_FILE 294
#define FSE_PROC 295
#define FSE_THREAD 296
#define FSE_CLEAR 297
#define FSE_SNAP 298
#define FSE_DUMP 299
#define FSE_DIRECTORY 300
#define FSE_COMMAND 301
#define FSE_FILESET 302
#define FSE_XMLDUMP 303
#define FSE_RAND 304
#define FSE_MODE 305
#define FSE_MULTI 306
#define FSE_MULTIDUMP 307
#define FSK_SEPLST 308
#define FSK_OPENLST 309
#define FSK_CLOSELST 310
#define FSK_OPENPAR 311
#define FSK_CLOSEPAR 312
#define FSK_ASSIGN 313
#define FSK_IN 314
#define FSK_QUOTE 315
#define FSA_SIZE 316
#define FSA_PREALLOC 317
#define FSA_PARALLOC 318
#define FSA_PATH 319
#define FSA_REUSE 320
#define FSA_PROCESS 321
#define FSA_MEMSIZE 322
#define FSA_RATE 323
#define FSA_CACHED 324
#define FSA_READONLY 325
#define FSA_TRUSTTREE 326
#define FSA_IOSIZE 327
#define FSA_FILE 328
#define FSA_WSS 329
#define FSA_NAME 330
#define FSA_RANDOM 331
#define FSA_INSTANCES 332
#define FSA_DSYNC 333
#define FSA_TARGET 334
#define FSA_ITERS 335
#define FSA_NICE 336
#define FSA_VALUE 337
#define FSA_BLOCKING 338
#define FSA_HIGHWATER 339
#define FSA_DIRECTIO 340
#define FSA_DIRWIDTH 341
#define FSA_FD 342
#define FSA_SRCFD 343
#define FSA_ROTATEFD 344
#define FSA_ENTRIES 345
#define FSA_DIRDEPTHRV 346
#define FSA_DIRGAMMA 347
#define FSA_USEISM 348
#define FSA_TYPE 349
#define FSA_RANDTABLE 350
#define FSA_RANDSRC 351
#define FSA_ROUND 352
#define FSA_LEAFDIRS 353
#define FSA_INDEXED 354
#define FSA_FSTYPE 355
#define FSA_RANDSEED 356
#define FSA_RANDGAMMA 357
#define FSA_RANDMEAN 358
#define FSA_MIN 359
#define FSA_MAX 360
#define FSA_MASTER 361
#define FSA_CLIENT 362
#define FSS_TYPE 363
#define FSS_SEED 364
#define FSS_GAMMA 365
#define FSS_MEAN 366
#define FSS_MIN 367
#define FSS_SRC 368
#define FSS_ROUND 369
#define FSA_LVAR_ASSIGN 370
#define FSA_ALLDONE 371
#define FSA_FIRSTDONE 372
#define FSA_TIMEOUT 373
#define FSC_OSPROF_ENABLE 374
#define FSC_OSPROF_DISABLE 375
#define FSA_NOREADAHEAD 376
#define FSA_IOPRIO 377
#define FSA_WRITEONLY 378
#define FSA_OFFSET 379
#define FSA_LENGTH 380
#define FSA_LOCKTYPE 381
#define FSE_CVAR 382
#define FSA_PARAMETERS 383

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 154 "parser_gram.y" /* yacc.c:355  */

	int64_t		 ival;
	unsigned char	 bval;
	char *		 sval;
	fs_u		 val;
	avd_t		 avd;
	cmd_t		*cmd;
	attr_t		*attr;
	list_t		*list;
	probtabent_t	*rndtb;

#line 499 "parser_gram.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 514 "parser_gram.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  245
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  336

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   383

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   248,   248,   255,   260,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   291,   297,   302,   311,   320,   327,   334,   341,
     350,   357,   362,   371,   378,   386,   390,   405,   412,   420,
     438,   455,   473,   490,   493,   498,   504,   509,   517,   522,
     531,   539,   549,   549,   549,   549,   551,   562,   572,   581,
     592,   604,   616,   626,   636,   646,   658,   666,   673,   681,
     689,   696,   703,   712,   719,   722,   740,   752,   755,   773,
     782,   787,   794,   802,   807,   826,   845,   852,   860,   867,
     874,   882,   889,   896,   904,   912,   921,   930,   938,   947,
     954,   960,   965,   966,   967,   968,   970,   973,   977,   990,
     995,  1005,  1009,  1022,  1041,  1046,  1052,  1057,  1063,  1073,
    1077,  1092,  1096,  1110,  1115,  1123,  1127,  1141,  1146,  1154,
    1158,  1171,  1185,  1190,  1198,  1202,  1216,  1221,  1229,  1233,
    1247,  1253,  1259,  1267,  1269,  1271,  1274,  1275,  1276,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1296,  1297,  1298,  1299,  1300,  1301,
    1303,  1311,  1312,  1313,  1315,  1323,  1324,  1327,  1328,  1329,
    1330,  1331,  1334,  1335,  1336,  1337,  1338,  1339,  1342,  1343,
    1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1364,  1367,
    1368,  1371,  1372,  1374,  1378,  1391,  1405,  1411,  1416,  1421,
    1426,  1431,  1436,  1442,  1450,  1456,  1460,  1474,  1481,  1482,
    1484,  1489,  1493,  1497,  1503,  1506
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FSC_LIST", "FSC_DEFINE", "FSC_QUIT",
  "FSC_DEBUG", "FSC_CREATE", "FSC_SLEEP", "FSC_STATS", "FSC_FOREACH",
  "FSC_SET", "FSC_SHUTDOWN", "FSC_LOG", "FSC_SYSTEM", "FSC_FLOWOP",
  "FSC_EVENTGEN", "FSC_ECHO", "FSC_RUN", "FSC_PSRUN", "FSC_WARMUP",
  "FSC_NOUSESTATS", "FSC_FSCHECK", "FSC_FSFLUSH", "FSC_USAGE", "FSC_HELP",
  "FSC_VERSION", "FSC_ENABLE", "FSC_DOMULTISYNC", "FSV_STRING",
  "FSV_VAL_INT", "FSV_VAL_NEGINT", "FSV_VAL_BOOLEAN", "FSV_VARIABLE",
  "FSV_WHITESTRING", "FSV_RANDUNI", "FSV_RANDTAB", "FSV_URAND",
  "FSV_RAND48", "FSE_FILE", "FSE_PROC", "FSE_THREAD", "FSE_CLEAR",
  "FSE_SNAP", "FSE_DUMP", "FSE_DIRECTORY", "FSE_COMMAND", "FSE_FILESET",
  "FSE_XMLDUMP", "FSE_RAND", "FSE_MODE", "FSE_MULTI", "FSE_MULTIDUMP",
  "FSK_SEPLST", "FSK_OPENLST", "FSK_CLOSELST", "FSK_OPENPAR",
  "FSK_CLOSEPAR", "FSK_ASSIGN", "FSK_IN", "FSK_QUOTE", "FSA_SIZE",
  "FSA_PREALLOC", "FSA_PARALLOC", "FSA_PATH", "FSA_REUSE", "FSA_PROCESS",
  "FSA_MEMSIZE", "FSA_RATE", "FSA_CACHED", "FSA_READONLY", "FSA_TRUSTTREE",
  "FSA_IOSIZE", "FSA_FILE", "FSA_WSS", "FSA_NAME", "FSA_RANDOM",
  "FSA_INSTANCES", "FSA_DSYNC", "FSA_TARGET", "FSA_ITERS", "FSA_NICE",
  "FSA_VALUE", "FSA_BLOCKING", "FSA_HIGHWATER", "FSA_DIRECTIO",
  "FSA_DIRWIDTH", "FSA_FD", "FSA_SRCFD", "FSA_ROTATEFD", "FSA_ENTRIES",
  "FSA_DIRDEPTHRV", "FSA_DIRGAMMA", "FSA_USEISM", "FSA_TYPE",
  "FSA_RANDTABLE", "FSA_RANDSRC", "FSA_ROUND", "FSA_LEAFDIRS",
  "FSA_INDEXED", "FSA_FSTYPE", "FSA_RANDSEED", "FSA_RANDGAMMA",
  "FSA_RANDMEAN", "FSA_MIN", "FSA_MAX", "FSA_MASTER", "FSA_CLIENT",
  "FSS_TYPE", "FSS_SEED", "FSS_GAMMA", "FSS_MEAN", "FSS_MIN", "FSS_SRC",
  "FSS_ROUND", "FSA_LVAR_ASSIGN", "FSA_ALLDONE", "FSA_FIRSTDONE",
  "FSA_TIMEOUT", "FSC_OSPROF_ENABLE", "FSC_OSPROF_DISABLE",
  "FSA_NOREADAHEAD", "FSA_IOPRIO", "FSA_WRITEONLY", "FSA_OFFSET",
  "FSA_LENGTH", "FSA_LOCKTYPE", "FSE_CVAR", "FSA_PARAMETERS", "$accept",
  "commands", "command", "eventgen_command", "system_command",
  "echo_command", "version_command", "osprof_enable_command",
  "osprof_disable_command", "usage_command", "enable_command",
  "multisync_command", "var_string", "var_string_list", "whitevar_string",
  "whitevar_string_list", "list_command", "fscheck_command",
  "fsflush_command", "log_command", "debug_command", "set_command",
  "set_variable", "set_random_variable", "set_custom_variable", "set_mode",
  "stats_command", "quit_command", "flowop_list", "thread", "thread_list",
  "proc_define_command", "files_define_command", "create_command",
  "shutdown_command", "warmup_command", "sleep_command", "run_command",
  "psrun_command", "help_command", "flowop_command", "entity", "name",
  "files_attr_ops", "files_attr_op", "randvar_attr_ops", "randvar_attr_op",
  "probtabentry", "probtabentry_list", "p_attr_ops", "p_attr_op",
  "t_attr_ops", "t_attr_op", "fo_attr_ops", "fo_attr_op", "ev_attr_ops",
  "ev_attr_op", "enable_multi_ops", "enable_multi_op", "multisync_op",
  "fscheck_attr_op", "files_attr_name", "fo_attr_name", "ev_attr_name",
  "attrs_define_proc", "attrs_define_fileset", "randvar_attr_name",
  "randvar_attr_typop", "randtype_name", "randvar_attr_srcop",
  "randsrc_name", "cvar_attr_name", "attrs_define_thread", "attrs_flowop",
  "attrs_eventgen", "em_attr_name", "fscheck_attr_name", "comp_attr_ops",
  "comp_attr_op", "comp_lvar_def", "fo_define_command", "cvar_attr_ops",
  "cvar_attr_op", "attrs_define_comp", "attr_value", "var_int_val", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383
};
# endif

#define YYPACT_NINF -211

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-211)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -211,     9,  -211,  -211,  -211,    54,  -211,   -27,    86,    85,
     147,    -9,    86,   -12,   -12,  -211,   -12,    91,    66,   168,
     -45,   -45,   -12,  -211,  -211,    13,    -7,  -211,  -211,  -211,
      16,  -211,  -211,  -211,  -211,  -211,  -211,    24,  -211,   135,
     -45,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,    30,    77,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
       3,     3,  -211,    30,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,   -12,    43,   -12,   -12,   -12,
      97,    25,  -211,   132,    48,    53,    53,    53,  -211,  -211,
      76,   114,  -211,  -211,  -211,  -211,  -211,   121,  -211,    53,
    -211,   136,  -211,  -211,   143,  -211,   162,  -211,  -211,  -211,
     173,  -211,   182,  -211,  -211,  -211,  -211,  -211,   178,  -211,
     184,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,   188,  -211,   185,  -211,
    -211,  -211,   191,  -211,   187,   150,   176,    53,  -211,  -211,
    -211,    43,    53,    53,    53,    10,    95,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   217,   129,
      16,   129,    24,   129,    30,   129,    77,   129,     5,   129,
     232,   207,  -211,  -211,  -211,  -211,   193,   216,   195,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,   194,  -211,  -211,  -211,
     224,   -10,    98,    23,  -211,    33,   131,   196,    15,   124,
    -211,  -211,  -211,    98,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,   202,  -211,   199,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,   183,  -211,   200,  -211,  -211,  -211,
     203,   204,  -211,  -211,  -211,  -211,  -211,    38,  -211,   205,
    -211,  -211,  -211,  -211,  -211,  -211,   206,   107,  -211,  -211,
    -211,  -211,  -211,   220,   -22,   129,    23,   232,   129,     8,
     201,   113,  -211,   129,   129,    15,  -211,   208,  -211,  -211,
    -211,  -211,    -8,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,   209,  -211,  -211,  -211,  -211,  -211,  -211,
     211,   212,   172,  -211,    96,  -211,  -211,   218,   212,  -211,
     172,  -211,   219,   172,   214,  -211
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,     3,    55,     0,    83,     0,     0,   100,
       0,     0,     0,     0,     0,    32,     0,   103,   104,     0,
       0,     0,     0,   109,    36,     0,     0,    37,    38,     2,
       9,    25,    11,    26,    27,    28,    12,    29,    30,    16,
      13,    14,    17,     8,    20,    62,    63,    64,    65,    24,
      31,     5,     6,    10,    21,    23,    22,    18,    19,    15,
       7,     0,    91,     0,    92,    61,   115,   112,   113,   114,
      94,    98,    99,    77,    76,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,    60,    34,    35,   101,   102,
     106,   105,    96,    97,   221,   222,    57,     0,    59,    39,
      40,     0,    42,   218,    33,   144,   147,   155,   219,   220,
      41,   148,     0,    56,    58,   157,   158,   156,    90,   131,
     134,   162,   165,   166,   160,   167,   171,   168,   169,   159,
     163,   161,   164,   170,   172,   173,    93,   117,   120,   153,
     238,   239,   234,   223,     0,     0,     0,    80,    44,    43,
      45,    78,    79,    81,    82,     0,     0,    75,    47,    48,
      50,    49,    54,    52,    51,    53,   108,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    69,    66,    67,     0,     0,     0,    73,
      74,    72,   152,   240,   241,   242,   243,   151,   145,   146,
     149,   150,   132,   133,   118,   119,   232,   224,   225,   226,
       0,     0,    84,     0,    87,     0,     0,     0,     0,     0,
     116,   110,   233,    85,   213,   199,   198,   200,   201,   205,
     208,   209,   210,   211,   212,   206,   202,   203,   204,   207,
     214,   215,   216,   217,   111,   139,   143,   154,   192,   194,
     193,   196,   195,   197,     0,   135,   138,    89,    88,   174,
       0,     0,   179,   175,   176,   177,   178,     0,   121,   125,
      68,   187,   191,   189,   190,   188,     0,     0,   235,   230,
     228,   227,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,    71,     0,   140,   141,
     142,   136,     0,   137,   181,   182,   183,   126,   180,   185,
     186,   127,   184,     0,   122,   124,   237,   236,   229,    86,
       0,     0,     0,   129,     0,   244,   245,     0,     0,   123,
       0,   130,     0,     0,     0,   128
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,   108,  -211,  -211,    57,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   -17,    45,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -210,   261,  -211,  -211,    99,  -211,   -15,   -54,  -211,   215,
     103,  -211,    -6,  -211,    -5,  -211,   111,  -211,   110,  -211,
      28,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,   222,   106,     1,
    -211,  -211,    -4,  -211,  -171,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   150,   151,    84,    85,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   211,   214,
     215,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     212,    70,   221,   136,   137,   267,   268,   323,   324,   118,
     119,   254,   255,   244,   245,   104,   105,   110,   111,   102,
      96,   138,   246,   106,   120,   139,   269,   307,   308,   311,
     312,   276,   256,   247,   107,   112,    97,   142,   143,   208,
      60,   277,   278,   144,   197,   327
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     199,   223,   201,    65,   203,   210,   205,   210,   209,     2,
       3,   206,     4,     5,     6,     7,     8,     9,    10,    94,
      11,    12,    13,    14,    80,    15,    16,    17,    18,    19,
     156,    20,    21,    22,    23,    24,    25,    26,   206,   183,
     184,    81,   185,   304,   305,   222,   157,   319,    83,    98,
     224,   225,   226,   227,   228,    95,   229,   230,   231,   186,
     232,   233,   234,   235,   100,   236,   237,   238,   114,    61,
     187,    86,   148,    87,   213,   101,   149,   239,   140,    99,
     140,   160,   161,   141,   103,   141,   163,   164,   257,   248,
     249,   291,   223,    62,    63,   292,    90,    91,   250,   240,
     251,    64,   241,   242,   243,   115,   166,   116,   162,   271,
     306,   117,   272,   165,   300,    71,   252,   303,    72,   273,
     274,    88,   315,   316,    89,    66,    67,    68,    27,    28,
     108,   109,   147,    69,   152,   153,   154,   188,   121,   122,
     123,   124,   125,   275,   167,   253,   126,   127,   128,   328,
     113,   329,   129,   279,   280,   155,   281,   282,   193,   194,
     295,   195,   196,   130,   296,   158,   159,   131,   132,   133,
     224,   225,   226,   227,   228,   134,   229,   230,   231,   168,
     232,   233,   234,   235,   283,   236,   237,   238,   259,    73,
      74,    75,    76,    77,   169,    78,   170,   239,    92,    79,
     135,    93,   325,   178,   180,   326,   259,   260,   313,   261,
     262,   189,   190,   191,   263,   264,   265,   266,   332,   240,
     171,   334,   241,   242,   243,   260,   172,   261,   262,   174,
     181,   174,   263,   264,   265,   266,   286,   287,   309,   310,
     173,   176,   175,   177,   178,   179,   192,   210,   213,   216,
     217,   218,   219,   220,   297,   284,   270,   285,   288,   182,
     258,   289,   290,   293,   294,   321,   322,   320,   318,   335,
     302,   330,   333,    82,   331,   204,   314,   202,   146,   298,
     301,   198,   200,   145,   207,   299,     0,     0,     0,     0,
       0,   317
};

static const yytype_int16 yycheck[] =
{
     171,   211,   173,    30,   175,    15,   177,    15,   179,     0,
       1,    33,     3,     4,     5,     6,     7,     8,     9,    64,
      11,    12,    13,    14,    33,    16,    17,    18,    19,    20,
       5,    22,    23,    24,    25,    26,    27,    28,    33,    29,
      30,    50,    32,    35,    36,    55,    21,    55,    60,    21,
      72,    73,    74,    75,    76,   100,    78,    79,    80,    49,
      82,    83,    84,    85,    51,    87,    88,    89,    40,    15,
      60,    14,    29,    16,    41,    82,    33,    99,    75,    22,
      75,    33,    34,    80,    68,    80,    33,    34,    55,    66,
      67,    53,   302,    39,    40,    57,    30,    31,    75,   121,
      77,    47,   124,   125,   126,    75,    30,    77,    60,    94,
     102,    81,    97,    60,   285,    30,    93,   288,    33,   104,
     105,    30,   293,   294,    33,    39,    40,    41,   119,   120,
     106,   107,    75,    47,    77,    78,    79,   127,    61,    62,
      63,    64,    65,   128,    30,   122,    69,    70,    71,    53,
      15,    55,    75,    29,    30,    58,    32,    33,    29,    30,
      53,    32,    33,    86,    57,    33,    34,    90,    91,    92,
      72,    73,    74,    75,    76,    98,    78,    79,    80,    58,
      82,    83,    84,    85,    60,    87,    88,    89,    75,    42,
      43,    44,    45,    46,    58,    48,    53,    99,    30,    52,
     123,    33,    30,    53,    54,    33,    75,    94,    95,    96,
      97,   116,   117,   118,   101,   102,   103,   104,   330,   121,
      58,   333,   124,   125,   126,    94,    53,    96,    97,    53,
      54,    53,   101,   102,   103,   104,    53,    54,    37,    38,
      58,    53,    58,    58,    53,    58,    29,    15,    41,    56,
      34,    56,    58,    29,    34,    53,    60,    58,    58,   151,
     215,    58,    58,    58,    58,    54,    54,    58,    60,    55,
     287,    53,    53,    12,   328,   176,   291,   174,    63,   284,
     286,   170,   172,    61,   178,   284,    -1,    -1,    -1,    -1,
      -1,   295
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   130,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    11,    12,    13,    14,    16,    17,    18,    19,    20,
      22,    23,    24,    25,    26,    27,    28,   119,   120,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     209,    15,    39,    40,    47,    30,    39,    40,    41,    47,
     170,    30,    33,    42,    43,    44,    45,    46,    48,    52,
      33,    50,   170,    60,   143,   144,   144,   144,    30,    33,
      30,    31,    30,    33,    64,   100,   189,   205,   189,   144,
      51,    82,   188,    68,   184,   185,   192,   203,   106,   107,
     186,   187,   204,    15,   189,    75,    77,    81,   178,   179,
     193,    61,    62,    63,    64,    65,    69,    70,    71,    75,
      86,    90,    91,    92,    98,   123,   172,   173,   190,   194,
      75,    80,   206,   207,   212,   206,   178,   144,    29,    33,
     141,   142,   144,   144,   144,    58,     5,    21,    33,    34,
      33,    34,    60,    33,    34,    60,    30,    30,    58,    58,
      53,    58,    53,    58,    53,    58,    53,    58,    53,    58,
      54,    54,   141,    29,    30,    32,    49,    60,   127,   116,
     117,   118,    29,    29,    30,    32,    33,   213,   185,   213,
     187,   213,   179,   213,   173,   213,    33,   207,   208,   213,
      15,   157,   169,    41,   158,   159,    56,    34,    56,    58,
      29,   171,    55,   169,    72,    73,    74,    75,    76,    78,
      79,    80,    82,    83,    84,    85,    87,    88,    89,    99,
     121,   124,   125,   126,   182,   183,   191,   202,    66,    67,
      75,    77,    93,   122,   180,   181,   201,    55,   158,    75,
      94,    96,    97,   101,   102,   103,   104,   174,   175,   195,
      60,    94,    97,   104,   105,   128,   200,   210,   211,    29,
      30,    32,    33,    60,    53,    58,    53,    54,    58,    58,
      58,    53,    57,    58,    58,    53,    57,    34,   183,   208,
     213,   181,   157,   213,    35,    36,   102,   196,   197,    37,
      38,   198,   199,    95,   175,   213,   213,   211,    60,    55,
      58,    54,    54,   176,   177,    30,    33,   214,    53,    55,
      53,   176,   214,    53,   214,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   129,   130,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   134,   135,   136,   137,   138,
     139,   139,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   144,   144,   144,   144,   145,   145,   146,   146,   147,
     148,   149,   150,   150,   150,   150,   151,   151,   151,   151,
     152,   153,   154,   154,   154,   154,   155,   155,   155,   155,
     155,   155,   155,   156,   157,   157,   158,   159,   159,   160,
     160,   161,   161,   161,   162,   163,   164,   164,   165,   165,
     165,   166,   166,   166,   167,   167,   167,   167,   167,   168,
     169,   169,   170,   170,   170,   170,   171,   172,   172,   173,
     173,   174,   174,   174,   175,   175,   175,   175,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   182,   183,   183,   184,   184,   185,   185,   186,   186,
     187,   188,   189,   190,   191,   192,   193,   193,   193,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   195,   195,   195,   195,   195,   195,
     196,   197,   197,   197,   198,   199,   199,   200,   200,   200,
     200,   200,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   203,   204,
     204,   205,   205,   206,   206,   206,   207,   208,   208,   208,
     208,   208,   208,   209,   209,   210,   210,   211,   212,   212,
     213,   213,   213,   213,   214,   214
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     4,     4,     6,     4,
       7,     7,     4,     4,     4,     3,     2,     2,     3,     3,
       3,     3,     3,     1,     1,     2,     5,     1,     2,     6,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     1,     2,     2,     3,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     3,     7,     3,     1,     3,     3,     7,     1,
       3,     1,     3,     3,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     1,     1,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     5,
       3,     3,     1,     6,     2,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 249 "parser_gram.y" /* yacc.c:1646  */
    {
	if ((yyvsp[0].cmd)->cmd)
		(yyvsp[0].cmd)->cmd((yyvsp[0].cmd));

	free((yyvsp[0].cmd));
}
#line 1902 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 3:
#line 256 "parser_gram.y" /* yacc.c:1646  */
    {
	if (dofile == DOFILE_TRUE)
		YYABORT;
}
#line 1911 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 32:
#line 292 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_eventgen;
}
#line 1921 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 33:
#line 298 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 1929 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 34:
#line 303 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_system;
}
#line 1941 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 35:
#line 312 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_echo;
}
#line 1953 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 36:
#line 321 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_version;
}
#line 1963 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_osprof_enable;
}
#line 1973 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 38:
#line 335 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_osprof_disable;
}
#line 1983 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 39:
#line 342 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_usage;
}
#line 1995 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 40:
#line 351 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd = parser_enable_mc;
}
#line 2006 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 41:
#line 358 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2014 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 42:
#line 363 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd = parser_domultisync;
	(yyval.cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2026 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 43:
#line 372 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));
}
#line 2037 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));
}
#line 2048 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 45:
#line 387 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.list) = (yyvsp[0].list);
}
#line 2056 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 46:
#line 391 "parser_gram.y" /* yacc.c:1646  */
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Find end of list */
	for (list = (yyvsp[-1].list); list != NULL;
	    list = list->list_next)
		list_end = list;

	list_end->list_next = (yyvsp[0].list);

	(yyval.list) = (yyvsp[-1].list);
}
#line 2074 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 47:
#line 406 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));
}
#line 2085 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 48:
#line 413 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.list) = alloc_list()) == NULL)
			YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));
}
#line 2096 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 49:
#line 421 "parser_gram.y" /* yacc.c:1646  */
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add string */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));

	/* Find end of list */
	for (list = (yyvsp[-1].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[-1].list);

}
#line 2119 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 50:
#line 439 "parser_gram.y" /* yacc.c:1646  */
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));

	/* Find end of list */
	for (list = (yyvsp[-1].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[-1].list);
}
#line 2141 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 51:
#line 456 "parser_gram.y" /* yacc.c:1646  */
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add string */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));

	/* Find end of list */
	for (list = (yyvsp[-1].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[-1].list);

}
#line 2164 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 52:
#line 474 "parser_gram.y" /* yacc.c:1646  */
    {
	list_t *list = NULL;
	list_t *list_end = NULL;

	/* Add variable */
	if (((yyval.list) = alloc_list()) == NULL)
		YYERROR;

	(yyval.list)->list_string = avd_str_alloc((yyvsp[0].sval));

	/* Find end of list */
	for (list = (yyvsp[-1].list); list != NULL;
	    list = list->list_next)
		list_end = list;
	list_end->list_next = (yyval.list);
	(yyval.list) = (yyvsp[-1].list);
}
#line 2186 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 53:
#line 491 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.list) = (yyvsp[-1].list);
}
#line 2194 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 54:
#line 494 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.list) = (yyvsp[-1].list);
}
#line 2202 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 55:
#line 499 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_list;
}
#line 2212 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 56:
#line 505 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd = &parser_flowop_list;
}
#line 2220 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 57:
#line 510 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_fscheck;

	(yyval.cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2232 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 58:
#line 518 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list->attr_next = (yyvsp[0].attr);
}
#line 2240 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 59:
#line 523 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_fsflush;

	(yyval.cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2252 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 60:
#line 532 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_log;
	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
}
#line 2263 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 61:
#line 540 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = NULL;
	filebench_shm->shm_debug_level = (yyvsp[0].ival);
	if (filebench_shm->shm_debug_level > 9)
		yydebug = 1;
}
#line 2276 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 66:
#line 552 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	var_assign_integer((yyvsp[-2].sval), (yyvsp[0].ival));

	(yyval.cmd)->cmd = NULL;
}
#line 2290 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 67:
#line 563 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	var_assign_boolean((yyvsp[-2].sval), (yyvsp[0].bval));

	(yyval.cmd)->cmd = NULL;
}
#line 2304 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 68:
#line 573 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	var_assign_string((yyvsp[-4].sval), (yyvsp[-1].sval));

	(yyval.cmd)->cmd = NULL;
}
#line 2317 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 69:
#line 582 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	var_assign_string((yyvsp[-2].sval), (yyvsp[0].sval));

	(yyval.cmd)->cmd = NULL;
}
#line 2331 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 70:
#line 593 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	(yyval.cmd)->cmd_attr_list = (yyvsp[-1].attr);
	(yyval.cmd)->cmd = NULL;

	parser_var_assign_random((yyvsp[-5].sval), (yyval.cmd));
}
#line 2346 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 71:
#line 605 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	(yyval.cmd)->cmd_attr_list = (yyvsp[-1].attr);
	(yyval.cmd)->cmd = NULL;

	parser_var_assign_custom((yyvsp[-5].sval), (yyval.cmd));
}
#line 2361 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 72:
#line 617 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	filebench_shm->shm_rmode = FILEBENCH_MODE_TIMEOUT;

	(yyval.cmd)->cmd = NULL;
}
#line 2375 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 73:
#line 627 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	filebench_shm->shm_rmode = FILEBENCH_MODE_QALLDONE;

	(yyval.cmd)->cmd = NULL;
}
#line 2389 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 74:
#line 637 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	filebench_shm->shm_rmode = FILEBENCH_MODE_Q1STDONE;

	(yyval.cmd)->cmd = NULL;
}
#line 2403 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 75:
#line 647 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	filebench_log(LOG_INFO, "Disabling CPU usage statistics");
	filebench_shm->shm_mmode |= FILEBENCH_MODE_NOUSAGE;

	(yyval.cmd)->cmd = NULL;
}
#line 2418 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 76:
#line 659 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = (void (*)(struct cmd *))&parser_statssnap;
	break;

}
#line 2430 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 77:
#line 667 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = (void (*)(struct cmd *))&stats_clear;

}
#line 2441 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 78:
#line 674 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = (void (*)(struct cmd *))&parser_directory;

}
#line 2453 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 79:
#line 682 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_statscmd;

}
#line 2466 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 80:
#line 690 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_statsdump;
}
#line 2478 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 81:
#line 697 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_statsxmldump;
}
#line 2490 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 82:
#line 704 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;

	(yyval.cmd)->cmd_param_list = (yyvsp[0].list);
	(yyval.cmd)->cmd = parser_statsmultidump;
}
#line 2502 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 83:
#line 713 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_filebench_shutdown;
}
#line 2512 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 84:
#line 720 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = (yyvsp[0].cmd);
}
#line 2520 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 85:
#line 723 "parser_gram.y" /* yacc.c:1646  */
    {
	cmd_t *list = NULL;
	cmd_t *list_end = NULL;

	/* Find end of list */
	for (list = (yyvsp[-1].cmd); list != NULL;
	    list = list->cmd_next)
		list_end = list;

	list_end->cmd_next = (yyvsp[0].cmd);

	filebench_log(LOG_DEBUG_IMPL,
	    "flowop_list adding cmd %zx to list %zx", (yyvsp[0].cmd), (yyvsp[-1].cmd));

	(yyval.cmd) = (yyvsp[-1].cmd);
}
#line 2541 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 86:
#line 741 "parser_gram.y" /* yacc.c:1646  */
    {
	/*
	 * Allocate a cmd node per thread, with a
	 * list of flowops attached to the cmd_list
	 */
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_list = (yyvsp[-1].cmd);
	(yyval.cmd)->cmd_attr_list = (yyvsp[-3].attr);
}
#line 2556 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 87:
#line 753 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = (yyvsp[0].cmd);
}
#line 2564 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 88:
#line 756 "parser_gram.y" /* yacc.c:1646  */
    {
	cmd_t *list = NULL;
	cmd_t *list_end = NULL;

	/* Find end of list */
	for (list = (yyvsp[-1].cmd); list != NULL;
	    list = list->cmd_next)
		list_end = list;

	list_end->cmd_next = (yyvsp[0].cmd);

	filebench_log(LOG_DEBUG_IMPL,
	    "thread_list adding cmd %zx to list %zx", (yyvsp[0].cmd), (yyvsp[-1].cmd));

	(yyval.cmd) = (yyvsp[-1].cmd);
}
#line 2585 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 89:
#line 774 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_proc_define;
	(yyval.cmd)->cmd_list = (yyvsp[-1].cmd);
	(yyval.cmd)->cmd_attr_list = (yyvsp[-3].attr);

}
#line 2598 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 90:
#line 783 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2606 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 91:
#line 788 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	(yyval.cmd)->cmd = &parser_file_define;
}
#line 2618 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 92:
#line 795 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.cmd) = alloc_cmd();
	if (!(yyval.cmd))
		YYERROR;

	(yyval.cmd)->cmd = &parser_fileset_define;
}
#line 2630 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 93:
#line 803 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2638 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 94:
#line 808 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	switch ((yyvsp[0].ival)) {
	case FSE_PROC:
		(yyval.cmd)->cmd = &parser_proc_create;
		break;
	case FSE_FILESET:
	case FSE_FILE:
		(yyval.cmd)->cmd = &parser_fileset_create;
		break;
	default:
		filebench_log(LOG_ERROR, "unknown entity", (yyvsp[0].ival));
		YYERROR;
	}

}
#line 2660 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 95:
#line 827 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	switch ((yyvsp[0].ival)) {
	case FSE_PROC:
		(yyval.cmd)->cmd = &parser_proc_shutdown;
		break;
	case FSE_FILE:
	case FSE_FILESET:
		(yyval.cmd)->cmd = &parser_fileset_shutdown;
		break;
	default:
		filebench_log(LOG_ERROR, "unknown entity", (yyvsp[0].ival));
		YYERROR;
	}

}
#line 2682 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 96:
#line 846 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_warmup;
	(yyval.cmd)->cmd_qty = (yyvsp[0].ival);
}
#line 2693 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 97:
#line 853 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_warmup_variable;
	(yyval.cmd)->cmd_tgt1 = fb_stralloc((yyvsp[0].sval));
}
#line 2704 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 98:
#line 861 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_sleep;
	(yyval.cmd)->cmd_qty = (yyvsp[0].ival);
}
#line 2715 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 99:
#line 868 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_sleep_variable;
	(yyval.cmd)->cmd_tgt1 = fb_stralloc((yyvsp[0].sval));
}
#line 2726 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 100:
#line 875 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_sleep;
	(yyval.cmd)->cmd_qty = 0;
}
#line 2737 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 101:
#line 883 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_run;
	(yyval.cmd)->cmd_qty = (yyvsp[0].ival);
}
#line 2748 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 102:
#line 890 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_run_variable;
	(yyval.cmd)->cmd_tgt1 = fb_stralloc((yyvsp[0].sval));
}
#line 2759 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 103:
#line 897 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_run;
	(yyval.cmd)->cmd_qty = 0;
}
#line 2770 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 104:
#line 905 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_psrun;
	(yyval.cmd)->cmd_qty1 = 0;
	(yyval.cmd)->cmd_qty = 0;
}
#line 2782 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 105:
#line 913 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_psrun;
	(yyval.cmd)->cmd_qty1 = (yyvsp[0].ival);
	(yyval.cmd)->cmd_qty = 0;

}
#line 2795 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 106:
#line 922 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_psrun;
	(yyval.cmd)->cmd_qty1 = (yyvsp[0].ival);
	(yyval.cmd)->cmd_qty = 0;

}
#line 2808 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 107:
#line 931 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_psrun;
	(yyval.cmd)->cmd_qty1 = (yyvsp[-1].ival);
	(yyval.cmd)->cmd_qty = (yyvsp[0].ival);
}
#line 2820 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 108:
#line 939 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_psrun;
	(yyval.cmd)->cmd_qty1 = (yyvsp[-1].ival);
	(yyval.cmd)->cmd_qty = (yyvsp[0].ival);
}
#line 2832 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 109:
#line 948 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = parser_help;
}
#line 2842 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 110:
#line 955 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd_name = fb_stralloc((yyvsp[0].sval));
}
#line 2852 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 111:
#line 961 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 2860 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 112:
#line 965 "parser_gram.y" /* yacc.c:1646  */
    {(yyval.ival) = FSE_PROC;}
#line 2866 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 113:
#line 966 "parser_gram.y" /* yacc.c:1646  */
    {(yyval.ival) = FSE_THREAD;}
#line 2872 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 114:
#line 967 "parser_gram.y" /* yacc.c:1646  */
    {(yyval.ival) = FSE_FILESET;}
#line 2878 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 115:
#line 968 "parser_gram.y" /* yacc.c:1646  */
    {(yyval.ival) = FSE_FILE;}
#line 2884 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 117:
#line 974 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 2892 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 118:
#line 978 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr; attr = attr->attr_next)
		list_end = attr;

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 2908 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 119:
#line 991 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 2917 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 120:
#line 996 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = alloc_attr();
	if (!(yyval.attr))
		YYERROR;

	(yyval.attr)->attr_name = (yyvsp[0].ival);
}
#line 2929 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1006 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 2937 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1010 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 2954 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1023 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-6].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	
	if ((attr = alloc_attr()) == NULL)
		YYERROR;

	attr->attr_name = FSA_RANDTABLE;
	attr->attr_obj = (void *)(yyvsp[-1].rndtb);
	list_end->attr_next = attr;
	(yyval.attr) = (yyvsp[-6].attr);
}
#line 2976 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1042 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 2985 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1047 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[0].ival);
}
#line 2995 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1053 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = FSA_TYPE;
}
#line 3004 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1058 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = FSA_RANDSRC;
}
#line 3013 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1064 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.rndtb) = alloc_probtabent()) == NULL)
		YYERROR;
	(yyval.rndtb)->pte_percent = (yyvsp[-5].avd);
	(yyval.rndtb)->pte_segmin  = (yyvsp[-3].avd);
	(yyval.rndtb)->pte_segmax  = (yyvsp[-1].avd);
}
#line 3025 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1074 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.rndtb) = (yyvsp[0].rndtb);
}
#line 3033 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1078 "parser_gram.y" /* yacc.c:1646  */
    {
	probtabent_t *pte = NULL;
	probtabent_t *ptelist_end = NULL;

	for (pte = (yyvsp[-2].rndtb); pte != NULL;
	    pte = pte->pte_next)
		ptelist_end = pte; /* Find end of prob table entry list */

	ptelist_end->pte_next = (yyvsp[0].rndtb);

	(yyval.rndtb) = (yyvsp[-2].rndtb);
}
#line 3050 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1093 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3058 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1097 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3075 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1111 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3084 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1116 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[0].ival);
}
#line 3094 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1124 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3102 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1128 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3119 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1142 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3128 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1147 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[0].ival);
}
#line 3138 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1155 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3146 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1159 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3163 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1172 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3180 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1186 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3189 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1191 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[0].ival);
}
#line 3199 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1199 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3207 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1203 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3224 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1217 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3233 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1222 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_name = (yyvsp[0].ival);
}
#line 3243 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1230 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3251 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1234 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3268 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1248 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3277 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1254 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = FSA_VALUE;
}
#line 3286 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1260 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_str_alloc((yyvsp[0].sval));
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3297 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1274 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NICE;}
#line 3303 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1275 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NAME;}
#line 3309 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1276 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_INSTANCES;}
#line 3315 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1279 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NAME;}
#line 3321 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1280 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_PATH;}
#line 3327 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1281 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_ENTRIES;}
#line 3333 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1282 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_SIZE;}
#line 3339 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1283 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_DIRWIDTH;}
#line 3345 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1284 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_DIRDEPTHRV;}
#line 3351 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1285 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_PREALLOC;}
#line 3357 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1286 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_PARALLOC;}
#line 3363 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1287 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_REUSE;}
#line 3369 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1288 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_READONLY;}
#line 3375 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1289 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_TRUSTTREE;}
#line 3381 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1290 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_DIRGAMMA;}
#line 3387 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1291 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_CACHED;}
#line 3393 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1292 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_LEAFDIRS;}
#line 3399 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1293 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_WRITEONLY;}
#line 3405 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1296 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NAME;}
#line 3411 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1297 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_RANDSEED;}
#line 3417 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1298 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_RANDGAMMA;}
#line 3423 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1299 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_RANDMEAN;}
#line 3429 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1300 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_MIN;}
#line 3435 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1301 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_ROUND;}
#line 3441 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1304 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[0].ival));
}
#line 3451 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1311 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSV_RANDUNI;}
#line 3457 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1312 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSV_RANDTAB;}
#line 3463 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1313 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_RANDGAMMA;}
#line 3469 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1316 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[0].ival));
}
#line 3479 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1323 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSV_URAND;}
#line 3485 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1324 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSV_RAND48;}
#line 3491 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1327 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_TYPE;}
#line 3497 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1328 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_PARAMETERS;}
#line 3503 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1329 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_MIN;}
#line 3509 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1330 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_MAX;}
#line 3515 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1331 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_ROUND;}
#line 3521 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1334 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_PROCESS;}
#line 3527 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1335 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NAME;}
#line 3533 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1336 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_MEMSIZE;}
#line 3539 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1337 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_USEISM;}
#line 3545 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1338 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_INSTANCES;}
#line 3551 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1339 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_IOPRIO;}
#line 3557 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1342 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_WSS;}
#line 3563 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1343 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_FILE;}
#line 3569 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1344 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NAME;}
#line 3575 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1345 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_RANDOM;}
#line 3581 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1346 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_FD;}
#line 3587 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1347 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_SRCFD;}
#line 3593 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1348 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_ROTATEFD;}
#line 3599 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1349 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_DSYNC;}
#line 3605 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1350 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_DIRECTIO;}
#line 3611 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1351 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_INDEXED;}
#line 3617 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1352 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_TARGET;}
#line 3623 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1353 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_ITERS;}
#line 3629 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1354 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_VALUE;}
#line 3635 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1355 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_BLOCKING;}
#line 3641 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1356 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_HIGHWATER;}
#line 3647 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1357 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_IOSIZE;}
#line 3653 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1358 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NOREADAHEAD;}
#line 3659 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1359 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_OFFSET; }
#line 3665 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1360 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_LENGTH; }
#line 3671 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1361 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_LOCKTYPE; }
#line 3677 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1364 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_RATE;}
#line 3683 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1367 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_MASTER;}
#line 3689 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1368 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_CLIENT;}
#line 3695 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1371 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_PATH;}
#line 3701 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1372 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_FSTYPE;}
#line 3707 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1375 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3715 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1379 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3732 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1392 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3749 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1406 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3758 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1412 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_boolean((yyvsp[-2].sval), (yyvsp[0].bval)))) == NULL)
		YYERROR;
}
#line 3767 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1417 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_integer((yyvsp[-2].sval), (yyvsp[0].ival)))) == NULL)
		YYERROR;
}
#line 3776 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1422 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_string((yyvsp[-4].sval), (yyvsp[-1].sval)))) == NULL)
		YYERROR;
}
#line 3785 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1427 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_string((yyvsp[-2].sval), (yyvsp[0].sval)))) == NULL)
		YYERROR;
}
#line 3794 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1432 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_assign_var((yyvsp[-2].sval), (yyvsp[0].sval)))) == NULL)
		YYERROR;
}
#line 3803 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1437 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_lvar_attr(var_lvar_alloc_local((yyvsp[0].sval)))) == NULL)
		YYERROR;
}
#line 3812 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1443 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.cmd) = alloc_cmd()) == NULL)
		YYERROR;
	(yyval.cmd)->cmd = &parser_composite_flowop_define;
	(yyval.cmd)->cmd_list = (yyvsp[-1].cmd);
	(yyval.cmd)->cmd_attr_list = (yyvsp[-3].attr);
}
#line 3824 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1451 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].cmd)->cmd_attr_list = (yyvsp[0].attr);
}
#line 3832 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1457 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
}
#line 3840 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1461 "parser_gram.y" /* yacc.c:1646  */
    {
	attr_t *attr = NULL;
	attr_t *list_end = NULL;

	for (attr = (yyvsp[-2].attr); attr != NULL;
	    attr = attr->attr_next)
		list_end = attr; /* Find end of list */

	list_end->attr_next = (yyvsp[0].attr);

	(yyval.attr) = (yyvsp[-2].attr);
}
#line 3857 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1475 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.attr) = (yyvsp[0].attr);
	(yyval.attr)->attr_name = (yyvsp[-2].ival);
}
#line 3866 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1481 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_NAME;}
#line 3872 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1482 "parser_gram.y" /* yacc.c:1646  */
    { (yyval.ival) = FSA_ITERS;}
#line 3878 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1485 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_str_alloc((yyvsp[0].sval));
}
#line 3888 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1489 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_int_alloc((yyvsp[0].ival));
}
#line 3898 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1493 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_bool_alloc((yyvsp[0].bval));
}
#line 3908 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1497 "parser_gram.y" /* yacc.c:1646  */
    {
	if (((yyval.attr) = alloc_attr()) == NULL)
		YYERROR;
	(yyval.attr)->attr_avd = avd_var_alloc((yyvsp[0].sval));
}
#line 3918 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1504 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.avd) = avd_int_alloc((yyvsp[0].ival));
}
#line 3926 "parser_gram.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1507 "parser_gram.y" /* yacc.c:1646  */
    {
	(yyval.avd) = avd_var_alloc((yyvsp[0].sval));
}
#line 3934 "parser_gram.c" /* yacc.c:1646  */
    break;


#line 3938 "parser_gram.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1511 "parser_gram.y" /* yacc.c:1906  */


/*
 * The following C routines implement the various commands defined in the above
 * yacc parser code. The yacc portion checks the syntax of the commands found in
 * a workload file (or typed interactively) and parses the commands' parameters
 * into lists. The lists are then passed in a cmd_t struct for each command to
 * its related routine in the following section for actual execution.  This
 * section also includes a few utility routines and the main entry point for the
 * program.
 */

#define	USAGE1	\
"Usage:\n" \
"filebench: interprets WML script and generates apporpriate workload\n" \
"Options:\n" \
"   [-h] Display verbose help\n" \
"   [-f <filename>] use specified file as an input instead of stdin\n"

#define	PARSER_CMDS \
"create [files|filesets|processes]\n" \
"stats [clear|snap]\n" \
"stats command \"shell command $var1,$var2...\"\n" \
"stats directory <directory>\n" \
"sleep <sleep-value>\n" \
"quit\n\n" \
"Variables:\n" \
"set $var = value\n" \
"    $var   - regular variables\n" \
"    ${var} - internal special variables\n" \
"    $(var) - environment variables\n\n"

#define	PARSER_EXAMPLE \
"Example:\n\n" \
"#!" FILEBENCHDIR "/bin/filebench -f\n" \
"\n" \
"define file name=bigfile,path=bigfile,size=1g,prealloc,reuse\n" \
"define process name=randomizer\n" \
"{\n" \
"  thread random-thread procname=randomizer\n"	\
"  {\n" \
"    flowop read name=random-read,filename=bigfile,iosize=16k,random\n" \
"  }\n" \
"}\n" \
"create files\n" \
"create processes\n" \
"stats clear\n" \
"sleep 30\n" \
"stats snap\n"

/*
 * Displays brief or verbose help for Filebench.
 */
static void
usage(int help)
{
	if (help >= 1)
		(void) fprintf(stderr, USAGE1);

	if (help >= 2) {
		(void) fprintf(stderr,
		    "\n'f' language definition:\n\n");
		fileset_usage();
		procflow_usage();
		threadflow_usage();
		flowoplib_usage();
		eventgen_usage();
		(void) fprintf(stderr, PARSER_CMDS);
		(void) fprintf(stderr, PARSER_EXAMPLE);
	}

	exit(1);
}

#ifdef HAVE_PROC_SYS_KERNEL_SHMMAX
/*
 * Increase the maximum shared memory segment size till some large value.  We do
 * not restore it to the old value when the Filebench run is over. If we could
 * not change the value - we continue execution.
 */
void
fb_set_shmmax(void)
{
	FILE *f;
	int ret;

	f = fopen("/proc/sys/kernel/shmmax", "r+");
	if (!f) {
		filebench_log(LOG_FATAL, "WARNING: Could not open "
				"/proc/sys/kernel/shmmax file!\n"
				"It means that you probably ran Filebench not "
				"as a root. Filebench will not increase shared\n"
				"region limits in this case, which can lead "
				"to the failures on certain workloads.");
		return; 
	}

	/* writing new value */
#define SOME_LARGE_SHMAX "268435456" /* 256 MB */
	ret = fwrite(SOME_LARGE_SHMAX, sizeof(SOME_LARGE_SHMAX), 1, f);
	if (ret != 1) 
		filebench_log(LOG_ERROR, "Coud not write to "
				"/proc/sys/kernel/shmmax file!");
#undef SOME_LARGE_SHMAX

	fclose(f);

	return;
}
#else /* HAVE_PROC_SYS_KERNEL_SHMMAX */
void
fb_set_shmmax(void)
{
	return;
}
#endif /* HAVE_PROC_SYS_KERNEL_SHMMAX */

#ifdef HAVE_SETRLIMIT
/*
 * Increase the limit of opened files.
 *
 * We first set the limit to the hardlimit reported by the kernel; this call
 * will always succeed.  Then we try to set the limit to some large number of
 * files (unfortunately we can't set this ulimit to infinity), this will only
 * succeed if the process is ran by root.  Therefore, we always set the maximum
 * possible value for the limit for this given process (well, only if hardlimit
 * is greater then the large number of files defined by us, it is not true).
 *
 * Increasing this limit is especially important when we use thread model,
 * because opened files are accounted per-process, not per-thread.
 */
void
fb_set_rlimit(void)
{
	struct rlimit rlp;

	(void)getrlimit(RLIMIT_NOFILE, &rlp);
	rlp.rlim_cur = rlp.rlim_max;
	(void)setrlimit(RLIMIT_NOFILE, &rlp);
#define SOME_LARGE_NUMBER_OF_FILES 50000
	rlp.rlim_cur = rlp.rlim_max = SOME_LARGE_NUMBER_OF_FILES;
#undef SOME_LARGE_NUMBER_OF_FILES
	(void)setrlimit(RLIMIT_NOFILE, &rlp);
	return;
}
#else /* HAVE_SETRLIMIT */
void
fb_set_rlimit(void)
{
	return;
}
#endif /* HAVE_SETRLIMIT */

/*
 * Entry point for Filebench. Processes command line arguments. The -f option
 * will read in a workload file (the full name and extension must must be
 * given). The -a, -s, -m and -i options are used by the worker process to
 * receive the name, the base address of shared memory, its path, and the
 * process' instance number, respectively. This information is supplied by the
 * master process when it execs worker processes. If the worker process
 * arguments are passed then main will call the procflow_exec() routine which
 * creates worker threadflows and flowops and executes the procflow's portion of
 * the workload model until completion. If worker process arguments are not
 * passed to the process, then it becomes the master process for a filebench
 * run. It initializes the various filebench components and either executes the
 * supplied workload file, or enters interactive mode.
 */
int
main(int argc, char *argv[])
{
	const char cmd_options[] = "m:s:a:i:hf:c:";
	int opt;
	char *procname = NULL;
	int instance;
	void *shmaddr;
	char *cwdret;
	char *fscriptname = NULL;
#ifdef HAVE_LIBTECLA
	char *line;
#else /* HAVE_LIBTECLA */
	char line[1024];
#endif
	int ret;
	int ls_cvars = 0;
	char *cvar_type = NULL;

 	/*
	 * We don't want getopt() to print error messages because
	 * sometimes what it percieves as an error is actually not
	 * an error.  For example, "-c" option might have or might
	 * not have an argument.  If opterr is non-zero, getopt()
	 * prints an error message when "-c"'s argument is missing.
	 */
	opterr = 0;

	 /* parsing the parameters */
	while ((opt = getopt(argc, argv, cmd_options)) > 0) {
		switch (opt) {
		/* public parameters */
		case 'h':
			usage(2);
			break;
		case 'c':	/* list cvar types or their parameters */
			cvar_type = optarg;
			ls_cvars = 1;
			break;
		case 'f':
			if (!optarg)
				usage(1);

			yyin = fopen(optarg, "r");
			if (!yyin) {
				filebench_log(LOG_FATAL,
				    "Cannot open file %s!", optarg);
				exit(1);
			}

			dofile = DOFILE_TRUE;
			fscriptname = optarg;
			break;
		/* private parameters: when filebench calls itself */
		case 'a':
			if (!optarg)
				usage(1);

			procname = optarg;
			break;
		case 's':
			if (!optarg)
				usage(1);
			sscanf(optarg, "%p", &shmaddr);
			break;
		case 'm':
			if (!optarg)
				usage(1);
			sscanf(optarg, "%s", shmpath);
			break;
		case 'i':
			if (!optarg)
				usage(1);
			sscanf(optarg, "%d", &instance);
			break;
		case '?':
			if (optopt == 'c') {
				ls_cvars = 1;
				break;
			}
		default:
			usage(1);
			break;
		}
	}

	/*
	 * Init things common to all processes: master and workers
	 */
	my_pid = getpid();
	fb_set_rlimit();
	fb_urandom_init();
	clock_init();

	if (procname) {
		/* A child Filebench instance */
		if (ipc_attach(shmaddr) < 0) {
			filebench_log(LOG_FATAL, "Cannot attach shm for %s",
			    procname);
			exit(1);
		}
		
		/* get correct function pointer for each working process */
		filebench_plugin_funcvecinit();
		
		/* Load custom variable libraries and re-validate handles. */
		ret = init_cvar_libraries();
		if (ret)
			exit(1);

		ret = revalidate_cvar_handles();
		if (ret)
			exit(1);

		/* execute corresponding procflow */
		if (procflow_exec(procname, instance) < 0) {
			filebench_log(LOG_FATAL, "Cannot startup process %s",
			    procname);
			exit(1);
		}

		exit(0);
	}

	/*
	 * Master process
	 */
	printf("Filebench Version %s\n", FILEBENCH_VERSION);
	disable_aslr();

	/* saving executable name to exec it later as worker processes */
	execname = argv[0];

	/* saving current working directory */
	cwdret = getcwd(cwd, MAXPATHLEN);
	if (cwdret != cwd) {
		filebench_log(LOG_FATAL, "Cannot save current "
					 "working directory!");
		exit(1);
	}

	fb_set_shmmax();

	ipc_init();

	if (fscriptname)
		(void)strcpy(filebench_shm->shm_fscriptname, fscriptname);

	flowop_init();
	stats_init();
	eventgen_init();
	
	/* Initialize custom variables. */
	ret = init_cvar_library_info(FILEBENCHDIR "/cvars");
	if (ret)
		filebench_shutdown(1);

	ret = init_cvar_libraries();
	if (ret)
		filebench_shutdown(1);

	if (ls_cvars) {
		if (cvar_type)
			parser_list_cvar_type_parameters(cvar_type);
		else
			parser_list_cvar_types();
		exit(1);
	}

	signal(SIGINT, parser_abort);

	if (dofile == DOFILE_TRUE)
		yyparse();
	else {
#ifdef HAVE_LIBTECLA
		if ((gl = new_GetLine(MAX_LINE_LEN, MAX_CMD_HIST)) == NULL) {
			filebench_log(LOG_ERROR,
			    "Failed to create GetLine object");
			filebench_shutdown(1);
		}

		if (gl_customize_completion(gl, NULL, command_complete)) {
			filebench_log(LOG_ERROR,
			    "Failed to register auto-completion function");
			filebench_shutdown(1);
		}

		while ((line = gl_get_line(gl, FILEBENCH_PROMPT, NULL, -1))) {
			arg_parse(line);
			yyparse();
		}

		del_GetLine(gl);
#else
		while (!feof(stdin)) {
			printf(FILEBENCH_PROMPT);
			fflush(stdout);
			if (fgets(line, sizeof (line), stdin) == NULL) {
				if (errno == EINTR)
					continue;
				else
					break;
			}
			arg_parse(line);
			yyparse();
		}
		printf("\n");
#endif	/* HAVE_LIBTECLA */
	}

	parser_filebench_shutdown((cmd_t *)0);

	return 0;
}

/*
 * arg_parse() puts the parser into command parsing mode. Create a tmpfile
 * and instruct the parser to read instructions from this location by setting
 * yyin to the value returned by tmpfile. Write the command into the file.
 * Then seek back to to the start of the file so that the parser can read
 * the instructions.
 */
static void
arg_parse(const char *command)
{
	if ((yyin = tmpfile()) == NULL) {
		filebench_log(LOG_FATAL,
		    "Exiting: Cannot create tmpfile: %s", strerror(errno));
		exit(1);
	}

	if (fwrite(command, strlen(command), 1, yyin) != 1)
		filebench_log(LOG_FATAL,
		    "Cannot write tmpfile: %s", strerror(errno));

	if (fseek(yyin, 0, SEEK_SET) != 0)
		filebench_log(LOG_FATAL,
		    "Cannot seek tmpfile: %s", strerror(errno));
}

/*
 * Converts a list of var_strings or ordinary strings to a single ordinary
 * string. It returns a pointer to the string (in malloc'd memory) if found,
 * or NULL otherwise.
 */
char *
parser_list2string(list_t *list)
{
	list_t *l;
	char *string;
	char *tmp;

	string = malloc(MAXPATHLEN);
	if (!string) {
		filebench_log(LOG_ERROR, "Failed to allocate memory");
		return NULL;
	}

	*string = 0;

	/* Format args */
	for (l = list; l != NULL; l = l->list_next) {

		char *lstr = avd_get_str(l->list_string);

		filebench_log(LOG_DEBUG_SCRIPT, "converting string '%s'", lstr);

		/* see if it is a random variable */
		if (l->list_integer) {
			fbint_t param_name;

			tmp = NULL;
			param_name = avd_get_int(l->list_integer);

			switch (param_name) {
			case FSS_TYPE:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_TYPE);
				break;

			case FSS_SRC:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_SRC);
				break;

			case FSS_SEED:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_SEED);
				break;

			case FSS_MIN:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_MIN);
				break;

			case FSS_MEAN:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_MEAN);
				break;

			case FSS_GAMMA:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_GAMMA);
				break;

			case FSS_ROUND:
				tmp = var_randvar_to_string(lstr,
				    RAND_PARAM_ROUND);
				break;
			}

			if (tmp) {
				(void) strcat(string, tmp);
				free(tmp);
			} else {
				(void) strcat(string, lstr);
			}
		} else {
			/* perhaps a normal variable? */
			if ((tmp = var_to_string(lstr)) != NULL) {
				(void) strcat(string, tmp);
				free(tmp);
			} else {
				(void) strcat(string, lstr);
			}
		}
	}

	return string;
}

/*
 * If the list just contains a single string starting with '$', then find
 * or create the named var and return the var's var_string component.
 * Otherwise, convert the list to a string, and allocate a var_string
 * containing a copy of that string. On failure either returns NULL
 * or shuts down the run.
 */
avd_t
parser_list2varstring(list_t *list)
{
	char *lstr = avd_get_str(list->list_string);

	/* Special case - variable name */
	if ((list->list_next == NULL) && (*lstr == '$'))
		return avd_var_alloc(lstr);

	return (avd_str_alloc(parser_list2string(list)));
}

/*
 * Looks for the var named in list_string of the first element of the
 * supplied list. If found, returns the var_val portion of the var in
 * an attribute value descriptor. If the var is not found, cannot be
 * allocated, the supplied list is NULL, or the list_string filed is
 * empty, returns NULL.
 */
avd_t
parser_list2avd(list_t *list)
{
	avd_t avd;
	char *lstr;

	if (list && ((lstr = avd_get_str(list->list_string)) != NULL)) {
		avd = avd_var_alloc(lstr);
		return (avd);
	}

	return (NULL);
}

/*
 * Sets the event generator rate from the attribute supplied with the
 * command. If the attribute doesn't exist the routine does nothing.
 */
static void
parser_eventgen(cmd_t *cmd)
{
	attr_t *attr;

	/* Get the rate from attribute */
	if ((attr = get_attr_integer(cmd, FSA_RATE))) {
		if (attr->attr_avd) {
			eventgen_setrate(attr->attr_avd);
		}
	}
}

/*
 * Lists the fileset name, path name and average size for all defined
 * filesets.
 */
static void
parser_list(cmd_t *cmd)
{
	(void) fileset_iter(fileset_print);
}

/*
 * Lists the flowop name and instance number for all flowops.
 */
static void
parser_flowop_list(cmd_t *cmd)
{
	flowop_printall();
}

/*
 * Calls procflow_define() to allocate "instances" number of  procflow(s)
 * (processes) with the supplied name. The default number of instances is
 * one. An optional priority level attribute can be supplied and is stored in
 * pf_nice. Finally the routine loops through the list of inner commands, if
 * any, which are defines for threadflows, and passes them one at a time to
 * parser_thread_define() to allocate threadflow entities for the process(es).
 */
static void
parser_proc_define(cmd_t *cmd)
{
	procflow_t *procflow;
	char *name = NULL;
	attr_t *attr;
	avd_t var_instances;
	fbint_t instances;
	cmd_t *inner_cmd;

	/* Get the name of the process */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define proc: proc specifies no name");
		filebench_shutdown(1);
	}

	/* Get the memory size from attribute */
	if ((attr = get_attr_integer(cmd, FSA_INSTANCES))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "proc_define: Instances attr cannot be random");
			filebench_shutdown(1);
		}
		var_instances = attr->attr_avd;
		instances = avd_get_int(var_instances);
		filebench_log(LOG_DEBUG_IMPL,
		    "Setting instances = %llu", (u_longlong_t)instances);
	} else {
		filebench_log(LOG_DEBUG_IMPL,
		    "Defaulting to instances = 1");
		var_instances = avd_int_alloc(1);
		instances = 1;
	}

	if ((procflow = procflow_define(name, NULL, var_instances)) == NULL) {
		filebench_log(LOG_ERROR,
		    "Failed to instantiate %d %s process(es)\n",
		    instances, name);
		filebench_shutdown(1);
	}

	/* Get the pri from attribute */
	if ((attr = get_attr_integer(cmd, FSA_NICE))) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "proc_define: priority cannot be random");
			filebench_shutdown(1);
		}
		filebench_log(LOG_DEBUG_IMPL, "Setting pri = %llu",
		    (u_longlong_t)avd_get_int(attr->attr_avd));
		procflow->pf_nice = attr->attr_avd;
	} else
		procflow->pf_nice = avd_int_alloc(0);


	/* Create the list of threads for this process  */
	for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
	    inner_cmd = inner_cmd->cmd_next) {
		parser_thread_define(inner_cmd, procflow, instances);
	}
}

/*
 * Calls threadflow_define() to allocate "instances" number of  threadflow(s)
 * (threads) with the supplied name. The default number of instances is
 * one. Two other optional attributes may be supplied, one to set the memory
 * size, stored in tf_memsize, and to select the use of Interprocess Shared
 * Memory, which sets the THREADFLOW_USEISM flag in tf_attrs. Finally
 * the routine loops through the list of inner commands, if any, which are
 * defines for flowops, and passes them one at a time to
 * parser_flowop_define() to allocate flowop entities for the threadflows.
 */
static void
parser_thread_define(cmd_t *cmd, procflow_t *procflow, int procinstances)
{
	threadflow_t *threadflow, template;
	attr_t *attr;
	avd_t instances;
	cmd_t *inner_cmd;
	char *name = NULL;

	memset(&template, 0, sizeof (threadflow_t));

	/* Get the name of the thread */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define thread: thread in process %s specifies no name",
		    procflow->pf_name);
		filebench_shutdown(1);
	}

	/* Get the number of instances from attribute */
	if ((attr = get_attr_integer(cmd, FSA_INSTANCES))) {
		instances = attr->attr_avd;
	} else
		instances = avd_int_alloc(1);

	/* Get the memory size from attribute */
	if ((attr = get_attr_integer(cmd, FSA_MEMSIZE))) {
		template.tf_memsize = attr->attr_avd;
	} else
		template.tf_memsize = avd_int_alloc(0);

	/* Get ioprio parameters from attribute */
	if ((attr = get_attr_integer(cmd, FSA_IOPRIO))) {
		template.tf_ioprio = attr->attr_avd;
	} else
		template.tf_ioprio = avd_int_alloc(8);

	if ((threadflow = threadflow_define(procflow, name,
	    &template, instances)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define thread: Failed to instantiate thread\n");
		filebench_shutdown(1);
	}

	/* Use ISM Memory? */
	if ((attr = get_attr(cmd, FSA_USEISM))) {
		threadflow->tf_attrs |= THREADFLOW_USEISM;
	}

	/* Create the list of flowops */
	for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
	    inner_cmd = inner_cmd->cmd_next) {
		parser_flowop_define(inner_cmd, threadflow,
		    &threadflow->tf_thrd_fops, FLOW_MASTER);
	}
}

/*
 * Fills in the attributes for a newly allocated flowop
 */
static void
parser_flowop_get_attrs(cmd_t *cmd, flowop_t *flowop)
{
	attr_t *attr;

	/* Get the filename from attribute */
	if ((attr = get_attr(cmd, FSA_FILE))) {
		flowop->fo_filename = attr->attr_avd;
		if (flowop->fo_filename == NULL) {
			filebench_log(LOG_ERROR,
			    "define flowop: no filename specfied");
			filebench_shutdown(1);
		}
	} else {
		/* no filename attribute specified */
		flowop->fo_filename = NULL;
	}

	/* Get the iosize of the op */
	if ((attr = get_attr_integer(cmd, FSA_IOSIZE)))
		flowop->fo_iosize = attr->attr_avd;
	else
		flowop->fo_iosize = avd_int_alloc(0);

	/* Get the working set size of the op */
	if ((attr = get_attr_integer(cmd, FSA_WSS)))
		flowop->fo_wss = attr->attr_avd;
	else
		flowop->fo_wss = avd_int_alloc(0);

	/* Random I/O? */
	if ((attr = get_attr_bool(cmd, FSA_RANDOM)))
		flowop->fo_random = attr->attr_avd;
	else
		flowop->fo_random = avd_bool_alloc(FALSE);

	/* Sync I/O? */
	if ((attr = get_attr_bool(cmd, FSA_DSYNC)))
		flowop->fo_dsync = attr->attr_avd;
	else
		flowop->fo_dsync = avd_bool_alloc(FALSE);

	/* Target, for wakeup etc */
	if ((attr = get_attr(cmd, FSA_TARGET)))
		(void) strcpy(flowop->fo_targetname,
		    avd_get_str(attr->attr_avd));

	/* Value */
	if ((attr = get_attr_integer(cmd, FSA_VALUE)))
		flowop->fo_value = attr->attr_avd;
	else
		flowop->fo_value = avd_int_alloc(0);

	/* FD */
	if ((attr = get_attr_integer(cmd, FSA_FD))) {
		flowop->fo_fdnumber = avd_get_int(attr->attr_avd);
		if (flowop->fo_filename != NULL)
			filebench_log(LOG_DEBUG_SCRIPT, "It is not "
			    "advisable to supply both an fd number "
			    "and a fileset name in most cases");
	}

	/* Rotatefd? */
	if ((attr = get_attr_bool(cmd, FSA_ROTATEFD)))
		flowop->fo_rotatefd = attr->attr_avd;
	else
		flowop->fo_rotatefd = avd_bool_alloc(FALSE);

	/* SRC FD, for copies etc... */
	if ((attr = get_attr_integer(cmd, FSA_SRCFD)))
		flowop->fo_srcfdnumber = avd_get_int(attr->attr_avd);

	/* Blocking operation? */
	if ((attr = get_attr_bool(cmd, FSA_BLOCKING)))
		flowop->fo_blocking = attr->attr_avd;
	else
		flowop->fo_blocking = avd_bool_alloc(FALSE);

	/* Direct I/O Operation */
	if ((attr = get_attr_bool(cmd, FSA_DIRECTIO)))
		flowop->fo_directio = attr->attr_avd;
	else
		flowop->fo_directio = avd_bool_alloc(FALSE);

	/* Highwater mark */
	if ((attr = get_attr_integer(cmd, FSA_HIGHWATER))) {
		flowop->fo_highwater = attr->attr_avd;
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define flowop: Highwater attr cannot be random");
			filebench_shutdown(1);
		}
	} else {
		flowop->fo_highwater = avd_int_alloc(1);
	}

	/* find file or leaf directory by index number */
	if ((attr = get_attr_integer(cmd, FSA_INDEXED)))
		flowop->fo_fileindex = attr->attr_avd;
	else
		flowop->fo_fileindex = NULL;

	/* Read Ahead Diable */
	if ((attr = get_attr_bool(cmd, FSA_NOREADAHEAD)))
		flowop->fo_noreadahead = attr->attr_avd;
	else
		flowop->fo_noreadahead = avd_bool_alloc(FALSE);

	/* byte-range lock offset */
	if ((attr = get_attr_integer(cmd, FSA_OFFSET)))
		flowop->fo_offset = attr->attr_avd;
	else
		flowop->fo_offset = NULL;
	/* FIXME: avd_int_alloc(0)? */
	/* TODO: allow offset to be a random variable */

	/* byte-range lock length */
	if ((attr = get_attr_integer(cmd, FSA_LENGTH)))
		flowop->fo_length = attr->attr_avd;
	else
		flowop->fo_length = NULL;

	/* byte-range lock type */
	if ((attr = get_attr(cmd, FSA_LOCKTYPE))) {
		strncpy(flowop->fo_locktype, avd_get_str(attr->attr_avd), 16);
	}
}

/*
 * defines the FLOW_MASTER flowops within a FLOW_MASTER instance of
 * a composit flowop. Default attributes from the FLOW_INNER_DEF instances
 * of the composit flowop's inner flowops are used if set. Otherwise
 * default attributes from the FLOW_MASTER instance of the composit flowop
 * are used, which may include defaults from the original FLOW_DEFINITION
 * of the composit flowop.
 */
static void
parser_inner_flowop_define(threadflow_t *thread, flowop_t *comp0_flow,
			   flowop_t *comp_mstr_flow)
{
	flowop_t *inner_flowtype, *inner_flowop;

	/* follow flowop list, creating composit names */
	inner_flowtype = comp0_flow->fo_comp_fops;
	comp_mstr_flow->fo_comp_fops = NULL;

	while (inner_flowtype) {
		char fullname[MAXPATHLEN];

		/* create composite_name.name for new flowop */
		snprintf(fullname, MAXPATHLEN, "%s.%s",
		    comp_mstr_flow->fo_name, inner_flowtype->fo_name);

		if ((inner_flowop = flowop_define(thread, fullname,
		    inner_flowtype, &comp_mstr_flow->fo_comp_fops,
		    FLOW_MASTER, 0)) == NULL) {
			filebench_log(LOG_ERROR,
			    "define flowop: Failed to instantiate flowop %s\n",
			    fullname);
			filebench_shutdown(1);
		}

		/* if applicable, update filename attribute */
		if (inner_flowop->fo_filename) {
			char *name;

			/* fix up avd_t */
			avd_update(&inner_flowop->fo_filename,
			    comp_mstr_flow->fo_lvar_list);

			/* see if ready to get the file or fileset */
			name = avd_get_str(inner_flowop->fo_filename);
			if (name) {

				inner_flowop->fo_fileset = fileset_find(name);

				if (inner_flowop->fo_fileset == NULL) {
					filebench_log(LOG_ERROR,
					    "inr flowop %s: file %s not found",
					    inner_flowop->fo_name, name);
					filebench_shutdown(1);
				}
			}
		}

		/* update attributes from local variables */
		avd_update(&inner_flowop->fo_iters,
		    comp_mstr_flow->fo_lvar_list);

		/* if the inner flowop is a composit flowop, recurse */
		if (inner_flowtype->fo_type == FLOW_TYPE_COMPOSITE) {
			var_t *newlvar, *proto_lvars, *lvar_ptr;

			proto_lvars = inner_flowop->fo_lvar_list;
			inner_flowop->fo_lvar_list = 0;

			for (lvar_ptr = inner_flowtype->fo_lvar_list; lvar_ptr;
			    lvar_ptr = lvar_ptr->var_next) {

				if ((newlvar = var_lvar_alloc_local(
				    lvar_ptr->var_name)) != NULL) {

					add_lvar_to_list(newlvar,
					    &inner_flowop->fo_lvar_list);

					var_update_comp_lvars(newlvar,
					    proto_lvars,
					    comp_mstr_flow->fo_lvar_list);
				}
			}
		  
			parser_inner_flowop_define(thread,
			    inner_flowtype,
			    inner_flowop);

			inner_flowtype = inner_flowtype->fo_exec_next;
			continue;
		}

		avd_update(&inner_flowop->fo_iosize,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_wss,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_iters,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_value,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_random,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_dsync,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_rotatefd,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_blocking,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_directio,
		    comp_mstr_flow->fo_lvar_list);
		avd_update(&inner_flowop->fo_highwater,
		    comp_mstr_flow->fo_lvar_list);

		inner_flowtype = inner_flowtype->fo_exec_next;
	}
}

/*
 * Calls flowop_define() to allocate a flowop with the supplied name.
 * The allocated flowop inherits attributes from a base flowop of the
 * same type.  If the new flowop has a file or fileset attribute specified,
 * it must specify a defined fileobj or fileset or an error will be logged.
 * The new flowop may  also have the following attributes set by
 * the program:
 *  - file size (fo_iosize)
 *  - working set size (fo_wss)
 *  - do random io (fo_random)
 *  - do synchronous io (fo_dsync)
 *  - perform each operation multiple times before advancing (fo_iter)
 *  - target name (fo_targetname)
 *  - An integer value (fo_value)
 *  - a file descriptor (fo_fd)
 *  - specify to rotate file descriptors (fo_rotatefd)
 *  - a source fd (fo_srcfdnumber)
 *  - specify a blocking operation (fo_blocking)
 *  - specify a highwater mark (fo_highwater)
 *
 * After all the supplied attributes are stored in their respective locations
 * in the flowop object, the flowop's init function is called. No errors are
 * returned, but the filebench run will be terminated if the flowtype is not
 * specified, a name for the new flowop is not supplied, the flowop_define
 * call fails, or a file or fileset name is supplied but the corresponding
 * fileobj or fileset cannot be located.
 */
static void
parser_flowop_define(cmd_t *cmd, threadflow_t *thread,
    flowop_t **flowoplist_hdp, int category)
{
	flowop_t *flowop, *flowop_type;
	char *type = (char *)cmd->cmd_name;
	char *name = NULL;
	attr_t *attr;

	/* Get the inherited flowop */
	flowop_type = flowop_find(type);
	if (flowop_type == NULL) {
		filebench_log(LOG_ERROR,
		    "define flowop: flowop type %s not found",
		    type);
		filebench_shutdown(1);
	}

	/* Get the name of the flowop */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define flowop: flowop %s specifies no name",
		    flowop_type->fo_name);
		filebench_shutdown(1);
	}

	if ((flowop = flowop_define(thread, name,
	    flowop_type, flowoplist_hdp, category, 0)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define flowop: Failed to instantiate flowop %s\n",
		    cmd->cmd_name);
		filebench_shutdown(1);
	}

	/* Iterations */
	if ((attr = get_attr_integer(cmd, FSA_ITERS)))
		flowop->fo_iters = attr->attr_avd;
	else
		flowop->fo_iters = avd_int_alloc(1);


	/* if this is a use of a composit flowop, create inner FLOW MASTERS */
	if (flowop_type->fo_type == FLOW_TYPE_COMPOSITE) {
		get_attr_lvars(cmd, flowop);
		if (category == FLOW_MASTER)
			parser_inner_flowop_define(thread,
			    flowop_type, flowop);
	}
	else {
		parser_flowop_get_attrs(cmd, flowop);
	}
}

static void
parser_composite_flowop_define(cmd_t *cmd)
{
	flowop_t *flowop;
	cmd_t *inner_cmd;
	char *name = NULL;
	attr_t *attr;

	/* Get the name of the flowop */
	if ((attr = get_attr(cmd, FSA_NAME))) {
		name = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "define flowop: Composit flowop specifies no name");

		filebench_shutdown(1);
	}

	if ((flowop = flowop_new_composite_define(name)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define flowop: Failed to instantiate flowop %s\n",
		    cmd->cmd_name);
		filebench_shutdown(1);
	}

	/* place any local var_t variables on the flowop's local list */
	get_attr_lvars(cmd, flowop);

	/* Iterations */
	if ((attr = get_attr_integer(cmd, FSA_ITERS)))
		flowop->fo_iters = attr->attr_avd;
	else
		flowop->fo_iters = avd_int_alloc(1);

	/* define inner flowops */
	for (inner_cmd = cmd->cmd_list; inner_cmd != NULL;
	    inner_cmd = inner_cmd->cmd_next) {
		parser_flowop_define(inner_cmd, NULL,
		    &flowop->fo_comp_fops, FLOW_INNER_DEF);
	}
}


/*
 * Calls fileset_define() to allocate a fileset with the supplied name and
 * initializes the fileset's pathname attribute, and optionally the
 * fileset_cached, fileset_reuse, fileset_prealloc and fileset_size attributes.
 *
 */
static fileset_t *
parser_fileset_define_common(cmd_t *cmd)
{
	fileset_t *fileset;
	avd_t name;
	attr_t *attr;

	/*
	 * Make sure all plugin flowops are initialized.
	 * Defaults to local fs for now
	 */
	flowop_plugin_flowinit();

	/* Get the name of the file */
	if ((attr = get_attr_fileset(cmd, FSA_NAME))) {
		name = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR,
		    "define fileset: file or fileset specifies no name");
		return (NULL);
	}

	if ((fileset = fileset_define(name)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define file: failed to instantiate file %s\n",
		    avd_get_str(name));
		return (NULL);
	}

	if ((attr = get_attr(cmd, FSA_PATH)))  {
		fileset->fs_path = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR, "Cannot interpret path");
		return (NULL);
	}

	/* How much should we preallocate? */
	if ((attr = get_attr_integer(cmd, FSA_PREALLOC)) &&
	    attr->attr_avd) {
		if (AVD_IS_RANDOM(attr->attr_avd)) {
			filebench_log(LOG_ERROR,
			    "define fileset: Prealloc attr cannot be random");
			filebench_shutdown(1);
		}
		fileset->fs_preallocpercent = attr->attr_avd;
	} else if (attr && !attr->attr_avd) {
		fileset->fs_preallocpercent = avd_int_alloc(100);
	} else {
		fileset->fs_preallocpercent = avd_int_alloc(0);
	}

	/* Should we preallocate? */
	if ((attr = get_attr_bool(cmd, FSA_PREALLOC)))
		fileset->fs_prealloc = attr->attr_avd;
	else
		fileset->fs_prealloc = avd_bool_alloc(FALSE);

	/* Should we prealloc in parallel? */
	if ((attr = get_attr_bool(cmd, FSA_PARALLOC)))
		fileset->fs_paralloc = attr->attr_avd;
	else
		fileset->fs_paralloc = avd_bool_alloc(FALSE);

	/* Should we allow writes to the file? */
	if ((attr = get_attr_bool(cmd, FSA_READONLY)))
		fileset->fs_readonly = attr->attr_avd;
	else
		fileset->fs_readonly = avd_bool_alloc(FALSE);

	if ((attr = get_attr_bool(cmd, FSA_WRITEONLY)))
		fileset->fs_writeonly = attr->attr_avd;
	else
		fileset->fs_writeonly = avd_bool_alloc(FALSE);

	if ((avd_get_bool(fileset->fs_readonly) == TRUE) &&
		(avd_get_bool(fileset->fs_writeonly) == TRUE)) {
		filebench_log(LOG_ERROR, "fileset can't be read-only and "
					"write-only at the same time!");
		return NULL;
	}

	/* Should we reuse the existing file? */
	if ((attr = get_attr_bool(cmd, FSA_REUSE)))
		fileset->fs_reuse = attr->attr_avd;
	else
		fileset->fs_reuse = avd_bool_alloc(FALSE);

	/* Should we check for files actual existance? */
	if ((attr = get_attr_bool(cmd, FSA_TRUSTTREE)))
		fileset->fs_trust_tree = attr->attr_avd;
	else
		fileset->fs_trust_tree = avd_bool_alloc(FALSE);

	/* Should we leave in cache? */
	if ((attr = get_attr_bool(cmd, FSA_CACHED)))
		fileset->fs_cached = attr->attr_avd;
	else
		fileset->fs_cached = avd_bool_alloc(FALSE);

	/* Get the mean or absolute size of the file */
	if ((attr = get_attr_integer(cmd, FSA_SIZE)))
		fileset->fs_size = attr->attr_avd;
	else
		fileset->fs_size = avd_int_alloc(0);

	return (fileset);
}

/*
 * Calls parser_fileset_define_common() to allocate a fileset with
 * one entry and optionally the fileset_prealloc. sets the fileset_entries,
 * fileset_dirwidth, fileset_dirgamma, and fileset_sizegamma attributes
 * to appropriate values for emulating the old "fileobj" entity
 */
static void
parser_file_define(cmd_t *cmd)
{
	fileset_t *fileset;

	if ((fileset = parser_fileset_define_common(cmd)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define file: failed to instantiate file");
		filebench_shutdown(1);
		return;
	}

	/* fileset is emulating a single file */
	fileset->fs_attrs = FILESET_IS_FILE;

	/* Set the size of the fileset to 1 */
	fileset->fs_entries = avd_int_alloc(1);

	/* Set the mean dir width to more than 1 */
	fileset->fs_dirwidth = avd_int_alloc(10);

	/* Set the dir and size gammas to 0 */
	fileset->fs_dirgamma = avd_int_alloc(0);

	fileset->fs_leafdirs = avd_int_alloc(0);
}

/*
 * Calls parser_fileset_define_common() to allocate a fileset with the
 * supplied name and initializes the fileset's fileset_preallocpercent,
 * fileset_prealloc, fileset_entries, fileset_dirwidth, fileset_dirgamma,
 * and fileset_sizegamma attributes.
 */
static void
parser_fileset_define(cmd_t *cmd)
{
	fileset_t *fileset;
	attr_t *attr;

	if ((fileset = parser_fileset_define_common(cmd)) == NULL) {
		filebench_log(LOG_ERROR,
		    "define fileset: failed to instantiate fileset");
		filebench_shutdown(1);
		return;
	}

	/* Get the number of files in the fileset */
	if ((attr = get_attr_integer(cmd, FSA_ENTRIES))) {
		fileset->fs_entries = attr->attr_avd;
	} else {
		fileset->fs_entries = avd_int_alloc(0);
	}

	/* Get the number of leafdirs in the fileset */
	if ((attr = get_attr_integer(cmd, FSA_LEAFDIRS))) {
		fileset->fs_leafdirs = attr->attr_avd;
	} else {
		fileset->fs_leafdirs = avd_int_alloc(0);
	}

	/* Get the mean dir width of the fileset */
	if ((attr = get_attr_integer(cmd, FSA_DIRWIDTH))) {
		fileset->fs_dirwidth = attr->attr_avd;
	} else {
		filebench_log(LOG_ERROR, "Fileset has zero directory width");
		fileset->fs_dirwidth = avd_int_alloc(0);
	}

	/* Get the dir depth */
	if ((attr = get_attr_integer(cmd, FSA_DIRDEPTHRV))) {
		fileset->fs_dirdepthrv = attr->attr_avd;
	} else {
		fileset->fs_dirdepthrv = NULL;
	}

	/* Get the gamma value for dir depth distributions */
	if ((attr = get_attr_integer(cmd, FSA_DIRGAMMA))) {
		fileset->fs_dirgamma = attr->attr_avd;
	} else
		fileset->fs_dirgamma = avd_int_alloc(1500);
}

/*
 * Creates and starts all defined procflow processes. The call to
 * procflow_init() results in creation of the requested number of
 * process instances for each previously defined procflow. The
 * child processes exec() a new instance of filebench, passing it
 * the instance number and address of the shared memory region.
 * The child processes will then create their threads and flowops.
 * The routine then unlocks the run_lock to allow all the processes'
 * threads to start and  waits for all of them to begin execution.
 * Finally, it records the start time and resets the event generation
 * system.
 */
static void
parser_proc_create(cmd_t *cmd)
{
	filebench_shm->shm_1st_err = 0;
	filebench_shm->shm_f_abort = FILEBENCH_OK;

	(void) pthread_rwlock_rdlock(&filebench_shm->shm_run_lock);

	if (procflow_init() != 0) {
		filebench_log(LOG_ERROR, "Failed to create processes\n");
		filebench_shutdown(1);
	}

	/* Wait for all threads to start */
	if (procflow_allstarted() != 0) {
		filebench_log(LOG_ERROR, "Could not start run");
		return;
	}

	/* Release the read lock, allowing threads to start */
	(void) pthread_rwlock_unlock(&filebench_shm->shm_run_lock);

	if (filebench_shm->shm_required &&
	    (ipc_ismcreate(filebench_shm->shm_required) < 0)) {
		filebench_log(LOG_ERROR, "Could not allocate shared memory");
		return;
	}

	filebench_shm->shm_starttime = gethrtime();
	eventgen_reset();
}

/*
 * Calls fileset_createsets() to populate all filesets and create all
 * associated, initially existant,  files and subdirectories.
 * If errors are encountered, calls filebench_shutdown() to exit Filebench.
 */
static void
parser_fileset_create(cmd_t *cmd)
{
	if (!filecreate_done) {
		filecreate_done = 1;

		if (fileset_createsets()) {
			filebench_log(LOG_ERROR, "Failed to create filesets");
			filebench_shutdown(1);
		}
	} else {
		filebench_log(LOG_INFO,
		    "Attempting to create fileset more than once, ignoring");
	}

}

/*
 * Deletes the files and directories that represent files and filesets on the
 * storage medium.
 */
static void
parser_fileset_shutdown(cmd_t *cmd)
{
	filebench_log(LOG_INFO, "Shutting down filesets");
	fileset_delete_all_filesets();
}

/*
 * Shuts down all processes and their associated threads. When finished
 * it deletes interprocess shared memory and resets the event generator.
 * It does not exit the filebench program though.
 */
static void
parser_proc_shutdown(cmd_t *cmd)
{
	filebench_log(LOG_INFO, "Shutting down processes");
	filecreate_done = 0;
	procflow_shutdown();
	if (filebench_shm->shm_required)
		ipc_ismdelete();
	eventgen_reset();
}

/*
 * Ends filebench run after first destoring any interprocess
 * shared memory. The call to filebench_shutdown()
 * also causes filebench to exit.
 */
static void
parser_filebench_shutdown(cmd_t *cmd)
{
	int f_abort = filebench_shm->shm_f_abort;

	ipc_fini();

	if (f_abort == FILEBENCH_ABORT_ERROR)
		filebench_shutdown(1);
	else
		filebench_shutdown(0);
}

/*
 * This is used for timing runs. Pauses the master thread in one second
 * intervals until the supplied ptime runs out or the f_abort flag
 * is raised. If given a time of zero, it will pause until f_abort is raised.
 */
static int
parser_pause(int ptime)
{
	int timeslept = 0;

	if (ptime) {
		while (timeslept < ptime) {
			(void) sleep(1);
			timeslept++;
			if (filebench_shm->shm_f_abort)
				break;
		}
	} else {
		/* initial runtime of 0 means run till abort */
		/* CONSTCOND */
		while (1) {
			(void) sleep(1);
			timeslept++;
			if (filebench_shm->shm_f_abort)
				break;
		}
	}

	return (timeslept);
}

#define TIMED_RUNTIME_DEFAULT 60 /* In seconds */
#define PERIOD_DEFAULT 10 /* In seconds */

/*
 * Do a file bench run. Calls routines to create file sets, files, and
 * processes. It resets the statistics counters, then sleeps for the runtime
 * passed as an argument to it on the command line in 1 second increments.
 * When it is finished sleeping, it collects a snapshot of the statistics
 * and ends the run.
 */
static void
parser_run(cmd_t *cmd)
{
	int runtime;
	int timeslept;

	runtime = cmd->cmd_qty;

	parser_fileset_create(cmd);
	parser_proc_create(cmd);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");
	stats_clear();

	/* If it is a timed mode and timeout is not specified use default */
	if (filebench_shm->shm_rmode == FILEBENCH_MODE_TIMEOUT && !runtime)
		runtime = TIMED_RUNTIME_DEFAULT;

	timeslept = parser_pause(runtime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
	parser_statssnap(cmd);
	parser_proc_shutdown(cmd);
	parser_filebench_shutdown((cmd_t *)0);
}

static void
parser_psrun(cmd_t *cmd)
{
	int runtime;
	int period;
	int timeslept = 0;
	int reset_stats = 0;

	runtime = cmd->cmd_qty;

	/*
	 * If period is negative then
	 * we want to reset statistics
	 * at the end of the every period
	 */
	if (cmd->cmd_qty1 < 0) {
		period = -cmd->cmd_qty1;
		reset_stats = 1;	
	} else if (cmd->cmd_qty1 > 0) {
		period = cmd->cmd_qty1;
		reset_stats = 0;
	} else { /* (cmd->cmd_qty1) == 0 */
		period = PERIOD_DEFAULT;
		reset_stats = 0;
	}

	parser_fileset_create(cmd);
	parser_proc_create(cmd);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");
	stats_clear();

	/* If it is a timed mode and timeout is not specified use default */
	if (filebench_shm->shm_rmode == FILEBENCH_MODE_TIMEOUT && !runtime)
		runtime = TIMED_RUNTIME_DEFAULT;

	while (1) {
		/* sleep the remaining time if a period is smaller */
		if (filebench_shm->shm_rmode == FILEBENCH_MODE_TIMEOUT)
			period = period > (runtime - timeslept) ?
						(runtime - timeslept) : period;

		timeslept += parser_pause(period);

		if (filebench_shm->shm_f_abort)
			break;

		if (filebench_shm->shm_rmode == FILEBENCH_MODE_TIMEOUT &&
							timeslept >= runtime)
			break;

		parser_statssnap(cmd);

		if (reset_stats)
			stats_clear();
	}

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
	parser_statssnap(cmd);
	parser_proc_shutdown(cmd);
	parser_filebench_shutdown((cmd_t *)0);
}

/*
 * Similar to parser_run, but gets the sleep time from a variable
 * whose name is supplied as an argument to the command.
 */
static void
parser_run_variable(cmd_t *cmd)
{
	avd_t integer = avd_var_alloc(cmd->cmd_tgt1);
	int runtime;
	int timeslept;

	if (integer == NULL) {
		filebench_log(LOG_ERROR, "Unknown variable %s",
		cmd->cmd_tgt1);
		return;
	}

	runtime = avd_get_int(integer);

	parser_fileset_create(cmd);
	parser_proc_create(cmd);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");
	stats_clear();

	/* If it is a timed mode and timeout is not specified use default */
	if (filebench_shm->shm_rmode == FILEBENCH_MODE_TIMEOUT && !runtime)
		runtime = TIMED_RUNTIME_DEFAULT;

	timeslept = parser_pause(runtime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
	parser_statssnap(cmd);
	parser_proc_shutdown(cmd);
	parser_filebench_shutdown((cmd_t *)0);
}

char *usagestr = NULL;

/*
 * Prints usage string if defined, else just a message requesting load of a
 * personality.
 */
static void
parser_help(cmd_t *cmd)
{
	if (usagestr) {
		filebench_log(LOG_INFO, "%s", usagestr);
	} else {
		filebench_log(LOG_INFO,
		    "load <personality> (ls "
		    "%s/workloads for list)", fbbasepath);
	}
}

/*
 * Establishes multi-client synchronization socket with synch server.
 */
static void
parser_enable_mc(cmd_t *cmd)
{
	attr_t *attr;
	char *master;
	char *client;

	if ((attr= get_attr(cmd, FSA_MASTER))) {
		master = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "enable multi: no master specified");
		return;
	}

	if ((attr= get_attr(cmd, FSA_CLIENT))) {
		client = avd_get_str(attr->attr_avd);
	} else {
		filebench_log(LOG_ERROR,
		    "enable multi: no client specified");
		return;
	}

	mc_sync_open_sock(master, 8001, client);
}

/*
 * Exchanges multi-client synchronization message with synch server.
 */
static void
parser_domultisync(cmd_t *cmd)
{
	attr_t *attr;
	fbint_t value;

	if ((attr = get_attr(cmd, FSA_VALUE)))
		value = avd_get_int(attr->attr_avd);
	else
		value = 1;

	mc_sync_synchronize((int)value);
}

/*
 * Sleeps for cmd->cmd_qty seconds, one second at a time.
 */
static void
parser_warmup(cmd_t *cmd)
{
	int sleeptime;

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	sleeptime = cmd->cmd_qty;
	filebench_log(LOG_INFO, "Warming up...");

	(void) parser_pause(sleeptime);
}

/*
 * Same as parser_sleep, except the sleep time is obtained from a variable
 * whose name is passed to it as an argument on the command line.
 */
static void
parser_warmup_variable(cmd_t *cmd)
{
	avd_t integer = avd_var_alloc(cmd->cmd_tgt1);
	int sleeptime;

	if (integer == NULL) {
		filebench_log(LOG_ERROR, "Unknown variable %s",
		cmd->cmd_tgt1);
		return;
	}

	sleeptime = avd_get_int(integer);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Warming up...");

	(void) parser_pause(sleeptime);
}

/*
 * Sleeps for cmd->cmd_qty seconds, one second at a time.
 */
static void
parser_sleep(cmd_t *cmd)
{
	int sleeptime;
	int timeslept;

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	sleeptime = cmd->cmd_qty;
	filebench_log(LOG_INFO, "Running...");

	timeslept = parser_pause(sleeptime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
}

/*
 * Same as parser_sleep, except the sleep time is obtained from a variable
 * whose name is passed to it as an argument on the command line.
 */
static void
parser_sleep_variable(cmd_t *cmd)
{
	avd_t integer = avd_var_alloc(cmd->cmd_tgt1);
	int sleeptime;
	int timeslept;

	if (integer == NULL) {
		filebench_log(LOG_ERROR, "Unknown variable %s",
		cmd->cmd_tgt1);
		return;
	}

	sleeptime = avd_get_int(integer);

	/* check for startup errors */
	if (filebench_shm->shm_f_abort)
		return;

	filebench_log(LOG_INFO, "Running...");

	timeslept = parser_pause(sleeptime);

	filebench_log(LOG_INFO, "Run took %d seconds...", timeslept);
}

/*
 * Parser log prints the values of a list of variables to the log file.
 * The list of variables is placed on the command line, separated
 * by comas and the entire list is enclosed in quotes.
 * For example, if $dir contains "/export/home/tmp" and $filesize = 1048576,
 * then typing: log "$dir, $filesize" prints: log /export/home/tmp, 1048576
 */
static void
parser_log(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE, "log %s", string);
	filebench_log(LOG_LOG, "%s", string);
}

/*
 * Implements the stats directory command. changes the directory for
 * dumping statistics to supplied directory path. For example:
 * 	stats directory /tmp
 * changes the stats directory to "/tmp".
 */
static void
parser_directory(cmd_t *cmd)
{
	char newdir[MAXPATHLEN];
	char *dir;
	int ret;

	if ((dir = parser_list2string(cmd->cmd_param_list)) == NULL) {
		filebench_log(LOG_ERROR, "Cannot interpret directory");
		return;
	}

	*newdir = 0;
	/* Change dir relative to cwd if path not fully qualified */
	if (*dir != '/') {
		(void) strcat(newdir, cwd);
		(void) strcat(newdir, "/");
	}
	(void) strcat(newdir, dir);
	(void) mkdir(newdir, 0755);
	filebench_log(LOG_VERBOSE, "Change dir to %s", newdir);
	if ((ret = chdir(newdir)) < 0) {
		filebench_log(LOG_ERROR, "Cannot change directory to %s: %s",
			      newdir, strerror(errno));
		return;
	}
	free(dir);
}

#define	PIPE_PARENT 1
#define	PIPE_CHILD  0

/*
 * Runs the quoted unix command as a background process. Intended for
 * running statistics gathering utilities such as mpstat while the filebench
 * workload is running. Also records the pid's of the background processes
 * so that parser_statssnap() can terminate them when the run completes.
 */
static void
parser_statscmd(cmd_t *cmd)
{
	char *string;
	pid_t pid;
	pidlist_t *pidlistent;
	int pipe_fd[2];
	int newstdout;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	if ((pipe(pipe_fd)) < 0) {
		filebench_log(LOG_ERROR, "statscmd pipe failed");
		goto out;
	}

#ifdef HAVE_FORK1
	if ((pid = fork1()) < 0) {
		filebench_log(LOG_ERROR, "statscmd fork failed");
		goto out;
	}
#elif HAVE_FORK
	if ((pid = fork()) < 0) {
		filebench_log(LOG_ERROR, "statscmd fork failed");
		goto out;
	}
#else
	Crash! - Need code to deal with no fork1!
#endif /* HAVE_FORK1 */

	if (pid == 0) {

		setsid();

		filebench_log(LOG_VERBOSE,
		    "Backgrounding %s", string);
		/*
		 * Child
		 * - close stdout
		 * - dup to create new stdout
		 * - close pipe fds
		 */
		(void) close(1);

		if ((newstdout = dup(pipe_fd[PIPE_CHILD])) < 0) {
			filebench_log(LOG_ERROR,
			    "statscmd dup failed: %s",
			    strerror(errno));
		}

		(void) close(pipe_fd[PIPE_PARENT]);
		(void) close(pipe_fd[PIPE_CHILD]);

		if (system(string) < 0) {
			filebench_log(LOG_ERROR,
			    "statscmd exec failed: %s",
			    strerror(errno));
		}
		/* Failed! */
		exit(1);

	} else {

		/* Record pid in pidlist for subsequent reaping by stats snap */
		if ((pidlistent = (pidlist_t *)malloc(sizeof (pidlist_t)))
		    == NULL) {
			filebench_log(LOG_ERROR, "pidlistent malloc failed");
			goto out;
		}

		pidlistent->pl_pid = pid;
		pidlistent->pl_fd = pipe_fd[PIPE_PARENT];
		(void) close(pipe_fd[PIPE_CHILD]);

		/* Add fileobj to global list */
		if (pidlist == NULL) {
			pidlist = pidlistent;
			pidlistent->pl_next = NULL;
		} else {
			pidlistent->pl_next = pidlist;
			pidlist = pidlistent;
		}
	}

out:
	free(string);
}

/*
 * Launches a shell to run the unix command supplied in the argument.
 * The command should be enclosed in quotes, as in:
 * 	system "rm xyz"
 * which would run the "rm" utility to delete the file "xyz".
 */
static void
parser_system(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Running '%s'", string);

	if (system(string) < 0) {
		filebench_log(LOG_ERROR,
		    "system exec failed: %s",
		    strerror(errno));
		filebench_shutdown(1);
	}
	free(string);
}

/*
 * Echos string supplied with command to the log.
 */
static void
parser_echo(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_INFO, "%s", string);
}

static void parser_fscheck(cmd_t *cmd) {
	return;
}

#if 0
/* XXX: do not support this command for now */
/*
 * Checks to see if the specified data directory exists and it's mounted file
 * system is the correct type.
 */
static void
parser_fscheck(cmd_t *cmd)
{
	int fstype_idx;
	char *pathname = NULL;
	char *filesys = "tmpfs";
	char string[MAXPATHLEN];
	struct statvfs64 statbuf;
	attr_t *attr;

	if (cmd->cmd_attr_list == NULL)
		return;

	for (attr = cmd->cmd_attr_list; attr; attr = attr->attr_next) {

		switch(attr->attr_name) {
		case FSA_PATH:
			pathname = avd_get_str(attr->attr_avd);
			break;
		case FSA_FSTYPE:
			filesys = avd_get_str(attr->attr_avd);
			break;
		}
	}

	if (pathname == NULL)
		return;

	if (statvfs64(pathname, &statbuf) < 0) {
		filebench_log(LOG_ERROR,
		    "%s error with supplied data path name: %s; exiting",
		    strerror(errno), pathname);
		filebench_shutdown(1);
		return;
	}

	if (strncmp(filesys, statbuf.f_basetype, FSTYPSZ) != 0) {
		filebench_log(LOG_ERROR,
		    "File System is of type %s, NOT %s as indicated",
		    statbuf.f_basetype, filesys);
		filebench_shutdown(1);
		return;
	}
}
#endif

/*
 * Checks to see if any filesets need to have their caches flushed, and
 * if so invokes the fs_flush script.
 */
static void
parser_fsflush(cmd_t *cmd)
{
	fileset_t *fileset;
	char **fspathlist;
	char *pathname = NULL;
	char *filesys = NULL;
	char string[MAXPATHLEN];
	attr_t *attr;
	int fsidx;

	if ((attr = cmd->cmd_attr_list) == NULL)
		return;

	/* Get supplied file system type */
	if (attr->attr_name == FSA_FSTYPE)
		filesys = avd_get_str(attr->attr_avd);

	if (filesys == NULL) {
		filebench_log(LOG_ERROR,
		    "FSFLUSH command lacks file system type");
		return;
	}

	/* Check all filesets for any that remain cached and count them*/
	fsidx = 0;
	for (fileset = filebench_shm->shm_filesetlist; fileset != NULL;
	     fileset = fileset->fs_next) {

		if (avd_get_bool(fileset->fs_cached))
			return;

		fsidx++;
	}

	/* allocated space for fileset path pointers */
	fspathlist = (char **)malloc(fsidx * sizeof(char *));

	/* If flushing still required, flush all filesets */
	fsidx = 0;
	for (fileset = filebench_shm->shm_filesetlist; fileset != NULL;
	     fileset = fileset->fs_next) {
		int idx;

		if ((pathname = avd_get_str(fileset->fs_path)) == NULL)
			goto out;

		for (idx = 0; idx < fsidx; idx++) {
			if (strcmp(pathname, fspathlist[idx]) == 0)
				break;
		}

		if (fsidx == idx) {

			/* found a new path */
			fspathlist[fsidx++] = pathname;

			/* now flush it */
			snprintf(string, MAXPATHLEN,
			    "%s/scripts/fs_flush %s %s", fbbasepath,
			    filesys, pathname);

			if (system(string) < 0) {
				filebench_log(LOG_ERROR,
				    "exec of fs_flush script failed: %s",
				    strerror(errno));
				free(fspathlist);
				filebench_shutdown(1);
			}
		}
	}

out:
	free(fspathlist);
}

/*
 * Prints out the version of Filebench.
 */
static void
parser_version(cmd_t *cmd)
{
	filebench_log(LOG_INFO, "Filebench Version: %s", FILEBENCH_VERSION);
}

/*
 * Sets osprof_enabled option
 */
static void
parser_osprof_enable(cmd_t *cmd)
{
	filebench_shm->osprof_enabled = 1;
	filebench_log(LOG_INFO, "OSprof enabled");
}

/*
 * Resets osprof_enabled option
 */
static void
parser_osprof_disable(cmd_t *cmd)
{
	filebench_shm->osprof_enabled = 0;
	filebench_log(LOG_INFO, "OSprof disabled");
}

/*
 * Adds the string supplied as the argument to the usage command
 * to the end of the string printed by the help command.
 */
static void
parser_usage(cmd_t *cmd)
{
	char *string;
	char *newusage;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	if (dofile == DOFILE_TRUE) {
		free(string);
		return;
	}

	if (usagestr == NULL) {
		newusage = malloc(strlen(string) + 2);
		*newusage = 0;
	} else {
		newusage = malloc(strlen(usagestr) + strlen(string) + 2);
		(void) strcpy(newusage, usagestr);
	}
	(void) strcat(newusage, "\n");
	(void) strcat(newusage, string);

	if (usagestr)
		free(usagestr);

	usagestr = newusage;

	filebench_log(LOG_INFO, "%s", string);

	free(string);
}

/*
 * Updates the global dump filename with the filename supplied
 * as the command's argument. Then dumps the statistics of each
 * worker flowop into the dump file, followed by a summary of
 * overall totals.
 */
static void
parser_statsdump(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Stats dump to file '%s'", string);

	stats_dump(string);

	free(string);
}

/*
 * Same as statsdump, but outputs in a computer friendly format.
 */
static void
parser_statsmultidump(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Stats dump to file '%s'", string);

	stats_multidump(string);

	free(string);
}

/*
 * Same as parser_statsdump, but in xml format.
 */
static void
parser_statsxmldump(cmd_t *cmd)
{
	char *string;

	if (cmd->cmd_param_list == NULL)
		return;

	string = parser_list2string(cmd->cmd_param_list);

	if (string == NULL)
		return;

	filebench_log(LOG_VERBOSE,
	    "Stats dump to file '%s'", string);

	stats_xmldump(string);

	free(string);
}

/*
 * Kills off background statistics collection processes, then takes a snapshot
 * of the filebench run's collected statistics using stats_snap() from
 * stats.c.
 */
static void
parser_statssnap(cmd_t *cmd)
{
	pidlist_t *pidlistent;
	int stat;
	pid_t pid;

	for (pidlistent = pidlist; pidlistent != NULL;
	    pidlistent = pidlistent->pl_next) {
		filebench_log(LOG_VERBOSE, "Killing session %d for pid %d",
		    getsid(pidlistent->pl_pid),
		    pidlistent->pl_pid);
		if (pidlistent->pl_fd)
			(void) close(pidlistent->pl_fd);
#ifdef HAVE_SIGSEND
		sigsend(P_SID, getsid(pidlistent->pl_pid), SIGTERM);
#else
		(void) kill(-1, SIGTERM);
#endif

		/* Close pipe */
		if (pidlistent->pl_fd)
			(void) close(pidlistent->pl_fd);

		/* Wait for cmd and all its children */
		while ((pid = waitpid(pidlistent->pl_pid * -1, &stat, 0)) > 0)
			filebench_log(LOG_DEBUG_IMPL,
			"Waited for pid %d", (int)pid);
	}

	for (pidlistent = pidlist; pidlistent != NULL;
	    pidlistent = pidlistent->pl_next) {
		free(pidlistent);
	}

	pidlist = NULL;
	stats_snap();
}

/*
 * Shutdown filebench.
 */
static void
parser_abort(int arg)
{
	(void) sigignore(SIGINT);
	filebench_log(LOG_INFO, "Aborting...");
	filebench_shutdown(1);
}

/*
 * define a random variable and initialize the distribution parameters
 */
static void
parser_var_assign_random(char *name, cmd_t *cmd)
{
	randdist_t	*rndp;
	attr_t		*attr;

	rndp = randdist_alloc();
	if (!rndp) {
		filebench_log(LOG_ERROR,
			"failed to alloc random distribution object\n");
		return;
	}

	rndp->rnd_type = 0;

	/* Get the source of the random numbers */
	if ((attr = get_attr_integer(cmd, FSA_RANDSRC))) {
		int randsrc = (int)avd_get_int(attr->attr_avd);

		switch (randsrc) {
		case FSV_URAND:
			rndp->rnd_type |= RAND_SRC_URANDOM;
			break;
		case FSV_RAND48:
			rndp->rnd_type |= RAND_SRC_GENERATOR;
			break;
		}
	} else {
		/* default to rand48 random number generator */
		rndp->rnd_type |= RAND_SRC_GENERATOR;
	}

	/* Get the min value of the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_MIN)))
		rndp->rnd_min = attr->attr_avd;
	else
		rndp->rnd_min = avd_int_alloc(0);

	/* Get the roundoff value for the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_ROUND)))
		rndp->rnd_round = attr->attr_avd;
	else
		rndp->rnd_round = avd_int_alloc(0);

	/* Get a tablular probablility distribution if there is one */
	if ((attr = get_attr(cmd, FSA_RANDTABLE))) {
		rndp->rnd_probtabs = (probtabent_t *)(attr->attr_obj);
		rndp->rnd_type |= RAND_TYPE_TABLE;

		/* no need for the rest of the attributes */
		goto randdist_init;
	} else {
		rndp->rnd_probtabs = NULL;
	}

	/* Get the type for the random variable */
	if ((attr = get_attr(cmd, FSA_TYPE))) {
		int disttype = (int)avd_get_int(attr->attr_avd);

		switch (disttype) {
		case FSV_RANDUNI:
			rndp->rnd_type |= RAND_TYPE_UNIFORM;
			break;
		case FSA_RANDGAMMA:
			rndp->rnd_type |= RAND_TYPE_GAMMA;
			break;
		case FSV_RANDTAB:
			filebench_log(LOG_ERROR,
			    "Table distribution type without prob table");
			break;
		}
	} else {
		/* default to gamma distribution type */
		rndp->rnd_type |= RAND_TYPE_GAMMA;
	}

	/* Get the seed for the random variable */
	if ((attr = get_attr_integer(cmd, FSA_RANDSEED)))
		rndp->rnd_seed = attr->attr_avd;
	else
		rndp->rnd_seed = avd_int_alloc(0);

	/* Get the gamma value of the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_RANDGAMMA)))
		rndp->rnd_gamma = attr->attr_avd;
	else
		rndp->rnd_gamma = avd_int_alloc(1500);

	/* Get the mean value of the random distribution */
	if ((attr = get_attr_integer(cmd, FSA_RANDMEAN))) {
		rndp->rnd_mean = attr->attr_avd;
	} else if ((rndp->rnd_type & RAND_TYPE_MASK) == RAND_TYPE_GAMMA) {
		rndp->rnd_mean = NULL;
	} else {
		rndp->rnd_mean = avd_int_alloc(0);
	}

	var_assign_random(name, rndp);

randdist_init:
	randdist_init(rndp);
}

/*
 * alloc_cmd() allocates the required resources for a cmd_t. On failure, a
 * filebench_log is issued and NULL is returned.
 */
static cmd_t *
alloc_cmd(void)
{
	cmd_t *cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd) {
		filebench_log(LOG_ERROR, "Alloc cmd failed");
		return NULL;
	}

	memset(cmd, 0, sizeof (cmd_t));

	return cmd;
}

/*
 * Allocates an attr_t structure and zeros it. Returns NULL on failure, or
 * a pointer to the attr_t.
 */
static attr_t *
alloc_attr(void)
{
	attr_t *attr;

	attr = malloc(sizeof(*attr));
	if (!attr)
		return (NULL);

	(void) memset(attr, 0, sizeof(*attr));

	return (attr);
}

/*
 * Allocates a probtabent_t structure and zeros it. Returns NULL on failure, or
 * a pointer to the probtabent_t.
 */
static probtabent_t *
alloc_probtabent(void)
{
	probtabent_t *rte;

	if ((rte = malloc(sizeof (probtabent_t))) == NULL) {
		return (NULL);
	}

	(void) memset(rte, 0, sizeof (probtabent_t));
	return (rte);
}

/*
 * Allocates an attr_t structure and puts the supplied var_t into
 * its attr_avd location, and sets its name to FSA_LVAR_ASSIGN
 */
static attr_t *
alloc_lvar_attr(var_t *var)
{
	attr_t *attr;

	if ((attr = alloc_attr()) == NULL)
		return (NULL);

	attr->attr_name = FSA_LVAR_ASSIGN;
	attr->attr_avd = (avd_t)var;

	return (attr);
}


/*
 * Searches the attribute list for the command for the named attribute type.
 * The attribute list is created by the parser from the list of attributes
 * supplied with certain commands, such as the define and flowop commands.
 * Returns a pointer to the attribute structure if the named attribute is
 * found, otherwise returns NULL. If the attribute includes a parameter list,
 * the list is converted to a string and stored in the attr_avd field of
 * the returned attr_t struct.
 */
static attr_t *
get_attr_fileset(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		filebench_log(LOG_DEBUG_IMPL,
		    "attr %d = %d %llx?",
		    attr->attr_name,
		    name,
		    attr->attr_avd);

		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list) {
		filebench_log(LOG_DEBUG_SCRIPT, "attr is param list");
		rtn->attr_avd = parser_list2varstring(rtn->attr_param_list);
	}

	return (rtn);
}


/*
 * Searches the attribute list for the command for the named attribute type.
 * The attribute list is created by the parser from the list of attributes
 * supplied with certain commands, such as the define and flowop commands.
 * Returns a pointer to the attribute structure if the named attribute is
 * found, otherwise returns NULL. If the attribute includes a parameter list,
 * the list is converted to a string and stored in the attr_avd field of
 * the returned attr_t struct.
 */
static attr_t *
get_attr(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;
	char *string;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		filebench_log(LOG_DEBUG_IMPL,
		    "attr %d = %d %llx?",
		    attr->attr_name,
		    name,
		    attr->attr_avd);

		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list) {
		filebench_log(LOG_DEBUG_SCRIPT, "attr is param list");
		string = parser_list2string(rtn->attr_param_list);
		if (string != NULL) {
			rtn->attr_avd = avd_str_alloc(string);
			filebench_log(LOG_DEBUG_SCRIPT,
			    "attr string %s", string);
		}
	}

	return (rtn);
}

/*
 * Similar to get_attr, but converts the parameter string supplied with the
 * named attribute to an integer and stores the integer in the attr_avd
 * portion of the returned attr_t struct.
 */
static attr_t *
get_attr_integer(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list)
		rtn->attr_avd = parser_list2avd(rtn->attr_param_list);

	return (rtn);
}

/*
 * Similar to get_attr, but converts the parameter string supplied with the
 * named attribute to an integer and stores the integer in the attr_avd
 * portion of the returned attr_t struct. If no parameter string is supplied
 * then it defaults to TRUE (1).
 */
static attr_t *
get_attr_bool(cmd_t *cmd, int64_t name)
{
	attr_t *attr;
	attr_t *rtn = NULL;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {
		if (attr->attr_name == name)
			rtn = attr;
	}

	if (rtn == NULL)
		return (NULL);

	if (rtn->attr_param_list) {
		rtn->attr_avd = parser_list2avd(rtn->attr_param_list);

	} else if (rtn->attr_avd == NULL) {
		rtn->attr_avd = avd_bool_alloc(TRUE);
	}

	/* boolean attributes cannot point to random variables */
	if (AVD_IS_RANDOM(rtn->attr_avd)) {
		filebench_log(LOG_ERROR,
		    "define flowop: Boolean attr %s cannot be random", name);
		filebench_shutdown(1);
		return (NULL);
	}

	return (rtn);
}

/*
 * removes the newly allocated local var from the shared local var
 * list, then puts it at the head of the private local var list
 * supplied as the second argument.
 */
static void
add_lvar_to_list(var_t *newlvar, var_t **lvar_list)
{
	var_t *prev;

	/* remove from shared local list, if there */
	if (newlvar == filebench_shm->shm_var_loc_list) {
		/* on top of list, just grap */
		filebench_shm->shm_var_loc_list = newlvar->var_next;
	} else {
		/* find newvar on list and remove */
		for (prev = filebench_shm->shm_var_loc_list; prev;
		    prev = prev->var_next) {
			if (prev->var_next == newlvar)
				prev->var_next = newlvar->var_next;
		}
	}
	newlvar->var_next = NULL;

	/* add to flowop private local list at head */
	newlvar->var_next = *lvar_list;
	*lvar_list = newlvar;
}

/*
 * Searches the attribute list for the command for any allocated local
 * variables. The attribute list is created by the parser from the list of
 * attributes supplied with certain commands, such as the define and flowop
 * commands. Places all found local vars onto the flowop's local variable
 * list. 
 */
static void
get_attr_lvars(cmd_t *cmd, flowop_t *flowop)
{
	attr_t *attr;
	var_t *orig_lvar_list;

	/* save the local var list */
	orig_lvar_list = flowop->fo_lvar_list;

	for (attr = cmd->cmd_attr_list; attr != NULL;
	    attr = attr->attr_next) {

		if (attr->attr_name == FSA_LVAR_ASSIGN) {
			var_t *newvar;

			if ((newvar = (var_t *)attr->attr_avd) == NULL)
				continue;

			add_lvar_to_list(newvar, &flowop->fo_lvar_list);
			var_update_comp_lvars(newvar, orig_lvar_list, NULL);
		}
	}
}

/*
 * Allocates memory for a list_t structure, initializes it to zero, and
 * returns a pointer to it. On failure, returns NULL.
 */
static list_t *
alloc_list()
{
	list_t *list;

	if ((list = malloc(sizeof (list_t))) == NULL) {
		return (NULL);
	}

	(void) memset(list, 0, sizeof (list_t));
	return (list);
}

/*
 * Define a custom variable and validate its parameters.
 * TODO: Clean up state when things go wrong.
 */
static void
parser_var_assign_custom(char *name, cmd_t *cmd)
{
	cvar_t	*cvar;
	attr_t	*attr;
	char	*type;
	char	*parameters;
	int 	ret;

	attr = get_attr(cmd, FSA_TYPE);
	if (attr)
		type = avd_get_str(attr->attr_avd);
	else {
		filebench_log(LOG_ERROR, "define cvar: no type specified");
		filebench_shutdown(1);
		return;
	}

	cvar = cvar_alloc();
	if (!cvar) {
		filebench_log(LOG_ERROR, "Failed to allocate custom variable");
		filebench_shutdown(1);
		return;
	}

	/* Initialize the custom variable mutex. */
	(void) pthread_mutex_init(&cvar->cvar_lock,
			ipc_mutexattr(IPC_MUTEX_NORMAL));

	/* Get the min, max and round values for the custom variable. */
	if ((attr = get_attr(cmd, FSA_MIN)))
		cvar->min = avd_get_dbl(attr->attr_avd);
	else
		cvar->min = DBL_MIN;

	if ((attr = get_attr(cmd, FSA_MAX)))
		cvar->max = avd_get_dbl(attr->attr_avd);
	else
		cvar->max = DBL_MAX;

	if ((attr = get_attr(cmd, FSA_ROUND)))
		cvar->round = avd_get_dbl(attr->attr_avd);
	else
		cvar->round = 0;

	attr = get_attr(cmd, FSA_PARAMETERS);
	if (attr)
		parameters = avd_get_str(attr->attr_avd);
	else
		parameters = NULL;

	ret = init_cvar_handle(cvar, type, parameters);
	if (ret) {
		filebench_log(LOG_FATAL, "define cvar: failed for custom variable %s",
		    name);
		filebench_shutdown(1);
		return;
	}

	var_assign_custom(name, cvar);
}

void parser_list_cvar_types(void)
{
	cvar_library_info_t *t;

	if (!filebench_shm->shm_cvar_lib_info_list) {
		printf("No custom variables supported.\n");
		return;
	}

	printf("Custom variable types supported:\n");
	for (t = filebench_shm->shm_cvar_lib_info_list; t; t = t->next)
		printf("  %s\n", t->type);

	return;
}

void parser_list_cvar_type_parameters(char *type)
{
	const char *version = NULL;
	const char *usage = NULL;

	cvar_library_info_t *t;

	for (t = filebench_shm->shm_cvar_lib_info_list; t != NULL; t = t->next) {
		if (!strcmp(type, t->type))
			break;
	}

	if (!t) {
		printf("Unknown custom variable type %s.", type);
		return;
	}

	printf("Custom variable type: %s\n", t->type);
	printf("Supporting library: %s\n", t->filename);

	if (cvar_libraries[t->index]->cvar_op.cvar_version)
		version = cvar_libraries[t->index]->cvar_op.cvar_version();
	
	if (cvar_libraries[t->index]->cvar_op.cvar_usage)
		usage = cvar_libraries[t->index]->cvar_op.cvar_usage();

	
	if (version)
		printf("Version: %s\n", version);
	else
		printf("Oops. No version information provided.\n");
	
	if (usage)
		printf("Usage:\n%s\n", usage);
	else
		printf("Oops. No usage information provided.\n");
	
	return;
}
