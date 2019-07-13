/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.yy"

#include "scanner.h"//se importa el header del analisis sintactico
#include "nodoast.h"
#include "qdebug.h"
#include <string.h>
#include <iostream>
#include <QList>
#include <semantic_error.h>
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern NodoAST *raiz; // Raiz del arbol
int yyerror(const char* mens)
{
    std::cout << mens <<" "<<yytext<<" Linea: "<< yylineno<< " Columna:" << columna << std::endl;
    return 0;
}

/* Line 371 of yacc.c  */
#line 87 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     numero = 258,
     decimal = 259,
     caracter = 260,
     booleano = 261,
     cadena = 262,
     pint = 263,
     pdouble = 264,
     pbool = 265,
     pchar = 266,
     pstring = 267,
     parreglo = 268,
     pclase = 269,
     pextender = 270,
     psobrescribir = 271,
     ppublico = 272,
     pprivado = 273,
     pprotegido = 274,
     pretornar = 275,
     pvoid = 276,
     pmostrarnotificacion = 277,
     pimprimir = 278,
     psi = 279,
     psino = 280,
     ppara = 281,
     pprincipal = 282,
     prepetir = 283,
     promper = 284,
     pmientras = 285,
     pcomprobar = 286,
     phacer = 287,
     pcontinuar = 288,
     pincluir = 289,
     parchivo = 290,
     pcreararchivoder = 291,
     pcrearconjunto = 292,
     pcrearregex = 293,
     pcrearentrada = 294,
     pguardararchivo = 295,
     pcrearcuenta = 296,
     pverificarcuenta = 297,
     pdepositarcuenta = 298,
     prestarcuenta = 299,
     pimprimirtransaccionescuenta = 300,
     pconsultarcuenta = 301,
     ptransferir = 302,
     pnew = 303,
     id = 304,
     abrir_corchete = 305,
     cerrar_corchete = 306,
     coma = 307,
     punto = 308,
     finalizacion = 309,
     igual = 310,
     aumento = 311,
     decremento = 312,
     abrir_parentesis = 313,
     cerrar_parentesis = 314,
     abrir_llave = 315,
     cerrar_llave = 316,
     igual_igual = 317,
     diferente_de = 318,
     menor_que = 319,
     menorigual_que = 320,
     mayor_que = 321,
     mayorigual_que = 322,
     opor = 323,
     opand = 324,
     opnand = 325,
     opnot = 326,
     opnor = 327,
     suma = 328,
     resta = 329,
     multi = 330,
     division = 331,
     potencia = 332,
     pcaso = 333,
     psalir = 334,
     pdefecto = 335,
     dos_puntos = 336,
     pcuenta = 337
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 25 "parser.yy"

char TEXT [256];
class NodoAST* nodito;


