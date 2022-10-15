#ifndef SPECIAL_MOVE_H
#define SPECIAL_MOVE_H

#include "board/headers/castling.h"
#include "board/headers/squares.h"
#include "board/headers/defs.h"

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
  const Move &get_rook_castle_move(const CastlePermission &);
  const int &get_castle_permission();
  Type check_special_type(const Move& m, Squares& squares);
  bool is_castling_move(const Move& m);
  void assign_castle_rights_to_move();
  void set_en_passant_square(SquareIndices sq);
  void set_castle_permission(CastlePermission perm);
  const SquareIndices &get_en_passant_square();
  Type get_type();

 private:
  bool is_pawn_piece(const Piecetype pct);
  bool is_king_piece(const Piecetype pct);
  bool is_castle_move(const Move& m, Squares& squares);
  bool is_en_passant_move(const Move &m);
  bool can_castle();

  Castling m_castling;
  int m_castle_perm{NO_CASTLING};
  SquareIndices en_passant_pos{SquareNull};

  Move m_move;
};

#endif /* SPECIAL_MOVE_H */
