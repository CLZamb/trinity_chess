#ifndef IBOARD_EVENT_HANDLER_H
#define IBOARD_EVENT_HANDLER_H

#include "game/players/player_info.hpp"
#include <string>

class IBoardInputEventHandler {
 public:
  virtual ~IBoardInputEventHandler () = default;
  virtual bool is_string_move_ready() = 0;
  virtual std::string get_string_move() = 0;
};

#endif /* IBOARD_EVENT_HANDLER_H */
