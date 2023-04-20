#ifndef BOARD_KEYBOARD_PANE_H
#define BOARD_KEYBOARD_PANE_H

#include "game/players/player_position.h"
#include "game/turn/game_turn_observer.h"
#include "ui/board/board_pane/board_pane.h"
#include "ui/input/keyboard/keyboard_input.h"
#include "IBoard_event_handler.h"
#include <algorithm>

class BoardKeyboardEventHandler : public IBoardEventHandler, public GameTurnObserver  {
 public:
  BoardKeyboardEventHandler(shared_ptr<BoardPane> b, shared_ptr<Input> p);

  virtual ~BoardKeyboardEventHandler() = default;

  void update_turn(const PlayerInfo& p) override ;
  bool has_events() override ;
  string get_string() override;

 private:
  void update_next_square(const SquareIndices next_pos);
  void handle_event_direction(CommandEvent& e);
  void handle_event_enter(CommandEvent&);
  string select_position(const SquareIndices &pos);
  bool is_next_position_out_of_bounds(int next_pos);

  const string key_not_supported = "key not supported\n";

  enum direction_value {
    DIR_UP = 8,
    DIR_RIGHT = 1,
    DIR_DOWN = -DIR_UP,
    DIR_LEFT = -DIR_RIGHT,
  };

 const unordered_map<KeyCode::Key, int> m_direction_value {
    {KeyCode::UP,    DIR_UP},
    {KeyCode::DOWN,  DIR_DOWN},
    {KeyCode::LEFT,  DIR_LEFT},
    {KeyCode::RIGHT, DIR_RIGHT},
  };

  static const int square_A1{A1};
  static const int square_H8{H8};

  Color m_player_color;
  bool completed{false};
  bool has_been_selected{false};
  PlayerPosition m_player_pos;

  string call_back{""};
  shared_ptr<BoardPane> p_board_pane;
};

#endif /* BOARD_KEYBOARD_PANE_H */
