#include "text_input_board.h"

using std::cout;
TextInputBoard::TextInputBoard() {}

TextInputBoard::~TextInputBoard() {}

void TextInputBoard::update_turn(const PlayerInfo &p) {
  std::cout << p.color << std::endl;
}
// bool TextInputBoard::is_preselect(const string& s) {
//   std::cout << s << std::endl;
//   return false;
// }

BoardInput::InputEvent TextInputBoard::get_next_string_move(string& next_moves) {
  cout << " >> ";
  next_moves =  m_text_input.get_string_input();
  // if (is_preselect(next_moves)) bv.select_next_square(A1);

  return InputEvent::COMPLETED;
}
