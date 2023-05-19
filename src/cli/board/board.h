#ifndef BOARD_H
#define BOARD_H

#include "board/board_window/board_window.h"
#include "board/chess.h"
#include "board/position/position_fen.h"
#include "board/special_moves/special_move_controller.h"
#include "configuration/file_configuration.hpp"
#include "game/turn/side_to_move.h"

class Board : public Window {
 public:
  explicit Board(BoardConfigInfo &board_config);

  void print();
  Move get_player_move();
  bool is_invalid_move(const Move &);
  void make_move(const Move &mv);
  void change_side();
  bool is_checkmate();
  Color get_winner_side();

 protected:
  std::string get_string_move();

  Chess m_chess;
  BoardWindow m_window;
};

#endif /* BOARD_H */
