#include "messagecenteritem.h"
#include "ui_messagecenteritem.h"

messageCenterItem::messageCenterItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messageCenterItem)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet("background-color:#222222;");
    ui->frame->setStyleSheet("#frame{border-radius:8px;}");

    ui->frame->setStyleSheet("border: 1px solid red");

    pRedPoint_ = new QLabel;
    pRedPoint_->setObjectName("redPoint");
    pRedPoint_->setFixedSize(QSize(10,10));
    pRedPoint_->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
//        pRedPoint_->setAlignment(Qt::AlignRight);
    pRedPoint_->setStyleSheet("background-color:#EB4D3C;border-radius:5px;");

    pRedPointBrother_ = new QLabel;
    pRedPointBrother_->setObjectName("redPointBrother");
    pRedPointBrother_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pRedPointBrother_->setStyleSheet("background-color:rgba(255,255,255,0);");

    QVBoxLayout* pLayoutInfoComing_ = new QVBoxLayout(ui->icon);
    pLayoutInfoComing_->setMargin(0);
    pLayoutInfoComing_->addWidget(pRedPoint_);
    pLayoutInfoComing_->addWidget(pRedPointBrother_);
}

messageCenterItem::~messageCenterItem()
{
    delete ui;
}

void messageCenterItem::setData(messageStruct message){
    qDebug()<<__FUNCTION__<<"---"<<message.id<<":"<<message.status;
    message_ = message;
    ui->title->setText(message_.title);
    Common::setButtonIcon(ui->icon,icon::getIcon(message_.icon));
    ui->dateTime->setText(message_.dateTime);
    ui->label->setText(message_.content);
    if(message_.status == 1){
        pRedPoint_->hide();
    }else {
        pRedPoint_->show();
    }
}

void messageCenterItem::read(){
    if(message_.status == 0){
        message_.status = 1;
        if(pRedPoint_!=nullptr){
            pRedPoint_->hide();
        }
    }
}
