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

class Board : public IDisplay {
 private:
  Player* player1, *player2;
  box wSquare, bSquare;
  Bitboard m_bb;
  Move test;

  void add_to_board(int piece, int position);
  void set_all_pieces_on_board();

  void create_board_squares();
  void create_square_bases();
  std::string get_str_type(int type);

  class Square {
   private:
      box* p_base_drawing;
      box* p_cur_drawing;
      Piece* p_piece = nullptr;
      bool m_occupied = false;
      bool m_black_box;

   public:
      Square(box*, bool);
      virtual ~Square();

      char* get_content(int i);
      void set_piece(Piece* piece);
      void clear_square();
      bool is_black_box();
      Piece* get_piece();
      box* get_current_drawing();
  };

  Square* p_board[64] = {nullptr};

 public:
  Board();
  ~Board();

  void _init(Player*, Player*);
  void print();
  void undo_square_move(int piece, int piece_captured, int from, int to);
  void generate_all_moves(bool side, MoveList* moveList);
  void move_piece_to_square(int piece, int from, int to);
  void move_squares(Piece*, int from, int to);
  void move_piece_bits(int type, int from, int to);
  void undo_move(int piece, int piece_captured, int from, int to);
  void capture_piece(int piece, int captured, int pos);
  void update_killers(Move mv);
  void update_search_history(int piece, int to, int depth);
  int get_board_score();
  int get_piece_at(int pos);
  U64 get_piece_attacks(int type, int from);
  U64 get_non_attack_moves(int type, int from);
  U64 get_own_pieces_occ(bool is_black);
  U64 get_all_pieces_bitboard() const;
  U64 get_piece_bitboard(int piece) const;
  Square* get_square_at_pos(int pos);
  Piece* get_piece_at_square(int);
};

#endif /* BOARD_H */