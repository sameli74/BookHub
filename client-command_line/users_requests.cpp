#include <vector>
#include <string>
#include <QString>

#include "users_requests.h"
#include "ui_users_requests.h"

using namespace std;

users_requests::users_requests(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users_requests)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();
}

void users_requests::set_client(Client* _c1){
    c1=_c1;
}

users_requests::~users_requests()
{
    delete ui;
}

void users_requests::on_pushButton_show_clicked()
{
        vector<string> v;
        v=c1->show_requests();
        ui->textBrowser->setText("Users requests are listed below: \n");
        ui->textBrowser->moveCursor (QTextCursor::End);
        if(v.size()==0)
            return;
        for(int i=0; i<v.size(); i++){
            ui->textBrowser->insertPlainText(QString::fromStdString(itos(i+1)));
            ui->textBrowser->moveCursor (QTextCursor::End);
            ui->textBrowser->insertPlainText(". ");
            ui->textBrowser->moveCursor (QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(v[i]));
            ui->textBrowser->moveCursor (QTextCursor::End);
            ui->textBrowser->insertPlainText("\n");
        }
}
