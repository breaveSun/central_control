#ifndef PRINTER_H
#define PRINTER_H


#include <QObject>
#include <QProcess>
class printer: public QObject
{
    Q_OBJECT
public:
    printer();

    printer( QProcess *obj );
    virtual ~printer();
signals:
    void myUid(QString uid);
public slots:
    void print(int);

private:
    QProcess *m_caller;

};

#endif // PRINTER_H
