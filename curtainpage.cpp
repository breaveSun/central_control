#include "curtainpage.h"
#include "ui_curtainpage.h"
#include "curtainopen.h"

curtainPage::curtainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::curtainPage)
{
    ui->setupUi(this);
    open1 = new curtainOpen(this);
    open1->setName("开合帘");
    open1->setOpenIcon(QChar(0xe608));
    open1->setCloseIcon(QChar(0xe609));
    open1->hideAngle();
    open2 = new curtainOpen(this);
    open2->setName("梦幻帘");
    open2->setOpenIcon(QChar(0xe612));
    open2->setCloseIcon(QChar(0xe607));


    ui->scrollAreaWidgetContents->layout()->addWidget(open1);
    ui->scrollAreaWidgetContents->layout()->addWidget(open2);

    open1->setId(1);
    open2->setId(2);

    connect(ui->curtainBack,&QPushButton::clicked,this,&curtainPage::goBackSlot);
    connect(ui->closeAll,&QPushButton::clicked,this,&curtainPage::closeAllSlot);

    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}

curtainPage::~curtainPage()
{
    delete ui;
}

void curtainPage::goBackSlot()
{
    emit goBackSignal(PB_GO_HOME);
}

void curtainPage::closeAllSlot()
{
    open1->closeCurtain();
    open2->closeCurtain();
}
