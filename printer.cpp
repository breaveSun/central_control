#include "printer.h"
#include <qdebug.h>
#include <QRegularExpression>

printer::printer()
{

}

printer::printer(QProcess *obj):m_caller( obj )
{}

printer::~printer()
{
    delete m_caller;
}

void printer::print(int)
{
    QString data = m_caller->readAllStandardOutput();
    //字符串截取
    QStringList list = data.split(" ");
    for( QString item : list )
    {
        if(item[0] == '#'){
            QString uid = item.mid(1,item.length()-1);
            emit myUid(uid);
            return;
        }
    }

}
