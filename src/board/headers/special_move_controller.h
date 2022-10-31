#ifndef SPECIAL_MOVE_CONTROLLER_H
#define SPECIAL_MOVE_CONTROLLER_H

#include "board/headers/castling.h"
#include "board/headers/pawn_promition.h"
#include "board/headers/squares.h"
#include "board/headers/defs.h"
#include "piece/headers/pawn.h"
#include "board/headers/en_passant.h"

class SpecialMoveController {
 public:
  SpecialMoveController();
  virtual ~SpecialMoveController();
  void set_en_passant_square(SquareIndices sq);
  void set_castle_permission(CastlePermission perm);
  const SquareIndices &get_en_passant_square();
  void handle_special_move(const Move& m, Squares& squares);
  bool is_current_move_special_move();
  void set_special_move_to_move(Move& m, Squares& squares);

 private:
  bool is_pawn_piece(const Piecetype pct);
  bool is_king_piece(const Piecetype pct);

  Move m_move;
  Castling m_castling;
  EnPassant m_en_passant;
  PawnPromition m_pawn_promotion;
  SpecialMove* m_special_move{nullptr};

  int castle_perm{NO_CASTLING};
};

#endif /* SPECIAL_MOVE_CONTROLLER_H */
