#include <vector>
#include <string>

#include "book_content.h"
#include "ui_book_content.h"

#define EMPTY -1

using namespace std;

book_content::book_content(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_content)

{
    ui->setupUi(this);
}

book_content::~book_content()
{
    delete ui;
}
void book_content::set_client(Client *_c1, QTextBrowser *qb){
    c1=_c1;
    _qb=qb;
}

void book_content::set_spin(){
    int number;
    number=c1->version_number(ui->bookNameLineEdit->text().toStdString(), ui->seasonNameLineEdit->text().toStdString());
    ui->numberOfVersionsSpinBox->setRange(1, number);
}

void book_content::on_checkBox_clicked(bool checked)
{
    if(checked)
        ui->numberOfVersionsSpinBox->setEnabled(false);
    else
        ui->numberOfVersionsSpinBox->setEnabled(true);

}

void book_content::on_buttonBox_rejected()
{
    close();
}

void book_content::on_buttonBox_accepted()
{
    int num;
    string book=ui->bookNameLineEdit->text().toStdString();
    string season=ui->seasonNameLineEdit->text().toStdString();
    if(ui->checkBox->checkState()==false)
        num=s_to_i(ui->numberOfVersionsSpinBox->text().toStdString());
    else
        num=0;
    set_browser(book, season, num);
    close();

}
void book_content::set_browser(string book, string season, int num){
    vector<string> v;
    v=c1->get_text(book, season, num);
    _qb->setText("Season Content: \n");
    _qb->moveCursor (QTextCursor::End);
    if(v.size()==0)
        return;
    for(int i=0; i<v.size(); i++){
        _qb->insertPlainText(QString::fromStdString(v[i]));
        _qb->moveCursor (QTextCursor::End);
        _qb->insertPlainText("\n");
    }
}
