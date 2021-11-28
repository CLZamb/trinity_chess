#ifndef GAME_H
#define GAME_H

#include <unistd.h>
#include <vector>
#include <string>
#include <utility>
// #include "../board/headers/info.h"
#include "../graphics/headers/uicontroller.h"
// #include "../graphics/headers/messages.h"
#include "../search/headers/uci.h"
#include "../ipc/headers/ipc_pipe.h"
// #include "../board/headers/board_with_info.h"
#include "../headers/player.h"
#include "../headers/move_utils.h"
#include "game_turn_observable.h"
#include "../headers/players_selections.h"
// #include "game_setup.h"
#include "options.h"
#include "players.h"

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
    void setup_player();
    void change_turn();
    void notify() override;
    bool game_turn_exists();
    bool has_player_quit(const string& str);
    int get_play_or_quit_selection();
    string get_current_player_input();
    Players players;

    Messages m_messages;
    BoardWithInfo m_board;

    Options options;

    pair<Player::Type, Player::Type> get_players_selection();

    UIController ui_controller;

    GameTurn::players m_turn = GameTurn::player_1;
    std::shared_ptr<Player> game_turn;
    string initial_side = "";
};


#endif /* GAME_H */
