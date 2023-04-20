#ifndef BOARD_TEXT_PANE_H
#define BOARD_TEXT_PANE_H

#include "IBoard_event_handler.hpp"
#include "ui/board/board_pane/board_pane.h"
#include "ui/input/text/text_input.h"

class BoardTextEventHandler : public IBoardEventHandler {
public:
  BoardTextEventHandler(std::shared_ptr<BoardPane> b, shared_ptr<Input> p)
      : p_board_pane(b) {
    p->bind(TextInput::STRING, &BoardTextEventHandler::handle_string_input, this);
  }

  virtual ~BoardTextEventHandler() {}

  bool has_events() override { return false; }

  string get_string() override { return call_back; }

  void handle_string_input(CommandEvent & e) {
    call_back = e.get_string();
  }

private:
  shared_ptr<BoardPane> p_board_pane;
  string call_back{""};
};

#endif /* BOARD_TEXT_PANE_H */
