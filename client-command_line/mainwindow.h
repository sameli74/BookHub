#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Client.h"
#include "signup.h"
#include "client_ui.h"
#include "Machine.h"
#include "UI.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void set_parameters (Client* _c1, Machine* _m1, UI* _u1);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_commandLinkButton_signup_clicked();

private:
    Ui::MainWindow *ui;
    Client* c1;
    Machine* m1;
    UI* u1;
    signup *si;
    client_ui* cu1;
};

#endif // MAINWINDOW_H
