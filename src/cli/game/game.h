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
  void set_new_configuration(IConfiguration &);
  void start_game_loop();
  void attach_observers_to_game_turn();
  void make_move(const Move &m);
  void update_board_view(const Move &);
  bool is_valid_string_move(const string &str_move);
  bool is_valid_move(const string &str_move, Move &mv);

  Configuration m_config;
 // Players m_players;
  // IpcPipe m_ipc_search;
};

#endif /* GAME_H */
