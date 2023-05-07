#include "text_input.h"

TextInput::TextInput() {}

TextInput::~TextInput() {}

void TextInput::set_string_before_prompt(const std::string& str) {
  m_string_before_prompt = str;
}

void TextInput::listen_for_input_events() {
  if (_events.find(keyboard_event_name) == _events.end()) {
    std::cout << "event not supported" << std::endl;
    return;
  }

  std::cout << m_string_before_prompt;

  m_text = m_text_input.get_string_input();

  m_event_command.udpate_string_input(m_text);

  for (auto &&event : Input::_events.at(keyboard_event_name)) {
    event(&m_event_command);
}
}
