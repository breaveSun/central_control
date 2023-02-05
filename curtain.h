#ifndef CURTAIN_H
#define CURTAIN_H
//窗帘
#include <common.h>

class Curtain
{
public:
    Curtain();
    void setId(QString id);
    void setName(QString name);
    void setSwitchStatus(int switchstatus);
    void setShadingArea(int shadingareanum);
private:
    //设备名称
    QString name_;
    //设备编号
    QString id_;
    //设备状态
    EquipmentSwitch switch_status_;
    //遮光率（窗帘拉上的比例）
    int shading_area_;
};

#endif // CURTAIN_H
