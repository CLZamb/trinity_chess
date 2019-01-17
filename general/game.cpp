#include "game.h"
Game::Game() { initializeMembers(); }
Game::~Game() {}

void Game::initializeMembers() {
  this->pMessagesDisplay = &this->m_messages;
  this->pBoardDisplay = &this->m_board;
  player1.setOpponent(&player2);
  player2.setOpponent(&player1);
}

void Game::start() {
  printMessage("welcome");
  std::cin.get();
  printMessage("start");

  switch (getOption()) {
  case 1:
    //  create boxes and set the pieces on those boxes
    m_board.initialize(&player1, &player2);
    pBoardDisplay->print();
    play();
    break;
  case 2:
    printMessage("gameOver");
    break;
  case 3:
    std::cout << "Credits" << std::endl;
    break;
  default:
    std::cout << "Wrong Input try again" << std::endl;
    break;
  }
}

void Game::play() {
  getline(cin, input);

  while (!isCheckMate) {
    std::cout << "move piece ie: (a7 a6), to end the game type "
                 "\"close, quite or exit\""
              << "\nis player " << playerTurn->getColor() << " turn"
              << "\n>> ";

    std::getline(std::cin, input);
    playerInput.getPlayerNextMove(input);
    if (!playerInput.isValidInput())
      continue;

    if (input == "quit" || input == "close" || input == "exit") {
      break;
    }

    from = playerInput.getPosFrom();
    to = playerInput.getPosTo();

    if (movementController.isValidMove(from, to)) {
      movementController.movePiece(from, to);
      isCheckMate = movementController.getCheckmate();
      pBoardDisplay->print();
      changeTurn();
    } else {
      std::cout << "invalid move, try again\n";
    }
  }
  if (isCheckMate)
    std::cout << "checkmate\n";
}

int Game::getOption() {
  std::cout << "choose one of the options (1,2 or 3)" << std::endl;
  int input;
  std::cin >> input;
  return input;
}

void Game::printMessage(string message) {
  Messages::m_nextMessage = message;
  this->pMessagesDisplay->print();
}

void Game::changeTurn() {
  if (playerTurn == &player1)
    playerTurn = &player2;
  else if (playerTurn == &player2)
    playerTurn = &player1;
}
