#ifndef IBOARD_INPUT_BUILDER_H
#define IBOARD_INPUT_BUILDER_H

#include <memory>
#include "board_input.h"

using std::shared_ptr;

class IBoardInputBuilder {
 public:
  virtual std::shared_ptr<BoardInput> get_new_board_input() = 0;
};

#endif /* BOARD_INPUT_H */
