#include "headers/piece.h"

Piece::Piece(const Piecetype &type) : 
  _m_type(type) {}

Piece::~Piece() {}

Piecetype Piece::get_type_and_color() { return _m_type; }

bool Piece::is_piece_in_same_side(const Piecetype captured) {
    return utils::check::get_color_piece(captured) ==
           utils::check::get_color_piece(_m_type);
}
