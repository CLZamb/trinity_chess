#include "headers/piece.h"

Piece::Piece(const Piecetype &type) : 
  m_type(type) {}

Piece::~Piece() {}

Piecetype Piece::get_type_and_color() { return m_type; }
