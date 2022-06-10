#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "input.h"

class ConsoleInput : public Input {
 public:
  ConsoleInput();

  void update_turn(const PlayerInfo &i) override;
  const string &get_player_string_move() override;
  void notify_input_event() override;
  void update_listener(InputObserver *observer) override;
  int select_menu_option(const vector<int> &opts) override;

 private:
  int get_integer_input();
  bool is_valid_option(const vector<int> options, const int &option);
  void has_player_quit(const string &s);

  void get_human_input(string &input);
  void get_cpu_input(string &input);
  PlayerInfo m_player_info;
  string input_space = "\t\t\t\t";
  string invalid_option_msg = input_space + "invalid option try again!\n";
  InputEvent m_event;
};

#endif /* CONSOLE_INPUT_H */
