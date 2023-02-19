#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include "common.h"
class QNetworkReply;
class httpServer : public QObject
{
    Q_OBJECT
public:
    httpServer();
    static void SendAndGetText(QString strUrl, QString thod, QString strInput, QString &strMessage, QString &strResult);
    void postHttpRequest(QString url,QString data);
    void requestFinished(QNetworkReply *reply);
};

#endif // HTTPSERVER_H
