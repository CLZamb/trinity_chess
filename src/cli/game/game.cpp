#include "game.h"

#include "configuration/input_configuration.hpp"
#include "game/messages/game_messages.hpp"
#include "menu/menu_window/menu_window.hpp"

Game::Game() {}

string Game::get_start_menu_option_as_string() {
  MenuWindow start_menu(m_config.get_input_type());

  start_menu.set_title("Welcome to trinity Chess");
  start_menu.add_option("Play");
  start_menu.add_option("Configuration");
  start_menu.add_option("Quit");
  start_menu.print();

  return start_menu.select_option();
}

void Game::start() {
  std::string m_selected = get_start_menu_option_as_string();

  if (m_selected == "Quit") {
    GameMessages::print_game_over();
    return;
  }

  if (m_selected == "Configuration") {
    m_config.get_new_configuration();
  }

  start_game_loop();
}

void Game::start_game_loop() {
  Move mv;
  Board board(m_config.get_board_config());

  do {
    board.print();

    mv = board.get_player_move();

    if (board.is_invalid_move(mv)) {
      continue;
    }

    board.make_move(mv);
    board.change_side();

  } while (!board.is_checkmate());

  board.print();
  GameMessages::print_game_winner(board.get_winner_side());
}
