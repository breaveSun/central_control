#include "ctrllistitem.h"
#include "ui_ctrllistitem.h"
#include "icon.h"

ctrlListItem::ctrlListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ctrlListItem)
{
    ui->setupUi(this);
    //设置右侧按钮图标
    Common::setButtonIcon(ui->goPage,icon::getIcon("more"));
    connect(ui->goPage, &QPushButton::clicked, this, &ctrlListItem::goDetailPage);
}

ctrlListItem::~ctrlListItem()
{
    delete ui;
}

void ctrlListItem::setName(QString name){
    ui->ctrlListTitle->setText(name);
}

void ctrlListItem::setIcon(int icon){
    ui->ctrlListTitle->setIcon(icon);
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
