#include "square_drawings_selector.h"

#include "ui_components/box_modifier.hpp"

using BM = BoxModifier;

SquareDrawingSelector::SquareDrawingSelector(SquaresDrawings &sq,
                                             Square init_selection)
    : m_squares(sq) {
  SquareDrawing *init_sq = m_squares[init_selection];

  set_select_attr(init_sq);

  p_prev_select_square = init_sq;
}

void SquareDrawingSelector::set_selected(SquareDrawing *sq) {
  if (sq == p_selected_square) return;
  p_selected_square = sq;
}

void SquareDrawingSelector::remove_previous_selected() {
  if (p_selected_square == nullptr) return;

  remove_select_attr(p_selected_square);

  p_selected_square = nullptr;
}

void SquareDrawingSelector::select_next(SquareDrawing *sq) {
  if (sq == nullptr) return;

  if (p_prev_select_square != p_selected_square) {
    remove_select_attr(p_prev_select_square);
  }

  set_select_attr(sq);

  p_prev_select_square = sq;
}

void SquareDrawingSelector::set_select_attr(SquareDrawing *sq) {
  if (sq == nullptr) return;
  if (sq == p_selected_square) return;

  BM::add_attribute(BM::BG_INVERSE, sq->get_drawing());
}

void SquareDrawingSelector::remove_select_attr(SquareDrawing *sq) {
  if (sq == nullptr) return;

  BM::remove_mod(BM::ATTRIBUTE, sq->get_drawing());
}
