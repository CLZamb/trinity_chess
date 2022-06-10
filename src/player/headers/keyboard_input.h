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
  int select_menu_option(const vector<int> &opts) override;
  void notify_input_event() override;
  void update_listener(InputObserver *observer) override;

private:
  void update_current_selection(const InputKeys::Key &key_pressed, const vector<int> &opts,
                                vector<int>::const_iterator &selected_option);
  int select_next_position();
  int get_key_pressed();
  int get_arrow_key_pressed();

  array<int, GameTurn::kSize> pos;

  const string m_quit_str = "quit";
  static struct termios old, current;
  PlayerInfo m_player_info;
  InputEvent m_event;
};

#endif /* KEBOARD_INPUT_H */
