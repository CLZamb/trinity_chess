#ifndef ROOK_H
#define ROOK_H

#include "boxStruct.h"
#include "piece.h"

class Rook : public Piece {
private:
  static box rookWhiteBoxP2;
  static box rookWhiteBoxP1;
  static box rookBlackBoxP2;
  static box rookBlackBoxP1;

public:
  explicit Rook(Player *side);
  virtual ~Rook();
  box *getDrawingWSquare();
  box *getDrawingBSquare();
  bool checkMove(Position, Position);
};

#endif /* ROOK_H */
