#ifndef SQUARE_DRAWING_INFO_H
#define SQUARE_DRAWING_INFO_H

#include "board/board_window/board_pane/board_drawings.hpp"
#include "ui_components/box_modifier.hpp"

class SquareDrawingInfo {
 public:
  virtual const Box &empty_square_drawing() const = 0;
  virtual const BoxModifier::BGColor &get_white_piece_bg_mod() const = 0;
  virtual const BoxModifier::BGColor &get_black_piece_bg_mod() const = 0;
};

struct WhiteSquareDrawingInfo : public SquareDrawingInfo {
  const Box &empty_square_drawing() const override {
    return BoardDrawings::Squares::Ksquares.at(
        StringDrawingName::Square::white_square);
  };
  const BoxModifier::BGColor &get_white_piece_bg_mod() const override {
    return m_w_bg_mod;
  }
  const BoxModifier::BGColor &get_black_piece_bg_mod() const override {
    return m_b_bg_mod;
  }

 private:
  BoxModifier::BGColor m_w_bg_mod = BoxModifier::GREY_BG;
  BoxModifier::BGColor m_b_bg_mod = BoxModifier::WHITE_BG;
};

class BlackSquareDrawingInfo : public SquareDrawingInfo {
  const Box &empty_square_drawing() const override {
    return BoardDrawings::Squares::Ksquares.at(
        StringDrawingName::Square::black_square);
  };
  const BoxModifier::BGColor &get_white_piece_bg_mod() const override {
    return m_w_bg_mod;
  }
  const BoxModifier::BGColor &get_black_piece_bg_mod() const override {
    return m_b_bg_mod;
  }

 private:
  BoxModifier::BGColor m_w_bg_mod = BoxModifier::GREEN_BG;
  BoxModifier::BGColor m_b_bg_mod = BoxModifier::RED_BG;
};

#endif /* SQUARE_DRAWING_INFO_H */
