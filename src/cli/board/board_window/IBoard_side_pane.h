#ifndef IBOARD_SIDE_PANE_H
#define IBOARD_SIDE_PANE_H

#include "ui_components/IPane.h"
#include "utils/move.hpp"

class IBoardSidePane {
 public:
  virtual void make_move(const Move &mv) = 0;
  virtual void update() = 0;
  virtual IPane* get_pane() = 0;
};

#endif /* IBOARD_SIDE_PANE_H */
