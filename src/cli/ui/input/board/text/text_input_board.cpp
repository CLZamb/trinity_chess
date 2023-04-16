#include "text_input_board.h"

TextInputBoard::TextInputBoard() {}

TextInputBoard::~TextInputBoard() {}

void TextInputBoard::get_input_event() {
  m_events.at(Keyboard::ENTER)(KeyCode::ENTER);
}
