#include "keyboard_input.h"
#include <iostream>

KeyboardInput::KeyboardInput() {}

KeyboardInput::~KeyboardInput() {}

void KeyboardInput::listen_for_input_events() {
  if (_events.find(keyboard_event_name) == _events.end()) {
    std::cout << "event not supported" << std::endl;
    return;
  }

  Keyboard::Key key = m_k_input.read_key();

  if (!m_command_event.check_if_is_in_map(key)) { 
    std::cout << "key not supported" << std::endl;
    return;
  }

  m_command_event.set_key_code(key);

  for (auto &&event : Input::_events.at(keyboard_event_name)) {
    event(&m_command_event);
  }
}
