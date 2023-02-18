#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include "common.h"

class httpServer : public QObject
{
    Q_OBJECT
public:
    httpServer();
    static void SendAndGetText(QString strUrl, QString thod, QString strInput, QString &strMessage, QString &strResult);
    static void SendJson(QString strUrl, QString thod, QString strInput, QString &strMessage, QString &strResult);
};

#endif // HTTPSERVER_H
