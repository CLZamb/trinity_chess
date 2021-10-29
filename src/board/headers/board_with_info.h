#ifndef BOARD_WITH_INFO_H
#define BOARD_WITH_INFO_H

#include "board.h"
#include "info.h"
#include "savable.h"
#include "../../headers/game_turn_observer.h"

class BoardWithInfo : public GameTurnObserver {
 public:
  BoardWithInfo();
  virtual ~BoardWithInfo();

  void make_move(Move m);
  void update_turn(GameTurn::players turn);
  void _init();
  Board* get_board();
  Info* get_info();

 private:
  MoveValidator mv;
  Board m_board;
  Info m_info;
};

#endif /* BOARD_WITH_INFO_H */
