#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
private:
  static box rook_w_sq_p2;
  static box rook_b_sq_p2;
  static box rook_w_sq_p1;
  static box rook_b_sq_p1;

public:
  explicit Rook(bool black, U64);
  virtual ~Rook();
  std::string get_type();
};

#endif /* ROOK_H */
