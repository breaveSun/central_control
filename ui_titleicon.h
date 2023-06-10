/********************************************************************************
** Form generated from reading UI file 'titleicon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEICON_H
#define UI_TITLEICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_titleIcon
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *titleIcone;
    QLabel *titleName;

    void setupUi(QWidget *titleIcon)
    {
        if (titleIcon->objectName().isEmpty())
            titleIcon->setObjectName(QString::fromUtf8("titleIcon"));
        titleIcon->resize(139, 42);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleIcon->sizePolicy().hasHeightForWidth());
        titleIcon->setSizePolicy(sizePolicy);
        titleIcon->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(titleIcon);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        titleIcone = new QLabel(titleIcon);
        titleIcone->setObjectName(QString::fromUtf8("titleIcone"));
        titleIcone->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleIcone->sizePolicy().hasHeightForWidth());
        titleIcone->setSizePolicy(sizePolicy1);
        titleIcone->setMinimumSize(QSize(0, 0));
        titleIcone->setMaximumSize(QSize(16777215, 16777215));
        titleIcone->setSizeIncrement(QSize(52, 0));
        titleIcone->setBaseSize(QSize(16, 0));
        titleIcone->setStyleSheet(QString::fromUtf8(""));
        titleIcone->setTextFormat(Qt::AutoText);
        titleIcone->setPixmap(QPixmap(QString::fromUtf8(":/icon/diaodeng.png")));
        titleIcone->setScaledContents(true);
        titleIcone->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(titleIcone);

        titleName = new QLabel(titleIcon);
        titleName->setObjectName(QString::fromUtf8("titleName"));
        titleName->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(titleName->sizePolicy().hasHeightForWidth());
        titleName->setSizePolicy(sizePolicy2);
        titleName->setMinimumSize(QSize(120, 0));
        titleName->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        titleName->setFont(font);
        titleName->setStyleSheet(QString::fromUtf8(""));
        titleName->setMargin(1);
        titleName->setIndent(6);

        horizontalLayout->addWidget(titleName);


        retranslateUi(titleIcon);

        QMetaObject::connectSlotsByName(titleIcon);
    } // setupUi

    void retranslateUi(QWidget *titleIcon)
    {
        titleIcon->setWindowTitle(QCoreApplication::translate("titleIcon", "Form", nullptr));
        titleIcone->setText(QString());
        titleName->setText(QCoreApplication::translate("titleIcon", "\345\220\212\347\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class titleIcon: public Ui_titleIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEICON_H
