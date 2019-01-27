#include "AiPlayer.h"

AiPlayer::AiPlayer(std::string s) : Player(s) {
  std::cout << "created a AiPlayer" << std::endl;
}
AiPlayer::~AiPlayer() {}

Input *AiPlayer::getPlayerNextMove() {
  std::string input = "a7 a6";
  std::cout << "Thinking...\n";
  playerInput.getNextMove(input);
  return &playerInput;
}
