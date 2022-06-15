#include "headers/square_drawing.h"

DrawingMod SquareDrawing::mod;

SquareDrawing::SquareDrawing() : 
  p_empty_square_drawing(&
      DrawingPieces::const_piece_drawing.at(
      DrawingPieces::white_square_str_name)) {
    update_drawing(p_empty_square_drawing);
}

SquareDrawing::SquareDrawing(bool is_black_square) {
  set_base_square_drawing(is_black_square);
}

SquareDrawing::~SquareDrawing() {}

const Box* SquareDrawing::get_drawing() { return p_cur_drawing; }
const char* SquareDrawing::at(int i) { return p_cur_drawing->content[i]; }
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
  update_drawing(p_empty_square_drawing);
  m_has_piece = false;
}

void SquareDrawing::set_piece_drawing(const Box* drawing) {
  p_piece_square_drawing = drawing;
  update_drawing(p_piece_square_drawing);
  m_has_piece = true;
}

void SquareDrawing::update_drawing(const Box* drawing) {
  if (p_cur_drawing != drawing)
    p_cur_drawing = drawing;
}

void SquareDrawing::deselect() {
  update_drawing(get_original_drawing());
}

void SquareDrawing::select() {
  if (p_cur_drawing == nullptr) return;

  m_select_drawing = *get_original_drawing();

  mod.add_attribute(DrawingMod::BG_INVERSE, &m_select_drawing);
  update_drawing(&m_select_drawing);
}

void SquareDrawing::set_base_square_drawing(bool is_black_square) {
  m_black_square = is_black_square;

  p_empty_square_drawing = 
    is_black_square ? 
      &DrawingPieces::const_piece_drawing.at(
        DrawingPieces::black_square_str_name) : 
      &DrawingPieces::const_piece_drawing.at(
        DrawingPieces::white_square_str_name);

  update_drawing(p_empty_square_drawing);
  m_has_piece = false;
}
