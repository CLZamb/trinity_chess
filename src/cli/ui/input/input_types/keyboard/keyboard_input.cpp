#include "keyboard_input.h"
#include <iostream>

KeyboardInput::KeyboardInput() {
  set_terminal_new_attributes();
}

KeyboardInput::~KeyboardInput() { restore_terminal_configuration(); }
