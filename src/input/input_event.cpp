#include "headers/input_event.h"

InputEvent::InputEvent() {}

void InputEvent::set_type(Type t) { m_type = t; }
void InputEvent::set_pressed_key(InputKeys::Key t) { m_key = t; }
void InputEvent::set_input(const string &i) { m_input = i; }
void InputEvent::set_position(const int &i) {
  m_prev_pos = m_pos;
  m_pos = i;
}

InputEvent::Type InputEvent::get_type() const { return m_type; }
InputKeys::Key InputEvent::get_pressed_key() const { return m_key; }
string InputEvent::get_input() const { return m_input; }
int InputEvent::get_position() const { return m_pos; }
int InputEvent::get_previous_position() const { return m_prev_pos; }
