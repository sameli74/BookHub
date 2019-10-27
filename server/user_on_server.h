#ifndef USER_ON_SERVER_H_
#define USER_ON_SERVER_H_

#include "Visitor.h"
class User : public Visitor {
private:
  bool _access;
public:
  User(std::string name, std::string password) : Visitor(name, password),_access(false) {}
  ~User();
  bool access(){ return _access; }
  void grant_access(){ _access=true; }
  int version_number(std::string book, std::string season);
  bool check_name(std::string name2);
  bool check_password(std::string pass);
  bool check_access(std::string _name, std::string book, std::string job);
  int is_last_version(std::string book_name, std::string season_name);
  void push_writting_book(Book *b1) { _going_to_write.push_back(b1); }
  bool push_new_season(Season *s1, std::string book, std::string season,
                       int place);
  void send_versions_from(int num, std::string &message, std::string book,
                          std::string season);
  std::string get_user_books();
  void back_to_version(std::string book, std::string season, int num);
  int get_version_number(std::string book, std::string season);
  void push_book(Book *b1, std::string position);
  Book *get_book_created(std::string book);
  void push_version(Version *v1, std::string book, std::string season);
  void erase_from_list_writting(std::string book);
  void erase_from_list_created(std::string book);
  std::string sync_books_info();
  void pop_book(std::string book);
};

#endif
