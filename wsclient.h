#ifndef WSCLIENT_H
#define WSCLIENT_H
#include <QObject>
#include <QWebSocket>
#include "equipment.h"
class QTimer;
class wsClient : public QObject
{
    Q_OBJECT
public:
    wsClient(QObject *parent);
    ~wsClient();
    void ConnectTo(const QString url);

    void Disconnect();


signals:
    void notices(deviceDataStruct datas);

private slots:

    void sendTextMessage(const QString message);

    void sendBinaryMessage(const QByteArray data);

    void on_connected();

    void on_disconnected();

    void on_error(QAbstractSocket::SocketError error);

    void on_textMessageReceived(const QString& message);

    void reconnect();


private:
    QWebSocket *pWSClientObj_;
    QTimer *pTimer_;
    QString path_;
};

#endif // WSCLIENT_H
