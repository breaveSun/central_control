/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainPage
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *ctrlList;
    QPushButton *homepage;

    void setupUi(QWidget *mainPage)
    {
        if (mainPage->objectName().isEmpty())
            mainPage->setObjectName(QString::fromUtf8("mainPage"));
        mainPage->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainPage->sizePolicy().hasHeightForWidth());
        mainPage->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(mainPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ctrlList = new QPushButton(mainPage);
        ctrlList->setObjectName(QString::fromUtf8("ctrlList"));

        verticalLayout->addWidget(ctrlList);

        homepage = new QPushButton(mainPage);
        homepage->setObjectName(QString::fromUtf8("homepage"));

        verticalLayout->addWidget(homepage);


        retranslateUi(mainPage);

        QMetaObject::connectSlotsByName(mainPage);
    } // setupUi

    void retranslateUi(QWidget *mainPage)
    {
        mainPage->setWindowTitle(QCoreApplication::translate("mainPage", "Form", nullptr));
        ctrlList->setText(QCoreApplication::translate("mainPage", "Control List", nullptr));
        homepage->setText(QCoreApplication::translate("mainPage", "home page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainPage: public Ui_mainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
