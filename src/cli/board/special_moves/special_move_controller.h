#ifndef SPECIAL_MOVE_CONTROLLER_H
#define SPECIAL_MOVE_CONTROLLER_H

#include "castling.h"
#include "pawn_promotion.h"
#include "en_passant.h"
#include "board/position/position_typedefs.h"
#include "board/position/position.h"

class SpecialMove {
 public:
  SpecialMove(Position& p);
  virtual ~SpecialMove();
  void handle_special_move(const Move& m, Position& squares);
  void set_special_move(Move& m, Position& squares);

 private:
  bool is_pawn_piece(const Piece pct);
  bool is_king_piece(const Piece pct);

  Castling m_castling;
  EnPassant m_en_passant;
  PawnPromition m_pawn_promotion;
  Position& m_position;
};

#endif /* SPECIAL_MOVE_CONTROLLER_H */
