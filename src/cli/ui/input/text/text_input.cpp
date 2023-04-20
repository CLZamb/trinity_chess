#include "text_input.h"

TextInput::TextInput() {}

TextInput::~TextInput() {}

void TextInput::get_input_event() {
  if (_events.find(STRING) == _events.end()) {
    std::cout << "event not supported" << std::endl;
    return;
  }

  std::cout << " >> ";
  m_text = m_text_input.get_string_input();

  m_event_command.udpate_string_input(m_text);

  for( auto&& event : Input::_events.at(STRING) )
    event( m_event_command );
}
