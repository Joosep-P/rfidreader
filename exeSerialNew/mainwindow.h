#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Serialportreader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //variable for open button function
    void on_pushButton_clicked();
    //variable for close button function
    void on_pushButton_2_clicked();
    //variable for printing serialport reader data
    void showSerialportData();

private:
    Ui::MainWindow *ui;
    SerialPortReader *obj;
};
#endif // MAINWINDOW_H
