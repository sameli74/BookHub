#include "publish.h"
#include "ui_publish.h"

#include <string>
#include <QMessageBox>

using namespace std;

publish::publish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::publish)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
}

publish::~publish()
{
    delete ui;
}

void publish::set_client(Client* _c1){
    c1=_c1;
}

void publish::on_pushButton_clicked()
{
    string s1;
    bool answer;
    s1 = ui->bookNameLineEdit->text().toStdString();    
    answer = c1->publish_book(s1);
    if(answer){
        QMessageBox::information(
            this,
            tr("Publish Book"),
            tr("Book has been successfully Published.") );
        this->close();
    }
    else {
        QMessageBox::information(
            this,
            tr("Publish Book"),
            tr("Could'nt publish the book.") );
    }



}
