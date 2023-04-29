#include "board_keyboard_event_handler.h" 

BoardKeyboardEventHandler::BoardKeyboardEventHandler(BoardPane& b, const std::unique_ptr<InputEvent>& p)
: m_board_pane(b) {
  p->bind<CommandEventKeyboard>(&BoardKeyboardEventHandler::on_key_pressed, this);
}

void BoardKeyboardEventHandler::on_key_pressed(CommandEventKeyboard& e) {
  KeyCode::Key keycode = e.get_key_code();

  if (keycode == KeyCode::ENTER) {
    handle_enter_key_event();
    return;
  }

  switch(keycode) {
    case KeyCode::DOWN:
      handle_direction_key_event(DIR_DOWN);
      break;
    case KeyCode::UP:
      handle_direction_key_event(DIR_UP);
      break;
    case KeyCode::LEFT:
      handle_direction_key_event(DIR_LEFT);
      break;
    case KeyCode::RIGHT:
      handle_direction_key_event(DIR_RIGHT);
      break;
    default:
      std::cout << "key not supported" << std::endl;
      break;
  }
}

void BoardKeyboardEventHandler::update_turn(const Color& c)  {
  m_player_color = c;

  Square last_pos = m_player_pos.get_last_position(m_player_color);
  update_next_square(last_pos);
}

bool BoardKeyboardEventHandler::is_string_move_ready()  {
  return completed;
}

string BoardKeyboardEventHandler::get_player_move_as_string()  {
  completed = false;
  return std::move(call_back);
}

void BoardKeyboardEventHandler::update_next_square(const Square next_pos) {
  m_board_pane.update_select_next_square(next_pos);
  m_player_pos.update_next_last_position(next_pos);
}

void BoardKeyboardEventHandler::handle_direction_key_event(const int& dir_value) {
  int cur_pos = static_cast<int>(m_player_pos.get_next_last_position());
  int next_pos = cur_pos + dir_value;

  if (is_next_position_out_of_bounds(next_pos)) {
    std::cout << "next position is out of bound" << std::endl;
    return;
  }

  update_next_square(static_cast<Square>(next_pos));
}

void BoardKeyboardEventHandler::handle_enter_key_event() { 
  Square cur_pos = m_player_pos.get_next_last_position();

  call_back += select_position(cur_pos);

  completed = has_been_selected;
  has_been_selected = !has_been_selected;

  if (completed) {
    m_board_pane.deselect_all_previous_selected_squares();
    m_player_pos.update_last_position(m_player_color);
  } else {
    m_board_pane.update_selected_square(cur_pos);
  }
}

string BoardKeyboardEventHandler::select_position(const Square &pos) {
  return string_utils::squareindex_to_str(Square(pos));
}

bool BoardKeyboardEventHandler::is_next_position_out_of_bounds(int next_pos) {
  return (next_pos < square_A1) || (next_pos > square_H8);
}
