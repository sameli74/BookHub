#include <string>
#include <QMessageBox>

#include "change_name.h"
#include "ui_change_name.h"

using namespace std;

change_name::change_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_name)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
}

change_name::~change_name()
{
    delete ui;
}
void change_name::set_client(Client* _c1){
    c1=_c1;
}


void change_name::on_pushButton_clicked()
{
    string answer;
    string p=ui->previousNameLineEdit->text().toStdString();
    string n=ui->newNameLineEdit->text().toStdString();;
    answer=c1->change_book_title(p, n);
    if(answer=="successful"){
        QMessageBox::information(
            this,
            tr("Change Book title"),
            tr("Book Name has been changed successfully.") );
        close();
    }
    else if(answer=="unsuccessful")
        QMessageBox::information(
            this,
            tr("Change book title"),
            tr("Changing book name was not successful.") );
}
