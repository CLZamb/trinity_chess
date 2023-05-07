#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/board_window/IBoard_side_pane.h"
#include "board/board_window/board_components.hpp"
#include "board/board_window/board_pane/IBoard_pane.h"
#include "board/board_window/board_pane/board_pane.h"
#include "board/check_move/board_check.h"
#include "game/turn/side_to_move.h"
#include "input/input.h"
#include "input/input_types.h"
#include "ui_components/window.h"
#include "utils/move.hpp"

class BoardWindow : public Window {
 public:
  BoardWindow();
  void update();
  void print();
  std::string get_player_move_as_string();
  void make_move(const Move &move);
  void parse_fen(const FenFields &fen);
  void set_board_pane(std::unique_ptr<IBoardPane> &&board_pane,
                      Window::PanePos pane_pos);
  void set_side_pane(std::unique_ptr<IBoardSidePane> &&pane,
                     Window::PanePos window_position);
  void set_input(std::unique_ptr<Input> &&keyboard);

 private:
  std::unique_ptr<Input> p_input;
  std::vector<std::unique_ptr<IBoardSidePane>> m_side_panes;
  std::unique_ptr<IBoardPane> p_board_pane;
};

#endif /* BOARD_VIEW_H */
