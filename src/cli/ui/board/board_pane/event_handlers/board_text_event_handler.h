#ifndef BOARD_TEXT_PANE_H
#define BOARD_TEXT_PANE_H

#include "IBoard_event_handler.h"
#include "ui/board/board_pane/board_pane.h"
#include "ui/input/text/text_input.h"

class BoardTextEventHandler : public IBoardEventHandler {
public:
  BoardTextEventHandler(std::shared_ptr<BoardPane> b, shared_ptr<Input> p);
  virtual ~BoardTextEventHandler() = default;

  bool has_events() override;
  string get_string() override;
  void handle_string_input(CommandEvent &e);

private:
  shared_ptr<BoardPane> p_board_pane;
  string call_back{""};
};

#endif /* BOARD_TEXT_PANE_H */
