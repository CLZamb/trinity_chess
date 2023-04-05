#ifndef SQUARES_DRAWING_H
#define SQUARES_DRAWING_H

#include <array>
#include "square_drawing.h"
#include "utils/utilities.h"

class SquaresDrawings {
 public:
  SquaresDrawings();
  virtual ~SquaresDrawings();

  SquareDrawing &operator[](size_t i);
  void select_next_square(const size_t &new_pos) ;
  void selected_square(const size_t &i) ;
  void deselected_square(const size_t &i) ;

 private:
  size_t prev_pos = A1;
  std::array<SquareDrawing, utils::constant::ksquares> m_squares;
};

#endif /* SQUARES_DRAWING_H */
