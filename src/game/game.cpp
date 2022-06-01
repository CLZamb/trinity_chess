#include "headers/game.h"

Game::Game(Configuration pc) : 
  m_players(pc.get_players_info()),
  m_board_view(m_board.get_view()),
  m_board_info(m_board.get_info())
{
  setup_players();
  setup_board();
}

Game::~Game() {}

void Game::setup_players() {
  attach_observers_to_players();
  m_players.set_inital_side(GameTurn::player_1);
  m_players.notify();
}

void Game::attach_observers_to_players() {
  m_players.attach(&m_board);
  m_players.attach(&m_board_info);
  m_players.attach(&m_game_info);
  m_players.attach(&m_info_view);
  // m_players.attach(&m_console_input);
}

void Game::setup_board() {
  m_board_view.add_pane_to_window_pos(&m_info_view, Window::Right_pane);
}

void Game::start() {
  this->play();
}

void Game::print_view() {
  m_info_view.update_game_info(m_game_info.get_info());
  m_board_view.print();
}

void Game::play() {
  string player_input = "";

  while (!m_board.is_checkmate()) {
    print_view();

    player_input = m_input.get_input();

    if (has_player_quit(player_input)){
      break;
    }
    if (!is_valid_str_move_format(player_input))
      continue;

    if (!is_legal_move(player_input))
      continue;

    make_move(player_input);
    m_players.change_turn();
  }
};

void Game::make_move(const string &move) {
  Move player_move = String::to_move(move);
  m_board.make_move(player_move);
  update_info_view();
}

void Game::update_info_view() {
  m_info_view.update_moves(m_board_info.get_moves());
  m_info_view.update_captures(m_board_info.get_captures());
}

bool Game::is_valid_str_move_format(const string &input) {
  if (String::is_valid_move_format(input))
    return true;

  m_game_info.wrong_format(input);
  return false;
}

bool Game::is_legal_move(const string &str_player_move) {
  Move player_move = String::to_move(str_player_move);

  if (m_board.is_legal_move(player_move))
    return true;

  m_game_info.illegal_move(str_player_move);
  return false;
}

bool Game::has_player_quit(const string &str) {
  return str == "quit" || str == "close" || str == "exit";
}
