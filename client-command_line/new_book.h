#ifndef NEW_BOOK_H
#define NEW_BOOK_H

#include <QDialog>

#include "Client.h"
#include <QTreeView>
#include <QtGui>

namespace Ui {
class new_book;
}

class new_book : public QDialog
{
    Q_OBJECT

public:
    explicit new_book(QWidget *parent = 0);
    ~new_book();
    void set_client(Client* _c1, QTreeView *qb);
    void set_tree();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::new_book *ui;
    Client* c1;
    QTreeView *_qb;
};

#endif // NEW_BOOK_H
