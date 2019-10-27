#include "edit_book.h"
#include "ui_edit_book.h"
#include <string>
#include <QMessageBox>

#include "methods.h"

using namespace std;
edit_book::edit_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_book)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
    on_whatDoYouWantToDoComboBox_activated(0);
}

edit_book::~edit_book()
{
    delete ui;
}
void edit_book::set_client(Client* _c1){
    c1=_c1;
}

void edit_book::on_buttonBox_rejected()
{
    this->close();
}


void edit_book::on_buttonBox_accepted()
{
    int index;
    string title;
    string book= ui->bookNameLineEdit->text().toStdString();
    string season= ui->seasonNameLineEdit->text().toStdString();
    string message;
    vector<string> tokens;
    index=ui->whatDoYouWantToDoComboBox->currentIndex();
    if(index==0){
        title= "add";
        tokens.push_back(title);
        tokens.push_back(ui->lineEdit_line_number->text().toStdString());
        tokens.push_back(ui->lineEdit_new_text->text().toStdString());
    }
    else if(index==1){
        title= "remove";
        tokens.push_back(title);
        tokens.push_back(ui->lineEdit_line_number->text().toStdString());

    }
    else{
        title= "change";
        tokens.push_back(title);
        tokens.push_back(ui->lineEdit_line_number->text().toStdString());
        tokens.push_back(ui->lineEdit_current_text->text().toStdString());
        tokens.push_back(ui->lineEdit_new_text->text().toStdString());
    }
    try{
        message=c1->start_editing(tokens, book, season);
        if(message=="successful"){
            QMessageBox::information(
                this,
                tr("Edit Season"),
                tr("Editing was successful.") );
            this->close();
        }
        else if(message=="unsuccessful")
            QMessageBox::information(
                this,
                tr("Edit season"),
                tr("Editing was not successful.") );
    }catch(...){
        QMessageBox::information(
            this,
            tr("Edit season"),
            tr("Something went wrong.\nTry again.") );
    }

}

void edit_book::on_whatDoYouWantToDoComboBox_activated(int index)
{
    ui->lineEdit_current_text->setEnabled(true);;
    ui->lineEdit_new_text->setEnabled(true);
    if(index==0)
        ui->lineEdit_current_text->setEnabled(false);
    else if(index == 2){
        ui->lineEdit_current_text->setEnabled(false);
        ui->lineEdit_new_text->setEnabled(false);
    }
}
