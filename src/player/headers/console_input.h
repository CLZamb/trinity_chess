#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "input.h"
#include "game/headers/game_turn_observer.h"

class ConsoleInput : public Input , public GameTurnObserver {
 public:
  ConsoleInput();
  virtual ~ConsoleInput();

  void update_turn(const PlayerInfo& i) override;
  const string& get_string_input() override;
  int get_integer_input() override;

 private:
  void has_player_quit(const string &s);
  void get_human_input();
  void get_cpu_input();
  PlayerInfo m_player_info;
};

#endif /* CONSOLE_INPUT_H */
