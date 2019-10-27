#include "server.h"
#include <cstdlib>
using namespace std;

#include "MyServer.h"

#define SERVER "./data"
#define USERS "./data/users"

void prepare();

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "valid operation: " << argv[0] << " [port number]\n";
    exit(-1);
  }
  prepare();
  MyServer server(Tools::mystoi(argv[1]));
  server.run();

  return 0;
}

void prepare(){
  make_directory(SERVER);
  make_directory(USERS);
}
