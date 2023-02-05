#include "space.h"
#include "light.h"

space::space()
{

}
space::space(QString name,QString id){
    name_= name;
    id_ = id;
}

void space::addLight(Light* l){
    lights.append(l);
}

void space::addCurtain(Curtain* c){
    curtains.append(c);
}
