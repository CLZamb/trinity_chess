#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <unordered_map>

#include "input/input.h"
#include "input/keyboard/keyboard_base.h"

struct KeyCode {
  enum Key {
    NONE,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    ENTER,
  };
};

struct CommandEventKeyboard {
  void set_key_code(const Keyboard::Key c) { m_keycode = m_keycodes.at(c); }

  KeyCode::Key get_key_code() const { return m_keycode; }

  bool check_if_is_in_map(const Keyboard::Key &k) {
    return m_keycodes.find(k) != m_keycodes.end();
  }

 private:
  KeyCode::Key m_keycode{KeyCode::NONE};

  std::unordered_map<Keyboard::Key, KeyCode::Key> m_keycodes{
      {Keyboard::W, KeyCode::UP},        {Keyboard::A, KeyCode::LEFT},
      {Keyboard::S, KeyCode::DOWN},      {Keyboard::D, KeyCode::RIGHT},
      {Keyboard::UP, KeyCode::UP},       {Keyboard::LEFT, KeyCode::LEFT},
      {Keyboard::DOWN, KeyCode::DOWN},   {Keyboard::RIGHT, KeyCode::RIGHT},
      {Keyboard::ENTER, KeyCode::ENTER},
  };
};

class KeyboardInput : public Input {
 public:
  KeyboardInput();
  virtual ~KeyboardInput();
  void listen_for_input_events() override;

 private:
  KeyboardBase m_k_input;
  CommandEventKeyboard m_command_event;
  const string keyboard_event_name = typeid(CommandEventKeyboard).name();
};

#endif /* KEYBOARD_INPUT_H */
