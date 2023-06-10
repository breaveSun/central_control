/********************************************************************************
** Form generated from reading UI file 'messagecenteritem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGECENTERITEM_H
#define UI_MESSAGECENTERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_messageCenterItem
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *messageTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *title;
    QPushButton *icon;
    QLabel *dateTime;
    QLabel *label;

    void setupUi(QWidget *messageCenterItem)
    {
        if (messageCenterItem->objectName().isEmpty())
            messageCenterItem->setObjectName(QString::fromUtf8("messageCenterItem"));
        messageCenterItem->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messageCenterItem->sizePolicy().hasHeightForWidth());
        messageCenterItem->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(messageCenterItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(messageCenterItem);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, -1, 20, -1);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 100));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        messageTitle = new QWidget(widget);
        messageTitle->setObjectName(QString::fromUtf8("messageTitle"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(messageTitle->sizePolicy().hasHeightForWidth());
        messageTitle->setSizePolicy(sizePolicy3);
        messageTitle->setLayoutDirection(Qt::RightToLeft);
        horizontalLayout_2 = new QHBoxLayout(messageTitle);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        title = new QLabel(messageTitle);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(title);

        icon = new QPushButton(messageTitle);
        icon->setObjectName(QString::fromUtf8("icon"));
        sizePolicy3.setHeightForWidth(icon->sizePolicy().hasHeightForWidth());
        icon->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(icon);


        horizontalLayout->addWidget(messageTitle);

        dateTime = new QLabel(widget);
        dateTime->setObjectName(QString::fromUtf8("dateTime"));
        sizePolicy4.setHeightForWidth(dateTime->sizePolicy().hasHeightForWidth());
        dateTime->setSizePolicy(sizePolicy4);
        dateTime->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout->addWidget(dateTime);


        verticalLayout_2->addWidget(widget);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(0);
        label->setMidLineWidth(0);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(true);
        label->setMargin(0);

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame);


        retranslateUi(messageCenterItem);

        QMetaObject::connectSlotsByName(messageCenterItem);
    } // setupUi

    void retranslateUi(QWidget *messageCenterItem)
    {
        messageCenterItem->setWindowTitle(QCoreApplication::translate("messageCenterItem", "Form", nullptr));
        title->setText(QString());
        icon->setText(QString());
        dateTime->setText(QCoreApplication::translate("messageCenterItem", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("messageCenterItem", " \351\246\226\345\205\210\345\256\236\344\276\213\345\214\226QNetworkRequest\357\274\214\345\260\206\344\274\240\345\205\245\345\217\202\346\225\260\344\275\234\344\270\272url\347\232\204\346\237\245\350\257\242\345\217\202\346\225\260\n"
"\n"
"\345\246\202https://localhost:3001/api/v1/users\n"
"\n"
"\345\212\240\345\205\245\345\217\202\346\225\260\345\220\216\345\217\257\350\203\275\345\217\230\346\210\220https://localhost:3001/api/v1/users?arg1=val1&arg2=val2\n"
"\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224\n"
"\347\211\210\346\235\203\345\243\260\346\230\216\357\274\232\346\234\254\346\226\207\344\270\272CSDN\345\215\232\344\270\273\343\200\214\352\247\201\347\231\275\346\235\250\346\240\221\344\270\213\352\247\202\343\200\215\347\232\204\345\216\237\345\210\233\346\226\207\347\253\240\357\274\214\351\201\265\345\276\252CC 4.0 BY-SA\347\211\210\346\235\203\345\215"
                        "\217\350\256\256\357\274\214\350\275\254\350\275\275\350\257\267\351\231\204\344\270\212\345\216\237\346\226\207\345\207\272\345\244\204\351\223\276\346\216\245\345\217\212\346\234\254\345\243\260\346\230\216\343\200\202\n"
"\345\216\237\346\226\207\351\223\276\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class messageCenterItem: public Ui_messageCenterItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGECENTERITEM_H
