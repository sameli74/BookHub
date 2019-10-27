#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <QString>
#include <QMessageBox>
#include "new_book.h"
#include "ui_new_book.h"


using namespace std;

new_book::new_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_book)
{
    ui->setupUi(this);
}

new_book::~new_book()
{
    delete ui;
}

void new_book::set_client(Client* _c1, QTreeView *qb){
    c1=_c1;
    _qb=qb;
}
void new_book::set_tree(){
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


void new_book::on_buttonBox_accepted()
{
    string st;
    string book = ui->bookNameLineEdit->text().toStdString();
    vector<string> data ;
    st=ui->writers->toPlainText().toStdString();
    istringstream iss(st);
    while(iss){
        string text;
        iss >> text;
        if(text=="")
            break;
        data.push_back(text);
    }
    try{
        if(c1->create_book(book, data)){
            QMessageBox::information(
                this,
                tr("Create Book"),
                tr("Book has been successfully added.") );
            set_tree();
            this->close();
        }

        else{
            QMessageBox::information(
                this,
                tr("Create Book"),
                tr("Book was not added successfully. Try again.") );
        }
    }catch(...){
        QMessageBox::information(
            this,
            tr("Problem"),
            tr("Something went wrong. Try again please") );
    }

}

void new_book::on_buttonBox_rejected()
{
    this->close();
}
