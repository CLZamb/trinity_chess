#include "board_text_event_handler.h"

BoardTextEventHandler::BoardTextEventHandler(BoardPane& b, const std::unique_ptr<Input>& p)
: m_board_pane(b) {
  p->bind<CommandEventText>(&BoardTextEventHandler::handle_string_input, this);
}

bool BoardTextEventHandler::is_player_string_move_ready() {
  return true; 
}

string BoardTextEventHandler::get_player_move_as_string() { 
  return m_string_move; 
}

void BoardTextEventHandler::handle_string_input(CommandEventText& e) {
  m_string_move = e.get_text();
}

