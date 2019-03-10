#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include "ZobristKey.h"
#include "Transposition_table.h"

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
  void move_piece_bits(int* move);
  void undo_last_bitboard_move(int last_move);
  void undo_last_move();
  void change_turn();
  bool is_valid_move(Move);
  bool get_checkmate();

  class MoveGenerator {
   private:
      std::map<int, int> move_map;

      Movement* movement;
      int negamax(int, int, int, int);

   public:
      explicit MoveGenerator(Movement* movement) : movement(movement) {}
      Move get_best_move();
      void generate_moves(MoveList*);
      int evaluate_board();
  };
};

// typedef vector<Movement::Move> MoveSet;

#endif /* MOVEMENT_H */
