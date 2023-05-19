#ifndef IBOARD_PANE_COMPONENT_H
#define IBOARD_PANE_COMPONENT_H

#include "components/IPane.h"
#include "utils/move.hpp"

class IBoardPaneComponent {
 public:
  virtual void make_move(const Move &mv) = 0;
  virtual void update() = 0;
  virtual IPane* get_view() = 0;
};

#endif /* IBOARD_PANE_COMPONENT_H */
