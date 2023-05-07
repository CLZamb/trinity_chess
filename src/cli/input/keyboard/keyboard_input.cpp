#include "keyboard_input.h"

#include <iostream>

void KeyboardInput::listen_for_input_events() {
  if (Input::_events.find(keyboard_event_name) == Input::_events.end()) {
    std::cout << "event not supported" << std::endl;
    return;
  }

  ASCIICharEncoding enconding = m_keyboard.read_key();

  if (!m_command_event.check_is_a_directional_key(enconding)) {
    std::cout << "key not supported" << std::endl;
    return;
  }

  m_command_event.set_key_code(enconding);

  for (auto &&event : Input::_events.at(keyboard_event_name)) {
    event(&m_command_event);
  }
}
