#ifndef BOARD_INPUT_H
#define BOARD_INPUT_H

#include "game/turn/game_turn_observer.h"
#include "ui/input/board/keyboard/key_code.h"
#include <string>

class BoardInput {
 public:
  virtual ~BoardInput() {}
  virtual KeyCode::Key get_input_event() = 0;
};

#endif /* BOARD_INPUT_H */
