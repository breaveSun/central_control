#include "changespace.h"
#include "ui_changespace.h"
#include "equipment.h"
#include "labelbtn.h"
#include <qdebug.h>

changeSpace::changeSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeSpace)
{
    ui->setupUi(this);

    //点击空白处 弹窗隐藏
    this->setWindowFlags(Qt::Popup);

}

changeSpace::~changeSpace()
{
    delete ui;
}

void changeSpace::setData(QVector<houseStruct>* house,int houseId,int spaceId){
    houseId_ = houseId;
    spaceId_ = spaceId;
    houses_ = house;
    int housesSize = houses_->size();
    int housesWidgetSize = houseBtnList_.size();

    //清空布局
    for (int i=0;i<housesWidgetSize;i++) {
        ui->housesContents->layout()->removeWidget(houseBtnList_[i]);
    }
    //清空参数
    houseBtnList_.remove(0,housesWidgetSize);

    //新数据填入
    for(int i=0;i<housesSize;i++) {
        labelBtn* hlb = new labelBtn(this);
        houseStruct house = houses_->at(i);
        hlb->setName(house.name);
        int hId = house.id;
        hlb->setId(hId);
        connect(hlb,SIGNAL(btnClicked(int)),this,SLOT(btnHouseSlot(int)));
        if(hId == houseId){
            hlb->setStyleSheet("#pushButton{"
                            "font-size:18pt;"
                            "padding:5px 20px;"
                            "background-color:#353638;"
                            "border-radius: 20px;}");
            QVector<spaceStruct> spaces = house.spaces;
            setSpaceData(spaces,spaceId);
        } else {
            hlb->setStyleSheet("#pushButton{"
                               "font-size:18pt;"
                               "padding:5px 20px;"
                               "background-color:#171717;"
                               "border-radius: 20px;}");
        }
        houseBtnList_.push_back(hlb);
        ui->housesContents->layout()->addWidget(hlb);
    }
    int housesContentHeight = ui->housesContents->sizeHint().height();
    int spacesContentHeight = ui->spacesContents->sizeHint().height();
    ui->housesContents->setFixedHeight(housesContentHeight);
    ui->spacesContents->setFixedHeight(spacesContentHeight);
    ui->line->setFixedHeight(housesContentHeight<spacesContentHeight?housesContentHeight:spacesContentHeight);

}



void changeSpace::btnHouseSlot(int houseId){
    int housesBtnListSize = houseBtnList_.size();
    for(int i=0;i<housesBtnListSize;i++) {
        labelBtn* lb = houseBtnList_[i];
        if(lb->id() == houseId){
            lb->setStyleSheet("#pushButton{"
                            "font-size:18pt;"
                            "padding:5px 20px;"
                            "background-color:#353638;"
                            "border-radius: 20px;}");
        }else{
            lb->setStyleSheet("#pushButton{"
                               "font-size:18pt;"
                               "padding:5px 20px;"
                               "background-color:#171717;"
                               "border-radius: 20px;}");
        }
    }

    int housesSize = houses_->size();
    for(int i=0;i<housesSize;i++) {
        houseStruct house = houses_->at(i);
        int hId = house.id;
        if(hId == houseId){
            QVector<spaceStruct> spaces = house.spaces;

            ui->spacesContents->hide();
            setSpaceData(spaces,spaceId_);

            ui->spacesContents->show();
            break;
        }
    }

    int housesContentHeight = ui->housesContents->sizeHint().height();
    int spacesContentHeight = ui->spacesContents->sizeHint().height();
    ui->spacesContents->setFixedHeight(spacesContentHeight);
    ui->line->setFixedHeight(housesContentHeight<spacesContentHeight?housesContentHeight:spacesContentHeight);
    houseId_ = houseId;
}

void changeSpace::btnSpaceSlot(int spaceId){
    spaceId_ = spaceId;
    emit updateRooms(houseId_,spaceId);
    this->hide();
}

void changeSpace::setSpaceData(QVector<spaceStruct> spaces,int spaceId){
    //清空布局
    int spacesWidgetSize = spaceBtnList_.size();
    for (int i=0;i<spacesWidgetSize;i++) {
        ui->spacesContents->layout()->removeWidget(spaceBtnList_[i]);
    }
    //清空参数
    spaceBtnList_.remove(0,spacesWidgetSize);
    for (int s=0;s<spaces.size();s++) {
        labelBtn* slb = new labelBtn(this);
        spaceStruct space = spaces[s];
        slb->setName(space.name);
        int sId = space.id;
        slb->setId(sId);
        connect(slb,SIGNAL(btnClicked(int)),this,SLOT(btnSpaceSlot(int)));

        if(sId == spaceId){
            slb->setStyleSheet("#pushButton{"
                            "font-size:18pt;"
                            "padding:5px 20px;"
                            "color:#D2AA74}");
        } else {
            slb->setStyleSheet("#pushButton{"
                            "font-size:18pt;"
                            "padding:5px 20px;"
                            "color:#BCBCBC}");
        }
        spaceBtnList_.push_back(slb);
        ui->spacesContents->layout()->addWidget(slb);
    }
    ui->spacesContents->update();
}

bool changeSpace::event(QEvent* event)
{
    if (event->type() == QEvent::HideToParent)
    {
        qDebug()<<__FUNCTION__;
        emit changeSpaceHide();
    }
    return QWidget::event(event);
}
