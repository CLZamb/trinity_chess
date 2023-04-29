#ifndef TEXT_INPUT_BOARD_H
#define TEXT_INPUT_BOARD_H

#include "ui/input/input.h"
#include "ui/input/text/text_input_base.h"

struct CommandEventText {
  void udpate_string_input(const std::string &c) {
    m_command_string = c;
  }

  std::string get_text() const {
    return m_command_string;
  }
 private:
  std::string m_command_string{""};
};

class TextInput : public Input {
 public:
  TextInput();
  virtual ~TextInput();
  void listen_for_input_events() override;
  void set_string_before_prompt(const string& space);
 private:
  string m_string_before_prompt{0};
  string m_text;
  TextInputBase m_text_input;
  CommandEventText m_event_command;
  const string keyboard_event_name = typeid(CommandEventText).name();
};

#endif /* TEXT_INPUT_BOARD_H */
