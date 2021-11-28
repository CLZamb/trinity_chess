#include "headers/square.h"

Square::Square(bool is_black_square):
  square_drawing(is_black_square),
  m_is_black_square(is_black_square) {}

Square::~Square() {}

void Square::set_piece(Piece* piece) {
  if (piece == nullptr) {
    cout << "piece not found" << endl;
    return;
  }

  this->p_piece = piece;
  square_drawing.update_drawing(this->p_piece->get_drawing(m_is_black_square));
}

void Square::clear_square() {
  this->p_piece = nullptr;
  square_drawing.clear_square();
}

char* Square::at(int i) {
  return square_drawing.at(i);
}

bool Square::is_black_square() {
  return m_is_black_square;
}

Piece* Square::get_piece() {
  return this->p_piece;
}
