#include "headers/en_passant.h"

EnPassant::EnPassant() {}
EnPassant::~EnPassant() {}

bool EnPassant::is_en_passant_move(const Move& m) {
  SquareIndices to = Move_Utils::get_to(m);
  Piecetype piece = Move_Utils::get_piece(m);
  return is_pawn_piece(piece) && (to == en_passant_pos);
}

void EnPassant::set_en_passant_position(const SquareIndices& p) {
  en_passant_pos = p;
}

const SquareIndices &EnPassant::get_en_passant_position() { 
  return en_passant_pos;
}

bool EnPassant::is_pawn_piece(const Piecetype pct) {
  return pct == bP || pct == wP;
}

void EnPassant::set_en_passant_to_move(Move &m) {
  Move_Utils::set_en_passant(m, true);
}
