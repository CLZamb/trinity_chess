#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include "components/event_emitter.h"

class InputComponent : public EventEmitter {
 public:
  virtual void send_event_input_to_listeners() = 0;
};

#endif /* INPUT_COMPONENT_H */
