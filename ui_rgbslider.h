/********************************************************************************
** Form generated from reading UI file 'rgbslider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGBSLIDER_H
#define UI_RGBSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rgbSlider
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *rgbChange;
    QHBoxLayout *horizontalLayout_3;
    QLabel *rgbName;
    QLabel *rgbNum;
    QSlider *sliderLine;

    void setupUi(QWidget *rgbSlider)
    {
        if (rgbSlider->objectName().isEmpty())
            rgbSlider->setObjectName(QString::fromUtf8("rgbSlider"));
        rgbSlider->resize(600, 24);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rgbSlider->sizePolicy().hasHeightForWidth());
        rgbSlider->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        rgbSlider->setFont(font);
        horizontalLayout = new QHBoxLayout(rgbSlider);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rgbChange = new QWidget(rgbSlider);
        rgbChange->setObjectName(QString::fromUtf8("rgbChange"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rgbChange->sizePolicy().hasHeightForWidth());
        rgbChange->setSizePolicy(sizePolicy1);
        rgbChange->setMinimumSize(QSize(0, 0));
        rgbChange->setMaximumSize(QSize(16777215, 16777215));
        rgbChange->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 54, 56);"));
        horizontalLayout_3 = new QHBoxLayout(rgbChange);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(8, 0, 8, 0);
        rgbName = new QLabel(rgbChange);
        rgbName->setObjectName(QString::fromUtf8("rgbName"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rgbName->sizePolicy().hasHeightForWidth());
        rgbName->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(8);
        rgbName->setFont(font1);
        rgbName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rgbName->setIndent(0);

        horizontalLayout_3->addWidget(rgbName);

        rgbNum = new QLabel(rgbChange);
        rgbNum->setObjectName(QString::fromUtf8("rgbNum"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rgbNum->sizePolicy().hasHeightForWidth());
        rgbNum->setSizePolicy(sizePolicy3);
        rgbNum->setMinimumSize(QSize(40, 0));
        rgbNum->setMaximumSize(QSize(40, 16777215));
        QFont font2;
        font2.setPointSize(7);
        rgbNum->setFont(font2);
        rgbNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(rgbNum);


        horizontalLayout->addWidget(rgbChange);

        sliderLine = new QSlider(rgbSlider);
        sliderLine->setObjectName(QString::fromUtf8("sliderLine"));
        sizePolicy.setHeightForWidth(sliderLine->sizePolicy().hasHeightForWidth());
        sliderLine->setSizePolicy(sizePolicy);
        sliderLine->setMinimumSize(QSize(0, 5));
        sliderLine->setMouseTracking(true);
        sliderLine->setTabletTracking(true);
        sliderLine->setStyleSheet(QString::fromUtf8(""));
        sliderLine->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderLine);


        retranslateUi(rgbSlider);

        QMetaObject::connectSlotsByName(rgbSlider);
    } // setupUi

    void retranslateUi(QWidget *rgbSlider)
    {
        rgbSlider->setWindowTitle(QCoreApplication::translate("rgbSlider", "Form", nullptr));
        rgbName->setText(QCoreApplication::translate("rgbSlider", "R ", nullptr));
        rgbNum->setText(QCoreApplication::translate("rgbSlider", "189", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rgbSlider: public Ui_rgbSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGBSLIDER_H
