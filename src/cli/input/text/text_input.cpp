#include "text_input.h"
#include <iostream>

TextInput::TextInput(const std::string &str) {
  m_string_before_prompt = str;
}

void TextInput::set_string_before_prompt(const std::string &str) {
  m_string_before_prompt = str;
}

void TextInput::send_event_input_to_listeners() {
  std::cout << m_string_before_prompt;

  m_event_text.udpate_string_input(m_text_input.get_string_input());

  EventEmitter::send_event(m_event_text);
}
