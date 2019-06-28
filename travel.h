#ifndef TRAVEL_H
#define TRAVEL_H

#include "scopenode.h"
#include "tailscope.h"
#include "symbol.h"
#include "nodoast.h"
#include <QHash>
#include <QString>

class Travel
{
public:
    Travel();
    ScopeNode *currentEnviroment;
    TailScope QueueScope;
    QHash<QString, Symbol> listClass;
    Symbol Recorrer(NodoAST *node);
};

#endif // TRAVEL_H
