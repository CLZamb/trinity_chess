#ifndef GAME_H
#define GAME_H

#include "board/headers/board.h"
#include "board/headers/board_fen.h"
#include "configuration/headers/configuration.h"
#include "controller/headers/uicontroller.h"
#include "controller/headers/ui_board_info_controller.h"
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
  virtual ~Game();
  void play();

 private:
  void attach_observers_to_players_turn();
  void setup_players_turn();
  void add_info_pane_to_board();
  void make_move(const Move& m);
  bool is_valid_move(const string& str_move, Move& mv);
  string get_winner_drawing();

  const string start_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  // const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
  // const string start_fen = "4k3/8/8/4pP2/8/8/8/4K2R w - e6 0 1";
  // const string start_fen = "r3k3/ppp5/8/8/8/8/5PPP/4K2R w Kq - 0";
  // const string start_fen = "k1R5/8/2Q5/8/1q6/2r5/8/K7 b - - 0 1";
  // const string start_fen = "3kq2r/8/8/8/8/8/8/3K1Q2 w - - 0 1";
  // const string start_fen = "2Q5/k7/8/2R5/7r/7r/8/K7 b - - 0 1";

  PlayersTurnController m_players_turn;
  Board m_board;
  BoardFen m_board_fen;
  BoardView m_board_view;
  InfoPane m_info_pane;
  Players m_players;
  BoardInfo m_board_info;

  PlayerInput &m_player_input;
  shared_ptr<UIBoard> p_boardview_controller;
};

#endif /* GAME_H */
