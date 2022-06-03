#ifndef GAME_H
#define GAME_H

#include "board/headers/board.h"
#include "configuration/headers/configuration.h"
#include "model/headers/game_info.h"
#include "move_utils.h"
#include "player/headers/console_input.h"
#include "player/headers/players.h"
#include "view/headers/info_view.h"

class Game {
  public:
    Game(Configuration);
    virtual ~Game();
    void start();

  private:
    void print_view();
    void attach_observers_to_players();
    bool is_valid_str_move_format(const string& move);
    bool is_legal_move(const string& move);
    void make_move(const string& move);
    void setup_players();
    void setup_board();
    void play();
    void change_turn();
    void update_info_view();
    bool game_players_exists();
    bool has_player_quit(const string& str);
    string select_option(const string& play, const string& quit);
    string get_play_or_quit_selection();

    Players m_players;
    Board m_board;

    BoardView& m_board_view;
    BoardInfo& m_board_info;
    GameInfo m_game_info;
    InfoView m_info_view;
    Input& m_input;
};


#endif /* GAME_H */
