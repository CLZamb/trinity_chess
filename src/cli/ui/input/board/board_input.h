#ifndef BOARD_INPUT_H
#define BOARD_INPUT_H

#include "game/turn/game_turn_observer.h"
#include "ui/graphics/board/board_pane.hpp"

class BoardInput : public GameTurnObserver {
 public:
  enum InputEvent {
    NO_EVENT = 0,
    COMPLETED = 1,
    PRINT = 0,
  };

  virtual InputEvent get_next_string_move(string& callback) = 0;
  virtual void update_turn(const PlayerInfo &) = 0;
};

#endif /* BOARD_INPUT_H */
