/********************************************************************************
** Form generated from reading UI file 'book_content.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_CONTENT_H
#define UI_BOOK_CONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_book_content
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QFormLayout *formLayout_3;
    QLabel *numberOfVersionsLabel;
    QSpinBox *numberOfVersionsSpinBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *book_content)
    {
        if (book_content->objectName().isEmpty())
            book_content->setObjectName(QStringLiteral("book_content"));
        book_content->resize(341, 252);
        widget = new QWidget(book_content);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(41, 41, 264, 171));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        bookNameLabel = new QLabel(widget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(widget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        seasonNameLabel = new QLabel(widget);
        seasonNameLabel->setObjectName(QStringLiteral("seasonNameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, seasonNameLabel);

        seasonNameLineEdit = new QLineEdit(widget);
        seasonNameLineEdit->setObjectName(QStringLiteral("seasonNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, seasonNameLineEdit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        numberOfVersionsLabel = new QLabel(widget);
        numberOfVersionsLabel->setObjectName(QStringLiteral("numberOfVersionsLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, numberOfVersionsLabel);

        numberOfVersionsSpinBox = new QSpinBox(widget);
        numberOfVersionsSpinBox->setObjectName(QStringLiteral("numberOfVersionsSpinBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, numberOfVersionsSpinBox);


        verticalLayout->addLayout(formLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(book_content);

        QMetaObject::connectSlotsByName(book_content);
    } // setupUi

    void retranslateUi(QDialog *book_content)
    {
        book_content->setWindowTitle(QApplication::translate("book_content", "Dialog", 0));
        bookNameLabel->setText(QApplication::translate("book_content", "Book Name:", 0));
        seasonNameLabel->setText(QApplication::translate("book_content", "Season Name:", 0));
        numberOfVersionsLabel->setText(QApplication::translate("book_content", "Number of Versions", 0));
        checkBox->setText(QApplication::translate("book_content", "CheckBox", 0));
    } // retranslateUi

};

namespace Ui {
    class book_content: public Ui_book_content {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_CONTENT_H
