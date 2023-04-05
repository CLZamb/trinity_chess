#ifndef KEYBOARD_BASE_H
#define KEYBOARD_BASE_H

#include "input_keyboard_keys.h"
#include "key_reader.h"
#include <termios.h>
#include <unistd.h>
#include <string>

using std::string;

class KeyboardBase {
 public:
  InputKeyboardKeys::Key read_key();
  InputKeyboardKeys::Key read_arrow_key();

 protected:
  void set_terminal_new_attributes();
  void restore_terminal_configuration();
  KeyReader m_k_reader;
 private:
  static struct termios old, current;
  static string hide_cursor, show_cursor;
  static const string key_not_supported;
};

#endif /* KEYBOARD_BASE_H */
