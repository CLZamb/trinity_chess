#include "headers/board_input_handler.h"

BoardInputHandler::BoardInputHandler(Input &i, BoardView &b): 
  m_input(i), m_view(b), 
  m_game_turn_event(InputEvent::GameTurnChanged) {
  m_input.update_input_event_listener(this); 
}

void BoardInputHandler::update_turn(const PlayerInfo &t) {
  m_turn = t;
  m_input.dispatch_event(m_game_turn_event);
}

string BoardInputHandler::get_next_player_string_move() {
  m_string_player_input.clear();
  m_input.get_player_string_move();
  return m_string_player_input;
}

void BoardInputHandler::handle_input_event(const InputEvent& e) {
  switch(e.get_event_type()) {
    case InputEvent::Setup:
      break;
    case InputEvent::KeyPressed:
      handle_key_pressed(e.get_pressed_key());
      break;
    case InputEvent::GameTurnChanged:
      handle_type(e.get_type());
      break;
    case InputEvent::String:
      m_string_player_input = e.get_string_input();
      break;
    default:
      break;
  }
}

void BoardInputHandler::handle_type(const InputEvent::Type & t) {
  switch(t) {
    case InputEvent::Text:
      break;
    case InputEvent::Keyboard:
      m_view.select_next_square(from_pos[m_turn.color]);
      break;
  }
}

void BoardInputHandler::handle_key_pressed(const InputKeys::Key key) {
  int next_pos = to_pos[m_turn.color];

  switch(key) {
    case InputKeys::UP:
      next_pos += DIR_UP;
      break;
    case InputKeys::DOWN:
      next_pos += DIR_DOWN;
      break;
    case InputKeys::LEFT:
      next_pos += DIR_LEFT;
      break;
    case InputKeys::RIGHT:
      next_pos += DIR_RIGHT;
      break;
    case InputKeys::ENTER:
      handle_selected_position(next_pos);
      return;
    default:
      std::cout << "key not suported" << std::endl;
      return;
  }

  if (next_pos < A1 || next_pos > H8) return;

  update_view_selected_square(next_pos);

  to_pos[m_turn.color] = next_pos;
}

void BoardInputHandler::update_view_selected_square(const int &next) {
  m_view.select_next_square(next);
  m_view.print();
}

void BoardInputHandler::handle_selected_position(const int& p){ 
  m_string_player_input += utils::square_int_to_str(SquareIndices(p));

  if (from_pos_selected) {
    from_pos_selected = false;
    m_view.deselect_square(from_pos[m_turn.turn]);
    m_view.print();
    return;
  }

  m_view.selected_square(p);
  m_view.print();
  from_pos[m_turn.turn] = to_pos[m_turn.turn];
  from_pos_selected = true;

  m_input.get_player_string_move();
}
