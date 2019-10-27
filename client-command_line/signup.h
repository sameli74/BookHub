#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "Client.h"

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();
    void set_client(Client* _c1);

private slots:
    void on_pushButton_signup_clicked();

private:
    Ui::signup *ui;
    Client* c1;
};

#endif // SIGNUP_H
