#ifndef PUBLISH_H
#define PUBLISH_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class publish;
}

class publish : public QDialog
{
    Q_OBJECT

public:
    explicit publish(QWidget *parent = 0);
    ~publish();
    void set_client(Client* _c1);

private slots:
    void on_pushButton_clicked();

private:
    Ui::publish *ui;
    Client* c1;
};

#endif // PUBLISH_H
