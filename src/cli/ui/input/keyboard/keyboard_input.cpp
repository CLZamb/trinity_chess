#include "keyboard_input.h"
#include <iostream>

KeyboardInput::KeyboardInput() {}

KeyboardInput::~KeyboardInput() {}

void KeyboardInput::get_input_event() {
  Keyboard::Key key = m_k_input.read_key();

  if (key == Keyboard::ARROW_KEY)
    key = m_k_input.read_arrow_key();

  if (_events.find(key) == _events.end()) {
    std::cout << "key not supported" << std::endl;
    return;
  }

  m_command_event.update_key_code(key);

  for (auto &&event : Input::_events.at(key))
    event(m_command_event);
}
