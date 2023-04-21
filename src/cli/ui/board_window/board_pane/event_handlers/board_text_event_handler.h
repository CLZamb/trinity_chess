#ifndef BOARD_TEXT_PANE_H
#define BOARD_TEXT_PANE_H

#include "IBoard_input_event_handler.h"
#include "ui/board_window/board_pane/board_pane.h"
#include "ui/input/text/text_input.h"

class BoardTextEventHandler : public IBoardInputEventHandler {
public:
  BoardTextEventHandler(std::shared_ptr<BoardPane> b, shared_ptr<InputEvent> p);
  virtual ~BoardTextEventHandler() = default;

  bool is_string_move_ready() override;
  string get_string_move() override;
  void handle_string_input(CommandEventText &e);

private:
  shared_ptr<BoardPane> p_board_pane;
  string call_back{""};
};

#endif /* BOARD_TEXT_PANE_H */
