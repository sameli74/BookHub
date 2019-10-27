/********************************************************************************
** Form generated from reading UI file 'publish.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLISH_H
#define UI_PUBLISH_H

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

class Ui_publish
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QPushButton *pushButton;
    QFrame *frame;
    QLabel *background;

    void setupUi(QDialog *publish)
    {
        if (publish->objectName().isEmpty())
            publish->setObjectName(QStringLiteral("publish"));
        publish->resize(294, 113);
        layoutWidget = new QWidget(publish);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 242, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        frame = new QFrame(publish);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 271, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        background = new QLabel(publish);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 311, 131));
        background->raise();
        frame->raise();
        layoutWidget->raise();

        retranslateUi(publish);

        QMetaObject::connectSlotsByName(publish);
    } // setupUi

    void retranslateUi(QDialog *publish)
    {
        publish->setWindowTitle(QApplication::translate("publish", "Dialog", 0));
        bookNameLabel->setText(QApplication::translate("publish", "Book Name: ", 0));
        pushButton->setText(QApplication::translate("publish", "Publish", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class publish: public Ui_publish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLISH_H
