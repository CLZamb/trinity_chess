#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "board.h"
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using std::string;
using std::vector;

class Movement {
private:
  Board* m_board;
  Player** pp_cur_player_turn = nullptr;
  bool checkmate;
  bool check_move(Piece*, int from, int to);
  Piece* take_piece(int pos);
  Piece* capture_piece(int pos);
  int get_type_capture_piece(int pos);
  unsigned int get_from_sq(int);
  unsigned int get_to_sq(int);
  unsigned int get_captured(int);
  unsigned int get_piece(int);
  vector<unsigned int> prev_moves;

public:
  Movement(Board*, Player** turn);
  virtual ~Movement();
  void move_piece(Move);
  void try_move_piece(int move);
  void undo_last_move(bool real_move = false);
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
      void order_moves(MoveList*);
      int evaluate_board();
  };
};

// typedef vector<Movement::Move> MoveSet;

#endif /* MOVEMENT_H */
