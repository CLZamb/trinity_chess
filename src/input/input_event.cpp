#include "headers/input_event.h"

InputEvent::InputEvent() {}
InputEvent::InputEvent(const EventType &t) { m_event_type = t; }

void InputEvent::set_type(const Type &t)            { m_type = t; }
void InputEvent::set_event_type(const EventType &t) { m_event_type = t; }
void InputEvent::set_pressed_key(InputKeys::Key t)  { m_key = t; }
void InputEvent::set_int_input(const int &i)        { m_int_input = i; }
void InputEvent::set_string_input(const string& i)  { m_string_input = i; }

InputEvent::Type      InputEvent::get_type()         const { return m_type; }
InputEvent::EventType InputEvent::get_event_type()   const { return m_event_type; }
InputKeys::Key        InputEvent::get_pressed_key()  const { return m_key; }
int                   InputEvent::get_int_input()    const { return m_int_input; }
const string         &InputEvent::get_string_input() const { return m_string_input; }


