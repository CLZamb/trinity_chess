#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "board/headers/squares.h"
#include "common/headers/common.h"
#include "graphics//headers/pieces_drawings.hpp"
#include "model/headers/board_info.h"
#include "piece/headers/piece.h"
#include "piece/headers/pieces.h"
#include "utils.h"
#include "square.h"
#include "game/headers/move.hpp"
#include "game/headers/game_turn_observer.h"
#include "view/headers/board_view.h"
#include "game/headers/string_utils.h"
// #include "BoardBitboard.h"
#include "board/headers/board_fen.h"

class Board : public GameTurnObserver {
 public:
  explicit Board(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  virtual ~Board();
  void update_turn(const PlayerInfo &) override;
  void make_move(string mv);
  bool is_checkmate();
  bool is_valid_move(const string &m);
  BoardView& get_view();
  BoardInfo& get_info();
  const BoardFen& get_board_fen();

 private:
  Move get_move_from_string(const string&);
  bool is_legal_move(Move&);
  void parser_fen(string fen);
  void move_piece_to_square(const Move&);
  void save_move(const Move &m);
  void update_board_info(const string &info);
  void update_board_view();
  void clear_board();
  void add_to_board(Piecetype piece, SquareIndices position);
  bool is_legal_attack_move(Move & m);
  bool is_legal_non_attack_move(Move & m);
  bool is_attack_move(const Move& to);
  bool is_number(char c);
  bool check_captured_belongs_to_opponent_player(const Piecetype& pos);
  bool check_piece_belongs_to_current_player(const Piecetype&);

  Squares m_squares;
  Pieces m_pieces;
  BoardBitboard m_board_state;
  bool checkmate = false;
  PlayerInfo m_turn_info;
  BoardView m_view;
  BoardInfo m_info;
  BoardFen m_fen;
};


#endif /* BOARD_H */
