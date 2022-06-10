#ifndef INPUT_OBSERVER_H
#define INPUT_OBSERVER_H

#include "input/headers/input_event.h"

class InputObserver {
public:
  virtual ~InputObserver() {};
  virtual void handle_input_event(const InputEvent &) = 0;
};

#endif /* INPUT_OBSERVER_H */
