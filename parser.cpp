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
#line 85 "parser.cpp"

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
     pcuenta = 337,
     menos = 338
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 23 "parser.yy"

char TEXT [256];
class NodoAST* nodito;


/* Line 387 of yacc.c  */
#line 217 "parser.cpp"
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
#line 258 "parser.cpp"

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
#define YYLAST   463

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNRULES -- Number of states.  */
#define YYNSTATES  380

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    20,    24,    25,
      27,    31,    33,    36,    38,    40,    42,    45,    47,    49,
      51,    53,    55,    57,    59,    61,    63,    65,    67,    69,
      71,    73,    78,    84,    88,    93,   100,   106,   111,   117,
     124,   131,   138,   144,   148,   154,   162,   171,   182,   190,
     193,   201,   209,   217,   224,   231,   237,   247,   250,   256,
     266,   268,   270,   271,   276,   279,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   302,   308,   311,   315,   317,
     319,   323,   332,   339,   346,   350,   357,   367,   369,   373,
     375,   379,   383,   389,   393,   397,   399,   403,   407,   411,
     415,   418,   420,   424,   428,   432,   436,   440,   444,   446,
     450,   454,   458,   462,   466,   469,   473,   475,   477,   479,
     481,   483,   485,   488,   491,   494,   497,   500,   503,   506,
     509,   512,   516,   518,   525,   534,   540,   547,   554,   560,
     566,   575,   584,   590,   595,   596,   598,   600,   602
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      85,     0,    -1,    86,    -1,    86,    87,    -1,    87,    -1,
      14,    49,    88,    -1,    15,    90,    60,    89,    61,    -1,
      60,    89,    61,    -1,    -1,    91,    -1,    90,    52,    49,
      -1,    49,    -1,    91,    92,    -1,    92,    -1,    93,    -1,
      94,    -1,   125,    54,    -1,    95,    -1,    97,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,
      -1,   104,    -1,   105,    -1,   107,    -1,   108,    -1,   109,
      -1,   110,    -1,   127,   113,    90,   115,    -1,   118,   127,
     113,    90,   115,    -1,   113,    90,   115,    -1,   118,   113,
      90,   115,    -1,   127,    13,   113,    90,   116,   117,    -1,
      13,   113,    90,   116,   117,    -1,    49,    55,   122,    54,
      -1,    49,   116,    55,   122,    54,    -1,    49,    53,    49,
      55,   122,    54,    -1,    27,    58,    59,    60,    89,    61,
      -1,    58,   114,    59,    60,    89,    61,    -1,    58,    59,
      60,    89,    61,    -1,    20,   122,    54,    -1,    23,    58,
     122,    59,    54,    -1,    22,    58,   122,    52,   122,    59,
      54,    -1,    24,    58,   122,    59,    60,    89,    61,   112,
      -1,    26,    58,   111,   122,    54,   122,    59,    60,    89,
      61,    -1,    28,    58,   122,    59,    60,    89,    61,    -1,
      29,    54,    -1,    30,    58,   122,    59,    60,    89,    61,
      -1,    31,    58,   122,    59,    60,   106,    61,    -1,   106,
      78,   122,    81,    89,    79,    54,    -1,   106,    80,    81,
      89,    79,    54,    -1,    78,   122,    81,    89,    79,    54,
      -1,    80,    81,    89,    79,    54,    -1,    32,    60,    89,
      61,    30,    58,   122,    59,    54,    -1,    33,    54,    -1,
      34,    58,   122,    59,    54,    -1,    47,    58,   122,    52,
     122,    52,   122,    59,    54,    -1,    93,    -1,    94,    -1,
      -1,    25,    60,    89,    61,    -1,    25,   100,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    49,
      -1,    21,    -1,    35,    -1,    82,    -1,   114,    52,   113,
      49,    -1,   114,    52,   113,    49,   116,    -1,   113,    49,
      -1,   113,    49,   116,    -1,    54,    -1,    96,    -1,    55,
     122,    54,    -1,    55,    41,    58,   122,    52,   122,    59,
      54,    -1,    55,    36,    58,   122,    59,    54,    -1,    55,
      48,    49,    58,    59,    54,    -1,    50,   122,    51,    -1,
      50,   122,    51,    50,   122,    51,    -1,    50,   122,    51,
      50,   122,    51,    50,   122,    51,    -1,    54,    -1,    55,
     119,    54,    -1,    16,    -1,    60,   121,    61,    -1,    60,
     120,    61,    -1,   120,    52,    60,   121,    61,    -1,    60,
     121,    61,    -1,   121,    52,   122,    -1,   122,    -1,   123,
      68,   123,    -1,   123,    72,   123,    -1,   123,    69,   123,
      -1,   123,    70,   123,    -1,    71,   122,    -1,   123,    -1,
     124,    62,   124,    -1,   124,    63,   124,    -1,   124,    64,
     124,    -1,   124,    66,   124,    -1,   124,    65,   124,    -1,
     124,    67,   124,    -1,   124,    -1,   124,    73,   124,    -1,
     124,    74,   124,    -1,   124,    75,   124,    -1,   124,    76,
     124,    -1,   124,    77,   124,    -1,    74,   124,    -1,    58,
     122,    59,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    49,    -1,    49,   116,    -1,    49,    56,
      -1,    49,    57,    -1,     3,    56,    -1,     3,    57,    -1,
       4,    56,    -1,     4,    57,    -1,     5,    56,    -1,     5,
      57,    -1,    49,    53,    49,    -1,   125,    -1,    49,    53,
      49,    58,   126,    59,    -1,    49,    53,    37,    58,   122,
      52,   122,    59,    -1,    49,    53,    42,    58,    59,    -1,
      49,    53,    43,    58,   122,    59,    -1,    49,    53,    44,
      58,   122,    59,    -1,    49,    53,    45,    58,    59,    -1,
      49,    53,    46,    58,    59,    -1,    49,    53,    38,    58,
     122,    52,   122,    59,    -1,    49,    53,    39,    58,   122,
      52,   122,    59,    -1,    49,    53,    40,    58,    59,    -1,
      49,    58,   126,    59,    -1,    -1,   121,    -1,    17,    -1,
      18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   168,   169,   171,   173,   174,   176,   177,
     179,   180,   182,   183,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   203,   204,   205,   206,   207,   208,   210,   211,   212,
     214,   216,   217,   219,   221,   223,   225,   227,   229,   231,
     233,   235,   237,   238,   239,   240,   242,   244,   246,   248,
     250,   251,   253,   254,   255,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   268,   269,   270,   271,   274,   275,
     276,   277,   278,   279,   281,   282,   283,   286,   287,   289,
     291,   292,   294,   295,   297,   298,   300,   301,   302,   303,
     304,   305,   307,   308,   309,   310,   311,   312,   313,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   352,   353,   355,   356,   357
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
  "menos", "$accept", "INICIO", "LCLASES", "CLASE", "TERMINACIONCLASE",
  "RELLENOCLASE", "LIDS", "LSENTENCIAS", "SENTENCIA", "DECLARACION",
  "ASIGNACION", "PRINCIPAL", "FUNCIONES", "RETORNAR", "IMPRIMIR",
  "MOSTRARNOTIFI", "SI", "PARA", "REPETIR", "ROMPER", "MIENTRAS",
  "COMPROBAR", "CASOS", "HACER", "CONTINUAR", "INCLUIR", "TRANSFERIR",
  "PRIMERFOR", "TERMINSI", "TIPO", "LTIPOS", "TERMDECLAR", "DIMENSION",
  "TERMARRAY", "SOBREESCRITURA", "LDECLARRAY", "LLLAVE", "LEXP", "EXPL",
  "EXPR", "EXPA", "LLAMADAFUNC", "VARF", "VISIBILIDAD", YY_NULL
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
     335,   336,   337,   338
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      95,    96,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   106,   106,   106,   107,   108,   109,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   117,   117,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   127,   127,   127
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     5,     3,     0,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     3,     4,     6,     5,     4,     5,     6,
       6,     6,     5,     3,     5,     7,     8,    10,     7,     2,
       7,     7,     7,     6,     6,     5,     9,     2,     5,     9,
       1,     1,     0,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     2,     3,     1,     1,
       3,     8,     6,     6,     3,     6,     9,     1,     3,     1,
       3,     3,     5,     3,     3,     1,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     1,     6,     8,     5,     6,     6,     5,     5,
       8,     8,     5,     4,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     0,     8,
       5,    11,     0,    65,    66,    67,    68,    69,     0,    89,
     146,   147,   148,     0,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    70,
      73,     0,     9,    13,    14,    15,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     8,    70,     0,   116,   117,
     118,   119,   120,   121,     0,     0,     0,     0,   101,   108,
     132,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       8,    57,     0,     0,     0,     0,     0,   144,     0,     7,
      12,     0,     0,     0,    16,     0,     0,    10,     0,     0,
     125,   126,   127,   128,   129,   130,     0,   123,   124,   122,
       0,   100,   114,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,    95,     0,     0,    78,
       0,     0,    79,    33,     0,     0,     0,     0,     6,     0,
     131,   115,    96,    98,    99,    97,   102,   103,   104,   106,
     105,   107,   109,   110,   111,   112,   113,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,    37,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,    31,    87,     0,    36,     0,
      44,     8,     0,     0,     0,     8,     8,     0,     0,    58,
       0,     0,     0,     0,     0,   142,   135,     0,     0,   138,
     139,     0,     0,    94,    38,     0,     0,     0,    80,     8,
      76,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,    39,   133,     0,     0,     0,     0,
      77,     0,     8,    35,     0,     0,     0,    88,    45,    62,
       0,    48,    50,     0,     8,    51,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,    42,    74,     0,
       0,     0,    91,    90,     0,    46,     8,     8,     0,     0,
       8,     0,     0,     0,   134,   140,   141,    82,     0,    83,
      75,    41,    93,     0,     8,    64,     0,     0,     0,     8,
       0,    56,    59,     0,     0,     0,     0,    47,     0,    55,
       0,     0,    86,    81,    92,    63,    54,     0,    53,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    41,    12,    42,    43,    44,
      45,    46,   172,    47,    48,    49,    50,    51,    52,    53,
      54,    55,   285,    56,    57,    58,    59,   145,   335,    60,
     231,   173,    98,   238,    61,   276,   305,   165,   166,    78,
      79,    80,   167,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -269
