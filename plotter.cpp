#include "plotter.h"

Plotter::Plotter()
{
    this->contador = 0;
}

Plotter::Plotter(NodoAST *raiz){
    this->grafo = "";
    this->raiz = raiz;
    this->contador = 0;
}

QString Plotter::graficar(){
    grafo = "digraph G{";
    grafo += "node[shape=\"box\"];";
    grafo += "NodoAST0[label=\"" + escapar("[" +raiz->type +"," + QString::number(raiz->typeofValue)+ "("+ QString::number(raiz->row)+","+ QString::number(raiz->column)+")"+"]"+raiz->value)  + "\"];\n";
    this->contador = 1;
    recorrerAST("NodoAST0", raiz);
    grafo += "}";
    return grafo;
}

QString Plotter::escapar(QString cadena){
    cadena = cadena.replace("\\", "\\\\");
    cadena = cadena.replace("\"", "\\\"");
    return cadena;
}

void Plotter::recorrerAST(QString padre, NodoAST *hijo){
    int x = 0;
    for (x = 0 ; x < hijo->child.count() ; x++)
    {
        NodoAST NodoAST = hijo->child[x];
        QString nombreHijo = "NodoAST" +  QString::number(contador);//  this->contador;
        grafo += nombreHijo + "[label=\"" + escapar("[" +NodoAST.type +"," + QString::number(NodoAST.typeofValue)+ "("+ QString::number(NodoAST.row)+","+ QString::number(NodoAST.column)+")"+NodoAST.value)  + "\"];\n";
        grafo += padre + "->" + nombreHijo + ";\n";
        contador++;
        recorrerAST(nombreHijo, &NodoAST);
    }
}

void Plotter::generarImagen(){
    QFileInfo fi("temp");

    graficar();
    QString grafoDOT = this->grafo;
    QString path = fi.absolutePath() +"/";
    QFile qFile(path+"grafo.txt");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile); out << grafoDOT;
        qFile.close();
    }
    QString cadenaComando = "dot grafo.txt -o grafo.png -Tpng";

    std::cout << cadenaComando.toStdString() << "\n" << std::endl;

    system(cadenaComando.toUtf8().constData());
}
