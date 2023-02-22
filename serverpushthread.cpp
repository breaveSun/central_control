#include "serverpushthread.h"
#include <QThread>
#include <qdebug.h>

serverPushThread::serverPushThread()
{
    qRegisterMetaType<deviceDataStructMap>("deviceDataStructMap");
}

serverPushThread::~serverPushThread()
{

}
void serverPushThread::Func(){
    qDebug()<<__FUNCTION__;
    {

        QMutexLocker locker(&mapMutex_);
        isCanRun_ = true;
    }
    while(1){
        {

            {
                QMutexLocker locker(&mapMutex_);
                if(!isCanRun_){
                    break;
                    //断开长链接
                }
            }

            QMap<QString,deviceDataStruct> datas;
            deviceDataStruct d;
            {
                QMutexLocker locker(&mapMutex_);
                d = equipment::getDeviceStruct("1/4/13");
                equipment::setDeviceStruct("1/4/13","0");

                qDebug()<<"d.value = "<<d.value;
                d.value = "0";

            }
            datas["1/4/13"] = d;

            qDebug()<<"before emit"<<d.value;
            emit notices(datas);
            qDebug()<<"after emit";
            QThread::msleep(5000);
            qDebug()<<"after sleep";
        }


    }
}
