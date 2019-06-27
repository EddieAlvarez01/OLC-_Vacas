#ifndef PLOTTER_H
#define PLOTTER_H

#include "nodoast.h"
#include <fstream>
#include <iostream>
#include <QtWidgets>


class Plotter
{
public:
    Plotter();
    Plotter(NodoAST*);
    NodoAST *raiz;
    int contador;
    QString grafo;
    QString graficar();
    void recorrerAST(QString padre, NodoAST *hijo);
    QString escapar(QString cadena);
    void generarImagen();
};

#endif // PLOTTER_H
