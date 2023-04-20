#ifndef STANDARD_PIECES_DRAWINGS_H
#define STANDARD_PIECES_DRAWINGS_H

#include <list>
#include "IPiecesDrawingBuilder.hpp"

using std::list;
class PiecesDrawingBuilder : public IPiecesDrawingBuilder {
 public:
  PiecesDrawingBuilder() : _pieces_drawings(new std::list<PieceDrawing*>) {}

  virtual ~PiecesDrawingBuilder() {
    _pieces_drawings->clear();
    delete _pieces_drawings;
  }

  PieceDrawing* draw_piece(Piecetype pct) override {
    PieceDrawing * piece_drawing = new PieceDrawing(pct);
    _pieces_drawings->push_back(piece_drawing);
    return piece_drawing;
  }

 private:
  list<PieceDrawing*> *_pieces_drawings;
};

#endif /* STANDARD_PIECES_DRAWINGS_H */
