#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "Client.h"

using namespace std;

#define COMPLETED_BOOKS "_completed"
#define IN_PROCESS_WRITTING_BOOKS "_going_to_write"
#define CREATED_BOOK "_created"
#define DATA "./data"
#define MACHINE_ADDRESS "./data/machine"
#define MACHINE_ADDRESS_EDITS "./data/machine/history/edits"
#define MACHINE_ADDRESS_VERSIONS "./data/machine/versions"
#define RAW_ADDRESS "./data/clients/"
#define WRITTING "_going_to_write"
#define CREATED "_created"
#define ADMIN_USER "Admin"
#define ADMIN_PASS "Admin"


#define CAN_NOT_CREATE 0
#define END -1
#define CAN_NOT_ADD -1

class INVALID_USER {};
class MACHINE_ERROR {};
class VERSION_DOWNLOAD_ERROR {};
class SERVER_ERROR {};
class INTERNAL_ERROR {};
class ALLOCATION_ERROR {};
class ACCESS_VIOLATION {};
class ERROR_ON_EDIT;

Client::Client(ClientSocket *_s1) : Visitor() { s1 = _s1; }
string Client::load_backup(string book, string season) {
  string name =
      (string)MACHINE_ADDRESS_EDITS + "/" + book + "/" + season + ".txt";
  const char *input = name.c_str();
  ifstream myfile(input);
  vector<string> loaded;
  if (myfile.is_open()) {
    string line;
    while (getline(myfile, line)) /// Read from from file
      loaded.push_back(line);
    myfile.close();
    m1->load_text_edits(loaded, book, season);
    return "successful";
  } else {
    return "no_backup";
  }
}
Client::~Client() {
  for (int i = 0; i < _created.size(); i++) {
    delete _created[i];
  }
  delete s1;
}
string Client::send_message(string message) {
  s1->send(message);
  message = s1->receive();
  s1->status();
  return message;

}
string Client::process_login(const vector<string> &tokens) {
  string answer;
  string message = "login";
  for (int i = 0; i < tokens.size(); i++) {
    message = message + " " + tokens[i];
  }
  answer = send_message(message);
  if (answer == "successful_login") {
    _name = tokens[0];
    _password = tokens[1];
    // _completed = get_data((string)COMPLETED_BOOKS, _name);
    // _going_to_write = get_data((string)IN_PROCESS_WRITTING_BOOKS, _name);
    // _created = get_data((string)CREATED_BOOK, _name);
    return "successful";
  } else if (answer == "unsuccessful_login")
    return "unsuccessful";
  else if (answer == "server_error")
    throw SERVER_ERROR();
}
string Client::register_client(const vector<string> &tokens) {
  ///////////////////////////////////////Done////////////////////////
  string message;
  message = "signup";
  for (int i = 0; i < tokens.size(); i++)
    message = message + " " + tokens[i];
  message = send_message(message);
  if (message == "server_error")
    throw SERVER_ERROR();
  else
    return message;
}
// vector<string> Client::get_data(string data_name, string _name) {
// 	return s1->send_data(data_name, _name);
// }
string Client::start_editing(vector<string> tokens, string book_name,
                             string season_name) {
  make_directory((string)DATA);
  make_directory((string)MACHINE_ADDRESS);
  make_directory((string)MACHINE_ADDRESS + "/" + _name);
  make_directory((string)MACHINE_ADDRESS + "/" + _name + "/" + book_name);
  try {
    m1->save_edits_ro_ram(tokens, book_name, season_name);
    string name = (string)MACHINE_ADDRESS + "/" + _name + "/" + book_name +
                  "/" + season_name + ".txt";
    const char *input = name.c_str();
    ofstream myfile2(input, ios::app);
    if (myfile2.is_open()) {
      process_edit(myfile2, tokens, book_name, season_name);
      myfile2.close();
      return "successful";
    } else
      throw INTERNAL_ERROR();
  } catch (ERROR_ON_EDIT ex()) {
    return "unsuccessful";
  }
}
bool Client::create_book(string title, vector<string> writers) {
  Book *b1;
  int id=add_book_to_server(title, writers);
  if (id > 0) {
    b1 = new Book(title, writers, _name, id);
    for (int i = 0; i < writers.size(); i++)
      if (writers[i] == _name)
        _going_to_write.push_back(b1);
    _created.push_back(b1);
    return true;
  }
  else
    return false;
}
int Client::add_book_to_server(string title, vector<string> writers) {
  string message = "add_book " + _name + " " + title;
  for (int i = 0; i < writers.size(); i++)
    message = message + " " + writers[i];
  message = send_message(message);
  vector<string> tokens;
  tokens=parse_input(message);
  if (tokens[0] == "successful") {
    return s_to_i(tokens[1]);
  }
  return -1;
}
bool Client::create_new_season(string book_name, string season_name,
                               int place) {
  string message =
      (string) "new_season " + _name + " " + book_name + " " + season_name;
  if(place!= LAST_SEASON)
    message=message+" "+(itos(place));
  int availabe_in_writting =
      find_book(book_name, season_name, (string)WRITTING);
  int availabe_in_completed =
      find_book(book_name, season_name, (string)CREATED);
  if (availabe_in_writting == CAN_NOT_ADD &&
      availabe_in_completed == CAN_NOT_ADD)
    return false;
  message = send_message(message);
  if (message == "successful") {
    Season *s1;
    s1 = new Season(season_name);
    if (availabe_in_writting != CAN_NOT_ADD) {
      _going_to_write[availabe_in_writting]->push_season(s1, place);
      return true;
    } else if (availabe_in_completed != CAN_NOT_ADD) {
      _created[availabe_in_completed]->push_season(s1, place);
      return true;
    }
  }
  return false;
}
bool Client::process_edit(ofstream &myfile2, vector<string> tokens, string book,
                          string season) {
  if (tokens[0] == "add")
    return (
        write(tokens[0] + " " + tokens[1] + " " + "empty " + tokens[2], _name,
              book + "/" + season)); /// tokens[1]=line_number ///tokens[2]=text
  else if (tokens[0] == "remove")
    return (write(tokens[0] + " " + tokens[1] + " empty" + " empty", _name,
                  book + "/" + season)); // tokens[1]=line number
  else if (tokens[0] == "change")
    return (
        write(tokens[0] + " " + tokens[1] + " " + tokens[2] + " " + tokens[3],
              _name, book + "/" + season)); // tokens[1]=line number
  return true;
}
bool Client::write(string command, string _name, string season_name) {
  int num = season_name.find("/");
  string temp = season_name.substr(0, num);
  make_directory(MACHINE_ADDRESS + _name + "/" + temp);
  make_directory(MACHINE_ADDRESS + _name + season_name);
  string addr =
      (string)MACHINE_ADDRESS + "/" + _name + "/" + season_name + ".txt";
  try {
    write_to_disk(command, addr);
    return true;
  } catch (MACHINE_ERROR ex()) {
    return false;
  }
}
bool Client::write_to_disk(string &text, string &addr) {
  const char *path = addr.c_str();
  ofstream myfile(path, ios::app);
  if (myfile.is_open()) {
    myfile.seekp(0, myfile.end);
    myfile << text << endl;
    myfile.close();
    return true;
  } else
    throw MACHINE_ERROR();
  return false;
}
bool Client::write_w(string text, string addr) {
  const char *path = addr.c_str();
  ofstream myfile(path);
  if (myfile.is_open()) {
    myfile << text;
    myfile.close();
    return true;
  } else
    return false;
}
bool write_to_disk(vector<string> &text, string &_path) {
  const char *path = _path.c_str();
  ofstream myfile(path);
  if (myfile.is_open()) {
    for (int i = 0; i < text.size(); i++) {
      myfile << text[i] << endl;
    }
    myfile.close();
    return true;
  } else
    throw VERSION_DOWNLOAD_ERROR();
}
void Client::decode_server_response(string answer, string book_name,
                                    string season_name) {
  for (int i = 0; i < _going_to_write.size(); i++) {
    if (_going_to_write[i]->name() == book_name) {
      vector<Version *> v = process_versions(answer, book_name, season_name);
      if (v.size() != 0){
        for(int j=0; j<v.size(); j++)
            _going_to_write[i]->push_version(v[j], season_name);
        return;
      }
    }
  }
}
int Client::version_number(string book, string season) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book)
      return _going_to_write[i]->version_number(season);
}
bool Client::receive_latest_version(string book_name, string season_name) {
  string message;
  message = "latest_versions " + _name + " " + book_name + " " + season_name +
            " " + itos(version_number(book_name, season_name));
  message = send_message(message);
  if (message == "all_is_updated")
    return true;
  else if(message=="access_denied" || message=="unsuccessful")
    return false;
  decode_server_response(message, book_name, season_name);

  return true;
}
int Client::find_book(string book_name, string season_name, string who_added) {
  if (who_added == WRITTING) {
    for (int i = 0; i < _going_to_write.size(); i++)
      if (_going_to_write[i]->name() == book_name) {

        return i;
      }
  } else if (who_added == CREATED) {
    for (int i = 0; i < _created.size(); i++)
      if (_created[i]->name() == book_name) {
        return i;
      }
  }
  return CAN_NOT_ADD;
}
vector<Version *> Client::process_versions(string answer, string book,
                                           string season) {
  istringstream iss(answer);
  vector<Version *> vers;
  string input;
  vector<string> tokens;
  getline(iss, input);
  cerr<<input<<endl;
  tokens = parse_input(input);
  if (input == "latest_version") {
    while (getline(iss, input)) {
        cerr<<input<<endl;
      vector<string> tokens;
      tokens = parse_input(input);
      Edition *ed;
      if (tokens[0] == "new") {
        cerr<<"1"<<endl;
        vector<Edit*> _edits;
        try {
          while (getline(iss, input)) {
            cerr<<input<<endl;
            vector<string> tokens2;
            tokens2 = parse_input(input);
            if (input == "end")
              break;
            cerr<<"1.25"<<endl;
            Edit* edit;
            edit = new Edit(tokens2[0], s_to_i(tokens2[1]),
                                  (tokens2[2] == "empty" ? "" : tokens2[2]),
                                  (tokens2[3] == "empty" ? "" : tokens2[3]));
            cerr<<"1.5"<<endl;
            if (edit == NULL)
              throw ALLOCATION_ERROR();
            cerr<<"1.5"<<endl;
            _edits.push_back(edit);
          }
        } catch (ALLOCATION_ERROR ex()) {
          for (int i = 0; i < _edits.size(); i++)
            delete _edits[i];
          throw;
        }
        cerr<<"2"<<endl;
        ed = new Edition(_edits);
        try {
          Version *ver = new Version(ed);
          if (ver == NULL)
            throw ALLOCATION_ERROR();
          cerr<<"3"<<endl;
          vers.push_back(ver);
          cerr<<"4"<<endl;
        } catch (ALLOCATION_ERROR ex()) {
          for (int i = 0; i < _edits.size(); i++)
            delete _edits[i];
          delete ed;
          for (int i = 0; i < vers.size(); i++) {
            vers[i]->del();
            delete vers[i];
          }
          throw;
        }
      }
    }
  } else if (input == "remove_from")
    for (int j = 0; j < _going_to_write.size(); j++) {
      if (_going_to_write[j]->name() == book) {
        _going_to_write[j]->del_ver(season, s_to_i(tokens[1]));
      }
    }
  return vers;
}
// bool Client::send_versions(string book_name, string season_name) {
// 	string message="is_last_version "+_name+" "+book+" "+season+"
// "itos(version_number(book, season));
// 	if (!is_last_version(book_name, season_name))
// 		get_latest_version(book_name, season_name);
// 	string response_to_server;
// 	response_to_server = response_to_server + "version ";
// 	response_to_server =
// 		response_to_server + m1->machine_send("one", book_name,
// season_name);
// 	if (s1->send_version_to_server("add_to_versions " + book_name + " " +
// 		season_name + " " + response_to_server) ==
// 		"invalid access")
// 		throw SERVER_ERROR();
// 	return true;
// }
// bool Client::send_all() {
// 	for (int i = 0; i < versions.size(); i++) {
// 		send_versions(versions[i]->name(), versions[i]->season_name());
// 	}
// }
int Client::get_version_number(string book_name, string season_name) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book_name)
      return _going_to_write[i]->version_number(season_name);
}
// bool Client::is_last_version(string book_name, string season_name) {
// 	int num = version_number(book_name, season_name);
// 	string message = "is_last_version " + _name + " " + book_name + " " +
// 		season_name + " " + itos(num);
// 	/// text=is_last_version clientname book season number_of_versions
// 	message = s1->is_last_version(text);
// 	if (message == "true")
// 		return true;
// 	else if (message == "false")
// 		return false;
// 	else if (message == "server_error")
// 		throw SERVER_ERROR();
// 	else if (message == "invalid_access")
// 		throw ACCESS_VIOLATION();
// }
void Client::get_latest_version(string book_name, string season_name) {
  int num = get_version_number(book_name, season_name);
  string message = "get_new_versions " + _name + " " + book_name + " " +
                   season_name + " " + itos(num);
  message = send_message(message);
}
string Client::change_book_title(string book, string title) {
    string message = "change_title " + _name + " " + book + " " + title;
    message = send_message(message);
    if(message=="successful"){
        for (int i = 0; i < _created.size(); i++) {
            if(_created[i]->name()==book){
                _created[i]->change_title(title);
                return "successful";
            }
            else{
                for(int j=0; j<_going_to_write.size();j++)
                    if(_going_to_write[j]->name()==book){
                        _going_to_write[j]->change_title(title);
                        _created.push_back(_going_to_write[j]);
                        return "successful";
                    }
            }
        }
    }
    return "unsuccessful";
  }

