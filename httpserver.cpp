#include "httpserver.h"
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QtGlobal>
#include<QEventLoop>
#include<QTimer>
#include <QJsonArray>
httpServer::httpServer()
{

}

/**
 * @brief http发送和接收接口
 * @param strUrl HTTP网络URL
 * @param thod HTTP方法，GET或POST
 * @param strInput 发送的数据
 * @param strMessage http返回的错误信息
 * @param strResult http接收响应
 */
void httpServer::SendAndGetText(QString strUrl, QString thod, QString strInput, QString &strMessage, QString &strResult)
{
    QNetworkRequest oNetRequest;
    oNetRequest.setUrl(QUrl(strUrl));

    QNetworkAccessManager oNetAccessManager;
    QNetworkReply* oNetReply = nullptr;
    QByteArray inputTmp;

    if (thod == "POST")
    {
        oNetRequest.setRawHeader("Content-Type", "application/json");
        oNetReply = oNetAccessManager.post(oNetRequest, strInput.toLocal8Bit());
    }
    else if (thod == "GET" )
    {
        oNetReply = oNetAccessManager.get(oNetRequest);
    }

    // 添加超时处理，10s超时
    QEventLoop eventloop;
    connect(oNetReply, SIGNAL(finished()), &eventloop, SLOT(quit()));
    QTimer::singleShot(10000, &eventloop, &QEventLoop::quit);
    eventloop.exec();

    QByteArray array;
    if(oNetReply->isFinished())
    {
        if(oNetReply->error() == QNetworkReply::NoError)//正常结束，读取响应数据
        {
            strResult = oNetReply->readAll();
        }
        else//异常结束，比如不存在的http服务器，错误信息：Connection refused
        {
        }
    }
    else//超时,错误信息：Operation canceled
    {
        disconnect(oNetReply, &QNetworkReply::finished, &eventloop, &QEventLoop::quit);
        oNetReply->abort();
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<" timeout";
    }

    QNetworkReply::NetworkError e = oNetReply->error();
    if (e)
    {
        strMessage = oNetReply->errorString();
    }

    oNetReply->deleteLater();
}
//发起post请求 异步
void httpServer::postHttpRequest(QString url,QString data)
{
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));

    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setUrl(QUrl::fromUserInput(url));

    QNetworkReply* reply = naManager->post(request,data.toLocal8Bit());//发起post请求
}

//接收网络响应槽函数 异步
void httpServer::requestFinished(QNetworkReply *reply)
{
    QString loginResultJson;
    QByteArray bytes = reply->readAll();
    // 获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
    {
        qDebug() << "status code=" << statusCode.toInt();
    }

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError)
    {
        qDebug() << "Failed: " << reply->errorString();
    }
    else
    {
        // 获取返回内容
        qDebug() << "loginResultJson  is  " <<  QString::fromStdString(bytes.toStdString());
        loginResultJson =  QString::fromStdString(bytes.toStdString());
        //处理返回数据
    }
}

