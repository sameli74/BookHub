#include <string>
#include <QMessageBox>

#include "users_grant.h"
#include "ui_users_grant.h"

using namespace std;

users_grant::users_grant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users_grant)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
}

users_grant::~users_grant()
{
    delete ui;
}

void users_grant::set_client(Client* _c1){
    c1=_c1;
}

void users_grant::on_pushButton_clicked()
{
    bool answer;
    string req=ui->bookNameLineEdit->text().toStdString();
    answer=c1->approve_request(req);
    if(answer){
        QMessageBox::information(
            this,
            tr("Grant Book requests"),
            tr("Book request has been granted successfully.") );
        close();
    }
    else
        QMessageBox::information(
            this,
            tr("Grant Book requests"),
            tr("Could'nt grant the book successfully.") );


}
