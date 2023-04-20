#ifndef COMMAND_EVENT_H
#define COMMAND_EVENT_H

#include <string>
#include "key_code.h"

struct CommandEvent {
  std::string get_string() const {
    return m_command_string;
  }

  KeyCode::Key get_key_code() const { 
    return m_keycode; 
  }

  int get_int() { return m_command_int; }

 protected:
  std::string m_command_string{""};
  int m_command_int{0};
  KeyCode::Key m_keycode{KeyCode::NONE};
};

#endif /* COMMAND_EVENT_H */
