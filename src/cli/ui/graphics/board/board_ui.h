#ifndef BOARD_UI_H
#define BOARD_UI_H

#include <memory>
#include "board/check_move/board_check.h"
#include "game/turn/game_turn.h"
#include "ui/graphics/board/board_view.h"
#include "ui/graphics/board/decorators/info/board_info_model.h"
#include "board/fen/board_fen_controller.h"

// using std::unique_ptr;

class BoardUi {
 public:
  BoardUi(const string& f, InputType i);
  virtual ~BoardUi();

  void attach_components_to_game_turn(GameTurn &t);
  void add_info_pane();
  void make_move(const Move& m);
  // void add_info_statistics_pane();
  void update_view();
  void print_view();
  void save_move(const Move& m);
  void update_board_info(const string& s);
  string get_next_string_move();

 private:
  void wrap_board_view();
  void wrap_board_check(BoardCheck &bc);
  std::unique_ptr<BoardInput> set_new_input(InputType c);

  BoardPane m_board_pane;
  BoardView m_board_view;
  BoardModelInfo m_board_model_info;
  PlayerInfo m_turn;
  const unique_ptr<BoardInput> p_input;
};

#endif /* BOARD_UI_H */
