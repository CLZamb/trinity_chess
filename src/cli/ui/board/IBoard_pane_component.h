#ifndef UI_BOARD_H
#define UI_BOARD_H

#include "game/players/player_info.hpp"
#include "ui/components/pane.h"
#include "utils/move.hpp"

class IBoardPaneComponent : public Pane {
 public:
  virtual ~IBoardPaneComponent() {}
  virtual void make_move(const Move &mv) = 0;
  virtual void update() = 0;
};

#endif /* UI_BOARD_H */
