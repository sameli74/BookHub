#ifndef _BOOK_H
#define _BOOK_H

#include "Edit.h"
#include "methods.h"

#define LAST_SEASON -1

class Season;
class Version;
class Client;

class Book {
private:
  int _id;
  std::vector<Season *> seasons;
  std::vector<std::string> writers;
  std::string title;
  std::string creator;
  bool _access;

public:
  Book(std::string _title, std::vector<std::string> writers,
       std::string _creator, int iid);
  Book(std::string _title, int iid): title(_title), _id(iid), _access(false){}
  ~Book();
  std::vector<std::string> seasons_list();
  std::string name() { return title; }
  int id(){ return _id; }
  bool access(){ return _access; }
  void grant_access(){ _access=true; }
  bool set_version(std::vector<Version *> versions, std::string season_name);
  int version_number(std::string season);
  bool check_season_availibility(std::string season);
  bool check_access(std::string _name);
  std::string get_creator() { return creator; };
  void change_title(std::string name, std::string ti);
  void change_title(std::string ti);
  void change_writer(std::string change, std::string writer_name_to_change);
  void send_versions_from(int num, std::string &message, std::string season);
  void del_ver(std::string season, int num);
  void push_season(Season *s1, int place = (int)LAST_SEASON);
  void push_version(Version *v1, std::string season);
  void edit_name();
  void edit_writers();
  void insert_book(int pos);
  std::string get_html();
  std::vector<std::string> get_text(std::string season, int num);
  std::vector<std::string> see_content(int num, std::string season);
  std::vector<std::string> changes_to_version(std::string season, int num);
};

class Season {
private:
  std::string _name;
  std::vector<Version *> versions;

public:
  Season(std::string name) { _name = name; }
  ~Season();
  std::string name() { return _name; }
  void push_version(Version *v1) { versions.push_back(v1); }
  void set_version(std::vector<Version *> _version) { versions = _version; }
  int version_number() { return versions.size(); };
  void send_versions_from(int num, std::string &message);
  void del_ver(int num);
  std::vector<std::string> get_text(int number);
  std::vector<std::string> see_content(int num);
  std::vector<std::string> changes_to_version(int num);
};

#endif
