#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QDialog>
#include "Client.h"
#include "Machine.h"
#include "UI.h"
#include "new_book.h";
#include "new_season.h"
#include "edit_book.h"
#include "edit_ui.h"
#include "export_edits.h"

namespace Ui {
class client_ui;
}

class client_ui : public QDialog
{
    Q_OBJECT

public:
    explicit client_ui(QWidget *parent = 0);
    ~client_ui();
    void set_parameters (Client* _c1, Machine* _m1, UI* _u1);
    void admin_features(bool select);
    void set_tree();
    void set_browser();

private slots:
    void on_pushButton_create_book_clicked();

    void on_pushButton_new_season_clicked();

    void on_pushButton_Export_changes_clicked();

    void on_pushButton_users_requests_clicked();

    void on_pushButton_grant_clicked();

    void on_pushButton_book_name_clicked();

    void on_pushButton_edit_writers_clicked();

    void on_pushButton_publish_clicked();

    void on_pushButton_back_version_clicked();

    void on_pushButton_show_edits_clicked();

    void on_pushButton_clicked();

    void on_pushButton_version_content_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_latest_version_clicked();

private:
    Ui::client_ui *ui;
    Client* c1;
    Machine* m1;
    UI* u1;

};

#endif // CLIENT_UI_H
