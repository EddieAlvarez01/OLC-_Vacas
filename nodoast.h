#ifndef NODOAST_H
#define NODOAST_H

#include "QList"


class NodoAST
{
public:
    NodoAST();
    NodoAST(int row, int column, QString type, QString value);
    void add(NodoAST newNode);
    QString value;
    QString type;
    int row;
    int column;
    int typeofValue;
    QList<NodoAST> child;
    int getTypeofValue();
};

#endif // NODOAST_H
