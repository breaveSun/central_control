/********************************************************************************
** Form generated from reading UI file 'vicontxt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICONTXT_H
#define UI_VICONTXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vIconTxt
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *vIconTxtBtn;

    void setupUi(QWidget *vIconTxt)
    {
        if (vIconTxt->objectName().isEmpty())
            vIconTxt->setObjectName(QString::fromUtf8("vIconTxt"));
        vIconTxt->resize(80, 23);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vIconTxt->sizePolicy().hasHeightForWidth());
        vIconTxt->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(vIconTxt);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        vIconTxtBtn = new QToolButton(vIconTxt);
        vIconTxtBtn->setObjectName(QString::fromUtf8("vIconTxtBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vIconTxtBtn->sizePolicy().hasHeightForWidth());
        vIconTxtBtn->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(vIconTxtBtn);


        retranslateUi(vIconTxt);

        QMetaObject::connectSlotsByName(vIconTxt);
    } // setupUi

    void retranslateUi(QWidget *vIconTxt)
    {
        vIconTxt->setWindowTitle(QCoreApplication::translate("vIconTxt", "Form", nullptr));
        vIconTxtBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class vIconTxt: public Ui_vIconTxt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICONTXT_H
