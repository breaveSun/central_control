/********************************************************************************
** Form generated from reading UI file 'verticaltxtunit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTICALTXTUNIT_H
#define UI_VERTICALTXTUNIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verticalTxtUnit
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *num;
    QLabel *unit;
    QLabel *title;

    void setupUi(QWidget *verticalTxtUnit)
    {
        if (verticalTxtUnit->objectName().isEmpty())
            verticalTxtUnit->setObjectName(QString::fromUtf8("verticalTxtUnit"));
        verticalTxtUnit->resize(109, 92);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalTxtUnit->sizePolicy().hasHeightForWidth());
        verticalTxtUnit->setSizePolicy(sizePolicy);
        verticalTxtUnit->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(verticalTxtUnit);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(verticalTxtUnit);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 35));
        widget->setMaximumSize(QSize(16777215, 35));
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        num = new QLabel(widget);
        num->setObjectName(QString::fromUtf8("num"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(num->sizePolicy().hasHeightForWidth());
        num->setSizePolicy(sizePolicy2);
        num->setMinimumSize(QSize(0, 0));
        num->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(15);
        num->setFont(font);
        num->setStyleSheet(QString::fromUtf8(""));
        num->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        num->setIndent(0);

        horizontalLayout->addWidget(num);

        unit = new QLabel(widget);
        unit->setObjectName(QString::fromUtf8("unit"));
        sizePolicy2.setHeightForWidth(unit->sizePolicy().hasHeightForWidth());
        unit->setSizePolicy(sizePolicy2);
        unit->setMinimumSize(QSize(0, 0));
        unit->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(8);
        unit->setFont(font1);
        unit->setStyleSheet(QString::fromUtf8(""));
        unit->setScaledContents(false);
        unit->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        unit->setMargin(0);
        unit->setIndent(0);

        horizontalLayout->addWidget(unit);


        verticalLayout_2->addWidget(widget);

        title = new QLabel(verticalTxtUnit);
        title->setObjectName(QString::fromUtf8("title"));
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setMinimumSize(QSize(70, 20));
        title->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(9);
        title->setFont(font2);
        title->setLayoutDirection(Qt::RightToLeft);
        title->setAlignment(Qt::AlignCenter);
        title->setMargin(0);
        title->setIndent(0);

        verticalLayout_2->addWidget(title);


        retranslateUi(verticalTxtUnit);

        QMetaObject::connectSlotsByName(verticalTxtUnit);
    } // setupUi

    void retranslateUi(QWidget *verticalTxtUnit)
    {
        verticalTxtUnit->setWindowTitle(QCoreApplication::translate("verticalTxtUnit", "Form", nullptr));
        num->setText(QCoreApplication::translate("verticalTxtUnit", "\344\274\230", nullptr));
        unit->setText(QCoreApplication::translate("verticalTxtUnit", "%", nullptr));
        title->setText(QCoreApplication::translate("verticalTxtUnit", "\346\271\277\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class verticalTxtUnit: public Ui_verticalTxtUnit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTICALTXTUNIT_H
