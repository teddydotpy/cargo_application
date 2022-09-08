#ifndef NETWORKCLIENT_H
#define NETOWRKCLIENT_H
#include <QTcpSocket>

class QString;
class QHostAddress;
class QObject;
class NetworkClient: public QTcpSocket{

    public:
        NetworkClient(QObject *parent = nullptr);
        ~NetworkClient();

        void connect(quint16 port);
        void connect(QString &hostName, quint16 port);
        void connect(QHostAddress &hostAddress, quint16 port);
        void close();
        bool write(QString data);

    private:
        bool connected;
};

#endif