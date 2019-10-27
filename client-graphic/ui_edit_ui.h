/********************************************************************************
** Form generated from reading UI file 'edit_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_UI_H
#define UI_EDIT_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_ui
{
public:
    QTextBrowser *textBrowser;
    QFrame *frame;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_edit;

    void setupUi(QDialog *edit_ui)
    {
        if (edit_ui->objectName().isEmpty())
            edit_ui->setObjectName(QStringLiteral("edit_ui"));
        edit_ui->resize(451, 279);
        textBrowser = new QTextBrowser(edit_ui);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 20, 256, 239));
        frame = new QFrame(edit_ui);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 10, 431, 261));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(edit_ui);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(300, 50, 126, 62));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_edit = new QPushButton(widget);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));

        verticalLayout->addWidget(pushButton_edit);

        frame->raise();
        textBrowser->raise();
        pushButton_edit->raise();
        pushButton_2->raise();
        textBrowser->raise();

        retranslateUi(edit_ui);

        QMetaObject::connectSlotsByName(edit_ui);
    } // setupUi

    void retranslateUi(QDialog *edit_ui)
    {
        edit_ui->setWindowTitle(QApplication::translate("edit_ui", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("edit_ui", "Version content", 0));
        pushButton_edit->setText(QApplication::translate("edit_ui", "Edit new line", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_ui: public Ui_edit_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_UI_H
