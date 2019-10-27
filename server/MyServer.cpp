#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "MyServer.h"

using namespace std;

#define USERS_ADDRESS "./data/users/users.txt"
#define RAW_ADDRESS "./data/users/"
#define BOOK "./data/books/"
#define WRITTING "_going_to_write"
#define SERVER "./data"
#define USERS "./data/users"
#define AVAILABLE_BOOKS "./data/available books"

#define LAST_SEASON -1

class SERVER_ERROR {};
class ACCESS_VIOLATION {};
class INVALID_WRITER_NAME;

MyServer::MyServer(int port) : Server(port), id_generator(1){
  users.push_back(new User("Admin", "Admin"));
  address = "./data";
}

bool check_registeration(const vector<string> &tokens, const string &name) {
  string line;
  const char *input = name.c_str();
  ifstream myfile(input);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      if (line == "")
        continue; // to avoid core dump
      vector<string> data;
      data = parse_input(line);
      if (data[0] == tokens[0]) {
        myfile.close();
        return false;
      }
    }
    myfile.close();
    return true;
  } else
    return true;
}
string MyServer::validate_user(const vector<string> &user) {
  for ( int i = 0; i < users.size(); i++) {
    if(users[i]->name()==user[0] && users[i]->password()==user[1])
      return "successful_login";
  }
  return "unsuccessful_login";
}
  // string name = (string)USERS_ADDRESS;
  // string line;
  // const char *input = name.c_str();
  // ifstream myfile(input);
  // if (myfile.is_open()) {
  //   while (getline(myfile, line)) {
  //     vector<string> tokens;
  //     tokens = parse_input(line);
  //     if (user[0] == tokens[0] && user[1] == tokens[1]) {
  //       myfile.close();
  //       return "successful_login";
  //     } else
  //       continue;
  //   }
  //   myfile.close();
  //   return "unsuccessful_login";
  // } else
  //   throw SERVER_ERROR();
