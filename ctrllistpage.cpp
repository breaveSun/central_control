#include "ctrllistpage.h"
#include "ui_ctrllistpage.h"
#include "ctrllistitem.h"
#include "equipment.h"
#include "icon.h"
#include "pagehead.h"

ctrlListPage::ctrlListPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ctrlListPage)
{
    ui->setupUi(this);
    ui->title->setTitle("设备管理");
    ui->title->addBackBtn();


    pLightCtrl_ = new ctrlListItem;
    pLightCtrl_->setIcon(icon::getIcon("lighting_control"));
    pLightCtrl_->setName("照明");
    pCurtainCtrl_ = new ctrlListItem;
    pCurtainCtrl_->setIcon(icon::getIcon("shading_control"));
    pCurtainCtrl_->setName("遮光");


    ui->scrollAreaWidgetContents->layout()->addWidget(pLightCtrl_);
    ui->scrollAreaWidgetContents->layout()->addWidget(pCurtainCtrl_);


    //返回页面跳转
    connect(ui->title,SIGNAL(backClick()),this,SLOT(goBackSlot()));

    //详情页面跳转
    connect(pLightCtrl_,SIGNAL(goDetailPageSignal(PageBack,int,int,int)),this,SLOT(goLightDetailSlot(PageBack,int,int,int)));
    connect(pCurtainCtrl_,SIGNAL(goDetailPageSignal(PageBack,int,int,int)),this,SLOT(goCurtainDetailSlot(PageBack,int,int,int)));

}
void ctrlListPage::setData(int houseId,int spaceId,int roomId)
{
    pRoomData_ = equipment::getRoom(houseId,spaceId,roomId);
    houseId_ = houseId;
    spaceId_ = spaceId;
    roomId_ = roomId;

    lightings_ = pRoomData_.lights;
    curtains_ = pRoomData_.curtains;
    if(lightings_.size()>0){
        pLightCtrl_->setVisible(true);
        pLightCtrl_->setGoPageData(PB_GO_LIGHT_PAGE,houseId,spaceId,roomId);
    } else {
        pLightCtrl_->setVisible(false);
    }
    if(curtains_.size()>0){
        pCurtainCtrl_->setVisible(true);
        pCurtainCtrl_->setGoPageData(PB_GO_CURTAIN_PAGE,houseId,spaceId,roomId);
    } else {
        pCurtainCtrl_->setVisible(false);
    }

    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}

ctrlListPage::~ctrlListPage()
{
    delete ui;
}

void ctrlListPage::goBackSlot(){
    emit goBackSignal(PB_GO_HOME,houseId_,spaceId_,roomId_);
}



void ctrlListPage::goLightDetailSlot(enum PageBack pb,int houseId,int spaceId,int roomId){

    emit goDetailSignal(pb,houseId,spaceId,roomId);
}
void ctrlListPage::goCurtainDetailSlot(enum PageBack pb,int houseId,int spaceId,int roomId){

    emit goDetailSignal(pb,houseId,spaceId,roomId);
}
