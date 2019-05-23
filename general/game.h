#ifndef GAME_H
#define GAME_H
#include "AiPlayer.h"
#include "board.h"
#include "messages.h"
#include "movement.h"
#include <vector>

class Game {
 public:
  Game();
  virtual ~Game();
  void start();

 private:
  Board m_board;
  Messages m_messages;
  IDisplay* p_message_display = &m_messages;
  Player* p_player1 = nullptr, *p_player2 = nullptr;

  int get_option(int from, int to);
  void print_message(Msg);
  void set_players(Playertype p1, Playertype p2);
  void play();
};

#endif /* GAME_H */
