#ifndef PIECE_DRAWINGS_H
#define PIECE_DRAWINGS_H

#include <iostream>
#include "board/board_window/board_pane/pieces/IPiece_drawing.hpp"
#include "board/position/position_utils.h"
#include "ui_components/box.h"
#include "ui_components/box_modifier.hpp"

class PieceDrawing : public IPieceDrawing {
 public:
  virtual ~PieceDrawing() = default;
  explicit PieceDrawing(Box drawing, Piece piece)
      : m_drawing(drawing)
      , m_piece(utils::check::get_color_piece(piece)) {
    BoxModifier::add_reset_attr(&m_drawing);
  }

  std::unique_ptr<IPieceDrawing> clone() override {
    std::cout << "created new piece drawing" << std::endl;
    return std::make_unique<PieceDrawing>(*this);
  }

  Box &get_drawing() override { return m_drawing; }
  const Box &get_drawing() const { return m_drawing; }
  const Color &get_color() const override { return m_piece; }

 private:
  Box m_drawing;
  Color m_piece;
};

#endif /* DRAWINGS_H */
