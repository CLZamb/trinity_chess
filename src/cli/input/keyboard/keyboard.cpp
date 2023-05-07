#include "keyboard.h"

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <limits>

#include "input/keyboard/ASCII_character_enconding.h"

termios Keyboard::old;
termios Keyboard::current;

char Keyboard::hide_cursor[] = "\x1b[?25l";
char Keyboard::show_cursor[] = "\x1b[?25h";

Keyboard::Keyboard() { set_terminal_new_attributes(); }

Keyboard::~Keyboard() { restore_terminal_configuration(); }

void Keyboard::set_terminal_new_attributes() {
  write(STDOUT_FILENO, hide_cursor, 6);

  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= static_cast<unsigned int>(~(ECHO | ICANON));
  tcflush(STDIN_FILENO, TCIFLUSH);
  tcsetattr(STDIN_FILENO, TCSANOW, &current);
}

void Keyboard::restore_terminal_configuration() {
  tcsetattr(STDIN_FILENO, TCSANOW, &old);

  write(STDOUT_FILENO, show_cursor, 6);
}

ASCIICharEncoding Keyboard::read_key() {
  ASCIICharEncoding encoding = m_k_reader.read_key();

  switch (encoding) {
    // check if is a escape sequence and read its value
    case ASCIICharEncoding::ESC:
      encoding = read_arrow_key();
      break;
    case ASCIICharEncoding::q:
    case ASCIICharEncoding::Q:
      quit_game();
      break;
    default:
      break;
  }

  return encoding;
}

ASCIICharEncoding Keyboard::read_arrow_key() {
  return m_k_reader.read_arrow_key();
}

void Keyboard::quit_game() {
  restore_terminal_configuration();
  exit(EXIT_SUCCESS);
}

const std::string Keyboard::key_not_supported = "key not supported\n";
