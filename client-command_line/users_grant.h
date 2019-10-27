#ifndef USERS_GRANT_H
#define USERS_GRANT_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class users_grant;
}

class users_grant : public QDialog
{
    Q_OBJECT

public:
    explicit users_grant(QWidget *parent = 0);
    ~users_grant();
    void set_client(Client* _c1);

private slots:
    void on_pushButton_clicked();

private:
    Ui::users_grant *ui;
    Client* c1;
};

#endif // USERS_GRANT_H
