#include "ui/graphics/ui_messages/game_messages.hpp"
#include "board/check_move/board_check.h"
#include <memory>
#include "game.h"

Game::Game(IConfiguration &pc)
    : m_game_turn(pc.get_players_config()),
      m_board_ui(m_board_fen, pc.get_input_type()),
      m_board_check(m_board),
      m_board_fen_info(m_board), m_board_fen(m_board_fen_info, start_fen) {
  // m_players(pc.get_players_config(), input) {
  m_board_ui.add_info_pane(m_board_check);
  attach_observers_to_game_turn();
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
  Move mv;

  do {
    m_board_ui.update_view();
    m_board_ui.print_view();

    str_move = m_board_ui.get_next_string_move();
    if (!m_board_check.is_string_format_valid(str_move)) 
      continue;

    mv = m_board.string_to_move(str_move);
    if (m_board_check.is_in_check(mv) || 
       !m_board_check.is_legal_move(mv))
      continue;

    make_move(mv);
    m_game_turn.change_turn();

  } while (!m_board_check.is_checkmate());


  m_board_ui.update_view();
  m_board_ui.print_view();
  // m_game_turn.change_turn();
  // GameMessages::print_game_winner(m_game_turn.get_turn_color());
}

void Game::make_move(const Move& mv) {
  m_board.make_move(mv);
  m_board_fen.update_fen(m_board_fen_info);
  m_board_ui.save_move(mv);
}
