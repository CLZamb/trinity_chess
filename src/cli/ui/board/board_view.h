#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/check_move/board_check.h"
#include "configuration/board_configuration.h"
#include "game/turn/side_to_move.h"
#include "ui/board/board_pane/board_pane.h"
#include "ui/board/board_pane/event_handlers/IBoard_event_handler.h"
#include "ui/board/info_pane/board_info_model.h"
#include "ui/components/window.h"
#include "ui/input/input.h"

class BoardView : public Window {
 public:
  BoardView(const string f, const BoardConfig &b, SideToMove &t);
  virtual ~BoardView();

  void update();
  void print();
  string get_next_string_move();
  void make_move(const Move &m);
  void add_info_pane(BoardCheck &b);

 private:
  void add_pane_component(shared_ptr<IBoardPaneComponent> p);
  void add_right_pane(shared_ptr<IBoardPaneComponent> p);
  void add_left_pane(shared_ptr<IBoardPaneComponent> p);
  void add_middle_pane(shared_ptr<IBoardPaneComponent> p);
  void set_text_input(shared_ptr<BoardPane> b);
  void set_keyboard_input(shared_ptr<BoardPane> b, SideToMove &s);

  SideToMove &m_turn;
  shared_ptr<Input> p_input;
  shared_ptr<IBoardEventHandler> p_input_event_handler;
  vector<shared_ptr<IBoardPaneComponent>> panes;
};

#endif /* BOARD_VIEW_H */
