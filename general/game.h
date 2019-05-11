#ifndef GAME_H
#define GAME_H
#include "AiPlayer.h"
#include "board.h"
#include "messages.h"
#include "movement.h"
#include <vector>

class Game {
private:
  Board m_board;
  Messages m_messages;
  IDisplay* p_board_display = &m_board;
  IDisplay* p_message_display = &m_messages;
  Player m_player1{WHITE};
  Player* p_player2 = nullptr, *p_player_turn = &m_player1;
  Movement movement_controller{&m_board, &p_player_turn};

  int get_option();
  void print_message(string);
  void change_turn();
  void set_players(bool is_cpu = false);
  void play();

public:
  Game();
  virtual ~Game();

  void start();
};

#endif /* GAME_H */
