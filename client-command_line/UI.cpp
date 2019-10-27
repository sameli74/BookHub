#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

#include "UI.h"

#define LOGIN "login"
#define SIGNUP "signup"
#define ALL -1;

class INVALID_USER {};
class SERVER_ERROR {};
class INVALID_BOOK;
class INVALID_SEASON_NAME {};
class INVALID_WRITER_NAME {};
class ACCESS_VIOLATION;
class ALLOCATION_ERROR;
class INTERNAL_ERROR;
class MACHINE_ERROR;
class INVALID_ARGUMENT_EX {};

void UI::start() {
  string input;
  cout  <<endl;
  cout << "**********" << endl;
  cout << " Options: " << endl;
  cout << "**********" <<endl << endl;
  cout << "1. signup" <<endl;
  cout << "2. login [username] [password]" << endl;
  cout << "Order: ";
  while (getline(cin, input)) {
    vector<string> tokens;
    string order;
    istringstream iss(input);
    iss >> order;
    try {
      if (order == LOGIN) {
        copy(istream_iterator<string>(iss), istream_iterator<string>(),
             back_inserter(tokens));
        if (login(tokens))
          break;
      } else if (order == SIGNUP)
        signup();
    } catch (...) {
      cout << "something went wrong. try again" << endl;
    }
  }
  get_order();
}
bool UI::process_login(const std::vector<std::string> &tokens) {
  string message = u1->process_login(tokens);
  if (message == "successful")
    return true;
  else if (message == "unsuccessful")
    return false;
}
bool UI::register_user(const std::vector<std::string> &tokens) {
  string message;
  message = u1->register_client(tokens);
  if (message == "register_successful")
    return true;
  else if (message == "register_failed")
    return false;
  else if (message == "server_error")
    throw SERVER_ERROR();
}
void UI::edit() {
  string book;
  string season;
  vector<string> tokens;
  cout << "Book name: ";
  getline(cin, book);
  cout << "season_name: ";
  getline(cin, season);
  try {
    string input2;
    cout << endl << "**********";
    cout << endl << " Options: ";
    cout << endl << "**********";
    cout << endl << "1. quit";
    cout << endl << "2. see_content";
    cout << endl << "3. [add/remove/change]";
    cout << endl << "4. finalize_edit"<<endl<<"order: ";
    while (getline(cin, input2)) {
      if (input2 == "")
        continue;
      tokens = parse_input(input2);
      if (tokens[0] == "quit")
        break;
      else if (tokens[0] == "add" || tokens[0] == "remove" || tokens[0] == "change") {
        vector<string> token;
        token.push_back(tokens[0]);
        string temp;

        cout << endl<< " [line number]: ";
        getline(cin, temp);
        token.push_back(temp);

        if(tokens[0]=="change"){
          cout << endl << "[primary_text]: ";
          getline(cin, temp);
          token.push_back(temp);
        }

        if(tokens[0]!="remove"){
          cout << endl<< "[new_text]: ";
          getline(cin, temp);
          token.push_back(temp);
        }
        input2 = u1->start_editing(token, book, season);
        if (input2 == "successful")
          cout << "done." << endl;
        else if (input2 == "unsuccessful")
          cout << "coul'nt add changes." << endl;
        else if (input2 == "input_error")
          cout << "invalid input format" << endl;
      }
      else if (tokens[0] == "see_content") {
        if (tokens.size() < 3)
          continue;
        show_content(tokens);
      }
      else if (tokens[0] == "finalize_edit")
        finalize();
      cout << endl << "**********";
      cout << endl << " Options: ";
      cout << endl << "**********";
      cout << endl << "1. quit";
      cout << endl << "2. see_content";
      cout << endl << "3. [add/remove/change]";
      cout << endl << "4. finalize_edit"<<endl<<"order: ";
    }
  } catch (MACHINE_ERROR ex()) {
    cout << "something went wrong..." << endl << "please try again." << endl;
  } catch (INTERNAL_ERROR ex()) {
    cout << "error on saving backup" << endl;
  }
}
void UI::finalize() {
  string book;
  string season;
  cout << "book name: ";
  cin >> book;
  cout << " season name: ";
  cin >> season;
  try {
    m1->finalize(book, season);
    cout<<endl<<"done";
  } catch (MACHINE_ERROR ex()) {
    cout << "couldn't finalize requested edition" << endl;
  }
}
// void UI::load_backup_if_necessary(string book, string season){
//   if(!m1->edits_availability(book, season)){
//     input2=u1->load_backup(book, season);
//     if(input2=="successful")
//       cout<<"Backup was loaded successfully"<<endl;
//     else if(input2=="no_backup")
//       cout<<"No backup is available"<<endl;
//     }
// }
void UI::new_season() {
  string book, season;
  string temp;
  int num;
  cout << "Book name: ";
  getline(cin, book);
  cout << "season name: ";
  getline(cin, season);
  cout << "seasons place(place -1 if not important): ";
  getline(cin, temp);
  num = s_to_i(temp);
  if (num > 0){
    if (u1->create_new_season(book, season, num)){
      cout << "Season added successfully to the requested place" << endl;}
    else
      cout << "Adding Season Failed" << endl;
  }
  else if (u1->create_new_season(book, season))
    cout << "Season Added successfully" << endl;
  else
    cout << "Adding Season Failed" << endl;
}
void UI::latest_version() {
  try {
    cout << "book name: ";
    string book_namee;
    while (book_namee == "")
      getline(cin, book_namee);
    cout << "Season name: ";
    string season_namee;
    while (season_namee == "")
      getline(cin, season_namee);
    if(u1->receive_latest_version(book_namee, season_namee))
      cout<<"Versions have been updated"<<endl;
    else
      cout<<"Updating versions have been unsuccessful"<<endl;
  } catch (ALLOCATION_ERROR ex()) {
    cout << "version download error.try again" << endl;
  }
}
bool UI::login(vector<string> tokens) {
  try {
    if (process_login(tokens)) {
      cout << "Login was successful." << endl << "order: ";
      return true;
    } else {
      cout << "Login was not successful" << endl;
      return false;
    }
  } catch (SERVER_ERROR ex()) {
    cout << endl << "Server error";
    cout << endl << "please try again";
  }
}
void UI::signup() {
  vector<string> tokens;
  string input;
  cout << "please enter your name and password: ";
  getline(cin, input);
  tokens = parse_input(input);
  try {
    if (register_user(tokens)) {

      cout << "Signup was successful";
      cout << endl << "now you can login" << endl;
      return;
    } else {
      cout << endl << "sorry, you have already registered to this site" << endl;
      return;
    }
  } catch (SERVER_ERROR ex()) {
    cout << endl << "///////////////";
    cout << endl << "something went wrong.";
    cout << endl << "///////////////";
    cout << endl << "try again";
  }
  return;
}
void UI::change_book_title() {
  string book;
  string new_title;
  cout << "book name: ";
  getline(cin, book);
  cout << "new title: ";
  getline(cin, new_title);
  try {
    if(u1->change_book_title(book, new_title)=="successful")
      cout << "book name changed successfully" << endl;
    else
      cout << endl << "could\'nt done.";
  } catch (ACCESS_VIOLATION ex()) {
    cout << endl << "////////////////////////////////";
    cout << endl << "you can't change this book title";
    cout << endl << "////////////////////////////////" << endl;
  }
}
void UI::change_writer() {
  string change;
  string book;
  string writer;
  cout << endl << "desired change (add/remove): ";
  getline(cin, change);
  cout << endl << "book name: ";
  getline(cin, book);
  cout << " writer name: ";
  getline(cin, writer);
  try {
    u1->change_to_writers(change, book, writer);
    cout << "successful" << endl;
  } catch (INVALID_WRITER_NAME ex()) {
    cout << "writer name is not true" << endl;
  } catch (ACCESS_VIOLATION ex()) {
    cout << " you don't have permisin to do that";
  }
}
void UI::send_version() {
  string book, season;
  string message;
  get_infos(book, season);

  if (m1->send_book(book, season))
    cout << "seccessfully done" << endl;
  else
    cout << "something wrong. try again" << endl;
}
void UI::back_to_version() {
  string book, season;
  int number;
  string message;
  get_infos(book, season);
  cout << "version_number: ";
  cin >> number;
  cout << endl << u1->version_number(book, season) << endl;
  if (number < 0 || number > u1->version_number(book, season))
    cout << "invalid input" << endl;
  else {
    message=u1->back_to_version(book, season, number);
    if (message == "successful")
      cout << "done." << endl;
    else if(message=="access_denied")
      cout<< "Administrative permision is required"<<endl;
    else
      cout << "could'nt back to version" << endl;
  }
}
void UI::new_book() {
  string book;
  cout << "Book name: ";
  getline(cin, book);
  cout << "writers name: ";
  string in;
  getline(cin, in);
  vector<string> data;
  data = parse_input(in);
  if (u1->create_book(book, data))
    cout << "Book has been registered" << endl;
  else
    cout << "Something went wrong.try again" << endl;
}
void UI::show_season_content() {
  string book, season;
  int number;
  get_infos(book, season);
  cout << "Version number: (enter 0 for all versions)" << endl;
  ;
  cin >> number;
  if (number < 0 || number > u1->version_number(book, season))
    throw INVALID_ARGUMENT_EX();
  cout << "*****************" << endl;
  cout << " Season Content: " << endl;
  cout << "*****************" << endl;
  print_content(u1->get_text(book, season, number));
}
void UI::show_seasons_list() {
  string book;
  vector<string> list;
  cout << "book name: " << endl;
  getline(cin, book);
  list = u1->seasons_list(book);
  cout << "***************" << endl;
  cout << " Seasons List: " << endl;
  cout << "***************" << endl;
  print_content(list);
}
void UI::get_order() {
  cout<<endl<<endl;
  cout << "**********" << endl;
  cout << " Options: " << endl;
  cout << "**********" << endl;
  if(u1->name()=="Admin"){
  cout << endl;
  cout << "0.show_requests";
  cout << endl<<"grant";
  }
  cout << endl;
  cout << "1. new_book";
  cout << endl << "2. new_season";
  cout << endl << "3. seasons_list";
  cout << endl << "4. show_season_content";
  cout << endl << "5. change_book_title";
  cout << endl << "6. change_writer";
  cout << endl << "7. edit";
  cout << endl << "8. latest_version";
  cout << endl << "9. send_version";
  cout << endl << "10. back_to_version";
  cout << endl << "11. changes to version";
  cout << endl << "12. publish_book";
  cout << endl << "13. exit" << endl;
  cout << "Order: ";
  string input;
  vector<string> tokens;
  while (getline(cin, input)) {
    if (input == "")
      continue; /// to avoid core dump
    try {
      u1->sync();
      tokens = parse_input(input);
      if (tokens[0] == "edit")
        edit();
      else if (tokens[0] == "new_book")
        new_book();
      else if (tokens[0] == "new_season")
        new_season();
      else if (tokens[0] == "show_season_content")
        show_season_content();
      else if (tokens[0] == "seasons_list")
        show_seasons_list();
      else if (tokens[0] == "latest_version")
        latest_version();
      else if (tokens[0] == "change_book_title")
        change_book_title();
      else if (tokens[0] == "change_writer")
        change_writer();
      else if (tokens[0] == "send_version")
        send_version();
      else if (tokens[0] == "back_to_version")
        back_to_version();
      else if (tokens[0] == "changes_to_version")
        changes_to_version();
      else if ( tokens[0] == "publish_book")
        publish_book();
      else if(tokens[0] == "show_requests"){
        if(u1->name()=="Admin")
          show_requests();
        }
      else if(tokens[0] == "grant"){
        if(u1->name()=="Admin")
          approve_request();
      }
      else if ("exit")
        return;
    } catch (INVALID_ARGUMENT_EX ex()) {
      cout << "Input is not valid" << endl;
    } catch (...) {
      cout << "Something went wrong. Try again please. " << endl;
    }
  }
}
UI::~UI() {
  delete u1;
  delete m1;
}
UI::UI(Client *_u1) { u1 = _u1; }
void UI::show_content(vector<string> tokens) {
  vector<string> content;
  content = m1->see_content(tokens[1], tokens[2]);
  cout << endl << endl << "*************" << endl;
  cout << "TEXT CONTENT: " << endl;
  cout << "*************" << endl;
  print_content(content);
  cout << endl << endl;
}
void UI::get_infos(string &book, string &season) {
  cout << "book name: " << endl;
  getline(cin, book);
  cout << "Season name: " << endl;
  getline(cin, season);
}
void UI::changes_to_version() {
  string book, season;
  int num;
  vector<string> out;
  get_infos(book, season);
  cout << "Enter Version number: " << endl;
  cin >> num;
  try {
    out = u1->changes_to_version(book, season, num);
  } catch (INVALID_ARGUMENT_EX ex()) {
    cout << "Invalid argument. try again please." << endl;
  }
  cout << "********************" << endl;
  cout << " CHANGES TO VERSION: " << endl;
  cout << "********************" << endl;
  print_content(out);
}
void UI::publish_book(){
  string book;
  cout << "book name: "<<endl;
  getline(cin, book);
  if(u1->publish_book(book))
    cout << "done." << endl;
  else
    cout << "coul'nt publish the book" << endl;
}
void UI::show_requests(){
  std::vector<string> v;
  v=u1->show_requests();
  print_content(v);
}
void UI::approve_request(){
  string book;
  cout <<"book name: ";
  getline(cin, book);
  if(u1->approve_request(book))
    cout << "done" << endl;
  else
    cout << "Could'nt complete the request" << endl;
}
