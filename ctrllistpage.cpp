#include "ctrllistpage.h"
#include "ui_ctrllistpage.h"
#include "ctrllistitem.h"
#include "equipment.h"
#include "common.h"
#include "icon.h"

ctrlListPage::ctrlListPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ctrlListPage)
{
    ui->setupUi(this);
    ui->titleLabel->setText("设备控制");
    pLightCtrl_ = new ctrlListItem;
    pLightCtrl_->setIcon(icon::getIcon("lighting_control"));
    pLightCtrl_->setName("照明控制");
    pCurtainCtrl_ = new ctrlListItem;
    pCurtainCtrl_->setIcon(icon::getIcon("shading_control"));
    pCurtainCtrl_->setName("遮光控制");


    ui->scrollAreaWidgetContents->layout()->addWidget(pLightCtrl_);
    ui->scrollAreaWidgetContents->layout()->addWidget(pCurtainCtrl_);

    //给返回按钮设置图标
    Common::setButtonIcon(ui->ctrlListpageBack,icon::getIcon("return"));

    //返回页面跳转
    connect(ui->ctrlListpageBack,&QPushButton::clicked,this,&ctrlListPage::goBackSlot);

    //详情页面跳转
    connect(pLightCtrl_,SIGNAL(goDetailPageSignal(PageBack,int,int,int)),this,SIGNAL(goDetailSignal(PageBack,int,int,int)));
    connect(pCurtainCtrl_,SIGNAL(goDetailPageSignal(PageBack,int,int,int)),this,SIGNAL(goDetailSignal(PageBack,int,int,int)));

}
void ctrlListPage::setData(int houseId,int spaceId,int roomId)
{
    QVariantMap room = equipment::getRoom(houseId,spaceId,roomId);
    pRoomData_ = room;
    houseId_ = houseId;
    spaceId_ = spaceId;
    roomId_ = roomId;

    QVariantList lightings = room["curtain"].toList();
    QVariantList curtains = room["curtain"].toList();
    qDebug()<<"lightings.size():"<<lightings.size();
    qDebug()<<"curtains.size():"<<curtains.size();
    if(lightings.size()>0){
        pLightCtrl_->setVisible(true);
        pLightCtrl_->setGoPageData(PB_GO_LIGHT_PAGE,houseId,spaceId,roomId);
    } else {
        pLightCtrl_->setVisible(false);
    }
    if(curtains.size()>0){
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
