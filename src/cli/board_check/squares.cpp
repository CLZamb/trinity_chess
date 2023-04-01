#include "squares.h"

Squares::Squares() {}
Squares::~Squares() {}

Square &Squares::operator[](size_t i) {
  return m_squares[i];
}

void Squares::clear() {
  for (auto &square : m_squares) {
    square.clear_square();
  }
}

void Squares::do_move(const SquareIndices &from, const SquareIndices &to) {
  m_squares[to].set_piece(m_squares[from].get_piece());
  m_squares[from].clear_square();
}

bool Squares::exist_piece_at_position(const unsigned int &pos) {
  return m_squares[pos].get_piece() != EMPTY;
}
