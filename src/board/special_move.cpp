#include "headers/special_move.h"

SpecialMove::SpecialMove() {}
SpecialMove::~SpecialMove() {}
SpecialMove::Type SpecialMove::check_special_type(const Move& m, Squares& squares) {
  Piecetype piece = Move_Utils::get_piece(m);
  if (!is_pawn_piece(piece) && !is_king_piece(piece)) 
    return None;

  if (is_en_passant_move(m)) {
    return En_Passant;
  }
  if (can_castle() && is_castle_move(m, squares)) {
    return Castling_Move;
  }

  return None;
}

bool SpecialMove::is_pawn_piece(const Piecetype pct) {
  return pct == bP || pct == wP;
}

bool SpecialMove::is_king_piece(const Piecetype pct) {
  return pct == bK || pct == wK;
}

bool SpecialMove::can_castle() {
  return get_castle_permission() != NO_CASTLING;
}

bool SpecialMove::is_castle_move(const Move& m, Squares& squares) {
  Color color = utils::check::get_color_piece(Move_Utils::get_piece(m));
  bool is_castle_move = m_castling.is_castle_move(m, color);
  CastleSquares rook_initial_pos = m_castling.get_castle_rook_initial_position(m, color);
  Piecetype piece_at_rook_initial_pos = squares[rook_initial_pos].get_piece();
  return is_castle_move & (piece_at_rook_initial_pos == bR || piece_at_rook_initial_pos == wR);
}

const Move &SpecialMove::get_rook_castle_move(const CastlePermission& permision) {
  return m_castling.get_rook_castle_move(permision);
}

bool SpecialMove::is_en_passant_move(const Move &m) {
  SquareIndices to = Move_Utils::get_to(m);
  Piecetype piece = Move_Utils::get_piece(m);
  return is_pawn_piece(piece) && (to == en_passant_pos);
}

void SpecialMove::set_en_passant_square(SquareIndices sq) {
  en_passant_pos = sq;
}

void SpecialMove::set_castle_permission(CastlePermission perm) {
  m_castle_perm |= perm;
}

const int &SpecialMove::get_castle_permission() {
  return m_castle_perm;
}

const SquareIndices &SpecialMove::get_en_passant_square() {
  return en_passant_pos;
}
