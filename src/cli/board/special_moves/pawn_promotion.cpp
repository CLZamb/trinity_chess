#include "pawn_promotion.h"
#include "board/check_move/pieces/pawn.hpp"

PawnPromition::PawnPromition() {}
PawnPromition::~PawnPromition() {}

bool PawnPromition::is_pawn_promotion(const Move& m) {
  Piece piece = MoveUtils::get_piece(m);
  if (!is_pawn_piece(piece)) return false;

  if (piece == bP) {
    if (Pawn<BLACK>::is_promotion(m))
      return true;
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_promotion(m))
      return true;
  }

  return false;
}

bool PawnPromition::is_pawn_piece(const Piece pct) {
  return pct == bP || pct == wP;
}

void PawnPromition::handle_promotion(const Move& m, Position &s) {
  Piece promotion = MoveUtils::get_promoted_piece(m);
  Square to_pos = MoveUtils::get_to(m);

  s.set_piece_at_square(promotion, to_pos);
}
