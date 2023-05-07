#include "square_drawings_selector.h"

#include "ui_components/box_modifier.hpp"

SquaresDrawingSelector::SquaresDrawingSelector(SquaresDrawings &sq,
                                               Square initial_selection)
    : m_squares_drawings(sq) {
  SquareDrawing *sq_drawing = m_squares_drawings[initial_selection];

  if (sq_drawing == nullptr) return;

  BoxModifier::add_attribute(BoxModifier::BG_INVERSE,
                             sq_drawing->get_drawing());

  p_prev_select_square_drawing = sq_drawing;
}

void SquaresDrawingSelector::set_start_pos(SquareDrawing *sq_drawing) {
  if (sq_drawing == nullptr) return;

  BoxModifier::add_attribute(BoxModifier::BG_INVERSE,
                             sq_drawing->get_drawing());

  p_prev_select_square_drawing = sq_drawing;
}

void SquaresDrawingSelector::set_selected(SquareDrawing *sq_drawing) {
  if (sq_drawing == nullptr) return;
  if (sq_drawing == p_selected_square_drawing) return;

  BoxModifier::add_attribute(BoxModifier::BG_INVERSE,
                             sq_drawing->get_drawing());
  p_selected_square_drawing = sq_drawing;
}

void SquaresDrawingSelector::remove_previous_selected() {
  if (p_selected_square_drawing == nullptr) return;

  BoxModifier::remove_mod(p_selected_square_drawing->get_drawing(),
                          BoxModifier::ATTRIBUTE);

  p_selected_square_drawing = nullptr;
}

void SquaresDrawingSelector::select_next(SquareDrawing *sq_drawing) {
  if (sq_drawing == nullptr) return;
  if (sq_drawing == p_selected_square_drawing) return;
  if (sq_drawing == p_prev_select_square_drawing) return;

  BoxModifier::remove_mod(p_prev_select_square_drawing->get_drawing(),
                          BoxModifier::ATTRIBUTE);

  BoxModifier::add_attribute(BoxModifier::BG_INVERSE,
                             sq_drawing->get_drawing());

  p_prev_select_square_drawing = sq_drawing;
}
