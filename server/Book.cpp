#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Book.h"

#define LAST_SEASON -1
#define ALL 0

class INVALID_BOOK {};
class ACCESS_VIOLATION {};
class INVALID_WRITER_NAME {};
class INVALID_SEASON_NAME {};
class INVALID_ARGUMENT_EX {};

Book::Book(string _title, vector<string> _writers, string _creator, int __id):_id(__id) {
  title = _title;
  if (_writers.size() == 0)
    throw INVALID_BOOK();
  else
    writers = _writers;
  creator = _creator;
  _access=false;
}
bool Book::set_version(vector<Version *> version, string _name) {
  for (int i = 0; i < seasons.size(); i++) {
    if (_name == seasons[i]->name()) {
      seasons[i]->set_version(version);
      return true;
    }
  }
  return false;
}
bool Book::check_season_availibility(string season) {
  for (int i = 0; i < seasons.size(); i++)
    if (seasons[i]->name() == season)
      return false;
  return true;
}
void Book::push_season(Season *s1, int place) {
  if (place >= 1) {
    seasons.insert(seasons.begin() + place - 1, s1);
  } else if (place == (int)LAST_SEASON) /// for better performance
    seasons.push_back(s1);
}
bool Book::check_access(string _name) {
  for (int i = 0; i < writers.size(); i++)
    if (writers[i] == _name) {
      return true;
    }
  return false;
}
void Book::change_title(string name, string ti) {
  if (creator == name) {
    title = ti;
    return;
  }
  throw ACCESS_VIOLATION();
}
void Book::change_title(string ti) {
  title = ti;
  return;
}

void Book::change_writer(string change, string writer_name_to_change) {
  int place = -1;
  if (change == "add")
    writers.push_back(writer_name_to_change);
  else if (change == "remove") {
    for (int i = 0; i < writers.size(); i++)
      if (writers[i] == writer_name_to_change) {
        place = i;
        break;
      }
    if (place == -1)
      throw INVALID_WRITER_NAME();
    writers.erase(writers.begin() + place);
  }
}
int Book::version_number(string season) {
  for (int i = 0; i < seasons.size(); i++) {
    if (seasons[i]->name() == season)
      return seasons[i]->version_number();
  }
  throw INVALID_SEASON_NAME();
}
void Book::send_versions_from(int num, string& message, string season) {
  for (int i = 0; i < seasons.size(); i++) {
    if (seasons[i]->name() == season){
      cerr<<"8"<<endl;
      seasons[i]->send_versions_from(num, message);
      cerr<<"9"<<endl;
      return;
    }
  }
  return;
}
void Season::send_versions_from(int num, string& message) {
  for (int i = num; i < versions.size(); i++) {
    cerr<<"10"<<endl;
    message = message + (string) "\n" + versions[i]->load_version();
    cerr<<"13"<<endl;
    cerr<<message<<endl;
    message = message + "\n" + "end";
  }
  return;
}
void Book::del_ver(string season, int num) {
  for (int i = 0; i < seasons.size(); i++)
    if (seasons[i]->name() == season) {
      seasons[i]->del_ver(num);
      return;
    }
}
void Season::del_ver(int num) {
  for (int i = num; i < versions.size(); i++) {
    delete versions[i];
    versions.erase(versions.begin() + i);
  }
}
void Book::push_version(Version *v1, string season) {
  for (int i = 0; i < seasons.size(); i++)
    if (seasons[i]->name() == season) {
      seasons[i]->push_version(v1);
      break;
    }
}
Book::~Book() {
  for (int i = 0; i < seasons.size(); i++) {
    delete seasons[i];
  }
}
Season::~Season() {
  for (int i = 0; i < versions.size(); i++) {
    delete versions[i];
  }
}
vector<string> Book::see_content(int num, string season) {
  for (int i = 0; i < seasons.size(); i++) {
    if (seasons[i]->name() == season) {
      return seasons[i]->see_content(num);
    }
  }
}
vector<string> Season::see_content(int num) {
  vector<string> content;
  for (int i = 0; i < (num <= versions.size() ? num : versions.size()); i++) {
    versions[i]->see_content(content);
  }
  return content;
}
vector<string> Book::get_text(string season, int number) {
  for (int i = 0; i < seasons.size(); i++) {
    if (seasons[i]->name() == season)
      return seasons[i]->get_text(number);
  }
}
vector<string> Season::get_text(int number) {
  if (number == 0)
    number = versions.size();
  vector<string> text;
  for (int i = 0; i < number; i++) {
    versions[i]->get_text(text);
  }
  return text;
}
vector<string> Book::seasons_list() {
  vector<string> seasons_list;
  for (int i = 0; i < seasons.size(); i++)
    seasons_list.push_back(seasons[i]->name());
  return seasons_list;
}
std::vector<std::string> Book::changes_to_version(std::string season, int num) {
  for (int i = 0; i < seasons.size(); i++) {
    if (seasons[i]->name() == season)
      return seasons[i]->changes_to_version(num);
  }
}
std::vector<std::string> Season::changes_to_version(int num) {
  if (num > versions.size())
    throw INVALID_ARGUMENT_EX();
  num--;
  return versions[num]->changes_to_version();
}

string Book::get_html(){
  string html;
  html="<link href=\"txtstyle.css\" rel=\"stylesheet\" type=\"text/css\" />";
  html=(string)"<h1>"+"Book Name: "+ title +(string)"</h1> ";
  html+="\n<body> ";
  for (int i = 0; i < seasons.size(); i++) {
    vector<string> content;
    html=html+"\n<h4>"+" Season name: "+ seasons[i]->name() +(string)" </h4>";
    content=seasons[i]->get_text(0);
    for (int j = 0; j < content.size(); j++) {
      html=html+"\n<p1>"+ content[j]+"</p1>";
    }
  }
  html+=(string)"\n</body>\n</html>";
  return html ;
}
