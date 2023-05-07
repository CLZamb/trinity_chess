#ifndef SQUARE_DRAWING_SELECTOR_H
#define SQUARE_DRAWING_SELECTOR_H

#include <memory>

#include "board/board_window/board_pane/squares/square_drawings.h"

class SquaresDrawingSelector {
 public:
  explicit SquaresDrawingSelector(SquaresDrawings &sq,
                                  Square initial_selection);
  void select_next(SquareDrawing *ptr_sq_drawing);
  void set_selected(SquareDrawing *ptr_sq_drawing);
  void set_start_pos(SquareDrawing *ptr_sq_drawing);
  void remove_previous_selected();

 private:
  SquaresDrawings &m_squares_drawings;
  SquareDrawing *p_selected_square_drawing;
  SquareDrawing *p_prev_select_square_drawing;

  const BoxModifier::Attribute m_select_attr_mod{BoxModifier::BG_INVERSE};
};

#endif /* SQUARE_DRAWING_SELECTOR_H */
