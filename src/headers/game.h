#ifndef GAME_H
#define GAME_H

#include <unistd.h>
#include <vector>
#include <string>
#include <utility>
#include "../board/headers/info.h"
#include "../graphics//headers/messages.h"
#include "../search/headers/uci.h"
#include "../ipc/headers/ipc_pipe.h"
#include "../board/headers/board_with_info.h"
#include "../graphics/headers/gui_controller.h"
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
    int get_start_or_quit_selection();
    void play();
    void print_message(MessageState* message);
    void set_players_on_board(const std::pair<Player::Type, Player::Type>&);
    void print_pane();
    void change_turn();
    void notify() override;
    int get_selected_option(vector<int> possible_options);
    pair<Player::Type, Player::Type> get_players_selection();
    bool has_player_quit(const string& str);
    bool check_valid_option(int i, const vector<int>& opts);
    std::unique_ptr<Player>create_new_player(Player::Type, Color color);

    GuiController m_main_gui;
    GuiController m_messages_gui;
    IpcPipe m_ipc_search;
    BoardWithInfo m_board_with_info;
    Messages m_messages;

    Move player_move;
    std::shared_ptr<Player> player_1, player_2, current_player;
    string initial_side = "";
    GameTurn::players m_turn = GameTurn::player_1;
    PlayersSelections m_players_selections;
};

#endif /* GAME_H */
