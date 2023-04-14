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

 private:
  std::array<SquareDrawing, SquareEnd> m_squares;
};

#endif /* SQUARES_DRAWING_H */
