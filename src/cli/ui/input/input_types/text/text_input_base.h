#ifndef TEXT_INPUT_BASE_H
#define TEXT_INPUT_BASE_H

#include <string>
#include <iostream>

using std::string;

class TextInputBase {
 public:
  int get_integer_input();
  string get_string_input();
  TextInputBase();
  virtual ~TextInputBase();

 protected:
  static const string input_space;
 private:
  void has_player_quit(const string &s);
};

#endif /* TEXT_INPUT_BASE_H */
