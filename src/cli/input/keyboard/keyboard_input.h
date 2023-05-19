#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <unordered_map>

#include "input/input_component.h"
#include "input/keyboard/keyboard.h"
#include "keyboard_keycode.h"

struct EventKeyboard {
  void set_key_code(const ASCIICharEncoding c) { m_keycode = m_keycodes.at(c); }

  KeyCode::Key get_key_code() const { return m_keycode; }

  bool is_the_key_supported(const ASCIICharEncoding &k) {
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

class KeyboardInput : public InputComponent {
 public:
  KeyboardInput();
  void send_event_input_to_listeners() override;

 private:
  EventKeyboard m_keyboard_event;
  Keyboard m_keyboard;
};

#endif /* KEYBOARD_INPUT_H */
