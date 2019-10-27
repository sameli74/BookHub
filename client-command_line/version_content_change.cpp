#include <string>
#include <vector>

#include "version_content_change.h"
#include "ui_version_content_change.h"

using namespace std;

version_content_change::version_content_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::version_content_change)
{
    ui->setupUi(this);
}

version_content_change::~version_content_change()
{
    delete ui;
}
void version_content_change::set_client(Client* _c1, QTextBrowser* qb){
    c1=_c1;
    _qb=qb;
}
void version_content_change::set_browser(string book, string season, int num){


}

void version_content_change::on_buttonBox_rejected()
{
    close();
}

void version_content_change::on_buttonBox_accepted()
{
    string html;
    string book= ui->bookNameLineEdit->text().toStdString();
    string season=ui->seasonNameLineEdit->text().toStdString();
    int num=ui->versionNumberSpinBox->value();
    vector<string> v;
    vector<string>u;
    //v=c1->changes_to_version(book, season, num);
    u=c1->get_text(book, season, num);
    v=c1->get_text(book, season, num-1);
    for(int i=0; i<u.size(); i++)
        for(int j=0; j<v.size(); j++)
            if(u[i]==v[j]){
                html=html+"<p> "+u[i]+" </p>\n";
                break;
            }
            else if(j==v.size()-1)
                html=html+"<p style=\"color:red\"> "+u[i]+" </p>\n";
    _qb->setText("<p>Version Changes: </p>\n");
    _qb->moveCursor (QTextCursor::End);
    _qb->setHtml(QString::fromStdString(html));
//    if(u.size()==0)
//        return;
//    for(int i=0; i<u.size(); i++){
//        _qb->insertPlainText(QString::fromStdString(u[i]));
//        _qb->moveCursor (QTextCursor::End);
//        _qb->insertPlainText("\n");
//    }

}
