#ifndef ARROW_KEY_READER_H
#define ARROW_KEY_READER_H

#include "input_keyboard_keys.h"

class KeyReader {
public:
  KeyReader () {}
  virtual ~KeyReader () {}
  InputKeyboardKeys::Key read_key();
  InputKeyboardKeys::Key read_arrow_key();
};

#endif /* ARROW_KEY_READER_H */
