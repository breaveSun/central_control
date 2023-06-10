/********************************************************************************
** Form generated from reading UI file 'messagecenter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGECENTER_H
#define UI_MESSAGECENTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myscollarea.h"

QT_BEGIN_NAMESPACE

class Ui_messageCenter
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *goBack;
    QSpacerItem *horizontalSpacer;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *messageRead;
    myScollArea *messageScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *messageCenter)
    {
        if (messageCenter->objectName().isEmpty())
            messageCenter->setObjectName(QString::fromUtf8("messageCenter"));
        messageCenter->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(messageCenter);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(messageCenter);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 30, 15, 30);
        goBack = new QPushButton(widget);
        goBack->setObjectName(QString::fromUtf8("goBack"));
        sizePolicy.setHeightForWidth(goBack->sizePolicy().hasHeightForWidth());
        goBack->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        goBack->setFont(font);
        goBack->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/style.qss"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icon/return.png"), QSize(), QIcon::Normal, QIcon::On);
        goBack->setIcon(icon);
        goBack->setCheckable(true);

        horizontalLayout->addWidget(goBack);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        titleLabel = new QLabel(widget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setFont(font);
        titleLabel->setMargin(0);

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer_2 = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        messageRead = new QPushButton(widget);
        messageRead->setObjectName(QString::fromUtf8("messageRead"));

        horizontalLayout->addWidget(messageRead);


        verticalLayout_2->addWidget(widget);

        messageScrollArea = new myScollArea(messageCenter);
        messageScrollArea->setObjectName(QString::fromUtf8("messageScrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(messageScrollArea->sizePolicy().hasHeightForWidth());
        messageScrollArea->setSizePolicy(sizePolicy1);
        messageScrollArea->setMinimumSize(QSize(0, 0));
        messageScrollArea->setMaximumSize(QSize(16777215, 16777215));
        messageScrollArea->setMouseTracking(true);
        messageScrollArea->setTabletTracking(true);
        messageScrollArea->setContextMenuPolicy(Qt::DefaultContextMenu);
        messageScrollArea->setAcceptDrops(true);
        messageScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        messageScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        messageScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        messageScrollArea->setWidgetResizable(true);
        messageScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 1000));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        scrollAreaWidgetContents->setMouseTracking(true);
        scrollAreaWidgetContents->setTabletTracking(true);
        scrollAreaWidgetContents->setAcceptDrops(true);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(15, 0, 15, 0);
        messageScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(messageScrollArea);


        retranslateUi(messageCenter);

        QMetaObject::connectSlotsByName(messageCenter);
    } // setupUi

    void retranslateUi(QWidget *messageCenter)
    {
        messageCenter->setWindowTitle(QCoreApplication::translate("messageCenter", "Form", nullptr));
        goBack->setText(QString());
        titleLabel->setText(QCoreApplication::translate("messageCenter", "\346\266\210\346\201\257\344\270\255\345\277\203", nullptr));
        messageRead->setText(QCoreApplication::translate("messageCenter", "\344\270\200\351\224\256\345\267\262\350\257\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class messageCenter: public Ui_messageCenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGECENTER_H
