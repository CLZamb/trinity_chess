#ifndef IBOARD_PANE_H
#define IBOARD_PANE_H

#include "ui/graphics/board/decorators/IUi_board.h"
#include "utils/move.hpp"

class IBoardPane {
 public:
  virtual ~IBoardPane() = default;
  virtual void make_move(const Move &mv) = 0;
};

#endif /* IBOARD_PANE_H */
