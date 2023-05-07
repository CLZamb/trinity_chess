#include "square_drawings.h"

#include "board/board_window/board_pane/squares/square_drawing_info.hpp"

SquaresDrawings::SquaresDrawings() {
  char squareColor = 'w';

  WhiteSquareDrawingInfo m_w_sq_drw_info;
  BlackSquareDrawingInfo m_b_sq_drw_info;

  static const int col_size = 7;
  static const int row_size = 8;
  Square position = A1;
  /*
   * Rows needs to be ordered upside down
   * because the program prints from top to bottom
   * so that the 8th row should be printed frist
   */
  for (int row = col_size; row >= 0; --row) {
    for (int col = 0; col < row_size; ++col) {
      /*
       * there are 8*8 (from 0 to 63) squares
       * to get the position
       * we need to multyply rwo by 8 and add the col
       * i.e the bottom right position would be
       * 8 * 0 + 7 = 7
       */
      position = static_cast<Square>(row * 8 + col);
      if (squareColor == 'b') {
        squareColor = 'w';
        m_squares[position] = new SquareDrawing(m_w_sq_drw_info);
      } else {
        squareColor = 'b';
        m_squares[position] = new SquareDrawing(m_b_sq_drw_info);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

SquaresDrawings::~SquaresDrawings() {
  for (auto square : m_squares) delete square;
}

SquareDrawing *SquaresDrawings::operator[](Square i) { return m_squares[i]; }

void SquaresDrawings::move_piece(const Square &from, const Square &to) {
  std::unique_ptr<IPieceDrawing> moved_piece =
      m_squares[from]->remove_piece_drawing();
  m_squares[to]->set_piece_drawing(std::move(moved_piece));
}

void SquaresDrawings::set_piece_at_square(Piece type, int position) {
  std::unique_ptr<IPieceDrawing> piece_drawing =
      m_pieces_drawings.new_piece_drawing(type);

  m_squares[static_cast<Square>(position)]->set_piece_drawing(
      std::move(piece_drawing));
}

void SquaresDrawings::remove_piece_at_square(int position) {
  m_squares[static_cast<Square>(position)]->remove_piece_drawing();
}

void SquaresDrawings::clear_square_at_pos(int position) {
  m_squares[static_cast<Square>(position)]->clear();
}
