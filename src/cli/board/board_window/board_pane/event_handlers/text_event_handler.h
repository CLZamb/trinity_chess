#ifndef TEXT_EVENT_HANDLER_H
#define TEXT_EVENT_HANDLER_H

#include <memory>

#include "board/board_window/board_pane/event_handlers/IPane_event_handler.h"
#include "input/text/text_input.h"

class TextEventHandler : public IPaneEventHandler {
 public:
  void handle_string_input(EventText &e);
  std::string get_move_as_string() override;
  void change_side() override {}

 private:
  std::string m_string_move;
};

#endif /* TEXT_EVENT_HANDLERS_H */
