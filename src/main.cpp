#include "game/headers/game.h"
#include "game/headers/menu.h"
#include "configuration/headers/configuration.h"
#include "configuration/headers/input_configuration.h"  

void play() {
  InputConfiguration i_config;
  i_config.get_configuration();
  Game game(i_config);
  game.play();
}

int main(/*int argc, char *argv[]*/) {
  string play_str = "Play", quit = "Quit";
  Menu<string> start_menu ({ 
      { 1, "Play", play_str}, 
      { 2, "Quit", quit}
  });

  start_menu.set_title("Welcome to trintity Chess");
  start_menu.print();
  ConsoleInput m_c_input;

  if (start_menu.select_option(m_c_input) == play_str) {
    play();
  }

  return 0;
 }
