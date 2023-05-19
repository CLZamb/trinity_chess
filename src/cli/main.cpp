#include "game/game.h"

int main(/*int argc, char *argv[]*/) {
  // BoardFactory::RegisterObject("board", InfoPane::Create);
  Game game;
  game.start();
  return EXIT_SUCCESS;
}
