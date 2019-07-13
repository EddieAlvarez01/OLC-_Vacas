#include "symbol.h"

Symbol::Symbol()
{
    dimension1 = -1;
    dimension2 = -1;
    dimension3 = -1;
}

Symbol::Symbol(int row_, int column_, QString id_, int typevalue_, QString role_, QString value_, int access_, QHash<QString, Symbol*> propertys_, int dimension1_, int dimension2_, int dimension3_, QLinkedList<Symbol*> linerize_, NodoAST instructions_, QString type_){
    row = row_;
    column = column_;
    id = id_;
    type_value = typevalue_;
    role = role_;
    value = value_;
    access = access_;
    propertys = propertys_;
    dimension1 = dimension1_;
    dimension2 = dimension2_;
    dimension3 = dimension3_;
    linearize = linerize_;
    instructions = instructions_;
    type = type_;
}

Symbol::Symbol(Symbol *obj){
    row = obj->row;
    column = obj->column;
    id = obj->id;
    type_value = obj->type_value;
    type = obj->type;
    role = obj->role;
    value = obj->value;
    access = obj->access;
    propertys = obj->propertys;
    dimension1 = obj->dimension1;
    dimension2 = obj->dimension2;
    dimension3 = obj->dimension3;
    linearize = obj->linearize;
    imports = obj->imports;
    instructions = obj->instructions;
    parameters = obj->parameters;
    path = obj->path;
    conj = obj->conj;
    regx = obj->regx;
    enter = obj->enter;
    i = obj->i;
    j = obj->j;
    k = obj->k;
}
