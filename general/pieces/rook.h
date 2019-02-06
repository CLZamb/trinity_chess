#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
private:
  static box rookWhiteBoxP2;
  static box rookBlackBoxP2;
  static box rookWhiteBoxP1;
  static box rookBlackBoxP1;
  std::string movestr;
  std::string currentpos;
  char i;
  char x;
  char y;

public:
  explicit Rook(std::string pieceColor);
  virtual ~Rook();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "queen"; }
  void possibleMoves(std::vector<std::string> &);
};

#endif /* ROOK_H */