// if (!change_if_not_sent(book, title)) {
// 	if (message == "access_violation")
// 		throw ACCESS_VIOLATION();
// 	return;
// }
// bool Client::change_if_not_sent(string book, string title) {
// 	for (int i = 0; i < _created.size(); i++) {
// 		if (_created[i]->name() == book)
// 			if (_created[i]->get_creator() == _name) {
// 				_created[i]->change_title(_name, title);
// 				return true;
// 			}
// 			else
// 				throw ACCESS_VIOLATION();
// 	}
// 	return false;
//  }
std::string Client::change_to_writers(string change, string book,
                               string writer_name_to_change) {
  change_writer(change, book, writer_name_to_change);
  string message = ((change == "add") ? "add_writer " : "remove_writer ") +
                   _name + " " + book + " " + writer_name_to_change;
  message = send_message(message);
  if(message=="successful")
       return message;
  else
      return "unsuccessful";
}
// if (!change_writer_if_not_sent(change, book, writer_name_to_change)) {
// 	if (message == "access_violation")
// 		throw ACCESS_VIOLATION();
// 	return;
// }
bool Client::change_writer_if_not_sent(string change, string book,
                                       string writer_name_to_change) {
  for (int i = 0; i < _created.size(); i++) {
    if (_created[i]->name() == book)
      if (_created[i]->get_creator() == _name) {
        _created[i]->change_writer(change, writer_name_to_change);
        return true;
      } else
        throw ACCESS_VIOLATION();
  }
  return false;
}
// void Client::finalize_version(Version *v1, string book, string season) {
// 	for (int i = 0; i < _going_to_write.size(); i++)
// 		if (_going_to_write[i]->name() == book) {
// 			_going_to_write[i]->push_version(v1, season);
//
// 			break;
// 		}
// }
bool Client::send_version(string book, string season, string &text) {
  text = "send_version" + (string) "\n" + _name + (string) "\n" + book +
         (string) "\n" + season + (string) "\n" + text;
  text = send_message(text);
  if (text == "successful") {
    string addr = (string)MACHINE_ADDRESS + "/" + _name + "/" + book + "/" +
                  season + ".txt";
    remove(addr.c_str());
    return true;
  } else if (text == "server_error" || text=="access_denied")
    return false;
}
bool Client::check_if_final_version(string book, string season) {
  int num;
  num = version_number(book, season);
  string message =
      "is_last_version " + _name + " " + book + " " + season + " " + itos(num);
  message = send_message(message);
  if (message == "true")
    return true;
  return false;
}
bool Client::send_book(Version *v1, string book, string season) {
  int k;
  bool answer;
  string text;
  int num;
  num = version_number(book, season);
  answer = check_if_final_version(book, season);
  text = v1->get_info();
  if (answer == true) {
    if (send_version(book, season, text)) {
      for (int j = 0; j < _going_to_write.size(); j++)
        if (_going_to_write[j]->name() == book) {
          _going_to_write[j]->push_version(v1, season);
          return true;
        }
    }
    delete v1;
    return false;
  } else {
    string path = (string)MACHINE_ADDRESS_VERSIONS + "/" + book + "/" + season +
                  "/" + season + ".txt";
    write_w(text, path);
    delete v1;
    string message;
    message = send_message("latest_version " + _name + " " + book + " " +
                           season + " " + itos(num));
    vector<string> ddata;
    ddata = parse_input(message);
    if (message == "remove_from") {
      //	del_ver(book, season, s_to_i(ddata[1]));
      // else
      del_ver(book, season, version_number(book, season) - 1);
      vector<Version *> v;
      v = process_versions(message, book, season);
      for (int j = 0; j < _going_to_write.size(); j++)
        if (_going_to_write[j]->name() == book) {
          for (int i = 0; i < v.size(); i++)
            _going_to_write[j]->push_version(v[i], season);
          break;
        }
    }
    return false;
  }
}
void Client::del_ver(string book, string season, int num) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book) {
      _going_to_write[i]->del_ver(season, num);
      break;
    }
}
string Client::back_to_version(string book, string season, int num) {
  bool flag = false;
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book) {
      del_ver(book, season, num);
      flag = true;
      break;
    }
  ////Creator////
  for (int i = 0; i < _created.size(); i++)
    if (_created[i]->name() == book) {
      if (!flag)
        del_ver(book, season, num);
      string message = "back_to_version " + _name + " " + book + " " + season +
                       " " + itos(num);
      // string message;
      // return
      message = send_message(message);
      return message;
    }
  ////Creator////
  return "successful";
}
string Client::back_to_version_repository(string book, string season, int num) {

  return "unsuccessful";
}

