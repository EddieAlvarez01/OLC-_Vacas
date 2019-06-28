#include "tailscope.h"

TailScope::TailScope()
{
    actually = nullptr;
}

void TailScope::newScope(ScopeNode *node){
    if(actually != nullptr){
        node->preview = actually;
        actually = node;
    }else{
        actually = node;
    }
}

ScopeNode* TailScope::deleteScope(){
    ScopeNode *tmp = actually->preview;
    actually->preview = nullptr;
    actually = tmp;
    return actually;
}
