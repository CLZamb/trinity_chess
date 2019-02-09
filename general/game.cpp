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
  std::string playerMove;
  // clear input buffer
  std::cin.clear();
  std::cin.ignore();

  while (!isCheckMate) {
    pBoardDisplay->print();
    playerMove = playerTurn->getPlayerNextMove();

    if (playerMove == "quit" || playerMove == "close" || playerMove == "exit")
      break;

    if (playerMove == "undo") {
      movementController.undoLastMove();
      continue;
    }

    if (movementController.isValidMove(playerMove)) {
      movementController.movePiece(playerMove);
      isCheckMate = movementController.getCheckmate();
    } else {
      std::cout << playerMove << std::endl;
      std::cout << "invalid move, try again\n";
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
