/********************************************************************************
** Form generated from reading UI file 'ctrllistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLLISTITEM_H
#define UI_CTRLLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <listbtn.h>

QT_BEGIN_NAMESPACE

class Ui_ctrlListItem
{
public:
    QVBoxLayout *verticalLayout;
    listBtn *item;

    void setupUi(QWidget *ctrlListItem)
    {
        if (ctrlListItem->objectName().isEmpty())
            ctrlListItem->setObjectName(QString::fromUtf8("ctrlListItem"));
        ctrlListItem->resize(400, 100);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ctrlListItem->sizePolicy().hasHeightForWidth());
        ctrlListItem->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ctrlListItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(35, 0, 35, 0);
        item = new listBtn(ctrlListItem);
        item->setObjectName(QString::fromUtf8("item"));
        sizePolicy.setHeightForWidth(item->sizePolicy().hasHeightForWidth());
        item->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(item);


        retranslateUi(ctrlListItem);

        QMetaObject::connectSlotsByName(ctrlListItem);
    } // setupUi

    void retranslateUi(QWidget *ctrlListItem)
    {
        ctrlListItem->setWindowTitle(QCoreApplication::translate("ctrlListItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ctrlListItem: public Ui_ctrlListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLLISTITEM_H
