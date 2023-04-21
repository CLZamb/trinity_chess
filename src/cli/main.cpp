#include "ui/menu_window/menu_window.hpp"
#include "ui/messages/game_messages.hpp"
#include "configuration/default_configuration.h"
#include "game/game.h"
#include "ui/input/keyboard/keyboard_base.h"

int main(/*int argc, char *argv[]*/) {
  DefaultConfiguration config;
  MenuWindow start_menu(config.get_board_config().get_input_type());

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
