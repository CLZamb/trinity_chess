#include "game.h"
Game::Game() {}
Game::~Game() { delete pPlayer2; }

void Game::start() {
  printMessage("welcome");
  std::cin.get();
  printMessage("start");
  int option = getOption();
  switch (option) {
  case 1:
  case 2:
    // create squares and set the pieces on those squares
    if (option == 1) {
      // Player vs Player
      pPlayer2 = new Player("black");
    } else if (option == 2) {
      // Player vs CPU
      Movement::MoveGenerator aiMoveGenerator(&movementController);
      pPlayer2 = new AiPlayer("black", &aiMoveGenerator);
    }
    m_board.initialize(&player1, pPlayer2);
    pPlayer2->setOpponent(&player1);
    player1.setOpponent(pPlayer2);
    play();
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

int Game::getOption() {
  std::cout << "\t\tchoose one of the options (1-4): ";
  int input;
  std::cin >> input;
  return input;
}

void Game::play() {
  bool isCheckMate = false;
  Move playerMove;
  // clear input buffer
  std::cin.clear();
  std::cin.ignore();

  int counter = 0;
  while (!isCheckMate) {
    pBoardDisplay->print();
    playerMove = playerTurn->getPlayerNextMove();

    if (playerMove.m_input == "quit" || playerMove.m_input == "close" ||
        playerMove.m_input == "exit")
      break;

    if (playerMove.m_input == "undo") {
      movementController.undoLastMove();
      continue;
    }

    if (movementController.isValidMove(playerMove)) {
      movementController.movePiece(playerMove);
      isCheckMate = movementController.getCheckmate();
      counter = 0;
    } else {
      if (counter == 4) break;
      std::cout << playerMove.getFrom()
        << " " << playerMove.getTo() << std::endl;
      std::cout << "invalid move, try again\n";
      counter++;
    }
  }
  if (isCheckMate) {
    std::cout << "checkmate\n";
    std::cout << "Player " << playerTurn->getOpponent()->getColorPieces()
              << " won ";
  }
}

void Game::printMessage(string message) {
  system(CLEAR);
  Messages::m_nextMessage = message;
  pMessagesDisplay->print();
}

void Game::changeTurn() { playerTurn = playerTurn->getOpponent(); }
