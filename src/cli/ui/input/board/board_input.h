#ifndef BOARD_INPUT_H
#define BOARD_INPUT_H

#include "ui/input/board/keyboard/key_code.h"
#include "ui/input/input_types/keyboard/keyboard_key.h"
#include <functional>
#include "function.hpp"
#include <unordered_map>

using std::unordered_map;


class BoardInput {
public:
  virtual ~BoardInput() {}
  virtual void get_input_event() = 0;

  template <typename Class>
  void bind(Keyboard::Key c, void (Class::*method)(KeyCode::Key), Class *e) {
    m_events.emplace(c, std::bind(method, e, std::placeholders::_1));
  }

protected:
  unordered_map<Keyboard::Key, function<void(KeyCode::Key)>> m_events;
};

#endif /* BOARD_INPUT_H */
