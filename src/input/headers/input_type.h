#ifndef INPUT_TYPE_H
#define INPUT_TYPE_H

#include "game/headers/options.h"
#include "input/headers/keyboard_base.h"
#include "player/headers/player_position.h"
#include "view/headers/board_view.h"
#include "view/headers/menu_view.h"
#include "game/headers/game_turn_observer.h"
#include <string>

using std::string;

class PlayerInput : public GameTurnObserver {
 public:
  virtual void setup(BoardView& v) = 0;
  virtual string get_player_string_move(PlayerPosition&) = 0;
};

template<typename T>
class MenuInput {
 public:
  virtual ~MenuInput() {}
  virtual const Option<T>& select_menu_option() = 0;
};

class InputType {
 public:
  virtual ~InputType() {};
  virtual PlayerInput &get_player_input() = 0;
};



#endif /* INPUT_TYPE_H */
