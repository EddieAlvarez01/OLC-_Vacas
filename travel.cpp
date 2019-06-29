#include "travel.h"

Travel::Travel()
{

}

enum Choice{
    LCLASES = 1,
    ID = 2,
    CLASE = 3,
    EXTENDER = 4,
    LIDS = 5,
    LSENTENCIAS = 6,
    VISIBILIDAD = 7,
    TIPO = 8,
    EXPRESION = 9,
    OR = 10,
    NOR = 11,
    AND = 12,
    NAND = 13,
    NOT = 14,
    IGUAL_IGUAL = 20,
    DIFERENTE_DE = 21,
    MENOR_QUE = 22,
    MAYOR_QUE = 23,
    MENORIGUAL_QUE = 24,
    MAYORIGUAL_QUE = 25,
    SUMA = 26,
    RESTA = 27,
    MULTI = 28,
    DIVISION = 29,
    POTENCIA = 30,
    NUMERO = 31,
    DECIMAL = 32,
    CARACTER = 33,
    BOOLEAN = 34,
    CADENA = 35,
    ARREGLO = 36,
    AUMENTO = 37,
    DECREMENTO = 38,
    OBJETO_VAR = 39,
    LEXP = 40,
    LLAMADAFUNC = 41,
    DIMENSION = 42,
    LTIPOS = 43,
    FUNCIONES = 44,
    OBJETO = 45,
    DECLARACION = 46,
    ASIGNACION = 47,
    MAIN = 48,
    RETORNAR = 49,
    MOSTRARNOTIFICACION = 50,
    ELSE = 51,
    SI = 52,
    PARA = 53,
    REPETIR = 54,
    ROMPER = 55,
    MIENTRAS = 56,
    DEFECTO = 57,
    CASO = 58,
    CASOS = 59,
    COMPROBAR = 60,
    HACER = 61,
    CONTINUAR = 62,
    INCLUIR = 63,
    TRANSFERIR = 64,
    LDIMENSIONESASIG = 65,
    IMPRIMIR = 66
};

Symbol Travel::Recorrer(NodoAST *node){
    Symbol sym;
    sym.row = node->row;
    sym.column = node->column;
    switch(node->typeofValue){
        case LCLASES:
        {
            for(int x=0; x<node->child.size(); x++){
                currentEnviroment = new ScopeNode();
                QueueScope.newScope(currentEnviroment);

            }
        }
        break;
    }
}
