#include "squares_drawing.h"

SquaresDrawings::SquaresDrawings() {
  char squareColor = 'w';
  bool is_black_squared = true;

  static const int col_size = 7;
  static const int row_size = 8;
  SquareIndices position = A1;
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
      position = static_cast<SquareIndices> (row * 8 + col);
      if (squareColor == 'b') {
        squareColor = 'w';
        m_squares[position].set_base_square_drawing(!is_black_squared);
      } else {
        squareColor = 'b';
        m_squares[position].set_base_square_drawing(is_black_squared);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

SquaresDrawings::~SquaresDrawings() {}

SquareDrawing &SquaresDrawings::operator[](SquareIndices i) {
  return m_squares[i];
}
