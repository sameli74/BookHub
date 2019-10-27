#include <vector>
#include <string>
#include <iostream>

#include "user_on_server.h"

using namespace std;

class ACCESS_VIOLATION {};

User::~User() {

}
void User::push_book(Book *b1, string position) {
  if (position == "writting")
    _going_to_write.push_back(b1);
  else if (position == "created")
    _created.push_back(b1);
  cerr<<_going_to_write.size()<<" "<<_created.size()<<endl;
  cerr<<_name<<endl;
}
bool User::push_new_season(Season *s1, string book, string season, int place) {
  for (int i = 0; i < _going_to_write.size(); i++) {
    if (_going_to_write[i]->name() == book)
      if (_going_to_write[i]->check_season_availibility(season)) {
        _going_to_write[i]->push_season(s1, place);
        return true;
      }
  }
  for (int i = 0; i < _created.size(); i++) {
    if (_created[i]->name() == book)
      if (_created[i]->check_season_availibility(
              season)) { /// to prevent repeated_season
        _created[i]->push_season(s1);
        return true;
      }
  }
  return false;
}
int User::version_number(string book, string season) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book)
      return _going_to_write[i]->version_number(season);
}
void User::send_versions_from(int num, std::string &message, std::string book,
                              std::string season) {
  cerr<<"5"<<endl;
  for (int i = 0; i < _going_to_write.size(); i++) {
    if (_going_to_write[i]->name() == book){
      cerr<<"6"<<endl;
      _going_to_write[i]->send_versions_from(num, message, season);
      cerr<<"7"<<endl;
    }
  }
}
int User::get_version_number(string book, string season) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book)
      return _going_to_write[i]->version_number(season);
}
bool User::check_access(string _name, std::string book, std::string job) {
  if (job == "writting")
    for (int i = 0; i < _going_to_write.size(); i++)
      if (_going_to_write[i]->name() == book)
        return _going_to_write[i]->check_access(_name);
      else if (job == "created")
        for (int i = 0; i < _created.size(); i++)
          if (_created[i]->name() == book)
            return _created[i]->check_access(_name);
}
void User::back_to_version(string book, string season, int num) {
  for (int i = 0; i < _created.size(); i++)
    if (_created[i]->name() == book) {
      _created[i]->del_ver(season, num);
      return;
    }
}
bool User::check_name(std::string name2) {
  if (_name == name2)
    return true;
  return false;
}
Book* User::get_book_created(std::string book) {
  for (int i = 0; i < _created.size(); i++) {
    if (_created[i]->name() == book)
      return _created[i];
  }
}
void User::push_version(Version *v1, std::string book, std::string season) {
  for (int i = 0; i < _going_to_write.size(); i++) {
    if (_going_to_write[i]->name() == book) {
      _going_to_write[i]->push_version(v1, season);
      return;
    }
  }
}
void User::erase_from_list_writting(string book){
  for (int i = 0; i < _going_to_write.size(); i++) {
    if(_going_to_write[i]->name()==book){
      _going_to_write.erase(_going_to_write.begin()+i);
      return;
    }
  }
}
void User::erase_from_list_created(string book){
  for (int i = 0; i < _created.size(); i++) {
    if(_created[i]->name()== book){
      //delete _created[i];
      _created.erase(_created.begin()+i);
      return;
    }
  }
}
string User::sync_books_info(){
  cerr<<"3"<<endl;
  std::vector<string> v;
  string message;
  for (int i = 0; i < _going_to_write.size(); i++) {
    cerr<<"4"<<endl;
    message=message+( i==0 ? "" : " ")+_going_to_write[i]->name()+" "+itos(_going_to_write[i]->id());
    cerr<<"4-1"<<endl;
    v =_going_to_write[i]->seasons_list();
    cerr<<v.size()<<endl;
    for (int j = 0; j < v.size(); j++) {
      cerr<<"5"<<endl;
      message=message+" "+v[j];
    }
    message+="\n";
  }
  cerr<<"6"<<endl;
  return message;
}
void User::pop_book(string book){
  for (int i = 0; i < _going_to_write.size(); i++) {
    if(_going_to_write[i]->name()==book){
      _going_to_write.erase(_going_to_write.begin()+i);
      return;
    }
  }
}
