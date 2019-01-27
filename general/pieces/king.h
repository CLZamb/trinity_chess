#ifndef KING_H
#define KING_H

#include "boxStruct.h"
#include "piece.h"

class King : public Piece {
private:
  static box kingWhiteBoxP1;
  static box kingWhiteBoxP2;
  static box kingBlackBoxP1;
  static box kingBlackBoxP2;

public:
  explicit King(Player *side);
  virtual ~King();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "king"; }
};

#endif /* KING_H */
