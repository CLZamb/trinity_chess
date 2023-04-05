#include "pawn_promotion.h"
#include "board/check_move/pieces/pawn.hpp"

PawnPromition::PawnPromition() {}
PawnPromition::~PawnPromition() {}

bool PawnPromition::is_pawn_promotion(const Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
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

bool PawnPromition::is_pawn_piece(const Piecetype pct) {
  return pct == bP || pct == wP;
}

void PawnPromition::assign_special_to_move(Move& m) {
  Piecetype piece = Move_Utils::get_piece(m);
  Piecetype promotion = Move_Utils::get_piece(m);

  if (piece == bP) {
    if (Pawn<BLACK>::is_promotion(m))
      promotion = bQ;
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_promotion(m))
      promotion = wQ;
  }
  Move_Utils::set_promoted_piece(m, promotion);
}

void PawnPromition::handle_special_move(const Move& m, Squares &s) {
  Piecetype promotion = Move_Utils::get_promoted_piece(m);
  SquareIndices to_pos = Move_Utils::get_to(m);

  s[to_pos].set_piece(promotion);
}
