#ifndef CHANGE_NAME_H
#define CHANGE_NAME_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class change_name;
}

class change_name : public QDialog
{
    Q_OBJECT

public:
    explicit change_name(QWidget *parent = 0);
    ~change_name();
    void set_client(Client* _c1);
private slots:
    void on_pushButton_clicked();

private:
    Ui::change_name *ui;
    Client* c1;

};

#endif // CHANGE_NAME_H
