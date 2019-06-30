#include "semantic_error.h"

Semantic_Error::Semantic_Error(int row, int column, QString type, QString description)
{
    this->row = row;
    this->column = column;
    this->type = type;
    this->description = description;
}
