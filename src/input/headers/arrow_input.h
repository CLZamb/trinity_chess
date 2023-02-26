#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include "input/headers/input_event.h"
#include "input/headers/key_reader.h"
#include "input_type.h"
#include "view/headers/board_view.h"
#include "input/headers/keyboard_base.h"
#include "input/headers/Arrow_input_menu.h"
#include "input/headers/keyboard_input_player.h"

class ArrowInput : public KeyboardBase, public InputType {
 public:
  ArrowInput();
  virtual ~ArrowInput();
  PlayerInput &get_player_input() override { return m_i_p; }

 private:
  KeyboardInputPlayer m_i_p;
};


#endif /* KEBOARD_INPUT_H */
