#ifndef SERVERPUSHTHREAD_H
#define SERVERPUSHTHREAD_H

#include <QObject>
#include <QMutex>
#include "equipment.h"
typedef QMap<QString,deviceDataStruct> deviceDataStructMap;
class serverPushThread : public QObject
{
    Q_OBJECT
public:
    serverPushThread();
    ~serverPushThread();

    void stop();
    void Func();

signals:
    void notices(QMap<QString,deviceDataStruct> datas);

private slots:

private:
    QMutex mapMutex_;
    bool isCanRun_;
};
/*
 * 使用方法
 *
 *
 *
.h

class serverPushThread;

serverPushThread *pServerPushThread_;
QThread *pWorkerThread_;

.cpp
//接受服务器消息
pServerPushThread_ = new serverPushThread;
pWorkerThread_ = new QThread;
pServerPushThread_->moveToThread(pWorkerThread_);
connect(pWorkerThread_,&QThread::finished,pWorkerThread_,&QObject::deleteLater);
connect(pWorkerThread_,&QThread::finished,pServerPushThread_,&QObject::deleteLater);
connect(this,&MainWindow::startThreadWork,pServerPushThread_,&serverPushThread::Func);
qDebug()<<"connect:"<<connect(pServerPushThread_,SIGNAL(notices(QMap<QString,deviceDataStruct>))
                  ,pHomePage_,SLOT(acceptPush(QMap<QString,deviceDataStruct>)));
connect(pServerPushThread_,SIGNAL(notices(QMap<QString,deviceDataStruct>))
        ,pHomePage_,SLOT(acceptPush(QMap<QString,deviceDataStruct>)));
pWorkerThread_->start();
//    emit startThreadWork();


//接收服务器推送
void acceptPush(QMap<QString,deviceDataStruct> datas);
*/
#endif // SERVERPUSHTHREAD_H
