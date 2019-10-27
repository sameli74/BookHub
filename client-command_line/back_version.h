#ifndef BACK_VERSION_H
#define BACK_VERSION_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class back_version;
}

class back_version : public QDialog
{
    Q_OBJECT

public:
    explicit back_version(QWidget *parent = 0);
    ~back_version();
    void set_client(Client* _c1);
    void set_spin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::back_version *ui;
    Client* c1;
};

#endif // BACK_VERSION_H
