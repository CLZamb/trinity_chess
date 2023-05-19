#ifndef TEXT_INPUT_BOARD_H
#define TEXT_INPUT_BOARD_H

#include "input/input_component.h"
#include "input/text/text_input_base.h"

struct EventText {
  void udpate_string_input(const std::string &c) {
    m_command_string = c;
  }

  std::string get_text() const {
    return m_command_string;
  }
 private:
  std::string m_command_string{""};
};

class TextInput : public InputComponent {
 public:
  explicit TextInput(const std::string& str = "");
  void send_event_input_to_listeners() override;
  void set_string_before_prompt(const std::string& space);
 private:
  std::string m_string_before_prompt{0};
  TextInputBase m_text_input;
  EventText m_event_text;
};

#endif /* TEXT_INPUT_BOARD_H */
