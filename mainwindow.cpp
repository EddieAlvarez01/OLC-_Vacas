#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <iostream>
#include <parser.h>
#include <scanner.h>
#include <qdebug.h>
#include "plotter.h"
#include "nodoast.h"
#include "travel.h"

extern int yyparse();
extern NodoAST *raiz;
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCompilar_triggered()
{
    QString program = ui->textEdit_3->toPlainText();
    YY_BUFFER_STATE buffer = yy_scan_string(program.toUtf8().constData());
    linea = 0;
    columna = 0;
    yylineno = 0;

    if(yyparse() == 0){
        std::cout << "Correcto" << std::endl;
        Plotter *plot = new Plotter(raiz);
        plot->generarImagen();
        Travel *travel = new Travel();
        travel->Recorrer(raiz);
        std::cout << "prueba";
    }else{
        std::cout << "Nel prro" << std::endl;
    }
}

void MainWindow::on_actionGenerar_AST_triggered()
{
    system("cmd /c start grafo.png");
}
