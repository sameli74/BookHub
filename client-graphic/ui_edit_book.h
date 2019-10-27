/********************************************************************************
** Form generated from reading UI file 'edit_book.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_BOOK_H
#define UI_EDIT_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_book
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QFormLayout *formLayout_3;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QFormLayout *formLayout;
    QLabel *whatDoYouWantToDoLabel;
    QComboBox *whatDoYouWantToDoComboBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit_line_number;
    QLabel *label_2;
    QLineEdit *lineEdit_current_text;
    QLabel *label_3;
    QLineEdit *lineEdit_new_text;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *buttonBox;
    QLabel *background;

    void setupUi(QDialog *edit_book)
    {
        if (edit_book->objectName().isEmpty())
            edit_book->setObjectName(QStringLiteral("edit_book"));
        edit_book->resize(523, 430);
        frame = new QFrame(edit_book);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 20, 481, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 268, 342));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));
        QFont font;
        font.setPointSize(10);
        bookNameLabel->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);


        verticalLayout_3->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        seasonNameLabel = new QLabel(layoutWidget);
        seasonNameLabel->setObjectName(QStringLiteral("seasonNameLabel"));
        seasonNameLabel->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, seasonNameLabel);

        seasonNameLineEdit = new QLineEdit(layoutWidget);
        seasonNameLineEdit->setObjectName(QStringLiteral("seasonNameLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, seasonNameLineEdit);


        verticalLayout_3->addLayout(formLayout_3);


        verticalLayout_2->addLayout(verticalLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        whatDoYouWantToDoLabel = new QLabel(layoutWidget);
        whatDoYouWantToDoLabel->setObjectName(QStringLiteral("whatDoYouWantToDoLabel"));
        whatDoYouWantToDoLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, whatDoYouWantToDoLabel);

        whatDoYouWantToDoComboBox = new QComboBox(layoutWidget);
        whatDoYouWantToDoComboBox->setObjectName(QStringLiteral("whatDoYouWantToDoComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, whatDoYouWantToDoComboBox);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer_6);


        verticalLayout_2->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        lineEdit_line_number = new QLineEdit(layoutWidget);
        lineEdit_line_number->setObjectName(QStringLiteral("lineEdit_line_number"));

        verticalLayout->addWidget(lineEdit_line_number);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        lineEdit_current_text = new QLineEdit(layoutWidget);
        lineEdit_current_text->setObjectName(QStringLiteral("lineEdit_current_text"));

        verticalLayout->addWidget(lineEdit_current_text);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        lineEdit_new_text = new QLineEdit(layoutWidget);
        lineEdit_new_text->setObjectName(QStringLiteral("lineEdit_new_text"));

        verticalLayout->addWidget(lineEdit_new_text);

        verticalSpacer_3 = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(190, 350, 264, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        background = new QLabel(edit_book);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 551, 451));
        background->raise();
        frame->raise();

        retranslateUi(edit_book);

        QMetaObject::connectSlotsByName(edit_book);
    } // setupUi

    void retranslateUi(QDialog *edit_book)
    {
        edit_book->setWindowTitle(QApplication::translate("edit_book", "Create new season", 0));
        bookNameLabel->setText(QApplication::translate("edit_book", "Book Name:     ", 0));
        seasonNameLabel->setText(QApplication::translate("edit_book", "Season Name: ", 0));
        whatDoYouWantToDoLabel->setText(QApplication::translate("edit_book", "Select Edit mode: ", 0));
        whatDoYouWantToDoComboBox->clear();
        whatDoYouWantToDoComboBox->insertItems(0, QStringList()
         << QApplication::translate("edit_book", "Add line", 0)
         << QApplication::translate("edit_book", "Change line", 0)
         << QApplication::translate("edit_book", "Remove line", 0)
        );
        label->setText(QApplication::translate("edit_book", "Line number", 0));
        label_2->setText(QApplication::translate("edit_book", "Current text", 0));
        label_3->setText(QApplication::translate("edit_book", "New text", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class edit_book: public Ui_edit_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_BOOK_H
