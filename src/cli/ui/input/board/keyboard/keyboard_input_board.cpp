#include "keyboard_input_board.h"

const string KeyboardInputBoard::key_not_supported = "key not supported\n";

KeyboardInputBoard::KeyboardInputBoard() {}

string KeyboardInputBoard::get_next_string_move(BoardView& board_view) {
  update_view_select_next_square(m_player_pos.get_last_position(), board_view);
  board_view.update_board_drawing();
  board_view.print();

  completed = false;
  has_been_selected = false;

  string next_move{""};
  size_t next_pos = m_player_pos.get_last_position();

  while (!completed) {
    switch (Keyboard::Key key = m_k_input.read_key(); key) {
      case Keyboard::ARROW_KEY:
        handle_arrow_keys(m_k_input.read_arrow_key(), next_pos);
        break;
      case Keyboard::W:
      case Keyboard::A:
      case Keyboard::S:
      case Keyboard::D:
        handle_arrow_keys(key, next_pos);
        break;
      case Keyboard::ENTER:
        next_move += select_position(next_pos);
        update_view_selected_square(next_pos, board_view);
        selected_positions.push_back(next_pos);
        break;
      default:
        std::cout << key_not_supported << std::endl;
        break;
    }

    update_view_select_next_square(next_pos, board_view);

  board_view.update_board_drawing();
    board_view.print();
  }

  deselect_all_previous_selected_squares(board_view);
  update_last_position(next_pos);
  return next_move;
}

void KeyboardInputBoard::deselect_all_previous_selected_squares(BoardView& bv) {
  for (const size_t &pos : selected_positions)
    update_view_deselected_square(pos, bv);
  selected_positions.clear();
}

void KeyboardInputBoard::update_last_position(const size_t &pos) {
  m_player_pos.update_last_position(pos);
}

void KeyboardInputBoard::handle_arrow_keys(Keyboard::Key k, size_t &pos) {
  size_t prev = pos;
  int _pos = static_cast<int>(pos);

  if (_pos >= 0)
    _pos += m_direction_value[k];

  pos = static_cast<size_t>(_pos);

  if (pos < A1 || pos > H8)
    pos = prev;
}

string KeyboardInputBoard::select_position(const size_t &pos) {
  has_been_selected ? select_to(pos) : select_from(pos);

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

void KeyboardInputBoard::update_view_select_next_square(const size_t &next, BoardView& bv) {
  bv.select_next_square(next);
}

void KeyboardInputBoard::update_view_selected_square(const size_t &p, BoardView& bv) {
  bv.selected_square(p);
}

void KeyboardInputBoard::update_view_deselected_square(const size_t &p, BoardView& bv) {
  bv.deselect_square(p);
}
