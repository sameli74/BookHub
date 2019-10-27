#ifndef AVAILABLE_BOOKS_H_
#define AVAILABLE_BOOKS_H_

class Available_books{
private:
  std::string _addr;
  std::string _name;
  std::string content;
public:
  Available_books(std::string ad, std::string n, std::string _con): _name(n), _addr(ad), content(_con){}
  ~Available_books(){}
  std::string name(){ return _name; }
  std:: string addr(){ return _addr; }
};

#endif
