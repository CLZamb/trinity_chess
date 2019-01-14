#ifndef ROOK_H
#define ROOK_H

#include "boxStruct.h"
#include "piece.h"

class Rook : public Piece {
private:
  static box rookA;
  static box rookB;

public:
  explicit Rook(Player *side);
  virtual ~Rook();
  box *getDrawingA();
  box *getDrawingB();
  bool isValidMove(Position, Position);
};

#endif /* ROOK_H */
