// File: board.h
#ifndef BOARD_H
#define BOARD_H

#pragma once

#include "Idisplay.h"
#include "bitboard.h"
#include "player.h"
#include <iostream>
#include <string>
#include <utility> // std::pair, std::make_pair
#include <vector>
#include <map>

using std::map;

class Board : public IDisplay {
 public:
  Board();
  ~Board();

  void _init();
  void set_players(Player* player1, Player* player2);
  void print();
  void undo_square_move(int piece, int piece_captured, int from, int to);
  void generate_all_moves(bool side, MoveList* moveList);
  void move_piece_to_square(int piece, int from, int to);
  void move_squares(Piece*, int from, int to);
  void move_piece_bits(int type, int from, int to);
  void undo_move(int piece, int piece_captured, int from, int to);
  void capture_piece(int captured, int pos);
  void update_killers(Move mv);
  void update_search_history(int piece, int to, int depth);
  int evaluate_board();
  int get_piece_at(int pos);
  U64 get_piece_attacks(int type, int from);
  U64 get_non_attack_moves(int type, int from);
  U64 get_own_pieces_occ(bool is_black);
  U64 get_all_pieces_bitboard() const;
  U64 get_piece_bitboard(int piece) const;
  Piece* get_piece_at_square(int);

 private:
  // default fen
  string pieces_start_pos =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  Player* player1, *player2;
  box wSquare, bSquare;
  Bitboard m_bb;
  Move test;

  void add_to_board(int piece, int position);
  void parser_fen(string fen);
  void create_board_squares();
  void create_squares_drawing();
  std::string get_str_type(int type);
  bool is_number(char c);
  bool is_piecetype(char c, map<char, int> pieces);

  class Square {
   private:
      box* p_base_drawing = nullptr;
      box* p_cur_drawing = nullptr;
      Piece* p_piece = nullptr;
      bool m_is_black_square = false;

   public:
      Square(box*, bool);
      virtual ~Square();

      char* at(int i);
      void set_piece(Piece* piece);
      void clear_square();
      bool is_black_square();
      Piece* get_piece();
      box* get_current_drawing();
  };
  Square* p_board[64] = {nullptr};
  Square* get_square_at_pos(int pos);
};

#endif /* BOARD_H */
