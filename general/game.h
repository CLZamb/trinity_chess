#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "messages.h"
#include "movement.h"
#include <vector>

class Game {
private:
  Board m_board;
  Messages m_messages;
  IDisplay *pBoardDisplay = &m_board;
  IDisplay *pMessagesDisplay = &m_messages;
  // Display *pScoreDisplay;
  Player player1{"white"}, *pPlayer2 = nullptr;
  Player *playerTurn = &player1;
  Movement movementController{&m_board, &playerTurn};

  int getOption();
  void printMessage(string);
  void changeTurn();
  void play();

public:
  Game();
  virtual ~Game();

  void start();
};

#endif /* GAME_H */
