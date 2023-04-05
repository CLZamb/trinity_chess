#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include <cstddef>
#include <array>
#include "utils/defs.h"

class PlayerPosition {
public:
  PlayerPosition() {}
  virtual ~PlayerPosition() {}
  void set_from_position(const size_t &pos) { from_pos = pos; }
  void set_to_position(const size_t &pos) { to_pos = pos; }
  void update_last_position(const size_t &pos) { 
    last_position[next_last_position] = pos; 
    next_last_position++;
    next_last_position = next_last_position % 2;
  }

  const size_t &get_from_position() const {  return from_pos; }
  const size_t &get_to_position() const { return to_pos; }
  const size_t &get_last_position() const { 
    return last_position[next_last_position];
  }

private:
  size_t from_pos{E4};
  size_t to_pos{E4};
  std::array<size_t, 2> last_position {D3, E6};
  size_t next_last_position{0};
};

#endif /* PLAYER_POSITION_H */
