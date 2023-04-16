#include "keyboard_input_board.h"
#include <iostream>

KeyboardInputBoard::KeyboardInputBoard() {}

KeyboardInputBoard::~KeyboardInputBoard() {}

void KeyboardInputBoard::get_input_event() {
  switch (Keyboard::Key key = m_k_input.read_key(); key) {
    case Keyboard::ARROW_KEY:
      handle_arrow_keys(m_k_input.read_arrow_key());
      break;
    case Keyboard::W:
    case Keyboard::A:
    case Keyboard::S:
    case Keyboard::D:
    case Keyboard::ENTER:
      m_events.at(key)(m_keycodes[key]);
      break;
    default:
      std::cout << "key not supported" << std::endl;
      break;
  }
}

void KeyboardInputBoard::handle_arrow_keys(Keyboard::Key key) {
  switch (key) {
    case Keyboard::UP:
    case Keyboard::DOWN:
    case Keyboard::LEFT:
    case Keyboard::RIGHT:
      m_events.at(key)(m_keycodes[key]);
      break;
    default:
      break;
  }
}
