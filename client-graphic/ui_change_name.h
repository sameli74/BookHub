/********************************************************************************
** Form generated from reading UI file 'change_name.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_NAME_H
#define UI_CHANGE_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_change_name
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *previousNameLabel;
    QLineEdit *previousNameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *newNameLabel;
    QLineEdit *newNameLineEdit;
    QPushButton *pushButton;
    QLabel *background;

    void setupUi(QDialog *change_name)
    {
        if (change_name->objectName().isEmpty())
            change_name->setObjectName(QStringLiteral("change_name"));
        change_name->resize(321, 160);
        frame = new QFrame(change_name);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 301, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(change_name);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 31, 264, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        previousNameLabel = new QLabel(layoutWidget);
        previousNameLabel->setObjectName(QStringLiteral("previousNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, previousNameLabel);

        previousNameLineEdit = new QLineEdit(layoutWidget);
        previousNameLineEdit->setObjectName(QStringLiteral("previousNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, previousNameLineEdit);


        verticalLayout_2->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        newNameLabel = new QLabel(layoutWidget);
        newNameLabel->setObjectName(QStringLiteral("newNameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, newNameLabel);

        newNameLineEdit = new QLineEdit(layoutWidget);
        newNameLineEdit->setObjectName(QStringLiteral("newNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, newNameLineEdit);


        verticalLayout_2->addLayout(formLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        background = new QLabel(change_name);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 341, 181));
        frame->raise();
        background->raise();
        layoutWidget->raise();

        retranslateUi(change_name);

        QMetaObject::connectSlotsByName(change_name);
    } // setupUi

    void retranslateUi(QDialog *change_name)
    {
        change_name->setWindowTitle(QApplication::translate("change_name", "Change Book Nmae", 0));
        previousNameLabel->setText(QApplication::translate("change_name", "Previous Name:", 0));
        newNameLabel->setText(QApplication::translate("change_name", "New Name: ", 0));
        pushButton->setText(QApplication::translate("change_name", "Apply", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class change_name: public Ui_change_name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_NAME_H
