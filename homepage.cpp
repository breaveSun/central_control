#include "homepage.h"
#include "ui_homepage.h"
#include "roomcard.h"
#include "equipment.h"
#include "common.h"
#include "icon.h"
#include "changespace.h"

homePage::homePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homePage)
{
    ui->setupUi(this);
    //切换空间
    pChangeSpace_ = new changeSpace(this);
    pChangeSpace_->setWindowOpacity(0.95);
    connect(pChangeSpace_,SIGNAL(changeSpaceHide()),this,SLOT(spaceChangeWidgetHide()));
    connect(pChangeSpace_,SIGNAL(updateRooms(int,int)),this,SLOT(updateRooms(int,int)));

    ui->spaceChanged->setIcon("drop_down",20);
    connect(ui->spaceChanged,SIGNAL(btnClicked(bool)),this,SLOT(spacesChange(bool)));

    //图标样式
    Common::setLabelIcon(ui->locationIcon,icon::getIcon("location"),20);
    ui->locationName->setText("拱墅区");
    Common::setLabelIcon(ui->weatherIcon,icon::getIcon("cloudy_to_clear"),20);
    ui->weatherTxt->setText("15°C");
    Common::setButtonIcon(ui->msg,icon::getIcon("msg"));
    Common::setButtonIcon(ui->personalCenter,icon::getIcon("my"));

    //加载页面数据
    setData(houseId_,spaceId_);

    //关闭全部设备
    ui->closeAllDevices->setCheckable(true);
    connect(ui->closeAllDevices,SIGNAL(clicked(bool)),this,SLOT(closeAllDevices(bool)));
    //消息列表
    connect(ui->msg,SIGNAL(clicked(bool)),this,SLOT(messageList(bool)));



}

homePage::~homePage()
{
    delete ui;
}

void homePage::setData(int houseId,int spaceId)
{
//    //获取房子和空间名称
    QString houseName;
    QString spaceName;

    houseData_ = equipment::getEquipment();
    for (int i=0;i<houseData_->size();i++) {
        houseStruct house = houseData_->at(i);
        if(houseId == 0){
            houseName = house.name;
            houseId_ = house.id;
            spaceStruct space = house.spaces[0];
            spaceName = space.name;
            spaceId_ = space.id;
            spaceData_ = space;
            break;
        }
        if(houseId == house.id){
            houseName = house.name;
            houseId_ = house.id;
            QVector<spaceStruct> spaces = house.spaces;
            if(spaceId == 0){
                spaceId_ = spaces[0].id;
                spaceName = spaces[0].name;
                break;
            }
            for(int j =0;j<spaces.size();j++){
                spaceStruct space = spaces[i];
                if(spaceId == space.id){
                    spaceName = space.name;
                    spaceId_ = space.id;
                    spaceData_ = space;
                    break;
                }
            }
        }
    }

    //给下拉菜单按钮设置文字
    ui->spaceChanged->setTxt(houseName+spaceName);

    //获取房间数据 更新房间列表
    QVector<roomStruct> rooms = spaceData_.rooms;
    int roomSize = rooms.size();
    int roomWidgetSize = roomCardWidgetList_.size();

    if(roomWidgetSize<roomSize){
        while(roomSize>roomWidgetSize){
            roomCard* rc = new roomCard(this);
            roomCardWidgetList_.append(rc);
            ui->scrollAreaWidgetContents->layout()->addWidget(rc);
            roomWidgetSize++;
        }
    }

    if(roomSize<roomWidgetSize){
        int removeNum = roomWidgetSize-roomSize;
        while(roomWidgetSize>roomSize){
            ui->scrollAreaWidgetContents->layout()->removeWidget(roomCardWidgetList_[roomWidgetSize-1]);
            roomWidgetSize--;
        }
        roomCardWidgetList_.remove(roomSize-1,removeNum);
    }

    for (int i=0;i<roomSize;i++) {
        roomCard * room = roomCardWidgetList_[i];
        roomStruct roomS = rooms[i];
        //名称
        room->setData(roomS);
        connect(room,SIGNAL(goPage(PageBack,int,int,int)),this,SIGNAL(goPage(PageBack,int,int,int)));

    }

    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());

}

