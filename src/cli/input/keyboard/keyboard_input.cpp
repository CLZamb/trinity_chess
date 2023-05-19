#include "keyboard_input.h"

#include <iostream>

KeyboardInput::KeyboardInput() {}

void KeyboardInput::send_event_input_to_listeners() {

  ASCIICharEncoding enconding = m_keyboard.read_key();

  if (!m_keyboard_event.is_the_key_supported(enconding)) {
    std::cout << "key not supported" << std::endl;
    return;
  }

  m_keyboard_event.set_key_code(enconding);

  EventEmitter::send_event(m_keyboard_event);
}
