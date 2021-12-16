#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <string>
#include "../../common/headers/common.h"
#include "../../graphics//headers/pieces_drawings.hpp"
#include "../../piece/headers/piece.h"
#include "../../piece/headers/pieces.h"
#include "utils.h"
#include "../../player/headers/player.h"
#include "../headers/square.h"
#include "../../game/headers/move.h"
#include "../../game/headers/game_turn_observer.h"
#include "../../graphics/headers/board_drawing.h"
#include "BoardBitboard.h"

using std::shared_ptr;

class Board {
 public:
  explicit Board();
  // explicit Board(string fen);
  virtual ~Board();
  void _init();
  void draw();
  void make_move(Move mv);
  void move_piece_to_square(Piece* piece, SquareIndices from, SquareIndices to);
  void parser_fen(string fen);
  bool is_checkmate();
  bool is_legal_move(std::shared_ptr<Player> turn, Move&);
  int evaluate_board() { return 0; }
  Piece* get_piece_at_square(int);
  Displayable* get_drawing();

 private:
  bool exist_piece_at_square(const int& pos);
  bool is_legal_attack_move(Move & m);
  bool is_legal_non_attack_move(Move & m);
  bool is_attack_move(std::shared_ptr<Player> turn, const int& to);
  void create_board_squares();
  void add_to_board(int piece, SquareIndices position);
  bool is_number(char c);
  bool check_captured_belongs_to_opponent_player(std::shared_ptr<Player> turn, const int& pos);
  bool check_piece_belongs_to_current_player(std::shared_ptr<Player> turn, const int& pos);

  Square& get_square_at_pos(int pos);
  static const size_t board_rwo_sizea = 8;
  static const size_t board_column_sizea = 8;
  std::array<Square, board_rwo_sizea * board_column_sizea> m_squares;  
  // Square* p_squares[board_rwo_sizea * board_column_sizea /*board size*/] = {nullptr};
  Pieces m_pieces;
  BoardDrawing m_bdrawing{m_squares};
  BoardBitboard board_state;
  bool checkmate = false;
};


#endif /* BOARD_H */
