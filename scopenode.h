#ifndef SCOPENODE_H
#define SCOPENODE_H

#include "symbol.h"
#include <cstddef>

class ScopeNode
{
public:
    ScopeNode();
    ScopeNode *preview;
    Symbol *actuallyClass;
};

#endif // SCOPENODE_H
