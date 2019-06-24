%option case-insensitive
%option yylineno
%{
#include <cstdlib>
#include "parser.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include <NodoAST.h>
#include "qlist.h"

int yylex();
void yyerror(const char *s);
int linea=0; // Para contar lineas
int columna = 1; // para las columnas
int anterior = 0;
NodoAST *raiz;
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

Commentary "//"[^\n]*[\n]
CommentaryM "<-"[^>]*"->"
letra [a-zñA-ZÑ]+
numero [0-9]+
booleano ("verdadero"|"falso"|"true"|"false")
decimal [0-9]+"."[0-9]+
id {letra}({letra}|{numero}|"_")*
caracter "'"."'"
caracter_especial ("\\\\"|"\\n"|"\\t"|"\\r"|"\\\""|"\\'")
cadena "\""[^"\""]*"\""


%%
INITIAL
{
{Commentary} {linea++;columna = 0;}
{CommentaryM} {}
{numero}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return numero;}
{decimal}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return decimal;}
{caracter}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return caracter;}
{booleano}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return booleano;}
{cadena}          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cadena;}
"principal" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pprincipal;}
"entero" {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pint;}
"doble" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pdouble;}
"booleano" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pbool;}
"caracter" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pchar;}
"cadena" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pstring;}
"arreglo" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return parreglo;}
"clase" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pclase;}
"extender" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pextender;}
"sobrescribir" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return psobrescribir;}
"publico" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return ppublico;}
"privado" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pprivado;}
"protegido" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pprotegido;}
"void" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pvoid;}
"retornar" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pretornar;}
"imprimir" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pimprimir;}
"mostrarnotificacion" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pmostrarnotificacion;}
"si" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return psi;}
"sino" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return psino;}
"para" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return ppara;}
"repetir" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prepetir;}
"romper" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return promper;}
"mientras" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pmientras;}
"comprobar" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcomprobar;}
"hacer" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return phacer;}
"continuar" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcontinuar;}
"incluir" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pincluir;}
"archivo" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return parchivo;}
"creararchivoder" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcreararchivoder;}
"crearconjunto" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcrearconjunto;}
"crearregex" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcrearregex;}
"crearentrada" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcrearentrada;}
"guardararchivo" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pguardararchivo;}
"crearcuenta" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pcrearcuenta;}
"verificarcuenta" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pverificarcuenta;}
"depositarcuenta" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pdepositarcuenta;}
"restarcuenta" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return prestarcuenta;}
"imprimirtransaccionescuenta" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pimprimirtransaccionescuenta;}
"consultarcuenta" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return pconsultarcuenta;}
"transferir" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return ptransferir;}
{id} { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return id;}
"[" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return abrir_corchete;}
"]" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cerrar_corchete;}
"," { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return coma;}
"$" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return finalizacion;}
"=" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return igual;}
"++" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return aumento;}
"--" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return decremento;}
"("          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return abrir_parentesis; }
")"          {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cerrar_parentesis; }
"{" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return abrir_llave;}
"}" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return cerrar_llave;}
"==" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return igual_igual;}
"!=" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return diferente_de;}
"<" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return menor_que;}
"<=" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return menorigual_que;}
">" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return mayor_que;}
">=" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return mayorigual_que;}
"||" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return opor;}
"&&" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return opand;}
"!&&" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return opnand;}
"!" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return opnot;}
"!||" { columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return opnor;}
"+"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return suma; }
"-"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return resta; }
"*"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return multi; }
"/"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return division; }
"^"         {   columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext); return potencia; }
"\t"            {
                    strcpy(yylval.TEXT, yytext); columna=26;
                }
[[:blank:]]     { columna++; }
"\n"            {linea++; columna = 0; anterior = 0;}
.               {
                    columna=columna+ anterior;  anterior = strlen(yytext);strcpy(yylval.TEXT, yytext);
/*                    errorT *nuevoE = new errorT("Lexico",yytext,linea, columna);
                    listaErrores->append(*nuevoE);
*/
                    std::cout <<yytext <<" Error Lexico en la linea "<< linea << " Columna:"<< columna<<  std::endl;
                }
}
%%
