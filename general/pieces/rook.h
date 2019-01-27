#ifndef ROOK_H
#define ROOK_H

#include "boxStruct.h"
#include "piece.h"

class Rook : public Piece {
private:
  static box rookWhiteBoxP2;
  static box rookBlackBoxP2;
  static box rookWhiteBoxP1;
  static box rookBlackBoxP1;

public:
  explicit Rook(Player *side);
  virtual ~Rook();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "queen"; }
};

#endif /* ROOK_H */
