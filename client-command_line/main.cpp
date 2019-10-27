#include <string>
#include <cstdlib>
#include <vector>
#include <QApplication>

#include "mainwindow.h"
#include "UI.h"
#include "Client.h"
#include "client_socket.h"
#include "Machine.h"
#include "methods.h"


using namespace std;

int main(int argc, char* argv[]) {

  if (argc != 3) {
    cerr << "valid operation: " << argv[0] << " [server address] [server port]\n";
    exit(-1);
  }
  ClientSocket* socket;
  cout << "# connection established\n";
  int num;
  QApplication a(argc, argv);
  MainWindow w;
  UI* ui1;
  Client* c1;
  Machine* m1;
  socket=new ClientSocket(string(argv[1]    ), Tools::mystoi(argv[2]));
  c1 = new Client(socket);
  ui1 = new UI(c1);
  m1 = new Machine(c1);
  ui1->set_machine(m1);
  c1->set_machine(m1);
  if(socket==NULL|| c1==NULL || ui1==NULL)
    exit(-1);
  w.set_parameters(c1, m1, ui1);
  w.show();
  num=a.exec();
  delete ui1;
  return num;
}
