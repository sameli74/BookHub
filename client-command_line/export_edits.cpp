#include <string>
#include <QMessageBox>


#include "export_edits.h"
#include "ui_export_edits.h"

using namespace std;

Export_edits::Export_edits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Export_edits)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();

}

Export_edits::~Export_edits()
{
    delete ui;
}
void Export_edits::set_client(Client* _c1, Machine* _m1){
    c1=_c1;
    m1=_m1;
}

void Export_edits::on_pushButton_final_clicked()
{
    string book, season;
    book=ui->bookNameLineEdit->text().toStdString();
    season= ui->seasonNameLineEdit->text().toStdString();
    try{
        m1->finalize(book, season);
        QMessageBox::information(
            this,
            tr("Make Edits as final"),
            tr("requested Edits has been finalized.") );
    }catch(...){
        QMessageBox::information(
            this,
            tr("Make Edits as final"),
            tr("Couldn't finalize requested Edits") );
    }

}

void Export_edits::on_pushButton_send_clicked()
{
    string book, season;
    book=ui->bookNameLineEdit->text().toStdString();
    season= ui->seasonNameLineEdit->text().toStdString();
    try{
       if( m1->send_book(book, season)){
           QMessageBox::information(
               this,
               tr("Sending versions"),
               tr("Selected version is sent.") );
            this->close();
       }
       else
           QMessageBox::information(
               this,
               tr("Make Edits as final"),
               tr("Couldn't send selected version") );


    }catch(...){
        QMessageBox::information(
            this,
            tr("Make Edits as final"),
            tr("Something went wrong. Try again.") );

    }



}
