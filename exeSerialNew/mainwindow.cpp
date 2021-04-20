#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    obj = new SerialPortReader;

    connect(obj, SIGNAL(serialportDataReadDone()),

                this,SLOT(showSerialportData()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete obj;
    obj = nullptr;

    qDebug() << "objectMySerialPortReader destroyed";



    delete ui;
    ui = nullptr;
    qDebug() << "ui destroyed";
}



void MainWindow::on_pushButton_clicked()
{
    obj->openSerialPort();

}

void MainWindow::on_pushButton_2_clicked()
{
    obj->closeSerialPort();
}
//takes serialport data and prints it to labelData
void MainWindow::showSerialportData()
{
    QString serialportData;

    serialportData = obj->returnSerialportData();

    ui->labelData->setText(serialportData);

}




