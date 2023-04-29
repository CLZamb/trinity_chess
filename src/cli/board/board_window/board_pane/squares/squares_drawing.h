#ifndef SQUARES_DRAWING_H
#define SQUARES_DRAWING_H

#include <array>

#include "square_drawing.h"
#include "utils/move.hpp"

class SquaresDrawings {
 public:
  SquaresDrawings();
  virtual ~SquaresDrawings() = default;

  SquareDrawing &operator[](Square i);
  void select_next_square(const Square &n);
  void selected_square(const Square &s);
  void deselect_square(const Square &d);

 private:
  Square prev_pos{SquareNull};
  std::array<SquareDrawing, SquareEnd> m_squares;
};

#endif /* SQUARES_DRAWING_H */
