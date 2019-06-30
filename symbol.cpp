#include "symbol.h"

Symbol::Symbol()
{
    dimension1 = 0;
    dimension2 = 0;
    dimension3 = 0;
}

Symbol::Symbol(int row_, int column_, QString id_, int typevalue_, QString role_, QString value_, int access_, QHash<QString, Symbol> propertys_, int dimension1_, int dimension2_, int dimension3_, QLinkedList<LexicoNode> linerize_, NodoAST *instructions_, QString type_){
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
