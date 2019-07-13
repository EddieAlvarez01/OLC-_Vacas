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
#include <QFile>
#include <QTextStream>
#include "notify.h"

class Travel
{
public:
    Travel();
    ScopeNode *currentEnviroment;
    TailScope QueueScope;
    QHash<QString, Symbol*> listClass;
    Symbol* Recorrer(NodoAST *node);
    Symbol* SearchRole(int );
    void CopyLIDS(QList<QString> &original, QList<QString>copy);
    QList<Semantic_Error*> semanticError;
    Symbol* SearchidScope(QString id);
    QList<QString> consoleMsg;
    QList<Notify *> notifyMsg;
    int AsignType(QString type);
    QString keyMain = "";
    void StartProgram();
    QHash<QString, Symbol*> CopyHash(QHash<QString, Symbol*>);
    void InitClassValues();
    bool isReturn, isBreak, isContinue = false;
    void importHash(QHash<QString, Symbol*>&, QHash<QString, Symbol*>&);
    void chargeImports();
};

#endif // TRAVEL_H
