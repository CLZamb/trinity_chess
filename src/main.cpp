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

// TextInput m_input;
// ArrowInput m_input;
int main(/*int argc, char *argv[]*/) {
  ArrowInput m_input;
  string play_str = "play", quit = "quit", config = "configuration";
  string title = "Welcome to trinity Chess";
  const Options<string> opts = {
    { 1, "Play", play_str},
    { 2, "Quit", quit},
    { 3, "Configuration", quit}
  };

  Menu<string>start_menu(m_input);
  start_menu.set_title(title);
  start_menu.add_options(opts);

  start_menu.print();
  if (start_menu.select_option() == play_str)
    play(m_input);

  return EXIT_SUCCESS;
}
