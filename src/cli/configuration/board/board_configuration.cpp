#include "board_configuration.h"

BoardConfig::BoardConfig() {}
BoardConfig::~BoardConfig() {}

InputType BoardConfig::get_input_type() const {
  return m_input_type;
}

void BoardConfig::set_input_type(InputType i) {
  m_input_type = i;
}

void BoardConfig::set_initial_color(Color c) {
  m_initial_side = c;
}

Color &BoardConfig::get_initial_color() {
  return m_initial_side;
}
