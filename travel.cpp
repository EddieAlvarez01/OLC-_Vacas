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
    VOID = 67
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
                Recorrer(&tmp2);
            }else if(node->child.size() == 2){
                currentEnviroment->actuallyClass->id = node->child.at(1).value.toLower();
                 NodoAST tmp = node->child.at(0);
                 Recorrer(&tmp);
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
                Recorrer(&tmp);
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
                    sym->imports = Recorrer(&tmp)->imports;
                    if(node->child.size() > 3){
                        if(node->child.at(3).typeofValue == DIMENSION){

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
                            for(int x=0; x<sym->parameters.size(); x++){
                                sym->propertys.insert(sym->parameters.at(x)->id, sym->parameters.at(x));
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
                        }
                    }else{
                        for(int x=0; x<sym->imports.size(); x++){
                            Symbol *newS = new Symbol();
                            newS->access = sym->access;
                            newS->type = sym->type;
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
                    sym->imports = Recorrer(&tmp)->imports;
                    if(node->child.size() > 2){
                        if(node->child.at(2).typeofValue == DIMENSION){

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
                            for(int x=0; x<sym->parameters.size(); x++){
                                sym->propertys.insert(sym->parameters.at(x)->id, sym->parameters.at(x));
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
                                for(int y=0; y<newS->parameters.size(); y++){
                                    newS->propertys.insert(newS->parameters.at(y)->id, newS->parameters.at(y));
                                }
                                newS->type_value = sym->type_value;
                                newS->id = sym->imports.at(x);
                                newS->value = sym->value;
                                currentEnviroment->actuallyClass->propertys.insert(newS->id, newS);
                            }
                        }
                    }else{
                        for(int x=0; x<sym->imports.size(); x++){
                            Symbol *newS = new Symbol();
                            newS->access = sym->access;
                            newS->type = sym->type;
                            newS->role = sym->role;
                            newS->parameters = sym->parameters;
                            for(int y=0; y<newS->parameters.size(); y++){
                                newS->propertys.insert(newS->parameters.at(y)->id, newS->parameters.at(y));
                            }
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
            node->value.replace("\"", "");
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
                    QueueScope.newScope(currentEnviroment);
                    NodoAST tmp = node->child.at(3);
                    Recorrer(&tmp);
                    currentEnviroment = QueueScope.deleteScope();
                    NodoAST tmp2 = node->child.at(2);
                    Recorrer(&tmp2);
                    NodoAST tmp3 = node->child.at(1);
                    cond = Recorrer(&tmp3);
                }
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
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = node->child.at(1);
                        Recorrer(&tmp);
                        currentEnviroment = QueueScope.deleteScope();
                    }
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
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = node->child.at(1);
                        Recorrer(&tmp);
                        currentEnviroment = QueueScope.deleteScope();
                        NodoAST tmp2 = node->child.at(0);
                        cond = Recorrer(&tmp2);
                    }
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
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tt = node->child.at(0);
                        Recorrer(&tt);
                        currentEnviroment = QueueScope.deleteScope();
                        NodoAST os = node->child.at(1);
                        cond = Recorrer(&os);
                    }while(QVariant(cond->value).toBool());
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
                    if(fun->parameters.size() == 0){
                        currentEnviroment = new ScopeNode();
                        QueueScope.newScope(currentEnviroment);
                        NodoAST tmp = fun->instructions;
                        Recorrer(&tmp);
                        currentEnviroment = QueueScope.deleteScope();
                    }else{
                        QString description = "La funcion " + sym->id + " esta esperando parametros";
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
                            NodoAST tmp = node->child.at(1);
                            Symbol *lv = Recorrer(&tmp);
                            bool error = false;
                            if(lv->parameters.size() == fun->parameters.size()){
                                for(int i=0; i<lv->parameters.size(); i++){
                                    if(lv->parameters.at(i)->type_value == fun->parameters.at(i)->type_value){
                                    }else{
                                        error = true;
                                        break;
                                    }
                                }
                                if(!error){
                                    for(int i=0; i<lv->parameters.size(); i++){
                                        fun->parameters.at(i)->value = lv->parameters.at(i)->value;
                                    }
                                    currentEnviroment = new ScopeNode();
                                    currentEnviroment->actuallyClass = fun;
                                    QueueScope.newScope(currentEnviroment);
                                    NodoAST tmp = fun->instructions;
                                    Recorrer(&tmp);
                                    QueueScope.deleteScope();
                                }else{
                                    QString description = "Error de tipos, al pasarle datos a la funcion " + sym->id;
                                    Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                    semanticError.push_back(error);
                                }
                            }else{
                                QString description = "No hay la misma cantidad de valores que la funcion esta esperando";
                                Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                                semanticError.push_back(error);
                            }
                        }else{
                            QString description = "La funcion " + sym->id + " no ha sido declarada";
                            Semantic_Error *error = new Semantic_Error(node->row, node->column, "Semantico", description);
                            semanticError.push_back(error);
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
    }
    return sym;
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
    }
    return 0;
}
