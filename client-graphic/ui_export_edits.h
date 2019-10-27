/********************************************************************************
** Form generated from reading UI file 'export_edits.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_EDITS_H
#define UI_EXPORT_EDITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
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

class Ui_Export_edits
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_final;
    QPushButton *pushButton_send;
    QFrame *frame;
    QLabel *background;

    void setupUi(QDialog *Export_edits)
    {
        if (Export_edits->objectName().isEmpty())
            Export_edits->setObjectName(QStringLiteral("Export_edits"));
        Export_edits->resize(350, 181);
        layoutWidget = new QWidget(Export_edits);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(51, 40, 250, 103));
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_final = new QPushButton(layoutWidget);
        pushButton_final->setObjectName(QStringLiteral("pushButton_final"));

        horizontalLayout->addWidget(pushButton_final);

        pushButton_send = new QPushButton(layoutWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout->addWidget(pushButton_send);


        verticalLayout_2->addLayout(horizontalLayout);

        frame = new QFrame(Export_edits);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 20, 281, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        background = new QLabel(Export_edits);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 371, 201));
        background->raise();
        frame->raise();
        layoutWidget->raise();

        retranslateUi(Export_edits);

        QMetaObject::connectSlotsByName(Export_edits);
    } // setupUi

    void retranslateUi(QDialog *Export_edits)
    {
        Export_edits->setWindowTitle(QApplication::translate("Export_edits", "Export Edits", 0));
        bookNameLabel->setText(QApplication::translate("Export_edits", "Book name: ", 0));
        seasonNameLabel->setText(QApplication::translate("Export_edits", "Season name: ", 0));
        pushButton_final->setText(QApplication::translate("Export_edits", "Set version as final", 0));
        pushButton_send->setText(QApplication::translate("Export_edits", "Send", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Export_edits: public Ui_Export_edits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_EDITS_H
