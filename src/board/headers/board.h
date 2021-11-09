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

using std::shared_ptr;

class Board : public GameTurnObserver {
 public:
  explicit Board();
  virtual ~Board();
  void _init();
  void make_move(Move mv);
  void set_players(
      std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
  void move_piece_to_square(Piece* piece, SquareIndices from, SquareIndices to);
  void update_turn(GameTurn::players turn);
  void parser_fen(string fen);
  bool is_checkmate();
  bool is_legal_move(Move&);
  int evaluate_board() { return 0; }
  Piece* get_piece_at_square(int);

  Displayable* get_drawing();
  shared_ptr<Player> get_turn();
  shared_ptr<Player> get_opponent();
  shared_ptr<Player> get_player_1();
  shared_ptr<Player> get_player_2();
  friend std::ostream& operator<<(std::ostream& os, Board& b);

 private:
  void create_board_squares();
  void create_empty_squares_drawing();
  void add_to_board(int piece, SquareIndices position);
  bool is_number(char c);
  bool check_piece_belongs_to_current_player(Piece*);
  char left_border(int row, int col);

  Square* get_square_at_pos(int pos);
  box wSquare, bSquare;
  Square* p_squares[8 * 8 /*board size*/] = {nullptr};
  BoardDrawing m_bdrawing{p_squares};
  Pieces m_pieces;
  bool checkmate = false;

  GameTurn::players m_turn = GameTurn::player_1;

 protected:
  std::shared_ptr<Player> player1, player2, turn, opponent;
};


#endif /* BOARD_H */
