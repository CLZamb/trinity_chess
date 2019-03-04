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

  void add_to_board(string type, int position, string color);
  void create_board_squares();
  void create_square_bases();
  void set_pieces_on_board();
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
      bool has_piece();
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
  void generate_all_moves(bool side, MoveList* moveList);
  void make_move(Piece*, int from, int to);
  void undo_move(int pieceType, int pos);
  void capture_piece(Piece* p, int pos);
  int get_board_score();
  U64 get_piece_attacks(Piece* piece, int from);
  U64 get_non_attack_moves(Piece* piece, int from);
  U64 get_own_pieces_occ(bool is_black);
  U64 get_all_w_pieces();
  U64 get_all_b_pieces();
  Square* get_square_at_pos(int pos);
  Piece* get_piece_at_pos(int);
};

#endif /* BOARD_H */
