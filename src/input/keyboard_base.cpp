#include "headers/keyboard_base.h"

termios KeyboardBase::old;
termios KeyboardBase::current;

string KeyboardBase::hide_cursor  = "\x1b[?25l";
string KeyboardBase::show_cursor  = "\x1b[?25h";

void KeyboardBase::set_terminal_new_attributes() {
  write(STDOUT_FILENO, hide_cursor.c_str(), 6);

  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &current);
}

void KeyboardBase::restore_terminal_configuration() {
  write(STDOUT_FILENO, show_cursor.c_str(), 6);
  tcsetattr(STDIN_FILENO, TCSANOW, &old); 
}

InputKeys::Key KeyboardBase::read_key() { 
  InputKeys::Key key = m_k_reader.read_key();
  switch(key) {
    case InputKeys::quit:
    case InputKeys::Quit:
      restore_terminal_configuration();
      exit(EXIT_SUCCESS);
      break;
    default:
      break;
  }

  return key; 
}

InputKeys::Key KeyboardBase::read_arrow_key() {
  return m_k_reader.read_arrow_key();
}

