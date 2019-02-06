#include "AiPlayer.h"

AiPlayer::AiPlayer(std::string side, Movement::MoveGenerator *generator)
    : Player(side), moveGenerator(generator) {
  std::cout << "created a AiPlayer" << std::endl;
}
AiPlayer::~AiPlayer() {}

std::string AiPlayer::getPlayerNextMove() {
  std::string input = "quit";
  std::cout << "Thinking...\n";
  input = moveGenerator->getBestMove();
  return input;
}
