#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Machine.h"

class ERROR_ON_EDIT {};
class MACHINE_ERROR {};

vector<string> parse_input(string message);
string itos(int id);
int s_to_i(string num);
Edit *new_edit(vector<string> tokens);

string Machine::get_info(string book, string season) {
  string text;
  for (int i = 0; i < versions.size(); i++)
    if (versions[i]->book_name() == book, versions[i]->season_name() == season)
      return text += versions[i]->get_info();
}
string Machine::machine_send(string state, string book_name,
                             string season_name) {
  return get_info(book_name, season_name);
}
void Machine::load_text_edits(std::vector<string> line, string book,
                              string season) {
  vector<Edit *> edits;
  Edition *ed;
  for (int i = 0; i < line.size(); i++) {
    Edit *edit;
    std::vector<string> v1;
    v1 = parse_input(line[i]);
    if (v1[0] == "add")
      edit = new Edit("add", s_to_i(v1[1]), "", v1[2]);
    else if (v1[0] == "change")
      edit = new Edit("change", s_to_i(v1[1]), "", v1[2]);
    else if (v1[0] == "remove")
      edit = new Edit("remove", s_to_i(v1[1]), "", "");
    edits.push_back(edit);
  }
  ed = new Edition(book, season, edits);
  edition.push_back(ed);
}
bool Machine::check_edits_availability(string book, string season) {
  for (int i = 0; i < edition.size(); i++) {
    if (book == edition[i]->book_name() && season == edition[i]->season_name())
      return true;
  }
  return false;
}
void Machine::save_edits_ro_ram(vector<string> tokens, string book,
                                string season) {
  Edit *edit;
  edit = new_edit(tokens);
  if (edit == NULL)
    throw ERROR_ON_EDIT();
  for (int i = 0; i < edition.size(); i++) {
    if (edition[i]->book_name() == book, edition[i]->season_name() == season) {
      edition[i]->push_edit(edit);
      return;
    }
  }
  vector<Edit *> edits(1, edit);
  Edition *ed;
  ed = new Edition(book, season, edits);
  edition.push_back(ed);
  return;
}
void Machine::finalize(string book, string season) {
  for (int i = 0; i < edition.size(); i++)
    if (edition[i]->book_name() == book &&
        edition[i]->season_name() == season) {
      Version *v1;
      v1 = new Version(book, season, edition[i]);
      if (v1 == NULL)
        throw MACHINE_ERROR();
      versions.push_back(v1);
      edition.erase(edition.begin() + i);
      return;
    }
  throw MACHINE_ERROR();
}
bool Machine::send_book(string book, string season) {
  for (int i = 0; i < versions.size(); i++) {
    if (versions[i]->book_name() == book &&
        versions[i]->season_name() == season)
      if (u1->send_book(versions[i], book, season)) {
        versions.erase(versions.begin() + i);
        return true;
      } else
        break;
  }
  return false;
}
Machine::~Machine() {
  for (int i = 0; i < edition.size(); i++) {
    delete edition[i];
  }
  for (int i = 0; i < versions.size(); i++) {
    delete versions[i];
  }
}
Machine::Machine(Client *c) { u1 = c; }
vector<string> Machine::see_content(string book, string season) {
  vector<string> content;
  for (int i = 0; i < edition.size(); i++) {
    if (edition[i]->book_name() == book && edition[i]->season_name() == season)
      edition[i]->see_content(content);
  }
  return content;
}

Edit *new_edit(vector<string> tokens) {
  Edit *edit;
  if (tokens[0] == "add")
    edit = new Edit("add", s_to_i(tokens[1]), "", tokens[2]);
  else if (tokens[0] == "remove")
    edit = new Edit("remove", s_to_i(tokens[1]), "", "");
  else if (tokens[0] == "change")
    edit = new Edit("change", s_to_i(tokens[1]), tokens[2], tokens[3]);
  return edit;
}
