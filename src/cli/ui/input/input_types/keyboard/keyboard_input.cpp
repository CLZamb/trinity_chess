#include "keyboard_input.h"

KeyboardInput::KeyboardInput() {
  KeyboardBase::set_terminal_new_attributes();
}

KeyboardInput::~KeyboardInput() { 
  KeyboardBase::restore_terminal_configuration();
}
