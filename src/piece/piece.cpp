#include "headers/piece.h"

Piece::Piece(const Piecetype& type):
              m_type(type),
              black(utils::check::is_black_piece(type)) {
}

Piece::~Piece() {}

Piecetype Piece::get_type_and_color() { return m_type; }

bool Piece::is_black() { 
  return black; 
}

