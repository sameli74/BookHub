#include <string>
#include <QMessageBox>

#include "back_version.h"
#include "ui_back_version.h"

using namespace std;

back_version::back_version(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::back_version)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();

}

back_version::~back_version()
{
    delete ui;
}
void back_version::set_client(Client *_c1)
{
    c1=_c1;
}
void back_version::set_spin(){
    ui->versionSpinBox->setRange(1, c1->get_version_number(ui->bookNameLineEdit->text().toStdString(),ui->seasonNameLineEdit->text().toStdString()));
}

void back_version::on_pushButton_clicked()
{
    string book=ui->bookNameLineEdit->text().toStdString();
    string season=ui->seasonNameLineEdit->text().toStdString();
    int num=ui->versionSpinBox->value();
    string message=c1->back_to_version(book, season, num);
    if(message=="successful"){
        QMessageBox::information(
            this,
            tr("Back to version"),
            tr("done.") );
        this->close();
    }
    else if(message=="access_denied"){
        QMessageBox::information(
            this,
            tr("Back to version"),
            tr("Administrative permision is required.") );
    }
    else
        QMessageBox::information(
            this,
            tr("Back to version"),
            tr("Unsuccessful operation.") );
}
