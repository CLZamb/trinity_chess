#include "keyboard_board_pane.h"

using std::string;

KeyboardBoardPane::KeyboardBoardPane(const std::unique_ptr<KeyboardInput> &p,
                                     const BoardConfigInfo &b_config)
    : m_player_pos(b_config.initial_side)
    , m_square_selector(BoardPane::m_square_drawings,
                        m_player_pos.get_cur_position()) {
  p->bind<CommandEventKeyboard>(&KeyboardBoardPane::on_key_pressed, this);

  BoardPane::parse_fen(b_config.fen_fields);
  BoardPane::update_drawing();
}

KeyboardBoardPane::~KeyboardBoardPane() {}

void KeyboardBoardPane::make_move(const Move &move) {
  m_player_pos.switch_side();
  select_next_square(m_player_pos.get_cur_position());
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
    BoardPane::update_drawing();
    return;
  }

  handle_direction_key_event(keycode);
  BoardPane::update_drawing();
}

void KeyboardBoardPane::handle_direction_key_event(
    const KeyCode::Key &keycode) {
  const Square next_pos = m_player_pos.get_next_position(keycode);
  select_next_square(next_pos);
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
  return StringUtils::squareindex_to_str(pos);
}

void KeyboardBoardPane::select_next_square(const Square &next) {
  m_square_selector.select_next(m_square_drawings[next]);
}

void KeyboardBoardPane::update_selected_square(const Square &next) {
  m_square_selector.set_selected(m_square_drawings[next]);
}

void KeyboardBoardPane::restore_previous_selected_squares() {
  m_square_selector.remove_previous_selected();
}
