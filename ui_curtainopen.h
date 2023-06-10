/********************************************************************************
** Form generated from reading UI file 'curtainopen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURTAINOPEN_H
#define UI_CURTAINOPEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myslider.h"
#include "titleicon.h"
#include "vicontxt.h"

QT_BEGIN_NAMESPACE

class Ui_curtainOpen
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *curtainFrame;
    QVBoxLayout *verticalLayout_2;
    QWidget *curtainTitleList;
    QHBoxLayout *horizontalLayout_2;
    titleIcon *curtainTitle;
    QWidget *curtainButtonW;
    QHBoxLayout *horizontalLayout;
    vIconTxt *open;
    vIconTxt *stop;
    vIconTxt *close;
    QWidget *curtainSliderW;
    QVBoxLayout *verticalLayout_3;
    mySlider *openCloseSlider;
    mySlider *angleSlider;

    void setupUi(QWidget *curtainOpen)
    {
        if (curtainOpen->objectName().isEmpty())
            curtainOpen->setObjectName(QString::fromUtf8("curtainOpen"));
        curtainOpen->resize(281, 202);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(curtainOpen->sizePolicy().hasHeightForWidth());
        curtainOpen->setSizePolicy(sizePolicy);
        curtainOpen->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(curtainOpen);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        curtainFrame = new QFrame(curtainOpen);
        curtainFrame->setObjectName(QString::fromUtf8("curtainFrame"));
        curtainFrame->setFrameShape(QFrame::StyledPanel);
        curtainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(curtainFrame);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        curtainTitleList = new QWidget(curtainFrame);
        curtainTitleList->setObjectName(QString::fromUtf8("curtainTitleList"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(curtainTitleList->sizePolicy().hasHeightForWidth());
        curtainTitleList->setSizePolicy(sizePolicy1);
        curtainTitleList->setMinimumSize(QSize(0, 0));
        curtainTitleList->setMaximumSize(QSize(16777215, 16777215));
        curtainTitleList->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(curtainTitleList);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        curtainTitle = new titleIcon(curtainTitleList);
        curtainTitle->setObjectName(QString::fromUtf8("curtainTitle"));
        sizePolicy1.setHeightForWidth(curtainTitle->sizePolicy().hasHeightForWidth());
        curtainTitle->setSizePolicy(sizePolicy1);
        curtainTitle->setMinimumSize(QSize(0, 0));
        curtainTitle->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(curtainTitle);


        verticalLayout_2->addWidget(curtainTitleList);

        curtainButtonW = new QWidget(curtainFrame);
        curtainButtonW->setObjectName(QString::fromUtf8("curtainButtonW"));
        sizePolicy.setHeightForWidth(curtainButtonW->sizePolicy().hasHeightForWidth());
        curtainButtonW->setSizePolicy(sizePolicy);
        curtainButtonW->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(curtainButtonW);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 20, 0);
        open = new vIconTxt(curtainButtonW);
        open->setObjectName(QString::fromUtf8("open"));
        sizePolicy.setHeightForWidth(open->sizePolicy().hasHeightForWidth());
        open->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(open);

        stop = new vIconTxt(curtainButtonW);
        stop->setObjectName(QString::fromUtf8("stop"));
        sizePolicy.setHeightForWidth(stop->sizePolicy().hasHeightForWidth());
        stop->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(stop);

        close = new vIconTxt(curtainButtonW);
        close->setObjectName(QString::fromUtf8("close"));
        sizePolicy.setHeightForWidth(close->sizePolicy().hasHeightForWidth());
        close->setSizePolicy(sizePolicy);
        close->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(close);


        verticalLayout_2->addWidget(curtainButtonW);

        curtainSliderW = new QWidget(curtainFrame);
        curtainSliderW->setObjectName(QString::fromUtf8("curtainSliderW"));
        verticalLayout_3 = new QVBoxLayout(curtainSliderW);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 30, 20, 0);
        openCloseSlider = new mySlider(curtainSliderW);
        openCloseSlider->setObjectName(QString::fromUtf8("openCloseSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openCloseSlider->sizePolicy().hasHeightForWidth());
        openCloseSlider->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(openCloseSlider);

        angleSlider = new mySlider(curtainSliderW);
        angleSlider->setObjectName(QString::fromUtf8("angleSlider"));
        sizePolicy2.setHeightForWidth(angleSlider->sizePolicy().hasHeightForWidth());
        angleSlider->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(angleSlider);


        verticalLayout_2->addWidget(curtainSliderW);


        verticalLayout->addWidget(curtainFrame);


        retranslateUi(curtainOpen);

        QMetaObject::connectSlotsByName(curtainOpen);
    } // setupUi

    void retranslateUi(QWidget *curtainOpen)
    {
        curtainOpen->setWindowTitle(QCoreApplication::translate("curtainOpen", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class curtainOpen: public Ui_curtainOpen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURTAINOPEN_H
