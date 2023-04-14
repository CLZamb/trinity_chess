#include "keyboard_input_board.h"

KeyboardInputBoard::KeyboardInputBoard() {}

KeyboardInputBoard::~KeyboardInputBoard() {}

KeyCode::Key KeyboardInputBoard::get_input_event() {
  switch (Keyboard::Key key = m_k_input.read_key(); key) {
    case Keyboard::ARROW_KEY:
      return handle_arrow_keys(m_k_input.read_arrow_key());
    case Keyboard::W: return KeyCode::UP;
    case Keyboard::A: return KeyCode::LEFT;
    case Keyboard::S: return KeyCode::DOWN;
    case Keyboard::D: return KeyCode::RIGHT;
    case Keyboard::ENTER: return KeyCode::ENTER;
    default: return KeyCode::NONE;
  }
}

KeyCode::Key KeyboardInputBoard::handle_arrow_keys(Keyboard::Key k) {
  switch(k) {
    case Keyboard::UP:    return KeyCode::UP;
    case Keyboard::DOWN:  return KeyCode::DOWN;
    case Keyboard::LEFT:  return KeyCode::LEFT;
    case Keyboard::RIGHT: return KeyCode::RIGHT;
    default: return KeyCode::NONE;
  }
}
