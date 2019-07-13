#include "travel.h"

Travel::Travel()
{

}

enum Choice{
    LCLASES = 1,
    ID = 2,
    CLASE = 3,
    EXTENDER = 4,
    LIDS = 5,
    LSENTENCIAS = 6,
    VISIBILIDAD = 7,
    TIPO = 8,
    EXPRESION = 9,
    OR = 10,
    NOR = 11,
    AND = 12,
    NAND = 13,
    NOT = 14,
    IGUAL_IGUAL = 20,
    DIFERENTE_DE = 21,
    MENOR_QUE = 22,
    MAYOR_QUE = 23,
    MENORIGUAL_QUE = 24,
    MAYORIGUAL_QUE = 25,
    SUMA = 26,
    RESTA = 27,
    MULTI = 28,
    DIVISION = 29,
    POTENCIA = 30,
    NUMERO = 31,
    DECIMAL = 32,
    CARACTER = 33,
    BOOLEAN = 34,
    CADENA = 35,
    ARREGLO = 36,
    AUMENTO = 37,
    DECREMENTO = 38,
    OBJETO_VAR = 39,
    LEXP = 40,
    LLAMADAFUNC = 41,
    DIMENSION = 42,
    LTIPOS = 43,
    FUNCIONES = 44,
    OBJETO = 45,
    DECLARACION = 46,
    ASIGNACION = 47,
    MAIN = 48,
    RETORNAR = 49,
    MOSTRARNOTIFICACION = 50,
    ELSE = 51,
    SI = 52,
    PARA = 53,
    REPETIR = 54,
    ROMPER = 55,
    MIENTRAS = 56,
    DEFECTO = 57,
    CASO = 58,
    CASOS = 59,
    COMPROBAR = 60,
    HACER = 61,
    CONTINUAR = 62,
    INCLUIR = 63,
    TRANSFERIR = 64,
    LDIMENSIONESASIG = 65,
    IMPRIMIR = 66,
    VOID = 67,
    MENOS = 68,
    ARCHIVO = 69
};

