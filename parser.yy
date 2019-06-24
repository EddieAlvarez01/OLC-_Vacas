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
%token<TEXT> id;
%token<TEXT> abrir_corchete;
%token<TEXT> cerrar_corchete;
%token<TEXT> coma;
%token<TEXT> punto_coma;
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
%type<nodito> ARGUMENTS;
%type<nodito> LIST;
%type<nodito> DECLARACION;
%type<nodito> TIPO;
%type<nodito> TERM;
%type<nodito> EX;
%type<nodito> REL;
%type<nodito> ARIT;
%type<nodito> ID;
%type<nodito> DIMENSIONS;
%type<nodito> ARRT;
%type<nodito> VAL;
%type<nodito> EXPR;
%type<nodito> LISTEX;
%type<nodito> SHOW;
%type<nodito> IMPRIMIR;
%type<nodito> SI;
%type<nodito> PARA;
%type<nodito> REPETIR;
%type<nodito> COUT;
%type<nodito> COUT2;

%left opor
%left opand
%right opnot
%left igual_igual diferente_de menor_que menorigual_que mayor_que mayorigual_que
%left suma menos
%left multi division
%left potencia

%start INICIO
%%

INICIO : ppublic pprincipal abrir_parentesis cerrar_parentesis abrir_llave ARGUMENTS cerrar_llave { $$ = new NodoAST(@1.first_line, @1.first_column, "principal", "principal"); $$->add(*$6); raiz = $$; };

ARGUMENTS : ARGUMENTS LIST { NodoAST* newNode = new NodoAST(); newNode = $1; newNode->add(*$2); $$ = newNode; }
            |LIST { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "argumento", "argumentos"); newNode->add(*$1); $$ = newNode;};

LIST : DECLARACION { $$ = $1; }
       |SHOW { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "show", "show"); newNode->add(*$1); $$ = newNode; }
       |IMPRIMIR { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "imprimir", "imprimir"); newNode->add(*$1); $$ = newNode; }
       |SI { $$ = $1; }
       |PARA { $$ = $1; }
       |REPETIR { $$ = $1; }
       |COUT { $$ = $1; };

DECLARACION : TIPO ID TERM { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion");  newNode->add(*$1); newNode->add(*$2); if($3 != NULL){ newNode->add(*$3); } $$ = newNode; }
             |TIPO parreglo ID DIMENSIONS ARRT { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion");  newNode->add(*$1); newNode->add(*$3); newNode->add(*$4); if($5 != NULL){ newNode->add(*$5); } $$ = newNode; }
             |ID igual EX punto_coma { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion");  newNode->add(*$1); novo->add(*$3); newNode->add(*novo); $$ = newNode; }
             |ID DIMENSIONS igual EX punto_coma { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "declaracion", "declaracion"); NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion");  newNode->add(*$1); newNode->add(*$2); novo->add(*$4); newNode->add(*novo); $$ = newNode; };

TIPO : pint { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "tipo", "tipo"); NodoAST* node = new NodoAST(@1.first_line, @1.first_column, "int", $1); newNode->add(*node); $$ = newNode; }
      |pstring { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "tipo", "tipo"); NodoAST* node = new NodoAST(@1.first_line, @1.first_column, "string", $1); newNode->add(*node); $$ = newNode; }
      |pdouble { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "tipo", "tipo"); NodoAST* node = new NodoAST(@1.first_line, @1.first_column, "decimal", $1); newNode->add(*node); $$ = newNode; }
      |pchar { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "tipo", "tipo"); NodoAST* node = new NodoAST(@1.first_line, @1.first_column, "caracter", $1); newNode->add(*node); $$ = newNode; }
      |pbool { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "tipo", "tipo"); NodoAST* node = new NodoAST(@1.first_line, @1.first_column, "bool", $1); newNode->add(*node); $$ = newNode; };

TERM : punto_coma { $$ = NULL; }
      |igual EX punto_coma { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); novo->add(*$2); $$ = novo; };

