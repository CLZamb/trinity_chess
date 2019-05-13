#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
private:
  IDrawing* w_sq_drawing = new PieceDrawing("knight");
  IDrawing* b_sq_drawing = new PieceDrawing("knight");

public:
  explicit Knight(bool black, U64);
  virtual ~Knight();
};

#endif /* KNIGHT_H */
