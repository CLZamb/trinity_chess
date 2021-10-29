#ifndef MOVE_VALIDATION_H
#define MOVE_VALIDATION_H

#pragma once
#include "IMove_validation.h"
// #include "bitboard.h"

class MoveValidator : public IMoveValidation {
 public:
  MoveValidator();
  virtual ~MoveValidator();

  bool is_valid_move(const Move& m) override;
  bool rook(int from, int to);
  bool knight(int from, int to);
  bool bishop(int from, int to);
  bool king(int from, int to);
  bool queen(int from, int to);
  bool pawn(int from, int to);
 private:
  // Bitboard m_b_board;
};

#endif /* MOVE_VALIDATION_H */
