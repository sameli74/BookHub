#include "client_ui.h"
#include "ui_client_ui.h"
#include "users_requests.h"
#include "users_grant.h"
#include "change_name.h"
#include "edit_writer.h"
#include "publish.h"
#include "back_version.h"
#include "book_content.h"
#include "version_content_change.h"
#include "edit_book.h"
#include "latest_version.h"

#include <QtCore>
#include <QtGui>

#define ADMIN "Admin"

using namespace std;

client_ui::client_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_ui)
{
    ui->setupUi(this);
    QPixmap qpix("/home/soroush/aa/Background.jpg");
    ui->background->setPixmap(qpix);
    ui->background->show();

}

client_ui::~client_ui()
{
    delete ui;
}

void client_ui::set_parameters(Client* _c1, Machine* _m1, UI* _u1){
    c1=_c1;
    m1=_m1;
    u1=_u1;
}

void client_ui::admin_features(bool select){
    ui->pushButton_users_requests->setHidden(select);
    ui->pushButton_grant->setHidden(select);

}
void client_ui::set_tree(){
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
    ui->book_list->setModel(mode1);
}

void client_ui::set_browser(){
    QStringList text_list; // I use this to store lines of text
    text_list << "> Added this row";
    text_list << "> Added this row";
    text_list << "< Removed this row";
    text_list << "> Added this row";

    //the following string is what we will use to style our text
    QString html_style("<style>"
                             "p.add{color: green; margin: 0; padding: 0;}"
                             "p.remove{color: red; margin: 0; padding: 0;}"
                             "</style>");

    QString format_add = "<p class=\"add\">%1</p>"; // we use these to make formatting easier
    QString format_remove = "<p class=\"remove\">%1</p>"; // basically helps us add tags before and after our text

    QString text; // this is a variable we will use to append our text as HTML code

    for(int i = 0; i < text_list.length(); i++)
    {
        if(text_list[i].startsWith(">")) // detect if the line was added
            text.append(format_add.arg(text_list[i].replace(">", "&#62;"))); // add the line in our html code, but replace > character with a character entity

        else if(text_list[i].startsWith("<")) // detect if the line was removed
            text.append(format_remove.arg(text_list[i].replace("<", "&#60;"))); // add the line in our html code, but replace < character with a character entity
    }

    ui->textBrowser->setHtml(html_style + text);
}

void client_ui::on_pushButton_create_book_clicked()
{
    c1->sync();
    set_tree();
    new_book* b1;
    b1=new new_book();
    b1->set_client(c1, ui->book_list);
    b1-> show();
}

void client_ui::on_pushButton_new_season_clicked()
{
    c1->sync();
    set_tree();
    new_season* s1;
    s1=new new_season();
    s1->set_client(c1, ui->book_list);
    s1-> show();
}

void client_ui::on_pushButton_Export_changes_clicked()
{
    c1->sync();
    set_tree();
    Export_edits* ee1;
    ee1=new Export_edits();
    ee1->set_client(c1, m1);
    ee1-> show();
}

void client_ui::on_pushButton_users_requests_clicked()
{
    c1->sync();
    set_tree();
    if(c1->name()==ADMIN){
        users_requests* ur1;
        ur1=new users_requests();
        ur1->set_client(c1);
        ur1-> show();
    }
}

void client_ui::on_pushButton_grant_clicked()
{
    c1->sync();
    set_tree();
    if(c1->name()==ADMIN){
        users_grant* ug1;
        ug1=new users_grant();
        ug1->set_client(c1);
        ug1-> show();
    }
}

void client_ui::on_pushButton_book_name_clicked()
{
    c1->sync();
    set_tree();
    change_name* cn1;
    cn1=new change_name();
    cn1->set_client(c1);
    cn1-> show();
}

void client_ui::on_pushButton_edit_writers_clicked()
{
    c1->sync();
    set_tree();
    edit_writer* ew1;
    ew1=new edit_writer();
    ew1->set_client(c1);
    ew1-> show();
}

void client_ui::on_pushButton_publish_clicked()
{
    c1->sync();
    set_tree();
    publish* p1;
    p1=new publish();
    p1->set_client(c1);
    p1-> show();
}

void client_ui::on_pushButton_back_version_clicked()
{
    c1->sync();
    set_tree();
    back_version* bv1;
    bv1=new back_version();
    bv1->set_client(c1);
    bv1-> show();
//    bv1->set_spin();

}


void client_ui::on_pushButton_show_edits_clicked()
{
    c1->sync();
    set_tree();
    book_content* bc1;
    bc1=new book_content();
    bc1->set_client(c1, ui->textBrowser);
    bc1-> show();
    bc1->set_spin();
}

void client_ui::on_pushButton_clicked()
{
    c1->sync();
    set_tree();
}

void client_ui::on_pushButton_version_content_clicked()
{
    c1->sync();
    set_tree();
    version_content_change* vcc1;
    vcc1=new version_content_change();
    vcc1->set_client(c1, ui->textBrowser);
    vcc1-> show();
}

void client_ui::on_pushButton_edit_clicked()
{
    c1->sync();
    set_tree();
    edit_book* eb1;
    eb1=new edit_book();
    eb1->set_client(c1);
    eb1-> show();

}

void client_ui::on_pushButton_latest_version_clicked()
{
    c1->sync();
    set_tree();
    latest_version* lv1;
    lv1=new latest_version();
    lv1->set_client(c1);
    lv1-> show();
}
