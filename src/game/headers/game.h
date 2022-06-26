#ifndef GAME_H
#define GAME_H

#include "board/headers/board.h"
#include "configuration/headers/configuration.h"
#include "controller/headers/uicontroller.h"
#include "input/headers/text_input.h"
#include "player/headers/players_turn_controller.h"
#include "view/headers/info_pane.h"
#include "player/headers/players.h"

class Game {
 public:
  Game(Configuration, PlayerInput &);
  virtual ~Game();
  void play();

 private:
  void print_view();
  void attach_observers_to_players_turn();
  void setup_board();
  void update_board_info_view();
  void update_move_info_view();
  void setup_players_turn();

  PlayersTurnController m_players_turn;
  Board m_board;

  BoardInfo &m_board_info;
  BoardView &m_board_view;
  InfoPane m_info_pane;
  PlayerInput &m_player_input;
  Players m_players;
};

#endif /* GAME_H */
