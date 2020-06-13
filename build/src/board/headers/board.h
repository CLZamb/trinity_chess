#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include "../../../include/common/headers/common.h"
#include "box.h"
#include "drawing.hpp"
#include "piece.h"
#include "utils.h"
#include "../../headers/player.h"
#include "../../display/headers/pane.h"
#include "../../display/headers/gui_controller.h"

using std::vector;
using std::shared_ptr;

class Board {
public:
  Board();
  virtual ~Board();
  void _init(Pane* board_drawing);
  void make_move(string pl_move);
  void set_players(Player* player1, Player* player2);
  // void undo_square_move(int piece, int piece_captured, SquareIndices from, SquareIndices to);
  // void move_piece_to_square(int piece, SquareIndices from, SquareIndices to);
  // void move_squares(Piece*, SquareIndices from, SquareIndices to);
  // void capture_piece(Move mv, SquareIndices pos);
  void change_turn();
  void parser_fen(string fen);
  void set_checkmate_true();
  bool is_checkmate();
  int evaluate_board() { return 0; }
  // Piece* get_piece_at_square(int);
  // PlayerMove get_next_move();
  // Player* get_active_player();
  // Player* get_opponent();

  void draw_board();
  Player* get_turn();
  Player* get_player_1();
  Player* get_player_2();
  friend std::ostream& operator<<(std::ostream& os, Board& b);

 private:
  class Square;
  void create_pieces();
  void create_board_squares();
  void create_empty_squares_drawing();
  void add_to_board(int piece, SquareIndices position);
  bool is_number(char c);
  char left_border(int row, int col);
  string right_border(vector<string> info, int col);
  string format_line(string tittle, string message);

  Square* get_square_at_pos(int pos);
  box wSquare, bSquare;
  Square* p_squares[8 * 8 /*board size*/] = {nullptr};
  vector<Piece*> m_pieces {13, nullptr};
  bool checkmate = false;
  Pane* m_drawing;
  shared_ptr<Section> p_main;

  Player* player1, *player2, *turn;
};

class Board::Square {
 public:
    Square(const Board& board, box*, bool);
    virtual ~Square();

    void set_piece(int type);
    void clear_square();
    char* at(int i);
    bool is_black_square();
    // Piece* get_piece();
    box* get_current_drawing();

 private:
    const Board& m_board;
    box* p_empty_square_drawing = nullptr;
    box* p_cur_drawing = nullptr;
    // Piece* p_piece = nullptr;
    bool m_is_black_square = false;
};

#endif /* BOARD_H */
