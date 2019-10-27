#ifndef NEW_SEASON_H
#define NEW_SEASON_H

#include <QDialog>
#include <QtGui>
#include <QTreeView>

#include "Client.h"
#include "methods.h"

namespace Ui {
class new_season;
}

class new_season : public QDialog
{
    Q_OBJECT

public:
    explicit new_season(QWidget *parent = 0);
    ~new_season();
    void set_client(Client* _c1, QTreeView* qb);
    void set_spin();
    void set_tree();

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_checkBox_clicked(bool checked);

private:
    Ui::new_season *ui;
    Client* c1;
    QTreeView *_qb;
};

#endif // NEW_SEASON_H
