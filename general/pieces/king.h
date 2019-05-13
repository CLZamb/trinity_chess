#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
private:
  IDrawing* king_w_sq = new PieceDrawing("king");
  IDrawing* king_b_sq = new PieceDrawing("king");

public:
  explicit King(bool black, U64);
  virtual ~King();
};

#endif /* KING_H */
