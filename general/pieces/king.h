#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
private:
  IDrawing* w_sq_drawing = new PieceDrawing("king");
  IDrawing* b_sq_drawing = new PieceDrawing("king");

public:
  explicit King(bool black, U64);
  virtual ~King();
};

#endif /* KING_H */
