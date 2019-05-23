// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "Idisplay.h"
#include <iostream>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <vector>
#include <map>
#include "movement.h"

using std::map;

class Board {
 public:
  Board();
  ~Board();

  void _init();
  void set_players(Player* player1, Player* player2);
  void undo_square_move(int piece, int piece_captured, int from, int to);
  void move_piece_to_square(int piece, int from, int to);
  void move_squares(Piece*, int from, int to);
  Piece* get_piece_at_square(int);
  PlayerMove get_next_move();
  Player* active_player();

  friend std::ostream& operator<<(std::ostream& os, const Board& b);

  // adapter_pattern Movement
  void undo_last_move();
  void move_piece(Move mv);
  bool is_valid_move(Move);
  bool get_checkmate();
  Movement* get_movement();

  // adapter_pattern Bitboard
  void generate_all_moves(bool side, MoveList* moveList);
  void move_piece_bits(int type, int from, int to);
  void update_killers(Move mv);
  void update_search_history(int piece, int to, int depth);
  void capture_piece(int captured, int pos);
  void undo_move(int piece, int piece_captured, int from, int to);
  U64 get_piece_attacks(int type, int from);
  U64 get_non_attack_moves(int type, int from);
  U64 get_own_pieces_occ(bool is_black);
  U64 get_all_pieces_bitboard() const;
  U64 get_piece_bitboard(int piece) const;
  int get_piece_at(int pos);
  int evaluate_board();

 private:
  // default fen
  string pieces_start_pos =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

  Player* player1, *player2, *turn;
  box wSquare, bSquare;
  Bitboard m_bb;
  Move test;
  Movement movement_controller{this, &turn};

  class Square;
  Square* p_board[64] = {nullptr};
  Square* get_square_at_pos(int pos);

  void create_board_squares();
  void create_squares_drawing();
  void parser_fen(string fen);
  void add_to_board(int piece, int position);
  bool is_number(char c);
};

class Board::Square {
 public:
    Square(box*, bool);
    virtual ~Square();

    void set_piece(Piece* piece);
    void clear_square();
    char* at(int i);
    bool is_black_square();
    Piece* get_piece();
    box* get_current_drawing();

 private:
    box* p_base_drawing = nullptr;
    box* p_cur_drawing = nullptr;
    Piece* p_piece = nullptr;
    bool m_is_black_square = false;
};

#endif /* BOARD_H */
