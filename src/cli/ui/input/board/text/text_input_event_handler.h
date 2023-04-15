#ifndef TEXT_INPUT_EVENT_HANDLER_H
#define TEXT_INPUT_EVENT_HANDLER_H

#include "ui/input/input_types/input_handler.h"
#include "ui/input/input_types/text/text_input_base.h"

class TextInputEventHandler : public InputHandler {
 public:
  TextInputEventHandler () {}
  virtual ~TextInputEventHandler () {}

  bool handle_event(KeyCode::Key e, string &call_back) override {
    call_back = "quit";
    switch (e) {
      case KeyCode::ENTER:
        std::cout << " >> ";
        call_back = m_text.get_string_input();
        return true;
      default: return false;
    }
  }

 private:
  TextInputBase m_text;
};

#endif /* TEXT_INPUT_EVENT_HANDLER_H */
