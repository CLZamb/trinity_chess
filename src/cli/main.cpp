#include <cstdlib>
#include "game/game.h"
#include "configuration/input_configuration.hpp"
#include "ui/graphics/ui_messages/game_messages.hpp"

// TextInput m_input;
// ArrowInput m_input;
int main(/*int argc, char *argv[]*/) {
  InputType type = InputType::Keyboard;
  // TextInput input;
  // ArrowInput input;
  InputConfiguration i_config(type);
  // InputType type = InputType::Keyboard;

  Menu start_menu(type);
  Game game(i_config, InputType::Text);
  //
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
      game.play();
      break;
    case quit_key_num:
      GameMessages::print_game_over();
    default: break;
  }

  return EXIT_SUCCESS;
}
