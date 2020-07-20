#ifndef BOARD_WITH_INFO_H
#define BOARD_WITH_INFO_H

#include "board.h"
#include "savable.h"
#include "../../headers/game_turn_observer.h"

class BoardWithInfo : public GameTurnObserver {
 public:
  explicit BoardWithInfo(Board* board, Savable* info);
  virtual ~BoardWithInfo();

  void make_move(Move m);
  void update_turn(GameTurn::players turn);
 private:
  Board* p_board;
  Savable* p_info;
};

#endif /* BOARD_WITH_INFO_H */
