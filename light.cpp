#include "light.h"

Light::Light()
{
}

void Light::setId(QString id){
    id_ = id;
}
void Light::setName(QString name){
    name_ = name;
}
void Light::setSwitchStatus(int switchstatus){
    switch_status_ = EquipmentSwitch(switchstatus);
}
void Light::setBrightness(int brightnessnum){
    brightness_ = brightnessnum;
}
void Light::setColorTemp(int colortempnum){
    color_temp_ = colortempnum;
}
void Light::setColor(int colornum){
    color_ = colornum;
}
