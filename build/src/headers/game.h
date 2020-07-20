#ifndef GAME_H
#define GAME_H

#include <unistd.h>
#include <vector>
#include <string>
#include <utility>
#include "../board/headers/info.h"
#include "../display/headers/messages.h"
#include "../search/headers/uci.h"
#include "../ipc/headers/ipc_pipe.h"
#include "../board/headers/board_with_info.h"
#include "../display/headers/gui_controller.h"
#include "../headers/player.h"
#include "../headers/move_utils.h"
#include "game_turn_observable.h"

class Game : public GameTurnObservable {
 public:
   enum Start_or_quit {
     Start = 1,
     Quit = 2,
   };

   enum Players_Selection {
     Players_selections_begin = 0,
     Human_vs_Human,
     Human_vs_Cpu,
     Cpu_vs_Cpu,
     Players_selections_end,
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
    int get_option(int from, int to);
    Players_Selection get_players_selection();
    bool has_player_quit(const string& str);
    std::unique_ptr<Player>create_new_player(Player::Type, Player::Color color);

    GuiController m_main_gui;
    GuiController m_messages_gui;
    IpcPipe m_ipc_search;
    Board m_board;
    Info m_info;
    BoardWithInfo m_board_with_info;
    Messages m_messages;

    Move player_move;
    std::shared_ptr<Player> player_1, player_2, current_player;
    GameTurn::players m_turn = GameTurn::player_1;

    unordered_map<
      Players_Selection, std::pair<Player::Type, Player::Type>
      >
      players_selections {
      {Human_vs_Human, {Player::Human, Player::Human}},
      {Human_vs_Cpu, {Player::Human, Player::Cpu}},
      {Cpu_vs_Cpu, {Player::Cpu, Player::Cpu}}};
};

#endif /* GAME_H */
