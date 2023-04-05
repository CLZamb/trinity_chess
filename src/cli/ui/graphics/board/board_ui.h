#ifndef BOARD_UI_H
#define BOARD_UI_H

#include <memory>
#include "ui/graphics/board/info/board_model_info.h"
#include "ui/input/board/board_input_builder.h"
#include "board_controller.h"
#include "board/fen/board_fen.h"
#include "ui/graphics/board/info/info_pane.h"

using std::shared_ptr;

class BoardUi : public GameTurnObserver {
 public:
  BoardUi(BoardFen& bf, InputType input);
  virtual ~BoardUi();

  void update_turn(const PlayerInfo &turn) override;
  void add_info_pane();
  void update_view();
  void print_view();
  void save_move(const Move& mv);
  void update_board_info(const string& s);
  string get_next_string_move();

 private:
  BoardFen& m_board_fen;
  BoardView m_board_view;
  InfoPane m_info_pane;
  BoardController m_board_controller;
  BoardModelInfo m_board_model_info;
  shared_ptr<IUIBoard> p_boardview_controller;
  PlayerInfo m_turn;
  BoardInputBuilder m_board_input_builder;
  const std::shared_ptr<BoardInput> p_board_input;
};

#endif /* BOARD_UI_H */
