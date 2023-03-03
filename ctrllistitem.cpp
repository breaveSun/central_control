#include "ctrllistitem.h"
#include "ui_ctrllistitem.h"
#include "icon.h"

ctrlListItem::ctrlListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ctrlListItem)
{
    ui->setupUi(this);
    connect(ui->item, SIGNAL(btnClick()), this, SLOT(goDetailPage()));
}

ctrlListItem::~ctrlListItem()
{
    delete ui;
}

void ctrlListItem::setName(QString name){
    ui->item->setName(name);
}

void ctrlListItem::setIcon(int icon){
    ui->item->setIcon(icon);
}

void ctrlListItem::setGoPageData(enum PageBack pb,int houseId,int spaceId,int roomId){
    roomId_ = roomId;
    spaceId_ = spaceId;
    houseId_ = houseId;
    pb_ = pb;
}
//进入页面
void ctrlListItem::goDetailPage()
{
    qDebug()<<__FUNCTION__<<"_"<<pb_;
    //进入详情页
    emit goDetailPageSignal(pb_,houseId_,spaceId_,roomId_);
}
