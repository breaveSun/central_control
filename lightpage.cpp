#include "lightpage.h"
#include "ui_lightpage.h"
#include "btntwoslider.h"
#include <qdebug.h>
#include <qlayout.h>
lightPage::lightPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightPage)
{
    ui->setupUi(this);
    titleBtnShow1 = new btnTwoSlider(this);
    titleBtnShow2 = new btnTwoSlider(this);
    titleBtnShow1->setName("主吊灯");
    titleBtnShow2->setName("玄关灯");
    titleBtnShow1->setIcon(QChar(0xe60e));
    titleBtnShow2->setIcon(QChar(0xe60c));
    ui->scrollAreaWidgetContents->layout()->addWidget(titleBtnShow1);
    ui->scrollAreaWidgetContents->layout()->addWidget(titleBtnShow2);


    connect(titleBtnShow1, SIGNAL(lightSwitch()), this,SLOT(ligthSwitch()));
    connect(titleBtnShow2, SIGNAL(lightSwitch()), this,SLOT(ligthSwitch()));

    connect(ui->lightBack,&QPushButton::clicked,this,&lightPage::goBackSlot);
    connect(ui->closeAll,&QPushButton::clicked,this,&lightPage::closeAllSlot);
    titleBtnShow1->setColor("FF0000");
    titleBtnShow2->setColor("00FF00");
}

lightPage::~lightPage()
{
    delete ui;
}

void lightPage::goBackSlot()
{
    emit goBackSignal(PB_GO_HOME);
}

void lightPage::closeAllSlot()
{
    titleBtnShow1->shutOff();
    titleBtnShow2->shutOff();
}

void lightPage::ligthSwitch()
{
   ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}
