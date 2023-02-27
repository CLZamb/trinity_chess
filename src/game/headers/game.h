#ifndef GAME_H
#define GAME_H

// #include "../search/headers/uci.h"
// #include "../ipc/headers/ipc_pipe.h"
#include "player/headers/player.h"
#include "player/headers/players.h"
#include "move_utils.h"
#include "view/headers/info_view.h"
#include "configuration/headers/configuration.h"
#include "game_turn_observable.h"
#include "options.h"
#include "board/headers/board.h"
#include "model/headers/game_info.h"

class Game {
  public:
    Game(Configuration);
    virtual ~Game();
    void start();

  private:
    void attach_observers_to_players();
    bool is_valid_str_move_format(const string& move);
    bool is_legal_move(const string& move);
    void make_move(const string& move);
    void setup_players(PlayersConfig pc);
    void setup_board();
    void play();
    void change_turn();
    void update_info_view();
    bool game_players_exists();
    bool has_player_quit(const string& str);
    string select_option(const string& play, const string& quit);
    string get_play_or_quit_selection();
    string get_current_player_input();
    Players m_players;
    Board m_board;

    BoardView& m_board_view;
    BoardInfo& m_board_info;
    GameInfo m_game_info;
    InfoView m_info_view;
};


#endif /* GAME_H */
