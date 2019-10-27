#ifndef LATEST_VERSION_H
#define LATEST_VERSION_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class latest_version;
}

class latest_version : public QDialog
{
    Q_OBJECT

public:
    explicit latest_version(QWidget *parent = 0);
    ~latest_version();
    void set_client(Client *_c1);

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::latest_version *ui;
    Client *c1;
};

#endif // LATEST_VERSION_H
