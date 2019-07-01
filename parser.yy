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
%type<nodito> MIENTRAS;
%type<nodito> COMPROBAR;
%type<nodito> CASOS;
%type<nodito> HACER;
%type<nodito> CONTINUAR;
%type<nodito> INCLUIR;
%type<nodito> TRANSFERIR;
%type<nodito> LEXP;
%type<nodito> PRINCIPAL;


%left opor opnor
%left opand opnand
%right opnot
%left igual_igual diferente_de menor_que menorigual_que mayor_que mayorigual_que
%left suma resta
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
             |LSENTENCIAS { $$ = $1; };

LIDS : LIDS coma id { $$ = $1; NodoAST *nodo = new NodoAST(@2.first_line, @2.first_column, "id", $3); $$->add(*nodo); }
      |id { $$ = new NodoAST(@1.first_line, @1.first_column, "lids", "lids"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); } ;

LSENTENCIAS : LSENTENCIAS SENTENCIA { $$ = $1; if($2 != NULL){ $$->add(*$2); } }
|SENTENCIA { $$ = new NodoAST(@1.first_line, @1.first_column, "lsentencias", "lsentencias"); if($1 != NULL){ $$->add(*$1); } };

SENTENCIA : DECLARACION { $$ = $1; }
           |ASIGNACION { $$ = $1; }
           |LLAMADAFUNC finalizacion { $$ = $1; }
           |PRINCIPAL { $$ = $1; }
           |RETORNAR { $$ = $1; }
           |IMPRIMIR { $$ = $1; }
           |MOSTRARNOTIFI { $$ = $1; }
           |SI { $$ = $1; }
           |PARA { $$ = $1; }
           |REPETIR { $$ = $1; }
           |ROMPER { $$ = $1; }
           |MIENTRAS { $$ = $1; }
           |COMPROBAR { $$ = $1; }
           |HACER { $$ = $1; }
           |CONTINUAR { $$ = $1; }
           |INCLUIR { $$ = $1; }
           |TRANSFERIR { $$ = $1; };

DECLARACION : VISIBILIDAD TIPO LIDS TERMDECLAR { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$1); $$->add(*$2); $$->add(*$3); if($4 != NULL){ $$->add(*$4); } }
             |SOBREESCRITURA VISIBILIDAD TIPO LIDS TERMDECLAR { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$2); $$->add(*$3); $$->add(*$4); if($5 != NULL){ $$->add(*$5); } }
             |TIPO LIDS TERMDECLAR { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$1); $$->add(*$2); if($3 != NULL){ $$->add(*$3); } }
             |SOBREESCRITURA TIPO LIDS TERMDECLAR { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$2); $$->add(*$3); if($4 != NULL){ $$->add(*$4); } }
             |VISIBILIDAD parreglo TIPO LIDS DIMENSION TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$1); $$->add(*$3); $$->add(*$4); $$->add(*$5); if($6 != NULL){ $$->add(*$6); } }
             |VISIBILIDAD parreglo TIPO DIMENSION LIDS TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$1); $$->add(*$3); $$->add(*$4); $$->add(*$5); if($6 != NULL){ $$->add(*$6); } }
             |SOBREESCRITURA VISIBILIDAD parreglo TIPO LIDS DIMENSION TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$2); $$->add(*$4); $$->add(*$5); $$->add(*$6); if($7 != NULL){ $$->add(*$7); } }
             |SOBREESCRITURA VISIBILIDAD parreglo TIPO DIMENSION LIDS TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$2); $$->add(*$4); $$->add(*$5); $$->add(*$6); if($7 != NULL){ $$->add(*$7); } }
             |parreglo TIPO LIDS DIMENSION TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$2); $$->add(*$3); $$->add(*$4); if($5 != NULL){ $$->add(*$5); } }
             |parreglo TIPO DIMENSION LIDS TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$2); $$->add(*$3); $$->add(*$4); if($5 != NULL){ $$->add(*$5); } }
             |SOBREESCRITURA parreglo TIPO LIDS DIMENSION TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$3); $$->add(*$4); $$->add(*$5); if($6 != NULL){ $$->add(*$6); } }
             |SOBREESCRITURA parreglo TIPO DIMENSION LIDS TERMARRAY { $$ = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); $$->add(*$3); $$->add(*$4); $$->add(*$5); if($6 != NULL){ $$->add(*$6); } };;

