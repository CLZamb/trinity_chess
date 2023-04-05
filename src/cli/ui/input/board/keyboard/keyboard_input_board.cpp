#include "keyboard_input_board.h"

const string KeyboardInputBoard::key_not_supported = "key not supported\n";

KeyboardInputBoard::KeyboardInputBoard(BoardView& bv) : m_board_view(bv) {}

string KeyboardInputBoard::get_next_string_move() {
  update_view_select_next_square(m_player_pos.get_last_position());
  m_board_view.update_board_drawing();
  m_board_view.print();

  completed = false;
  has_been_selected = false;

  string next_move{""};
  size_t next_pos = m_player_pos.get_last_position();

  while (!completed) {
    switch (InputKeyboardKeys::Key key = m_k_input.read_key(); key) {
      case InputKeyboardKeys::ARROW_KEY:
        handle_arrow_keys(m_k_input.read_arrow_key(), next_pos);
        break;
      case InputKeyboardKeys::W:
      case InputKeyboardKeys::A:
      case InputKeyboardKeys::S:
      case InputKeyboardKeys::D:
        handle_arrow_keys(key, next_pos);
        break;
      case InputKeyboardKeys::ENTER:
        next_move += select_position(next_pos);
        update_view_selected_square(next_pos);
        selected_positions.push_back(next_pos);
        break;
      default:
        std::cout << key_not_supported << std::endl;
        break;
    }

    update_view_select_next_square(next_pos);

  m_board_view.update_board_drawing();
    m_board_view.print();
  }

  deselect_all_previous_selected_squares();
  update_last_position(next_pos);
  return next_move;
}

void KeyboardInputBoard::deselect_all_previous_selected_squares() {
  for (const size_t &pos : selected_positions)
    update_view_deselected_square(pos);
  selected_positions.clear();
}

void KeyboardInputBoard::update_last_position(const size_t &pos) {
  m_player_pos.update_last_position(pos);
}

void KeyboardInputBoard::handle_arrow_keys(const InputKeyboardKeys::Key &k, size_t &pos) {
  size_t prev = pos;
  int _pos = static_cast<int>(pos);

  if (_pos >= 0)
    _pos += m_direction_value[k];

  pos = static_cast<size_t>(_pos);

  if (pos < A1 || pos > H8)
    pos = prev;
}

string KeyboardInputBoard::select_position(const size_t &pos) {
  if (has_been_selected) {
    select_to(pos);
  } else {
    select_from(pos);
  }

  has_been_selected = !has_been_selected;
  return string_utils::squareindex_to_str(SquareIndices(pos));
}

void KeyboardInputBoard::select_from(const size_t pos) {
  m_player_pos.set_from_position(pos);
}

void KeyboardInputBoard::select_to(const size_t pos) {
  completed = true;
  m_player_pos.set_to_position(pos);
}

void KeyboardInputBoard::update_view_select_next_square(const size_t &next) {
  m_board_view.select_next_square(next);
}

void KeyboardInputBoard::update_view_selected_square(const size_t &p) {
  m_board_view.selected_square(p);
}

void KeyboardInputBoard::update_view_deselected_square(const size_t &p) {
  m_board_view.deselect_square(p);
}
