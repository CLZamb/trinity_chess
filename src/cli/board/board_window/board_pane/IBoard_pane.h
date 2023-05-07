#ifndef IBOARD_PANE_H
#define IBOARD_PANE_H

#include "board/board_window/board_pane/board_pane.h"

class IBoardPane : public BoardPane {
 public:
  virtual bool is_player_string_move_ready() = 0;
  virtual std::string get_player_move_as_string() = 0;
};

#endif /* IBOARD_PANE_H */
