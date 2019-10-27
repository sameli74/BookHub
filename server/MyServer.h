#ifndef _MYSERVER_H
#define _MYSERVER_H

#include "Book.h"
#include "Edit.h"
#include "methods.h"
#include "user_on_server.h"
#include "available_books.h"
#include "server.h"

class Book;
class Season;
class User;


class MyServer : public Server{

public:

	MyServer(int port);
	~MyServer();
	//Network
	void on_standard_input(std::string line);
  void on_new_connection(int identifier);
  void on_new_message(int identifier, std::string message);
  void on_terminated_connection(int identifier);
	///local
	std::vector<std::string> send_data(std::string data_name, std::string _name);
	std::string create_new_season(std::string message);
	bool send_version_to_server(std::string response);
	std::string get_message(std::string message);

private:

	int id_generator;
	std::string address;
	std::vector<User *> users;
	std::vector< Available_books* > available_books;
	std::vector<std::string> requests;
	std::vector<Book *> books;

private:

	std::string validate_user(const std::vector<std::string> &user);
	void write_to_database_with_number(std::string _path,
                                     std::vector<std::string> records);
  std::string get_user_books(std::string name);
  std::string back_to_version(std::vector<std::string> data);
  void prepare_versions_from(int line, std::string &message, std::string _name,
                             std::string book, std::string season);
  int version_number(std::string _name, std::string book, std::string season);
  std::string change_title(std::vector<std::string> data);
  std::string change_writer(std::vector<std::string> data);
  bool push_new_season(Season *s1, std::string _name, std::string book,
                       std::string season, int place);
 void backup_new_season_creation(std::string book, std::string season);
 void backup_new_season_creation(std::string book, std::string season,
                                 int line);
 void check_access(std::string _name, std::string book_name,
                   std::string season_name);
 bool check_access_writer(std::string _name, std::string book_name,
                          std::string season_name);
 bool check_access_creator(std::string _name, std::string book_name,
                           std::string season_name);
 std::string get_new_versions(std::vector<std::string> data);
 std::string is_last_version(std::vector<std::string> data);
 std::vector<std::string> read_database(std::string data_name,
																				std::string _name);
 std::vector<std::string> read_path_database(std::string _name);
 void add_book_backup(std::vector<std::string> data);
 std::string add_book(std::vector<std::string> data);
 std::string register_client(const std::vector<std::string> &tokens);
 std::string process_login(const std::vector<std::string> &tokens);
 bool write_to_database(std::string &_name, std::string &path, int line);
 bool write_to_database(std::string &text, std::string &path);
 bool write_to_database(const std::vector<std::string> &tokens,
												std::string &path);
 void new_book(std::string title, std::vector<std::string> writers,
							 std::string creator, std::string name);
 void add_to_(std::vector<std::string> path, std::string title);
 bool add_to_(std::string &season_name, std::string &addr, int line);
 std::string load_latest_version(std::vector<std::string> data);
 std::string push_version(std::string message);
 std::string publish_book(std::string message);
 std::string sync(std::string message);
 std::string show_requests();
 std::string approve_request(std::string message);

};
#endif
