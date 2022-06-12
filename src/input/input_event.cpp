#include "headers/input_event.h"

InputEvent::InputEvent() {}

void InputEvent::set_type(Type t) { m_type = t; }
void InputEvent::set_pressed_key(InputKeys::Key t) { m_key = t; }
void InputEvent::set_int_input(const int &i) { m_int_input = i; }
void InputEvent::set_string_input(const string& i) {  m_string_input = i; }

InputEvent::Type InputEvent::get_type() const { return m_type; }
InputKeys::Key InputEvent::get_pressed_key() const { return m_key; }
int InputEvent::get_int_input() const { return m_int_input; }
const string &InputEvent::get_string_input()  const {  return m_string_input; }