std::string MyServer::process_login(const vector<string> &tokens) {
  string answer;
  try {
    answer = validate_user(tokens);
    return answer;
  } catch (SERVER_ERROR ex()) {
    return "server_error";
  }
}
string MyServer::register_client(const vector<string> &tokens) {
  User *us = new User(tokens[0], tokens[1]);
  if (us != NULL) {
    for (int i = 0; i < users.size(); i++) {
      if(users[i]->name()==us->name()){
        delete us;
        return "register_failed";
      }
    }
    users.push_back(us);
    cerr<<"pushed"<<endl;
    string _name = "./data/users/" + tokens[0];
    make_directory(_name);
    _name = "./data/users/" + tokens[0] + "/" + tokens[0] + ".txt";
    string _name2 = "./data/users/users.txt";
    string _user = tokens[0] + " " + tokens[1];
    if (check_registeration(tokens, (string)USERS_ADDRESS) &&
        write_to_database(tokens, _name))
      if (write_to_database(_user, _name2))
        return "register_successful";
  }
  return "register_failed";
}
bool MyServer::write_to_database(string &text, string &_name) {
  const char *path = _name.c_str();
  ofstream myfile(path, ios::app);
  if (myfile.is_open()) {
    myfile.seekp(0, myfile.end);
    myfile << text << endl;
    myfile.close();
    return true;
  } else {
    throw SERVER_ERROR();
  }
}
bool MyServer::write_to_database(const vector<string> &tokens, string &_name) {
  const char *path = _name.c_str();
  fstream myfile(path, ios::out);
  if (myfile.is_open()) {
    myfile << tokens[0] << " ";
    myfile << tokens[1];
    myfile.close();
    return true;
  } else {
    throw SERVER_ERROR();
  }
  return false;
}
vector<string> MyServer::send_data(std::string data_name, string _name) {
  string path = (string)RAW_ADDRESS + _name + "/" + data_name + ".txt";
  return read_database(data_name, path);
}
vector<string> MyServer::read_database(string data_name, string path) {
  vector<string> data;
  const char *input = path.c_str();
  string line;
  ifstream myfile(input);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      getline(myfile, line);
      int size = s_to_i(line);
      for (int i = 0; i < size; i++) {
        getline(myfile, line);
        data.push_back(line);
      }
      break;
    }
    myfile.close();
    return data;
  } else {
    throw SERVER_ERROR();
  }
}
string MyServer::add_book(vector<string> data) {
  /// data[1]==username
  std::vector<string> writers; /// data[2]==book_name
  for (int i = 3; i < data.size(); i++) {
    writers.push_back(data[i]);
  }
  Book *b1;
  b1 = new Book(data[2], writers, data[1], id_generator);
  if (b1 == NULL)
    return "unsuccessful";
  for (int i = 0; i < users.size(); i++)
    if (users[i]->name()==data[1]) {
      users[i]->push_book(b1, (string) "created");
      books.push_back(b1);
      if(!users[i]->access())
        requests.push_back(data[2]);
      cerr<<"added_book"<<endl;
      //add_book_backup(data);
      /// add book to writers///
      cerr<<writers.size();
      for (int k = 0; k < writers.size(); k++) {
        for (int j = 0; j < users.size(); j++) {
          if (users[j]->name() == writers[k]) {
            users[j]->push_book(b1, (string) "writting");
            cerr<<"added book"<<endl;
            break;
          }
        }
      }
      return "successful "+itos(id_generator++);
    }
  delete b1;
  return "unsuccessful";
}
void MyServer::add_book_backup(std::vector<string> data) {
  make_directory(BOOK);
  string book_path = (string)BOOK + data[2]; //////data[2]=title
  string temp = RAW_ADDRESS + data[1] + "/_created.txt";
  vector<string> creator_path(1, temp);
  std::vector<string> writers_path;
  vector<string> writers;
  for (int i = 3; i < data.size(); i++) {
    writers.push_back(data[i]);
  }
  for (int i = 0; i < writers.size(); i++) {
    writers_path.push_back((string)RAW_ADDRESS + writers[i] + "/" +
                           (string)WRITTING + ".txt");
  }
  new_book(data[2], writers, data[1], book_path);
  add_to_(writers_path, data[2]);
  add_to_(creator_path, data[2]);
}
void MyServer::new_book(string title, std::vector<string> writers,
                        string creator, string book_path) {
  make_directory(book_path);
  make_directory(book_path + (string) "/versions");
  string ppp = book_path + "/versions" + "/versions_number.txt";
  string qqq = "0";
  write_to_database(ppp, qqq);
  string temp = book_path + "/writers.txt";
  const char *path = temp.c_str();
  temp = book_path + "/creator.txt";
  const char *path2 = temp.c_str();
  ofstream myfile(path);
  ofstream myfile2(path2);
  if (myfile.is_open())
    if (myfile2.is_open()) {
      for (int i = 0; i < writers.size(); i++) {
        myfile << writers[i];
        if (i != writers.size() - 1)
          myfile << endl;
      }
      myfile2 << creator;
      myfile2.close();
      myfile.close();
    } else {

      myfile.close();
      throw SERVER_ERROR();
    }
  else
    throw SERVER_ERROR();
}
void MyServer::add_to_(vector<string> addr, string title) {
  for (int i = 0; i < addr.size(); i++) {
    vector<string> records;
    records = read_path_database(addr[i]);
    records.push_back(title);
    write_to_database_with_number(addr[i], records);
  }
}
void MyServer::backup_new_season_creation(string book_name,
                                          string season_name) {
  make_directory((string)BOOK);
  string directory_addr = (string)BOOK + book_name;
  make_directory(directory_addr);
  vector<string> addr(1, string(directory_addr + "/" + "seasons" + ".txt"));
  make_directory(directory_addr + "/" + season_name);
  add_to_(addr, season_name);
}
void MyServer::backup_new_season_creation(string book_name, string season_name,
                                          int line) {
  make_directory((string)BOOK);
  string directory_addr = (string)BOOK + book_name;
  make_directory(directory_addr);
  string addr = directory_addr + "/" + "seasons" + ".txt";
  make_directory(directory_addr + "/" + season_name);
  add_to_(season_name, addr, line);
}
string MyServer::create_new_season(string message) {
  vector<string> tokens;
  tokens = parse_input(message);
  string usser = tokens[1];
  string book_name = tokens[2];
  string season_name = tokens[3];
  for (int i = 0; i < books.size(); i++) {
      if(books[i]->name()==book_name)
        if(users[i]->access()==true){
        check_access(usser, book_name, season_name);
        int place = (tokens.size() > 4 ? s_to_i(tokens[4]) : (int)LAST_SEASON);
        Season *s1;
        s1 = new Season(season_name);
        if (s1 == NULL)
          return "unsuccessful";
        if (!push_new_season(s1, usser, book_name, season_name, place)) {

          delete s1;
          return "unsuccessful";
        }
        else
          return "successful";
        // if (place == (int)LAST_SEASON)
        //   backup_new_season_creation(book_name, season_name);
        // else
        //   backup_new_season_creation(book_name, season_name, place);
        // return "successful";
      }
      else
        return "access_denied";
  }
}
bool MyServer::push_new_season(Season *s1, string _name, string book,
                               string season, int place) {
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()==book){
      books[i]->push_season(s1, place);
      return true;
    }
  }
  return false;

  // for (int i = 0; i < users.size(); i++)
  //   if (users[i]->name() == _name)
  //     if (users[i]->push_new_season(s1, book, season, place)) {
  //       return true;
  //     }
  // return false;
}
bool MyServer::add_to_(string &season_name, string &addr, int line) {
  int size2;
  int size = 0;
  const char *path = addr.c_str();
  for (int i = 0; i < addr.size(); i++) {

    vector<string> records;
    records = read_path_database(addr);
    ofstream myfile(path);
    if (myfile.is_open()) {
      myfile << itos(records.size());
      for (int i = 1; i < line; i++)
        myfile << endl << records[i];
      myfile << endl << season_name;
      for (int i = line + 1; i < records.size(); i++)
        myfile << endl << records[i];
    } else
      throw SERVER_ERROR();
  }
}
int MyServer::version_number(std::string _name, std::string book,
                             std::string season) {
  for (int i = 0; i < users.size(); i++) {
    if (users[i]->name() == _name) {
      return users[i]->version_number(book, season);
    }
  }
  throw SERVER_ERROR();
}
string MyServer::load_latest_version(vector<string> data) {
  cerr<<"i'm in"<<endl;
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name() == data[2]){
      //for(int j=0;j<users.size(); j++)
        //if(users[j]->name()==data[1]){
          // if(users[j]->access()){
        check_access_writer(data[1], data[2], data[3]);
        string message = "latest_version";
        vector< vector<string> > vers;
        cerr<<"hereeeee"<<endl;
        int num = (data[4]=="0" ? 0 : s_to_i(data[4]));
        int available_version = version_number(data[1], data[2], data[3]);
        cerr<<num<<" "<<available_version<<endl;
        if (num < available_version){
          cerr<<"here"<<endl;
          cerr<<message<<endl;
          cerr<<"***********"<<endl;
          prepare_versions_from(num, message, data[1], data[2], data[3]);
          cerr<<message<<endl;
          return message;
        }
        else if (num > available_version)
          return (string) "remove_from " + itos(available_version + 1);
        else
          return (string) "all_is_updated";
          // }
          // else
          //   return "access_denied";
      // }
      // else
      //   return "unsuccessful";
    }
    else
      return "unsuccessful";
  }
  return "unsuccessful";
}
void MyServer::prepare_versions_from(int num, string &message, string _name,
                                     string book, string season) {
        cerr<<"1"<<endl;
  for (int i = 0; i < users.size(); i++) {
    if (users[i]->name() == _name){
      cerr<<"2"<<endl;
      users[i]->send_versions_from(num, message, book, season);
      cerr<<"3"<<endl;
    }
  }
}
vector<string> MyServer::read_path_database(string path) {
  vector<string> data;
  string line;
  const char *input = path.c_str();
  ifstream myfile(input);
  if (myfile.is_open()) {
    while (getline(myfile, line))
      data.push_back(line);
    myfile.close();
    return data;
  }
  return data;
}
void MyServer::write_to_database_with_number(string _path,
                                             vector<string> records) {
  const char *path = _path.c_str();
  ofstream myfile(path);
  if (myfile.is_open()) {
    myfile << itos(records.size());
    for (int i = 0; i < records.size(); i++) {
      myfile << endl << records[i];
    }
  } else
    throw SERVER_ERROR();
}
bool MyServer::send_version_to_server(std::string response) {}
string MyServer::is_last_version(std::vector<string> data) {
  check_access_writer(data[1], data[2],
                      data[3]); /// data1=username, data2= book , data3= season
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name() == data[2])
      if(users[i]->access()){
        int num;
        for (int i = 0; i < users.size(); i++)
        if (users[i]->name() == data[1])
        num = users[i]->get_version_number(data[2], data[3]);
        if (num == -1)
        throw SERVER_ERROR();
        if (s_to_i(data[4]) != num)
        return "false";
        else
        return "true";
      }
      else
        return "access_denied";
    else
      return "unsuccessful";
    }
}
string MyServer::get_new_versions(std::vector<string> data) {
  check_access_writer(data[1], data[2], data[3]);
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()==data[2])
      if(users[i]->access())
      {

      }
  }
}
void MyServer::check_access(string _name, string book_name,
                            string season_name) {
  bool first;
  bool second;
  first = check_access_writer(_name, book_name, season_name);
  second = check_access_creator(_name, book_name, season_name);
  if (first || second)
    return;
  throw ACCESS_VIOLATION();
}
bool MyServer::check_access_writer(string _name, string book_name,
                                   string season_name) {
  string job = "writting";
  for (int i = 0; i < users.size(); i++)
    if (users[i]->name() == _name)
      return users[i]->check_access(_name, book_name, job);
  throw SERVER_ERROR();
}
bool MyServer::check_access_creator(string _name, string book_name,
                                    string season_name) {
  for (int i = 0; i < users.size(); i++)
    if (users[i]->name() == _name)
      return users[i]->check_access(_name, book_name, "created");
  throw SERVER_ERROR();
}
string MyServer::change_writer(vector<string> data) {
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()==data[2]){
        string change = (data[0] == "add_writer" ? "add" : "remove");
        for (int j = 0; j < users.size(); j++)
          if (users[j]->name() == data[1]) {
            try {
              users[j]->change_writer(change, data[2], data[3]);
              for (int k = 0; k < users.size(); k++) {
                if (users[k]->name() == data[3]) {
                  if(change=="add"){
                    for(int d=0; d<books.size(); d++)
                      if(books[d]->name()==data[2]){
                        users[k]->push_book(books[d],"writting");
                        return "successful";
                      }
                  }
                  else if(change=="remove")
                    users[k]->pop_book(data[2]);
                  return "successful";
                }
              }
            } catch (INVALID_WRITER_NAME ex()) {
              return "invalid_writer_name";
            }
          }
    }
    else
      return "unsuccessful";
  }
  return "unsuccessful";
}
string MyServer::push_version(string message) {
  ////initializion
  string name, book, season, input;
  string addr;
  istringstream iss(message);
  getline(iss, book); ////extra input
  getline(iss, name);
  getline(iss, book);
  getline(iss, season);
  vector<Edit *> edit;
  vector<string> tokens;
  Edition *edition;
  Version *v1;
  ////initializion
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()==book)
      if(users[i]->access()){
        check_access_writer(name, book, season);
        while (getline(iss, input)) {
          if (input == "new")
            continue;
          else if (input == "end")
            break;
          make_directory((string)BOOK + book + "/" + (string) "/versions/" + season);
          addr = (string)BOOK + book + "/" + (string) "/versions/" + season + "/" +
                 itos(version_number(name, book, season) + 1) + ".txt";
          //write_to_database(input, addr);
          tokens = parse_input(input);
          tokens[2]=replaced_under_with_space(tokens[2]);
          tokens[3]=replaced_under_with_space(tokens[3]);
          Edit *ed;
          try {
            ed = new Edit(tokens[0], s_to_i(tokens[1]),
                          (tokens[2] == "empty" ? "" : tokens[2]),
                          (tokens[3] == "empty" ? "" : tokens[3]));
            if (ed == NULL)
              throw SERVER_ERROR();
            edit.push_back(ed);
          } catch (SERVER_ERROR ex()) {
            for (int i = 0; i < edit.size(); i++)
              delete edit[i];
            throw;
          }
        }
        try {
          edition = new Edition(book, season, edit);
          if (edition == NULL)
            throw SERVER_ERROR();
        } catch (SERVER_ERROR ex()) {
          for (int i = 0; i < edit.size(); i++)
            delete edit[i];
          throw;
        }
        try {
          v1 = new Version(edition);
          if (v1 == NULL)
            throw SERVER_ERROR();
        } catch (SERVER_ERROR ex()) {
          for (int i = 0; i < edit.size(); i++)
            delete edit[i];
          delete edition;
          throw;
        }
        for (int i = 0; i < users.size(); i++) {
          if (users[i]->name() == name)
            users[i]->push_version(v1, book, season);
        }
        return "successful";
      }
      else
        return "access_denied";
    else
      return "unsuccessful";
  }
}
// void versions_backup(){
// 	string addr=BOOK+book_name+"/"+season_name;
// 	make_directory(addr);
// 	int
// number_of_versions=s_to_i(read_path_database(BOOK+book_name+"/"+season_name+"/versions/versions.txt");
// 	for (int i = 0; i < number_of_versions; i++) {
// 		data.push_back(
// read_path_database(BOOK+book_name+"/"+season_name+"/versions/"+itos(i)+".txt")
// )
// 	}
// 	return data;
// }
string MyServer::back_to_version(std::vector<string> data) {
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()==data[2])
      if(users[i]->access()){
        check_access_creator(data[1], data[2], data[3]);
        for (int i = 0; i < users.size(); i++) {
          if (users[i]->name() == data[1]) {
            users[i]->back_to_version(data[2], data[3], s_to_i(data[4]));
            return "successful";
          }
        }
        return "unsuccessful";
      }
      else
        return "access_denied";
    else
      return "unsuccessful";
  }
}
string MyServer::get_message(string message) {
  std::vector<string> data;
  istringstream iss(message);
  string input;
  getline(iss, input);
  data = parse_input(message);
  try {
    if (data[0] == "login") {
      data.erase(data.begin());
      return process_login(data);
    } else if (data[0] == "signup") {
      data.erase(data.begin());
      return register_client(data);
    } else if (data[0] == "add_book")
      return add_book(data);
    else if (data[0] == "new_season")
      return create_new_season(message);
    else if (data[0] == "is_last_version") /// checked
      return is_last_version(data); /// for saving changes
    else if (data[0] == "get_new_versions")
      return get_new_versions(data);
    else if (data[0] == "change_title")
      return change_title(data);
    else if (data[0] == "add_writer" || data[0] == "remove_writer")
      return change_writer(data);
    else if (data[0] == "latest_versions")
      return load_latest_version(data);
    else if (data[0] == "back_to_version")
      return back_to_version(data);
    else if ( data [0] == "publish_book")
      return publish_book(message);
    else if(data[0]=="sync")
      return sync(message);
    if (input == "send_version")
      return push_version(message);
    else if(input =="show_requests")
      return show_requests();
    else if(data[0]=="approve_request")
      return approve_request(message);
  } catch (SERVER_ERROR ex()) {
    return "server_error";
  } catch (ACCESS_VIOLATION ex()) {
    return "invalid_access";
  }catch(...){
    return "unsuccessful";
  }
}
MyServer::~MyServer() {
  for (int i = 0; i < books.size(); i++) {
    delete books[i];
  }
  for (int i = 0; i < users.size(); i++) {
    delete users[i];
  }
  for (int i = 0; i < available_books.size(); i++) {
    delete available_books[i];
  }
}
string MyServer::change_title(vector<string> data) {
  for (int i = 0; i < books.size(); i++)
    if(books[i]->name()==data[2]){
      if(users[i]->access()){
        for (int i = 0; i < users.size(); i++)
          if (users[i]->name() == data[1]) {
            users[i]->change_title(data[2], data[3]);
            return "successful";
          }
          else
            return "unsuccessful";
      }
      else
        return "access_denied";
    }
    else
      return "unsuccessful";
}
string MyServer::publish_book(string message){

  ///initializion
  make_directory(AVAILABLE_BOOKS);
  vector <string> tokens;
  string text;
  string temp;
  istringstream iss(message);
  getline(iss, temp);
  tokens= parse_input(temp);
  ////initializion

  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()== tokens[2])
      if(users[i]->access()){
        make_directory(AVAILABLE_BOOKS+(string)"/"+tokens[2]);
        Available_books* a1;
        while(getline(iss, temp)){
          if(temp=="")
            break;
          text = text + temp +"\n";
        }
        a1=new Available_books(AVAILABLE_BOOKS+(string)"/"+tokens[2]+(string)".html", tokens[2], text);
        available_books.push_back(a1);
        string addr=AVAILABLE_BOOKS+(string)"/"+tokens[2]+(string)"/"+tokens[2]+(string)".html";
        write_to_database(text, addr);
        addr=AVAILABLE_BOOKS+(string)"/"+tokens[2]+(string)"/"+(string)"txtstyle.css";
        temp=(string)"html, body {font-family:Helvetica, Arial, sans-serif}";
        write_to_database(temp, addr);
        for (int i = 0; i < users.size(); i++)
          users[i]->erase_from_list_writting(tokens[2]);
        for (int i = 0; i < users.size(); i++)
          users[i]->erase_from_list_created(tokens[2]);
        return "successful";
      }
      else
        return "access_denied";
    else
      return "unsuccessful";
  }
}
string MyServer::sync(string message){
  std::vector<string> v;
  v=parse_input(message);
  cerr<<"1"<<endl;
  for (int i = 0; i < users.size(); i++) {
    if(users[i]->name()==v[1]){
      cerr<<"2"<<endl;
      message=users[i]->sync_books_info();
      cerr<<"message server: "<<message<<endl;
      return message;
    }
  }
}
string MyServer::show_requests(){
  string message;
  for (int i = 0; i < requests.size(); i++) {
    message=message+requests[i]+" ";
  }
  if(requests.size()==0)
    return "";
  return message;
}
string MyServer::approve_request(string message){
  std::vector<string> v;
  v=parse_input(message);
  for (int i = 0; i < books.size(); i++) {
    if(books[i]->name()==v[1]){
      users[i]->grant_access();
      for (int i = 0; i < requests.size(); i++) {
        if(requests[i]==v[1]){
          requests.erase(requests.begin()+i);
          return "successful";
        }
      }
    }
  }
  return "unsuccessful";
}
void MyServer::on_standard_input(string line){

	cout << "STDIN: " << line << endl;
  if (line == ":q")
    stop();
}
void MyServer::on_new_connection(int identifier) {
  cout << "NEW CONNECTION: " << identifier << endl;
}
void MyServer::on_new_message(int identifier, string message) {
  cout << "NEW MESSAGE FROM " << identifier <<": " << message << endl;
	try{
	message = get_message(message);
	cout<< "MESSAGE TO " <<identifier <<": "<<message << endl ;
	}catch(...){
	message = "unsuccessful";
	}
	send(identifier, message);
}
void MyServer::on_terminated_connection(int identifier) {
  cout << "TERMINATED CONNECTION: " << identifier << endl;
}