EX : EX opor REL { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "or", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
    |EX opand REL { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "and", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
    |opnot REL { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "not", $1); novo->add(*$2); $$ = novo; }
    |REL { $$ = $1; };

REL : REL menor_que ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "menor_que", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
     |REL mayor_que ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "mayor_que", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
     |REL mayorigual_que ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "mayor_igual", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
     |REL menorigual_que ARIT {  NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "menor_igual", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
     |REL igual_igual ARIT {  NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "igual", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
     |REL diferente_de ARIT {  NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "diferente_de", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
     |ARIT { $$ = $1; };

ARIT : ARIT suma ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "suma", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
      |ARIT resta ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "resta", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
      |ARIT multi ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "multiplicacion", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
      |ARIT division ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "division", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
      |ARIT potencia ARIT { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "potencia", $2); novo->add(*$1); novo->add(*$3); $$ = novo; }
      |numero { $$ = new NodoAST(@1.first_line, @1.first_column, "int", $1); }
      |caracter { $$ = new NodoAST(@1.first_line, @1.first_column, "caracter", $1); }
      |decimal { $$ = new NodoAST(@1.first_line, @1.first_column, "decimal", $1); }
      |booleano { $$ = new NodoAST(@1.first_line, @1.first_column, "bool", $1); }
      |cadena { $$ = new NodoAST(@1.first_line, @1.first_column, "string", $1); }
      |abrir_parentesis ARIT cerrar_parentesis { $$ = $2; }
      |abrir_parentesis resta numero cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "int", strcat($2, $3)); }
      |abrir_parentesis resta decimal cerrar_parentesis { $$ = new NodoAST(@1.first_line, @1.first_column, "decimal", strcat($2, $3)); }
      |id { $$ = new NodoAST(@1.first_line, @1.first_column, "variable", $1); }
      |id abrir_corchete ARIT cerrar_corchete { $$ = new NodoAST(@1.first_line, @1.first_column, "arreglo", $1); };

ID : ID coma id { NodoAST* idnode = new NodoAST(@1.first_line, @1.first_column, "id", $3); $1->add(*idnode); $$ = $1; }
     |id { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "id", "id"); NodoAST* idnode = new NodoAST(@1.first_line, @1.first_column, "id", $1); newNode->add(*idnode); $$ = newNode; };

DIMENSIONS : DIMENSIONS abrir_corchete ARIT cerrar_corchete { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); newNode->add(*$3); $1->add(*newNode); $$ = $1; }
            |abrir_corchete ARIT cerrar_corchete { NodoAST* newDimension = new NodoAST(@1.first_line, @1.first_column, "dimension", "dimension"); NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); newNode->add(*$2); newDimension->add(*newNode); $$ = newDimension; };

ARRT : punto_coma { $$ = NULL; }
       |igual VAL punto_coma { $$ = $2; };

VAL : abrir_llave EXPR cerrar_llave {  NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "valor_array", "valor_array"); newNode->add(*$2); $$ = newNode; }
       |abrir_llave LISTEX cerrar_llave {  NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "valor_array", "valor_array"); newNode->add(*$2); $$ = newNode; };

EXPR : EXPR coma abrir_llave LISTEX cerrar_llave {  NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "coma", $2); newNode->add(*$1); newNode->add(*$4); $$ = newNode;  }
       |abrir_llave LISTEX cerrar_llave {  NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "lista_expresiones", "lista_expresiones"); newNode->add(*$2); $$ = newNode; };

LISTEX : LISTEX coma EX {  NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "coma", $2); newNode->add(*$1); newNode->add(*$3); $$ = newNode; }
        |EX {  NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); newNode->add(*$1); $$ = newNode; };

SHOW : pshow abrir_parentesis EX coma EX cerrar_parentesis punto_coma { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "parametros_show", "parametros_show"); NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); newNode->add(*$3); newNode->add(*$5); novo->add(*newNode); $$ = newNode; };

IMPRIMIR : pimprimir abrir_parentesis EX cerrar_parentesis punto_coma { NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "parametros_imprimir", "parametros_imprimir"); NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); newNode->add(*$3); novo->add(*newNode); $$ = novo; };

