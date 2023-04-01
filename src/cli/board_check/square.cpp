#include "square.h"

Square::Square() {}
Square::~Square() {}

void Square::set_piece(Piecetype pt) {
  this->m_piece = pt;
}

void Square::clear_square() {
  this->m_piece = EMPTY;
}

Piecetype& Square::get_piece() {
  return m_piece;
}
