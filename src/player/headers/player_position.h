#ifndef PLAYER_POSITION_H
#define PLAYER_POSITION_H

#include "board/headers/defs.h"

class PlayerPosition {
public:
  PlayerPosition() {}
  virtual ~PlayerPosition() {}
  void set_from_poistion(const int &pos) { from_pos = pos; }
  void set_to_position(const int &pos) { to_pos = pos; }
  const int &get_from_position() const { return from_pos; }
  const int &get_to_position() const { return to_pos; }

private:
  int from_pos{E4};
  int to_pos{E4};
};

#endif /* PLAYER_POSITION_H */
