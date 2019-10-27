/********************************************************************************
** Form generated from reading UI file 'users_grant.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_GRANT_H
#define UI_USERS_GRANT_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_users_grant
{
public:
    QFrame *frame;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *bookNameLLabel;
    QLineEdit *bookNameLineEdit;
    QPushButton *pushButton;
    QLabel *background;

    void setupUi(QDialog *users_grant)
    {
        if (users_grant->objectName().isEmpty())
            users_grant->setObjectName(QStringLiteral("users_grant"));
        users_grant->resize(332, 141);
        frame = new QFrame(users_grant);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 291, 121));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 251, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        bookNameLLabel = new QLabel(formLayoutWidget);
        bookNameLLabel->setObjectName(QStringLiteral("bookNameLLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, bookNameLLabel);

        bookNameLineEdit = new QLineEdit(formLayoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton);

        background = new QLabel(users_grant);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 351, 171));
        background->raise();
        frame->raise();

        retranslateUi(users_grant);

        QMetaObject::connectSlotsByName(users_grant);
    } // setupUi

    void retranslateUi(QDialog *users_grant)
    {
        users_grant->setWindowTitle(QApplication::translate("users_grant", "Grant Requests", 0));
        bookNameLLabel->setText(QApplication::translate("users_grant", "Book Name: ", 0));
        pushButton->setText(QApplication::translate("users_grant", "Grant", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class users_grant: public Ui_users_grant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_GRANT_H
