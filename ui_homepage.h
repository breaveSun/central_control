/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "btntxticon.h"
#include "myscollarea.h"

QT_BEGIN_NAMESPACE

class Ui_homePage
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *locationWeather;
    QHBoxLayout *horizontalLayout_2;
    QLabel *locationIcon;
    QLabel *locationName;
    QSpacerItem *horizontalSpacer_2;
    QLabel *weatherIcon;
    QLabel *weatherTxt;
    QSpacerItem *horizontalSpacer;
    QPushButton *msg;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *personalCenter;
    QWidget *spacesCloseAll;
    QHBoxLayout *horizontalLayout_3;
    btnTxtIcon *spaceChanged;
    myScollArea *roomsScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *homePage)
    {
        if (homePage->objectName().isEmpty())
            homePage->setObjectName(QString::fromUtf8("homePage"));
        homePage->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(homePage->sizePolicy().hasHeightForWidth());
        homePage->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(homePage);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, 30, 15, 0);
        widget = new QWidget(homePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        locationWeather = new QWidget(widget);
        locationWeather->setObjectName(QString::fromUtf8("locationWeather"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(locationWeather->sizePolicy().hasHeightForWidth());
        locationWeather->setSizePolicy(sizePolicy1);
        locationWeather->setMinimumSize(QSize(0, 0));
        locationWeather->setMaximumSize(QSize(16777215, 16777215));
        locationWeather->setSizeIncrement(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(locationWeather);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        locationIcon = new QLabel(locationWeather);
        locationIcon->setObjectName(QString::fromUtf8("locationIcon"));
        sizePolicy1.setHeightForWidth(locationIcon->sizePolicy().hasHeightForWidth());
        locationIcon->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(locationIcon);

        locationName = new QLabel(locationWeather);
        locationName->setObjectName(QString::fromUtf8("locationName"));
        sizePolicy1.setHeightForWidth(locationName->sizePolicy().hasHeightForWidth());
        locationName->setSizePolicy(sizePolicy1);
        locationName->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(locationName);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        weatherIcon = new QLabel(locationWeather);
        weatherIcon->setObjectName(QString::fromUtf8("weatherIcon"));
        sizePolicy1.setHeightForWidth(weatherIcon->sizePolicy().hasHeightForWidth());
        weatherIcon->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(weatherIcon);

        weatherTxt = new QLabel(locationWeather);
        weatherTxt->setObjectName(QString::fromUtf8("weatherTxt"));
        sizePolicy1.setHeightForWidth(weatherTxt->sizePolicy().hasHeightForWidth());
        weatherTxt->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(weatherTxt);


        horizontalLayout->addWidget(locationWeather);

        horizontalSpacer = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        msg = new QPushButton(widget);
        msg->setObjectName(QString::fromUtf8("msg"));
        sizePolicy1.setHeightForWidth(msg->sizePolicy().hasHeightForWidth());
        msg->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(msg);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        personalCenter = new QPushButton(widget);
        personalCenter->setObjectName(QString::fromUtf8("personalCenter"));
        sizePolicy1.setHeightForWidth(personalCenter->sizePolicy().hasHeightForWidth());
        personalCenter->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(personalCenter);


        verticalLayout_2->addWidget(widget);

        spacesCloseAll = new QWidget(homePage);
        spacesCloseAll->setObjectName(QString::fromUtf8("spacesCloseAll"));
        sizePolicy1.setHeightForWidth(spacesCloseAll->sizePolicy().hasHeightForWidth());
        spacesCloseAll->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(spacesCloseAll);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
        spaceChanged = new btnTxtIcon(spacesCloseAll);
        spaceChanged->setObjectName(QString::fromUtf8("spaceChanged"));
        sizePolicy1.setHeightForWidth(spaceChanged->sizePolicy().hasHeightForWidth());
        spaceChanged->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(spaceChanged);


        verticalLayout_2->addWidget(spacesCloseAll);

        roomsScrollArea = new myScollArea(homePage);
        roomsScrollArea->setObjectName(QString::fromUtf8("roomsScrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(roomsScrollArea->sizePolicy().hasHeightForWidth());
        roomsScrollArea->setSizePolicy(sizePolicy2);
        roomsScrollArea->setMinimumSize(QSize(0, 0));
        roomsScrollArea->setMaximumSize(QSize(16777215, 16777215));
        roomsScrollArea->setMouseTracking(true);
        roomsScrollArea->setTabletTracking(true);
        roomsScrollArea->setContextMenuPolicy(Qt::DefaultContextMenu);
        roomsScrollArea->setAcceptDrops(true);
        roomsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        roomsScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        roomsScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        roomsScrollArea->setWidgetResizable(true);
        roomsScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 368, 1000));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        scrollAreaWidgetContents->setMouseTracking(true);
        scrollAreaWidgetContents->setTabletTracking(true);
        scrollAreaWidgetContents->setAcceptDrops(true);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        roomsScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(roomsScrollArea);


        retranslateUi(homePage);

        QMetaObject::connectSlotsByName(homePage);
    } // setupUi

    void retranslateUi(QWidget *homePage)
    {
        homePage->setWindowTitle(QCoreApplication::translate("homePage", "Form", nullptr));
        locationIcon->setText(QCoreApplication::translate("homePage", "!", nullptr));
        locationName->setText(QCoreApplication::translate("homePage", "\346\213\261\345\242\205\345\214\272", nullptr));
        weatherIcon->setText(QCoreApplication::translate("homePage", "we", nullptr));
        weatherTxt->setText(QCoreApplication::translate("homePage", "15*", nullptr));
        msg->setText(QString());
        personalCenter->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class homePage: public Ui_homePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
