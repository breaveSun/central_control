#include "curtain.h"

Curtain::Curtain()
{

}

void Curtain::setId(QString id){
    id_ = id;
}
void Curtain::setName(QString name){
    name_ = name;
}
void Curtain::setSwitchStatus(int switchstatus){
    switch_status_ = EquipmentSwitch(switchstatus);
}
void Curtain::setShadingArea(int shadingareanum){
    shading_area_ = shadingareanum;
}
