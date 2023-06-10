/********************************************************************************
** Form generated from reading UI file 'horizontalbtn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HORIZONTALBTN_H
#define UI_HORIZONTALBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_horizontalBtn
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *horizontalBtnFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *horIcon;
    QPushButton *horTxt;

    void setupUi(QWidget *horizontalBtn)
    {
        if (horizontalBtn->objectName().isEmpty())
            horizontalBtn->setObjectName(QString::fromUtf8("horizontalBtn"));
        horizontalBtn->resize(91, 31);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalBtn->sizePolicy().hasHeightForWidth());
        horizontalBtn->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(7);
        horizontalBtn->setFont(font);
        verticalLayout = new QVBoxLayout(horizontalBtn);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalBtnFrame = new QFrame(horizontalBtn);
        horizontalBtnFrame->setObjectName(QString::fromUtf8("horizontalBtnFrame"));
        sizePolicy.setHeightForWidth(horizontalBtnFrame->sizePolicy().hasHeightForWidth());
        horizontalBtnFrame->setSizePolicy(sizePolicy);
        horizontalBtnFrame->setFrameShape(QFrame::StyledPanel);
        horizontalBtnFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(horizontalBtnFrame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, 5, 12, 5);
        horIcon = new QPushButton(horizontalBtnFrame);
        horIcon->setObjectName(QString::fromUtf8("horIcon"));
        sizePolicy.setHeightForWidth(horIcon->sizePolicy().hasHeightForWidth());
        horIcon->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(horIcon);

        horTxt = new QPushButton(horizontalBtnFrame);
        horTxt->setObjectName(QString::fromUtf8("horTxt"));
        sizePolicy.setHeightForWidth(horTxt->sizePolicy().hasHeightForWidth());
        horTxt->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(9);
        horTxt->setFont(font1);

        horizontalLayout->addWidget(horTxt);


        verticalLayout->addWidget(horizontalBtnFrame);


        retranslateUi(horizontalBtn);

        QMetaObject::connectSlotsByName(horizontalBtn);
    } // setupUi

    void retranslateUi(QWidget *horizontalBtn)
    {
        horizontalBtn->setWindowTitle(QCoreApplication::translate("horizontalBtn", "Form", nullptr));
        horIcon->setText(QString());
        horTxt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class horizontalBtn: public Ui_horizontalBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HORIZONTALBTN_H
