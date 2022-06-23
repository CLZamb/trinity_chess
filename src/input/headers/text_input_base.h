#ifndef TEXT_INPUT_BASE_H
#define TEXT_INPUT_BASE_H

#include <string>
#include <iostream>

using std::string;

class TextInputBase {
 public:
  TextInputBase();
  virtual ~TextInputBase();

  int get_integer_input();
  string get_string_input();

  static const string input_space;
  static const string invalid_option_msg;
 private:
  void has_player_quit(const string &s);
};

#endif /* TEXT_INPUT_BASE_H */
