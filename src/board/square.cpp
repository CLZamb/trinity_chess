#include "headers/square.h"

Square::Square(box* emtpySqDrawing, bool blackBox):
  p_empty_square_drawing(emtpySqDrawing),
  p_cur_drawing(emtpySqDrawing),
  m_is_black_square(blackBox) {}

Square::~Square() {}

void Square::set_piece(Piece* piece) {
  this->p_piece = piece;
  p_cur_drawing = piece->get_box_drawing(m_is_black_square);
}

void Square::clear_square() {
  p_cur_drawing = p_empty_square_drawing;
}

char* Square::at(int i) {
  return p_cur_drawing->content[i];
}

bool Square::is_black_square() {
  return m_is_black_square;
}

Piece* Square::get_piece() {
  return this->p_piece;
}

box* Square::get_current_drawing() {
  return p_cur_drawing;
}
