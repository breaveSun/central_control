#ifndef SPACE_H
#define SPACE_H
//房间
#include <QString>
#include <QVector>
class Light;
class Curtain;
class room
{
public:
    room();
    room(QString name,QString id);
    void addLight(Light* l);
    void addCurtain(Curtain* c);
private:
    //名称
    QString name_;
    //设备编号
    QString id_;
    //灯列表
    QVector<Light*> lights;
    //窗帘列表
    QVector<Curtain*> curtains;
};

#endif // SPACE_H
