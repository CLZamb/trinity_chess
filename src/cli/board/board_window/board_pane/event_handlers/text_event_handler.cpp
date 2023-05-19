#include "text_event_handler.h"

std::string TextEventHandler::get_move_as_string() {
  return m_string_move;
}

void TextEventHandler::handle_string_input(EventText &e) {
  m_string_move = e.get_text();
  send_event(e);
}
