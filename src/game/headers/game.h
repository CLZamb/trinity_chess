#ifndef GAME_H
#define GAME_H

#include "../../graphics/headers/uicontroller.h"
// #include "../search/headers/uci.h"
// #include "../ipc/headers/ipc_pipe.h"
#include "../../player/headers/player.h"
#include "../../player/headers/players.h"
#include "../headers/move_utils.h"
#include "game_turn_observable.h"
#include "options.h"

class Game: public GameTurnObservable {
  public:
    Game();
    virtual ~Game();
    void start();

  private:
    bool is_valid_str_move_format(const string& move);
    bool is_legal_move(const string& move);
    void make_move(const string& move);
    void setup_players();
    void setup_board();
    void play();
    void print_message(MessageState* message);
    void change_turn();
    void notify() override;
    bool game_players_exists();
    bool has_player_quit(const string& str);
    string select_option(const string& play, const string& quit);
    string get_play_or_quit_selection();
    string get_current_player_input();
    Players players;
    Messages m_messages;
    BoardWithInfo m_board;
    Options<string> start_quit;

    UIController ui_controller;

    GameTurn::players m_turn = GameTurn::player_1;
    std::shared_ptr<Player> game_turn;
    string initial_side = "";
};


#endif /* GAME_H */
