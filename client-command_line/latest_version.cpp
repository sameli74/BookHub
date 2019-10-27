#include <string>
#include <QMessageBox>

#include "latest_version.h"
#include "ui_latest_version.h"

using namespace std;

latest_version::latest_version(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::latest_version)
{
    ui->setupUi(this);
}

latest_version::~latest_version()
{
    delete ui;
}

void latest_version::set_client(Client *_c1){
    c1=_c1;
}

void latest_version::on_buttonBox_rejected()
{
    close();
}

void latest_version::on_buttonBox_accepted()
{
    string book= ui->bookNameLineEdit->text().toStdString();
    string season= ui->seasonNameLineEdit->text().toStdString();
    bool answer=c1->receive_latest_version(book, season);
    if(answer){
        QMessageBox::information(
            this,
            tr("Get latest version"),
            tr("Updated successfully.") );
        close();
    }
    else
        QMessageBox::information(
            this,
            tr("Back to version"),
            tr("could'nt update successfully.") );
}