/* Line 387 of yacc.c  */
#line 218 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 259 "parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNRULES -- Number of states.  */
#define YYNSTATES  439

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   337

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    20,    24,    25,
      27,    31,    33,    36,    38,    40,    42,    45,    47,    49,
      51,    53,    55,    57,    59,    61,    63,    65,    67,    69,
      71,    73,    76,    79,    84,    90,    94,    99,   106,   113,
     121,   129,   135,   141,   148,   155,   160,   166,   173,   181,
     191,   199,   207,   214,   221,   227,   231,   237,   245,   254,
     265,   273,   276,   284,   292,   300,   307,   314,   320,   330,
     333,   339,   349,   351,   353,   354,   359,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   385,   391,   394,
     398,   400,   402,   406,   415,   422,   429,   433,   440,   450,
     452,   454,   458,   460,   464,   468,   474,   480,   484,   488,
     492,   494,   498,   502,   506,   510,   513,   515,   519,   523,
     527,   531,   535,   539,   541,   545,   549,   553,   557,   561,
     564,   568,   570,   572,   574,   576,   578,   580,   583,   587,
     589,   591,   593,   600,   609,   615,   622,   629,   635,   641,
     650,   659,   665,   670,   673,   676,   679,   682,   685,   688,
     691,   694,   695,   697,   699,   701
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      84,     0,    -1,    85,    -1,    85,    86,    -1,    86,    -1,
      14,    49,    87,    -1,    15,    89,    60,    88,    61,    -1,
      60,    88,    61,    -1,    -1,    90,    -1,    89,    52,    49,
      -1,    49,    -1,    90,    91,    -1,    91,    -1,    92,    -1,
      93,    -1,   124,    54,    -1,    94,    -1,    96,    -1,    97,
      -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,   102,
      -1,   103,    -1,   104,    -1,   106,    -1,   107,    -1,   108,
      -1,   109,    -1,   125,    54,    -1,   126,    54,    -1,   128,
     112,    89,   114,    -1,   117,   128,   112,    89,   114,    -1,
     112,    89,   114,    -1,   117,   112,    89,   114,    -1,   128,
      13,   112,    89,   115,   116,    -1,   128,    13,   112,   115,
      89,   116,    -1,   117,   128,    13,   112,    89,   115,   116,
      -1,   117,   128,    13,   112,   115,    89,   116,    -1,    13,
     112,    89,   115,   116,    -1,    13,   112,   115,    89,   116,
      -1,   117,    13,   112,    89,   115,   116,    -1,   117,    13,
     112,   115,    89,   116,    -1,    49,    55,   121,    54,    -1,
      49,   115,    55,   121,    54,    -1,    49,    53,    49,    55,
     121,    54,    -1,    49,    53,    49,   115,    55,   121,    54,
      -1,    49,    55,    41,    58,   121,    52,   121,    59,    54,
      -1,    49,    55,    36,    58,   121,    59,    54,    -1,    49,
      55,    48,    49,    58,    59,    54,    -1,    27,    58,    59,
      60,    88,    61,    -1,    58,   113,    59,    60,    88,    61,
      -1,    58,    59,    60,    88,    61,    -1,    20,   121,    54,
      -1,    23,    58,   121,    59,    54,    -1,    22,    58,   121,
      52,   121,    59,    54,    -1,    24,    58,   121,    59,    60,
      88,    61,   111,    -1,    26,    58,   110,   121,    54,   121,
      59,    60,    88,    61,    -1,    28,    58,   121,    59,    60,
      88,    61,    -1,    29,    54,    -1,    30,    58,   121,    59,
      60,    88,    61,    -1,    31,    58,   121,    59,    60,   105,
      61,    -1,   105,    78,   121,    81,    88,    79,    54,    -1,
     105,    80,    81,    88,    79,    54,    -1,    78,   121,    81,
      88,    79,    54,    -1,    80,    81,    88,    79,    54,    -1,
      32,    60,    88,    61,    30,    58,   121,    59,    54,    -1,
      33,    54,    -1,    34,    58,   121,    59,    54,    -1,    47,
      58,   121,    52,   121,    52,   121,    59,    54,    -1,    92,
      -1,    93,    -1,    -1,    25,    60,    88,    61,    -1,    25,
      99,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    49,    -1,    21,    -1,    35,    -1,    82,    -1,
     113,    52,   112,    49,    -1,   113,    52,   112,   115,    49,
      -1,   112,    49,    -1,   112,   115,    49,    -1,    54,    -1,
      95,    -1,    55,   121,    54,    -1,    55,    41,    58,   121,
      52,   121,    59,    54,    -1,    55,    36,    58,   121,    59,
      54,    -1,    55,    48,    49,    58,    59,    54,    -1,    50,
     121,    51,    -1,    50,   121,    51,    50,   121,    51,    -1,
      50,   121,    51,    50,   121,    51,    50,   121,    51,    -1,
      54,    -1,    95,    -1,    55,   118,    54,    -1,    16,    -1,
      60,   120,    61,    -1,    60,   119,    61,    -1,   119,    52,
      60,   120,    61,    -1,   119,    52,    60,   119,    61,    -1,
      60,   119,    61,    -1,    60,   120,    61,    -1,   120,    52,
     121,    -1,   121,    -1,   121,    68,   121,    -1,   121,    72,
     121,    -1,   121,    69,   121,    -1,   121,    70,   121,    -1,
      71,   121,    -1,   122,    -1,   123,    62,   123,    -1,   123,
      63,   123,    -1,   123,    64,   123,    -1,   123,    66,   123,
      -1,   123,    65,   123,    -1,   123,    67,   123,    -1,   123,
      -1,   123,    73,   123,    -1,   123,    74,   123,    -1,   123,
      75,   123,    -1,   123,    76,   123,    -1,   123,    77,   123,
      -1,    74,   123,    -1,    58,   121,    59,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,    49,    -1,
      49,   115,    -1,    49,    53,    49,    -1,   124,    -1,   125,
      -1,   126,    -1,    49,    53,    49,    58,   127,    59,    -1,
      49,    53,    37,    58,   121,    52,   121,    59,    -1,    49,
      53,    42,    58,    59,    -1,    49,    53,    43,    58,   121,
      59,    -1,    49,    53,    44,    58,   121,    59,    -1,    49,
      53,    45,    58,    59,    -1,    49,    53,    46,    58,    59,
      -1,    49,    53,    38,    58,   121,    52,   121,    59,    -1,
      49,    53,    39,    58,   121,    52,   121,    59,    -1,    49,
      53,    40,    58,    59,    -1,    49,    58,   127,    59,    -1,
      49,    56,    -1,     3,    56,    -1,     4,    56,    -1,     5,
      56,    -1,    49,    57,    -1,     3,    57,    -1,     4,    57,
      -1,     5,    57,    -1,    -1,   120,    -1,    17,    -1,    18,
      -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   174,   175,   177,   179,   180,   182,   183,
     185,   186,   188,   189,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   224,   225,   226,   227,   228,
     229,   230,   232,   234,   235,   237,   239,   241,   243,   245,
     247,   249,   251,   253,   255,   256,   257,   258,   260,   262,
     264,   266,   268,   269,   271,   272,   273,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   286,   287,   288,   289,
     292,   293,   294,   295,   296,   297,   299,   300,   301,   304,
     305,   306,   308,   310,   311,   313,   314,   315,   316,   318,
     319,   321,   322,   323,   324,   325,   326,   328,   329,   330,
     331,   332,   333,   334,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   367,   368,   369,   370,   372,   373,   374,
     375,   377,   378,   380,   381,   382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "numero", "decimal", "caracter",
  "booleano", "cadena", "pint", "pdouble", "pbool", "pchar", "pstring",
  "parreglo", "pclase", "pextender", "psobrescribir", "ppublico",
  "pprivado", "pprotegido", "pretornar", "pvoid", "pmostrarnotificacion",
  "pimprimir", "psi", "psino", "ppara", "pprincipal", "prepetir",
  "promper", "pmientras", "pcomprobar", "phacer", "pcontinuar", "pincluir",
  "parchivo", "pcreararchivoder", "pcrearconjunto", "pcrearregex",
  "pcrearentrada", "pguardararchivo", "pcrearcuenta", "pverificarcuenta",
  "pdepositarcuenta", "prestarcuenta", "pimprimirtransaccionescuenta",
  "pconsultarcuenta", "ptransferir", "pnew", "id", "abrir_corchete",
  "cerrar_corchete", "coma", "punto", "finalizacion", "igual", "aumento",
  "decremento", "abrir_parentesis", "cerrar_parentesis", "abrir_llave",
  "cerrar_llave", "igual_igual", "diferente_de", "menor_que",
  "menorigual_que", "mayor_que", "mayorigual_que", "opor", "opand",
  "opnand", "opnot", "opnor", "suma", "resta", "multi", "division",
  "potencia", "pcaso", "psalir", "pdefecto", "dos_puntos", "pcuenta",
  "$accept", "INICIO", "LCLASES", "CLASE", "TERMINACIONCLASE",
  "RELLENOCLASE", "LIDS", "LSENTENCIAS", "SENTENCIA", "DECLARACION",
  "ASIGNACION", "PRINCIPAL", "FUNCIONES", "RETORNAR", "IMPRIMIR",
  "MOSTRARNOTIFI", "SI", "PARA", "REPETIR", "ROMPER", "MIENTRAS",
  "COMPROBAR", "CASOS", "HACER", "CONTINUAR", "INCLUIR", "TRANSFERIR",
  "PRIMERFOR", "TERMINSI", "TIPO", "LTIPOS", "TERMDECLAR", "DIMENSION",
  "TERMARRAY", "SOBREESCRITURA", "LDECLARRAY", "LLLAVE", "LEXP", "EXPL",
  "EXPR", "EXPA", "LLAMADAFUNC", "AUMENTO", "DECREMENTO", "VARF",
  "VISIBILIDAD", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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
     335,   336,   337
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    87,    87,    88,    88,
      89,    89,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    94,    95,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   105,   105,   105,   106,   107,
     108,   109,   110,   110,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   116,   117,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   125,   125,   126,   126,   126,
     126,   127,   127,   128,   128,   128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     5,     3,     0,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     5,     3,     4,     6,     6,     7,
       7,     5,     5,     6,     6,     4,     5,     6,     7,     9,
       7,     7,     6,     6,     5,     3,     5,     7,     8,    10,
       7,     2,     7,     7,     7,     6,     6,     5,     9,     2,
       5,     9,     1,     1,     0,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     2,     3,
       1,     1,     3,     8,     6,     6,     3,     6,     9,     1,
       1,     3,     1,     3,     3,     5,     5,     3,     3,     3,
       1,     3,     3,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     6,     8,     5,     6,     6,     5,     5,     8,
       8,     5,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     0,     8,
       5,    11,     0,     0,     0,     0,    77,    78,    79,    80,
      81,     0,   102,   163,   164,   165,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    82,    85,     0,     9,    13,    14,    15,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       8,   154,   158,   155,   159,   156,   160,    82,     0,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,   116,
     123,   139,   140,   141,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     8,    69,     0,     0,     0,     0,     0,
     153,   157,   161,     0,     7,    12,     0,     0,     0,     0,
      16,    31,    32,     0,     0,    10,     0,     0,     0,     0,
     137,     0,   115,   129,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     110,     0,     0,    90,     0,     0,    91,    35,     0,     0,
       0,     0,     0,     0,     6,     0,     0,   138,   130,   111,
     113,   114,   112,   117,   118,   119,   121,   120,   122,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,    45,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
      33,    99,     0,   100,    41,    42,     0,    56,     8,     0,
       0,     0,     8,     8,     0,     0,    70,     0,     0,     0,
       0,     0,   151,   144,     0,     0,   147,   148,     0,     0,
       0,     0,     0,     0,   109,    46,     0,     0,     0,    92,
       8,    88,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,    47,   142,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     8,    43,    44,     0,     0,    37,    38,
       0,     0,     0,   101,    57,    74,     0,    60,    62,     0,
       8,    63,     0,     0,     0,     0,    97,     0,     0,     0,
      48,    50,     0,    51,     0,     0,     0,    54,    86,     0,
       0,    39,    40,     0,     0,     0,   104,   103,     0,    58,
       8,     8,     0,     0,     8,     0,     0,     0,   143,   149,
     150,     0,    94,     0,    95,    87,    53,   107,   108,     0,
       8,    76,     0,     0,     0,     8,     0,    68,    71,     0,
      49,     0,     0,     0,     0,    59,     0,    67,     0,     0,
      98,    93,   106,   105,    75,    66,     0,    65,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    44,    12,    45,    46,    47,
      48,    49,   263,    50,    51,    52,    53,    54,    55,    56,
      57,    58,   322,    59,    60,    61,    62,   156,   389,    63,
     252,   187,   113,   264,    64,   313,   351,   179,   180,    89,
      90,    91,    92,    93,   181,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -327
