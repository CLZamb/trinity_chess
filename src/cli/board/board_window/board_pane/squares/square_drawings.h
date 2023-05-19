#ifndef SQUARES_DRAWING_H
#define SQUARES_DRAWING_H

#include "board/board_window/board_pane/pieces/pieces_drawings.hpp"
#include "board/board_window/board_pane/squares/square_drawing.h"
#include "utils/move.hpp"

class SquaresDrawings {
 public:
  SquaresDrawings();
  virtual ~SquaresDrawings();

  SquareDrawing& operator[](size_t i) {
    return *m_squares.at(i);
  }

  void move_piece(const Square &from, const Square &to);
  void set_piece_at_square(Piece type, int position);
  void remove_piece_at_square(int position);
  void clear_square_at_pos(int position);

 private:
  Square to_sq(int &pos);
  std::array<SquareDrawing*, SquareEnd> m_squares;
  PiecesDrawings m_pieces_drawings;
};

#endif /* SQUARES_DRAWING_H */
