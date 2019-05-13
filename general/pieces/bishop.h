#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
private:
  IDrawing* w_sq_drawing = new PieceDrawing("bishop");
  IDrawing* b_sq_drawing = new PieceDrawing("bishop");

public:
  explicit Bishop(bool black, U64);
  virtual ~Bishop();
};

#endif /* BISHOP_H */
