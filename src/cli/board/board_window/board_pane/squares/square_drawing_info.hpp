#ifndef SQUARE_DRAWING_INFO_H
#define SQUARE_DRAWING_INFO_H

#include "board/board_window/board_pane/board_drawings.hpp"
#include "board/board_window/board_pane/squares/square_drawing.h"

struct WhiteSquareDrawing : public SquareDrawing {
 public:
  WhiteSquareDrawing() {
    m_side_bg_color_mod = {
        BM::GREY_BG,    // WHITE SIDE
        BM::WHITE_BG,   // BLACK SIDE
    };

    std::array<BoxModifier::FGColor, Box::kRowSize> colors{
        BoxModifier::FGColor::WHITE_SQ_FG_1,
        BoxModifier::FGColor::WHITE_SQ_FG_2,
        BoxModifier::FGColor::WHITE_SQ_FG_3,
        BoxModifier::FGColor::WHITE_SQ_FG_4,
        BoxModifier::FGColor::WHITE_SQ_FG_5,
    };

    BM::add_fg_color(colors, &m_empty_drawing);
  }
};

class BlackSquareDrawing : public SquareDrawing {
 public:
  BlackSquareDrawing() {
    m_side_bg_color_mod = {
        BM::GREEN_BG,   // WHITE SIDE
        BM::RED_BG,     // BLACK SIDE
    };

    std::array<BoxModifier::FGColor, Box::kRowSize> colors{
        BoxModifier::FGColor::BLACK_SQ_FG_1,
        BoxModifier::FGColor::BLACK_SQ_FG_2,
        BoxModifier::FGColor::BLACK_SQ_FG_3,
        BoxModifier::FGColor::BLACK_SQ_FG_4,
        BoxModifier::FGColor::BLACK_SQ_FG_5,
    };

    BM::add_fg_color(colors, &m_empty_drawing);
  }
};

#endif /* SQUARE_DRAWING_INFO_H */
