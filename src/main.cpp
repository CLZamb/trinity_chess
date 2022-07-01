#include "game/headers/game.h"
#include "game/headers/menu.h"
#include "configuration/headers/input_configuration.h"  


template<typename T>
void play(T& input) {
  InputConfiguration i_config(input);
  i_config.get_configuration();
  Game game(i_config, input.get_player_input());
  game.play();
}

int main(/*int argc, char *argv[]*/) {
  KeyboardInput m_input;

  string play_str = "Play", quit = "Quit";
  Menu<string> start_menu ( 
      m_input,
    "Welcome to trintity Chess",{ 
      { 1, "Play", play_str}, 
      { 2, "Quit", quit}
    }
  );

  start_menu.print();
  if (start_menu.select_option() == play_str)
    play(m_input);

  return EXIT_SUCCESS;
 }


