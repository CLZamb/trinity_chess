#include "game.h"
Game::Game() {}
Game::~Game() { delete pPlayer2; }

void Game::start() {
  printMessage("welcome");
  std::cin.get();
  printMessage("start");

  switch (getOption()) {
    // Player vs Player
  case 1:
    // create squares and set the pieces on those squares
    pPlayer2 = new Player("black");
    play();
    break;
    // Player vs CPU
  case 2:
    std::cout << "not implemented yet!" << std::endl;
    printMessage("gameOver");
    // pPlayer2 = new AiPlayer("black");
    // play();
    break;
  case 3:
    printMessage("gameOver");
    break;
  case 4:
    std::cout << "Credits" << std::endl;
    break;
  default:
    std::cout << "Invalid Input:" << std::endl;
    break;
  }
}

void Game::play() {
  m_board.initialize(&player1, pPlayer2);
  pPlayer2->setOpponent(&player1);
  player1.setOpponent(pPlayer2);

  bool isCheckMate = false;
  Position from, to;
  Input *playerInput = nullptr;

  // clear input buffer
  std::cin.clear();
  std::cin.ignore();

  while (!isCheckMate) {
    pBoardDisplay->print();
    playerInput = playerTurn->getPlayerNextMove();

    if (!playerInput->isValidInput())
      continue;

    if (playerInput->toString() == "quit" ||
        playerInput->toString() == "close" ||
        playerInput->toString() == "exit") {
      break;
    }

    from = playerInput->getPosFrom();
    to = playerInput->getPosTo();

    if (movementController.isValidMove(from, to)) {
      movementController.movePiece(from, to);
      isCheckMate = movementController.getCheckmate();
      changeTurn();
    } else {
      std::cout << "invalid move, try again\n";
    }
  }
  if (isCheckMate)
    std::cout << "checkmate\n";
}

int Game::getOption() {
  std::cout << "\t\tchoose one of the options (1-4): ";
  int input;
  std::cin >> input;
  return input;
}

void Game::printMessage(string message) {
  system(CLEAR);
  Messages::m_nextMessage = message;
  pMessagesDisplay->print();
}

void Game::changeTurn() {
  if (playerTurn == &player1)
    playerTurn = pPlayer2;
  else if (playerTurn == pPlayer2)
    playerTurn = &player1;
}
