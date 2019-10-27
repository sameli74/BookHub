/********************************************************************************
** Form generated from reading UI file 'edit_writer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_WRITER_H
#define UI_EDIT_WRITER_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_writer
{
public:
    QFrame *frame;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *changeToWriterLabel;
    QComboBox *changeToWriterComboBox;
    QFormLayout *formLayout_5;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *addingWriterLabel;
    QLineEdit *removingingWriterLineEdit;
    QFormLayout *formLayout_3;
    QLabel *goingToAddLabel;
    QLineEdit *NewWriterLineEdit;
    QLabel *background;

    void setupUi(QDialog *edit_writer)
    {
        if (edit_writer->objectName().isEmpty())
            edit_writer->setObjectName(QStringLiteral("edit_writer"));
        edit_writer->resize(373, 229);
        frame = new QFrame(edit_writer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 351, 211));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 180, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(edit_writer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 282, 138));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        changeToWriterLabel = new QLabel(layoutWidget);
        changeToWriterLabel->setObjectName(QStringLiteral("changeToWriterLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, changeToWriterLabel);

        changeToWriterComboBox = new QComboBox(layoutWidget);
        changeToWriterComboBox->setObjectName(QStringLiteral("changeToWriterComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, changeToWriterComboBox);


        verticalLayout->addLayout(formLayout);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);


        verticalLayout->addLayout(formLayout_5);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        addingWriterLabel = new QLabel(layoutWidget);
        addingWriterLabel->setObjectName(QStringLiteral("addingWriterLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, addingWriterLabel);

        removingingWriterLineEdit = new QLineEdit(layoutWidget);
        removingingWriterLineEdit->setObjectName(QStringLiteral("removingingWriterLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, removingingWriterLineEdit);


        verticalLayout->addLayout(formLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        goingToAddLabel = new QLabel(layoutWidget);
        goingToAddLabel->setObjectName(QStringLiteral("goingToAddLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, goingToAddLabel);

        NewWriterLineEdit = new QLineEdit(layoutWidget);
        NewWriterLineEdit->setObjectName(QStringLiteral("NewWriterLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, NewWriterLineEdit);


        verticalLayout_2->addLayout(formLayout_3);

        background = new QLabel(edit_writer);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 401, 251));
        background->raise();
        frame->raise();
        layoutWidget->raise();

        retranslateUi(edit_writer);

        QMetaObject::connectSlotsByName(edit_writer);
    } // setupUi

    void retranslateUi(QDialog *edit_writer)
    {
        edit_writer->setWindowTitle(QApplication::translate("edit_writer", "Dialog", 0));
        changeToWriterLabel->setText(QApplication::translate("edit_writer", "Change to writer", 0));
        changeToWriterComboBox->clear();
        changeToWriterComboBox->insertItems(0, QStringList()
         << QApplication::translate("edit_writer", "add", 0)
         << QApplication::translate("edit_writer", "remove", 0)
        );
        bookNameLabel->setText(QApplication::translate("edit_writer", "Book Name: ", 0));
        addingWriterLabel->setText(QApplication::translate("edit_writer", "Going to remove:", 0));
        goingToAddLabel->setText(QApplication::translate("edit_writer", "New Writer: ", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class edit_writer: public Ui_edit_writer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_WRITER_H
