#include "game/headers/game.h"
#include "game/headers/menu.h"
#include "configuration/headers/configuration.h"
#include "configuration/headers/input_configuration.h"  

void play() {
  InputConfiguration i_config;
  i_config.get_player_input_configuration();
  Game game(i_config);
  game.start();
}

int main(/*int argc, char *argv[]*/) {
  string play_str = "Play", quit = "Quit";
  Menu<string> start_menu ({ 
      { 1, "Play", play_str}, 
      { 2, "Quit", quit}
  });

  start_menu.set_title("Game Menu");
  start_menu.print();

  if (start_menu.select_option() == play_str) {
    play();
  }

  return 0;
 }
