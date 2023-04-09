#ifndef BOARD_UI_H
#define BOARD_UI_H

#include <memory>
#include "board/check_move/board_check.h"
#include "ui/graphics/board/decorators/IUi_board.h"
#include "ui/graphics/board/decorators/info/board_info_model.h"
#include "ui/input/board/board_input_builder.h"
#include "board/fen/board_fen.h"

using std::unique_ptr;

class BoardUi : public GameTurnObserver {
 public:
  BoardUi(BoardFen& bfi, InputType input);
  virtual ~BoardUi();

  void update_turn(const PlayerInfo &turn) override;
  void add_info_pane(BoardCheck &board_check);
  void update_view();
  void print_view();
  void save_move(const Move& mv);
  void update_board_info(const string& s);
  string get_next_string_move();

 private:
  void wrap_board_view();
  void wrap_board_check(BoardCheck &board_check);
  BoardFen& m_board_fen;
  BoardView m_board_view;
  BoardModelInfo m_board_model_info;
  unique_ptr<IUIBoard> p_board_view;
  PlayerInfo m_turn;
  BoardInputBuilder m_board_input_builder;
  const unique_ptr<BoardInput> p_board_input;
  array<string, Color::SIZE> m_turn_string{"Is white turn", "Is black turn"};
};

#endif /* BOARD_UI_H */
