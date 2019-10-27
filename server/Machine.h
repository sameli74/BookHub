#ifndef _MACHINE_H
#define _MACHINE_H

#include "Client.h"
#include "Edit.h"

class Client;
class Book;
class Edition;
class Edit;
class Version;

class Machine{
private:
	std::vector< Edition* > edition;
	Client* u1;
	std::vector<Version*> versions;
public:
	Machine(Client* c);
	~Machine();
	void save_edits_ro_ram(std::vector<std::string> tokens, std::string book_name, std::string season_name);
	void load_text_edits(std::vector<std::string> line, std::string book, std::string season);
	std::string machine_send(std::string state, std::string book_name = "", std::string season_name = "");
	std::string get_info(std::string book_name = "", std::string season_name = "");
	bool check_edits_availability(std::string book, std::string season);
	void finalize(std::string book, std::string season);
	bool send_book(std::string book, std::string season);
	void get_text(std::vector<std::string>& text);
	std::vector<std::string> see_content(std::string book, std::string season);
};
#endif
