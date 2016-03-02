#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void readData();
    void DeclenchementDeMesure();
    void RecuperationMesure();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
};

#endif // MAINWINDOW_H
