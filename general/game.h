#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "input.h"
#include "messages.h"
#include "movement.h"
#include <vector>

class Game {
private:
  Board m_board;
  Messages m_messages;
  Display *pBoardDisplay;
  Display *pMessagesDisplay;
  // Display *pScoreDisplay;
  Player player1{"white"}, player2{"black"};
  Player *playerTurn = &player1;

  Movement movementController{&m_board, &playerTurn};
  std::vector<Piece *> allPieces;
  std::string input;
  bool isCheckMate = false;
  Input playerInput;
  Position from, to;
  int getOption();

public:
  Game();
  virtual ~Game();

  void initializeMembers();
  void start();
  void play();
  void printMessage(string);
  void changeTurn();
};

#endif /* GAME_H */
