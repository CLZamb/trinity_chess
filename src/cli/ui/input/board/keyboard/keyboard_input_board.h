#ifndef KEYBOARD_INPUT_PLAYER_H
#define KEYBOARD_INPUT_PLAYER_H

// #include "ui/graphics/board/board_view.h"
#include "game/players/player_position.h"
#include "ui/input/board/board_input.h"
#include "ui/input/input_types/keyboard/keyboard_input.h"
#include "ui/input/input_types/keyboard/keyboard_key.h"
#include <unordered_map>

class KeyboardInputBoard : public BoardInput {
public:
  KeyboardInputBoard(KeyboardBoardInputSelection &bv);
  virtual ~KeyboardInputBoard();

  void update_turn(const PlayerInfo &) override;
  InputEvent get_next_string_move(string &call_back) override;

private:
  enum direction_value {
    DIR_UP = 8,
    DIR_RIGHT = 1,
    DIR_LEFT = -DIR_RIGHT,
    DIR_DOWN = -DIR_UP,
  };

  unordered_map<Keyboard::Key, int> m_direction_value {
    {Keyboard::UP,    DIR_UP},       {Keyboard::W, DIR_UP},
    {Keyboard::DOWN,  DIR_DOWN},   {Keyboard::A, DIR_LEFT},
    {Keyboard::LEFT,  DIR_LEFT},   {Keyboard::S, DIR_DOWN},
    {Keyboard::RIGHT, DIR_RIGHT}, {Keyboard::D, DIR_RIGHT},
  };

  string select_position(const SquareIndices &pos);
  void update_view_select_next_square(const SquareIndices &position);
  void update_view_selected_square(const SquareIndices &position);
  void update_view_deselected_square(const SquareIndices &position);
  void select_from(const SquareIndices &pos);
  void select_to(const SquareIndices &pos);
  void handle_arrow_keys(const Keyboard::Key key, SquareIndices &pos);
  void deselect_all_previous_selected_squares();

  static const string key_not_supported;

  bool completed{false};
  bool has_been_selected{false};
  list<SquareIndices> selected_positions;
  KeyboardInput m_k_input;
  KeyboardBoardInputSelection &m_board_pane;
  PlayerPosition m_player_pos;
  PlayerInfo m_player_info;
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
