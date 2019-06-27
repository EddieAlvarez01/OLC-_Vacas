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
%token<TEXT> punto;
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
%token<TEXT> pcaso;
%token<TEXT> psalir;
%token<TEXT> pdefecto;
%token<TEXT> dos_puntos;
%token<TEXT> pcuenta;



/*No terimanesl*/
%type<nodito> INICIO;
%type<nodito> LCLASES;
%type<nodito> CLASE;
%type<nodito> TERMINACIONCLASE;
%type<nodito> RELLENOCLASE;
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
%type<nodito> LLAMADAFUNC;
%type<nodito> VARF;
%type<nodito> VISIBILIDAD;
%type<nodito> FUNCIONES;
%type<nodtio> SOBREESCRITURA;
%type<nodito> LTIPOS;
%type<nodito> RETORNAR;
%type<nodito> IMPRIMIR;
%type<nodito> MOSTRARNOTIFI;
%type<nodito> SI;
%type<nodito> TERMINSI;
%type<nodito> PARA;
%type<nodito> PRIMERFOR;
%type<nodito> REPETIR;
%type<nodito> ROMPER;
%type<nodtio> MIENTRAS;
%type<nodito> COMPROBAR;
%type<nodito> CASOS;
%type<nodito> HACER;
%type<nodito> CONTINUAR;
%type<nodito> INCLUIR;
%type<nodito> TRANSFERIR;


%left opor opnor
%left opand opnand
%right opnot
%left igual_igual diferente_de menor_que menorigual_que mayor_que mayorigual_que
%left suma menos
%left multi division
%nonassoc potencia

%start INICIO
%%

INICIO : LCLASES { raiz = $$; };

LCLASES : LCLASES CLASE { $$ = $1; $$->add(*$2); }
         |CLASE { $$ = new NodoAST(@1.first_line, @1.first_column, "lclases", "lclases"); $$->add(*$1); } ;

CLASE : pclase id TERMINACIONCLASE { NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $2); $3->add(*nodo); $$ = $3; };

TERMINACIONCLASE : pextender LIDS abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "clase", "clase"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "extender", "extender"); nodo->add(*$2); $$->add(*nodo); if($4 != NULL){ $$->add(*$4); } }
|abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "clase", "clase"); if($2 != NULL){ $$->add(*$2); } };

RELLENOCLASE : { $$ = NULL; }
             |LSENTENCIAS { $$ = NULL; };

LIDS : LIDS coma id { $$ = $1; NodoAST *nodo = new NodoAST(@2.first_line, @2.first_column, "id", $3); $$->add(*nodo); }
      |id { $$ = new NodoAST(@1.first_line, @1.first_column, "lids", "lids"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); } ;

LSENTENCIAS : LSENTENCIAS SENTENCIA
             |SENTENCIA;

SENTENCIA : DECLARACION
           |ASIGNACION
           |LLAMADAFUNC finalizacion
           |PRINCIPAL
           |RETORNAR
           |IMPRIMIR
           |MOSTRARNOTIFI
           |SI
           |PARA
           |REPETIR
           |ROMPER
           |MIENTRAS
           |COMPROBAR
           |HACER
           |CONTINUAR
           |INCLUIR
           |TRANSFERIR;

DECLARACION : VISIBILIDAD TIPO LIDS TERMDECLAR
             |SOBREESCRITURA VISIBILIDAD TIPO LIDS TERMDECLAR
             |TIPO LIDS TERMDECLAR
             |SOBREESCRITURA TIPO LIDS TERMDECLAR
             |VISIBILIDAD parreglo TIPO LIDS DIMENSION TERMARRAY
             |parreglo TIPO LIDS DIMENSION TERMARRAY;

ASIGNACION : id igual EXPL finalizacion
            |id DIMENSION igual EXPL finalizacion
            |id punto id igual EXPL finalizacion;

PRINCIPAL : pprincipal abrir_parentesis cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave;

FUNCIONES : abrir_parentesis LTIPOS cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave
           |abrir_parentesis cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave;

RETORNAR : pretornar EXPL finalizacion;

