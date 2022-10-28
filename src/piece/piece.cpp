#include "headers/piece.h"

Piece::Piece(const Piecetype &type) : 
  _m_type(type) {}

Piece::~Piece() {}

Piecetype Piece::get_piecetype() { return _m_type; }
