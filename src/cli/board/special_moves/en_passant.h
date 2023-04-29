#ifndef EN_PASSANT_H
#define EN_PASSANT_H

#include "board/position/position.h"
#include "utils/move.hpp"

class EnPassant {
public:
  EnPassant();
  virtual ~EnPassant();
  bool is_en_passant_move(const Move &m, const Square& sq);
  void set_en_passant_position(const Square &sq);
  const Square &get_en_passant_position();
  void capture_en_passant(const Move& m, Position& s);

private:
  bool is_pawn_piece(const Piece pct);
  bool is_first_move(const Move& m);
  bool is_double_forward_move(const Move& m);

};

#endif /* EN_PASSANT_H */
