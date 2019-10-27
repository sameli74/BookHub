#ifndef VERSION_CONTENT_CHANGE_H
#define VERSION_CONTENT_CHANGE_H

#include <QDialog>
#include <QTextBrowser>

#include "Client.h"
#include "methods.h"



namespace Ui {
class version_content_change;
}

class version_content_change : public QDialog
{
    Q_OBJECT

public:
    explicit version_content_change(QWidget *parent = 0);
    ~version_content_change();
    void set_client(Client* _c1, QTextBrowser* qb);
    void set_browser(std::string book, std::string season, int num);

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::version_content_change *ui;
    Client* c1;
    QTextBrowser* _qb;
};

#endif // VERSION_CONTENT_CHANGE_H
