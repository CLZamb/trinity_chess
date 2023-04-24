#include "game.h"
#include "ui/messages/game_messages.hpp"

Game::Game(IConfiguration &config)
    : m_turn(config.get_players_config()),
      m_special_move(m_position),
      m_board_check(m_position),
      m_board_ui(config.get_fen(), config.get_board_config(), m_turn) {
  m_board_ui.add_info_pane(m_board_check);
  // m_players(pc.get_players_config(), input) {
  attach_observers_to_game_turn();

  m_fen_parser.parse_fen(config.get_fen(), m_position);
}

Game::~Game() {}

void Game::attach_observers_to_game_turn() { 
  m_turn.attach(&m_board_check);
  m_turn.attach(&m_position);
  m_turn.notify_turn();
}

void Game::set_configuration(IConfiguration& c) {
  m_turn.set_new_configuration(c.get_players_config());
}

void Game::play() {
  string str_move;
  Move mv;

  do {
    m_board_ui.update();
    m_board_ui.print();

    str_move = m_board_ui.get_next_string_move();

    if (str_move == "quit") return;

    if (!m_board_check.is_string_format_valid(str_move)) 
      continue;

    mv = string_to_move(str_move);
    if (m_board_check.is_in_check(mv) || 
       !m_board_check.is_legal_move(mv))
      continue;

    make_move(mv);
    m_turn.change_turn();

  } while (!m_board_check.is_checkmate());

  m_board_ui.update();
  m_board_ui.print();
  GameMessages::print_game_winner(m_turn.get_color());
}

void Game::make_move(const Move& mv) {
  m_position.move(mv);
  m_board_ui.make_move(mv);

  m_special_move.handle_special_move(mv, m_position);
}

Move Game::string_to_move(const string& m) {
  Move mv = string_utils::to_move(m);
  Square from = MoveUtils::get_from(mv);
  Square to = MoveUtils::get_to(mv);

  Piece player_piece = m_position.get_piece_at_square(from);
  Piece captured = m_position.get_piece_at_square(to);

  MoveUtils::set_piece(mv, player_piece);
  MoveUtils::set_capture_piece(mv, captured);

  m_special_move.set_special_move_to_move(mv, m_position);
  return mv;
}
