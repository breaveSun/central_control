/********************************************************************************
** Form generated from reading UI file 'ctrllistpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLLISTPAGE_H
#define UI_CTRLLISTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myscollarea.h"
#include "pagehead.h"

QT_BEGIN_NAMESPACE

class Ui_ctrlListPage
{
public:
    QVBoxLayout *verticalLayout_2;
    pageHead *title;
    QHBoxLayout *horizontalLayout;
    myScollArea *curtainScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *ctrlListPage)
    {
        if (ctrlListPage->objectName().isEmpty())
            ctrlListPage->setObjectName(QString::fromUtf8("ctrlListPage"));
        ctrlListPage->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ctrlListPage->sizePolicy().hasHeightForWidth());
        ctrlListPage->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(ctrlListPage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, 0, 15, 0);
        title = new pageHead(ctrlListPage);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setMinimumSize(QSize(0, 0));
        title->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, 30, 15, 30);

        verticalLayout_2->addWidget(title);

        curtainScrollArea = new myScollArea(ctrlListPage);
        curtainScrollArea->setObjectName(QString::fromUtf8("curtainScrollArea"));
        sizePolicy.setHeightForWidth(curtainScrollArea->sizePolicy().hasHeightForWidth());
        curtainScrollArea->setSizePolicy(sizePolicy);
        curtainScrollArea->setMinimumSize(QSize(0, 0));
        curtainScrollArea->setMaximumSize(QSize(16777215, 16777215));
        curtainScrollArea->setMouseTracking(true);
        curtainScrollArea->setTabletTracking(true);
        curtainScrollArea->setContextMenuPolicy(Qt::DefaultContextMenu);
        curtainScrollArea->setAcceptDrops(true);
        curtainScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        curtainScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        curtainScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        curtainScrollArea->setWidgetResizable(true);
        curtainScrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 368, 1000));
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
        curtainScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(curtainScrollArea);


        retranslateUi(ctrlListPage);

        QMetaObject::connectSlotsByName(ctrlListPage);
    } // setupUi

    void retranslateUi(QWidget *ctrlListPage)
    {
        ctrlListPage->setWindowTitle(QCoreApplication::translate("ctrlListPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ctrlListPage: public Ui_ctrlListPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLLISTPAGE_H
