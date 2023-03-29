#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include "keyboard_input_player.h"

class ArrowInput : public KeyboardBase, public InputType {
 public:
  ArrowInput();
  virtual ~ArrowInput();
  PlayerInput &get_player_input() override { return m_i_p; }

 private:
  KeyboardInputPlayer m_i_p;
};


#endif /* KEBOARD_INPUT_H */
