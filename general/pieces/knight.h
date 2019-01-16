#ifndef KNIGHT_H
#define KNIGHT_H

#include "boxStruct.h"
#include "piece.h"

class Knight : public Piece {
private:
  static box knightA;
  static box knightB;

public:
  explicit Knight(Player* side);
  virtual ~Knight();
  box *getDrawingA();
  box *getDrawingB();
  bool checkMove(Position, Position);
};

#endif /* KNIGHT_H */
