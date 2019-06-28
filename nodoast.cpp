#include "nodoast.h"

NodoAST::NodoAST()
{
 value = "";
 type = "";
 row = 0;
 column = 0;
 child = QList<NodoAST>();
}

NodoAST::NodoAST(int row, int column, QString type, QString value){
    this->row = row;
    this->column = column;
    this->type = type;
    this->value = value;
    typeofValue = getTypeofValue();
}

void NodoAST::add(NodoAST newNode){
    this->child.append(newNode);
}

int NodoAST::getTypeofValue(){
    if(type == "lclases"){
        return 1;
    }else if(type == "id"){
        return 2;
    }else if(type == "clase"){
        return 3;
    }else if(type == "extender"){
        return 4;
    }else if(type == "lids"){
        return 5;
    }else if(type == "lsentencias"){
        return 6;
    }else if(type == "visibilidad"){
        return 7;
    }else if(type == "tipo"){
        return 8;
    }else if(type == "expresion"){
        return 9;
    }else if(type == "or"){
        return 10;
    }else if(type == "nor"){
        return 11;
    }else if(type == "and"){
        return 12;
    }else if(type == "nand"){
        return 13;
    }else if(type == "not"){
        return 14;
    }else if(type == "tipo"){
        return 15;
    }else if(type == "expresion"){
        return 16;
    }else if(type == "or"){
        return 17;
    }else if(type == "and"){
        return 18;
    }else if(type == "not"){
        return 19;
    }else if(type == "igual_igual"){
        return 20;
    }else if(type == "diferente_de"){
        return 21;
    }else if(type == "menor_que"){
        return 22;
    }else if(type == "mayor_que"){
        return 23;
    }else if(type == "menorigual_que"){
        return 24;
    }else if(type == "mayorigual_que"){
        return 25;
    }else if(type == "suma"){
        return 26;
    }else if(type == "resta"){
        return 27;
    }else if(type == "multi"){
        return 28;
    }else if(type == "division"){
        return 29;
    }else if(type == "potencia"){
        return 30;
    }else if(type == "numero"){
        return 31;
    }else if(type == "decimal"){
        return 32;
    }else if(type == "caracter"){
        return 33;
    }else if(type == "boolean"){
        return 34;
    }else if(type == "cadena"){
        return 35;
    }else if(type == "arreglo"){
        return 36;
    }else if(type == "aumento"){
        return 37;
    }else if(type == "decremento"){
        return 38;
    }else if(type == "objeto_var"){
        return 39;
    }else if(type == "lexp"){
        return 40;
    }else if(type == "llamadafunc"){
        return 41;
    }else if(type == "dimension"){
        return 42;
    }else if(type == "ltipos"){
        return 43;
    }else if(type == "funciones"){
        return 44;
    }else if(type == "objeto"){
        return 45;
    }else if(type == "declaracion"){
        return 46;
    }else if(type == "asignacion"){
        return 47;
    }else if(type == "main"){
        return 48;
    }else if(type == "retornar"){
        return 49;
    }else if(type == "mostrarNotificacion"){
        return 50;
    }else if(type == "else"){
        return 51;
    }else if(type == "si"){
        return 52;
    }
    return 0;
}
