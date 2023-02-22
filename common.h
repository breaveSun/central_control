#ifndef COMMON_H
#define COMMON_H

#include <QCloseEvent>
#include <QString>
#include <iostream>
#include <qdebug.h>
#include <QFont>
#include <QFontDatabase>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QJsonDocument>
#include <QJsonObject>
#include <equipment.h>
#include <icon.h>
#include <QNetworkInterface>

enum  EquipmentSwitch {
    ES_LOST_CONTACT,  //断开连接
    ES_ON,//开启
    ES_OFF//关闭
};

enum PageBack {
    PB_GO_MAIN, //主页（测试）
    PB_GO_HOME, //主页
    PB_GO_LIGHT_PAGE, //照明控制
    PB_GO_CURTAIN_PAGE, //遮光控制
    PB_GO_CTRLLIST_PAGR, //设备控制
    PB_GO_MESSAGE_CENTER //消息列表页
};


typedef struct messageStruct{
    int id;
    QString title;
    QString dateTime;
    QString content;
    QString icon;
    int status;
    int type;
}messageStruct;
Q_DECLARE_METATYPE(messageStruct)

class Common{
public:
    static QFont loadIcon(int size){
        //加入字体，并获取字体ID
        int fontId = QFontDatabase::addApplicationFont(":/resource/iconfont.ttf");
        //获取字体名称
        QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont iconFont = QFont(fontName);
        iconFont.setPixelSize(size);
        return iconFont;
    }

    static void setLabelIcon(QLabel * obj,int icon,int size=30){
        obj->setStyleSheet("font-family: iconfont");
        obj->setFont(Common::loadIcon(size));
        obj->setText(QChar(icon));
    }

    static void setButtonIcon(QPushButton * obj,int icon,int size=30){
        obj->setStyleSheet("font-family: iconfont");
        obj->setFont(Common::loadIcon(size));
        obj->setText(QChar(icon));
    }

    static QVariantMap StringToVariantMap(const QString& str)
    {
        QByteArray njba = str.toUtf8();
        QJsonParseError json_error;

        QJsonDocument json_doc = QJsonDocument::fromJson(str.toUtf8(), &json_error);

        if (json_error.error != QJsonParseError::NoError)
        {
            qDebug()<<"parse json error "<<json_error.error;
            return QVariantMap{};
        }

        QJsonObject nobj = QJsonObject(json_doc.object());
        QVariantMap query = nobj.toVariantMap();
        return query;
    }

    static QString ListToString(QVariantList vtmap)
    {
        QJsonDocument doc = QJsonDocument::fromVariant(QVariant(vtmap));
        //QByteArray jba = doc.toJson();
        QByteArray jba = doc.toJson(QJsonDocument::Compact);
        QString jsonString = QString(jba);
        return jsonString;
    }

    static QString getHostMacAddress()
    {
            QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
            int nCnt = nets.count();
//            qDebug()<<nets;
            QString strMacAddr = "";
            for(int i = 0; i < nCnt; i ++)
            {
                // 如果此网络接口被激活并且正在运行并且不是回环地址，且该mac的ip地址不能是回环地址并且是ipv4地址，则就是我们需要找的Mac地址
                if(nets[i].flags().testFlag(QNetworkInterface::IsUp) &&
                   nets[i].flags().testFlag(QNetworkInterface::IsRunning)
                   && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
                {
                    for (int j=0;j<nets[i].addressEntries().size() ;j++ ) {
                    //该mac的ip地址不能为172.0.0.1，且需是ipv4地址
                    if(nets[i].addressEntries().at(j).ip()!=QHostAddress::LocalHost&&nets[i].addressEntries().at(j).ip().protocol()== QAbstractSocket::IPv4Protocol
    ){
                            strMacAddr = nets[i].hardwareAddress();
                        }
                    }
                }
            }
            qDebug()<<"strMacAddr:"<<strMacAddr;
            return strMacAddr;
    }

};

#endif // COMMON_H
