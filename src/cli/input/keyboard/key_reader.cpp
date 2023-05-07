#include "key_reader.h"

#include <cstdio>

ASCIICharEncoding KeyReader::read_key() {
  ASCIICharEncoding key =
      static_cast<ASCIICharEncoding>(fgetc(stdin));
  return key;
}

ASCIICharEncoding KeyReader::read_arrow_key() {
  if (static_cast<ASCIICharEncoding>(fgetc(stdin)) !=
      ASCIICharEncoding::LEFT_BRACKET) {
    return ASCIICharEncoding::Q;
  }

  ASCIICharEncoding key_pressed =
      static_cast<ASCIICharEncoding>(fgetc(stdin));
  return key_pressed;
}
