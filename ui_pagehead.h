/********************************************************************************
** Form generated from reading UI file 'pagehead.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEHEAD_H
#define UI_PAGEHEAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageHead
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *pageTitle;

    void setupUi(QWidget *pageHead)
    {
        if (pageHead->objectName().isEmpty())
            pageHead->setObjectName(QString::fromUtf8("pageHead"));
        pageHead->resize(400, 106);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pageHead->sizePolicy().hasHeightForWidth());
        pageHead->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(pageHead);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 30, 0, 30);
        pageTitle = new QLabel(pageHead);
        pageTitle->setObjectName(QString::fromUtf8("pageTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pageTitle->sizePolicy().hasHeightForWidth());
        pageTitle->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        pageTitle->setFont(font);
        pageTitle->setTextFormat(Qt::AutoText);
        pageTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pageTitle);


        retranslateUi(pageHead);

        QMetaObject::connectSlotsByName(pageHead);
    } // setupUi

    void retranslateUi(QWidget *pageHead)
    {
        pageHead->setWindowTitle(QCoreApplication::translate("pageHead", "Form", nullptr));
        pageTitle->setText(QCoreApplication::translate("pageHead", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageHead: public Ui_pageHead {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEHEAD_H
