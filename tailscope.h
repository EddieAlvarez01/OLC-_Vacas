#ifndef TAILSCOPE_H
#define TAILSCOPE_H

#include "scopenode.h"

class TailScope
{
public:
    TailScope();
    ScopeNode *actually;
    void newScope(ScopeNode*);
    ScopeNode* deleteScope();
};

#endif // TAILSCOPE_H
