/********************************************************************************
** Form generated from reading UI file 'new_book.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_BOOK_H
#define UI_NEW_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_book
{
public:
    QFrame *frame;
    QLabel *label_title;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QSpacerItem *verticalSpacer_6;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_writer_name;
    QSpacerItem *verticalSpacer;
    QTextEdit *writers;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *new_book)
    {
        if (new_book->objectName().isEmpty())
            new_book->setObjectName(QStringLiteral("new_book"));
        new_book->resize(452, 411);
        frame = new QFrame(new_book);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 20, 411, 371));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_title = new QLabel(frame);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(10, 10, 81, 17));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 50, 311, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bookNameLabel = new QLabel(verticalLayoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));
        QFont font;
        font.setPointSize(10);
        bookNameLabel->setFont(font);

        verticalLayout->addWidget(bookNameLabel);

        bookNameLineEdit = new QLineEdit(verticalLayoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        verticalLayout->addWidget(bookNameLineEdit);

        verticalSpacer_6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalLayoutWidget_2 = new QWidget(frame);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(40, 140, 311, 181));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_writer_name = new QLabel(verticalLayoutWidget_2);
        label_writer_name->setObjectName(QStringLiteral("label_writer_name"));
        label_writer_name->setFont(font);

        verticalLayout_2->addWidget(label_writer_name);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        writers = new QTextEdit(verticalLayoutWidget_2);
        writers->setObjectName(QStringLiteral("writers"));

        verticalLayout_2->addWidget(writers);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 330, 260, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_title->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        buttonBox->raise();
        frame->raise();

        retranslateUi(new_book);

        QMetaObject::connectSlotsByName(new_book);
    } // setupUi

    void retranslateUi(QDialog *new_book)
    {
        new_book->setWindowTitle(QApplication::translate("new_book", "Create New Book", 0));
        label_title->setText(QApplication::translate("new_book", "New Book", 0));
        bookNameLabel->setText(QApplication::translate("new_book", "Book Name :", 0));
        label_writer_name->setText(QApplication::translate("new_book", "Writers Name: ", 0));
    } // retranslateUi

};

namespace Ui {
    class new_book: public Ui_new_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_BOOK_H
