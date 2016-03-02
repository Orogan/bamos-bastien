#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    //DeclenchementDeMesure();
    RecuperationMesure();
}

void MainWindow::readData()
{
    QByteArray data2 = serial->readAll();
    qDebug() << data2;
}

void MainWindow::DeclenchementDeMesure()
{
    QByteArray data1;
    //Message à envoyé
    data1[0] = 0x2A;
    data1[1] = 0x54;
    data1[2] = 0x52;
    data1[3] = 0x47;

    //Retour chariot
    data1[4] = 0x0D;

    if (serial->open(QIODevice::ReadWrite))
    {
        serial->write(data1);
    }
}

void MainWindow::RecuperationMesure()
{
    QByteArray data1;

    //Message à envoyé
    data1[0] = 0x56;
    data1[1] = 0x41;
    data1[2] = 0x4C;
    data1[3] = 0x31;
    data1[4] = 0x3F;

    //Retour chariot
    data1[5] = 0x0D;

    if (serial->open(QIODevice::ReadWrite))
    {
        serial->write(data1);
    }
}
