#ifndef GAME_H
#define GAME_H

#include "board/headers/board.h"
#include "configuration/headers/configuration.h"
#include "controller/headers/uicontroller.h"
#include "../../controller/headers/ui_board_info_controller.h"
#include "controller/headers/ui_board_controller.h"
#include "input/headers/text_input.h"
#include "player/headers/players_turn_controller.h"
#include "view/headers/info_pane.h"
#include "player/headers/players.h"
#include <memory>

using std::shared_ptr;

class Game {
 public:
  Game(Configuration, PlayerInput &);
  void play();

 private:
  void attach_observers_to_players_turn();
  void setup_players_turn();
  void add_info_to_board();
  void make_move(const Move& m);
  bool is_valid_move(const string& str_move, Move& mv);

  PlayersTurnController m_players_turn;
// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
  Board m_board{"r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1"};
  BoardView m_board_view;
  InfoPane m_info_pane;
  Players m_players;
  BoardInfo m_board_info;

  PlayerInput &m_player_input;
  shared_ptr<UIBoard> p_boardview_controller;
};

#endif /* GAME_H */
