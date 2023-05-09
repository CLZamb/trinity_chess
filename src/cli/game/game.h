#ifndef GAME_H
#define GAME_H

#include "board/board.h"
#include "configuration/configuration.h"
#include "game/turn/side_to_move.h"

class Game {
 public:
  Game();
  void start();

 private:
  void get_config_from_file(Configuration& config);
  std::string get_menu_option_as_string(InputType input_type);
  void start_game_loop(BoardConfigInfo &board_config);
  // Players m_players;
  // IpcPipe m_ipc_search;
};

#endif /* GAME_H */
