/********************************************************************************
** Form generated from reading UI file 'users_requests.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_REQUESTS_H
#define UI_USERS_REQUESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_users_requests
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *pushButton_show;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QScrollBar *verticalScrollBar;
    QTextBrowser *textBrowser;
    QLabel *background;

    void setupUi(QDialog *users_requests)
    {
        if (users_requests->objectName().isEmpty())
            users_requests->setObjectName(QStringLiteral("users_requests"));
        users_requests->resize(491, 360);
        frame = new QFrame(users_requests);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 471, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 111, 17));
        pushButton_show = new QPushButton(frame);
        pushButton_show->setObjectName(QStringLiteral("pushButton_show"));
        pushButton_show->setGeometry(QRect(350, 300, 97, 27));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 50, 341, 241));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalScrollBar = new QScrollBar(layoutWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        background = new QLabel(users_requests);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 511, 381));
        background->raise();
        frame->raise();

        retranslateUi(users_requests);

        QMetaObject::connectSlotsByName(users_requests);
    } // setupUi

    void retranslateUi(QDialog *users_requests)
    {
        users_requests->setWindowTitle(QApplication::translate("users_requests", "Requests List", 0));
        label->setText(QApplication::translate("users_requests", "List of requests", 0));
        pushButton_show->setText(QApplication::translate("users_requests", "Show", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class users_requests: public Ui_users_requests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_REQUESTS_H
