#ifndef _UI_H
#define _UI_H

#include "Client.h"
#include "Machine.h"
#include "methods.h"

class UI {

public:
  UI(Client *_u1);
  ~UI();
  void set_machine(Machine *m) { m1 = m; };
  void get_order();
  void start();
  bool process_login(const std::vector<std::string> &tokens);
  bool register_user(const std::vector<std::string> &tokens);
  void show_content(std::vector<std::string> tokens);

private:
  Client *u1;
  Machine *m1;

private:
  void send_version();
  void change_writer();
  void back_to_version();
  void change_book_title();
  void new_book();
  void edit();
  void signup();
  void finalize();
  void new_season();
  void publish_book();
  void latest_version();
  void show_seasons_list();
  void changes_to_version();
  void show_season_content();
  void show_requests();
  void approve_request();
  bool login(std::vector<std::string> tokens);
  void get_infos(std::string &book, std::string &season);
  void load_backup_if_necessary(std::string book, std::string season);
};

#endif
