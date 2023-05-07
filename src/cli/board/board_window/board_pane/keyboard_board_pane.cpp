#include "keyboard_board_pane.h"

KeyboardBoardPane::KeyboardBoardPane(const std::unique_ptr<KeyboardInput> &p,
                                     const FenFields &fen,
                                     Color initial_side)
    : m_player_pos(initial_side)
    , m_drawing_selector(m_squares_drawings, m_player_pos.get_cur_position()) {
  BoardPane::parse_fen(fen);

  p->bind<CommandEventKeyboard>(&KeyboardBoardPane::on_key_pressed, this);
  BoardPane::update_drawing();
}

KeyboardBoardPane::~KeyboardBoardPane() {}

void KeyboardBoardPane::make_move(const Move &move) {
  m_player_pos.switch_side();
  Square cur_pos = m_player_pos.get_cur_position();
  update_select_next_square_drawing(cur_pos);
  BoardPane::make_move(move);
}

bool KeyboardBoardPane::is_player_string_move_ready() { return completed; }

string KeyboardBoardPane::get_player_move_as_string() {
  completed = false;
  return std::move(m_string_move);
}

void KeyboardBoardPane::on_key_pressed(CommandEventKeyboard &e) {
  KeyCode::Key keycode = e.get_key_code();

  if (keycode == KeyCode::ENTER) {
    handle_enter_key_event();
    return;
  }

  handle_direction_key_event(keycode);
}

void KeyboardBoardPane::handle_direction_key_event(
    const KeyCode::Key &keycode) {
  const Square next_pos = m_player_pos.get_next_position(keycode);
  update_select_next_square_drawing(next_pos);
}

void KeyboardBoardPane::handle_enter_key_event() {
  Square cur_pos = m_player_pos.get_cur_position();

  m_string_move += get_selected_position_as_string(cur_pos);

  completed = has_been_selected;
  has_been_selected = !has_been_selected;

  if (completed) {
    restore_previous_selected_squares();
  } else {
    update_selected_square(cur_pos);
  }
}

string KeyboardBoardPane::get_selected_position_as_string(const Square &pos) {
  return string_utils::squareindex_to_str(pos);
}

void KeyboardBoardPane::update_select_next_square_drawing(const Square &next) {
  m_drawing_selector.select_next(m_squares_drawings[next]);
  BoardPane::update_drawing();
}

void KeyboardBoardPane::update_selected_square(const Square &next) {
  m_drawing_selector.set_selected(m_squares_drawings[next]);
  BoardPane::update_drawing();
}

void KeyboardBoardPane::restore_previous_selected_squares() {
  m_drawing_selector.remove_previous_selected();
  BoardPane::update_drawing();
}
