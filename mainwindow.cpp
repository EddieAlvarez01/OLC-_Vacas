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

QString path = "";

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
        ui->textEdit_2->setText("");
        ui->textEdit->setText("");
        Plotter *plot = new Plotter(raiz);
        plot->generarImagen();
        Travel *travel = new Travel();
        travel->Recorrer(raiz);
        travel->StartProgram();
        if(travel->semanticError.size() == 0){
            QString chain = "";
            for(int x=0; x<travel->consoleMsg.size(); x++){
                chain += travel->consoleMsg.at(x) + "\n";
            }
            ui->textEdit->setText(chain);
            QString syt = "";
            QHash<QString, Symbol*>::const_iterator i = travel->listClass.constBegin();
            while(i != travel->listClass.constEnd()){
                syt += "Clase:  id-> " + i.value()->id;
                if(i.value()->imports.size() > 0){
                    syt += " exportar -> ";
                    for(int x=0; x<i.value()->imports.size(); x++){
                        syt += i.value()->imports.at(x) + " ";
                    }
                }
                syt += "\n";
                QHash<QString, Symbol*>::const_iterator it = i.value()->propertys.constBegin();
                while(it != i.value()->propertys.constEnd()){
                    if(it.value()->role == "funcion"){
                        syt += "Funcion : id -> " + it.value()->id + "\n";
                    }else if(it.value()->role == "objeto"){
                        syt += "Objeto :  id -> " + it.value()->id + " Tipo -> " + it.value()->type + "Valor -> " + it.value()->path + "\n";
                    }else{
                        syt += "Variable : id -> " + it.value()->id +" Tipo -> " + it.value()->type + " Valor -> " + it.value()->value + "\n";
                    }
                    it++;
                }
                syt += "---------------------Termina Clase-------------------\n";
                i++;
            }
            ui->textEdit_2->setText(syt);

        }else{
            ui->textEdit->setText("Hay errores porfavor corrijalos");
            QString tb = "";
            for(int x=0; x<travel->semanticError.size(); x++){
                tb += "<tr>\n";
                tb += "<td>" + QString::number(x+1) + "</td>\n";
                tb += "<td>" + QString::number(travel->semanticError.at(x)->row) + "</td>\n";
                tb += "<td>" + QString::number(travel->semanticError.at(x)->column) + "</td>\n";
                tb += "<td>" + travel->semanticError.at(x)->type + "</td>\n";
                tb += "<td>" + travel->semanticError.at(x)->description + "</td>\n";
                tb += "</tr>\n";
            }
            QFile file("errors.html");
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream data(&file);
                data << "<!DOCTYPE html>" << endl;
                data << "<html lang=\"es\">" << endl;
                data << "<head>" << endl;
                data << "<meta charset=\"utf-8\">" << endl;
                data << "<title>Errores</title>" << endl;
                data << "<style>table.GeneratedTable { width: 100%; background-color: #ffffff; border-collapse: collapse; border-width: 2px; border-color: #000000; border-style: solid; color: #000000; } table.GeneratedTable td, table.GeneratedTable th { border-width: 2px; border-color: #000000; border-style: solid; padding: 3px; } table.GeneratedTable thead { background-color: #03fc6c; } </style>" <<endl;
                data << "</head>" << endl;
                data << "<body>" << endl;
                data << "<table class=\"GeneratedTable\">" << endl;
                data << "<thead>" << endl;
                data << "<tr>" << endl;
                data << "<th>No.</th>" << endl;
                data << "<th>Linea</th>" << endl;
                data << "<th>Columna</th>" << endl;
                data << "<th>Tipo</th>" << endl;
                data << "<th>Descripción</th>" << endl;
                data << "</tr>" << endl;
                data << "</thead>" << endl;
                data << "<tbody>" << endl;
                data << tb << endl;
                data << "</tbody>" << endl;
                data << "</table>" << endl;
                data << "</body>" << endl;
                data << "</html>" << endl;
            }
            file.close();
        }

    }else{
        std::cout << "Nel prro" << std::endl;
    }
}

void MainWindow::on_actionGenerar_AST_triggered()
{
    system("cmd /c start grafo.png");
}

void MainWindow::on_actionAbrir_Archivo_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/home/Eddie/Documents", "Text Files (*.tr)");
    path = fileName;
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(file.open(QFile::ReadOnly)){
            ui->textEdit_3->setPlainText(file.readAll());
        }else{

        }
    }
}

void MainWindow::on_actionCrear_Archivo_triggered()
{
    path = "";
    ui->textEdit_2->setText("");
    ui->textEdit->setText("");
    ui->textEdit_3->setText("");
}

void MainWindow::on_actionReporte_de_Errores_triggered()
{
     system("cmd /c start errors.html");
}

void MainWindow::on_actionGuardar_Archivo_triggered()
{
    QFile file(path);
     if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
         QTextStream data(&file);
         data << ui->textEdit_3->toPlainText() << endl;
     }
     file.close();
}

void MainWindow::on_actionGuardar_Como_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save file", "", ".tr");
    path = filename;
    if(!filename.isEmpty()){
        QFile file(filename);
         if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream data(&file);
             data << ui->textEdit_3->toPlainText() << endl;
         }
         file.close();
    }
}
