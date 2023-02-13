#include "curtainThread.h"
#include <QThread>
#include <qdebug.h>

curtainThread::curtainThread()
{
//    runMutex_ = new QMutex;
    qDebug()<<__FUNCTION__;
}curtainThread::~curtainThread()
{

}
void curtainThread::Func(){
    qDebug()<<__FUNCTION__;
    {
        QMutexLocker locker(&runMutex_);
        running_ = true;
    }
    while(1){
        {
            QMutexLocker locker(&runMutex_);
            if(!running_){
                qDebug()<<"running = false";
                break;
            }
        }
        emit once();
        QThread::msleep(500);
        qDebug()<<"end sleep";

    }
}
bool curtainThread::isRunning()
{
    QMutexLocker locker(&runMutex_);
    return running_;
}

void curtainThread::stop()
{
    QMutexLocker locker(&runMutex_);
    running_ = false;
}
