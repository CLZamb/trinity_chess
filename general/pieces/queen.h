#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
private:
  static box queenWhiteBoxP1;
  static box queenWhiteBoxP2;
  static box queenBlackBoxP1;
  static box queenBlackBoxP2;

public:
  explicit Queen(std::string pieceColor, U64);
  virtual ~Queen();
  std::string getPieceType() { return "queen"; }
};

#endif /* QUEEN_H */
