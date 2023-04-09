#include "text_input_board.h"

using std::cout;
TextInputBoard::TextInputBoard() {}

TextInputBoard::~TextInputBoard() {}

bool TextInputBoard::is_preselect(const string& s) {
  std::cout << s << std::endl;
  return true;
}

string TextInputBoard::get_next_string_move(BoardView& bv) {
  cout << " >> ";
  string next_moves =  m_text_input.get_string_input();

  if (is_preselect(next_moves)) bv.select_next_square(A1);

  return next_moves;
}
