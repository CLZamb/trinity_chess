#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include "player/headers/input.h"
#include "view/headers/board_view.h"
#include <array>
#include <termios.h>

using std::array;
class KeyboardInput : public Input {
public:
  KeyboardInput();
  virtual ~KeyboardInput();

  void update_turn(const PlayerInfo &i) override;
  const string &get_player_string_move() override;
  void select_menu_option() override;
  void update_listener(InputObserver *observer) override;
  void notify_input_event() override;

private:
  void notify_key_pressed(const InputKeys::Key &key);
  void next_position();
  int select_next_position();
  InputKeys::Key get_arrow_key_pressed();
  string get_input();

  static struct termios old, current;
  const string m_quit_str = "quit";
  array<int, GameTurn::kSize> pos;

  PlayerInfo m_player_info;
  InputEvent m_event;
};

#endif /* KEBOARD_INPUT_H */
