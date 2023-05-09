#ifndef BOARD_H
#define BOARD_H

#include "board/board_window/board_window.h"
#include "board/check_move/IBoard_check.h"
#include "board/position/position_fen.h"
#include "board/special_moves/special_move_controller.h"
#include "configuration/file_configuration.hpp"
#include "game/turn/side_to_move.h"

class Board {
 public:
  explicit Board(BoardConfigInfo &board_config);
  virtual ~Board() = default;

  void print();
  Move get_player_move();
  bool is_invalid_move(const Move &);
  void make_move(const Move &mv);
  bool is_checkmate();
  void change_side();
  Color get_winner_side();

 private:
  void build_window(BoardConfigInfo &b_config);
  void build_side_pane(const BoardSidePaneInfo& side_pane_type);
  Move convert_string_to_move(const std::string &m);
  SideToMove m_side_to_move;
  Position m_position;
  PositionFen m_position_fen;
  SpecialMove m_special_move;
  std::unique_ptr<IBoardCheck> p_check;
  BoardWindow m_board_win;
};

#endif /* BOARD_H */
