#ifndef BOOK_CONTENT_H
#define BOOK_CONTENT_H

#include <QDialog>
#include <QTextBrowser>

#include "Client.h"
#include "methods.h"

class client_ui;

namespace Ui {
class book_content;
}

class book_content : public QDialog
{
    Q_OBJECT

public:
    explicit book_content(QWidget *parent = 0);
    ~book_content();
    void set_client(Client* _c1, QTextBrowser *qb);
    void set_spin();
    void set_browser(std::string book, std::string season, int num);

private slots:
    void on_checkBox_clicked(bool checked);

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::book_content *ui;
    Client* c1;
    QTextBrowser *_qb;
};

#endif // BOOK_CONTENT_H
