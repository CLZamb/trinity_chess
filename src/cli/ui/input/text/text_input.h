#ifndef TEXT_INPUT_BOARD_H
#define TEXT_INPUT_BOARD_H

#include "ui/input/input.h"
#include "ui/input/text/text_input_base.h"

struct CommandEventText : public CommandEvent {
  void udpate_string_input(const std::string &c) {
    CommandEvent::m_command_string = c;
  }
};

class TextInput : public Input {
 public:
  enum EventIDs {
    STRING = 0,
  };

  TextInput();
  virtual ~TextInput();
  void get_input_event() override;
 private:
  string m_text;
  TextInputBase m_text_input;
  CommandEventText m_event_command;
};

#endif /* TEXT_INPUT_BOARD_H */
