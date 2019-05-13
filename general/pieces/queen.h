#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
private:
  IDrawing* w_sq_drawing = new WhiteSquare(new PieceDrawing("queen"));
  IDrawing* b_sq_drawing = new PieceDrawing("queen");

public:
  explicit Queen(bool black, U64);
  virtual ~Queen();
};

#endif /* QUEEN_H */
