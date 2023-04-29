#include "en_passant.h"

#include "board/check_move/pieces/pawn.hpp"
#include "board/position/position_typedefs.h"

EnPassant::EnPassant() {}
EnPassant::~EnPassant() {}

bool EnPassant::is_en_passant_move(const Move &m,
                                   const Square &en_passant_pos) {
  Square to = MoveUtils::get_to(m);
  Piece piece = MoveUtils::get_piece(m);
  return is_pawn_piece(piece) && (to == en_passant_pos);
}

bool EnPassant::is_pawn_piece(const Piece pct) {
  return pct == bP || pct == wP;
}

bool EnPassant::is_first_move(const Move &m) {
  Piece piece = MoveUtils::get_piece(m);

  if (piece == bP) {
    if (Pawn<BLACK>::is_first_move(m)) {
      return true;
    }
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_first_move(m)) {
      return true;
    }
  }

  return false;
}

bool EnPassant::is_double_forward_move(const Move &m) {
  Piece piece = MoveUtils::get_piece(m);
  if (piece == bP) {
    if (Pawn<BLACK>::is_double_forward_move(m)) {
      return true;
    }
  } else if (piece == wP) {
    if (Pawn<WHITE>::is_double_forward_move(m)) {
      return true;
    }
  }
  return false;
}

void EnPassant::capture_en_passant(const Move &m, Position &s) {
  bitUtility::Direction d =
      (utils::check::is_black_piece(MoveUtils::get_piece(m))
           ? bitUtility::NORTH
           : bitUtility::SOUTH);
  Square piece_capture_position = MoveUtils::get_to(m) + d;

  s.clear_square_at_pos(piece_capture_position);
  s.set_en_passant_square(SquareNull);
}