ASIGNACION : id igual EXPL finalizacion { $$ = new NodoAST(@1.first_line, @1.first_line, "asignacion", "asignacion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); $$->add(*$3); }
            |id DIMENSION igual EXPL finalizacion { $$ = new NodoAST(@1.first_line, @1.first_line, "asignacion", "asignacion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); $$->add(*$2); $$->add(*$4); }
            |id punto id igual EXPL finalizacion { $$ = new NodoAST(@1.first_line, @1.first_line, "asignacion", "asignacion"); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "objeto_var", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo3 = new NodoAST(@1.first_line, @1.first_column, "id", $3); nodo2->add(*nodo); nodo2->add(*nodo3); $$->add(*nodo2); $$->add(*$5); };

PRINCIPAL : pprincipal abrir_parentesis cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "main", "main"); if($5 != NULL){ $$->add(*$5); } };

FUNCIONES : abrir_parentesis LTIPOS cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "funciones", "funciones"); $$->add(*$2); if($5 != NULL){ $$->add(*$5); } }
            |abrir_parentesis cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "funciones", "funciones"); if($4 != NULL){ $$->add(*$4); } };

RETORNAR : pretornar EXPL finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "retornar", "retornar"); $$->add(*$2); };

IMPRIMIR : pimprimir abrir_parentesis EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "imprimir", "imprimir"); $$->add(*$3); };

MOSTRARNOTIFI : pmostrarnotificacion abrir_parentesis EXPL coma EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "mostrarNotificacion", "mostrarNotificacion"); $$->add(*$3); $$->add(*$5); };

SI : psi abrir_parentesis EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave TERMINSI { $$ = new NodoAST(@1.first_line, @1.first_column, "si", "si"); $$->add(*$3); if($6 != NULL){ $$->add(*$6); } if($8 != NULL){ $$->add(*$8); } };

PARA : ppara abrir_parentesis PRIMERFOR EXPL finalizacion EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "para", "para"); $$->add(*$3); $$->add(*$4); $$->add(*$6); if($9 != NULL){ $$->add(*$9); } };

REPETIR : prepetir abrir_parentesis EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "repetir", "repetir"); $$->add(*$3); if($6 != NULL){ $$->add(*$6); } };

ROMPER : promper finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "romper", "romper"); };

MIENTRAS : pmientras abrir_parentesis EXPL cerrar_parentesis abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "mientras", "mientras"); $$->add(*$3); if($6 != NULL){ $$->add(*$6); } };

COMPROBAR : pcomprobar abrir_parentesis EXPL cerrar_parentesis abrir_llave CASOS cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "comprobar", "comprobar"); $$->add(*$3); $$->add(*$6); };

CASOS : CASOS pcaso EXPL dos_puntos RELLENOCLASE psalir finalizacion { $$ = $1; NodoAST *nodo = new NodoAST(@1.first_line, @1.first_line, "caso", "caso"); nodo->add(*$3); if($5 != NULL){ nodo->add(*$5); } $$->add(*nodo); }
       |CASOS pdefecto dos_puntos RELLENOCLASE psalir finalizacion { $$ = $1; NodoAST *nodo = new NodoAST(@1.first_line, @1.first_line, "defecto", "defecto"); if($4 != NULL){ nodo->add(*$4); }  $$->add(*nodo); }
       |pcaso EXPL dos_puntos RELLENOCLASE psalir finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "casos", "casos"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_line, "caso", "caso"); nodo->add(*$2); if($4 != NULL){ nodo->add(*$4); } $$->add(*nodo); }
       |pdefecto dos_puntos RELLENOCLASE psalir finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "casos", "casos"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_line, "defecto", "defecto");  if($3 != NULL){ nodo->add(*$3); } $$->add(*nodo); };

HACER : phacer abrir_llave RELLENOCLASE cerrar_llave pmientras abrir_parentesis EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "hacer", "hacer"); if($3 != NULL){ $$->add(*$3); } $$->add(*$7); };

CONTINUAR : pcontinuar finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "continuar", "continuar"); };

INCLUIR : pincluir abrir_parentesis EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "incluir", "incluir"); $$->add(*$3); };

TRANSFERIR : ptransferir abrir_parentesis EXPL coma EXPL coma EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "transferir", "transferir"); $$->add(*$3); $$->add(*$5); $$->add(*$7); };

PRIMERFOR : DECLARACION { $$ = $1; }
            |ASIGNACION { $$ = $1; };

