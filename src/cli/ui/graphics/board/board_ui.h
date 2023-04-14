#ifndef BOARD_UI_H
#define BOARD_UI_H

#include "board/check_move/board_check.h"
#include "configuration/board_configuration.h"
#include "game/turn/side_to_move.h"
#include "ui/graphics/board/board_keyboard_pane.h"
#include "ui/graphics/board/board_view.h"
#include "ui/graphics/board/decorators/info/info_pane.h"
#include "ui/input/board/board_input.h"
#include "ui/input/board/keyboard/keyboard_input_board_event_handler.hpp"

using std::unique_ptr;

class BoardUi {
public:
  BoardUi(const string &f, BoardConfig &c);
  virtual ~BoardUi();

  void attach_ui_elements(SideToMove &t);
  void add_info_pane(BoardCheck &board_check);
  void make_move(const Move &m);
  // void add_info_statistics_pane();
  void update_view();
  void print_view();
  void update_board_info(const string &s);
  void add_statistics_pane();
  string get_next_string_move();

private:
  auto new_board_keyboard_pane(const string &s);
  auto new_keyboard_event_handler(std::shared_ptr<IKeyboardBoardInput> b);
  auto set_up_input(InputType c);
  auto get_new_keyboard_board_pane(const string& f);
  shared_ptr<IUiPaneComponent> add_info_pane(shared_ptr<IUiPaneComponent> side_pane);
  shared_ptr<IUiPaneComponent> add_statistics_pane(shared_ptr<IUiPaneComponent> side_pane);

  void add_side_panes();
  void wrap_board_check_behaviour(BoardCheck &b);

  shared_ptr<BoardPane> p_board_pane;
  shared_ptr<KeyboardEventHandler> p_event_handler;
  unique_ptr<BoardInput> p_input;

  BoardView m_board_view;
  BoardModelInfo m_board_model_info;
  PlayerInfo m_turn;
};

#endif /* BOARD_UI_H */
