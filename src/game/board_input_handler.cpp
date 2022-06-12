#include "headers/board_input_hanlder.h"

BoardInputHanlder::BoardInputHanlder(Input &i, BoardView &b): m_input(i), m_view(b) {
  m_input.update_listener(this); 
}

void BoardInputHanlder::update_turn(const PlayerInfo &t) {
  m_turn = t;
}

string BoardInputHanlder::get_next_player_string_move() {
  m_input.get_player_string_move();
  return m_string_player_input;
}

void BoardInputHanlder::handle_input_event(const InputEvent& e) {
  switch(e.get_type()) {
    case InputEvent::KeyPressed:
      handle_key_pressed(e.get_pressed_key());
      break;
    case InputEvent::KeyboardSetup:
      m_view.select_square(pos[m_turn.turn]);
      break;
    case InputEvent::StringInput:
      m_string_player_input = e.get_string_input();
      break;
    default:
      break;
  }
}

void BoardInputHanlder::handle_key_pressed(const InputKeys::Key key) {
  int prev_pos = pos[m_turn.turn];

  switch(key) {
    case InputKeys::UP:
      pos[m_turn.turn] += DIR_UP;
      break;
    case InputKeys::DOWN:
      pos[m_turn.turn] += DIR_DOWN;
      break;
    case InputKeys::LEFT:
      pos[m_turn.turn] += DIR_LEFT;
      break;
    case InputKeys::RIGHT:
      pos[m_turn.turn] += DIR_RIGHT;
      break;
    case InputKeys::ENTER:
      m_string_player_input = 
        utils::square_int_to_str(SquareIndices(from_pos[m_turn.turn])) + 
        utils::square_int_to_str(SquareIndices(pos[m_turn.turn]));
      return;
    default:
      return;
  }

  if (pos[m_turn.turn] > H8) {
    pos[m_turn.turn] = prev_pos;
    return;
  }

  if (pos[m_turn.turn] < A1) { 
    pos[m_turn.turn] = prev_pos;
    return;
  }

  m_view.deselect_square(prev_pos);
  m_view.select_square(pos[m_turn.turn]);

  m_view.print();
}

