#ifndef BOARD_PANE_H
#define BOARD_PANE_H

#include <memory>

#include "board/board_window/IBoard_pane_component.h"
#include "board/board_window/board_pane/IBoard_Pane.h"
#include "board/board_window/board_pane/board_pane_view.h"
#include "board/board_window/board_pane/event_handlers/IPane_event_handler.h"
#include "board/board_window/board_pane/event_handlers/keyboard_event_handler.h"
#include "board/board_window/board_pane/event_handlers/text_event_handler.h"
#include "configuration/board_info.h"
#include "input/input_component.h"
#include "input/text/text_input.h"

struct PrintWindowEvent {};

class BoardPane : public EventEmitter {
 public:
  explicit BoardPane(const BoardConfigInfo &b_info);
  virtual ~BoardPane() = default;

  void make_move(const Move &mv);
  void update();
  IPane *get_view() { return &m_view; } 
  std::string get_move_as_string();

 private:
  void setup_player_input_component(const BoardConfigInfo &b_info);
  void setup_keyboard_input(Color initial_side);
  void setup_text_input();

  void on_key_pressed(EventKeyboard &e);
  void on_text(EventText &e);

  BoardPaneView m_view;

  PrintWindowEvent m_reprint_ui_event;
  std::unique_ptr<IPaneEventHandler> event_handler;
};

#endif   // !BOARD_PANE_H
