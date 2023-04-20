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
  void select_next_square(const SquareIndices &n);
  void selected_square(const SquareIndices &s);
  void deselect_square(const SquareIndices &d);

 private:
  SquareIndices prev_pos{SquareNull};
  std::array<SquareDrawing, SquareEnd> m_squares;
};

#endif /* SQUARES_DRAWING_H */