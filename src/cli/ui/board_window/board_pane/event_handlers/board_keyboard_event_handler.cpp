#include "board_keyboard_event_handler.h" 

BoardKeyboardEventHandler::BoardKeyboardEventHandler(shared_ptr<BoardPane> b, shared_ptr<InputEvent> p)
: p_board_pane(b) {
  p->bind<CommandEventKeyboard>(&BoardKeyboardEventHandler::on_key_pressed, this);
}

void BoardKeyboardEventHandler::on_key_pressed(CommandEventKeyboard& e) {
  KeyCode::Key keycode = e.get_key_code();

  if (keycode == KeyCode::ENTER) {
    handle_event_enter();
    return;
  }

  if (is_directional_keyCode(keycode)) {
    handle_event_direction(m_keycode_dir_value.at(keycode));
    return;
  }

  std::cout << "key not supported" << std::endl;
}

bool BoardKeyboardEventHandler::is_directional_keyCode(KeyCode::Key keycode) {
  return m_keycode_dir_value.find(keycode) != m_keycode_dir_value.end();
}

void BoardKeyboardEventHandler::update_turn(const PlayerInfo& p)  {
  m_player_color = p.color;

  SquareIndices last_pos = m_player_pos.get_last_position(m_player_color);
  update_next_square(last_pos);
}

bool BoardKeyboardEventHandler::is_string_move_ready()  {
  return completed;
}

string BoardKeyboardEventHandler::get_string_move()  {
  completed = false;
  return std::move(call_back);
}

void BoardKeyboardEventHandler::update_next_square(const SquareIndices next_pos) {
  p_board_pane->update_select_next_square(next_pos);
  m_player_pos.update_next_last_position(next_pos);
}

void BoardKeyboardEventHandler::handle_event_direction(const int& dir_value) {
  int cur_pos = static_cast<int>(m_player_pos.get_next_last_position());
  int next_pos = cur_pos + dir_value;

  if (is_next_position_out_of_bounds(next_pos)) {
    std::cout << "next position is out of bound" << std::endl;
    return;
  }

  update_next_square(static_cast<SquareIndices>(next_pos));
}

void BoardKeyboardEventHandler::handle_event_enter() { 
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
