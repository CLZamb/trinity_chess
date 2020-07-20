#include "headers/Idisplay.h"

Displayable::Displayable(size_t size) : m_drawing(size) {}

const string& Displayable::operator[](int i) {
  return m_drawing[i];
}

int Displayable::size() {
  return m_drawing.size();
}
