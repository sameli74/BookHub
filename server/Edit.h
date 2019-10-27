#ifndef EDIT_H_
#define EDIT_H_

class Edit {
private:
  std::string title;
  std::string primary_text;
  std::string new_text;
  int line_number;

public:
  Edit() {}
  Edit(std::string _title, int _line, std::string _primary_text,
       std::string _new_text);
  ~Edit();

public:
  void remove_line(int _line);
  void add_line(int _line, std::string new_text);
  void edit_line(int _line, std::string prev_text, std::string new_text);
  std::string get_info();
  std::string load_edit();
  void see_content(std::vector<std::string> &content);
  void get_text(std::vector<std::string> &text);
  std::string changes_to_version();
  void del();
};

class Edition {
private:
  std::string _book_name;
  std::string _season_name;
  std::vector<Edit *> edits;

public:
  Edition() {}
  Edition(std::string book_name, std::string season_name,
          std::vector<Edit *> _edit);
  Edition(std::vector<Edit *> _edit) { edits = _edit; }
  ~Edition();
  std::string book_name() { return _book_name; }
  std::string season_name() { return _season_name; }
  void push_edit(Edit *ed) { edits.push_back(ed); }
  int size() { return edits.size(); }
  std::string get_info();
  void get_text(std::vector<std::string> &text);
  std::string load_edition();
  void see_content(std::vector<std::string> &content);
  std::vector<std::string> changes_to_version();
  void del();
};

class Version {
private:
  std::string _book_name;
  std::string _season_name;
  Edition *edition;

public:
  Version(Edition *ed);
  Version(std::string book, std::string season, Edition *ed);
  ~Version();
  std::string book_name() { return _book_name; }
  std::string season_name() { return _season_name; }
  int size() { return edition->size(); }
  std::string get_info();
  void get_text(std::vector<std::string> &text);
  std::string load_version();
  void see_content(std::vector<std::string> &content);
  std::vector<std::string> changes_to_version();
  void del();
};

#endif
