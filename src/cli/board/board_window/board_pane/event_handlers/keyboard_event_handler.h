#ifndef KEYBOARD_EVENT_HANDLER_H
#define KEYBOARD_EVENT_HANDLER_H

#include <list>

#include "board/board_window/board_pane/board_pane_view.h"
#include "board/board_window/board_pane/event_handlers/IPane_event_handler.h"
#include "board/board_window/board_pane/squares/square_drawings_selector.h"
#include "game/players/player_position.h"
#include "input/keyboard/keyboard_input.h"

class KeyboardEventHandler : public IPaneEventHandler {
 public:
  KeyboardEventHandler(const Color &initial_side,
                       BoardPaneView &squares_drawing);
  virtual ~KeyboardEventHandler();

  std::string get_move_as_string() override;
  void change_side() override;
  void on_key_pressed(EventKeyboard &e);

  void handle_direction(const KeyCode::Key &keycode);
  void handle_enter();
  void select_next_square(const Square &next);
  void update_selected_square(const Square &next);
  void restore_previous_selected_squares();
  std::string get_cur_position_as_string();

 private:
  KeyboardInput m_input;
  BoardPaneView &m_board_view;
  PlayerPosition m_player_pos;
  SquareDrawingSelector m_square_selector;
  int m_str_move_selected_counter;
  std::string m_string_move;
  bool m_completed{false};
  const std::string key_not_supported = "key not supported\n";
};

#endif /* KEYBOARD_EVENT_HANDLER_H */
