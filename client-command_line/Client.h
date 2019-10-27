#ifndef _USER_H
#define _USER_H

#include "Machine.h"
#include "client_socket.h"
#include "Book.h"
#include "methods.h"
#include "Visitor.h"

#define END -1

class Machine;
class Version;
class Book;
class Season;

class Client : public Visitor {

public:
  Client(ClientSocket* _s1);
  ~Client();
  void set_login(std::string name, std::string pass);
  std::string process_login(const std::vector<std::string> &tokens);
  std::string register_client(const std::vector<std::string> &tokens);
  bool create_book(std::string title, std::vector<std::string> writers);
  bool create_new_season(std::string book_name, std::string season_title,
                         int line = END);
  std::vector<std::string> get_data(std::string data_name, std::string _name);
  void set_machine(Machine *_m1);
  int add_book_to_server(std::string title, std::vector<std::string> writers);
  bool process_edit(std::ofstream &myfile2, std::vector<std::string> tokens,
                    std::string book_name, std::string season_name);
  bool write(std::string command, std::string _name, std::string season_name);
  bool receive_latest_version(std::string book_name, std::string season_name);
  bool send_version(std::string book_name, std::string season_name);
  std::string back_to_version(std::string book, std::string season, int num);
  std::string back_to_version_repository(std::string book, std::string season,
                                         int num);
  void get_latest_version(std::string book_name, std::string season_name);
  std::string change_book_title(std::string book, std::string new_title);
  std::string change_to_writers(std::string change, std::string book,
                         std::string writer_name);
  int version_number(std::string book, std::string season);
  void finalize_version(Version *v1, std::string book, std::string season);
  bool send_book(Version *v1, std::string book, std::string season);
  void del_ver(std::string book, std::string season, int num);
  std::vector<std::string> get_text(std::string book, std::string season,
                                    int number);
  std::string start_editing(std::vector<std::string> tokens, std::string book,
                            std::string season);
  std::string send_message(std::string message);
  std::vector<std::string> changes_to_version(std::string book,
                                              std::string season, int num);
  bool publish_book(std::string book);
  void sync();
  std::vector<std::string> show_requests();
  bool approve_request(std::string book);
  int get_version_number(std::string book_name, std::string season_name);
  std::vector<std::string> get_books_writting();

protected:
  // fields
  ClientSocket *s1;
  Machine *m1;

protected:
  // Methods
  bool send_version(std::string book, std::string season, std::string &text);
  bool check_if_final_version(std::string book, std::string season);
  bool send_versions(std::string book_name, std::string season_name);
  std::vector<Version *> process_versions(std::string answer, std::string book,
                                          std::string season);
  int find_book(std::string book_name, std::string season_name,
                std::string who_added);
  std::string load_backup(std::string book, std::string season);
  bool change_if_not_sent(std::string book, std::string title);
  bool change_writer_if_not_sent(std::string change, std::string book,
                                 std::string writer_name_to_change);
  void decode_server_response(std::string answer, std::string book_name,
                              std::string season_name);
  bool write_to_disk(std::string &text, std::string &_path);
  bool write_to_disk(std::vector<std::string> &text, std::string &_path);
  bool write_w(std::string text, std::string addr);
  void check_book(std::vector<std::string> v);
  void check_season(std::vector<std::string> v);
};

#endif
