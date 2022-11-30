#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include "board/headers/defs.h"
#include "game/headers/string_utils.h"

class PlayerPosition {
public:
  PlayerPosition() {}
  virtual ~PlayerPosition() {}
  void set_from_position(const size_t &pos) { from_pos = pos; }
  void set_to_position(const size_t &pos) { to_pos = pos; }
  const size_t &get_from_position() const { return from_pos; }
  const size_t &get_to_position() const { return to_pos; }

private:
  size_t from_pos{E4};
  size_t to_pos{E4};
};

#endif /* PLAYER_POSITION_H */
