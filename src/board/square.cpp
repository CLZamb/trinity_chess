#include "headers/square.h"

Square::Square() {}
Square::~Square() {}

void Square::set_piece(Piece* piece) {
  if (piece == nullptr) {
    cout << "piece not found" << endl;
    return;
  }

  this->p_piece = piece;
}

void Square::clear_square() {
  this->p_piece = nullptr;
}

Piece* Square::get_piece() {
  return this->p_piece;
}
