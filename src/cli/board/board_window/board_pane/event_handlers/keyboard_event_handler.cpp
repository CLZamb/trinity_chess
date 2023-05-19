#include "keyboard_event_handler.h"

using std::string;

KeyboardEventHandler::KeyboardEventHandler(
    const Color &initial_side,
    BoardPaneView &pane_view)
    : m_board_view(pane_view)
    , m_player_pos(initial_side)
    , m_square_selector(m_board_view.get_square(m_player_pos.get_cur_position())) {
  m_input.bind(&KeyboardEventHandler::on_key_pressed, this);
}

KeyboardEventHandler::~KeyboardEventHandler() {}

void KeyboardEventHandler::change_side() {
  m_player_pos.switch_side();
  select_next_square(m_player_pos.get_cur_position());
}

string KeyboardEventHandler::get_move_as_string() {
  do {
    m_input.send_event_input_to_listeners();
  } while (!m_completed);

  m_completed = false;
  return std::move(m_string_move);
}

void KeyboardEventHandler::on_key_pressed(EventKeyboard &e) {
  KeyCode::Key keycode = e.get_key_code();

  switch (keycode) {
    case KeyCode::ENTER:
      handle_enter();
      break;
    case KeyCode::UP:
    case KeyCode::DOWN:
    case KeyCode::RIGHT:
    case KeyCode::LEFT:
      handle_direction(keycode);
    default:
      break;
  }

  send_event(e);
}

void KeyboardEventHandler::handle_direction(const KeyCode::Key &keycode) {
  const Square next_pos = m_player_pos.get_next_position(keycode);
  select_next_square(next_pos);
}

void KeyboardEventHandler::handle_enter() {
  m_string_move += get_cur_position_as_string();

  m_str_move_selected_counter++;

  if (m_str_move_selected_counter == 2) {
    m_str_move_selected_counter = 0;

    restore_previous_selected_squares();

    m_completed = true;
  } else {
    update_selected_square(m_player_pos.get_cur_position());
  }
}

string KeyboardEventHandler::get_cur_position_as_string() {
  return StringUtils::square_to_str(m_player_pos.get_cur_position());
}

void KeyboardEventHandler::select_next_square(const Square &next) {
  m_square_selector.select_next(m_board_view.get_square(next));
}

void KeyboardEventHandler::update_selected_square(const Square &next) {
  m_square_selector.set_selected(m_board_view.get_square(next));
}

void KeyboardEventHandler::restore_previous_selected_squares() {
  m_square_selector.remove_previous_selected();
}
