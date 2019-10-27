/********************************************************************************
** Form generated from reading UI file 'new_season.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_SEASON_H
#define UI_NEW_SEASON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_season
{
public:
    QFrame *frame;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *bookNameLabel;
    QLineEdit *bookNameLineEdit;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *seasonNameLabel;
    QLineEdit *seasonNameLineEdit;
    QSpacerItem *verticalSpacer_6;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QLabel *seasonPlaceLabel;
    QSpinBox *seasonPlaceSpinBox;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *new_season)
    {
        if (new_season->objectName().isEmpty())
            new_season->setObjectName(QStringLiteral("new_season"));
        new_season->resize(575, 333);
        frame = new QFrame(new_season);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 20, 521, 281));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 111, 17));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(340, 240, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(new_season);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 70, 473, 192));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(0, QFormLayout::FieldRole, verticalSpacer_3);

        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName(QStringLiteral("bookNameLabel"));
        bookNameLabel->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, bookNameLabel);

        bookNameLineEdit = new QLineEdit(layoutWidget);
        bookNameLineEdit->setObjectName(QStringLiteral("bookNameLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, bookNameLineEdit);

        verticalSpacer_2 = new QSpacerItem(366, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        verticalSpacer_5 = new QSpacerItem(350, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(0, QFormLayout::FieldRole, verticalSpacer_5);

        seasonNameLabel = new QLabel(layoutWidget);
        seasonNameLabel->setObjectName(QStringLiteral("seasonNameLabel"));
        seasonNameLabel->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, seasonNameLabel);

        seasonNameLineEdit = new QLineEdit(layoutWidget);
        seasonNameLineEdit->setObjectName(QStringLiteral("seasonNameLineEdit"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, seasonNameLineEdit);

        verticalSpacer_6 = new QSpacerItem(350, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(2, QFormLayout::FieldRole, verticalSpacer_6);


        verticalLayout->addLayout(formLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

        seasonPlaceLabel = new QLabel(layoutWidget);
        seasonPlaceLabel->setObjectName(QStringLiteral("seasonPlaceLabel"));
        seasonPlaceLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, seasonPlaceLabel);

        seasonPlaceSpinBox = new QSpinBox(layoutWidget);
        seasonPlaceSpinBox->setObjectName(QStringLiteral("seasonPlaceSpinBox"));
        seasonPlaceSpinBox->setMinimum(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, seasonPlaceSpinBox);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox);

        verticalSpacer_4 = new QSpacerItem(350, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_4);


        verticalLayout->addLayout(formLayout);


        retranslateUi(new_season);

        QMetaObject::connectSlotsByName(new_season);
    } // setupUi

    void retranslateUi(QDialog *new_season)
    {
        new_season->setWindowTitle(QApplication::translate("new_season", "Create new season", 0));
        label->setText(QApplication::translate("new_season", "New season", 0));
        bookNameLabel->setText(QApplication::translate("new_season", "Book Name:", 0));
        seasonNameLabel->setText(QApplication::translate("new_season", "Season Name:", 0));
        seasonPlaceLabel->setText(QApplication::translate("new_season", "Season Place: ", 0));
        checkBox->setText(QApplication::translate("new_season", "Put season at the end of book", 0));
    } // retranslateUi

};

namespace Ui {
    class new_season: public Ui_new_season {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_SEASON_H
