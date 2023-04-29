#include "board_text_event_handler.h"

BoardTextEventHandler::BoardTextEventHandler(BoardPane& b, const std::unique_ptr<InputEvent>& p)
: m_board_pane(b) {
  p->bind<CommandEventText>(&BoardTextEventHandler::handle_string_input, this);
}

bool BoardTextEventHandler::is_string_move_ready() {
  return true; 
}

string BoardTextEventHandler::get_player_move_as_string() { 
  return call_back; 
}

void BoardTextEventHandler::handle_string_input(CommandEventText& e) {
  call_back = e.get_string();
}

