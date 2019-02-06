#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
private:
  static box queenWhiteBoxP1;
  static box queenWhiteBoxP2;
  static box queenBlackBoxP1;
  static box queenBlackBoxP2;
  std::string movestr;
  std::string currentpos;
  char i;
  char j;
  char x;
  char y;

public:
  explicit Queen(std::string pieceColor);
  virtual ~Queen();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "queen"; }
  void possibleMoves(std::vector<std::string> &);
};

#endif /* QUEEN_H */
