#include "game/headers/game.h"
#include "game/headers/menu.h"
#include "configuration/headers/input_configuration.h"
#include <unistd.h>

template<typename T>
void play(T& input) {
  InputConfiguration i_config(input);
  i_config.get_configuration();
  Game game(i_config, input.get_player_input());
  game.play();
}

int main(/*int argc, char *argv[]*/) {
  // int *i;
  // std::cout << *i << std::endl;
  // TextInput m_input;
  KeyboardInput m_input;
  string play_str = "Play", quit = "Quit";
  // Menu<string> m_inputt (m_input);
  // m_inputt.set_title("Welcome to trintity Chess");
  // m_inputt.add_options ({
  //     { 1, "Play", play_str},
  //     { 2, "Quit", quit}
  // });

  // m_inputt.print();
  Menu<string> start_menu(
    m_input,
    "Welcome to trintity Chess", {
      { 1, "Play", play_str},
      { 2, "Quit", quit}
    }
  );

  start_menu.print();
  if (start_menu.select_option() == play_str)
    play(m_input);

  return EXIT_SUCCESS;
}
