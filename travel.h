#ifndef TRAVEL_H
#define TRAVEL_H

#include "scopenode.h"
#include "tailscope.h"
#include "symbol.h"
#include "nodoast.h"
#include "semantic_error.h"
#include <QHash>
#include <QString>
#include <QList>
#include <math.h>
#include <iostream>
#include <algorithm>

class Travel
{
public:
    Travel();
    ScopeNode *currentEnviroment;
    TailScope QueueScope;
    QHash<QString, Symbol*> listClass;
    Symbol* Recorrer(NodoAST *node);
    void CopyLIDS(QList<QString> &original, QList<QString>copy);
    QList<Semantic_Error*> semanticError;
    Symbol* SearchidScope(QString id);
    QList<QString> consoleMsg;
    int AsignType(QString type);
    QString keyMain = "";
    void StartProgram();
};

#endif // TRAVEL_H
