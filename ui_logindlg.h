/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QString::fromUtf8("LoginDlg"));
        LoginDlg->resize(400, 300);
        pushButton = new QPushButton(LoginDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 150, 89, 25));

        retranslateUi(LoginDlg);
        QObject::connect(pushButton, SIGNAL(clicked()), LoginDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QCoreApplication::translate("LoginDlg", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginDlg", "\347\231\273\345\275\225\345\210\260\344\270\273\351\241\265\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
