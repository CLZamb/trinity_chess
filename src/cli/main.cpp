#include <cstdlib>
#include "ui/graphics/menu/menu.hpp"
#include "ui/graphics/ui_messages/game_messages.hpp"
#include "configuration/default_configuration.h"
#include "game/game.h"

// TextInput m_input;
// ArrowInput m_input;
int main(/*int argc, char *argv[]*/) {
  DefaultConfiguration config;
  Menu start_menu(config.get_input_type());

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
      config.get_new_configuration();
      [[fallthrough]];
    case play_key_num: 
      { // setting local scope explicitly
        Game game(config);
        game.play();
      }
      break;
    case quit_key_num:
      GameMessages::print_game_over();
    default: break;
  }

  return EXIT_SUCCESS;
}
