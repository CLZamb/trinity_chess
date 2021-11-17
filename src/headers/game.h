#ifndef GAME_H
#define GAME_H

#include <unistd.h>
#include <vector>
#include <string>
#include <utility>
#include "../board/headers/info.h"
#include "../graphics//headers/messages.h"
#include "../graphics/headers/window.h"
#include "../search/headers/uci.h"
#include "../ipc/headers/ipc_pipe.h"
#include "../board/headers/board_with_info.h"
#include "../headers/player.h"
#include "../headers/move_utils.h"
#include "game_turn_observable.h"
#include "../headers/players_selections.h"


class Game : public GameTurnObservable {
 public:
   enum Start_or_quit {
     Start = 1,
     Quit = 2,
   };

    Game();
    virtual ~Game();
    void start();

 private:
    void _init();
    void setup_players();
    bool game_turn_exists();
    int get_start_or_quit_selection();
    void play();
    void print_message(MessageState* message);
    void create_players(const std::pair<Player::Type, Player::Type>&);
    void setup_player();
    void change_turn();
    void notify() override;
    string get_current_player_input();
    int get_selected_option(vector<int> possible_options);
    pair<Player::Type, Player::Type> get_players_selection();
    bool has_player_quit(const string& str);
    bool check_valid_option(int i, const vector<int>& opts);
    std::unique_ptr<Player>create_new_player(Player::Type, Color color);

    Window m_game_window;
    Window m_messages_window;
    IpcPipe m_ipc_search;
    BoardWithInfo m_board;
    Messages m_messages;

    std::shared_ptr<Player> player_1, player_2, game_turn;
    GameTurn::players m_turn = GameTurn::player_1;
    string initial_side = "";
    PlayersSelections m_players_selections;
};

#endif /* GAME_H */
