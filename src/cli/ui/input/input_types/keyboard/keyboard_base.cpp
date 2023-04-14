#include "keyboard_base.h"
#include <iostream>

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

bool KeyboardBase::initialized = false;

void KeyboardBase::set_terminal_new_attributes() {
  if (initialized) return;

  write(STDOUT_FILENO, hide_cursor.c_str(), 6);

  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= static_cast<unsigned int>(~(ECHO | ICANON));
  tcsetattr(STDIN_FILENO, TCSANOW, &current);

  initialized = true;
}

void KeyboardBase::restore_terminal_configuration() {
  if (!initialized) return;

  write(STDOUT_FILENO, show_cursor.c_str(), 6);
  tcsetattr(STDIN_FILENO, TCSANOW, &old); 

  initialized = false;
}

Keyboard::Key KeyboardBase::read_key() { 
  if (!initialized) quit_game();

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
  if (!initialized) quit_game();
  return m_k_reader.read_arrow_key();
}

void KeyboardBase::quit_game() {
  restore_terminal_configuration();
  exit(EXIT_SUCCESS);
}

const string KeyboardBase::key_not_supported = "key not supported\n";
