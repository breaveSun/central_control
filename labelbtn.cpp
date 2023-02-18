#include "labelbtn.h"
#include "ui_labelbtn.h"
#include <qdebug.h>
labelBtn::labelBtn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labelBtn)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(btnClickedSlot(bool)));

}

labelBtn::~labelBtn()
{
    delete ui;
}

void labelBtn::setName(QString name){
    ui->pushButton->setText(name);
}

void labelBtn::setId(int id){
    id_ = id;
}


int labelBtn::id(){
    return id_;
}

void labelBtn::setColor(QString color){
    ui->pushButton->setStyleSheet("#pushButton{color:"+color+";}");
}

void labelBtn::setBKColor(QString color){
    ui->pushButton->setStyleSheet("#pushButton{background-color:"+color+";}");
}

void labelBtn::setStyleSheet(QString style){
ui->pushButton->setStyleSheet(style);
}

void labelBtn::btnClickedSlot(bool clicked){
    qDebug()<<__FUNCTION__<<clicked;
    emit btnClicked(id_);
}
