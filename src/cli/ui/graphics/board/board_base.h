#ifndef BOARD_BASE_H
#define BOARD_BASE_H

#include "ui/graphics/board/board_view.h"

class BoardBase {
 public:
  BoardBase() = default;
  virtual ~BoardBase() = default;
 private:
  BoardView _board_view;
};

#endif /* board_Base*/
