#ifndef SYMBOL_H
#define SYMBOL_H

#include "nodoast.h"
#include <QString>
#include <QHash>
#include <QLinkedList>
#include <QList>

class Symbol
{
public:
    Symbol();
    Symbol(Symbol *);
    Symbol(int, int, QString, int, QString, QString, int, QHash<QString, Symbol*>, int, int, int, QLinkedList<Symbol*>, NodoAST, QString);
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
    QLinkedList<Symbol*> linearize;
    QList<QString> imports;
    NodoAST instructions;
    QList<Symbol*> parameters;
    QString path = "";
    QString conj = "";
    QString regx = "";
    QString enter = "";
    int i = 0;
    int j = 0;
    int k = 0;
    Symbol *regresa;
};

#endif // SYMBOL_H
