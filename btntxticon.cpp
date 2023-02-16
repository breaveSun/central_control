#include "btntxticon.h"
#include "ui_btntxticon.h"
#include "common.h"
#include "icon.h"

btnTxtIcon::btnTxtIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::btnTxtIcon)
{
    ui->setupUi(this);
    connect(ui->txt, SIGNAL(pressed()), SIGNAL(btnPressed()));
    connect(ui->icon, SIGNAL(pressed()), SIGNAL(btnPressed()));
    connect(ui->txt, SIGNAL(released()), SIGNAL(btnReleased()));
    connect(ui->icon, SIGNAL(released()), SIGNAL(btnReleased()));
    connect(ui->txt, SIGNAL(clicked(bool)), SIGNAL(btnClicked(bool)));
    connect(ui->icon, SIGNAL(clicked(bool)), SIGNAL(btnClicked(bool)));
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
