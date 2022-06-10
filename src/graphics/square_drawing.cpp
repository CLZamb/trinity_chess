#include "headers/square_drawing.h"

DrawingMod SquaresDrawings::mod;

SquareDrawing::SquareDrawing() : 
  p_empty_square_drawing(&DrawingPieces::const_piece_drawing.at("BaseSquare")) {
  p_cur_drawing = p_empty_square_drawing;
}

SquareDrawing::SquareDrawing(bool is_black_square) {
  update_drawing(is_black_square);
}

SquareDrawing::~SquareDrawing() {}

const Box* SquareDrawing::get_drawing() {
  return p_cur_drawing;
}

const char* SquareDrawing::at(int i) {
  return p_cur_drawing->content[i];
}

void SquareDrawing::clear_square() {
  update_drawing(p_empty_square_drawing);
}

void SquareDrawing::update_drawing(const Box* drawing) {
  if (p_cur_drawing != drawing)
    p_cur_drawing = drawing;
}

void SquareDrawing::update_drawing(bool is_black_square) {
  m_black_square = is_black_square;

  p_empty_square_drawing = 
    is_black_square ? 
      &DrawingPieces::const_piece_drawing.at("BlackSquare") : 
      &DrawingPieces::const_piece_drawing.at("BaseSquare");

  p_cur_drawing = p_empty_square_drawing;
}

bool SquareDrawing::is_black_square() {
  return m_black_square;
}
