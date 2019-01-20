#ifndef KNIGHT_H
#define KNIGHT_H

#include "boxStruct.h"
#include "piece.h"

class Knight : public Piece {
private:
  static box knightWhiteBoxP2;
  static box knightWhiteBoxP1;
  static box knightBlackBoxP1;
  static box knightBlackBoxP2;

public:
  explicit Knight(Player *side);
  virtual ~Knight();
  box *getDrawingWSquare();
  box *getDrawingBSquare();
  bool checkMove(Position, Position);
};

#endif /* KNIGHT_H */
