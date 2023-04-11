#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include <cstddef>
#include <array>
#include "utils/defs.h"
#include "utils/utilities.h"

class PlayerPosition {
public:
  PlayerPosition() {}
  virtual ~PlayerPosition() {}

  void update_last_position(Color c) { 
    last_position[c] = next_last_position; 
  }

  void update_next_last_position(const SquareIndices &pos) { 
    next_last_position = pos; 
  }

  const SquareIndices &get_next_last_position() const {  
    return next_last_position; 
  }

  const SquareIndices &get_last_position(Color c) const { 
    return last_position[c];
  }

private:
  std::array<SquareIndices, Color::SIZE> last_position {D3, E6};
  SquareIndices next_last_position{last_position[Color::WHITE]};
};

#endif /* PLAYER_POSITION_H */
