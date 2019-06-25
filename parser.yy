%{
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
%}

%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{
char TEXT [256];
class NodoAST* nodito;
}

%token<TEXT> numero;
%token<TEXT> decimal;
%token<TEXT> caracter;
%token<TEXT> booleano;
%token<TEXT> cadena;
%token<TEXT> pint;
%token<TEXT> pdouble;
%token<TEXT> pbool;
%token<TEXT> pchar;
%token<TEXT> pstring;
%token<TEXT> parreglo;
%token<TEXT> pclase;
%token<TEXT> pextender;
%token<TEXT> psobrescribir;
%token<TEXT> ppublico;
%token<TEXT> pprivado;
%token<TEXT> pprotegido;
%token<TEXT> pretornar;
%token<TEXT> pvoid;
%token<TEXT> pmostrarnotificacion;
%token<TEXT> pimprimir;
%token<TEXT> psi;
%token<TEXT> psino;
%token<TEXT> ppara;
%token<TEXT> pprincipal;
%token<TEXT> prepetir;
%token<TEXT> promper;
%token<TEXT> pmientras;
%token<TEXT> pcomprobar;
%token<TEXT> phacer;
%token<TEXT> pcontinuar;
%token<TEXT> pincluir;
%token<TEXT> parchivo;
%token<TEXT> pcreararchivoder;
%token<TEXT> pcrearconjunto;
%token<TEXT> pcrearregex;
%token<TEXT> pcrearentrada;
%token<TEXT> pguardararchivo;
%token<TEXT> pcrearcuenta;
%token<TEXT> pverificarcuenta;
%token<TEXT> pdepositarcuenta;
%token<TEXT> prestarcuenta;
%token<TEXT> pimprimirtransaccionescuenta;
%token<TEXT> pconsultarcuenta;
%token<TEXT> ptransferir;
%token<TEXT> pnew;
%token<TEXT> id;
%token<TEXT> abrir_corchete;
%token<TEXT> cerrar_corchete;
%token<TEXT> coma;
%token<TEXT> finalizacion;
%token<TEXT> igual;
%token<TEXT> aumento;
%token<TEXT> decremento;
%token<TEXT> abrir_parentesis;
%token<TEXT> cerrar_parentesis;
%token<TEXT> abrir_llave;
%token<TEXT> cerrar_llave;
%token<TEXT> igual_igual;
%token<TEXT> diferente_de;
%token<TEXT> menor_que;
%token<TEXT> menorigual_que;
%token<TEXT> mayor_que;
%token<TEXT> mayorigual_que;
%token<TEXT> opor;
%token<TEXT> opand;
%token<TEXT> opnand;
%token<TEXT> opnot;
%token<TEXT> opnor;
%token<TEXT> suma;
%token<TEXT> resta;
%token<TEXT> multi;
%token<TEXT> division;
%token<TEXT> potencia;



/*No terimanesl*/
%type<nodito> INICIO;
%type<nodito> LCLASES;
%type<nodito> CLASE;
%type<nodito> LIDS;
%type<nodito> LSENTENCIAS;
%type<nodito> TERMDECLAR;
%type<nodito> SENTENCIA;
%type<nodito> DECLARACION;
%type<nodito> TIPO;
%type<nodito> EXPL;
%type<nodito> EXPR;
%type<nodito> EXPA;
%type<nodito> DIMENSION;
%type<nodito> TERMARRAY;
%type<nodito> LDECLARRAY;
%type<nodito> LLLAVE;
%type<nodito> ASIGNACION;
%type<nodito> AUMENTO;
%type<nodito> DECREMENTO;

%left opor opnor
%left opand opnand
%right opnot
%left igual_igual diferente_de menor_que menorigual_que mayor_que mayorigual_que
%left suma menos
%left multi division
%nonassoc potencia

%start INICIO
%%

INICIO : LCLASES;

LCLASES : LCLASES CLASE
          |CLASE;

CLASE : pclase id pextender LIDS abrir_llave cerrar_llave
       |pclase id pextender LIDS abrir_llave LSENTENCIAS cerrar_llave
       |pclase id abrir_llave cerrar_llave
       |pclase id abrir_llave LSENTENCIAS cerrar_llave;

LIDS : LIDS coma id
      |id;

LSENTENCIAS : LSENTENCIAS SENTENCIA
             |SENTENCIA;

SENTENCIA : DECLARACION
           |ASIGNACION
           |AUMENTO
           |DECREMENTO;

DECLARACION : TIPO LIDS TERMDECLAR
             |parreglo TIPO LIDS DIMENSION TERMARRAY;

ASIGNACION : id igual EXPL finalizacion
            |id DIMENSION igual EXPL finalizacion;

TIPO : pint
      |pdouble
      |pbool
      |pchar
      |pstring
      |id;

TERMDECLAR : finalizacion
            |igual EXPL finalizacion
            |igual pnew id abrir_parentesis cerrar_parentesis finalizacion;

DIMENSION : abrir_corchete EXPL cerrar_corchete
           |abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete
           |abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete;

AUMENTO : EXPL aumento finalizacion;

DECREMENTO : EXPL decremento finalizacion;

TERMARRAY : finalizacion
           |igual LDECLARRAY finalizacion;

LDECLARRAY : abrir_llave LEXP cerrar_llave
            |abrir_llave LLLAVE cerrar_llave;

LLLAVE : LLLAVE coma abrir_llave LEXP cerrar_llave
        |abrir_llave LEXP cerrar_llave;

LEXP : LEXP coma EXPL
      |EXPL;

EXPL :  EXPR opor EXPR
       |EXPR opnor EXPR
       |EXPR opand EXPR
       |EXPR opnand EXPR
       |opnot EXPL
       |EXPR;

EXPR : EXPA igual_igual EXPA
      |EXPA diferente_de EXPA
      |EXPA menor_que EXPA
      |EXPA mayor_que EXPA
      |EXPA menorigual_que EXPA
      |EXPA mayorigual_que EXPA
      |EXPA;

EXPA : EXPA suma EXPA
      |EXPA resta EXPA
      |EXPA multi EXPA
      |EXPA division EXPA
      |EXPA potencia EXPA
      |resta EXPA
      |abrir_parentesis EXPA cerrar_parentesis
      |numero
      |decimal
      |caracter
      |booleano
      |cadena
      |id
      |id DIMENSION;


%%
