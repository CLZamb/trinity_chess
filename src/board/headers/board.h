#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <string>
#include "common/headers/common.h"
#include "graphics//headers/pieces_drawings.hpp"
#include "model/headers/board_info.h"
#include "piece/headers/piece.h"
#include "piece/headers/pieces.h"
#include "utils.h"
#include "player/headers/player.h"
#include "../headers/square.h"
#include "game/headers/move.h"
#include "game/headers/game_turn_observer.h"
#include "view/headers/board_view.h"
#include "BoardBitboard.h"

using std::shared_ptr;

class Board : public GameTurnObserver {
 public:
  explicit Board(string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  virtual ~Board();
  void update_turn(const PlayerInfo &) override;
  void make_move(Move mv);
  void move_piece_to_square(Piece* piece, SquareIndices from, SquareIndices to);
  void parser_fen(string fen);
  bool is_checkmate();
  bool is_legal_move(Move&);
  int evaluate_board() { return 0; }
  Piece* get_piece_at_square(int);
  string get_fen();
  BoardView& get_view();
  BoardInfo& get_info();

 private:
  void save_move(const Move &m);
  void update_board_view();
  void clear_board();
  void add_to_board(Piecetype piece, SquareIndices position);
  bool exist_piece_at_square(const int& pos);
  bool is_legal_attack_move(Move & m);
  bool is_legal_non_attack_move(Move & m);
  bool is_attack_move(const int& to);
  bool is_number(char c);
  bool check_captured_belongs_to_opponent_player(const int& pos);
  bool check_piece_belongs_to_current_player(const int& pos);
  Square& get_square_at_pos(int pos);

  static const size_t board_rwo_sizea = 8;
  static const size_t board_column_sizea = 8;
  std::array<Square, board_rwo_sizea * board_column_sizea> m_squares;  
  Pieces m_pieces;
  BoardBitboard board_state;
  bool checkmate = false;
  PlayerInfo m_turn_info;
  BoardView m_view;
  BoardInfo m_info;
};


#endif /* BOARD_H */
