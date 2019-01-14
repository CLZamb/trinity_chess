#include "game.h"
Game::Game() { initializeMembers(); }
Game::~Game() {}

void Game::initializeMembers() {
  this->pMessagesDisplay = &this->m_messages;
  this->pBoardDisplay = &this->m_board;
}

void Game::start() {
  printMessage("welcome");
  std::cin.get();
  printMessage("start");
  switch (getOption()) {
  case 1:
    playerTurn = &player1;
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
      printMessage("gameOver");
      break;
    }

    from = playerInput.getPosFrom();
    to = playerInput.getPosTo();

    if (isValidMove(from, to)) {
      m_board.movePiece(from, to);
      pBoardDisplay->print();
      changeTurn();
    } else {
      std::cout << "invalid move, try again\n";
    }
  }
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

bool Game::isValidMove(Position from, Position to) {
  return m_board.isValidMove(playerTurn, from, to);
}
