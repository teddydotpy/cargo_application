#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H
#include <QTcpSocket>

class QString;
class QHostAddress;
class QObject;
class NetworkClient: public QTcpSocket{

    public:
        NetworkClient(QObject *parent = nullptr);
        ~NetworkClient();

        void connect();
        void connect(QString &hostName, quint16 port);
        void connect(QHostAddress &hostAddress, quint16 port);
        bool writeToServer(QString data);

    private:
        bool connected;
};

#endif