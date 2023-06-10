/********************************************************************************
** Form generated from reading UI file 'changespace.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESPACE_H
#define UI_CHANGESPACE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myscollarea.h"

QT_BEGIN_NAMESPACE

class Ui_changeSpace
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *changeSpaceFrame;
    QHBoxLayout *horizontalLayout_2;
    myScollArea *housesList;
    QWidget *housesContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *line;
    QWidget *widget_2;
    myScollArea *spacesList;
    QWidget *spacesContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *changeSpace)
    {
        if (changeSpace->objectName().isEmpty())
            changeSpace->setObjectName(QString::fromUtf8("changeSpace"));
        changeSpace->resize(535, 595);
        horizontalLayout = new QHBoxLayout(changeSpace);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        changeSpaceFrame = new QFrame(changeSpace);
        changeSpaceFrame->setObjectName(QString::fromUtf8("changeSpaceFrame"));
        changeSpaceFrame->setFrameShape(QFrame::StyledPanel);
        changeSpaceFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(changeSpaceFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 20, 0, 0);
        housesList = new myScollArea(changeSpaceFrame);
        housesList->setObjectName(QString::fromUtf8("housesList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(housesList->sizePolicy().hasHeightForWidth());
        housesList->setSizePolicy(sizePolicy);
        housesList->setMinimumSize(QSize(0, 0));
        housesList->setMaximumSize(QSize(16777215, 16777215));
        housesList->setMouseTracking(true);
        housesList->setTabletTracking(true);
        housesList->setContextMenuPolicy(Qt::DefaultContextMenu);
        housesList->setAcceptDrops(true);
        housesList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        housesList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        housesList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        housesList->setWidgetResizable(true);
        housesList->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        housesContents = new QWidget();
        housesContents->setObjectName(QString::fromUtf8("housesContents"));
        housesContents->setGeometry(QRect(0, 0, 264, 1000));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(housesContents->sizePolicy().hasHeightForWidth());
        housesContents->setSizePolicy(sizePolicy1);
        housesContents->setMinimumSize(QSize(0, 1000));
        housesContents->setMouseTracking(true);
        housesContents->setTabletTracking(true);
        housesContents->setAcceptDrops(true);
        housesContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(housesContents);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(30, 0, 30, 0);
        housesList->setWidget(housesContents);

        horizontalLayout_2->addWidget(housesList);

        widget = new QWidget(changeSpaceFrame);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setLayoutDirection(Qt::RightToLeft);
        widget->setStyleSheet(QString::fromUtf8(""));
        widget->setLocale(QLocale(QLocale::Church, QLocale::Russia));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        line = new QWidget(widget);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setMinimumSize(QSize(2, 250));
        line->setMaximumSize(QSize(2, 250));
        line->setLayoutDirection(Qt::RightToLeft);
        line->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(line);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy4);
        widget_2->setMaximumSize(QSize(2, 16777215));

        verticalLayout_3->addWidget(widget_2);


        horizontalLayout_2->addWidget(widget);

        spacesList = new myScollArea(changeSpaceFrame);
        spacesList->setObjectName(QString::fromUtf8("spacesList"));
        sizePolicy.setHeightForWidth(spacesList->sizePolicy().hasHeightForWidth());
        spacesList->setSizePolicy(sizePolicy);
        spacesList->setMinimumSize(QSize(0, 0));
        spacesList->setMaximumSize(QSize(16777215, 16777215));
        spacesList->setMouseTracking(true);
        spacesList->setTabletTracking(true);
        spacesList->setContextMenuPolicy(Qt::DefaultContextMenu);
        spacesList->setAcceptDrops(true);
        spacesList->setStyleSheet(QString::fromUtf8(""));
        spacesList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        spacesList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        spacesList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        spacesList->setWidgetResizable(true);
        spacesList->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        spacesContents = new QWidget();
        spacesContents->setObjectName(QString::fromUtf8("spacesContents"));
        spacesContents->setGeometry(QRect(0, 0, 263, 1000));
        sizePolicy1.setHeightForWidth(spacesContents->sizePolicy().hasHeightForWidth());
        spacesContents->setSizePolicy(sizePolicy1);
        spacesContents->setMinimumSize(QSize(0, 1000));
        spacesContents->setMouseTracking(true);
        spacesContents->setTabletTracking(true);
        spacesContents->setAcceptDrops(true);
        spacesContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(spacesContents);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 0, 30, 0);
        spacesList->setWidget(spacesContents);

        horizontalLayout_2->addWidget(spacesList);


        horizontalLayout->addWidget(changeSpaceFrame);


        retranslateUi(changeSpace);

        QMetaObject::connectSlotsByName(changeSpace);
    } // setupUi

    void retranslateUi(QWidget *changeSpace)
    {
        changeSpace->setWindowTitle(QCoreApplication::translate("changeSpace", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeSpace: public Ui_changeSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESPACE_H
