#include "square_drawing.h"
#include "ui/board/board_pane/board_drawings.hpp"

BoxModifier SquareDrawing::mod;

SquareDrawing::SquareDrawing() : 
  p_empty_square_drawing(&
      BoardDrawings::Squares::Ksquares.at(
      StringDrawingName::Square::white_square)) {
    update_current_drawing(p_empty_square_drawing);
}

SquareDrawing::SquareDrawing(bool is_black_square) {
  set_base_square_drawing(is_black_square);
}

SquareDrawing::~SquareDrawing() {}

const Box* SquareDrawing::get_drawing() { return p_cur_drawing; }
const char* SquareDrawing::at_row(int row_index) { 
  return p_cur_drawing->content[row_index]; 
}
bool SquareDrawing::is_black_square() { return m_black_square; }
bool SquareDrawing::is_selected() { return m_is_selected; }
void SquareDrawing::set_is_selected(const bool & s) {
  m_is_selected = s;
}

const Box* SquareDrawing::get_original_drawing() {
  if (m_has_piece)
    return p_piece_square_drawing;

  return p_empty_square_drawing;
}

void SquareDrawing::clear_square() {
  update_current_drawing(p_empty_square_drawing);

  m_has_piece = false;
}

void SquareDrawing::set_piece_drawing(const Box* drawing) {
  p_piece_square_drawing = drawing;

  update_current_drawing(p_piece_square_drawing);

  m_has_piece = true;
}

void SquareDrawing::update_current_drawing(const Box* drawing) {
  if (p_cur_drawing != drawing)
    p_cur_drawing = drawing;
}

void SquareDrawing::deselect() {
  if (m_is_selected) return;
  update_current_drawing(get_original_drawing());
}

void SquareDrawing::select() {
  if (p_cur_drawing == nullptr) return;

  m_select_drawing = *get_original_drawing();

  mod.add_attribute(BoxModifier::BG_INVERSE, &m_select_drawing);
  update_current_drawing(&m_select_drawing);
}

void SquareDrawing::set_base_square_drawing(bool is_black_square) {
  m_black_square = is_black_square;

  p_empty_square_drawing = 
    is_black_square ? 
      &BoardDrawings::Squares::Ksquares.at(
        StringDrawingName::Square::black_square) : 
      &BoardDrawings::Squares::Ksquares.at(
        StringDrawingName::Square::white_square);

  update_current_drawing(p_empty_square_drawing);
  m_has_piece = false;
}
