#include "board_text_event_handler.h"

BoardTextEventHandler::BoardTextEventHandler(std::shared_ptr<BoardPane> b, shared_ptr<Input> p)
: p_board_pane(b) {
  p->bind(TextInput::STRING, &BoardTextEventHandler::handle_string_input, this);
}

bool BoardTextEventHandler::has_events() { return false; }

string BoardTextEventHandler::get_string() { return call_back; }

void BoardTextEventHandler::handle_string_input(CommandEvent & e) {
  call_back = e.get_string();
}

