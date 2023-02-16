#include "homepage.h"
#include "ui_homepage.h"
#include "roomcard.h"
#include "equipment.h"
#include "common.h"
#include "icon.h"

homePage::homePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homePage)
{
    ui->setupUi(this);
    pSpacesChange_ = new QWidget(this);
    pSpacesChange_->setVisible(false);
    Common::setLabelIcon(ui->locationIcon,icon::getIcon("location"),20);
    ui->locationName->setText("拱墅区");
    Common::setLabelIcon(ui->weatherIcon,icon::getIcon("cloudy_to_clear"),20);
    ui->weatherTxt->setText("15°C");
    Common::setButtonIcon(ui->msg,icon::getIcon("msg"));
    Common::setButtonIcon(ui->personalCenter,icon::getIcon("my"));
    ui->spaceChanged->setIcon("drop_down",20);
    connect(ui->spaceChanged,SIGNAL(btnClicked(bool)),this,SLOT(spacesChange(bool)));
}

homePage::~homePage()
{
    delete ui;
}

void homePage::setData(int houseId,int spaceId)
{
    houseId_ = houseId;
    spaceId_ = spaceId;
    QVariantMap space = equipment::getSpace(houseId,spaceId);
    spaceData_ = space;
    ui->spaceChanged->setTxt(spaceData_["name"].toString());
    QVariantList rooms = space["rooms"].toList();
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
        QVariantMap roomM = rooms[i].toMap();
        //名称
        room->setName(roomM["name"].toString());
        //icon
        int icon = icon::getIcon(roomM["icon"].toString());
        room->setIcon(icon);
        room->setData(houseId_,spaceId_,roomM["id"].toInt());
        //设置房间参数
        room->setParams(roomM["param"].toList());
        //设置房间场景
        room->setScenes(roomM["scene"].toList());
        connect(room,SIGNAL(goPage(PageBack,int,int,int)),this,SIGNAL(goPage(PageBack,int,int,int)));

    }

    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());

}

void homePage::spacesChange(bool clicked){
    pSpacesChange_->setVisible(clicked);
    pSpacesChange_->isActiveWindow();
    pSpacesChange_->setGeometry(ui->roomsScrollArea->geometry());
    qDebug()<<"size:"<<ui->roomsScrollArea->size()<<" hint:"<<ui->roomsScrollArea->sizeHint();
    qDebug()<<"size:"<<pSpacesChange_->size()<<" hint:"<<pSpacesChange_->sizeHint();
}
