/********************************************************************************
** Form generated from reading UI file 'version_content_change.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSION_CONTENT_CHANGE_H
#define UI_VERSION_CONTENT_CHANGE_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_version_content_change
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *bookNameLineEdit;
    QLabel *bookNameLabel;
    QFormLayout *formLayout_2;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QFormLayout *formLayout_3;
    QLabel *versionNumberLabel;
    QSpinBox *versionNumberSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *version_content_change)
    {
        if (version_content_change->objectName().isEmpty())
            version_content_change->setObjectName(QStringLiteral("version_content_change"));
        version_content_change->resize(299, 180);
        frame = new QFrame(version_content_change);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 10, 281, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(version_content_change);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 257, 136));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, bookNameLineEdit);

        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, bookNameLabel);


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

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        versionNumberLabel = new QLabel(layoutWidget);
        versionNumberLabel->setObjectName(QStringLiteral("versionNumberLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, versionNumberLabel);

        versionNumberSpinBox = new QSpinBox(layoutWidget);
        versionNumberSpinBox->setObjectName(QStringLiteral("versionNumberSpinBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, versionNumberSpinBox);


        verticalLayout->addLayout(formLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(version_content_change);

        QMetaObject::connectSlotsByName(version_content_change);
    } // setupUi

    void retranslateUi(QDialog *version_content_change)
    {
        version_content_change->setWindowTitle(QApplication::translate("version_content_change", "Changes to Version", 0));
#ifndef QT_NO_TOOLTIP
        version_content_change->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        bookNameLabel->setText(QApplication::translate("version_content_change", "Book Name: ", 0));
        seasonNameLabel->setText(QApplication::translate("version_content_change", "Season Name: ", 0));
        versionNumberLabel->setText(QApplication::translate("version_content_change", "Version Number", 0));
    } // retranslateUi

};

namespace Ui {
    class version_content_change: public Ui_version_content_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSION_CONTENT_CHANGE_H
