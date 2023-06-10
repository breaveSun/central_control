/********************************************************************************
** Form generated from reading UI file 'fingerboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINGERBOARD_H
#define UI_FINGERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fingerboard
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnA;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btnDel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnB;
    QPushButton *btnC;
    QPushButton *btnD;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn4;
    QPushButton *btn7;
    QPushButton *btnE;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btnF;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn6;
    QPushButton *btn9;
    QPushButton *btn0;
    QPushButton *btnDefine;

    void setupUi(QWidget *fingerboard)
    {
        if (fingerboard->objectName().isEmpty())
            fingerboard->setObjectName(QString::fromUtf8("fingerboard"));
        fingerboard->resize(635, 326);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fingerboard->sizePolicy().hasHeightForWidth());
        fingerboard->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(fingerboard);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(fingerboard);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 12, 5, 0);
        btnA = new QPushButton(widget_2);
        btnA->setObjectName(QString::fromUtf8("btnA"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnA->sizePolicy().hasHeightForWidth());
        btnA->setSizePolicy(sizePolicy1);
        btnA->setMinimumSize(QSize(0, 70));
        btnA->setMaximumSize(QSize(16777215, 70));

        horizontalLayout->addWidget(btnA);

        btn1 = new QPushButton(widget_2);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy2);
        btn1->setMinimumSize(QSize(0, 70));
        btn1->setMaximumSize(QSize(16777215, 70));

        horizontalLayout->addWidget(btn1);

        btn2 = new QPushButton(widget_2);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        sizePolicy1.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy1);
        btn2->setMinimumSize(QSize(0, 70));
        btn2->setMaximumSize(QSize(16777215, 70));

        horizontalLayout->addWidget(btn2);

        btn3 = new QPushButton(widget_2);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        sizePolicy2.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy2);
        btn3->setMinimumSize(QSize(0, 70));
        btn3->setMaximumSize(QSize(16777215, 70));

        horizontalLayout->addWidget(btn3);

        btnDel = new QPushButton(widget_2);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        sizePolicy1.setHeightForWidth(btnDel->sizePolicy().hasHeightForWidth());
        btnDel->setSizePolicy(sizePolicy1);
        btnDel->setMinimumSize(QSize(0, 70));
        btnDel->setMaximumSize(QSize(16777215, 70));

        horizontalLayout->addWidget(btnDel);


        verticalLayout_4->addWidget(widget_2);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 4, 5, 20);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnB = new QPushButton(widget_3);
        btnB->setObjectName(QString::fromUtf8("btnB"));
        sizePolicy2.setHeightForWidth(btnB->sizePolicy().hasHeightForWidth());
        btnB->setSizePolicy(sizePolicy2);
        btnB->setMinimumSize(QSize(0, 70));
        btnB->setMaximumSize(QSize(16777215, 70));

        verticalLayout_2->addWidget(btnB);

        btnC = new QPushButton(widget_3);
        btnC->setObjectName(QString::fromUtf8("btnC"));
        sizePolicy1.setHeightForWidth(btnC->sizePolicy().hasHeightForWidth());
        btnC->setSizePolicy(sizePolicy1);
        btnC->setMinimumSize(QSize(0, 70));
        btnC->setMaximumSize(QSize(16777215, 70));

        verticalLayout_2->addWidget(btnC);

        btnD = new QPushButton(widget_3);
        btnD->setObjectName(QString::fromUtf8("btnD"));
        sizePolicy1.setHeightForWidth(btnD->sizePolicy().hasHeightForWidth());
        btnD->setSizePolicy(sizePolicy1);
        btnD->setMinimumSize(QSize(0, 70));
        btnD->setMaximumSize(QSize(16777215, 70));

        verticalLayout_2->addWidget(btnD);


        horizontalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn4 = new QPushButton(widget_4);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        sizePolicy1.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy1);
        btn4->setMinimumSize(QSize(0, 70));
        btn4->setMaximumSize(QSize(16777215, 70));

        verticalLayout_3->addWidget(btn4);

        btn7 = new QPushButton(widget_4);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        sizePolicy1.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy1);
        btn7->setMinimumSize(QSize(0, 70));
        btn7->setMaximumSize(QSize(16777215, 70));

        verticalLayout_3->addWidget(btn7);

        btnE = new QPushButton(widget_4);
        btnE->setObjectName(QString::fromUtf8("btnE"));
        sizePolicy1.setHeightForWidth(btnE->sizePolicy().hasHeightForWidth());
        btnE->setSizePolicy(sizePolicy1);
        btnE->setMinimumSize(QSize(0, 70));
        btnE->setMaximumSize(QSize(16777215, 70));

        verticalLayout_3->addWidget(btnE);


        horizontalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        btn5 = new QPushButton(widget_5);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        sizePolicy1.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy1);
        btn5->setMinimumSize(QSize(0, 70));
        btn5->setMaximumSize(QSize(16777215, 70));

        verticalLayout_5->addWidget(btn5);

        btn8 = new QPushButton(widget_5);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        sizePolicy1.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy1);
        btn8->setMinimumSize(QSize(0, 70));
        btn8->setMaximumSize(QSize(16777215, 70));

        verticalLayout_5->addWidget(btn8);

        btnF = new QPushButton(widget_5);
        btnF->setObjectName(QString::fromUtf8("btnF"));
        sizePolicy1.setHeightForWidth(btnF->sizePolicy().hasHeightForWidth());
        btnF->setSizePolicy(sizePolicy1);
        btnF->setMinimumSize(QSize(0, 70));
        btnF->setMaximumSize(QSize(16777215, 70));

        verticalLayout_5->addWidget(btnF);


        horizontalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(widget_6);
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        btn6 = new QPushButton(widget_6);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        sizePolicy2.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy2);
        btn6->setMinimumSize(QSize(0, 70));
        btn6->setMaximumSize(QSize(16777215, 70));

        verticalLayout_6->addWidget(btn6);

        btn9 = new QPushButton(widget_6);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        sizePolicy2.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy2);
        btn9->setMinimumSize(QSize(0, 70));
        btn9->setMaximumSize(QSize(16777215, 70));

        verticalLayout_6->addWidget(btn9);

        btn0 = new QPushButton(widget_6);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        sizePolicy1.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy1);
        btn0->setMinimumSize(QSize(0, 70));
        btn0->setMaximumSize(QSize(16777215, 70));

        verticalLayout_6->addWidget(btn0);


        horizontalLayout_2->addWidget(widget_6);

        btnDefine = new QPushButton(widget);
        btnDefine->setObjectName(QString::fromUtf8("btnDefine"));
        sizePolicy1.setHeightForWidth(btnDefine->sizePolicy().hasHeightForWidth());
        btnDefine->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(btnDefine);


        verticalLayout_4->addWidget(widget);


        verticalLayout->addWidget(frame);


        retranslateUi(fingerboard);

        QMetaObject::connectSlotsByName(fingerboard);
    } // setupUi

    void retranslateUi(QWidget *fingerboard)
    {
        fingerboard->setWindowTitle(QCoreApplication::translate("fingerboard", "Form", nullptr));
        btnA->setText(QCoreApplication::translate("fingerboard", "A", nullptr));
        btn1->setText(QCoreApplication::translate("fingerboard", "1", nullptr));
        btn2->setText(QCoreApplication::translate("fingerboard", "2", nullptr));
        btn3->setText(QCoreApplication::translate("fingerboard", "3", nullptr));
        btnDel->setText(QCoreApplication::translate("fingerboard", "del", nullptr));
        btnB->setText(QCoreApplication::translate("fingerboard", "B", nullptr));
        btnC->setText(QCoreApplication::translate("fingerboard", "C", nullptr));
        btnD->setText(QCoreApplication::translate("fingerboard", "D", nullptr));
        btn4->setText(QCoreApplication::translate("fingerboard", "4", nullptr));
        btn7->setText(QCoreApplication::translate("fingerboard", "7", nullptr));
        btnE->setText(QCoreApplication::translate("fingerboard", "E", nullptr));
        btn5->setText(QCoreApplication::translate("fingerboard", "5", nullptr));
        btn8->setText(QCoreApplication::translate("fingerboard", "8", nullptr));
        btnF->setText(QCoreApplication::translate("fingerboard", "F", nullptr));
        btn6->setText(QCoreApplication::translate("fingerboard", "6", nullptr));
        btn9->setText(QCoreApplication::translate("fingerboard", "9", nullptr));
        btn0->setText(QCoreApplication::translate("fingerboard", "0", nullptr));
        btnDefine->setText(QCoreApplication::translate("fingerboard", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fingerboard: public Ui_fingerboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINGERBOARD_H
