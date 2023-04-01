#ifndef IPIECE_DRAWING_BUILDER_H
#define IPIECE_DRAWING_BUILDER_H

#include "piece_drawing.hpp"

class IPiecesDrawingBuilder {
 public:
  virtual PieceDrawing* build_drawing(Piecetype pct)  = 0;
 protected:
  IPiecesDrawingBuilder() {}
};

#endif
