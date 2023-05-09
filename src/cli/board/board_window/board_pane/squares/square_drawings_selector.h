#ifndef SQUARE_DRAWING_SELECTOR_H
#define SQUARE_DRAWING_SELECTOR_H

#include <memory>

#include "board/board_window/board_pane/squares/square_drawings.h"

class SquareDrawingSelector {
 public:
  explicit SquareDrawingSelector(SquaresDrawings &sq,
                                  Square initial_selection);
  void select_next(SquareDrawing *ptr_sq_drawing);
  void set_selected(SquareDrawing *ptr_sq_drawing);
  void remove_previous_selected();

 private:
  void set_select_attr(SquareDrawing *ptr_sq_drawing);
  void remove_select_attr(SquareDrawing *ptr_sq_drawing);
  SquaresDrawings &m_squares;
  SquareDrawing *p_selected_square;
  SquareDrawing *p_prev_select_square;

  const BoxModifier::Attribute m_select_attr_mod{BoxModifier::BG_INVERSE};
};

#endif /* SQUARE_DRAWING_SELECTOR_H */
