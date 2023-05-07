#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <unordered_map>

#include "input/input.h"
#include "input/keyboard/keyboard.h"
#include "keyboard_keycode.h"

struct CommandEventKeyboard {
  void set_key_code(const ASCIICharEncoding c) { m_keycode = m_keycodes.at(c); }

  KeyCode::Key get_key_code() const { return m_keycode; }

  bool check_is_a_directional_key(const ASCIICharEncoding &k) {
    return m_keycodes.find(k) != m_keycodes.end();
  }

 private:
  KeyCode::Key m_keycode{KeyCode::NONE};

  const std::unordered_map<ASCIICharEncoding, KeyCode::Key> m_keycodes{
      {          ASCIICharEncoding::W,    KeyCode::UP},
      {          ASCIICharEncoding::A,  KeyCode::LEFT},
      {          ASCIICharEncoding::S,  KeyCode::DOWN},
      {          ASCIICharEncoding::D, KeyCode::RIGHT},
      {   ASCIICharEncoding::ARROW_UP,    KeyCode::UP},
      { ASCIICharEncoding::ARROW_LEFT,  KeyCode::LEFT},
      { ASCIICharEncoding::ARROW_DOWN,  KeyCode::DOWN},
      {ASCIICharEncoding::ARROW_RIGHT, KeyCode::RIGHT},
      {      ASCIICharEncoding::ENTER, KeyCode::ENTER},
  };
};

class KeyboardInput : public Input {
 public:
  void listen_for_input_events() override;

 private:
  Keyboard m_keyboard;
  CommandEventKeyboard m_command_event;
  const std::string keyboard_event_name = typeid(CommandEventKeyboard).name();
};

#endif /* KEYBOARD_INPUT_H */
