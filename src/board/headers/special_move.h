#ifndef SPECIAL_MOVE_H
#define SPECIAL_MOVE_H

#include "board/headers/squares.h"
#include "game/headers/move.hpp"

class SpecialMove {
 public:
  virtual void assign_special_to_move(Move&) = 0;
  virtual void handle_special_move(const Move& m, Squares& squares) = 0;
};

#endif /* SPECIAL_MOVE_H */
