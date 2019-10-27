#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client_ui.h"
#include <QString>
#include <string>
#include <QtGui>
#include <vector>
#include <QMessageBox>
#include <QDialog>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::set_parameters(Client* _c1, Machine* _m1, UI* _u1){
    c1=_c1;
    m1=_m1;
    u1=_u1;
}

void MainWindow::on_pushButton_clicked()
{
    vector<string>tokens;
    string _user;
    string _pass;
    string answer;
    _user=ui->usernameLineEdit_login->text().toStdString();
    _pass=ui->passwordLineEdit_login->text().toStdString();
    tokens.push_back(_user);
    tokens.push_back((_pass));
    try{
        answer=c1->process_login(tokens);
        if(answer=="successful"){

        this->close();

        cu1= new client_ui();
        cu1->set_parameters(c1, m1, u1);
        cu1->show();
        }
        else if(answer=="unsuccessful")
                QMessageBox::information(
                    this,
                    tr("Unsuccessful login"),
                    tr("Login was not successful.") );
    }catch(...){
        QMessageBox::information(
            this,
            tr("Unsuccessful login"),
            tr("Login was not successful.") );
    }
}


void MainWindow::on_commandLinkButton_signup_clicked()
{

    si=new signup();
    si->set_client(c1);
    si->show();

}
