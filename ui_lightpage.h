/********************************************************************************
** Form generated from reading UI file 'lightpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTPAGE_H
#define UI_LIGHTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myscollarea.h"
#include "pagehead.h"

QT_BEGIN_NAMESPACE

class Ui_lightPage
{
public:
    QVBoxLayout *verticalLayout_2;
    pageHead *title;
    QHBoxLayout *horizontalLayout;
    myScollArea *lightScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *lightPage)
    {
        if (lightPage->objectName().isEmpty())
            lightPage->setObjectName(QString::fromUtf8("lightPage"));
        lightPage->resize(700, 1024);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lightPage->sizePolicy().hasHeightForWidth());
        lightPage->setSizePolicy(sizePolicy);
        lightPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(lightPage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, 0, 15, 0);
        title = new pageHead(lightPage);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setMinimumSize(QSize(0, 0));
        title->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(title);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 30, 15, 30);

        verticalLayout_2->addWidget(title);

        lightScrollArea = new myScollArea(lightPage);
        lightScrollArea->setObjectName(QString::fromUtf8("lightScrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lightScrollArea->sizePolicy().hasHeightForWidth());
        lightScrollArea->setSizePolicy(sizePolicy2);
        lightScrollArea->setMinimumSize(QSize(0, 0));
        lightScrollArea->setMaximumSize(QSize(16777215, 16777215));
        lightScrollArea->setMouseTracking(true);
        lightScrollArea->setTabletTracking(true);
        lightScrollArea->setContextMenuPolicy(Qt::DefaultContextMenu);
        lightScrollArea->setAcceptDrops(true);
        lightScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lightScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lightScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        lightScrollArea->setWidgetResizable(true);
        lightScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 668, 1000));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        scrollAreaWidgetContents->setMouseTracking(true);
        scrollAreaWidgetContents->setTabletTracking(true);
        scrollAreaWidgetContents->setAcceptDrops(true);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lightScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(lightScrollArea);


        retranslateUi(lightPage);

        QMetaObject::connectSlotsByName(lightPage);
    } // setupUi

    void retranslateUi(QWidget *lightPage)
    {
        (void)lightPage;
    } // retranslateUi

};

namespace Ui {
    class lightPage: public Ui_lightPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTPAGE_H
