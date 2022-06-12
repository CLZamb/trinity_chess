#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include "input/headers/input_event.h"
#include "player/headers/input.h"
#include <termios.h>
#include <iostream>

class KeyboardInput : public Input {
public:
  KeyboardInput();
  virtual ~KeyboardInput();

  void get_player_string_move() override;
  void select_menu_option() override;
  void update_listener(InputObserver *observer) override;
  void notify_input_event() override;

private:
  void notify_key_pressed(const InputKeys::Key &key);
  InputKeys::Key get_arrow_key_pressed();

  static struct termios old, current;
  const string m_quit_str = "quit";
  InputEvent m_event;
};

#endif /* KEBOARD_INPUT_H */
