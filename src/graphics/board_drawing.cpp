#include "headers/board_drawing.h"


BoardDrawing::BoardDrawing(Square* p_squares[]) : 
  p_squares{p_squares} {
}

BoardDrawing::~BoardDrawing() {}

void BoardDrawing::_init() {
  p_top_section = std::make_unique<Section>("top", 1);
  p_main = std::make_unique<Section>("board", 40);
  p_bottom_section = std::make_unique<Section>("bottom", 3);

  p_top_section->set_content_at_index(
       " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓", 0);
  p_bottom_section->set_content({
       " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
       " ┃    A        B        C        D        E        F        G       H     ┃",
       " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"});

  m_drawing.add_section(p_top_section);
  m_drawing.add_section(p_main);
  m_drawing.add_section(p_bottom_section);
}

void BoardDrawing::draw() {
  int row_counter = 0;
  string row_drawing = "";
  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < Box::kRowSize; ++k, row_counter++) {
      row_drawing = "";

      row_drawing += left_border(row, k);
      row_drawing += "┃";

      for (int col = 0; col < 8; col++) {
        row_drawing += p_squares[(row * 8) + col]->at(k);
      }

      row_drawing += "┃";
      p_main->set_content_at_index(row_drawing, row_counter);
    }
  }
}

char BoardDrawing::left_border(int row, int col) {
  return (col + 1) % 3 ? ' ' :  ('0' + row + 1);
}
