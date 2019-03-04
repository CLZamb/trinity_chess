#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
private:
  static box king_w_sq_p2;
  static box king_b_sq_p2;
  static box king_w_sq_p1;
  static box king_b_sq_p1;

public:
  explicit King(bool black, U64);
  virtual ~King();
  std::string get_type();
};

#endif /* KING_H */
