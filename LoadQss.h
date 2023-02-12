#ifndef LOADQSS_H
#define LOADQSS_H
#include <QFile>
#include <QApplication>

class LoadQss
{
public:
    static void loadQss(const QString &path)
    {
        QFile qss(path);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

#endif // LOADQSS_H
