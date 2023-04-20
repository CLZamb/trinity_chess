#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/check_move/board_check.h"
#include "board_window.h"
#include "configuration/board_configuration.h"
#include "game/turn/side_to_move.h"
#include "ui/board/board_pane/board_pane.h"
#include "ui/board/board_pane/event_handlers/IBoard_event_handler.hpp"
#include "ui/board/info_pane/board_info_model.h"
#include "ui/input/input.h"

class BoardView {
 public:
  BoardView(const string f, const BoardConfig &b, SideToMove &t);
  virtual ~BoardView();

  void update();
  void print();
  string get_next_string_move();
  void make_move(const Move &m);
  void add_info_pane(BoardCheck &b);

 private:
  void set_text_input(shared_ptr<BoardPane> b);
  void set_keyboard_input(shared_ptr<BoardPane> b, SideToMove &s);

  Move m_move;
  BoardWindow m_board_window;
  shared_ptr<Input> p_input;
  shared_ptr<IBoardEventHandler> p_input_event_handler;
  SideToMove& m_turn;
};

#endif /* BOARD_VIEW_H */
