#include "signup.h"
#include "ui_signup.h"
#include <string>
#include <vector>
#include<QString>
#include<QtGui>
#include<QMessageBox>
using namespace std;

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
}

signup::~signup()
{
    delete ui;
}

void signup::set_client(Client* _c1){
    c1=_c1;
}

void signup::on_pushButton_signup_clicked()
{

        vector <string> tokens;
        string user, pass, confirm, message;
        user=ui->usernameLineEdit_signup->text().toStdString();
        pass=ui->passwordLineEdit_signup->text().toStdString();
            try{
                tokens.push_back(user);
                tokens.push_back(pass);
                message=c1->register_client(tokens);
                if(message== "register_successful"){
                    QMessageBox::information(
                        this,
                        tr("Successful Signup!"),
                        tr("Signup was successful. Now you can login to the site") );
                    this->close();
                }
                else if(message=="register_failed"){
                    QMessageBox::information(
                        this,
                        tr("Unsuccessful Signup!"),
                        tr("You have already registered") );
                    this ->close();
                    delete this;
                }
            }catch(...){
                QMessageBox::information(
                    this,
                    tr("Unsuccessful Signup"),
                    tr("Signup was not successful. Try again") );
            }


}
