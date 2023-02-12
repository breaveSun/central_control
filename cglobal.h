#ifndef CGLOBAL_H
#define CGLOBAL_H

#include <QFont>
#include <QFontDatabase>
class CGlobal
{
public:
    CGlobal();
    static QFont getIconfont();
    ~CGlobal();

public:

    static QFontDatabase fontDb;
    static QFont iconfont;
};

#endif // CGLOBAL_H
