#ifndef LIGHT_H
#define LIGHT_H
//灯
#include <common.h>

class Light
{
public:
    Light();
    void setId(QString id);
    void setName(QString name);
    void setSwitchStatus(int switchstatus);
    void setBrightness(int brightnessnum);
    void setColorTemp(int colortempnum);
    void setColor(int colornum);

private:
    //设备名称
    QString name_;
    //设备编号
    QString id_;
    //设备状态
    EquipmentSwitch switch_status_;
    //亮度
    int brightness_;
    //色温
    int color_temp_;
    //颜色
    int color_;
};

#endif // LIGHT_H