static const yytype_int16 yypact[] =
{
      11,   -17,    43,    11,  -327,    -3,  -327,  -327,     3,   407,
    -327,  -327,   -23,   -46,   106,   108,  -327,  -327,  -327,  -327,
    -327,    37,  -327,  -327,  -327,  -327,   489,  -327,     4,     9,
      20,    27,    31,    35,    59,    73,    96,    21,   124,   122,
    -327,   130,   723,  -327,   138,   407,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,     3,   173,   150,   162,   166,     6,   193,
     407,  -327,  -327,  -327,  -327,  -327,  -327,  -327,    74,   -46,
     106,   108,  -327,  -327,   732,   489,   489,   317,   105,  -327,
     540,  -327,  -327,  -327,   489,   489,   489,   449,   184,   489,
    -327,   489,   489,   407,  -327,   489,   489,   489,   713,   442,
    -327,  -327,   489,   191,  -327,  -327,   151,    37,     3,   306,
    -327,  -327,  -327,    37,     3,  -327,   207,    98,     3,   726,
    -327,   550,  -327,    62,  -327,   489,   489,   489,   489,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
      83,   562,   567,    42,  -327,  -327,   489,   187,   574,   579,
     586,   213,   591,   159,    57,   194,   196,   218,   219,   223,
     226,   227,   229,   230,    29,   232,   236,   200,   476,   245,
     500,   239,   489,  -327,   469,   158,  -327,  -327,    74,   151,
      37,     3,    74,   151,  -327,   215,   318,   242,  -327,   145,
    -327,  -327,   145,   718,   718,   718,   718,   718,   718,    62,
      62,   234,   234,   249,   489,   276,   275,   288,   507,   407,
     278,   279,   285,   316,   294,   489,   302,   489,   489,   489,
     291,   295,   489,   489,   297,   298,   489,   489,   307,   489,
     489,   303,  -327,   489,  -327,   512,   311,   319,   315,   517,
     305,   174,    23,    98,     3,  -327,    74,   151,    98,     3,
    -327,  -327,   332,  -327,  -327,  -327,   598,  -327,   407,    67,
     489,   325,   407,   407,    80,   321,  -327,   210,   489,   240,
     326,   434,  -327,  -327,   603,   610,  -327,  -327,   524,   338,
     489,   615,   456,   340,   500,  -327,   489,   489,   342,  -327,
     407,  -327,   355,    37,   345,   215,   318,    98,     3,  -327,
     215,   318,   300,   353,   359,   360,   622,  -327,   361,   371,
     489,   362,   -27,   489,   489,    77,   489,   489,   489,  -327,
    -327,  -327,  -327,   529,   390,   489,   396,   627,   467,   404,
     408,  -327,   186,   407,  -327,  -327,   215,   318,  -327,  -327,
     300,   -31,   -26,  -327,  -327,   446,   417,  -327,  -327,   383,
     407,  -327,   489,   398,   634,   639,   430,   646,   651,   658,
    -327,  -327,   663,  -327,   427,   489,   428,  -327,  -327,   436,
     426,  -327,  -327,   -19,     7,   439,  -327,  -327,   -20,  -327,
     407,   407,   409,   668,   407,   447,   453,   489,  -327,  -327,
    -327,   455,  -327,   675,  -327,  -327,  -327,  -327,  -327,   300,
     407,  -327,   450,   433,   460,   407,   441,  -327,  -327,   188,
    -327,   461,    12,    13,   462,  -327,   468,  -327,   454,   475,
    -327,  -327,  -327,  -327,  -327,  -327,   478,  -327,  -327
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -327,  -327,  -327,   518,  -327,   -47,   -58,  -327,   496,   437,
     445,  -327,  -113,  -327,  -327,  -327,   176,  -327,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,   -14,
    -327,  -180,   -56,  -190,  -327,  -327,  -326,  -311,     5,  -327,
     410,    -9,    -7,    -1,   328,   498
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      65,   352,    66,   186,    30,   116,   265,    78,    67,   255,
      71,    72,     8,   260,    16,    17,    18,    19,    20,   123,
     127,   385,   128,   126,   383,     1,   243,    27,   130,    69,
     386,    88,     5,   385,   361,   387,    65,    70,    66,   384,
     410,    40,   407,     6,    67,    16,    17,    18,    19,    20,
     118,   362,    11,   363,   124,    77,   161,     9,    27,   243,
     189,    65,    94,    66,   385,   243,   193,    95,   408,    67,
     196,   195,    40,   432,   433,   303,   186,   309,    96,   107,
     186,   103,   304,   422,   236,    97,    77,   237,    43,    98,
     131,   132,   107,    99,    65,   217,    66,   109,   423,   150,
     151,   152,    67,   188,   158,   191,   159,   160,   226,   192,
     162,   163,   164,   100,   178,   344,   345,   107,   238,    43,
     348,   349,   236,    11,   107,   135,   136,   137,   366,   138,
     253,   101,   254,   257,   258,   214,   259,   147,   148,   149,
     199,   200,   201,   202,   186,   135,   136,   137,   107,   138,
      69,   135,   136,   137,   102,   138,   381,   382,   320,   134,
     321,   218,    73,    74,    75,    76,    16,    17,    18,    19,
      20,   251,   271,   135,   136,   137,   256,   138,   104,    27,
     105,    16,    17,    18,    19,    20,   117,   245,   106,   249,
      23,    24,    25,    40,    27,   302,   306,   305,   307,   114,
     308,   311,   310,    69,   120,   183,   184,    77,    40,   185,
      65,   225,    66,   238,   136,   137,   121,   250,    67,   266,
     122,   315,    77,   301,   107,   318,   319,   135,   136,   137,
     277,   138,   279,   280,   281,   378,   107,   284,   285,   430,
      43,   288,   125,   157,   291,   292,   182,   219,   294,   241,
     347,   346,   227,   340,   228,    43,   135,   136,   137,    65,
     138,    66,   324,    65,    65,    66,    66,    67,   194,   261,
     262,    67,    67,   185,   223,   316,   229,   230,   135,   136,
     137,   231,   138,   325,   232,   233,   379,   234,   235,   342,
     239,    65,   326,    66,   240,   333,   380,   243,   244,    67,
     237,   337,   338,    79,    80,    81,    82,    83,   135,   136,
     137,   149,   138,   392,    16,    17,    18,    19,    20,   190,
      79,    80,    81,    82,    83,   359,    -1,    27,   364,   365,
     267,   367,   368,   369,    65,   268,    66,   269,   272,   273,
     372,    40,    67,   412,   413,   274,   275,   416,   276,    84,
     282,    65,   278,    66,   283,    77,   286,   287,    85,    67,
     350,   293,   290,   424,   298,   300,    84,   393,   428,   296,
      69,    86,   261,   262,    87,    85,   185,   297,   327,   323,
     403,    65,    65,    66,    66,    65,   317,    66,    43,    67,
      67,    87,   312,    67,   135,   136,   137,   332,   138,   336,
     339,    65,   419,    66,   341,   343,    65,   353,    66,    67,
      13,    14,    15,   354,    67,    16,    17,    18,    19,    20,
      21,   355,   357,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   358,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   360,   371,    79,    80,    81,    82,    83,
     373,   135,   136,   137,    41,   138,    42,    16,    17,    18,
      19,    20,    21,   376,   391,    22,    23,    24,    25,   377,
      27,   388,    79,    80,    81,    82,    83,   390,   175,   394,
     397,   402,   404,   176,    40,   405,   328,   406,   414,    43,
     177,    84,    79,    80,    81,    82,    83,   133,   153,   409,
      85,   417,   135,   136,   137,   246,   138,   418,   335,   420,
     247,   425,   426,    86,   427,   431,    87,   248,    84,   375,
     429,     7,   435,   434,   135,   136,   137,    85,   138,   437,
     242,    43,   438,   436,   154,   135,   136,   137,    84,   138,
      86,   115,   155,    87,   135,   136,   137,    85,   138,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      86,   270,   119,    87,   411,   289,   295,     0,   135,   136,
     137,   299,   138,     0,     0,   135,   136,   137,   331,   138,
     135,   136,   137,   370,   138,   135,   136,   137,     0,   138,
       0,     0,   135,   136,   137,     0,   138,   135,   136,   137,
       0,   138,   139,   140,   141,   142,   143,   144,     0,   198,
       0,     0,     0,   145,   146,   147,   148,   149,   135,   136,
     137,   215,   138,     0,     0,     0,   216,     0,     0,     0,
     135,   136,   137,   220,   138,   135,   136,   137,   221,   138,
       0,     0,   135,   136,   137,   222,   138,   135,   136,   137,
     224,   138,     0,     0,   135,   136,   137,   314,   138,   135,
     136,   137,   329,   138,     0,     0,   135,   136,   137,   330,
     138,   135,   136,   137,   334,   138,     0,     0,   135,   136,
     137,   356,   138,   135,   136,   137,   374,   138,     0,     0,
     135,   136,   137,   395,   138,   135,   136,   137,   396,   138,
       0,     0,   135,   136,   137,   398,   138,   135,   136,   137,
     399,   138,     0,     0,   135,   136,   137,   400,   138,   135,
     136,   137,   401,   138,     0,     0,   135,   136,   137,     0,
     138,   135,   136,   137,   421,   138,   135,   136,   137,     0,
     138,     0,     0,   135,   136,   137,     0,   138,     0,   415,
     165,   166,   167,   168,     0,   169,   170,   171,   172,   173,
       0,     0,   174,   165,   166,   167,   168,     0,   169,   170,
     171,   172,   173,   107,     0,   197,   108,     0,   109,   110,
     111,   112,   107,     0,     0,   129,     0,     0,   110,   111,
     112,   145,   146,   147,   148,   149
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-327)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
       9,   312,     9,   116,    24,    63,   196,    21,     9,   189,
      56,    57,    15,   193,     8,     9,    10,    11,    12,    13,
      78,    52,    78,    70,   350,    14,    52,    21,    84,    52,
      61,    26,    49,    52,    61,    61,    45,    60,    45,   350,
      60,    35,    61,     0,    45,     8,     9,    10,    11,    12,
      64,    78,    49,    80,    68,    49,   103,    60,    21,    52,
     118,    70,    58,    70,    52,    52,   124,    58,    61,    70,
     128,   127,    35,    61,    61,    52,   189,   257,    58,    50,
     193,    60,    59,   409,    55,    58,    49,    58,    82,    58,
      85,    86,    50,    58,   103,    53,   103,    55,   409,    94,
      95,    96,   103,   117,    99,   119,   101,   102,    51,   123,
     105,   106,   107,    54,   109,   305,   306,    50,   174,    82,
     310,   311,    55,    49,    50,    68,    69,    70,    51,    72,
     188,    58,   188,   191,   192,    52,   192,    75,    76,    77,
     135,   136,   137,   138,   257,    68,    69,    70,    50,    72,
      52,    68,    69,    70,    58,    72,   346,   347,    78,    54,
      80,   156,    56,    57,    56,    57,     8,     9,    10,    11,
      12,   185,   219,    68,    69,    70,   190,    72,    54,    21,
      58,     8,     9,    10,    11,    12,    13,   182,    58,   184,
      17,    18,    19,    35,    21,   251,   254,   253,   256,    61,
     256,   259,   258,    52,    54,    54,    55,    49,    35,    58,
     219,    52,   219,   269,    69,    70,    54,    59,   219,   214,
      54,   268,    49,    49,    50,   272,   273,    68,    69,    70,
     225,    72,   227,   228,   229,    49,    50,   232,   233,    51,
      82,   236,    49,    59,   239,   240,    55,    60,   243,    49,
     308,   307,    58,   300,    58,    82,    68,    69,    70,   268,
      72,   268,    52,   272,   273,   272,   273,   268,    61,    54,
      55,   272,   273,    58,    61,   270,    58,    58,    68,    69,
      70,    58,    72,   278,    58,    58,   342,    58,    58,   303,
      58,   300,    52,   300,    58,   290,   343,    52,    59,   300,
      58,   296,   297,     3,     4,     5,     6,     7,    68,    69,
      70,    77,    72,   360,     8,     9,    10,    11,    12,    13,
       3,     4,     5,     6,     7,   320,    77,    21,   323,   324,
      54,   326,   327,   328,   343,    60,   343,    49,    60,    60,
     335,    35,   343,   390,   391,    60,    30,   394,    54,    49,
      59,   360,    50,   360,    59,    49,    59,    59,    58,   360,
      60,    58,    55,   410,    49,    60,    49,   362,   415,    58,
      52,    71,    54,    55,    74,    58,    58,    58,    52,    58,
     375,   390,   391,   390,   391,   394,    61,   394,    82,   390,
     391,    74,    60,   394,    68,    69,    70,    59,    72,    59,
      58,   410,   397,   410,    49,    60,   415,    54,   415,   410,
       3,     4,     5,    54,   415,     8,     9,    10,    11,    12,
      13,    61,    61,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    61,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    81,    54,     3,     4,     5,     6,     7,
      54,    68,    69,    70,    47,    72,    49,     8,     9,    10,
      11,    12,    13,    59,    81,    16,    17,    18,    19,    61,
      21,    25,     3,     4,     5,     6,     7,    60,    36,    81,
      50,    54,    54,    41,    35,    49,    52,    61,    79,    82,
      48,    49,     3,     4,     5,     6,     7,    87,    49,    60,
      58,    54,    68,    69,    70,    36,    72,    54,    52,    54,
      41,    61,    79,    71,    54,    54,    74,    48,    49,    52,
      79,     3,    54,    61,    68,    69,    70,    58,    72,    54,
      54,    82,    54,    79,    97,    68,    69,    70,    49,    72,
      71,    45,    97,    74,    68,    69,    70,    58,    72,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      71,    54,    64,    74,   388,   237,    54,    -1,    68,    69,
      70,    54,    72,    -1,    -1,    68,    69,    70,    54,    72,
      68,    69,    70,    54,    72,    68,    69,    70,    -1,    72,
      -1,    -1,    68,    69,    70,    -1,    72,    68,    69,    70,
      -1,    72,    62,    63,    64,    65,    66,    67,    -1,    59,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    68,    69,
      70,    59,    72,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      68,    69,    70,    59,    72,    68,    69,    70,    59,    72,
      -1,    -1,    68,    69,    70,    59,    72,    68,    69,    70,
      59,    72,    -1,    -1,    68,    69,    70,    59,    72,    68,
      69,    70,    59,    72,    -1,    -1,    68,    69,    70,    59,
      72,    68,    69,    70,    59,    72,    -1,    -1,    68,    69,
      70,    59,    72,    68,    69,    70,    59,    72,    -1,    -1,
      68,    69,    70,    59,    72,    68,    69,    70,    59,    72,
      -1,    -1,    68,    69,    70,    59,    72,    68,    69,    70,
      59,    72,    -1,    -1,    68,    69,    70,    59,    72,    68,
      69,    70,    59,    72,    -1,    -1,    68,    69,    70,    -1,
      72,    68,    69,    70,    59,    72,    68,    69,    70,    -1,
      72,    -1,    -1,    68,    69,    70,    -1,    72,    -1,    81,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      -1,    -1,    49,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    50,    -1,    49,    53,    -1,    55,    56,
      57,    58,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,    73,    74,    75,    76,    77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    84,    85,    86,    49,     0,    86,    15,    60,
      87,    49,    89,     3,     4,     5,     8,     9,    10,    11,
      12,    13,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    47,    49,    82,    88,    90,    91,    92,    93,    94,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   106,
     107,   108,   109,   112,   117,   124,   125,   126,   128,    52,
      60,    56,    57,    56,    57,    56,    57,    49,   112,     3,
       4,     5,     6,     7,    49,    58,    71,    74,   121,   122,
     123,   124,   125,   126,    58,    58,    58,    58,    58,    58,
      54,    58,    58,    60,    54,    58,    58,    50,    53,    55,
      56,    57,    58,   115,    61,    91,    89,    13,   112,   128,
      54,    54,    54,    13,   112,    49,    88,    89,   115,    53,
     115,   121,   121,   123,    54,    68,    69,    70,    72,    62,
      63,    64,    65,    66,    67,    73,    74,    75,    76,    77,
     121,   121,   121,    49,    92,    93,   110,    59,   121,   121,
     121,    88,   121,   121,   121,    37,    38,    39,    40,    42,
      43,    44,    45,    46,    49,    36,    41,    48,   121,   120,
     121,   127,    55,    54,    55,    58,    95,   114,   112,    89,
      13,   112,   112,    89,    61,   115,    89,    49,    59,   121,
     121,   121,   121,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,    52,    59,    59,    53,   121,    60,
      59,    59,    59,    61,    59,    52,    51,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    55,    58,   115,    58,
      58,    49,    54,    52,    59,   121,    36,    41,    48,   121,
      59,   112,   113,    89,   115,   114,   112,    89,    89,   115,
     114,    54,    55,    95,   116,   116,   121,    54,    60,    49,
      54,    88,    60,    60,    60,    30,    54,   121,    50,   121,
     121,   121,    59,    59,   121,   121,    59,    59,   121,   127,
      55,   121,   121,    58,   121,    54,    58,    58,    49,    54,
      60,    49,   115,    52,    59,   115,    89,    89,   115,   114,
     115,    89,    60,   118,    59,    88,   121,    61,    88,    88,
      78,    80,   105,    58,    52,   121,    52,    52,    52,    59,
      59,    54,    59,   121,    59,    52,    59,   121,   121,    58,
      88,    49,   112,    60,   116,   116,   115,    89,   116,   116,
      60,   119,   120,    54,    54,    61,    59,    61,    61,   121,
      81,    61,    78,    80,   121,   121,    51,   121,   121,   121,
      54,    54,   121,    54,    59,    52,    59,    61,    49,   115,
      88,   116,   116,   119,   120,    52,    61,    61,    25,   111,
      60,    81,    88,   121,    81,    59,    59,    50,    59,    59,
      59,    59,    54,   121,    54,    49,    61,    61,    61,    60,
      60,    99,    88,    88,    79,    81,    88,    54,    54,   121,
      54,    59,   119,   120,    88,    61,    79,    54,    88,    79,
      51,    54,    61,    61,    61,    54,    79,    54,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 172 "parser.yy"
    { raiz = (yyval.nodito); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 174 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (2)].nodito); (yyval.nodito)->add(*(yyvsp[(2) - (2)].nodito)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 175 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "lclases", "lclases"); (yyval.nodito)->add(*(yyvsp[(1) - (1)].nodito)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 177 "parser.yy"
    { NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "id", (yyvsp[(2) - (3)].TEXT)); (yyvsp[(3) - (3)].nodito)->add(*nodo); (yyval.nodito) = (yyvsp[(3) - (3)].nodito); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 179 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "clase", "clase"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "extender", "extender"); nodo->add(*(yyvsp[(2) - (5)].nodito)); (yyval.nodito)->add(*nodo); if((yyvsp[(4) - (5)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); } }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 180 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "clase", "clase"); if((yyvsp[(2) - (3)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); } }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 182 "parser.yy"
    { (yyval.nodito) = NULL; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 183 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 185 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (3)].nodito); NodoAST *nodo = new NodoAST((yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, "id", (yyvsp[(3) - (3)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 186 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "lids", "lids"); NodoAST *nodo = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "id", (yyvsp[(1) - (1)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 188 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (2)].nodito); if((yyvsp[(2) - (2)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(2) - (2)].nodito)); } }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 189 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "lsentencias", "lsentencias"); if((yyvsp[(1) - (1)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(1) - (1)].nodito)); } }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 191 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 192 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 193 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (2)].nodito); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 194 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 195 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 196 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 197 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 198 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 199 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 200 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 201 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 202 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 203 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 204 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 205 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 206 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 207 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 208 "parser.yy"
    {(yyval.nodito) = (yyvsp[(1) - (2)].nodito);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 209 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (2)].nodito); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 211 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(1) - (4)].nodito)); (yyval.nodito)->add(*(yyvsp[(2) - (4)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (4)].nodito)); if((yyvsp[(4) - (4)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(4) - (4)].nodito)); } }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 212 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(2) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); if((yyvsp[(5) - (5)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(5) - (5)].nodito)); } }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 213 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); if((yyvsp[(3) - (3)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); } }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 214 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(2) - (4)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (4)].nodito)); if((yyvsp[(4) - (4)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(4) - (4)].nodito)); } }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 215 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(1) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); if((yyvsp[(6) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (6)].nodito)); } }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 216 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(1) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); if((yyvsp[(6) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (6)].nodito)); } }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 217 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(2) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(6) - (7)].nodito)); if((yyvsp[(7) - (7)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(7) - (7)].nodito)); } }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 218 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(2) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(6) - (7)].nodito)); if((yyvsp[(7) - (7)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(7) - (7)].nodito)); } }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 219 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(2) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); if((yyvsp[(5) - (5)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(5) - (5)].nodito)); } }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 220 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(2) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); if((yyvsp[(5) - (5)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(5) - (5)].nodito)); } }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 221 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(3) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); if((yyvsp[(6) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (6)].nodito)); } }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 222 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "declaracion", "declaracion"); (yyval.nodito)->add(*(yyvsp[(3) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); if((yyvsp[(6) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (6)].nodito)); } }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 224 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_line, "asignacion", "asignacion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "id", (yyvsp[(1) - (4)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*(yyvsp[(3) - (4)].nodito)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 225 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_line, "asignacion", "asignacion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(1) - (5)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*(yyvsp[(2) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 226 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_line, "asignacion", "asignacion"); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(1) - (6)].TEXT)); NodoAST *nodo3 = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(3) - (6)].TEXT)); nodo2->add(*nodo3); nodo2->add(*(yyvsp[(5) - (6)].nodito)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 227 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_line, "asignacion", "asignacion"); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "id", (yyvsp[(1) - (7)].TEXT)); NodoAST *nodo3 = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "id", (yyvsp[(3) - (7)].TEXT)); nodo2->add(*nodo3); nodo2->add(*(yyvsp[(4) - (7)].nodito)); nodo2->add(*(yyvsp[(6) - (7)].nodito)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 228 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_line, "asignacion", "asignacion"); NodoAST *nodo3 = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, "id", (yyvsp[(1) - (9)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, "id", (yyvsp[(3) - (9)].TEXT)); nodo2->add(*nodo); nodo2->add(*(yyvsp[(5) - (9)].nodito)); nodo2->add(*(yyvsp[(7) - (9)].nodito)); (yyval.nodito)->add(*nodo3); (yyval.nodito)->add(*nodo2); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 229 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_line, "asignacion", "asignacion"); NodoAST *nodo3 = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "id", (yyvsp[(1) - (7)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "id", (yyvsp[(3) - (7)].TEXT)); nodo2->add(*nodo); nodo2->add(*(yyvsp[(5) - (7)].nodito)); (yyval.nodito)->add(*nodo3); (yyval.nodito)->add(*nodo2); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 230 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_line, "asignacion", "asignacion"); NodoAST *nodo3 = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "id", (yyvsp[(1) - (7)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "id", (yyvsp[(4) - (7)].TEXT)); nodo2->add(*nodo); (yyval.nodito)->add(*nodo3); (yyval.nodito)->add(*nodo2); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 232 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "main", "main"); if((yyvsp[(5) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); } }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 234 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "funciones", "funciones"); (yyval.nodito)->add(*(yyvsp[(2) - (6)].nodito)); if((yyvsp[(5) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); } }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 235 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "funciones", "funciones"); if((yyvsp[(4) - (5)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); } }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 237 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "retornar", "retornar"); (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 239 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "imprimir", "imprimir"); (yyval.nodito)->add(*(yyvsp[(3) - (5)].nodito)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 241 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "mostrarNotificacion", "mostrarNotificacion"); (yyval.nodito)->add(*(yyvsp[(3) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (7)].nodito)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 243 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "si", "si"); (yyval.nodito)->add(*(yyvsp[(3) - (8)].nodito)); if((yyvsp[(6) - (8)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (8)].nodito)); } if((yyvsp[(8) - (8)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(8) - (8)].nodito)); } }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 245 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (10)]).first_line, (yylsp[(1) - (10)]).first_column, "para", "para"); (yyval.nodito)->add(*(yyvsp[(3) - (10)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (10)].nodito)); (yyval.nodito)->add(*(yyvsp[(6) - (10)].nodito)); if((yyvsp[(9) - (10)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(9) - (10)].nodito)); } }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 247 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "repetir", "repetir"); (yyval.nodito)->add(*(yyvsp[(3) - (7)].nodito)); if((yyvsp[(6) - (7)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (7)].nodito)); } }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 249 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "romper", "romper"); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 251 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "mientras", "mientras"); (yyval.nodito)->add(*(yyvsp[(3) - (7)].nodito)); if((yyvsp[(6) - (7)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(6) - (7)].nodito)); } }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 253 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "comprobar", "comprobar"); (yyval.nodito)->add(*(yyvsp[(3) - (7)].nodito)); (yyval.nodito)->add(*(yyvsp[(6) - (7)].nodito)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 255 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (7)].nodito); NodoAST *nodo = new NodoAST((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_line, "caso", "caso"); nodo->add(*(yyvsp[(3) - (7)].nodito)); if((yyvsp[(5) - (7)].nodito) != NULL){ nodo->add(*(yyvsp[(5) - (7)].nodito)); } (yyval.nodito)->add(*nodo); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 256 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (6)].nodito); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_line, "defecto", "defecto"); if((yyvsp[(4) - (6)].nodito) != NULL){ nodo->add(*(yyvsp[(4) - (6)].nodito)); }  (yyval.nodito)->add(*nodo); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 257 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "casos", "casos"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_line, "caso", "caso"); nodo->add(*(yyvsp[(2) - (6)].nodito)); if((yyvsp[(4) - (6)].nodito) != NULL){ nodo->add(*(yyvsp[(4) - (6)].nodito)); } (yyval.nodito)->add(*nodo); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 258 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "casos", "casos"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_line, "defecto", "defecto");  if((yyvsp[(3) - (5)].nodito) != NULL){ nodo->add(*(yyvsp[(3) - (5)].nodito)); } (yyval.nodito)->add(*nodo); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 260 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, "hacer", "hacer"); if((yyvsp[(3) - (9)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(3) - (9)].nodito)); } (yyval.nodito)->add(*(yyvsp[(7) - (9)].nodito)); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 262 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "continuar", "continuar"); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 264 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "incluir", "incluir"); (yyval.nodito)->add(*(yyvsp[(3) - (5)].nodito)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 266 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, "transferir", "transferir"); (yyval.nodito)->add(*(yyvsp[(3) - (9)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (9)].nodito)); (yyval.nodito)->add(*(yyvsp[(7) - (9)].nodito)); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 268 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 269 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 271 "parser.yy"
    { (yyval.nodito) = NULL; }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 272 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_line, "else", "else"); if((yyvsp[(3) - (4)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(3) - (4)].nodito)); } }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 273 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "else", "else"); (yyval.nodito)->add(*(yyvsp[(2) - (2)].nodito)); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 276 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 277 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 278 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 279 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 280 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 281 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 282 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 283 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 284 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "tipo", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 286 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (4)].nodito); (yyval.nodito)->add(*(yyvsp[(3) - (4)].nodito)); NodoAST *nodo = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "id", (yyvsp[(4) - (4)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 287 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (5)].nodito); (yyval.nodito)->add(*(yyvsp[(3) - (5)].nodito)); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(5) - (5)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 288 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "ltipos", "ltipos"); (yyval.nodito)->add(*(yyvsp[(1) - (2)].nodito)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "id", (yyvsp[(2) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 289 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "ltipos", "ltipos"); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "id", (yyvsp[(3) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); (yyval.nodito)->add(*nodo); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 292 "parser.yy"
    { (yyval.nodito) = NULL; }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 293 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 294 "parser.yy"
    { (yyval.nodito) = (yyvsp[(2) - (3)].nodito); }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 295 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(2) - (8)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*(yyvsp[(4) - (8)].nodito)); (yyval.nodito)->add(*(yyvsp[(6) - (8)].nodito)); }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 296 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(2) - (6)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*(yyvsp[(4) - (6)].nodito)); }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 297 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(3) - (6)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 299 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "dimension", "dimension"); (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 300 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "dimension", "dimension"); (yyval.nodito)->add(*(yyvsp[(2) - (6)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 301 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, "dimension", "dimension"); (yyval.nodito)->add(*(yyvsp[(2) - (9)].nodito)); (yyval.nodito)->add(*(yyvsp[(5) - (9)].nodito)); (yyval.nodito)->add(*(yyvsp[(8) - (9)].nodito)); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 304 "parser.yy"
    { (yyval.nodito) = NULL; }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 305 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 306 "parser.yy"
    { (yyval.nodito) = (yyvsp[(2) - (3)].nodito); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 310 "parser.yy"
    { (yyval.nodito) = (yyvsp[(2) - (3)].nodito); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 311 "parser.yy"
    { (yyval.nodito) = (yyvsp[(2) - (3)].nodito); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 313 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (5)].nodito); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 314 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (5)].nodito); (yyval.nodito)->add(*(yyvsp[(4) - (5)].nodito)); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 315 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "ldimensionesasig", "ldimensionesasig"); (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 316 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "ldimensionesasig", "ldimensionesasig"); (yyval.nodito)->add(*(yyvsp[(2) - (3)].nodito)); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 318 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (3)].nodito); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 319 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "lexp", "lexp"); (yyval.nodito)->add(*(yyvsp[(1) - (1)].nodito)); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 321 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "or", (yyvsp[(2) - (3)].TEXT)); nodo->add(*(yyvsp[(1) - (3)].nodito)); nodo->add(*(yyvsp[(3) - (3)].nodito)); (yyval.nodito)->add(*nodo); }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 322 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "nor", (yyvsp[(2) - (3)].TEXT)); nodo->add(*(yyvsp[(1) - (3)].nodito)); nodo->add(*(yyvsp[(3) - (3)].nodito)); (yyval.nodito)->add(*nodo); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 323 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "and", (yyvsp[(2) - (3)].TEXT)); nodo->add(*(yyvsp[(1) - (3)].nodito)); nodo->add(*(yyvsp[(3) - (3)].nodito)); (yyval.nodito)->add(*nodo); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 324 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "nand", (yyvsp[(2) - (3)].TEXT)); nodo->add(*(yyvsp[(1) - (3)].nodito)); nodo->add(*(yyvsp[(3) - (3)].nodito)); (yyval.nodito)->add(*nodo); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 325 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "not", (yyvsp[(1) - (2)].TEXT)); nodo->add(*(yyvsp[(2) - (2)].nodito)); (yyval.nodito)->add(*nodo); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 326 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "expresion", "expresion"); (yyval.nodito)->add(*(yyvsp[(1) - (1)].nodito)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 328 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "igual_igual", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 329 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "diferente_de", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 330 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "menor_que", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 331 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "mayor_que", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 332 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "menorigual_que", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 333 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "mayorigual_que", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 334 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 336 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "suma", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 337 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "resta", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 338 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "multi", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 339 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "division", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 340 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "potencia", (yyvsp[(2) - (3)].TEXT)); (yyval.nodito)->add(*(yyvsp[(1) - (3)].nodito)); (yyval.nodito)->add(*(yyvsp[(3) - (3)].nodito)); }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 341 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yyvsp[(1) - (2)].TEXT), (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*(yyvsp[(2) - (2)].nodito)); }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 342 "parser.yy"
    { (yyval.nodito) = (yyvsp[(2) - (3)].nodito); }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 343 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "numero", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 344 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "decimal", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 345 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "caracter", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 346 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "boolean", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 347 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "cadena", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 348 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "id", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 349 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "arreglo", (yyvsp[(1) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "id", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*(yyvsp[(2) - (2)].nodito)); }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 350 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "objeto_var", (yyvsp[(2) - (3)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "id", (yyvsp[(1) - (3)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "id", (yyvsp[(3) - (3)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 351 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 352 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 353 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 355 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(1) - (6)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(3) - (6)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); if((yyvsp[(5) - (6)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); } }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 356 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(1) - (8)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(3) - (8)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); (yyval.nodito)->add(*(yyvsp[(5) - (8)].nodito)); (yyval.nodito)->add(*(yyvsp[(7) - (8)].nodito)); }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 357 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(1) - (5)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(3) - (5)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 358 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(1) - (6)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(3) - (6)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 359 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(1) - (6)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, "id", (yyvsp[(3) - (6)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); (yyval.nodito)->add(*(yyvsp[(5) - (6)].nodito)); }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 360 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(1) - (5)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(3) - (5)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 361 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(1) - (5)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(3) - (5)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 362 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(1) - (8)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(3) - (8)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); (yyval.nodito)->add(*(yyvsp[(5) - (8)].nodito)); (yyval.nodito)->add(*(yyvsp[(7) - (8)].nodito)); }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 363 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(1) - (8)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, "id", (yyvsp[(3) - (8)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); (yyval.nodito)->add(*(yyvsp[(5) - (8)].nodito)); (yyval.nodito)->add(*(yyvsp[(7) - (8)].nodito)); }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 364 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(1) - (5)].TEXT)); NodoAST *nodo2 = new NodoAST((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "id", (yyvsp[(3) - (5)].TEXT)); (yyval.nodito)->add(*nodo); (yyval.nodito)->add(*nodo2); }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 365 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "id", (yyvsp[(1) - (4)].TEXT));  (yyval.nodito)->add(*nodo); if((yyvsp[(3) - (4)].nodito) != NULL){ (yyval.nodito)->add(*(yyvsp[(3) - (4)].nodito)); } }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 367 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "aumento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "id", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 368 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "aumento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "numero", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 369 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "aumento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "decimal", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 370 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "aumento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "caracter", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 372 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "decremento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "id", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 373 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "decremento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "numero", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 374 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "decremento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "decimal", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 375 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "decremento", (yyvsp[(2) - (2)].TEXT)); NodoAST *nodo = new NodoAST((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "caracter", (yyvsp[(1) - (2)].TEXT)); (yyval.nodito)->add(*nodo); }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 377 "parser.yy"
    { (yyval.nodito) = NULL; }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 378 "parser.yy"
    { (yyval.nodito) = (yyvsp[(1) - (1)].nodito); }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 380 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "visibilidad", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 381 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "visibilidad", (yyvsp[(1) - (1)].TEXT)); }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 382 "parser.yy"
    { (yyval.nodito) = new NodoAST((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "visibilidad", (yyvsp[(1) - (1)].TEXT)); }
    break;


/* Line 1792 of yacc.c  */
#line 2997 "parser.cpp"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 385 "parser.yy"

