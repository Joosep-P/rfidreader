#include "serialportreader.h"




serialPortReader::serialPortReader(QObject *parent) : QObject(parent)

{

    objectQSerialPort = new QSerialPort;



    connect (objectQSerialPort, SIGNAL(readyRead()), this, SLOT(readSerialPort()));

    //connect(objectQSerialPort, &QSerialPort::readyRead, this, &MySerialPortReader::readSerialPort);

}



serialPortReader::~serialPortReader()

{

    delete objectQSerialPort;

    objectQSerialPort = nullptr;

    qDebug () << "objectQSerialPort destroyed";

}



void serialPortReader::openSerialPort()

{

    objectQSerialPort->setPortName("COM8");

    objectQSerialPort->setBaudRate(QSerialPort::Baud9600);

    objectQSerialPort->setDataBits(QSerialPort::Data8);

    objectQSerialPort->setParity(QSerialPort::NoParity);

    objectQSerialPort->setStopBits(QSerialPort::OneStop);

    objectQSerialPort->setFlowControl(QSerialPort::NoFlowControl);



    if (objectQSerialPort->open(QIODevice::ReadWrite))

    {

        qDebug () << "Serial port open";

    }

    else

    {

        qDebug () << "Fail to open serial port";

    }

}



QString serialPortReader::returnSerialportData()

{

    return serialportData;


}



void serialPortReader::readSerialPort()

{

    qDebug() << "Reading data from serial port";

    serialportData="";

    serialportData=objectQSerialPort->readAll();

    serialportData.remove(0,3);

    serialportData.chop(3);

    qDebug() << serialportData;

    qDebug() << "EMIT dataReadDone";

    emit serialportDataReadDone();

}



void serialPortReader::closeSerialPort()

{

    objectQSerialPort->close();

    qDebug () << "Serial port closed";

}

