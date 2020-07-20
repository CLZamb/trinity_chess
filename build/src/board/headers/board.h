#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>
#include <string>
#include "../../../include/common/headers/common.h"
#include "box.h"
#include "pieces_drawings.hpp"
#include "piece.h"
#include "utils.h"
#include "../../headers/player.h"
#include "../../display/headers/section.h"
#include "../../display/headers/Idisplay.h"
#include "../headers/square.h"
#include "../../headers/move.h"
#include "../../headers/game_turn_observer.h"

using std::shared_ptr;

class Board : public Displayable, public GameTurnObserver {
 public:
  Board();
  virtual ~Board();
  void _init();
  void make_move(Move mv);
  void set_players(
      std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
  void move_piece_to_square(Piece* piece, SquareIndices from, SquareIndices to);
  void update_turn(GameTurn::players turn);
  void parser_fen(string fen);
  void set_checkmate_true();
  bool is_checkmate();
  bool is_valid_move(string mv);
  int evaluate_board() { return 0; }
  Piece* get_piece_at_square(int);

  void draw();
  shared_ptr<Player> get_turn();
  shared_ptr<Player> get_opponent();
  shared_ptr<Player> get_player_1();
  shared_ptr<Player> get_player_2();
  friend std::ostream& operator<<(std::ostream& os, Board& b);

 private:
  void create_pieces();
  void create_board_squares();
  void create_empty_squares_drawing();
  void add_to_board(int piece, SquareIndices position);
  bool is_number(char c);
  char left_border(int row, int col);

  Square* get_square_at_pos(int pos);
  box wSquare, bSquare;
  std::array<Square*, 8 * 8> test = {nullptr};
  Square* p_squares[8 * 8 /*board size*/] = {nullptr};
  std::array<Piece*, 13> m_pieces {
    nullptr,  // EMPTY 0
      // black pieces
      new Piece(bP),
      new Piece(bR),
      new Piece(bN),
      new Piece(bB),
      new Piece(bQ),
      new Piece(bK),
      // white pieces
      new Piece(wP),
      new Piece(wR),
      new Piece(wN),
      new Piece(wB),
      new Piece(wQ),
      new Piece(wK),  // 12
  };

  bool checkmate = false;
  shared_ptr<Section> p_top_section;
  shared_ptr<Section> p_main;
  shared_ptr<Section> p_bottom_section;

  GameTurn::players m_turn = GameTurn::player_1;

 protected:
  std::shared_ptr<Player> player1, player2, turn, opponent;
};


#endif /* BOARD_H */