static const yytype_int16 yypact[] =
{
      17,    -6,    58,    17,  -269,    -1,  -269,  -269,    15,    81,
    -269,  -269,   -23,  -269,  -269,  -269,  -269,  -269,   290,  -269,
    -269,  -269,  -269,   349,  -269,     8,    12,    20,    22,    29,
      37,    52,    69,    73,    77,    90,    88,  -269,    94,    98,
    -269,    89,    81,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
      15,   124,   120,    14,   106,    81,  -269,    15,    61,    82,
     101,  -269,  -269,    26,   349,   349,   165,   121,    92,   326,
    -269,   349,   349,   349,   200,   118,   349,  -269,   349,   349,
      81,  -269,   349,   349,   349,   399,   349,   349,   123,  -269,
    -269,    71,    15,   290,  -269,   290,    15,  -269,   119,   -11,
    -269,  -269,  -269,  -269,  -269,  -269,   412,  -269,  -269,  -269,
     122,  -269,   151,  -269,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   130,
     126,   127,     2,  -269,  -269,   349,   128,   133,   137,   138,
     139,   140,   150,   153,   147,   157,   162,   171,   173,   175,
     176,   180,   183,   -39,   188,   191,  -269,   187,   349,  -269,
     310,   275,  -269,  -269,    71,    15,    15,    71,  -269,   111,
     189,  -269,  -269,  -269,  -269,  -269,   151,   151,   151,   151,
     151,   151,   181,   151,     0,     0,    45,   349,   194,   190,
     202,   199,    81,   203,   204,   207,   229,   217,   349,   222,
     349,   349,   349,   214,   218,   349,   349,   220,   221,   349,
     349,  -269,   349,  -269,   227,   236,   245,   257,   253,   216,
     259,   -14,  -269,    71,   -11,  -269,  -269,   249,  -269,   260,
    -269,    81,   263,   349,   251,    81,    81,   -30,   262,  -269,
     269,   349,   271,   274,   277,  -269,  -269,   273,   276,  -269,
    -269,   279,   278,  -269,  -269,   349,   349,   272,  -269,    81,
     286,   290,   287,  -269,   111,   337,   284,   294,   288,   301,
    -269,   300,   302,   349,   281,   -46,   349,   349,   313,   349,
     349,   349,  -269,  -269,  -269,  -269,   306,   314,   308,   309,
    -269,   320,    81,  -269,   349,   -44,   -43,  -269,  -269,   346,
     315,  -269,  -269,   293,    81,  -269,   349,   295,   318,   319,
     329,   321,   323,   324,   331,   349,   333,  -269,   286,   335,
     -41,   334,  -269,  -269,   -20,  -269,    81,    81,   325,   328,
      81,   351,   352,   349,  -269,  -269,  -269,  -269,   353,  -269,
    -269,  -269,  -269,   349,    81,  -269,   354,   338,   356,    81,
     339,  -269,  -269,   362,   360,   -31,   355,  -269,   365,  -269,
     342,   368,  -269,  -269,  -269,  -269,  -269,   370,  -269,  -269
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -269,  -269,  -269,   437,  -269,   -62,   -55,  -269,   404,   363,
     369,  -269,  -269,  -269,  -269,  -269,   125,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,   -17,
    -269,  -164,   -67,   186,  -269,  -269,  -269,  -268,   -21,   164,
     297,    -9,   242,   402
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      62,    67,    77,   108,    27,   101,   119,   306,   331,   222,
     232,   222,   109,   235,     8,   315,   219,   332,   333,   220,
     352,   222,    13,    14,    15,    16,    17,   105,   150,    64,
     374,     1,   316,    62,   317,    24,   330,    65,   271,    94,
     354,    64,   179,     5,   102,   272,   106,   174,   283,    37,
     284,   177,    94,   120,   121,   200,    62,    96,     6,     9,
     139,   140,   141,    66,    11,   147,    81,   148,   149,   273,
      82,   151,   152,   153,   135,   164,    94,   138,    83,   116,
      84,    62,   117,   118,    97,   365,   175,    85,   176,    13,
      14,    15,    16,    17,    18,    86,    40,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    87,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,   110,   111,   135,
     233,   234,    -1,    64,   201,   169,   170,    88,    38,   171,
      39,    89,    13,    14,    15,    16,    17,    90,   112,   113,
     244,    20,    21,    22,    91,    24,    92,   224,    94,   228,
      99,    95,    93,    96,   230,   107,    97,   114,   115,    37,
     124,   125,   126,    40,   127,   236,   237,   274,    68,    69,
      70,    71,    72,    66,   104,   123,   239,   146,   168,   278,
     178,   181,   197,   281,   282,   198,   199,   250,   202,   252,
     253,   254,   203,    62,   257,   258,   204,   205,   261,   207,
     206,   263,   208,   300,   209,   210,    40,   299,    13,    14,
      15,    16,    17,    18,    73,   211,    19,    20,    21,    22,
     212,    24,   279,    74,   134,   135,   136,   137,   138,   213,
     288,   214,    62,   215,   216,    37,    62,    62,   217,    76,
     329,   218,   221,   222,   296,   297,   223,   220,   240,   142,
     241,   242,   338,   243,   301,   135,   136,   137,   138,   248,
      62,   350,   313,   245,   246,   318,   319,   247,   321,   322,
     323,   249,   251,   255,   356,   357,   269,   256,   360,   259,
     260,   264,    40,    13,    14,    15,    16,    17,   182,   183,
     184,   185,   366,    62,   265,   339,    24,   370,    13,    14,
      15,    16,    17,   266,   348,    62,   267,   268,   270,   275,
      37,    24,   280,    68,    69,    70,    71,    72,   219,   277,
     286,   287,   363,   289,    66,    37,   290,    62,    62,   291,
     298,    62,   292,   294,   229,   293,    94,   295,   307,    66,
      68,    69,    70,    71,    72,    62,   225,   302,   308,   309,
      62,   226,    68,    69,    70,    71,    72,    40,   227,    73,
     310,   311,   314,   312,   320,   324,   325,   326,    74,   328,
     327,   334,    40,   122,   337,   336,   340,   341,   342,   343,
     344,    75,   345,   346,    76,   347,    73,   349,   128,   129,
     130,   131,   132,   133,   353,    74,   351,   304,    73,   134,
     135,   136,   137,   138,   358,   361,   362,    74,    75,   359,
     369,    76,   364,   372,   373,   367,   375,   368,   371,   376,
      75,   377,   378,    76,   379,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   154,   155,   156,   157,
       7,   158,   159,   160,   161,   162,   100,   143,   163,   154,
     155,   156,   157,   144,   158,   159,   160,   161,   162,   355,
     303,   180,   262,   103
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-269)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_uint16 yycheck[] =
{
       9,    18,    23,    65,    24,    60,    73,   275,    52,    52,
     174,    52,    67,   177,    15,    61,    55,    61,    61,    58,
      61,    52,     8,     9,    10,    11,    12,    13,    90,    52,
      61,    14,    78,    42,    80,    21,   304,    60,    52,    50,
      60,    52,   109,    49,    61,    59,    63,   102,    78,    35,
      80,   106,    50,    74,    75,    53,    65,    55,     0,    60,
      81,    82,    83,    49,    49,    86,    58,    88,    89,   233,
      58,    92,    93,    94,    74,    96,    50,    77,    58,    53,
      58,    90,    56,    57,    58,   353,   103,    58,   105,     8,
       9,    10,    11,    12,    13,    58,    82,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    54,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    56,    57,    74,
     175,   176,    77,    52,   145,    54,    55,    58,    47,    58,
      49,    58,     8,     9,    10,    11,    12,    60,    56,    57,
     202,    17,    18,    19,    54,    21,    58,   168,    50,   170,
      61,    53,    58,    55,   171,    49,    58,    56,    57,    35,
      68,    69,    70,    82,    72,    54,    55,   234,     3,     4,
       5,     6,     7,    49,    54,    54,   197,    59,    55,   241,
      61,    59,    52,   245,   246,    59,    59,   208,    60,   210,
     211,   212,    59,   202,   215,   216,    59,    59,   219,    59,
      61,   222,    52,   270,    51,    58,    82,   269,     8,     9,
      10,    11,    12,    13,    49,    58,    16,    17,    18,    19,
      58,    21,   243,    58,    73,    74,    75,    76,    77,    58,
     251,    58,   241,    58,    58,    35,   245,   246,    58,    74,
     302,    58,    54,    52,   265,   266,    59,    58,    54,    49,
      60,    49,   314,    54,   271,    74,    75,    76,    77,    30,
     269,   328,   283,    60,    60,   286,   287,    60,   289,   290,
     291,    54,    50,    59,   336,   337,    60,    59,   340,    59,
      59,    54,    82,     8,     9,    10,    11,    12,   124,   125,
     126,   127,   354,   302,    58,   316,    21,   359,     8,     9,
      10,    11,    12,    58,   325,   314,    49,    54,    49,    60,
      35,    21,    61,     3,     4,     5,     6,     7,    55,    59,
      58,    52,   343,    52,    49,    35,    52,   336,   337,    52,
      58,   340,    59,    54,    59,    59,    50,    59,    54,    49,
       3,     4,     5,     6,     7,   354,    36,    60,    54,    61,
     359,    41,     3,     4,     5,     6,     7,    82,    48,    49,
      59,    61,    81,    61,    51,    59,    52,    59,    58,    49,
      61,    25,    82,    76,    81,    60,    81,    59,    59,    50,
      59,    71,    59,    59,    74,    54,    49,    54,    62,    63,
      64,    65,    66,    67,    60,    58,    61,    60,    49,    73,
      74,    75,    76,    77,    79,    54,    54,    58,    71,    81,
      54,    74,    59,    51,    54,    61,    61,    79,    79,    54,
      71,    79,    54,    74,    54,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    37,    38,    39,    40,
       3,    42,    43,    44,    45,    46,    42,    84,    49,    37,
      38,    39,    40,    84,    42,    43,    44,    45,    46,   334,
     274,    49,   220,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    85,    86,    87,    49,     0,    87,    15,    60,
      88,    49,    90,     8,     9,    10,    11,    12,    13,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    47,    49,
      82,    89,    91,    92,    93,    94,    95,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   107,   108,   109,   110,
     113,   118,   125,   127,    52,    60,    49,   113,     3,     4,
       5,     6,     7,    49,    58,    71,    74,   122,   123,   124,
     125,    58,    58,    58,    58,    58,    58,    54,    58,    58,
      60,    54,    58,    58,    50,    53,    55,    58,   116,    61,
      92,    90,   113,   127,    54,    13,   113,    49,    89,    90,
      56,    57,    56,    57,    56,    57,    53,    56,    57,   116,
     122,   122,   124,    54,    68,    69,    70,    72,    62,    63,
      64,    65,    66,    67,    73,    74,    75,    76,    77,   122,
     122,   122,    49,    93,    94,   111,    59,   122,   122,   122,
      89,   122,   122,   122,    37,    38,    39,    40,    42,    43,
      44,    45,    46,    49,   122,   121,   122,   126,    55,    54,
      55,    58,    96,   115,    90,   113,   113,    90,    61,   116,
      49,    59,   123,   123,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,    52,    59,    59,
      53,   122,    60,    59,    59,    59,    61,    59,    52,    51,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    55,
      58,    54,    52,    59,   122,    36,    41,    48,   122,    59,
     113,   114,   115,    90,    90,   115,    54,    55,   117,   122,
      54,    60,    49,    54,    89,    60,    60,    60,    30,    54,
     122,    50,   122,   122,   122,    59,    59,   122,   122,    59,
      59,   122,   126,   122,    54,    58,    58,    49,    54,    60,
      49,    52,    59,   115,   116,    60,   119,    59,    89,   122,
      61,    89,    89,    78,    80,   106,    58,    52,   122,    52,
      52,    52,    59,    59,    54,    59,   122,   122,    58,    89,
     116,   113,    60,   117,    60,   120,   121,    54,    54,    61,
      59,    61,    61,   122,    81,    61,    78,    80,   122,   122,
      51,   122,   122,   122,    59,    52,    59,    61,    49,    89,
     121,    52,    61,    61,    25,   112,    60,    81,    89,   122,
      81,    59,    59,    50,    59,    59,    59,    54,   122,    54,
     116,    61,    61,    60,    60,   100,    89,    89,    79,    81,
      89,    54,    54,   122,    59,   121,    89,    61,    79,    54,
      89,    79,    51,    54,    61,    61,    54,    79,    54,    54
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
      
/* Line 1792 of yacc.c  */
#line 1915 "parser.cpp"
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
#line 360 "parser.yy"

