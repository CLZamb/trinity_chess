#include "game.h"

#include "game/messages/game_messages.hpp"
#include "menu/menu_window/menu_window.hpp"

using std::string;

Game::Game() {}

void Game::start() {
  Configuration config;
  get_config_from_file(config);

  string opt_selected = get_menu_option_as_string(config.get_input_type());

  if (opt_selected == "Quit") {
    GameMessages::print_game_over();
    return;
  }

  if (opt_selected == "Configuration") { config.get_new_configuration(); }

  start_game_loop(config.get_board_config());
}

void Game::get_config_from_file(Configuration &config) {
  BoardConfigInfo board_info;
  FileInput::from_json_file("configuration.json", board_info);
  config.set_board_configuration(board_info);
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

    if (board.is_invalid_move(mv)) { continue; }

    board.make_move(mv);
    board.change_side();

  } while (!board.is_checkmate());

  board.print();
  GameMessages::print_game_winner(board.get_winner_side());
}
