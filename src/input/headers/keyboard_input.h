#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include "input/headers/input_event.h"
#include "input/headers/input.h"
#include <termios.h>
#include <iostream>

class KeyboardInput : public Input {
public:
  KeyboardInput();
  virtual ~KeyboardInput();

  void get_player_string_move() override;
  void select_menu_option() override;
  void update_input_event_listener(InputObserver *observer) override;
  void notify_input_event() override;
  void dispatch_event(const InputEvent& event) override;
  void set_terminal_new_attributes();

private:
  void notify_key_pressed(const InputKeys::Key &key);
  void reset_terminal_configuration();

  InputKeys::Key get_arrow_key_pressed();

  static struct termios old, current;
  InputEvent m_event;
  static string hide_cursor;
  static string show_cursor;
};

#endif /* KEBOARD_INPUT_H */
