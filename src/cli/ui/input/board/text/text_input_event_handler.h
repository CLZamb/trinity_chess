#ifndef TEXT_INPUT_EVENT_HANDLER_H
#define TEXT_INPUT_EVENT_HANDLER_H

#include "ui/input/input_types/text/text_input_base.h"
#include "ui/input/board/keyboard/key_code.h"

class TextInputEventHandler {
 public:
  TextInputEventHandler () {}
  virtual ~TextInputEventHandler () {}

  bool handle_event(KeyCode::Key e) {
    call_back = "quit";
    switch (e) {
      case KeyCode::ENTER:
        std::cout << " >> ";
        call_back = m_text.get_string_input();
        return true;
      default: return false;
    }
  }

  string get_string() {
    return call_back;
  }

 private:
  string call_back{""};
  TextInputBase m_text;
};

#endif /* TEXT_INPUT_EVENT_HANDLER_H */
