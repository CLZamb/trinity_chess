#include "headers/square_drawing.h"

SquareDrawing::SquareDrawing() {}

SquareDrawing::SquareDrawing(bool is_black_suqare) {
  update_drawing(is_black_suqare);
}

SquareDrawing::~SquareDrawing(){}

Box* SquareDrawing::get_drawing() {
  return p_cur_drawing;
}

char* SquareDrawing::at(int i) {
  return p_cur_drawing->content[i];
}

void SquareDrawing::clear_square() {
  update_drawing(&p_empty_square_drawing);
}

void SquareDrawing::update_drawing(Box* drawing) {
  if (p_cur_drawing != drawing)
    p_cur_drawing = drawing;
}

void SquareDrawing::update_drawing(bool is_black_suqare) {
  m_black_square = is_black_suqare;

  p_empty_square_drawing = 
    (is_black_suqare)?
  *Drawing("BaseBlackSquare").get_drawing():
  *Drawing("BaseWhiteSquare").get_drawing();

  update_drawing(&p_empty_square_drawing);
}

bool SquareDrawing::is_black_square() {
  return m_black_square;
}
