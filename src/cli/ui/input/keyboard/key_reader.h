#ifndef ARROW_KEY_READER_H
#define ARROW_KEY_READER_H

#include "keyboard_key.h"

class KeyReader {
public:
  KeyReader () {}
  virtual ~KeyReader () {}
  Keyboard::Key read_key();
  Keyboard::Key read_arrow_key();
};

#endif /* ARROW_KEY_READER_H */
