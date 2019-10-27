#ifndef EXPORT_EDITS_H
#define EXPORT_EDITS_H

#include <QDialog>
#include <Client.h>

namespace Ui {
class Export_edits;
}

class Export_edits : public QDialog
{
    Q_OBJECT

public:
    explicit Export_edits(QWidget *parent = 0);
    ~Export_edits();
    void set_client(Client* _c1, Machine* _m1);

private slots:
    void on_pushButton_final_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::Export_edits *ui;
    Client* c1;
    Machine* m1;
};

#endif // EXPORT_EDITS_H
