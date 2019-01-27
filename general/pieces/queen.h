#ifndef QUEEN_H
#define QUEEN_H
#include "boxStruct.h"
#include "piece.h"

class Queen : public Piece {
private:
  static box queenWhiteBoxP1;
  static box queenWhiteBoxP2;
  static box queenBlackBoxP1;
  static box queenBlackBoxP2;

public:
  explicit Queen(Player *side);
  virtual ~Queen();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "queen"; }
};

#endif /* QUEEN_H */
