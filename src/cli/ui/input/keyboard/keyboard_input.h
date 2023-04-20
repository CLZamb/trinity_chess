#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <unordered_map>
#include "ui/input/input.h"
#include "ui/input/command_event.h"
#include "ui/input/keyboard/keyboard_base.h"

struct CommandEventKeyboard : public CommandEvent {
  void update_key_code(const Keyboard::Key c) {
    CommandEvent::m_keycode = m_keycodes.at(c);
  }

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
};

class KeyboardInput : public Input {
public:
  KeyboardInput();
  virtual ~KeyboardInput();
  void get_input_event() override;

private:

  KeyboardBase m_k_input;
  CommandEventKeyboard m_command_event;
};

#endif /* KEYBOARD_INPUT_H */
