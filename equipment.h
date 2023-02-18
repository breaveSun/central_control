#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <memory>
#include <QVariant>


typedef struct lightingFuncStruct{
    int Switch;
    int dimming;
    int hue;
    int color_temperature;
}lightingFuncStruct;
Q_DECLARE_METATYPE(lightingFuncStruct)

typedef struct lightingStruct {
    QString name;
    int id;
    int project_id;
    int build_id;
    int space_id;
    int room_id;
    QString icon;
    lightingFuncStruct function;
    QString Switch;
    QString switch_feedback;
    QString switch_value;
    QString dimming_relative;
    QString dimming_absolute;
    QString dimming_absolute_feedback;
    QString dimming_absolute_value;
    QString hue;
    QString hue_feedback;
    QString hue_value;
    QString color_temperature;
    QString color_temperature_feedback;
    QString color_temperature_value;
    QString min_color_temperature;
    QString max_color_temperature;
}lightingStruct;
Q_DECLARE_METATYPE(lightingStruct)

typedef struct curtainFuncStruct{
    int Switch;
    int position;
    int angle;
}curtainFuncStruct;
Q_DECLARE_METATYPE(curtainFuncStruct)

typedef struct curtainStruct{
    QString name;
    int id;
    int project_id;
    int build_id;
    int space_id;
    int room_id;
    QString icon;
    QString direction;
    curtainFuncStruct function;
    QString Switch;
    QString switch_feedback;
    QString switch_value;
    QString position;
    QString position_feedback;
    QString position_value;
    QString stop;
}curtainStruct;
Q_DECLARE_METATYPE(curtainStruct)

typedef struct roomParamStruct{
    QString name;
    QString title;
    QString value;
    QString unit;
}roomParamStruct;
Q_DECLARE_METATYPE(roomParamStruct)

typedef struct roomSceneStruct{
    QString name;
    QString icon;
}roomSceneStruct;
Q_DECLARE_METATYPE(roomSceneStruct)


typedef struct roomStruct{
    QString name;
    int id;
    int project_id;
    int build_id;
    int space_id;
    QString icon;
    QVector<roomParamStruct> params;
    QVector<roomSceneStruct> scene;
    QVector<lightingStruct> lighting;
    QVector<curtainStruct> curtain;
}roomStruct;
Q_DECLARE_METATYPE(roomStruct)


typedef struct spaceStruct{
    QString name;
    int id;
    int project_id;
    int build_id;
    QVector<roomStruct> rooms;
}spaceStruct;
Q_DECLARE_METATYPE(spaceStruct)


typedef struct houseStruct{
    QString name;
    int id;
    int project_id;
    QVector<spaceStruct> spaces;
}houseStruct;
Q_DECLARE_METATYPE(houseStruct)


typedef QList<QVariant> QVariantList;
class equipment
{
public:
    equipment();
    static bool init();
    static QVector<houseStruct>* getEquipment();
    static roomStruct getRoom(int houseId,int spaceId,int roomId);
    static spaceStruct getSpace(int houseId,int spaceId);
    static void getHouseSpaceName(int &houseId,int &spaceId,QString &houseName,QString &spaceName);

    //控制灯发请求
    static void lightControl(QString data);

    //控制窗帘发请求
    static void curtainControl(QString data);

private:
    static QMap<QString,QString> getDeviceData();

private:
    static QVector<houseStruct> houses_;
    static QVariantMap devicesData_;
};

#endif // EQUIPMENT_H
