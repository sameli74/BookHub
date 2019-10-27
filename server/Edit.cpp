#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include "Edit.h"
#include "methods.h"

class ERROR_ON_EDIT;
class MACHINE_ERROR {};

Edit::Edit(std::string _title, int line, std::string _primary_text,
           std::string _new_text) {
  title = _title;
  primary_text = _primary_text;
  new_text = _new_text;
  if (line < 0)
    throw MACHINE_ERROR();
  line_number = line;
}
Edit::~Edit() {}
string Edit::get_info() {
  string text;
  string p1,n1;
  p1=replaced_space_with_under(primary_text);
  n1=replaced_space_with_under(new_text);
  text = title + " " + itos(line_number) + " " +
         (primary_text == "" ? "empty" : p1) + " " +
         (new_text == "" ? "empty" : n1) + "\n";
  return text;
}
std::string Edit::load_edit() {
  if (title == "change")
    return (string) "\n" + title + " " + itos(line_number) + " " +
           primary_text + " " + new_text;
  else if (title == "add")
    return (string) "\n" + title + " " + itos(line_number) + " " + "empty " +
           new_text;
  else if (title == "remove")
    return (string) "\n" + title + " " + itos(line_number) + " empty " +
           "empty";
}
void Edit::see_content(vector<string> &content) {
  if (title == "add")
    if (line_number + 1 > content.size()) {
      content.resize(line_number);
      content.push_back(new_text);
    } else
      content.insert(content.begin() + line_number, new_text);
  else if (title == "remove")
    if (line_number + 1 <= content.size())
      content.erase(content.begin() + line_number);
    else if (title == "change")
      if (line_number + 1 <= content.size())
        content[line_number] = new_text;
}

Edition::Edition(string book_name, string season_name, vector<Edit *> _edit) {
  _book_name = book_name;
  _season_name = season_name;
  edits = _edit;
}
Edition::~Edition() {
  for (int i = 0; i < edits.size(); i++) {
    delete edits[i];
  }
}
string Edition::get_info() {
  string text;
  for (int i = 0; i < edits.size(); i++)
    text += edits[i]->get_info();
  return text + "end";
}
std::string Edition::load_edition() {
  string message = (string) "new";
  cerr<<"11"<<endl;
  for (int i = 0; i < edits.size(); i++)
    message += edits[i]->load_edit();
  cerr<<"12"<<endl;
  return message;
}
void Edition::see_content(vector<string> &content) {
  for (int i = 0; i < edits.size(); i++) {
    edits[i]->see_content(content);
  }
}
void Edition::del() {
  for (int i = 0; i < edits.size(); i++) {
    // edits[i]->del();
  }
  delete this;
}

Version::Version(Edition *ed) { edition = ed; }
Version::Version(string book, string season, Edition *ed) {
  edition = ed;
  _book_name = book;
  _season_name = season;
}
Version::~Version() { delete edition; }
string Version::get_info() { return "new\n" + edition->get_info(); }
std::string Version::load_version() { return edition->load_edition(); }
void Version::del() {
  edition->del();
  delete edition;
}
void Version::see_content(vector<string> &content) {
  edition->see_content(content);
}
void Edit::del() { }

void Version::get_text(std::vector<std::string> &text) {
  edition->get_text(text);
}
void Edition::get_text(std::vector<std::string> &text) {
  for (int i = 0; i < edits.size(); i++) {
    edits[i]->get_text(text);
  }
}
void Edit::get_text(vector<string> &text) { see_content(text); }
vector<std::string> Version::changes_to_version() {
  return edition->changes_to_version();
}
vector<string> Edition::changes_to_version() {
  vector<string> content;
  for (int i = 0; i < edits.size(); i++) {
    content.push_back(edits[i]->changes_to_version());
  }
  return content;
}
string Edit::changes_to_version() {
  if (title == "add")
    return new_text + " " + "has been added to line " + itos(line_number) + ".";
  else if (title == "remove")
    return "line number " + itos(line_number) + " has been removed.";
  else if (title == "change")
    return primary_text + " " + "on line number " + itos(line_number) + " " +
           "changed to " + new_text;
}
