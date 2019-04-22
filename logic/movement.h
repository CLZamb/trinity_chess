#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include "ZobristKey.h"
#include "transposition_table.h"

using std::string;
using std::vector;

class Movement {
private:
  Board* m_board;
  Player** pp_cur_player_turn = nullptr;
  ZobristKey m_zkey;
  TTable m_table;
  bool checkmate;
  bool check_move(Piece*, int from, int to);
  int take_piece(int pos);
  int capture_piece(int pos);
  vector<unsigned int> prev_moves;

public:
  Movement(Board*, Player** turn);
  virtual ~Movement();
  void move_piece(Move);
  void move_piece_bits(Move*);
  void undo_last_bitboard_move(Move last_move);
  void undo_last_move();
  void change_turn();
  bool is_valid_move(Move);
  bool get_checkmate();

  class MoveGenerator {
   private:
     Movement* movement;
     Board* m_board;
     bool m_stop = false;
     std::chrono::time_point<std::chrono::steady_clock> m_start;
     int m_time_allocated = 4000;
     int m_elapsed = 0;
     int negamax(int, int, int, int);
     bool time_out();
     void pick_next_move(int index, MoveList*);
     int is_repeated_move(const int& depth, int* alpha, int* beta);
     TTEntry::Flag get_flag(int alpha, int orig_alpha, int beta);

   public:
      explicit MoveGenerator(Movement* movement);
      Move root_negamax(int cur_depth);
      Move search_best_move();
      void generate_moves(MoveList*);
      int evaluate_board();
  };
};

#endif /* MOVEMENT_H */
