#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "ui/input/board/keyboard/key_code.h"
#include <string>

class InputHandler {
 public:
  virtual ~InputHandler() = default;
  virtual bool handle_event(KeyCode::Key, std::string& callback)= 0;
};

#endif /* INPUT_HANDLER_H */
