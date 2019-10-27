/********************************************************************************
** Form generated from reading UI file 'latest_version.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LATEST_VERSION_H
#define UI_LATEST_VERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_latest_version
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *latest_version)
    {
        if (latest_version->objectName().isEmpty())
            latest_version->setObjectName(QStringLiteral("latest_version"));
        latest_version->resize(309, 177);
        frame = new QFrame(latest_version);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 271, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(latest_version);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 254, 117));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        seasonNameLabel = new QLabel(layoutWidget);
        seasonNameLabel->setObjectName(QStringLiteral("seasonNameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, seasonNameLabel);

        seasonNameLineEdit = new QLineEdit(layoutWidget);
        seasonNameLineEdit->setObjectName(QStringLiteral("seasonNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, seasonNameLineEdit);


        verticalLayout->addLayout(formLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(latest_version);

        QMetaObject::connectSlotsByName(latest_version);
    } // setupUi

    void retranslateUi(QDialog *latest_version)
    {
        latest_version->setWindowTitle(QApplication::translate("latest_version", "Dialog", 0));
        bookNameLabel->setText(QApplication::translate("latest_version", "Book Name: ", 0));
        seasonNameLabel->setText(QApplication::translate("latest_version", "Season Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class latest_version: public Ui_latest_version {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LATEST_VERSION_H
