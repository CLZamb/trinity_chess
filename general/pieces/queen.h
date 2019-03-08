#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
private:
  static box queen_w_sq_p2;
  static box queen_b_sq_p2;
  static box queen_w_sq_p1;
  static box queen_b_sq_p1;

public:
  explicit Queen(bool black, U64);
  virtual ~Queen();
};

#endif /* QUEEN_H */
