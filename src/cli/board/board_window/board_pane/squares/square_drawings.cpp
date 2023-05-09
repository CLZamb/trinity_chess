#include "square_drawings.h"

#include "board/board_window/board_pane/squares/square_drawing_info.hpp"

SquaresDrawings::SquaresDrawings() {
  char squareColor = 'b';

  for (Square sq = SquareBegin; sq < SquareEnd; ++sq) {
    if (squareColor == 'b') {
      m_squares[sq] = new BlackSquareDrawing();
    } else {
      m_squares[sq] = new WhiteSquareDrawing();
    }

    if ((sq + 1) % 8) { squareColor = squareColor == 'b' ? 'w' : 'b'; }
  }
}

SquaresDrawings::~SquaresDrawings() {
  for (auto square : m_squares) delete square;
}

SquareDrawing *SquaresDrawings::operator[](Square i) { return m_squares[i]; }

void SquaresDrawings::move_piece(const Square &from, const Square &to) {
  auto moved_piece = m_squares[from]->remove_piece_drawing();
  m_squares[to]->set_piece_drawing(std::move(moved_piece));
}

Square SquaresDrawings::to_sq(int &pos) { return static_cast<Square>(pos); }

void SquaresDrawings::set_piece_at_square(Piece type, int position) {
  auto piece_drawing = m_pieces_drawings.new_piece_drawing(type);

  m_squares[to_sq(position)]->set_piece_drawing(std::move(piece_drawing));
}

void SquaresDrawings::remove_piece_at_square(int position) {
  m_squares[to_sq(position)]->remove_piece_drawing();
}

void SquaresDrawings::clear_square_at_pos(int position) {
  m_squares[to_sq(position)]->clear();
}
