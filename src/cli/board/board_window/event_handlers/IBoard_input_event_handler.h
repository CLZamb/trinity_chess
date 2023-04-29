#ifndef IBOARD_EVENT_HANDLER_H
#define IBOARD_EVENT_HANDLER_H

#include <string>

class IBoardInputEventHandler {
 public:
  virtual ~IBoardInputEventHandler () = default;
  virtual bool is_player_string_move_ready() = 0;
  virtual std::string get_player_move_as_string() = 0;
};

#endif /* IBOARD_EVENT_HANDLER_H */
