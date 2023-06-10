/********************************************************************************
** Form generated from reading UI file 'listbtn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTBTN_H
#define UI_LISTBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listBtn
{
public:
    QVBoxLayout *verticalLayout;
    QToolButton *listBtnItem;

    void setupUi(QWidget *listBtn)
    {
        if (listBtn->objectName().isEmpty())
            listBtn->setObjectName(QString::fromUtf8("listBtn"));
        listBtn->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listBtn->sizePolicy().hasHeightForWidth());
        listBtn->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(listBtn);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listBtnItem = new QToolButton(listBtn);
        listBtnItem->setObjectName(QString::fromUtf8("listBtnItem"));
        sizePolicy.setHeightForWidth(listBtnItem->sizePolicy().hasHeightForWidth());
        listBtnItem->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(listBtnItem);


        retranslateUi(listBtn);

        QMetaObject::connectSlotsByName(listBtn);
    } // setupUi

    void retranslateUi(QWidget *listBtn)
    {
        listBtn->setWindowTitle(QCoreApplication::translate("listBtn", "Form", nullptr));
        listBtnItem->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class listBtn: public Ui_listBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTBTN_H
