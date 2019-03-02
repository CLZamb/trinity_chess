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

public:
  explicit Rook(std::string pieceColor, U64);
  virtual ~Rook();
  std::string getPieceType() { return "rook"; }
};

#endif /* ROOK_H */