TERMINSI : /* %empty */ { $$ = NULL; }
          |psino abrir_llave RELLENOCLASE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_line, "else", "else"); if($3 != NULL){ $$->add(*$3); } }
          |psino SI { $$ = new NodoAST(@1.first_line, @1.first_column, "else", "else"); $$->add(*$2); };


TIPO : pint { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |pdouble { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |pbool { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |pchar { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |pstring { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |id { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |pvoid { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |parchivo { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); }
      |pcuenta { $$ = new NodoAST(@1.first_line, @1.first_column, "tipo", $1); };

LTIPOS : LTIPOS coma TIPO id { $$ = $1; $$->add(*$3); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $4); $$->add(*nodo); }
        |LTIPOS coma TIPO DIMENSION id { $$ = $1; $$->add(*$3); $$->add(*$4); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $5); $$->add(*nodo); }
        |TIPO id { $$ = new NodoAST(@1.first_line, @1.first_column, "ltipos", "ltipos"); $$->add(*$1); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $2); $$->add(*nodo); }
        |TIPO DIMENSION id { $$ = new NodoAST(@1.first_line, @1.first_column, "ltipos", "ltipos"); $$->add(*$1); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*$2); $$->add(*nodo); };


TERMDECLAR : finalizacion { $$ = NULL; }
            |FUNCIONES { $$ = $1; }
            |igual EXPL finalizacion { $$ = $2; }
            |igual pcrearcuenta abrir_parentesis EXPL coma EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $2); $$->add(*nodo); $$->add(*$4); $$->add(*$6); }
            |igual pcreararchivoder abrir_parentesis EXPL cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $2); $$->add(*nodo); $$->add(*$4); }
            |igual pnew id abrir_parentesis cerrar_parentesis finalizacion { $$ = new NodoAST(@1.first_line, @1.first_column, "objeto", "objeto"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); };

DIMENSION : abrir_corchete EXPL cerrar_corchete { $$ = new NodoAST(@1.first_line, @1.first_column, "dimension", "dimension"); $$->add(*$2); }
           |abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete { $$ = new NodoAST(@1.first_line, @1.first_column, "dimension", "dimension"); $$->add(*$2); $$->add(*$5); }
           |abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete abrir_corchete EXPL cerrar_corchete{ $$ = new NodoAST(@1.first_line, @1.first_column, "dimension", "dimension"); $$->add(*$2); $$->add(*$5); $$->add(*$8); } ;


TERMARRAY : finalizacion { $$ = NULL; }
           |FUNCIONES { $$ = $1; }
           |igual LDECLARRAY finalizacion { $$ = $2; };

SOBREESCRITURA : psobrescribir;

LDECLARRAY : abrir_llave LEXP cerrar_llave { $$ = $2; }
            |abrir_llave LLLAVE cerrar_llave { $$ = $2; };

LLLAVE : LLLAVE coma abrir_llave LEXP cerrar_llave { $$ = $1; $$->add(*$4); }
        |LLLAVE coma abrir_llave LLLAVE cerrar_llave { $$ = $1; $$->add(*$4); }
        |abrir_llave LLLAVE cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "ldimensionesasig", "ldimensionesasig"); $$->add(*$2); }
        |abrir_llave LEXP cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "ldimensionesasig", "ldimensionesasig"); $$->add(*$2); };

LEXP : LEXP coma EXPL { $$ = $1; $$->add(*$3); }
      |EXPL { $$ = new NodoAST(@1.first_line, @1.first_column, "lexp", "lexp"); $$->add(*$1); };

EXPL :  EXPR opor EXPR { $$ = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "or", $2); nodo->add(*$1); nodo->add(*$3); $$->add(*nodo); }
       |EXPR opnor EXPR { $$ = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "nor", $2); nodo->add(*$1); nodo->add(*$3); $$->add(*nodo); }
       |EXPR opand EXPR { $$ = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "and", $2); nodo->add(*$1); nodo->add(*$3); $$->add(*nodo); }
       |EXPR opnand EXPR { $$ = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "nand", $2); nodo->add(*$1); nodo->add(*$3); $$->add(*nodo); }
       |opnot EXPL { $$ = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "not", $1); nodo->add(*$2); $$->add(*nodo); }
       |EXPR { $$ = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); $$->add(*$1); };

EXPR : EXPA igual_igual EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "igual_igual", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA diferente_de EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "diferente_de", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA menor_que EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "menor_que", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA mayor_que EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "mayor_que", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA menorigual_que EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "menorigual_que", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA mayorigual_que EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "mayorigual_que", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA { $$ = $1; };

