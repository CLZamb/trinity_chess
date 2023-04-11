#include "keyboard_input_board.h"
#include "utils/defs.h"

const string KeyboardInputBoard::key_not_supported = "key not supported\n";

KeyboardInputBoard::KeyboardInputBoard(KeyboardBoardInputSelection& bv) : m_board_pane(bv){}

KeyboardInputBoard::~KeyboardInputBoard() {}

void KeyboardInputBoard::update_turn(const PlayerInfo &p) {
  m_player_info = p;

  m_player_pos.update_next_last_position(m_player_pos.get_last_position(p.color));
  update_view_select_next_square(m_player_pos.get_last_position(p.color));

  has_been_selected = false;
  completed = false;
}

BoardInput::InputEvent KeyboardInputBoard::get_next_string_move(string& next_move) {
  SquareIndices next_pos = m_player_pos.get_next_last_position();
  InputEvent event = InputEvent::NO_EVENT;

  switch (Keyboard::Key key = m_k_input.read_key(); key) {
    case Keyboard::ARROW_KEY:
      handle_arrow_keys(m_k_input.read_arrow_key(), next_pos);
      event = InputEvent::PRINT;
      break;
    case Keyboard::W:
    case Keyboard::A:
    case Keyboard::S:
    case Keyboard::D:
      handle_arrow_keys(key, next_pos);
      event = InputEvent::PRINT;
      break;
    case Keyboard::ENTER:
      next_move += select_position(next_pos);
      update_view_selected_square(next_pos);
      selected_positions.push_back(next_pos);

      if (completed) {
        deselect_all_previous_selected_squares();
        m_player_pos.update_last_position(m_player_info.color);
        event = InputEvent::COMPLETED;
      }
      break;
    default:
      std::cout << key_not_supported << std::endl;
      break;
  }

  m_player_pos.update_next_last_position(next_pos);
  update_view_select_next_square(next_pos);
  return event;
}

void KeyboardInputBoard::deselect_all_previous_selected_squares() {
  for (const SquareIndices &pos : selected_positions)
    update_view_deselected_square(pos);
  selected_positions.clear();
}

void KeyboardInputBoard::handle_arrow_keys(Keyboard::Key k, SquareIndices &pos) {
  int _pos = static_cast<int>(pos) + m_direction_value[k];

  if (_pos >= static_cast<int>(A1) && _pos <= static_cast<int>(H8)) {
    pos = static_cast<SquareIndices>(_pos);
  }
}

string KeyboardInputBoard::select_position(const SquareIndices &pos) {
  completed = has_been_selected;

  has_been_selected = !has_been_selected;
  return string_utils::squareindex_to_str(SquareIndices(pos));
}

void KeyboardInputBoard::update_view_select_next_square(const SquareIndices &next) {
  m_board_pane.select_next_square(next);
}

void KeyboardInputBoard::update_view_selected_square(const SquareIndices &next) {
  m_board_pane.selected_square(next);
}

void KeyboardInputBoard::update_view_deselected_square(const SquareIndices &next) {
  m_board_pane.deselect_square(next);
}
