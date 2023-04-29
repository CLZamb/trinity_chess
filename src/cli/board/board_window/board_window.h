#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board/board_window/IBoard_side_pane.h"
#include "board/check_move/board_check.h"
#include "configuration/board/board_configuration.h"
#include "game/turn/side_to_move.h"
#include "board/board_window/board_pane/board_pane.h"
#include "board/event_handlers/IBoard_input_event_handler.h"
#include "board/board_window/info_pane/board_info_model.h"
#include "ui/components/window.h"
#include "ui/input/input.h"

class BoardWindow : public Window {
 public:
  BoardWindow(const string fen, const InputType &i, SideToMove &t);
  virtual ~BoardWindow() = default;
  void update();
  void print();
  string get_player_string_move();
  void make_move(const Move &m);
  void add_info_pane(BoardCheck &b);
  void add_statistics_pane();
  void parse_fen(const string& fen);

 private:
  void add_side_pane(shared_ptr<IBoardSidePane> p, Window::Pane_pos);
  void set_text_input(BoardPane &b);
  void set_keyboard_input(BoardPane &b, SideToMove &s);

  SideToMove &m_turn;
  std::unique_ptr<InputEvent> p_input_event;
  std::shared_ptr<IBoardInputEventHandler> p_input_event_handler;
  vector<std::shared_ptr<IBoardSidePane>> m_side_panes;
  BoardPane m_board_pane;
};

#endif /* BOARD_VIEW_H */
