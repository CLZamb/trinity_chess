#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
private:
  static box knight_w_sq_p2;
  static box knight_b_sq_p2;
  static box knight_w_sq_p1;
  static box knight_b_sq_p1;

public:
  explicit Knight(bool black, U64);
  virtual ~Knight();
};

#endif /* KNIGHT_H */
