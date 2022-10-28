#ifndef SPECIAL_MOVE_H
#define SPECIAL_MOVE_H

#include "board/headers/castling.h"
#include "board/headers/squares.h"
#include "board/headers/defs.h"
#include "piece/headers/pawn.h"
#include "board/headers/en_passant.h"

class SpecialMove {
 public:
  enum Type {
    None = 0,
    Pawn_Promotion = 1,
    En_Passant,
    Castling_Move,
  };
  SpecialMove();
  virtual ~SpecialMove();
  void set_en_passant_square(SquareIndices sq);
  void set_castle_permission(CastlePermission perm);
  const SquareIndices &get_en_passant_square();
  void handle_special_move(const Move& m, Squares& squares);
  bool is_special_move(const Move& m);
  void set_special_move_to_move(Move& m, Squares& squares);

 private:
  void move_rook(const Move&, Squares& s);
  void capture_en_passant(const Move& m, Squares& s);
  bool is_first_move(const Move& m);
  bool is_double_forward_move(const Move& m);

  Move m_move;
  Castling m_castling;
  EnPassant m_en_passant;
  int castle_perm{NO_CASTLING};
  Type m_type;
};

#endif /* SPECIAL_MOVE_H */
