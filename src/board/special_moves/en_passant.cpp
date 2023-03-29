#include "en_passant.h"

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

bool EnPassant::is_first_move(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);

  if (piece == bP) {
    if (Pawn<BLACK>::is_first_move(m))
      return true;
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_first_move(m))
      return true;
  }

  return false;
}

bool EnPassant::is_double_forward_move(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  if (piece == bP) {
    if (Pawn<BLACK>::is_double_forward_move(m))
      return true;
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_double_forward_move(m))
      return true;
  }
  return false;
}

void EnPassant::capture_en_passant(const Move& m, Squares& s) {
  Direction d = (utils::check::is_black_piece(Move_Utils::get_piece(m)) ?  NORTH :  SOUTH);
  SquareIndices piece_capture_position = Move_Utils::get_to(m) + d;
  s[piece_capture_position].clear_square();
  en_passant_pos = SquareNull;
}

void EnPassant::assign_special_to_move(Move& m) {
  Move_Utils::set_en_passant(m, true);
}

void EnPassant::handle_special_move(const Move &m, Squares &s) {
  capture_en_passant(m, s);
}
