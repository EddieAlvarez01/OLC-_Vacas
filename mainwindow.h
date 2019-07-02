#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCompilar_triggered();

    void on_actionGenerar_AST_triggered();

    void on_actionAbrir_Archivo_triggered();

    void on_actionCrear_Archivo_triggered();

    void on_actionReporte_de_Errores_triggered();

    void on_actionGuardar_Archivo_triggered();

    void on_actionGuardar_Como_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
