#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "input.h"

class ConsoleInput : public Input {
 public:
  ConsoleInput();

  void get_player_string_move() override;
  void notify_input_event() override;
  void update_listener(InputObserver *observer) override;
  void select_menu_option() override;

 private:
  void has_player_quit(const string &s);

  int get_integer_input();
  string get_string_input();

  static const string input_space;
  InputEvent m_event;
};


#endif /* CONSOLE_INPUT_H */
