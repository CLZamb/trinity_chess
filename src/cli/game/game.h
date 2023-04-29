#ifndef GAME_H
#define GAME_H

#include "board/board.h"
#include "configuration/configuration.h"
#include "game/turn/side_to_move.h"

class Game {
 public:
  Game();
  virtual ~Game() = default;
  void start();

 private:
  string get_start_menu_option_as_string();
  void start_game_loop();
  void create_new_input(InputType type);
  Configuration m_config;
  // Players m_players;
  // IpcPipe m_ipc_search;
};

#endif /* GAME_H */
