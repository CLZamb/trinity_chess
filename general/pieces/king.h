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

public:
  explicit King(std::string pieceColor, U64);
  virtual ~King();
  std::string getPieceType() { return "king"; }
};

#endif /* KING_H */
