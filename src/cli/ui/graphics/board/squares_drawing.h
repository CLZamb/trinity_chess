#ifndef SQUARES_DRAWING_H
#define SQUARES_DRAWING_H

#include <array>
#include "square_drawing.h"
#include "utils/move.hpp"
#include "utils/utilities.h"

class SquaresDrawings {
 public:
  SquaresDrawings();
  virtual ~SquaresDrawings();

  SquareDrawing &operator[](SquareIndices i);
  void select_next_square(const SquareIndices &new_pos) ;
  void selected_square(const SquareIndices &i) ;
  void deselected_square(const SquareIndices &i) ;
  void make_move(const Move& mv);

 private:
  SquareIndices prev_pos = A1;
  SquareIndices selected = prev_pos;
  std::array<SquareDrawing, SquareEnd> m_squares;
};

#endif /* SQUARES_DRAWING_H */
