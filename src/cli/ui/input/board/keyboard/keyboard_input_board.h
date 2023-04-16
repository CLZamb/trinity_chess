#ifndef KEYBOARD_INPUT_PLAYER_H
#define KEYBOARD_INPUT_PLAYER_H

#include "ui/input/board/board_input.h"
#include "ui/input/input_types/keyboard/keyboard_base.h"

class KeyboardInputBoard : public BoardInput {
public:
  KeyboardInputBoard();
  virtual ~KeyboardInputBoard();
  void get_input_event() override;

private:
  std::unordered_map<Keyboard::Key, KeyCode::Key> m_keycodes {
    {Keyboard::W, KeyCode::UP},
    {Keyboard::A, KeyCode::LEFT},
    {Keyboard::S, KeyCode::DOWN},
    {Keyboard::D, KeyCode::RIGHT},
    {Keyboard::UP, KeyCode::UP},
    {Keyboard::LEFT, KeyCode::LEFT},
    {Keyboard::DOWN, KeyCode::DOWN},
    {Keyboard::RIGHT, KeyCode::RIGHT},
    {Keyboard::ENTER, KeyCode::ENTER},
  };
  void handle_arrow_keys(const Keyboard::Key key);
  KeyboardBase m_k_input;
};

#endif /* KEYBOARD_INPUT_PLAYER_H */
