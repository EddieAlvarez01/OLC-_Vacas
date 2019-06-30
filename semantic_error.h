#ifndef SEMANTIC_ERROR_H
#define SEMANTIC_ERROR_H

#include <QString>


class Semantic_Error
{
public:
    Semantic_Error(int, int, QString, QString);
    int row;
    int column;
    QString type;
    QString description;
};

#endif // SEMANTIC_ERROR_H
