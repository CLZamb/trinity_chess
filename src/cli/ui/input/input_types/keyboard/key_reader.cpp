#include "key_reader.h"
#include <cstdio>
// #include <termios.h>

InputKeyboardKeys::Key KeyReader::read_key() {
  InputKeyboardKeys::Key key = InputKeyboardKeys::NONE;
  key = InputKeyboardKeys::Key(fgetc(stdin));
  return key;
}

InputKeyboardKeys::Key KeyReader::read_arrow_key() {
  if (fgetc(stdin) != InputKeyboardKeys::LEFT_BRACKET) return InputKeyboardKeys::Quit;

  InputKeyboardKeys::Key key_pressed = InputKeyboardKeys::Key(fgetc(stdin));
  return key_pressed;
}

