#ifndef IBOARD_EVENT_HANDLER_H
#define IBOARD_EVENT_HANDLER_H

#include "game/players/player_info.hpp"
#include <string>

class IBoardEventHandler {
 public:
  virtual ~IBoardEventHandler () = default;
  virtual bool has_events() = 0;
  virtual std::string get_string() = 0;
};

#endif /* IBOARD_EVENT_HANDLER_H */
