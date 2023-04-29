#ifndef BOARD_KEYBOARD_PANE_H
#define BOARD_KEYBOARD_PANE_H

#include "game/players/player_position.h"
#include "game/turn/game_turn_observer.h"
#include "board/board_window/board_pane/board_pane.h"
#include "ui/input/keyboard/keyboard_input.h"
#include "IBoard_input_event_handler.h"

class BoardKeyboardEventHandler : public IBoardInputEventHandler, public GameTurnObserver  {
 public:
  BoardKeyboardEventHandler(BoardPane& b, const std::unique_ptr<Input>& p);

  virtual ~BoardKeyboardEventHandler() = default;

  void update_turn(const Color& p) override ;
  bool is_player_string_move_ready() override ;
  string get_player_move_as_string() override;

 private:
  void on_key_pressed(CommandEventKeyboard& e);
  void update_next_square(const Square next_pos);
  void handle_direction_key_event(const int& d);
  void handle_enter_key_event();
  string select_position(const Square &pos);
  bool is_next_position_out_of_bounds(int next_pos);
  bool is_directional_keyCode(KeyCode::Key);

  const string key_not_supported = "key not supported\n";

  enum direction_value {
    DIR_UP = 8,
    DIR_RIGHT = 1,
    DIR_DOWN = -DIR_UP,
    DIR_LEFT = -DIR_RIGHT,
  };

  static const int square_A1{A1};
  static const int square_H8{H8};

  Color m_player_color;
  bool completed{false};
  bool has_been_selected{false};
  PlayerPosition m_player_pos;

  string m_string_move{""};
  BoardPane m_board_pane;
};

#endif /* BOARD_KEYBOARD_PANE_H */
