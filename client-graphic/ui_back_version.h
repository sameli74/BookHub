/********************************************************************************
** Form generated from reading UI file 'back_version.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACK_VERSION_H
#define UI_BACK_VERSION_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_back_version
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QFormLayout *formLayout_2;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QFormLayout *formLayout_3;
    QLabel *versionLabel;
    QSpinBox *versionSpinBox;
    QLabel *background;

    void setupUi(QDialog *back_version)
    {
        if (back_version->objectName().isEmpty())
            back_version->setObjectName(QStringLiteral("back_version"));
        back_version->resize(341, 198);
        pushButton = new QPushButton(back_version);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 140, 97, 27));
        QFont font;
        font.setPointSize(10);
        pushButton->setFont(font);
        frame = new QFrame(back_version);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(19, 10, 301, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(back_version);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 30, 255, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));
        bookNameLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        seasonNameLabel = new QLabel(layoutWidget);
        seasonNameLabel->setObjectName(QStringLiteral("seasonNameLabel"));
        seasonNameLabel->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, seasonNameLabel);

        seasonNameLineEdit = new QLineEdit(layoutWidget);
        seasonNameLineEdit->setObjectName(QStringLiteral("seasonNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, seasonNameLineEdit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        versionLabel = new QLabel(layoutWidget);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, versionLabel);

        versionSpinBox = new QSpinBox(layoutWidget);
        versionSpinBox->setObjectName(QStringLiteral("versionSpinBox"));
        versionSpinBox->setFont(font);
        versionSpinBox->setMinimum(0);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, versionSpinBox);


        verticalLayout->addLayout(formLayout_3);

        background = new QLabel(back_version);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 361, 211));
        frame->raise();
        background->raise();
        layoutWidget->raise();
        pushButton->raise();

        retranslateUi(back_version);

        QMetaObject::connectSlotsByName(back_version);
    } // setupUi

    void retranslateUi(QDialog *back_version)
    {
        back_version->setWindowTitle(QApplication::translate("back_version", "Back to version", 0));
        pushButton->setText(QApplication::translate("back_version", "Apply", 0));
        bookNameLabel->setText(QApplication::translate("back_version", "Book Name:", 0));
        seasonNameLabel->setText(QApplication::translate("back_version", "Season Name: ", 0));
        versionLabel->setText(QApplication::translate("back_version", "Version:", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class back_version: public Ui_back_version {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACK_VERSION_H
