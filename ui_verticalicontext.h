/********************************************************************************
** Form generated from reading UI file 'verticalicontext.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTICALICONTEXT_H
#define UI_VERTICALICONTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verticalIconText
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *verticalIconTextFrame;
    QVBoxLayout *verticalLayout_2;
    QPushButton *icon;
    QPushButton *txt;

    void setupUi(QWidget *verticalIconText)
    {
        if (verticalIconText->objectName().isEmpty())
            verticalIconText->setObjectName(QString::fromUtf8("verticalIconText"));
        verticalIconText->resize(100, 67);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalIconText->sizePolicy().hasHeightForWidth());
        verticalIconText->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalIconText);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalIconTextFrame = new QFrame(verticalIconText);
        verticalIconTextFrame->setObjectName(QString::fromUtf8("verticalIconTextFrame"));
        verticalIconTextFrame->setFrameShape(QFrame::StyledPanel);
        verticalIconTextFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(verticalIconTextFrame);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 5, 0, 5);
        icon = new QPushButton(verticalIconTextFrame);
        icon->setObjectName(QString::fromUtf8("icon"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(icon->sizePolicy().hasHeightForWidth());
        icon->setSizePolicy(sizePolicy1);
        icon->setStyleSheet(QString::fromUtf8("border-left:3px solid red;"));

        verticalLayout_2->addWidget(icon);

        txt = new QPushButton(verticalIconTextFrame);
        txt->setObjectName(QString::fromUtf8("txt"));
        sizePolicy1.setHeightForWidth(txt->sizePolicy().hasHeightForWidth());
        txt->setSizePolicy(sizePolicy1);
        txt->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(txt);


        verticalLayout->addWidget(verticalIconTextFrame);


        retranslateUi(verticalIconText);

        QMetaObject::connectSlotsByName(verticalIconText);
    } // setupUi

    void retranslateUi(QWidget *verticalIconText)
    {
        verticalIconText->setWindowTitle(QCoreApplication::translate("verticalIconText", "Form", nullptr));
        icon->setText(QCoreApplication::translate("verticalIconText", "icon", nullptr));
        txt->setText(QCoreApplication::translate("verticalIconText", "txt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class verticalIconText: public Ui_verticalIconText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTICALICONTEXT_H
