#include "edit_ui.h"
#include "ui_edit_ui.h"


edit_ui::edit_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_ui)
{
    ui->setupUi(this);
}

edit_ui::~edit_ui()
{
    delete ui;
}
void edit_ui::set_client(Client* _c1){
    c1=_c1;
}


void edit_ui::on_pushButton_2_clicked()
{

}
