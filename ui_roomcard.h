/********************************************************************************
** Form generated from reading UI file 'roomcard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMCARD_H
#define UI_ROOMCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "btntxticon.h"
#include "myscollarea.h"
#include "titleicon.h"

QT_BEGIN_NAMESPACE

class Ui_roomCard
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *roomCardFrame;
    QVBoxLayout *verticalLayout_2;
    QWidget *roomCardTitle;
    QHBoxLayout *horizontalLayout_9;
    titleIcon *roomTitle;
    QWidget *statusParam;
    QHBoxLayout *horizontalLayout_2;
    QWidget *devicesInfo;
    QHBoxLayout *horizontalLayout_3;
    QWidget *devices;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *deviceNum;
    QSpacerItem *horizontalSpacer_2;
    QWidget *deviceEnabled;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *enabledNum;
    QSpacerItem *horizontalSpacer_3;
    QWidget *checkDeviceWidget;
    QVBoxLayout *verticalLayout_3;
    btnTxtIcon *checkDevice;
    QWidget *sceneTitle;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QWidget *sceneConf;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *slipLeft;
    myScollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *slipRight;

    void setupUi(QWidget *roomCard)
    {
        if (roomCard->objectName().isEmpty())
            roomCard->setObjectName(QString::fromUtf8("roomCard"));
        roomCard->resize(400, 335);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roomCard->sizePolicy().hasHeightForWidth());
        roomCard->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(roomCard);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        roomCardFrame = new QFrame(roomCard);
        roomCardFrame->setObjectName(QString::fromUtf8("roomCardFrame"));
        roomCardFrame->setFrameShape(QFrame::StyledPanel);
        roomCardFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(roomCardFrame);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        roomCardTitle = new QWidget(roomCardFrame);
        roomCardTitle->setObjectName(QString::fromUtf8("roomCardTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(roomCardTitle->sizePolicy().hasHeightForWidth());
        roomCardTitle->setSizePolicy(sizePolicy1);
        horizontalLayout_9 = new QHBoxLayout(roomCardTitle);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        roomTitle = new titleIcon(roomCardTitle);
        roomTitle->setObjectName(QString::fromUtf8("roomTitle"));
        sizePolicy1.setHeightForWidth(roomTitle->sizePolicy().hasHeightForWidth());
        roomTitle->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(roomTitle);


        verticalLayout_2->addWidget(roomCardTitle);

        statusParam = new QWidget(roomCardFrame);
        statusParam->setObjectName(QString::fromUtf8("statusParam"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statusParam->sizePolicy().hasHeightForWidth());
        statusParam->setSizePolicy(sizePolicy2);
        horizontalLayout_2 = new QHBoxLayout(statusParam);
        horizontalLayout_2->setSpacing(40);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 12, 0, 12);

        verticalLayout_2->addWidget(statusParam);

        devicesInfo = new QWidget(roomCardFrame);
        devicesInfo->setObjectName(QString::fromUtf8("devicesInfo"));
        horizontalLayout_3 = new QHBoxLayout(devicesInfo);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 12, 0, 12);
        devices = new QWidget(devicesInfo);
        devices->setObjectName(QString::fromUtf8("devices"));
        sizePolicy1.setHeightForWidth(devices->sizePolicy().hasHeightForWidth());
        devices->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(devices);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(devices);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label);

        deviceNum = new QLabel(devices);
        deviceNum->setObjectName(QString::fromUtf8("deviceNum"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(deviceNum->sizePolicy().hasHeightForWidth());
        deviceNum->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(deviceNum);


        horizontalLayout_3->addWidget(devices);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        deviceEnabled = new QWidget(devicesInfo);
        deviceEnabled->setObjectName(QString::fromUtf8("deviceEnabled"));
        sizePolicy1.setHeightForWidth(deviceEnabled->sizePolicy().hasHeightForWidth());
        deviceEnabled->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(deviceEnabled);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(deviceEnabled);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(label_2);

        enabledNum = new QLabel(deviceEnabled);
        enabledNum->setObjectName(QString::fromUtf8("enabledNum"));
        sizePolicy4.setHeightForWidth(enabledNum->sizePolicy().hasHeightForWidth());
        enabledNum->setSizePolicy(sizePolicy4);
        QFont font;
        font.setPointSize(11);
        enabledNum->setFont(font);

        horizontalLayout_4->addWidget(enabledNum);


        horizontalLayout_3->addWidget(deviceEnabled);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        checkDeviceWidget = new QWidget(devicesInfo);
        checkDeviceWidget->setObjectName(QString::fromUtf8("checkDeviceWidget"));
        sizePolicy1.setHeightForWidth(checkDeviceWidget->sizePolicy().hasHeightForWidth());
        checkDeviceWidget->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(checkDeviceWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        checkDevice = new btnTxtIcon(checkDeviceWidget);
        checkDevice->setObjectName(QString::fromUtf8("checkDevice"));
        sizePolicy1.setHeightForWidth(checkDevice->sizePolicy().hasHeightForWidth());
        checkDevice->setSizePolicy(sizePolicy1);
        checkDevice->setMinimumSize(QSize(0, 0));
        checkDevice->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(13);
        checkDevice->setFont(font1);

        verticalLayout_3->addWidget(checkDevice);


        horizontalLayout_3->addWidget(checkDeviceWidget);


        verticalLayout_2->addWidget(devicesInfo);

        sceneTitle = new QWidget(roomCardFrame);
        sceneTitle->setObjectName(QString::fromUtf8("sceneTitle"));
        horizontalLayout_6 = new QHBoxLayout(sceneTitle);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 0, -1);
        label_3 = new QLabel(sceneTitle);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);


        verticalLayout_2->addWidget(sceneTitle);

        sceneConf = new QWidget(roomCardFrame);
        sceneConf->setObjectName(QString::fromUtf8("sceneConf"));
        sizePolicy.setHeightForWidth(sceneConf->sizePolicy().hasHeightForWidth());
        sceneConf->setSizePolicy(sizePolicy);
        horizontalLayout_8 = new QHBoxLayout(sceneConf);
        horizontalLayout_8->setSpacing(12);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        slipLeft = new QPushButton(sceneConf);
        slipLeft->setObjectName(QString::fromUtf8("slipLeft"));
        sizePolicy3.setHeightForWidth(slipLeft->sizePolicy().hasHeightForWidth());
        slipLeft->setSizePolicy(sizePolicy3);
        slipLeft->setMinimumSize(QSize(22, 0));
        slipLeft->setMaximumSize(QSize(22, 16777215));

        horizontalLayout_8->addWidget(slipLeft);

        scrollArea = new myScollArea(sceneConf);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 500, 16));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMinimumSize(QSize(500, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_7 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_7->setSpacing(15);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_8->addWidget(scrollArea);

        slipRight = new QPushButton(sceneConf);
        slipRight->setObjectName(QString::fromUtf8("slipRight"));
        sizePolicy3.setHeightForWidth(slipRight->sizePolicy().hasHeightForWidth());
        slipRight->setSizePolicy(sizePolicy3);
        slipRight->setMinimumSize(QSize(22, 0));
        slipRight->setMaximumSize(QSize(22, 16777215));

        horizontalLayout_8->addWidget(slipRight);


        verticalLayout_2->addWidget(sceneConf);


        verticalLayout->addWidget(roomCardFrame);


        retranslateUi(roomCard);

        QMetaObject::connectSlotsByName(roomCard);
    } // setupUi

    void retranslateUi(QWidget *roomCard)
    {
        roomCard->setWindowTitle(QCoreApplication::translate("roomCard", "Form", nullptr));
        label->setText(QCoreApplication::translate("roomCard", "\350\256\276\345\244\207\357\274\232", nullptr));
        deviceNum->setText(QCoreApplication::translate("roomCard", "20", nullptr));
        label_2->setText(QCoreApplication::translate("roomCard", "\345\274\200\345\220\257\357\274\232", nullptr));
        enabledNum->setText(QCoreApplication::translate("roomCard", "5", nullptr));
        label_3->setText(QCoreApplication::translate("roomCard", "\345\234\272\346\231\257", nullptr));
        slipLeft->setText(QString());
        slipRight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class roomCard: public Ui_roomCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMCARD_H
