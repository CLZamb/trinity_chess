#ifndef IBOARD_INFO_GETTER_H
#define IBOARD_INFO_GETTER_H

#include <string>

#include "game/game_typedefs.h"

class IBoardInfoGetter {
 public:
  virtual std::string get_moves(Color c) = 0;
  virtual std::string get_captures(Color c) = 0;
  virtual std::string get_info() = 0;
  virtual Color get_side_to_move_color() = 0;
};

#endif /* IBOARD_INFO_GETTER_H */
