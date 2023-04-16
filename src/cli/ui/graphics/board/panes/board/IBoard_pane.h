#ifndef IBOARD_PANE_H
#define IBOARD_PANE_H

#include "game/players/player_info.hpp"
#include "utils/move.hpp"

class IBoardPane {
 public:
  virtual ~IBoardPane() = default;
  virtual void make_move(const Move &mv) = 0;
  virtual void update_turn(const PlayerInfo &) = 0;
  virtual bool has_events() = 0;
  virtual std::string get_string() = 0;
};

#endif /* IBOARD_PANE_H */
