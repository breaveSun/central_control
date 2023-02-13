#include "space.h"
#include "light.h"

room::room()
{

}
room::room(QString name,QString id){
    name_= name;
    id_ = id;
}

void room::addLight(Light* l){
    lights.append(l);
}

void room::addCurtain(Curtain* c){
    curtains.append(c);
}
