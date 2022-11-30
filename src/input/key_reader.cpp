#include "input/headers/key_reader.h"

InputKeys::Key KeyReader::read_key() {
  InputKeys::Key key = InputKeys::NONE;
  key = InputKeys::Key(fgetc(stdin));
  return key;
}

InputKeys::Key KeyReader::read_arrow_key() {
  if (fgetc(stdin) != InputKeys::LEFT_BRACKET) return InputKeys::Quit;

  InputKeys::Key key_pressed = InputKeys::Key(fgetc(stdin));
  return key_pressed;
}

