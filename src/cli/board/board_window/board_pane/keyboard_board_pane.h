#ifndef KEYBOARD_BOARD_PANE_H
#define KEYBOARD_BOARD_PANE_H

#include <list>

#include "IBoard_pane.h"
#include "board/board_window/board_pane/squares/square_drawings_selector.h"
#include "board/position/position_fen.h"
#include "game/players/player_position.h"

class KeyboardBoardPane : public IBoardPane {
 public:
  explicit KeyboardBoardPane(const std::unique_ptr<KeyboardInput> &p,
                             const FenFields &fen, Color initial_selected_side);
  virtual ~KeyboardBoardPane();

  void make_move(const Move &move) override;
  bool is_player_string_move_ready() override;
  string get_player_move_as_string() override;

 private:
  void on_key_pressed(CommandEventKeyboard &e);
  void handle_direction_key_event(const KeyCode::Key& keycode);
  void handle_enter_key_event();
  string get_selected_position_as_string(const Square &pos);
  bool is_directional_keyCode(KeyCode::Key);
  int get_direction_value(KeyCode::Key);
  void update_select_next_square_drawing(const Square &next);
  void update_selected_square(const Square &next);
  void update_deselected_square(const Square &next);
  void restore_previous_selected_squares();

  bool completed{false};
  bool has_been_selected{false};
  string m_string_move{""};
  PlayerPosition m_player_pos;
  SquaresDrawingSelector m_drawing_selector;
  const string key_not_supported = "key not supported\n";
};

#endif /* KEYBOARD_BOARD_PANE_H */