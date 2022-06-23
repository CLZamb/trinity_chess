#include "headers/keyboard_input.h"

KeyboardInput::KeyboardInput() : m_i_p(*this) {
  set_terminal_new_attributes();
}

KeyboardInput::~KeyboardInput() { restore_terminal_configuration(); }
