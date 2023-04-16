#ifndef KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H
#define KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H

#include "game/players/player_info.hpp"
#include "game/players/player_position.h"
#include "ui/graphics/board/panes/board/IKeyboard_board_input_selection.h"
#include "ui/input/board/keyboard/key_code.h"
#include "ui/input/board/keyboard/keyboard_input_board.h"
#include "utils/defs.h"
#include "utils/string_utils.h"
#include "utils/utilities.h"
#include <iostream>
#include <list>
#include <unordered_map>

class KeyboardEventHandler {
public:
  KeyboardEventHandler(IKeyboardBoardInput &b) : m_board_pane(b) {}

  virtual ~KeyboardEventHandler() {}

  void update_turn(const PlayerInfo &p) {
    m_player_color = p.color;

    SquareIndices last_pos = m_player_pos.get_last_position(m_player_color);
    update_select_next_square(last_pos);

    has_been_selected = false;
    completed = false;
  }

  bool is_completed() { return completed; }
  string get_string() { return std::move(call_back); }
  void handle_event_up(KeyCode::Key) { handle_event_direction(DIR_UP); }
  void handle_event_down(KeyCode::Key) { handle_event_direction(-DIR_UP); }
  void handle_event_left(KeyCode::Key) { handle_event_direction(-DIR_RIGHT); }
  void handle_event_right(KeyCode::Key) { handle_event_direction(DIR_RIGHT); }
  void handle_event_enter(KeyCode::Key) { handle_enter_key_event(call_back); }

private:
  string call_back{""};

  void handle_event_direction(int dir_value) {
    update_select_next_square(get_next_position(dir_value));
  }

  void handle_enter_key_event(string &callback) {
    SquareIndices next_pos = m_player_pos.get_next_last_position();

    callback += select_position(next_pos);
    update_selected_square(next_pos);

    if (completed) {
      deselect_all_previous_selected_squares();
    }
  }

  void deselect_all_previous_selected_squares() {
    for (const SquareIndices &pos : selected_positions)
      update_deselected_square(pos);

    selected_positions.clear();

    m_player_pos.update_last_position(m_player_color);
  }

  string select_position(const SquareIndices &pos) {
    completed = has_been_selected;

    has_been_selected = !completed;
    return string_utils::squareindex_to_str(SquareIndices(pos));
  }

  void update_select_next_square(const SquareIndices &next) {
    m_board_pane.select_next_square(next);
    m_board_pane.update();
    m_player_pos.update_next_last_position(next);
  }

  void update_selected_square(const SquareIndices &next) {
    m_board_pane.selected_square(next);
    m_board_pane.update();
    selected_positions.push_back(next);
  }

  void update_deselected_square(const SquareIndices &next) {
    m_board_pane.deselect_square(next);
    m_board_pane.update();
  }

  SquareIndices get_next_position(int dir_value) {
    SquareIndices next_pos = m_player_pos.get_next_last_position();
    int _pos = static_cast<int>(next_pos) + dir_value;

    if (_pos >= first_square && _pos <= last_square) {
      return static_cast<SquareIndices>(_pos);
    }

    return next_pos;
  }

  const string key_not_supported = "key not supported\n";

  enum direction_value {
    DIR_UP = 8,
    DIR_RIGHT = 1,
  };

  std::list<SquareIndices> selected_positions;

  static const int first_square{A1};
  static const int last_square{H8};

  Color m_player_color;
  bool has_been_selected{false};
  bool completed{false};
  IKeyboardBoardInput &m_board_pane;
  PlayerPosition m_player_pos;
};

#endif /* KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H */
