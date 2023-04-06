#include "game.h"
#include "ui/graphics/ui_messages/game_messages.hpp"

Game::Game(IConfiguration& pc) : 
    m_game_turn(pc.get_players_config()),
    m_board_ui(m_board_fen, pc.get_input_type()),
    m_board_check(m_board),
    m_board_fen_info(m_board),
    m_board_fen(m_board_fen_info, start_fen) {
  // m_players(pc.get_players_config(), input) {
  attach_observers_to_game_turn();
  m_board_ui.add_info_pane();
}

Game::~Game() {}

void Game::attach_observers_to_game_turn() { 
  m_game_turn.attach(&m_board_fen_info);
  m_game_turn.attach(&m_board_ui);
  m_game_turn.attach(&m_board_check);
  m_game_turn.notify_game_turn();
}

void Game::set_configuration(IConfiguration& c) {
  m_game_turn.set_new_configuration(c.get_players_config());
}

void Game::play() {
  string str_move;
  string player_input;
  Move mv;

  m_board_ui.update_view();

  do {

    m_board_ui.print_view();
    str_move = m_board_ui.get_next_string_move();
    mv = m_board.string_to_move(str_move);

    if (!m_board_check.is_valid_move(str_move, mv)) {
      m_board_ui.update_board_info(m_board_check.get_error_str());
      continue;
    }

    make_move(mv);
    m_game_turn.change_turn();

  } while (!m_board_check.is_checkmate());

  if (m_board_check.is_checkmate())  {
    m_game_turn.change_turn();
    GameMessages::print_game_winner(m_game_turn.get_turn_color());
  } else {
    GameMessages::print_game_over();
  }
}

void Game::make_move(const Move& mv) {
  m_board.make_move(mv);
  m_board_fen.update_fen(m_board_fen_info);
  m_board_ui.save_move(mv);
  m_board_ui.update_view();
}
