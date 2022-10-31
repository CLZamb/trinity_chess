#ifndef EN_PASSANT_H
#define EN_PASSANT_H

#include "board/headers/special_move.h"
#include "board/headers/squares.h"
#include "board/headers/utils.h"
#include "game/headers/move.hpp"

class EnPassant : public SpecialMove {
public:
  EnPassant();
  virtual ~EnPassant();
  bool is_en_passant_move(const Move &m);
  void set_en_passant_position(const SquareIndices &sq);
  const SquareIndices &get_en_passant_position();
  void assign_special_to_move(Move& m) override;
  void handle_special_move(const Move& m, Squares& s) override;

private:
  void capture_en_passant(const Move& m, Squares& s);
  bool is_pawn_piece(const Piecetype pct);
  bool is_first_move(const Move& m);
  bool is_double_forward_move(const Move& m);

  SquareIndices en_passant_pos{SquareNull};
};

#endif /* EN_PASSANT_H */
