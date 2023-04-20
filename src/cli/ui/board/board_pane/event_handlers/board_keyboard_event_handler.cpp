#include "board_keyboard_event_handler.h" 

BoardKeyboardEventHandler::BoardKeyboardEventHandler(shared_ptr<BoardPane> b, shared_ptr<Input> p)
: p_board_pane(b) {

  p->bind(Keyboard::W, &BoardKeyboardEventHandler::handle_event_direction, this);
  p->bind(Keyboard::A, &BoardKeyboardEventHandler::handle_event_direction, this);
  p->bind(Keyboard::S, &BoardKeyboardEventHandler::handle_event_direction, this);
  p->bind(Keyboard::D, &BoardKeyboardEventHandler::handle_event_direction, this);

  p->bind(Keyboard::UP, &BoardKeyboardEventHandler::handle_event_direction, this);
  p->bind(Keyboard::DOWN, &BoardKeyboardEventHandler::handle_event_direction, this);
  p->bind(Keyboard::LEFT, &BoardKeyboardEventHandler::handle_event_direction, this);
  p->bind(Keyboard::RIGHT, &BoardKeyboardEventHandler::handle_event_direction, this);

  p->bind(Keyboard::ENTER, &BoardKeyboardEventHandler::handle_event_enter, this);
}

void BoardKeyboardEventHandler::update_turn(const PlayerInfo& p)  {
  m_player_color = p.color;

  SquareIndices last_pos = m_player_pos.get_last_position(m_player_color);
  update_next_square(last_pos);
}

bool BoardKeyboardEventHandler::has_events()  {
  return !completed;
}

string BoardKeyboardEventHandler::get_string()  {
  completed = false;
  return std::move(call_back);
}

void BoardKeyboardEventHandler::update_next_square(const SquareIndices next_pos) {
  p_board_pane->update_select_next_square(next_pos);
  m_player_pos.update_next_last_position(next_pos);
}

void BoardKeyboardEventHandler::handle_event_direction(CommandEvent& e) {
  int dir_value = m_direction_value.at(e.get_key_code());
  int cur_pos = static_cast<int>(m_player_pos.get_next_last_position());
  int next_pos = cur_pos + dir_value;

  if (is_next_position_out_of_bounds(next_pos)) {
    std::cout << "next position is out of bound" << std::endl;
    return;
  }

  update_next_square(static_cast<SquareIndices>(next_pos));
}

void BoardKeyboardEventHandler::handle_event_enter(CommandEvent&) { 
  SquareIndices cur_pos = m_player_pos.get_next_last_position();

  call_back += select_position(cur_pos);

  completed = has_been_selected;
  has_been_selected = !has_been_selected;

  if (completed) {
    p_board_pane->deselect_all_previous_selected_squares();
    m_player_pos.update_last_position(m_player_color);
  } else {
    p_board_pane->update_selected_square(cur_pos);
  }
}

string BoardKeyboardEventHandler::select_position(const SquareIndices &pos) {
  return string_utils::squareindex_to_str(SquareIndices(pos));
}

bool BoardKeyboardEventHandler::is_next_position_out_of_bounds(int next_pos) {
  return (next_pos < square_A1) || (next_pos > square_H8);
}
