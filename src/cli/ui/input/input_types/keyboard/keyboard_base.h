#ifndef KEYBOARD_BASE_H
#define KEYBOARD_BASE_H

#include "key_reader.h"
#include <termios.h>
#include <unistd.h>
#include <string>

using std::string;

class KeyboardBase {
 public:
  Keyboard::Key read_key();
  Keyboard::Key read_arrow_key();

 protected:
  KeyboardBase();
  static void set_terminal_new_attributes();
  static void restore_terminal_configuration();
 private:
  void quit_game();
  KeyReader m_k_reader;
  static struct termios old, current;
  static string hide_cursor, show_cursor;
  static const string key_not_supported;
  static bool initialized;
};

#endif /* KEYBOARD_BASE_H */