void homePage::spacesChange(bool clicked){
    if(clicked){
        QPoint pos = this->mapToGlobal(ui->roomsScrollArea->pos());
        pChangeSpace_->setGeometry(pos.x(),pos.y(),ui->roomsScrollArea->width(),ui->roomsScrollArea->height());
        pChangeSpace_->setData(houseData_,houseId_,spaceId_);
        pChangeSpace_->show();
        ui->spaceChanged->setIcon("pull_up",20);
    } else {
        pChangeSpace_->hide();
        ui->spaceChanged->setIcon("drop_down",20);
    }
}

void homePage::spaceChangeWidgetHide(){
    if (pChangeSpace_ != nullptr && ui->spaceChanged->isChecked())
    {
        ui->spaceChanged->setChecked(false);
        ui->spaceChanged->setIcon("drop_down",20);
    }
    QRect closeAllDeviceRect = QRect(ui->closeAllDevices->pos().x()+ui->spacesCloseAll->pos().x()
                                     ,ui->closeAllDevices->pos().y()+ui->spacesCloseAll->pos().y()
                                     ,ui->closeAllDevices->width()
                                     ,ui->closeAllDevices->height());
   if(closeAllDeviceRect.contains(this->mapFromGlobal(QCursor::pos()))){
        qDebug()<<"触发关闭全部按钮的信号";
        //触发关闭全部按钮的信号
        closeAllDevices(true);
    }

}

void homePage::updateRooms(int houseId,int spaceId){
    ui->scrollAreaWidgetContents->show();
    setData(houseId,spaceId);
    ui->scrollAreaWidgetContents->show();
}

void homePage::closeAllDevices(bool checked){
    qDebug()<<__FUNCTION__<<checked;
    QVariantList lightData;
    QVariantList curtainData;
    for (int r=0;r<spaceData_.rooms.size();r++) {
        roomStruct room = spaceData_.rooms[r];
        for (int i=0;i<room.lighting.size();i++){
            QVariantMap lightMap;
            lightMap["group_id"] = room.lighting[i].Switch;
            lightMap["switch"] = "0";

            lightData.append(lightMap);
        }
        for (int i=0;i<room.curtain.size();i++){
            QVariantMap curtainMap;
            curtainMap["group_id"] = room.curtain[i].Switch;
            curtainMap["switch"] = "0";

            curtainData.append(curtainMap);
        }
    }

    QString jsonStr = Common::ListToString(lightData);
    equipment::lightControl(jsonStr);

    jsonStr = Common::ListToString(curtainData);
    equipment::curtainControl(jsonStr);

    for (int i=0;i<roomCardWidgetList_.size();i++) {
        roomCardWidgetList_[i]->setEnableDeviceNum("0");
    }
}

void homePage::messageList(bool checked){
    emit goPage(PB_GO_MESSAGE_CENTER,0,0,0);
}
void homePage::acceptPush(deviceDataStruct data){
    qDebug()<<__FUNCTION__;

    qDebug()<<"key:"<<data.groupId
           <<"value:"<<data.value
            <<"deviceType:"<<data.deviceType
            <<"functionType:"<<data.functionType
           <<"build_id:"<<data.houseId
          <<"spaceId:"<<data.spaceId
         <<"roomId:"<<data.roomId;

    if (data.functionType == FT_SWITCH && spaceData_.build_id == data.houseId && spaceData_.id == data.spaceId){
        for (int i=0;i<roomCardWidgetList_.size();i++) {
            roomCard* roomCard = roomCardWidgetList_[i];
            qDebug()<<"card room id"<<roomCard->getRoomId();
            if(roomCard->getRoomId() == data.roomId){
                roomCard->updateEnableDeviceNum();
                break;
            }
        }
    }
}

