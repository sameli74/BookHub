/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel_signup;
    QLineEdit *usernameLineEdit_signup;
    QFormLayout *formLayout_5;
    QLabel *passwordLabel_signup;
    QLineEdit *passwordLineEdit_signup;
    QFrame *frame;
    QLabel *label;
    QPushButton *pushButton_signup;
    QLabel *background;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QStringLiteral("signup"));
        signup->resize(432, 225);
        layoutWidget = new QWidget(signup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 70, 261, 81));
        QFont font;
        font.setPointSize(10);
        layoutWidget->setFont(font);
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        usernameLabel_signup = new QLabel(layoutWidget);
        usernameLabel_signup->setObjectName(QStringLiteral("usernameLabel_signup"));
        usernameLabel_signup->setFont(font);

        horizontalLayout->addWidget(usernameLabel_signup);

        usernameLineEdit_signup = new QLineEdit(layoutWidget);
        usernameLineEdit_signup->setObjectName(QStringLiteral("usernameLineEdit_signup"));
        usernameLineEdit_signup->setFont(font);

        horizontalLayout->addWidget(usernameLineEdit_signup);


        verticalLayout->addLayout(horizontalLayout);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        passwordLabel_signup = new QLabel(layoutWidget);
        passwordLabel_signup->setObjectName(QStringLiteral("passwordLabel_signup"));
        passwordLabel_signup->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, passwordLabel_signup);

        passwordLineEdit_signup = new QLineEdit(layoutWidget);
        passwordLineEdit_signup->setObjectName(QStringLiteral("passwordLineEdit_signup"));
        passwordLineEdit_signup->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, passwordLineEdit_signup);


        verticalLayout->addLayout(formLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        frame = new QFrame(signup);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(49, 20, 331, 181));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 269, 33));
        QFont font1;
        font1.setFamily(QStringLiteral("Umpush"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        pushButton_signup = new QPushButton(frame);
        pushButton_signup->setObjectName(QStringLiteral("pushButton_signup"));
        pushButton_signup->setGeometry(QRect(190, 120, 111, 31));
        pushButton_signup->setFont(font);
        background = new QLabel(signup);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 451, 241));
        background->setFont(font);
        background->raise();
        frame->raise();
        layoutWidget->raise();

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QApplication::translate("signup", "Signup", 0));
        usernameLabel_signup->setText(QApplication::translate("signup", "Username :", 0));
        passwordLabel_signup->setText(QApplication::translate("signup", "Password : ", 0));
        label->setText(QApplication::translate("signup", "Signup", 0));
        pushButton_signup->setText(QApplication::translate("signup", "Signup", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
