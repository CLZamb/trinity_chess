#include "special_move_controller.h"

#include "board/position/position_typedefs.h"
#include "utils/move.hpp"

SpecialMove::SpecialMove(Position &p)
    : m_position(p) {}
SpecialMove::~SpecialMove() {}

void SpecialMove::handle_special_move(const Move &m, Position &position) {
  if (MoveUtils::is_en_passand(m)) {
    m_en_passant.capture_en_passant(m, position);
  } else if (MoveUtils::can_castle(m)) {
    m_castling.move_rook(m, position);
  } else if (MoveUtils::get_promoted_piece(m) != NO_PIECE) {
    m_pawn_promotion.handle_promotion(m, position);
  }
}

void SpecialMove::set_special_move(Move &m, Position &squares) {
  Piece pct = MoveUtils::get_piece(m);
  if (!is_pawn_piece(pct) && !is_king_piece(pct)) return;

  if (m_castling.is_castle_move(m, squares)) {
    MoveUtils::set_castle_permission(m, m_position.get_castle_permission(m));
  } else if (m_en_passant.is_en_passant_move(
                 m, m_position.get_en_passant_square())) {
    MoveUtils::set_en_passant(m, m_position.get_en_passant_square());
  } else if (m_pawn_promotion.is_pawn_promotion(m)) {
    MoveUtils::set_promoted_piece(m, bQ);
  }
}

bool SpecialMove::is_pawn_piece(const Piece pct) {
  return pct == bP || pct == wP;
}

bool SpecialMove::is_king_piece(const Piece pct) {
  return pct == bK || pct == wK;
}
