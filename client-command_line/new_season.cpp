#include <string>
#include <vector>
#include <QMessageBox>

#include "new_season.h"
#include "ui_new_season.h"


#define END_OF_BOOK -1

using namespace std;

new_season::new_season(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_season)
{
    ui->setupUi(this);
}

new_season::~new_season()
{
    delete ui;
}
void new_season::set_client(Client* _c1, QTreeView *qb){
    c1=_c1;
    _qb=qb;
}

void new_season::set_tree(){
    QStandardItemModel* mode1= new QStandardItemModel();
    vector<string> books;
    books=c1->get_books_writting();
    for(int i=0; i<books.size(); i++){
        vector<string> seasons;
        seasons=c1->seasons_list(books[i]);
        QStandardItem* item0= new QStandardItem(books[i].c_str());
        for(int j=0; j<seasons.size(); j++){
            QStandardItem* item1= new QStandardItem(seasons[j].c_str());
            item0->appendRow(item1);
        }
        mode1->appendRow(item0);
    }
    _qb->setModel(mode1);
}

void new_season::set_spin(){
   // ui->seasonPlaceSpinBox->setRange(1, );
}

void new_season::on_buttonBox_accepted()
{
    string book, season;
    int place;
    //int p;
    bool answer;
    book = ui->bookNameLineEdit->text().toStdString();
    season = ui->seasonNameLineEdit->text().toStdString();
    place =  ui->seasonPlaceSpinBox->value();
    cerr << endl<< place <<endl;
    try{
        if(ui->checkBox->checkState())
            answer = c1->create_new_season(book, season, END_OF_BOOK);
        else
            answer = c1->create_new_season(book, season, place);
        if(answer){
            QMessageBox::information(
                this,
                tr("Add new season"),
                tr("New season has been added successfully.") );
            set_tree();
            this->close();
        }
        else
            QMessageBox::information(
                this,
                tr("Add new season"),
                tr("Adding new season was not successful.\nTry again") );
    }catch(...){
        QMessageBox::information(
            this,
            tr("Problem"),
            tr("Something went wrong. Try again please") );
    }

}

void new_season::on_buttonBox_rejected()
{
    this->close();
}

void new_season::on_checkBox_clicked(bool checked)
{
    if(checked)
        ui->seasonPlaceSpinBox->setEnabled(false);
    else
        ui->seasonPlaceSpinBox->setEnabled(true);
}
