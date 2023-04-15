#ifndef KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H
#define KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H

#include "game/players/player_info.hpp"
#include "game/players/player_position.h"
#include "ui/graphics/board/panes/board/IKeyboard_board_input_selection.h"
#include "ui/input/input_types/input_handler.h"
#include "utils/string_utils.h"
#include "utils/utilities.h"
#include <unordered_map>
#include <iostream>
#include <list>

class KeyboardEventHandler : public InputHandler {
public:
  KeyboardEventHandler(IKeyboardBoardInput& b)
      : m_board_pane(b) {}

  virtual ~KeyboardEventHandler() {}

  void update_turn(const PlayerInfo &p) {
    m_player_color = p.color;

    SquareIndices last_pos = m_player_pos.get_last_position(m_player_color);
    update_select_next_square(last_pos);

    has_been_selected = false;
    is_completed = false;
  }

  bool handle_event(KeyCode::Key e, string &call_back) override {
    switch (e) {
      case KeyCode::UP:
      case KeyCode::DOWN:
      case KeyCode::LEFT:
      case KeyCode::RIGHT:
        handle_direction_event(e);
        m_board_pane.update();
        return false;
      case KeyCode::ENTER:
        handle_enter_key_event(call_back);
        return is_completed;
      default:
        std::cout << key_not_supported << std::endl;
        return false;
    }
  }

private:
  void deselect_all_previous_selected_squares() {
    for (const SquareIndices &pos : selected_positions)
      update_deselected_square(pos);

    selected_positions.clear();

    m_player_pos.update_last_position(m_player_color);
  }

  string select_position(const SquareIndices &pos) {
    is_completed = has_been_selected;

    has_been_selected = !is_completed;
    return string_utils::squareindex_to_str(SquareIndices(pos));
  }

  void update_select_next_square(const SquareIndices &next) {
    m_board_pane.select_next_square(next);
    m_player_pos.update_next_last_position(next);
  }

  void update_selected_square(const SquareIndices &next) {
    m_board_pane.selected_square(next);
    selected_positions.push_back(next);
  }

  void update_deselected_square(const SquareIndices &next) {
    m_board_pane.deselect_square(next);
  }

  void handle_direction_event(KeyCode::Key e) {
    SquareIndices next_pos = m_player_pos.get_next_last_position();
    next_pos = get_next_position(e, next_pos);
    update_select_next_square(next_pos);
  }

  void handle_enter_key_event(string &callback) {
    SquareIndices next_pos = m_player_pos.get_next_last_position();

    callback += select_position(next_pos);
    update_selected_square(next_pos);

    if (is_completed) {
      deselect_all_previous_selected_squares();
    }
  }

  SquareIndices get_next_position(KeyCode::Key k, SquareIndices &pos) {
    int _pos = static_cast<int>(pos) + m_direction_value[k];

    if (_pos >= static_cast<int>(A1) && _pos <= static_cast<int>(H8)) {
      return static_cast<SquareIndices>(_pos);
    }

    return pos;
  }

  const string key_not_supported = "key not supported\n";

  enum direction_value {
    DIR_UP    = 8,
    DIR_RIGHT = 1,
  };

  std::unordered_map<KeyCode::Key, int> m_direction_value{
      {KeyCode::UP,    DIR_UP},
      {KeyCode::DOWN, -DIR_UP},
      {KeyCode::RIGHT, DIR_RIGHT},
      {KeyCode::LEFT, -DIR_RIGHT},
  };

  std::list<SquareIndices> selected_positions;

  Color m_player_color;
  bool has_been_selected{false};
  bool is_completed{false};
  IKeyboardBoardInput& m_board_pane;
  PlayerPosition m_player_pos;
};

#endif /* KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H */