void Client::set_login(string name, string pass) {
  _name = name;
  _password = pass;
  int id;
}
void Client::set_machine(Machine *_m1) { m1 = _m1; }

vector<string> Client::get_text(string book, string season, int number) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book)
      return _going_to_write[i]->get_text(season, number);
}

vector<string> Client::changes_to_version(string book, string season, int num) {
  for (int i = 0; i < _going_to_write.size(); i++) {
    if (_going_to_write[i]->name() == book)
      return _going_to_write[i]->changes_to_version(season, num);
  }
}
bool Client::publish_book(string book){
  string html;
  for (int i = 0; i < _created.size(); i++) {
    if(_created[i]->name()== book){
      html = _created[i]-> get_html();
      for (int j = 0; j < _going_to_write.size(); j++)
        if(_going_to_write[j]->name() == book ){
          _going_to_write.erase(_going_to_write.begin()+j);
          break;
        }
      delete _created[i];
      _created.erase(_created.begin()+i);
      string message= (string)"publish_book"+" "+ _name + " " +book+ "\n";
      message = message + html;
      message = send_message(message);
      if(message=="access_denied"||message=="unsuccessful")
        return false;
      return true;
    }
  }
  return false;
}
void Client::sync(){
  string message= "sync "+_name;
  message=send_message(message);
  std::vector<string> v;
  istringstream iss(message);
  while(getline(iss, message)){
    if(message=="")
      continue;
    v=parse_input(message);
    check_book(v);
    check_season(v);
  }
  return;
}
void Client::check_book(vector<string>v){
  for (int i = 0; i < _going_to_write.size(); i++) {
      if(s_to_i(v[1])==_going_to_write[i]->id())
        if(v[0] == _going_to_write[i]->name())
          return;
        else{
          cerr<<"change title"<<endl;
          _going_to_write[i]->change_title(v[0]);
          return;
        }
  }
  _going_to_write.push_back(new Book(v[0], s_to_i(v[1])));
  return;
}
void Client::check_season(std::vector<string> v){
  std::vector<string> s;
  int size1, size2;
  size2=v.size()-2;
  for (int i = 0; i < _going_to_write.size(); i++) {
    if(_going_to_write[i]->name()==v[0]){
      s=_going_to_write[i]->seasons_list();
      size1=s.size();
      if(size1>=size2){
        return;
      }
      else{
        for (int j = 2; j < v.size(); j++) {
            if(_going_to_write[i]->check_season_availibility(v[j]))
              _going_to_write[i]->push_season(new Season(v[j]), j-1);
        }
        return;
      }
    }
  }

}
bool Client::approve_request(string book){
  if(_name==ADMIN_USER && _password==ADMIN_PASS){
    string message="approve_request "+book;
    message=send_message(message);
    if(message=="successful")
      return true;
  }
  return false;
}
vector<string> Client::show_requests(){
  std::vector<string> v;
  string message="show_requests";
  message=send_message(message);
  v = parse_input(message);
  return v;
}
vector<string> Client::get_books_writting(){
    vector<string> books;
    for(int i=0; i<_going_to_write.size(); i++)
        books.push_back(_going_to_write[i]->name());
    return books;
}
