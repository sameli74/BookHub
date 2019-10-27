#ifndef EDIT_BOOK_H
#define EDIT_BOOK_H

#include <QDialog>
#include "Client.h"

namespace Ui {
class edit_book;
}

class edit_book : public QDialog
{
    Q_OBJECT

public:
    explicit edit_book(QWidget *parent = 0);
    ~edit_book();
    void set_client(Client* _c1);

private slots:
    void on_buttonBox_rejected();


    void on_buttonBox_accepted();

    void on_whatDoYouWantToDoComboBox_activated(int index);

private:
    Ui::edit_book *ui;
    Client* c1;

};

#endif // EDIT_BOOK_H
