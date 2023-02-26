#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <memory>
#include <QVariant>
#include <QVector>
enum DEVICE_TYPE{
    DT_LIGHT,//灯
    DT_CURTAIN,//窗帘
};

enum FUNCTION_TYPE{
    //通用
    FT_SWITCH,//开关
    //灯
    FT_BRIGHTNESS,//亮度
    FT_HUE,
    FT_COLOR_TEMPERATURE,
    //窗帘
    FT_ANGLE,
    FT_OC_DEGREE,
    FT_STOP
};

//通知结构体
typedef struct deviceDataStruct{
    int houseId;
    int spaceId;
    int roomId;
    QString groupId;
    QString value;  //数据值
    DEVICE_TYPE deviceType; //设备类型
    FUNCTION_TYPE functionType; //数据类型 例如 灯的开关functionType=switch
} deviceDataStruct;
Q_DECLARE_METATYPE(deviceDataStruct)

//页面布局结构体
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
//    QString switch_value;
    QString dimming_relative;
    QString dimming_absolute;
    QString dimming_absolute_feedback;
//    QString dimming_absolute_value;
    QString hue;
    QString hue_feedback;
//    QString hue_value;
    QString color_temperature;
    QString color_temperature_feedback;
//    QString color_temperature_value;
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
//    QString switch_value;
    QString position;
    QString position_feedback;
//    QString position_value;
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

typedef struct roomSceneLightsStruct{
    int id;
    QString brightness_value;
    QString color_temperature_value;
    QString hue_value;
}roomSceneLightsStruct;
Q_DECLARE_METATYPE(roomSceneLightsStruct)

typedef struct roomSceneCurtainsStruct{
    int id;
    QString angle_value;
    QString oc_degree_value;
}roomSceneCurtainsStruct;
Q_DECLARE_METATYPE(roomSceneCurtainsStruct)

typedef struct roomSceneStruct{
    QString id;
    int room_id;
    QString name;
    QString icon;
    QString type;
    QVector<roomSceneLightsStruct> lights;
    QVector<roomSceneCurtainsStruct> curtains;
}roomSceneStruct;
Q_DECLARE_METATYPE(roomSceneStruct)


typedef struct roomStruct{
    QString name;
    int id;
    int project_id;
    int build_id;
    int space_id;
    QString icon;
    QString current_scene;
    QVector<roomParamStruct> params;
    QVector<roomSceneStruct> scenes;
    QVector<lightingStruct> lights;
    QVector<curtainStruct> curtains;
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

    //切换场景请求
    static void changeScene(int roomId,QString sceneId);

    static QString getDeviceValue(QString key);
    static void setDeviceStruct(QString key,QString value);
    static deviceDataStruct getDeviceStruct(QString key);
    static void setDeviceStruct(QString key,deviceDataStruct value);
    static QMap<QString,deviceDataStruct> deviceDataStructs_;//全局的设备数据

public:

private:
    //从api获取device数据
    static QMap<QString,QString> getDeviceData();
    //从api获取页面配置
    static QVariantList getConfigData();

private:
    static QVector<houseStruct> houses_;
};

#endif // EQUIPMENT_H
