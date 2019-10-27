#ifndef VISITOR_H_
#define VISITOR_H_

#include "Book.h"

class Visitor {
protected:
  std::string _name;
  std::string _password;
  std::vector<Book *> _completed;
  std::vector<Book *> _going_to_write;
  std::vector<Book *> _created;

public:
  Visitor(std::string name, std::string password)
      : _name(name), _password(password) {}
  Visitor() {}
  virtual ~Visitor() = 0;
  std::string name() { return _name; }
  std::string password() { return _password; }
  bool change_title(std::string book, std::string title);
  bool change_writer(std::string change, std::string book,
                     std::string writer_name_to_change);
  std::vector<std::string> see_content(int number_of_versions, std::string book,
                                       std::string season);
  std::vector<std::string> seasons_list(std::string book);
};

#endif
