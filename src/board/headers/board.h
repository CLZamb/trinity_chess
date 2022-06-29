#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "board/headers/board_fen.h"
#include "board/headers/defs.h"
#include "board/headers/squares.h"
#include "board/headers/utils.h"
#include "common/headers/common.h"
#include "game/headers/game_turn_observer.h"
#include "game/headers/move.hpp"
#include "game/headers/string_utils.h"
#include "model/headers/board_info.h"
#include "piece/headers/piece.h"
#include "piece/headers/pieces.h"
#include "view/headers/board_view.h"

class Board : public GameTurnObserver {
public:
  explicit Board(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  virtual ~Board();
  void update_turn(const PlayerInfo &) override;
  void make_move(Move mv);
  bool is_checkmate();
  bool is_legal_move(Move &);
  BoardInfo &get_info();
  BoardFen &get_board_fen();
  Move string_to_move(const string &);

private:
  void parser_fen(string fen);
  void move_piece_to_square(const Move &);
  void save_move(const Move &m);
  void clear_board();
  void add_to_board(Piecetype piece, SquareIndices position);
  bool is_attack_move(const Piecetype &captured);
  bool is_number(char c);
  bool check_piece_belongs_to_current_player(const Piecetype &);

  Squares m_squares;
  Pieces m_pieces;
  BoardBitboard m_board_state;
  bool checkmate = false;
  PlayerInfo m_turn_info;
  BoardFen m_fen;
};

#endif /* BOARD_H */
