#include "game.h"

#include "configuration/board_info.h"
#include "game/messages/game_messages.hpp"
#include "menu/menu_window/menu_window.hpp"
#include "board/board.h"

using std::string;

void Game::start() {
  Configuration config;
  config.get_config_from_file("configuration.json");

  string opt_selected = get_menu_option_as_string(config.get_input_type());

  if (opt_selected == "Quit") {
    GameMessages::print_game_over();
    return;
  }

  if (opt_selected == "Configuration") {
    config.get_new_configuration();
  }

  start_game_loop(config.get_board_config());
}

string Game::get_menu_option_as_string(InputType i_type) {
  MenuWindow start_menu(i_type);

  start_menu.set_title("Welcome to trinity Chess");
  start_menu.add_option("Play");
  start_menu.add_option("Configuration");
  start_menu.add_option("Quit");
  start_menu.print();

  return start_menu.select_option();
}

void Game::start_game_loop(BoardConfigInfo &board_config) {
  Move mv;
  Board board(board_config);

  do {
    board.print();

    mv = board.get_player_move();

    if (board.is_invalid_move(mv)) {
      continue;
    }

    board.make_move(mv);
    board.change_side();

  } while (!board.is_checkmate());

  GameMessages::print_game_winner(board.get_winner_side());
}
