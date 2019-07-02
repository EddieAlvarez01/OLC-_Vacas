#ifndef SYMBOL_H
#define SYMBOL_H

#include "lexiconode.h"
#include "nodoast.h"
#include <QString>
#include <QHash>
#include <QLinkedList>
#include <QList>

class Symbol
{
public:
    Symbol();
    Symbol(int, int, QString, int, QString, QString, int, QHash<QString, Symbol*>, int, int, int, QLinkedList<LexicoNode>, NodoAST, QString);
    int row, column;
    QString id;
    int type_value;
    QString type;
    QString role = "";
    QString value = "";
    int access;  /* 0 publico, 1 privado, 2 protegido */
    QHash<QString, Symbol*> propertys;
    int dimension1;
    int dimension2;
    int dimension3;
    QLinkedList<LexicoNode> linearize;
    QList<QString> imports;
    NodoAST instructions;
    QList<Symbol*> parameters;
    QString path = "";
    QString conj = "";
    QString regx = "";
    QString enter = "";

};

#endif // SYMBOL_H
