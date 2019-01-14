
#ifndef BISHOP_H
#define BISHOP_H

#include "boxStruct.h"
#include "piece.h"

class Bishop : public Piece {
private:
  static box bishopA;
  static box bishopB;

public:
  explicit Bishop(Player* side);
  virtual ~Bishop();
  box *getDrawingA();
  box *getDrawingB();
  bool isValidMove(Position, Position);
};

#endif /* BISHOP_H */
