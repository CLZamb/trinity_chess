#include "text_input_board.h"

using std::cout;
TextInputBoard::TextInputBoard() {}

TextInputBoard::~TextInputBoard() {}

string TextInputBoard::get_next_string_move() {
  cout << " >> ";
  string next_moves =  m_text_input.get_string_input();
  return next_moves;
}
