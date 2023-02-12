#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QMutex>

class curtainThread : public QObject
{
    Q_OBJECT
public:
    curtainThread();
    ~curtainThread();

    void stop();

    void Func(void);

private:
    bool running_;
    QMutex runMutex_;

signals:
    void once();
};

#endif // MYTHREAD_H
