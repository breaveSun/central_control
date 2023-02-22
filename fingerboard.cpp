#include "fingerboard.h"
#include "ui_fingerboard.h"

fingerboard::fingerboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fingerboard)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint
                    /*| Qt::Tool*/
                    | Qt::WindowStaysOnTopHint
                    | Qt::WindowDoesNotAcceptFocus);
    ui->frame->setObjectName("fingerboardFrame");
}

fingerboard::~fingerboard()
{
    delete ui;
}
