#include "game/headers/game.h"
#include "game/headers/menu.h"
// #include "configuration/headers/configuration.h"
#include "configuration/headers/input_configuration.h"  
#include "player/headers/keyboard_input.h"
#include <iostream>

void play(Input& input) {
  // fileConfiguration json?
  InputConfiguration i_config(input);
  i_config.get_configuration();
  Game game(i_config, input);
  game.play();
}

int main(/*int argc, char *argv[]*/) {
  KeyboardInput m_c_input;

  string play_str = "Play", quit = "Quit";
  Menu<string> start_menu (
    "Welcome to trintity Chess",{ 
      { 1, "Play", play_str}, 
      { 2, "Quit", quit}
    }
  );

  start_menu.add_input_manager(m_c_input);
  if (start_menu.select_option() == play_str) {
    play(m_c_input);
  }

  return 0;
 }


