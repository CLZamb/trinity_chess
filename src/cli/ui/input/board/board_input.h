#ifndef BOARD_INPUT_H
#define BOARD_INPUT_H

#include <string>
#include "ui/graphics/board/board_view.h"

class BoardInput {
 public:
  virtual std::string get_next_string_move(BoardView& bv) = 0;
};

#endif /* BOARD_INPUT_H */
