#ifndef SQUARE_DRAWING_INFO_H
#define SQUARE_DRAWING_INFO_H

#include "board/board_window/board_pane/board_drawings.hpp"
#include "board/board_window/board_pane/pieces/IPiece_drawing.hpp"
#include "board/board_window/board_pane/squares/square_drawing.h"
#include "ui_components/box_modifier.hpp"

struct WhiteSquareDrawing : public SquareDrawing {
 public:
  WhiteSquareDrawing() {
    m_side_bg_color_mod = {
      BM::GREY_BG,    // WHITE SIDE
      BM::WHITE_BG,   // BLACK SIDE
    };
    m_empty_drawing = BoardDrawings::Squares::Ksquares.at(
      StringDrawingName::Square::white_square);
  }
};

class BlackSquareDrawing : public SquareDrawing {
 public:
  BlackSquareDrawing() {
    m_side_bg_color_mod = {
        BM::GREEN_BG,   // WHITE SIDE
        BM::RED_BG,     // BLACK SIDE
    };
    m_empty_drawing = BoardDrawings::Squares::Ksquares.at(
        StringDrawingName::Square::black_square);
  }
};

#endif /* SQUARE_DRAWING_INFO_H */
