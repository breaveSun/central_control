/********************************************************************************
** Form generated from reading UI file 'myslider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSLIDER_H
#define UI_MYSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mySlider
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *sliderTitle;
    QSlider *hSlider;
    QLabel *sliderNum;
    QLabel *sliderUnit;

    void setupUi(QWidget *mySlider)
    {
        if (mySlider->objectName().isEmpty())
            mySlider->setObjectName(QString::fromUtf8("mySlider"));
        mySlider->resize(600, 24);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mySlider->sizePolicy().hasHeightForWidth());
        mySlider->setSizePolicy(sizePolicy);
        mySlider->setMinimumSize(QSize(0, 5));
        horizontalLayout = new QHBoxLayout(mySlider);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sliderTitle = new QLabel(mySlider);
        sliderTitle->setObjectName(QString::fromUtf8("sliderTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sliderTitle->sizePolicy().hasHeightForWidth());
        sliderTitle->setSizePolicy(sizePolicy1);
        sliderTitle->setMinimumSize(QSize(40, 0));
        sliderTitle->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setPointSize(10);
        sliderTitle->setFont(font);

        horizontalLayout->addWidget(sliderTitle);

        hSlider = new QSlider(mySlider);
        hSlider->setObjectName(QString::fromUtf8("hSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hSlider->sizePolicy().hasHeightForWidth());
        hSlider->setSizePolicy(sizePolicy2);
        hSlider->setStyleSheet(QString::fromUtf8(""));
        hSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hSlider);

        sliderNum = new QLabel(mySlider);
        sliderNum->setObjectName(QString::fromUtf8("sliderNum"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sliderNum->sizePolicy().hasHeightForWidth());
        sliderNum->setSizePolicy(sizePolicy3);
        sliderNum->setMinimumSize(QSize(40, 0));
        sliderNum->setMaximumSize(QSize(40, 16777215));
        sliderNum->setFont(font);
        sliderNum->setContextMenuPolicy(Qt::NoContextMenu);
        sliderNum->setLayoutDirection(Qt::RightToLeft);
        sliderNum->setStyleSheet(QString::fromUtf8("text-align:right;"));
        sliderNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(sliderNum);

        sliderUnit = new QLabel(mySlider);
        sliderUnit->setObjectName(QString::fromUtf8("sliderUnit"));
        sizePolicy1.setHeightForWidth(sliderUnit->sizePolicy().hasHeightForWidth());
        sliderUnit->setSizePolicy(sizePolicy1);
        sliderUnit->setMinimumSize(QSize(15, 0));
        sliderUnit->setMaximumSize(QSize(15, 16777215));
        sliderUnit->setFont(font);

        horizontalLayout->addWidget(sliderUnit);


        retranslateUi(mySlider);

        QMetaObject::connectSlotsByName(mySlider);
    } // setupUi

    void retranslateUi(QWidget *mySlider)
    {
        mySlider->setWindowTitle(QCoreApplication::translate("mySlider", "Form", nullptr));
        sliderTitle->setText(QCoreApplication::translate("mySlider", "\344\272\256\345\272\246", nullptr));
        sliderNum->setText(QCoreApplication::translate("mySlider", "10", nullptr));
        sliderUnit->setText(QCoreApplication::translate("mySlider", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mySlider: public Ui_mySlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSLIDER_H