SI : psi abrir_parentesis EX cerrar_parentesis abrir_llave cerrar_llave { NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "condicion", "condicion"); NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); novo->add(*$3); newNode->add(*novo); $$ = newNode; }
    |psi abrir_parentesis EX cerrar_parentesis abrir_llave ARGUMENTS cerrar_llave { NodoAST* newIf = new NodoAST(@1.first_line, @1.first_column, "if", "if"); NodoAST* newThen = new NodoAST(@1.first_line, @1.first_column, "then", "then"); NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "condicion", "condicion"); NodoAST* newNodeArguments = new NodoAST(@1.first_line, @1.first_column, "argumento", "argumentos"); NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); novo->add(*$3); newNode->add(*novo); newNodeArguments->add(*$6); newThen->add(*newNodeArguments); newIf->add(*newNode); newIf->add(*newThen); $$ = newIf; }
    |psi abrir_parentesis EX cerrar_parentesis abrir_llave ARGUMENTS cerrar_llave psino abrir_llave ARGUMENTS cerrar_llave { NodoAST* newIf = new NodoAST(@1.first_line, @1.first_column, "if", "if"); NodoAST* newNodeArguments = new NodoAST(@1.first_line, @1.first_column, "argumento", "argumentos"); NodoAST* newNodeArguments2 = new NodoAST(@1.first_line, @1.first_column, "argumento", "argumentos"); NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "condicion", "condicion"); NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST* newThen = new NodoAST(@1.first_line, @1.first_column, "then", "then"); NodoAST* newElse = new NodoAST(@1.first_line, @1.first_column, "else", "else"); novo->add(*$3); newNode->add(*novo); newNodeArguments->add(*$6); newThen->add(*newNodeArguments); newNodeArguments2->add(*$10); newElse->add(*newNodeArguments2); $$ = newIf; }
    |psi abrir_parentesis EX cerrar_parentesis abrir_llave ARGUMENTS cerrar_llave psino SI { NodoAST* newIf = new NodoAST(@1.first_line, @1.first_column, "if", "if"); NodoAST* newThen = new NodoAST(@1.first_line, @1.first_column, "then", "then"); NodoAST* newNode = new NodoAST(@1.first_line, @1.first_column, "condicion", "condicion"); NodoAST* newNodeArguments = new NodoAST(@1.first_line, @1.first_column, "argumento", "argumentos"); NodoAST* novo = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); novo->add(*$3); newNode->add(*novo); newNodeArguments->add(*$6); newThen->add(*newNodeArguments); newIf->add(*newNode); newIf->add(*newThen); $$ = newIf; };

PARA : ppara abrir_parentesis DECLARACION EX punto_coma COUT2 cerrar_parentesis abrir_llave ARGUMENTS cerrar_llave { NodoAST* newPara = new NodoAST(@1.first_line, @1.first_column, "para", "para"); NodoAST* newCond = new NodoAST(@1.first_line, @1.first_column, "instrucciones", "instrucciones"); NodoAST* newArguments = new NodoAST(@1.first_line, @1.first_column, "argumento", "arguments"); newCond->add(*$3); newCond->add(*$4); newCond->add(*$6); newArguments->add(*$9); newPara->add(*newCond); newPara->add(*newArguments); $$ = newPara; };

REPETIR : prepetir abrir_parentesis ARIT cerrar_parentesis abrir_llave ARGUMENTS cerrar_llave { NodoAST* newRepeat = new NodoAST(@1.first_line, @1.first_column, "repetir", "repetir"); NodoAST* newCond = new NodoAST(@1.first_line, @1.first_column, "condicion", "condicion"); NodoAST* newExpression = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); NodoAST* newArguments = new NodoAST(@1.first_line, @1.first_column, "argumento", "argumentos"); newExpression->add(*$3); newCond->add(*newExpression); newArguments->add(*$6); newRepeat->add(*newCond); newRepeat->add(*newArguments); $$ = newRepeat; }
|prepetir abrir_parentesis ARIT cerrar_parentesis abrir_llave cerrar_llave {NodoAST* newRepeat = new NodoAST(@1.first_line, @1.first_column, "repetir", "repetir"); NodoAST* newCond = new NodoAST(@1.first_line, @1.first_column, "condicion", "condicion"); NodoAST* newExpression = new NodoAST(@1.first_line, @1.first_column, "expresion", "expresion"); newExpression->add(*$3); newCond->add(*newExpression); newRepeat->add(*newCond); };

COUT : id aumento punto_coma { NodoAST* newCout = new NodoAST(@1.first_line, @1.first_column, "cout", "cout"); NodoAST* newBuff = new NodoAST(@1.first_line, @1.first_column, "aumento", strcat($1, "++")); newCout->add(*newBuff); $$ = newCout; }
      |id decremento punto_coma { NodoAST* newCout = new NodoAST(@1.first_line, @1.first_column, "cout", "cout"); NodoAST* newDecrement = new NodoAST(@1.first_line, @1.first_column, "decremento", strcat($1, "--")); newCout->add(*newDecrement); $$ = newCout; };

COUT2 :  id aumento { NodoAST* newCout = new NodoAST(@1.first_line, @1.first_column, "cout", "cout"); NodoAST* newBuff = new NodoAST(@1.first_line, @1.first_column, "aumento", strcat($1, "++")); newCout->add(*newBuff); $$ = newCout; };

%%
