#ifndef USERS_REQUESTS_H
#define USERS_REQUESTS_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class users_requests;
}

class users_requests : public QDialog
{
    Q_OBJECT

public:
    explicit users_requests(QWidget *parent = 0);
    ~users_requests();
    void set_client(Client* _c1);

private slots:
    void on_pushButton_show_clicked();

private:
    Ui::users_requests *ui;
    Client* c1;
};

#endif // USERS_REQUESTS_H
