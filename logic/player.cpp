#include "player.h"

Player::Player(std::string c) : colorPieces(c) {}
Player::~Player() {}

void Player::remainingPieces() {}

Input *Player::getPlayerNextMove() {
  std::string input;
  std::cout << "move piece ie: (a7 a6), to end the game type "
               "\"close, quite or exit\""
            << "\nis player " << this->colorPieces << " turn"
            << "\n>> ";
  std::getline(std::cin, input);
  playerInput.getNextMove(input);
  return &playerInput;
}
