#ifndef KEYBOARD_BASE_H
#define KEYBOARD_BASE_H

#include "key_reader.h"
#include <termios.h>
#include <string>

class Keyboard {
 public:
  Keyboard();
  virtual ~Keyboard();
  ASCIICharEncoding read_key();
  ASCIICharEncoding read_arrow_key();

 protected:
  void quit_game();
  void set_terminal_new_attributes();
  void restore_terminal_configuration();
 private:
  void clear_standard_input();
  KeyReader m_k_reader;
  static struct termios old, current;
  static char hide_cursor[], show_cursor[];
  static const std::string key_not_supported;
};

#endif /* KEYBOARD_BASE_H */
