#ifndef STANDARD_PIECES_DRAWINGS_H
#define STANDARD_PIECES_DRAWINGS_H

#include <list>
#include "IPiecesDrawingBuilder.hpp"

using std::list;
class StandardPiecesDrawingBuilder : public IPiecesDrawingBuilder {
 public:
  StandardPiecesDrawingBuilder() : _pieces_drawings(new std::list<PieceDrawing*>) {}
  virtual ~StandardPiecesDrawingBuilder() {
    for (auto * piece_drawing : *_pieces_drawings) 
      delete piece_drawing;

    _pieces_drawings->clear();
    delete _pieces_drawings;
  }

  PieceDrawing* build_drawing(Piecetype pct) override {
    std::string piece_type = string_utils::get_piece_str_name_from_piecetype(pct);
    PieceDrawing * piece_drawing = new PieceDrawing(piece_type);
    _pieces_drawings->push_back(piece_drawing);
    return piece_drawing;
  }

 private:
  list<PieceDrawing*> *_pieces_drawings;
};

#endif /* STANDARD_PIECES_DRAWINGS_H */