IMPRIMIR : pimprimir abrir_parentesis EXPL cerrar_parentesis finalizacion;

MOSTRARNOTIFI : pmostrarnotificacion abrir_parentesis EXPL coma EXPL cerrar_parentesis finalizacion;

SI : psi abrir_parentesis EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave TERMINSI;

PARA : ppara abrir_parentesis PRIMERFOR EXPL finalizacion EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave;

REPETIR : prepetir abrir_parentesis EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave;

ROMPER : promper finalizacion;

MIENTRAS : pmientras abrir_parentesis EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave;

COMPROBAR : pcomprobar abrir_parentesis EXPL cerrar_parentesis abrir_llave CASOS cerrar_llave;

CASOS : CASOS pcaso EXPL dos_puntos RELLENOCLASE psalir finalizacion
       |CASOS pdefecto dos_puntos RELLENOCLASE psalir finalizacion
       |pcaso EXPL dos_puntos RELLENOCLASE psalir finalizacion
       |pdefecto dos_puntos RELLENOCLASE psalir finalizacion;

HACER : phacer abrir_llave RELLENOCLASE cerrar_llave pmientras abrir_parentesis EXPL cerrar_parentesis finalizacion;

CONTINUAR : pcontinuar finalizacion;

INCLUIR : pincluir abrir_parentesis EXPL cerrar_parentesis finalizacion;

TRANSFERIR : ptransferir abrir_parentesis EXPL coma EXPL coma EXPL cerrar_parentesis finalizacion;

PRIMERFOR : DECLARACION
           |ASIGNACION;

TERMINSI : /* %empty */
          |psino abrir_llave RELLENOCLASE cerrar_llave
          |psino SI;


TIPO : pint
      |pdouble
      |pbool
      |pchar
      |pstring
      |id
      |pvoid
      |parchivo
      |pcuenta;

LTIPOS : LTIPOS coma TIPO id
        |LTIPOS coma TIPO id DIMENSION
        |TIPO id
        |TIPO id DIMENSION;


TERMDECLAR : finalizacion
            |FUNCIONES
            |igual EXPL finalizacion
            |igual pcrearcuenta abrir_parentesis EXPL coma EXPL cerrar_parentesis finalizacion
            |igual pcreararchivoder abrir_parentesis EXPL cerrar_parentesis finalizacion
            |igual pnew id abrir_parentesis cerrar_parentesis finalizacion;

DIMENSION : abrir_corchete EXPL cerrar_corchete
           |abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete
           |abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete;


TERMARRAY : finalizacion
           |igual LDECLARRAY finalizacion;

SOBREESCRITURA : psobrescribir;

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
      |abrir_parentesis EXPL cerrar_parentesis
      |numero
      |decimal
      |caracter
      |booleano
      |cadena
      |id
      |id DIMENSION
      |id aumento
      |id decremento
      |numero aumento
      |numero decremento
      |decimal aumento
      |decimal decremento
      |caracter aumento
      |caracter decremento
      |id punto id
      |LLAMADAFUNC;

LLAMADAFUNC : id punto id abrir_parentesis VARF cerrar_parentesis
             |id punto pcrearconjunto abrir_parentesis EXPL coma EXPL cerrar_parentesis
             |id punto pverificarcuenta abrir_parentesis cerrar_parentesis
             |id punto pdepositarcuenta abrir_parentesis EXPL cerrar_parentesis
             |id punto prestarcuenta abrir_parentesis EXPL cerrar_parentesis
             |id punto pimprimirtransaccionescuenta abrir_parentesis cerrar_parentesis
             |id punto pconsultarcuenta abrir_parentesis cerrar_parentesis
             |id punto pcrearregex abrir_parentesis EXPL coma EXPL cerrar_parentesis
             |id punto pcrearentrada abrir_parentesis EXPL coma EXPL cerrar_parentesis
             |id punto pguardararchivo abrir_parentesis cerrar_parentesis
             |id abrir_parentesis VARF cerrar_parentesis;

VARF : /*%empty*/
      |LEXP;

VISIBILIDAD : ppublico
            |pprivado
            |pprotegido;


%%
