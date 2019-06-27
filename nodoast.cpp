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
    }else if(type == "suma"){
        return 6;
    }else if(type == "resta"){
        return 7;
    }else if(type == "multiplicacion"){
        return 8;
    }else if(type == "division"){
        return 9;
    }else if(type == "potencia"){
        return 10;
    }else if(type == "operacion"){
        return 11;
    }else if(type == "principal"){
        return 12;
    }else if(type == "argumento"){
        return 13;
    }else if(type == "declaracion"){
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
    }else if(type == "menor_que"){
        return 20;
    }else if(type == "mayor_que"){
        return 21;
    }else if(type == "mayor_igual"){
        return 22;
    }else if(type == "menor_igual"){
        return 23;
    }else if(type == "igual"){
        return 24;
    }else if(type == "diferente_de"){
        return 25;
    }else if(type == "variable"){
        return 26;
    }else if(type == "arreglo"){
        return 27;
    }else if(type == "id"){
        return 28;
    }else if(type == "valor_array"){
        return 29;
    }else if(type == "coma"){
        return 30;
    }else if(type == "lista_expresiones"){
        return 31;
    }else if(type == "parametros_show"){
        return 32;
    }else if(type == "parametros_imprimir"){
        return 33;
    }else if(type == "condicion"){
        return 34;
    }else if(type == "then"){
        return 35;
    }else if(type == "else"){
        return 36;
    }else if(type == "if"){
        return 37;
    }else if(type == "para"){
        return 38;
    }else if(type == "instrucciones"){
        return 39;
    }else if(type == "repetir"){
        return 40;
    }else if(type == "aumento"){
        return 41;
    }else if(type == "cout"){
        return 42;
    }else if(type == "decremento"){
        return 43;
    }
    return 0;
}