EXPA : EXPA suma EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "suma", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA resta EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "resta", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA multi EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "multi", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA division EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "division", $2); $$->add(*$1); $$->add(*$3); }
      |EXPA potencia EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, "potencia", $2); $$->add(*$1); $$->add(*$3); }
      |resta EXPA { $$ = new NodoAST(@1.first_line, @1.first_column, $1, $1); $$->add(*$2); }
      |abrir_parentesis EXPL cerrar_parentesis { $$ = $2; }
      |numero { $$ = new NodoAST(@1.first_line, @1.first_column, "numero", $1); }
      |decimal { $$ = new NodoAST(@1.first_line, @1.first_column, "decimal", $1); }
      |caracter { $$ = new NodoAST(@1.first_line, @1.first_column, "caracter", $1); }
      |booleano { $$ = new NodoAST(@1.first_line, @1.first_column, "boolean", $1); }
      |cadena { $$ = new NodoAST(@1.first_line, @1.first_column, "cadena", $1); }
      |id { $$ = new NodoAST(@1.first_line, @1.first_column, "id", $1); }
      |id DIMENSION { $$ = new NodoAST(@1.first_line, @1.first_column, "arreglo", $1); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); $$->add(*$2); }
      |id aumento { $$ = new NodoAST(@1.first_line, @1.first_column, "aumento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); }
      |id decremento { $$ = new NodoAST(@1.first_line, @1.first_column, "decremento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); $$->add(*nodo); }
      |numero aumento { $$ = new NodoAST(@1.first_line, @1.first_column, "aumento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "numero", $1); $$->add(*nodo); }
      |numero decremento { $$ = new NodoAST(@1.first_line, @1.first_column, "decremento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "numero", $1); $$->add(*nodo); }
      |decimal aumento { $$ = new NodoAST(@1.first_line, @1.first_column, "aumento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "decimal", $1); $$->add(*nodo); }
      |decimal decremento { $$ = new NodoAST(@1.first_line, @1.first_column, "decremento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "decimal", $1); $$->add(*nodo); }
      |caracter aumento { $$ = new NodoAST(@1.first_line, @1.first_column, "aumento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "caracter", $1); $$->add(*nodo); }
      |caracter decremento { $$ = new NodoAST(@1.first_line, @1.first_column, "decremento", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "caracter", $1); $$->add(*nodo); }
      |id punto id { $$ = new NodoAST(@1.first_line, @1.first_column, "objeto_var", $2); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); }
      |LLAMADAFUNC { $$ = $1; };

LLAMADAFUNC : id punto id abrir_parentesis VARF cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); if($5 != NULL){ $$->add(*$5); } }
             |id punto pcrearconjunto abrir_parentesis EXPL coma EXPL cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); $$->add(*$5); $$->add(*$7); }
             |id punto pverificarcuenta abrir_parentesis cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); }
             |id punto pdepositarcuenta abrir_parentesis EXPL cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); $$->add(*$5); }
             |id punto prestarcuenta abrir_parentesis EXPL cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); $$->add(*$5); }
             |id punto pimprimirtransaccionescuenta abrir_parentesis cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); }
             |id punto pconsultarcuenta abrir_parentesis cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); }
             |id punto pcrearregex abrir_parentesis EXPL coma EXPL cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); $$->add(*$5); $$->add(*$7); }
             |id punto pcrearentrada abrir_parentesis EXPL coma EXPL cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); $$->add(*$5); $$->add(*$7); }
             |id punto pguardararchivo abrir_parentesis cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1); NodoAST *nodo2 = new NodoAST(@1.first_line, @1.first_column, "id", $3); $$->add(*nodo); $$->add(*nodo2); }
             |id abrir_parentesis VARF cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "llamadafunc", "llamadafunc"); NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column, "id", $1);  $$->add(*nodo); if($3 != NULL){ $$->add(*$3); } };

VARF : /*%empty*/ { $$ = NULL; }
      |LEXP { $$ = $1; };

VISIBILIDAD : ppublico { $$ = new NodoAST(@1.first_line, @1.first_column, "visibilidad", $1); }
            |pprivado { $$ = new NodoAST(@1.first_line, @1.first_column, "visibilidad", $1); }
            |pprotegido { $$ = new NodoAST(@1.first_line, @1.first_column, "visibilidad", $1); };


%%
