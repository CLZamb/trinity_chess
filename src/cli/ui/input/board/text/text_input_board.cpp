#include "text_input_board.h"

TextInputBoard::TextInputBoard() {}

TextInputBoard::~TextInputBoard() {}

KeyCode::Key TextInputBoard::get_input_event() {
  return KeyCode::ENTER;
}
