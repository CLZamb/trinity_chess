#include "headers/square_drawing.h"

SquareDrawing::SquareDrawing(bool is_black_suqare) {
  p_empty_square_drawing = 
    (is_black_suqare)?
  *Drawing("BaseBlackSquare").get_drawing():
  *Drawing("BaseWhiteSquare").get_drawing();

  p_cur_drawing = &p_empty_square_drawing;
}

SquareDrawing::~SquareDrawing(){}

Box* SquareDrawing::get_drawing() {
  return p_cur_drawing;
}

char* SquareDrawing::at(int i) {
  return p_cur_drawing->content[i];
}

void SquareDrawing::clear_square() {
  p_cur_drawing = &p_empty_square_drawing;
}

void SquareDrawing::update_drawing(Box* drawing) {
  p_cur_drawing = drawing;
}


