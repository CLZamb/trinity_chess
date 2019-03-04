#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
private:
  static box bishop_b_sq_p1;
  static box bishop_w_sq_p1;
  static box bishop_b_sq_p2;
  static box bishop_w_sq_p2;

public:
  explicit Bishop(bool black, U64);
  virtual ~Bishop();
  std::string get_type();
};

#endif /* BISHOP_H */
