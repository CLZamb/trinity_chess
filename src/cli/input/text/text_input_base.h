#ifndef TEXT_INPUT_BASE_H
#define TEXT_INPUT_BASE_H

#include <string>
#include <iostream>

class TextInputBase {
 public:
  int get_integer_input();
  std::string get_string_input();
  TextInputBase();
  virtual ~TextInputBase();

 private:
  static const std::string input_space;
  void has_player_quit(const std::string &s);
};

#endif /* TEXT_INPUT_BASE_H */
