#include <QMessageBox>

#include "edit_writer.h"
#include "ui_edit_writer.h"

using namespace std;

edit_writer::edit_writer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_writer)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
    ui->removingingWriterLineEdit->setEnabled(false);
}

edit_writer::~edit_writer()
{
    delete ui;
}

void edit_writer::set_client(Client* _c1){
    c1=_c1;
}

void edit_writer::on_changeToWriterComboBox_activated(int index)
{
    ui->NewWriterLineEdit->setEnabled(true);
    ui->removingingWriterLineEdit->setEnabled(true);
    if(index==0){
        ui->removingingWriterLineEdit->setEnabled(false);
    }
    else
        ui->NewWriterLineEdit->setEnabled(false);
}

void edit_writer::on_buttonBox_rejected()
{
    close();
}

void edit_writer::on_buttonBox_accepted()
{
    int index=ui->changeToWriterComboBox->currentIndex();
    string data, book;
    if(index==0){
        data = ui->NewWriterLineEdit->text().toStdString();
        book=ui->bookNameLineEdit->text().toStdString();
        string answer=c1->change_to_writers("add", book , data);
        if(answer=="successful")
            QMessageBox::information(
                this,
                tr("Successful"),
                tr("Writer has been added.") );
        else if(answer=="unsuccessful")
            QMessageBox::information(
                this,
                tr("Problem"),
                tr("Could'nt add the writer.") );

    }
    else if(index==1){
        data = ui->removingingWriterLineEdit->text().toStdString();
        book=ui->bookNameLineEdit->text().toStdString();
        string answer=c1->change_to_writers("remove", book , data);
        if(answer=="successful")
            QMessageBox::information(
                this,
                tr("Successful"),
                tr("Writer has been removed.") );
        else if(answer=="unsuccessful")
            QMessageBox::information(
                this,
                tr("Problem"),
                tr("Could'nt remove the writer.") );
    }
}
