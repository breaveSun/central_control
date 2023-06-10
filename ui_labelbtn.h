/********************************************************************************
** Form generated from reading UI file 'labelbtn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELBTN_H
#define UI_LABELBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_labelBtn
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *labelBtn)
    {
        if (labelBtn->objectName().isEmpty())
            labelBtn->setObjectName(QString::fromUtf8("labelBtn"));
        labelBtn->resize(80, 49);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelBtn->sizePolicy().hasHeightForWidth());
        labelBtn->setSizePolicy(sizePolicy);
        labelBtn->setMinimumSize(QSize(80, 20));
        QFont font;
        font.setPointSize(15);
        labelBtn->setFont(font);
        verticalLayout = new QVBoxLayout(labelBtn);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(labelBtn);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pushButton);


        retranslateUi(labelBtn);

        QMetaObject::connectSlotsByName(labelBtn);
    } // setupUi

    void retranslateUi(QWidget *labelBtn)
    {
        labelBtn->setWindowTitle(QCoreApplication::translate("labelBtn", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("labelBtn", "\347\224\250\344\272\216\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class labelBtn: public Ui_labelBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELBTN_H
