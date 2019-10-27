#ifndef AVAILABLE_BOOKS_H_
#define AVAILABLE_BOOKS_H_

class Available_books{
private:
  std::string _addr;
  std::string _name;
public:
  Available_books(std::string ad, std::string n): _name(n), _addr(ad){}
  ~Available_books(){}
  std::string name(){ return _name; }
  std:: string addr(){ return _addr; }
};

#endif
