#ifndef LEXICONODE_H
#define LEXICONODE_H

#include <QString>


class LexicoNode
{
public:
    LexicoNode();
    LexicoNode(int, int, int, QString);
    QString data;
    int i;
    int j;
    int k;
};

#endif // LEXICONODE_H
