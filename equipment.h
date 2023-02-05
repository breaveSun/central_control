#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <QVector>
class space;
class equipment
{
public:
    equipment();
    bool init();
    QVector<space*> spaces;
};

#endif // EQUIPMENT_H
