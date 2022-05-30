#ifndef SQUARE_DRAWING_H
#define SQUARE_DRAWING_H

#include "pieces_drawings.hpp"

class SquareDrawing {
public:
  SquareDrawing();
  SquareDrawing(bool is_black_squared);
  virtual ~SquareDrawing();
  Box* get_drawing();
  char* at(int i);
  void clear_square();
  void update_drawing(Box* drawing);
  void update_drawing(bool is_black_square);
  bool is_black_square();

private:
  Box p_empty_square_drawing;
  Box* p_cur_drawing = nullptr;
  bool m_black_square = false;
};

#endif /* SQUARE__DRAWING_H */
