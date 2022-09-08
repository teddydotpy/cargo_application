#include "../headers/network_ client.h"

#include <QTcpSocket>
#include <QHostAddress>
#include <QString>
#include <QByteArray>

static inline QByteArray IntToArray(qint32 source);

NetworkClient::NetworkClient(QObject *parent)
    :QTcpSocket(parent){

    connected = false;
}

NetworkClient::~NetworkClient(){

}

void NetworkClient::connect(quint16 port){
    QHostAddress home = QHostAddress("12.0.0.1");
    this->connectToHost(home, port);
    connected = this->waitForConnected(60000);
}

void NetworkClient::connect(QString &hostName, quint16 port){
    this->connectToHost(hostName, port);
    connected = this->waitForConnected(60000);
}

void NetworkClient::connect(QHostAddress &hostAddress, quint16 port){
    this->connectToHost(hostAddress, port);
    connected = this->waitForConnected(60000);
}

void NetworkClient::close(){
    this->close();
}

bool NetworkClient::write(QString data){
    QByteArray byte_data = data.toUtf8();
    if (this->state() == QAbstractSocket::ConnectedState){
        this->write(IntToArray(byte_data.size())); //write size of data
        this->write(byte_data); //write the data itself
        return this->waitForBytesWritten();
    }else{
        return false;
    }
}

QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}
