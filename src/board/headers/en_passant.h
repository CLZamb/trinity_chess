#ifndef EN_PASSANT_H
#define EN_PASSANT_H

#include "board/headers/utils.h"
#include "game/headers/move.hpp"

class EnPassant{
public:
  EnPassant();
  virtual ~EnPassant();
  bool is_en_passant_move(const Move &m);
  void set_en_passant_to_move(Move &m);
  void set_en_passant_position(const SquareIndices &sq);
  const SquareIndices &get_en_passant_position();

private:
  bool is_pawn_piece(const Piecetype pct);
  SquareIndices en_passant_pos{SquareNull};
};

#endif /* EN_PASSANT_H */
