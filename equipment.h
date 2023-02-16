#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <memory>
#include <QVariant>

typedef QList<QVariant> QVariantList;
class equipment
{
public:
    equipment();
    static QVariantMap getRoom(int houseId,int spaceId,int roomId);
    static QVariantMap getSpace(int houseId,int spaceId);

private:
    static bool init();
    static QVariantList getEquipment();

private:
    static QVariantList houses_;
};

#endif // EQUIPMENT_H
