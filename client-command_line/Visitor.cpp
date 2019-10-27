#include <vector>
#include <string>
#include <iostream>

#include "Visitor.h"
#include "methods.h"

class ACCESS_VIOLATION {};

using namespace std;

Visitor::~Visitor() {}
vector<string> Visitor::see_content(int number_of_versions, string book,
                                    string season) {
  for (int i = 0; i < _going_to_write.size(); i++) {
    if (_going_to_write[i]->name() == book) {
      return _going_to_write[i]->see_content(number_of_versions, season);
      break;
    }
  }
}
bool Visitor::change_title(string book, string title) {
  for (int i = 0; i < _created.size(); i++) {
    if (_created[i]->name() == book)
      if (_created[i]->get_creator() == _name) {
        _created[i]->change_title(_name, title);
        return true;
      } else
        throw ACCESS_VIOLATION();
  }
  return false;
}
bool Visitor::change_writer(string change, string book,
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
vector<string> Visitor::seasons_list(string book) {
  for (int i = 0; i < _going_to_write.size(); i++)
    if (_going_to_write[i]->name() == book)
      return _going_to_write[i]->seasons_list();
}
string Visitor::sync_books_info(){
  std::vector<string> v;
  string message;
  for (int i = 0; i < _going_to_write.size(); i++) {
    message=_going_to_write[i]->name()+" "+itos(_going_to_write[i]->id());
    v =_going_to_write[i]->seasons_list();
    for (int j = 0; j < v.size(); j++) {
      message=message+" "+v[j];
    }
  }
  return message;
}
