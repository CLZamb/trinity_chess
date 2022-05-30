#include "headers/game.h"
#include "game/headers/game_turn_observer.h"

Game::Game(Configuration pc) : 
  m_board_view(m_board.get_view()),
  m_board_info(m_board.get_info())
{
  setup_players(pc.get_players_info());
  setup_board();
}

Game::~Game() {}

void Game::setup_players(PlayersConfig pc) {
  attach_observers_to_players();
  m_players.create_players(pc);
  m_players.set_inital_side(GameTurn::player_1);
  m_players.notify();
}

void Game::attach_observers_to_players() {
  m_players.attach(&m_board);
  m_players.attach(&m_board_info);
  m_players.attach(&m_game_info);
  m_players.attach(&m_info_view);
}

void Game::start() {
  this->play();
}

void Game::setup_board() {
  m_board_view.add_view_to_window_pos(m_info_view, Window::Right_pane);
}

void Game::play() {
  string player_input = "";

  while (!m_board.is_checkmate()) {
    m_info_view.update_game_info(m_game_info.get_info());
    m_board_view.print();
    player_input = get_current_player_input();

    if (has_player_quit(player_input))
      break;
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

string Game::get_current_player_input() {
  string input;
  std::cout << std::endl << " >> ";
  std::getline(std::cin, input);
  std::cout << std::endl;
  return input;
}
