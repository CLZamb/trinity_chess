#ifndef GAME_H
#define GAME_H

#include "board/headers/board.h"
#include "configuration/headers/configuration.h"
// #include "move_utils.h"
#include "controller/headers/uicontroller.h"
#include "game/headers/board_input_hanlder.h"
#include "player/headers/console_input.h"
#include "player/headers/players.h"
#include "view/headers/info_pane.h"

class Game {
 public:
  Game(Configuration, Input &);
  virtual ~Game();
  void play();

 private:
  void print_view();
  void attach_observers_to_players();
  void setup_players();
  void setup_board();
  void update_board_info_view();
  void update_move_info_view();

  Players m_players;
  Board m_board;

  BoardInfo &m_board_info;
  BoardView &m_board_view;
  InfoPane m_info_pane;

  BoardInputHanlder m_board_input_handler;
};

#endif /* GAME_H */
