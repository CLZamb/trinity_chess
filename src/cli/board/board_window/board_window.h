#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/board_window/IBoard_side_pane.h"
#include "board/board_window/board_pane/board_pane.h"
#include "board/board_window/event_handlers/IBoard_input_event_handler.h"
#include "board/check_move/board_check.h"
#include "game/turn/side_to_move.h"
#include "ui/components/window.h"
#include "ui/input/input.h"
#include "ui/input/input_types.h"
#include "utils/move.hpp"

class BoardWindow : public Window {
 public:
  BoardWindow(const std::string fen, const InputType &i, SideToMove &t);
  virtual ~BoardWindow() = default;
  void update();
  void print();
  std::string get_player_move_as_string();
  void make_move(const Move &m);
  void add_info_pane(BoardCheck &b);
  void add_statistics_pane();
  void parse_fen(const string &fen);

 private:
  void add_side_pane(std::shared_ptr<IBoardSidePane> p, Window::Pane_pos);
  void set_text_input(BoardPane &b);
  void set_keyboard_input(BoardPane &b, SideToMove &s);

  SideToMove &m_side_to_move;
  std::unique_ptr<Input> p_input;
  std::unique_ptr<IBoardInputEventHandler> p_input_event_handler;
  vector<std::shared_ptr<IBoardSidePane>> m_side_panes;
  BoardPane m_board_pane;
};

#endif /* BOARD_VIEW_H */
