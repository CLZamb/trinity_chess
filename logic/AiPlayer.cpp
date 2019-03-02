#include "AiPlayer.h"

AiPlayer::AiPlayer(std::string side, Movement::MoveGenerator *generator)
    : Player(side), moveGenerator(generator) {
  std::cout << "created a AiPlayer" << std::endl;
}

AiPlayer::~AiPlayer() {}

Move AiPlayer::getPlayerNextMove() {
  std::string input = "quit";
  std::cout << "Thinking...\n";
  Move bestMove = moveGenerator->getBestMove();
  return bestMove;
}
