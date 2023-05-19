#ifndef IPANE_EVENT_HANDLER_H
#define IPANE_EVENT_HANDLER_H

#include <string>

#include "components/event_emitter.h"
#include "utils/move.hpp"

class IPaneEventHandler : public EventEmitter {
 public:
  virtual std::string get_move_as_string() = 0;
  virtual void change_side() = 0;
};

#endif /* IPANE_EVENT_HANDLER_H */
