
#ifndef BISHOP_H
#define BISHOP_H

#include "boxStruct.h"
#include "piece.h"

class Bishop : public Piece {
private:
  static box bishopBlackBoxP1;
  static box bishopWhiteBoxP1;
  static box bishopBlackBoxP2;
  static box bishopWhiteBoxP2;

public:
  explicit Bishop(Player *side);
  virtual ~Bishop();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "bishop"; }
};

#endif /* BISHOP_H */
