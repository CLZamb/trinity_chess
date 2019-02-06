#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
private:
  static box kingWhiteBoxP1;
  static box kingWhiteBoxP2;
  static box kingBlackBoxP1;
  static box kingBlackBoxP2;
  std::string movestr;
  std::string currentpos;

public:
  explicit King(std::string pieceColor);
  virtual ~King();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "king"; }
  void possibleMoves(std::vector<std::string> &);
};

#endif /* KING_H */
