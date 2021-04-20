#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>
#include "serialportreader_global.h"


class SerialPortReader:public QObject
{
    Q_OBJECT

public:
    SerialPortReader(QObject *parent = nullptr);
    ~SerialPortReader();

    void openSerialPort();
    void closeSerialPort();

    QString returnSerialportData();
private:
    QSerialPort *objectQSerialPort = nullptr;
    QString serialportData;
private slots:
    void readSerialPort();

signals:
void serialportDataReadDone();

};

#endif // SERIALPORTREADER_H
