#include "game/headers/game.h"
#include "game/headers/game_options.h"

int main(/*int argc, char *argv[]*/) {
  GameOptions game_opts;
  string play = "Play", quit = "Quit", config = "Config";
  Options<string> options{play, quit, config};
  string option_selected = game_opts.select_start_option(options);

  if (option_selected == play) {
    Game game;
    game.start();
  }

  return 0;
}
