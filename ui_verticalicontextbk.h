/********************************************************************************
** Form generated from reading UI file 'verticalicontextbk.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTICALICONTEXTBK_H
#define UI_VERTICALICONTEXTBK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_verticalicontextBK
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *verticalicontextBKFrame;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *verticalicontextBK)
    {
        if (verticalicontextBK->objectName().isEmpty())
            verticalicontextBK->setObjectName(QString::fromUtf8("verticalicontextBK"));
        verticalicontextBK->resize(80, 80);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalicontextBK->sizePolicy().hasHeightForWidth());
        verticalicontextBK->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalicontextBK);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalicontextBKFrame = new QFrame(verticalicontextBK);
        verticalicontextBKFrame->setObjectName(QString::fromUtf8("verticalicontextBKFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalicontextBKFrame->sizePolicy().hasHeightForWidth());
        verticalicontextBKFrame->setSizePolicy(sizePolicy1);
        verticalicontextBKFrame->setMinimumSize(QSize(80, 80));
        verticalicontextBKFrame->setMaximumSize(QSize(80, 80));
        verticalicontextBKFrame->setFrameShape(QFrame::StyledPanel);
        verticalicontextBKFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(verticalicontextBKFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(verticalicontextBKFrame);


        retranslateUi(verticalicontextBK);

        QMetaObject::connectSlotsByName(verticalicontextBK);
    } // setupUi

    void retranslateUi(QWidget *verticalicontextBK)
    {
        verticalicontextBK->setWindowTitle(QCoreApplication::translate("verticalicontextBK", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class verticalicontextBK: public Ui_verticalicontextBK {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTICALICONTEXTBK_H
