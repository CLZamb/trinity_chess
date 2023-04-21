#include "board_text_event_handler.h"

BoardTextEventHandler::BoardTextEventHandler(std::shared_ptr<BoardPane> b, shared_ptr<InputEvent> p)
: p_board_pane(b) {
  p->bind<CommandEventText>(&BoardTextEventHandler::handle_string_input, this);
}

bool BoardTextEventHandler::is_string_move_ready() {
  return true; 
}

string BoardTextEventHandler::get_string_move() { 
  return call_back; 
}

void BoardTextEventHandler::handle_string_input(CommandEventText& e) {
  call_back = e.get_string();
}

