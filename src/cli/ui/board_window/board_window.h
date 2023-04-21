#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/check_move/board_check.h"
#include "configuration/board_configuration.h"
#include "game/turn/side_to_move.h"
#include "ui/board_window/board_pane/board_pane.h"
#include "ui/board_window/board_pane/event_handlers/IBoard_input_event_handler.h"
#include "ui/board_window/info_pane/board_info_model.h"
#include "ui/components/window.h"
#include "ui/input/input.h"

class BoardWindow : public Window {
 public:
  BoardWindow(const string f, const BoardConfig &b, SideToMove &t);
  virtual ~BoardWindow() = default;
  void update();
  void print();
  string get_next_string_move();
  void make_move(const Move &m);
  void add_info_pane(BoardCheck &b);
  void add_statistics_pane();

 private:
  void add_pane(shared_ptr<IBoardPane> p);
  void add_right_pane(shared_ptr<IBoardPane> p);
  void add_left_pane(shared_ptr<IBoardPane> p);
  void add_middle_pane(shared_ptr<IBoardPane> p);
  void set_text_input(shared_ptr<BoardPane> b);
  void set_keyboard_input(shared_ptr<BoardPane> b, SideToMove &s);

  SideToMove &m_turn;
  shared_ptr<InputEvent> p_input_event;
  shared_ptr<IBoardInputEventHandler> p_input_event_handler;
  vector<shared_ptr<IBoardPane>> panes;
};

#endif /* BOARD_VIEW_H */
