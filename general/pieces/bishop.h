
#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
private:
  static box bishopBlackBoxP1;
  static box bishopWhiteBoxP1;
  static box bishopBlackBoxP2;
  static box bishopWhiteBoxP2;
  std::string movestr;
  std::string currentpos;
  char i;
  char j;
  char x;
  char y;

public:
  explicit Bishop(std::string pieceColor);
  virtual ~Bishop();
  bool checkMove(Position, Position);
  std::string getPieceType() { return "bishop"; }
  void possibleMoves(std::vector<std::string> &);
};

#endif /* BISHOP_H */
