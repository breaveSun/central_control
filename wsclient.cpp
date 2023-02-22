#include "wsclient.h"
#include "common.h"
#include <QWebSocket>
#include <QTimer>
#include <QJsonParseError>
#include <QJsonObject>

wsClient::wsClient(QObject *parent): QObject(parent)
{
    pTimer_ = new QTimer();
    pWSClientObj_ = new QWebSocket;   //构造函数未设置参数和指定父对象
    pWSClientObj_->setParent(this);   //这里必须设置父对象，否则多线程运行报错
    //客户端需要处理的信号：连接成功、断开连接、发生错误、收到消息
    connect(pWSClientObj_, &QWebSocket::connected, this, &wsClient::on_connected);
    connect(pWSClientObj_, &QWebSocket::disconnected, this, &wsClient::on_disconnected);
    connect(pWSClientObj_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(on_error(QAbstractSocket::SocketError)));
    connect(pWSClientObj_, &QWebSocket::textMessageReceived, this, &wsClient::on_textMessageReceived);
    connect(pTimer_,SIGNAL(timeout()),this,SLOT(reconnect()),Qt::AutoConnection);
}
wsClient::~wsClient(){

}

//连接服务端
void wsClient::ConnectTo(const QString url)
{
    path_ = url;
    pWSClientObj_->open(QUrl(url));
}
//断开连接
void wsClient::Disconnect()
{
    pWSClientObj_->close();
}
 //发消息，字符串
void wsClient::sendTextMessage(const QString message)
{
    pWSClientObj_->sendTextMessage(message);
}
 //发消息，二进制
void wsClient::sendBinaryMessage(const QByteArray data)
{
    pWSClientObj_->sendBinaryMessage(data);
}
 //连接成功，通知UI
void wsClient::on_connected()
{
    pTimer_->stop();
    qDebug()<<"websocket connect success";
}
 //断开连接，通知UI
void wsClient::on_disconnected()
{
    pTimer_->start(3000);
    qDebug()<<"websocket is disconnected";
}
 //报错，通知UI
void wsClient::on_error(QAbstractSocket::SocketError error)
{
    qDebug()<<"error message:" + pWSClientObj_->errorString() + "\nerror code:" + QString::number(error);
}
 //接收消息，通知UI
void wsClient::on_textMessageReceived(const QString& message)
{
    qDebug()<<"receive::"+message;
    //灯开关
//    QString selfMsg = "{\"type\":\"device\",\"data\":{\"1/4/13\":\"0\"}}";
    //灯亮度
//    QString selfMsg = "{\"type\":\"device\",\"data\":{\"1/5/14\":\"77\"}}";
//    //灯色温
//    QString selfMsg = "{\"type\":\"device\",\"data\":{\"1/0/14\":\"3300\"}}";
//    //灯颜色
//    QString selfMsg = "{\"type\":\"device\",\"data\":{\"1/7/14\":\"00FF00\"}}";
    //窗帘开关
//        QString selfMsg = "{\"type\":\"device\",\"data\":{\"3/4/1\":\"0\"}}";
//        //窗帘开合度
//        QString selfMsg = ""{\"type\":\"device\",\"data\":{\"3/5/1\":\"86\"}}";

    QString selfMsg = "{\"type\":\"message\",\"data\":{\"id\":69,\"title\":\"系统消息\",\"date_time\":\"2023/01/05 12:30\",\"content\":\"【系统升级】有升级啦！千峰智能空间系统2.0版本已经下载成功，我们将在今晚的8点正式为您更新。\",\"icon\":\"info\",\"status\":0,\"type\":0}}";



    QVariantMap mapV = Common::StringToVariantMap(selfMsg);
    QString type = mapV["type"].toString();
    if(type == "message"){
        QVariantMap messageMap = mapV["data"].toMap();
        messageStruct message;
        message.id = messageMap["id"].toInt();
        message.title = messageMap["title"].toString();
        message.dateTime = messageMap["date_time"].toString();
        message.content = messageMap["content"].toString();
        message.icon = messageMap["icon"].toString();
        message.status = 0;
        message.type = messageMap["type"].toInt();
        emit notices(message);
    }else if(type == "device"){
        QVariantMap deviceMap = mapV["data"].toMap();
        QVariantMap::iterator iter;
         for(iter=deviceMap.begin(); iter!=deviceMap.end(); iter++){
             equipment::setDeviceStruct(iter.key(),iter.value().toString());
             deviceDataStruct deviceData = equipment::getDeviceStruct(iter.key());
             deviceData.value = iter.value().toString();
             emit notices(deviceData);
         }
    }

}

void wsClient::reconnect()
{
    qDebug()<<"websocket reconnected";
    pWSClientObj_->abort();
    pWSClientObj_->open(QUrl(path_));
}

