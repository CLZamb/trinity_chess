#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <string>
#include "../../include/common/headers/common.h"
#include "../../graphics//headers/pieces_drawings.hpp"
#include "../../piece/headers/piece.h"
#include "../../piece/headers/pieces.h"
#include "utils.h"
#include "../../headers/player.h"
#include "../headers/square.h"
#include "../../headers/move.h"
#include "../../headers/game_turn_observer.h"
#include "../../graphics/headers/board_drawing.h"
#include "BoardBitboard.h"

using std::shared_ptr;

class Board {
 public:
  explicit Board();
  virtual ~Board();
  void _init();
  void make_move(Move mv);
  void set_players(
      std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
  void move_piece_to_square(Piece* piece, SquareIndices from, SquareIndices to);
  void parser_fen(string fen);
  bool is_checkmate();
  bool is_legal_move(std::shared_ptr<Player> turn, Move&);
  int evaluate_board() { return 0; }
  Piece* get_piece_at_square(int);

  Displayable* get_drawing();
  friend std::ostream& operator<<(std::ostream& os, Board& b);

 private:
  bool exist_piece_at_square(const int& pos);
  bool is_legal_attack_move(Move & m);
  bool is_legal_non_attack_move(Move & m);
  bool is_attack_move(std::shared_ptr<Player> turn, const int& to);
  void create_board_squares();
  void create_empty_squares_drawing();
  void add_to_board(int piece, SquareIndices position);
  bool is_number(char c);
  bool check_captured_belongs_to_opponent_player(std::shared_ptr<Player> turn, const int& pos);
  bool check_piece_belongs_to_current_player(std::shared_ptr<Player> turn, const int& pos);

  Square* get_square_at_pos(int pos);
  Box wSquare, bSquare;
  Square* p_squares[8 * 8 /*board size*/] = {nullptr};
  BoardDrawing m_bdrawing{p_squares};
  Pieces m_pieces;
  bool checkmate = false;
  BoardBitboard board_state;

  // GameTurn::players m_turn = GameTurn::player_1;

//  protected:
};


#endif /* BOARD_H */
