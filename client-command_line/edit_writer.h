#ifndef EDIT_WRITER_H
#define EDIT_WRITER_H

#include <QDialog>

#include "Client.h"

namespace Ui {
class edit_writer;
}

class edit_writer : public QDialog
{
    Q_OBJECT

public:
    explicit edit_writer(QWidget *parent = 0);
    ~edit_writer();
    void set_client(Client* _c1);

private slots:
    void on_changeToWriterComboBox_activated(int index);

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::edit_writer *ui;
    Client* c1;
};

#endif // EDIT_WRITER_H
