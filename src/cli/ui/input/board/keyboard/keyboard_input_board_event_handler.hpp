#ifndef KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H
#define KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H

#include "game/players/player_position.h"
#include "game/turn/game_turn_observer.h"
#include "ui/graphics/board/IKeyboard_board_input_selection.h"
#include "ui/graphics/board/board_pane.h"
#include "ui/input/board/keyboard/key_code.h"
#include "ui/input/input_types/input_handler.h"
#include "utils/defs.h"
#include "utils/utilities.h"
#include <unordered_map>

class KeyboardEventHandler : public InputHandler, public GameTurnObserver {
public:
  KeyboardEventHandler(std::shared_ptr<IKeyboardBoardInput> b)
      : p_board_pane(b) {}

  virtual ~KeyboardEventHandler() {}

  void update_turn(const PlayerInfo &p) override {
    m_player_info = p;

    SquareIndices last_pos = m_player_pos.get_last_position(p.color);
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

  list<SquareIndices> selected_positions;

  void deselect_all_previous_selected_squares() {
    for (const SquareIndices &pos : selected_positions)
      update_deselected_square(pos);

    selected_positions.clear();

    m_player_pos.update_last_position(m_player_info.color);
  }

  string select_position(const SquareIndices &pos) {
    is_completed = has_been_selected;

    has_been_selected = !is_completed;
    return string_utils::squareindex_to_str(SquareIndices(pos));
  }

  void update_select_next_square(const SquareIndices &next) {
    p_board_pane->select_next_square(next);
    m_player_pos.update_next_last_position(next);
  }

  void update_selected_square(const SquareIndices &next) {
    p_board_pane->selected_square(next);
    selected_positions.push_back(next);
  }

  void update_deselected_square(const SquareIndices &next) {
    p_board_pane->deselect_square(next);
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

  PlayerInfo m_player_info;

  bool has_been_selected{false};
  bool is_completed{false};

  std::shared_ptr<IKeyboardBoardInput> p_board_pane;
  PlayerPosition m_player_pos;
};

#endif /* KEYBOARD_INPUT_BOARD_EVENT_HANDLER_H */
