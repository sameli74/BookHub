#ifndef EDIT_UI_H
#define EDIT_UI_H

#include <QDialog>

#include "edit_book.h"
#include "Client.h"

namespace Ui {
class edit_ui;
}

class edit_ui : public QDialog
{
    Q_OBJECT

public:
    explicit edit_ui(QWidget *parent = 0);
    ~edit_ui();
    void set_client(Client* _c1);
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::edit_ui *ui;
    Client* c1;
};

#endif // EDIT_UI_H
