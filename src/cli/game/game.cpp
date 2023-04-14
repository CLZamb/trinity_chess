#include "game.h"
#include "ui/graphics/ui_messages/game_messages.hpp"

Game::Game(IConfiguration &pc)
    : m_turn(pc.get_players_config()),
      m_board_check(m_board),
      m_board_fen(m_board, start_fen),
      m_board_ui(start_fen, pc.get_board_config()) {
  // m_players(pc.get_players_config(), input) {
  // TODO
  m_board_ui.add_info_pane(m_board_check);
  // m_board_ui.add_statistics_pane();
  attach_observers_to_game_turn();
}

Game::~Game() {}

void Game::attach_observers_to_game_turn() { 
  m_turn.attach(&m_board_check);
  m_board_ui.attach_ui_elements(m_turn);
  m_turn.notify_turn();
}

void Game::set_configuration(IConfiguration& c) {
  m_turn.set_new_configuration(c.get_players_config());
}

void Game::play() {
  string str_move;
  Move mv;

  do {
    m_board_ui.update_view();
    m_board_ui.print_view();

    str_move = m_board_ui.get_next_string_move();

    if (str_move == "quit") return;

    if (!m_board_check.is_string_format_valid(str_move)) 
      continue;

    mv = m_board.string_to_move(str_move);
    if (m_board_check.is_in_check(mv) || 
       !m_board_check.is_legal_move(mv))
      continue;

    make_move(mv);
    m_turn.change_turn();

  } while (!m_board_check.is_checkmate());

  m_board_ui.update_view();
  m_board_ui.print_view();
  GameMessages::print_game_winner(m_turn.get_turn_color());
}

void Game::make_move(const Move& mv) {
  m_board.make_move(mv);
  m_board_ui.make_move(mv);
  m_board_fen.update_fen();
}
