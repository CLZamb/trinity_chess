#ifndef BOARD_TEXT_PANE_H
#define BOARD_TEXT_PANE_H

#include "IBoard_input_event_handler.h"
#include "board/board_window/board_pane/board_pane.h"
#include "ui/input/text/text_input.h"

class BoardTextEventHandler : public IBoardInputEventHandler {
public:
  BoardTextEventHandler(BoardPane &b, const std::unique_ptr<Input>& p);
  virtual ~BoardTextEventHandler() = default;

  bool is_player_string_move_ready() override;
  string get_player_move_as_string() override;
  void handle_string_input(CommandEventText &e);

private:
  BoardPane& m_board_pane;
  string m_string_move{""};
};

#endif /* BOARD_TEXT_PANE_H */
