#ifndef PIECE_DRAWINGS_H
#define PIECE_DRAWINGS_H

#include <iostream>

#include "board/position/position_utils.h"
#include "components/box.h"
#include "components/box_modifier.hpp"

class PieceDrawing {
 public:
  PieceDrawing(Box drawing, Piece piece)
      : m_drawing(drawing)
      , m_piece(utils::check::get_color_piece(piece)) {
    BoxModifier::add_reset_attr(&m_drawing);
  }

  Box &get_drawing() { return m_drawing; }
  const Box &get_drawing() const { return m_drawing; }
  const Color &get_color() const { return m_piece; }

 private:
  Box m_drawing;
  Color m_piece;
};

#endif /* DRAWINGS_H */
