#ifndef IPIECE_DRAWING_BUILDER_H
#define IPIECE_DRAWING_BUILDER_H

#include "piece_drawing.hpp"

class IPiecesDrawingBuilder {
 public:
  virtual ~IPiecesDrawingBuilder() = default;
  virtual PieceDrawing* draw_piece(Piecetype pct)  = 0;
 protected:
  IPiecesDrawingBuilder() {}
};

#endif
