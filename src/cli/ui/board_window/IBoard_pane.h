#ifndef IBOARD_PANE_H
#define IBOARD_PANE_H

#include "game/players/player_info.hpp"
#include "ui/components/pane.h"
#include "utils/move.hpp"

class IBoardPane : public Pane {
 public:
  IBoardPane() : Pane(Kboard_pane_size) {}
  virtual ~IBoardPane() {}
  virtual void make_move(const Move &mv) = 0;
  virtual void update() = 0;
 private:
  static const size_t Kboard_pane_size{44};
};

#endif /* UI_BOARD_H */
