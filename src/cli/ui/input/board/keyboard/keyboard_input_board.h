#ifndef KEYBOARD_INPUT_PLAYER_H
#define KEYBOARD_INPUT_PLAYER_H

// #include "ui/graphics/board/board_view.h"
#include "ui/input/board/board_input.h"
#include "ui/input/input_types/keyboard/keyboard_base.h"

class KeyboardInputBoard : public BoardInput {
public:
  KeyboardInputBoard();
  virtual ~KeyboardInputBoard();
  KeyCode::Key get_input_event() override;

private:
  KeyCode::Key handle_arrow_keys(const Keyboard::Key key);
  KeyboardBase m_k_input;
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
