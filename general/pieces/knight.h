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
  bool checkMove(Position, Position);
  std::string getPieceType() { return "knight"; }
};

#endif /* KNIGHT_H */
