#include "key_reader.h"
#include <cstdio>

Keyboard::Key KeyReader::read_key() {
  Keyboard::Key key = Keyboard::NONE;
  key = Keyboard::Key(fgetc(stdin));
  return key;
}

Keyboard::Key KeyReader::read_arrow_key() {
  if (fgetc(stdin) != Keyboard::LEFT_BRACKET) return Keyboard::Quit;

  Keyboard::Key key_pressed = Keyboard::Key(fgetc(stdin));
  return key_pressed;
}

