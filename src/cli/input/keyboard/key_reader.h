#ifndef ARROW_KEY_READER_H
#define ARROW_KEY_READER_H

#include "ASCII_character_enconding.h"

class KeyReader {
public:
  KeyReader () {}
  virtual ~KeyReader () {}
  ASCIICharEncoding read_key();
  ASCIICharEncoding read_arrow_key();
};

#endif /* ARROW_KEY_READER_H */
