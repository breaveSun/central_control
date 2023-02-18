#include "btntxticon.h"
#include "ui_btntxticon.h"
#include "common.h"
#include "icon.h"

btnTxtIcon::btnTxtIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::btnTxtIcon)
{
    ui->setupUi(this);
    isChecked_ = false;
    connect(ui->txt, SIGNAL(pressed()), SIGNAL(btnPressed()));
    connect(ui->icon, SIGNAL(pressed()), SIGNAL(btnPressed()));
    connect(ui->txt, SIGNAL(released()), SIGNAL(btnReleased()));
    connect(ui->icon, SIGNAL(released()), SIGNAL(btnReleased()));
    connect(ui->txt, SIGNAL(clicked(bool)), SLOT(btnClickedSlot(bool)));
    connect(ui->icon, SIGNAL(clicked(bool)), SLOT(btnClickedSlot(bool)));
}

btnTxtIcon::~btnTxtIcon()
{
    delete ui;
}

void btnTxtIcon::setTxt(QString txt){
    ui->txt->setText(txt);
}

void btnTxtIcon::setIcon(QString icon,int size){
    Common::setButtonIcon(ui->icon,icon::getIcon(icon),size);
}

bool btnTxtIcon::isChecked(){
    return isChecked_;
}

void btnTxtIcon::setChecked(bool checked){
    isChecked_ = checked;
}

void btnTxtIcon::btnClickedSlot(bool clicked){
    isChecked_ = !isChecked_;
    emit btnClicked(isChecked_);
}

