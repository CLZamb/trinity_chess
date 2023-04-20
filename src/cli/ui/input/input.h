#ifndef INPUT_H
#define INPUT_H

#include "command_event.h"
#include <functional>
#include <unordered_map>
#include <string>

class Input {
 public:
  virtual ~Input() {}
  virtual void get_input_event() = 0;

  using method = std::function<void(CommandEvent&)>;

  template <typename EventID, typename Class>
  void bind(EventID key, void (Class::*m)(CommandEvent&), Class *c) {
    _events[key].push_back(std::bind(m, c, std::placeholders::_1));
  }

protected:
  std::unordered_map<int, std::vector<method>> _events;
};

#endif /* INPUT_H */

