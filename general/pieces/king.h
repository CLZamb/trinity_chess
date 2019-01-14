#ifndef KING_H
#define KING_H

#include "boxStruct.h"
#include "piece.h"

class King : public Piece {
private:
  static box kingA;
  static box kingB;

public:
  explicit King(Player* side);
  virtual ~King();
  box *getDrawingA();
  box *getDrawingB();
  bool isValidMove(Position, Position);
};

#endif /* KING_H */