Symbol* Travel::Recorrer(NodoAST *node){
    Symbol *sym = new Symbol();
    sym->row = node->row;
    sym->column = node->column;
    switch(node->typeofValue){
        case LCLASES:
        {
            for(int x=0; x<node->child.size(); x++){
                currentEnviroment = new ScopeNode();
                QueueScope.newScope(currentEnviroment);
                NodoAST tmp = node->child.at(x);
                Recorrer(&tmp);
                listClass.insert(currentEnviroment->actuallyClass->id, currentEnviroment->actuallyClass);
                currentEnviroment = QueueScope.deleteScope();
            }
        }
        break;
        case CLASE:
        {
            currentEnviroment->actuallyClass->role = "clase";
            if(node->child.size() == 3){
                currentEnviroment->actuallyClass->id = node->child.at(2).value.toLower();
                NodoAST tmp = node->child.at(0);
                NodoAST tmp2 = node->child.at(1);
                Recorrer(&tmp);
                currentEnviroment->actuallyClass->instructions = tmp2;
            }else if(node->child.size() == 2){
                currentEnviroment->actuallyClass->id = node->child.at(1).value.toLower();
                 NodoAST tmp = node->child.at(0);
                 currentEnviroment->actuallyClass->instructions = tmp;
            }else{
                currentEnviroment->actuallyClass->id = node->child.at(0).value.toLower();
            }
        }
        break;
        case EXTENDER:
        {
            NodoAST tmp = node->child.at(0);
            QList<QString> list = Recorrer(&tmp)->imports;
            CopyLIDS(currentEnviroment->actuallyClass->imports, list);
        }
        break;
        case LIDS:
        {
            for(int x=0; x<node->child.size(); x++){
                sym->imports.push_back(node->child.at(x).value.toLower());
            }
        }
        break;
        case LSENTENCIAS:
        {
            for(int x=0; x<node->child.size(); x++){
                NodoAST tmp = node->child.at(x);
                if(!isReturn && !isBreak && !isContinue){
                    Recorrer(&tmp);
                }
            }
        }
        break;
        case DECLARACION:
        {
            switch (node->child.at(0).typeofValue) {
                case VISIBILIDAD:
                {
                    if(node->child.at(0).value.toLower() == "publico"){
                        sym->access = 0;
                    }else if(node->child.at(0).value.toLower() == "privado"){
                        sym->access = 1;
                    }else if(node->child.at(0).value.toLower() == "protegido"){
                        sym->access = 2;
                    }
                    sym->type = node->child.at(1).value.toLower();
                    sym->type_value = AsignType(sym->type);
                    NodoAST tmp = node->child.at(2);
                    if(tmp.typeofValue == LIDS){
                        sym->imports = Recorrer(&tmp)->imports;
                    }else{
                        Symbol *listD = Recorrer(&tmp);
                        if(listD->dimension1 == 0 || listD->dimension2 == 0 || listD->dimension3 == 0){
                            QString description = "No se puede asignar 0 a una dimension";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }else{
                            sym->dimension1 = listD->dimension1;
                            sym->dimension2 = listD->dimension2;
                            sym->dimension3 = listD->dimension3;
                        }
                    }
                    if(node->child.size() > 3){
                        if(node->child.at(3).typeofValue == DIMENSION){
                             NodoAST tmp = node->child.at(3);
                             Symbol *listD = Recorrer(&tmp);
                             if(listD->dimension1 == 0 || listD->dimension2 == 0 || listD->dimension3 == 0){
                                 QString description = "No se puede asignar 0 a una dimension";
                                 Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                 semanticError.push_back(error);
                             }else{
                                 sym->dimension1 = listD->dimension1;
                                 sym->dimension2 = listD->dimension2;
                                 sym->dimension3 = listD->dimension3;
                                 if(node->child.size() > 4){
                                    switch (node->child.at(4).typeofValue) {
                                        case LEXP:
                                        {
                                            NodoAST gg = node->child.at(4);
                                            sym->parameters = Recorrer(&gg)->parameters;
                                            if(sym->parameters.size() <= sym->dimension1){
                                                bool flagError = false;
                                                for(int x=0; x<sym->parameters.size(); x++){
                                                    switch (sym->type_value) {
                                                        case NUMERO:
                                                        {
                                                            switch(sym->parameters.at(x)->type_value){
                                                                case NUMERO:
                                                                {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   arr->value = sym->parameters.at(x)->value;
                                                                   arr->type_value = NUMERO;
                                                                   sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                case DECIMAL:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    int result = (int)sym->parameters.at(x)->value.toDouble();
                                                                    arr->value = QString::number(result);
                                                                    arr->type_value = NUMERO;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                case CARACTER:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    int result = sym->parameters.at(x)->value[0].toLatin1();
                                                                    arr->value = QString::number(result);
                                                                    arr->type_value = NUMERO;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                case BOOLEAN:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    int result = QVariant(sym->parameters.at(x)->value).toBool();
                                                                    arr->value = QString::number(result);
                                                                    arr->type_value = NUMERO;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                default:
                                                                {
                                                                    QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                        case DECIMAL:
                                                        {
                                                            switch (sym->parameters.at(x)->type_value) {
                                                                case NUMERO:
                                                                {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   double result = sym->parameters.at(x)->value.toInt();
                                                                   arr->value = QString::number(result);
                                                                   arr->type_value = DECIMAL;
                                                                   sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                case DECIMAL:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    arr->value = sym->parameters.at(x)->value;
                                                                    arr->type_value = DECIMAL;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                default:
                                                                {
                                                                    QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                        case CADENA:
                                                        {
                                                            switch (sym->parameters.at(x)->type_value) {
                                                                case BOOLEAN:
                                                                {
                                                                    QString description = "No se puede asignar un booleano a una cadena";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                                break;
                                                                case ID:
                                                                {
                                                                    QString description = "No se puede asignar un objeto a una cadena";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                                break;
                                                                default:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    arr->value = sym->parameters.at(x)->value;
                                                                    arr->type_value = CADENA;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                        case CARACTER:
                                                        {
                                                            switch (sym->parameters.at(x)->type_value) {
                                                                case NUMERO:
                                                                {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   QChar result = sym->parameters.at(x)->value.toInt();
                                                                   arr->value = result;
                                                                   arr->type_value = CARACTER;
                                                                   sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                case CARACTER:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    arr->value = sym->parameters.at(x)->value;
                                                                    arr->type_value = CARACTER;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                default:
                                                                {
                                                                    QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                        case BOOLEAN:
                                                        {
                                                            switch (sym->parameters.at(x)->type_value) {
                                                                case BOOLEAN:
                                                                {
                                                                    Symbol *arr = new Symbol();
                                                                    arr->i = x;
                                                                    arr->value = sym->parameters.at(x)->value;
                                                                    arr->type_value = BOOLEAN;
                                                                    sym->linearize.push_back(arr);
                                                                }
                                                                break;
                                                                case NUMERO:
                                                                {
                                                                    int op = sym->parameters.at(x)->value.toInt();
                                                                    if(op == 1 || op == 0){
                                                                        Symbol *arr = new Symbol();
                                                                        arr->i = x;
                                                                            arr->type_value = BOOLEAN;
                                                                          bool result = QVariant(op).toBool();
                                                                          arr->value = result ? "true" : "false";
                                                                          sym->linearize.push_back(arr);
                                                                    }else{
                                                                        QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                        semanticError.push_back(error);
                                                                        flagError = true;
                                                                    }
                                                                }
                                                                break;
                                                                default:
                                                                {
                                                                    QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                        case ID:
                                                        {
                                                            switch (sym->parameters.at(x)->type_value) {
                                                                case ID:
                                                                {

                                                                }
                                                                break;
                                                                default:
                                                                {

                                                                }
                                                                break;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }
                                                if(!flagError){
                                                    sym->role = "arreglo";
                                                    for(int i=0; i<sym->imports.size(); i++){
                                                        Symbol *newS = new Symbol();
                                                        newS->access = sym->access;
                                                        newS->id = sym->imports.at(i);
                                                        newS->dimension1 = sym->dimension1;
                                                        newS->dimension2 = sym->dimension2;
                                                        newS->dimension3 = sym->dimension3;
                                                        newS->type_value = sym->type_value;
                                                        newS->role = sym->role;
                                                        newS->linearize = sym->linearize;
                                                        newS->row = sym->row;
                                                        newS->column = sym->column;
                                                        currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                                    }
                                                }
                                            }else{
                                                QString description = "Esta declarando un numero de valores mas grande que el array";
                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                semanticError.push_back(error);
                                            }
                                        }
                                        break;
                                        case LDIMENSIONESASIG:
                                        {
                                            if(sym->dimension3 != -1){
                                                bool flagError = false;
                                                if(node->child.at(4).child.at(0).typeofValue == LDIMENSIONESASIG){
                                                    for(int i=0; i<node->child.at(4).child.size(); i++){
                                                        NodoAST sia = node->child.at(4).child.at(i);
                                                        for(int y=0; y<sia.child.size(); y++){
                                                            NodoAST tmp = sia.child.at(y);
                                                            Symbol *ju = Recorrer(&tmp);
                                                            for(int x=0; x<ju->parameters.size(); x++){
                                                                if(x < sym->dimension1 && y < sym->dimension2 && i < sym->dimension3){
                                                                    switch (sym->type_value) {
                                                                        case NUMERO:
                                                                        {
                                                                            switch(ju->parameters.at(x)->type_value){
                                                                                case NUMERO:
                                                                                {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   arr->value = ju->parameters.at(x)->value;
                                                                                   arr->type_value = NUMERO;
                                                                                   sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                case DECIMAL:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    int result = (int)ju->parameters.at(x)->value.toDouble();
                                                                                    arr->value = QString::number(result);
                                                                                    arr->type_value = NUMERO;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                case CARACTER:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    int result = ju->parameters.at(x)->value[0].toLatin1();
                                                                                    arr->value = QString::number(result);
                                                                                    arr->type_value = NUMERO;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                case BOOLEAN:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    int result = QVariant(ju->parameters.at(x)->value).toBool();
                                                                                    arr->value = QString::number(result);
                                                                                    arr->type_value = NUMERO;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                default:
                                                                                {
                                                                                    QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                    semanticError.push_back(error);
                                                                                    flagError = true;
                                                                                }
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                        case DECIMAL:
                                                                        {
                                                                            switch (ju->parameters.at(x)->type_value) {
                                                                                case NUMERO:
                                                                                {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   double result = ju->parameters.at(x)->value.toInt();
                                                                                   arr->value = QString::number(result);
                                                                                   arr->type_value = DECIMAL;
                                                                                   sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                case DECIMAL:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    arr->value = ju->parameters.at(x)->value;
                                                                                    arr->type_value = DECIMAL;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                default:
                                                                                {
                                                                                    QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                    semanticError.push_back(error);
                                                                                    flagError = true;
                                                                                }
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                        case CADENA:
                                                                        {
                                                                            switch (ju->parameters.at(x)->type_value) {
                                                                                case BOOLEAN:
                                                                                {
                                                                                    QString description = "No se puede asignar un booleano a una cadena";
                                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                    semanticError.push_back(error);
                                                                                    flagError = true;
                                                                                }
                                                                                break;
                                                                                case ID:
                                                                                {
                                                                                    QString description = "No se puede asignar un objeto a una cadena";
                                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                    semanticError.push_back(error);
                                                                                    flagError = true;
                                                                                }
                                                                                break;
                                                                                default:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    arr->value = ju->parameters.at(x)->value;
                                                                                    arr->type_value = CADENA;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                        case CARACTER:
                                                                        {
                                                                            switch (ju->parameters.at(x)->type_value) {
                                                                                case NUMERO:
                                                                                {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   QChar result = ju->parameters.at(x)->value.toInt();
                                                                                   arr->value = result;
                                                                                   arr->type_value = CARACTER;
                                                                                   sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                case CARACTER:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    arr->value = ju->parameters.at(x)->value;
                                                                                    arr->type_value = CARACTER;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                default:
                                                                                {
                                                                                    QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                    semanticError.push_back(error);
                                                                                    flagError = true;
                                                                                }
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                        case BOOLEAN:
                                                                        {
                                                                            switch (ju->parameters.at(x)->type_value) {
                                                                                case BOOLEAN:
                                                                                {
                                                                                    Symbol *arr = new Symbol();
                                                                                    arr->i = x;
                                                                                    arr->j = y;
                                                                                    arr->k = i;
                                                                                    arr->value = ju->parameters.at(x)->value;
                                                                                    arr->type_value = BOOLEAN;
                                                                                    sym->linearize.push_back(arr);
                                                                                }
                                                                                break;
                                                                                case NUMERO:
                                                                                {
                                                                                    int op = ju->parameters.at(x)->value.toInt();
                                                                                    if(op == 1 || op == 0){
                                                                                        Symbol *arr = new Symbol();
                                                                                        arr->i = x;
                                                                                        arr->j = y;
                                                                                        arr->k = i;
                                                                                            arr->type_value = BOOLEAN;
                                                                                          bool result = QVariant(op).toBool();
                                                                                          arr->value = result ? "true" : "false";
                                                                                          sym->linearize.push_back(arr);
                                                                                    }else{
                                                                                        QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                        semanticError.push_back(error);
                                                                                        flagError = true;
                                                                                    }
                                                                                }
                                                                                break;
                                                                                default:
                                                                                {
                                                                                    QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                    semanticError.push_back(error);
                                                                                    flagError = true;
                                                                                }
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                        case ID:
                                                                        {
                                                                            switch (sym->parameters.at(x)->type_value) {
                                                                                case ID:
                                                                                {

                                                                                }
                                                                                break;
                                                                                default:
                                                                                {

                                                                                }
                                                                                break;
                                                                            }
                                                                        }
                                                                        break;
                                                                    }
                                                                }else{
                                                                    QString description = "Se salio fuera de los limites del array";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                    flagError = true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if(!flagError){
                                                        sym->role = "arreglo";
                                                        for(int i=0; i<sym->imports.size(); i++){
                                                            Symbol *newS = new Symbol();
                                                            newS->access = sym->access;
                                                            newS->id = sym->imports.at(i);
                                                            newS->dimension1 = sym->dimension1;
                                                            newS->dimension2 = sym->dimension2;
                                                            newS->dimension3 = sym->dimension3;
                                                            newS->type_value = sym->type_value;
                                                            newS->role = sym->role;
                                                            newS->linearize = sym->linearize;
                                                            newS->row = sym->row;
                                                            newS->column = sym->column;
                                                            currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                                        }
                                                    }
                                                }else{
                                                    QString description = "No se puede declarar un array unidimensional o bimensional en uno de 3 dimensiones";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                    flagError = true;
                                                }
                                            }else{
                                                int county = 0;
                                                bool flagError = false;
                                                for(int i=0; i<node->child.at(4).child.size(); i++){
                                                    NodoAST tmp = node->child.at(4).child.at(i);
                                                    Symbol *ju = Recorrer(&tmp);
                                                    for(int x=0; x<ju->parameters.size(); x++){
                                                        if(x < sym->dimension1 && county < sym->dimension2){
                                                            switch (sym->type_value) {
                                                                case NUMERO:
                                                                {
                                                                    switch(ju->parameters.at(x)->type_value){
                                                                        case NUMERO:
                                                                        {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           arr->value = ju->parameters.at(x)->value;
                                                                           arr->type_value = NUMERO;
                                                                           sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        case DECIMAL:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            int result = (int)ju->parameters.at(x)->value.toDouble();
                                                                            arr->value = QString::number(result);
                                                                            arr->type_value = NUMERO;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        case CARACTER:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            int result = ju->parameters.at(x)->value[0].toLatin1();
                                                                            arr->value = QString::number(result);
                                                                            arr->type_value = NUMERO;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        case BOOLEAN:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            int result = QVariant(ju->parameters.at(x)->value).toBool();
                                                                            arr->value = QString::number(result);
                                                                            arr->type_value = NUMERO;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        default:
                                                                        {
                                                                            QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                            semanticError.push_back(error);
                                                                            flagError = true;
                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                                case DECIMAL:
                                                                {
                                                                    switch (ju->parameters.at(x)->type_value) {
                                                                        case NUMERO:
                                                                        {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           double result = ju->parameters.at(x)->value.toInt();
                                                                           arr->value = QString::number(result);
                                                                           arr->type_value = DECIMAL;
                                                                           sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        case DECIMAL:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            arr->value = ju->parameters.at(x)->value;
                                                                            arr->type_value = DECIMAL;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        default:
                                                                        {
                                                                            QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                            semanticError.push_back(error);
                                                                            flagError = true;
                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                                case CADENA:
                                                                {
                                                                    switch (ju->parameters.at(x)->type_value) {
                                                                        case BOOLEAN:
                                                                        {
                                                                            QString description = "No se puede asignar un booleano a una cadena";
                                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                            semanticError.push_back(error);
                                                                            flagError = true;
                                                                        }
                                                                        break;
                                                                        case ID:
                                                                        {
                                                                            QString description = "No se puede asignar un objeto a una cadena";
                                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                            semanticError.push_back(error);
                                                                            flagError = true;
                                                                        }
                                                                        break;
                                                                        default:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            arr->value = ju->parameters.at(x)->value;
                                                                            arr->type_value = CADENA;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                                case CARACTER:
                                                                {
                                                                    switch (ju->parameters.at(x)->type_value) {
                                                                        case NUMERO:
                                                                        {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           QChar result = ju->parameters.at(x)->value.toInt();
                                                                           arr->value = result;
                                                                           arr->type_value = CARACTER;
                                                                           sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        case CARACTER:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            arr->value = ju->parameters.at(x)->value;
                                                                            arr->type_value = CARACTER;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        default:
                                                                        {
                                                                            QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                            semanticError.push_back(error);
                                                                            flagError = true;
                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                                case BOOLEAN:
                                                                {
                                                                    switch (ju->parameters.at(x)->type_value) {
                                                                        case BOOLEAN:
                                                                        {
                                                                            Symbol *arr = new Symbol();
                                                                            arr->i = x;
                                                                            arr->j = county;
                                                                            arr->value = ju->parameters.at(x)->value;
                                                                            arr->type_value = BOOLEAN;
                                                                            sym->linearize.push_back(arr);
                                                                        }
                                                                        break;
                                                                        case NUMERO:
                                                                        {
                                                                            int op = ju->parameters.at(x)->value.toInt();
                                                                            if(op == 1 || op == 0){
                                                                                Symbol *arr = new Symbol();
                                                                                arr->i = x;
                                                                                arr->j = county;
                                                                                    arr->type_value = BOOLEAN;
                                                                                  bool result = QVariant(op).toBool();
                                                                                  arr->value = result ? "true" : "false";
                                                                                  sym->linearize.push_back(arr);
                                                                            }else{
                                                                                QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                semanticError.push_back(error);
                                                                                flagError = true;
                                                                            }
                                                                        }
                                                                        break;
                                                                        default:
                                                                        {
                                                                            QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                            semanticError.push_back(error);
                                                                            flagError = true;
                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                                case ID:
                                                                {
                                                                    switch (sym->parameters.at(x)->type_value) {
                                                                        case ID:
                                                                        {

                                                                        }
                                                                        break;
                                                                        default:
                                                                        {

                                                                        }
                                                                        break;
                                                                    }
                                                                }
                                                                break;
                                                            }
                                                        }else{
                                                            QString description = "Se salio fuera de los limites del array";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                            flagError = true;
                                                        }
                                                    }
                                                    county++;
                                                }
                                                if(!flagError){
                                                    sym->role = "arreglo";
                                                    for(int i=0; i<sym->imports.size(); i++){
                                                        Symbol *newS = new Symbol();
                                                        newS->access = sym->access;
                                                        newS->id = sym->imports.at(i);
                                                        newS->dimension1 = sym->dimension1;
                                                        newS->dimension2 = sym->dimension2;
                                                        newS->dimension3 = sym->dimension3;
                                                        newS->type_value = sym->type_value;
                                                        newS->role = sym->role;
                                                        newS->linearize = sym->linearize;
                                                        newS->row = sym->row;
                                                        newS->column = sym->column;
                                                        currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    }
                                 }else{
                                     sym->role = "arreglo";
                                     for(int i=0; i<sym->imports.size(); i++){
                                        Symbol *newS = new Symbol();
                                        newS->access = sym->access;
                                        newS->id = sym->imports.at(i);
                                        newS->dimension1 = sym->dimension1;
                                        newS->dimension2 = sym->dimension2;
                                        newS->dimension3 = sym->dimension3;
                                        newS->type_value = sym->type_value;
                                        newS->role = sym->role;
                                        newS->row = sym->row;
                                        newS->column = sym->column;
                                        currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                     }
                                 }
                             }
                        }else if(node->child.at(3).typeofValue == FUNCIONES){
                            NodoAST fun = node->child.at(3);
                            sym->role = "funcion";
                            if(fun.child.size() == 1){
                                switch (fun.child.at(0).typeofValue) {
                                    case LSENTENCIAS:
                                    {
                                        sym->instructions = fun.child.at(0);
                                        sym->id = sym->imports.at(0);
                                    }
                                    break;
                                    case LTIPOS:
                                    {
                                        NodoAST tmp = fun.child.at(0);
                                        Symbol *list = Recorrer(&tmp);
                                        sym->parameters = list->parameters;
                                        sym->id = sym->imports.at(0);
                                    }
                                    break;
                                }
                            }else if(fun.child.size() == 2){
                                NodoAST tmp = fun.child.at(0);
                                Symbol *list = Recorrer(&tmp);
                                sym->parameters = list->parameters;
                                sym->id = sym->imports.at(0);
                                sym->instructions = fun.child.at(1);
                            }
                            currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
                        }else if(node->child.at(3).typeofValue == EXPRESION){
                            NodoAST tmp = node->child.at(3);
                            Symbol *ss = Recorrer(&tmp);
                            if(sym->type == "entero"){
                                switch(ss->type_value){
                                    case NUMERO:
                                    {
                                        sym->type_value = NUMERO;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        sym->type_value = NUMERO;
                                        int result = (int)ss->value.toDouble();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        sym->type_value = NUMERO;
                                        int result = ss->value[0].toLatin1();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        sym->type_value = NUMERO;
                                        int result = QVariant(ss->value).toBool();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo entero";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }else if(sym->type == "doble"){
                                switch(ss->type_value){
                                    case NUMERO:
                                    {
                                        sym->type_value = DECIMAL;
                                        double result = ss->value.toInt();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        sym->type_value = DECIMAL;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        QString description = "No se puede asignar un caracter a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        QString description = "No se puede asignar un booleano a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            else if(sym->type == "cadena"){
                                sym->type_value = CADENA;
                                sym->value = ss->value;
                            }else if(sym->type == "caracter"){
                                switch(ss->type_value){
                                    case NUMERO:
                                    {
                                        sym->type_value = CARACTER;
                                        QChar result = ss->value.toInt();
                                        sym->value = result;
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        sym->type_value = CARACTER;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        QString description = "No se puede asignar un doble a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        QString description = "No se puede asignar un booleano a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }else if(sym->type == "booleano"){
                                switch (ss->type_value) {
                                    case BOOLEAN:
                                    {
                                        sym->type_value = BOOLEAN;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case NUMERO:
                                    {
                                        int op = ss->value.toInt();
                                        if(op == 1 || op == 0){
                                                sym->type_value = BOOLEAN;
                                              bool result = QVariant(op).toBool();
                                              sym->value = result ? "true" : "false";
                                        }else{
                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        QString description = "No se puede asignar un doble a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        QString description = "No se puede asignar un caracter a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            for(int x=0; x<sym->imports.size(); x++){
                                Symbol *newS = new Symbol();
                                newS->access = sym->access;
                                newS->type = sym->type;
                                newS->type_value = sym->type_value;
                                newS->id = sym->imports.at(x);
                                newS->value = sym->value;
                                currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                            }
                        }else if(node->child.at(3).typeofValue == OBJETO){
                            if(node->child.at(3).child.size() == 1){
                                sym->role = "objeto";
                                Symbol *cl = listClass.value(sym->type, nullptr);
                                if(cl != nullptr){
                                    if(cl->propertys.size() == 0){
                                        currentEnviroment = new ScopeNode();
                                        currentEnviroment->actuallyClass = cl;
                                        QueueScope.newScope(currentEnviroment);
                                        Recorrer(&cl->instructions);
                                        currentEnviroment = QueueScope.deleteScope();
                                        sym->propertys = CopyHash(cl->propertys);
                                    }else{
                                        sym->propertys = CopyHash(cl->propertys);
                                    }
                                }
                                sym->id = sym->imports.at(0);
                                currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
                            }else if(node->child.at(3).child.size() == 2){
                                NodoAST tmp = node->child.at(3).child.at(1);
                                Symbol *op = Recorrer(&tmp);
                                if(op->type_value == CADENA){
                                    sym->path = op->value.toLower();
                                    sym->role = "objeto";
                                    if(!sym->path.contains(".der")){
                                        sym->path = sym->path + ".der";
                                    }
                                    sym->id = sym->imports.at(0);
                                    currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
                                }else{
                                    QString description = "Al declarar una variable archivo se espera una cadena con el nombre";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }
                        }
                    }else{
                        if(sym->type_value == ID){
                            sym->role = "objeto";
                            Symbol *cl = listClass.value(sym->type, nullptr);
                            if(cl != nullptr){
                                if(cl->propertys.size() == 0){
                                    currentEnviroment = new ScopeNode();
                                    currentEnviroment->actuallyClass = cl;
                                    QueueScope.newScope(currentEnviroment);
                                    Recorrer(&cl->instructions);
                                    currentEnviroment = QueueScope.deleteScope();
                                    sym->propertys = CopyHash(cl->propertys);
                                }else{
                                    sym->propertys = CopyHash(cl->propertys);
                                }
                            }
                        }
                        for(int x=0; x<sym->imports.size(); x++){
                            Symbol *newS = new Symbol();
                            newS->access = sym->access;
                            newS->role = sym->role;
                            newS->type = sym->type;
                            newS->propertys = sym->propertys;
                            newS->type_value = sym->type_value;
                            newS->id = sym->imports.at(x);
                            currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                        }
                    }
                }
                break;
                case TIPO:
                {
                    sym->type = node->child.at(0).value.toLower();
                    sym->access = 0;
                    sym->type_value = AsignType(sym->type);
                    NodoAST tmp = node->child.at(1);
                    if(tmp.typeofValue == LIDS){
                        sym->imports = Recorrer(&tmp)->imports;
                    }else{
                        Symbol *listD = Recorrer(&tmp);
                        if(listD->dimension1 == 0 || listD->dimension2 == 0 || listD->dimension3 == 0){
                            QString description = "No se puede asignar 0 a una dimension";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }else{
                            sym->dimension1 = listD->dimension1;
                            sym->dimension2 = listD->dimension2;
                            sym->dimension3 = listD->dimension3;
                        }
                    }
                    if(node->child.size() > 2){
                        if(node->child.at(2).typeofValue == DIMENSION){
                            NodoAST tmp = node->child.at(2);
                            Symbol *listD = Recorrer(&tmp);
                            if(listD->dimension1 == 0 || listD->dimension2 == 0 || listD->dimension3 == 0){
                                QString description = "No se puede asignar 0 a una dimension";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }else{
                                sym->dimension1 = listD->dimension1;
                                sym->dimension2 = listD->dimension2;
                                sym->dimension3 = listD->dimension3;
                                if(node->child.size() > 3){
                                   switch (node->child.at(3).typeofValue) {
                                       case LEXP:
                                       {
                                           NodoAST gg = node->child.at(3);
                                           sym->parameters = Recorrer(&gg)->parameters;
                                           if(sym->parameters.size() <= sym->dimension1){
                                               bool flagError = false;
                                               for(int x=0; x<sym->parameters.size(); x++){
                                                   switch (sym->type_value) {
                                                       case NUMERO:
                                                       {
                                                           switch(sym->parameters.at(x)->type_value){
                                                               case NUMERO:
                                                               {
                                                                  Symbol *arr = new Symbol();
                                                                  arr->i = x;
                                                                  arr->value = sym->parameters.at(x)->value;
                                                                  arr->type_value = NUMERO;
                                                                  sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               case DECIMAL:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   int result = (int)sym->parameters.at(x)->value.toDouble();
                                                                   arr->value = QString::number(result);
                                                                   arr->type_value = NUMERO;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               case CARACTER:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   int result = sym->parameters.at(x)->value[0].toLatin1();
                                                                   arr->value = QString::number(result);
                                                                   arr->type_value = NUMERO;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               case BOOLEAN:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   int result = QVariant(sym->parameters.at(x)->value).toBool();
                                                                   arr->value = QString::number(result);
                                                                   arr->type_value = NUMERO;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               default:
                                                               {
                                                                   QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                               break;
                                                           }
                                                       }
                                                       break;
                                                       case DECIMAL:
                                                       {
                                                           switch (sym->parameters.at(x)->type_value) {
                                                               case NUMERO:
                                                               {
                                                                  Symbol *arr = new Symbol();
                                                                  arr->i = x;
                                                                  double result = sym->parameters.at(x)->value.toInt();
                                                                  arr->value = QString::number(result);
                                                                  arr->type_value = DECIMAL;
                                                                  sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               case DECIMAL:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   arr->value = sym->parameters.at(x)->value;
                                                                   arr->type_value = DECIMAL;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               default:
                                                               {
                                                                   QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                               break;
                                                           }
                                                       }
                                                       break;
                                                       case CADENA:
                                                       {
                                                           switch (sym->parameters.at(x)->type_value) {
                                                               case BOOLEAN:
                                                               {
                                                                   QString description = "No se puede asignar un booleano a una cadena";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                               break;
                                                               case ID:
                                                               {
                                                                   QString description = "No se puede asignar un objeto a una cadena";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                               break;
                                                               default:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   arr->value = sym->parameters.at(x)->value;
                                                                   arr->type_value = CADENA;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                           }
                                                       }
                                                       break;
                                                       case CARACTER:
                                                       {
                                                           switch (sym->parameters.at(x)->type_value) {
                                                               case NUMERO:
                                                               {
                                                                  Symbol *arr = new Symbol();
                                                                  arr->i = x;
                                                                  QChar result = sym->parameters.at(x)->value.toInt();
                                                                  arr->value = result;
                                                                  arr->type_value = CARACTER;
                                                                  sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               case CARACTER:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   arr->value = sym->parameters.at(x)->value;
                                                                   arr->type_value = CARACTER;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               default:
                                                               {
                                                                   QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                               break;
                                                           }
                                                       }
                                                       break;
                                                       case BOOLEAN:
                                                       {
                                                           switch (sym->parameters.at(x)->type_value) {
                                                               case BOOLEAN:
                                                               {
                                                                   Symbol *arr = new Symbol();
                                                                   arr->i = x;
                                                                   arr->value = sym->parameters.at(x)->value;
                                                                   arr->type_value = BOOLEAN;
                                                                   sym->linearize.push_back(arr);
                                                               }
                                                               break;
                                                               case NUMERO:
                                                               {
                                                                   int op = sym->parameters.at(x)->value.toInt();
                                                                   if(op == 1 || op == 0){
                                                                       Symbol *arr = new Symbol();
                                                                       arr->i = x;
                                                                           arr->type_value = BOOLEAN;
                                                                         bool result = QVariant(op).toBool();
                                                                         arr->value = result ? "true" : "false";
                                                                         sym->linearize.push_back(arr);
                                                                   }else{
                                                                       QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                       Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                       semanticError.push_back(error);
                                                                       flagError = true;
                                                                   }
                                                               }
                                                               break;
                                                               default:
                                                               {
                                                                   QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                               break;
                                                           }
                                                       }
                                                       break;
                                                       case ID:
                                                       {
                                                           switch (sym->parameters.at(x)->type_value) {
                                                               case ID:
                                                               {

                                                               }
                                                               break;
                                                               default:
                                                               {

                                                               }
                                                               break;
                                                           }
                                                       }
                                                       break;
                                                   }
                                               }
                                               if(!flagError){
                                                   sym->role = "arreglo";
                                                   for(int i=0; i<sym->imports.size(); i++){
                                                       Symbol *newS = new Symbol();
                                                       newS->access = sym->access;
                                                       newS->id = sym->imports.at(i);
                                                       newS->dimension1 = sym->dimension1;
                                                       newS->dimension2 = sym->dimension2;
                                                       newS->dimension3 = sym->dimension3;
                                                       newS->type_value = sym->type_value;
                                                       newS->role = sym->role;
                                                       newS->linearize = sym->linearize;
                                                       newS->row = sym->row;
                                                       newS->column = sym->column;
                                                       currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                                   }
                                               }
                                           }else{
                                               QString description = "Esta declarando un numero de valores mas grande que el array";
                                               Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                               semanticError.push_back(error);
                                           }
                                       }
                                       break;
                                       case LDIMENSIONESASIG:
                                       {
                                           if(sym->dimension3 != -1){
                                               bool flagError = false;
                                               if(node->child.at(3).child.at(0).typeofValue == LDIMENSIONESASIG){
                                                   for(int i=0; i<node->child.at(3).child.size(); i++){
                                                       NodoAST sia = node->child.at(3).child.at(i);
                                                       for(int y=0; y<sia.child.size(); y++){
                                                           NodoAST tmp = sia.child.at(y);
                                                           Symbol *ju = Recorrer(&tmp);
                                                           for(int x=0; x<ju->parameters.size(); x++){
                                                               if(x < sym->dimension1 && y < sym->dimension2 && i < sym->dimension3){
                                                                   switch (sym->type_value) {
                                                                       case NUMERO:
                                                                       {
                                                                           switch(ju->parameters.at(x)->type_value){
                                                                               case NUMERO:
                                                                               {
                                                                                  Symbol *arr = new Symbol();
                                                                                  arr->i = x;
                                                                                  arr->j = y;
                                                                                  arr->k = i;
                                                                                  arr->value = ju->parameters.at(x)->value;
                                                                                  arr->type_value = NUMERO;
                                                                                  sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               case DECIMAL:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   int result = (int)ju->parameters.at(x)->value.toDouble();
                                                                                   arr->value = QString::number(result);
                                                                                   arr->type_value = NUMERO;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               case CARACTER:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   int result = ju->parameters.at(x)->value[0].toLatin1();
                                                                                   arr->value = QString::number(result);
                                                                                   arr->type_value = NUMERO;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               case BOOLEAN:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   int result = QVariant(ju->parameters.at(x)->value).toBool();
                                                                                   arr->value = QString::number(result);
                                                                                   arr->type_value = NUMERO;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               default:
                                                                               {
                                                                                   QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                   semanticError.push_back(error);
                                                                                   flagError = true;
                                                                               }
                                                                               break;
                                                                           }
                                                                       }
                                                                       break;
                                                                       case DECIMAL:
                                                                       {
                                                                           switch (ju->parameters.at(x)->type_value) {
                                                                               case NUMERO:
                                                                               {
                                                                                  Symbol *arr = new Symbol();
                                                                                  arr->i = x;
                                                                                  arr->j = y;
                                                                                  arr->k = i;
                                                                                  double result = ju->parameters.at(x)->value.toInt();
                                                                                  arr->value = QString::number(result);
                                                                                  arr->type_value = DECIMAL;
                                                                                  sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               case DECIMAL:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   arr->value = ju->parameters.at(x)->value;
                                                                                   arr->type_value = DECIMAL;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               default:
                                                                               {
                                                                                   QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                   semanticError.push_back(error);
                                                                                   flagError = true;
                                                                               }
                                                                               break;
                                                                           }
                                                                       }
                                                                       break;
                                                                       case CADENA:
                                                                       {
                                                                           switch (ju->parameters.at(x)->type_value) {
                                                                               case BOOLEAN:
                                                                               {
                                                                                   QString description = "No se puede asignar un booleano a una cadena";
                                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                   semanticError.push_back(error);
                                                                                   flagError = true;
                                                                               }
                                                                               break;
                                                                               case ID:
                                                                               {
                                                                                   QString description = "No se puede asignar un objeto a una cadena";
                                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                   semanticError.push_back(error);
                                                                                   flagError = true;
                                                                               }
                                                                               break;
                                                                               default:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   arr->value = ju->parameters.at(x)->value;
                                                                                   arr->type_value = CADENA;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                           }
                                                                       }
                                                                       break;
                                                                       case CARACTER:
                                                                       {
                                                                           switch (ju->parameters.at(x)->type_value) {
                                                                               case NUMERO:
                                                                               {
                                                                                  Symbol *arr = new Symbol();
                                                                                  arr->i = x;
                                                                                  arr->j = y;
                                                                                  arr->k = i;
                                                                                  QChar result = ju->parameters.at(x)->value.toInt();
                                                                                  arr->value = result;
                                                                                  arr->type_value = CARACTER;
                                                                                  sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               case CARACTER:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   arr->value = ju->parameters.at(x)->value;
                                                                                   arr->type_value = CARACTER;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               default:
                                                                               {
                                                                                   QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                   semanticError.push_back(error);
                                                                                   flagError = true;
                                                                               }
                                                                               break;
                                                                           }
                                                                       }
                                                                       break;
                                                                       case BOOLEAN:
                                                                       {
                                                                           switch (ju->parameters.at(x)->type_value) {
                                                                               case BOOLEAN:
                                                                               {
                                                                                   Symbol *arr = new Symbol();
                                                                                   arr->i = x;
                                                                                   arr->j = y;
                                                                                   arr->k = i;
                                                                                   arr->value = ju->parameters.at(x)->value;
                                                                                   arr->type_value = BOOLEAN;
                                                                                   sym->linearize.push_back(arr);
                                                                               }
                                                                               break;
                                                                               case NUMERO:
                                                                               {
                                                                                   int op = ju->parameters.at(x)->value.toInt();
                                                                                   if(op == 1 || op == 0){
                                                                                       Symbol *arr = new Symbol();
                                                                                       arr->i = x;
                                                                                       arr->j = y;
                                                                                       arr->k = i;
                                                                                           arr->type_value = BOOLEAN;
                                                                                         bool result = QVariant(op).toBool();
                                                                                         arr->value = result ? "true" : "false";
                                                                                         sym->linearize.push_back(arr);
                                                                                   }else{
                                                                                       QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                                       Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                       semanticError.push_back(error);
                                                                                       flagError = true;
                                                                                   }
                                                                               }
                                                                               break;
                                                                               default:
                                                                               {
                                                                                   QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                                   semanticError.push_back(error);
                                                                                   flagError = true;
                                                                               }
                                                                               break;
                                                                           }
                                                                       }
                                                                       break;
                                                                       case ID:
                                                                       {
                                                                           switch (sym->parameters.at(x)->type_value) {
                                                                               case ID:
                                                                               {

                                                                               }
                                                                               break;
                                                                               default:
                                                                               {

                                                                               }
                                                                               break;
                                                                           }
                                                                       }
                                                                       break;
                                                                   }
                                                               }else{
                                                                   QString description = "Se salio fuera de los limites del array";
                                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                   semanticError.push_back(error);
                                                                   flagError = true;
                                                               }
                                                           }
                                                       }
                                                   }
                                                   if(!flagError){
                                                       sym->role = "arreglo";
                                                       for(int i=0; i<sym->imports.size(); i++){
                                                           Symbol *newS = new Symbol();
                                                           newS->access = sym->access;
                                                           newS->id = sym->imports.at(i);
                                                           newS->dimension1 = sym->dimension1;
                                                           newS->dimension2 = sym->dimension2;
                                                           newS->dimension3 = sym->dimension3;
                                                           newS->type_value = sym->type_value;
                                                           newS->role = sym->role;
                                                           newS->linearize = sym->linearize;
                                                           newS->row = sym->row;
                                                           newS->column = sym->column;
                                                           currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                                       }
                                                   }
                                               }else{
                                                   QString description = "No se puede declarar un array unidimensional o bimensional en uno de 3 dimensiones";
                                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                   semanticError.push_back(error);
                                                   flagError = true;
                                               }
                                           }else{
                                               int county = 0;
                                               bool flagError = false;
                                               for(int i=0; i<node->child.at(3).child.size(); i++){
                                                   NodoAST tmp = node->child.at(3).child.at(i);
                                                   Symbol *ju = Recorrer(&tmp);
                                                   for(int x=0; x<ju->parameters.size(); x++){
                                                       if(x < sym->dimension1 && county < sym->dimension2){
                                                           switch (sym->type_value) {
                                                               case NUMERO:
                                                               {
                                                                   switch(ju->parameters.at(x)->type_value){
                                                                       case NUMERO:
                                                                       {
                                                                          Symbol *arr = new Symbol();
                                                                          arr->i = x;
                                                                          arr->j = county;
                                                                          arr->value = ju->parameters.at(x)->value;
                                                                          arr->type_value = NUMERO;
                                                                          sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       case DECIMAL:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           int result = (int)ju->parameters.at(x)->value.toDouble();
                                                                           arr->value = QString::number(result);
                                                                           arr->type_value = NUMERO;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       case CARACTER:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           int result = ju->parameters.at(x)->value[0].toLatin1();
                                                                           arr->value = QString::number(result);
                                                                           arr->type_value = NUMERO;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       case BOOLEAN:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           int result = QVariant(ju->parameters.at(x)->value).toBool();
                                                                           arr->value = QString::number(result);
                                                                           arr->type_value = NUMERO;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       default:
                                                                       {
                                                                           QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                           semanticError.push_back(error);
                                                                           flagError = true;
                                                                       }
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                               case DECIMAL:
                                                               {
                                                                   switch (ju->parameters.at(x)->type_value) {
                                                                       case NUMERO:
                                                                       {
                                                                          Symbol *arr = new Symbol();
                                                                          arr->i = x;
                                                                          arr->j = county;
                                                                          double result = ju->parameters.at(x)->value.toInt();
                                                                          arr->value = QString::number(result);
                                                                          arr->type_value = DECIMAL;
                                                                          sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       case DECIMAL:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           arr->value = ju->parameters.at(x)->value;
                                                                           arr->type_value = DECIMAL;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       default:
                                                                       {
                                                                           QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                           semanticError.push_back(error);
                                                                           flagError = true;
                                                                       }
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                               case CADENA:
                                                               {
                                                                   switch (ju->parameters.at(x)->type_value) {
                                                                       case BOOLEAN:
                                                                       {
                                                                           QString description = "No se puede asignar un booleano a una cadena";
                                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                           semanticError.push_back(error);
                                                                           flagError = true;
                                                                       }
                                                                       break;
                                                                       case ID:
                                                                       {
                                                                           QString description = "No se puede asignar un objeto a una cadena";
                                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                           semanticError.push_back(error);
                                                                           flagError = true;
                                                                       }
                                                                       break;
                                                                       default:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           arr->value = ju->parameters.at(x)->value;
                                                                           arr->type_value = CADENA;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                               case CARACTER:
                                                               {
                                                                   switch (ju->parameters.at(x)->type_value) {
                                                                       case NUMERO:
                                                                       {
                                                                          Symbol *arr = new Symbol();
                                                                          arr->i = x;
                                                                          arr->j = county;
                                                                          QChar result = ju->parameters.at(x)->value.toInt();
                                                                          arr->value = result;
                                                                          arr->type_value = CARACTER;
                                                                          sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       case CARACTER:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           arr->value = ju->parameters.at(x)->value;
                                                                           arr->type_value = CARACTER;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       default:
                                                                       {
                                                                           QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                           semanticError.push_back(error);
                                                                           flagError = true;
                                                                       }
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                               case BOOLEAN:
                                                               {
                                                                   switch (ju->parameters.at(x)->type_value) {
                                                                       case BOOLEAN:
                                                                       {
                                                                           Symbol *arr = new Symbol();
                                                                           arr->i = x;
                                                                           arr->j = county;
                                                                           arr->value = ju->parameters.at(x)->value;
                                                                           arr->type_value = BOOLEAN;
                                                                           sym->linearize.push_back(arr);
                                                                       }
                                                                       break;
                                                                       case NUMERO:
                                                                       {
                                                                           int op = ju->parameters.at(x)->value.toInt();
                                                                           if(op == 1 || op == 0){
                                                                               Symbol *arr = new Symbol();
                                                                               arr->i = x;
                                                                               arr->j = county;
                                                                                   arr->type_value = BOOLEAN;
                                                                                 bool result = QVariant(op).toBool();
                                                                                 arr->value = result ? "true" : "false";
                                                                                 sym->linearize.push_back(arr);
                                                                           }else{
                                                                               QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                               Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                               semanticError.push_back(error);
                                                                               flagError = true;
                                                                           }
                                                                       }
                                                                       break;
                                                                       default:
                                                                       {
                                                                           QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                           semanticError.push_back(error);
                                                                           flagError = true;
                                                                       }
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                               case ID:
                                                               {
                                                                   switch (sym->parameters.at(x)->type_value) {
                                                                       case ID:
                                                                       {

                                                                       }
                                                                       break;
                                                                       default:
                                                                       {

                                                                       }
                                                                       break;
                                                                   }
                                                               }
                                                               break;
                                                           }
                                                       }else{
                                                           QString description = "Se salio fuera de los limites del array";
                                                           Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                           semanticError.push_back(error);
                                                           flagError = true;
                                                       }
                                                   }
                                                   county++;
                                               }
                                               if(!flagError){
                                                   sym->role = "arreglo";
                                                   for(int i=0; i<sym->imports.size(); i++){
                                                       Symbol *newS = new Symbol();
                                                       newS->access = sym->access;
                                                       newS->id = sym->imports.at(i);
                                                       newS->dimension1 = sym->dimension1;
                                                       newS->dimension2 = sym->dimension2;
                                                       newS->dimension3 = sym->dimension3;
                                                       newS->type_value = sym->type_value;
                                                       newS->role = sym->role;
                                                       newS->linearize = sym->linearize;
                                                       newS->row = sym->row;
                                                       newS->column = sym->column;
                                                       currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                                   }
                                               }
                                           }
                                       }
                                       break;
                                   }
                                }else{
                                    sym->role = "arreglo";
                                    for(int i=0; i<sym->imports.size(); i++){
                                       Symbol *newS = new Symbol();
                                       newS->access = sym->access;
                                       newS->id = sym->imports.at(i);
                                       newS->dimension1 = sym->dimension1;
                                       newS->dimension2 = sym->dimension2;
                                       newS->dimension3 = sym->dimension3;
                                       newS->type_value = sym->type_value;
                                       newS->role = sym->role;
                                       newS->row = sym->row;
                                       newS->column = sym->column;
                                       currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                                    }
                                }
                            }
                        }else if(node->child.at(2).typeofValue == FUNCIONES){
                            NodoAST fun = node->child.at(2);
                            sym->role = "funcion";
                            if(fun.child.size() == 1){
                                switch (fun.child.at(0).typeofValue) {
                                    case LSENTENCIAS:
                                    {
                                        sym->instructions = fun.child.at(0);
                                        sym->id = sym->imports.at(0);
                                    }
                                    break;
                                    case LTIPOS:
                                    {
                                        NodoAST tmp = fun.child.at(0);
                                        Symbol *list = Recorrer(&tmp);
                                        sym->parameters = list->parameters;
                                        sym->id = sym->imports.at(0);
                                    }
                                    break;
                                }
                            }else if(fun.child.size() == 2){
                                NodoAST tmp = fun.child.at(0);
                                Symbol *list = Recorrer(&tmp);
                                sym->parameters = list->parameters;
                                sym->id = sym->imports.at(0);
                                sym->instructions = fun.child.at(1);
                            }
                            currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
                        }else if(node->child.at(2).typeofValue == EXPRESION){
                            NodoAST tmp = node->child.at(2);
                            Symbol *ss = Recorrer(&tmp);
                            if(sym->type == "entero"){
                                switch(ss->type_value){
                                    case NUMERO:
                                    {
                                        sym->type_value = NUMERO;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        sym->type_value = NUMERO;
                                        int result = (int)ss->value.toDouble();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        sym->type_value = NUMERO;
                                        int result = ss->value[0].toLatin1();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        sym->type_value = NUMERO;
                                        int result = QVariant(ss->value).toBool();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo entero";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }else if(sym->type == "doble"){
                                switch(ss->type_value){
                                    case NUMERO:
                                    {
                                        sym->type_value = DECIMAL;
                                        double result = ss->value.toInt();
                                        sym->value = QString::number(result);
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        sym->type_value = DECIMAL;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        QString description = "No se puede asignar un caracter a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        QString description = "No se puede asignar un booleano a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            else if(sym->type == "cadena"){
                                sym->type_value = CADENA;
                                sym->value = ss->value;
                            }else if(sym->type == "caracter"){
                                switch(ss->type_value){
                                    case NUMERO:
                                    {
                                        sym->type_value = CARACTER;
                                        QChar result = ss->value.toInt();
                                        sym->value = result;
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        sym->type_value = CARACTER;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        QString description = "No se puede asignar un doble a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        QString description = "No se puede asignar un booleano a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }else if(sym->type == "booleano"){
                                switch (ss->type_value) {
                                    case BOOLEAN:
                                    {
                                        sym->type_value = BOOLEAN;
                                        sym->value = ss->value;
                                    }
                                    break;
                                    case NUMERO:
                                    {
                                        int op = ss->value.toInt();
                                        if(op == 1 || op == 0){
                                                sym->type_value = BOOLEAN;
                                              bool result = QVariant(op).toBool();
                                              sym->value = result ? "true" : "false";
                                        }else{
                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        QString description = "No se puede asignar un doble a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        QString description = "No se puede asignar un caracter a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            for(int x=0; x<sym->imports.size(); x++){
                                Symbol *newS = new Symbol();
                                newS->access = sym->access;
                                newS->type = sym->type;
                                newS->role = sym->role;
                                newS->parameters = sym->parameters;
                                newS->type_value = sym->type_value;
                                newS->id = sym->imports.at(x);
                                newS->value = sym->value;
                                currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                            }
                        }else if(node->child.at(2).typeofValue == OBJETO){
                            if(node->child.at(2).child.size() == 1){
                                    sym->role = "objeto";
                                    Symbol *cl = listClass.value(sym->type, nullptr);
                                    if(cl != nullptr){
                                        if(cl->propertys.size() == 0){
                                            currentEnviroment = new ScopeNode();
                                            currentEnviroment->actuallyClass = cl;
                                            QueueScope.newScope(currentEnviroment);
                                            Recorrer(&cl->instructions);
                                            currentEnviroment = QueueScope.deleteScope();
                                            sym->propertys = CopyHash(cl->propertys);
                                        }else{
                                            sym->propertys = CopyHash(cl->propertys);
                                        }
                                    }
                                    sym->id = sym->imports.at(0);
                                    currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
                            }else if(node->child.at(2).child.size() == 2){
                                NodoAST tmp = node->child.at(2).child.at(1);
                                Symbol *op = Recorrer(&tmp);
                                if(op->type_value == CADENA && op->value != ""){
                                    sym->path = op->value.toLower();
                                    sym->role = "objeto";
                                    if(!sym->path.contains(".der")){
                                        sym->path = sym->path + ".der";
                                    }
                                    sym->id = sym->imports.at(0);
                                    currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
                                }else{
                                    QString description = "Al declarar una variable archivo se espera una cadena con el nombre";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }
                        }
                    }else{
                        if(sym->type_value == ID){
                            sym->role = "objeto";
                            Symbol *cl = listClass.value(sym->type, nullptr);
                            if(cl != nullptr){
                                if(cl->propertys.size() == 0){
                                    currentEnviroment = new ScopeNode();
                                    currentEnviroment->actuallyClass = cl;
                                    QueueScope.newScope(currentEnviroment);
                                    Recorrer(&cl->instructions);
                                    currentEnviroment = QueueScope.deleteScope();
                                    sym->propertys = CopyHash(cl->propertys);
                                }else{
                                    sym->propertys = CopyHash(cl->propertys);
                                }
                            }
                        }
                        for(int x=0; x<sym->imports.size(); x++){
                            Symbol *newS = new Symbol();
                            newS->access = sym->access;
                            newS->type = sym->type;
                            newS->propertys = sym->propertys;
                            newS->type_value = sym->type_value;
                            newS->id = sym->imports.at(x);
                            currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                        }
                    }
                }
                break;
            }
        }
        break;
        case EXPRESION:
        {
            NodoAST tmp = node->child.at(0);
            sym = Recorrer(&tmp);
        }
        break;
        case OR:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch(op1->type_value){
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() || QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "Para efectuar un or ambos operadores deber ser booleanos";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "Para efectuar un or ambos operadores deber ser booleanos";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case NOR:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = !(QVariant(op1->value).toBool() || QVariant(op2->value).toBool());
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "Para efectuar un nor ambos operadores deber ser booleanos";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "Para efectuar un nor ambos operadores deber ser booleanos";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case AND:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() && QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "Para efectuar un and ambos operadores deber ser booleanos";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "Para efectuar un and ambos operadores deber ser booleanos";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case NAND:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = !(QVariant(op1->value).toBool() && QVariant(op2->value).toBool());
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "Para efectuar un nand ambos operadores deber ser booleanos";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "Para efectuar un nand ambos operadores deber ser booleanos";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case NOT:
        {
            NodoAST der = node->child.at(1);
            Symbol *op1 = Recorrer(&der);
            switch (op1->type_value) {
                case BOOLEAN:
                {
                    sym->type_value = BOOLEAN;
                    bool result = !(QVariant(op1->value).toBool());
                    sym->value = result ? "true" : "false";
                }
                break;
                default:
                {
                    QString description = "Para efectuar un not se debe operar un booleano";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case IGUAL_IGUAL:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value == op2->value;
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar una cadena a otro tipo que no sea cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() == op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() == op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() == QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() == op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() == op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() == op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() == QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() == op2->value[0].toLatin1();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() == op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() == op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() == QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un booleano con una cadena o caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] == op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0].toLatin1() == op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] == op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un caracter con una cadena o booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case DIFERENTE_DE:
            {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value != op2->value;
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar una cadena a otro tipo que no sea cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() != op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() != op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() != QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() != op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() != op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() != op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() != QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() != op2->value[0].toLatin1();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() != op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() != op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() != QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un booleano con una cadena o caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] != op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0].toLatin1() != op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] != op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un caracter con una cadena o booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case MENOR_QUE:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value < op2->value;
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar una cadena a otro tipo que no sea cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() < op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() < op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() < QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() < op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() < op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() < op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() < QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() < op2->value[0].toLatin1();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() < op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() < op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() < QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un booleano con una cadena o caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] < op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0].toLatin1() < op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] < op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un caracter con una cadena o booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case MAYOR_QUE:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value > op2->value;
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar una cadena a otro tipo que no sea cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() > op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() > op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() > QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() > op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() > op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() > op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() > QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() > op2->value[0].toLatin1();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() > op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() > op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() > QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un booleano con una cadena o caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] > op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0].toLatin1() > op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] > op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un caracter con una cadena o booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case MENORIGUAL_QUE:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value <= op2->value;
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar una cadena a otro tipo que no sea cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() <= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() <= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() <= QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() <= op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() <= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() <= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() <= QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() <= op2->value[0].toLatin1();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() <= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() <= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() <= QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un booleano con una cadena o caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] <= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0].toLatin1() <= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] <= op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un caracter con una cadena o booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case MAYORIGUAL_QUE:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch (op1->type_value) {
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value >= op2->value;
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar una cadena a otro tipo que no sea cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() >= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() >= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() >= QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toInt() >= op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() >= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() >= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() >= QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value.toDouble() >= op2->value[0].toLatin1();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() >= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() >= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() >= QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un booleano con una cadena o caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] >= op2->value.toInt();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0].toLatin1() >= op2->value.toDouble();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = op1->value[0] >= op2->value[0];
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede comparar un caracter con una cadena o booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case SUMA:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch(op1->type_value){
                case CADENA:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        case NUMERO:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede sumar un booleano con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case NUMERO:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() + op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() + op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() + op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            int result = op1->value.toInt() + QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        case NUMERO:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() + op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() + op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() + op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() + QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch (op2->type_value) {
                        case CADENA:
                        {
                            sym->type_value = CADENA;
                            sym->value = op1->value + op2->value;
                        }
                        break;
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() + op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value[0].toLatin1() + op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() + op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() + QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = QVariant(op1->value).toBool() + op2->value.toInt();
                            sym->value = QString(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = QVariant(op1->value).toBool() + op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = QVariant(op1->value).toBool() + op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() || QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede sumar un booleano con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
        case RESTA:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch(op1->type_value){
                case NUMERO:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() - op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() - op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() - op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() - QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede restar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() - op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() - op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() - op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() - QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede restar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() - op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value[0].toLatin1() - op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() - op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede restar un caracter con una cadena o con un booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = QVariant(op1->value).toBool() - op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = QVariant(op1->value).toBool() - op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede restar un booleano con una cadena, con un booleano o un caracter";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "No se puede restar con una cadena o cualquier tipo";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case MULTI:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch(op1->type_value){
                case NUMERO:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() * op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() * op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() * op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value.toInt() * QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede multiplicar un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() * op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() * op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() * op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value.toDouble() * QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede multiplicar un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() * op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = op1->value[0].toLatin1() * op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() * op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = NUMERO;
                            int result = op1->value[0].toLatin1() * QVariant(op2->value).toBool();
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede multilicar un caracter con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = QVariant(op1->value).toBool() * op2->value.toInt();
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = QVariant(op1->value).toBool() * op2->value.toDouble();
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = QVariant(op1->value).toBool() * op2->value[0].toLatin1();
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = BOOLEAN;
                            bool result = QVariant(op1->value).toBool() && QVariant(op2->value).toBool();
                            sym->value = result ? "true" : "false";
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede multiplicar un booleano con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "No se puede multiplicar con una cadena a cualquier tipo";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case DIVISION:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch(op1->type_value){
                case NUMERO:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            if(op2->value.toInt() != 0){
                                 sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case DECIMAL:
                        {
                            if(op2->value.toDouble() != 0.0){
                                sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case CARACTER:
                        {
                            if(op2->value[0].toLatin1() != 0){
                                sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / op2->value[0].toLatin1();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case BOOLEAN:
                        {
                            if(QVariant(op2->value).toBool() != 0){
                                sym->type_value = NUMERO;
                                int result = op1->value.toInt() / QVariant(op2->value).toBool();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir un dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede dividir un entero con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            if(op2->value.toInt() != 0){
                                 sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case DECIMAL:
                        {
                            if(op2->value.toDouble() != 0.0){
                                 sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case CARACTER:
                        {
                            if(op2->value[0].toLatin1() != 0){
                                sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / op2->value[0].toLatin1();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case BOOLEAN:
                        {
                            if(QVariant(op2->value).toBool() != 0){
                                sym->type_value = DECIMAL;
                                double result = op1->value.toDouble() / QVariant(op2->value).toBool();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede dividir un decimal con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            if(op2->value.toInt() != 0){
                                sym->type_value = DECIMAL;
                                double result = op1->value[0].toLatin1() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case DECIMAL:
                        {
                            if(op2->value.toDouble() != 0.0){
                                sym->type_value = DECIMAL;
                                double result = op1->value[0].toLatin1() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case CARACTER:
                        {
                            if(op2->value[0].toLatin1() != 0){
                                sym->type_value = DECIMAL;
                                double result = op1->value[0].toLatin1() / op2->value[0].toLatin1();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case BOOLEAN:
                        {
                            if(QVariant(op2->value).toBool() != 0){
                                sym->type_value = NUMERO;
                                double result = op1->value[0].toLatin1() / QVariant(op2->value).toBool();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede dividir un caracter con una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            if(op2->value.toInt() != 0){
                                sym->type_value = DECIMAL;
                                double result = QVariant(op1->value).toBool() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case DECIMAL:
                        {
                            if(op2->value.toDouble() != 0.0){
                                sym->type_value = DECIMAL;
                                double result = QVariant(op1->value).toBool() / op2->value.toDouble();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        case CARACTER:
                        {
                            if(op2->value[0].toLatin1() != 0){
                                sym->type_value = DECIMAL;
                                double result = QVariant(op1->value).toBool() / op2->value[0].toLatin1();
                                sym->value = QString::number(result);
                            }else{
                                QString description = "No se puede dividir dentro de 0";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede dividir un booleano con una cadena o con un booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "No se puede dividir con una cadena a cualquier tipo";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case POTENCIA:
        {
            NodoAST izq = node->child.at(0);
            Symbol *op1 = Recorrer(&izq);
            NodoAST der = node->child.at(1);
            Symbol *op2 = Recorrer(&der);
            switch(op1->type_value){
                case NUMERO:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(op1->value.toInt(), op2->value.toInt());
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(op1->value.toDouble(), op2->value.toDouble());
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(op1->value.toInt(), op2->value[0].toLatin1());
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(op1->value.toInt(), QVariant(op2->value).toBool());
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede elevar un entero a una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case DECIMAL:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(op1->value.toDouble(), op2->value.toDouble());
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(op1->value.toDouble(), op2->value.toDouble());
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(op1->value.toDouble(), op2->value[0].toLatin1());
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(op1->value.toDouble(), QVariant(op2->value).toBool());
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede elevar un decimal a una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case CARACTER:
                {
                    switch(op2->type_value){
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(op1->value[0].toLatin1(), op2->value.toInt());
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(op1->value[0].toLatin1(), op2->value.toDouble());
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(op1->value[0].toLatin1(), op2->value[0].toLatin1());
                            sym->value = QString::number(result);
                        }
                        break;
                        case BOOLEAN:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(op1->value[0].toLatin1(), QVariant(op2->value).toBool());
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede elevar un caracter a una cadena";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                case BOOLEAN:
                {
                    switch (op2->type_value) {
                        case NUMERO:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(QVariant(op1->value).toBool(), op2->value.toInt());
                            sym->value = QString::number(result);
                        }
                        break;
                        case DECIMAL:
                        {
                            sym->type_value = DECIMAL;
                            double result = pow(QVariant(op1->value).toBool(), op2->value.toDouble());
                            sym->value = QString::number(result);
                        }
                        break;
                        case CARACTER:
                        {
                            sym->type_value = NUMERO;
                            int result = (int)pow(QVariant(op1->value).toBool(), op2->value[0].toLatin1());
                            sym->value = QString::number(result);
                        }
                        break;
                        default:
                        {
                            QString description = "No se puede wlwvar un booleano con una cadena u otro booleano";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                        break;
                    }
                }
                break;
                default:
                {
                    QString description = "No se puede elevar una cadena a cualquier tipo";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case NUMERO:
        {
            sym->type_value = NUMERO;
            sym->value = node->value;
        }
        break;
        case CADENA:
        {
            sym->type_value = CADENA;
            node->value.replace(0,1,"");
            node->value.replace(node->value.length()-1,1,"");
            sym->value = node->value;
        }
        break;
        case DECIMAL:
        {
            sym->type_value = DECIMAL;
            sym->value = node->value;
        }
        break;
        case CARACTER:
        {
            sym->type_value = CARACTER;
            sym->value = node->value.replace("'", "");
        }
        break;
        case BOOLEAN:
        {
            if(node->value.toLower() == "falso"){
                node->value = "false";
            }else if(node->value.toLower() == "verdadero"){
                node->value = "true";
            }
            sym->type_value = BOOLEAN;
            sym->value = node->value;
        }
        break;
        case ID:
        {
            QString id = node->value.toLower();
            Symbol *ss = SearchidScope(id);
            if(ss != nullptr){
                sym = ss;
            }else{
                QString description = "No existe la variable " + id;
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case ARREGLO:
        {
             QString id = node->child.at(0).value.toLower();
             Symbol *ss = SearchidScope(id);
             if(ss != nullptr && ss->role == "arreglo"){
                NodoAST tmp = node->child.at(1);
                Symbol *lD = Recorrer(&tmp);
                if(ss->dimension3 != -1){
                    if(lD->dimension1 < ss->dimension1 && lD->dimension2 < ss->dimension2 && lD->dimension3 < ss->dimension3){
                        QLinkedList<Symbol*>::iterator it;
                        for(it = ss->linearize.begin(); it != ss->linearize.end(); ++it){
                            if((*it)->i == lD->dimension3 && (*it)->j == lD->dimension2 && (*it)->k == lD->dimension1){
                                sym->type_value = (*it)->type_value;
                                sym->value = (*it)->value;
                                break;
                            }
                        }
                    }else{
                        QString description = "La asignacion se sale de los limites del array de " + ss->id;
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }else if(ss->dimension2 != -1){
                    if(lD->dimension3 == -1){
                        if(lD->dimension1 < ss->dimension1 && lD->dimension2 < ss->dimension2){
                            QLinkedList<Symbol*>::iterator it;
                            for(it = ss->linearize.begin(); it != ss->linearize.end(); ++it){
                                if((*it)->i == lD->dimension2 && (*it)->j == lD->dimension1){
                                    sym->type_value = (*it)->type_value;
                                    sym->value = (*it)->value;
                                    break;
                                }
                            }
                        }else{
                            QString description = "La asignacion se sale de los limites del array de " + ss->id;
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                    }else{
                        QString description = "Se le estan haciendo referencia a mas dimensiones que las que puede la variable " + ss->id;
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }else{
                    if(lD->dimension2 == -1 && lD->dimension3 == -1){
                        if(lD->dimension1 < ss->dimension1){
                            QLinkedList<Symbol*>::iterator it;
                            for(it = ss->linearize.begin(); it != ss->linearize.end(); ++it){
                                if((*it)->i == lD->dimension1){
                                    sym->type_value = (*it)->type_value;
                                    sym->value = (*it)->value;
                                    break;
                                }
                            }
                        }else{
                            QString description = "La asignacion se sale de los limites del array de " + ss->id;
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                    }else{
                        QString description = "Se le estan haciendo referencia a mas dimensiones que las que puede la variable " + ss->id;
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }
             }else{
                 QString description = "No existe la variable " + id;
                 Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                 semanticError.push_back(error);
             }
        }
        break;
        case ASIGNACION:
        {
            QString id = node->child.at(0).value.toLower();
            Symbol *ss = SearchidScope(id);
            if(ss != nullptr){
                switch (node->child.at(1).typeofValue) {
                    case EXPRESION:
                    {
                        NodoAST tmp = node->child.at(1);
                        Symbol *exp = Recorrer(&tmp);
                        switch (ss->type_value) {
                            case CADENA:
                            {
                                ss->value = exp->value;
                            }
                            break;
                            case NUMERO:
                            {
                                switch(exp->type_value){
                                    case NUMERO:
                                    {
                                        ss->value = exp->value;
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        int result = (int)exp->value.toDouble();
                                        ss->value = QString::number(result);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        int result = exp->value[0].toLatin1();
                                        ss->value = QString::number(result);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        int result = QVariant(exp->value).toBool();
                                        ss->value = QString::number(result);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo entero";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            break;
                            case DECIMAL:
                            {
                                switch(exp->type_value){
                                    case NUMERO:
                                    {
                                        double result = exp->value.toInt();
                                        ss->value = QString::number(result);
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        ss->value = exp->value;
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        QString description = "No se puede asignar un caracter a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        QString description = "No se puede asignar un booleano a un tipo doble";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            break;
                            case CARACTER:
                            {
                                switch(exp->type_value){
                                    case NUMERO:
                                    {
                                        QChar result = exp->value.toInt();
                                        ss->value = result;
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        ss->value = exp->value;
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        QString description = "No se puede asignar un doble a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case BOOLEAN:
                                    {
                                        QString description = "No se puede asignar un booleano a un tipo caracter";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            break;
                            case BOOLEAN:
                            {
                                switch (exp->type_value) {
                                    case BOOLEAN:
                                    {
                                        ss->value = exp->value;
                                    }
                                    break;
                                    case NUMERO:
                                    {
                                        int op = exp->value.toInt();
                                        if(op == 1 || op == 0){
                                              bool result = QVariant(op).toBool();
                                              ss->value = result ? "true" : "false";
                                        }else{
                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                    }
                                    break;
                                    case DECIMAL:
                                    {
                                        QString description = "No se puede asignar un doble a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CADENA:
                                    {
                                        QString description = "No se puede asignar una cadena a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                    case CARACTER:
                                    {
                                        QString description = "No se puede asignar un caracter a un tipo booleano";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    break;
                    case DIMENSION:
                    {
                        NodoAST tmp = node->child.at(1);
                        Symbol *op = Recorrer(&tmp);
                        NodoAST val = node->child.at(2);
                        sym = Recorrer(&val);
                        Symbol *inArr = nullptr;
                        if(ss->dimension3 != -1){
                            if(op->dimension1 < ss->dimension1 && op->dimension2 < ss->dimension2 && op->dimension3 < ss->dimension3){
                                QLinkedList<Symbol*>::iterator it;
                                for(it = ss->linearize.begin(); it != ss->linearize.end(); ++it){
                                    if((*it)->i == op->dimension3 && (*it)->j == op->dimension2 && (*it)->k == op->dimension1){
                                        inArr = (*it);
                                        break;
                                    }
                                }
                                if(inArr != nullptr){
                                    switch (ss->type_value) {
                                        case NUMERO:
                                        {
                                            switch(sym->type_value){
                                                case NUMERO:
                                                {
                                                   inArr->value = sym->value;
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    int result = sym->value.toDouble();
                                                    inArr->value = QString::number(result);
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    int result = sym->value[0].toLatin1();
                                                    inArr->value = QString::number(result);
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    int result = QVariant(sym->value).toBool();
                                                    inArr->value = QString::number(result);
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar un objeto o cadena a un entero";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case DECIMAL:
                                        {
                                            switch (sym->type_value) {
                                                case NUMERO:
                                                {
                                                   double result = sym->value.toInt();
                                                   inArr->value = QString::number(result);
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    inArr->value = sym->value;
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case CADENA:
                                        {
                                            switch (sym->type_value) {
                                                case BOOLEAN:
                                                {
                                                    QString description = "No se puede asignar un booleano a una cadena";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case ID:
                                                {
                                                    QString description = "No se puede asignar un objeto a una cadena";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                default:
                                                {
                                                    inArr->value = sym->value;
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case CARACTER:
                                        {
                                            switch (sym->type_value) {
                                                case NUMERO:
                                                {
                                                   QChar result = sym->value.toInt();
                                                   inArr->value = result;
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    inArr->value = sym->value;
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case BOOLEAN:
                                        {
                                            switch (sym->type_value) {
                                                case BOOLEAN:
                                                {
                                                    inArr->value = sym->value;
                                                }
                                                break;
                                                case NUMERO:
                                                {
                                                    int ae = sym->value.toInt();
                                                    if(ae == 1 || ae == 0){
                                                          bool result = QVariant(ae).toBool();
                                                          inArr->value = result ? "true" : "false";
                                                    }else{
                                                        QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case ID:
                                        {
                                            switch (sym->type_value) {
                                                case ID:
                                                {

                                                }
                                                break;
                                                default:
                                                {

                                                }
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }else{
                                    inArr = new Symbol();
                                    switch (ss->type_value) {
                                        case NUMERO:
                                        {
                                            switch(sym->type_value){
                                                case NUMERO:
                                                {
                                                   inArr->type_value = sym->type_value;
                                                   inArr->i = op->dimension3;
                                                   inArr->j = op->dimension2;
                                                   inArr->k = op->dimension1;
                                                   inArr->value = sym->value;
                                                   ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    int result = sym->value.toDouble();
                                                    inArr->value = QString::number(result);
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    int result = sym->value[0].toLatin1();
                                                    inArr->value = QString::number(result);
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    int result = QVariant(sym->value).toBool();
                                                    inArr->value = QString::number(result);
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar un objeto o cadena a un entero";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case DECIMAL:
                                        {
                                            switch (sym->type_value) {
                                                case NUMERO:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                   double result = sym->value.toInt();
                                                   inArr->value = QString::number(result);
                                                   ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    inArr->value = sym->value;
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case CADENA:
                                        {
                                            switch (sym->type_value) {
                                                case BOOLEAN:
                                                {
                                                    QString description = "No se puede asignar un booleano a una cadena";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case ID:
                                                {
                                                    QString description = "No se puede asignar un objeto a una cadena";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                default:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    inArr->value = sym->value;
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case CARACTER:
                                        {
                                            switch (sym->type_value) {
                                                case NUMERO:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                   QChar result = sym->value.toInt();
                                                   inArr->value = result;
                                                   ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    inArr->value = sym->value;
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case BOOLEAN:
                                        {
                                            switch (sym->type_value) {
                                                case BOOLEAN:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    inArr->value = sym->value;
                                                    ss->linearize.push_back(inArr);
                                                }
                                                break;
                                                case NUMERO:
                                                {
                                                    inArr->type_value = sym->type_value;
                                                    inArr->i = op->dimension3;
                                                    inArr->j = op->dimension2;
                                                    inArr->k = op->dimension1;
                                                    int ae = sym->value.toInt();
                                                    if(ae == 1 || ae == 0){
                                                          bool result = QVariant(ae).toBool();
                                                          inArr->value = result ? "true" : "false";
                                                          ss->linearize.push_back(inArr);
                                                    }else{
                                                        QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                }
                                                break;
                                                default:
                                                {
                                                    QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case ID:
                                        {
                                            switch (sym->type_value) {
                                                case ID:
                                                {

                                                }
                                                break;
                                                default:
                                                {

                                                }
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }
                            }else{
                                QString description = "La asignacion se sale de los limites del array de " + ss->id;
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else if(ss->dimension2 != -1){
                            if(op->dimension3 == -1){
                                if(op->dimension1 < ss->dimension1 && op->dimension2 < ss->dimension2){
                                    QLinkedList<Symbol*>::iterator it;
                                    for(it = ss->linearize.begin(); it != ss->linearize.end(); ++it){
                                        if((*it)->i == op->dimension2 && (*it)->j == op->dimension1){
                                            inArr = (*it);
                                            break;
                                        }
                                    }
                                    if(inArr != nullptr){
                                        switch (ss->type_value) {
                                            case NUMERO:
                                            {
                                                switch(sym->type_value){
                                                    case NUMERO:
                                                    {
                                                       inArr->value = sym->value;
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        int result = sym->value.toDouble();
                                                        inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        int result = sym->value[0].toLatin1();
                                                        inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        int result = QVariant(sym->value).toBool();
                                                        inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar un objeto o cadena a un entero";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case DECIMAL:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                       double result = sym->value.toInt();
                                                       inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CADENA:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        QString description = "No se puede asignar un booleano a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        QString description = "No se puede asignar un objeto a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CARACTER:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                       QChar result = sym->value.toInt();
                                                       inArr->value = result;
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case BOOLEAN:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                    case NUMERO:
                                                    {
                                                        int ae = sym->value.toInt();
                                                        if(ae == 1 || ae == 0){
                                                              bool result = QVariant(ae).toBool();
                                                              inArr->value = result ? "true" : "false";
                                                        }else{
                                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case ID:
                                            {
                                                switch (sym->type_value) {
                                                    case ID:
                                                    {

                                                    }
                                                    break;
                                                    default:
                                                    {

                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }else{
                                        inArr = new Symbol();
                                        switch (ss->type_value) {
                                            case NUMERO:
                                            {
                                                switch(sym->type_value){
                                                    case NUMERO:
                                                    {
                                                       inArr->type_value = sym->type_value;
                                                       inArr->i = op->dimension2;
                                                       inArr->j = op->dimension1;
                                                       inArr->value = sym->value;
                                                       ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        int result = sym->value.toDouble();
                                                        inArr->value = QString::number(result);
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        int result = sym->value[0].toLatin1();
                                                        inArr->value = QString::number(result);
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        int result = QVariant(sym->value).toBool();
                                                        inArr->value = QString::number(result);
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar un objeto o cadena a un entero";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case DECIMAL:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                       double result = sym->value.toInt();
                                                       inArr->value = QString::number(result);
                                                       ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CADENA:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        QString description = "No se puede asignar un booleano a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        QString description = "No se puede asignar un objeto a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CARACTER:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                       QChar result = sym->value.toInt();
                                                       inArr->value = result;
                                                       ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case BOOLEAN:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case NUMERO:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension2;
                                                        inArr->j = op->dimension1;
                                                        int ae = sym->value.toInt();
                                                        if(ae == 1 || ae == 0){
                                                              bool result = QVariant(ae).toBool();
                                                              inArr->value = result ? "true" : "false";
                                                              ss->linearize.push_back(inArr);
                                                        }else{
                                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case ID:
                                            {
                                                switch (sym->type_value) {
                                                    case ID:
                                                    {

                                                    }
                                                    break;
                                                    default:
                                                    {

                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                }else{
                                    QString description = "La asignacion se sale de los limites del array de " + ss->id;
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "Se le estan haciendo referencia a mas dimensiones que las que puede la variable " + ss->id;
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else{
                            if(op->dimension2 == -1 && op->dimension3 == -1){
                                if(op->dimension1 < ss->dimension1){
                                    QLinkedList<Symbol*>::iterator it;
                                    for(it = ss->linearize.begin(); it != ss->linearize.end(); ++it){
                                        if((*it)->i == op->dimension1){
                                            inArr = (*it);
                                            break;
                                        }
                                    }
                                    if(inArr != nullptr){
                                        switch (ss->type_value) {
                                            case NUMERO:
                                            {
                                                switch(sym->type_value){
                                                    case NUMERO:
                                                    {
                                                       inArr->value = sym->value;
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        int result = sym->value.toDouble();
                                                        inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        int result = sym->value[0].toLatin1();
                                                        inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        int result = QVariant(sym->value).toBool();
                                                        inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar un objeto o cadena a un entero";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case DECIMAL:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                       double result = sym->value.toInt();
                                                       inArr->value = QString::number(result);
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CADENA:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        QString description = "No se puede asignar un booleano a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        QString description = "No se puede asignar un objeto a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CARACTER:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                       QChar result = sym->value.toInt();
                                                       inArr->value = result;
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case BOOLEAN:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        inArr->value = sym->value;
                                                    }
                                                    break;
                                                    case NUMERO:
                                                    {
                                                        int ae = sym->value.toInt();
                                                        if(ae == 1 || ae == 0){
                                                              bool result = QVariant(ae).toBool();
                                                              inArr->value = result ? "true" : "false";
                                                        }else{
                                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case ID:
                                            {
                                                switch (sym->type_value) {
                                                    case ID:
                                                    {

                                                    }
                                                    break;
                                                    default:
                                                    {

                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }else{
                                        inArr = new Symbol();
                                        switch (ss->type_value) {
                                            case NUMERO:
                                            {
                                                switch(sym->type_value){
                                                    case NUMERO:
                                                    {
                                                       inArr->type_value = sym->type_value;
                                                       inArr->i = op->dimension1;
                                                       inArr->value = sym->value;
                                                       ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        int result = sym->value.toDouble();
                                                        inArr->value = QString::number(result);
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        int result = sym->value[0].toLatin1();
                                                        inArr->value = QString::number(result);
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        int result = QVariant(sym->value).toBool();
                                                        inArr->value = QString::number(result);
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar un objeto o cadena a un entero";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case DECIMAL:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                       double result = sym->value.toInt();
                                                       inArr->value = QString::number(result);
                                                       ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CADENA:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        QString description = "No se puede asignar un booleano a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        QString description = "No se puede asignar un objeto a una cadena";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case CARACTER:
                                            {
                                                switch (sym->type_value) {
                                                    case NUMERO:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                       QChar result = sym->value.toInt();
                                                       inArr->value = result;
                                                       ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case BOOLEAN:
                                            {
                                                switch (sym->type_value) {
                                                    case BOOLEAN:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        inArr->value = sym->value;
                                                        ss->linearize.push_back(inArr);
                                                    }
                                                    break;
                                                    case NUMERO:
                                                    {
                                                        inArr->type_value = sym->type_value;
                                                        inArr->i = op->dimension1;
                                                        int ae = sym->value.toInt();
                                                        if(ae == 1 || ae == 0){
                                                              bool result = QVariant(ae).toBool();
                                                              inArr->value = result ? "true" : "false";
                                                              ss->linearize.push_back(inArr);
                                                        }else{
                                                            QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                    }
                                                    break;
                                                    default:
                                                    {
                                                        QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                            case ID:
                                            {
                                                switch (sym->type_value) {
                                                    case ID:
                                                    {

                                                    }
                                                    break;
                                                    default:
                                                    {

                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                }else{
                                    QString description = "La asignacion se sale de los limites del array de " + ss->id;
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "Se le estan haciendo referencia amas dimensiones que las que podee la variable " + ss->id;
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                    }
                    break;
                    case OBJETO:
                    {
                        if(node->child.at(1).child.size() == 1){

                        }else if(node->child.at(1).child.size() == 2){
                            if(node->child.at(1).child.at(0).value.toLower() == "creararchivoder"){
                                if(ss->type_value == ARCHIVO){
                                    NodoAST tmp = node->child.at(1).child.at(1);
                                    sym = Recorrer(&tmp);
                                    if(sym->type_value == CADENA){
                                        ss->path = sym->value.toLower();
                                        ss->role = "objeto";
                                        if(!ss->path.contains(".der")){
                                            ss->path = ss->path + ".der";
                                        }
                                    }else{
                                        QString description = "Al declarar una variable archivo se espera una cadena con el nombre";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                }else{
                                    QString description = "No se puede declarar un archivo en una variable no tipo archivo";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                Symbol *objL = ss->propertys.value(node->child.at(1).child.at(0).value.toLower(), nullptr);
                                if(objL != nullptr){
                                    NodoAST tmp = node->child.at(1).child.at(1);
                                    sym = Recorrer(&tmp);
                                    switch (objL->type_value) {
                                        case CADENA:
                                        {
                                            objL->value = sym->value;
                                        }
                                        break;
                                        case NUMERO:
                                        {
                                            switch(sym->type_value){
                                                case NUMERO:
                                                {
                                                    objL->value = sym->value;
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    int result = (int)sym->value.toDouble();
                                                    objL->value = QString::number(result);
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    int result = sym->value[0].toLatin1();
                                                    objL->value = QString::number(result);
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    int result = QVariant(sym->value).toBool();
                                                    objL->value = QString::number(result);
                                                }
                                                break;
                                                case CADENA:
                                                {
                                                    QString description = "No se puede asignar una cadena a un tipo entero";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case DECIMAL:
                                        {
                                            switch(sym->type_value){
                                                case NUMERO:
                                                {
                                                    double result = sym->value.toInt();
                                                    objL->value = QString::number(result);
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    objL->value = sym->value;
                                                }
                                                break;
                                                case CADENA:
                                                {
                                                    QString description = "No se puede asignar una cadena a un tipo doble";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    QString description = "No se puede asignar un caracter a un tipo doble";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    QString description = "No se puede asignar un booleano a un tipo doble";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case CARACTER:
                                        {
                                            switch(sym->type_value){
                                                case NUMERO:
                                                {
                                                    QChar result = sym->value.toInt();
                                                    objL->value = result;
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    objL->value = sym->value;
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    QString description = "No se puede asignar un doble a un tipo caracter";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case CADENA:
                                                {
                                                    QString description = "No se puede asignar una cadena a un tipo caracter";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    QString description = "No se puede asignar un booleano a un tipo caracter";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                        case BOOLEAN:
                                        {
                                            switch (sym->type_value) {
                                                case BOOLEAN:
                                                {
                                                    objL->value = sym->value;
                                                }
                                                break;
                                                case NUMERO:
                                                {
                                                    int op = sym->value.toInt();
                                                    if(op == 1 || op == 0){
                                                          bool result = QVariant(op).toBool();
                                                          objL->value = result ? "true" : "false";
                                                    }else{
                                                        QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                        semanticError.push_back(error);
                                                    }
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    QString description = "No se puede asignar un doble a un tipo booleano";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case CADENA:
                                                {
                                                    QString description = "No se puede asignar una cadena a un tipo booleano";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    QString description = "No se puede asignar un caracter a un tipo booleano";
                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                    semanticError.push_back(error);
                                                }
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                }else{
                                    QString description = "No existe " + node->child.at(0).value.toLower() + " en objeto " + objL->value;
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }
                        }else if(node->child.at(1).child.size() == 3){
                            Symbol *objL = ss->propertys.value(node->child.at(1).child.at(0).value.toLower(), nullptr);
                            if(objL != nullptr){
                                NodoAST tmp = node->child.at(1).child.at(1);
                                Symbol *lD = Recorrer(&tmp);
                                NodoAST Exps = node->child.at(1).child.at(2);
                                Symbol *op = Recorrer(&Exps);
                                Symbol *inArray = nullptr;
                                Symbol *inArr = nullptr;
                                if(objL->dimension3 != -1){
                                    if(lD->dimension1 < objL->dimension1 && lD->dimension2 < objL->dimension2 && lD->dimension3 < objL->dimension3){
                                        QLinkedList<Symbol*>::iterator it;
                                        for(it = objL->linearize.begin(); it != objL->linearize.end(); ++it){
                                            if((*it)->i == lD->dimension3 && (*it)->j == lD->dimension2 && (*it)->k == lD->dimension1){
                                                inArr = (*it);
                                                break;
                                            }
                                        }
                                        if(inArr != nullptr){
                                            switch (objL->type_value) {
                                                case NUMERO:
                                                {
                                                    switch(op->type_value){
                                                        case NUMERO:
                                                        {
                                                           inArr->value = op->value;
                                                        }
                                                        break;
                                                        case DECIMAL:
                                                        {
                                                            int result = op->value.toDouble();
                                                            inArr->value = QString::number(result);
                                                        }
                                                        break;
                                                        case CARACTER:
                                                        {
                                                            int result = op->value[0].toLatin1();
                                                            inArr->value = QString::number(result);
                                                        }
                                                        break;
                                                        case BOOLEAN:
                                                        {
                                                            int result = QVariant(op->value).toBool();
                                                            inArr->value = QString::number(result);
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar un objeto o cadena a un entero";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    switch (op->type_value) {
                                                        case NUMERO:
                                                        {
                                                           double result = op->value.toInt();
                                                           inArr->value = QString::number(result);
                                                        }
                                                        break;
                                                        case DECIMAL:
                                                        {
                                                            inArr->value = op->value;
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case CADENA:
                                                {
                                                    switch (op->type_value) {
                                                        case BOOLEAN:
                                                        {
                                                            QString description = "No se puede asignar un booleano a una cadena";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                        case ID:
                                                        {
                                                            QString description = "No se puede asignar un objeto a una cadena";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            inArr->value = op->value;
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    switch (op->type_value) {
                                                        case NUMERO:
                                                        {
                                                           QChar result = op->value.toInt();
                                                           inArr->value = result;
                                                        }
                                                        break;
                                                        case CARACTER:
                                                        {
                                                            inArr->value = op->value;
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    switch (op->type_value) {
                                                        case BOOLEAN:
                                                        {
                                                            inArr->value = op->value;
                                                        }
                                                        break;
                                                        case NUMERO:
                                                        {
                                                            int ae = op->value.toInt();
                                                            if(ae == 1 || ae == 0){
                                                                  bool result = QVariant(ae).toBool();
                                                                  inArr->value = result ? "true" : "false";
                                                            }else{
                                                                QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case ID:
                                                {
                                                    switch (op->type_value) {
                                                        case ID:
                                                        {

                                                        }
                                                        break;
                                                        default:
                                                        {

                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                        }else{
                                            inArr = new Symbol();
                                            switch (objL->type_value) {
                                                case NUMERO:
                                                {
                                                    switch(op->type_value){
                                                        case NUMERO:
                                                        {
                                                           inArr->type_value = op->type_value;
                                                           inArr->i = lD->dimension3;
                                                           inArr->j = lD->dimension2;
                                                           inArr->k = lD->dimension1;
                                                           inArr->value = op->value;
                                                           objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        case DECIMAL:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            int result = op->value.toDouble();
                                                            inArr->value = QString::number(result);
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        case CARACTER:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            int result = op->value[0].toLatin1();
                                                            inArr->value = QString::number(result);
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        case BOOLEAN:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            int result = QVariant(op->value).toBool();
                                                            inArr->value = QString::number(result);
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar un objeto o cadena a un entero";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case DECIMAL:
                                                {
                                                    switch (op->type_value) {
                                                        case NUMERO:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                           double result = op->value.toInt();
                                                           inArr->value = QString::number(result);
                                                           objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        case DECIMAL:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            inArr->value = op->value;
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case CADENA:
                                                {
                                                    switch (op->type_value) {
                                                        case BOOLEAN:
                                                        {
                                                            QString description = "No se puede asignar un booleano a una cadena";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                        case ID:
                                                        {
                                                            QString description = "No se puede asignar un objeto a una cadena";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            inArr->value = op->value;
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case CARACTER:
                                                {
                                                    switch (op->type_value) {
                                                        case NUMERO:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                           QChar result = op->value.toInt();
                                                           inArr->value = result;
                                                           objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        case CARACTER:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            inArr->value = op->value;
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case BOOLEAN:
                                                {
                                                    switch (op->type_value) {
                                                        case BOOLEAN:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            inArr->value = op->value;
                                                            objL->linearize.push_back(inArr);
                                                        }
                                                        break;
                                                        case NUMERO:
                                                        {
                                                            inArr->type_value = op->type_value;
                                                            inArr->i = lD->dimension3;
                                                            inArr->j = lD->dimension2;
                                                            inArr->k = lD->dimension1;
                                                            int ae = op->value.toInt();
                                                            if(ae == 1 || ae == 0){
                                                                  bool result = QVariant(ae).toBool();
                                                                  inArr->value = result ? "true" : "false";
                                                                  objL->linearize.push_back(inArr);
                                                            }else{
                                                                QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                        }
                                                        break;
                                                        default:
                                                        {
                                                            QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                            semanticError.push_back(error);
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                                case ID:
                                                {
                                                    switch (sym->type_value) {
                                                        case ID:
                                                        {

                                                        }
                                                        break;
                                                        default:
                                                        {

                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                        }
                                    }else{
                                        QString description = "La asignacion se sale de los limites del array de " + objL->id;
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                }else if(objL->dimension2 != -1){
                                    if(lD->dimension3 == -1){
                                        if(lD->dimension1 < objL->dimension1 && lD->dimension2 < objL->dimension2){
                                            QLinkedList<Symbol*>::iterator it;
                                            for(it = objL->linearize.begin(); it != objL->linearize.end(); ++it){
                                                if((*it)->i == lD->dimension2 && (*it)->j == lD->dimension1){
                                                    inArr = (*it);
                                                    break;
                                                }
                                            }
                                            if(inArr != nullptr){
                                                switch (objL->type_value) {
                                                    case NUMERO:
                                                    {
                                                        switch(op->type_value){
                                                            case NUMERO:
                                                            {
                                                               inArr->value = op->value;
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                int result = op->value.toDouble();
                                                                inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                int result = op->value[0].toLatin1();
                                                                inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            case BOOLEAN:
                                                            {
                                                                int result = QVariant(op->value).toBool();
                                                                inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                               double result = op->value.toInt();
                                                               inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CADENA:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                QString description = "No se puede asignar un booleano a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            case ID:
                                                            {
                                                                QString description = "No se puede asignar un objeto a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                               QChar result = op->value.toInt();
                                                               inArr->value = result;
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                            case NUMERO:
                                                            {
                                                                int ae = op->value.toInt();
                                                                if(ae == 1 || ae == 0){
                                                                      bool result = QVariant(ae).toBool();
                                                                      inArr->value = result ? "true" : "false";
                                                                }else{
                                                                    QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                }
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        switch (op->type_value) {
                                                            case ID:
                                                            {

                                                            }
                                                            break;
                                                            default:
                                                            {

                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                            }else{
                                                inArr = new Symbol();
                                                switch (objL->type_value) {
                                                    case NUMERO:
                                                    {
                                                        switch(op->type_value){
                                                            case NUMERO:
                                                            {
                                                               inArr->type_value = op->type_value;
                                                               inArr->i = lD->dimension2;
                                                               inArr->j = lD->dimension1;
                                                               inArr->value = op->value;
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                int result = op->value.toDouble();
                                                                inArr->value = QString::number(result);
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                int result = op->value[0].toLatin1();
                                                                inArr->value = QString::number(result);
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case BOOLEAN:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                int result = QVariant(op->value).toBool();
                                                                inArr->value = QString::number(result);
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                               double result = op->value.toInt();
                                                               inArr->value = QString::number(result);
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CADENA:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                QString description = "No se puede asignar un booleano a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            case ID:
                                                            {
                                                                QString description = "No se puede asignar un objeto a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                               QChar result = op->value.toInt();
                                                               inArr->value = result;
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case NUMERO:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension2;
                                                                inArr->j = lD->dimension1;
                                                                int ae = op->value.toInt();
                                                                if(ae == 1 || ae == 0){
                                                                      bool result = QVariant(ae).toBool();
                                                                      inArr->value = result ? "true" : "false";
                                                                      objL->linearize.push_back(inArr);
                                                                }else{
                                                                    QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                }
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        switch (sym->type_value) {
                                                            case ID:
                                                            {

                                                            }
                                                            break;
                                                            default:
                                                            {

                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                            }
                                        }else{
                                            QString description = "La asignacion se sale de los limites del array de " + objL->id;
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                    }else{
                                        QString description = "Se le estan haciendo referencia a mas dimensiones que las que puede la variable " + objL->id;
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                }else{
                                    if(lD->dimension2 == -1 && lD->dimension3 == -1){
                                        if(lD->dimension1 < objL->dimension1){
                                            QLinkedList<Symbol*>::iterator it;
                                            for(it = objL->linearize.begin(); it != objL->linearize.end(); ++it){
                                                if((*it)->i == lD->dimension1){
                                                    inArr = (*it);
                                                    break;
                                                }
                                            }
                                            if(inArr != nullptr){
                                                switch (objL->type_value) {
                                                    case NUMERO:
                                                    {
                                                        switch(op->type_value){
                                                            case NUMERO:
                                                            {
                                                               inArr->value = op->value;
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                int result = op->value.toDouble();
                                                                inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                int result = op->value[0].toLatin1();
                                                                inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            case BOOLEAN:
                                                            {
                                                                int result = QVariant(op->value).toBool();
                                                                inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                               double result = op->value.toInt();
                                                               inArr->value = QString::number(result);
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CADENA:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                QString description = "No se puede asignar un booleano a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            case ID:
                                                            {
                                                                QString description = "No se puede asignar un objeto a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                               QChar result = op->value.toInt();
                                                               inArr->value = result;
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                inArr->value = op->value;
                                                            }
                                                            break;
                                                            case NUMERO:
                                                            {
                                                                int ae = op->value.toInt();
                                                                if(ae == 1 || ae == 0){
                                                                      bool result = QVariant(ae).toBool();
                                                                      inArr->value = result ? "true" : "false";
                                                                }else{
                                                                    QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                }
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        switch (op->type_value) {
                                                            case ID:
                                                            {

                                                            }
                                                            break;
                                                            default:
                                                            {

                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                            }else{
                                                inArr = new Symbol();
                                                switch (objL->type_value) {
                                                    case NUMERO:
                                                    {
                                                        switch(op->type_value){
                                                            case NUMERO:
                                                            {
                                                               inArr->type_value = op->type_value;
                                                               inArr->i = lD->dimension1;
                                                               inArr->value = op->value;
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                int result = op->value.toDouble();
                                                                inArr->value = QString::number(result);
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                int result = op->value[0].toLatin1();
                                                                inArr->value = QString::number(result);
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case BOOLEAN:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                int result = QVariant(op->value).toBool();
                                                                inArr->value = QString::number(result);
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar un objeto o cadena a un entero";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case DECIMAL:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                               double result = op->value.toInt();
                                                               inArr->value = QString::number(result);
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case DECIMAL:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numer a un doble";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CADENA:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                QString description = "No se puede asignar un booleano a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            case ID:
                                                            {
                                                                QString description = "No se puede asignar un objeto a una cadena";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case CARACTER:
                                                    {
                                                        switch (op->type_value) {
                                                            case NUMERO:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                               QChar result = op->value.toInt();
                                                               inArr->value = result;
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case CARACTER:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                inArr->value = op->value;
                                                                objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero caracter a un caracter";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case BOOLEAN:
                                                    {
                                                        switch (op->type_value) {
                                                            case BOOLEAN:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                inArr->value = op->value;
                                                               objL->linearize.push_back(inArr);
                                                            }
                                                            break;
                                                            case NUMERO:
                                                            {
                                                                inArr->type_value = op->type_value;
                                                                inArr->i = lD->dimension1;
                                                                int ae = op->value.toInt();
                                                                if(ae == 1 || ae == 0){
                                                                      bool result = QVariant(ae).toBool();
                                                                      inArr->value = result ? "true" : "false";
                                                                      objL->linearize.push_back(inArr);
                                                                }else{
                                                                    QString description = "No se puede asignar un entero diferente de 0 y 1, a un booleano";
                                                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                    semanticError.push_back(error);
                                                                }
                                                            }
                                                            break;
                                                            default:
                                                            {
                                                                QString description = "No se puede asignar algo que no  sea un numero o booleano a un booleano";
                                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                                semanticError.push_back(error);
                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    case ID:
                                                    {
                                                        switch (sym->type_value) {
                                                            case ID:
                                                            {

                                                            }
                                                            break;
                                                            default:
                                                            {

                                                            }
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                            }
                                        }else{
                                            QString description = "La asignacion se sale de los limites del array de " + objL->id;
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                    }else{
                                        QString description = "Se le estan haciendo referencia amas dimensiones que las que podee la variable " + objL->id;
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                }
                            }else{
                                QString description = "No existe " + node->child.at(0).value.toLower() + " en objeto " + objL->value;
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }
                    }
                    break;
                }
            }else{
                QString description = "No existe la variable " + id;
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case SI:
        {
            NodoAST tmp = node->child.at(0);
            Symbol *cond = Recorrer(&tmp);
            if(cond->type_value == BOOLEAN){
                if(node->child.size() == 2){
                    switch (node->child.at(1).typeofValue) {
                        case LSENTENCIAS:
                        {
                            if(QVariant(cond->value).toBool()){
                                currentEnviroment = new ScopeNode();
                                QueueScope.newScope(currentEnviroment);
                                NodoAST tmp = node->child.at(1);
                                Recorrer(&tmp);
                                currentEnviroment = QueueScope.deleteScope();
                            }
                        }
                        break;
                        case ELSE:
                        {
                            if(!QVariant(cond->value).toBool()){
                                if(node->child.at(1).child.size() != 0){
                                    currentEnviroment = new ScopeNode();
                                    QueueScope.newScope(currentEnviroment);
                                    NodoAST tmp = node->child.at(1).child.at(0);
                                    Recorrer(&tmp);
                                    currentEnviroment = QueueScope.deleteScope();
                                }
                            }
                        }
                        break;
                    }
                }else if(node->child.size() == 3){
                    if(QVariant(cond->value).toBool()){
                        currentEnviroment = new ScopeNode();
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = node->child.at(1);
                        Recorrer(&tmp);
                        currentEnviroment = QueueScope.deleteScope();
                    }else{
                        if(node->child.at(2).child.size() != 0){
                            currentEnviroment = new ScopeNode();
                            QueueScope.newScope(currentEnviroment);
                            NodoAST tmp = node->child.at(2).child.at(0);
                            Recorrer(&tmp);
                            currentEnviroment = QueueScope.deleteScope();
                        }
                    }
                }
            }else{
                QString description = "No se puede evaluar en el si una condicion no booleana";
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case PARA:
        {
            currentEnviroment = new ScopeNode();
            QueueScope.newScope(currentEnviroment);
            NodoAST tmp = node->child.at(0);
            Recorrer(&tmp);
            NodoAST tmp2 = node->child.at(1);
            Symbol *cond = Recorrer(&tmp2);
            if(cond->type_value == BOOLEAN && node->child.size() > 3){
                while(QVariant(cond->value).toBool()){
                    currentEnviroment = new ScopeNode();
                    currentEnviroment->actuallyClass->role = "ciclo";
                    QueueScope.newScope(currentEnviroment);
                    NodoAST tmp = node->child.at(3);
                    Recorrer(&tmp);
                    currentEnviroment = QueueScope.deleteScope();
                    isContinue = false;
                    if(isBreak){
                        break;
                    }
                    NodoAST tmp2 = node->child.at(2);
                    Recorrer(&tmp2);
                    NodoAST tmp3 = node->child.at(1);
                    cond = Recorrer(&tmp3);
                }
                isBreak = false;
            }else{
                QString description = "No se puede poner una condicion no boolena en el para";
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
            currentEnviroment = QueueScope.deleteScope();
        }
        break;
        case AUMENTO:
        {
            NodoAST tmp = node->child.at(0);
            sym = Recorrer(&tmp);
            switch (sym->type_value) {
                case NUMERO:
                {

                    int result = sym->value.toInt();
                    result++;
                    sym->value = QString::number(result);
                }
                break;
                case DECIMAL:
                {
                    double result = sym->value.toDouble();
                    result++;
                    sym->value = QString::number(result);
                }
                break;
                case CARACTER:
                {
                    QChar result = sym->value[0].toLatin1() + 1;
                    sym->value = result;
                }
                break;
                default:
                {
                    QString description = "No se puede aumentar valores que no sean caracter, entero o doble";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case DECREMENTO:
        {
            NodoAST tmp = node->child.at(0);
            sym = Recorrer(&tmp);
            switch (sym->type_value) {
                case NUMERO:
                {
                    int result = sym->value.toInt();
                    result--;
                    sym->value = QString::number(result);
                }
                break;
                case DECIMAL:
                {
                    double result = sym->value.toDouble();
                    result--;
                    sym->value = QString::number(result);
                }
                break;
                case CARACTER:
                {
                    QChar result = sym->value[0].toLatin1() - 1;
                    sym->value = result;
                }
                break;
                default:
                {
                    QString description = "No se puede decrementar valores que no sean caracter, entero o doble";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case IMPRIMIR:
        {
            NodoAST tmp = node->child.at(0);
            Symbol *msg = Recorrer(&tmp);
            consoleMsg.push_back(msg->value);
        }
        break;
        case REPETIR:
        {
            NodoAST tmp = node->child.at(0);
            Symbol *cond = Recorrer(&tmp);
            if(cond->type_value == NUMERO){
                if(node->child.size() > 1){
                    int ss = cond->value.toInt();
                    for(int x=0; x<ss; x++){
                        currentEnviroment = new ScopeNode();
                        currentEnviroment->actuallyClass->role = "ciclo";
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = node->child.at(1);
                        Recorrer(&tmp);
                        currentEnviroment = QueueScope.deleteScope();
                        isContinue = false;
                        if(isBreak){
                            break;
                        }
                    }
                    isBreak = false;
                }
            }else{
                QString description = "No se puede usar en la condicion de repetir algo que no sea entero";
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case MIENTRAS:
        {
            NodoAST tmp = node->child.at(0);
            Symbol *cond = Recorrer(&tmp);
            if(cond->type_value == BOOLEAN){
                if(node->child.size() > 1){
                    while(QVariant(cond->value).toBool()){
                        currentEnviroment = new ScopeNode();
                        currentEnviroment->actuallyClass->role = "ciclo";
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = node->child.at(1);
                        Recorrer(&tmp);
                        currentEnviroment = QueueScope.deleteScope();
                        isContinue = false;
                        if(isBreak){
                            break;
                        }
                        NodoAST tmp2 = node->child.at(0);
                        cond = Recorrer(&tmp2);
                    }
                    isBreak = false;
                }
            }else{
                QString description = "No se puede evaluar en mientras un no booleano";
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case HACER:
        {
            if(node->child.size() > 1){
                NodoAST tmp = node->child.at(1);
                Symbol *cond = Recorrer(&tmp);
                if(cond->type_value == BOOLEAN){
                    do{
                        currentEnviroment = new ScopeNode();
                        currentEnviroment->actuallyClass->role = "ciclo";
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tt = node->child.at(0);
                        Recorrer(&tt);
                        currentEnviroment = QueueScope.deleteScope();
                        isContinue = false;
                        if(isBreak){
                           break;
                        }
                        NodoAST os = node->child.at(1);
                        cond = Recorrer(&os);
                    }while(QVariant(cond->value).toBool());
                    isBreak = false;
                }else{
                    QString description = "No se puede evaluar en hacer un no booleano";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
            }
        }
        break;
        case LTIPOS:
        {
            if(node->child.size() > 0){
                for(int x=0; x<node->child.size(); x++){
                    Symbol *tmp = new Symbol();
                    tmp->type = node->child.at(x).value.toLower();
                    tmp->type_value = AsignType(tmp->type);
                    switch(node->child.at(x+1).typeofValue){
                        case ID:
                        {
                            tmp->id = node->child.at(x+1).value.toLower();
                            sym->parameters.push_back(tmp);
                            x++;
                        }
                        break;
                        case DIMENSION:
                        {

                        }
                        break;
                    }
                }
            }
        }
        break;
        case LLAMADAFUNC:
        {
            sym->id = node->child.at(0).value.toLower();
            if(node->child.size() == 1){
                Symbol *fun = SearchidScope(sym->id);
                if(fun != nullptr){
                    Symbol *sonFun = new Symbol();
                    sonFun->id = fun->id;
                    sonFun->role = fun->role;
                    sonFun->access = fun->access;
                    sonFun->instructions = fun->instructions;
                    sonFun->type_value = fun->type_value;
                    sonFun->parameters = fun->parameters;
                    if(sonFun->parameters.size() == 0){
                        currentEnviroment = new ScopeNode();
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = sonFun->instructions;
                        Recorrer(&tmp);
                        sym = currentEnviroment->actuallyClass->regresa;
                        currentEnviroment = QueueScope.deleteScope();
                        isReturn = false;
                    }else{
                        QString description = "La funcion " + sonFun->id + " esta esperando parametros";
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }else{
                    QString description = "La funcion " + sym->id + " no ha sido declarada";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
            }else{
                switch(node->child.at(1).typeofValue){
                    case LEXP:
                    {
                        Symbol *fun = SearchidScope(sym->id);
                        if(fun != nullptr){
                            Symbol *sonFun = new Symbol();
                            sonFun->id = fun->id;
                            sonFun->role = fun->role;
                            sonFun->access = fun->access;
                            sonFun->instructions = fun->instructions;
                            sonFun->type_value = fun->type_value;
                            sonFun->parameters = fun->parameters;
                            NodoAST tmp = node->child.at(1);
                            Symbol *lv = Recorrer(&tmp);
                            bool error = false;
                            if(lv->parameters.size() == sonFun->parameters.size()){
                                for(int i=0; i<lv->parameters.size(); i++){
                                    if(lv->parameters.at(i)->type_value == sonFun->parameters.at(i)->type_value){
                                    }else{
                                        error = true;
                                        break;
                                    }
                                }
                                if(!error){
                                    for(int i=0; i<lv->parameters.size(); i++){
                                        sonFun->parameters.at(i)->value = lv->parameters.at(i)->value;
                                    }
                                    for(int x=0; x<sonFun->parameters.size(); x++){
                                        Symbol *tmp = new Symbol();
                                        tmp->id = sonFun->parameters.at(x)->id;
                                        tmp->role = sonFun->parameters.at(x)->role;
                                        tmp->type_value = sonFun->parameters.at(x)->type_value;
                                        tmp->value = sonFun->parameters.at(x)->value;
                                        sonFun->propertys.insert(tmp->id, tmp);
                                    }
                                    currentEnviroment = new ScopeNode();
                                    currentEnviroment->actuallyClass = sonFun;
                                    QueueScope.newScope(currentEnviroment);
                                    NodoAST tmp = sonFun->instructions;
                                    Recorrer(&tmp);
                                    sym = currentEnviroment->actuallyClass->regresa;
                                    currentEnviroment = QueueScope.deleteScope();
                                    isReturn = false;
                                }else{
                                    QString description = "Error de tipos, al pasarle datos a la funcion " + sonFun->id;
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "No hay la misma cantidad de valores que la funcion esta esperando";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else{
                            QString description = "La funcion " + fun->id + " no ha sido declarada";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
                        }
                    }
                    break;
                    case ID:
                    {
                        if(node->child.at(1).value.toLower() == "crearconjunto"){
                            Symbol *conj = SearchidScope(sym->id);
                            if(conj != nullptr){
                                NodoAST p1 = node->child.at(2);
                                Symbol *op1 = Recorrer(&p1);
                                NodoAST p2 = node->child.at(3);
                                Symbol *op2 = Recorrer(&p2);
                                if(op1->type_value == CADENA && op2->type_value == CADENA){
                                    QString chain = "CONJ: " + op1->value + " -> " + op2->value + ";\n";
                                    conj->conj += chain;
                                }else{
                                    QString description = "Crearconjunto recibe dos cadenas";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "No existe la variable de tipo archivo";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else if(node->child.at(1).value.toLower() == "crearregex"){
                            Symbol *conj = SearchidScope(sym->id);
                            if(conj != nullptr){
                                NodoAST p1 = node->child.at(2);
                                Symbol *op1 = Recorrer(&p1);
                                NodoAST p2 = node->child.at(3);
                                Symbol *op2 = Recorrer(&p2);
                                if(op1->type_value == CADENA && op2->type_value == CADENA){
                                    QString chain =  op1->value + " -> " + op2->value + ";\n";
                                    conj->regx += chain;
                                }else{
                                    QString description = "CrearRegex recibe dos cadenas";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "No existe la variable de tipo archivo";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else if(node->child.at(1).value.toLower() == "crearentrada"){
                            Symbol *conj = SearchidScope(sym->id);
                            if(conj != nullptr){
                                NodoAST p1 = node->child.at(2);
                                Symbol *op1 = Recorrer(&p1);
                                NodoAST p2 = node->child.at(3);
                                Symbol *op2 = Recorrer(&p2);
                                if(op1->type_value == CADENA && op2->type_value == CADENA){
                                    QString chain =  op1->value + " : \"" + op2->value + "\";\n";
                                    conj->enter += chain;
                                }else{
                                    QString description = "CrearEntrada recibe dos cadenas";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "No existe la variable de tipo archivo";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else if(node->child.at(1).value.toLower() == "guardararchivo"){
                            Symbol *conj = SearchidScope(sym->id);
                            if(conj != nullptr){
                                    QFile file(conj->path);
                                    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                                        QTextStream data(&file);
                                        data << "{" << endl;
                                        data << conj->conj << endl;
                                        data << conj->regx << endl;
                                        data << "%%" << endl;
                                        data << "%%" << endl;
                                        data << conj->enter << endl;
                                        data << "}" << endl;
                                    }
                                    file.close();
                                }else{
                                    QString description = "CrearEntrada recibe dos cadenas";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                        }else{
                            if(node->child.size() == 3){
                                Symbol *obj = SearchidScope(sym->id);
                                if(obj != nullptr){
                                    Symbol *fun = obj->propertys.value(node->child.at(1).value, nullptr);
                                    if(fun != nullptr){
                                        Symbol *sonFun = new Symbol();
                                        sonFun->id = fun->id;
                                        sonFun->role = fun->role;
                                        sonFun->access = fun->access;
                                        sonFun->instructions = fun->instructions;
                                        sonFun->type_value = fun->type_value;
                                        sonFun->parameters = fun->parameters;
                                        NodoAST tmp = node->child.at(2);
                                        Symbol *lv = Recorrer(&tmp);
                                        bool error = false;
                                        if(lv->parameters.size() == sonFun->parameters.size()){
                                            for(int i=0; i<lv->parameters.size(); i++){
                                                if(lv->parameters.at(i)->type_value == sonFun->parameters.at(i)->type_value){
                                                }else{
                                                    error = true;
                                                    break;
                                                }
                                            }
                                            if(!error){
                                                for(int i=0; i<lv->parameters.size(); i++){
                                                    sonFun->parameters.at(i)->value = lv->parameters.at(i)->value;
                                                }
                                                for(int x=0; x<sonFun->parameters.size(); x++){
                                                    Symbol *tmp = new Symbol();
                                                    tmp->id = sonFun->parameters.at(x)->id;
                                                    tmp->role = sonFun->parameters.at(x)->role;
                                                    tmp->type_value = sonFun->parameters.at(x)->type_value;
                                                    tmp->value = sonFun->parameters.at(x)->value;
                                                    sonFun->propertys.insert(tmp->id, tmp);
                                                }
                                                currentEnviroment = new ScopeNode();
                                                currentEnviroment->actuallyClass = obj;
                                                QueueScope.newScope(currentEnviroment);
                                                currentEnviroment = new ScopeNode();
                                                currentEnviroment->actuallyClass = sonFun;
                                                QueueScope.newScope(currentEnviroment);
                                                NodoAST tmp = sonFun->instructions;
                                                Recorrer(&tmp);
                                                sym = currentEnviroment->actuallyClass->regresa;
                                                currentEnviroment = QueueScope.deleteScope();
                                                isReturn = false;
                                            }else{
                                                QString description = "Error de tipos, al pasarle datos a la funcion " + sonFun->id;
                                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                                semanticError.push_back(error);
                                            }
                                            currentEnviroment = QueueScope.deleteScope();
                                        }else{
                                            QString description = "No hay la misma cantidad de valores que la funcion esta esperando";
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                    }else{
                                        QString description = "La funcion " + obj->id + " no ha sido declarada";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                                }else{
                                    QString description = "La funcion " + sym->id + " no ha sido declarada";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                               Symbol *obj = SearchidScope(sym->id);
                               if(obj != nullptr){
                                    Symbol *fun = obj->propertys.value(node->child.at(1).value, nullptr);
                                    if(fun != nullptr){
                                        Symbol *sonFun = new Symbol();
                                        sonFun->id = fun->id;
                                        sonFun->role = fun->role;
                                        sonFun->access = fun->access;
                                        sonFun->instructions = fun->instructions;
                                        sonFun->type_value = fun->type_value;
                                        sonFun->parameters = fun->parameters;
                                        currentEnviroment = new ScopeNode();
                                        currentEnviroment->actuallyClass = obj;
                                        QueueScope.newScope(currentEnviroment);
                                        if(sonFun->parameters.size() == 0){
                                            currentEnviroment = new ScopeNode();
                                            QueueScope.newScope(currentEnviroment);
                                            NodoAST tmp = sonFun->instructions;
                                            Recorrer(&tmp);
                                            sym = currentEnviroment->actuallyClass->regresa;
                                            currentEnviroment = QueueScope.deleteScope();
                                            isReturn = false;
                                        }else{
                                            QString description = "La funcion " + sonFun->id + " esta esperando parametros";
                                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                            semanticError.push_back(error);
                                        }
                                        currentEnviroment = QueueScope.deleteScope();
                                    }else{
                                        QString description = "La funcion " + obj->id + " no ha sido declarada";
                                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                        semanticError.push_back(error);
                                    }
                               }else{
                                   QString description = "La funcion " + sym->id + " no ha sido declarada";
                                   Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                   semanticError.push_back(error);
                               }
                            }
                        }
                    }
                    break;
                }
            }
        }
        break;
        case LEXP:
        {
            for(int x=0; x<node->child.size(); x++){
                NodoAST tmp = node->child.at(x);
                sym->parameters.push_back(Recorrer(&tmp));
            }
        }
        break;
        case MAIN:
        {
            if(node->child.size() > 0){
                keyMain = currentEnviroment->actuallyClass->id;
                sym->role = "principal";
                sym->id = "principal";
                sym->instructions = node->child.at(0);
                currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
            }else{
                keyMain = currentEnviroment->actuallyClass->id;
                sym->role = "principal";
                sym->id = "principal";
                currentEnviroment->actuallyClass->propertys.insert(sym->id, sym);
            }
        }
        break;
        case MENOS:
        {
            NodoAST tmp = node->child.at(0);
            Symbol *ss = Recorrer(&tmp);
            switch (ss->type_value) {
                case NUMERO:
                {
                    sym->type_value = NUMERO;
                    int result = -(ss->value.toInt());
                    sym->value = QString::number(result);
                }
                break;
                case DECIMAL:
                {
                    sym->type_value = DECIMAL;
                    double result = -(ss->value.toDouble());
                    sym->value = QString::number(result);
                }
                break;
                default:
                {
                    QString description = "No se puede poner \"-\" a un no numero";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
                break;
            }
        }
        break;
        case DIMENSION:
        {
            if(node->child.size() == 1){
                NodoAST tmp = node->child.at(0);
                Symbol *res1 = Recorrer(&tmp);
                if(res1->type_value == NUMERO){
                    int result1 = res1->value.toInt();
                    if(result1 >= 0){
                        sym->dimension1 = result1;
                    }else{
                        QString description = "No se puede poner un numero negativo a una dimension";
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }else{
                    QString description = "No se puede poner un tipo diferente de entero a una dimension";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
            }else if(node->child.size() == 2){
                NodoAST tmp = node->child.at(0);
                NodoAST tmp2 = node->child.at(1);
                Symbol *res1 = Recorrer(&tmp);
                Symbol *res2 = Recorrer(&tmp2);
                if(res1->type_value == NUMERO && res2->type_value == NUMERO){
                    int result1 = res1->value.toInt();
                    int result2 = res2->value.toInt();
                    if(result1 >= 0 && result2 >= 0){
                        sym->dimension1 = result1;
                        sym->dimension2 = result2;
                    }else{
                        QString description = "No se puede poner un numero negativo a una dimension";
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }else{
                    QString description = "No se puede poner un tipo diferente de entero a una dimension";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
            }else{
                NodoAST tmp = node->child.at(0);
                NodoAST tmp2 = node->child.at(1);
                NodoAST tmp3 = node->child.at(2);
                Symbol *res1 = Recorrer(&tmp);
                Symbol *res2 = Recorrer(&tmp2);
                Symbol *res3 = Recorrer(&tmp3);
                if(res1->type_value == NUMERO && res2->type_value== NUMERO && res3->type_value == NUMERO){
                    int result1 = res1->value.toInt();
                    int result2 = res2->value.toInt();
                    int result3 = res3->value.toInt();
                    if(result1 >= 0 && result2 >= 0 && result3 >= 0){
                        sym->dimension1 = result1;
                        sym->dimension2 = result2;
                        sym->dimension3 = result3;
                    }else{
                        QString description = "No se puede poner un numero negativo a una dimension";
                        Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                        semanticError.push_back(error);
                    }
                }else{
                    QString description = "No se puede poner un tipo diferente de entero a una dimension";
                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                    semanticError.push_back(error);
                }
            }
        }
        break;
        case MOSTRARNOTIFICACION:
        {
            NodoAST tmp1 = node->child.at(0);
            Symbol *title = Recorrer(&tmp1);
            NodoAST tmp2 = node->child.at(1);
            Symbol *msg = Recorrer(&tmp2);
            Notify *newNo = new Notify(title->value, msg->value);
            notifyMsg.push_back(newNo);
        }
        break;
        case RETORNAR:
        {
            Symbol *env = SearchRole(1);
            if(env != nullptr){
                NodoAST exp = node->child.at(0);
                sym = Recorrer(&exp);
                switch (env->type_value) {
                    case NUMERO:
                    {
                        switch(sym->type_value){
                            case NUMERO:
                            {
                               env->regresa = sym;
                               isReturn = true;
                            }
                            break;
                            case DECIMAL:
                            {

                                int result = (int)sym->value.toDouble();
                                sym->value = QString::number(result);
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            case CARACTER:
                            {
                                int result = sym->value[0].toLatin1();
                                sym->value = QString::number(result);
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            case BOOLEAN:
                            {
                                int result = QVariant(sym->value).toBool();
                                sym->value = QString::number(result);
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            default:
                            {
                                QString description = "No se puede returnar un objeto o cadena a un entero";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                            break;
                        }
                    }
                    break;
                    case DECIMAL:
                    {
                        switch (sym->type_value) {
                            case NUMERO:
                            {
                               double result = sym->value.toInt();
                               sym->value = QString::number(result);
                               env->regresa = sym;
                               isReturn = true;
                            }
                            break;
                            case DECIMAL:
                            {
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            default:
                            {
                                QString description = "No se puede retornar algo que no  sea un numer a un doble";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                            break;
                        }
                    }
                    break;
                    case CADENA:
                    {
                        switch (sym->type_value) {
                            case BOOLEAN:
                            {
                                QString description = "No se puede retornar un booleano a una cadena";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                            break;
                            case ID:
                            {
                                QString description = "No se puede retornar un objeto a una cadena";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                            break;
                            default:
                            {
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                        }
                    }
                    break;
                    case CARACTER:
                    {
                        switch (sym->type_value) {
                            case NUMERO:
                            {
                               QChar result = sym->value.toInt();
                               sym->value = result;
                               env->regresa = sym;
                               isReturn = true;
                            }
                            break;
                            case CARACTER:
                            {
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            default:
                            {
                                QString description = "No se puede retornar algo que no  sea un numero caracter a un caracter";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                            break;
                        }
                    }
                    break;
                    case BOOLEAN:
                    {
                        switch (sym->type_value) {
                            case BOOLEAN:
                            {
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            case NUMERO:
                            {
                                int ae = sym->value.toInt();
                                if(ae == 1 || ae == 0){
                                      bool result = QVariant(ae).toBool();
                                      sym->value = result ? "true" : "false";
                                      env->regresa = sym;
                                      isReturn = true;
                                }else{
                                    QString description = "No se puede retornar un entero diferente de 0 y 1, a un booleano";
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }
                            break;
                            default:
                            {
                                QString description = "No se puede retornar algo que no  sea un numero o booleano a un booleano";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                            break;
                        }
                    }
                    break;
                    case ID:
                    {
                        switch (sym->type_value) {
                            case ID:
                            {
                                env->regresa = sym;
                                isReturn = true;
                            }
                            break;
                            default:
                            {

                            }
                            break;
                        }
                    }
                    break;
                }
            }else{
                QString description = "No se declarar return en algo que no sea un metodo";
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case ROMPER:
        {
            Symbol *cicl = SearchRole(2);
            if(cicl != nullptr){
                isBreak = true;
            }else{
                QString description = "No se declarar romper en algo que no sea un ciclo";
                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                semanticError.push_back(error);
            }
        }
        break;
        case CONTINUAR:
        {
        Symbol *cicl = SearchRole(2);
        if(cicl != nullptr){
            isContinue = true;
        }else{
            QString description = "No se declarar continuar en algo que no sea un ciclo";
            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
            semanticError.push_back(error);
        }
        }
        break;
    }
    return sym;
}

void Travel::StartProgram(){
    if(keyMain != ""){
        Symbol *cl = listClass.value(keyMain, nullptr);
        if(cl != nullptr){
            Symbol *mm = cl->propertys.value("principal", nullptr);
            if(mm != nullptr){
                currentEnviroment = new ScopeNode();
                currentEnviroment->actuallyClass = cl;
                QueueScope.newScope(currentEnviroment);
                NodoAST  tmp = mm->instructions;
                Recorrer(&tmp);
                currentEnviroment = QueueScope.deleteScope();
            }else{
                QString description = "No hay una funcion principal definida";
                Semantic_Error *error = new Semantic_Error(0, 0, "Semantico", description);
                semanticError.push_back(error);
            }
        }else{
            QString description = "No hay una funcion principal definida";
            Semantic_Error *error = new Semantic_Error(0, 0, "Semantico", description);
            semanticError.push_back(error);
        }
    }else{
        QString description = "No hay una funcion principal definida";
        Semantic_Error *error = new Semantic_Error(0, 0, "Semantico", description);
        semanticError.push_back(error);
    }
}

void Travel::InitClassValues(){
    QHash<QString, Symbol*>::const_iterator i = listClass.constBegin();
    while(i != listClass.constEnd()){
        currentEnviroment = new ScopeNode();
        currentEnviroment->actuallyClass = i.value();
        QueueScope.newScope(currentEnviroment);
        Recorrer(&i.value()->instructions);
        currentEnviroment = QueueScope.deleteScope();
        i++;
    }
}

void Travel::chargeImports(){
    QHash<QString, Symbol*>::const_iterator i = listClass.constBegin();
    while(i != listClass.constEnd()){
        for(int x=0; x<i.value()->imports.size(); x++){
            Symbol *cl = listClass.value(i.value()->imports.at(x), nullptr);
            if(cl != nullptr){
                importHash(i.value()->propertys, cl->propertys);
            }
        }
        i++;
    }
}

void Travel::importHash(QHash<QString, Symbol *> &original, QHash<QString, Symbol *> &toCopy){
    QHash<QString, Symbol*>::const_iterator i = toCopy.constBegin();
    while(i != toCopy.constEnd()){
        Symbol *newS = new Symbol(i.value());
        original.insert(i.key(), newS);
        i++;
    }
}

void Travel::CopyLIDS(QList<QString> &original, QList<QString> copy){
    for(int i=0; i<copy.size(); i++){
        original.push_back(copy.at(i));
    }
}

Symbol* Travel::SearchidScope(QString id){
    ScopeNode *tmp = QueueScope.actually;
    while(tmp != nullptr){
        Symbol *result = tmp->actuallyClass->propertys.value(id, nullptr);
        if(result != nullptr){
            return result;
        }
        tmp = tmp->preview;
    }
    return nullptr;
}

Symbol* Travel::SearchRole(int code){
    ScopeNode *tmp = QueueScope.actually;
    while(tmp != nullptr){
        switch (code) {
            case 1:
            {
                if(tmp->actuallyClass->role == "funcion"){
                    return tmp->actuallyClass;
                }
            }
            break;
            case 2:
            {
                if(tmp->actuallyClass->role == "ciclo"){
                    return tmp->actuallyClass;
                }
            }
            break;
        }
        tmp = tmp->preview;
    }
    return nullptr;
}

QHash<QString, Symbol*> Travel::CopyHash(QHash<QString, Symbol *>toCopy){
    QHash<QString, Symbol*> newHash;
    QHash<QString, Symbol*>::const_iterator i = toCopy.constBegin();
    while(i != toCopy.constEnd()){
        newHash.insert(i.key(), new Symbol(i.value()));
        i++;
    }
    return newHash;
}

int Travel::AsignType(QString type){
    if(type.toLower() == "entero"){
        return NUMERO;
    }else if(type.toLower() == "doble"){
        return DECIMAL;
    }else if(type.toLower() == "booleano"){
        return BOOLEAN;
    }else if(type.toLower() == "caracter"){
        return CARACTER;
    }else if(type.toLower() == "cadena"){
        return CADENA;
    }else if(type.toLower() == "void"){
        return VOID;
    }else if(type.toLower() == "archivo"){
        return ARCHIVO;
    }
    return ID;
}
