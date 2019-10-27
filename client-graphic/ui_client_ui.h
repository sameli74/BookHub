/********************************************************************************
** Form generated from reading UI file 'client_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_UI_H
#define UI_CLIENT_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client_ui
{
public:
    QTreeView *book_list;
    QFrame *frame;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QFrame *frame_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_create_book;
    QPushButton *pushButton_new_season;
    QPushButton *pushButton_book_name;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_edit_writers;
    QPushButton *pushButton_Export_changes;
    QPushButton *pushButton_latest_version;
    QPushButton *pushButton_show_edits;
    QPushButton *pushButton_version_content;
    QPushButton *pushButton_back_version;
    QPushButton *pushButton_publish;
    QPushButton *pushButton_published;
    QPushButton *pushButton_users_requests;
    QPushButton *pushButton_grant;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *background;

    void setupUi(QDialog *client_ui)
    {
        if (client_ui->objectName().isEmpty())
            client_ui->setObjectName(QStringLiteral("client_ui"));
        client_ui->resize(931, 559);
        QFont font;
        font.setPointSize(10);
        client_ui->setFont(font);
        book_list = new QTreeView(client_ui);
        book_list->setObjectName(QStringLiteral("book_list"));
        book_list->setGeometry(QRect(10, 20, 141, 521));
        book_list->setFrameShape(QFrame::StyledPanel);
        book_list->setFrameShadow(QFrame::Sunken);
        book_list->setLineWidth(3);
        book_list->header()->setVisible(false);
        frame = new QFrame(client_ui);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(160, 20, 561, 521));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 10, 521, 501));
        textBrowser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textBrowser->setMouseTracking(false);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        verticalScrollBar = new QScrollBar(frame);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(10, 10, 20, 501));
        verticalScrollBar->setOrientation(Qt::Vertical);
        verticalScrollBar->raise();
        textBrowser->raise();
        frame_2 = new QFrame(client_ui);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(729, 19, 191, 521));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 174, 515));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        pushButton_create_book = new QPushButton(layoutWidget);
        pushButton_create_book->setObjectName(QStringLiteral("pushButton_create_book"));

        verticalLayout->addWidget(pushButton_create_book);

        pushButton_new_season = new QPushButton(layoutWidget);
        pushButton_new_season->setObjectName(QStringLiteral("pushButton_new_season"));

        verticalLayout->addWidget(pushButton_new_season);

        pushButton_book_name = new QPushButton(layoutWidget);
        pushButton_book_name->setObjectName(QStringLiteral("pushButton_book_name"));

        verticalLayout->addWidget(pushButton_book_name);

        pushButton_edit = new QPushButton(layoutWidget);
        pushButton_edit->setObjectName(QStringLiteral("pushButton_edit"));

        verticalLayout->addWidget(pushButton_edit);

        pushButton_edit_writers = new QPushButton(layoutWidget);
        pushButton_edit_writers->setObjectName(QStringLiteral("pushButton_edit_writers"));

        verticalLayout->addWidget(pushButton_edit_writers);

        pushButton_Export_changes = new QPushButton(layoutWidget);
        pushButton_Export_changes->setObjectName(QStringLiteral("pushButton_Export_changes"));

        verticalLayout->addWidget(pushButton_Export_changes);

        pushButton_latest_version = new QPushButton(layoutWidget);
        pushButton_latest_version->setObjectName(QStringLiteral("pushButton_latest_version"));

        verticalLayout->addWidget(pushButton_latest_version);

        pushButton_show_edits = new QPushButton(layoutWidget);
        pushButton_show_edits->setObjectName(QStringLiteral("pushButton_show_edits"));

        verticalLayout->addWidget(pushButton_show_edits);

        pushButton_version_content = new QPushButton(layoutWidget);
        pushButton_version_content->setObjectName(QStringLiteral("pushButton_version_content"));

        verticalLayout->addWidget(pushButton_version_content);

        pushButton_back_version = new QPushButton(layoutWidget);
        pushButton_back_version->setObjectName(QStringLiteral("pushButton_back_version"));

        verticalLayout->addWidget(pushButton_back_version);

        pushButton_publish = new QPushButton(layoutWidget);
        pushButton_publish->setObjectName(QStringLiteral("pushButton_publish"));

        verticalLayout->addWidget(pushButton_publish);

        pushButton_published = new QPushButton(layoutWidget);
        pushButton_published->setObjectName(QStringLiteral("pushButton_published"));

        verticalLayout->addWidget(pushButton_published);

        pushButton_users_requests = new QPushButton(layoutWidget);
        pushButton_users_requests->setObjectName(QStringLiteral("pushButton_users_requests"));

        verticalLayout->addWidget(pushButton_users_requests);

        pushButton_grant = new QPushButton(layoutWidget);
        pushButton_grant->setObjectName(QStringLiteral("pushButton_grant"));

        verticalLayout->addWidget(pushButton_grant);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        layoutWidget1 = new QWidget(client_ui);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        background = new QLabel(client_ui);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-10, -10, 941, 591));
        background->raise();
        layoutWidget->raise();
        book_list->raise();
        frame_2->raise();
        frame->raise();

        retranslateUi(client_ui);

        QMetaObject::connectSlotsByName(client_ui);
    } // setupUi

    void retranslateUi(QDialog *client_ui)
    {
        client_ui->setWindowTitle(QApplication::translate("client_ui", "Book Storage", 0));
        label->setText(QApplication::translate("client_ui", "Options panel: ", 0));
        pushButton_create_book->setText(QApplication::translate("client_ui", "New Book", 0));
        pushButton_new_season->setText(QApplication::translate("client_ui", "New Season", 0));
        pushButton_book_name->setText(QApplication::translate("client_ui", "Change Book Name", 0));
        pushButton_edit->setText(QApplication::translate("client_ui", "Edit line", 0));
        pushButton_edit_writers->setText(QApplication::translate("client_ui", "Edit Writers", 0));
        pushButton_Export_changes->setText(QApplication::translate("client_ui", "Export changes", 0));
        pushButton_latest_version->setText(QApplication::translate("client_ui", "Get Latest Version", 0));
        pushButton_show_edits->setText(QApplication::translate("client_ui", "Show Season content", 0));
        pushButton_version_content->setText(QApplication::translate("client_ui", "Version content", 0));
        pushButton_back_version->setText(QApplication::translate("client_ui", "Back to version", 0));
        pushButton_publish->setText(QApplication::translate("client_ui", "Publicate Book", 0));
        pushButton_published->setText(QApplication::translate("client_ui", "Published books", 0));
        pushButton_users_requests->setText(QApplication::translate("client_ui", "Show users requests", 0));
        pushButton_grant->setText(QApplication::translate("client_ui", "Grant a request", 0));
        pushButton->setText(QApplication::translate("client_ui", "Sync", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class client_ui: public Ui_client_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_UI_H
