#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
private:
  IDrawing* w_sq_drawing = new PieceDrawing("rook");
  IDrawing* b_sq_drawing = new PieceDrawing("rook");

public:
  explicit Rook(bool black, U64);
  virtual ~Rook();
};

#endif /* ROOK_H */
