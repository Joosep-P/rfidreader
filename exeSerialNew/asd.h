#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class serialPortReader:public QObject
{
    Q_OBJECT

public:
    serialPortReader(QObject *parent = nullptr);
    ~serialPortReader();

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
