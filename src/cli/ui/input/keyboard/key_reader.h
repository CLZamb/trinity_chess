#ifndef ARROW_KEY_READER_H
#define ARROW_KEY_READER_H

#include "input_event.h"
#include <cstdio>

class KeyReader {
public:
  KeyReader () {}
  virtual ~KeyReader () {}
  InputKeys::Key read_key();
  InputKeys::Key read_arrow_key();
};

#endif /* ARROW_KEY_READER_H */
