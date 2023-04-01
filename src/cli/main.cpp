#include "game.h"
#include "menu.hpp"
#include "input_configuration.h"
#include <cstdlib>
#include <unistd.h>

template<typename T>
void play(InputConfiguration<T> &i_config, PlayerInput &player_input) {
  Game game(i_config, player_input);
  game.play();
}

// TextInput m_input;
// ArrowInput m_input;
int main(/*int argc, char *argv[]*/) {
  // TextInput m_input;
  ArrowInput m_input;
  Menu start_menu(m_input);
  InputConfiguration i_config(m_input);

  string title = "Welcome to trinity Chess";
  const int play_key_num = 1, quit_key_num = 3, config_key_num = 2;
  const Options opts = {
    { play_key_num, "Play"},
    { config_key_num, "Settings"},
    { quit_key_num, "Quit"}
  };

  start_menu.set_title(title);
  start_menu.add_options(opts);
  start_menu.print();

  switch(start_menu.select_option_by_number_key()) {
    case config_key_num:
      i_config.get_configuration();
      [[fallthrough]];
    case play_key_num:
      play(i_config, m_input.get_player_input());
      break;
    case quit_key_num:
      std::cout << GameDrawing::game_over << std::endl;
    default: break;
  }

  return EXIT_SUCCESS;
}
