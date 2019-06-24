#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <iostream>
#include <parser.h>
#include <scanner.h>
#include <qdebug.h>

extern int yyparse();
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
    }else{
        std::cout << "Nel prro" << std::endl;
    }
}
