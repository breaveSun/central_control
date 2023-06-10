/********************************************************************************
** Form generated from reading UI file 'btntxticon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTNTXTICON_H
#define UI_BTNTXTICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btnTxtIcon
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *btnTxtIconFrame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *txt;
    QPushButton *icon;

    void setupUi(QWidget *btnTxtIcon)
    {
        if (btnTxtIcon->objectName().isEmpty())
            btnTxtIcon->setObjectName(QString::fromUtf8("btnTxtIcon"));
        btnTxtIcon->resize(192, 43);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnTxtIcon->sizePolicy().hasHeightForWidth());
        btnTxtIcon->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(btnTxtIcon);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnTxtIconFrame = new QFrame(btnTxtIcon);
        btnTxtIconFrame->setObjectName(QString::fromUtf8("btnTxtIconFrame"));
        btnTxtIconFrame->setFrameShape(QFrame::StyledPanel);
        btnTxtIconFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(btnTxtIconFrame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 5, 12, 5);
        txt = new QPushButton(btnTxtIconFrame);
        txt->setObjectName(QString::fromUtf8("txt"));
        sizePolicy.setHeightForWidth(txt->sizePolicy().hasHeightForWidth());
        txt->setSizePolicy(sizePolicy);
        txt->setCheckable(true);

        horizontalLayout_2->addWidget(txt);

        icon = new QPushButton(btnTxtIconFrame);
        icon->setObjectName(QString::fromUtf8("icon"));
        sizePolicy.setHeightForWidth(icon->sizePolicy().hasHeightForWidth());
        icon->setSizePolicy(sizePolicy);
        icon->setMinimumSize(QSize(0, 0));
        icon->setMaximumSize(QSize(16777215, 16777215));
        icon->setCheckable(true);

        horizontalLayout_2->addWidget(icon);


        horizontalLayout->addWidget(btnTxtIconFrame);


        retranslateUi(btnTxtIcon);

        QMetaObject::connectSlotsByName(btnTxtIcon);
    } // setupUi

    void retranslateUi(QWidget *btnTxtIcon)
    {
        btnTxtIcon->setWindowTitle(QCoreApplication::translate("btnTxtIcon", "Form", nullptr));
        txt->setText(QCoreApplication::translate("btnTxtIcon", "\346\237\245\347\234\213\350\256\276\345\244\207", nullptr));
        icon->setText(QCoreApplication::translate("btnTxtIcon", "icon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class btnTxtIcon: public Ui_btnTxtIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTNTXTICON_H
