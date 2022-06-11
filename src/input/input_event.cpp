#include "headers/input_event.h"

InputEvent::InputEvent() {}

void InputEvent::set_type(Type t) { m_type = t; }
void InputEvent::set_pressed_key(InputKeys::Key t) { m_key = t; }
void InputEvent::set_int_input(const int &i) { m_int_input = i; }
void InputEvent::set_position(const int &i) {
  m_prev_pos = m_pos;
  m_pos = i;
}

InputEvent::Type InputEvent::get_type() const { return m_type; }
InputKeys::Key InputEvent::get_pressed_key() const { return m_key; }
int InputEvent::get_int_input() const { return m_int_input; }
int InputEvent::get_position() const { return m_pos; }
int InputEvent::get_previous_position() const { return m_prev_pos; }
