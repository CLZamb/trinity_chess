#ifndef QUEEN_H
#define QUEEN_H
#include "boxStruct.h"
#include "piece.h"

class Queen : public Piece {
private:
  static box queenA;
  static box queenB;

public:
  explicit Queen(Player *side);
  virtual ~Queen();
  box *getDrawingA();
  box *getDrawingB();
  bool checkMove(Position, Position);
};

#endif /* QUEEN_H */
