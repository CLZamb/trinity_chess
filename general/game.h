#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "input.h"
#include "messages.h"
#include <vector>

class Game {
private:
  Display *pBoardDisplay;
  Display *pMessagesDisplay;
  // Display *pScoreDisplay;
  Player *playerTurn;
  Player player1{"white"}, player2{"black"};

  Board m_board;
  Messages m_messages;
  std::vector<Piece *> allPieces;
  bool isCheckMate = false;
  std::string input;
  Input playerInput;
  Position from, to;
  int getOption();
  bool isValidMove(Position, Position);

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
