#include "lexiconode.h"

LexicoNode::LexicoNode()
{
    i = 0;
    j = 0;
    k = 0;
    data = "";
}

LexicoNode::LexicoNode(int i_, int j_, int k_, QString data_){
    i = i_;
    j = j_;
    k = k_;
    data = data_;
}
