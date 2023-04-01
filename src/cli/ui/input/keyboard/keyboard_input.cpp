#include "arrow_input.h"

ArrowInput::ArrowInput() : m_i_p(*this) {
  set_terminal_new_attributes();
}

ArrowInput::~ArrowInput() { restore_terminal_configuration(); }
