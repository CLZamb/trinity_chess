#ifndef KEYBOARD_BASE_H
#define KEYBOARD_BASE_H

#include "input/headers/input_event.h"
#include "input/headers/key_reader.h"
#include <termios.h>
#include <unistd.h>
#include <string>

using std::string;

class KeyboardBase {
 public:
  InputKeys::Key read_key();
  InputKeys::Key read_arrow_key();

 protected:
  void set_terminal_new_attributes();
  void restore_terminal_configuration();
  KeyReader m_k_reader;
 private:
  static struct termios old, current;
  static string hide_cursor, show_cursor;
};

#endif /* KEYBOARD_BASE_H */
