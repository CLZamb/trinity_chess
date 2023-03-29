#include "Idisplay.h"

Displayable::Displayable(size_t size /* = 44 */) : m_pane(size) {}

const string& Displayable::operator[](size_t i) {
  return m_pane[i];
}

size_t Displayable::size() {
  return m_pane.size();
}
