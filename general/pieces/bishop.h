
#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
private:
  static box bishopBlackBoxP1;
  static box bishopWhiteBoxP1;
  static box bishopBlackBoxP2;
  static box bishopWhiteBoxP2;

public:
  explicit Bishop(std::string pieceColor, U64);
  virtual ~Bishop();
  std::string getPieceType() { return "bishop"; }
};

#endif /* BISHOP_H */
