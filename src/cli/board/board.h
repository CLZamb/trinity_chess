#ifndef BOARD_H
#define BOARD_H

#include "board/board_window/board_window.h"
#include "board/special_moves/special_move_controller.h"
#include "configuration/board/board_configuration.h"

class Board {
 public:
  explicit Board(BoardConfig &config);
  virtual ~Board();

  void add_info_pane();
  void print();
  Move get_player_move();
  bool is_invalid_move(const Move &);
  void make_move(const Move &mv);
  bool is_checkmate();
  void parse_fen(const string &fen);
  void change_side();
  Color get_winner_side();

 private:
  Move convert_string_to_move(const string &m);
  SideToMove m_side_to_move;
  Position m_position;
  SpecialMove m_special_move;
  BoardCheck m_board_check;
  BoardWindow m_board_window;
  Color m_color_to_move;
};

#endif /* BOARD_H */
