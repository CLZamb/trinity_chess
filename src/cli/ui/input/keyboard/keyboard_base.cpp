#include "keyboard_base.h"
#include <unistd.h>
#include <stdlib.h>
// #include <termios.h>

termios KeyboardBase::old;
termios KeyboardBase::current;

string KeyboardBase::hide_cursor  = "\x1b[?25l";
string KeyboardBase::show_cursor  = "\x1b[?25h";

KeyboardBase::KeyboardBase() {
  set_terminal_new_attributes();
}

KeyboardBase::~KeyboardBase() {
  restore_terminal_configuration();
}

void KeyboardBase::set_terminal_new_attributes() {
  write(STDOUT_FILENO, hide_cursor.c_str(), 6);

  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= static_cast<unsigned int>(~(ECHO | ICANON));
  tcsetattr(STDIN_FILENO, TCSANOW, &current);
}

void KeyboardBase::restore_terminal_configuration() {
  tcsetattr(STDIN_FILENO, TCSANOW, &old); 

  write(STDOUT_FILENO, show_cursor.c_str(), 6);
}

Keyboard::Key KeyboardBase::read_key() { 
  Keyboard::Key key = m_k_reader.read_key();

  switch(key) {
    case Keyboard::quit:
    case Keyboard::Quit:
      quit_game();
      break;
    default: break;
  }

  return key; 
}

Keyboard::Key KeyboardBase::read_arrow_key() {
  return m_k_reader.read_arrow_key();
}

void KeyboardBase::quit_game() {
  restore_terminal_configuration();
  exit(EXIT_SUCCESS);
}

const string KeyboardBase::key_not_supported = "key not supported\n";
